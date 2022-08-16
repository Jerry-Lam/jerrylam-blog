import { defineStore } from 'pinia'


export const useCounterStore = defineStore({
  id: 'counter',
  state: () => ({
    counter: 0,
    loading: false
  }),
  getters: {
    doubleCount: (state) => state.counter * 2
  },
  actions: {
    increment() {
      this.counter++
    },
    openLoading(){
      this.loading = true
    },
    closeLoading() {
      this.loading = false
    }
  }
})
