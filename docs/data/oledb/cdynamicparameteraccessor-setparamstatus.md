---
title: 'Cdynamicparameteraccessor:: Setparamstatus | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDynamicParameterAccessor::SetParamStatus
- ATL.CDynamicParameterAccessor.SetParamStatus
- ATL::CDynamicParameterAccessor::SetParamStatus
- CDynamicParameterAccessor.SetParamStatus
- SetParamStatus
dev_langs: C++
helpviewer_keywords: SetParamStatus method
ms.assetid: 0c2271f6-457d-46ca-88b7-4590aadb20d7
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 52059675e20eb1789addf20dbf7a0e772f779efb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdynamicparameteraccessorsetparamstatus"></a>CDynamicParameterAccessor::SetParamStatus
Define o status do parâmetro especificado armazenado no buffer.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      bool SetParamStatus(  
   DBORDINAL nParam,  
   DBSTATUS status  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nParam`  
 [in] O número do parâmetro (deslocamento de 1). Parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 *status*  
 [in] O `DBSTATUS` status do parâmetro especificado. Para obter informações sobre `DBSTATUS` valores, consulte [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx) no *referência do programador de DB OLE*, ou procurar `DBSTATUS` no OLEDB.  
  
## <a name="remarks"></a>Comentários  
 Retorna **true** em caso de sucesso ou **false** em caso de falha.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)