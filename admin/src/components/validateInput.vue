<template>
    <div>
        <label>用户名</label>
        <input :ref="userName.refDom" :dataRule="userName.dataRule = { maxlength: 5 }" v-model="userName.data.value"
            type="text" @change="userName.validata()">
        <div v-if="!userName.inputError.value">用户名格式有误</div>
    </div>
    <div>
        <label>密码</label>
        <input :ref="passWord.refDom" :dataRule="passWord.dataRule = { required: true }" v-model="passWord.data.value"
            type="text" @change="passWord.validata()">
        <div v-if="!passWord.inputError.value">密码不能为空</div>
    </div>
</template>
    
<script setup lang='ts'>
import { Validator, type rule } from '@/utils/Validator';
import { onMounted, ref, type Ref } from 'vue';

class valid {
    refDom: Ref<HTMLInputElement | undefined> = ref<HTMLInputElement>();
    data: Ref<string | number | undefined> = ref<string | number>();
    inputError: Ref<boolean | undefined> = ref<boolean>(true);
    dataRule: rule = {};
    validate!: Validator;

    constructor() {}

    validata() {
        this.validate = new Validator(this.data.value, this.dataRule);
        this.inputError.value = this.validate.is_valid();
    }
}

onMounted(() => {
})

let userName = new valid();
let passWord = new valid();

</script>
    
<style>
</style>