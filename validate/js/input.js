class Input {
    #rule = {};
    #element;
    validator;
    ele;

    constructor(inputHtml) {
        this.#element = get_val(inputHtml);
        this.Get_error_ele();
        this.Parse_rule();
        this.validator = load_validator(this.#element.value, this.#rule);
        this.Listen(this.#element);
    }

    Parse_rule() {
        let rule_str = this.#element.getAttribute('data-rule');
        if (!rule_str)
            return;

        let rule_arr = rule_str.split('|');
        for (let i = 0; i < rule_arr.length; i++) {
            let item_str = rule_arr[i];
            let item_arr = item_str.split(':');
            this.#rule[item_arr[0]] = JSON.parse(item_arr[1]);
        }
    }

    Listen(value) {
        this.#element.addEventListener('change', () => {
            let validr = this.validator.is_valid(get_val(value));
            if (validr) {
                this.ele.style.display = 'none'
            } else {
                this.ele.style.display = 'block'
            }
        })
    }

    Get_error_ele() {
        this.ele = get_error_selector(this.#element);
    }
}

const load_validator = (val, rule) => {
    let validator = new Validator(val, rule);
    return validator;
}

const get_val = (val) => {
    return val;
}

const get_error_selector = (value) => {
    return document.getElementById(`${value.name}-input-error`);
}