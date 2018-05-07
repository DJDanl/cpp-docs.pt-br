---
title: CDynamicParameterAccessor::GetParamLength | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ee19c694fa267630419857c3a81bd9e61d044939
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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