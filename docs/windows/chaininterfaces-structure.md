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
ms.openlocfilehash: 18814a4ad87cefa39201d369926c0778931d4d64
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33861130"
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
 `I0`  
 (Obrigatório) Interface ID 0.  
  
 `I1`  
 (Obrigatório) Interface ID 1.  
  
 `I2`  
 (Opcional) Interface ID 2.  
  
 `I3`  
 (Opcional) ID de interface 3.  
  
 `I4`  
 (Opcional) ID da interface 4.  
  
 `I5`  
 (Opcional) ID de interface 5.  
  
 `I6`  
 (Opcional) Interface ID 6.  
  
 `I7`  
 (Opcional) Interface ID 7.  
  
 `I8`  
 (Opcional) ID de interface 8.  
  
 `I9`  
 (Opcional) ID de interface 9.  
  
 `DerivedType`  
 Um tipo derivado.  
  
 `BaseType`  
 O tipo base de um tipo derivado.  
  
 `hasImplements`  
 Um valor booleano que se `true`, significa que você não pode usar um [mesclado](../windows/mixin-structure.md) estrutura com uma classe que não derivam de [implementa](../windows/implements-structure.md) estrutura.  
  
## <a name="members"></a>Membros  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ChainInterfaces::CanCastTo](../windows/chaininterfaces-cancastto-method.md)|Indica se a ID de interface especificado pode ser convertida em cada uma das especializações definidas pelos parâmetros de modelo ChainInterface.|  
|[Método ChainInterfaces::CastToUnknown](../windows/chaininterfaces-casttounknown-method.md)|Converte o ponteiro de interface do tipo definido pelo `I0` parâmetro de modelo para um ponteiro IUnknown.|  
|[Método ChainInterfaces::FillArrayWithIid](../windows/chaininterfaces-fillarraywithiid-method.md)|Armazena a ID de interface definida pelo `I0` parâmetro do modelo em um local especificado em um conjunto especificado de IDs de interface.|  
|[Método ChainInterfaces::Verify](../windows/chaininterfaces-verify-method.md)|Verifica se cada interface definidos pelos parâmetros de modelo `I0` por meio de `I9` herda de IUnknown e/ou IInspectable que `I0` herda de `I1` por meio de `I9`.|  
  
### <a name="protected-constants"></a>Constantes protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante ChainInterfaces::IidCount](../windows/chaininterfaces-iidcount-constant.md)|O número total de IDs contidos nas interfaces de especificados pelos parâmetros de modelo de interface `I0` por meio de `I9`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `I0`  
  
 `ChainInterfaces`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)