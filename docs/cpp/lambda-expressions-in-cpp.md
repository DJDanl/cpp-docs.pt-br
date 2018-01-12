---
title: "Expressões lambda em C++ | Microsoft Docs"
ms.custom: 
ms.date: 07/19/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- lambda expressions [C++]
- lambda expressions [C++], overview
- lambda expressions [C++], vs. function objects
ms.assetid: 713c7638-92be-4ade-ab22-fa33417073bf
caps.latest.revision: "36"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 035fe5c222f6de5b3f0d71c0ce9133c1101f2993
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="lambda-expressions-in-c"></a>Expressões lambda em C++
No C++ 11 e posterior, uma expressão lambda — geralmente chamada uma *lambda*— é uma maneira conveniente de definir um objeto de função anônima (um *fechamento*) à direita no local onde ele é chamado ou passado como um argumento para uma função. Normalmente lambdas são usados para encapsular algumas linhas de código que são passadas para algoritmos ou métodos assíncronos. Este artigo define o que são as lambdas, as compara a outras técnicas de programação, descreve suas vantagens e fornece um exemplo básico.  

## <a name="related-topics"></a>Tópicos relacionados
- [Expressões lambda vs. objetos de função](lambda-expression-syntax.md)
- [Trabalhando com expressões lambda](examples-of-lambda-expressions.md)
- [expressões lambda de constexpr](lambda-expressions-constexpr.md)

## <a name="parts-of-a-lambda-expression"></a>Partes de uma expressão Lambda  
 O ISO C++ padrão mostra um simple lambda que é passado como o terceiro argumento para o `std::sort()` função:  
  
```cpp  
#include <algorithm>  
#include <cmath>  
  
void abssort(float* x, unsigned n) {  
    std::sort(x, x + n,  
        // Lambda expression begins  
        [](float a, float b) {  
            return (std::abs(a) < std::abs(b));  
        } // end of lambda expression  
    );  
}  
  
```  
  
 Esta ilustração mostra as partes de uma expressão lambda:  
  
 ![Elementos estruturais de uma expressão lambda](../cpp/media/lambdaexpsyntax.png "LambdaExpSyntax")  
  
1.  *capturar cláusula* (também conhecido como o *Introdutor lambda* na especificação do C++.)  
  
2.  *lista de parâmetros* opcional. (Também conhecido como o *declarador lambda*)  
  
3.  *especificação mutável* opcional.  
  
4.  *especificação de exceção* opcional.  
  
5.  *à direita-tipo de retorno* opcional.  
  
6.  *corpo lambda*)  
  
### <a name="capture-clause"></a>Cláusula capture  
 Uma expressão lambda pode introduzir novas variáveis em seu corpo (em **C + + 14**) e ele também pode acessar, ou *capturar*, variáveis do escopo ao redor. Uma expressão lambda começa com a cláusula de captura (*Introdutor lambda* na sintaxe padrão), que especifica quais variáveis são capturadas e se a captura é por valor ou por referência. Variáveis que têm o prefixo E comercial (`&`) são acessadas por referência e variáveis que não têm o prefixo são acessadas por valor.  
  
 Uma cláusula de captura vazia, `[ ]`, indica que o corpo da expressão lambda não acessa variáveis no escopo delimitador.  
  
 Você pode usar o modo de captura padrão (*padrão de captura* na sintaxe padrão) para indicar como capturar qualquer fora variáveis que são referenciadas no lambda: `[&]` significa que todas as variáveis que você consulte são capturadas pelo referência, e `[=]` significa que elas são capturadas por valor. Você pode usar um modo de captura padrão e, em seguida, especifique o modo oposto explicitamente para variáveis específicas. Por exemplo, se um corpo de lambda acessar a variável externa `total` por referência e a variável externa `factor` por valor, as seguintes cláusulas de captura serão equivalentes:  
  
```cpp  
[&total, factor]  
[factor, &total]  
[&, factor]  
[factor, &]  
[=, &total]  
[&total, =]  
```  
  
 Apenas as variáveis que são mencionadas na lambda são capturadas quando um padrão de captura é usado.  
  
 Se uma cláusula de captura inclui um padrão de captura `&`, nenhuma `identifier` em uma `capture` que captura a cláusula pode ter a forma `& identifier`. Da mesma forma, se a cláusula de captura inclui um padrão de captura `=`, nenhuma `capture` que captura a cláusula pode ter a forma `= identifier`. Um identificador ou `this` não podem aparecer mais de uma vez em uma cláusula capture. O trecho de código a seguir ilustra alguns exemplos.  
  
```cpp  
struct S { void f(int i); };  
  
void S::f(int i) {  
    [&, i]{};      // OK  
    [&, &i]{};     // ERROR: i preceded by & when & is the default  
    [=, this]{};   // ERROR: this when = is the default  
    [=, *this]{ }; // OK: captures this by value. See below.
    [i, i]{};      // ERROR: i repeated  
}  
```  
  
 Uma captura seguida por um sinal de reticências é um pacote de expansão, conforme mostrado neste [modelo variadic](../cpp/ellipses-and-variadic-templates.md) exemplo:  
  
```cpp  
template<class... Args>  
void f(Args... args) {  
    auto x = [args...] { return g(args...); };  
    x();  
}  
```  
  
 Para usar expressões lambda no corpo de um método de classe, passa o `this` ponteiro para a cláusula de captura para fornecer acesso para os membros de dados e os métodos da classe delimitador. 
 
**Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): O `this` ponteiro pode ser capturado por valor especificando `*this` na cláusula de captura. Captura pelo valor significa que todo o *fechamento*, que é o objeto de função anônima que encapulates a expressão lambda, é copiado para cada site de chamada onde o lambda é chamado. Captura pelo valor é útil quando o lambda será executado em paralelas ou assíncronas operações, especialmente em determinadas arquiteturas de hardware, como NUMA. 

Para obter um exemplo que mostra como usar expressões lambda com métodos de classe, consulte "Exemplo: usando uma expressão em um método Lambda" [exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md).  
  
 Ao usar a cláusula de captura, nós recomendamos que você mantenha esses pontos em mente, especialmente ao usar lambdas com multithreading:  
  
-   As capturas de referência podem ser usadas para modificar variáveis externas, mas as capturas de valor não. (`mutable` permite cópias a serem modificados, mas não originais.)  
  
-   As capturas de referência refletem atualizações para variáveis externas, mas as capturas de valor não.  
  
-   As capturas de referência introduzem uma dependência de tempo de vida, mas as capturas de valor não possuem dependências de tempo de vida. Isso é especialmente importante quando o lambda executa de forma assíncrona. Se você capturar um local por referência em um lambda assíncronas, esse local será muito possivelmente retirada no momento em que o lambda é executado, resultando em uma violação de acesso em tempo de execução.  
  
### <a name="generalized-capture-c-14"></a>Captura generalizada (C++ 14)  
  
 No C++ 14, você pode introduzir e inicializar novas variáveis na cláusula de captura, sem a necessidade de ter essas variáveis existem no escopo de fechamento da função lambda. A inicialização pode ser expressada como qualquer expressão arbitrária; o tipo da nova variável é deduzido do tipo produzido pela expressão. Uma vantagem desse recurso é que, em C++ 14, você pode capturar somente mover variáveis (como STD:: unique_ptr) do escopo ao redor e usá-los em uma expressão lambda.  
  
```cpp  
pNums = make_unique<vector<int>>(nums);  
//...  
      auto a = [ptr = move(pNums)]()  
        {  
           // use ptr  
        };  
```  
  
### <a name="parameter-list"></a>Lista de parâmetros  
 Além de capturar variáveis, uma expressão lambda pode aceitar parâmetros de entrada. Uma lista de parâmetros (*declarador lambda* na sintaxe padrão) é opcional e na maioria dos aspectos é semelhante a lista de parâmetros para uma função.  
  
```cpp  
auto y = [] (int first, int second)  
{  
    return first + second;  
};  
  
```  
  
 Em **C++ 14**, se o tipo de parâmetro genérico, você pode usar a palavra-chave auto como o especificador de tipo. Isso informa ao compilador para criar o operador de chamada de função como um modelo. Cada instância de auto em uma lista de parâmetro é equivalente a um parâmetro de tipo distinto.  
  
```cpp  
auto y = [] (auto first, auto second)  
{  
    return first + second;  
};  
```  
  
 Uma expressão lambda pode usar outra expressão lambda como seu argumento. Para obter mais informações, consulte "Expressões Lambda de ordem superior" no tópico [exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md).  
  
 Como uma lista de parâmetros é opcional, você pode omitir os parênteses vazios se você não passar argumentos para a expressão lambda e seu Declarador de lambda não contém *especificação de exceção*,  *à direita-tipo de retorno*, ou `mutable`.  
  
### <a name="mutable-specification"></a>Especificação mutável  
 Geralmente, o operador de chamada de função de uma lambda é constante por valor, mas o uso da palavra-chave `mutable` cancela esse efeito. Membros de dados mutáveis não são produzidos. A especificação mutável permite que o corpo de uma expressão lambda modifique variáveis capturadas por valor. Alguns dos exemplos, mais adiante neste artigo, mostram como usar `mutable`.  
  
### <a name="exception-specification"></a>Especificação de exceção  
 É possível usar a especificação de exceção `noexcept` para indicar que a expressão lambda não lança nenhuma exceção. Como com funções comuns, o compilador do Visual C++ gera o aviso [C4297](../error-messages/compiler-warnings/compiler-warning-level-1-c4297.md) se uma expressão lambda declara o `noexcept` especificação de exceção e o corpo lambda lança uma exceção, conforme mostrado aqui:  
  
```cpp  
// throw_lambda_expression.cpp  
// compile with: /W4 /EHsc   
int main() // C4297 expected  
{  
   []() noexcept { throw 5; }();  
}  
```  
  
 Para obter mais informações, consulte [especificações de exceção (lançar)](../cpp/exception-specifications-throw-cpp.md).  
  
### <a name="return-type"></a>Tipo de retorno  
 O tipo de retorno de uma expressão lambda é deduzido automaticamente. Você não precisa usar o [automática](../cpp/auto-cpp.md) palavra-chave, a menos que você especificar um *à direita-tipo de retorno*. O *tipo à direita de retorno de* é semelhante a parte do tipo de retorno de um método comum ou uma função. No entanto, o tipo de retorno deve seguir a lista de parâmetros e você deve incluir a palavra-chave trailing-return-type `->` antes do tipo de retorno.  
  
 É possível omitir a parte return-type de uma expressão lambda se o corpo lambda contiver apenas uma instrução de retorno ou se a expressão lambda não retornar um valor. Se o corpo lambda contém uma instrução de retorno, o compilador deduzirá o tipo de retorno do tipo da expressão de retorno. Caso contrário, o compilador deduzirá que o tipo de retorno é `void`. Considere os trechos de código do exemplo a seguir que ilustram esse princípio.  
  
```cpp  
auto x1 = [](int i){ return i; }; // OK: return type is int  
auto x2 = []{ return{ 1, 2 }; };  // ERROR: return type is void, deducing   
                                  // return type from braced-init-list is not valid  
```  
  
 Uma expressão lambda pode gerar outra expressão lambda como seu valor de retorno. Para obter mais informações, consulte "Expressões Lambda de ordem superior" em [exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md).  
  
### <a name="lambda-body"></a>Corpo lambda  
 O corpo lambda (*compostas instrução* na sintaxe padrão) de uma expressão lambda expressão pode conter qualquer coisa que o corpo de um método comum ou função pode conter. O corpo de uma função comum e de uma expressão lambda pode acessar os seguintes tipos de variáveis:  
  
-   Capturar variáveis de escopo delimitador, conforme descrito anteriormente.  
  
-   Parâmetros  
  
-   Variáveis declaradas localmente  
  
-   Membros de dados de classe, quando declarados dentro de uma classe e quando `this` for capturado  
  
-   Qualquer variável que possui a duração de armazenamento estático como, por exemplo, variáveis globais  
  
 O exemplo a seguir contém uma expressão lambda que captura explicitamente a variável `n` por valor e que captura implicitamente a variável `m` por referência:  
  
```cpp  
// captures_lambda_expression.cpp  
// compile with: /W4 /EHsc   
#include <iostream>  
using namespace std;  
  
int main()  
{  
   int m = 0;  
   int n = 0;  
   [&, n] (int a) mutable { m = ++n + a; }(4);  
   cout << m << endl << n << endl;  
}  
```  
  
```Output  
5  
0  
```  
  
 Como a variável `n` é capturada pelo valor, seu valor permanece `0` após a chamada para a expressão lambda. A especificação `mutable` permite que `n` seja modificada na lambda.  
  
 Embora uma expressão lambda possa capturar apenas variáveis que tenham a duração automática de armazenamento, você pode usar variáveis que tenham a duração de armazenamento estático no corpo de uma expressão lambda. O exemplo a seguir usa a função `generate` e uma expressão lambda para atribuir um valor para cada elemento em um objeto `vector`. A expressão lambda modifica a variável estática para gerar o valor do próximo elemento.  
  
```cpp  
void fillVector(vector<int>& v)  
{  
    // A local static variable.  
    static int nextValue = 1;  
  
    // The lambda expression that appears in the following call to  
    // the generate function modifies and uses the local static   
    // variable nextValue.  
    generate(v.begin(), v.end(), [] { return nextValue++; });   
    //WARNING: this is not thread-safe and is shown for illustration only  
}  
```  
  
 Para obter mais informações, consulte [gerar](../standard-library/algorithm-functions.md#generate).  
  
 O exemplo de código a seguir usa a função do exemplo anterior e adiciona um exemplo de uma expressão lambda que usa o algoritmo de biblioteca padrão C++ `generate_n`. Essa expressão lambda atribui um elemento de um objeto `vector` à soma dos dois elementos anteriores. A palavra-chave `mutable` é usada de modo que o corpo da expressão lambda possa modificar suas cópias das variáveis externas `x` e `y`, que a expressão lambda captura por valor. Uma vez que a expressão lambda captura as variáveis originais `x` e `y` por valor, seus valores permanecem `1` depois que a lambda é executada.  
  
```cpp  
// compile with: /W4 /EHsc  
#include <algorithm>  
#include <iostream>  
#include <vector>  
#include <string>  
  
using namespace std;  
  
template <typename C> void print(const string& s, const C& c) {  
    cout << s;  
  
    for (const auto& e : c) {  
        cout << e << " ";  
    }  
  
    cout << endl;  
}  
  
void fillVector(vector<int>& v)  
{  
    // A local static variable.  
    static int nextValue = 1;  
  
    // The lambda expression that appears in the following call to  
    // the generate function modifies and uses the local static   
    // variable nextValue.  
    generate(v.begin(), v.end(), [] { return nextValue++; });  
    //WARNING: this is not thread-safe and is shown for illustration only  
}  
  
int main()  
{  
    // The number of elements in the vector.  
    const int elementCount = 9;  
  
    // Create a vector object with each element set to 1.  
    vector<int> v(elementCount, 1);  
  
    // These variables hold the previous two elements of the vector.  
    int x = 1;  
    int y = 1;  
  
    // Sets each element in the vector to the sum of the   
    // previous two elements.  
    generate_n(v.begin() + 2,  
        elementCount - 2,  
        [=]() mutable throw() -> int { // lambda is the 3rd parameter  
        // Generate current value.  
        int n = x + y;  
        // Update previous two values.  
        x = y;  
        y = n;  
        return n;  
    });  
    print("vector v after call to generate_n() with lambda: ", v);  
  
    // Print the local variables x and y.  
    // The values of x and y hold their initial values because   
    // they are captured by value.  
    cout << "x: " << x << " y: " << y << endl;  
  
    // Fill the vector with a sequence of numbers  
    fillVector(v);  
    print("vector v after 1st call to fillVector(): ", v);  
    // Fill the vector with the next sequence of numbers  
    fillVector(v);  
    print("vector v after 2nd call to fillVector(): ", v);  
}  
```  
  
```Output  
vector v after call to generate_n() with lambda: 1 1 2 3 5 8 13 21 34  
x: 1 y: 1  
vector v after 1st call to fillVector(): 1 2 3 4 5 6 7 8 9  
vector v after 2nd call to fillVector(): 10 11 12 13 14 15 16 17 18  
```  
  
 Para obter mais informações, consulte [generate_n](../standard-library/algorithm-functions.md#generate_n).  

## <a name="constexpr-lambda-expressions"></a>expressões lambda de constexpr
**Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): uma expressão lambda pode ser declarada como `constexpr` ou usados em uma expressão constante quando a inicialização de cada membro de dados que ele captura ou introduz é permitida dentro de uma expressão constante.  

```cpp
    int y = 32;
    auto answer = [y]() constexpr 
    {
        int x = 10;
        return y + x; 
    };

    constexpr int Increment(int n) 
    {
        return [n] { return n + 1; }();
    }

``` 
Uma expressão lambda é implicitamente `constexpr` se seu resultado satisfaz os requisitos de um `constexpr` função:
```cpp
    auto answer = [](int n) 
    {
        return 32 + n; 
    };

    constexpr int response = answer(10);
``` 
Se uma expressão lambda é implicitamente ou explicitamente `constexpr`, conversão para um ponteiro de função produz um `constexpr` função:

```cpp
    auto Increment = [](int n)
    {
        return n + 1;
    };

    constexpr int(*inc)(int) = Increment;
```
  
## <a name="microsoft-specific"></a>Específico da Microsoft  
 As lambdas não têm suporte nas seguintes entidades gerenciadas de CLR (Common Language Runtime): `ref class`, `ref struct`, `value class` ou `value struct`.  
  
 Se você estiver usando um modificador específicas da Microsoft, como [declspec](../cpp/declspec.md), você pode inserir uma expressão lambda imediatamente após o `parameter-declaration-clause`— por exemplo:  
  
```cpp  
auto Sqr = [](int t) __declspec(code_seg("PagedMem")) -> int { return t*t; };  
```  
  
 Para determinar se um modificador é suportado pelo lambdas, consulte o artigo sobre ele no [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md) seção da documentação.  
  
 Além de C++ 11 funcionalidade de lambda padrão, o Visual Studio oferece suporte a lambdas sem monitoração de estado, que são omni conversíveis para ponteiros de função que usam convenções de chamada arbitrárias.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Objetos de função na biblioteca C++ padrão](../standard-library/function-objects-in-the-stl.md)   
 [Chamada de função](../cpp/function-call-cpp.md)   
 [for_each](../standard-library/algorithm-functions.md#for_each)
