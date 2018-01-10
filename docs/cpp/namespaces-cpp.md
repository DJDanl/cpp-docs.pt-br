---
title: Namespaces (C++) | Microsoft Docs
ms.custom: 
ms.date: 08/30/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: namespace_CPP
dev_langs: C++
helpviewer_keywords:
- namespaces [C++], C++
- namespaces [C++]
- namespaces [C++], global
- global namespace
- Visual C++, namespaces
ms.assetid: d1a5a9ab-1cad-47e6-a82d-385bb77f4188
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0f7abecca114b30ddf57f8530b9fbef1bd7ce909
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="namespaces-c"></a>Namespaces (C++)
Um namespace é uma região declarativa que fornece um escopo para os identificadores (os nomes de tipos, funções, variáveis, etc) dentro dele. Namespaces são usados para organizar o código em grupos lógicos e para evitar colisões de nome que podem ocorrer especialmente quando sua base de código inclui várias bibliotecas. Todos os identificadores no escopo do namespace são visíveis para um outro sem qualificação. Identificadores fora o namespace podem acessar os membros usando o nome totalmente qualificado para cada identificador, por exemplo `std::vector<std::string> vec;`, ou se encontram em um [usando declaração](../cpp/using-declaration.md) para um único identificador (`using std::string`), ou um [usando diretiva](../cpp/namespaces-cpp.md#using_directives) para todos os identificadores no namespace (`using namespace std;`). Código em arquivos de cabeçalho sempre deve usar o nome totalmente qualificado de namespace.  
  
 O exemplo a seguir mostra uma declaração de namespace e três maneiras de código fora do namespace pode acessar seus membros.  
  
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
  
 Usam uma declaração para trazer um identificador para o escopo:  
  
```cpp  
using ContosoData::ObjectManager;  
ObjectManager mgr;  
mgr.DoSomething();  
  
```  
  
 Usam uma diretiva para colocar tudo no namespace no escopo:  
  
```cpp  
using namespace ContosoData;
  
ObjectManager mgr;  
mgr.DoSomething();  
Func(mgr);  
  
```  
  
## <a id="using_directives"></a>usando diretivas  
 O `using` diretiva permite que todos os nomes em um **namespace** a ser usado sem o *nome do namespace* como um qualificador explícito. Usam uma diretiva em um arquivo de implementação (ou seja, *.cpp), se você estiver usando vários identificadores diferentes em um namespace; Se estiver usando apenas um ou dois identificadores, em seguida, utilize uma declaração para colocar somente os identificadores no escopo e nem todos os identificadores no namespace. Se uma variável local tiver o mesmo nome de uma variável de namespace, a variável de namespace será oculta. É um erro ter uma variável de namespace com o mesmo nome de uma variável global.  
  
> [!NOTE]
>  Uso de uma diretiva pode ser colocada na parte superior de um arquivo. cpp (no escopo de arquivo), ou dentro de uma definição de classe ou função.  
>   
>  Em geral, evite colocar usando diretivas em arquivos de cabeçalho (*. h) como qualquer arquivo que inclui esse cabeçalho será colocar tudo no namespace no escopo, o que pode causar ocultação de nome e problemas de colisão de nomes que são muito difíceis de depurar. Sempre use nomes totalmente qualificados em um arquivo de cabeçalho. Se esses nomes muito longos, você pode usar um alias de namespace para encurtá-los. (Veja abaixo).  
  
## <a name="declaring-namespaces-and-namespace-members"></a>Declarar membros de espaços para nome e namespace  
 Normalmente, você pode declarar um namespace em um arquivo de cabeçalho. Se suas implementações de função em um arquivo separado, em seguida, qualificar os nomes de função, como neste exemplo.  
  
```cpp  
//contosoData.h   
#pragma once  
namespace ContosoDataServer  
{  
    void Foo();  
    int Bar();  
  
}  
```  
  
 Implementações de função em contosodata.cpp devem usar o nome totalmente qualificado, mesmo se você colocar um `using` diretiva na parte superior do arquivo:  
  
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
  
 Um namespace pode ser declarado em vários blocos em um único arquivo e em vários arquivos. O compilador une as partes juntas durante o pré-processamento e o namespace resultante contém todos os membros declarados em todas as partes. Um exemplo disso é o namespace padrão que é declarado em cada um dos arquivos de cabeçalho na biblioteca padrão.  
  
 Membros de um namespace nomeado podem ser definidos fora o namespace no qual eles são declarados por qualificação explícita do nome que está sendo definido. No entanto, a definição deve aparecer após o ponto de declaração em um namespace que inclui o namespace da declaração. Por exemplo:  
  
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
}  
```  
  
 Esse erro pode ocorrer quando os membros do namespace são declarados em vários arquivos de cabeçalho, e você não incluiu esses cabeçalhos na ordem correta.  
  
## <a name="the-global-namespace"></a>O namespace global  
 Se um identificador não é declarado em um namespace explícito, é parte do namespace global implícita. Em geral, tente evitar a criação de declarações no escopo global, quando possível, exceto para o ponto de entrada [função main](../c-language/main-function-and-program-execution.md), que deve estar no namespace global. Para qualificar-se explicitamente um identificador global, use o operador de resolução de escopo sem nome, como em `::SomeFunction(x);`. Isso será diferenciar o identificador de nenhum outro com o mesmo nome em qualquer outro namespace e ele também ajuda a facilitar para outras pessoas entenderem seu código.  
  
## <a name="the-std-namespace"></a>O namespace std  
 Todas as funções e os tipos de biblioteca padrão C++ são declaradas no `std` namespace ou namespaces aninhados `std`.  
  
## <a name="nested-namespaces"></a>Namespaces aninhados  
 Namespaces podem ser aninhadas. Um namespace aninhado comum tem acesso não qualificado para os membros de seu pai, mas os membros pai não tem acesso não qualificado para o namespace aninhado (a menos que ele é declarado como embutido), conforme mostrado no exemplo a seguir:  
  
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
  
 Namespaces aninhados comuns pode ser usados para encapsular os detalhes de implementação interna que não fazem parte da interface pública do namespace pai.  
  
## <a name="inline-namespaces-c-11"></a>Namespaces embutido (C++ 11)  
 Em contraste com um namespace aninhado comum, membros de um namespace embutido são tratados como membros do namespace pai. Essa característica permite que a pesquisa dependente de argumento em funções sobrecarregadas para funcionar em funções que têm sobrecargas em um pai e um namespace aninhado embutido. Ele também permite que você declarar uma especialização em um namespace do pai de um modelo que é declarado no namespace embutido. O exemplo a seguir mostra o código externo como associa ao namespace embutido por padrão:  
  
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
  
 O exemplo a seguir mostra como você pode declarar uma especialização de um pai de um modelo que é declarado em um namespace embutido:  
  
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
  
 Você pode usar namespaces embutido como um mecanismo de controle de versão para gerenciar alterações na interface pública de uma biblioteca. Por exemplo, você pode criar um namespace único pai e encapsular cada versão da interface em seu próprio namespace aninhado dentro do pai. O namespace que contém a versão mais recente ou preferencial é qualificado como embutido e, portanto, é exposto como se fosse um membro direto para o namespace pai. Código do cliente que invoca o Parent::Class associará automaticamente para o novo código. Clientes que preferem usar a versão mais antiga ainda podem acessá-lo usando o caminho totalmente qualificado para o namespace aninhado com esse código.  
  
 A palavra-chave embutida deve ser aplicada a primeira declaração do namespace em uma unidade de compilação.  
  
 O exemplo a seguir mostra duas versões de uma interface, cada um em um namespace aninhado. O `v_20` namespace tem algumas modificações do `v_10` interface e é marcado como embutido. Código do cliente que usa a nova biblioteca e chama `Contoso::Funcs::Add` invocará a versão v_20. Código que tenta chamar `Contoso::Funcs::Divide` agora obterão um erro de tempo de compilação. Se eles realmente precisam dessa função, eles ainda podem acessar o `v_10` versão explicitamente chamando `Contoso::v_10::Funcs::Divide`.  
  
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
  
## <a id="namespace_aliases"></a>Alias de Namespace  
 Nomes de Namespace precisam ser exclusivo, o que significa que geralmente não devem ser muito curtas. Se o comprimento do nome de um código difíceis de ler, ou é entediante para o tipo em um arquivo de cabeçalho onde usando diretivas não pode ser usado, em seguida, você pode fazer um alias de namespace que serve como uma abreviação para o nome real. Por exemplo:  
  
```cpp  
namespace a_very_long_namespace_name { class Foo {}; }  
namespace AVLNN = a_very_long_namespace_name;  
void Bar(AVLNN::Foo foo){ }  
  
```  
  
## <a name="anonymous-or-unnamed-namespaces"></a>namespaces sem nome ou anônimos  
 Você pode criar um espaço para nome explícito, mas não dê a ele um nome:  
  
```cpp  
namespace  
{  
    int MyFunc(){}  
}  
```  
  
 Isso é chamado de um namespace não nomeado ou anônimo e é útil quando você deseja tornar as declarações de variável invisível ao código em outros arquivos (ou seja, fornecer vinculação interna) sem a necessidade de criar um namespace nomeado. Todo o código no mesmo arquivo pode ver os identificadores em um namespace não nomeado, mas os identificadores, juntamente com o namespace em si, não são visíveis fora desse arquivo, ou mais precisamente fora da unidade de tradução.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações e definições](declarations-and-definitions-cpp.md)
