<template>
login
</template>
    
<script setup lang='ts'>
import { onMounted } from 'vue';
import { useCounterStore } from '@/stores/counter';
const load = useCounterStore();

onMounted(() => {
  setTimeout(() => {
    load.closeLoading();
    console.log(load.loading)
  }, 1000)
})
</script>
    
<style>
    
</style>