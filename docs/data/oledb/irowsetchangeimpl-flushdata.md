---
title: "IRowsetChangeImpl::FlushData | Microsoft Docs"
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
  - "IRowsetChangeImpl::FlushData"
  - "IRowsetChangeImpl.FlushData"
  - "FlushData"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método FlushData"
ms.assetid: fd4bc73b-bc25-4aab-90d5-0bed92670c88
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IRowsetChangeImpl::FlushData
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Overidden pelo provedor para confirmar dados ao seu repositório.  
  
## Sintaxe  
  
```  
  
      HRESULT FlushData(  
   HROW hRowToFlush,  
   HACCESSOR hAccessorToFlush   
);  
```  
  
#### Parâmetros  
 *hRowToFlush*  
 \[in\] identificador para as linhas dos dados.  O tipo dessa linha é determinado pelo argumento do modelo *RowClass* da classe `IRowsetImpl` \(`CSimpleRow` por padrão\).  
  
 *hAccessorToFlush*  
 \[in\] identificador do acessador, que contém informações de informações de associação e do tipo no **PROVIDER\_MAP** \(consulte [IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)\).  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md)