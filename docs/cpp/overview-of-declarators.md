---
title: "Vis&#227;o geral dos declaradores | Microsoft Docs"
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
  - "declaradores, sobre declaradores"
ms.assetid: 0f2e2312-80bd-4154-8345-718bd9ed2173
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral dos declaradores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Declaradores são os componentes de uma declaração que especificam nomes de objetos ou funções. Declaradores também especificam se o objeto nomeado é um objeto, ponteiro, referência ou uma matriz.  Embora declaradores não especificar o tipo base, eles modificam as informações de tipo no tipo básico para especificar tipos derivados, como ponteiros, referências e matrizes.  Aplicado a funções, o declarador trabalha com o especificador de tipo para especificar o tipo de retorno de uma função para ser um objeto, ponteiro ou referência completamente. (Especificadores, abordados em [Declarações](../misc/declarations.md), transmitem propriedades como o armazenamento e o tipo de classe. Modificadores, abordados nesta seção e na [modificadores específicos da Microsoft](../Topic/Microsoft-Specific%20Modifiers.md), modificam declaradores.) A figura a seguir mostra uma declaração completa de `MyFunction`, e chama os componentes da declaração.  
  
 ![Declaradores, modificadores e especificadores](../cpp/media/vc38qy1.png "vc38QY1")  
Especificadores, modificadores e declaradores  
  
 **Específico da Microsoft**  
  
 Derivado de Microsoft a maioria das palavras-chave estendidas podem ser usadas como modificadores para formar tipos; eles não são especificadores ou declaradores. (Consulte [Modificadores de Microsoft-Specific](../Topic/Microsoft-Specific%20Modifiers.md).)  
  
 **FIM de específico da Microsoft**  
  
 Declaradores aparecem na sintaxe da declaração após uma lista opcional de especificadores. Esses especificadores são abordados em [declarações.](../misc/declarations.md) Uma declaração pode conter mais de um declarador, mas cada declarador declara apenas um nome.  
  
 A declaração de exemplo a seguir mostra como os especificadores e declaradores são combinados para formar uma declaração completa:  
  
```  
const char *pch, ch;  
```  
  
 Na declaração anterior, as palavras-chave **const** e `char` formam a lista de especificadores. Dois declaradores são listados: `*pch` e `ch`.  Uma declaração que declara várias entidades consiste em um especificador de tipo seguido por uma lista separada por vírgulas de declaradores, encerrada com um ponto e vírgula.  
  
 **Declaradores para objetos simples**  
  
 O declarador de um objeto simples, como um int ou double é simplesmente seu nome, com parênteses opcionais.  
  
 `int i; // declarator is i`  
  
 `int (i); // declarator is (i)`  
  
 **Declaradores para ponteiros, referências e matrizes**  
  
 Operadores de ponteiro inseridos na frente do nome fazem com que o objeto ser um ponteiro ou referência.  O **\*** operador declara o nome como um ponteiro; o **&** operador declara-o como uma referência.  
  
```  
int *i; // declarator is *i  
int **i; // declarator is **i;  
int &i = x; // declaratory is &i  
```  
  
 Anexar `const` ou `volatile` dá ao ponteiro essas propriedades especiais.  O uso destes especificadores em um declarador (e não no especificador de tipo) modifica as propriedades do ponteiro, não o objeto apontado:  
  
```  
char *const cpc; // const pointer to char   
const char *pcc; // pointer to const char   
const char *const cpcc; // const pointer to const char  
```  
  
 Informações adicionais podem ser encontradas no [ponteiros const e volatile](../Topic/const%20and%20volatile%20Pointers.md).  
  
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
  
 Parênteses que contém a lista de argumentos são usados depois do nome para declarar uma função.  O exemplo a seguir declara uma função do tipo de retorno `int` e três argumentos de tipo `int`.  
  
```  
int f(int a, int b, int c);  
```  
  
 Para obter informações sobre listas de argumentos, consulte [declarações de função](http://msdn.microsoft.com/pt-br/3f9b4e14-60d2-47c1-acd8-4fa8fc988be7).  
  
 Ponteiros e referências a funções são declaradas acrescentando o ponteiro ou o operador de referência ao nome da função, conforme mostrado abaixo.  Parênteses, normalmente opcionais, são necessários para diferenciar um ponteiro para uma função de uma função que retorna um ponteiro:  
  
```  
int (*pf)(int); // pointer to function returning int  
int *f(int i); // function returning pointer to int  
int (&pf)(int); // reference to function   
```  
  
 Ponteiros para funções de membro são distinguidos por especificadores de nomes aninhados:  
  
```  
int (X::* pmf)(); // pointer to member function of X returning int  
int* (X::* pmf)(); // pointer to member function returning pointer to int  
```  
  
 Consulte também [ponteiros para membros](../Topic/Pointers%20to%20Members.md).  
  
 **Funções e objetos na mesma declaração**  
  
 Funções e objetos podem ser declarados na mesma declaração da seguinte maneira:  
  
```  
int i, *j, f(int k);  // int, pointer to int, function returning int  
```  
  
 A sintaxe pode ser confusa em algumas circunstâncias.  A declaração a seguir  
  
```  
int* i, f(int k);  // pointer to int, function returning int (not int*)  
```  
  
 pode se parecer com a declaração de um ponteiro `int` e uma função que retorna `int*`, mas não é.  Isso é porque * faz parte do declarador para `i`, e não faz parte do declarador para `f`.  
  
 **Simplificando a sintaxe do declarator com typedef**  
  
 Uma técnica melhor, porém, é usar `typedef` ou uma combinação de parênteses e da palavra-chave `typedef`. Considere declarar uma matriz de ponteiros para funções:  
  
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
  
 Para obter mais informações sobre typedef, consulte [especificador typedef](http://msdn.microsoft.com/pt-br/cc96cf26-ba93-4179-951e-695d1f5fdcf1).  
  
 Ponteiros, referências, matrizes de um único tipo de base podem ser combinados em uma única declaração (separada por vírgulas) como  
  
```  
int a, *b, c[5], **d, &e=a;  
```  
  
 **Sintaxe de declarador mais complexa**  
  
-   Ponteiro, referência, matriz e declaradores de função podem ser combinados para especificar esses objetos como matrizes de ponteiros para funções, ponteiros para matrizes, etc.  
  
-   A gramática recursiva a seguir descreve a sintaxe de Declarador de ponteiro totalmente.  
  
-   
          `declarator` é definido como um dos seguintes:  
  
```  
1. identifier   
2. qualified-name   
3. declarator ( argument-list ) [cv-qualfiers] [exception-spec]  
4. declarator [ [ constant-expression ] ]   
  
5. pointer-operatordeclarator   
6. ( declarator )  
```  
  
-   e *operador ponteiro* é um destes:  
  
```  
  
      * [cv-qualifiers]  
& [cv-qualifiers]  
::nested-name-specifier * [cv-qualfiers]  
```  
  
 Como um declarador pode conter declaradores, é possível construir os tipos derivados mais complexos, como matrizes de ponteiros, funções que retornam matrizes de ponteiros de função, usando as regras acima.  Para formar cada etapa da construções, comece com o identificador que representa o tipo de dados base e aplique a regra de sintaxe acima com a expressão anterior como `declarator`.  A ordem que você aplique as regras de sintaxe deve ser o inverso da maneira como a expressão é indicada em inglês.  Se aplicar a *operador ponteiro* regra de sintaxe para uma expressão de matriz ou função, use parênteses se você quiser que um ponteiro para a matriz ou função, como a última linha na tabela a seguir.  
  
 O exemplo a seguir mostra a construção de "ponteiro para matriz de 10 ponteiros para int".  
  
|Expressão verbal|Declarador|Regra de sintaxe aplicada|  
|-----------------------|----------------|-------------------------|  
||`i`|1|  
|indicador de|`*i`|5|  
|matriz de 10|`(*i)[10]`|4|  
|ponteiro para|`*((*i)[10])`|em seguida, 5 e 6|  
  
 Quando vários ponteiro, referência, matriz ou função modificadores são usados, declaradores podem se tornar bastante complicados.  O tópico [Interpretando declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md) descreve como ler a sintaxe de declarador mais complexa.  O tópico é aplicável para C e C++, embora em C++, em qualquer lugar do * é usado para indicar um ponteiro, um nome qualificado, como MyClass::\* pode ser usada para especificar um ponteiro para um membro de uma classe.