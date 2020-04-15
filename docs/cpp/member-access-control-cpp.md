---
title: Controle de acesso a membro (C++)
ms.date: 11/19/2018
helpviewer_keywords:
- access control [C++]
- member access [C++]
- member-access control [C++]
ms.assetid: 2d596bca-56ad-4277-94e1-ce3db45fa14a
ms.openlocfilehash: e8f62e82ebb7fcc18be5ac7d203df0fb46c9b635
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369849"
---
# <a name="member-access-control-c"></a>Controle de acesso a membro (C++)

Os controles de acesso permitem separar a interface [pública](../cpp/public-cpp.md) de uma classe dos detalhes de implementação [privada](../cpp/private-cpp.md) e dos membros [protegidos](../cpp/protected-cpp.md) que são apenas para uso por classes derivadas. O especificador de acesso se aplica a todos os membros declarados após ele até que o próximo especificador de acesso seja encontrado.

```cpp
class Point
{
public:
    Point( int, int ) // Declare public constructor.;
    Point();// Declare public default constructor.
    int &x( int ); // Declare public accessor.
    int &y( int ); // Declare public accessor.

private:                 // Declare private state variables.
    int _x;
    int _y;

protected:      // Declare protected function for derived classes only.
    Point ToWindowCoords();
};
```

O acesso padrão é **privado** em uma classe, e **público** em uma estrutura ou união. Os especificadores de acesso em uma classe podem ser usados várias vezes em qualquer ordem. A alocação de armazenamento para objetos de tipos de classe depende da implementação, mas é garantido que os membros receberão endereços de memória sucessivamente mais altos entre especificadores de acesso.

## <a name="member-access-control"></a>Controle de acesso de membros

|Tipo de acesso|Significado|
|--------------------|-------------|
|[particulares](../cpp/private-cpp.md)|Os membros da classe declarados **como privados** só podem ser usados por funções de membros e amigos (classes ou funções) da classe.|
|[protegidos](../cpp/protected-cpp.md)|Os membros da classe declarados **como protegidos** podem ser usados por funções de membros e amigos (classes ou funções) da classe. Além disso, eles podem ser usados por classes derivadas da classe.|
|[públicos](../cpp/public-cpp.md)|Os membros da classe declarados como **públicos** podem ser usados por qualquer função.|

O controle de acesso ajuda a evitar que você use objetos de maneiras que não sejam as destinadas a eles. Essa proteção será perdida quando as conversões de tipo explícitas (casts) forem executadas.

> [!NOTE]
> O controle de acesso é igualmente aplicável a todos os nomes: funções membro, dados de membro, classes aninhadas e enumeradores.

## <a name="access-control-in-derived-classes"></a>Controle de Acesso em Classes Derivadas

Dois fatores controlam quais membros de uma classe base são acessíveis em uma classe derivada; esses mesmos fatores controlam o acesso aos membros herdados na classe derivada:

- Se a classe derivada declara a classe base usando o especificador de acesso **público.**

- Qual é o acesso ao membro na classe base.

A tabela a seguir mostra a interação entre esses fatores e como determinar o acesso do membro da classe base.

### <a name="member-access-in-base-class"></a>Acesso do membro na classe base

|particulares|protegidos|Público|
|-------------|---------------|------------|
|Sempre inacessível independentemente do acesso de derivação|Privado na classe derivada se você usar derivação particular|Privado na classe derivada se você usar derivação particular|
||Protegido na classe derivada se você usar derivação protegida|Protegido na classe derivada se você usar derivação protegida|
||Protegido na classe derivada se você usar derivação pública|Público na classe derivada se você usar derivação pública|

O exemplo a seguir ilustra isso:

```cpp
// access_specifiers_for_base_classes.cpp
class BaseClass
{
public:
    int PublicFunc(); // Declare a public member.
protected:
    int ProtectedFunc(); // Declare a protected member.
private:
    int PrivateFunc(); // Declare a private member.
};

// Declare two classes derived from BaseClass.
class DerivedClass1 : public BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
        PrivateFunc(); // function is inaccessible
    }
};

class DerivedClass2 : private BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
        PrivateFunc(); // function is inaccessible
    }
};

int main()
{
    DerivedClass1 derived_class1;
    DerivedClass2 derived_class2;
    derived_class1.PublicFunc();
    derived_class2.PublicFunc(); // function is inaccessible
}
```

Em `DerivedClass1`, a função de membro `PublicFunc` é um membro público e `ProtectedFunc` é um membro protegido porque `BaseClass` é uma classe base pública. `PrivateFunc` é particular a `BaseClass`, e inacessível a quaisquer classes derivadas.

Em `DerivedClass2`, as funções `PublicFunc` e `ProtectedFunc` são consideradas membros particulares porque `BaseClass` é uma classe base particular. Novamente, `PrivateFunc` é particular a `BaseClass`, e inacessível a quaisquer classes derivadas.

Você pode declarar uma classe derivada sem um especificador de acesso de classe base. Nesse caso, a derivação é considerada privada se a declaração de classe derivada usar a palavra-chave de **classe.** A derivação é considerada pública se a declaração de classe derivada usar a palavra-chave **de estrutura.** Por exemplo, o código a seguir:

```cpp
class Derived : Base
...
```

é equivalente a:

```cpp
class Derived : private Base
...
```

Da mesma forma, o código a seguir:

```cpp
struct Derived : Base
...
```

é equivalente a:

```cpp
struct Derived : public Base
...
```

Observe que os membros declarados como tendo acesso privado não estão acessíveis a funções ou classes derivadas, a menos que essas funções ou classes sejam declaradas usando a declaração **de amigo** na classe base.

Um tipo **de sindicato** não pode ter uma classe base.

> [!NOTE]
> Ao especificar uma classe de base privada, é aconselhável usar explicitamente a palavra-chave **privada** para que os usuários da classe derivada entendam o acesso ao membro.

## <a name="access-control-and-static-members"></a>Controle de acesso e membros estáticos

Quando você especifica uma classe base como **privada,** ela afeta apenas membros não estáticos. Os membros estáticos públicos ainda são acessíveis nas classes derivadas. No entanto, o acesso a membros da classe base usando ponteiros, referências ou objetos pode exigir uma conversão, quando então o controle de acesso é aplicado novamente. Considere o exemplo a seguir:

```cpp
// access_control.cpp
class Base
{
public:
    int Print();             // Nonstatic member.
    static int CountOf();    // Static member.
};

// Derived1 declares Base as a private base class.
class Derived1 : private Base
{
};
// Derived2 declares Derived1 as a public base class.
class Derived2 : public Derived1
{
    int ShowCount();    // Nonstatic member.
};
// Define ShowCount function for Derived2.
int Derived2::ShowCount()
{
   // Call static member function CountOf explicitly.
    int cCount = Base::CountOf();     // OK.

   // Call static member function CountOf using pointer.
    cCount = this->CountOf();  // C2247. Conversion of
                               //  Derived2 * to Base * not
                               //  permitted.
    return cCount;
}
```

No código acima, o controle de acesso proíbe a conversão de um ponteiro para `Derived2` em um ponteiro para `Base`. O **ponteiro deste** ponto `Derived2 *`é implicitamente do tipo . Para selecionar `CountOf` a função, **ela** deve `Base *`ser convertida em tipo . Essa conversão não é permitida porque `Base` é uma classe base indireta privada para `Derived2`. A conversão em um tipo de classe base privada é aceitável apenas no caso de ponteiros para as classes derivadas imediatas. Consequentemente, os ponteiros do tipo `Derived1 *` podem ser convertidos no tipo `Base *`.

Observe que chamar a função `CountOf` explicitamente, sem usar um ponteiro, uma referência ou um objeto para selecioná-la, não implica em nenhuma conversão. Consequentemente, a chamada é permitida.

Os membros e amigos de uma classe derivada, `T`, podem converter um ponteiro para `T` em um ponteiro para uma classe base direta privada de `T`.

## <a name="access-to-virtual-functions"></a>Acesso a funções virtuais

O controle de acesso aplicado às funções [virtuais](../cpp/virtual-cpp.md) é determinado pelo tipo usado para fazer a chamada de função. Substituir declarações da função não afeta o controle de acesso para um determinado tipo. Por exemplo:

```cpp
// access_to_virtual_functions.cpp
class VFuncBase
{
public:
    virtual int GetState() { return _state; }
protected:
    int _state;
};

class VFuncDerived : public VFuncBase
{
private:
    int GetState() { return _state; }
};

int main()
{
   VFuncDerived vfd;             // Object of derived type.
   VFuncBase *pvfb = &vfd;       // Pointer to base type.
   VFuncDerived *pvfd = &vfd;    // Pointer to derived type.
   int State;

   State = pvfb->GetState();     // GetState is public.
   State = pvfd->GetState();     // C2248 error expected; GetState is private;
}
```

No exemplo anterior, chamar a função virtual `GetState` usando um ponteiro para o tipo `VFuncBase` chama `VFuncDerived::GetState`, e `GetState` é tratada como pública. No entanto, chamar `GetState` usando um ponteiro para o tipo `VFuncDerived` é uma violação de controle de acesso porque `GetState` é declarado como particular na classe `VFuncDerived`.

> [!CAUTION]
> A função virtual `GetState` pode ser chamada usando um ponteiro para a classe base `VFuncBase`. Isso não significa que a função chamada seja a versão da classe base dessa função.

## <a name="access-control-with-multiple-inheritance"></a>Controle de acesso com herança múltipla

Em células entrelaçadas de herança múltipla que envolvem classes base virtuais, um nome determinado pode ser acessado por mais de um caminho. Como o controle de acesso diferente pode ser aplicado ao longo desses caminhos diferentes, o compilador escolhe o caminho que fornece o maior acesso. Consulte a figura a seguir.

![Acesso ao longo de caminhos de um gráfico de herança](../cpp/media/vc38v91.gif "Acesso ao longo de caminhos de um gráfico de herança") <br/>
Acesso ao longo de caminhos de um gráfico de herança

Na figura, um nome declarado na classe `VBase` é sempre acessado pela classe `RightPath`. O caminho à direita é mais acessível porque `RightPath` declara `VBase` como uma classe base pública, enquanto que `LeftPath` declara `VBase` como particular.

## <a name="see-also"></a>Confira também

[Referência de linguagem C++](../cpp/cpp-language-reference.md)
