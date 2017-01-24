---
title: "Fun&#231;&#227;o de retorno de chamada para CDC::EnumObjects | Microsoft Docs"
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
  - "Callback Function for CDC::EnumObjects"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções de retorno de chamada, para CDC::EnumObjects"
ms.assetid: 380088b1-88a5-4fb4-bbb5-dd9e8386572b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de retorno de chamada para CDC::EnumObjects
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O nome *de ObjectFunc* é um espaço reservado para o nome da função de aplicativo fornecido.  
  
## Sintaxe  
  
```  
  
      int CALLBACK EXPORT ObjectFunc(   
   LPSTR lpszLogObject,   
   LPSTR* lpData    
);  
```  
  
#### Parâmetros  
 *lpszLogObject*  
 Aponta para uma estrutura de dados de [LOGPEN](../../mfc/reference/logpen-structure.md) ou de [LOGBRUSH](../Topic/LOGBRUSH%20Structure.md) que contém informações sobre os atributos lógicos do objeto.  
  
 `lpData`  
 Os pontos aos dados fornecidos pelo aplicativo passados para a função de `EnumObjects` .  
  
## Valor de retorno  
 A função de retorno de chamada retorna `int`.  O valor do retorno é definido pelo usuário.  Se a função de retorno de chamada retorna 0, `EnumObjects` para a enumeração no início.  
  
## Comentários  
 O nome real deve ser exportado.  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC::EnumObjects](../Topic/CDC::EnumObjects.md)