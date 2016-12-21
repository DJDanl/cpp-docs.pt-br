---
title: "Declaradores e declara&#231;&#245;es vari&#225;veis | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "declaradores, definição"
  - "declarando variáveis, instruções de declaração"
  - "declarando variáveis, declaradores"
ms.assetid: 5fd67a6a-3a6a-4ec9-b257-3f7390a48d40
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declaradores e declara&#231;&#245;es vari&#225;veis
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O restante desta seção descreve o formato e o significado das declarações para os tipos de variável resumidos nesta lista.  Em particular, as demais seções explicam como declarar o seguinte:  
  
|Tipo de variável|Descrição|  
|----------------------|---------------|  
|[Variáveis simples](../c-language/simple-variable-declarations.md)|Variáveis de valor único com tipo integral ou de ponto flutuante|  
|[Matrizes](../Topic/Array%20Declarations.md)|Variáveis compostas de uma coleção de elementos com o mesmo tipo|  
|[Ponteiros](../c-language/pointer-declarations.md)|Variáveis que apontam para outras variáveis e contêm locais de variáveis \(na forma de endereços\) em vez de valores|  
|[Variáveis de enumeração](../c-language/c-enumeration-declarations.md)|Variáveis simples com tipo integral que mantêm um único valor de um conjunto de constantes de inteiro nomeadas|  
|[Estruturas](../c-language/structure-declarations.md)|Variáveis compostas de uma coleção de valores que podem ter tipos diferentes|  
|[Uniões](../c-language/union-declarations.md)|Variáveis compostas de vários valores de tipos diferentes que ocupam o mesmo espaço de armazenamento|  
  
 Um declarador é a parte de uma declaração que especifica o nome a ser introduzido no programa.  Pode incluir modificadores como **\*** \(ponteiro para\) e qualquer uma das palavras\-chave de convenção de chamada da Microsoft.  
  
 **Específico da Microsoft**  
  
 No declarador  
  
```  
__declspec(thread) char *var;  
```  
  
 `char` é o especificador de tipo, `__declspec(thread)` e `*` são os modificadores, e `var` é o nome do identificador.  
  
 **FIM de Específico da Microsoft**  
  
 Você usa declaradores para declarar matrizes de valores, ponteiros para valores e funções que retornam valores de um tipo especificado.  Os declaradores aparecem nas declarações de matrizes e de ponteiros descritas posteriormente nesta seção.  
  
## Sintaxe  
 `declarator`:  
 *pointer*  opt *direct\-declarator*  
  
 *direct\-declarator*:  
 *identifier*  
  
 **\(**  *declarator*  **\)**  
  
 *direct\-declarator*  **\[**  *constant\-expression*  opt **\]**  
  
 *direct\-declarator*  **\(**  *parameter\-type\-list*  **\)**  
  
 *direct\-declarator*  **\(**  *identifier\-list*  opt **\)**  
  
 `pointer`:  
 **\*** *type\-qualifier\-list*  opt  
  
 **\*** *type\-qualifier\-list*  opt `pointer`  
  
 *type\-qualifier\-list*:  
 *type\-qualifier*  
  
 *type\-qualifier\-list type\-qualifier*  
  
> [!NOTE]
>  Consulte a sintaxe de `declaration` na [visão geral sobre declarações](../Topic/Overview%20of%20Declarations.md) ou no tópico com o [resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md) correspondente à sintaxe que faz referência a um `declarator`.  
  
 Quando um declarador consiste em um identificador não modificado, o item que está sendo declarado tem um tipo de base.  Se um asterisco \(**\***\) aparecer à esquerda de um identificador, o tipo será modificado para um tipo ponteiro.  Se o identificador for seguido por colchetes \(**\[ \]**\), o tipo será modificado para um tipo de matriz.  Se o identificador for seguido por parênteses, o tipo será modificado para um tipo de função.  Para obter mais informações sobre como interpretar a precedência em declarações, consulte o tópico sobre [interpretação de declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md).  
  
 Cada declarador declara pelo menos um identificador.  Um declarador deve incluir um especificador de tipo para ser uma declaração completa.  O especificador de tipo fornece o tipo dos elementos de um tipo de matriz, o tipo de objeto tratado por um tipo ponteiro ou o tipo de retorno de uma função.  
  
 As declarações de [matrizes](../Topic/Array%20Declarations.md) e de [ponteiros](../c-language/pointer-declarations.md) são discutidas em mais detalhes posteriormente nesta seção.  Os exemplos a seguir ilustram alguns formatos simples de declaradores:  
  
```  
int list[20]; // Declares an array of 20 int values named list  
char *cp;     // Declares a pointer to a char value  
double func( void ); // Declares a function named func, with no   
                     // arguments, that returns a double value  
int *aptr[10] // Declares an array of 10 pointers  
```  
  
 **Específico da Microsoft**  
  
 O compilador de C da Microsoft não limita o número de declaradores que podem modificar um tipo aritmético, de estrutura ou de união.  O número é limitado somente pela memória disponível.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Declarações e tipos](../c-language/declarations-and-types.md)