---
title: CDynamicStringAccessor::SetString | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDynamicStringAccessor::SetString
- CDynamicStringAccessor.SetString
dev_langs:
- C++
helpviewer_keywords:
- SetString method
ms.assetid: 94846d8b-4c1b-47fe-acdc-1752981cee25
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7d425159b1234a152fc5e914db4a664abd91e599
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdynamicstringaccessorsetstring"></a>CDynamicStringAccessor::SetString
Define os dados da coluna especificada como uma cadeia de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```
HRESULT SetString(DBORDINAL nColumn,  
  BaseType* data) throw();  


HRESULT SetString(const CHAR* pColumnName,  
   BaseType* data) throw();  


HRESULT SetString(const WCHAR* pColumnName,  
   BaseType* data) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nColumn`  
 [in] O número da coluna. Coluna de números começam com 1. O valor especial de 0 se refere à coluna de indicador, se houver.  
  
 `pColumnName`  
 [in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
 `data`  
 [in] Um ponteiro para os dados de cadeia de caracteres a ser gravado para a coluna especificada.  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o valor de cadeia de caracteres para o qual definir a coluna especificada. O valor é do tipo `BaseType`, que será `CHAR` ou `WCHAR` dependendo se `_UNICODE` está definido ou não.  
  
## <a name="remarks"></a>Comentários  
 O segundo substituir o formulário usa o nome da coluna como uma cadeia de caracteres ANSI e a terceira substituir o formulário usa o nome da coluna como uma cadeia de caracteres Unicode.  
  
 Se `_SECURE_ATL` está definido para ter um valor diferente de zero, uma falha de asserção de tempo de execução será gerada se a entrada `data` cadeia for maior que o comprimento máximo permitido da coluna de dados referenciado. Caso contrário, a cadeia de caracteres de entrada será truncada se for maior que o comprimento máximo permitido.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)