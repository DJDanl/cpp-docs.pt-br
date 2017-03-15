---
title: "Classe ActivationFactory | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::ActivationFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ActivationFactory"
ms.assetid: 5faddf1f-43b6-4f8a-97de-8c9d3ae1e1ff
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe ActivationFactory
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Habilita uma ou mais classes a ser ativadas por Tempo de Execução do Windows.  
  
## Sintaxe  
  
```  
template <  
   typename I0 = Details::Nil,  
   typename I1 = Details::Nil,  
   typename I2 = Details::Nil  
>  
class ActivationFactory : public Details::RuntimeClass<typename Details::InterfaceListHelper<IActivationFactory, I0, I1, I2, Details::Nil>::TypeT, RuntimeClassFlags<WinRt | InhibitWeakReference>, false>;  
```  
  
#### Parâmetros  
 `I0`  
 A interface de zeroth.  
  
 `I1`  
 A primeira interface.  
  
 `I2`  
 A segunda interface.  
  
## Comentários  
 ActivationFactory fornece métodos do registro e a funcionalidade básica da interface de IActivationFactory.  ActivationFactory também permite fornecer uma implementação personalizada de fábrica.  
  
 O seguinte fragmento de código a seguir ilustra simbolicamente como usar ActivationFactory.  
  
 [!code-cpp[wrl-microsoft__wrl__activationfactory#1](../windows/codesnippet/CPP/activationfactory-class_1.cpp)]  
  
 O seguinte fragmento de código mostra como usar a estrutura de [Implementa](../Topic/Implements%20Structure.md) para especificar mais de três IDs da interface.  
  
 `struct MyFactory : ActivationFactory<Implements<I1, I2, I3>, I4, I5>;`  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor ActivationFactory::ActivationFactory](../windows/activationfactory-activationfactory-constructor.md)|Inicializa a classe de ActivationFactory.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ActivationFactory::AddRef](../windows/activationfactory-addref-method.md)|Incrementa a contagem de referência do objeto atual de ActivationFactory.|  
|[Método ActivationFactory::GetIids](../windows/activationfactory-getiids-method.md)|Recupera uma matriz de IDs implementados da interface.|  
|[Método ActivationFactory::GetRuntimeClassName](../windows/activationfactory-getruntimeclassname-method.md)|Obtém o nome da classe de tempo de execução do objeto que o ActivationFactory atual cria uma instância do.|  
|[Método ActivationFactory::GetTrustLevel](../windows/activationfactory-gettrustlevel-method.md)|Obtém o nível de confiança do objeto que o ActivationFactory atual cria uma instância do.|  
|[Método ActivationFactory::QueryInterface](../windows/activationfactory-queryinterface-method.md)|Recupera um ponteiro para a interface especificada.|  
|[Método ActivationFactory::Release](../windows/activationfactory-release-method.md)|Diminui a contagem de referência do objeto atual de ActivationFactory.|  
  
## Hierarquia de Herança  
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
  
## Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)