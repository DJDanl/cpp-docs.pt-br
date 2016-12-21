---
title: "O que &#233; ATL API de Hospedagem? | Microsoft Docs"
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
  - "APIs [C++], hospedar"
  - "hospedando controles API"
  - "controles [ATL], hospedando APIs"
ms.assetid: 75b27e45-cfba-4950-aa35-96cc7d8da753
caps.latest.revision: 15
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# O que &#233; ATL API de Hospedagem?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

ATL que hospeda API é o conjunto de funções que permite que qualquer janela atua como um recipiente de controles ActiveX.  Essas funções podem para vincular estaticamente ou dinamicamente em seu projeto já que estão disponíveis como código\-fonte e expostos por ATL90.dll.  Funções de hospedagem são listadas na tabela abaixo.  
  
|Função|Descrição|  
|------------|---------------|  
|[AtlAxAttachControl](../Topic/AtlAxAttachControl.md)|Cria um objeto host, conectá\-lo a janela fornecida, então anexa um controle existente.|  
|[AtlAxCreateControl](../Topic/AtlAxCreateControl.md)|Cria um objeto host, conectá\-lo a janela fornecida, então carregá\-lo um controle.|  
|[AtlAxCreateControlLic](../Topic/AtlAxCreateControlLic.md)|Cria um controle ActiveX licenciado, inicializa\-o, e hospedá\-lo na janela especificada, semelhante a [AtlAxCreateControl](../Topic/AtlAxCreateControl.md).|  
|[AtlAxCreateControlEx](../Topic/AtlAxCreateControlEx.md)|Cria um objeto host, conectá\-lo a janela fornecida, então carregá\-lo um controle \(também permite que os coletores de eventos são configurados\).|  
|[AtlAxCreateControlLicEx](../Topic/AtlAxCreateControlLicEx.md)|Cria um controle ActiveX licenciado, inicializa\-o, e hospedá\-lo na janela especificada, semelhante a [AtlAxCreateControlLic](../Topic/AtlAxCreateControlLic.md).|  
|[AtlAxCreateDialog](../Topic/AtlAxCreateDialog.md)|Cria uma caixa de diálogo sem\-modo de um recurso da caixa de diálogo e retorna o identificador de janela.|  
|[AtlAxDialogBox](../Topic/AtlAxDialogBox.md)|Cria uma caixa de diálogo modal de um recurso da caixa de diálogo.|  
|[AtlAxGetControl](../Topic/AtlAxGetControl.md)|Retorna o ponteiro de interface de **IUnknown** do controle hospedado em uma janela.|  
|[AtlAxGetHost](../Topic/AtlAxGetHost.md)|Retorna o ponteiro de interface de **IUnknown** do objeto host conectado a uma janela.|  
|[AtlAxWinInit](../Topic/AtlAxWinInit.md)|Inicializa o código de controle de hospedagem.|  
|[AtlAxWinTerm](../Topic/AtlAxWinTerm.md)|Uninitializes o código de controle de hospedagem.|  
  
 Os parâmetros de `HWND` nas três primeiras funções devem ser uma janela existente de \(praticamente\) qualquer tipo.  Se você chamar qualquer uma de essas três funções explicitamente \(normalmente, você não tem que\), não passar um identificador para uma janela que já está atuando como um host \(se você fizer isso, o objeto existente host não será liberado.\)  
  
 a primeira ligação de controle sete [AtlAxWinInit](../Topic/AtlAxWinInit.md) implicitamente.  
  
> [!NOTE]
>  A API de hospedagem forma a base de suporte de ATL para retenção de controle ActiveX.  Em o entanto, há geralmente uma pequena necessidade de chamar diretamente essas funções se você aproveita ou se torna de uso completo de classes envoltório de ATL.  Para obter mais informações, consulte [ATL classes que facilita a retenção do controle ActiveX?](../atl/which-atl-classes-facilitate-activex-control-containment-q.md).  
  
## Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)