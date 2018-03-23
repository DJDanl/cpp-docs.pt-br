---
title: 'Método: Casttobase | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceTraits::CastToBase
dev_langs:
- C++
helpviewer_keywords:
- CastToBase method
ms.assetid: 0591a017-0adf-4358-b946-eb0a307ce7f2
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6817f83d40943b871327c56fac692d9a60163de2
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="interfacetraitscasttobase-method"></a>Método InterfaceTraits::CastToBase
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T>  
static __forceinline Base* CastToBase(  
   _In_ T* ptr  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de parâmetro `ptr`.  
  
 `ptr`  
 Ponteiro para um tipo `T`.  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para `Base`.  
  
## <a name="remarks"></a>Comentários  
 Converte o ponteiro especificado para um ponteiro para `Base`.  
  
 Para obter mais informações sobre `Base`, consulte a seção de Typedefs públicos em [estrutura InterfaceTraits](../windows/interfacetraits-structure.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)