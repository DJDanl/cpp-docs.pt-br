---
title: "autom&#225;tico (C++) | Microsoft Docs"
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
ms.assetid: e9d495d7-601c-4547-b897-998389a311f4
caps.latest.revision: 18
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# autom&#225;tico (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Deduz o tipo de uma variável declarada da expressão de inicialização.  
  
## Sintaxe  
  
```  
auto declarator initializer;  
```  
  
```  
[](auto param1, auto param2) {};  
```  
  
## Comentários  
 O `auto` palavra\-chave direciona o compilador para usar a expressão de inicialização de uma variável declarada ou parâmetro de expressão lambda, para deduzir o tipo.  
  
 Recomendamos que você use a palavra\-chave `auto` para a maioria das situações, a menos que você realmente deseje uma conversão, pois ela fornece estes benefícios:  
  
-   **Vigor:** se o tipo da expressão for modificado, e isso inclui a alteração de um tipo de retorno da função, ele apenas funciona.  
  
-   **Desempenho:** você tem a garantia de que não haverá conversão.  
  
-   **Usabilidade:** você não precisa se preocupar com dificuldades e erros de ortografia do nome do tipo.  
  
-   **Eficiência:** a codificação pode ser mais eficiente.  
  
 Casos de conversão nos quais você pode não querer usar `auto`:  
  
-   Quando você desejar um tipo específico e nada mais serve.  
  
-   O auxiliar do modelo de expressão do tipo, como por exemplo, `(valarray+valarray)` e listas do inicializador, ainda que raramente você escolheria a gravação de `auto x = { 1 };` e esperaria realmente obter `int`.  
  
 Para usar a palavra\-chave `auto`, use\-a em vez de um tipo para declarar uma variável e especifique uma expressão de inicialização.  Além disso, você pode alterar a palavra\-chave `auto` usando especificadores e declaradores como `const`, `volatile`, ponteiro \(`*`\), referência \(`&`\) e a referência de rvalue `(&&`\).  O compilador avalia a expressão e de inicialização e usa essas informações para deduzir o tipo da variável.  
  
 A expressão de inicialização pode ser uma atribuição \(sintaxe do sinal de igual\), uma inicialização direta \(sintaxe de estilo de função\), um [novo operador](../Topic/operator%20new%20\(%3Cnew%3E\).md) expressão ou a expressão de inicialização pode ser o *declaração de intervalo* parâmetro em uma [Instrução for com base em intervalo \(C\+\+\)](../Topic/Range-based%20for%20Statement%20\(C++\).md) instrução.  Para obter mais informações, consulte [Inicializadores](../cpp/initializers.md) e exemplos de código neste documento.  
  
 A palavra\-chave `auto` é um espaço reservado para um tipo, mas não é um tipo ela mesma.  Portanto, o `auto` palavra\-chave não pode ser usado nas conversões ou operadores como [sizeof](../cpp/sizeof-operator.md) e [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md).  
  
## Utilidade  
 A palavra\-chave `auto` é uma maneira simples de declarar uma variável que tenha um tipo complicado.  Por exemplo, você pode usar `auto` para declarar uma variável onde a expressão de inicialização envolve modelos, ponteiros para as funções ou ponteiros para os membros.  
  
 Você também pode usar `auto` para declarar e inicializar uma variável em uma expressão lambda.  Você não pode declarar o tipo da variável você mesmo pois o tipo de uma expressão lambda é conhecido apenas pelo compilador.  Para obter mais informações, consulte [Exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md).  
  
## Rastreamento de tipos de retorno  
 Você pode usar `auto` junto ao especificador de tipo `decltype` para ajudar a escrever bibliotecas do modelo.  Use `auto` e `decltype` para declarar uma função de modelo cujo tipo de retorno dependa dos tipos dos argumentos de modelo.  Ou, pode usar `auto` e `decltype` para declarar uma função do modelo que envolve uma chamada para outra função e então retorna o que for o tipo de retorno dessa outra função.  Para obter mais informações, consulte [decltype](../cpp/decltype-cpp.md).  
  
## Referências e qualificadores CV  
 Observe que o uso de `auto` solta referências, qualificadores de constante e qualificadores voláteis.  Considere o exemplo a seguir:  
  
```cpp  
// cl.exe /analyze /EHsc /W4  
#include <iostream>  
  
using namespace std;  
  
int main( )  
{  
    int count = 10;  
    int& countRef = count;  
    auto myAuto = countRef;  
  
    countRef = 11;  
    cout << count << " ";  
  
    myAuto = 12;  
    cout << count << endl;  
}  
  
```  
  
 Você pode acreditar que myAuto é uma referência int, mas não é.  Ele simplesmente é um int, portanto o resultado é `11 11` e não `11 12`, como seria o caso se a referência não tivesse sido solta por `auto`.  
  
## Limitações e mensagens de erro  
 A tabela a seguir lista as limitações no uso da palavra\-chave `auto` e a mensagem de erro de diagnóstico correspondente, emitida pelo compilador.  
  
|Número do erro|Descrição|  
|--------------------|---------------|  
|[C3530](../Topic/Compiler%20Error%20C3530.md)|A palavra\-chave `auto` não pode ser combinada com qualquer outro especificador de tipo.|  
|[C3531](../error-messages/compiler-errors-2/compiler-error-c3531.md)|Um símbolo que é declarado com a palavra\-chave `auto` deve ter um inicializador.|  
|[C3532](../error-messages/compiler-errors-2/compiler-error-c3532.md)|Você usou incorretamente a palavra\-chave `auto` para declarar um tipo.  Por exemplo, você declarou um tipo de retorno do método ou matriz.|  
|[C3533](../Topic/Compiler%20Error%20C3533.md), [C3539](../Topic/Compiler%20Error%20C3539.md)|Um argumento de modelo ou parâmetro não pode ser declarado com a palavra\-chave `auto`.|  
|[C3534](../Topic/Compiler%20Error%20C3534.md)|Um símbolo que é declarado com a palavra\-chave `auto` em uma expressão `new` deve ter um inicializador.  Para obter mais informações, consulte [operator new](../Topic/operator%20new%20\(%3Cnew%3E\).md).|  
|[C3535](../error-messages/compiler-errors-2/compiler-error-c3535.md)|Um parâmetro de modelo ou método não pode ser declarado com a palavra\-chave `auto`.|  
|[C3536](../error-messages/compiler-errors-2/compiler-error-c3536.md)|Um símbolo não pode ser usado antes de ser inicializado.  Na prática, isso significa que uma variável não pode ser usada para se inicializar.|  
|[C3537](../error-messages/compiler-errors-2/compiler-error-c3537.md)|Você não converter para um tipo que é declarado com a palavra\-chave `auto`.|  
|[C3538](../error-messages/compiler-errors-2/compiler-error-c3538.md)|Todos os símbolos em uma lista de declaradores que são declarados com a palavra\-chave `auto` devem ser resolvidos para o mesmo tipo.  Para obter mais informações, consulte [Declarações](../misc/declarations.md).|  
|[C3540](../error-messages/compiler-errors-2/compiler-error-c3540.md), [C3541](../error-messages/compiler-errors-2/compiler-error-c3541.md)|O [sizeof](../cpp/sizeof-operator.md) e [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md) operadores não podem ser aplicados a um símbolo que é declarado com o `auto` palavra\-chave.|  
  
## Exemplos  
 Estes fragmentos de código ilustram alguns modos de uso da palavra\-chave `auto`.  
  
 As declarações a seguir são equivalentes.  Na primeira instrução, a variável `j` é declarada como tipo `int`.  Na segunda instrução, a variável `k` é deduzida como sendo do tipo `int` pois a expressão de inicialização \(0\) é um inteiro.  
  
```cpp  
  
int j = 0;  // Variable j is explicitly type int.  
auto k = 0; // Variable k is implicitly type int because 0 is an integer.  
```  
  
 As seguintes declarações são equivalentes, mas a segunda declaração é mais simples do que a primeira.  Um dos motivos mais convincentes para o uso da palavra\-chave `auto` é a simplicidade.  
  
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
  
 O próximo fragmento de código declara vários símbolos em cada instrução de declaração.  Observe que todos os símbolos em cada instrução são resolvidos para o mesmo tipo.  
  
```cpp  
  
auto x = 1, *y = &x, **z = &y; // Resolves to int.  
auto a(2.01), *b (&a);         // Resolves to double.  
auto c = 'a', *d(&c);          // Resolves to char.  
auto m = 1, &n = m;            // Resolves to int.  
```  
  
 Esse fragmento de código usa o operador condicional \(`?:`\) para declarar a variável `x` como um inteiro com o valor de 200:  
  
```cpp  
  
int v1 = 100, v2 = 200;  
auto x = v1 > v2 ? v1 : v2;  
```  
  
 O fragmento de código a seguir inicializa a variável `x` para o tipo `int`, variável `y` para uma referência para um tipo `const` `int`, e variável `fp` para um ponteiro para uma função que retorna o tipo `int`.  
  
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
  
## Consulte também  
 [Palavra\-chave auto](../cpp/auto-keyword.md)   
 [\(NOTINBUILD\)Storage\-Class Specifiers](http://msdn.microsoft.com/pt-br/10b3d22d-cb40-450b-994b-08cf9a211b6c)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [\/Zc:auto \(deduzir tipo variável\)](../build/reference/zc-auto-deduce-variable-type.md)   
 [Operador sizeof](../cpp/sizeof-operator.md)   
 [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md)   
 [operator new](../Topic/operator%20new%20\(%3Cnew%3E\).md)   
 [Declarações](../misc/declarations.md)   
 [Exemplos de expressões lambda](../cpp/examples-of-lambda-expressions.md)   
 [Inicializadores](../cpp/initializers.md)   
 [decltype](../cpp/decltype-cpp.md)