---
title: CDynamicParameterAccessor::GetParamName | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDynamicParameterAccessor::GetParamName
- ATL.CDynamicParameterAccessor.GetParamName
- GetParamName
- CDynamicParameterAccessor.GetParamName
- ATL::CDynamicParameterAccessor::GetParamName
dev_langs:
- C++
helpviewer_keywords:
- GetParamName method
ms.assetid: 707c08ed-d3d0-4ce8-b23e-20b07202a3e2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1b41b9f2daca1b6f4d911bfc64e675079bdee0e5
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cdynamicparameteraccessorgetparamname"></a>CDynamicParameterAccessor::GetParamName
Recupera o nome do parâmetro especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      LPOLESTR GetParamName(DBORDINAL nParam) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nParam`  
 [in] O número do parâmetro (deslocamento de 1). Parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
## <a name="return-value"></a>Valor de retorno  
 O nome do parâmetro especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)