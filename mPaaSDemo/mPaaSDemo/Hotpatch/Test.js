require('UIAlertView');
defineClass('HotpatchDemoViewController', {
    createCrash: function() {
        var array = ["Crash被Hotpatch热修复啦", "Hello World"];
        var str = array[0];

        console.log(str);
        var alert = UIAlertView.alloc().initWithTitle_message_delegate_cancelButtonTitle_otherButtonTitles(str, null, null, null, "ok", null);
        alert.show();
    },
});