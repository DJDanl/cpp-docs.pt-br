---
title: union
description: Uma descrição do tipo C++ padrão union class e da palavra-chave, seu uso e restrições.
ms.date: 08/18/2020
f1_keywords:
- union_cpp
helpviewer_keywords:
- class type [C++], union as
- union keyword [C++]
ms.assetid: 25c4e219-fcbb-4b7b-9b64-83f3252a92ca
no-loc:
- union
- struct
- enum
- class
- static
ms.openlocfilehash: a4dc07df5e7858dffe62478509ee1d8dc759ce96
ms.sourcegitcommit: f1752bf90b4f869633a859ace85439ca19e208b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/21/2020
ms.locfileid: "88722174"
---
# `union`

> [!NOTE]
> No C++ 17 e posterior, a `std::variant` class é uma alternativa de tipo seguro para um union .

Um **`union`** é um tipo definido pelo usuário no qual todos os membros compartilham o mesmo local de memória. Essa definição significa que, a qualquer momento, um union não pode conter mais de um objeto de sua lista de membros. Isso também significa que, independentemente de quantos membros a union têm, ele sempre usa apenas memória suficiente para armazenar o maior membro.

Um union pode ser útil para conservar memória quando você tem muitos objetos e memória limitada. No entanto, um union requer um cuidado extra com o uso correto. Você é responsável por garantir que sempre acesse o mesmo membro que você atribuiu. Se qualquer tipo de membro tiver uma con não trivial struct ou, então, você deverá escrever código adicional para con explicitamente struct e destruir esse membro. Antes de usar um union , considere se o problema que você está tentando resolver pode ser melhor expresso com o uso de class tipos base e derivados class .

## <a name="syntax"></a>Sintaxe

> **`union`***`tag`* <sub>opt</sub> **`{`** aceitar *`member-list`***`};`**

### <a name="parameters"></a>Parâmetros

*`tag`*<br/>
O nome do tipo fornecido para o union .

*`member-list`*<br/>
Membros que o union pode conter.

## <a name="declare-a-no-locunion"></a>Declarar um union

Inicie a declaração de um union usando a **`union`** palavra-chave e coloque a lista de membros entre chaves:

```cpp
// declaring_a_union.cpp
union RecordType    // Declare a simple union type
{
    char   ch;
    int    i;
    long   l;
    float  f;
    double d;
    int *int_ptr;
};

int main()
{
    RecordType t;
    t.i = 5; // t holds an int
    t.f = 7.25; // t now holds a float
}
```

## <a name="use-a-no-locunion"></a>Usar um union

No exemplo anterior, qualquer código que acessa o union precisa saber qual membro contém os dados. A solução mais comum para esse problema é chamada de *discriminado union *. Ele engloba o union em struct e inclui um enum membro que indica o tipo de membro atualmente armazenado no union . O exemplo a seguir mostra o padrão básico:

```cpp
#include <queue>

using namespace std;

enum class WeatherDataType
{
    Temperature, Wind
};

struct TempData
{
    int StationId;
    time_t time;
    double current;
    double max;
    double min;
};

struct WindData
{
    int StationId;
    time_t time;
    int speed;
    short direction;
};

struct Input
{
    WeatherDataType type;
    union
    {
        TempData temp;
        WindData wind;
    };
};

// Functions that are specific to data types
void Process_Temp(TempData t) {}
void Process_Wind(WindData w) {}

void Initialize(std::queue<Input>& inputs)
{
    Input first;
    first.type = WeatherDataType::Temperature;
    first.temp = { 101, 1418855664, 91.8, 108.5, 67.2 };
    inputs.push(first);

    Input second;
    second.type = WeatherDataType::Wind;
    second.wind = { 204, 1418859354, 14, 27 };
    inputs.push(second);
}

int main(int argc, char* argv[])
{
    // Container for all the data records
    queue<Input> inputs;
    Initialize(inputs);
    while (!inputs.empty())
    {
        Input const i = inputs.front();
        switch (i.type)
        {
        case WeatherDataType::Temperature:
            Process_Temp(i.temp);
            break;
        case WeatherDataType::Wind:
            Process_Wind(i.wind);
            break;
        default:
            break;
        }
        inputs.pop();

    }
    return 0;
}
```

No exemplo anterior, o union no `Input` struct não tem nome, portanto, ele é chamado de *anônimo* union . Seus membros podem ser acessados diretamente como se fossem membros do struct . Para obter mais informações sobre como usar um anônimo union , consulte a [seção union anônima](#anonymous_unions) .

O exemplo anterior mostra um problema que você também pode resolver usando class tipos que derivam de uma base comum class . Você pode ramificar seu código com base no tipo de tempo de execução de cada objeto no contêiner. Seu código pode ser mais fácil de manter e entender, mas também pode ser mais lento do que usar um union . Além disso, com um union , você pode armazenar tipos não relacionados. Um union permite que você altere dinamicamente o tipo do valor armazenado sem alterar o tipo da union variável em si. Por exemplo, você pode criar uma matriz heterogênea de `MyUnionType` , cujos elementos armazenam valores diferentes de tipos diferentes.

É fácil refazer o uso indevido do `Input` struct exemplo. Cabe ao usuário usar o discriminador corretamente para acessar o membro que contém os dados. Você pode se proteger contra uso indevido, fazendo o union **`private`** e fornecendo funções de acesso especiais, conforme mostrado no exemplo a seguir.

## <a name="unrestricted-no-locunion-c11"></a>Irrestrito union (c++ 11)

No C++ 03 e versões anteriores, um union pode conter membros que não são de static dados que têm um class tipo, desde que o tipo não tenha um usuário que tenha fornecido o struct ORS, de struct ORS nem de operadores de atribuição. No C++ 11, essas restrições são removidas. Se você incluir tal membro em seu union , o compilador marcará automaticamente qualquer função de membro especial que não seja fornecida pelo usuário como **`deleted`** . Se o union for um anônimo union dentro de um class ou struct , qualquer função de membro especial do class ou struct que não seja fornecida pelo usuário será marcada como **`deleted`** . O exemplo a seguir mostra como lidar com esse caso. Um dos membros do union tem um membro que exige esse tratamento especial:

```cpp
// for MyVariant
#include <crtdbg.h>
#include <new>
#include <utility>

// for sample objects and output
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct A
{
    A() = default;
    A(int i, const string& str) : num(i), name(str) {}

    int num;
    string name;
    //...
};

struct B
{
    B() = default;
    B(int i, const string& str) : num(i), name(str) {}

    int num;
    string name;
    vector<int> vec;
    // ...
};

enum class Kind { None, A, B, Integer };

#pragma warning (push)
#pragma warning(disable:4624)
class MyVariant
{
public:
    MyVariant()
        : kind_(Kind::None)
    {
    }

    MyVariant(Kind kind)
        : kind_(kind)
    {
        switch (kind_)
        {
        case Kind::None:
            break;
        case Kind::A:
            new (&a_) A();
            break;
        case Kind::B:
            new (&b_) B();
            break;
        case Kind::Integer:
            i_ = 0;
            break;
        default:
            _ASSERT(false);
            break;
        }
    }

    ~MyVariant()
    {
        switch (kind_)
        {
        case Kind::None:
            break;
        case Kind::A:
            a_.~A();
            break;
        case Kind::B:
            b_.~B();
            break;
        case Kind::Integer:
            break;
        default:
            _ASSERT(false);
            break;
        }
        kind_ = Kind::None;
    }

    MyVariant(const MyVariant& other)
        : kind_(other.kind_)
    {
        switch (kind_)
        {
        case Kind::None:
            break;
        case Kind::A:
            new (&a_) A(other.a_);
            break;
        case Kind::B:
            new (&b_) B(other.b_);
            break;
        case Kind::Integer:
            i_ = other.i_;
            break;
        default:
            _ASSERT(false);
            break;
        }
    }

    MyVariant(MyVariant&& other)
        : kind_(other.kind_)
    {
        switch (kind_)
        {
        case Kind::None:
            break;
        case Kind::A:
            new (&a_) A(move(other.a_));
            break;
        case Kind::B:
            new (&b_) B(move(other.b_));
            break;
        case Kind::Integer:
            i_ = other.i_;
            break;
        default:
            _ASSERT(false);
            break;
        }
        other.kind_ = Kind::None;
    }

    MyVariant& operator=(const MyVariant& other)
    {
        if (&other != this)
        {
            switch (other.kind_)
            {
            case Kind::None:
                this->~MyVariant();
                break;
            case Kind::A:
                *this = other.a_;
                break;
            case Kind::B:
                *this = other.b_;
                break;
            case Kind::Integer:
                *this = other.i_;
                break;
            default:
                _ASSERT(false);
                break;
            }
        }
        return *this;
    }

    MyVariant& operator=(MyVariant&& other)
    {
        _ASSERT(this != &other);
        switch (other.kind_)
        {
        case Kind::None:
            this->~MyVariant();
            break;
        case Kind::A:
            *this = move(other.a_);
            break;
        case Kind::B:
            *this = move(other.b_);
            break;
        case Kind::Integer:
            *this = other.i_;
            break;
        default:
            _ASSERT(false);
            break;
        }
        other.kind_ = Kind::None;
        return *this;
    }

    MyVariant(const A& a)
        : kind_(Kind::A), a_(a)
    {
    }

    MyVariant(A&& a)
        : kind_(Kind::A), a_(move(a))
    {
    }

    MyVariant& operator=(const A& a)
    {
        if (kind_ != Kind::A)
        {
            this->~MyVariant();
            new (this) MyVariant(a);
        }
        else
        {
            a_ = a;
        }
        return *this;
    }

    MyVariant& operator=(A&& a)
    {
        if (kind_ != Kind::A)
        {
            this->~MyVariant();
            new (this) MyVariant(move(a));
        }
        else
        {
            a_ = move(a);
        }
        return *this;
    }

    MyVariant(const B& b)
        : kind_(Kind::B), b_(b)
    {
    }

    MyVariant(B&& b)
        : kind_(Kind::B), b_(move(b))
    {
    }

    MyVariant& operator=(const B& b)
    {
        if (kind_ != Kind::B)
        {
            this->~MyVariant();
            new (this) MyVariant(b);
        }
        else
        {
            b_ = b;
        }
        return *this;
    }

    MyVariant& operator=(B&& b)
    {
        if (kind_ != Kind::B)
        {
            this->~MyVariant();
            new (this) MyVariant(move(b));
        }
        else
        {
            b_ = move(b);
        }
        return *this;
    }

    MyVariant(int i)
        : kind_(Kind::Integer), i_(i)
    {
    }

    MyVariant& operator=(int i)
    {
        if (kind_ != Kind::Integer)
        {
            this->~MyVariant();
            new (this) MyVariant(i);
        }
        else
        {
            i_ = i;
        }
        return *this;
    }

    Kind GetKind() const
    {
        return kind_;
    }

    A& GetA()
    {
        _ASSERT(kind_ == Kind::A);
        return a_;
    }

    const A& GetA() const
    {
        _ASSERT(kind_ == Kind::A);
        return a_;
    }

    B& GetB()
    {
        _ASSERT(kind_ == Kind::B);
        return b_;
    }

    const B& GetB() const
    {
        _ASSERT(kind_ == Kind::B);
        return b_;
    }

    int& GetInteger()
    {
        _ASSERT(kind_ == Kind::Integer);
        return i_;
    }

    const int& GetInteger() const
    {
        _ASSERT(kind_ == Kind::Integer);
        return i_;
    }

private:
    Kind kind_;
    union
    {
        A a_;
        B b_;
        int i_;
    };
};
#pragma warning (pop)

int main()
{
    A a(1, "Hello from A");
    B b(2, "Hello from B");

    MyVariant mv_1 = a;

    cout << "mv_1 = a: " << mv_1.GetA().name << endl;
    mv_1 = b;
    cout << "mv_1 = b: " << mv_1.GetB().name << endl;
    mv_1 = A(3, "hello again from A");
    cout << R"aaa(mv_1 = A(3, "hello again from A"): )aaa" << mv_1.GetA().name << endl;
    mv_1 = 42;
    cout << "mv_1 = 42: " << mv_1.GetInteger() << endl;

    b.vec = { 10,20,30,40,50 };

    mv_1 = move(b);
    cout << "After move, mv_1 = b: vec.size = " << mv_1.GetB().vec.size() << endl;

    cout << endl << "Press a letter" << endl;
    char c;
    cin >> c;
}
```

Um union não pode armazenar uma referência. Um union também não dá suporte à herança. Isso significa que você não pode usar um union como base class , ou herdar de outro class , ou ter funções virtuais.

## <a name="initialize-a-no-locunion"></a>Inicializar um union

Você pode declarar e inicializar um union na mesma instrução atribuindo uma expressão entre chaves. A expressão é avaliada e atribuída ao primeiro campo do union .

```cpp
#include <iostream>
using namespace std;

union NumericType
{
    short       iValue;
    long        lValue;
    double      dValue;
};

int main()
{
    union NumericType Values = { 10 };   // iValue = 10
    cout << Values.iValue << endl;
    Values.dValue = 3.1416;
    cout << Values.dValue << endl;
}
/* Output:
10
3.141600
*/
```

O `NumericType` union é organizado na memória (conceitualmente), conforme mostrado na figura a seguir.

![Armazenamento de dados em um tipo numérico::: no-Loc (Union):::](../cpp/media/vc38ul1.png "Armazenamento de dados em um Numerictype::: no-Loc (Union):::") <br/>
Armazenamento de dados em um `NumericType`union

## <a name="anonymous-no-locunion"></a><a name="anonymous_unions"></a> Modo union

Um anônimo union é um declarado sem um *`class-name`* ou *`declarator-list`* .

> **`union  {`**  *`member-list`*  **`}`**

Nomes declarados em um anônimo union são usados diretamente, como variáveis não membro. Isso implica que os nomes declarados em um anônimo union devem ser exclusivos no escopo ao redor.

Um anônimo union está sujeito a essas restrições adicionais:

- Se declarado em escopo de arquivo ou de namespace, ele também deve ser declarado como **`static`** .

- Ele só pode ter **`public`** Membros; ter **`private`** e **`protected`** Membros em um anônimo union geram erros.

- Ele não pode ter funções de membro.

## <a name="see-also"></a>Consulte também

[Classes e structs](../cpp/classes-and-structs-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[`class`](../cpp/class-cpp.md)<br/>
[`struct`](../cpp/struct-cpp.md)
