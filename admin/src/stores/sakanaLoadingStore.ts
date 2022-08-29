import { defineStore } from 'pinia'


export const sakanaLoadingStore = defineStore({
  id: 'sakanaLoading',
  state: () => ({
    sakanaLoading: true,
  }),
  actions: {
    openLoading() {
      this.sakanaLoading = true
    },
    closeLoading() {
      this.sakanaLoading = false
    }
  }
})
