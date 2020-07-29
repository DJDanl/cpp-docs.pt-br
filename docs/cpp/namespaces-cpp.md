---
title: Namespaces (C++)
ms.date: 08/30/2017
f1_keywords:
- namespace_CPP
- using_CPP
helpviewer_keywords:
- namespaces [C++]
ms.assetid: d1a5a9ab-1cad-47e6-a82d-385bb77f4188
ms.openlocfilehash: 234df334a8c385859440175cb9a1aab5b2e26ead
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227290"
---
# <a name="namespaces-c"></a>Namespaces (C++)

Um namespace é uma região declarativa que fornece um escopo para os identificadores (os nomes de tipos, funções, variáveis, etc) dentro dele. Os namespaces são usados para organizar o código em grupos lógicos e para evitar colisões de nomes que podem ocorrer especialmente quando sua base de código inclui várias bibliotecas. Todos os identificadores no escopo do namespace são visíveis entre si sem qualificação. Os identificadores fora do namespace podem acessar os membros usando o nome totalmente qualificado para cada identificador, por exemplo `std::vector<std::string> vec;` , ou por uma [declaração using](../cpp/using-declaration.md) para um único identificador ( `using std::string` ) ou uma [diretiva using](../cpp/namespaces-cpp.md#using_directives) para todos os identificadores no namespace ( `using namespace std;` ). O código nos arquivos de cabeçalho sempre deve usar o nome totalmente qualificado do namespace.

O exemplo a seguir mostra uma declaração de namespace e três maneiras que o código fora do namespace pode acessar seus membros.

```cpp
namespace ContosoData
{
    class ObjectManager
    {
    public:
        void DoSomething() {}
    };
    void Func(ObjectManager) {}
}
```

Use o nome totalmente qualificado:

```cpp
ContosoData::ObjectManager mgr;
mgr.DoSomething();
ContosoData::Func(mgr);
```

Use uma declaração using para colocar um identificador no escopo:

```cpp
using ContosoData::ObjectManager;
ObjectManager mgr;
mgr.DoSomething();
```

Use uma diretiva using para trazer tudo no namespace para o escopo:

```cpp
using namespace ContosoData;

ObjectManager mgr;
mgr.DoSomething();
Func(mgr);
```

## <a name="using-directives"></a><a id="using_directives"></a>usando diretivas

A **`using`** diretiva permite que todos os nomes em um **`namespace`** sejam usados sem o *nome do namespace* como um qualificador explícito. Use uma diretiva using em um arquivo de implementação (ou seja, *. cpp) se você estiver usando vários identificadores diferentes em um namespace; Se você estiver usando apenas um ou dois identificadores, considere uma declaração using para colocar apenas esses identificadores no escopo e não todos os identificadores no namespace. Se uma variável local tiver o mesmo nome de uma variável de namespace, a variável de namespace será oculta. É um erro ter uma variável de namespace com o mesmo nome de uma variável global.

> [!NOTE]
> Uma diretiva using pode ser colocada na parte superior de um arquivo. cpp (no escopo do arquivo) ou dentro de uma definição de classe ou função.
>
> Em geral, evite colocar diretivas em arquivos de cabeçalho (*. h) porque qualquer arquivo que inclua esse cabeçalho colocará tudo no namespace no escopo, o que pode causar a ocultação de nomes e problemas de colisão de nomes que são muito difíceis de depurar. Sempre use nomes totalmente qualificados em um arquivo de cabeçalho. Se esses nomes forem muito longos, você poderá usar um alias de namespace para encurtá-los. (Veja abaixo.)

## <a name="declaring-namespaces-and-namespace-members"></a>Declarando namespaces e membros de namespace

Normalmente, você declara um namespace em um arquivo de cabeçalho. Se as implementações de função estiverem em um arquivo separado, qualifique os nomes de função, como neste exemplo.

```cpp
//contosoData.h
#pragma once
namespace ContosoDataServer
{
    void Foo();
    int Bar();
}
```

Implementações de função em contosodata. cpp devem usar o nome totalmente qualificado, mesmo que você coloque uma **`using`** diretiva na parte superior do arquivo:

```cpp
#include "contosodata.h"
using namespace ContosoDataServer;

void ContosoDataServer::Foo() // use fully-qualified name here
{
   // no qualification needed for Bar()
   Bar();
}

int ContosoDataServer::Bar(){return 0;}
```

Um namespace pode ser declarado em vários blocos em um único arquivo e em vários arquivos. O compilador une as partes durante o pré-processamento e o namespace resultante contém todos os membros declarados em todas as partes. Um exemplo disso é o namespace padrão que é declarado em cada um dos arquivos de cabeçalho na biblioteca padrão.

Os membros de um namespace nomeado podem ser definidos fora do namespace em que são declarados pela qualificação explícita de nome que está sendo definido. No entanto, a definição deve aparecer após o ponto de declaração em um namespace que inclui o namespace da declaração. Por exemplo:

```cpp
// defining_namespace_members.cpp
// C2039 expected
namespace V {
    void f();
}

void V::f() { }        // ok
void V::g() { }        // C2039, g() is not yet a member of V

namespace V {
    void g();
}
```

Esse erro pode ocorrer quando os membros do namespace são declarados em vários arquivos de cabeçalho, e você não incluiu esses cabeçalhos na ordem correta.

## <a name="the-global-namespace"></a>O namespace global

Se um identificador não for declarado em um namespace explícito, ele será parte do namespace global implícito. Em geral, tente evitar fazer declarações no escopo global quando possível, exceto para a [função principal](../c-language/main-function-and-program-execution.md)do ponto de entrada, que deve estar no namespace global. Para qualificar explicitamente um identificador global, use o operador de resolução de escopo sem nome, como em `::SomeFunction(x);` . Isso diferenciará o identificador de qualquer coisa com o mesmo nome em qualquer outro namespace e também ajudará a facilitar o seu código para outras pessoas entenderem.

## <a name="the-std-namespace"></a>O namespace std

Todas as funções e tipos de biblioteca padrão do C++ são declarados no `std` namespace ou namespaces aninhados dentro de `std` .

## <a name="nested-namespaces"></a>Namespaces aninhados

Os namespaces podem estar aninhados. Um namespace aninhado comum tem acesso não qualificado aos membros de seus pais, mas os membros pai não têm acesso não qualificado ao namespace aninhado (a menos que seja declarado como embutido), conforme mostrado no exemplo a seguir:

```cpp
namespace ContosoDataServer
{
    void Foo();

    namespace Details
    {
        int CountImpl;
        void Ban() { return Foo(); }
    }

    int Bar(){...};
    int Baz(int i) { return Details::CountImpl; }
}
```

Namespaces aninhados comuns podem ser usados para encapsular detalhes de implementação internos que não fazem parte da interface pública do namespace pai.

## <a name="inline-namespaces-c-11"></a>Namespaces embutidos (C++ 11)

Ao contrário de um namespace aninhado comum, os membros de um namespace embutido são tratados como membros do namespace pai. Essa característica permite que a pesquisa dependente de argumento em funções sobrecarregadas funcionem em funções que têm sobrecargas em um namespace pai e aninhado embutido. Ele também permite que você declare uma especialização em um namespace pai para um modelo declarado no namespace embutido. O exemplo a seguir mostra como o código externo é associado ao namespace embutido por padrão:

```cpp
//Header.h
#include <string>

namespace Test
{
    namespace old_ns
    {
        std::string Func() { return std::string("Hello from old"); }
    }

    inline namespace new_ns
    {
        std::string Func() { return std::string("Hello from new"); }
    }
}

#include "header.h"
#include <string>
#include <iostream>

int main()
{
    using namespace Test;
    using namespace std;

    string s = Func();
    std::cout << s << std::endl; // "Hello from new"
    return 0;
}
```

O exemplo a seguir mostra como você pode declarar uma especialização em um pai de um modelo que é declarado em um namespace embutido:

```cpp
namespace Parent
{
    inline namespace new_ns
    {
         template <typename T>
         struct C
         {
             T member;
         };
    }
     template<>
     class C<int> {};
}
```

Você pode usar namespaces embutidos como um mecanismo de controle de versão para gerenciar alterações na interface pública de uma biblioteca. Por exemplo, você pode criar um único namespace pai e encapsular cada versão da interface em seu próprio namespace aninhado dentro do pai. O namespace que contém a versão mais recente ou preferida é qualificado como embutido e, portanto, é exposto como se fosse um membro direto do namespace pai. O código do cliente que invoca a classe pai:: será automaticamente associado ao novo código. Os clientes que preferem usar a versão mais antiga ainda podem acessá-lo usando o caminho totalmente qualificado para o namespace aninhado que tem esse código.

A palavra-chave inline deve ser aplicada à primeira declaração do namespace em uma unidade de compilação.

O exemplo a seguir mostra duas versões de uma interface, cada uma em um namespace aninhado. O `v_20` namespace tem alguma modificação da `v_10` interface e está marcado como embutido. O código do cliente que usa a nova biblioteca e as chamadas `Contoso::Funcs::Add` invocará a versão v_20. O código que tenta chamar `Contoso::Funcs::Divide` agora receberá um erro de tempo de compilação. Se eles realmente precisarem dessa função, eles ainda poderão acessar a `v_10` versão chamando explicitamente `Contoso::v_10::Funcs::Divide` .

```cpp
namespace Contoso
{
    namespace v_10
    {
        template <typename T>
        class Funcs
        {
        public:
            Funcs(void);
            T Add(T a, T b);
            T Subtract(T a, T b);
            T Multiply(T a, T b);
            T Divide(T a, T b);
        };
    }

    inline namespace v_20
    {
        template <typename T>
        class Funcs
        {
        public:
            Funcs(void);
            T Add(T a, T b);
            T Subtract(T a, T b);
            T Multiply(T a, T b);
            std::vector<double> Log(double);
            T Accumulate(std::vector<T> nums);
      };
    }
}
```

## <a name="namespace-aliases"></a><a id="namespace_aliases"></a>Aliases de namespace

Os nomes de namespace precisam ser exclusivos, o que significa que, geralmente, eles não devem ser curtos demais. Se o comprimento de um nome dificulta a leitura do código ou é entediante digitar em um arquivo de cabeçalho no qual as diretivas não podem ser usadas, você pode criar um alias de namespace que serve como uma abreviação do nome real. Por exemplo:

```cpp
namespace a_very_long_namespace_name { class Foo {}; }
namespace AVLNN = a_very_long_namespace_name;
void Bar(AVLNN::Foo foo){ }
```

## <a name="anonymous-or-unnamed-namespaces"></a>namespaces anônimos ou não nomeados

Você pode criar um namespace explícito, mas não dar um nome a ele:

```cpp
namespace
{
    int MyFunc(){}
}
```

Isso é chamado de namespace não nomeado ou anônimo e é útil quando você deseja tornar declarações de variáveis invisíveis para código em outros arquivos (ou seja, dar a elas vínculos internos) sem precisar criar um namespace nomeado. Todo o código no mesmo arquivo pode ver os identificadores em um namespace sem nome, mas os identificadores, juntamente com o próprio namespace, não são visíveis fora desse arquivo — ou mais precisamente fora da unidade de tradução.

## <a name="see-also"></a>Confira também

[Declarações e definições](declarations-and-definitions-cpp.md)
