---
title: 'Irowsetimpl:: GetData | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.IRowsetImpl.GetData
- ATL::IRowsetImpl::GetData
- IRowsetImpl::GetData
- IRowsetImpl.GetData
dev_langs: C++
helpviewer_keywords: GetData method [OLE DB]
ms.assetid: cb15f1cc-bd25-4b74-93c3-db71aa93829c
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 0226a9096a93ae1b0e6cd7705fef773a01eea9f0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="irowsetimplgetdata"></a>IRowsetImpl::GetData
Recupera dados de cópia do conjunto de linhas da linha.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      STDMETHOD( GetData )(  
   HROW hRow,  
   HACCESSOR hAccessor,  
   void* pDstData   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IRowset:: GetData](https://msdn.microsoft.com/en-us/library/ms716988.aspx) no *referência do programador de OLE DB*.  
  
 Alguns parâmetros correspondem a *referência do programador de DB OLE* parâmetros de nomes diferentes, que são descritos em **IRowset:: GetData**:  
  
|Parâmetros de modelo de banco de dados OLE|*Referência do programador DB OLE* parâmetros|  
|--------------------------------|------------------------------------------------|  
|*pDstData*|`pData`|  
  
## <a name="remarks"></a>Comentários  
 Também lida com a conversão de dados usando a DLL de conversão de dados OLE DB.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)