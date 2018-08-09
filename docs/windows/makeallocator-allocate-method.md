---
title: 'Método makeallocator:: allocate | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::MakeAllocator::Allocate
dev_langs:
- C++
helpviewer_keywords:
- Allocate method
ms.assetid: a01997bc-4ff1-4ed0-9def-e4aaa15b0598
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3252096216757c34e93933bcdd91f9da2c5bb14f
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40015963"
---
# <a name="makeallocatorallocate-method"></a>Método MakeAllocator::Allocate
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
__forceinline void* Allocate();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um ponteiro para a memória alocada; Caso contrário, **nullptr**.  
  
## <a name="remarks"></a>Comentários  
 Aloca memória e o associa ao atual **MakeAllocator** objeto.  
  
 O tamanho da memória alocada é o tamanho do tipo especificado pelo atual **MakeAllocator** parâmetro de modelo.  
  
 Um desenvolvedor precisar substituir apenas a **Allocate()** método para implementar um modelo de alocação de memória diferentes.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe MakeAllocator](../windows/makeallocator-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)