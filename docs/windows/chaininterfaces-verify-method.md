---
title: 'Método Chaininterfaces: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::ChainInterfaces::Verify
dev_langs:
- C++
helpviewer_keywords:
- Verify method
ms.assetid: c591e130-8686-4130-ba69-1aaedc250038
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c83479434a936f32fb0f7367d8cd02c6676c74e7
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33860688"
---
# <a name="chaininterfacesverify-method"></a>Método ChainInterfaces::Verify
Verifica se cada interface definidos pelos parâmetros de modelo `I0` por meio de `I9` herda de IUnknown e/ou IInspectable que `I0` herda de `I1` por meio de `I9`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW __forceinline static void Verify();  
```  
  
## <a name="remarks"></a>Comentários  
 Se a operação de verificação falhar, um `static_assert` emite uma mensagem de erro que descreve a falha.  
  
## <a name="remarks"></a>Comentários  
 Parâmetros de modelo `I0` e `I1` são necessários e os parâmetros `I2` por meio de `I9` são opcionais.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)