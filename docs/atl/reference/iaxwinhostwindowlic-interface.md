---
title: "Interface de IAxWinHostWindowLic | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "IAxWinHostWindowLic"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface de IAxWinHostWindowLic"
ms.assetid: 750f1520-6bce-428c-aca0-fccbe3f063c7
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interface de IAxWinHostWindowLic
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa interface fornece métodos para manipular um controle licenciado e seu objeto host.  
  
## Sintaxe  
  
```  
  
interface IAxWinHostWindowLic : IAxWinHostWindow  
  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CreateControlLic](../Topic/IAxWinHostWindowLic::CreateControlLic.md)|Cria um controle licenciado e anexá\-la ao objeto do host.|  
|[CreateControlLicEx](../Topic/IAxWinHostWindowLic::CreateControlLicEx.md)|Cria um controle licenciado, anexa o objeto para o host, e opcionalmente configura de um manipulador de eventos.|  
  
## Comentários  
 `IAxWinHostWindowLic` herda de [IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md) e adiciona os métodos que oferecem suporte à criação de controles licenciadas.  
  
 [Hospedando controles ActiveX usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) consulte para um exemplo que usa os membros da interface.  
  
## Requisitos  
 A definição de essa interface está disponível como IDL ou C\+\+, como mostrado abaixo.  
  
|Definição de tipo|File|  
|-----------------------|----------|  
|IDL|ATLIFace.idl|  
|C\+\+|ATLIFace.h \(também incluído em ATLBase.h\)|