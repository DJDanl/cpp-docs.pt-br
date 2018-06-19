---
title: CDynamicParameterAccessor::GetParamStatus | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDynamicParameterAccessor::GetParamStatus
- CDynamicParameterAccessor.GetParamStatus
- ATL.CDynamicParameterAccessor.GetParamStatus
- ATL::CDynamicParameterAccessor::GetParamStatus
- GetParamStatus
dev_langs:
- C++
helpviewer_keywords:
- GetParamStatus method
ms.assetid: 9300225a-616c-4a7d-82d0-8c2ecd4d8185
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5be2b663dfc1fedf9dffdf1d3acb34e58de23269
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33096815"
---
# <a name="cdynamicparameteraccessorgetparamstatus"></a>CDynamicParameterAccessor::GetParamStatus
Recupera o status do parâmetro especificado armazenado no buffer.  
  
## <a name="syntax"></a>Sintaxe  
  
```
bool GetParamStatus(DBORDINAL nParam,  
  DBSTATUS* pStatus);  

DBSTATUS* GetParamStatus(DBORDINAL nParam) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nParam`  
 [in] O número do parâmetro (deslocamento de 1). Parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 `pStatus`  
 [out] Um ponteiro para a variável que contém o `DBSTATUS` status do parâmetro especificado. Para obter informações sobre `DBSTATUS` valores, consulte [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx) no *referência do programador de DB OLE*, ou procurar `DBSTATUS` no OLEDB.  
  
## <a name="remarks"></a>Comentários  
 A primeira substituição retorna **true** em caso de sucesso ou **false** em caso de falha. O segundo substituir aponta para a memória que contém o status do parâmetro especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)