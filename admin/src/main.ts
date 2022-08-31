import { createApp, createVNode, render } from 'vue'
import { createPinia } from 'pinia'

import App from './App.vue'
import router from './router'

import './assets/index.css'
import { sakanaLoadingStore } from './stores/sakanaLoadingStore'

// import loadingBar from '@/components/loadingBar.vue'

// const Vnode = createVNode(loadingBar);
// render(Vnode, document.body);

const app = createApp(App)

app.use(createPinia())
app.use(router)

app.mount('#app')

// router.beforeEach(async (to, from, next) => {
//     Vnode.component?.exposed?.startLoading();
//     return true
// });

router.afterEach((to, from) => {
    const sakanaLoad = sakanaLoadingStore();
    if (to.path === '/login') {
        return
    } else {
        sakanaLoad.closeLoading();
    }
})