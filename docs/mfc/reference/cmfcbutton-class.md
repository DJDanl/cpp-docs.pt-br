---
title: "Classe de CMFCButton | Microsoft Docs"
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
  - "CMFCButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCButton"
  - "Construtor de CMFCButton"
  - "Método de CMFCButton::CreateObject"
  - "Método de CMFCButton::DrawItem"
  - "Método de CMFCButton::OnDrawParentBackground"
  - "Método de CMFCButton::PreTranslateMessage"
ms.assetid: 4b32f57c-7a53-4734-afb9-d47e3359f62e
caps.latest.revision: 35
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCButton` adicionar funcionalidade à classe de [CButton](../../mfc/reference/cbutton-class.md) como alinhar o texto do botão, a combinação de texto do botão e de uma imagem, selecione um cursor, e especificar uma dica de ferramenta.  
  
## Sintaxe  
  
```  
class CMFCButton : public CButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCButton::CMFCButton`|Construtor padrão.|  
|`CMFCButton::~CMFCButton`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCButton::CleanUp](../Topic/CMFCButton::CleanUp.md)|Reinicializa variáveis internas e libera recursos designados como imagens, ícones bitmaps, e.|  
|`CMFCButton::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|`CMFCButton::DrawItem`|Chamado pela estrutura quando uma aparência visual de um botão proprietário desenhado alterar.  Overrides \( [CButton::DrawItem](../Topic/CButton::DrawItem.md).\)|  
|[CMFCButton::EnableFullTextTooltip](../Topic/CMFCButton::EnableFullTextTooltip.md)|Especifica se exibir texto completo de um tooltip em uma grande janela de tooltip ou truncado uma versão do texto em uma pequena janela de tooltip.|  
|[CMFCButton::EnableMenuFont](../Topic/CMFCButton::EnableMenuFont.md)|Especifica se a fonte do texto do botão é a mesma que a fonte do menu do aplicativo.|  
|[CMFCButton::EnableWindowsTheming](../Topic/CMFCButton::EnableWindowsTheming.md)|Especifica se o estilo de borda do botão corresponde ao tema atual do windows.|  
|`CMFCButton::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto de [CRuntimeClass](../Topic/CRuntimeClass%20Structure.md) que está associado com esse tipo da classe.|  
|[CMFCButton::GetToolTipCtrl](../Topic/CMFCButton::GetToolTipCtrl.md)|Retorna uma referência ao controle subjacente de tooltip.|  
|[CMFCButton::IsAutoCheck](../Topic/CMFCButton::IsAutoCheck.md)|Indica se uma caixa de seleção ou um botão de opção são um botão automático.|  
|[CMFCButton::IsAutorepeatCommandMode](../Topic/CMFCButton::IsAutorepeatCommandMode.md)|Indica se um botão é definido para automático de repetição.|  
|[CMFCButton::IsCheckBox](../Topic/CMFCButton::IsCheckBox.md)|Indica se um botão é um botão da caixa de seleção.|  
|[CMFCButton::IsChecked](../Topic/CMFCButton::IsChecked.md)|Indica se o botão atual é verificado.|  
|[CMFCButton::IsHighlighted](../Topic/CMFCButton::IsHighlighted.md)|Indica se um botão é realçado.|  
|[CMFCButton::IsPressed](../Topic/CMFCButton::IsPressed.md)|Indica se um botão é empurrado e realçado.|  
|[CMFCButton::IsPushed](../Topic/CMFCButton::IsPushed.md)|Indica se um botão é empurrado.|  
|[CMFCButton::IsRadioButton](../Topic/CMFCButton::IsRadioButton.md)|Indica se um botão é um botão de opção.|  
|[CMFCButton::IsWindowsThemingEnabled](../Topic/CMFCButton::IsWindowsThemingEnabled.md)|Indica se o estilo de borda do botão corresponde ao tema atual do windows.|  
|`CMFCButton::OnDrawParentBackground`|Desenha o plano de fundo do pai de um botão na área especificada.  Overrides \( [AFX\_GLOBAL\_DATA::DrawParentBackground](../Topic/AFX_GLOBAL_DATA::DrawParentBackground.md).\)|  
|`CMFCButton::PreTranslateMessage`|Converte mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Overrides \( [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md).\)|  
|[CMFCButton::SetAutorepeatMode](../Topic/CMFCButton::SetAutorepeatMode.md)|Define um modo automático de repetição do botão.|  
|[CMFCButton::SetCheckedImage](../Topic/CMFCButton::SetCheckedImage.md)|Define a imagem para um botão selecionado.|  
|[CMFCButton::SetFaceColor](../Topic/CMFCButton::SetFaceColor.md)|Define a cor do plano de fundo para o texto do botão.|  
|[CMFCButton::SetImage](../Topic/CMFCButton::SetImage.md)|Define a imagem de um botão.|  
|[CMFCButton::SetMouseCursor](../Topic/CMFCButton::SetMouseCursor.md)|Define a imagem do cursor.|  
|[CMFCButton::SetMouseCursorHand](../Topic/CMFCButton::SetMouseCursorHand.md)|Define o cursor para a imagem de uma mão.|  
|[CMFCButton::SetStdImage](../Topic/CMFCButton::SetStdImage.md)|Usa um objeto de `CMenuImages` para definir a imagem do botão.|  
|[CMFCButton::SetTextColor](../Topic/CMFCButton::SetTextColor.md)|Define a cor do texto do botão para um botão que não está selecionado.|  
|[CMFCButton::SetTextHotColor](../Topic/CMFCButton::SetTextHotColor.md)|Define a cor do texto do botão para um botão que está selecionado.|  
|[CMFCButton::SetTooltip](../Topic/CMFCButton::SetTooltip.md)|Associa um tooltip com um botão.|  
|[CMFCButton::SizeToContent](../Topic/CMFCButton::SizeToContent.md)|Redimensiona um botão para conter os imagem e texto do botão.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCButton::OnDraw](../Topic/CMFCButton::OnDraw.md)|Chamado pela estrutura para desenhar um botão.|  
|[CMFCButton::OnDrawBorder](../Topic/CMFCButton::OnDrawBorder.md)|Chamado pela estrutura para desenhar a borda de um botão.|  
|[CMFCButton::OnDrawFocusRect](../Topic/CMFCButton::OnDrawFocusRect.md)|Chamado pela estrutura para desenhar o retângulo de foco de um botão.|  
|[CMFCButton::OnDrawText](../Topic/CMFCButton::OnDrawText.md)|Chamado pela estrutura para desenhar o texto do botão.|  
|[CMFCButton::OnFillBackground](../Topic/CMFCButton::OnFillBackground.md)|Chamado pela estrutura para desenhar o plano de fundo do botão texto.|  
|[CMFCButton::SelectFont](../Topic/CMFCButton::SelectFont.md)|Recupera a fonte que está associada com o contexto específico de dispositivo.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCButton::m\_bDrawFocus](../Topic/CMFCButton::m_bDrawFocus.md)|Indica se desenhar um retângulo de foco em torno de um botão.|  
|[CMFCButton::m\_bHighlightChecked](../Topic/CMFCButton::m_bHighlightChecked.md)|Indica se realçar um BS\_CHECKBOX\-style botão quando o cursor passa sobre ele.|  
|[CMFCButton::m\_bRightImage](../Topic/CMFCButton::m_bRightImage.md)|Indica se exibir uma imagem no lado direito do botão.|  
|[CMFCButton::m\_bTransparent](../Topic/CMFCButton::m_bTransparent.md)|Indica se o botão é transparente.|  
|[CMFCButton::m\_nAlignStyle](../Topic/CMFCButton::m_nAlignStyle.md)|Especifica o alinhamento de texto do botão.|  
|[CMFCButton::m\_nFlatStyle](../Topic/CMFCButton::m_nFlatStyle.md)|Especifica o estilo do botão, como sem fronteira, suave, o semi\- plano, ou o 3D.|  
  
## Comentários  
 Outros tipos de botões são derivados da classe de `CMFCButton` , como a classe de [CMFCURLLinkButton](../../mfc/reference/cmfclinkctrl-class.md) , que suporta hiperlinks, e a classe de `CMFCColorButton` , que suporta uma caixa de diálogo seletor de cor.  
  
 O estilo de um objeto de `CMFCButton` pode ser *3D*, *plano*, *semi\- fundo* ou *nenhuma borda*.  O texto do botão pode ser alinhado na esquerda, cobre, ou centro de um botão.  Em tempo de execução, você pode controlar se o botão exibe o texto, uma imagem, ou texto e uma imagem.  Você também pode especificar que uma imagem específica do cursor seja exibida quando o cursor focaliza um botão.  
  
 Crie um controle de botão diretamente em seu código, ou usando a ferramenta de **Assistente de Classe MFC** e um modelo da caixa de diálogo.  Se você criar um controle de botão diretamente, adicione uma variável de `CMFCButton` ao seu aplicativo, e então chame o construtor e métodos de `Create` de `CMFCButton` objeto.  Se você usar **Assistente de Classe MFC**, adicione uma variável de `CButton` para seu aplicativo em seguida, altere o tipo da variável de `CButton` a `CMFCButton`.  
  
 Para manipular notificações em um aplicativo da caixa de diálogo, adicione uma entrada de mapa de mensagem e um manipulador de eventos para cada notificação.  As notificações enviadas por um objeto de `CMFCButton` são as mesmas que aquelas fornecidas por um objeto de `CButton` .  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar as propriedades do botão usando vários métodos na classe de `CMFCButton` .  o exemplo é parte de [novo exemplo de controles](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_NewControls#28](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#28)]  
[!CODE [NVC_MFC_NewControls#31](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#31)]  
[!CODE [NVC_MFC_NewControls#32](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#32)]  
[!CODE [NVC_MFC_NewControls#33](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#33)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCButton](../../mfc/reference/cmfcbutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxbutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCLinkCtrl](../../mfc/reference/cmfclinkctrl-class.md)   
 [Classe de CMFCColorButton](../../mfc/reference/cmfccolorbutton-class.md)   
 [Classe CMFCMenuButton](../../mfc/reference/cmfcmenubutton-class.md)