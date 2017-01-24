---
title: "Mapas de mensagem (MFC) | Microsoft Docs"
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
  - "vc.mfc.messages"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "mapas de mensagem [C++], MFC"
  - "mensagens [C++], Janelas"
  - "MFC [C++], mensagens"
  - "mensagens do Windows [C++], mapas de mensagem"
ms.assetid: 3f9855e4-9d7d-4b64-8f3f-a19ea3cf79ba
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapas de mensagem (MFC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta seção das listas de referência qualquer [macros de mapeamento de mensagem](../../mfc/reference/message-map-macros-mfc.md) e todas as entradas retornadas mapa de [CWnd](../Topic/CWnd%20Class.md) junto com os protótipos da função de membro:  
  
|Categoria|Descrição|  
|---------------|---------------|  
|[Manipulador de mensagens de WM\_COMMAND](../Topic/WM_COMMAND%20Message%20Handler.md)|Mensagens de **WM\_COMMAND** de identificadores geradas por seleções de menu do usuário ou por chaves de acesso no menu.|  
|[Manipuladores de notificação da janela filho](../Topic/Child%20Window%20Notification%20Message%20Handlers.md)|Notificações do identificador do windows filho.|  
|[Manipuladores de mensagem de WM\_](../../mfc/reference/handlers-for-wm-messages.md)|Mensagens de **WM\_** de identificador, como `WM_PAINT`.|  
|[Manipuladores de mensagem definidos pelo usuário](../Topic/User-Defined%20Handlers.md)|Mensagens definidas pelo usuário do identificador.|  
  
 \(Para obter uma explicação da terminologia e as convenções usadas nesta referência, consulte [Como usar a referência cruzada da mensagem](../../mfc/reference/how-to-use-the-message-map-cross-reference.md).\)  
  
 Desde que o windows é um sistema operacional mensagem\- orientada, uma grande parte de programação para o ambiente do windows envolve a manipulação de mensagens.  Cada vez que um evento como um pressionamento da tecla ou clicar no mouse ocorre, uma mensagem será enviada ao aplicativo, que deve tratar no evento.  
  
 A biblioteca de classes do Microsoft oferece um modelo de programação otimizado para a programação mensagem\- baseada.  Neste modelo, “mapas mensagem” são usados para designar funções que tratarão mais mensagens de uma classe específica.  Os mapas de mensagem contêm um ou mais macros que especificam quais mensagens serão manipuladas por que funciona.  Por exemplo, um mapa de mensagem que contém uma macro de `ON_COMMAND` pode ter esta aparência:  
  
 [!code-cpp[NVC_MFCMessageMaps#16](../../mfc/reference/codesnippet/CPP/message-maps-mfc_1.cpp)]  
  
 A macro de `ON_COMMAND` é usado para tratar mensagens do comando geradas por menus, por botões, e por teclas de aceleração.  [Macros](../../mfc/reference/message-map-macros-mfc.md) está disponível para mapear o seguinte:  
  
## Mensagens do windows  
  
-   Controle notificações  
  
-   Mensagens definidas pelo usuário  
  
## Mensagens de comando  
  
-   Mensagens definidas pelo usuário registradas  
  
-   Mensagens de atualização da interface do usuário  
  
## Intervalos de mensagens  
  
-   Comandos  
  
-   Mensagens do manipulador de atualização  
  
-   Controle notificações  
  
 Embora as macros retornadas o mapa são importantes, geralmente você não terá que usá\-los diretamente.  Isso é porque a janela Propriedades cria automaticamente entradas retornadas o mapa em seus arquivos de origem quando você usa para associar a funções de gerenciamento de mensagens com as mensagens.  Quando você deseja editar ou adicionar uma entrada retornadas mapa, você pode usar a janela Propriedades.  
  
> [!NOTE]
>  A janela Propriedades não oferece suporte a intervalos retornadas mapa.  Você deve gravar essas entradas retornadas mapa você mesmo.  
  
 No entanto, os mapas da mensagem é uma parte importante da biblioteca de classes do Microsoft.  Você deve entender o que faz, e a documentação é fornecida para ele.  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)