<template>
    <div class="w-[400px] p-3">
        <input
            class="text-center w-full h-9 hover:outline-black rounded-xl border-[3px] border-black dark:border-white bg-inherit"
            :ref="userName.refDom" :dataRule="userName.dataRule = { required: true }" v-model="userName.data.value"
            type="text" placeholder="请输入用户名" @change="userName.validata()">
        <div class="text-pink-600 text-sm text-center" v-if="!userName.inputError.value">用户名不能为空</div>
    </div>
    <div class="w-[400px] p-3">
        <input
            class="text-center w-full h-9 hover:outline-black rounded-xl border-[3px] border-black dark:border-white bg-inherit"
            :ref="passWord.refDom" :dataRule="passWord.dataRule = { required: true }" v-model="passWord.data.value"
            type="password" placeholder="请输入密码" @change="passWord.validata()">
        <div class="text-pink-600 text-sm text-center" v-if="!passWord.inputError.value">密码不能为空</div>
    </div>
    <button class="py-0 px-4 my-4 w-36 h-14 bg-[url('@/assets/login.png')] bg-cover" @click="login()"></button>
</template>
    
<script setup lang='ts'>
import router from '@/router';
import { Validator, type rule } from '@/utils/Validator';
import { onMounted, ref, type Ref } from 'vue';

class valid {
    refDom: Ref<HTMLInputElement | undefined> = ref<HTMLInputElement>();
    data: Ref<string | number | undefined> = ref<string | number>();
    inputError: Ref<boolean | undefined> = ref<boolean>(true);
    dataRule: rule = {};
    validate!: Validator;

    constructor() { }

    validata() {
        this.validate = new Validator(this.data.value, this.dataRule);
        this.inputError.value = this.validate.is_valid();
    }
}

onMounted(() => {
})

let userName = new valid();
let passWord = new valid();

const login = () => {
    userName.validata();
    passWord.validata();
    if (userName.inputError.value && passWord.inputError.value)
        toPage('Dashboard');
}

const toPage = (url: string) => {
    router.push({
        name: url
    })
}
</script>
    
<style>

</style>