---
title: CDynamicStringAccessor::GetString | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDynamicStringAccessor.GetString
- CDynamicStringAccessor::GetString
dev_langs:
- C++
helpviewer_keywords:
- GetString method
ms.assetid: 4af27f27-7589-49f5-93d8-6ef05c023c8a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7c6a2340ddd0e123720cd59bb2ee0bf8ca58504f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdynamicstringaccessorgetstring"></a>CDynamicStringAccessor::GetString
Recupera os dados da coluna especificada como uma cadeia de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      BaseType* GetString(DBORDINAL nColumn) const throw();  

BaseType* GetString(const CHAR* pColumnName) const throw();  

BaseType* GetString(const WCHAR* pColumnName) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `nColumn`  
 [in] O número da coluna. Coluna de números começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.  
  
 `pColumnName`  
 [in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o valor de cadeia de caracteres recuperados da coluna especificada. O valor é do tipo ***BaseType***, que será **CHAR** ou **WCHAR** dependendo se Unicode é definida ou não. Retorna NULL se a coluna especificada não foi encontrada.  
  
## <a name="remarks"></a>Comentários  
 O segundo substituir o formulário usa o nome da coluna como uma cadeia de caracteres ANSI. A terceira substituir o formulário usa o nome da coluna como uma cadeia de caracteres Unicode.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)