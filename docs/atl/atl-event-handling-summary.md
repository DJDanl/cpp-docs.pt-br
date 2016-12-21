---
title: "Resumo de manipula&#231;&#227;o de eventos do ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "eventos de manipulação, Implementando"
ms.assetid: e8b47ef0-0bdc-47ff-9dd6-34df11dde9a2
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Resumo de manipula&#231;&#227;o de eventos do ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em geral, a manipulação de eventos COM é um processo relativamente simple. Há três etapas principais:  
  
-   Implemente a interface de eventos em seu objeto.  
  
-   A origem do evento de aviso que o objeto deseja receber eventos.  
  
-   Não recomendar a origem do evento quando o objeto não precisa receber eventos.  
  
## Implementando a Interface  
 Há quatro maneiras principais de implementação de uma interface usando ATL.  
  
|Derivar de|Adequado para o tipo de Interface|Exige que você implementar todos os métodos \*|Requer uma biblioteca de tipos em tempo de execução|  
|----------------|---------------------------------------|----------------------------------------------------|---------------------------------------------------------|  
|A interface|Vtable|Sim|Não|  
|[IDispatchImpl](../atl/reference/idispatchimpl-class.md)|Dual|Sim|Sim|  
|[IDispEventImpl](../atl/reference/idispeventimpl-class.md)|Dispinterface|Não|Sim|  
|[IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md)|Dispinterface|Não|Não|  
  
 \* Ao usar classes de suporte ATL, você nunca precisa implementar o **IUnknown** ou `IDispatch` métodos manualmente.  
  
## Orientando e Unadvising a origem do evento  
 Há três maneiras principais de aconselhar e unadvising uma origem de evento usando ATL.  
  
|Função de aviso|Não recomendar a função|Mais adequado para uso com|Requer que você mantenha o controle de um cookie?|Comentários|  
|---------------------|-----------------------------|--------------------------------|-------------------------------------------------------|-----------------|  
|[AtlAdvise](../Topic/AtlAdvise.md), [CComPtrBase::Advise](../Topic/CComPtrBase::Advise.md)|[AtlUnadvise](../Topic/AtlUnadvise.md)|Vtable ou interfaces duplas|Sim|`AtlAdvise` é uma função global do ATL.`CComPtrBase::Advise` é usado pelo [CComPtr](../atl/reference/ccomptr-class.md) e [CComQIPtr](../atl/reference/ccomqiptr-class.md).|  
|[IDispEventSimpleImpl::DispEventAdvise](../Topic/IDispEventSimpleImpl::DispEventAdvise.md)|[IDispEventSimpleImpl::DispEventUnadvise](../Topic/IDispEventSimpleImpl::DispEventUnadvise.md)|[IDispEventImpl](../atl/reference/idispeventimpl-class.md) ou [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md)|Não|Menos parâmetros que `AtlAdvise` como a classe base mais funciona.|  
|[CComCompositeControl::AdviseSinkMap\(TRUE\)](../Topic/CComCompositeControl::AdviseSinkMap.md)|[CComCompositeControl::AdviseSinkMap\(FALSE\)](../Topic/CComCompositeControl::AdviseSinkMap.md)|Controles ActiveX em controles compostos|Não|`CComCompositeControl::AdviseSinkMap` recomenda que todas as entradas de coletor de eventos de mapa. A mesma função unadvises as entradas. Este método é chamado automaticamente pelo `CComCompositeControl` classe.|  
|[CAxDialogImpl::AdviseSinkMap\(TRUE\)](../Topic/CAxDialogImpl::AdviseSinkMap.md)|[CAxDialogImpl::AdviseSinkMap\(FALSE\)](../Topic/CAxDialogImpl::AdviseSinkMap.md)|Controles ActiveX em uma caixa de diálogo|Não|`CAxDialogImpl::AdviseSinkMap` avisa e unadvises todos os controles ActiveX no recurso de caixa de diálogo. Isso é feito automaticamente para você.|  
  
## Consulte também  
 [Manipulação de eventos](../Topic/Event%20Handling%20and%20ATL.md)   
 [Suporte IDispEventImpl](../atl/supporting-idispeventimpl.md)