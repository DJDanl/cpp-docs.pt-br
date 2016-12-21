---
title: "Classe de CMFCPropertyGridCtrl | Microsoft Docs"
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
  - "CMFCPropertyGridCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCPropertyGridCtrl"
  - "Método de CMFCPropertyGridCtrl::accHitTest"
  - "Método de CMFCPropertyGridCtrl::accLocation"
  - "Método de CMFCPropertyGridCtrl::get_accChild"
  - "Método de CMFCPropertyGridCtrl::get_accDefaultAction"
  - "Método de CMFCPropertyGridCtrl::get_accDescription"
  - "Método de CMFCPropertyGridCtrl::get_accName"
  - "Método de CMFCPropertyGridCtrl::get_accRole"
  - "Método de CMFCPropertyGridCtrl::get_accState"
  - "Método de CMFCPropertyGridCtrl::get_accValue"
  - "Método de CMFCPropertyGridCtrl::PreTranslateMessage"
ms.assetid: 95877cae-2311-4a2a-9031-0c8c3cf0a5f9
caps.latest.revision: 35
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCPropertyGridCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
 Suporta um controle de grade editável de propriedade que pode exibir propriedades em ordem alfabética ou hierárquica.  
  
## Sintaxe  
  
```  
class CMFCPropertyGridCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPropertyGridCtrl::CMFCPropertyGridCtrl](../Topic/CMFCPropertyGridCtrl::CMFCPropertyGridCtrl.md)|Constrói um objeto de `CMFCPropertyGridCtrl` .|  
|`CMFCPropertyGridCtrl::~CMFCPropertyGridCtrl`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCPropertyGridCtrl::accHitTest`|Chamado pela estrutura para recuperar o elemento filho ou o objeto filho em um determinado ponto na tela.  Overrides \( [CWnd::accHitTest](../Topic/CWnd::accHitTest.md).\)|  
|`CMFCPropertyGridCtrl::accLocation`|Chamado pela estrutura para recuperar o local atual da tela do objeto especificado.  Overrides \( [CWnd::accLocation](../Topic/CWnd::accLocation.md).\)|  
|[CMFCPropertyGridCtrl::accSelect](../Topic/CMFCPropertyGridCtrl::accSelect.md)|Chamado pela estrutura para alterar a seleção ou mover o foco do teclado do objeto especificado.  Overrides \( [CWnd::accSelect](../Topic/CWnd::accSelect.md).\)|  
|[CMFCPropertyGridCtrl::AddProperty](../Topic/CMFCPropertyGridCtrl::AddProperty.md)|Adiciona uma nova propriedade para um controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::AlwaysShowUserToolTip](../Topic/CMFCPropertyGridCtrl::AlwaysShowUserToolTip.md)||  
|[CMFCPropertyGridCtrl::CloseColorPopup](../Topic/CMFCPropertyGridCtrl::CloseColorPopup.md)|Fechar a caixa de diálogo de seleção de cor.|  
|[CMFCPropertyGridCtrl::Create](../Topic/CMFCPropertyGridCtrl::Create.md)|Cria um controle de grade de propriedade e anexá\-la ao objeto do controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::DeleteProperty](../Topic/CMFCPropertyGridCtrl::DeleteProperty.md)|Exclui a propriedade especificada do controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::DrawControlBarColors](../Topic/CMFCPropertyGridCtrl::DrawControlBarColors.md)||  
|[CMFCPropertyGridCtrl::EnableDescriptionArea](../Topic/CMFCPropertyGridCtrl::EnableDescriptionArea.md)|Habilita ou desabilita a área de descrição que é exibida abaixo da lista de propriedades.|  
|[CMFCPropertyGridCtrl::EnableHeaderCtrl](../Topic/CMFCPropertyGridCtrl::EnableHeaderCtrl.md)|Habilita ou desabilita o controle de cabeçalho na parte superior do controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::EnsureVisible](../Topic/CMFCPropertyGridCtrl::EnsureVisible.md)|Colocar um controle de grade de propriedade e expande itens da propriedade até que a propriedade especificada seja visível.|  
|[CMFCPropertyGridCtrl::ExpandAll](../Topic/CMFCPropertyGridCtrl::ExpandAll.md)|Expande ou recolhe todos os nós do controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::FindItemByData](../Topic/CMFCPropertyGridCtrl::FindItemByData.md)|Recupera a propriedade que está associada com um valor definido pelo usuário de `DWORD` .|  
|`CMFCPropertyGridCtrl::get_accChild`|Chamado pela estrutura para recuperar o endereço de uma interface de `IDispatch` para o filho especificado.  Overrides \( [CWnd::get\_accChild](../Topic/CWnd::get_accChild.md).\)|  
|[CMFCPropertyGridCtrl::get\_accChildCount](../Topic/CMFCPropertyGridCtrl::get_accChildCount.md)|Chamado pela estrutura para recuperar o número de filhos que pertencem a esse objeto.  Overrides \( [CWnd::get\_accChildCount](../Topic/CWnd::get_accChildCount.md).\)|  
|`CMFCPropertyGridCtrl::get_accDefaultAction`|Chamado pela estrutura para recuperar uma cadeia de caracteres que descreve a ação default do objeto.  Overrides \( [CWnd::get\_accDefaultAction](../Topic/CWnd::get_accDefaultAction.md).\)|  
|`CMFCPropertyGridCtrl::get_accDescription`|Chamado pela estrutura para recuperar uma cadeia de caracteres que descreve a aparência visual do objeto especificado.  Overrides \( [CWnd::get\_accDescription](../Topic/CWnd::get_accDescription.md).\)|  
|[CMFCPropertyGridCtrl::get\_accFocus](../Topic/CMFCPropertyGridCtrl::get_accFocus.md)|Chamado pela estrutura para recuperar o objeto que tem o foco do teclado.  Overrides \( [CWnd::get\_accFocus](../Topic/CWnd::get_accFocus.md).\)|  
|[CMFCPropertyGridCtrl::get\_accHelp](../Topic/CMFCPropertyGridCtrl::get_accHelp.md)|Chamado pela estrutura para recuperar a cadeia de caracteres de propriedade de `Help` de um objeto.  Overrides \( [CWnd::get\_accHelp](../Topic/CWnd::get_accHelp.md).\)|  
|[CMFCPropertyGridCtrl::get\_accHelpTopic](../Topic/CMFCPropertyGridCtrl::get_accHelpTopic.md)|Chamado pela estrutura para recuperar o caminho completo do arquivo de `WinHelp`associado ao objeto especificado e o identificador do tópico apropriado dentro de esse arquivo.  Overrides \( [CWnd::get\_accHelpTopic](../Topic/CWnd::get_accHelpTopic.md).\)|  
|[CMFCPropertyGridCtrl::get\_accKeyboardShortcut](../Topic/CMFCPropertyGridCtrl::get_accKeyboardShortcut.md)|Chamado pela estrutura para recuperar a chave ou a tecla de acesso de atalho do objeto especificado.  Overrides \( [CWnd::get\_accKeyboardShortcut](../Topic/CWnd::get_accKeyboardShortcut.md).\)|  
|`CMFCPropertyGridCtrl::get_accName`|Chamado pela estrutura para recuperar o nome do objeto especificado.  Overrides \( [CWnd::get\_accName](../Topic/CWnd::get_accName.md).\)|  
|`CMFCPropertyGridCtrl::get_accRole`|Chamado pela estrutura para recuperar informações que descrevem a função do objeto especificado.  Overrides \( [CWnd::get\_accRole](../Topic/CWnd::get_accRole.md).\)|  
|[CMFCPropertyGridCtrl::get\_accSelection](../Topic/CMFCPropertyGridCtrl::get_accSelection.md)|Chamado pela estrutura para recuperar os filhos de este objeto selecionados.  Overrides \( [CWnd::get\_accSelection](../Topic/CWnd::get_accSelection.md).\)|  
|`CMFCPropertyGridCtrl::get_accState`|Chamado pela estrutura para recuperar o estado atual do objeto especificado.  Overrides \( [CWnd::get\_accState](../Topic/CWnd::get_accState.md).\)|  
|`CMFCPropertyGridCtrl::get_accValue`|Chamado pela estrutura para recuperar o valor do objeto especificado.  Overrides \( [CWnd::get\_accValue](../Topic/CWnd::get_accValue.md).\)|  
|[CMFCPropertyGridCtrl::GetBkColor](../Topic/CMFCPropertyGridCtrl::GetBkColor.md)|Recupera a cor do plano de fundo do controle de grade atual da propriedade.|  
|[CMFCPropertyGridCtrl::GetBoldFont](../Topic/CMFCPropertyGridCtrl::GetBoldFont.md)|Recupera a fonte do windows que o texto no controle de grade atual da propriedade para o estilo em negrito.|  
|[CMFCPropertyGridCtrl::GetCurSel](../Topic/CMFCPropertyGridCtrl::GetCurSel.md)|Recupera a propriedade selecionada.|  
|[CMFCPropertyGridCtrl::GetCustomColors](../Topic/CMFCPropertyGridCtrl::GetCustomColors.md)|Recupera as cores personalizados que são definidas no momento para elementos de controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::GetDescriptionHeight](../Topic/CMFCPropertyGridCtrl::GetDescriptionHeight.md)|Recupera a altura da área de descrição localizada na parte inferior do controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::GetDescriptionRows](../Topic/CMFCPropertyGridCtrl::GetDescriptionRows.md)|Retorna o número de linhas na área de descrição de um controle de grade atual da propriedade.|  
|[CMFCPropertyGridCtrl::GetHeaderCtrl](../Topic/CMFCPropertyGridCtrl::GetHeaderCtrl.md)|Retorna o objeto interno de [CMFCHeaderCtrl](../Topic/CMFCHeaderCtrl%20Class.md) que a estrutura usa para exibir o controle de grade atual da propriedade.|  
|[CMFCPropertyGridCtrl::GetHeaderHeight](../Topic/CMFCPropertyGridCtrl::GetHeaderHeight.md)|Recupera a altura do cabeçalho do controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::GetLeftColumnWidth](../Topic/CMFCPropertyGridCtrl::GetLeftColumnWidth.md)|Obtém a largura da coluna esquerda do controle de grade atual da propriedade, que contém o nome de cada propriedade.|  
|[CMFCPropertyGridCtrl::GetListRect](../Topic/CMFCPropertyGridCtrl::GetListRect.md)|Recupera o retângulo delimitador do controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::GetProperty](../Topic/CMFCPropertyGridCtrl::GetProperty.md)|Recupera um ponteiro para o objeto da propriedade correspondente ao índice especificado de um item do controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::GetPropertyColumnWidth](../Topic/CMFCPropertyGridCtrl::GetPropertyColumnWidth.md)|Obtém a largura atual da coluna que contém valores de propriedade.|  
|[CMFCPropertyGridCtrl::GetPropertyCount](../Topic/CMFCPropertyGridCtrl::GetPropertyCount.md)|Retorna o número de propriedades em um controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::GetRowHeight](../Topic/CMFCPropertyGridCtrl::GetRowHeight.md)|Recupera a altura de uma linha no controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::GetScrollBarCtrl](../Topic/CMFCPropertyGridCtrl::GetScrollBarCtrl.md)|Recupera um ponteiro para o controle de barra de rolagem no controle de grade de propriedade.  Overrides \( [CWnd::GetScrollBarCtrl](../Topic/CWnd::GetScrollBarCtrl.md).\)|  
|[CMFCPropertyGridCtrl::GetTextColor](../Topic/CMFCPropertyGridCtrl::GetTextColor.md)|Recupera a cor do texto de itens da propriedade no controle de grade atual da propriedade.|  
|`CMFCPropertyGridCtrl::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCPropertyGridCtrl::HitTest](../Topic/CMFCPropertyGridCtrl::HitTest.md)|Recupera um ponteiro para o objeto de propriedade que corresponde a um item do controle de grade de propriedade se um ponto está especificado no item.  Esse método também indica a área no controle de grade de propriedade que contém o ponto.|  
|[CMFCPropertyGridCtrl::InitHeader](../Topic/CMFCPropertyGridCtrl::InitHeader.md)|Inicializa o objeto interno de [CMFCHeaderCtrl](../Topic/CMFCHeaderCtrl%20Class.md) que a estrutura usa para exibir o controle de grade atual da propriedade.|  
|[CMFCPropertyGridCtrl::IsAlphabeticMode](../Topic/CMFCPropertyGridCtrl::IsAlphabeticMode.md)|Indica se um controle de grade de propriedade está no modo alfabética.|  
|[CMFCPropertyGridCtrl::IsAlwaysShowUserToolTip](../Topic/CMFCPropertyGridCtrl::IsAlwaysShowUserToolTip.md)||  
|[CMFCPropertyGridCtrl::IsDescriptionArea](../Topic/CMFCPropertyGridCtrl::IsDescriptionArea.md)|Indica se a área de descrição de um controle de grade de propriedade é exibida.|  
|[CMFCPropertyGridCtrl::IsGroupNameFullWidth](../Topic/CMFCPropertyGridCtrl::IsGroupNameFullWidth.md)|Indica se cada nome de grupo de propriedades é exibido pela largura do controle de grade atual da propriedade.|  
|[CMFCPropertyGridCtrl::IsHeaderCtrl](../Topic/CMFCPropertyGridCtrl::IsHeaderCtrl.md)|Indica se o controle de cabeçalho é exibido.|  
|[CMFCPropertyGridCtrl::IsMarkModifiedProperties](../Topic/CMFCPropertyGridCtrl::IsMarkModifiedProperties.md)|Indica como o controle de grade de propriedade exibe propriedades alteradas.|  
|[CMFCPropertyGridCtrl::IsShowDragContext](../Topic/CMFCPropertyGridCtrl::IsShowDragContext.md)|Indica se a estrutura redesenho nome das colunas e o valor do controle de grade atual da propriedade quando um usuário redimensionar colunas.|  
|[CMFCPropertyGridCtrl::IsVSDotNetLook](../Topic/CMFCPropertyGridCtrl::IsVSDotNetLook.md)|Indica se a aparência do controle de grade de propriedade está no estilo que é usado por CONTRA .NET.|  
|[CMFCPropertyGridCtrl::MarkModifiedProperties](../Topic/CMFCPropertyGridCtrl::MarkModifiedProperties.md)|Especifica como exibir propriedades alteradas.|  
|`CMFCPropertyGridCtrl::PreTranslateMessage`|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) transladar mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Overrides \( [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md).\)|  
|[CMFCPropertyGridCtrl::RemoveAll](../Topic/CMFCPropertyGridCtrl::RemoveAll.md)|Remove todos os objetos da propriedade de um controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::ResetOriginalValues](../Topic/CMFCPropertyGridCtrl::ResetOriginalValues.md)|Restaura o valor original de todas as propriedades.|  
|[CMFCPropertyGridCtrl::SetAlphabeticMode](../Topic/CMFCPropertyGridCtrl::SetAlphabeticMode.md)|Define ou alfabético modo de redefinições.|  
|[CMFCPropertyGridCtrl::SetBoolLabels](../Topic/CMFCPropertyGridCtrl::SetBoolLabels.md)|Especifica o texto de rótulos booleanos.|  
|[CMFCPropertyGridCtrl::SetCurSel](../Topic/CMFCPropertyGridCtrl::SetCurSel.md)|Seleciona uma propriedade em um controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::SetCustomColors](../Topic/CMFCPropertyGridCtrl::SetCustomColors.md)|Especifica cores personalizado para os vários elementos de controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::SetDescriptionRows](../Topic/CMFCPropertyGridCtrl::SetDescriptionRows.md)|Especifica o número de linhas para exibir na seção de descrição de um controle de grade atual da propriedade.|  
|[CMFCPropertyGridCtrl::SetGroupNameFullWidth](../Topic/CMFCPropertyGridCtrl::SetGroupNameFullWidth.md)|Especifica se mostrar a largura total de nome de categoria para um grupo de propriedades do controle de grade atual da propriedade.|  
|[CMFCPropertyGridCtrl::SetListDelimiter](../Topic/CMFCPropertyGridCtrl::SetListDelimiter.md)|Define um caractere usado como um delimitador em uma lista de valores de propriedade.|  
|[CMFCPropertyGridCtrl::SetShowDragContext](../Topic/CMFCPropertyGridCtrl::SetShowDragContext.md)|Especifica se a estrutura redesenho nome das colunas e o valor do controle de grade atual da propriedade quando um usuário redimensionar colunas.|  
|[CMFCPropertyGridCtrl::SetVSDotNetLook](../Topic/CMFCPropertyGridCtrl::SetVSDotNetLook.md)|Define a aparência do controle de grade de propriedade para o estilo que é usado em CONTRA .NET.|  
|[CMFCPropertyGridCtrl::UpdateColor](../Topic/CMFCPropertyGridCtrl::UpdateColor.md)|Defina o valor de cor da propriedade de cor selecionada.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPropertyGridCtrl::AdjustLayout](../Topic/CMFCPropertyGridCtrl::AdjustLayout.md)|Redesenho do controle grade de propriedade e suas propriedades.|  
|[CMFCPropertyGridCtrl::CompareProps](../Topic/CMFCPropertyGridCtrl::CompareProps.md)|Chamado pelo controle de grade de propriedades para classificar propriedades.|  
|[CMFCPropertyGridCtrl::EditItem](../Topic/CMFCPropertyGridCtrl::EditItem.md)|Chamado pela estrutura quando o usuário para alterar uma propriedade.|  
|[CMFCPropertyGridCtrl::EndEditItem](../Topic/CMFCPropertyGridCtrl::EndEditItem.md)|Chamado pela estrutura quando o usuário parar de alterar uma propriedade.|  
|[CMFCPropertyGridCtrl::Init](../Topic/CMFCPropertyGridCtrl::Init.md)|Chamado pela estrutura para inicializar um controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::OnChangeSelection](../Topic/CMFCPropertyGridCtrl::OnChangeSelection.md)|Chamado pela estrutura quando a seleção atual é alterada.|  
|[CMFCPropertyGridCtrl::OnClickButton](../Topic/CMFCPropertyGridCtrl::OnClickButton.md)|Chamado pela estrutura de propriedade quando um botão é clicado.|  
|[CMFCPropertyGridCtrl::OnDrawBorder](../Topic/CMFCPropertyGridCtrl::OnDrawBorder.md)|Chamado pela estrutura para desenhar uma borda ao redor de um controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::OnDrawDescription](../Topic/CMFCPropertyGridCtrl::OnDrawDescription.md)|Chamado pela estrutura para desenhar a área de descrição e para exibir a descrição.|  
|[CMFCPropertyGridCtrl::OnDrawList](../Topic/CMFCPropertyGridCtrl::OnDrawList.md)|Chamado pela estrutura para exibir a lista de propriedades do controle de grade de propriedade.|  
|[CMFCPropertyGridCtrl::OnDrawProperty](../Topic/CMFCPropertyGridCtrl::OnDrawProperty.md)|Chamado pela estrutura para exibir uma propriedade.|  
|[CMFCPropertyGridCtrl::OnPropertyChanged](../Topic/CMFCPropertyGridCtrl::OnPropertyChanged.md)|Chamado pela estrutura quando o valor de uma propriedade é alterado.|  
|[CMFCPropertyGridCtrl::OnSelectCombo](../Topic/CMFCPropertyGridCtrl::OnSelectCombo.md)|Chamado pela estrutura quando uma propriedade que contém um controle caixa de combinação está marcada.|  
|[CMFCPropertyGridCtrl::ValidateItemData](../Topic/CMFCPropertyGridCtrl::ValidateItemData.md)|Chamado pela estrutura para validar dados da propriedade.|  
  
## Comentários  
 Exibe de classe de `CMFCPropertyGridCtrl` um controle de grade de propriedade que contém as propriedades editáveis derivadas de classes de [CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md) .  Cada propriedade pode representar um tipo e pode conter sub\-itens.  O controle de grade de propriedade suporta uma área redimensionável na parte inferior que pode exibir a descrição de uma propriedade selecionada.  
  
 Para usar um controle de grade de propriedade, construir um objeto de `CMFCPropertyGridCtrl` e então chame o método de [CMFCPropertyGridCtrl::Create](../Topic/CMFCPropertyGridCtrl::Create.md) .  Use o método de [CMFCPropertyGridCtrl::AddProperty](../Topic/CMFCPropertyGridCtrl::AddProperty.md) para adicionar propriedades à lista.  
  
## Propriedades de seleção  
 Em vez de representar um valor, um item propriedade pode iniciar uma caixa de diálogo que permite que o usuário selecione uma cor, um arquivo, ou uma fonte.  
  
 A tabela a seguir lista quatro tipos de propriedades de seleção:  
  
|Classe|Descrição|  
|------------|---------------|  
|[Classe de CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)|Uma propriedade comumente usados que é usada para especificar o valor de cadeias de caracteres, Booleans datas, e assim por diante.|  
|[Classe de CMFCPropertyGridColorProperty](../Topic/CMFCPropertyGridColorProperty%20Class.md)|Uma propriedade que é usada para selecionar um valor de cor.|  
|[Classe de CMFCPropertyGridFileProperty](../Topic/CMFCPropertyGridFileProperty%20Class.md)|Uma propriedade que é usada para selecionar um arquivo.|  
|[Classe de CMFCPropertyGridFontProperty](../../mfc/reference/cmfcpropertygridfontproperty-class.md)|Uma propriedade que é usada para selecionar uma fonte.|  
  
## Ilustrações  
 As ilustrações a seguir descrevem um controle de grade de propriedade que exibe as propriedades de duas maneiras.  A primeira ilustração exibe as propriedades hierarquicamente e a segunda exibe propriedades em ordem alfabética.  
  
 ![PropertySheet de lista](../../mfc/reference/media/proplist.png "PropList")  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar um objeto do controle de grade de propriedade usando vários métodos na classe de `CMFCPropertyGridCtrl` .  O exemplo demonstra como habilitar o controle de cabeçalho, permite a área de descrição, e define a aparência do controle de grade de propriedade.  O exemplo também mostra como definir o modo alfabético para o controle por meio de classes que o controle todas as propriedades que contém pelo nome de propriedade, e como definir as cores personalizado para vários elementos de controle de grade de propriedade.  Este exemplo é parte de [novo exemplo de controles](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_NewControls#14](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#14)]  
[!CODE [NVC_MFC_NewControls#16](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#16)]  
[!CODE [NVC_MFC_NewControls#20](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#20)]  
[!CODE [NVC_MFC_NewControls#21](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#21)]  
[!CODE [NVC_MFC_NewControls#24](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#24)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxpropertygridctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)