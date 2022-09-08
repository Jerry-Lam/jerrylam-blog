import isNumeric from "./isNumeric";

type rule = {
    max?: number;
    min?: number;
    maxlength?: number,
    minlength?: number,
    numeric?: boolean,
    required?: boolean
    pattern?: string
}

class Validator {

    private m_val: string | number | undefined;
    private m_rule?: rule;

    private pre_max_min() {
        this.m_val = parseFloat(this.m_val as string);
    }

    private pre_Length() {
        if (this.m_val)
            this.m_val = (this.m_val as string).toString();
    }

    constructor(val: any, rule: rule) {
        this.m_val = val;
        this.m_rule = rule;
    }

    is_valid() {
        let key: string;

        //如果不是必填项，且没填任何内容，直接判定为合法
        if (!this.m_rule?.required && !this.m_val)
            return true;

        for (key in this.m_rule) {
            let r = eval(`this["Validate_${key}"]()`);
            if (!r) return false;
        }

        return true;
    }

    Validate_max() {
        this.pre_max_min();
        return (this.m_val as number) <= (this.m_rule?.max as number);
    }

    Validate_min() {
        this.pre_max_min();
        return (this.m_val as number) <= (this.m_rule?.min as number);
    }

    Validate_maxlength() {
        this.pre_Length();
        if (this.m_val)
            return (this.m_val as string).length <= (this.m_rule?.maxlength as number);

        return false;
    }

    Validate_minlength() {
        this.pre_Length();
        if (this.m_val)
            return (this.m_val as string).length >= (this.m_rule?.minlength as number);

        return false;
    }

    Validate_numeric() {
        return isNumeric(this.m_val);
    }

    Validate_required() {
        let real = (this.m_val as string)?.trim();
        if (!real)
            return false;
        return true;
    }

    Validate_pattern() {
        let reg = new RegExp(this.m_rule?.pattern as string);
        //正则对象
        return reg.test(this.m_val as string);
    }

}

export { type rule, Validator };