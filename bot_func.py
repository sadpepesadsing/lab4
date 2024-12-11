import telebot

from bot_btns import *
user_currency = {}

token = "7710098454:AAGn-yU94cI96EoFCtieXGJLilQ-F5spWns"
bot = telebot.TeleBot(token)

def amount_msg(message):
    message.text = message.text.replace(',', '.')
    try:
        bot.send_message(message.chat.id, f'{message.text} {user_currency[message.chat.id][0]} = '
                                          f'{round(float(message.text) * float(user_currency[message.chat.id][1]), 3)} RUB',
                         reply_markup=menu_btns)
    except TypeError:
        bot.send_message(message.chat.id, 'Ваше сообщение не является числом', reply_markup=menu_btns)

    bot.delete_message(message.chat.id, message.message_id)
    bot.delete_message(message.chat.id, message.message_id-1)