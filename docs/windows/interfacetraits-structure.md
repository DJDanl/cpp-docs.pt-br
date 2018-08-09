---
title: Estrutura InterfaceTraits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceTraits
dev_langs:
- C++
helpviewer_keywords:
- InterfaceTraits structure
ms.assetid: ede0c284-19a7-4892-9738-ff3da4923d0a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6cb96b90a069c12e65c53158717d9a89fb0aed3d
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40014094"
---
# <a name="interfacetraits-structure"></a>Estrutura InterfaceTraits
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<  
   typename I0  
>  
struct __declspec(novtable) InterfaceTraits;  
template<typename CloakedType>  
struct __declspec(novtable) InterfaceTraits<CloakedIid<CloakedType>>;  
  
template<>  
struct __declspec(novtable) InterfaceTraits<Nil>;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *I0*  
 O nome de uma interface.  
  
 *CloakedType*  
 Para `RuntimeClass`, `Implements` e `ChainInterfaces`, suporte de uma interface que não esteja na lista de IDs de interface.  
  
## <a name="remarks"></a>Comentários  
 Características comuns de implementa uma interface.  
  
 O segundo modelo é uma especialização para interfaces encobertas. O terceiro modelo é uma especialização para parâmetros Nil.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`Base`|Um sinônimo para o *I0* parâmetro de modelo.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método InterfaceTraits::CanCastTo](../windows/interfacetraits-cancastto-method.md)|Indica se o ponteiro especificado pode ser convertido em um ponteiro para `Base`.|  
|[Método InterfaceTraits::CastToBase](../windows/interfacetraits-casttobase-method.md)|Converte o ponteiro especificado para um ponteiro para `Base`.|  
|[Método InterfaceTraits::CastToUnknown](../windows/interfacetraits-casttounknown-method.md)|Converte o ponteiro especificado para um ponteiro para `IUnknown`.|  
|[Método InterfaceTraits::FillArrayWithIid](../windows/interfacetraits-fillarraywithiid-method.md)|Atribui a ID de interface do `Base` ao elemento de matriz especificado pelo argumento de índice.|  
|[Método InterfaceTraits::Verify](../windows/interfacetraits-verify-method.md)|Verifica se `Base` é derivado corretamente.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante InterfaceTraits::IidCount](../windows/interfacetraits-iidcount-constant.md)|Contém o número de IDs associadas ao atual de interface **InterfaceTraits** objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `InterfaceTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)