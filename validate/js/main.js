//选中页面所有的input[data-rule]

//解析每一个input验证规则

//验证
// $(() => {
//     'use strict';

    let rule = {
        max: 100,
        min: 10,
        maxlength: 5,
        numeric: false
    }

    var validator = new Validator('123', rule);

    // var result = validator.validate_max();
    // var result = validator.validate_min();
    var result = validator.Validate_Numeric();
    console.log(`result:`,result);
// })



// var name_validator = new Validator(user_input, rule);
//user_input传需要验证的参数，rule传验证规则
// name_validator.is_valid();
//is_valid根据传入的规则，验证传入的参数