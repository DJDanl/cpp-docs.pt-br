---
title: "Classe WeakReference | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::WeakReference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe WeakReference"
ms.assetid: 3f4c956b-dbbd-49b1-8cfa-9509a9956c97
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe WeakReference
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
class WeakReference;  
```  
  
## Comentários  
 Representa *uma referência de URL* que pode ser usada com tempos de Execução do Windows ou COM clássico.  Uma referência de objeto representa um que pode ou não ser acessível.  
  
 Um objeto de `WeakReference` mantém *uma referência forte*, que é um ponteiro para um objeto, e *uma contagem forte de referência*, que é o número de cópias de referência forte que foram distribuídas pelo método de resolução \(\).  Quando a contagem forte de referência seja diferente de zero, a referência forte é válido e o objeto está acessível.  Quando a contagem de referência forte se tornará zero, a referência forte não é válida e o objeto está inacessível.  
  
 Um objeto de WeakReference normalmente é usado para representar um objeto cuja existente é controlada por um thread ou por um aplicativo externo.  Por exemplo, construir um objeto de WeakReference de uma referência a um objeto de arquivo.  Quando o arquivo estiver aberto, a referência forte é válido.  Mas se o arquivo é fechado, a referência forte torna\-se inválido.  
  
 Os métodos de WeakReference são thread\-safe.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor WeakReference::WeakReference](../windows/weakreference-weakreference-constructor.md)|Inicializa uma nova instância da classe de WeakReference.|  
|[Destruidor WeakReference::~WeakReference](../windows/weakreference-tilde-weakreference-destructor.md)|Deinitializes \(destruir\) a instância atual da classe de WeakReference.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método WeakReference::DecrementStrongReference](../Topic/WeakReference::DecrementStrongReference%20Method.md)|Forte do diminuirá a contagem de referência do objeto atual de WeakReference.|  
|[Método WeakReference::IncrementStrongReference](../windows/weakreference-incrementstrongreference-method.md)|Forte incrementa a contagem de referência do objeto atual de WeakReference.|  
|[Método WeakReference::Resolve](../windows/weakreference-resolve-method.md)|Define o ponteiro especificado ao valor de referência forte atual se a contagem forte de referência for diferente de zero.|  
|[Método WeakReference::SetUnknown](../windows/weakreference-setunknown-method.md)|Define a referência forte do objeto atual de WeakReference especificado para o ponteiro da interface.|  
  
## Hierarquia de Herança  
 `WeakReference`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)