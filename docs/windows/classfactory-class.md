---
title: Classe ClassFactory | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ClassFactory
dev_langs:
- C++
helpviewer_keywords:
- ClassFactory class
ms.assetid: f13e6bce-722b-4f18-b7cf-3ffa6345c1db
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6294634652ffc6a53a577ccd75c348ed63c502e7
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="classfactory-class"></a>Classe ClassFactory
Implementa a funcionalidade básica da interface IClassFactory.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename I0 = Details::Nil,  
   typename I1 = Details::Nil,  
   typename I2 = Details::Nil  
>  
class ClassFactory : public Details::RuntimeClass<  
   typename Details::InterfaceListHelper<IClassFactory,   
   I0,   
   I1,   
   I2,   
   Details::Nil>::TypeT,   
   RuntimeClassFlags<ClassicCom | InhibitWeakReference>,   
      false>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `I0`  
 A interface de zero.  
  
 `I1`  
 A primeira interface.  
  
 `I2`  
 A segunda interface.  
  
## <a name="remarks"></a>Comentários  
 Utilizar `ClassFactory` para fornecer uma implementação de fábrica definido pelo usuário.  
  
 O padrão de programação a seguir demonstra como usar o [implementa](../windows/implements-structure.md) para especificar mais de três interfaces em uma fábrica de classe.  
  
 `struct MyFactory : ClassFactory<Implements<I1, I2, I3>, I4, I5>`  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor ClassFactory::ClassFactory](../windows/classfactory-classfactory-constructor.md)||  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ClassFactory::AddRef](../windows/classfactory-addref-method.md)|Incrementa a contagem de referência para o objeto ClassFactory atual.|  
|[Método ClassFactory::LockServer](../windows/classfactory-lockserver-method.md)|Aumenta ou diminui o número de base de objetos que são controlados pelo objeto ClassFactory atual.|  
|[Método ClassFactory::QueryInterface](../windows/classfactory-queryinterface-method.md)|Recupera um ponteiro para a interface especificada pelo parâmetro.|  
|[Método ClassFactory::Release](../windows/classfactory-release-method.md)|Diminui a contagem de referência para o objeto ClassFactory atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `I0`  
  
 `ChainInterfaces`  
  
 `I0`  
  
 `RuntimeClassBase`  
  
 `ImplementsHelper`  
  
 `DontUseNewUseMake`  
  
 `RuntimeClassFlags`  
  
 `RuntimeClassBaseT`  
  
 `RuntimeClass`  
  
 `ClassFactory`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft:: wrl](../windows/microsoft-wrl-namespace.md)   
 [Enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md)