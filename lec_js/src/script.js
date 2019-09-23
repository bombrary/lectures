let cnt = 0;
const p = document.getElementById('num_display');
p.textContent = "0";

document.getElementById('plus_btn')
  .addEventListener('click', () => {
    cnt++;
    p.textContent = String(cnt);
  }, false);
document.getElementById('minus_btn')
  .addEventListener('click', () => {
    cnt--;
    p.textContent = String(cnt);
  }, false);

