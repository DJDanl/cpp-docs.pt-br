---
title: "Método CompareStringOrdinal | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::Details::CompareStringOrdinal
dev_langs: C++
ms.assetid: ffa997fd-8cd7-40a5-b9e7-f55d40b072f4
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0c7e83d78bd311d7a3bfcba0cbe1a092c6c1c46b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comparestringordinal-method"></a>Método CompareStringOrdinal
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline INT32 CompareStringOrdinal(  
   HSTRING lhs,   
   HSTRING rhs)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `lhs`  
 A primeira HSTRING para comparar.  
  
 `rhs`  
 O segundo HSTRING para comparar.  
  
## <a name="return-value"></a>Valor de retorno  
  
|Valor|Condição|  
|-----------|---------------|  
|-1|`lhs` é menor que `rhs`.|  
|0|`lhs` é igual a `rhs`.|  
|1|`lhs` é maior que `rhs`.|  
  
## <a name="remarks"></a>Comentários  
 Compara dois objetos HSTRING especificados e retorna um inteiro que indica sua posição relativa em uma ordem de classificação.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)