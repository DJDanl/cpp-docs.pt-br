---
title: "IRowsetImpl::CreateRow | Microsoft Docs"
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
  - "IRowsetImpl.CreateRow"
  - "ATL.IRowsetImpl.CreateRow"
  - "ATL::IRowsetImpl::CreateRow"
  - "CreateRow"
  - "IRowsetImpl::CreateRow"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CreateRow"
ms.assetid: b01c430c-9484-4fef-a6cf-a2e8d9d99130
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetImpl::CreateRow
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um método auxiliar chamado por [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md) para atribuir nova **HROW**.  
  
## Sintaxe  
  
```  
  
      HRESULT CreateRow(  
   DBROWOFFSET lRowsOffset,  
   DBCOUNTITEM& cRowsObtained,  
   HROW* rgRows   
);  
```  
  
#### Parâmetros  
 *lRowsOffset*  
 Posição da linha que está sendo criada.  
  
 *cRowsObtained*  
 Uma referência passados de volta ao usuário que indica o número de linhas criadas.  
  
 *rgRows*  
 Uma matriz de s **HROW**retorna ao chamador com as alças de linha recém\-criados.  
  
## Comentários  
 Se a linha existir, chamadas [AddRefRows](../../data/oledb/irowsetimpl-addrefrows.md) esse método e retorna.  Caso contrário, o atribui uma nova instância da variável do modelo de RowClass e adicioná\-la a [m\_rgRowHandles](../../data/oledb/irowsetimpl-m-rgrowhandles.md).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetImpl](../Topic/IRowsetImpl%20Class.md)