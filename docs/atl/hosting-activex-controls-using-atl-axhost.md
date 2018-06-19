---
title: Hospedando controles ActiveX usando ATL AXHost | Microsoft Docs
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
ms.openlocfilehash: 5057a077e8e778fa3d943b736d51d19af8f60fc6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32356246"
---
# <a name="hosting-activex-controls-using-atl-axhost"></a>Hospedando controles ActiveX usando AXHost ATL
O exemplo neste tópico mostra como criar AXHost e como hospedar um controle ActiveX usando várias funções ATL. Ele também mostra como acessar o controle e o coletor de eventos (usando [IDispEventImpl](../atl/reference/idispeventimpl-class.md)) do controle que está hospedado. O exemplo hospeda o controle de calendário em uma janela principal ou em uma janela filho.  
  
 Observe a definição do `USE_METHOD` símbolo. Você pode alterar o valor desse símbolo para variar entre 1 e 8. O valor do símbolo determina como o controle será criado:  
  
-   Para obter valores de pares de `USE_METHOD`, a chamada para criar uma janela de subclasses de host e os converte em um host do controle. Para obter valores de número ímpar, o código cria uma janela filho que atua como um host.  
  
-   Para obter valores de `USE_METHOD` entre 1 e 4, acesse o controle e recebendo de eventos são realizadas na chamada que também cria o host. Os valores entre 5 e 8 o host para as interfaces de consulta e conectar-se com o coletor.  
  
 Segue um resumo:  
  
|USE_METHOD|Host|Controlar o acesso e a recepção de evento|Função demonstrada|  
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

