---
title: 'Cdbpropset:: Cdbpropset | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDBPropSet.CDBPropSet
- CDBPropSet::CDBPropSet
- ATL::CDBPropSet::CDBPropSet
- ATL.CDBPropSet.CDBPropSet
dev_langs: C++
helpviewer_keywords: CDBPropSet class, constructor
ms.assetid: 02ae5d9e-c067-47ca-8111-a03e86b5626b
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 239f6c0a03186736d35b8d082913aeb76cac1d14
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdbpropsetcdbpropset"></a>CDBPropSet::CDBPropSet
O construtor. Inicializa o **rgProperties**, **cProperties**, e **guidPropertySet** campos do [DBPROPSET](https://msdn.microsoft.com/en-us/library/ms714367.aspx) estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      CDBPropSet(  
   const GUID& guid   
);  
CDBPropSet(   
   const CDBPropSet& propset    
);  
CDBPropSet( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `guid`  
 [in] Um GUID usado para inicializar o **guidPropertySet** campo.  
  
 *conjunto de propriedades*  
 [in] Outro `CDBPropSet` objeto para a construção de cópia.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDBPropSet](../../data/oledb/cdbpropset-class.md)   
 [Cdbpropset:: Setguid](../../data/oledb/cdbpropset-setguid.md)   
 [Estrutura DBPROP](https://msdn.microsoft.com/en-us/library/ms717970.aspx)