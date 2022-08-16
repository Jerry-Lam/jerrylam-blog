<template>
  <div class="a relative">
    <div class="b absolute top-[25px] left-[25px]"></div>
  </div>
  <div>
    <button class="shadow" @click="toPage('Login')">login</button>
    <button class="shadow ml-2.5" @click="toPage('Reg')">reg</button>
  </div>
  <div v-show="loading">
    <loading></loading>
  </div>
  <div v-show="!loading">
    <router-view></router-view>
  </div>
  <div>
    {{loading}}
  </div>
</template>

<script setup lang='ts'>
import { storeToRefs } from 'pinia';
import { useRouter } from 'vue-router'
import Loading from './components/loading.vue';

import { useCounterStore } from './stores/counter';
const load = useCounterStore();
const { loading } = storeToRefs(load);

const router = useRouter();


const toPage = (url: string) => {
  router.push({
    name: url
  })
}

</script>
  
<style lang="postcss" scoped>
.a {
  width: 100px;
  height: 100px;
  background-color: green;

  .b {
    width: 50px;
    height: 50px;
    background-color: white;
  }
}
</style>