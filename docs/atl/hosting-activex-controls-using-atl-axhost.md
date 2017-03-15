---
title: "Hospedando controles ActiveX usando ATL AXHost | Microsoft Docs"
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
  - "Controles ActiveX [C++], hospedar"
  - "Método de AXHost"
  - "Controle de calendário (ActiveX)"
  - "Controle de calendário (ActiveX), hospedar com ATL AXHost"
  - "Classe de CAxWindow2T"
  - "hospedando controles ActiveX"
ms.assetid: 2c1200ec-effb-4814-820a-509519699468
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Hospedando controles ActiveX usando ATL AXHost
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo em este tópico mostra como criar AXHost e como hospedar um controle ActiveX usando várias funções de ATL.  Também mostra como acessar os eventos do controle e o coletor \(usando [IDispEventImpl](../atl/reference/idispeventimpl-class.md)\) do controle que é hospedado.  O exemplo hospeda o controle de calendário em uma janela principal ou janela filho.  
  
 Observe a definição do símbolo de `USE_METHOD` .  Você pode alterar o valor de esse símbolo para variar entre 1 e 8.  O valor do símbolo determina como o controle será criado:  
  
-   Para valores pares numerados de `USE_METHOD`, a chamada para criar as subclasses host uma janela e ele converte em um host do controle.  Para valores ímpares numerados, o código cria uma janela filho que atua como um host.  
  
-   Para valores de `USE_METHOD` entre 1 e 4, acesso ao controle e o naufrágio de eventos é realizada na chamada que também cria o host.  Os valores entre 5 e 8 consulte o host para engancham interfaces e o coletor.  
  
 Aqui está um resumo:  
  
|USE\_METHOD|Hosts|Controle acesso e o naufrágio de evento|Função demonstrada|  
|-----------------|-----------|---------------------------------------------|------------------------|  
|1|Janela filho|Uma etapa|CreateControlLicEx|  
|2|Janela principal|Uma etapa|AtlAxCreateControlLicEx|  
|3|Janela filho|Uma etapa|CreateControlEx|  
|4|Janela principal|Uma etapa|AtlAxCreateControlEx|  
|5|Janela filho|Várias etapas|CreateControlLic|  
|6|Janela principal|Várias etapas|AtlAxCreateControlLic|  
|7|Janela filho|Várias etapas|CreateControl|  
|8|Janela principal|Várias etapas|AtlAxCreateControl|  
  
 [!code-cpp[NVC_ATL_AxHost#1](../atl/codesnippet/CPP/hosting-activex-controls-using-atl-axhost_1.cpp)]  
  
## Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)   
 [AtlAxCreateControl](../Topic/AtlAxCreateControl.md)   
 [AtlAxCreateControlEx](../Topic/AtlAxCreateControlEx.md)   
 [AtlAxCreateControlLic](../Topic/AtlAxCreateControlLic.md)   
 [AtlAxCreateControlLicEx](../Topic/AtlAxCreateControlLicEx.md)   
 [Classe de CAxWindow2T](../Topic/CAxWindow2T%20Class.md)   
 [Interface de IAxWinHostWindowLic](../atl/reference/iaxwinhostwindowlic-interface.md)