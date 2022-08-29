<template>
<div class="w-80 h-80 bg-cyan-600">
  login
</div>
</template>
    
<script setup lang='ts'>
import { onMounted } from 'vue';
import { useCounterStore } from '@/stores/counter';

const load = useCounterStore();

onMounted(() => {
  // setTimeout(() => {
    
  //   // console.log(load.loading)
  // }, 2000)
  load.closeLoading();
})
</script>
    
<style>
    
</style>