---
title: 'Irowsetlocateimpl:: Compare | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.IRowsetLocateImpl.Compare
- IRowsetLocateImpl::Compare
- IRowsetLocateImpl.Compare
- ATL::IRowsetLocateImpl::Compare
dev_langs: C++
helpviewer_keywords: Compare method
ms.assetid: 6f84052c-c68c-480a-982f-03748faa7d5d
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9eaa0aaecd1ff30e51416aaaccebcc8fe6746222
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="irowsetlocateimplcompare"></a>IRowsetLocateImpl::Compare
Compara dois indicadores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      STDMETHOD ( Compare )(  
   HCHAPTER /* hReserved */,  
   DBBKMARK cbBookmark1,  
   const BYTE* pBookmark1,  
   DBBKMARK cbBookmark2,  
   const BYTE* pBookmark2,  
   DBCOMPARE* pComparison   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IRowsetLocate::Compare](https://msdn.microsoft.com/en-us/library/ms709539.aspx) no *referência do programador de OLE DB*.  
  
## <a name="remarks"></a>Comentários  
 Qualquer um dos indicadores podem ser um padrão definido pelo OLE DB [indicador padrão](https://msdn.microsoft.com/en-us/library/ms712954.aspx) (**DBBMK_FIRST**, **DBBMK_LAST**, ou **DBBMK_INVALID**). O valor retornado em `pComparison` indica a relação entre os dois indicadores:  
  
-   **DBCOMPARE_LT** (`cbBookmark1` é antes `cbBookmark2`.)  
  
-   **DBCOMPARE_EQ** (`cbBookmark1` é igual a `cbBookmark2`.)  
  
-   **DBCOMPARE_GT** (`cbBookmark1` após `cbBookmark2`.)  
  
-   **DBCOMPARE_NE** (os indicadores são iguais e não ordenada).  
  
-   **DBCOMPARE_NOTCOMPARABLE** (não não possível comparar os indicadores.)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md)