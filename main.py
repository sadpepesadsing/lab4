import telebot
from telebot import types

from Currency import find_currency

token = "7710098454:AAGn-yU94cI96EoFCtieXGJLilQ-F5spWns"
bot = telebot.TeleBot(token)

hello_btns = types.InlineKeyboardMarkup(row_width=2)
hello_btns.row(types.InlineKeyboardButton('Евро', callback_data='euro'),
                     types.InlineKeyboardButton('Сумы', callback_data='som'))
hello_btns.row(types.InlineKeyboardButton('Доллар', callback_data='dollar'))

menu_btns = types.InlineKeyboardMarkup(row_width=1)
menu_btns.row(types.InlineKeyboardButton('Калькулятор', callback_data='calc'),
              types.InlineKeyboardButton('Назад', callback_data='back'))


@bot.message_handler(commands=['start'])
def start_message(message):
    bot.delete_message(message.chat.id, message.message_id)
    bot.send_message(message.chat.id, 'Добрый день, какая валюта вас интересует?', reply_markup=hello_btns)

@bot.callback_query_handler(func=lambda call: True)
def answer(call):
    if call.data == 'euro':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        euro = find_currency('EUR')
        bot.send_message(call.message.chat.id, f"1€ = {euro}₽", reply_markup=menu_btns)

    if call.data == 'dollar':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        usd = find_currency('USD')
        bot.send_message(call.message.chat.id, f"1$ = {usd}₽", reply_markup=menu_btns)
    if call.data == 'som':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        uzs = find_currency('UZS')
        bot.send_message(call.message.chat.id, f"10000 UZS = {uzs}₽", reply_markup=menu_btns)
    if call.data == 'back':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        bot.send_message(call.message.chat.id, 'Добрый день, какая валюта вас интересует?', reply_markup=hello_btns)
    if call.data == 'calc':
        bot.delete_message(call.message.chat.id, call.message.message_id)
        amount = bot.send_message(call.message.chat.id, 'Введите сумму в УЕ, чтобы узнать конвертацию в рублях')
        bot.register_next_step_handler(amount, amount_msg)


bot.infinity_polling()
