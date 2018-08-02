---
title: Estrutura ChainInterfaces | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::ChainInterfaces
dev_langs:
- C++
helpviewer_keywords:
- ChainInterfaces structure
ms.assetid: d7415b59-5468-4bef-a3fd-8d82b12f0e9c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f16a10ef5119730fb492c4adb890aedcc09d3174
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39461527"
---
# <a name="chaininterfaces-structure"></a>Estrutura ChainInterfaces
Especifica as funções de verificação e de inicialização que podem ser aplicadas a um conjunto de IDs de interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename I0,  
   typename I1,  
   typename I2 = Details::Nil,  
   typename I3 = Details::Nil,  
   typename I4 = Details::Nil,  
   typename I5 = Details::Nil,  
   typename I6 = Details::Nil,  
   typename I7 = Details::Nil,  
   typename I8 = Details::Nil,  
   typename I9 = Details::Nil  
>  
struct ChainInterfaces : I0;  
template <  
   typename DerivedType,  
   typename BaseType,  
   bool hasImplements,  
   typename I1,  
   typename I2,  
   typename I3,  
   typename I4,  
   typename I5,  
   typename I6,  
   typename I7,  
   typename I8,  
   typename I9  
>  
struct ChainInterfaces<MixIn<DerivedType, BaseType, hasImplements>, I1, I2, I3, I4, I5, I6, I7, I8, I9>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *I0*  
 (Obrigatório) Interface ID 0.  
  
 *I1*  
 (Obrigatório) Interface ID 1.  
  
 *I2*  
 (Opcional) ID da interface 2.  
  
 *I3*  
 (Opcional) ID da interface 3.  
  
 *I4*  
 (Opcional) ID da interface 4.  
  
 *I5*  
 (Opcional) ID da interface 5.  
  
 *I6*  
 (Opcional) ID de interface 6.  
  
 *I7*  
 (Opcional) ID de interface 7.  
  
 *I8*  
 (Opcional) ID de interface 8.  
  
 *I9*  
 (Opcional) ID de interface 9.  
  
 *DerivedType*  
 Um tipo derivado.  
  
 *BaseType*  
 O tipo base de um tipo derivado.  
  
 *hasImplements*  
 Um valor booliano que, se **verdadeira**, significa que você não pode usar um [mescla](../windows/mixin-structure.md) estrutura com uma classe que deriva a [implementa](../windows/implements-structure.md) estrutura.  
  
## <a name="members"></a>Membros  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ChainInterfaces::CanCastTo](../windows/chaininterfaces-cancastto-method.md)|Indica se a ID de interface especificado pode ser convertida em cada um dos especializações definidas pelos parâmetros de modelo ChainInterface.|  
|[Método ChainInterfaces::CastToUnknown](../windows/chaininterfaces-casttounknown-method.md)|Converte o ponteiro de interface do tipo definido pelos *I0* parâmetro de modelo para um ponteiro para IUnknown.|  
|[Método ChainInterfaces::FillArrayWithIid](../windows/chaininterfaces-fillarraywithiid-method.md)|Armazena a ID de interface definida pelo *I0* parâmetro de modelo em um local especificado em uma matriz especificada de IDs de interface.|  
|[Método ChainInterfaces::Verify](../windows/chaininterfaces-verify-method.md)|Verifica se cada interface definido pelos parâmetros de modelo *I0* por meio *I9* herda `IUnknown` e/ou `IInspectable`e que *I0* herda de *I1* por meio *I9*.|  
  
### <a name="protected-constants"></a>Constantes protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante ChainInterfaces::IidCount](../windows/chaininterfaces-iidcount-constant.md)|O número total de IDs contidas nas interfaces especificadas pelos parâmetros de modelo de interface *I0* por meio *I9*.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `I0`  
  
 `ChainInterfaces`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)