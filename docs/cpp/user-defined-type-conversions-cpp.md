---
title: Conversões de tipo definido pelo usuário (C++)
ms.date: 11/04/2016
f1_keywords:
- explicit_cpp
helpviewer_keywords:
- constructors [C++], and constants
- conversion functions [C++]
- explicit keyword [C++]
- type conversion
- constructors [C++], drawbacks
- conversion constructors
- type conversion [C++], explicit conversion
- coercion [C++]
- conversions [C++], explicit
- objects [C++], converting
- conversion functions [C++], rules for declaring
- declaring functions [C++], conversion functions
- functions [C++], conversion
- converting objects
- constructors [C++], conversion
- conversions [C++], by constructors
- data type conversion [C++], explicit
ms.assetid: d40e4310-a190-4e95-a34c-22c5c20aa0b9
ms.openlocfilehash: e7889a7365a6b3a362804d3dad4b2fefc3780d01
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227030"
---
# <a name="user-defined-type-conversions-c"></a>Conversões de tipo definido pelo usuário (C++)

Uma *conversão* produz um novo valor de algum tipo a partir de um valor de um tipo diferente. As *conversões padrão* são incorporadas à linguagem C++ e dão suporte a seus tipos internos, e você pode criar *conversões definidas pelo usuário* para executar conversões de, de ou entre os tipos definidos pelo usuário.

As conversões padrão realizam conversões entre tipos internos, entre ponteiros ou referências para tipos relacionados por herança, para os ponteiros void e nulo. Para obter mais informações, consulte [conversões padrão](../cpp/standard-conversions.md). As conversões definidas pelo usuário realizam conversões entre tipos definidos pelo usuário ou entre tipos definidos pelo usuário e tipos internos. Você pode implementá-los como [construtores de conversão](#ConvCTOR) ou como [funções de conversão](#ConvFunc).

As conversões podem ser implícitas (quando as chamadas do programador de um tipo a ser convertido para outro, como em uma inicialização direta ou convertida) ou implícita (quando o programa ou a linguagem chama um tipo diferente daquele fornecido pelo programador).

As conversões implícitas são tentadas quando:

- Um argumento fornecido para uma função não tem o mesmo tipo do parâmetro correspondente.

- O valor retornado de uma função não tem o mesmo tipo do tipo de retorno de função.

- Uma expressão de inicializador não tem o mesmo tipo do objeto que está sendo inicializado.

- Uma expressão que controla uma instrução condicional, constructos de loop ou opção não tem o tipo de resultado necessário para controlá-la.

- Um operando fornecido para um operador não tem o mesmo tipo do parâmetro do operando correspondente. Para operadores internos, ambos os operandos devem ter o mesmo tipo e são convertidos para um tipo comum que pode representar ambos. Para obter mais informações, consulte [conversões padrão](standard-conversions.md). Para operadores definidos por usuários, cada operando deve ter o mesmo tipo do parâmetro operando correspondente.

Quando uma conversão padrão não pode concluir uma conversão implícita, o compilador pode usar uma conversão definida pelo usuário, seguida opcionalmente por uma conversão padrão adicional, para completá-la.

Quando duas ou mais conversões definidas pelo usuário que executam a mesma conversão estão disponíveis em um site de conversão, a conversão é chamada de ambígua. Essas ambiguidades são um erro porque o compilador não pode determinar qual das conversões disponíveis deve escolher. No entanto, não é errado apenas definir várias maneira de realizar a mesma conversão porque o conjunto de conversões disponíveis pode ser diferente em locais diferentes no código-fonte, por exemplo, dependendo de quais arquivos de cabeçalho estão incluídos no arquivo fonte. Enquanto apenas uma conversão estiver disponível no local da conversão, não há ambiguidade. Conversões ambíguas podem ocorrer de várias maneiras, mas as mais comuns são:

- Herança múltipla. A conversão é definida em mais de uma classe base.

- Chamada de função ambígua. A conversão é defina como um construtor de conversão do tipo de destino e como uma função de conversão do tipo de fonte. Para obter mais informações, consulte [funções de conversão](#ConvFunc).

Geralmente, você pode resolver uma ambiguidade apenas por meio da qualificação do nome do tipo envolvido ou realizando uma conversão explícita para esclarecer sua intenção.

Ambos, construtores de conversão e funções de conversão obedecem regras de controle de acesso de membro, mas a acessibilidade das conversões é apenas considerada se e quando uma conversão ambígua puder ser determinada. Isso significa que uma conversão pode ser ambígua ainda que o nível de acesso de uma conversão concorrente impeça o seu uso. Para obter mais informações sobre acessibilidade de membro, consulte [controle de acesso de membro](../cpp/member-access-control-cpp.md).

## <a name="the-explicit-keyword-and-problems-with-implicit-conversion"></a>A palavra-chave e problemas explícitos com conversão implícita

Por padrão, ao criar uma conversão definida pelo usuário, o compilador pode usá-la para executar conversões implícitas. Algumas vezes pode ser que você queira isso, mas outras vezes as regras simples que guiam o compilador para fazer conversões implícitas pode levá-lo a aceitar códigos que não quer.

Um exemplo bem conhecido de uma conversão implícita que pode causar problemas é a conversão para **`bool`** . Há muitas razões pelas quais você pode querer criar um tipo de classe que possa ser usado em um contexto booliano — por exemplo, para que possa ser usado para controlar uma **`if`** instrução ou um loop — mas quando o compilador executa uma conversão definida pelo usuário em um tipo interno, o compilador tem permissão para aplicar uma conversão padrão adicional posteriormente. A intenção dessa conversão padrão adicional é permitir coisas como a promoção de **`short`** para **`int`** , mas também abre a porta para conversões menos óbvias — por exemplo, de **`bool`** para **`int`** , que permite que seu tipo de classe seja usado em contextos inteiros que você nunca pretendeu. Esse problema específico é conhecido como o *problema booliano seguro*. Esse tipo de problema é onde a **`explicit`** palavra-chave pode ajudar.

A **`explicit`** palavra-chave informa ao compilador que a conversão especificada não pode ser usada para executar conversões implícitas. Se você quisesse a conveniência sintática de conversões implícitas antes da **`explicit`** introdução da palavra-chave, era necessário aceitar as consequências involuntárias que às vezes a conversão implícita criava ou usar funções de conversão nomeadas menos convenientes como uma solução alternativa. Agora, ao usar a **`explicit`** palavra-chave, você pode criar conversões convenientes que só podem ser usadas para executar transmissões explícitas ou inicialização direta, e isso não levará a um tipo de problema exemplificado pelo problema booliano seguro.

A **`explicit`** palavra-chave pode ser aplicada aos construtores de conversão desde o c++ 98 e às funções de conversão desde o c++ 11. As seções a seguir contêm mais informações sobre como usar a **`explicit`** palavra-chave.

## <a name="conversion-constructors"></a><a name="ConvCTOR"></a>Construtores de conversão

Os construtores de conversão definem conversões de tipos internos ou definidos pelo usuário para um tipo definido pelo usuário. O exemplo a seguir demonstra um construtor de conversão que converte do tipo interno **`double`** para um tipo definido pelo usuário `Money` .

```cpp
#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    Money(double _amount) : amount{ _amount } {};

    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main(int argc, char* argv[])
{
    Money payable{ 79.99 };

    display_balance(payable);
    display_balance(49.95);
    display_balance(9.99f);

    return 0;
}
```

Observe que a primeira chamada para a função `display_balance`, que leva um argumento do tipo `Money`, não necessita de uma conversão porque seu argumento é do tipo correto. No entanto, na segunda chamada para `display_balance` , uma conversão é necessária porque o tipo do argumento, um **`double`** com um valor de `49.95` , não é o que a função espera. A função não pode usar esse valor diretamente, mas como há uma conversão do tipo do argumento — **`double`** – para o tipo do parâmetro correspondente — `Money` — um valor temporário do tipo `Money` é construído a partir do argumento e usado para concluir a chamada de função. Na terceira chamada para `display_balance` , observe que o argumento não é um **`double`** , mas, em vez disso, é um **`float`** com um valor de `9.99` – e, ainda assim, a chamada de função ainda pode ser concluída porque o compilador pode executar uma conversão padrão — nesse caso, de **`float`** para **`double`** – e, em seguida, executar a conversão definida pelo usuário de **`double`** para `Money` para concluir a conversão necessária.

### <a name="declaring-conversion-constructors"></a>Declaração de construtores de conversão

As regras a seguir aplicam-se à declaração de um construtor de conversão:

- O tipo de destino da conversão é o tipo definido pelo usuário que está sendo construído.

- Geralmente, os construtores de conversão usam exatamente um argumento, que é o do tipo do código-fonte. No entanto, um construtor de conversão pode especificar parâmetros adicionais, caso cada parâmetro adicional tenha um valor padrão. O tipo de código-fonte permanece o tipo do primeiro parâmetro.

- Os construtores de conversão, como todos os construtores, não especificam um tipo de retorno. Especificar um tipo de retorno na declaração é um erro.

- Os construtores de conversão podem ser explícitos.

### <a name="explicit-conversion-constructors"></a>Construtores de conversão explícita

Ao declarar um construtor de conversão para ser **`explicit`** , ele só pode ser usado para executar a inicialização direta de um objeto ou para executar uma conversão explícita. Isso evita que funções que aceitam um argumento do tipo de classe também aceitem argumentos implicitamente do tipo de fonte do construtor de conversão, evitando que o tipo de classe seja inicializado por cópia a partir de um valor do tipo de fonte. O exemplo a seguir demonstra como definir um construtor de conversão explícita e o efeito que tem sobre qual código é bem formado.

```cpp
#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    explicit Money(double _amount) : amount{ _amount } {};

    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main(int argc, char* argv[])
{
    Money payable{ 79.99 };        // Legal: direct initialization is explicit.

    display_balance(payable);      // Legal: no conversion required
    display_balance(49.95);        // Error: no suitable conversion exists to convert from double to Money.
    display_balance((Money)9.99f); // Legal: explicit cast to Money

    return 0;
}
```

Nesse exemplo, observe que você pode ainda usar o construtor de conversão explícita para executar a inicialização direta de `payable`. Se ao invés disso você tivesse que inicializar `Money payable = 79.99;` por cópia, o resultado seria um erro. A primeira chamada para `display_balance` é sem efeito porque o argumento é o tipo correto. A segunda chamada para `display_balance` é um erro, porque o construtor de conversão não pode ser usado para executar conversões implícitas. A terceira chamada para `display_balance` é legal devido à conversão explícita para `Money` , mas observe que o compilador ainda ajudou a concluir a conversão inserindo uma conversão implícita de **`float`** para **`double`** .

Embora a praticidade de permitir conversões implícitas possa ser tentadora, fazer isso pode introduzir bugs difíceis de encontrar. A regra recomendada é tornar explícitos todos os construtores de conversão, exceto quando você tem certeza que deseja que uma conversão específica ocorra implicitamente.

## <a name="conversion-functions"></a><a name="ConvFunc"></a>Funções de conversão

As funções de conversão definem conversões de um tipo definidas pelo usuário para outros tipos. Essas funções são algumas vezes chamadas como operadores cast pois, juntamente com os construtores de conversão, são chamadas quando um valor é convertido para um tipo diferente. O exemplo a seguir demonstra uma função de conversão que converte do tipo definido pelo usuário, `Money` , para um tipo interno, **`double`** :

```cpp
#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    Money(double _amount) : amount{ _amount } {};

    operator double() const { return amount; }
private:
    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << balance << std::endl;
}
```

Observe que a variável de membro `amount` é tornada privada e que uma função de conversão pública para Type **`double`** é introduzida apenas para retornar o valor de `amount` . Na função `display_balance`, uma conversão implícita ocorre quando o valor de `balance` é transmitido para saída padrão usando o operador de inserção de fluxo `<<`. Como nenhum operador de inserção de fluxo é definido para o tipo definido pelo usuário `Money` , mas há um para o tipo interno **`double`** , o compilador pode usar a função de conversão de `Money` para **`double`** para satisfazer o operador de inserção de fluxo.

As funções de conversão são herdadas por classes derivadas. As funções de conversão em uma classe derivada apenas substitui uma função de conversão herdada quando convertidas exatamente para o mesmo tipo. Por exemplo, uma função de conversão definida pelo usuário do operador de classe derivada **int** não substitui — ou até mesmo influencia — uma função de conversão definida pelo usuário do **operador**de classe base curta, embora as conversões padrão definam uma relação de conversão entre **`int`** e **`short`** .

### <a name="declaring-conversion-functions"></a>Declaração de funções de conversão

As regras a seguir são aplicadas ao declarar uma função de conversão:

- O tipo de destino da conversão deve ser declarado antes da declaração da função de conversão. Classes, estruturas, enumerações e typedefs não podem ser declarados na declaração da função de conversão.

    ```cpp
    operator struct String { char string_storage; }() // illegal
    ```

- As funções de conversão não têm argumentos. Especificar quaisquer parâmetros na declaração é um erro.

- As funções de conversão têm um tipo de retorno que é especificado pelo nome da função de conversão, que é também o nome do tipo de destino da conversão. Especificar um tipo de retorno na declaração é um erro.

- As funções de conversão podem ser virtuais.

- As funções de conversão podem ser explícitas.

### <a name="explicit-conversion-functions"></a>Funções de conversão explícitas

Quando uma função de conversão é declarada como explícita, ele pode ser usada para executar uma conversão explícita. Isso evita que funções que aceitam um argumento do tipo de destino da função de conversão também aceitem implicitamente argumentos do tipo de classe, além de evitar que o tipo de destino seja inicializado por cópia, a partir de um valor do tipo de classe. O exemplo a seguir demonstra como definir uma função de conversão explícita e o efeito que tem sobre qual código é bem formado.

```cpp
#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    Money(double _amount) : amount{ _amount } {};

    explicit operator double() const { return amount; }
private:
    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << (double)balance << std::endl;
}
```

Aqui, o **operador** de função de conversão Double foi explicitado e uma conversão explícita para **`double`** o tipo foi introduzida na função `display_balance` para executar a conversão. Se essa conversão for omitida, o compilador será incapaz de localizar um operador de inserção de fluxo adequado `<<` de tipo `Money` e poderá ocorrer um erro.
