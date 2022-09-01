// $(() => {
//     'use strict';

class Validator {
    #m_val;
    #m_rule;

    //用于Validate_Max或Validate_min的前置工作
    #pre_Max_Min() {
        this.#m_val = parseFloat(this.#m_val);
    }

    //用于Validate_Maxlength或Validate_Minlength的前置工作
    #pre_Length() {
        this.#m_val = this.#m_val.toString();
    }

    constructor(val, rule) {
        this.#m_val = val;
        this.#m_rule = rule;
    }

    get() { }
    set() { }

    is_valid(val) {
        let key;
        this.#m_val = val.value || this.#m_val;

        //如果不是必填项，且没填任何内容，直接判定为合法
        if (!this.#m_rule.required && !this.#m_val)
            return true;

        for (key in this.#m_rule) {
            //防止重复检查
            if (key === 'required')
                continue;

            let r = this[`Validate_${key}`]();
            if (!r) return false;
        }

        return true;
    }

    Validate_Max() {
        this.#pre_Max_Min();
        return this.#m_val <= this.#m_rule.Max;
    }

    Validate_Min() {
        this.#pre_Max_Min();
        return this.#m_val >= this.#m_rule.Min;
    }

    Validate_Maxlength() {
        this.#pre_Length();
        return this.#m_val.length <= this.#m_rule.Maxlength;
    }

    Validate_Minlength() {
        this.#pre_Length();
        return this.#m_val.length >= this.#m_rule.Minlength;
    }

    Validate_Numeric() {
        return isNumeric(this.#m_val);
    }

    Validate_Required() {
        let real = this.#m_val.trim();
        if (!real && real !== 0)
            return false;
        return true;
    }

    Validate_Pattern() {
        let reg = new RegExp(this.#m_rule.Pattern);
        //正则对象
        return reg.test(this.#m_val);
    }

}

function isNumeric(value) {
    return !isNaN(value - parseFloat(value));
}
    // window.Validator = function (val, rule) {
    //     // this.is_valid = () => {
    //     //     //设计一个总的方法，根据rule匹配所有方法，根据匹配的方法验证传参，最后返回
    //     //     return true;
    //     //     return false;
    //     // }


    //     this.validate_max = () => {
    //         val = parseFloat(val);
    //         return val <= rule.max;
    //     }

    //     // this.validate_min = () => {
    //     //     return true;
    //     //     return false;
    //     // }
    // }
// })