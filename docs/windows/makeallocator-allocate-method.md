---
title: 'Método Makeallocator: | Microsoft Docs'
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
ms.openlocfilehash: d0e8d387dea7687ad61d85f975d58aa47489266d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33876209"
---
# <a name="makeallocatorallocate-method"></a>Método MakeAllocator::Allocate
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__forceinline void* Allocate();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um ponteiro para a memória alocada; Caso contrário, `nullptr`.  
  
## <a name="remarks"></a>Comentários  
 Aloca memória e o associa ao objeto MakeAllocator atual.  
  
 O tamanho da memória alocada é o tamanho do tipo especificado pelo parâmetro de modelo MakeAllocator atual.  
  
 Um desenvolvedor precisa substituir apenas o método Allocate() para implementar um modelo de alocação de memória diferentes.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe MakeAllocator](../windows/makeallocator-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)