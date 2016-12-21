---
title: "IRowsetUpdateImpl::m_mapCachedData | Microsoft Docs"
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
  - "IRowsetUpdateImpl.m_mapCachedData"
  - "IRowsetUpdateImpl::m_mapCachedData"
  - "m_mapCachedData"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "m_mapCachedData"
ms.assetid: 65131743-8580-48c8-bb22-68f17c9dfa13
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetUpdateImpl::m_mapCachedData
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um mapa que contém os dados originais para a operação adiada.  
  
## Sintaxe  
  
```  
  
      CAtlMap<   
   HROW hRow,    
   Storage* pData   
>   
m_mapCachedData;  
```  
  
#### Parâmetros  
 `hRow`  
 Identificador para as linhas dos dados.  
  
 `pData`  
 Um ponteiro para os dados a serem armazenados em cachê.  Os dados são do tipo de *armazenamento* \(a classe de registro do usuário\).  Veja o argumento do modelo *de armazenamento* em [Classe de IRowsetUpdateImpl](../Topic/IRowsetUpdateImpl%20Class.md).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetUpdateImpl](../Topic/IRowsetUpdateImpl%20Class.md)