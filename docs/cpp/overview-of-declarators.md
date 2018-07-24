---
title: Visão geral dos declaradores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- declarators, about declarators
ms.assetid: 0f2e2312-80bd-4154-8345-718bd9ed2173
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 405ef6da02c15e93e516069c1fedc22f002bdf2c
ms.sourcegitcommit: 7eadb968405bcb92ffa505e3ad8ac73483e59685
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/23/2018
ms.locfileid: "39208556"
---
# <a name="overview-of-declarators"></a>Visão geral dos declaradores
Declaradores são os componentes de uma declaração que especificam nomes de objetos ou funções. Os declaradores também especificam se o objeto nomeado é ou não um objeto, um ponteiro, uma referência ou uma matriz.  Quando os declaradores não especificam o tipo de base, eles modificam as informações de tipo no tipo básico para especificar tipos derivados, como ponteiros, referências e matrizes.  Aplicado a funções, o declarador trabalha com o especificador de tipo para especificar completamente o tipo de retorno de uma função para ser um objeto, ponteiro ou referência. (Especificadores, abordados em [declarações e definições](declarations-and-definitions-cpp.md), transmitem propriedades como o armazenamento e o tipo de classe. Os modificadores, abordados nesta seção e, na [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md), modificam declaradores.) A figura a seguir mostra uma declaração completa de `MyFunction`, e chama os componentes da declaração.  
  
 ![Modificadores, especificadores e declaradores](../cpp/media/vc38qy1.gif "vc38QY1")  
Especificadores, modificadores e declaradores  
  
 **Seção específica da Microsoft**  
  
 A maioria das palavras-chave estendidas da Microsoft podem ser usadas como modificadores para formar tipos derivados; não são especificadores ou declaradores. (Consulte [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md).)  
  
 **Fim da seção específica da Microsoft**  
  
 Os declaradores aparecem na sintaxe da declaração após uma lista opcional de especificadores. Esses especificadores são abordados em [declarações.](declarations-and-definitions-cpp.md) Uma declaração pode conter mais de um declarador, mas cada declarador declara apenas um nome.  
  
 A seguinte declaração de exemplo mostra como os especificadores e os declaradores são combinados para formar uma declaração completa:  
  
```cpp 
const char *pch, ch;  
```  
  
 Na declaração anterior, as palavras-chave **const** e **char** compõem a lista de especificadores. Dois declaradores são listados: `*pch` e `ch`.  Uma declaração que declara várias entidades consiste em um especificador de tipo seguido por uma lista separada por vírgulas de declaradores, encerrada com um ponto-e-vírgula.  
  
 **Declaradores para objetos simples**  
  
 O declarador de um objeto simples, como um inteiro ou um valor double, é simplesmente seu nome, com parênteses opcionais.  
  
 `int i; // declarator is i`  
  
 `int (i); // declarator is (i)`  
  
 **Declaradores para ponteiros, referências e matrizes**  
  
 Os operadores de ponteiro inseridos na frente do nome fazem com que o objeto seja um ponteiro ou uma referência.  O **\*** operador declara o nome como um ponteiro; o **&** operador declara-o como uma referência.  
  
```cpp 
int *i; // declarator is *i  
int **i; // declarator is **i;  
int &i = x; // declaratory is &i  
```  
  
 Acrescentando **const** ou **volátil** dá ao ponteiro essas propriedades especiais.  O uso destes especificadores em um declarador (e não no especificador de tipo) altera as propriedades do ponteiro, não do objeto apontado:  
  
```cpp 
char *const cpc; // const pointer to char   
const char *pcc; // pointer to const char   
const char *const cpcc; // const pointer to const char  
```  
  
 Informações adicionais podem ser localizadas em [ponteiros const e volatile](../cpp/const-and-volatile-pointers.md).  
  
 Um ponteiro para um membro de uma classe ou struct é declarado com o especificador de nome aninhado apropriado:  
  
```cpp 
int X::* pIntMember;   
int ::X::* pIntMember; // the initial :: specifies X is in global scope  
char Outer::Inner::* pIntMember; // pointer to char in a nested class  
```  
  
 Colchetes que incluem uma expressão constante opcional após o nome fazem com que o objeto seja uma matriz.  Os colchetes sucessivos declaram dimensões adicionais na matriz.  
  
```cpp 
int i[5]; // array with five elements of type int numbered from 0 to 4  
int i[]; // array of unknown size  
char *s[4]; // array of pointers to char  
int i[2][2]; // two dimensional array  
```  
  
 **Declaradores para funções**  
  
 Os parênteses que contêm a lista de argumentos são usados depois do nome para declarar uma função.  A seguir declara uma função do tipo de retorno **int** e três argumentos do tipo **int**.  
  
```cpp 
int f(int a, int b, int c);  
```  
  
 Os ponteiros e as referências a funções são declarados acrescentando o operador de ponteiro ou referência ao nome da função como mostrado abaixo.  Os parênteses, normalmente opcionais, são necessários para diferenciar um ponteiro para uma função de uma função que retorna um ponteiro:  
  
```cpp 
int (*pf)(int); // pointer to function returning int  
int *f(int i); // function returning pointer to int  
int (&pf)(int); // reference to function   
```  
  
 Os ponteiros para as funções de membro são distinguidos por especificadores de nomes aninhados:  
  
```cpp 
int (X::* pmf)(); // pointer to member function of X returning int  
int* (X::* pmf)(); // pointer to member function returning pointer to int  
```  
  
 Consulte também [ponteiros para membros](../cpp/pointers-to-members.md).  
  
 **Funções e objetos na mesma declaração**  
  
 As funções e os objetos podem ser declarados na mesma declaração da seguinte maneira:  
  
```cpp 
int i, *j, f(int k);  // int, pointer to int, function returning int  
```  
  
 A sintaxe pode ser confusa em algumas circunstâncias.  A seguinte declaração  
  
```cpp 
int* i, f(int k);  // pointer to int, function returning int (not int*)  
```  
  
 pode se parecer com a declaração de um **int** ponteiro e uma função que retorna `int*`, mas não é.  Isso ocorre porque o \* faz parte do declarador para `i`, que não faz parte do declarador para `f`.  
  
 **Simplificando a sintaxe do declarator com typedef**  
  
 No entanto, é uma técnica melhor, usar um **typedef** ou uma combinação de parênteses e o **typedef** palavra-chave. Considere declarar uma matriz de ponteiros para as funções:  
  
```cpp 
//  Function returning type int that takes one   
//   argument of type char *.  
typedef int (*PIFN)( char * );  
//  Declare an array of 7 pointers to functions   
//   returning int and taking one argument of type   
//   char *.  
PIFN pifnDispatchArray[7];  
```  
  
 A declaração equivalente pode ser escrita sem a **typedef** declaração, mas isso é tão complicado que o potencial para erros excede todos os benefícios:  
  
```cpp 
int ( *pifnDispatchArray[7] )( char * );  
```  
  
 Para obter mais informações sobre typdef, consulte [Aliases e typedefs](aliases-and-typedefs-cpp.md).  
  
 Ponteiros, referências, matrizes de um único tipo de base podem ser combinados em uma única declaração (separados por vírgulas) como  
  
```cpp 
int a, *b, c[5], **d, &e=a;  
```  
  
 **Sintaxe de declarador mais complexa**  
  
- Os declaradores de ponteiro, referência, matriz e função podem ser combinados para especificar esses objetos como matrizes de ponteiros para funções, ponteiros para matrizes, etc.  
  
- A gramática recursiva a seguir descreve a sintaxe do declarator de ponteiro totalmente.  
  
- `declarator` é definido como um dos seguintes:  

  - identifier   
  - nome qualificado   
  - Declarador (-lista de argumentos) [cv-qualfiers] [especificação de exceção]  
  - Declarador de [[expressão constante]]
  - Declarador de operador de ponteiro   
  - (declarador)  

  
- e *operador de ponteiro* é um dos:  
  
  - \* [qualificadores cv]  
  - & [qualificadores cv]:: especificador aninhados de nome \* [qualificadores cv]  

  
 Como um declarador pode conter declaradores, é possível criar os tipos derivados mais complexos, como matrizes de ponteiros, funções que retornam matrizes de ponteiros de função, usando as regras acima.  Para formar cada etapa da construções, comece com o identificador que representa o tipo de dados base e aplique a regra de sintaxe acima com a expressão anterior como `declarator`.  A ordem que você aplica as regras de sintaxe deve ser contrária à forma que a expressão é indicada em inglês.  Se aplicar a *operador de ponteiro* regra de sintaxe em uma expressão de matriz ou função, use parênteses se você quiser que um ponteiro para a matriz ou função, como a última linha na tabela a seguir.  
  
 O exemplo a seguir mostra a construção de “ponteiro para uma matriz de 10 ponteiros para int”.  
  
|Expressão verbal|Declarador|Regra de sintaxe aplicada|  
|-----------------------|----------------|-------------------------|  
||`i`|1|  
|ponteiro(s) para|`*i`|5|  
|matriz de 10|`(*i)[10]`|4|  
|ponteiro para|`*((*i)[10])`|6 e depois 5|  
  
 Quando vários modificadores de ponteiro, referência, matriz ou função são usados, os declaradores podem se tornar bem complicados.  O tópico [Interpretando declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md) descreve como ler a sintaxe de declarador mais complexa.  O tópico é aplicável para C e C++, embora em C++, em qualquer lugar de \* é usado para indicar um ponteiro, um nome qualificado, como MyClass::\* pode ser usada para especificar um ponteiro para um membro de uma classe.