<template>
  <div class="a relative">
    <div class="b absolute top-[25px] left-[25px]"></div>
  </div>
  <div>
    <button class="shadow" @click="toPage('Login')">login</button>
    <button class="shadow ml-2.5" @click="toPage('Reg')">reg</button>
  </div>

  <router-view></router-view>
</template>
  
<script setup lang='ts'>
import { useRouter } from 'vue-router'

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