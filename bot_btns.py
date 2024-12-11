from telebot import types

hello_btns = types.InlineKeyboardMarkup(row_width=2)
hello_btns.row(types.InlineKeyboardButton('Евро', callback_data='euro'),
                     types.InlineKeyboardButton('Сумы', callback_data='som'))
hello_btns.row(types.InlineKeyboardButton('Доллар', callback_data='dollar'))

menu_btns = types.InlineKeyboardMarkup(row_width=1)
menu_btns.row(types.InlineKeyboardButton('Калькулятор', callback_data='calc'),
              types.InlineKeyboardButton('Назад', callback_data='back'))