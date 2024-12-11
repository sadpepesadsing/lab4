import telebot
from telebot import types

token = "7710098454:AAGn-yU94cI96EoFCtieXGJLilQ-F5spWns"
bot = telebot.TeleBot(token)

def amount_msg(message, currency):
    bot.delete_message(message.chat.id, message.message_id - 1)