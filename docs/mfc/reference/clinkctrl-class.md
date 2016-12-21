---
title: "Classe de CLinkCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CLinkCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CLinkCtrl"
  - "controles [MFC], links"
  - "links [C++], controle de link"
  - "Controle de SysLink"
  - "Páginas da Web, controle de link"
ms.assetid: d1cd876a-ecca-42db-8ac4-9cd327df0cd4
caps.latest.revision: 23
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CLinkCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle comum de SysLink do windows.  
  
## Sintaxe  
  
```  
class CLinkCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLinkCtrl::CLinkCtrl](../Topic/CLinkCtrl::CLinkCtrl.md)|Constrói um objeto de `CLinkCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CLinkCtrl::Create](../Topic/CLinkCtrl::Create.md)|Cria um controle de link e anexá\-la a um objeto de `CLinkCtrl` .|  
|[CLinkCtrl::CreateEx](../Topic/CLinkCtrl::CreateEx.md)|Cria um controle de link com os estilos estendidos e anexá\-la a um objeto de `CLinkCtrl` .|  
|[CLinkCtrl::GetIdealHeight](../Topic/CLinkCtrl::GetIdealHeight.md)|Recupera a altura ideal de controle de link.|  
|[CLinkCtrl::GetIdealSize](../Topic/CLinkCtrl::GetIdealSize.md)|Calcula a altura preferencial de texto de link para o controle de link atual, dependendo da largura especificada de link.|  
|[CLinkCtrl::GetItem](../Topic/CLinkCtrl::GetItem.md)|Recupera os estados e atributos de um item de controle de link.|  
|[CLinkCtrl::GetItemID](../Topic/CLinkCtrl::GetItemID.md)|Recupera a identificação de um item de controle de link.|  
|[CLinkCtrl::GetItemState](../Topic/CLinkCtrl::GetItemState.md)|Recupera o estado do item de controle de link.|  
|[CLinkCtrl::GetItemUrl](../Topic/CLinkCtrl::GetItemUrl.md)|Recupera o URL representado pelo item de controle de link.|  
|[CLinkCtrl::HitTest](../Topic/CLinkCtrl::HitTest.md)|Determina se o usuário clicou no link especificado.|  
|[CLinkCtrl::SetItem](../Topic/CLinkCtrl::SetItem.md)|Defina os estados e atributos de um item de controle de link.|  
|[CLinkCtrl::SetItemID](../Topic/CLinkCtrl::SetItemID.md)|Define a identificação de um item de controle de link.|  
|[CLinkCtrl::SetItemState](../Topic/CLinkCtrl::SetItemState.md)|Define o estado do item de controle de link.|  
|[CLinkCtrl::SetItemUrl](../Topic/CLinkCtrl::SetItemUrl.md)|Define o URL representado pelo item de controle de link.|  
  
## Comentários  
 Um link de “controle” fornece uma maneira conveniente de inserir os links de hypertext em uma janela.  O controle real é uma janela que renderiza o texto marcado \- acima e inicia aplicativos apropriados quando o usuário clica em um link inserido.  Vários links são suportados em um controle e podem ser acessados por um índice com base zero.  
  
 Este controle \(e portanto a classe de `CLinkCtrl` \) estão disponíveis somente para programas que executam no Windows XP e posteriormente.  
  
 Para obter mais informações, consulte [controle de SysLink](http://msdn.microsoft.com/library/windows/desktop/bb760706) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CLinkCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)