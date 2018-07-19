---
title: automático (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
f1_keywords:
- auto_CPP
- auto
helpviewer_keywords:
- auto keyword [C++]
ms.assetid: e9d495d7-601c-4547-b897-998389a311f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e33faac0bf222a94b21878eb287e696ae8c7de47
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939852"
---
# <a name="auto-c"></a>automático (C++)
Deduz o tipo de uma variável declarada da expressão de inicialização.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
auto declarator initializer;  
```  
  
```  
[](auto param1, auto param2) {};  
```  
  
## <a name="remarks"></a>Comentários  
 O **automática** palavra-chave instrui o compilador a usar a expressão de inicialização de uma variável declarada, ou o parâmetro de expressão lambda, para deduzir o tipo.  
  
 É recomendável que você use o **automática** palavra-chave para a maioria das situações — a menos que você realmente deseje uma conversão — porque ele oferece estes benefícios:  
  
-   **Robustez:** se o tipo da expressão for alterado — isso inclui quando um tipo de retorno da função é alterado — ele apenas funciona.  
  
-   **Desempenho:** tem a garantia de que não haja nenhuma conversão.  
  
-   **Facilidade de uso:** você não precisa se preocupar com dificuldades de ortografia do nome de tipo e erros de digitação.  
  
-   **Eficiência:** a codificação pode ser mais eficiente.  
  
 Casos de conversão em que você não poderá usar **automática**:  
  
-   Quando você desejar um tipo específico e nada mais serve.  
  
-   Tipos de auxiliar de modelo de expressão — por exemplo, `(valarray+valarray)`.  
  
 Para usar o **automática** palavra-chave, usá-lo em vez de um tipo para declarar uma variável e especifique uma expressão de inicialização. Além disso, você pode modificar os **automática** palavra-chave usando especificadores e declaradores como **const**, **volátil**, ponteiro (`*`), referência (`&`) e referência de rvalue (`&&`). O compilador avalia a expressão e de inicialização e usa essas informações para deduzir o tipo da variável.  
  
 A expressão de inicialização pode ser uma atribuição (sintaxe de sinal de igual), uma inicialização direta (sintaxe de estilo de função), uma [operador new](new-operator-cpp.md) expressão ou a expressão de inicialização pode ser o  *para range-declaration* parâmetro em uma [de instrução (C++) baseado em intervalo](../cpp/range-based-for-statement-cpp.md) instrução. Para obter mais informações, consulte [inicializadores](../cpp/initializers.md) e exemplos de código neste documento.  
  
 O **automática** palavra-chave é um espaço reservado para um tipo, mas ele não é um tipo. Portanto, o **automática** palavra-chave não pode ser usado nas conversões ou operadores, como [sizeof](../cpp/sizeof-operator.md) e [typeid](../windows/typeid-cpp-component-extensions.md).  
  
## <a name="usefulness"></a>Utilidade  
 O **automática** palavra-chave é uma maneira simples de declarar uma variável que tenha um tipo complicado. Por exemplo, você pode usar **automática** para declarar uma variável em que a expressão de inicialização envolve modelos, ponteiros para funções ou ponteiros para membros.  
  
 Você também pode usar **automática** declarar e inicializar uma variável para uma expressão lambda. Você não pode declarar o tipo da variável você mesmo pois o tipo de uma expressão lambda é conhecido apenas pelo compilador. Para obter mais informações, consulte [exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md).  
  
## <a name="trailing-return-types"></a>Rastreamento de tipos de retorno  
 Você pode usar **automática**, juntamente com o **decltype** especificador, para ajudar a escrever bibliotecas do modelo de tipo. Use **automática** e **decltype** para declarar uma função de modelo cujo retorno tipo depende dos tipos de seus argumentos de modelo. Ou, use **automática** e **decltype** para declarar uma função de modelo que encapsula uma chamada para outra função e, em seguida, retorna a tudo o que é o tipo de retorno dessa outra função. Para obter mais informações, consulte [decltype](../cpp/decltype-cpp.md).  
  
## <a name="references-and-cv-qualifiers"></a>Referências e qualificadores CV  
 Observe que o uso **automática** remove referências, qualificadores de constante e qualificadores voláteis. Considere o exemplo a seguir:  
  
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
  
 No exemplo anterior, myAuto é um int, não uma referência int, portanto, a saída é `11 11`, e não `11 12` como seria o caso se o qualificador de referência não tivesse sido solta **automática**.  
  
## <a name="type-deduction-with-braced-initializers-c14"></a>Dedução de tipo com inicializadores entre chaves (c++14)  
 O exmample de código a seguir mostra como inicializar uma variável automática usando chaves. Observe a diferença entre B e C e entre um e E.  
  
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
 A tabela a seguir lista as restrições no uso do **automática** palavra-chave e a mensagem de erro de diagnóstico correspondente que o compilador emite.  
  
|Número do erro|Descrição|  
|------------------|-----------------|  
|[C3530](../error-messages/compiler-errors-2/compiler-error-c3530.md)|O **automática** palavra-chave não pode ser combinado com qualquer outro especificador de tipo.|  
|[C3531](../error-messages/compiler-errors-2/compiler-error-c3531.md)|Um símbolo que é declarado com o **automática** palavra-chave deve ter um inicializador.|  
|[C3532](../error-messages/compiler-errors-2/compiler-error-c3532.md)|Você usou incorretamente a **automática** palavra-chave para declarar um tipo. Por exemplo, você declarou um tipo de retorno do método ou matriz.|  
|[C3533](../error-messages/compiler-errors-2/compiler-error-c3533.md), [C3539](../error-messages/compiler-errors-2/compiler-error-c3539.md)|Um argumento de modelo ou parâmetro não pode ser declarado com o **automática** palavra-chave.|  
|[C3535](../error-messages/compiler-errors-2/compiler-error-c3535.md)|Um parâmetro de modelo ou método não pode ser declarado com o **automática** palavra-chave.|  
|[C3536](../error-messages/compiler-errors-2/compiler-error-c3536.md)|Um símbolo não pode ser usado antes de ser inicializado. Na prática, isso significa que uma variável não pode ser usada para se inicializar.|  
|[C3537](../error-messages/compiler-errors-2/compiler-error-c3537.md)|Você não pode ser convertido em um tipo que é declarado com o **automática** palavra-chave.|  
|[C3538](../error-messages/compiler-errors-2/compiler-error-c3538.md)|Todos os símbolos em uma lista de declaradores que é declarado com o **automática** palavra-chave deve ser resolvido para o mesmo tipo. Para obter mais informações, consulte [declarações e definições](declarations-and-definitions-cpp.md).|  
|[C3540](../error-messages/compiler-errors-2/compiler-error-c3540.md), [C3541](../error-messages/compiler-errors-2/compiler-error-c3541.md)|O [sizeof](../cpp/sizeof-operator.md) e [typeid](../windows/typeid-cpp-component-extensions.md) operadores não podem ser aplicados a um símbolo que é declarado com o **automático** palavra-chave.|  
  
## <a name="examples"></a>Exemplos  
 Esses fragmentos de código ilustram algumas das maneiras em que o **automática** palavra-chave pode ser usado.  
  
 As declarações a seguir são equivalentes. Na primeira instrução, variável `j` é declarado como tipo **int**. Na segunda instrução, variável `k` é deduzida como sendo do tipo **int** porque a expressão de inicialização (0) é um número inteiro.  
  
```cpp  
int j = 0;  // Variable j is explicitly type int.  
auto k = 0; // Variable k is implicitly type int because 0 is an integer.  
```  
  
 As seguintes declarações são equivalentes, mas a segunda declaração é mais simples do que a primeira. Um dos motivos mais convincentes para usar o **automática** palavra-chave é a simplicidade.  
  
```cpp  
map<int,list<string>>::iterator i = m.begin();   
auto i = m.begin();   
```  
  
 O fragmento de código a seguir declara o tipo de variáveis `iter` e `elem` quando o **para** e o intervalo **para** faz um loop iniciar.  
  
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
  
 O fragmento de código a seguir usa o **novo** declaração do operador e o ponteiro para declarar ponteiros.  
  
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
  
 O fragmento de código a seguir inicializa a variável `x` para o tipo **int**, a variável `y` para uma referência ao tipo **const int**e a variável `fp` em um ponteiro para uma função que retorna o tipo **int**.  
  
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
 [TypeId](../windows/typeid-cpp-component-extensions.md)   
 [operador new](new-operator-cpp.md)   
 [Declarações e definições](declarations-and-definitions-cpp.md)   
 [Exemplos de expressões Lambda](../cpp/examples-of-lambda-expressions.md)   
 [Inicializadores](../cpp/initializers.md)   
 [decltype](../cpp/decltype-cpp.md)