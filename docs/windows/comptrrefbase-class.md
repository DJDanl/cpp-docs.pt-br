---
title: "Classe ComPtrRefBase | Microsoft Docs"
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
  - "client/Microsoft::WRL::Details::ComPtrRefBase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ComPtrRefBase"
ms.assetid: 6d344c1a-cc13-4a3f-8a0d-f167ccb9348f
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe ComPtrRefBase
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template <  
   typename T  
>  
class ComPtrRefBase;  
```  
  
#### Parâmetros  
 `T`  
 Um tipo de [ComPtr\<T\>](../windows/comptr-class.md) ou um tipo derivado deles, não apenas a interface representada pelo ComPtr.  
  
## Comentários  
 Representa a classe base da classe de [ComPtrRef](../Topic/ComPtrRef%20Class.md) .  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`InterfaceType`|Um sinônimo para o tipo de parâmetro `T`do modelo.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ComPtrRefBase::operator Operador IInspectable\*\*](../windows/comptrrefbase-operator-iinspectable-star-star-operator.md)|Converte o membro de dados atual de [ptr\_](../windows/comptrrefbase-ptr-data-member.md) à ponteiro\-à\-um\-ponteiro\- à interface de IInspectable.|  
|[ComPtrRefBase::operator IUnknown\*\* Operador](../windows/comptrrefbase-operator-iunknown-star-star-operator.md)|Converte o membro de dados atual de [ptr\_](../windows/comptrrefbase-ptr-data-member.md) à ponteiro\-à\-um\-ponteiro\- à interface IUnknown.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados ComPtrRefBase::ptr\_](../windows/comptrrefbase-ptr-data-member.md)|Ponteiro para o tipo especificado pelo parâmetro atual do modelo.|  
  
## Hierarquia de Herança  
 `ComPtrRefBase`  
  
## Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)