---
title: "Fun&#231;&#245;es globais de controle composto | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles de composição, funções globais"
ms.assetid: 536884cd-e863-4c7a-ab0a-604dc60a0bbe
caps.latest.revision: 20
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es globais de controle composto
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essas funções oferecem suporte para criar caixas de diálogo, e para criar, e licenciamento hospedar controles ActiveX.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlAxDialogBox](../Topic/AtlAxDialogBox.md)|Cria uma caixa de diálogo modal de um modelo da caixa de diálogo fornecido pelo usuário.  A caixa de diálogo resultante pode conter controles ActiveX.|  
|[AtlAxCreateDialog](../Topic/AtlAxCreateDialog.md)|Cria uma caixa de diálogo sem\-modo de um modelo da caixa de diálogo fornecido pelo usuário.  A caixa de diálogo resultante pode conter controles ActiveX.|  
|[AtlAxCreateControl](../Topic/AtlAxCreateControl.md)|Cria um controle ActiveX, inicializa\-o, e hospedá\-lo na janela especificada.|  
|[AtlAxCreateControlEx](../Topic/AtlAxCreateControlEx.md)|Cria um controle ActiveX, inicializa\-o, hospedá\-lo na janela especificada, e recupera um ponteiro de interface \(ou\) ponteiros do controle.|  
|[AtlAxCreateControlLic](../Topic/AtlAxCreateControlLic.md)|Cria um controle ActiveX licenciado, inicializa\-o, e hospedá\-lo na janela especificada.|  
|[AtlAxCreateControlLicEx](../Topic/AtlAxCreateControlLicEx.md)|Cria um controle ActiveX licenciado, inicializa\-o, hospedá\-lo na janela especificada, e recupera um ponteiro de interface \(ou\) ponteiros do controle.|  
|[AtlAxAttachControl](../Topic/AtlAxAttachControl.md)|Anexar um controle anteriormente criada para a janela especificada.|  
|[AtlAxGetHost](../Topic/AtlAxGetHost.md)|Usado para obter um ponteiro direto de interface para o contêiner para uma janela especificada \(se houver\), dado o identificador.|  
|[AtlAxGetControl](../Topic/AtlAxGetControl.md)|Usado para obter um ponteiro direto de interface para o controle contido dentro de uma janela especificada \(se houver\), dada a alça.|  
|[AtlSetChildSite](../Topic/AtlSetChildSite.md)|Inicializa **IUnknown** de site filho.|  
|[AtlAxWinInit](../Topic/AtlAxWinInit.md)|Inicializa o código de hospedagem para objetos de AxWin.|  
|[AtlAxWinTerm](../Topic/AtlAxWinTerm.md)|Uninitializes o código de hospedagem para objetos de AxWin.|  
|[AtlGetObjectSourceInterface](../Topic/AtlGetObjectSourceInterface.md)|Returns informações sobre a interface padrão da fonte de um objeto.|  
  
## Consulte também  
 [Funções](../../atl/reference/atl-functions.md)   
 [Macros controle composto](../../atl/reference/composite-control-macros.md)