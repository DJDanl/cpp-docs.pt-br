---
title: Método CompareStringOrdinal | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Details::CompareStringOrdinal
dev_langs:
- C++
ms.assetid: ffa997fd-8cd7-40a5-b9e7-f55d40b072f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e3abf87340671d1ac4851b055a57896e340d0c20
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33860805"
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