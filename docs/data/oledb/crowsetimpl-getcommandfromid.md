---
title: "CRowsetImpl::GetCommandFromID | Microsoft Docs"
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
  - "CRowsetImpl::GetCommandFromID"
  - "GetCommandFromID"
  - "CRowsetImpl.GetCommandFromID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetCommandFromID"
ms.assetid: 9f39cb07-1c40-486f-ba5b-cb4a65fab8a7
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowsetImpl::GetCommandFromID
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, em caso afirmativo, copia os valores da cadeia de caracteres os membros de dados [m\_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m\_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).  
  
## Sintaxe  
  
```  
  
      HRESULT CRowsetBaseImpl::GetCommandFromID(  
   DBID* pTableID,  
   DBID* pIndexID   
);  
```  
  
#### Parâmetros  
 `pTableID`  
 \[in\] ponteiro da **DBID** que representa a ID da tabela  
  
 `pIndexID`  
 \[in\] ponteiro da **DBID** que representa o ID de índice  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Este método é chamado por um upcast estática por `CRowsetImpl` para popular os membros de dados [m\_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m\_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).  Por padrão, esse método verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres.  Se contêm valores de cadeia de caracteres, cópias desse método os valores da cadeia de caracteres os membros de dados.  Colocando um método com essa assinatura no `CRowsetImpl`\- a classe derivada, o método será chamada em vez de implementação de base.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe CRowsetImpl](../../data/oledb/crowsetimpl-class.md)   
 [CRowsetImpl::SetCommandText](../../data/oledb/crowsetimpl-setcommandtext.md)