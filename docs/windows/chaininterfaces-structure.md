---
title: "Estrutura ChainInterfaces | Microsoft Docs"
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
  - "implements/Microsoft::WRL::ChainInterfaces"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura ChainInterfaces"
ms.assetid: d7415b59-5468-4bef-a3fd-8d82b12f0e9c
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura ChainInterfaces
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica as funções de verificação e inicialização que podem ser aplicadas a um conjunto de IDs da interface.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `I0`  
 ID \(obrigatório\) 0 da interface.  
  
 `I1`  
 ID \(obrigatório\) 1. da interface.  
  
 `I2`  
 \(Opcional\) ID 2. da interface.  
  
 `I3`  
 \(Opcional\) ID 3. da interface.  
  
 `I4`  
 \(Opcional\) ID 4. da interface.  
  
 `I5`  
 \(Opcional\) ID 5. da interface.  
  
 `I6`  
 \(Opcional\) ID 6. da interface.  
  
 `I7`  
 \(Opcional\) ID 7. da interface.  
  
 `I8`  
 \(Opcional\) ID 8. da interface.  
  
 `I9`  
 \(Opcional\) ID 9. da interface.  
  
 `DerivedType`  
 Um tipo derivado.  
  
 `BaseType`  
 O tipo de base de um tipo derivado.  
  
 `hasImplements`  
 Um valor booliano que se `true`, significa que você não pode usar uma estrutura de [MixIn](../windows/mixin-structure.md) com uma classe que não deriva da estrutura de [Implementa](../Topic/Implements%20Structure.md) .  
  
## Membros  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ChainInterfaces::CanCastTo](../Topic/ChainInterfaces::CanCastTo%20Method.md)|Indica se a ID de interface pode ser convertido em cada uma das especializações definidas pelos parâmetros do modelo de ChainInterface.|  
|[Método ChainInterfaces::CastToUnknown](../windows/chaininterfaces-casttounknown-method.md)|Converte o ponteiro de interface do tipo definido pelo parâmetro do modelo de `I0` a um ponteiro para IUnknown.|  
|[Método ChainInterfaces::FillArrayWithIid](../Topic/ChainInterfaces::FillArrayWithIid%20Method.md)|Armazena a ID da interface definido pelo parâmetro do modelo de `I0` em um local especificado de uma matriz especificada de IDs da interface.|  
|[Método ChainInterfaces::Verify](../windows/chaininterfaces-verify-method.md)|Verifica se cada interface definida por `I0` parâmetros do modelo com `I9` herde IUnknown e\/ou de IInspectable, e que `I0` herda de `I1` com `I9`.|  
  
### Constantes protegidas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Constante ChainInterfaces::IidCount](../windows/chaininterfaces-iidcount-constant.md)|O número total de IDs de interface contidos nas interfaces especificadas por `I0` parâmetros do modelo com `I9`.|  
  
## Hierarquia de Herança  
 `I0`  
  
 `ChainInterfaces`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)