---
title: "Classe de COlePropertyPage | Microsoft Docs"
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
  - "COlePropertyPage"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COlePropertyPage"
  - "controles personalizados [MFC], propriedades"
  - "exibindo propriedades"
  - "Páginas de propriedades VELHOS"
  - "propriedades [C++], exibir"
  - "páginas de propriedades, O OLE"
ms.assetid: e9972872-8e6b-4550-905e-d36a274d64dc
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COlePropertyPage
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para exibir as propriedades de um controle personalizado em uma interface gráfica, semelhante a uma caixa de diálogo.  
  
## Sintaxe  
  
```  
class AFX_NOVTABLE COlePropertyPage : public CDialog  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COlePropertyPage::COlePropertyPage](../Topic/COlePropertyPage::COlePropertyPage.md)|Constrói um objeto de `COlePropertyPage` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COlePropertyPage::GetControlStatus](../Topic/COlePropertyPage::GetControlStatus.md)|Indica se o usuário alterou o valor no controle.|  
|[COlePropertyPage::GetObjectArray](../Topic/COlePropertyPage::GetObjectArray.md)|Retorna a matriz de objetos que estão sendo editados pela página de propriedades.|  
|[COlePropertyPage::GetPageSite](../Topic/COlePropertyPage::GetPageSite.md)|Retorna um ponteiro para a interface de `IPropertyPageSite` da página de propriedades.|  
|[COlePropertyPage::IgnoreApply](../Topic/COlePropertyPage::IgnoreApply.md)|Determina quais controles não permitem o botão aplicar.|  
|[COlePropertyPage::IsModified](../Topic/COlePropertyPage::IsModified.md)|Indica se o usuário alterou a página de propriedades.|  
|[COlePropertyPage::OnEditProperty](../Topic/COlePropertyPage::OnEditProperty.md)|Chamado pela estrutura quando o usuário edita uma propriedade.|  
|[COlePropertyPage::OnHelp](../Topic/COlePropertyPage::OnHelp.md)|Chamado pela estrutura quando o usuário chamar a ajuda.|  
|[COlePropertyPage::OnInitDialog](../Topic/COlePropertyPage::OnInitDialog.md)|Chamado pela estrutura quando a página de propriedades é inicializada.|  
|[COlePropertyPage::OnObjectsChanged](../Topic/COlePropertyPage::OnObjectsChanged.md)|Chamado pela estrutura quando outro controlador OLE, com as novas propriedades, é escolhido.|  
|[COlePropertyPage::OnSetPageSite](../Topic/COlePropertyPage::OnSetPageSite.md)|Chamado pela estrutura quando o quadro de propriedade fornecer ao site da página.|  
|[COlePropertyPage::SetControlStatus](../Topic/COlePropertyPage::SetControlStatus.md)|Define um sinalizador que indica se o usuário alterou o valor no controle.|  
|[COlePropertyPage::SetDialogResource](../Topic/COlePropertyPage::SetDialogResource.md)|Define o recurso da caixa de diálogo da página de propriedades.|  
|[COlePropertyPage::SetHelpInfo](../Topic/COlePropertyPage::SetHelpInfo.md)|Define o texto de ajuda da página de propriedades o breve, o nome do arquivo de ajuda, e o contexto da ajuda.|  
|[COlePropertyPage::SetModifiedFlag](../Topic/COlePropertyPage::SetModifiedFlag.md)|Define um sinalizador que indica se o usuário alterou a página de propriedades.|  
|[COlePropertyPage::SetPageName](../Topic/COlePropertyPage::SetPageName.md)|Define o nome da página de propriedades \(legenda\).|  
  
## Comentários  
 Por exemplo, uma página de propriedades pode incluir um controle de edição que permite que o usuário exiba e altere a propriedade da legenda do controle.  
  
 Cada propriedade personalizada ou controle estoque pode ter um controle de caixa de diálogo que permite que o usuário do controle exibe o valor atual da propriedade e modificar esse valor se necessário.  
  
 Para obter mais informações sobre como usar `COlePropertyPage`, consulte o artigo [Controles ActiveX: Páginas de Propriedade](../../mfc/mfc-activex-controls-property-pages.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 `COlePropertyPage`  
  
## Requisitos  
 **Cabeçalho:** afxctl.h  
  
## Consulte também  
 [O MFC exemplos CIRC3](../../top/visual-cpp-samples.md)   
 [Exemplo TESTHELP MFC](../../top/visual-cpp-samples.md)   
 [Classe de CDialog](../../mfc/reference/cdialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDialog](../../mfc/reference/cdialog-class.md)