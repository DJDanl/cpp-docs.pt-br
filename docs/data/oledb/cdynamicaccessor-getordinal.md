---
title: CDynamicAccessor::GetOrdinal | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDynamicAccessor.GetOrdinal
- ATL::CDynamicAccessor::GetOrdinal
- CDynamicAccessor::GetOrdinal
- ATL.CDynamicAccessor.GetOrdinal
- GetOrdinal
dev_langs:
- C++
helpviewer_keywords:
- GetOrdinal method
ms.assetid: 2095b71c-a7a4-4034-89a1-77a78cb9633f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 423dd0757123f6c62a3a8f794e04772e370716b7
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cdynamicaccessorgetordinal"></a>CDynamicAccessor::GetOrdinal
Recupera o número de coluna recebe um nome de coluna.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      bool GetOrdinal(const CHAR* pColumnName,  
   DBORDINAL* pOrdinal) const throw();  

bool GetOrdinal(const WCHAR* pColumnName,  
   DBORDINAL* pOrdinal) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pColumnName`  
 [in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.  
  
 *pOrdinal*  
 [out] Um ponteiro para o número da coluna.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna **true** se uma coluna com o nome especificado for encontrada. Caso contrário, essa função retorna **false**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)