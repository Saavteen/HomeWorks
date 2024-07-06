# HomeWorks

реалізовано повністю : b,d,e,h
частково a,f
не реалізовані : g , c 

a. Реалізувати функцію std::string RunawayPolicy::getFullInfo() та розширити UI для виводу
повної інформації про монстра, н-д:
Monster “Shiva”, level 20. You are dead! (level is dropped to 1, will lose 3 cards from the hand)

b. Додати нові Item з новими здібностями. Н-д: “Holy Sword”, який одразу знищує Zombie

c. Реалізувати методи MonsterDeck::generateMonster(), ModifierDeck::generateModifier(),
ItemDeck::generateItems(), які повинні щоразу повертати випадковий/випадкові, проте
унікальний/унікальні предмет/-и (який ще не розігрувався у грі)

d. Об’єднати дубльований код у MonsterDeck::generateMonster(),
ModifierDeck::generateModifier(), ItemDeck::generateItems(), оскільки вони виконують один
і той самий код (наприклад, з використанням наслідування (шляхом об’єднання під
одну ієрархію — наприклад, DeckBase) або із застосуванням композиції та винесенням
спільного коду в DeckSelectionHelper class)

e. Реалізувати заготовки нових RunawayPolicy: Runaway_ItemEquipedRemoval,
Runaway_ModifierFromHandRemoval, Runaway_BiggestBonusCardRemoval

f. Реалізувати VictoryPolicy — особливі бонуси, які отримає Манчкін, коли перемагає
монстра, окрім нового рівня. (Збільшення рівня на декілька пунктів, генерація нових
карт в руку, генерація нового аутфіту тощо)

g. Перенести базу даних айтемів у файл у форматі “type;name; params for the type”
Н-д: UndeadWeapon;"Holy Grenade";4
Modifier;”Doppelganger”;Double_Bonus

h. Реалізувати заготовки Modifier’ів інших типів
