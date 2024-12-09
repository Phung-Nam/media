import QtQuick 2.12

Item {
    id: root
    property bool bBold: false
    property real textSize: 15  //kích thước của text
    property bool flagFistRun: false //biến này dùng để đánh dấu lần chạy đầu tiên
    property real runSpeed: 0.06      /* biến này cài đặt tốc dộ chạy của text (Pixel/ms). với vận tốc chạy của các đoạn text là 0.06 (pixel/ms)
                                        thì mắt ta có thể nhìn thấy rõ chữ (đã test :v). Vì vậy ta chọn là 0.06(pixel/ms)*/
    property int delayTime: 1000      // Biến này cài đặt thời gian delay khi chuyển sang dòng text mới để chạy (ms).

    property bool bLong // Biến này dùng để kiểm tra độ dài của text có vượt ra khỏi Rectangle không. nếu có thì true, ngược lại thì false
    width: parent.width // width của item này sẽ bằng width của Rectangle trong hàm main
    height: idText.height
    property string strText
    property string space:"                           "
    signal finishedAnimation()

    Text { //text này dùng để kiểm tra độ dài với đơn vị là pixel
        id: idTempText
        visible: false
        text: strText
        font.pixelSize: textSize
    }
    Text { //cái text này để lấy độ dài theo pixel của chuỗi (strText + space)
        id: id_StringText_Space_Pixel
        visible: false
        text: (strText + space)
        font.pixelSize: textSize
    }

    Text {

        id: idText
        font.bold:bBold
        text:
        {
            if(idTempText.contentWidth>root.width)
            {
                bLong = true
                return (strText +space + strText)
            }
            else
            {
                bLong = false
                return strText
            }
        }
        font.pixelSize: textSize

    }
    NumberAnimation
    {
        id: t1
        property: "x"
        target: idText
        from:0
        to:  - id_StringText_Space_Pixel.contentWidth // mục đích là khi đầu text thứ 2 chạm mốc x = 0 thì dùng
        duration:
        {
            /* duration là thời gian để hoàn thành animation. Vấn đề ở đây là thời gian này của mỗi
             dòng text bằng bao nhiêu để cho tốc độ của mỗi dòng text chạy mà mắt ta có thể nhìn rõ chữ
             Sử dụng công thức t = S/v.
             t: duration (ms)
             S: quãng dường mà đoạn text chạy (pixel)
             v: Vận tốc chạy của đoạn text (pixel/ms) . ta có thể tùy chỉnh tốc độ mong muốn (sử dụng biến runSpeed để set).
             Vì vậy ta chon v là 0.06(pixel/ms). Lúc này t chỉ còn phụ thuộc vào S. mà S ta đã tìm được ở trên.
           */
            return (id_StringText_Space_Pixel.contentWidth/runSpeed) // t = (S/v)
        }
        running: false
        onFinished:
        {
            finishedAnimation()
        }
    }
    function startAnimation()
    {
        t1.stop()
        idText.x = 0
        if(idTempText.contentWidth>root.width)
        {
            if(flagFistRun === false)  // điều kiện này tránh lần chạy đầu tiên bị delay
            {
                t1.start()
                flagFistRun =true
            }
            else
            {
                tm1.start()
            }
        }
        else
        {
            finishedAnimation()
        }
    }
    function stopAnimation()
    {
        t1.restart()
        t1.stop()
    }

    Timer
    {
        id: tm1
        interval: delayTime; running: false; repeat: false
        onTriggered: t1.start()
    }
}

