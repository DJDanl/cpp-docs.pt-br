---
title: "CRowsetImpl::NameFromDBID | Microsoft Docs"
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
  - "CRowsetImpl.NameFromDBID"
  - "CRowsetImpl::NameFromDBID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método NameFromDBID"
ms.assetid: 6aa5b074-90c7-4434-adfd-c64c13e76c78
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowsetImpl::NameFromDBID
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Extrai uma cadeia de caracteres de **DBID** e copiá\-lo em `bstr` passado.  
  
## Sintaxe  
  
```  
  
      HRESULT CRowsetBaseImpl::NameFromDBID(  
   DBID* pDBID,  
   CComBSTR& bstr,  
   bool bIndex   
);  
```  
  
#### Parâmetros  
 *pDBID*  
 \[in\] ponteiro da **DBID** do qual extrair uma cadeia de caracteres.  
  
 `bstr`  
 \[in\] referência de [CComBSTR](../../atl/reference/ccombstr-class.md) para colocar uma cópia da cadeia de caracteres de **DBID** .  
  
 `bIndex`  
 \[in\] **true** se um índice **DBID**; **false** se uma tabela **DBID**.  
  
## Valor de retorno  
 `HRESULT`padrão.  Dependendo **DBID** é uma tabela ou um índice \(indicado por `bIndex`\), o método retornará **DB\_E\_NOINDEX** ou **DB\_E\_NOTABLE**.  
  
## Comentários  
 Este método é chamado por implementações de `CRowsetImpl` de [ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md) e de [GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe CRowsetImpl](../../data/oledb/crowsetimpl-class.md)