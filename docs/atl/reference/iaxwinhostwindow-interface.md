---
title: "Interface de IAxWinHostWindow | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "IAxWinHostWindow"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface de IAxWinHostWindow"
ms.assetid: 9821c035-cd52-4c46-b58a-9278064f09b4
caps.latest.revision: 21
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interface de IAxWinHostWindow
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa interface fornece métodos para manipular um controle e seu objeto host.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
interface IAxWinHostWindow : IUnknown  
  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[AttachControl](../Topic/IAxWinHostWindow::AttachControl.md)|Anexar um controle existente ao objeto do host.|  
|[CreateControl](../Topic/IAxWinHostWindow::CreateControl.md)|Cria um controle e anexá\-la ao objeto do host.|  
|[CreateControlEx](../Topic/IAxWinHostWindow::CreateControlEx.md)|Cria um controle, anexa o objeto para o host, e opcionalmente configura de um manipulador de eventos.|  
|[QueryControl](../Topic/IAxWinHostWindow::QueryControl.md)|Retorna um ponteiro de interface para o controle hospedado.|  
|[SetExternalDispatch](../Topic/IAxWinHostWindow::SetExternalDispatch.md)|Define a interface de `IDispatch` externo.|  
|[SetExternalUIHandler](../Topic/IAxWinHostWindow::SetExternalUIHandler.md)|Define a interface de `IDocHostUIHandlerDispatch` externo.|  
  
## Comentários  
 Essa interface é exposta pelo controle ActiveX de ATL que hospeda objetos.  Chamar os métodos em esta interface para criar e\/ou anexar um controle ao objeto do host, para obter uma interface de um controle hospedado, ou para definir o dispinterface ou manipulador externo de interface de usuário para uso para hospedar o navegador da Web.  
  
## Requisitos  
 A definição de essa interface está disponível como IDL ou C\+\+, como mostrado abaixo.  
  
|Definição de tipo|File|  
|-----------------------|----------|  
|IDL|ATLIFace.idl|  
|C\+\+|ATLIFace.h \(também incluído em ATLBase.h\)|  
  
## Consulte também  
 [Interface de IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)   
 [CAxWindow::QueryHost](../Topic/CAxWindow::QueryHost.md)   
 [AtlAxGetHost](../Topic/AtlAxGetHost.md)