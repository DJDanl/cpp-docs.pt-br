---
title: auto (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
f1_keywords:
- auto_CPP
- auto
helpviewer_keywords:
- auto keyword [C++]
ms.assetid: e9d495d7-601c-4547-b897-998389a311f4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 334006e8ad06bdc174922d57d97d2d0f0335cf34
ms.sourcegitcommit: 4e01d36ffa64ea11bacf589f79d2f1df947e2510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2018
---
# <a name="auto-c"></a>Auto (C++)
Deduz o tipo de uma variável declarada da expressão de inicialização.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
auto declarator initializer;  
```  
  
```  
[](auto param1, auto param2) {};  
```  
  
## <a name="remarks"></a>Comentários  
 O `auto` palavra-chave direciona o compilador para usar a expressão de inicialização de uma variável declarada ou parâmetro de expressão lambda, para deduzir o tipo.  
  
 Recomendamos que você use a palavra-chave `auto` para a maioria das situações, a menos que você realmente deseje uma conversão, pois ela fornece estes benefícios:  
  
-   **Robustez:** se do tipo da expressão for alterado — isso inclui quando um tipo de retorno da função é alterado — simplesmente funciona.  
  
-   **Desempenho:** tem a garantia de que não haja nenhuma conversão.  
  
-   **Uso:** você não precisa se preocupar com dificuldades de ortografia do nome de tipo e erros de digitação.  
  
-   **Eficiência:** a codificação pode ser mais eficiente.  
  
 Casos de conversão nos quais você pode não querer usar `auto`:  
  
-   Quando você desejar um tipo específico e nada mais serve.  
  
-   Tipos de auxiliar de modelo de expressão — por exemplo, `(valarray+valarray)`.  
  
 Para usar a palavra-chave `auto`, use-a em vez de um tipo para declarar uma variável e especifique uma expressão de inicialização. Além disso, você pode alterar a palavra-chave `auto` usando especificadores e declaradores como `const`, `volatile`, ponteiro (`*`), referência (`&`) e a referência de rvalue `(&&`). O compilador avalia a expressão e de inicialização e usa essas informações para deduzir o tipo da variável.  
  
 A expressão de inicialização pode ser uma atribuição (sintaxe do sinal de igual), uma inicialização direta (sintaxe de função estilo), um [operador novo](new-operator-cpp.md) expressão ou a expressão de inicialização pode ser o  *declaração de intervalo* parâmetro em uma [com base em intervalo de instrução (C++)](../cpp/range-based-for-statement-cpp.md) instrução. Para obter mais informações, consulte [inicializadores](../cpp/initializers.md) e os exemplos de código neste documento.  
  
 A palavra-chave `auto` é um espaço reservado para um tipo, mas não é um tipo ela mesma. Portanto, o `auto` palavra-chave não pode ser usado em conversões ou operadores como [sizeof](../cpp/sizeof-operator.md) e [typeid](../windows/typeid-cpp-component-extensions.md).  
  
## <a name="usefulness"></a>Utilidade  
 A palavra-chave `auto` é uma maneira simples de declarar uma variável que tenha um tipo complicado. Por exemplo, você pode usar `auto` para declarar uma variável onde a expressão de inicialização envolve modelos, ponteiros para as funções ou ponteiros para os membros.  
  
 Você também pode usar `auto` para declarar e inicializar uma variável em uma expressão lambda. Você não pode declarar o tipo da variável você mesmo pois o tipo de uma expressão lambda é conhecido apenas pelo compilador. Para obter mais informações, consulte [exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md).  
  
## <a name="trailing-return-types"></a>Rastreamento de tipos de retorno  
 Você pode usar `auto` junto ao especificador de tipo `decltype` para ajudar a escrever bibliotecas do modelo. Use `auto` e `decltype` para declarar uma função de modelo cujo tipo de retorno dependa dos tipos dos argumentos de modelo. Ou, pode usar `auto` e `decltype` para declarar uma função do modelo que envolve uma chamada para outra função e então retorna o que for o tipo de retorno dessa outra função. Para obter mais informações, consulte [decltype](../cpp/decltype-cpp.md).  
  
## <a name="references-and-cv-qualifiers"></a>Referências e qualificadores CV  
 Observe que o uso de `auto` solta referências, qualificadores de constante e qualificadores voláteis. Considere o exemplo a seguir:  
  
```cpp  
// cl.exe /analyze /EHsc /W4  
#include <iostream>  
  
using namespace std;  
  
int main( )  
{  
    int count = 10;  
    int& countRef = count;  
    auto myAuto = countRef;  
  
    countRef = 11;  
    cout << count << " ";  
  
    myAuto = 12;  
    cout << count << endl;  
}  
  
```  
  
 No exemplo anterior, myAuto é um inteiro, não é uma referência de int, portanto, a saída é `11 11`, não `11 12` como seria o caso se o qualificador de referência não tinha sido descartado pelo `auto`.  
  
## <a name="type-deduction-with-braced-initializers-c14"></a>Dedução de tipo com inicializadores entre chaves (C + + 14)  
 O exmample de código a seguir mostra como inicializar uma variável automática usando chaves. Observe a diferença entre B e C e entre A e E.  
  
```cpp  
#include <initializer_list>  
  
int main()  
{  
    // std::initializer_list<int>  
    auto A = { 1, 2 };  
  
    // std::initializer_list<int>  
    auto B = { 3 };  
  
    // int  
    auto C{ 4 };  
  
    // C3535: cannot deduce type for 'auto' from initializer list'  
    auto D = { 5, 6.7 };  
  
    // C3518 in a direct-list-initialization context the type for 'auto'  
    // can only be deduced from a single initializer expression  
    auto E{ 8, 9 };  
  
    return 0;  
}  
```  
  
## <a name="restrictions-and-error-messages"></a>Limitações e mensagens de erro  
 A tabela a seguir lista as limitações no uso da palavra-chave `auto` e a mensagem de erro de diagnóstico correspondente, emitida pelo compilador.  
  
|Número do erro|Descrição|  
|------------------|-----------------|  
|[C3530](../error-messages/compiler-errors-2/compiler-error-c3530.md)|A palavra-chave `auto` não pode ser combinada com qualquer outro especificador de tipo.|  
|[C3531](../error-messages/compiler-errors-2/compiler-error-c3531.md)|Um símbolo que é declarado com a palavra-chave `auto` deve ter um inicializador.|  
|[C3532](../error-messages/compiler-errors-2/compiler-error-c3532.md)|Você usou incorretamente a palavra-chave `auto` para declarar um tipo. Por exemplo, você declarou um tipo de retorno do método ou matriz.|  
|[C3533](../error-messages/compiler-errors-2/compiler-error-c3533.md), [C3539](../error-messages/compiler-errors-2/compiler-error-c3539.md)|Um argumento de modelo ou parâmetro não pode ser declarado com a palavra-chave `auto`.|  
|[C3535](../error-messages/compiler-errors-2/compiler-error-c3535.md)|Um parâmetro de modelo ou método não pode ser declarado com a palavra-chave `auto`.|  
|[C3536](../error-messages/compiler-errors-2/compiler-error-c3536.md)|Um símbolo não pode ser usado antes de ser inicializado. Na prática, isso significa que uma variável não pode ser usada para se inicializar.|  
|[C3537](../error-messages/compiler-errors-2/compiler-error-c3537.md)|Você não converter para um tipo que é declarado com a palavra-chave `auto`.|  
|[C3538](../error-messages/compiler-errors-2/compiler-error-c3538.md)|Todos os símbolos em uma lista de declaradores que são declarados com a palavra-chave `auto` devem ser resolvidos para o mesmo tipo. Para obter mais informações, consulte [declarações e definições](declarations-and-definitions-cpp.md).|  
|[C3540](../error-messages/compiler-errors-2/compiler-error-c3540.md), [C3541](../error-messages/compiler-errors-2/compiler-error-c3541.md)|O [sizeof](../cpp/sizeof-operator.md) e [typeid](../windows/typeid-cpp-component-extensions.md) operadores não podem ser aplicados a um símbolo que é declarado com o `auto` palavra-chave.|  
  
## <a name="examples"></a>Exemplos  
 Estes fragmentos de código ilustram alguns modos de uso da palavra-chave `auto`.  
  
 As declarações a seguir são equivalentes. Na primeira instrução, a variável `j` é declarada como tipo `int`. Na segunda instrução, a variável `k` é deduzida como sendo do tipo `int` pois a expressão de inicialização (0) é um inteiro.  
  
```cpp  
int j = 0;  // Variable j is explicitly type int.  
auto k = 0; // Variable k is implicitly type int because 0 is an integer.  
```  
  
 As seguintes declarações são equivalentes, mas a segunda declaração é mais simples do que a primeira. Um dos motivos mais convincentes para o uso da palavra-chave `auto` é a simplicidade.  
  
```cpp  
map<int,list<string>>::iterator i = m.begin();   
auto i = m.begin();   
```  
  
 O fragmento de código a seguir declara o tipo de variável `iter` e `elem` quando os loops de `for` e de `for` do intervalo são iniciados.  
  
```cpp  
// cl /EHsc /nologo /W4  
#include <deque>  
using namespace std;  
  
int main()  
{  
    deque<double> dqDoubleData(10, 0.1);  
  
    for (auto iter = dqDoubleData.begin(); iter != dqDoubleData.end(); ++iter)  
    { /* ... */ }  
  
    // prefer range-for loops with the following information in mind  
    // (this applies to any range-for with auto, not just deque)  
  
    for (auto elem : dqDoubleData) // COPIES elements, not much better than the previous examples  
    { /* ... */ }  
  
    for (auto& elem : dqDoubleData) // observes and/or modifies elements IN-PLACE  
    { /* ... */ }  
  
    for (const auto& elem : dqDoubleData) // observes elements IN-PLACE  
    { /* ... */ }  
}  
```  
  
 O fragmento de código a seguir usa a declaração do operador `new` e um ponteiro para declarar ponteiros.  
  
```cpp  
double x = 12.34;  
auto *y = new auto(x), **z = new auto(&x);  
```  
  
 O próximo fragmento de código declara vários símbolos em cada instrução de declaração. Observe que todos os símbolos em cada instrução são resolvidos para o mesmo tipo.  
  
```cpp  
auto x = 1, *y = &x, **z = &y; // Resolves to int.  
auto a(2.01), *b (&a);         // Resolves to double.  
auto c = 'a', *d(&c);          // Resolves to char.  
auto m = 1, &n = m;            // Resolves to int.  
```  
  
 Esse fragmento de código usa o operador condicional (`?:`) para declarar a variável `x` como um inteiro com o valor de 200:  
  
```cpp  
int v1 = 100, v2 = 200;  
auto x = v1 > v2 ? v1 : v2;  
```  
  
 O fragmento de código a seguir inicializa a variável `x` para o tipo `int`, variáveis, `y` para uma referência ao tipo `const int`e a variável `fp` para um ponteiro para uma função que retorna tipo `int`.  
  
```cpp  
int f(int x) { return x; }  
int main()  
{  
    auto x = f(0);  
    const auto & y = f(1);  
    int (*p)(int x);  
    p = f;  
    auto fp = p;  
    //...  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [palavra-chave auto](../cpp/auto-keyword.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [/ZC: auto (deduzir tipo variável)](../build/reference/zc-auto-deduce-variable-type.md)   
 [Operador sizeof](../cpp/sizeof-operator.md)   
 [typeid](../windows/typeid-cpp-component-extensions.md)   
 [operador novo](new-operator-cpp.md)   
 [Declarações e definições](declarations-and-definitions-cpp.md)   
 [Exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md)   
 [Inicializadores](../cpp/initializers.md)   
 [decltype](../cpp/decltype-cpp.md)