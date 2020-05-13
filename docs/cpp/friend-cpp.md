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
ms.openlocfilehash: 20116674feffaa5b4bbddf707dd3a4d0c1d9ad98
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364437"
---
# <a name="friend-c"></a>friend (C++)

Em algumas circunstâncias, é mais conveniente conceder acesso ao nível dos membros a funções que não são membros de uma classe ou a todos os membros de uma classe separada. Só o implementador de classe pode declarar quem são seus amigos. Uma função ou classe não pode se declarar como um amigo de qualquer classe. Em uma definição de classe, use a palavra-chave **amigo** e o nome de uma função não-membro ou outra classe para conceder-lhe acesso aos membros privados e protegidos de sua classe. Em uma definição de modelo, um parâmetro de tipo pode ser declarado como um amigo.

## <a name="syntax"></a>Sintaxe

```
class friend F
friend F;
```

## <a name="friend-declarations"></a>Declarações de amigos

Se você declarar uma função de amigo que não foi declarada anteriormente, essa função é exportada para o escopo de envolvimento sem classe.

As funções declaradas em uma declaração de amigo são tratadas como se tivessem sido declaradas usando a palavra-chave **extern.** Para obter mais informações, consulte [extern](extern-cpp.md).

Ainda que as funções com escopo global possam ser declaradas como amigos antes dos protótipos, as funções de membro não podem ser declaradas como amigos antes da aparência de sua declaração completa da classe. O exemplo de código a seguir mostra porque isso falha:

```cpp
class ForwardDeclared;   // Class name is known.
class HasFriends
{
    friend int ForwardDeclared::IsAFriend();   // C2039 error expected
};
```

O exemplo anterior insere o nome da classe `ForwardDeclared` no escopo, mas a declaração completa — especificamente, a parte que declara a função `IsAFriend` — não é conhecida. Portanto, a declaração `HasFriends` de **amigo** na aula gera um erro.

A partir de C++11, existem duas formas de declarações de amigos para uma classe:

```cpp
friend class F;
friend F;
```

A primeira forma introduz uma nova classe F se nenhuma classe existente com esse nome foi encontrada no namespace mais íntimo. **C++11**: A segunda forma não introduz uma nova classe; ele pode ser usado quando a classe já foi declarada, e deve ser usada ao declarar um parâmetro de tipo de modelo ou um typedef como um amigo.

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

No exemplo a `friend F` seguir, `F` refere-se à classe que é declarada fora do escopo do NS.

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

Use `friend F` para declarar um typedef como amigo:

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

Uma função **de amigo** é uma função que não é membro de uma classe, mas tem acesso aos membros privados e protegidos da classe. As funções friend não são consideradas membros de classe; elas são funções externas normais que recebem privilégios de acesso especiais. Os amigos não estão no escopo da classe, e eles não são chamados usando os operadores de seleção de membros (**.** e**>**- ) a menos que sejam membros de outra classe. Uma função **de amigo** é declarada pela classe que está concedendo acesso. A declaração **do amigo** pode ser colocada em qualquer lugar da declaração da classe. Ela não é afetada pelas palavras-chave de controle de acesso.

O exemplo a seguir mostra uma classe `Point` e uma função friend, `ChangePrivate`. A função **amigo** tem acesso ao `Point` membro de dados privados do objeto que recebe como parâmetro.

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

No exemplo anterior, somente a função `A::Func1( B& )` tem acesso de amigo para classificar `B`. Portanto, o acesso ao `_b` membro `Func1` privado `A` é correto `Func2`na classe, mas não em .

Uma classe `friend` é uma classe cujas funções membro são as funções amigas de uma classe, ou seja, cujas funções membro tenham acesso aos outros membros particulares e protegidos da classe. Suponha que a declaração `friend` na classe `B` fosse:

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

Um tipo gerenciado (em C++/CLI) não pode ter funções de amigos, classes de amigos ou interfaces de amigos.

A amizade não é herdada, o que significa que as classes derivadas de `YourOtherClass` não podem acessar os membros privados de `YourClass`. A amizade não é transitiva, assim as classes que são amigos de `YourOtherClass` não podem acessar membros privados de `YourClass`.

A figura a seguir mostra quatro declarações de classe: `Base`, `Derived`, `aFriend` e `anotherFriend`. Somente a classe `aFriend` tem acesso direto aos membros privados de `Base` (e a todos os membros que `Base` pode ter herdado).

![Implicações da relação de amigos](../cpp/media/vc38v41.gif "Implicações da relação de amigos") <br/>
Implicações da relação de amigos

## <a name="inline-friend-definitions"></a>Definições de amigos inline

As funções do amigo podem ser definidas (dado um corpo função) dentro das declarações de classe. Essas funções são funções embutidas, e como funções membro embutidas, se comportam como se fossem definidas imediatamente após todos os membros de classe terem sido vistos, mas antes que o escopo de classe seja fechado (o final da declaração de classe). As funções de amigos que são definidas dentro das declarações de classe estão no escopo da classe de encerramento.

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
