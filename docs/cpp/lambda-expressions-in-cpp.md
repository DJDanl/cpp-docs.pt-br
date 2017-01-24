---
title: "Express&#245;es lambda em C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "expressões lambda [C++]"
  - "expressões lambda [C++], visão geral"
  - "expressões lambda [C++], vs. objetos de função"
ms.assetid: 713c7638-92be-4ade-ab22-fa33417073bf
caps.latest.revision: 36
caps.handback.revision: 34
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Express&#245;es lambda em C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

No C\+\+ 11, uma expressão lambda, geralmente chamado de um *lambda*— é uma maneira conveniente de definir um objeto de função anônima à direita no local onde ele é chamado ou passado como um argumento para uma função.  Normalmente, lambdas são usados para encapsular algumas linhas de código que são passadas para algoritmos ou métodos assíncronos.  Este artigo define o que são as lambdas, as compara a outras técnicas de programação, descreve suas vantagens e fornece um exemplo básico.  
  
## Partes de uma expressão Lambda  
 O padrão ISO C\+\+ mostra um simple lambda que é passada como o terceiro argumento para a `std::sort()` função:  
  
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
  
 Esta ilustração mostra as partes de uma lambda:  
  
 ![Os elementos estruturais de uma expressão lambda](../cpp/media/lambdaexpsyntax.png "LambdaExpSyntax")  
  
1.  *cláusula capture* \(também conhecido como o *lambda Introdutor* na especificação do C\+\+.\)  
  
2.  *lista de parâmetros* opcional.  \(Também conhecido como o *declarador lambda*\)  
  
3.  *especificação mutável* opcional.  
  
4.  *especificação de exceção* opcional.  
  
5.  *tipo à direita de retorno* opcional.  
  
6.  *corpo lambda*\)  
  
### Cláusula capture  
 Um lambda pode introduzir novas variáveis em seu corpo \(no **C \+ \+ 14**\), e também podem acessar – ou *capturar*– variáveis do escopo ao redor.  Um lambda começa com a cláusula capture \(*lambda Introdutor* na sintaxe padrão\), que especifica quais variáveis são capturadas, e se a captura é por valor ou por referência.  Variáveis que têm o prefixo E comercial \(`&`\) são acessadas por referência e variáveis que não têm o prefixo são acessadas por valor.  
  
 Uma cláusula de captura vazia, `[ ]`, indica que o corpo da expressão lambda não acessa variáveis no escopo delimitador.  
  
 Você pode usar o modo de captura padrão \(`capture-default` na sintaxe padrão\) para indicar como capturar qualquer fora variáveis que são referenciadas no lambda: \[e\] significa que todas as variáveis que você consulte são capturadas por referência e \[\=\] significa que eles são capturados pelo valor.  Você pode usar um modo de captura padrão e, em seguida, especificar o modo oposto explicitamente para variáveis específicas.  Por exemplo, se um corpo de lambda acessar a variável externa `total` por referência e a variável externa `factor` por valor, as seguintes cláusulas de captura serão equivalentes:  
  
```cpp  
  
[&total, factor]  
[factor, &total]  
[&, factor]  
[factor, &]  
[=, &total]  
[&total, =]  
```  
  
 Somente as variáveis que são mencionadas na lambda são capturadas quando um `capture-default` é usado.  
  
 Se uma cláusula de captura inclui um `capture-default` `&`, então nenhum `identifier` em um `capture` da cláusula de captura pode ter o formato `& identifier`.  Da mesma forma, se uma cláusula de captura inclui um `capture-default` `=`, então nenhum `capture` da cláusula de captura pode ter o formato `= identifier`.  Um identificador ou `this` não podem aparecer mais de uma vez em uma cláusula capture.  O trecho de código a seguir ilustra alguns exemplos.  
  
```cpp  
struct S { void f(int i); };  
  
void S::f(int i) {  
    [&, i]{};    // OK  
    [&, &i]{};   // ERROR: i preceded by & when & is the default  
    [=, this]{}; // ERROR: this when = is the default  
    [i, i]{};    // ERROR: i repeated  
}  
```  
  
 Um `capture` seguido por reticências é uma expansão do pacote, conforme mostrado neste exemplo de [modelo variadic](../cpp/ellipses-and-variadic-templates.md):  
  
```cpp  
template<class... Args>  
void f(Args... args) {  
    auto x = [args...] { return g(args...); };  
    x();  
}  
```  
  
 Para usar expressões lambda no corpo de um método de classe, passe o `this` ponteiro para a cláusula de captura para fornecer acesso aos membros de dados e métodos da classe delimitadora.  Para obter um exemplo que mostra como usar expressões lambda com métodos de classe, consulte "Exemplo: usando um Lambda expressão em um método" [Exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md).  
  
 Ao usar a cláusula de captura, nós recomendamos que você mantenha esses pontos em mente, especialmente ao usar lambdas com multithreading:  
  
-   As capturas de referência podem ser usadas para modificar variáveis externas, mas as capturas de valor não.  \(`mutable` permite cópias sejam modificadas, mas não originais.\)  
  
-   As capturas de referência refletem atualizações para variáveis externas, mas as capturas de valor não.  
  
-   As capturas de referência introduzem uma dependência de tempo de vida, mas as capturas de valor não possuem dependências de tempo de vida.  Isso é especialmente importante quando lambda é executado de forma assíncrona.  Se você capturar um local por referência em um lambda assíncrono, esse local será muito possivelmente retirada no momento em que a lambda é executado, resultando em uma violação de acesso em tempo de execução.  
  
 **Captura generalizada \(C\+\+ 14\)**  
  
 No C\+\+ 14, você pode introduzir e inicializar novas variáveis na cláusula de captura, sem a necessidade de ter essas variáveis existirem no escopo delimitador da função lambda.  A inicialização pode ser expresso como qualquer expressão arbitrária; o tipo da nova variável é deduzido do tipo produzido pela expressão.  Uma vantagem desse recurso é que, no C\+\+ 14, você pode capturar somente mover variáveis \(como STD:: unique\_ptr\) do escopo ao redor e usá\-los em um lambda.  
  
```  
pNums = make_unique<vector<int>>(nums);  
//...  
      auto a = [ptr = move(pNums)]()  
        {  
           // use ptr  
        };  
```  
  
### Lista de Parâmetro  
 Além de capturar a variáveis, uma lambda pode aceitar parâmetros de entrada.  Uma lista de parâmetros \(*declarador lambda* na sintaxe padrão\) é opcional e, na maioria dos aspectos se parece com a lista de parâmetros para uma função.  
  
```  
int y = [] (int first, int second)  
{  
    return first + second;  
};  
  
```  
  
 Em **C\+\+ 14**, se o tipo de parâmetro for genérico, você pode usar a palavra\-chave auto como o especificador de tipo.  Isso informa ao compilador para criar o operador de chamada de função como um modelo.  Cada instância do automaticamente em uma lista de parâmetros é equivalente a um parâmetro de tipo diferente.  
  
```  
auto y = [] (auto first, auto second)  
{  
    return first + second;  
};  
```  
  
 Uma expressão lambda pode usar outra expressão lambda como seu argumento.  Para obter mais informações, consulte "Expressões Lambda de ordem superior" no tópico [Exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md).  
  
 Porque uma lista de parâmetros é opcional, você pode omitir os parênteses vazios caso não passe argumentos para a expressão lambda e seu `lambda-declarator:` não contenha *exception\-specification*, *trailing\-return\-type* ou `mutable`.  
  
### Especificação mutável  
 Geralmente, o operador de chamada de função de uma lambda é constante por valor, mas o uso da palavra\-chave `mutable` cancela esse efeito.  Membros de dados mutáveis não são produzidos.  A especificação mutável permite que o corpo de uma expressão lambda modifique variáveis capturadas por valor.  Alguns dos exemplos, mais adiante neste artigo, mostram como usar `mutable`.  
  
### Especificação de exceção  
 É possível usar a especificação de exceção `throw()` para indicar que a expressão lambda não lança nenhuma exceção.  Assim como em funções regulares, o compilador Visual C\+\+ gera o aviso [C4297](../Topic/Compiler%20Warning%20\(level%201\)%20C4297.md) caso uma expressão lambda declare a especificação de exceção `throw()` e o corpo lambda lance uma exceção, conforme apresentado a seguir:  
  
```cpp  
// throw_lambda_expression.cpp  
// compile with: /W4 /EHsc   
int main() // C4297 expected  
{  
   []() throw() { throw 5; }();  
}  
```  
  
 Para obter mais informações, consulte [Especificações de exceção \(lançar\)](../cpp/exception-specifications-throw-cpp.md).  
  
### Tipo de Retorno  
 O tipo de retorno de uma expressão lambda é deduzido automaticamente.  Você não precisa usar o [automático](../cpp/auto-cpp.md) palavra\-chave, a menos que você especifique um *à direita\-tipo de retorno*.  O *trailing\-return\-type* se parece com a parte return\-type de um método ou de uma função comum.  No entanto, o tipo de retorno deve seguir a lista de parâmetros e você deve incluir a palavra\-chave trailing\-return\-type `->` antes do tipo de retorno.  
  
 É possível omitir a parte return\-type de uma expressão lambda se o corpo lambda contiver apenas uma instrução de retorno ou se a expressão lambda não retornar um valor.  Se o corpo lambda contém uma instrução de retorno, o compilador deduzirá o tipo de retorno do tipo da expressão de retorno.  Caso contrário, o compilador deduzirá que o tipo de retorno é `void`.  Considere os trechos de código do exemplo a seguir que ilustram esse princípio.  
  
```cpp  
auto x1 = [](int i){ return i; }; // OK: return type is int  
auto x2 = []{ return{ 1, 2 }; };  // ERROR: return type is void, deducing   
                                  // return type from braced-init-list is not valid  
  
```  
  
 Uma expressão lambda pode gerar outra expressão lambda como seu valor de retorno.  Para obter mais informações, consulte "Expressões Lambda de ordem superior" [Exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md).  
  
### Corpo lambda  
 A parte do corpo lambda \(*compound\-statement* na sintaxe padrão\) de uma expressão lambda pode conter tudo o que o corpo de um método ou uma função comum pode conter.  O corpo de uma função comum e de uma expressão lambda pode acessar os seguintes tipos de variáveis:  
  
-   Capturadas variáveis no escopo delimitador, conforme descrito anteriormente.  
  
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
  
 **Saída:**  
  
  **5**  
**0** Como a variável `n` é capturada pelo valor, seu valor permanece `0` após a chamada para a expressão lambda.  A especificação `mutable` permite que `n` seja modificada na lambda.  
  
 Embora uma expressão lambda possa capturar apenas variáveis que tenham a duração automática de armazenamento, você pode usar variáveis que tenham a duração de armazenamento estático no corpo de uma expressão lambda.  O exemplo a seguir usa a função `generate` e uma expressão lambda para atribuir um valor para cada elemento em um objeto `vector`.  A expressão lambda modifica a variável estática para gerar o valor do próximo elemento.  
  
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
  
 Para obter mais informações, consulte [generate](../Topic/generate.md).  
  
 O exemplo de código a seguir usa a função do exemplo anterior e adiciona um exemplo de uma expressão lambda que usa o algoritmo STL `generate_n`.  Essa expressão lambda atribui um elemento de um objeto `vector` à soma dos dois elementos anteriores.  A palavra\-chave `mutable` é usada de modo que o corpo da expressão lambda possa modificar suas cópias das variáveis externas `x` e `y`, que a expressão lambda captura por valor.  Uma vez que a expressão lambda captura as variáveis originais `x` e `y` por valor, seus valores permanecem `1` depois que a lambda é executada.  
  
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
  
 **Saída:**  
  
  **vetor v após chamada para generate\_n\(\) com lambda: 1 1 2 3 5 8 13 21 34**  
**x: 1 y: 1**  
**vetor v após primeira chamada para fillVector\(\): 1 2 3 4 5 6 7 8 9**  
**vetor v após segunda chamada para fillVector\(\): 10 11 12 13 14 15 16 17 18** Para obter mais informações, consulte [generate\_n](../Topic/generate_n.md).  
  
## Específico da Microsoft  
 As lambdas não têm suporte nas seguintes entidades gerenciadas de CLR \(Common Language Runtime\): `ref class`, `ref struct`, `value class` ou `value struct`.  
  
 Se você está usando um modificador específico da Microsoft como [\_\_declspec](../cpp/declspec.md), é possível inseri\-lo em uma expressão lambda imediatamente após o `parameter-declaration-clause`— por exemplo:  
  
```cpp  
auto Sqr = [](int t) __declspec(code_seg("PagedMem")) -> int { return t*t; };  
  
```  
  
 Para determinar se um modificador tem suporte por lambdas, consulte o artigo sobre isso na seção de documentação dos [Modificadores específicos da Microsoft](../Topic/Microsoft-Specific%20Modifiers.md).  
  
 O Visual Studio oferece suporte à sintaxe e à funcionalidade da expressão lambda padrão de C\+\+11, com as seguintes exceções:  
  
-   Como todas as outras classes, lambdas não obtêm construtores de movimentação e operadores de atribuição de movimentação gerados automaticamente.  Para obter mais informações sobre o suporte a comportamentos de referência rvalue, consulte a seção "Referências de Rvalue" [Suporte a recursos do C\+\+11\/14\/17](../Topic/Support%20For%20C++11-14-17%20Features%20\(Modern%20C++\).md).  
  
-   O opcional *attribute\-specifier\-seq* não é compatível com essa versão.  
  
 O Visual Studio inclui esses recursos além da funcionalidade lambda do padrão C\+\+11:  
  
-   As lambdas sem monitoração de estado que podem ser convertidas em omni para ponteiros de função usam convenções de chamada arbitrárias.  
  
-   Tipos de retorno deduzidos automaticamente para corpos lambda mais complicados que `{ return expression; }`, desde que todos retornem instruções do mesmo tipo.  \(Essa funcionalidade é parte do C\+\+14 padrão proposto.\)  
  
## Consulte também  
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Objetos de função no STL](../standard-library/function-objects-in-the-stl.md)   
 [Chamada de função](../Topic/Function%20Call%20\(C++\).md)   
 [for\_each](../Topic/for_each.md)