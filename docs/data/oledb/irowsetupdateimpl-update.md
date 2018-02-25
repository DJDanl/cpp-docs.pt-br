---
title: IRowsetUpdateImpl::Update | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::IRowsetUpdateImpl::Update
- IRowsetUpdateImpl::Update
- IRowsetUpdateImpl.Update
- ATL.IRowsetUpdateImpl.Update
dev_langs:
- C++
helpviewer_keywords:
- Update method
ms.assetid: 9ec6884d-aa9c-4871-a803-c048f162403c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b398bcc4d522fdb682778de1088c60c5b3ac63f3
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="irowsetupdateimplupdate"></a>IRowsetUpdateImpl::Update
Transmite todas as alterações feitas desde a última busca ou atualizar a linha.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD (Update )(HCHAPTER /* hReserved */,  
   DBCOUNTITEM cRows,  
   const HROW rghRows[],  
   DBCOUNTITEM* pcRows,  
   HROW** prgRows,  
   DBROWSTATUS** prgRowStatus);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hReserved`  
 [in] Corresponde do `hChapter` parâmetro em [IRowsetUpdate:: Update](https://msdn.microsoft.com/en-us/library/ms719709.aspx).  
  
 Para outros parâmetros, consulte [IRowsetUpdate:: Update](https://msdn.microsoft.com/en-us/library/ms719709.aspx) no *referência do programador de DB OLE*.  
  
## <a name="remarks"></a>Comentários  
 As alterações são transmitidas chamando [irowsetchangeimpl:: Flushdata](../../data/oledb/irowsetchangeimpl-flushdata.md). O consumidor deve chamar [crowset:: Update](../../data/oledb/crowset-update.md) para que as alterações entrem em vigor. Definir *prgRowstatus* para um valor apropriado, conforme descrito em [estados de linha](https://msdn.microsoft.com/en-us/library/ms722752.aspx) no *referência do programador de DB OLE*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md)