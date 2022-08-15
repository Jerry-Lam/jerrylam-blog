import { createApp, createVNode, render } from 'vue'
import { createPinia } from 'pinia'

import App from './App.vue'
import router from './router'

import './assets/index.css'

import loadingBar from '@/components/loadingBar.vue'

const Vnode = createVNode(loadingBar);
render(Vnode, document.body);

const app = createApp(App)

app.use(createPinia())
app.use(router)

app.mount('#app')

router.beforeEach((to, from, next)=>{
    Vnode.component?.exposed?.startLoading();
    next()
});

router.afterEach((to, from)=>{
    Vnode.component?.exposed?.endLoading()
})