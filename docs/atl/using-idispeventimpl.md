---
title: Usando IDispEventImpl (ATL) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IDispEventImpl
dev_langs:
- C++
helpviewer_keywords:
- IDispEventImpl class, using
ms.assetid: 82d53b61-9d0d-45c5-aff9-2fafa468a9ca
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f787fac05e95fff8a974692c3e6fca24561ed222
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-idispeventimpl"></a>Usando IDispEventImpl
Ao usar `IDispEventImpl` para manipular eventos, você precisará:  
  
-   Derive a classe de [IDispEventImpl](../atl/reference/idispeventimpl-class.md).  
  
-   Adicione um mapa de coletor de eventos à sua classe.  
  
-   Adicione entradas para o mapa de coletor de evento usando o [SINK_ENTRY](reference/composite-control-macros.md#sink_entry) ou [SINK_ENTRY_EX](reference/composite-control-macros.md#sink_entry_ex) macro.  
  
-   Implemente os métodos que você está interessado na manipulação.  
  
-   Avisar e unadvise a origem do evento.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como tratar o **DocumentChange** eventos acionados por do Word **aplicativo** objeto. Esse evento é definido como um método no **ApplicationEvents** dispinterface.  
  
 O exemplo é proveniente do [ATLEventHandling exemplo](../visual-cpp-samples.md).  
  
 `[`  
  
 `uuid(000209F7-0000-0000-C000-000000000046),`  
  
 `hidden`  
  
 `]`  
  
 `dispinterface ApplicationEvents {`  
  
 `properties:`  
  
 `methods:`  
  
 `[id(0x00000001), restricted, hidden]`  
  
 `void Startup();`  
  
 `[id(0x00000002)]`  
  
 `void Quit();`  
  
 `[id(0x00000003)]`  
  
 `void DocumentChange();`  
  
 `};`  
  
 O exemplo usa `#import` para gerar os arquivos de cabeçalho necessários da biblioteca de tipos do Word. Se você quiser usar este exemplo com outras versões do Word, você deve especificar o arquivo de dll mso correto. Por exemplo, Office 2000 fornece Mso9 e OfficeXP fornece Mso. dll. Esse código é simplificado do Stdafx. h:  
  
 [!code-cpp[NVC_ATL_EventHandlingSample#1](../atl/codesnippet/cpp/using-idispeventimpl_1.h)]  
  
 O código a seguir aparece no NotSoSimple.h. O código relevante é indicado por comentários:  
  
 [!code-cpp[NVC_ATL_EventHandlingSample#2](../atl/codesnippet/cpp/using-idispeventimpl_2.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de eventos](../atl/event-handling-and-atl.md)   
 [Exemplo de ATLEventHandling](../visual-cpp-samples.md)

