---
title: "Visão geral dos declaradores | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords: declarators, about declarators
ms.assetid: 0f2e2312-80bd-4154-8345-718bd9ed2173
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d64e375375deac828689f37475d9bfe04b08925b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="overview-of-declarators"></a>Visão geral dos declaradores
Declaradores são os componentes de uma declaração que especificam nomes de objetos ou funções. Os declaradores também especificam se o objeto nomeado é ou não um objeto, um ponteiro, uma referência ou uma matriz.  Quando os declaradores não especificam o tipo de base, eles modificam as informações de tipo no tipo básico para especificar tipos derivados, como ponteiros, referências e matrizes.  Aplicado a funções, o declarador trabalha com o especificador de tipo para especificar completamente o tipo de retorno de uma função para ser um objeto, ponteiro ou referência. (Especificadores, discutidos em [declarações e definições](declarations-and-definitions-cpp.md), transmitir propriedades como classe de tipo e armazenamento. Modificadores, discutidas nesta seção e em [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md), modificar declaradores.) A figura a seguir mostra uma declaração completa de `MyFunction`, e chama os componentes da declaração.  
  
 ![Declaradores, modificadores e especificadores](../cpp/media/vc38qy1.gif "vc38QY1")  
Especificadores, modificadores e declaradores  
  
 **Seção específica da Microsoft**  
  
 A maioria das palavras-chave estendidas da Microsoft podem ser usadas como modificadores para formar tipos derivados; não são especificadores ou declaradores. (Consulte [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md).)  
  
 **Fim da seção específica da Microsoft**  
  
 Os declaradores aparecem na sintaxe da declaração após uma lista opcional de especificadores. Esses especificadores são discutidos em [declarações.](declarations-and-definitions-cpp.md) Uma declaração pode conter mais de um declarador, mas cada declarador declara apenas um nome.  
  
 A seguinte declaração de exemplo mostra como os especificadores e os declaradores são combinados para formar uma declaração completa:  
  
```  
const char *pch, ch;  
```  
  
 Na declaração anterior, as palavras-chave **const** e `char` formam a lista de especificadores. Dois declaradores são listados: `*pch` e `ch`.  Uma declaração que declara várias entidades consiste em um especificador de tipo seguido por uma lista separada por vírgulas de declaradores, encerrada com um ponto-e-vírgula.  
  
 **Declaradores para objetos simples**  
  
 O declarador de um objeto simples, como um inteiro ou um valor double, é simplesmente seu nome, com parênteses opcionais.  
  
 `int i; // declarator is i`  
  
 `int (i); // declarator is (i)`  
  
 **Declaradores de ponteiros, referências e matrizes**  
  
 Os operadores de ponteiro inseridos na frente do nome fazem com que o objeto seja um ponteiro ou uma referência.  O  **\***  operador declara o nome como um ponteiro; o  **&**  operador declara como referência.  
  
```  
int *i; // declarator is *i  
int **i; // declarator is **i;  
int &i = x; // declaratory is &i  
```  
  
 Anexar `const` ou `volatile` dá ao ponteiro essas propriedades especiais.  O uso destes especificadores em um declarador (e não no especificador de tipo) altera as propriedades do ponteiro, não do objeto apontado:  
  
```  
char *const cpc; // const pointer to char   
const char *pcc; // pointer to const char   
const char *const cpcc; // const pointer to const char  
```  
  
 Informações adicionais podem ser encontradas no [ponteiros const e volatile](../cpp/const-and-volatile-pointers.md).  
  
 Um ponteiro para um membro de uma classe ou struct é declarado com o especificador de nome aninhado apropriado:  
  
```  
int X::* pIntMember;   
int ::X::* pIntMember; // the initial :: specifies X is in global scope  
char Outer::Inner::* pIntMember; // pointer to char in a nested class  
```  
  
 Colchetes que incluem uma expressão constante opcional após o nome fazem com que o objeto seja uma matriz.  Os colchetes sucessivos declaram dimensões adicionais na matriz.  
  
```  
int i[5]; // array with five elements of type int numbered from 0 to 4  
int i[]; // array of unknown size  
char *s[4]; // array of pointers to char  
int i[2][2]; // two dimensional array  
```  
  
 **Declaradores para funções**  
  
 Os parênteses que contêm a lista de argumentos são usados depois do nome para declarar uma função.  O exemplo a seguir declara uma função do tipo de retorno `int` e três argumentos de tipo `int`.  
  
```  
int f(int a, int b, int c);  
```  
  
 Os ponteiros e as referências a funções são declarados acrescentando o operador de ponteiro ou referência ao nome da função como mostrado abaixo.  Os parênteses, normalmente opcionais, são necessários para diferenciar um ponteiro para uma função de uma função que retorna um ponteiro:  
  
```  
int (*pf)(int); // pointer to function returning int  
int *f(int i); // function returning pointer to int  
int (&pf)(int); // reference to function   
```  
  
 Os ponteiros para as funções de membro são distinguidos por especificadores de nomes aninhados:  
  
```  
int (X::* pmf)(); // pointer to member function of X returning int  
int* (X::* pmf)(); // pointer to member function returning pointer to int  
```  
  
 Consulte também [ponteiros para membros](../cpp/pointers-to-members.md).  
  
 **Funções e objetos na mesma declaração**  
  
 As funções e os objetos podem ser declarados na mesma declaração da seguinte maneira:  
  
```  
int i, *j, f(int k);  // int, pointer to int, function returning int  
```  
  
 A sintaxe pode ser confusa em algumas circunstâncias.  A seguinte declaração  
  
```  
int* i, f(int k);  // pointer to int, function returning int (not int*)  
```  
  
 pode se parecer com a declaração de um ponteiro `int` e uma função que retorna `int*`, mas não é.  Isso é porque * faz parte do declarador para `i`, e não faz parte do declarador para `f`.  
  
 **Simplificando a sintaxe de declarador com typedef**  
  
 Uma técnica melhor, porém, é usar `typedef` ou uma combinação de parênteses e da palavra-chave `typedef`. Considere declarar uma matriz de ponteiros para as funções:  
  
```  
//  Function returning type int that takes one   
//   argument of type char *.  
typedef int (*PIFN)( char * );  
//  Declare an array of 7 pointers to functions   
//   returning int and taking one argument of type   
//   char *.  
PIFN pifnDispatchArray[7];  
```  
  
 A declaração equivalente pode ser escrita sem a declaração `typedef`, mas isso é tão complicado que o potencial para erros excede todos os benefícios:  
  
```  
int ( *pifnDispatchArray[7] )( char * );  
```  
  
 Para obter mais informações sobre o typedef, consulte [Aliases e typedefs](aliases-and-typedefs-cpp.md).  
  
 Ponteiros, referências, matrizes de um único tipo de base podem ser combinados em uma única declaração (separados por vírgulas) como  
  
```  
int a, *b, c[5], **d, &e=a;  
```  
  
 **Sintaxe de declarador mais complexo**  
  
-   Os declaradores de ponteiro, referência, matriz e função podem ser combinados para especificar esses objetos como matrizes de ponteiros para funções, ponteiros para matrizes, etc.  
  
-   A gramática recursiva a seguir descreve a sintaxe do declarator de ponteiro totalmente.  
  
-   `declarator` é definido como um dos seguintes:  
  
```  
1. identifier   
2. qualified-name   
3. declarator ( argument-list ) [cv-qualfiers] [exception-spec]  
4. declarator [ [ constant-expression ] ]   
  
5. pointer-operatordeclarator   
6. ( declarator )  
```  
  
-   e *operador ponteiro* é um de:  
  
```  
  
      * [cv-qualifiers]  
& [cv-qualifiers]  
::nested-name-specifier * [cv-qualfiers]  
```  
  
 Como um declarador pode conter declaradores, é possível criar os tipos derivados mais complexos, como matrizes de ponteiros, funções que retornam matrizes de ponteiros de função, usando as regras acima.  Para formar cada etapa da construções, comece com o identificador que representa o tipo de dados base e aplique a regra de sintaxe acima com a expressão anterior como `declarator`.  A ordem que você aplica as regras de sintaxe deve ser contrária à forma que a expressão é indicada em inglês.  Se aplicar a *operador ponteiro* regras de sintaxe para uma expressão de matriz ou função, use parênteses, se você quiser que um ponteiro para a matriz ou uma função, como a última linha na tabela a seguir.  
  
 O exemplo a seguir mostra a construção de “ponteiro para uma matriz de 10 ponteiros para int”.  
  
|Expressão verbal|Declarador|Regra de sintaxe aplicada|  
|-----------------------|----------------|-------------------------|  
||`i`|1|  
|ponteiro(s) para|`*i`|5|  
|matriz de 10|`(*i)[10]`|4|  
|ponteiro para|`*((*i)[10])`|6 e depois 5|  
  
 Quando vários modificadores de ponteiro, referência, matriz ou função são usados, os declaradores podem se tornar bem complicados.  O tópico [Interpretando declaradores complexos mais](../c-language/interpreting-more-complex-declarators.md) descreve como ler a sintaxe de declarador mais complexa.  O tópico é aplicável para C e C++, embora em C++, em qualquer lugar a * é usado para indicar um ponteiro, um nome qualificado como MyClass::\* podem ser usados para especificar um ponteiro para um membro de uma classe.