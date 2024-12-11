from bot_func import *
from Currency import find_currency


@bot.message_handler(commands=['start'])
def start_message(message):
    bot.send_message(message.chat.id, 'Добрый день, какая валюта вас интересует?', reply_markup=hello_btns)
@bot.message_handler(content_types=['text'])
def any_message(message):
    bot.delete_message(message.chat.id, message.message_id)
    bot.delete_message(message.chat.id, message.message_id-1)
    bot.send_message(message.chat.id, 'Добрый день, какая валюта вас интересует?', reply_markup=hello_btns)

@bot.callback_query_handler(func=lambda call: True)
def answer(call):
    if call.data == 'euro':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        euro = find_currency('EUR')
        user_currency[call.message.chat.id] = ('EUR', euro.replace(',', '.'))
        bot.send_message(call.message.chat.id, f"1€ = {euro}₽", reply_markup=menu_btns)

    if call.data == 'dollar':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        usd = find_currency('USD')
        user_currency[call.message.chat.id] = ('USD', usd.replace(',', '.'))
        bot.send_message(call.message.chat.id, f"1$ = {usd}₽", reply_markup=menu_btns)
    if call.data == 'som':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        uzs = find_currency('UZS')
        user_currency[call.message.chat.id] = ('UZS', str(float(uzs.replace(',', '.'))/10000))
        bot.send_message(call.message.chat.id, f"10000 UZS = {uzs}₽", reply_markup=menu_btns)
    if call.data == 'back':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        bot.send_message(call.message.chat.id, 'Добрый день, какая валюта вас интересует?', reply_markup=hello_btns)
    if call.data == 'calc':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        amount = bot.send_message(call.message.chat.id, 'Введите сумму в УЕ, чтобы узнать конвертацию в рублях (только числа)')
        bot.register_next_step_handler(amount, amount_msg)


bot.infinity_polling()
