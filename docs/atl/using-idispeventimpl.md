---
title: "Usando IDispEventImpl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "IDispEventImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IDispEventImpl, Usando"
ms.assetid: 82d53b61-9d0d-45c5-aff9-2fafa468a9ca
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando IDispEventImpl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A o usar `IDispEventImpl` para manipular eventos, você precisará:  
  
-   Derivado da classe de [IDispEventImpl](../atl/reference/idispeventimpl-class.md).  
  
-   Adicione [mapa o coletor de eventos](../Topic/BEGIN_SINK_MAP.md) a sua classe.  
  
-   Adicione entradas no mapa do coletor de eventos usando a macro de [SINK\_ENTRY](../Topic/SINK_ENTRY.md) ou de [SINK\_ENTRY\_EX](../Topic/SINK_ENTRY_EX.md) .  
  
-   Implementar métodos que você está interessado em tratamento.  
  
-   Seja recomendável e unadvise a fonte do evento.  
  
## Exemplo  
 O exemplo a seguir mostra como manipular o evento de **DocumentChange** acionado pelo objeto de **Aplicativo** palavra.  Este evento é definido como um método no dispinterface de **ApplicationEvents** .  
  
 o exemplo é de [exemplo de ATLEventHandling](../top/visual-cpp-samples.md).  
  
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
  
 Usos `#import` de exemplo para gerar os arquivos de cabeçalho necessários da biblioteca de tipos palavra.  Se você desejar usar esse exemplo com outras versões do word, você deve especificar o arquivo correto de DLL de mso.  Por exemplo, o Office 2000 fornece mso9.dll e Office XP fornece mso.dll.  Esse código é simplificado de stdafx.h:  
  
 [!code-cpp[NVC_ATL_EventHandlingSample#1](../atl/codesnippet/CPP/using-idispeventimpl_1.h)]  
  
 O código a seguir aparece em NotSoSimple.h.  O código relevante é mencionado por comentários:  
  
 [!code-cpp[NVC_ATL_EventHandlingSample#2](../atl/codesnippet/CPP/using-idispeventimpl_2.h)]  
  
## Consulte também  
 [Manipulação de eventos](../Topic/Event%20Handling%20and%20ATL.md)   
 [exemplo de ATLEventHandling](../top/visual-cpp-samples.md)