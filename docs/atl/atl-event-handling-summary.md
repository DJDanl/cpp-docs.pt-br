---
title: Resumo de manipulação de eventos ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- event handling, implementing
ms.assetid: e8b47ef0-0bdc-47ff-9dd6-34df11dde9a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a938bd072ea8df30e64cce28fbf0709f08547d28
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="atl-event-handling-summary"></a>Resumo de manipulação de eventos do ATL
Em geral, a manipulação de eventos COM é um processo relativamente simples. Há três etapas principais:  
  
-   Implemente a interface de eventos em seu objeto.  
  
-   A origem do evento de aviso que o objeto deseja receber eventos.  
  
-   Unadvise a origem do evento quando o objeto não precisa receber eventos.  
  
## <a name="implementing-the-interface"></a>Implementando a Interface  
 Há quatro principais maneiras de implementar uma interface usando ATL.  
  
|Derivar de|Adequado para o tipo de Interface|Exige que você implementar todos os métodos *|Requer uma biblioteca de tipos em tempo de execução|  
|-----------------|---------------------------------|---------------------------------------------|-----------------------------------------|  
|A interface|Vtable|Sim|Não|  
|[IDispatchImpl](../atl/reference/idispatchimpl-class.md)|Duplo|Sim|Sim|  
|[IDispEventImpl](../atl/reference/idispeventimpl-class.md)|Dispinterface|Não|Sim|  
|[IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md)|Dispinterface|Não|Não|  
  
 \* Ao usar as classes de suporte ATL, nunca são necessários para implementar o **IUnknown** ou `IDispatch` métodos manualmente.  
  
## <a name="advising-and-unadvising-the-event-source"></a>Orientando e Unadvising a origem do evento  
 Há três maneiras principais de informando e unadvising uma origem de evento usando a ATL.  
  
|Função de aviso|Unadvise função|Mais adequado para uso com|Exige que você mantenha o controle de um cookie|Comentários|  
|---------------------|-----------------------|--------------------------------|---------------------------------------------|--------------|  

|[AtlAdvise](reference/connection-point-global-functions.md#atladvise), [CComPtrBase::Advise](../atl/reference/ccomptrbase-class.md#advise)|[AtlUnadvise](reference/connection-point-global-functions.md#atlunadvise)| Vtable ou interfaces duplas | Sim | `AtlAdvise` é uma função global do ATL. `CComPtrBase::Advise` é usado pelo [CComPtr](../atl/reference/ccomptr-class.md) e [CComQIPtr](../atl/reference/ccomqiptr-class.md). |  

|[IDispEventSimpleImpl::DispEventAdvise](../atl/reference/idispeventsimpleimpl-class.md#dispeventadvise)|[IDispEventSimpleImpl::DispEventUnadvise](../atl/reference/idispeventsimpleimpl-class.md#dispeventunadvise)|[IDispEventImpl](../atl/reference/idispeventimpl-class.md) ou [ IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md)| Não | Menos parâmetros que `AtlAdvise` desde que a classe base funciona mais. |  
|[CComCompositeControl::AdviseSinkMap(TRUE)](../atl/reference/ccomcompositecontrol-class.md#advisesinkmap)|[CComCompositeControl::AdviseSinkMap(FALSE)](../atl/reference/ccomcompositecontrol-class.md#advisesinkmap)| Controles ActiveX em controles compostos | Não | `CComCompositeControl::AdviseSinkMap` aconselha todas as entradas do coletor de eventos de mapa. A mesma função unadvises as entradas. Este método é chamado automaticamente pelo `CComCompositeControl` classe. |  
|[CAxDialogImpl::AdviseSinkMap(TRUE)](../atl/reference/caxdialogimpl-class.md#advisesinkmap)|[CAxDialogImpl::AdviseSinkMap(FALSE)](../atl/reference/caxdialogimpl-class.md#advisesinkmap)| Controles ActiveX na caixa de diálogo | Não | `CAxDialogImpl::AdviseSinkMap` aconselha e unadvises todos os controles ActiveX no recurso de caixa de diálogo. Isso é feito automaticamente para você. |  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de eventos](../atl/event-handling-and-atl.md)   
 [Suporte a IDispEventImpl](../atl/supporting-idispeventimpl.md)

