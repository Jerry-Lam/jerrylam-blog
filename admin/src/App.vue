<template>
  <div class="a relative">
    <div class="b absolute top-[25px] left-[25px]"></div>
  </div>
</template>
  
<script setup lang='ts'>

</script>
  
<style lang="postcss" scoped>
.a {
  width: 100px;
  height: 100px;
  background-color: green;
  .b{
    width: 50px;
    height: 50px;
    background-color: white;
  }
}
</style>