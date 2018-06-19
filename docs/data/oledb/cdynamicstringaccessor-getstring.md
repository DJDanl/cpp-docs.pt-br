---
title: 'Cdynamicstringaccessor:: GetString | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDynamicStringAccessor.GetString
- CDynamicStringAccessor::GetString
dev_langs:
- C++
helpviewer_keywords:
- GetString method
ms.assetid: 4af27f27-7589-49f5-93d8-6ef05c023c8a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: cc23fe73eb0d804d0b53950885b1b83aba58ff91
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33096542"
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