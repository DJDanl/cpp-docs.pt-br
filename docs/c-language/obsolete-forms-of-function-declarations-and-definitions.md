---
title: "Formas obsoletas de declara&#231;&#245;es e defini&#231;&#245;es da fun&#231;&#227;o | Microsoft Docs"
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
  - "declarações de função de estilo antigo"
ms.assetid: 67c5038f-0529-4f29-9d0f-c27580977b50
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Formas obsoletas de declara&#231;&#245;es e defini&#231;&#245;es da fun&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As declarações e definições de função de estilo antigo usam regras ligeiramente diferentes para declarar parâmetros em relação à sintaxe recomendada pelo padrão ANSI C.  Primeiro, as declarações de estilo antigo não têm uma lista de parâmetros.  Segundo, na definição de função, os parâmetros são listados, mas seus tipos não são declarados na lista de parâmetros.  As declarações de tipo precedem a instrução composta que constitui o corpo da função.  A sintaxe de estilo antigo está obsoleta e não deve ser usada em novas instâncias de código.  Contudo, o código que usa a sintaxe de estilo antigo ainda tem suporte.  Este exemplo ilustra os formatos obsoletos de declarações e definições:  
  
```  
double old_style();           /* Obsolete function declaration */  
  
double alt_style( a , real )  /* Obsolete function definition */  
    double *real;   
    int a;   
{  
    return ( *real + a ) ;  
}  
```  
  
 As funções que retornam um inteiro ou um ponteiro com o mesmo tamanho de um `int` não precisam ter uma declaração, embora ela seja recomendada.  
  
 Para manter a conformidade com o padrão ANSI C, as declarações de função de estilo antigo que usam reticências agora geram um erro ao compilar com a opção \/Za e um aviso de nível 4 ao compilar com \/Ze.  Por exemplo:  
  
```  
void funct1( a, ... )  /* Generates a warning under /Ze or */  
int a;                 /* an error when compiling with /Za */  
{  
}  
```  
  
 Recomenda\-se reescrever essa declaração como um protótipo:  
  
```  
void funct1( int a, ... )  
{  
}  
```  
  
 As declarações de função de estilo antigo também geram avisos se você subsequentemente declara ou define a mesma função com reticências ou com um parâmetro de um tipo que não é igual ao tipo promovido.  
  
 A próxima seção, sobre [definições de função em C](../c-language/c-function-definitions.md), mostra a sintaxe para definições de função, inclusive a sintaxe de estilo antigo.  O não terminal para a lista de parâmetros na sintaxe de estilo antigo é *identifier\-list*.  
  
## Consulte também  
 [Visão geral das funções](../c-language/overview-of-functions.md)