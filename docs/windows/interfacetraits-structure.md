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
ms.openlocfilehash: 4203fbb639b06e7e421809f9d901c70933d586d1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="interfacetraits-structure"></a>Estrutura InterfaceTraits
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<  
   typename I0  
>  
struct __declspec(novtable) InterfaceTraits;  
template<typename CloakedType>  
struct __declspec(novtable) InterfaceTraits<CloakedIid<CloakedType>>;  
  
template<>  
struct __declspec(novtable) InterfaceTraits<Nil>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `I0`  
 O nome de uma interface.  
  
 `CloakedType`  
 Para RuntimeClass, implementa e ChainInterfaces, uma interface que não seja na lista de suporte para as IDs de interface.  
  
## <a name="remarks"></a>Comentários  
 Características em comum implementa uma interface.  
  
 O segundo é uma especialização de interfaces encobertos. O terceiro modelo é uma especialização de parâmetros Nil.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`Base`|Um sinônimo para o `I0` parâmetro do modelo.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método InterfaceTraits::CanCastTo](../windows/interfacetraits-cancastto-method.md)|Indica se o ponteiro especificado pode ser convertido em um ponteiro para `Base`.|  
|[Método InterfaceTraits::CastToBase](../windows/interfacetraits-casttobase-method.md)|Converte o ponteiro especificado para um ponteiro para `Base`.|  
|[Método InterfaceTraits::CastToUnknown](../windows/interfacetraits-casttounknown-method.md)|Converte o ponteiro especificado para um ponteiro IUnknown.|  
|[Método InterfaceTraits::FillArrayWithIid](../windows/interfacetraits-fillarraywithiid-method.md)|Atribui a ID de interface de `Base` ao elemento de matriz especificado pelo argumento de índice.|  
|[Método InterfaceTraits::Verify](../windows/interfacetraits-verify-method.md)|Verifica que Base é derivada corretamente.|  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante InterfaceTraits::IidCount](../windows/interfacetraits-iidcount-constant.md)|Contém o número da interface que IDs associadas com o objeto de InterfaceTraits atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `InterfaceTraits`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)