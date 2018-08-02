---
title: Classe ActivationFactory | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ActivationFactory
dev_langs:
- C++
helpviewer_keywords:
- ActivationFactory class
ms.assetid: 5faddf1f-43b6-4f8a-97de-8c9d3ae1e1ff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 18ce213d6c4bedd0bcaa2be1af33281ae69f6ad1
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39461499"
---
# <a name="activationfactory-class"></a>Classe ActivationFactory
Permite que um ou mais classes sejam ativadas pelo tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename I0 = Details::Nil,  
   typename I1 = Details::Nil,  
   typename I2 = Details::Nil  
>  
class ActivationFactory : public Details::RuntimeClass<typename Details::InterfaceListHelper<IActivationFactory, I0, I1, I2, Details::Nil>::TypeT, RuntimeClassFlags<WinRt | InhibitWeakReference>, false>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *I0*  
 A interface inicial.  
  
 *I1*  
 A primeira interface.  
  
 *I2*  
 A segunda interface.  
  
## <a name="remarks"></a>Comentários  
 **ActivationFactory** fornece métodos de registro e a funcionalidade básica para o `IActivationFactory` interface. **ActivationFactory** também permite que você forneça uma implementação de fábrica personalizada.  
  
 O fragmento de código a seguir simbolicamente ilustra como usar ActivationFactory.  
  
 [!code-cpp[wrl-microsoft__wrl__activationfactory#1](../windows/codesnippet/CPP/activationfactory-class_1.cpp)]  
  
 O fragmento de código a seguir mostra como usar o [implementa](../windows/implements-structure.md) estrutura para especificar mais de três IDs de interface.  
  
 `struct MyFactory : ActivationFactory<Implements<I1, I2, I3>, I4, I5>;`  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor ActivationFactory::ActivationFactory](../windows/activationfactory-activationfactory-constructor.md)|Inicializa o **ActivationFactory** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método ActivationFactory::AddRef](../windows/activationfactory-addref-method.md)|Incrementa a contagem de referência do atual **ActivationFactory** objeto.|  
|[Método ActivationFactory::GetIids](../windows/activationfactory-getiids-method.md)|Recupera uma matriz de IDs de interface implementada.|  
|[Método ActivationFactory::GetRuntimeClassName](../windows/activationfactory-getruntimeclassname-method.md)|Obtém o nome de classe de tempo de execução do objeto que o atual **ActivationFactory** cria uma instância.|  
|[Método ActivationFactory::GetTrustLevel](../windows/activationfactory-gettrustlevel-method.md)|Obtém o nível de confiança do objeto que instancia o ActivationFactory atual.|  
|[Método ActivationFactory::QueryInterface](../windows/activationfactory-queryinterface-method.md)|Recupera um ponteiro para a interface especificada.|  
|[Método ActivationFactory::Release](../windows/activationfactory-release-method.md)|Diminui a contagem de referência do atual **ActivationFactory** objeto.|  
  
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
  
 `ActivationFactory`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)