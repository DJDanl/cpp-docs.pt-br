---
title: friend (C++)
ms.date: 07/15/2019
f1_keywords:
- friend_cpp
helpviewer_keywords:
- member access, from friend functions
- friend classes [C++]
- friend keyword [C++]
ms.assetid: 8fe9ee55-d56f-40cd-9075-d9fb1375aff4
ms.openlocfilehash: 772eada8257917a6127b15ea2e50946aebb3bc74
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227459"
---
# <a name="friend-c"></a>friend (C++)

Em algumas circunstâncias, é mais conveniente conceder acesso em nível de membro a funções que não são membros de uma classe ou a todos os membros em uma classe separada. Somente o implementador de classe pode declarar quem são seus amigos. Uma função ou classe não pode se declarar como um amigo de qualquer classe. Em uma definição de classe, use a **`friend`** palavra-chave e o nome de uma função não membro ou outra classe para conceder a ela acesso aos membros privados e protegidos da sua classe. Em uma definição de modelo, um parâmetro de tipo pode ser declarado como um amigo.

## <a name="syntax"></a>Sintaxe

```
class friend F
friend F;
```

## <a name="friend-declarations"></a>Declarações Friend

Se você declarar uma função de amigo que não foi declarada anteriormente, essa função é exportada para o escopo de envolvimento sem classe.

As funções declaradas em uma declaração Friend são tratadas como se tivessem sido declaradas usando a **`extern`** palavra-chave. Para obter mais informações, consulte [extern](extern-cpp.md).

Ainda que as funções com escopo global possam ser declaradas como amigos antes dos protótipos, as funções de membro não podem ser declaradas como amigos antes da aparência de sua declaração completa da classe. O exemplo de código a seguir mostra porque isso falha:

```cpp
class ForwardDeclared;   // Class name is known.
class HasFriends
{
    friend int ForwardDeclared::IsAFriend();   // C2039 error expected
};
```

O exemplo anterior insere o nome da classe `ForwardDeclared` no escopo, mas a declaração completa — especificamente, a parte que declara a função `IsAFriend` — não é conhecida. Portanto, a **`friend`** declaração na classe `HasFriends` gera um erro.

A partir do C++ 11, há duas formas de declarações Friend para uma classe:

```cpp
friend class F;
friend F;
```

O primeiro formulário apresenta uma nova classe F se nenhuma classe existente com esse nome foi encontrada no namespace mais interno. **C++ 11**: o segundo formulário não introduz uma nova classe; Ele pode ser usado quando a classe já foi declarada e deve ser usada ao declarar um parâmetro de tipo de modelo ou um typedef como um Friend.

Use `class friend F` quando o tipo referenciado ainda não tiver sido declarado:

```cpp
namespace NS
{
    class M
    {
        class friend F;  // Introduces F but doesn't define it
    };
}
```

```cpp
namespace NS
{
    class M
    {
        friend F; // error C2433: 'NS::F': 'friend' not permitted on data declarations
    };
}
```

No exemplo a seguir, `friend F` refere-se à `F` classe declarada fora do escopo do NS.

```cpp
class F {};
namespace NS
{
    class M
    {
        friend F;  // OK
    };
}
```

Use `friend F` para declarar um parâmetro de modelo como um amigo:

```cpp
template <typename T>
class my_class
{
    friend T;
    //...
};
```

Use `friend F` para declarar um typedef como Friend:

```cpp
class Foo {};
typedef Foo F;

class G
{
    friend F; // OK
    friend class F // Error C2371 -- redefinition
};
```

Para declarar duas classes que são amigas da outro, a segunda classe inteira deve ser especificada como amiga de primeira classe. A razão para essa restrição é que o compilador tem informações suficientes para declarar funções individuais de amigo somente no ponto onde a segunda classe é declarada.

> [!NOTE]
> Embora a segunda classe inteira deve ser amiga da primeira classe, você pode selecionar quais funções na primeira classe serão amigas da segunda classe.

## <a name="friend-functions"></a>funções friend

Uma **`friend`** função é uma função que não é um membro de uma classe, mas tem acesso aos membros privados e protegidos da classe. As funções friend não são consideradas membros de classe; elas são funções externas normais que recebem privilégios de acesso especiais. Os amigos não estão no escopo da classe e não são chamados usando os operadores de seleção de Membros (**.** and- **>** ) a menos que sejam membros de outra classe. Uma **`friend`** função é declarada pela classe que está concedendo acesso. A **`friend`** declaração pode ser colocada em qualquer lugar na declaração de classe. Ela não é afetada pelas palavras-chave de controle de acesso.

O exemplo a seguir mostra uma classe `Point` e uma função friend, `ChangePrivate`. A **`friend`** função tem acesso ao membro de dados privados do `Point` objeto que recebe como um parâmetro.

```cpp
// friend_functions.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class Point
{
    friend void ChangePrivate( Point & );
public:
    Point( void ) : m_i(0) {}
    void PrintPrivate( void ){cout << m_i << endl; }

private:
    int m_i;
};

void ChangePrivate ( Point &i ) { i.m_i++; }

int main()
{
   Point sPoint;
   sPoint.PrintPrivate();
   ChangePrivate(sPoint);
   sPoint.PrintPrivate();
// Output: 0
           1
}
```

## <a name="class-members-as-friends"></a>Membros da classe como amigos

As funções de membro da classe podem ser declaradas como amigos em outras classes. Considere o exemplo a seguir:

```cpp
// classes_as_friends1.cpp
// compile with: /c
class B;

class A {
public:
   int Func1( B& b );

private:
   int Func2( B& b );
};

class B {
private:
   int _b;

   // A::Func1 is a friend function to class B
   // so A::Func1 has access to all members of B
   friend int A::Func1( B& );
};

int A::Func1( B& b ) { return b._b; }   // OK
int A::Func2( B& b ) { return b._b; }   // C2248
```

No exemplo anterior, somente a função `A::Func1( B& )` tem acesso de amigo para classificar `B`. Portanto, o acesso ao membro privado `_b` está correto na `Func1` classe `A` , mas não no `Func2` .

Uma **`friend`** classe é uma classe que todas as funções de membro são funções Friend de uma classe, ou seja, cujas funções de membro têm acesso aos membros privados e protegidos da outra classe. Suponha que a **`friend`** declaração na classe `B` tenha sido:

```cpp
friend class A;
```

Nesse caso, todas as funções membro na classe `A` receberão acesso de amigo para classificar `B`. O código a seguir é um exemplo de uma classe de amigo:

```cpp
// classes_as_friends2.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class YourClass {
friend class YourOtherClass;  // Declare a friend class
public:
   YourClass() : topSecret(0){}
   void printMember() { cout << topSecret << endl; }
private:
   int topSecret;
};

class YourOtherClass {
public:
   void change( YourClass& yc, int x ){yc.topSecret = x;}
};

int main() {
   YourClass yc1;
   YourOtherClass yoc1;
   yc1.printMember();
   yoc1.change( yc1, 5 );
   yc1.printMember();
}
```

A amizade não é mútua a menos que explicitamente especificada como tal. No exemplo anterior, as funções membro de `YourClass` não podem acessar os membros privados de `YourOtherClass`.

Um tipo gerenciado (em C++/CLI) não pode ter nenhuma função Friend, Friend classes ou Friend interfaces.

A amizade não é herdada, o que significa que as classes derivadas de `YourOtherClass` não podem acessar os membros privados de `YourClass`. A amizade não é transitiva, assim as classes que são amigos de `YourOtherClass` não podem acessar membros privados de `YourClass`.

A figura a seguir mostra quatro declarações de classe: `Base`, `Derived`, `aFriend` e `anotherFriend`. Somente a classe `aFriend` tem acesso direto aos membros privados de `Base` (e a todos os membros que `Base` pode ter herdado).

![Implicações da relação Friend](../cpp/media/vc38v41.gif "Implicações da relação Friend") <br/>
Implicações da relação Friend

## <a name="inline-friend-definitions"></a>Definições de amigo embutido

As funções Friend podem ser definidas (dadas um corpo de função) dentro de declarações de classe. Essas funções são funções embutidas, e como funções membro embutidas, se comportam como se fossem definidas imediatamente após todos os membros de classe terem sido vistos, mas antes que o escopo de classe seja fechado (o final da declaração de classe). Funções Friend definidas dentro de declarações de classe estão no escopo da classe delimitadora.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
