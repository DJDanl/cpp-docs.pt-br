---
title: "Qualificadores de tipo | Microsoft Docs"
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
  - "palavra-chave const [C]"
  - "memória, acessar usando volátil"
  - "qualificadores para tipos"
  - "qualificadores de tipo"
  - "palavra-chave volatile [C]"
  - "palavra-chave volatile [C], qualificador de tipo"
  - "palavra-chave volatile [C], especificador de tipo"
ms.assetid: bb4c6744-1dd7-40a8-b4eb-f5585be30908
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Qualificadores de tipo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os qualificadores de tipo fornecem uma de duas propriedades a um identificador.  O qualificador de tipo **const** declara um objeto como não modificável.  O qualificador de tipo `volatile` declara um item cujo valor possa ser alterado legitimamente para algo além do controle do programa em que aparece como um thread de execução simultânea.  
  
 Os dois qualificadores de tipo, **const** e `volatile`, podem aparecer apenas uma vez em uma declaração.  Os qualificadores de tipo podem aparecer com qualquer especificador de tipo; porém, eles não podem aparecer depois da primeira vírgula em uma declaração de vários itens.  Por exemplo, as seguintes declarações são aceitáveis:  
  
```  
typedef volatile int VI;  
const int ci;  
```  
  
 Estas declarações não são aceitáveis:  
  
```  
typedef int *i, volatile *vi;  
float f, const cf;     
```  
  
 Os qualificadores de tipo são relevantes apenas ao acessar identificadores como l\-values nas expressões.  Consulte [Expressões L\-Value e R\-Value](../Topic/L-Value%20and%20R-Value%20Expressions.md) para obter informações sobre l\-values e expressões.  
  
## Sintaxe  
 *type\-qualifier*:  
 **constvolatile**  
  
 As declarações **const** e `volatile` são aceitáveis:  
  
```  
int const *p_ci;       /* Pointer to constant int */  
int const (*p_ci);     /* Pointer to constant int */  
int *const cp_i;       /* Constant pointer to int */  
int (*const cp_i);     /* Constant pointer to int */  
int volatile vint;     /* Volatile integer        */  
```  
  
 Se a especificação de um tipo de matriz incluir qualificadores de tipo, o elemento será qualificada, não o tipo de matriz.  Se a especificação de tipo de função incluir qualificadores, o comportamento será indefinido.  Nem `volatile` ou **const** afetam as propriedades aritméticas ou do intervalo de valores do objeto.  
  
 Esta lista descreve como usar **const** e `volatile`.  
  
-   A palavra\-chave **const** pode ser usada para modificar qualquer tipo fundamental ou de agregação, um ponteiro para um objeto de qualquer tipo ou um `typedef`.  Se um item for declarado apenas com o qualificador de tipo **const**, seu tipo será considerado **const int**.  Uma variável **const** pode ser inicializada ou colocada em uma região somente leitura de armazenamento.  A palavra\-chave **const** é útil para declarar ponteiros para **const**, pois isso requer que a função não altere o ponteiro de qualquer maneira.  
  
-   O compilador pressupõe que, a qualquer momento no programa, uma variável de `volatile` pode ser acessada por um processo desconhecido que usa ou modifica seu valor.  Portanto, independentemente das otimizações especificadas na linha de comando, o código para cada atribuição ou referência a uma variável `volatile` deve ser gerado mesmo se isso não tiver qualquer efeito aparente.  
  
     Se `volatile` for usado sozinho, `int` será presumido.  O especificador de tipo `volatile` pode ser usado para fornecer acesso confiável aos locais especiais de memória.  Use `volatile` com objetos de dados que possam ser acessados ou modificados por manipuladores de sinal, por programas de execução simultânea ou por hardware especial, como registros de controle de E\/S mapeadas em memória.  Você pode declarar uma variável como `volatile` para seu tempo de vida, ou você pode determinar que uma única referência seja `volatile`.  
  
-   Um item pode ser **const** e `volatile` ao mesmo tempo. Nesse caso, o item não pode ser modificado legitimamente por seu próprio programa, mas pode ser modificado por algum processo não simultâneo.  
  
## Consulte também  
 [Declarações e tipos](../c-language/declarations-and-types.md)