---
title: 'Método interfacetraits:: Casttounknown | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceTraits::CastToUnknown
dev_langs:
- C++
helpviewer_keywords:
- CastToUnknown method
ms.assetid: aca47fa0-3c60-47f2-a73c-258f7160adff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bdb87fe43b5cc6a5d2c141ac534e3b5e781f91e8
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40019911"
---
# <a name="interfacetraitscasttounknown-method"></a>Método InterfaceTraits::CastToUnknown
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename T>  
static __forceinline IUnknown* CastToUnknown(  
   _In_ T* ptr  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 O tipo do parâmetro *ptr*.  
  
 *ptr*  
 Ponteiro para o tipo *T*.  
  
## <a name="return-value"></a>Valor de retorno  
 Ponteiro para o IUnknown do qual `Base` é derivado.  
  
## <a name="remarks"></a>Comentários  
 Converte o ponteiro especificado para um ponteiro para `IUnknown`.  
  
 Para obter mais informações sobre `Base`, consulte a seção Typedefs públicos [estrutura InterfaceTraits](../windows/interfacetraits-structure.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)