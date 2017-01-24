---
title: "Classe de CAxWindow | Microsoft Docs"
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
  - "CAxWindowT"
  - "CAxWindow"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, hospedando controles ActiveX"
  - "Classe de CAxWindow"
ms.assetid: 85e79261-43e4-4770-bde0-1ff87f222b0f
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAxWindow
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CAxWindow : public CWindow  
  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[AttachControl](../Topic/CAxWindow::AttachControl.md)|Anexar um controle ActiveX existente ao objeto de `CAxWindow` .|  
|[CAxWindow](../Topic/CAxWindow::CAxWindow.md)|Constrói um objeto de `CAxWindow` .|  
|[CreateControl](../Topic/CAxWindow::CreateControl.md)|Cria um controle ActiveX, inicializa\-o, e hospedá\-lo na janela de `CAxWindow` .|  
|[CreateControlEx](../Topic/CAxWindow::CreateControlEx.md)|Cria um controle ActiveX e recupera um ponteiro de interface \(ou\) ponteiros do controle.|  
|[GetWndClassName](../Topic/CAxWindow::GetWndClassName.md)|\(Static\) Retorna o nome da classe predefinido do objeto de `CAxWindow` .|  
|[QueryControl](../Topic/CAxWindow::QueryControl.md)|Recupera **IUnknown** do controle ActiveX hospedado.|  
|[QueryHost](../Topic/CAxWindow::QueryHost.md)|Recupera o ponteiro de **IUnknown** do objeto de `CAxWindow` .|  
|[SetExternalDispatch](../Topic/CAxWindow::SetExternalDispatch.md)|Define a interface externo de distribuição usada pelo objeto de `CAxWindow` .|  
|[SetExternalUIHandler](../Topic/CAxWindow::SetExternalUIHandler.md)|Define a interface externo de **IDocHostUIHandler** usada pelo objeto de `CAxWindow` .|  
  
### Operadores  
  
|||  
|-|-|  
|[operador \=](../Topic/CAxWindow::operator%20=.md)|Atribui **HWND** a um objeto existente de**CAxWindow** .|  
  
## Comentários  
 Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX.  Hospedar é fornecido por “**AtlAxWin80"**, que é empacotado por `CAxWindow`.  
  
 A classe `CAxWindow` é implementada como uma especialização da classe de `CAxWindowT` .  Esta especialização é declarada como:  
  
 `typedef CAxWindowT<CWindow> CAxWindow;`  
  
 Se você precisar alterar a classe base, você pode usar `CAxWindowT` e especificar a nova classe base como um argumento de modelo.  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [exemplo de ATLCON](../../top/visual-cpp-samples.md)   
 [Classe de CWindow](../../atl/reference/cwindow-class.md)   
 [Fundamentos do controle composto](../Topic/ATL%20Composite%20Control%20Fundamentals.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Perguntas frequentes sobre contenção de controle](../../atl/atl-control-containment-faq.md)