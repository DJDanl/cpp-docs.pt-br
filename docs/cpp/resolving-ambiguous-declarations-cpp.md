---
title: "Resolu&#231;&#227;o de ambiguidade | Microsoft Docs"
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
ms.assetid: 3d773ee7-bbea-47de-80c2-cb0a9d4ec0b9
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Resolu&#231;&#227;o de ambiguidade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para executar conversões explícitas de um tipo em outro, você deve usar as conversões, especificando o nome do tipo desejado.  Algumas conversões de tipos resultam na ambiguidade sintática.  A seguinte conversão de tipos estilo função é ambígua:  
  
```  
char *aName( String( s ) );  
```  
  
 Não está claro se esta é uma declaração de função ou uma declaração de objeto com conversão estilo função do inicializador: poderia declarar um tipo de retorno **char \*** que usa um argumento de tipo `String` ou poderia declarar o objeto `aName` e inicializá\-lo com o valor de `s` convertido no tipo `String`.  
  
 Se uma declaração puder ser considerada uma declaração de função válida, ela será tratada como tal.  Se, possivelmente, ela não for uma declaração de função – ou seja, se estiver sintaticamente incorreta — será uma instrução examinada para ver se é uma conversão de tipo estilo função.  Portanto, o compilador considera a instrução como uma declaração de uma função e ignora os parênteses em torno do identificador `s`.  Por outro lado, as instruções:  
  
```  
char *aName( (String)s );  
```  
  
 e  
  
```  
char *aName = String( s );  
```  
  
 são claramente declarações de objetos, e uma conversão definida pelo usuário do tipo `String` no tipo **char \*** é chamada para executar a inicialização de `aName`.  
  
## Consulte também  
 [C\+\+ Abstract Declarators](http://msdn.microsoft.com/pt-br/e7e18c18-0cad-4450-942b-d27e1d4dd088)