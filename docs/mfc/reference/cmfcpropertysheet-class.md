---
title: "Classe de CMFCPropertySheet | Microsoft Docs"
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
  - "CMFCPropertySheet"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCPropertySheet"
  - "Método de CMFCPropertySheet::OnInitDialog"
  - "Método de CMFCPropertySheet::PreTranslateMessage"
ms.assetid: 01d93573-9698-440f-a6a4-5bebbee879dc
caps.latest.revision: 35
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCPropertySheet
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `CMFCPropertySheet` classe oferece suporte a uma folha de propriedades em que cada página de propriedade é indicada por uma guia de página, um botão de barra de ferramentas, um nó de controle de árvore ou um item de lista.  
  
## Sintaxe  
  
```  
class CMFCPropertySheet : public CPropertySheet  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPropertySheet::CMFCPropertySheet](../Topic/CMFCPropertySheet::CMFCPropertySheet.md)|Constrói um objeto `CMFCPropertySheet`.|  
|`CMFCPropertySheet::~CMFCPropertySheet`|Destruidor.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPropertySheet::AddPage](../Topic/CMFCPropertySheet::AddPage.md)|Adiciona uma página para a folha de propriedades.|  
|[CMFCPropertySheet::AddPageToTree](../Topic/CMFCPropertySheet::AddPageToTree.md)|Adiciona uma nova página de propriedade para o controle de árvore.|  
|[CMFCPropertySheet::AddTreeCategory](../Topic/CMFCPropertySheet::AddTreeCategory.md)|Adiciona um novo nó ao controle de árvore.|  
|[CMFCPropertySheet::EnablePageHeader](../Topic/CMFCPropertySheet::EnablePageHeader.md)|Reserva espaço na parte superior de cada página para desenhar um cabeçalho personalizado.|  
|[CMFCPropertySheet::GetHeaderHeight](../Topic/CMFCPropertySheet::GetHeaderHeight.md)|Recupera a altura do cabeçalho atual.|  
|[CMFCPropertySheet::GetLook](../Topic/CMFCPropertySheet::GetLook.md)|Recupera um valor de enumeração que especifica a aparência da folha de propriedades atual.|  
|[CMFCPropertySheet::GetNavBarWidth](../Topic/CMFCPropertySheet::GetNavBarWidth.md)|Repete a largura da barra de navegação, em pixels.|  
|[CMFCPropertySheet::GetTab](../Topic/CMFCPropertySheet::GetTab.md)|Recupera o objeto de controle de guia interna que oferece suporte ao controle de folha de propriedade atual.|  
|`CMFCPropertySheet::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) objeto associado esse tipo de classe.|  
|[CMFCPropertySheet::InitNavigationControl](../Topic/CMFCPropertySheet::InitNavigationControl.md)|Inicializa a aparência do controle de planilha de propriedade atual.|  
|[CMFCPropertySheet::OnActivatePage](../Topic/CMFCPropertySheet::OnActivatePage.md)|Chamado pela estrutura quando uma página de propriedades está habilitada.|  
|[CMFCPropertySheet::OnDrawPageHeader](../Topic/CMFCPropertySheet::OnDrawPageHeader.md)|Chamado pela estrutura para desenhar um cabeçalho de página de propriedade personalizada.|  
|`CMFCPropertySheet::OnInitDialog`|Manipula o [WM\_INITDIALOG](http://msdn.microsoft.com/library/windows/desktop/ms645428) mensagem.  \(Substitui [CPropertySheet::OnInitDialog](../Topic/CPropertySheet::OnInitDialog.md).\)|  
|[CMFCPropertySheet::OnRemoveTreePage](../Topic/CMFCPropertySheet::OnRemoveTreePage.md)|Chamado pela estrutura para remover uma página de propriedades de um controle de árvore.|  
|`CMFCPropertySheet::PreTranslateMessage`|Converte as mensagens da janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows.  \(Substitui `CPropertySheet::PreTranslateMessage`.\)|  
|[CMFCPropertySheet::RemoveCategory](../Topic/CMFCPropertySheet::RemoveCategory.md)|Remove um nó de controle de árvore.|  
|[CMFCPropertySheet::RemovePage](../Topic/CMFCPropertySheet::RemovePage.md)|Remove uma página de propriedades da folha de propriedades.|  
|[CMFCPropertySheet::SetIconsList](../Topic/CMFCPropertySheet::SetIconsList.md)|Especifica a lista de imagens que são usados no controle de navegação do painel de tarefas do Outlook.|  
|[CMFCPropertySheet::SetLook](../Topic/CMFCPropertySheet::SetLook.md)|Especifica a aparência da folha de propriedades.|  
  
## Comentários  
 O `CMFCPropertySheet` classe representa folhas de propriedades, também conhecido como caixas de diálogo de guia.  O `CMFCPropertySheet` classe pode exibir uma página de propriedades de várias maneiras.  
  
 Execute as seguintes etapas para usar o `CMFCPropertySheet` classe em seu aplicativo:  
  
1.  Derivar uma classe a partir de `CMFCPropertySheet` classe e o nome da classe, por exemplo, CMyPropertySheet.  
  
2.  Construir uma [CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md) objeto para cada página de propriedade.  
  
3.  Chamar o [CMFCPropertySheet::SetLook](../Topic/CMFCPropertySheet::SetLook.md) método no construtor CMyPropertySheet.  Um parâmetro do método Especifica que as páginas de propriedade devem ser exibidas como guias na parte superior ou esquerda da folha de propriedades; guias no estilo de uma folha de propriedades do Microsoft OneNote; botões em um controle de barra de ferramentas do Microsoft Outlook; nós em um controle de árvore; ou como uma lista de itens no lado esquerdo da folha de propriedades.  
  
4.  Se você criar uma folha de propriedades no estilo de uma barra de ferramentas do Microsoft Outlook, chame o [CMFCPropertySheet::SetIconsList](../Topic/CMFCPropertySheet::SetIconsList.md) método para associar uma lista de imagens em conjunto com as páginas de propriedades.  
  
5.  Chamar o [CMFCPropertySheet::AddPage](../Topic/CMFCPropertySheet::AddPage.md) método para cada página de propriedades.  
  
6.  Criar um `CMFCPropertySheet` controlar e chamar seu `DoModal` método.  
  
## Ilustrações  
 A ilustração a seguir mostra uma folha de propriedades está no estilo de uma barra de ferramentas do Microsoft Outlook incorporado.  A barra de ferramentas do Outlook aparece no lado esquerdo da folha de propriedades.  
  
 ![Controles de cor CMFCPropertySheet](../../mfc/reference/media/cmfcpropertysheet_color.png "cmfcpropertysheet\_color")  
  
 A ilustração a seguir mostra uma folha de propriedades contém um [Classe de CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md) objeto.  Esse objeto é uma folha de propriedades no estilo de uma folha de propriedades de controles comuns padrão.  
  
 ![Controles de lista e a propriedade CMFCPropertySheet](../../mfc/reference/media/cmfcpropertysheet_list.png "cmfcpropertysheet\_list")  
  
 A ilustração a seguir mostra uma folha de propriedades está no estilo de um controle de árvore.  
  
 ![Árvore de propriedades](../Image/PropTree.png "PropTree")  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CPropertySheet](../../mfc/reference/cpropertysheet-class.md)  
  
 [CMFCPropertySheet](../../mfc/reference/cmfcpropertysheet-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxpropertysheet.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCPropertyPage](../../mfc/reference/cmfcpropertypage-class.md)   
 [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)