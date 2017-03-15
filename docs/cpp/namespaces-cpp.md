---
title: "Namespaces (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "namespace_CPP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "namespace global"
  - "namespaces [C++]"
  - "namespaces [C++], C++"
  - "namespaces [C++], global"
  - "Visual C++, namespaces"
ms.assetid: d1a5a9ab-1cad-47e6-a82d-385bb77f4188
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Namespaces (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um namespace é uma região declarativa que fornece um escopo para os identificadores \(os nomes de tipos, funções, variáveis, etc\) dentro dela.  Namespaces são usados para organizar o código em grupos lógicos e para evitar conflitos de nome podem ocorrer especialmente quando sua base de código inclui várias bibliotecas.  Todos os identificadores no escopo de namespace são visíveis entre si sem qualificação.  Identificadores fora do namespace podem acessar os membros usando o nome totalmente qualificado para cada identificador, por exemplo `std::vector<std::string> vec;`, ou se encontram em um [Declaração de uso](../cpp/using-declaration.md) para um único identificador \(`using std::string`\), ou um [Diretiva de uso](../misc/using-directive-cpp.md) para todos os identificadores no namespace \(`using namespace std;`\).  Código em arquivos de cabeçalho sempre deve usar o nome totalmente qualificado de namespace.  
  
 O exemplo a seguir mostra uma declaração de namespace e três maneiras de código fora do namespace pode acessar seus membros.  
  
```  
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
  
```  
ContosoData::ObjectManager mgr;  
mgr.DoSomething();  
ContosoData::Func(mgr);  
```  
  
 Usar uma declaração para um identificador para o escopo:  
  
```  
using WidgetsUnlimited::ObjectManager;  
ObjectManager mgr;  
mgr.DoSomething();  
  
```  
  
 Usar uma diretiva para colocar tudo no namespace no escopo:  
  
```  
using namespace WidgetsUnlimited;  
ObjectManager mgr;  
mgr.DoSomething();  
Func(mgr);  
  
```  
  
## usando diretivas  
 A `using` diretiva permite que todos os nomes em uma **namespace** sejam usados sem a *nome do namespace* como um qualificador explícito.  Usar um arquivo de diretiva em uma implementação \(ou seja,  \*.cpp\) se você estiver usando vários identificadores diferentes em um namespace; Se você estiver usando apenas um ou dois identificadores, em seguida, utilize uma declaração para apenas esses identificadores no escopo e nem todos os identificadores no namespace.  Se uma variável local tiver o mesmo nome de uma variável de namespace, a variável de namespace será oculta.  É um erro ter uma variável de namespace com o mesmo nome de uma variável global.  
  
> [!NOTE]
>  Uso de uma diretiva pode ser colocada na parte superior de um arquivo. cpp \(no escopo do arquivo\), ou dentro de uma definição de classe ou função.  
>   
>  Em geral, evite colocar usando diretivas nos arquivos de cabeçalho \(\*. h\) porque qualquer arquivo que inclui esse cabeçalho será colocar tudo no namespace no escopo, que podem causar ocultação de nome e problemas de colisão de nomes que são muito difíceis de depurar.  Sempre use nomes totalmente qualificados em um arquivo de cabeçalho.  Se esses nomes muito longos, você pode usar um alias de namespace para encurtá\-los.  \(Veja abaixo\).  
  
## Declarar membros de espaços para nome e namespace  
 Normalmente, você pode declarar um namespace em um arquivo de cabeçalho.  Se suas implementações de função em um arquivo separado, você se qualifica os nomes de função, como neste exemplo.  
  
```  
//contosoData.h   
#pragma once  
namespace ContosoDataServer  
{  
    void Foo();  
    int Bar();  
  
}  
```  
  
 As implementações de função contosodata.cpp devem usar o nome totalmente qualificado, mesmo se você colocar um usando diretiva na parte superior do arquivo:  
  
```  
#include "contosodata.h"  
using namespace ContosoDataServer;   
  
void ContosoDataServer::Foo()  
{  
   //no qualification because using directive above  
   Bar();   
}  
  
int ContosoDataServer::Bar(){return 0;}  
```  
  
 Um namespace pode ser declarado em vários blocos em um único arquivo e em vários arquivos.  O compilador une as partes juntas durante o pré\-processamento e o namespace resultante contém todos os membros declarados em todas as partes.  Um exemplo disso é o namespace padrão declarado em cada um dos arquivos de cabeçalho na biblioteca padrão.  
  
 Os membros de um namespace nomeado podem ser definidos fora do namespace em que são declarados pela [qualificação explícita](../misc/explicit-qualification.md) de nome que está sendo definido.  No entanto, a definição deve aparecer após o ponto de declaração em um namespace que inclui o namespace da declaração.  Por exemplo:  
  
```  
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
  
 Esse erro pode ocorrer quando os membros do namespace são declarados em vários arquivos de cabeçalho, e você não incluí esses cabeçalhos na ordem correta.  
  
## O namespace global  
 Se um identificador não for declarado em um namespace explícito, é parte do namespace global implícito.  Em geral, tente evitar fazer declarações no escopo global, quando possível, exceto para o ponto de entrada [função principal](../c-language/main-function-and-program-execution.md), que deve estar no namespace global.  Para qualificar explicitamente um identificador global, use o operador de resolução de escopo sem nome, como em `::SomeFunction(x);`.  Isso será diferenciar o identificador de qualquer coisa com o mesmo nome em qualquer outro namespace, e ele também ajuda a tornar seu código mais fácil para outras pessoas entenderem.  
  
## O namespace std  
 Todos os tipos de biblioteca padrão C\+\+ e funções são declaradas no namespace padrão ou namespaces aninhados dentro de padrão.  
  
## Namespaces aninhados  
 Namespaces podem ser aninhados.  Um namespace aninhado comum tem acesso não qualificado para os membros de seu pai, mas os membros pai não tiver acesso não qualificado para namespace aninhado \(a menos que ele é declarado como embutida\), conforme mostrado no exemplo a seguir:  
  
```  
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
  
 Namespaces aninhados comuns pode ser usados para encapsular os detalhes de implementação internos que não fazem parte da interface pública do namespace pai.  
  
## Namespaces embutidos \(C\+\+ 11\)  
 Em contraste com um namespace aninhado comum, os membros de um namespace embutido são tratados como membros do namespace pai.  Essa característica permite que a pesquisa dependente de argumento em funções sobrecarregadas para trabalhar em funções que têm sobrecargas em um pai e um namespace aninhado embutido.  Ele também permite que você declare uma especialização em um namespace do pai de um modelo que é declarado no namespace embutido.  O exemplo a seguir mostra o código externo como associa ao namespace embutidos por padrão:  
  
```  
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
  
```  
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
  
 Você pode usar namespaces embutidos como um mecanismo de controle de versão para gerenciar alterações na interface pública de uma biblioteca.  Por exemplo, você pode criar um namespace único pai e encapsular cada versão da interface em seu próprio namespace aninhado dentro do pai.  O namespace que contém a versão mais recente ou preferencial é qualificado como embutido e, portanto, é exposto como se fosse um membro direto do namespace pai.  Código do cliente que invoca o Parent::Class irá associar automaticamente para o novo código.  Os clientes que preferem usar a versão mais antiga ainda podem acessá\-lo usando o caminho totalmente qualificado para o namespace aninhado com esse código.  
  
 A palavra\-chave embutida deve ser aplicada à primeira declaração de namespace em uma unidade de compilação.  
  
 O exemplo a seguir mostra duas versões de uma interface, cada um em um namespace aninhado.  O `v_20` namespace tem algumas modificações do `v_10` da interface e é marcado como embutido.  Código do cliente que usa a nova biblioteca e chama `Contoso::Funcs::Add` invocará a versão v\_20.  Código que tenta chamar `Contoso::Funcs::Divide` agora receberá um erro de tempo de compilação.  Se eles realmente precisam dessa função, eles ainda podem acessar o `v_10` versão explicitamente chamando `Contoso::v_10::Funcs::Divide`.  
  
```  
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
  
## Alias de namespace  
 Nomes de namespace precisam ser exclusivos, o que significa que geralmente eles não devem ser muito curtos.  Se o comprimento do nome de um código difícil de ler, ou é entediante em um arquivo de cabeçalho onde usando diretivas não pode ser usado, em seguida, você pode fazer um alias de namespace que serve como uma abreviação para o nome real.  Por exemplo:  
  
```  
namespace a_very_long_namespace_name { class Foo {}; }  
namespace AVLNN = a_very_long_namespace_name;  
void Bar(AVLNN::Foo foo){ }  
  
```  
  
## namespaces anônimos ou sem nome  
 Você pode criar um namespace explícito mas não nomeá\-lo:  
  
```  
namespace  
{  
    int MyFunc(){}  
}  
```  
  
 Isso é chamado de um namespace não nomeado ou anônimo e é útil quando você quer fazer declarações de variável invisíveis ao código em outros arquivos \(ou seja  fornecer vinculação interna\) sem precisar criar um namespace nomeado.  Todo o código no mesmo arquivo pode ver os identificadores em um namespace sem nome, mas os identificadores, juntamente com o namespace em si, não são visíveis fora desse arquivo — ou, mais precisamente fora da unidade de tradução.  
  
## Comentários  
  
## Consulte também  
 [Declarações](../misc/declarations.md)