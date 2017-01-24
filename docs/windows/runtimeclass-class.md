---
title: "Classe RuntimeClass | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "implements/Microsoft::WRL::RuntimeClass"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe RuntimeClass"
ms.assetid: d52f9d1a-98e5-41f2-a143-8fb629dd0727
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe RuntimeClass
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa uma classe instanciada que herda o número especificado de interfaces e fornece o [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]especificado, COM clássico e suporte fraco de referência.  
  
 Você normalmente deriva seus tipos de WRL do `RuntimeClass` porque essa classe implementa `AddRef`, `Release`, e `QueryInterface`, e ajuda a gerenciar a contagem geral de referência do módulo.  
  
## Sintaxe  
  
```  
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
class RuntimeClass : public Details::RuntimeClass<typename Details::InterfaceListHelper<I0, I1, I2, I3, I4, I5, I6, I7, I8, I9>::TypeT, RuntimeClassFlags<WinRt>>;  
  
template <  
   unsigned int classFlags,  
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
class RuntimeClass<RuntimeClassFlags<classFlags>, I0, I1, I2, I3, I4, I5, I6, I7, I8> : public Details::RuntimeClass<typename Details::InterfaceListHelper<I0, I1, I2, I3, I4, I5, I6, I7, I8>::TypeT, RuntimeClassFlags<classFlags> >;  
```  
  
#### Parâmetros  
 `I0`  
 A ID de interface número zero. \(Obrigatório\)  
  
 `I1`  
 A primeira ID de interface. \(Opcional\)  
  
 `I2`  
 A segunda ID de interface. \(Opcional\)  
  
 `I3`  
 A terceira ID de interface. \(Opcional\)  
  
 `I4`  
 A quarta ID de interface. \(Opcional\)  
  
 `I5`  
 A quinta ID de interface. \(Opcional\)  
  
 `I6`  
 A sexta ID de interface. \(Opcional\)  
  
 `I7`  
 A sétima ID de interface. \(Opcional\)  
  
 `I8`  
 A oitava ID de interface. \(Opcional\)  
  
 `I9`  
 A nona ID de interface. \(Opcional\)  
  
 `classFlags`  
 Uma combinação de uma ou mais valores de enumeração [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) .  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor RuntimeClass::RuntimeClass](../windows/runtimeclass-runtimeclass-constructor.md)|Inicializa a instância atual da classe RuntimeClass.|  
|[Destruidor RuntimeClass::~RuntimeClass](../windows/runtimeclass-tilde-runtimeclass-destructor.md)|Cancela a inicialização da instância atual da classe RuntimeClass.|  
  
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
  
 `RuntimeClass`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)