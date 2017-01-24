---
title: "Operador de colagem de token (##) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "##"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Operador de pré-processador ##"
  - "pré-processador, operadores"
ms.assetid: 4f173503-990f-4bff-aef3-ec4d1f1458ef
caps.latest.revision: 10
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Operador de colagem de token (##)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O operador double\-number\-sign ou "token\-pasting" \(**\#\#**\), que às vezes é chamado de operador "merging", é usado em macros do tipo objeto e do tipo função.  Ele permite que tokens separados sejam agrupados em um único token e, portanto, não pode ser o primeiro ou último o token na definição da macro.  
  
 Se um parâmetro formal em uma definição de macro é precedido ou seguido pelo operador token\-pasting, o parâmetro formal é substituído imediatamente pelo argumento real não expandido.  A expansão da macro não é executada no argumento antes da substituição.  
  
 Em seguida, cada ocorrência do operador token\-pasting em *token\-string* é removida, e os tokens que o precedem e seguem são concatenados.  O token resultante deve ser um token válido.  Nesse caso, o token será verificado para uma possível substituição se representar o nome de uma macro.  O identificador representa o nome pelo qual os tokens concatenados serão conhecidos no programa antes da substituição.  Cada token representa um token definido em outro lugar, no programa ou na linha de comando do compilador.  O espaço em branco que precede ou segue o operador é opcional.  
  
 Este exemplo ilustra o uso de operadores stringizing em token\-pasting na especificação da saída do programa:  
  
```  
#define paster( n ) printf_s( "token" #n " = %d", token##n )  
int token9 = 9;  
```  
  
 Se uma macro é chamada com um argumento numérico como  
  
```  
paster( 9 );  
```  
  
 a macro gera  
  
```  
printf_s( "token" "9" " = %d", token9 );  
```  
  
 que se torna  
  
```  
printf_s( "token9 = %d", token9 );  
```  
  
## Exemplo  
  
```  
// preprocessor_token_pasting.cpp  
#include <stdio.h>  
#define paster( n ) printf_s( "token" #n " = %d", token##n )  
int token9 = 9;  
  
int main()  
{  
   paster(9);  
}  
```  
  
  **token9 \= 9**   
## Consulte também  
 [Operadores de pré\-processador](../preprocessor/preprocessor-operators.md)