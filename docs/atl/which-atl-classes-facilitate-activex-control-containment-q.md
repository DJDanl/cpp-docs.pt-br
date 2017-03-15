---
title: "Quais Classes ATL facilitam a conten&#231;&#227;o de controle ActiveX? | Microsoft Docs"
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
  - "hospedando controles usando a ATL"
  - "Hospedagem de controles de contêineres de controle ActiveX [C++], ATL"
ms.assetid: 803a4605-7f4c-4139-8638-49d8783d31b0
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Quais Classes ATL facilitam a conten&#231;&#227;o de controle ActiveX?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Código de hospedagem de controles da ATL não exige que você use as classes ATL; Você pode simplesmente criar um **"AtlAxWin80"** janela e use a API de hospedagem de controles, se necessário \(para obter mais informações, consulte [o que é a API de hospedagem de controle ATL?](../atl/what-is-the-atl-control-hosting-api-q.md)\). No entanto, as seguintes classes de tornam os recursos de contenção mais fácil de usar.  
  
|Classe|Descrição|  
|------------|---------------|  
|[CAxWindow](../atl/reference/caxwindow-class.md)|Encapsula uma **"AtlAxWin80"** janela, fornecendo métodos para criar a janela, criando um controle de e\/ou anexar um controle para a janela e recuperar ponteiros de interface no objeto de host.|  
|[CAxWindow2T](../Topic/CAxWindow2T%20Class.md)|Encapsula uma **"AtlAxWinLic80"** janela, fornecendo métodos para criar a janela, criando um controle de e\/ou anexar um controle licenciado para a janela e recuperar ponteiros de interface no objeto de host.|  
|[CComCompositeControl](../atl/reference/ccomcompositecontrol-class.md)|Atua como uma classe base para classes de controle ActiveX com base em um recurso de caixa de diálogo. Esses controles podem conter outros controles ActiveX.|  
|[CAxDialogImpl](../Topic/CAxDialogImpl%20Class.md)|Atua como uma classe base para classes de caixa de diálogo com base em um recurso de caixa de diálogo. Essas caixas de diálogo podem conter controles ActiveX.|  
|[CWindow](../atl/reference/cwindow-class.md)|Fornece um método [GetDlgControl](../Topic/CWindow::GetDlgControl.md), que retorna um ponteiro de interface em um controle, dado a ID de sua janela de host. Além disso, os invólucros da API do Windows é exposto pelo `CWindow` geralmente facilitar o gerenciamento de janela.|  
  
## Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)