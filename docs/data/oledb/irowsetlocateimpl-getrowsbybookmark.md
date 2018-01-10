---
title: 'Irowsetlocateimpl:: Getrowsbybookmark | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IRowsetLocateImpl::GetRowsByBookmark
- IRowsetLocateImpl.GetRowsByBookmark
- GetRowsByBookmark
dev_langs: C++
helpviewer_keywords: GetRowsByBookmark method
ms.assetid: 07906e42-3582-427e-812a-aa19791e3c56
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ad35b152b5e7285d4dbd80c69ad60e05ddb87f62
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="irowsetlocateimplgetrowsbybookmark"></a>IRowsetLocateImpl::GetRowsByBookmark
Busca de uma ou mais linhas que correspondem os marcadores especificados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      STDMETHOD ( GetRowsByBookmark )(  
   HCHAPTER /* hReserved */,  
   DBCOUNTITEM cRows,  
   const DBBKMARK rgcbBookmarks[],  
   const BYTE* rgpBookmarks,  
   HROW rghRows[],  
   DBROWSTATUS* rgRowStatus[]   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hReserved`  
 [in] Corresponde à `hChapter` parâmetro [irowsetlocate:: Getrowsbybookmark](https://msdn.microsoft.com/en-us/library/ms725420.aspx).  
  
 Para outros parâmetros, consulte [irowsetlocate:: Getrowsbybookmark](https://msdn.microsoft.com/en-us/library/ms725420.aspx) no *referência do programador de DB OLE*.  
  
## <a name="remarks"></a>Comentários  
 O indicador pode ser um valor que você define ou OLE DB [indicadores padrão](https://msdn.microsoft.com/en-us/library/ms712954.aspx) (**DBBMK_FIRST** ou **DBBMK_LAST**). Não altere a posição do cursor.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md)   
 [IRowsetLocateImpl::GetRowsAt](../../data/oledb/irowsetlocateimpl-getrowsat.md)