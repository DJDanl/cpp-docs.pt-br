---
title: "Classe DeferrableEventArgs | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: ece89267-7b72-40e1-8185-550c865b070a
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe DeferrableEventArgs
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de modelo usada para os tipos de argumento do evento para adiamentos.  
  
## Sintaxe  
  
```cpp  
template <  
typename TEventArgsInterface,  
typename TEventArgsClass  
>  
class DeferrableEventArgs : public TEventArgsInterface  
  
```  
  
#### Parâmetros  
 `TEventArgsInterface`  
 O tipo de interface que declara os argumentos para um evento adiado.  
  
 `TEventArgsClass`  
 A classe que implementa `TEventArgsInterface`.  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método DeferrableEventArgs::GetDeferral](../windows/deferrableeventargs-getdeferral-method.md)|Obtém uma referência para o [adiamento](http://go.microsoft.com/fwlink/?LinkId=526520) objeto que representa um evento adiado.|  
|[Método DeferrableEventArgs::InvokeAllFinished](../windows/deferrableeventargs-invokeallfinished-method.md)|Chamado para indicar que todo o processamento para manipular um evento adiado foi concluído.|  
  
## Comentários  
 As instâncias dessa classe são passadas para manipuladores de eventos para eventos adiados.  Os parâmetros de modelo representam uma interface que define os detalhes dos argumentos do evento para um tipo específico de evento adiado e uma classe que implementa a interface.  
  
 A classe é exibido como o primeiro argumento para um manipulador de eventos para um evento adiado.  Você pode chamar o [GetDeferral](../windows/deferrableeventargs-getdeferral-method.md) método para obter o [adiamento](http://go.microsoft.com/fwlink/?LinkId=526520) objeto do qual você pode obter todas as informações sobre o evento adiado.  Depois de concluir a manipulação de eventos, você deve chamar Complete no objeto de adiamento.  Você deve chamar [InvokeAllFinished](../windows/deferrableeventargs-invokeallfinished-method.md) no final do método do manipulador de eventos, que garante que a conclusão dos eventos adiados tudo é comunicada corretamente.  
  
## Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)