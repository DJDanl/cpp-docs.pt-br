---
title: "Exemplos de express&#245;es lambda | Microsoft Docs"
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
  - "expressões lambda [C++], exemplos"
ms.assetid: 52506b15-0771-4190-a966-2f302049ca86
caps.latest.revision: 22
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exemplos de express&#245;es lambda
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo mostra como usar expressões lambda em seus programas.  Para obter uma visão geral das expressões lambda, consulte [Expressões lambda](../cpp/lambda-expressions-in-cpp.md).  Para obter mais informações sobre a estrutura de uma expressão lambda, consulte [Sintaxe da expressão lambda](../cpp/lambda-expression-syntax.md).  
  
##  <a name="top"></a> Neste artigo  
 [Declarando expressões lambda](#declaringLambdaExpressions)  
  
 [Chamando expressões lambda](#callingLambdaExpressions)  
  
 [Aninhando expressões lambda](#nestingLambdaExpressions)  
  
 [Funções lambda de ordem superior](#higherOrderLambdaExpressions)  
  
 [Usando uma expressão Lambda em uma função](#methodLambdaExpressions)  
  
 [Usando expressões lambda com modelos](#templateLambdaExpressions)  
  
 [Tratando exceções](#ehLambdaExpressions)  
  
 [Usando expressões Lambda com tipos gerenciados (C + c++ /CLI)](#managedLambdaExpressions)  
  
##  <a name="declaringLambdaExpressions"></a> Declarando expressões lambda  
  
### Exemplo 1  
 Como uma expressão lambda é digitada, é possível atribuí\-la a uma variável `auto` ou a um objeto [function](../standard-library/function-class.md), como mostrado aqui:  
  
### Código  
  
```cpp  
// declaring_lambda_expressions1.cpp  
// compile with: /EHsc /W4  
#include <functional>  
#include <iostream>  
  
int main()  
{  
  
    using namespace std;  
  
    // Assign the lambda expression that adds two numbers to an auto variable.  
    auto f1 = [](int x, int y) { return x + y; };  
  
    cout << f1(2, 3) << endl;  
  
    // Assign the same lambda expression to a function object.  
    function<int(int, int)> f2 = [](int x, int y) { return x + y; };  
  
    cout << f2(3, 4) << endl;  
}  
```  
  
### Saída  
  **5**  
**7**   
### Observações  
 Para obter mais informações, consulte [auto](../cpp/auto-cpp.md), [Classe function](../standard-library/function-class.md), e [Chamada de função](../Topic/Function%20Call%20\(C++\).md).  
  
 Embora as expressões lambda são declaradas com mais frequência no corpo de uma função, você pode declará\-los em qualquer lugar que você pode inicializar uma variável.  
  
### Exemplo 2  
 O compilador do Visual C\+\+ associa uma expressão lambda às suas variáveis capturadas quando a expressão é declarada, e não quando a expressão é chamada.  O exemplo a seguir mostra uma expressão lambda que captura a variável local `i` por valor e a variável local `j` por referência.  Como a expressão lambda é capturada `i` por valor, a reatribuição posterior de `i` no programa não afetará o resultado da expressão.  No entanto, como a expressão lambda captura `j` por referência, a reatribuição de `j` afetará o resultado da expressão.  
  
### Código  
  
```cpp  
// declaring_lambda_expressions2.cpp  
// compile with: /EHsc /W4  
#include <functional>  
#include <iostream>  
  
int main()  
{  
   using namespace std;  
  
   int i = 3;  
   int j = 5;  
  
   // The following lambda expression captures i by value and  
   // j by reference.  
   function<int (void)> f = [i, &j] { return i + j; };  
  
   // Change the values of i and j.  
   i = 22;  
   j = 44;  
  
   // Call f and print its result.  
   cout << f() << endl;  
}  
```  
  
### Saída  
  **47** \[[Neste artigo](#top)\]  
  
##  <a name="callingLambdaExpressions"></a> Chamando expressões lambda  
 Você poderá chamar uma expressão lambda imediatamente, conforme mostrado no próximo trecho de código.  O segundo trecho mostra como passar um lambda como argumento aos algoritmos STL, como `find_if`.  
  
### Exemplo 1  
 Este exemplo declara uma expressão lambda que retorna a soma de dois inteiros e chama a expressão imediatamente com os argumentos `5` e `4`:  
  
### Código  
  
```cpp  
// calling_lambda_expressions1.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main()  
{  
   using namespace std;  
   int n = [] (int x, int y) { return x + y; }(5, 4);  
   cout << n << endl;  
}  
```  
  
### Saída  
  **9**   
### Exemplo 2  
 Este exemplo passa uma expressão lambda como argumento para a função `find_if`.  A expressão lambda retornará `true` se o parâmetro for um número par.  
  
### Código  
  
```cpp  
// calling_lambda_expressions2.cpp  
// compile with: /EHsc /W4  
#include <list>  
#include <algorithm>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
  
    // Create a list of integers with a few initial elements.  
    list<int> numbers;  
    numbers.push_back(13);  
    numbers.push_back(17);  
    numbers.push_back(42);  
    numbers.push_back(46);  
    numbers.push_back(99);  
  
    // Use the find_if function and a lambda expression to find the   
    // first even number in the list.  
    const list<int>::const_iterator result =   
        find_if(numbers.begin(), numbers.end(),[](int n) { return (n % 2) == 0; });  
  
    // Print the result.  
    if (result != numbers.end()) {  
        cout << "The first even number in the list is " << *result << "." << endl;  
    } else {  
        cout << "The list contains no even numbers." << endl;  
    }  
}  
```  
  
### Saída  
  **O primeiro número par na lista é 42.**   
### Observações  
 Para obter mais informações sobre o `find_if` funcionam, consulte [find\_if](../Topic/find_if.md).  Para obter mais informações sobre as funções STL que executam algoritmos comuns, consulte [\<algorithm\>](../standard-library/algorithm.md).  
  
 \[[Neste artigo](#top)\]  
  
##  <a name="nestingLambdaExpressions"></a> Aninhando expressões lambda  
  
### Exemplo  
 É possível aninhar uma expressão lambda dentro de outra, como mostrado neste exemplo.  A expressão lambda interna multiplica seu argumento por 2 e retorna o resultado.  A expressão lambda externa chama a expressão lambda interna com seu argumento e adiciona 3 ao resultado.  
  
### Código  
  
```cpp  
// nesting_lambda_expressions.cpp  
// compile with: /EHsc /W4  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
  
    // The following lambda expression contains a nested lambda  
    // expression.  
    int timestwoplusthree = [](int x) { return [](int y) { return y * 2; }(x) + 3; }(5);  
  
    // Print the result.  
    cout << timestwoplusthree << endl;  
}  
  
```  
  
### Saída  
  **13**   
### Observações  
 Neste exemplo, `[](int y) { return y * 2; }` representa a expressão lambda aninhada.  
  
 \[[Neste artigo](#top)\]  
  
##  <a name="higherOrderLambdaExpressions"></a> Funções lambda de ordem superior  
  
### Exemplo  
 Muitas linguagens de programação oferecem suporte ao conceito de uma *função de ordem superior.* Uma função de ordem superior é uma expressão lambda que usa outra expressão lambda como seu argumento ou retorna uma expressão lambda.  Você pode usar a classe [function](../standard-library/function-class.md) para permitir que uma expressão lambda C\+\+ se comporte como uma função de ordem superior.  O exemplo a seguir mostra uma expressão lambda que retorna um objeto `function` e uma expressão lambda que usa um objeto `function` como seu argumento.  
  
### Código  
  
```cpp  
// higher_order_lambda_expression.cpp  
// compile with: /EHsc /W4  
#include <iostream>  
#include <functional>  
  
int main()  
{  
    using namespace std;  
  
    // The following code declares a lambda expression that returns   
    // another lambda expression that adds two numbers.   
    // The returned lambda expression captures parameter x by value.  
    auto addtwointegers = [](int x) -> function<int(int)> {   
        return [=](int y) { return x + y; };   
    };  
  
    // The following code declares a lambda expression that takes another  
    // lambda expression as its argument.  
    // The lambda expression applies the argument z to the function f  
    // and multiplies by 2.  
    auto higherorder = [](const function<int(int)>& f, int z) {   
        return f(z) * 2;   
    };  
  
    // Call the lambda expression that is bound to higherorder.   
    auto answer = higherorder(addtwointegers(7), 8);  
  
    // Print the result, which is (7+8)*2.  
    cout << answer << endl;  
}  
  
```  
  
### Saída  
  **30** \[[Neste artigo](#top)\]  
  
##  <a name="methodLambdaExpressions"></a> Usando uma expressão Lambda em uma função  
  
### Exemplo  
 Você pode usar expressões lambda no corpo de uma função.  A expressão lambda pode acessar qualquer função ou membro de dados que a função pode acessar.  Você pode capturar explicita ou implicitamente o `this` ponteiro para fornecer acesso a membros de funções e os dados da classe delimitadora.  
  
 Você pode usar o `this` ponteiro explicitamente em uma função, como mostrado aqui:  
  
```cpp  
void ApplyScale(const vector<int>& v) const  
{  
   for_each(v.begin(), v.end(),   
      [this](int n) { cout << n * _scale << endl; });  
}  
```  
  
 Você também pode capturar o ponteiro `this` implicitamente:  
  
```  
void ApplyScale(const vector<int>& v) const  
{  
   for_each(v.begin(), v.end(),   
      [=](int n) { cout << n * _scale << endl; });  
}  
```  
  
 O exemplo a seguir mostra a classe `Scale`, que encapsula um valor da escala.  
  
```cpp  
// function_lambda_expression.cpp  
// compile with: /EHsc /W4  
#include <algorithm>  
#include <iostream>  
#include <vector>  
  
using namespace std;  
  
class Scale  
{  
public:  
    // The constructor.  
    explicit Scale(int scale) : _scale(scale) {}  
  
    // Prints the product of each element in a vector object   
    // and the scale value to the console.  
    void ApplyScale(const vector<int>& v) const  
    {  
        for_each(v.begin(), v.end(), [=](int n) { cout << n * _scale << endl; });  
    }  
  
private:  
    int _scale;  
};  
  
int main()  
{  
    vector<int> values;  
    values.push_back(1);  
    values.push_back(2);  
    values.push_back(3);  
    values.push_back(4);  
  
    // Create a Scale object that scales elements by 3 and apply  
    // it to the vector object. Does not modify the vector.  
    Scale s(3);  
    s.ApplyScale(values);  
}  
  
```  
  
### Saída  
  **3**  
**6**  
**9**  
**12**   
### Observações  
 O `ApplyScale` função usa uma expressão lambda para imprimir o produto do valor da escala e cada elemento em uma `vector` objeto.  A expressão lambda captura implicitamente `this` para que possa acessar o membro `_scale`.  
  
 \[[Neste artigo](#top)\]  
  
##  <a name="templateLambdaExpressions"></a> Usando expressões lambda com modelos  
  
### Exemplo  
 Como as expressões lambda são digitadas, é possível usá\-las com modelos C\+\+.  O exemplo a seguir mostra as funções `negate_all` e `print_all`.  A função `negate_all` aplica o unário `operator-` a cada elemento no objeto `vector`.  A função `print_all` imprime cada elemento no objeto `vector` para o console.  
  
### Código  
  
```cpp  
// template_lambda_expression.cpp  
// compile with: /EHsc  
#include <vector>  
#include <algorithm>  
#include <iostream>  
  
using namespace std;  
  
// Negates each element in the vector object. Assumes signed data type.  
template <typename T>  
void negate_all(vector<T>& v)  
{  
    for_each(v.begin(), v.end(), [](T& n) { n = -n; });  
}  
  
// Prints to the console each element in the vector object.  
template <typename T>  
void print_all(const vector<T>& v)  
{  
    for_each(v.begin(), v.end(), [](const T& n) { cout << n << endl; });  
}  
  
int main()  
{  
    // Create a vector of signed integers with a few elements.  
    vector<int> v;  
    v.push_back(34);  
    v.push_back(-43);  
    v.push_back(56);  
  
    print_all(v);  
    negate_all(v);  
    cout << "After negate_all():" << endl;  
    print_all(v);  
}  
  
```  
  
### Saída  
  **34**  
**\-43**  
**56**  
**Após negate\_all\(\):**  
**\-34**  
**43**  
**\-56**   
### Observações  
 Para obter mais informações sobre modelos C\+\+, consulte [Modelos](../Topic/Templates%20\(C++\).md).  
  
 \[[Neste artigo](#top)\]  
  
##  <a name="ehLambdaExpressions"></a> Tratando exceções  
  
### Exemplo  
 O corpo de uma expressão lambda segue as regras para a manipulação de exceção estruturada \(SEH\) e o tratamento de exceções C\+\+.  Você pode manipular uma exceção gerada no corpo de uma expressão lambda ou adiar o tratamento de exceções para o escopo delimitador.  O exemplo a seguir usa a função `for_each` e uma expressão lambda para preencher um objeto `vector` com os valores de outro.  Usa um bloco `try`\/`catch` para tratar o acesso inválido ao primeiro vetor.  
  
### Código  
  
```cpp  
// eh_lambda_expression.cpp  
// compile with: /EHsc /W4  
#include <vector>  
#include <algorithm>  
#include <iostream>  
using namespace std;  
  
int main()  
{  
    // Create a vector that contains 3 elements.  
    vector<int> elements(3);  
  
    // Create another vector that contains index values.  
    vector<int> indices(3);  
    indices[0] = 0;  
    indices[1] = -1; // This is not a valid subscript. It will trigger an exception.  
    indices[2] = 2;  
  
    // Use the values from the vector of index values to   
    // fill the elements vector. This example uses a   
    // try/catch block to handle invalid access to the   
    // elements vector.  
    try  
    {  
        for_each(indices.begin(), indices.end(), [&](int index) {   
            elements.at(index) = index;   
        });  
    }  
    catch (const out_of_range& e)  
    {  
        cerr << "Caught '" << e.what() << "'." << endl;  
    };  
}  
```  
  
### Saída  
  **Caught 'invalid vector\<T\> subscript'.**   
### Observações  
 Para obter mais informações sobre o tratamento de exceções, consulte [Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md).  
  
 \[[Neste artigo](#top)\]  
  
##  <a name="managedLambdaExpressions"></a> Usando expressões Lambda com tipos gerenciados \(C \+ c\+\+ \/CLI\)  
  
### Exemplo  
 A cláusula de captura de uma expressão lambda não pode conter uma variável que tenha um tipo gerenciado.  No entanto, você pode passar um argumento que tenha um tipo gerenciado para uma lista de parâmetros de uma expressão lambda.  O exemplo a seguir contém uma expressão lambda que captura a variável local não gerenciada `ch` por valor e usa um objeto <xref:System.String?displayProperty=fullName> como seu parâmetro.  
  
### Código  
  
```cpp  
// managed_lambda_expression.cpp  
// compile with: /clr  
using namespace System;  
  
int main()  
{  
    char ch = '!'; // a local unmanaged variable  
  
    // The following lambda expression captures local variables  
    // by value and takes a managed String object as its parameter.  
    [=](String ^s) {   
        Console::WriteLine(s + Convert::ToChar(ch));   
    }("Hello");  
}  
  
```  
  
### Saída  
  **Olá\!**   
### Observações  
 Você também pode usar expressões lambda com a biblioteca STL\/CLR.  Para obter mais informações, consulte [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md).  
  
> [!IMPORTANT]
>  As lambdas não têm suporte nestas entidades gerenciadas de CLR \(Common Language Runtime\): `ref class`, `ref struct`, `value class` e `value struct`.  
  
 \[[Neste artigo](#top)\]  
  
## Consulte também  
 [Expressões lambda](../cpp/lambda-expressions-in-cpp.md)   
 [Sintaxe da expressão lambda](../cpp/lambda-expression-syntax.md)   
 [auto](../cpp/auto-cpp.md)   
 [Classe function](../standard-library/function-class.md)   
 [find\_if](../Topic/find_if.md)   
 [\<algorithm\>](../standard-library/algorithm.md)   
 [Chamada de função](../Topic/Function%20Call%20\(C++\).md)   
 [Modelos](../Topic/Templates%20\(C++\).md)   
 [Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)   
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)