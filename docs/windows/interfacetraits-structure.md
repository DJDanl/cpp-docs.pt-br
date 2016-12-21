---
title: "Estrutura InterfaceTraits | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::InterfaceTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura InterfaceTraits"
ms.assetid: ede0c284-19a7-4892-9738-ff3da4923d0a
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura InterfaceTraits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template<  
   typename I0  
>  
struct __declspec(novtable) InterfaceTraits;  
  
template<  
   typename CloakedType  
>  
struct __declspec(novtable) InterfaceTraits<CloakedIid<CloakedType>>;  
  
template<>  
struct __declspec(novtable) InterfaceTraits<Nil>;  
```  
  
#### Parâmetros  
 `I0`  
 O nome de uma interface.  
  
 `CloakedType`  
 Para RuntimeClass, implementa e ChainInterfaces, que não está na lista de IDs de suporte da interface.  
  
## Comentários  
 Implementa características de uma interface comum.  
  
 O segundo modelo é uma especialização para interfaces cloaked.  O terceiro modelo é uma especialização para parâmetros de nada.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`Base`|Um sinônimo para o parâmetro do modelo de `I0` .|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método InterfaceTraits::CanCastTo](../Topic/InterfaceTraits::CanCastTo%20Method.md)|Indica se o ponteiro especificado pode ser convertido em um ponteiro para `Base`.|  
|[Método InterfaceTraits::CastToBase](../windows/interfacetraits-casttobase-method.md)|Converte o ponteiro especificado para um ponteiro para `Base`.|  
|[Método InterfaceTraits::CastToUnknown](../windows/interfacetraits-casttounknown-method.md)|Converte o ponteiro especificado para um ponteiro para IUnknown.|  
|[Método InterfaceTraits::FillArrayWithIid](../windows/interfacetraits-fillarraywithiid-method.md)|Atribui a ID da interface de `Base` ao elemento da matriz especificado pelo argumento de índice.|  
|[Método InterfaceTraits::Verify](../Topic/InterfaceTraits::Verify%20Method.md)|Verifica se a base seja derivada corretamente.|  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Constante InterfaceTraits::IidCount](../Topic/InterfaceTraits::IidCount%20Constant.md)|Contém o número de IDs de interface associados ao objeto atual de InterfaceTraits.|  
  
## Hierarquia de Herança  
 `InterfaceTraits`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)