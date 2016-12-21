---
title: "Mapas de evento | Microsoft Docs"
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
  - "vc.mfc.macros.maps"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "mapas de evento"
ms.assetid: 1ed53aee-bc53-43cd-834a-6fb935c0d29b
caps.latest.revision: 15
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapas de evento
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Sempre que um controle desejar notificar o contêiner que qualquer ação \(determinada pelo desenvolvedor de controle\) aconteceu \(como um pressionamento da tecla, clique em do mouse, ou uma alteração no estado de controle\) chama uma função de evento acionado.  Essa função notifica o contêiner do controle que qualquer ação importante acionando ocorreu o evento relacionado.  
  
 A biblioteca de classes do Microsoft oferece um modelo de programação otimizado acionando eventos.  Neste modelo, “evento” mapas são usados para designar que o acionamento das funções que eventos para um controle específico.  O evento contêm uma macro para cada evento.  Por exemplo, um mapa de evento que com um evento de estoque em pode ter esta aparência:  
  
 [!code-cpp[NVC_MFCAxCtl#16](../../mfc/reference/codesnippet/CPP/event-maps_1.cpp)]  
  
 A macro de **EVENT\_STOCK\_CLICK** indica que o controle será acionado um evento de estoque em todas as vezes que detecta um clique do mouse.  Para uma lista mais detalhada de outros eventos de estoque, consulte o artigo [Controles ActiveX: Eventos](../../mfc/mfc-activex-controls-events.md).  Macros também estão disponíveis para indicar eventos personalizados.  
  
 Embora as macros de evento o mapa são importantes, geralmente você não insere os diretamente.  Isso é porque a janela Propriedades cria automaticamente entradas de evento o mapa em seus arquivos de origem quando você usa para associar a funções de eventos acionamento com os eventos.  Quando você deseja editar ou adicionar uma entrada ao evento mapa, você pode usar a janela Propriedades.  
  
 Para dar suporte aos mapas de evento, MFC o fornece os seguintes macros:  
  
### Declaração e delimitação do mapa de evento  
  
|||  
|-|-|  
|[DECLARE\_EVENT\_MAP](../Topic/DECLARE_EVENT_MAP.md)|Declara que um mapa de evento será usado em uma classe para mapear eventos para as funções do evento \(acionamento deve ser usado na declaração de classe\).|  
|[BEGIN\_EVENT\_MAP](../Topic/BEGIN_EVENT_MAP.md)|Inicia a definição de um mapa de evento \(deve ser usado na implementação da classe\).|  
|[END\_EVENT\_MAP](../Topic/END_EVENT_MAP.md)|Termina a definição de um mapa de evento \(deve ser usado na implementação da classe\).|  
  
### Macros de mapeamento de evento  
  
|||  
|-|-|  
|[EVENT\_CUSTOM](../Topic/EVENT_CUSTOM.md)|Indica que eventos função de acionamento acionará o evento especificado.|  
|[EVENT\_CUSTOM\_ID](../Topic/EVENT_CUSTOM_ID.md)|Indica que eventos função de acionamento acionará o evento especificado, com uma ID designada de distribuição|  
  
### Macros de mapeamento de mensagem  
  
|||  
|-|-|  
|[ON\_OLEVERB](../Topic/ON_OLEVERB.md)|Indica um verbo personalizado tratado pelo controlador OLE.|  
|[ON\_STDOLEVERB](../Topic/ON_STDOLEVERB.md)|Substitui um mapeamento padrão do verbo de controlador OLE.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)