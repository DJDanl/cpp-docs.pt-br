---
title: Enumerações (C++)
ms.date: 06/01/2018
f1_keywords:
- enum_cpp
helpviewer_keywords:
- declarations, enumerations
- enumerators, declaring
- enum keyword [C++]
- named constants, enumeration declarations
- declaring enumerations
ms.assetid: 081829db-5dca-411e-a53c-bffef315bcb3
ms.openlocfilehash: caec9ea7ac5482ff23b73676a3fd7b3d25ad293f
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78884139"
---
# <a name="enumerations-c"></a>Enumerações (C++)

Uma enumeração é um tipo definido pelo usuário que consiste em um conjunto de constantes integrais nomeadas que são conhecidas como enumeradores.

> [!NOTE]
>  Este artigo aborda o tipo de C++ **Enumeração** de idioma padrão ISO e o tipo de **classe de enumeração** com escopo (ou fortemente tipado) que é introduzido no c++ 11. Para obter informações sobre **a classe de enumeração pública** ou tipos de classe C++de **enumeração privada** em/CLI e C++/CX, consulte classe de [Enumeração](../extensions/enum-class-cpp-component-extensions.md).

## <a name="syntax"></a>Sintaxe

```
// unscoped enum:
enum [identifier] [: type]
{enum-list};

// scoped enum:
enum [class|struct]
[identifier] [: type]
{enum-list};
```

```cpp
// Forward declaration of enumerations  (C++11):
enum A : int; // non-scoped enum must have type specified
enum class B; // scoped enum defaults to int but ...
enum class C : short;  // ... may have any integral underlying type
```

## <a name="parameters"></a>parâmetros

*identifier*<br/>
O nome do tipo dado à enumeração.

*tipo*<br/>
O tipo subjacente dos enumeradores; todos os enumeradores têm o mesmo tipo subjacente. Pode ser qualquer tipo integral.

*lista de enums*<br/>
Uma lista separada por vírgulas dos enumeradores na enumeração. Cada enumerador ou nome de variável no escopo deve ser exclusivo. No entanto, os valores podem ser duplicados. Em uma enumeração sem escopo, o escopo é o escopo ao redor; em uma enumeração com escopo, o escopo é a própria *lista de enums* .  Em uma enumeração com escopo, a lista pode estar vazia, o que, em vigor, define um novo tipo integral.

*class*<br/>
Ao usar essa palavra-chave na declaração, você especifica o escopo da enumeração e um *identificador* deve ser fornecido. Você também pode usar a palavra-chave **struct** no lugar da **classe**, pois elas são semanticamente equivalentes nesse contexto.

## <a name="enumerator-scope"></a>Escopo do enumerador

Uma enumeração fornece o contexto para descrever um intervalo de valores que são representados como constantes nomeadas e que também são chamados de enumeradores. Nos tipos de enum originais de C e C++, os enumeradores não qualificados são visíveis em todo o escopo no qual o enum é declarado. Em enums com escopo, o nome do enumerador deve ser qualificado pelo nome do tipo enum. O exemplo a seguir demonstra essa diferença básica entre os dois tipos de enums:

```cpp
namespace CardGame_Scoped
{
    enum class Suit { Diamonds, Hearts, Clubs, Spades };

    void PlayCard(Suit suit)
    {
        if (suit == Suit::Clubs) // Enumerator must be qualified by enum type
        { /*...*/}
    }
}

namespace CardGame_NonScoped
{
    enum Suit { Diamonds, Hearts, Clubs, Spades };

    void PlayCard(Suit suit)
    {
        if (suit == Clubs) // Enumerator is visible without qualification
        { /*...*/
        }
    }
}
```

Cada nome em uma enumeração recebe um valor integral que corresponde ao seu local na ordem dos valores na enumeração. Por padrão, o primeiro valor é atribuído a 0, o seguinte é atribuído a 1, e assim por diante, mas você pode definir explicitamente o valor de um enumerador, como mostrado aqui:

```cpp
enum Suit { Diamonds = 1, Hearts, Clubs, Spades };
```

O enumerador `Diamonds` recebe o valor `1`. Os enumeradores subsequentes, se não recebem um valor explícito, recebem o valor do enumerador anterior mais um. No exemplo anterior, `Hearts` teria o valor 2, `Clubs` teria 3 e assim por diante.

Cada enumerador é tratado como uma constante e deve ter um nome exclusivo dentro do escopo em que a **Enumeração** é definida (para enumerações sem escopo) ou dentro do próprio **enum** (para enumerações com escopo). Os valores dados para os nomes não devem ser exclusivos. Por exemplo, se a declaração de um enum sem escopo `Suit` for esta:

```cpp
enum Suit { Diamonds = 5, Hearts, Clubs = 4, Spades };
```

Os valores de `Diamonds`, `Hearts`, `Clubs` e `Spades` são 5, 6, 4, e 5, respectivamente. Observe que 5 será usado mais de uma vez; isso é permitido mesmo que não seja pretendido. Essas regras são as mesmas para enums com escopo.

## <a name="casting-rules"></a>Regras de conversão

Constantes de enumeração sem escopo podem ser convertidas implicitamente em **int**, mas um **int** nunca é implicitamente conversível em um valor de enumeração. O exemplo a seguir mostra o que acontece se você tentar atribuir a `hand` um valor que não seja `Suit`:

```cpp
int account_num = 135692;
Suit hand;
hand = account_num; // error C2440: '=' : cannot convert from 'int' to 'Suit'
```

Uma conversão é necessária para converter um **int** em um enumerador com escopo ou sem escopo. No entanto, você pode promover um enumerador para um valor inteiro sem uma conversão.

```cpp
int account_num = Hearts; //OK if Hearts is in a unscoped enum
```

O uso de conversões implícitas dessa maneira pode levar a efeitos colaterais não intencionais. Para ajudar a eliminar erros de programação associados aos enums sem escopo, os valores enum com escopo são fortemente tipados. Os enumeradores com escopo devem ser qualificados pelo nome do tipo enum (identificador) e não podem ser convertidos implicitamente, conforme mostrado no exemplo a seguir:

```cpp
namespace ScopedEnumConversions
{
    enum class Suit { Diamonds, Hearts, Clubs, Spades };

    void AttemptConversions()
    {
        Suit hand;
        hand = Clubs; // error C2065: 'Clubs' : undeclared identifier
        hand = Suit::Clubs; //Correct.
        int account_num = 135692;
        hand = account_num; // error C2440: '=' : cannot convert from 'int' to 'Suit'
        hand = static_cast<Suit>(account_num); // OK, but probably a bug!!!

        account_num = Suit::Hearts; // error C2440: '=' : cannot convert from 'Suit' to 'int'
        account_num = static_cast<int>(Suit::Hearts); // OK
    }
}
```

Observe que a linha `hand = account_num;` ainda causa o erro que ocorre com enums sem escopo, como mostrado anteriormente. É permitido com uma conversão explícita. No entanto, com enums com escopo, a conversão tentada na próxima instrução, `account_num = Suit::Hearts;`, não é mais permitida sem uma conversão explícita.

## <a name="no_enumerators"></a>Enums sem enumeradores

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): ao definir uma enumeração (regular ou com escopo) com um tipo subjacente explícito e nenhum enumerador, você pode, na verdade, introduzir um novo tipo integral que não tenha nenhuma conversão implícita para nenhum outro tipo. Ao usar esse tipo em vez de seu tipo subjacente interno, você pode eliminar o potencial para erros sutis causados por conversões implícitas inadvertidas.

```cpp
enum class byte : unsigned char { };
```

O novo tipo é uma cópia exata do tipo subjacente e, portanto, tem a mesma convenção de chamada, o que significa que ele pode ser usado em ABIs sem nenhuma penalidade de desempenho. Nenhuma conversão é necessária quando as variáveis do tipo são inicializadas usando a inicialização da lista direta. O exemplo a seguir mostra como inicializar enums sem enumeradores em vários contextos:

```cpp
enum class byte : unsigned char { };

enum class E : int { };
E e1{ 0 };
E e2 = E{ 0 };

struct X
{
    E e{ 0 };
    X() : e{ 0 } { }
};

E* p = new E{ 0 };

void f(E e) {};

int main()
{
    f(E{ 0 });
    byte i{ 42 };
    byte j = byte{ 42 };

    // unsigned char c = j; // C2440: 'initializing': cannot convert from 'byte' to 'unsigned char'
    return 0;
}
```

## <a name="see-also"></a>Confira também

[Declarações de enumeração C](../c-language/c-enumeration-declarations.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)