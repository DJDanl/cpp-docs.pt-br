---
title: O que é a ATL API de hospedagem de controles? | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- APIs [C++], hosting
- control-hosting API
- controls [ATL], hosting APIs
ms.assetid: 75b27e45-cfba-4950-aa35-96cc7d8da753
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2cc85c7ca47d5d1226ffc3089e01c0755ef6c6ac
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37850547"
---
# <a name="what-is-the-atl-control-hosting-api"></a>O que é a ATL API de hospedagem de controles?
ATL do controle de hospedagem API é o conjunto de funções que permite que qualquer janela atuar como um contêiner de controle ActiveX. Essas funções podem ser estaticamente ou dinamicamente vinculada ao seu projeto, pois eles estão disponíveis como código-fonte e expostos pelo ATL90.dll. As funções de hospedagem de controles são listadas na tabela a seguir.  
  
|Função|Descrição|  
|--------------|-----------------|  
|[AtlAxAttachControl](reference/composite-control-global-functions.md#atlaxattachcontrol)|Cria um objeto de host, conecta-se à janela fornecida e anexa um controle existente.|  
|[AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol)|Cria um objeto de host, conecta-se à janela fornecida e carrega um controle.|  
|[AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante à [AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol).|  
|[AtlAxCreateControlEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)|Cria um objeto de host, conecta-se à janela fornecida e, em seguida, carrega um controle (também permite que os coletores de eventos para ser configurado).|  
|[AtlAxCreateControlLicEx](reference/composite-control-global-functions.md#atlaxcreatecontrollicex)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante à [AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic).|  
|[AtlAxCreateDialog](reference/composite-control-global-functions.md#atlaxcreatedialog)|Cria uma caixa de diálogo sem janela restrita de um recurso de caixa de diálogo e retorna o identificador de janela.|  
|[AtlAxDialogBox](reference/composite-control-global-functions.md#atlaxdialogbox)|Cria uma caixa de diálogo modal a partir de um recurso de caixa de diálogo.|  
|[AtlAxGetControl](reference/composite-control-global-functions.md#atlaxgetcontrol)|Retorna o `IUnknown` ponteiro de interface do controle hospedado em uma janela.|  
|[AtlAxGetHost](reference/composite-control-global-functions.md#atlaxgethost)|Retorna o `IUnknown` ponteiro de interface do objeto de host conectado a uma janela.|  
|[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit)|Inicializa o código de hospedagem de controles.|  
|[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm)|Encerra o código de hospedagem de controles.|  
  
 O `HWND` parâmetros nas três primeiras funções devem ser uma janela existente de (quase) qualquer tipo. Se você chamar qualquer uma dessas três funções explicitamente (normalmente, você não precisará), não passe um identificador para uma janela que já está atuando como um host (se você fizer isso, o objeto de host existente não ser liberado).  
  
 As primeiras sete funções chamam [AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) implicitamente.  
  
> [!NOTE]
>  A API de hospedagem de controles constitui a base do suporte do ATL para contenção de controle ActiveX. No entanto, geralmente há pouca necessidade de chamar essas funções diretamente se você tira proveito dos ou fazer uso integral de classes de wrapper do ATL. Para obter mais informações, consulte [quais Classes facilitar ActiveX contenção de controle ATL](which-atl-classes-facilitate-activex-control-containment-q.md).  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](which-atl-classes-facilitate-activex-control-containment-q.md)
