---
title: Melhorias de conformidade do compilador C++ | Microsoft Docs
ms.custom: 
ms.date: 06/05/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- vs-ide-general
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 8801dbdb-ca0b-491f-9e33-01618bff5ae9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: 3c1955bece0c8cdadb4a151ee06fa006402666a4
ms.openlocfilehash: d00951204a358ec064f69035b7dd6ac5adc08ed9
ms.contentlocale: pt-br
ms.lasthandoff: 06/08/2017

---
   
# Melhorias de conformidade do C++ no [!INCLUDE[vs_dev15_md](misc/includes/vs_dev15_md.md)]
<a id="c-conformance-improvements-in-includevsdev15mdmiscincludesvsdev15mdmd" class="xliff"></a>
Para conhecer as melhorias da Versão de Atualização 15.3, confira [Correções de bugs na Versão de Atualização do Visual Studio 15.3](#update_153).
## Novos recursos de linguagem
<a id="new-language-features" class="xliff"></a>  
Com suporte para constexpr generalizado e NSDMI para agregações, agora o compilador está completo com relação aos recursos adicionados no padrão C++14. Observe que o compilador ainda não tem alguns recursos dos padrões C++11 e C++98. Confira [Conformidade com a linguagem Visual C++](visual-cpp-language-conformance.md) para ver uma tabela que mostra o estado atual do compilador.

### C++11:
<a id="c11" class="xliff"></a>
**Suporte da expressão SFINAE em mais bibliotecas** O compilador do Visual C++ continua melhorando seu suporte da expressão SFINAE, necessário para dedução e substituição de argumentos de modelo em que as expressões decltype e constexpr podem ser exibidas como parâmetros de modelo. Para obter mais informações, consulte [Expression SFINAE improvements in Visual Studio 2017 RC (Melhorias da expressão SFINAE no Visual Studio 2017 RC)](https://blogs.msdn.microsoft.com/vcblog/2016/06/07/expression-sfinae-improvements-in-vs-2015-update-3). 


### C++ 14:
<a id="c-14" class="xliff"></a>
**NSDMI para agregações** Uma agregação é uma matriz ou uma classe sem nenhum construtor fornecido pelo usuário, sem membros de dados não estáticos privados ou protegidos, sem classes base e sem funções virtuais. Começando pelo C ++14, as agregações podem conter inicializadores de membro. Para obter mais informações, consulte [Member initializers and aggregates (Inicializadores de membro e agregações)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3605.html).

**Constexpr estendida** Agora as expressões declaradas como constexpr podem conter alguns tipos de declaração, instruções if e switch, declarações de loop e mutação de objetos cujo tempo de vida começou dentro da avaliação da expressão constexpr. Além disso, não há mais o requisito de que uma função membro não estática constexpr seja implicitamente const. Para obter mais informações, consulte [Relaxing constraints on constexpr functions (Relaxando restrições em funções constexpr)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3652.html). 

### C++17:
<a id="c17" class="xliff"></a>
**Static_assert concisa** (disponível com /std:c++latest) No C++17, o parâmetro da mensagem para static_assert é opcional. Para obter mais informações, consulte [Extending static_assert, v2 (Estendendo static_assert, v2)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.pdf). 

**Atributo [[fallthrough]]** (disponível com /std:c++latest) O atributo [[fallthrough]] pode ser usado no contexto de instruções switch como uma dica para o compilador de que o comportamento fall-through é intencional. Isso impede o compilador de emitir avisos em tais casos. Para obter mais informações, consulte [Wording for [[fallthrough]] attribute (Expressão para atributo [[fallthrough]])](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r0.pdf). 

**Loops “for” baseados em intervalo generalizados** (não é necessária nenhuma opção de compilador) Loops “for” baseados em intervalo não exigem mais que begin() e end() retornem objetos do mesmo tipo. Isso permite que end() retorne um objeto sentinela como usado por intervalos, conforme definido na proposta Ranges-V3. Para obter mais informações, consulte [Generalizing the Range-Based For Loop (Generalizando o loop “for” baseado em intervalo)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html) e [range-v3 library on GitHub (Biblioteca range-v3 no GitHub)](https://github.com/ericniebler/range-v3). 


Para obter uma lista das melhorias de conformidade até o Visual Studio 2015, Atualização 3, consulte [Visual C++ What's New 2003 through 2015 (Novidades do Visual C++ 2003 a 2015)](https://msdn.microsoft.com/en-us/library/mt723604.aspx).

## Correções de bug
<a id="bug-fixes" class="xliff"></a>
### Inicialização de lista de cópia
<a id="copy-list-initialization" class="xliff"></a>
O Visual Studio 2017 gera corretamente erros de compilador relacionados à criação de objetos usando listas de inicializador que não foram detectadas no Visual Studio 2015 e que podem causar falhas ou comportamento indefinido do tempo de execução.  De acordo com a N4594 13.3.1.7p1, na inicialização de lista de cópia, o compilador deverá considerar um construtor explícito para resolução de sobrecarga, mas deverá gerar um erro se essa sobrecarga for realmente escolhida. 

Os dois exemplos a seguir são compilados no Visual Studio 2015, mas não no Visual Studio 2017.
```cpp  
struct A
{
    explicit A(int) {} 
    A(double) {}
};

int main()
{
    A a1 = { 1 }; // error C3445: copy-list-initialization of 'A' cannot use an explicit constructor
    const A& a2 = { 1 }; // error C2440: 'initializing': cannot convert from 'int' to 'const A &'

}
```
Para corrigir o erro, use a inicialização direta:
```cpp  
A a1{ 1 };
const A& a2{ 1 };
```

No Visual Studio 2015, o compilador tratou a inicialização de lista de cópia de maneira incorreta da mesma maneira que a inicialização de cópia regular; ele considerou somente a conversão de construtores para a resolução de sobrecarga. No exemplo a seguir, o Visual Studio 2015 escolhe MyInt(23), mas o Visual Studio 2017 gera o erro corretamente. 

```cpp  
// From http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_closed.html#1228
struct MyStore {
       explicit MyStore(int initialCapacity);
};

struct MyInt {
       MyInt(int i);
};

struct Printer {
       void operator()(MyStore const& s);
       void operator()(MyInt const& i);
};

void f() {
       Printer p;
       p({ 23 }); // C3066: there are multiple ways that an object of this type can be called with these arguments
}
```

Esse exemplo é semelhante ao anterior, mas gera um erro diferente. Ele tem êxito no Visual Studio 2015 e falha no Visual Studio 2017 com C2668. 

```cpp  
struct A {
    explicit A(int) {}
};

struct B {
    B(int) {}
};

void f(const A&) {}
void f(const B&) {}

int main()
{
    f({ 1 }); // error C2668: 'f': ambiguous call to overloaded function
}
```

### Typedefs preteridos
<a id="deprecated-typedefs" class="xliff"></a>
Agora o Visual Studio 2017 emite o aviso correto para typedefs preteridos declarados em uma classe ou em um struct. O exemplo a seguir é compilado sem avisos no Visual Studio 2015, mas gera C4996 no Visual Studio 2017.

```cpp  
struct A 
{
    // also for __declspec(deprecated) 
    [[deprecated]] typedef int inttype;
};

int main()
{
    A::inttype a = 0; // C4996 'A::inttype': was declared deprecated
}
```

### constexpr
<a id="constexpr" class="xliff"></a>
O Visual Studio 2017 gera corretamente um erro quando o operando esquerdo de uma operação de avaliação condicional é inválido em um contexto constexpr. O código a seguir é compilado no Visual Studio 2015, mas não no Visual Studio 2017 (C3615 a função constexpr 'f' não pode resultar em uma expressão de constante):

```cpp  
template<int N>
struct array 
{
       int size() const { return N; }
};

constexpr bool f(const array<1> &arr)
{
       return arr.size() == 10 || arr.size() == 11; // C3615    
}
```
Para corrigir o erro, declare a função array::size() como constexpr ou remova o qualificador constexpr de f. 

### Tipos de classe passados para funções variadic
<a id="class-types-passed-to-variadic-functions" class="xliff"></a>
No Visual Studio de 2017, as classes ou structs passados para uma função variadic como printf devem ser facilmente copiados. Ao passar esses objetos, o compilador simplesmente faz uma cópia bit a bit e não chama o construtor nem o destruidor. 

```cpp  
#include <atomic>
#include <memory>
#include <stdio.h>

int main()
{
    std::atomic<int> i(0);
    printf("%i\n", i); // error C4839: non-standard use of class 'std::atomic<int>'
                        // as an argument to a variadic function
                        // note: the constructor and destructor will not be called; 
                        // a bitwise copy of the class will be passed as the argument
                        // error C2280: 'std::atomic<int>::atomic(const std::atomic<int> &)':
                        // attempting to reference a deleted function

    struct S {
        S(int i) : i(i) {}
        S(const S& other) : i(other.i) {}
        operator int() { return i; }
    private:
        int i;
    } s(0);
    printf("%i\n", s); // warning C4840 : non-portable use of class 'main::S'
                      // as an argument to a variadic function
}
```
Para corrigir o erro, é possível chamar uma função membro que retorna um tipo facilmente copiado, 

```cpp  
    std::atomic<int> i(0);
    printf("%i\n", i.load());
```
ou realiza uma conversão estática para converter o objeto antes de passá-lo:
```cpp  
    struct S {/* as before */} s(0);
    printf("%i\n", static_cast<int>(s))
```
Para cadeias de caracteres criadas e gerenciadas usando o CStringW, o `operator LPCWSTR()` fornecido deve ser usado para converter um objeto CStringW no ponteiro do C esperado pela cadeia de caracteres de formato.

```cpp  
CStringW str1;
CStringW str2;
str1.Format(L"%s", static_cast<LPCWSTR>(str2));
```

### Qualificadores CV na construção de classe
<a id="cv-qualifiers-in-class-construction" class="xliff"></a>
No Visual Studio 2015, às vezes, o compilador ignora incorretamente o qualificador CV ao gerar um objeto de classe por meio de uma chamada do construtor. Eventualmente, isso pode gerar uma falha ou comportamento inesperado do tempo de execução. O exemplo a seguir é compilado no Visual Studio 2015, mas gera um erro de compilador no Visual Studio 2017:

```cpp  
struct S 
{
    S(int);
    operator int();
};

int i = (const S)0; // error C2440
```
Para corrigir o erro, declare o operador int() como const. 

### Verificação de acesso em nomes qualificados em modelos
<a id="access-checking-on-qualified-names-in-templates" class="xliff"></a>
As versões anteriores do compilador não realizavam a verificação de acesso em nomes qualificados em alguns contextos de modelo. Isso pode interferir no comportamento SFINAE esperado quando a substituição deve falhar devido à inacessibilidade de um nome. Eventualmente, isso poderia ter causado uma falha ou comportamento inesperado no tempo de execução devido ao compilador ter chamado incorretamente a sobrecarga errada do operador. No Visual Studio 2017, é gerado um erro do compilador. O erro específico pode variar, mas geralmente é "C2672 nenhuma função sobrecarregada correspondente encontrada". O código a seguir é compilado no Visual Studio 2015, mas gera um erro no Visual Studio 2017:

```cpp  
#include <type_traits>

template <class T> class S {
       typedef typename T type;
};

template <class T, std::enable_if<std::is_integral<typename S<T>::type>::value, T> * = 0>
bool f(T x);

int main()
{
       f(10); // C2672: No matching overloaded function found. 
}
```

### Listas de argumentos de modelo ausentes
<a id="missing-template-argument-lists" class="xliff"></a>
No Visual Studio 2015 e anteriores, o compilador não diagnosticava listas de argumentos de modelo ausentes quando o modelo era exibido em uma lista de parâmetro de modelo (por exemplo, como parte de um argumento de modelo padrão ou um parâmetro de não tipo de modelo). Isso pode resultar em comportamento imprevisível, incluindo falhas do compilador ou comportamento inesperado do tempo de execução. O código a seguir é compilado no Visual Studio 2015, mas produz um erro no Visual Studio 2017.

```cpp  
template <class T> class ListNode;
template <class T> using ListNodeMember = ListNode<T> T::*;
template <class T, ListNodeMember M> class ListHead; // C2955: 'ListNodeMember': use of alias 
                                                     // template requires template argument list

// correct:  template <class T, ListNodeMember<T> M> class ListHead;  
```

### Expressão SFINAE
<a id="expression-sfinae" class="xliff"></a>
Para dar suporte à expressão SFINAE, agora o compilador analisa argumentos decltype quando os modelos são declarados em vez de instanciados. Consequentemente, se uma especialização não dependente for encontrada no argumento decltype, ela não será adiada para o momento de instanciação e será processada imediatamente e quaisquer erros resultantes serão ser diagnosticados nesse momento.  

O exemplo a seguir mostra esse erro do compilador gerado no momento da declaração:

```cpp  
#include <utility>
template <class T, class ReturnT, class... ArgsT> class IsCallable
{
public:
       struct BadType {};
       template <class U>
       static decltype(std::declval<T>()(std::declval<ArgsT>()...)) Test(int); //C2064. Should be declval<U>
       template <class U>
       static BadType Test(...);
       static constexpr bool value = std::is_convertible<decltype(Test<T>(0)), ReturnT>::value;
};

constexpr bool test1 = IsCallable<int(), int>::value;
static_assert(test1, "PASS1");
constexpr bool test2 = !IsCallable<int*, int>::value;
static_assert(test2, "PASS2");
```
### Classes declaradas em namespaces anônimos
<a id="classes-declared-in-anonymous-namespaces" class="xliff"></a>
De acordo com o padrão C++, uma classe declarada dentro de um namespace anônimo tem vinculação interna e, portanto, não pode ser exportada. No Visual Studio 2015 e anteriores, essa regra não foi aplicada. No Visual Studio 2017, a regra foi parcialmente aplicada. O exemplo a seguir gera este erro no Visual Studio 2017: "erro C2201: 'const `anonymous namespace'::S1::`vftable': deve ter vinculação externa para poder ser exportado/importado".

```cpp
struct __declspec(dllexport) S1 { virtual void f() {} }; //C2201
```

### Inicializadores padrão para membros de classe de valor (C++/CLI)
<a id="default-initializers-for-value-class-members-ccli" class="xliff"></a>
No Visual Studio 2015 e nas versões anteriores, o compilador permitia (mas ignorava) um inicializador de membro padrão para um membro de uma classe de valor.  A inicialização padrão de uma classe de valor sempre inicializa os membros em zero; um construtor padrão não é permitido.  No Visual Studio 2017, os inicializadores de membro padrão geram um erro de compilador, conforme mostrado neste exemplo:

```cpp  
value struct V
{
       int i = 0; // error C3446: 'V::i': a default member initializer  
                  // is not allowed for a member of a value class
};
```

### Indexadores padrão (C++/CLI)
<a id="default-indexers-ccli" class="xliff"></a>
No Visual Studio 2015 e em versões anteriores, o compilador, em alguns casos, identificava incorretamente uma propriedade padrão como um indexador padrão. É possível resolver o problema usando o identificador "padrão" para acessar a propriedade. A solução em si se tornou um problema depois que o padrão foi introduzido como uma palavra-chave no C++ 11. Portanto, no Visual Studio 2017, os bugs que exigiam a solução alternativa foram corrigidos, e agora o compilador gera um erro quando o “padrão” é usado para acessar a propriedade padrão de uma classe.

```cpp  
//class1.cs

using System.Reflection;
using System.Runtime.InteropServices;

namespace ClassLibrary1
{
    [DefaultMember("Value")]
    public class Class1
    {
        public int Value
        {
            // using attribute on the return type triggers the compiler bug
            [return: MarshalAs(UnmanagedType.I4)]
            get;
        }
    }
    [DefaultMember("Value")]
    public class Class2
    {
        public int Value
        {
            get;
        }
    }
}

 
// code.cpp
#using "class1.dll"

void f(ClassLibrary1::Class1 ^r1, ClassLibrary1::Class2 ^r2)
{
       r1->Value; // error
       r1->default;
       r2->Value;
       r2->default; // error
}
```

No Visual Studio de 2017, é possível acessar ambas as propriedades Value pelo nome:

```cpp  
#using "class1.dll"

void f(ClassLibrary1::Class1 ^r1, ClassLibrary1::Class2 ^r2)
{
       r1->Value;
       r2->Value;
}
```

## <a name="update_153"></a>Visual Studio 2017 Versão de Atualização 15.3
### Chamadas para modelos de membros excluídos
<a id="calls-to-deleted-member-templates" class="xliff"></a>
Nas versões anteriores do Visual Studio, em alguns casos o compilador falhará ao emitir um erro para chamadas malformados para um modelo de membro excluído que poderia potencialmente causar falhas em tempo de execução. Agora, o código a seguir produz C2280, "'int S<int>::f<int>(void)': tentativa de fazer referência a uma função excluída":
```cpp
template<typename T> 
struct S { 
   template<typename U> static int f() = delete; 
}; 
 
void g() 
{ 
   decltype(S<int>::f<int>()) i; // this should fail 
}
```
Para corrigir o erro, declare i como `int`.

### Verificações de pré-condição para características de tipo
<a id="pre-condition-checks-for-type-traits" class="xliff"></a>
O Visual Studio 2017 Versão de Atualização 15.3 melhora as verificações de pré-condição para características de tipo para seguir o padrão mais estritamente. Uma verificação assim destina-se aos atribuíveis. O código a seguir produz C2139 na Versão de Atualização 15.3:

```cpp
struct S; 
enum E; 
 
static_assert(!__is_assignable(S, S), "fail"); // C2139 in 15.3
static_assert(__is_convertible_to(E, E), "fail"); // C2139 in 15.3
```

### Novas verificações de tempo de execução e o aviso do compilador em marshaling nativo para gerenciado
<a id="new-compiler-warning-and-runtime-checks-on-native-to-managed-marshaling" class="xliff"></a>
Chamar desde funções gerenciadas para funções nativas requer o marshaling. O CLR realiza marshaling, mas não entende a semântica do C++. Se você passar um objeto nativo por valor, o CLR chamará o construtor de cópia do objeto ou usará BitBlt, o que pode causar um comportamento indefinido em tempo de execução. 
 
Agora, o compilador emitirá um aviso se puder sabe em tempo de compilação que um objeto nativo com o construtor de cópia excluído é passado entre limites nativos e gerenciados por valor. Nos casos em que o compilador não souber em tempo de compilação, ele injetará uma verificação de tempo de execução para que o programa chame std::terminate imediatamente quando um empacotamento malformado ocorrer. Na Versão de Atualização 15.3, o código a seguir produz C4606 "'A': passar o argumento por valor entre limite nativo e gerenciado exige um construtor de cópia válido. Caso contrário, o comportamento de tempo de execução é indefinido".
```cpp
class A 
{ 
public: 
   A() : p_(new int) {} 
   ~A() { delete p_; } 
 
   A(A const &) = delete; 
   A(A &&rhs) { 
   p_ = rhs.p_; 
} 
 
private: 
   int *p_; 
}; 
 
#pragma unmanaged 
 
void f(A a) 
{ 
} 
 
#pragma managed 
 
int main() 
{ 
    f(A()); // This call from managed to native requires marshalling. The CLR doesn't understand C++ and uses BitBlt, which will result in a double-free later. 
}
```
Para corrigir o erro, remova a política `#pragma managed` para marcar o chamador como nativo e evitar o empacotamento. 

### Aviso de API experimental para WinRT
<a id="experimental-api-warning-for-winrt" class="xliff"></a>
As APIs do WinRT lançadas para experimentação e comentários serão decoradas com `Windows.Foundation.Metadata.ExperimentalAttribute`. Na Versão de Atualização 15.3, o compilador gerará o aviso C4698 quando encontrar o atributo. Algumas APIs em versões anteriores do SDK do Windows já tinham sido decoradas com o atributo, e chamadas para essas APIs começarão a disparar esse aviso do compilador. Os SDKs mais recentes terão o atributo removido de todos os tipos enviados, mas se você estiver usando um SDK mais antigo, precisará suprimir esses avisos para todas as chamadas para tipos enviados.
O código a seguir produz o aviso C4698: "'Windows::Storage::IApplicationDataStatics2::GetForUserAsync' é para fins de avaliação e está sujeito a alteração ou remoção em atualizações futuras":
```cpp
Windows::Storage::IApplicationDataStatics2::GetForUserAsync() //C4698
```

Para desabilitar o aviso, adicione um #pragma:

```cpp
#pragma warning(push) 
#pragma warning(disable:4698) 
 
Windows::Storage::IApplicationDataStatics2::GetForUserAsync() 
 
#pragma warning(pop)
```
### Definição fora da linha de uma função de membro de modelo
<a id="out-of-line-definition-of-a-template-member-function" class="xliff"></a> 
A Versão de Atualização 15.3 produz um erro ao encontrar uma definição fora da linha de uma função de membro de modelo que não foi declarada na classe. Agora, o código a seguir produz o erro C2039: 'f': não é membro de 'S':

```cpp
struct S {}; 
 
template <typename T> 
void S::f(T t) {} //C2039: 'f': is not a member of 'S'
```

Para corrigir o erro, adicione uma declaração à classe:

```cpp
struct S { 
    template <typename T> 
    void f(T t); 
}; 
template <typename T> 
void S::f(T t) {}
```

### Tentativa de obter o endereço do ponteiro "this"
<a id="attempting-to-take-the-address-of-this-pointer" class="xliff"></a>
Em C++, 'this' é um prvalue do tipo ponteiro para X. Você não pode obter o endereço de 'this' nem vinculá-lo a uma referência de lvalue. Nas versões anteriores do Visual Studio, o compilador permitia evitar essa restrição, executando uma conversão. Na Versão de Atualização 15.3, o compilador produz o erro C2664.

### Conversão em uma classe base inacessível
<a id="conversion-to-an-inaccessible-base-class" class="xliff"></a>
A Versão de Atualização 15.3 produz um erro durante a tentativa de converter um tipo em uma classe base que está inacessível. O compilador agora emitirá  
"erro C2243: 'conversão de tipo': a conversão de 'D *' em 'B *' existe, mas está inacessível". O código a seguir está malformado e poderá causar uma falha em tempo de execução. Agora, o compilador produz C2243 ao encontrar código como este:

```cpp
#include <memory> 
 
class B { }; 
class D : B { }; // C2243. should be public B { }; 
 
void f() 
{ 
   std::unique_ptr<B>(new D()); 
}
```
### Os argumentos padrão não são permitidos em definições fora de linha de funções de membro
<a id="default-arguments-are-not-allowed-on-out-of-line-definitions-of-member-functions" class="xliff"></a>
Os argumentos padrão não são permitidos em definições fora da linha de funções de membro em classes de modelo.  O compilador emitirá um aviso em /permissive e um erro de disco rígido em /permissive- em versões anteriores do Visual Studio, o código malformado a seguir pode causar uma falha de tempo de execução. A Versão de Atualização 15.3 produz o aviso C5034: 'A<T>::f': uma definição fora de linha de um membro de um modelo de classe não pode ter argumentos padrão:
```cpp
 
template <typename T> 
struct A { 
    T f(T t, bool b = false); 
}; 
 
template <typename T> 
T A<T>::f(T t, bool b = false) // C5034
{ 
... 
}
```
Para corrigir o erro, remova o argumento padrão "= false". 

### Uso de offsetof com o designador de membro composto
<a id="use-of-offsetof-with-compound-member-designator" class="xliff"></a>
Na Versão de Atualização 15.3, usar offsetof (T, m), em que m é um designador"membro composto", resultará em um aviso quando você compilar com a opção /Wall. O código a seguir está malformado e pode causar falhas em tempo de execução. A Versão de Atualização 15.3 produz o "aviso C4841: extensão não padrão usada: designador de membro composto em deslocamento":

```cpp
  
struct A { 
int arr[10]; 
}; 
 
// warning C4841: non-standard extension used: compound member designator in offsetof 
constexpr auto off = offsetof(A, arr[2]);
```
Para corrigir o código, desabilite o aviso com um pragma ou altere o código para não usar offsetof: 

```cpp
#pragma warning(push) 
#pragma warning(disable: 4841) 
constexpr auto off = offsetof(A, arr[2]); 
#pragma warning(pop) 
```

### Uso do offsetof com o membro de dados estáticos ou função de membro
<a id="using-offsetof-with-static-data-member-or-member-function" class="xliff"></a>
Na Versão de Atualização 15.3, usar offsetof (T, m), em que m se refere a um membro de dados estático ou uma função de membro, resultará em um erro. O código a seguir produz o "erro C4597: comportamento indefinido: offsetof aplicado à função de membro 'foo'" e "erro C4597: comportamento indefinido: offsetof aplicado ao membro de dados estáticos 'bar'":
```cpp
 
#include <cstddef> 
 
struct A { 
int foo() { return 10; } 
static constexpr int bar = 0; 
}; 
 
constexpr auto off = offsetof(A, foo); 
Constexpr auto off2 = offsetof(A, bar);
```
 
Esse código está malformado e pode causar falhas em tempo de execução. Para corrigir o erro, altere o código para não invocar mais um comportamento indefinido. Este é o código não portátil que não é permitido pelo padrão de C++.

### Novo aviso de atributos declspec
<a id="new-warning-on-declspec-attributes" class="xliff"></a>
Na atualização de versão 15.3, o compilador não ignorará atributos se __declspec(...) for aplicado antes da especificação de vinculação externa "C". Anteriormente, o compilador ignorava o atributo, o que podia ter implicações de tempo de execução. Quando a opção `/Wall /WX` é definida, o código a seguir produz o "aviso C4768: atributos __declspec antes da especificação de vinculação são ignorados":

```cpp
 
__declspec(noinline) extern "C" HRESULT __stdcall //C4768
```

Para corrigir o aviso, coloque o "C" externo em primeiro lugar:

```cpp
extern "C" __declspec(noinline) HRESULT __stdcall
```
Esse aviso está desativado por padrão e só afeta o código compilado com `/Wall /WX`.

### decltype e chamadas para destruidores excluídos
<a id="decltype-and-calls-to-deleted-destructors" class="xliff"></a>
Nas versões anteriores do Visual Studio, o compilador não detectava quando ocorria uma chamada para um destruidor excluído no contexto de expressão associado 'decltype'. Na Versão de Atualização 15.3, o código a seguir produz o "Erro C2280: 'A<T>::~A(void)': ao tentar fazer referência a uma função excluída":

```cpp
template<typename T> 
struct A 
{ 
   ~A() = delete; 
}; 
 
template<typename T> 
auto f() -> A<T>; 
 
template<typename T> 
auto g(T) -> decltype((f<T>())); 
 
void h() 
{ 
   g(42); 
}
```
### Variáveis constantes não inicializadas
<a id="uninitialized-const-variables" class="xliff"></a>
A versão do Visual Studio 2017 RTW tinha uma regressão em que o compilador do C++ não emitia um diagnóstico se uma variável 'const' não fosse inicializada. Essa regressão foi corrigida na Atualização 1 do Visual Studio 2017. Agora, o código a seguir produz o "aviso C4132: 'Value': objeto const deve ser inicializado":

```cpp
const int Value; //C4132
```
Para corrigir o erro, atribua um valor a `Value`.

### Declarações vazias
<a id="empty-declarations" class="xliff"></a>
O Visual Studio 2017 Versão de Atualização 15.3 agora avisa sobre declarações vazias para todos os tipos, não apenas tipos internos. Agora, o código a seguir produz um aviso C4091 de nível 2 para todas as quatro declarações:

```cpp
struct A {};
template <typename> struct B {};
enum C { c1, c2, c3 };
 
int;    // warning C4091 : '' : ignored on left of 'int' when no variable is declared
A;      // warning C4091 : '' : ignored on left of 'main::A' when no variable is declared
B<int>; // warning C4091 : '' : ignored on left of 'B<int>' when no variable is declared
C;      // warning C4091 : '' : ignored on left of 'C' when no variable is declared
```

Para remover os avisos, simplesmente comente ou remova as declarações vazias.  Em casos em que o objeto nomeado não se destinar a ter um efeito colateral (como RAII), deverá receber um nome.
 
O aviso é excluído em /Wv:18 e é ativado por padrão em W2 de nível de aviso.


### std::is_convertible para tipos de matriz
<a id="stdisconvertible-for-array-types" class="xliff"></a>
As versões anteriores do compilador forneciam resultados incorretos para [std::is_convertible](standard-library/is-convertible-class.md) para tipos de matriz. Isso exigia que gravadores de biblioteca tratassem o compilador Visual C++ de forma especial ao usar a característica de tipo `std::is_convertable<…>`. No exemplo a seguir, as declarações de estática passam em versões anteriores do Visual Studio, mas falham no Visual Studio 2017 Versão de Atualização 15.3:

```cpp
#include <type_traits>
 
using Array = char[1];
 
static_assert(std::is_convertible<Array, Array>::value);
static_assert((std::is_convertible<const Array, const Array>::value), "");
static_assert((std::is_convertible<Array&, Array>::value), "");
static_assert((std::is_convertible<Array, Array&>::value), "");
```

**std::is_convertible<From, To>** é calculada para verificar se uma definição de função imaginária está bem formada:
```cpp 
   To test() { return std::declval<From>(); }
``` 

### Destruidores particulares e std::is_constructible
<a id="private-destructors-and-stdisconstructible" class="xliff"></a>
As versões anteriores do compilador ignoravam se um destruidor era particular quando decidia o resultado de [std::is_constructible](standard-library/is-constructible-class.md). Agora ele os considera. No exemplo a seguir, as declarações de estática passam em versões anteriores do Visual Studio, mas falham no Visual Studio 2017 Versão de Atualização 15.3:

```cpp
#include <type_traits>
 
class PrivateDtor {
   PrivateDtor(int) { }
private:
   ~PrivateDtor() { }
};
 
// This assertion used to succeed. It now correctly fails.
static_assert(std::is_constructible<PrivateDtor, int>::value);
```  

Os destruidores particulares fazem com que um tipo não seja construível. **std::is_constructible<T, Args…>** é calculada como se a declaração a seguir estivesse escrita:
```cpp 
   T obj(std::declval<Args>()…)
``` 
Essa chamada implica em uma chamada de destruidor.

### C2668: resolução de sobrecarga ambígua
<a id="c2668-ambiguous-overload-resolution" class="xliff"></a>
As versões anteriores do compilador falhavam algumas vezes ao detectar ambiguidade quando encontravam vários candidatos, tanto por meio de declarações using quanto de pesquisas dependentes de argumento. Isso poderia levar à escolha errada de sobrecarga e ao comportamento inesperado de tempo de execução. No exemplo a seguir, o Visual Studio 2017 Versão de Atualização 15.3 aciona corretamente o C2668 'f': chamada ambígua à função sobrecarregada:

```cpp
namespace N {
   template<class T>
   void f(T&, T&);
 
   template<class T>
   void f();
}
 
template<class T>
void f(T&, T&);
 
struct S {};
void f()
{
   using N::f; 
 
   S s1, s2;
   f(s1, s2); // C2668
}
```
Para corrigir o código, remova o uso da instrução N::f se você pretende chamar ::f().

### C2660: declarações de função local e pesquisa dependente de argumento
<a id="c2660-local-function-declarations-and-argument-dependent-lookup" class="xliff"></a>
As declarações de função local ocultam a declaração da função no escopo delimitador e desabilitam a pesquisa dependente de argumento.
No entanto, as versões anteriores do compilador Visual C++ executavam a pesquisa dependente de argumento nesse caso, possivelmente resultando na escolha errada de sobrecarga e em comportamento inesperado de tempo de execução. Normalmente, o erro é devido a uma assinatura incorreta da declaração da função local. No exemplo a seguir, o Visual Studio 2017 Versão de Atualização 15.3 aciona corretamente o C2660 'f': função não recebe 2 argumentos:

```cpp
struct S {}; 
void f(S, int);
 
void g()
{
   void f(S); // C2660 'f': function does not take 2 arguments:
   // or void f(S, int);
   S s;
   f(s, 0);
}
```

Para corrigir o problema, altere a assinatura **f(S)** ou remova-a.

### C5038: ordem de inicialização em listas de inicializador
<a id="c5038-order-of-initialization-in-initializer-lists" class="xliff"></a>
Os membros de classe são inicializados na ordem em que são declarados e não na ordem em que aparecem em listas de inicializador. As versões anteriores do compilador não avisavam quando a ordem da lista de inicializador era diferente da ordem da declaração. Isso poderia resultar em comportamento indefinido de tempo de execução, caso a inicialização de um membro dependesse de outro membro na lista que já estivesse sendo inicializada. No exemplo a seguir, o Visual Studio 2017 Versão de Atualização 15.3 (com /Wall ou /WX) aciona o aviso C5038: membro de dados 'A::y' será inicializados após o membro de dados 'A::x':

```cpp
struct A
{
    A(int a) : y(a), x(y) {} // Initialized in reverse, y reused
    int x;
    int y;
};

```
Para corrigir o problema, organize a lista de inicializador para que tenha a mesma ordem que as declarações. Um aviso semelhante é gerado quando um ou ambos os inicializadores fazem referência a membros de classe base.

Observe que o aviso está desativado por padrão e afeta somente o código compilado com /Wall ou /WX.

## Consulte também
<a id="see-also" class="xliff"></a>  
[Conformidade com a linguagem Visual C++](visual-cpp-language-conformance.md)  

