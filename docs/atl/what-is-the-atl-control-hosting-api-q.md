---
title: O que é o ATL API de hospedagem de controle? | Microsoft Docs
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
ms.openlocfilehash: 30b104e21259006da41c236c168431d85b43e0d4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32363240"
---
# <a name="what-is-the-atl-control-hosting-api"></a>O que é o ATL API de hospedagem de controle?
ATL da hospedagem de controles API é o conjunto de funções que permite que qualquer janela atuar como um contêiner de controle ActiveX. Essas funções podem ser estaticamente ou dinamicamente vinculado em seu projeto, porque eles estão disponíveis como código-fonte e expostos pelo ATL90.dll. As funções de controle de hospedagem são listadas na tabela a seguir.  
  
|Função|Descrição|  
|--------------|-----------------|  
|[AtlAxAttachControl](reference/composite-control-global-functions.md#atlaxattachcontrol)|Cria um objeto de host, conecta-se à janela fornecida e anexa um controle existente.|  
|[AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol)|Cria um objeto de host, conecta-se à janela fornecida e carrega um controle.|  
|[AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic)|Cria um controle ActiveX licenciado, inicializa e hospeda na janela especificada, semelhante ao [AtlAxCreateControl](reference/composite-control-global-functions.md#atlaxcreatecontrol).|  
|[AtlAxCreateControlEx](reference/composite-control-global-functions.md#atlaxcreatecontrolex)|Cria um objeto de host, conecta-se à janela fornecida e carrega um controle (também permite que os coletores de eventos para ser configurado).|  
|[AtlAxCreateControlLicEx](reference/composite-control-global-functions.md#atlaxcreatecontrollicex)|Cria um controle ActiveX licenciado, inicializa e hospeda na janela especificada, semelhante ao [AtlAxCreateControlLic](reference/composite-control-global-functions.md#atlaxcreatecontrollic).|  
|[AtlAxCreateDialog](reference/composite-control-global-functions.md#atlaxcreatedialog)|Cria uma caixa de diálogo sem janela restrita de um recurso de caixa de diálogo e retorna o identificador de janela.|  
|[AtlAxDialogBox](reference/composite-control-global-functions.md#atlaxdialogbox)|Cria uma caixa de diálogo modal de um recurso de caixa de diálogo.|  
|[AtlAxGetControl](reference/composite-control-global-functions.md#atlaxgetcontrol)|Retorna o **IUnknown** ponteiro de interface do controle hospedado em uma janela.|  
|[AtlAxGetHost](reference/composite-control-global-functions.md#atlaxgethost)|Retorna o **IUnknown** ponteiro de interface de objeto de host conectado a uma janela.|  
|[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit)|Inicializa o código de hospedagem de controles.|  
|[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm)|Uninitializes o código de hospedagem de controles.|  
  
 O `HWND` parâmetros nas três primeiras funções devem ser uma janela existente de (quase) qualquer tipo. Se você chamar qualquer uma dessas três funções explicitamente (normalmente, você não precisará), não passar um identificador para uma janela que já está atuando como um host (nesse caso, o objeto de host existente não ser liberado).  
  
 Chamam as funções primeiro sete [AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) implicitamente.  
  
> [!NOTE]
>  A API de hospedagem de controles de formulários a base de suporte do ATL para contenção de controle ActiveX. No entanto, geralmente há pouca necessidade de chamar diretamente essas funções se aproveitar ou fazer uso total de classes de wrapper da ATL. Para obter mais informações, consulte [que Classes facilitar ActiveX contenção de controle ATL](which-atl-classes-facilitate-activex-control-containment-q.md).  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](which-atl-classes-facilitate-activex-control-containment-q.md)
