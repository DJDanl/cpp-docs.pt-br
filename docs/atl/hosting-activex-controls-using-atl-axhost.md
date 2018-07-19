---
title: Hospedando controles ActiveX usando AXHost ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CAxWindow2T class
- Calendar control (ActiveX), hosting with ATL AXHost
- Calendar control (ActiveX)
- ActiveX controls [C++], hosting
- hosting ActiveX controls
- AXHost method
ms.assetid: 2c1200ec-effb-4814-820a-509519699468
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e26fd9e80b96c2b0196e3fd0e11b9c97f0f3bff3
ms.sourcegitcommit: 76fd30ff3e0352e2206460503b61f45897e60e4f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39027200"
---
# <a name="hosting-activex-controls-using-atl-axhost"></a>Hospedando controles ActiveX usando AXHost ATL
O exemplo neste tópico mostra como criar AXHost e como hospedar um controle ActiveX usando várias funções ATL. Ele também mostra como acessar os eventos de controle e de coletor (usando [IDispEventImpl](../atl/reference/idispeventimpl-class.md)) do controle que está hospedado. O exemplo hospeda o controle de calendário em uma janela principal ou em uma janela filho.  
  
 Observe que a definição do símbolo USE_METHOD. Você pode alterar o valor desse símbolo para variar entre 1 e 8. O valor do símbolo determina como o controle será criado:  
  
-   Para valores de par de USE_METHOD, a chamada para criar uma janela de subclasses de host e o converte em um host do controle. Para obter valores de número ímpar, o código cria uma janela filho que atua como um host.  
  
-   Para valores de USE_METHOD entre 1 e 4, acesso ao controle e coleta de eventos são realizadas na chamada que também cria o host. Os valores entre 5 e 8 o host para interfaces de consulta e o coletor de gancho.  
  
Segue um resumo:  
  
|USE_METHOD|Host|Controlar o acesso e recepção de evento|Função demonstrada|  
|-----------------|----------|--------------------------------------|---------------------------|  
|1|Janela filho|Uma etapa|CreateControlLicEx|  
|2|Janela principal|Uma etapa|AtlAxCreateControlLicEx|  
|3|Janela filho|Uma etapa|CreateControlEx|  
|4|Janela principal|Uma etapa|AtlAxCreateControlEx|  
|5|Janela filho|Várias etapas|CreateControlLic|  
|6|Janela principal|Várias etapas|AtlAxCreateControlLic|  
|7|Janela filho|Várias etapas|CreateControl|  
|8|Janela principal|Várias etapas|AtlAxCreateControl|  
  
 [!code-cpp[NVC_ATL_AxHost#1](../atl/codesnippet/cpp/hosting-activex-controls-using-atl-axhost_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)   
 [AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol)   
 [AtlAxCreateControlEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)   
 [AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic)   
 [AtlAxCreateControlLicEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)   
 [Classe CAxWindow2T](../atl/reference/caxwindow2t-class.md)   
 [Interface IAxWinHostWindowLic](../atl/reference/iaxwinhostwindowlic-interface.md)

