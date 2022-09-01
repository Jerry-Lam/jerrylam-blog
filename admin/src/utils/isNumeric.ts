function isNumeric(value: any): boolean {
    return !isNaN(value - parseFloat(value));
}

export default isNumeric