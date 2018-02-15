---
title: CDynamicParameterAccessor::GetParamString | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDynamicParameterAccessor.GetParamString
- GetParamString
- CDynamicParameterAccessor::GetParamString
- ATL.CDynamicParameterAccessor.GetParamString
- ATL::CDynamicParameterAccessor::GetParamString
dev_langs:
- C++
helpviewer_keywords:
- GetParamString method
ms.assetid: 078c2b1c-7072-47c1-a203-f47e75363f91
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5ee0bb1dce2206902f6ccf1ed331d5c843690ce0
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cdynamicparameteraccessorgetparamstring"></a>CDynamicParameterAccessor::GetParamString
Recupera os dados de cadeia de caracteres do parâmetro especificado armazenado no buffer.  
  
## <a name="syntax"></a>Sintaxe  
  
```
bool GetParamString(DBORDINAL nParam,  
  CSimpleStringA& strOutput) throw();bool GetParamString(DBORDINAL nParam,  
  CSimpleStringW& strOutput) throw();bool GetParamString(DBORDINAL nParam,  
  CHAR* pBuffer,  
   size_t* pMaxLen) throw();bool GetParamString(DBORDINAL nParam,  
  WCHAR* pBuffer,  
   size_t* pMaxLen) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nParam`  
 [in] O número do parâmetro (deslocamento de 1). Parâmetro 0 é reservado para valores de retorno. O número do parâmetro é o índice do parâmetro com base em sua ordem na chamada de procedimento armazenado ou SQL. Consulte [SetParam](../../data/oledb/cdynamicparameteraccessor-setparam.md) para obter um exemplo.  
  
 `strOutput`  
 [out] O ANSI (**CSimpleStringA**) ou Unicode (**CSimpleStringW**) dados do parâmetro especificado de cadeia de caracteres. Você deve passar um parâmetro de tipo `CString`, por exemplo:  
  
 [!code-cpp[NVC_OLEDB_Consumer#9](../../data/oledb/codesnippet/cpp/cdynamicparameteraccessor-getparamstring_1.cpp)]  
  
 `pBuffer`  
 [out] Um ponteiro para o ANSI (**CHAR**) ou Unicode (**WCHAR**) dados do parâmetro especificado de cadeia de caracteres.  
  
 `pMaxLen`  
 [out] Um ponteiro para o tamanho do buffer apontado pelo `pBuffer` (em caracteres, incluindo a terminação nula).  
  
## <a name="remarks"></a>Comentários  
 Retorna **true** em caso de sucesso ou **false** em caso de falha.  
  
 Se `pBuffer` for NULL, esse método definirá o tamanho do buffer exigido na memória apontada pela `pMaxLen` e retornar **true** sem copiar os dados.  
  
 Esse método irá falhar se o buffer `pBuffer` não é grande o suficiente para conter a cadeia de caracteres inteira.  
  
 Use `GetParamString` para recuperar dados de parâmetro de cadeia de caracteres do buffer. Use [GetParam](../../data/oledb/cdynamicparameteraccessor-getparam.md) para recuperar dados parâmetro que não sejam do buffer.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)