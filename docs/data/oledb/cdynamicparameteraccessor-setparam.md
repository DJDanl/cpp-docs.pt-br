---
title: CDynamicParameterAccessor::SetParam | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CDynamicParameterAccessor::SetParam
- ATL::CDynamicParameterAccessor::SetParam<ctype>
- CDynamicParameterAccessor.SetParam
- ATL.CDynamicParameterAccessor.SetParam
- SetParam
- CDynamicParameterAccessor:SetParam
- CDynamicParameterAccessor::SetParam<ctype>
- CDynamicParameterAccessor::SetParam
dev_langs:
- C++
helpviewer_keywords:
- SetParam method
ms.assetid: e2349220-545c-46ad-90da-9113ac52551a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3fcedc0d54e5b25eb4490425253f6c1bfd139a85
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdynamicparameteraccessorsetparam"></a>CDynamicParameterAccessor::SetParam
Define o buffer de parâmetro usando os dados (não-cadeia de caracteres) especificados.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
template <class ctype>
bool SetParam(DBORDINAL nParam,  
               constctype* pData,  
               DBSTATUS status = DBSTATUS_S_OK) throw();  

template <class ctype>  
bool SetParam(TCHAR* pParamName,  
               const ctype* pData,  
               DBSTATUS status = DBSTATUS_S_OK) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `ctype`  
 Um parâmetro de modelo que é o tipo de dados.  
  
 `nParam`  
 [in] O número do parâmetro (deslocamento de 1). Parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Por exemplo:  
  
 [!code-cpp[NVC_OLEDB_Consumer#8](../../data/oledb/codesnippet/cpp/cdynamicparameteraccessor-setparam_1.cpp)]  
  
 `pParamName`  
 [in] O nome do parâmetro.  
  
 `pData`  
 [in] O ponteiro para a memória que contém os dados a ser gravado no buffer.  
  
 *status*  
 [in] O `DBSTATUS` status da coluna. Para obter informações sobre `DBSTATUS` valores, consulte [Status](https://msdn.microsoft.com/en-us/library/ms722617.aspx) no *referência do programador de DB OLE*, ou procurar `DBSTATUS` no OLEDB.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna **true** em caso de sucesso ou **false** em caso de falha.  
  
 Use `SetParam` para definir os dados que não sejam parâmetro no buffer. Use [SetParamString](../../data/oledb/cdynamicparameteraccessor-setparamstring.md) para definir dados de parâmetro de cadeia de caracteres no buffer.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)