---
title: "Adicionando funcionalidade para o controle composto | Microsoft Docs"
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
  - "Controles ActiveX [C++], eventos"
  - "controles de composição, manipulando eventos"
  - "manipuladores de eventos [C++], Controles ActiveX"
ms.assetid: 98f85681-9564-480d-af38-03f9733fe58b
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando funcionalidade para o controle composto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma vez que você inseriu todos os controles necessários no controle composto, a próxima etapa envolve adicionar uma nova funcionalidade.  Essa nova funcionalidade está geralmente em duas categorias:  
  
-   Interfaces adicionais de suporte e personalizar o comportamento do seu controle composto com recursos adicionais, específicos.  
  
-   Manipulando eventos de controle ActiveX contido \(ou de controles\).  
  
 Para a finalidade e o escopo de este artigo, o restante de esta seção foca sobre exclusivamente manipulando eventos dos controles ActiveX.  
  
> [!NOTE]
>  Se você precisar manipular mensagens dos controles do windows, consulte [implementando uma janela](../atl/implementing-a-window.md) para obter mais informações sobre manipulação de mensagem em ATL.  
  
 Após inserido um controle ActiveX no recurso da caixa de diálogo, clique com o botão direito do mouse no controle e clique **Adicionar Manipulador de Eventos**.  Selecione o evento que deseja manipular e clique **Add and Edit**.  O código do manipulador de eventos será adicionado ao arquivo .h do controle.  
  
 Os pontos de conexão para controles ActiveX no controle composto automaticamente estão conectados e desconectados entre chamadas a [CComCompositeControl::AdviseSinkMap](../Topic/CComCompositeControl::AdviseSinkMap.md).  
  
## Consulte também  
 [Fundamentos do controle composto](../Topic/ATL%20Composite%20Control%20Fundamentals.md)