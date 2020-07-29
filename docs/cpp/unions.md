---
title: Uniões
ms.date: 05/06/2019
f1_keywords:
- union_cpp
helpviewer_keywords:
- class types [C++], unions as
- union keyword [C++]
ms.assetid: 25c4e219-fcbb-4b7b-9b64-83f3252a92ca
ms.openlocfilehash: 5010512b2c5f19a236d2f44bd3acf00097a3e168
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213132"
---
# <a name="unions"></a>Uniões

> [!NOTE]
> No C++ 17 e posteriores, a classe **std:: Variant** é uma alternativa de tipo seguro para uniões.

Um **`union`** é um tipo definido pelo usuário no qual todos os membros compartilham o mesmo local de memória. Isso significa que, a qualquer momento determinado, uma União pode conter no máximo um objeto de sua lista de membros. Isso também significa que, independentemente de quantos membros uma União tem, ele sempre usa apenas memória suficiente para armazenar o maior membro.

As uniões podem ser úteis para conservar memória quando você tem muitos objetos e/ou memória limitada. No entanto, eles exigem um cuidado extra para usar corretamente porque você é responsável por garantir que sempre acesse o último membro que foi gravado no. Se qualquer tipo de membro tiver um construtor não trivial, você deverá escrever código adicional para construir e destruir explicitamente esse membro. Antes de usar uma União, considere se o problema que você está tentando resolver pode ser melhor expresso usando uma classe base e classes derivadas.

## <a name="syntax"></a>Sintaxe

```cpp
union [name]  { member-list };
```

### <a name="parameters"></a>parâmetros

*name*<br/>
O nome do tipo dado à união.

*lista de membros*<br/>
Membros que a União pode conter. Consulte Observações.

## <a name="remarks"></a>Comentários

## <a name="declaring-a-union"></a>Declarando uma união

Inicie a declaração de uma União com a **`union`** palavra-chave e coloque a lista de membros entre chaves:

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

## <a name="using-unions"></a>Usando uniões

No exemplo anterior, qualquer código que acessa a União precisa saber qual membro está mantendo os dados. A solução mais comum para esse problema é colocar a União em uma struct junto com um membro enum adicional que indica o tipo dos dados atualmente armazenados na União. Isso é chamado de *união discriminada* e o exemplo a seguir mostra o padrão básico.

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

// Container for all the data records
queue<Input> inputs;
void Initialize();

int main(int argc, char* argv[])
{
    Initialize();
    while (!inputs.empty())
    {
        Input i = inputs.front();
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

void Initialize()
{
    Input first, second;
    first.type = WeatherDataType::Temperature;
    first.temp = { 101, 1418855664, 91.8, 108.5, 67.2 };
    inputs.push(first);

    second.type = WeatherDataType::Wind;
    second.wind = { 204,1418859354, 14, 27 };
    inputs.push(second);
}
```

No exemplo anterior, observe que a União no struct de entrada não tem nenhum nome. Essa é uma União anônima e seus membros podem ser acessados como se fossem membros diretos da estrutura. Para obter mais informações sobre uniões anônimas, consulte a seção abaixo.

É claro que o exemplo anterior mostra um problema que também pode ser resolvido usando classes que derivam de uma classe base comum e ramificando seu código com base no tipo de tempo de execução de cada objeto no contêiner. Isso pode resultar em um código mais fácil de manter e entender, mas também pode ser mais lento do que o uso de uniões. Além disso, com uma União, você pode armazenar tipos completamente não relacionados e alterar dinamicamente o tipo do valor que é armazenado sem alterar o tipo da própria variável Union. Assim, você pode criar uma matriz heterogênea de myuniontype cujos elementos armazenam diferentes valores de tipos diferentes.

Observe que a `Input` estrutura no exemplo anterior pode ser facilmente usada com facilidade. É completamente possível que o usuário use o discriminador corretamente para acessar o membro que contém os dados. Você pode se proteger contra uso indevido, tornando a União privada e fornecendo funções de acesso especiais, conforme mostrado no exemplo a seguir.

## <a name="unrestricted-unions-c11"></a>Uniões irrestritas (C++ 11)

No C++ 03 e versões anteriores, uma União pode conter membros de dados não estáticos com o tipo de classe, desde que o tipo não tenha construtores, destruidores ou operadores de atribuição fornecidos pelo usuário. No C++ 11, essas restrições são removidas. Se você incluir tal membro em sua União, o compilador marcará automaticamente qualquer função de membro especial que não seja fornecida pelo usuário como excluída. Se Union for uma Union anônima dentro de uma classe ou struct, quaisquer funções de membro especiais da classe ou struct que não são fornecidas pelo usuário serão marcadas como excluídas. O exemplo a seguir mostra como lidar com o caso em que um dos membros da União tem um membro que requer esse tratamento especial:

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
#include <queue>
#include <iostream>
using namespace std;

enum class WeatherDataType
{
    Temperature, Wind
};

struct TempData
{
    TempData() : StationId(""), time(0), current(0), maxTemp(0), minTemp(0) {}
    TempData(string id, time_t t, double cur, double max, double min)
        : StationId(id), time(t), current(cur), maxTemp(max), minTemp(0) {}
    string StationId;
    time_t time = 0;
    double current;
    double maxTemp;
    double minTemp;
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
    Input() {}
    Input(const Input&) {}

    ~Input()
    {
        if (type == WeatherDataType::Temperature)
        {
            temp.StationId.~string();
        }
    }

    WeatherDataType type;
    void SetTemp(const TempData& td)
    {
        type = WeatherDataType::Temperature;

        // must use placement new because of string member!
        new(&temp) TempData(td);
    }

    TempData GetTemp()
    {
        if (type == WeatherDataType::Temperature)
            return temp;
        else
            throw logic_error("Can't return TempData when Input holds a WindData");
    }
    void SetWind(WindData wd)
    {
        // Explicitly delete struct member that has a
        // non-trivial constructor
        if (type == WeatherDataType::Temperature)
        {
            temp.StationId.~string();
        }
        wind = wd; //placement new not required.
    }
    WindData GetWind()
    {
        if (type == WeatherDataType::Wind)
        {
            return wind;
        }
        else
            throw logic_error("Can't return WindData when Input holds a TempData");
    }

private:

    union
    {
        TempData temp;
        WindData wind;
    };
};
```

As uniões não podem armazenar referências. As uniões não dão suporte à herança, portanto, uma União em si não pode ser usada como uma classe base ou herdada de outra classe, ou ter funções virtuais.

## <a name="initializing-unions"></a>Inicializando uniões

Você pode declarar e inicializar uma união na mesma instrução atribuindo uma expressão entre chaves. A expressão é avaliada e atribuída ao primeiro campo da união.

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
    cout << Values.dValue) << endl;
}
/* Output:
10
3.141600
*/
```

A união `NumericType` é organizada na memória (conceitualmente) conforme mostrado na figura a seguir.

![Armazenamento de dados em uma União de tipo numérico](../cpp/media/vc38ul1.png "Armazenamento de dados em uma União numérica") <br/>
Armazenamento de dados na união NumericType

## <a name="anonymous-unions"></a><a name="anonymous_unions"></a>Uniões anônimas

As uniões anônimas são uniões declaradas sem uma lista de *nomes de classe* ou *declaradores*.

```cpp
union  {  member-list  }
```

Os nomes declarados em uma união anônima são usados diretamente, como variáveis de não membro. Portanto, os nomes declarados em uma União anônima devem ser exclusivos no escopo ao redor.

Além das restrições para uniões nomeadas, as uniões anônimas estão sujeitas a essas restrições adicionais:

- Eles também devem ser declarados como **`static`** se declarassem no escopo do arquivo ou do namespace.

- Eles podem ter somente **`public`** Membros; **`private`** e **`protected`** os membros em uniões anônimas geram erros.

- Eles não podem ter funções de membro.

## <a name="see-also"></a>Confira também

[Classes e structs](../cpp/classes-and-structs-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[class](../cpp/class-cpp.md)<br/>
[struct](../cpp/struct-cpp.md)
