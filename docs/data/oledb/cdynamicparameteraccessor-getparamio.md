---
title: CDynamicParameterAccessor::GetParamIO | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- GetParamIO
- CDynamicParameterAccessor::GetParamIO
- ATL.CDynamicParameterAccessor.GetParamIO
- CDynamicParameterAccessor.GetParamIO
- ATL::CDynamicParameterAccessor::GetParamIO
dev_langs:
- C++
helpviewer_keywords:
- GetParamIO method
ms.assetid: 9c485e39-c67e-4df7-a707-c773019c4d1e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4a4ed23081ea7d9ee146a749ff642328fac7d80f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdynamicparameteraccessorgetparamio"></a>CDynamicParameterAccessor::GetParamIO
Determina se o parâmetro especificado é um parâmetro de entrada ou saído.  
  
## <a name="syntax"></a>Sintaxe  
  
```
bool GetParamIO(DBORDINAL nParam,   
   DBPARAMIO* pParamIO) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nParam`  
 [in] O número do parâmetro (deslocamento de 1). Parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 *pParamIO*  
 Um ponteiro para a variável que contém o **DBPARAMIO** (entrada ou saída) o tipo do parâmetro especificado. Ele é definido da seguinte maneira:  
  
```  
typedef DWORD DBPARAMIO;  
  
enum DBPARAMIOENUM {  
    DBPARAMIO_NOTPARAM   = 0,  
    DBPARAMIO_INPUT      = 0x1,  
    DBPARAMIO_OUTPUT     = 0x2  
};  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna **true** em caso de sucesso ou **false** em caso de falha.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)