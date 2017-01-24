---
title: "IOpenRowsetImpl::CreateRowset | Microsoft Docs"
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
  - "IOpenRowsetImpl.CreateRowset"
  - "IOpenRowsetImpl::CreateRowset"
  - "CreateRowset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CreateRowset"
ms.assetid: 69041cf6-7a2f-4409-a26e-6e984c24986e
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# IOpenRowsetImpl::CreateRowset
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um objeto de conjunto de linhas.  Não chamado diretamente pelo usuário.  Consulte [IOpenRowset::OpenRowset](https://msdn.microsoft.com/en-us/library/ms716724.aspx)*na referência do programador de OLE DB.*  
  
## Sintaxe  
  
```  
  
      template <class   
      RowsetClass  
      >  
HRESULT CreateRowset(  
   IUnknown* pUnkOuter,  
   DBID* pTableID,  
   DBID* pIndexID,  
   REFIID riid,  
   ULONG cPropertySets,  
   DBPROPSET rgPropertySets[],  
   IUnknown** ppRowset,  
   RowsetClass*& pRowsetObj   
);  
```  
  
#### Parâmetros  
 `RowsetClass`  
 Um membro da classe do modelo que representa a classe do conjunto de linhas do usuário.  Geralmente gerado pelo assistente.  
  
 `pRowsetObj`  
 \[out\] ponteiro de um em um objeto do conjunto de linhas.  Esse parâmetro não é usado normalmente, mas poderá ser usado se você deve executar mais trabalho no conjunto de linhas antes de passá\-lo para um objeto COM.  O tempo de vida de `pRowsetObj` é associado por `ppRowset`.  
  
 Para outros parâmetros, consulte [IOpenRowset::OpenRowset](https://msdn.microsoft.com/en-us/library/ms716724.aspx)*na referência do programador de OLE DB.*  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe IOpenRowsetImpl](../../data/oledb/iopenrowsetimpl-class.md)