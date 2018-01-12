---
title: 'Cdbpropidset:: Setguid | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDBPropIDSet.SetGUID
- ATL::CDBPropIDSet::SetGUID
- SetGUID
- ATL.CDBPropIDSet.SetGUID
- CDBPropIDSet::SetGUID
dev_langs: C++
helpviewer_keywords: SetGUID method
ms.assetid: 8dd0f3bf-1490-4d53-9063-322b8d821bbe
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: aa70e704cd8e132404442ef390ea5582155a76e2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdbpropidsetsetguid"></a>CDBPropIDSet::SetGUID
Define o campo GUID no **DBPROPIDSET** estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void SetGUID(   
   const GUID& guid    
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `guid`  
 [in] Um GUID usado para definir o **guidPropertySet** campo o [DBPROPIDSET](https://msdn.microsoft.com/en-us/library/ms717981.aspx) estrutura.  
  
## <a name="remarks"></a>Comentários  
 Este campo pode ser definido pelo [construtor](../../data/oledb/cdbpropidset-cdbpropidset.md) também. Chame essa função se você usar o construtor padrão para esta classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDBPropIDSet](../../data/oledb/cdbpropidset-class.md)