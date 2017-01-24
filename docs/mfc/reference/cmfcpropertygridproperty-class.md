---
title: "Classe de CMFCPropertyGridProperty | Microsoft Docs"
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
  - "CMFCPropertyGridProperty"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCPropertyGridProperty"
ms.assetid: 36f3fabe-0efe-468b-8a0b-5a7956db38a2
caps.latest.revision: 35
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCPropertyGridProperty
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um objeto de `CMFCPropertyGridProperty` representa um item de lista em um controle de lista de propriedades.  
  
## Sintaxe  
  
```  
class CMFCPropertyGridProperty : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPropertyGridProperty::CMFCPropertyGridProperty](../Topic/CMFCPropertyGridProperty::CMFCPropertyGridProperty.md)|Constrói um objeto de `CMFCPropertyGridProperty` .|  
|`CMFCPropertyGridProperty::~CMFCPropertyGridProperty`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPropertyGridProperty::AddOption](../Topic/CMFCPropertyGridProperty::AddOption.md)|Adicionar um novo item de lista para um controle de lista de propriedades.|  
|[CMFCPropertyGridProperty::AddSubItem](../Topic/CMFCPropertyGridProperty::AddSubItem.md)|Adiciona um item filho a uma propriedade.|  
|[CMFCPropertyGridProperty::AdjustButtonRect](../Topic/CMFCPropertyGridProperty::AdjustButtonRect.md)|Chamado pelo controle pai da lista de propriedades para dizer uma propriedade para redimensionar o retângulo delimitador de um botão inserido.|  
|[CMFCPropertyGridProperty::AdjustInPlaceEditRect](../Topic/CMFCPropertyGridProperty::AdjustInPlaceEditRect.md)|Recupera os limites da caixa de texto e opcional de controle de botão de rotação que são usados para definir um valor de propriedade.|  
|[CMFCPropertyGridProperty::AllowEdit](../Topic/CMFCPropertyGridProperty::AllowEdit.md)|Faz uma propriedade somente leitura ou editável.|  
|[CMFCPropertyGridProperty::CreateInPlaceEdit](../Topic/CMFCPropertyGridProperty::CreateInPlaceEdit.md)|Chamado pela estrutura para criar um controle editável para uma propriedade.|  
|[CMFCPropertyGridProperty::CreateSpinControl](../Topic/CMFCPropertyGridProperty::CreateSpinControl.md)|Chamado pela estrutura para criar um controle editável do botão de rotação.|  
|[CMFCPropertyGridProperty::Enable](../Topic/CMFCPropertyGridProperty::Enable.md)|Habilita ou desabilita uma propriedade.|  
|[CMFCPropertyGridProperty::EnableSpinControl](../Topic/CMFCPropertyGridProperty::EnableSpinControl.md)|Habilita ou desabilita um controle de botão de rotação que é usado para alterar um valor de propriedade.|  
|[CMFCPropertyGridProperty::Expand](../Topic/CMFCPropertyGridProperty::Expand.md)|Expande ou recolhe uma propriedade que contém sub\-propriedades.|  
|[CMFCPropertyGridProperty::FormatProperty](../Topic/CMFCPropertyGridProperty::FormatProperty.md)|Formata a representação de texto de um valor de propriedade.|  
|[CMFCPropertyGridProperty::GetData](../Topic/CMFCPropertyGridProperty::GetData.md)|Recupera um valor de `DWORD` que está associado com uma propriedade.|  
|[CMFCPropertyGridProperty::GetDescription](../Topic/CMFCPropertyGridProperty::GetDescription.md)|Recupera uma descrição da propriedade.|  
|[CMFCPropertyGridProperty::GetExpandedSubItems](../Topic/CMFCPropertyGridProperty::GetExpandedSubItems.md)|Retorna o número de sub\-elementos expandidos.|  
|[CMFCPropertyGridProperty::GetHierarchyLevel](../Topic/CMFCPropertyGridProperty::GetHierarchyLevel.md)|Retorna o índice com base zero do nível da hierarquia da propriedade.|  
|[CMFCPropertyGridProperty::GetName](../Topic/CMFCPropertyGridProperty::GetName.md)|Recupera o nome da propriedade.|  
|[CMFCPropertyGridProperty::GetNameTooltip](../Topic/CMFCPropertyGridProperty::GetNameTooltip.md)|Chamado pela estrutura para exibir o nome da propriedade em uma dica de ferramenta.|  
|[CMFCPropertyGridProperty::GetOption](../Topic/CMFCPropertyGridProperty::GetOption.md)|Recupera o texto de opção que é especificado por um índice.|  
|[CMFCPropertyGridProperty::GetOptionCount](../Topic/CMFCPropertyGridProperty::GetOptionCount.md)|Retorna o número de opções que pertencem a uma propriedade.|  
|[CMFCPropertyGridProperty::GetOriginalValue](../Topic/CMFCPropertyGridProperty::GetOriginalValue.md)|Recupera o valor inicial da propriedade atual.|  
|[CMFCPropertyGridProperty::GetParent](../Topic/CMFCPropertyGridProperty::GetParent.md)|Recupera um ponteiro para uma propriedade pai.|  
|[CMFCPropertyGridProperty::GetRect](../Topic/CMFCPropertyGridProperty::GetRect.md)|Recupera o retângulo delimitador de uma propriedade.|  
|[CMFCPropertyGridProperty::GetSubItem](../Topic/CMFCPropertyGridProperty::GetSubItem.md)|Recupera uma sub\-propriedade identificada por um índice com base zero.|  
|[CMFCPropertyGridProperty::GetSubItemsCount](../Topic/CMFCPropertyGridProperty::GetSubItemsCount.md)|Retorna o número de sub\-elementos.|  
|`CMFCPropertyGridProperty::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCPropertyGridProperty::GetValue](../Topic/CMFCPropertyGridProperty::GetValue.md)|Recupera um valor de propriedade.|  
|[CMFCPropertyGridProperty::GetValueTooltip](../Topic/CMFCPropertyGridProperty::GetValueTooltip.md)|Chamado pela estrutura para recuperar a representação de texto do valor da propriedade que é exibido em uma dica de ferramenta.|  
|[CMFCPropertyGridProperty::HitTest](../Topic/CMFCPropertyGridProperty::HitTest.md)|Os pontos à propriedade do objeto que corresponde ao item da lista de propriedades que corresponde a um ponto.|  
|[CMFCPropertyGridProperty::IsAllowEdit](../Topic/CMFCPropertyGridProperty::IsAllowEdit.md)|Indica se uma propriedade é editável.|  
|[CMFCPropertyGridProperty::IsEnabled](../Topic/CMFCPropertyGridProperty::IsEnabled.md)|Indica se uma propriedade é ativado ou desativado.|  
|[CMFCPropertyGridProperty::IsExpanded](../Topic/CMFCPropertyGridProperty::IsExpanded.md)|Indica se uma propriedade é expandida ou recolhida.|  
|[CMFCPropertyGridProperty::IsGroup](../Topic/CMFCPropertyGridProperty::IsGroup.md)|Indica se a propriedade atual representa um grupo.|  
|[CMFCPropertyGridProperty::IsInPlaceEditing](../Topic/CMFCPropertyGridProperty::IsInPlaceEditing.md)|Indica se a propriedade atual é editável.|  
|[CMFCPropertyGridProperty::IsModified](../Topic/CMFCPropertyGridProperty::IsModified.md)|Indica se a propriedade atual é modificada.|  
|[CMFCPropertyGridProperty::IsParentExpanded](../Topic/CMFCPropertyGridProperty::IsParentExpanded.md)|Indica se os pais da propriedade atual são expandidos.|  
|[CMFCPropertyGridProperty::IsSelected](../Topic/CMFCPropertyGridProperty::IsSelected.md)|Indica se a propriedade atual está selecionada.|  
|[CMFCPropertyGridProperty::IsVisible](../Topic/CMFCPropertyGridProperty::IsVisible.md)|Indica se a propriedade atual é visível.|  
|[CMFCPropertyGridProperty::OnClickButton](../Topic/CMFCPropertyGridProperty::OnClickButton.md)|Chamado pela estrutura quando o usuário clica em um botão que está contido em uma propriedade.|  
|[CMFCPropertyGridProperty::OnClickName](../Topic/CMFCPropertyGridProperty::OnClickName.md)|Chamado por um controle pai da lista de propriedades quando um usuário clica no campo de nome de uma propriedade.|  
|[CMFCPropertyGridProperty::OnClickValue](../Topic/CMFCPropertyGridProperty::OnClickValue.md)|Chamado por um controle pai da lista de propriedades quando um usuário clica no campo de valor de uma propriedade.|  
|[CMFCPropertyGridProperty::OnCloseCombo](../Topic/CMFCPropertyGridProperty::OnCloseCombo.md)|Chamado pela estrutura quando uma caixa de combinação que está contida em uma propriedade é fechada.|  
|[CMFCPropertyGridProperty::OnDblClk](../Topic/CMFCPropertyGridProperty::OnDblClk.md)|Chamado pela estrutura quando o usuário clique duas vezes em uma propriedade.|  
|[CMFCPropertyGridProperty::OnDrawButton](../Topic/CMFCPropertyGridProperty::OnDrawButton.md)|Chamado pela estrutura para desenhar um botão que está contido em uma propriedade.|  
|[CMFCPropertyGridProperty::OnDrawDescription](../Topic/CMFCPropertyGridProperty::OnDrawDescription.md)|Chamado pela estrutura para exibir a descrição da propriedade.|  
|[CMFCPropertyGridProperty::OnDrawExpandBox](../Topic/CMFCPropertyGridProperty::OnDrawExpandBox.md)|Chamado pela estrutura para desenhar um controle de caixa de expandir por uma propriedade que contém sub\-propriedades.|  
|[CMFCPropertyGridProperty::OnDrawName](../Topic/CMFCPropertyGridProperty::OnDrawName.md)|Chamado pela estrutura para exibir o nome da propriedade.|  
|[CMFCPropertyGridProperty::OnDrawValue](../Topic/CMFCPropertyGridProperty::OnDrawValue.md)|Chamado pela estrutura para exibir o valor da propriedade.|  
|[CMFCPropertyGridProperty::OnEdit](../Topic/CMFCPropertyGridProperty::OnEdit.md)|Chamado pela estrutura quando o usuário está a ponto de alterar um valor de propriedade.|  
|[CMFCPropertyGridProperty::OnEndEdit](../Topic/CMFCPropertyGridProperty::OnEndEdit.md)|Chamado pela estrutura quando o usuário tiver terminado de altera o valor de uma propriedade.|  
|[CMFCPropertyGridProperty::OnKillSelection](../Topic/CMFCPropertyGridProperty::OnKillSelection.md)||  
|[CMFCPropertyGridProperty::OnPosSizeChanged](../Topic/CMFCPropertyGridProperty::OnPosSizeChanged.md)||  
|[CMFCPropertyGridProperty::OnRClickName](../Topic/CMFCPropertyGridProperty::OnRClickName.md)|Chamado pela estrutura quando o usuário clica no botão direito do mouse na área do nome da propriedade.|  
|[CMFCPropertyGridProperty::OnRClickValue](../Topic/CMFCPropertyGridProperty::OnRClickValue.md)|Chamado pela estrutura quando o usuário clica no botão direito do mouse na área de valor de propriedade.|  
|[CMFCPropertyGridProperty::OnSelectCombo](../Topic/CMFCPropertyGridProperty::OnSelectCombo.md)|Chamado pela estrutura quando o usuário seleciona um item da caixa de combinação editável.|  
|[CMFCPropertyGridProperty::OnSetCursor](../Topic/CMFCPropertyGridProperty::OnSetCursor.md)|Chamado pela estrutura quando o ponteiro do mouse mover para um item da propriedade.|  
|[CMFCPropertyGridProperty::OnSetSelection](../Topic/CMFCPropertyGridProperty::OnSetSelection.md)||  
|[CMFCPropertyGridProperty::OnUpdateValue](../Topic/CMFCPropertyGridProperty::OnUpdateValue.md)|Chamado pela estrutura quando o valor de uma propriedade editável alterar.|  
|[CMFCPropertyGridProperty::PushChar](../Topic/CMFCPropertyGridProperty::PushChar.md)|Chamado de controle de lista de propriedades quando a propriedade é selecionada e de usuário insere um novo caractere.|  
|[CMFCPropertyGridProperty::Redraw](../Topic/CMFCPropertyGridProperty::Redraw.md)|Redesenha a propriedade.|  
|[CMFCPropertyGridProperty::RemoveAllOptions](../Topic/CMFCPropertyGridProperty::RemoveAllOptions.md)|Remove todas as opções \(itens\) de uma propriedade.|  
|[CMFCPropertyGridProperty::RemoveSubItem](../Topic/CMFCPropertyGridProperty::RemoveSubItem.md)|Remove o sub\-elemento especificado.|  
|[CMFCPropertyGridProperty::ResetOriginalValue](../Topic/CMFCPropertyGridProperty::ResetOriginalValue.md)|Restaura o valor original de uma propriedade editada.|  
|[CMFCPropertyGridProperty::SetData](../Topic/CMFCPropertyGridProperty::SetData.md)|Associa um valor de `DWORD` com uma propriedade.|  
|[CMFCPropertyGridProperty::SetDescription](../Topic/CMFCPropertyGridProperty::SetDescription.md)|Especifica o texto que descreve a propriedade atual.|  
|[CMFCPropertyGridProperty::SetName](../Topic/CMFCPropertyGridProperty::SetName.md)|Define o nome de uma propriedade.|  
|[CMFCPropertyGridProperty::SetOriginalValue](../Topic/CMFCPropertyGridProperty::SetOriginalValue.md)|Defina o valor original de uma propriedade editável.|  
|[CMFCPropertyGridProperty::SetValue](../Topic/CMFCPropertyGridProperty::SetValue.md)|Defina o valor de uma propriedade da grade de propriedade.|  
|[CMFCPropertyGridProperty::Show](../Topic/CMFCPropertyGridProperty::Show.md)|Mostra ou oculta uma propriedade.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPropertyGridProperty::CreateCombo](../Topic/CMFCPropertyGridProperty::CreateCombo.md)|Chamado pela estrutura para adicionar uma caixa de combinação a uma propriedade.|  
|[CMFCPropertyGridProperty::HasButton](../Topic/CMFCPropertyGridProperty::HasButton.md)|Indica se uma propriedade contém um botão.|  
|[CMFCPropertyGridProperty::Init](../Topic/CMFCPropertyGridProperty::Init.md)|Chamado pela estrutura para inicializar um objeto da propriedade.|  
|[CMFCPropertyGridProperty::IsSubItem](../Topic/CMFCPropertyGridProperty::IsSubItem.md)|Indica se a propriedade especificada é um sub\-elemento da propriedade atual.|  
|[CMFCPropertyGridProperty::IsValueChanged](../Topic/CMFCPropertyGridProperty::IsValueChanged.md)|Indica se o valor da propriedade atual foi alterado.|  
|[CMFCPropertyGridProperty::OnCtlColor](../Topic/CMFCPropertyGridProperty::OnCtlColor.md)|Quando chamado pela estrutura deve recuperar um pincel para preencher a cor do plano de fundo de uma propriedade.|  
|[CMFCPropertyGridProperty::OnDestroyWindow](../Topic/CMFCPropertyGridProperty::OnDestroyWindow.md)|Chamado pela estrutura quando uma propriedade é destruída ou editando quando terminar.|  
|[CMFCPropertyGridProperty::OnKillFocus](../Topic/CMFCPropertyGridProperty::OnKillFocus.md)|Chamado pela estrutura quando a propriedade perde o foco de entrada.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCPropertyGridProperty::m\_strFormatDouble](../Topic/CMFCPropertyGridProperty::m_strFormatDouble.md)|Cadeia de caracteres de formato para um valor double do tipo.|  
|[CMFCPropertyGridProperty::m\_strFormatFloat](../Topic/CMFCPropertyGridProperty::m_strFormatFloat.md)|Cadeia de caracteres de formato para um valor de flutuante de tipo.|  
|[CMFCPropertyGridProperty::m\_strFormatLong](../Topic/CMFCPropertyGridProperty::m_strFormatLong.md)|Formatar a cadeia de caracteres para um valor de tipo long.|  
|[CMFCPropertyGridProperty::m\_strFormatShort](../Topic/CMFCPropertyGridProperty::m_strFormatShort.md)|Formatar a cadeia de caracteres para um valor de tipo curta.|  
  
## Comentários  
 Use um objeto de `CMFCPropertyGridProperty` para representar uma propriedade, que você adicionar a um controle de lista de propriedades.  Para mais informações, consulte [Classe de CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md).  
  
 Um objeto de propriedade pode representar tipos de dados como cadeias de caracteres, datas, e valores booleanos ou inteiro.  Pode conter propriedades filhas, ou pode conter um controle como uma caixa de combinação ou um controle de botão.  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCPropertyGridProperty` .  O exemplo também demonstra como usar vários métodos na classe de `CMFCPropertyGridProperty` para adicionar uma opção, para adicionar um sub\-elemento, para ativar uma propriedade, e para mostrar uma propriedade.  Este exemplo é parte de [novo exemplo de controles](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_NewControls#27](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#27)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxpropertygridctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)