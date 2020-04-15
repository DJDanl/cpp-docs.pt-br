---
title: Namespaces (C++)
ms.date: 08/30/2017
f1_keywords:
- namespace_CPP
- using_CPP
helpviewer_keywords:
- namespaces [C++]
ms.assetid: d1a5a9ab-1cad-47e6-a82d-385bb77f4188
ms.openlocfilehash: 4957ec5a5face860d2e39861eddc8f7e5abe9370
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367907"
---
# <a name="namespaces-c"></a>Namespaces (C++)

Um namespace é uma região declarativa que fornece um escopo para os identificadores (os nomes dos tipos, funções, variáveis, etc) dentro dele. Namespaces são usados para organizar códigos em grupos lógicos e para evitar colisões de nomes que podem ocorrer especialmente quando sua base de código inclui várias bibliotecas. Todos os identificadores no escopo do namespace são visíveis uns aos outros sem qualificação. Os identificadores fora do namespace podem acessar os membros usando o `std::vector<std::string> vec;`nome totalmente qualificado para cada identificador, por exemplo , ou então usando uma`using namespace std;` [Declaração](../cpp/using-declaration.md) para um único identificador (),`using std::string`ou usando [diretiva](../cpp/namespaces-cpp.md#using_directives) para todos os identificadores no namespace ( ). O código em arquivos de cabeçalho deve sempre usar o nome de namespace totalmente qualificado.

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

Use uma declaração de uso para trazer um identificador para o escopo:

```cpp
using ContosoData::ObjectManager;
ObjectManager mgr;
mgr.DoSomething();
```

Use uma diretiva de uso para colocar tudo no namespace no escopo:

```cpp
using namespace ContosoData;

ObjectManager mgr;
mgr.DoSomething();
Func(mgr);
```

## <a name="using-directives"></a><a id="using_directives"></a>usando diretivas

A diretiva **de uso** permite que todos os nomes em um namespace sejam **usados** sem o *nome do namespace* como um qualificador explícito. Use uma diretiva de uso em um arquivo de implementação (ou seja, *.cpp) se você estiver usando vários identificadores diferentes em um namespace; se você estiver usando apenas um ou dois identificadores, então considere uma declaração de uso para apenas trazer esses identificadores para o escopo e não todos os identificadores no namespace. Se uma variável local tiver o mesmo nome de uma variável de namespace, a variável de namespace será oculta. É um erro ter uma variável de namespace com o mesmo nome de uma variável global.

> [!NOTE]
> Uma diretiva de uso pode ser colocada na parte superior de um arquivo .cpp (no escopo do arquivo), ou dentro de uma definição de classe ou função.
>
> Em geral, evite colocar o uso de diretivas em arquivos de cabeçalho (*.h) porque qualquer arquivo que inclua esse cabeçalho trará tudo no namespace para o escopo, o que pode causar problemas de ocultação de nomes e colisão de nomes que são muito difíceis de depurar. Use sempre nomes totalmente qualificados em um arquivo de cabeçalho. Se esses nomes ficarem muito longos, você pode usar um pseudônimo de namespace para encurtá-los. (Veja abaixo.)

## <a name="declaring-namespaces-and-namespace-members"></a>Declarando namespaces e membros de namespace

Normalmente, você declara um namespace em um arquivo de cabeçalho. Se as implementações da sua função estiverem em um arquivo separado, qualifique os nomes da função, como neste exemplo.

```cpp
//contosoData.h
#pragma once
namespace ContosoDataServer
{
    void Foo();
    int Bar();
}
```

As implementações de função em contosodata.cpp devem usar o nome totalmente qualificado, mesmo se você colocar uma diretiva **de uso** na parte superior do arquivo:

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

Um namespace pode ser declarado em vários blocos em um único arquivo e em vários arquivos. O compilador junta as peças durante o pré-processamento e o namespace resultante contém todos os membros declarados em todas as partes. Um exemplo disso é o namespace do Std que é declarado em cada um dos arquivos de cabeçalho na biblioteca padrão.

Os membros de um namespace nomeado podem ser definidos fora do namespace em que são declarados pela qualificação explícita de nome que está sendo definido. No entanto, a definição deve aparecer após o ponto de declaração em um namespace que inclui o espaço de nome da declaração. Por exemplo:

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

Se um identificador não for declarado em um namespace explícito, ele faz parte do namespace global implícito. Em geral, tente evitar fazer declarações no âmbito global quando possível, exceto para a [função principal](../c-language/main-function-and-program-execution.md)do ponto de entrada, que é necessária para estar no namespace global. Para qualificar explicitamente um identificador global, use o operador `::SomeFunction(x);`de resolução de escopo sem nome, como em . Isso diferenciará o identificador de qualquer coisa com o mesmo nome em qualquer outro namespace, e também ajudará a tornar seu código mais fácil para os outros entenderem.

## <a name="the-std-namespace"></a>O namespace std

Todos os tipos e funções padrão da `std` biblioteca C++ são `std`declarados no namespace ou namespaces aninhados dentro .

## <a name="nested-namespaces"></a>Espaços de nomes aninhados

Os espaços de nome podem ser aninhados. Um namespace aninhado comum tem acesso não qualificado aos membros de seus pais, mas os membros-mãe não têm acesso não qualificado ao espaço de nome aninhado (a menos que seja declarado como inline), como mostrado no exemplo a seguir:

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

Os namespaces aninhados ordinários podem ser usados para encapsular detalhes de implementação interna que não fazem parte da interface pública do namespace pai.

## <a name="inline-namespaces-c-11"></a>Espaços de nomes inline (C++ 11)

Em contraste com um espaço de nome aninhado comum, os membros de um namespace inline são tratados como membros do namespace pai. Essa característica permite que a análise dependente de argumentos em funções sobrecarregadas funcione em funções que tenham sobrecargas em um pai e um espaço de nome inline aninhado. Ele também permite que você declare uma especialização em um namespace pai para um modelo que é declarado no namespace inline. O exemplo a seguir mostra como o código externo se liga ao namespace inline por padrão:

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

O exemplo a seguir mostra como você pode declarar uma especialização em um pai de um modelo que é declarado em um namespace inline:

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

Você pode usar namespaces inline como um mecanismo de versão para gerenciar alterações na interface pública de uma biblioteca. Por exemplo, você pode criar um namespace de pai único e encapsular cada versão da interface em seu próprio namespace aninhado dentro do pai. O namespace que detém a versão mais recente ou preferida é qualificado como inline e, portanto, é exposto como se fosse um membro direto do namespace pai. O código do cliente que invoca o Pai:Classe se vinculará automaticamente ao novo código. Os clientes que preferem usar a versão mais antiga ainda podem acessá-la usando o caminho totalmente qualificado para o espaço de nome aninhado que possui esse código.

A palavra-chave inline deve ser aplicada à primeira declaração do namespace em uma unidade de compilação.

O exemplo a seguir mostra duas versões de uma interface, cada uma em um espaço de nome aninhado. O `v_20` namespace tem alguma `v_10` modificação da interface e está marcado como inline. O código do cliente que `Contoso::Funcs::Add` usa a nova biblioteca e as chamadas invocará a versão v_20. O código que `Contoso::Funcs::Divide` tenta ligar agora terá um erro de tempo de compilação. Se eles realmente precisam dessa função, eles ainda podem acessar a `v_10` versão chamando `Contoso::v_10::Funcs::Divide`explicitamente .

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

Os nomes do namespace precisam ser únicos, o que significa que muitas vezes eles não devem ser muito curtos. Se o comprimento de um nome torna o código difícil de ler, ou é tedioso digitar um arquivo de cabeçalho onde o uso de diretivas não pode ser usado, então você pode fazer um alias namespace que serve como uma abreviação para o nome real. Por exemplo:

```cpp
namespace a_very_long_namespace_name { class Foo {}; }
namespace AVLNN = a_very_long_namespace_name;
void Bar(AVLNN::Foo foo){ }
```

## <a name="anonymous-or-unnamed-namespaces"></a>espaços de nomes anônimos ou anônimos

Você pode criar um namespace explícito, mas não dar-lhe um nome:

```cpp
namespace
{
    int MyFunc(){}
}
```

Isso é chamado de namespace anônimo ou anônimo e é útil quando você deseja tornar as declarações variáveis invisíveis ao código em outros arquivos (ou seja, dar-lhes linkagem interna) sem ter que criar um namespace nomeado. Todos os códigos no mesmo arquivo podem ver os identificadores em um namespace não nomeado, mas os identificadores, juntamente com o próprio namespace, não são visíveis fora desse arquivo — ou mais precisamente fora da unidade de tradução.

## <a name="see-also"></a>Confira também

[Declarações e definições](declarations-and-definitions-cpp.md)
