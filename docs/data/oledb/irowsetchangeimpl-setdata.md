---
title: 'Irowsetchangeimpl:: SetData | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- SetData
- IRowsetChangeImpl::SetData
- ATL.IRowsetChangeImpl.SetData
- IRowsetChangeImpl.SetData
- ATL::IRowsetChangeImpl::SetData
dev_langs: C++
helpviewer_keywords: SetData method
ms.assetid: 81e1dd0a-0518-440c-8808-cee76e4929c7
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d42f64575e515b67d296acbd21411bcd184d479c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="irowsetchangeimplsetdata"></a>IRowsetChangeImpl::SetData
Define valores de dados em uma ou mais colunas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      STDMETHOD ( SetData )(  
   HROW hRow,  
   HACCESSOR hAccessor,  
   void* pSrcData   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IRowsetChange:: SetData](https://msdn.microsoft.com/en-us/library/ms721232.aspx) no *referência do programador de OLE DB*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IRowsetChangeImpl](../../data/oledb/irowsetchangeimpl-class.md)