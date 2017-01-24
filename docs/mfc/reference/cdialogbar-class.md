---
title: "Classe de CDialogBar | Microsoft Docs"
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
  - "CDialogBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDialogBar"
  - "barras da caixa de diálogo, Caixa de diálogo sem-modo do windows"
  - "caixas de diálogo, sem-modo"
ms.assetid: da2f7a30-970c-44e3-87f0-6094bd002cab
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDialogBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade de uma caixa de diálogo sem\-modo do windows em uma barra de controle.  
  
## Sintaxe  
  
```  
class CDialogBar : public CControlBar  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDialogBar::CDialogBar](../Topic/CDialogBar::CDialogBar.md)|Constrói um objeto de `CDialogBar` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDialogBar::Create](../Topic/CDialogBar::Create.md)|Cria uma barra da caixa de diálogo do windows e anexá\-la ao objeto de `CDialogBar` .|  
  
## Comentários  
 Uma barra da caixa de diálogo é semelhante a uma caixa de diálogo que contém os controles padrão do windows que o usuário pode voltar no meio.  Outra similaridade é que você cria um modelo da caixa de diálogo para representar a barra da caixa de diálogo.  
  
 Criar e usar uma barra da caixa de diálogo são semelhantes à criar e usar um objeto de `CFormView` .  Primeiro, use [editor de diálogo](../../mfc/dialog-editor.md) para definir um modelo da caixa de diálogo com o estilo **WS\_CHILD** e nenhum outro estilo.  o modelo não deve ter o estilo **WS\_VISIBLE**.  Em o código do aplicativo, chamar o construtor para construir o objeto de `CDialogBar` , então chamar **Criar** para criar a janela da caixa de diálogo\- barra para e anexá\-la ao objeto de `CDialogBar` .  
  
 Para obter mais informações sobre `CDialogBar`, consulte o artigo [Barras da caixa de diálogo](../../mfc/dialog-bars.md) e [Observe técnica 31](../../mfc/tn031-control-bars.md), barras de controle.  
  
> [!NOTE]
>  Em a versão atual, um objeto de `CDialogBar` não pode hospedar controles de formulários do windows.  Para obter mais informações sobre controles de formulários do windows em Visual C\+\+, consulte [Usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CDialogBar`  
  
## Requisitos  
 **Cabeçalho:** afxext.h  
  
## Consulte também  
 [Exemplo CTRLBARS MFC](../../top/visual-cpp-samples.md)   
 [Classe de CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFormView](../../mfc/reference/cformview-class.md)   
 [Classe de CControlBar](../../mfc/reference/ccontrolbar-class.md)