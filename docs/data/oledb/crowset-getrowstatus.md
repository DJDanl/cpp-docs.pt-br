---
title: "CRowset::GetRowStatus | Microsoft Docs"
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
  - "CRowset.GetRowStatus"
  - "ATL.CRowset<TAccessor>.GetRowStatus"
  - "ATL::CRowset<TAccessor>::GetRowStatus"
  - "CRowset::GetRowStatus"
  - "ATL::CRowset::GetRowStatus"
  - "CRowset<TAccessor>::GetRowStatus"
  - "ATL.CRowset.GetRowStatus"
  - "CRowset<TAccessor>.GetRowStatus"
  - "GetRowStatus"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetRowStatus"
ms.assetid: 7a29a235-cb7e-40c1-92ce-5441751febee
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CRowset::GetRowStatus
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna o status de todas as linhas.  
  
## Sintaxe  
  
```  
  
      HRESULT GetRowStatus(   
   DBPENDINGSTATUS* pStatus    
) const throw( );  
```  
  
#### Parâmetros  
 `pStatus`  
 \[out\] de ponteiro para um local onde `GetRowStatus` retorna o valor de status.  Consulte DBPENDINGSTATUS na referência do programador de OLE DB.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Esse método exige a interface opcional `IRowsetUpdate`, que pode não haver suporte em todos os provedores; nesse caso, o método retornará **E\_NOINTERFACE**.  Você também deve definir **DBPROP\_IRowsetUpdate** a `VARIANT_TRUE` antes de chamar **Abrir** na tabela ou o comando que contém o conjunto de linhas.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CRowset](../Topic/CRowset%20Class.md)   
 [IRowsetUpdate::GetRowStatus](https://msdn.microsoft.com/en-us/library/ms724377.aspx)