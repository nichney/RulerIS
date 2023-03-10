class node:
    def __init__(self, question, answerYes, answerNo):
        self.question = question
        self.answerYes = answerYes
        self.answerNo = answerNo

    def ask(self):
        ans = input(self.question)
        if ans == "y":
            if isinstance(self.answerYes, str):
                print(self.answerYes)
            else:
                self.answerYes.ask()
        else:
            if isinstance(self.answerNo, str):
                print(self.answerNo)
            else:
                self.answerNo.ask()


print("Это ИС для угадывания правителей Российского государства. ")
main_event = node(
    "Загаданный вами персонаж - мужчина? ",
    node(
        "Является представителем правящего привелегированного сословия? ",
        node(
            "Он из рода Рюриковичей?",
            node(
                "Носил титул царя?",
                "Вы загадали Ивана IV Грозного",
                node(
                    "Он новгородский князь?",
                    node(
                        "Он умер от змеиного яда?",
                        "Вы загадали Олега Вещего",
                        "Вы загадали Первого Русского правителя - Рюрика",
                    ),
                    node(
                        "Он киевский князь? ",
                        node(
                            "Крестил Русь?",
                            "Это Владимир Красное Солнышко",
                            node(
                                "Собирал дань с древлян 2 раза?",
                                "Вы загадали Игоря Рюриковича",
                                node(
                                    "ОН раздробил Русь?",
                                    "Вы загадали Ярослава Мудрого",
                                    node(
                                        "Он носил шапку с интересным названием?",
                                        "Кажется это Владимир Мономах",
                                        node(
                                            "Он основал Москву?",
                                            "ВЫ загадали Юрия Долгорукого",
                                            node(
                                                "Бился на Чудском озере?",
                                                "Я думаю что это Александр Невский",
                                                "Наверное это Андрей Боголюбский",
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        ),
                        node(
                            "Он Владимирский князь?",
                            node(
                                "У него было 12 детей?",
                                "Это Всеволод Большое Гнездо",
                                "Наверное это Александр Невский",
                            ),
                            node(
                                "Он обманывал татар на деньги?",
                                "Вы загадали Ивана Калиту",
                                node(
                                    "У него хорошее зрение?",
                                    node(
                                        "Он освободил Русь от татаро-монгольского ига?",
                                        "Это Иван III Великий",
                                        "ВОЗМОЖНО ЭТО АЛЕКСАНДР НЕВСКИЙ",
                                    ),
                                    "Скорее всего это Василий II Темный",
                                ),
                            ),
                        ),
                    ),
                ),
            ),
            node(
                "Он носил титул императора?",
                node(
                    "Он играл в солдатиков?",
                    node(
                        "Он проиграл в войне Пруссии?",
                        "Вы загадали Петра III",
                        "Вы загадали Петра I",
                    ),
                    node(
                        "Умер от заговора?",
                        "Вы загадали Павла I",
                        node(
                            "Он подавлял восстание или революцию?",
                            node(
                                "А всегда успешно?",
                                "Вы загадали Николая I",
                                "Вы загадали Николая II",
                            ),
                            node(
                                "Он держал упавшую крышу поезда?",
                                "Вы загадали Александра III",
                                node(
                                    "Его убил террорист?",
                                    "Кажется это Александр II",
                                    "Я думаю, это Александр I",
                                ),
                            ),
                        ),
                    ),
                ),
                node(
                    "Жил во времена смуты?",
                    "Кажется это Михаил Романов",
                    node(
                        "Он правил после Михаила?",
                        "Я думаю, что это Алексей Романов",
                        "Вы загадали Федора III",
                    ),
                ),
            ),
        ),
        node(
            "Он представитель эпохи XX - XXI века?",
            node(
                "Он был президентом?",
                node(
                    "Он сейчас жив?",
                    node("Он лысый?", "Вы загадали Путина", "Вы загадали Медведева"),
                    node(
                        "Он стоял на танке?",
                        "Вы загадали Ельцина",
                        "ВЫ загадали Горбачева",
                    ),
                ),
                node(
                    "Он лысый?",
                    node(
                        "Он стоял на броневике?",
                        "ВЫ загадали Владимира Ильича Ленина",
                        node(
                            "Он засадил страну кукурузой?",
                            "Вы загадали Хрущева",
                            "Вы загадали Андропова",
                        ),
                    ),
                    node(
                        "Коммунист?",
                        node(
                            "Он этнический грузин?",
                            "Вы загадали Сталина!",
                            node(
                                "Он целовался с политиками?",
                                "Вы загадали Брежнева",
                                "Вы загадали Черненко",
                            ),
                        ),
                        node(
                            "Белый генерал?",
                            "Вы загадали Колчака",
                            "Вы загадали Керенского",
                        ),
                    ),
                ),
            ),
            "Вы загадали Лжедмитрия (одного из)",
        ),
    ),
    node(
        "Из рода Рюриковичей? ",
        "Вы загадали княгиню Ольгу!",
        node(
            "Она жена Петра I? ",
            "Вы загадали Екатерину I",
            node(
                "Она дочь Петра I? ",
                "Вы загадали Елизавету Петровну",
                node(
                    "Она прозвана Великой?",
                    "Вы загадали Екатерину II",
                    "Вы загадали Анну Иоановну",
                ),
            ),
        ),
    ),
)

main_event.ask()
input("press any key...")
