---
title: Implementa estrutura | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Implements
dev_langs:
- C++
helpviewer_keywords:
- Implements structure
ms.assetid: 29b13e90-34d4-4a0b-babd-5187c9eb0c36
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 31b95901f2c0b7ff210cc8542dce49991a9eef87
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40014812"
---
# <a name="implements-structure"></a>Implementa estrutura
Implementa `QueryInterface` e `GetIid` para interfaces especificadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <  
   typename I0,  
   typename I1 = Details::Nil,  
   typename I2 = Details::Nil,  
   typename I3 = Details::Nil,  
   typename I4 = Details::Nil,  
   typename I5 = Details::Nil,  
   typename I6 = Details::Nil,  
   typename I7 = Details::Nil,  
   typename I8 = Details::Nil,  
   typename I9 = Details::Nil  
>  
struct __declspec(novtable) Implements : Details::ImplementsHelper<RuntimeClassFlags<WinRt>, typename Details::InterfaceListHelper<I0, I1, I2, I3, I4, I5, I6, I7, I8, I9>::TypeT>, Details::ImplementsBase;  
template <  
   int flags,  
   typename I0,  
   typename I1,  
   typename I2,  
   typename I3,  
   typename I4,  
   typename I5,  
   typename I6,  
   typename I7,  
   typename I8  
>  
struct __declspec(novtable) Implements<RuntimeClassFlags<flags>, I0, I1, I2, I3, I4, I5, I6, I7, I8> : Details::ImplementsHelper<RuntimeClassFlags<flags>, typename Details::InterfaceListHelper<I0, I1, I2, I3, I4, I5, I6, I7, I8>::TypeT>, Details::ImplementsBase;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *I0*  
 A ID de interface inicial. (Obrigatório)  
  
 *I1*  
 A primeira ID de interface. (Opcional)  
  
 *I2*  
 A segunda ID de interface. (Opcional)  
  
 *I3*  
 A terceira ID de interface. (Opcional)  
  
 *I4*  
 A quarta ID de interface. (Opcional)  
  
 *I5*  
 A quinta ID de interface. (Opcional)  
  
 *I6*  
 A sexta ID de interface. (Opcional)  
  
 *I7*  
 A sétima ID de interface. (Opcional)  
  
 *I8*  
 A ID de interface do oitavo. (Opcional)  
  
 *I9*  
 A nona ID de interface. (Opcional)  
  
 *flags*  
 Sinalizadores de configuração para a classe. Um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumerações que são especificadas em uma [RuntimeClassFlags](../windows/runtimeclassflags-structure.md) estrutura.  
  
## <a name="remarks"></a>Comentários  
 Deriva da lista de interfaces especificadas e implementa os modelos de auxiliar para `QueryInterface` e `GetIid`.  
  
 Cada *I0* por meio *I9* parâmetro interface deve derivar do `IUnknown`, `IInspectable`, ou o [ChainInterfaces](../windows/chaininterfaces-structure.md) modelo. O *sinalizadores* parâmetro determina se o suporte é gerado para `IUnknown` ou `IInspectable`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`ClassFlags`|Um sinônimo de `RuntimeClassFlags<WinRt>`.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Implements::CanCastTo](../windows/implements-cancastto-method.md)|Obtém um ponteiro para a interface especificada.|  
|[Método Implements::CastToUnknown](../windows/implements-casttounknown-method.md)|Obtém um ponteiro para subjacente `IUnknown` interface.|  
|[Método Implements::FillArrayWithIid](../windows/implements-fillarraywithiid-method.md)|Insere a ID de interface especificada pelo parâmetro de modelo inicial atual para o elemento da matriz especificada.|  
  
### <a name="protected-constants"></a>Constantes protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante Implements::IidCount](../windows/implements-iidcount-constant.md)|Contém o número de IDs de interface implementada.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `I0`  
  
 `ChainInterfaces`  
  
 `I0`  
  
 `ImplementsBase`  
  
 `ImplementsHelper`  
  
 `Implements`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)