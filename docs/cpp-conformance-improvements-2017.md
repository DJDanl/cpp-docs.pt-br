---
title: Melhorias de conformidade do compilador C++ | Microsoft Docs
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- vs-ide-general
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 8801dbdb-ca0b-491f-9e33-01618bff5ae9
author: BrianPeek
ms.author: brpeek
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
translationtype: Human Translation
ms.sourcegitcommit: a769a69a788c2c7ae1fd9854afe89d1feccf9278
ms.openlocfilehash: bc9ac2892eb9372586f101d706e744e60ebda3ce
ms.lasthandoff: 03/02/2017

---
   
# <a name="c-conformance-improvements-in-includevsdev15mdmiscincludesvsdev15mdmd"></a>Melhorias de conformidade do C++ no [!INCLUDE[vs_dev15_md](misc/includes/vs_dev15_md.md)]

## <a name="new-language-features"></a>Novos recursos de linguagem  
Com suporte para constexpr generalizado e NSDMI para agregações, agora o compilador está completo com relação aos recursos adicionados no padrão C++14. Observe que o compilador ainda não tem alguns recursos dos padrões C++11 e C++98.

### <a name="c11"></a>C++11:
**Suporte da expressão SFINAE em mais bibliotecas** O compilador do Visual C++ continua melhorando seu suporte da expressão SFINAE, necessário para dedução e substituição de argumentos de modelo em que as expressões decltype e constexpr podem ser exibidas como parâmetros de modelo. Para obter mais informações, consulte [Expression SFINAE improvements in Visual Studio 2017 RC (Melhorias da expressão SFINAE no Visual Studio 2017 RC)](https://blogs.msdn.microsoft.com/vcblog/2016/06/07/expression-sfinae-improvements-in-vs-2015-update-3). 


### <a name="c-14"></a>C++ 14:
**NSDMI para agregações** Uma agregação é uma matriz ou uma classe sem nenhum construtor fornecido pelo usuário, sem membros de dados não estáticos privados ou protegidos, sem classes base e sem funções virtuais. Começando pelo C ++14, as agregações podem conter inicializadores de membro. Para obter mais informações, consulte [Member initializers and aggregates (Inicializadores de membro e agregações)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3605.html).

**Constexpr estendida** Agora as expressões declaradas como constexpr podem conter alguns tipos de declaração, instruções if e switch, declarações de loop e mutação de objetos cujo tempo de vida começou dentro da avaliação da expressão constexpr. Além disso, não há mais o requisito de que uma função membro não estática constexpr seja implicitamente const. Para obter mais informações, consulte [Relaxing constraints on constexpr functions (Relaxando restrições em funções constexpr)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3652.html). 

### <a name="c17"></a>C++17:
**Static_assert concisa** (disponível com /std:c++latest) No C++17, o parâmetro da mensagem para static_assert é opcional. Para obter mais informações, consulte [Extending static_assert, v2 (Estendendo static_assert, v2)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.pdf). 

**Atributo [[fallthrough]]** (disponível com /std:c++latest) O atributo [[fallthrough]] pode ser usado no contexto de instruções switch como uma dica para o compilador de que o comportamento fall-through é intencional. Isso impede o compilador de emitir avisos em tais casos. Para obter mais informações, consulte [Wording for [[fallthrough]] attribute (Expressão para atributo [[fallthrough]])](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r0.pdf). 

**Loops “for” baseados em intervalo generalizados** (não é necessária nenhuma opção de compilador) Loops “for” baseados em intervalo não exigem mais que begin() e end() retornem objetos do mesmo tipo. Isso permite que end() retorne um objeto sentinela como usado por intervalos, conforme definido na proposta Ranges-V3. Para obter mais informações, consulte [Generalizing the Range-Based For Loop (Generalizando o loop “for” baseado em intervalo)](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html) e [range-v3 library on GitHub (Biblioteca range-v3 no GitHub)](https://github.com/ericniebler/range-v3). 


Para obter uma lista das melhorias de conformidade até o Visual Studio 2015, Atualização 3, consulte [Visual C++ What's New 2003 through 2015 (Novidades do Visual C++ 2003 a 2015)](https://msdn.microsoft.com/en-us/library/mt723604.aspx).

## <a name="bug-fixes"></a>Correções de bug
### <a name="copy-list-initialization"></a>Inicialização de lista de cópia
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
struct MyList {
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

### <a name="deprecated-typedefs"></a>Typedefs preteridos
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

### <a name="constexpr"></a>constexpr
O Visual Studio 2017 gera corretamente um erro quando o operando esquerdo de uma operação de avaliação condicional é inválido em um contexto constexpr. O código a seguir é compilado no Visual Studio 2015, mas não no Visual Studio 2017:

```cpp  
template<int N>
struct array 
{
       int size() const { return N; }
};

constexpr bool f(const array<1> &arr)
{
       return arr.size() == 10 || arr.size() == 11; // error starting in Visual Studio 2017
}
```
Para corrigir o erro, declare a função array::size() como constexpr ou remova o qualificador constexpr de f. 

### <a name="class-types-passed-to-variadic-functions"></a>Tipos de classe passados para funções variadic
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
Para cadeias de caracteres criadas e gerenciadas usando o CStringW, o “operador LPCWSTR()” fornecido deve ser usado para converter um objeto CStringW no ponteiro do C esperado pela cadeia de caracteres de formato.

```cpp  
CStringW str1;
CStringW str2;
str1.Format(… , static_cast<LPCWSTR>(str2));
```

### <a name="cv-qualifiers-in-class-construction"></a>Qualificadores CV na construção de classe
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

### <a name="access-checking-on-qualified-names-in-templates"></a>Verificação de acesso em nomes qualificados em modelos
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

### <a name="missing-template-argument-lists"></a>Listas de argumentos de modelo ausentes
No Visual Studio 2015 e anteriores, o compilador não diagnosticava listas de argumentos de modelo ausentes quando o modelo era exibido em uma lista de parâmetro de modelo (por exemplo, como parte de um argumento de modelo padrão ou um parâmetro de não tipo de modelo). Isso pode resultar em comportamento imprevisível, incluindo falhas do compilador ou comportamento inesperado do tempo de execução. O código a seguir é compilado no Visual Studio 2015, mas produz um erro no Visual Studio 2017.

```cpp  
template <class T> class ListNode;
template <class T> using ListNodeMember = ListNode<T> T::*;
template <class T, ListNodeMember M> class ListHead; // C2955: 'ListNodeMember': use of alias 
                                                     // template requires template argument list

// correct:  template <class T, ListNodeMember<T> M> class ListHead;  
```

### <a name="expression-sfinae"></a>Expressão SFINAE
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

### <a name="default-initializers-for-value-class-members-ccli"></a>Inicializadores padrão para membros de classe de valor (C++/CLI)
No Visual Studio 2015 e nas versões anteriores, o compilador permitia (mas ignorava) um inicializador de membro padrão para um membro de uma classe de valor.  A inicialização padrão de uma classe de valor sempre inicializa os membros em zero; um construtor padrão não é permitido.  No Visual Studio 2017, os inicializadores de membro padrão geram um erro de compilador, conforme mostrado neste exemplo:

```cpp  
value struct V
{
       int i = 0; // error C3446: 'V::i': a default member initializer  
                  // is not allowed for a member of a value class
};
```

### <a name="default-indexers-ccli"></a>Indexadores padrão (C++/CLI)
No Visual Studio 2015 e em versões anteriores, o compilador, em alguns casos, identificava incorretamente uma propriedade padrão como um indexador padrão. É possível resolver o problema usando o identificador "padrão" para acessar a propriedade. A solução em si se tornou um problema depois que o padrão foi introduzido como uma palavra-chave no C++&11;. Portanto, no Visual Studio 2017, os bugs que exigiam a solução alternativa foram corrigidos, e agora o compilador gera um erro quando o “padrão” é usado para acessar a propriedade padrão de uma classe.

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

## <a name="see-also"></a>Consulte também  
[Conformidade com a linguagem Visual C/C++](c-cpp-language-conformance.md)  

