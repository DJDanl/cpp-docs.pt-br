---
title: "Classe de CMFCDesktopAlertWndInfo | Microsoft Docs"
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
  - "CMFCDesktopAlertWndInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCDesktopAlertWndInfo"
ms.assetid: 5c9bb84e-6c96-4748-8e74-6951b6ae8e84
caps.latest.revision: 26
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCDesktopAlertWndInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

a classe de `CMFCDesktopAlertWndInfo` é usada com [Classe de CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md).  Especifica os controles que são exibidos se a janela de alerta da área de trabalho aparece acima.  
  
## Sintaxe  
  
```  
class CMFCDesktopAlertWndInfo  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCDesktopAlertWndInfo::~CMFCDesktopAlertWndInfo`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCDesktopAlertWndInfo::operator\=](../Topic/CMFCDesktopAlertWndInfo::operator=.md)||  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCDesktopAlertWndInfo::m\_hIcon](../Topic/CMFCDesktopAlertWndInfo::m_hIcon.md)|Um identificador para o ícone que é exibido.|  
|[CMFCDesktopAlertWndInfo::m\_nURLCmdID](../Topic/CMFCDesktopAlertWndInfo::m_nURLCmdID.md)|A identificação de O comando associado com um link na janela de alerta da área de trabalho.|  
|[CMFCDesktopAlertWndInfo::m\_strText](../Topic/CMFCDesktopAlertWndInfo::m_strText.md)|O texto que é exibido na janela de alerta da área de trabalho.|  
|[CMFCDesktopAlertWndInfo::m\_strURL](../Topic/CMFCDesktopAlertWndInfo::m_strURL.md)|O link que é exibido na janela de alerta da área de trabalho.|  
  
## Comentários  
 A classe de `CMFCDesktopAlertWndInfo` é passada para o método de [CMFCDesktopAlertWnd::Create](../Topic/CMFCDesktopAlertWnd::Create.md) para especificar elementos que são exibidos na caixa de diálogo de janela padrão de alerta da área de trabalho.  a caixa de diálogo padrão pode conter três itens:  
  
-   Um ícone, que é definida chamando [CMFCDesktopAlertWndInfo::m\_hIcon](../Topic/CMFCDesktopAlertWndInfo::m_hIcon.md).  
  
-   Um rótulo, ou mensagem de texto, que é definida chamando [CMFCDesktopAlertWndInfo::m\_strText](../Topic/CMFCDesktopAlertWndInfo::m_strText.md).  
  
-   Um link, que é definida chamando [CMFCDesktopAlertWndInfo::m\_strURL](../Topic/CMFCDesktopAlertWndInfo::m_strURL.md).  Para definir o comando que é executado quando o link é clicado, chame [CMFCDesktopAlertWndInfo::m\_nURLCmdID](../Topic/CMFCDesktopAlertWndInfo::m_nURLCmdID.md).  
  
 Se a caixa de diálogo padrão não é suficiente, você pode criar uma caixa de diálogo personalizada e passá\-lo para o método de [CMFCDesktopAlertWnd::Create](../Topic/CMFCDesktopAlertWnd::Create.md) em vez de usar esta classe.  Para mais informações, consulte [Classe de CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários membros na classe de `CMFCDesktopAlertWndInfo` .  O exemplo demonstra como definir o identificador para o ícone que é exibido, o texto é exibido na janela de alerta da área de trabalho, no link que é exibido na janela de alerta da área de trabalho, e na identificação de comando que está associado com um link na janela de alerta da área de trabalho.  Este exemplo é parte de [Alerta exemplo de demonstração da área de trabalho](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DesktopAlertDemo#3](../../mfc/reference/codesnippet/CPP/cmfcdesktopalertwndinfo-class_1.cpp)]  
  
## Hierarquia de herança  
 [CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxDesktopAlertDialog.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)   
 [CMFCDesktopAlertWnd::Create](../Topic/CMFCDesktopAlertWnd::Create.md)   
 [Classe de CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)