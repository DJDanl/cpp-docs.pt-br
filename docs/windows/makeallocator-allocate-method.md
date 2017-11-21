---
title: "Método Makeallocator: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::MakeAllocator::Allocate
dev_langs: C++
helpviewer_keywords: Allocate method
ms.assetid: a01997bc-4ff1-4ed0-9def-e4aaa15b0598
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 997386e42851c6d4e15aceac006b4e27eea35c44
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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