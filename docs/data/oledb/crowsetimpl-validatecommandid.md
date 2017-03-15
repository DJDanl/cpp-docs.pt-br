---
title: "CRowsetImpl::ValidateCommandID | Microsoft Docs"
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
  - "CRowsetImpl.ValidateCommandID"
  - "CRowsetImpl::ValidateCommandID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método ValidateCommandID"
ms.assetid: cdde6088-41bc-4b8f-a32b-f36f7d9b5ec0
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowsetImpl::ValidateCommandID
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Verifica se um ou ambos **DBID**s contém valores de cadeia de caracteres e, em caso afirmativo, copiá\-los para os membros de dados [m\_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m\_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).  
  
## Sintaxe  
  
```  
  
      HRESULT CRowsetBaseImpl::ValidateCommandID(  
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
 Este método é chamado por um upcast estática por `CRowsetImpl` para popular seus membros de dados [m\_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m\_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).  Por padrão, esse método verifica se um ou ambos **DBID**s contém valores de cadeia de caracteres e, em caso afirmativo, copiá\-los para os membros de dados.  Colocando um método com essa assinatura no `CRowsetImpl`\- a classe derivada, o método será chamada em vez de implementação de base.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe CRowsetImpl](../../data/oledb/crowsetimpl-class.md)   
 [CRowsetImpl::SetCommandText](../../data/oledb/crowsetimpl-setcommandtext.md)