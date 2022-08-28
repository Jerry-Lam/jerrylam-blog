const throttle = (fn: Function, delay: number) => {
    let timer: number | null = null;

    return () => {
        if (timer) {
            return
        }
        fn()
        timer = setTimeout(() => {
            timer = null
        }, delay)
    }
}

export default throttle