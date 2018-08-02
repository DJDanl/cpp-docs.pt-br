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
ms.openlocfilehash: 58e808510868e375672ee5de0b27c4bed3c568e0
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39464045"
---
# <a name="comparestringordinal-method"></a>Método CompareStringOrdinal
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline INT32 CompareStringOrdinal(  
   HSTRING lhs,   
   HSTRING rhs)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *LHS*  
 O HSTRING primeiro a ser comparado.  
  
 *rhs*  
 O segundo HSTRING para comparar.  
  
## <a name="return-value"></a>Valor de retorno  
  
|Valor|Condição|  
|-----------|---------------|  
|-1|*LHS* é menor que *rhs*.|  
|0|*LHS* é igual a *rhs*.|  
|1|*LHS* é maior que *rhs*.|  
  
## <a name="remarks"></a>Comentários  
 Compara dois objetos HSTRING especificados e retorna um inteiro que indica sua posição relativa em uma ordem de classificação.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)