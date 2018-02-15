---
title: CDynamicParameterAccessor::GetParamLength | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::CDynamicParameterAccessor::GetParamLength
- ATL.CDynamicParameterAccessor.GetParamLength
- CDynamicParameterAccessor.GetParamLength
- CDynamicParameterAccessor::GetParamLength
- GetParamLength
dev_langs:
- C++
helpviewer_keywords:
- GetParamLength method
ms.assetid: 04d76931-911a-4915-9c2c-ad585a9f3854
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c60f2a294019b269535a9f2f1debf5d257d9c242
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cdynamicparameteraccessorgetparamlength"></a>CDynamicParameterAccessor::GetParamLength
Recupera o comprimento do parâmetro especificado armazenado no buffer.  
  
## <a name="syntax"></a>Sintaxe  
  
```
bool GetParamLength(DBORDINAL nParam,  
  DBLENGTH* pLength);  

DBLENGTH* GetParamLength(DBORDINAL nParam) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nParam`  
 [in] O número do parâmetro (deslocamento de 1). Parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 `pLength`  
 [out] Um ponteiro para a variável que contém o comprimento em bytes do parâmetro especificado.  
  
## <a name="remarks"></a>Comentários  
 A primeira substituição retorna **true** em caso de sucesso ou **false** em caso de falha. O segundo substituir aponta para a memória que contém o comprimento do parâmetro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)