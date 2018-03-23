---
title: Classe MakeAllocator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::MakeAllocator
dev_langs:
- C++
helpviewer_keywords:
- MakeAllocator class
ms.assetid: a1114615-abd7-4a56-9bc3-750c118f0fa1
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 33ba172099fd2554709cc539eeee8999c0e42cef
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="makeallocator-class"></a>Classe MakeAllocator
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
template<  
   typename T,  
   bool hasWeakReferenceSupport =   
         !__is_base_of(RuntimeClassFlags<InhibitWeakReference>, T)>
 class MakeAllocator;  
  
template<typename T>  
class MakeAllocator<T, false>;  
  
template<typename T>  
class MakeAllocator<T, true>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O nome de um tipo.  
  
 `hasWeakReferenceSupport`  
 `true` para alocar memória para um objeto que oferece suporte a referências fracas; `false` ao alocar memória para um objeto que não oferece suporte a referências fracas.  
  
## <a name="remarks"></a>Comentários  
 Aloca memória para uma classe ativável, com ou sem suporte de referência fraca.  
  
 Substitua a classe MakeAllocator para implementar um modelo de alocação de memória definido pelo usuário.  
  
 MakeAllocator normalmente é usado para impedir vazamentos de memória se gera um objeto durante a construção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor MakeAllocator::MakeAllocator](../windows/makeallocator-makeallocator-constructor.md)|Inicializa uma nova instância da classe MakeAllocator.|  
|[Destruidor MakeAllocator::~MakeAllocator](../windows/makeallocator-tilde-makeallocator-destructor.md)|Deinitializes a instância atual da classe MakeAllocator.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método MakeAllocator::Allocate](../windows/makeallocator-allocate-method.md)|Aloca memória e o associa ao objeto MakeAllocator atual.|  
|[Método MakeAllocator::Detach](../windows/makeallocator-detach-method.md)|Desassocia a memória alocada pelo [alocar](../windows/makeallocator-allocate-method.md) método do objeto MakeAllocator atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `MakeAllocator`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)