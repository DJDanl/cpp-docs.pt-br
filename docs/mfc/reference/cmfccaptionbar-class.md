---
title: "Classe CMFCCaptionBar | Microsoft Docs"
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
  - "CMFCCaptionBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMFCCaptionBar"
ms.assetid: acb54d5f-14ff-4c96-aeb3-7717cf566d9a
caps.latest.revision: 28
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CMFCCaptionBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um objeto de `CMFCCaptionBar` é uma barra de controle que pode exibir três elementos: um botão, um rótulo de texto, e um bitmap.  Só pode exibir um elemento de cada tipo de cada vez.  Você pode alinhar cada elemento as bordas esquerda ou direita do controle ou o centro.  Você também pode aplicar um plano ou um estilo 3D às bordas da parte superior e inferior da barra de título.  
  
## Sintaxe  
  
```  
class CMFCCaptionBar : public CPane  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCCaptionBar::Create](../Topic/CMFCCaptionBar::Create.md)|Cria o controle de barra de título e anexá\-la ao objeto de `CMFCCaptionBar`.|  
|[CMFCCaptionBar::DoesAllowDynInsertBefore](../Topic/CMFCCaptionBar::DoesAllowDynInsertBefore.md)|Indica se outro painel dinamicamente pode ser inserido entre a barra de título e seu elemento pai.  Overrides \( [CBasePane::DoesAllowDynInsertBefore](../Topic/CBasePane::DoesAllowDynInsertBefore.md).\)|  
|[CMFCCaptionBar::EnableButton](../Topic/CMFCCaptionBar::EnableButton.md)|Habilita ou desabilita o botão na barra de título.|  
|[CMFCCaptionBar::GetAlignment](../Topic/CMFCCaptionBar::GetAlignment.md)|Retorna o alinhamento do elemento especificado.|  
|[CMFCCaptionBar::GetBorderSize](../Topic/CMFCCaptionBar::GetBorderSize.md)|Retorna o tamanho da borda da barra de título.|  
|[CMFCCaptionBar::GetButtonRect](../Topic/CMFCCaptionBar::GetButtonRect.md)|Recupera o retângulo delimitador de botão na barra de título.|  
|[CMFCCaptionBar::GetMargin](../Topic/CMFCCaptionBar::GetMargin.md)|Retorna a distância entre a borda dos elementos da barra de título e a borda do controle de barra de título.|  
|[CMFCCaptionBar::IsMessageBarMode](../Topic/CMFCCaptionBar::IsMessageBarMode.md)|Especifica se a barra de título está no modo da barra de mensagens.|  
|[CMFCCaptionBar::RemoveBitmap](../Topic/CMFCCaptionBar::RemoveBitmap.md)|Remove a imagem de bitmap da barra de título.|  
|[CMFCCaptionBar::RemoveButton](../Topic/CMFCCaptionBar::RemoveButton.md)|Remove o botão da barra de título.|  
|[CMFCCaptionBar::RemoveIcon](../Topic/CMFCCaptionBar::RemoveIcon.md)|Remove o ícone da barra de título.|  
|[CMFCCaptionBar::RemoveText](../Topic/CMFCCaptionBar::RemoveText.md)|Remove o rótulo de texto da barra de título.|  
|[CMFCCaptionBar::SetBitmap](../Topic/CMFCCaptionBar::SetBitmap.md)|Define a imagem de bitmap para a barra de título.|  
|[CMFCCaptionBar::SetBorderSize](../Topic/CMFCCaptionBar::SetBorderSize.md)|Defina o tamanho da borda da barra de título.|  
|[CMFCCaptionBar::SetButton](../Topic/CMFCCaptionBar::SetButton.md)|Define o botão da barra de título.|  
|[CMFCCaptionBar::SetButtonPressed](../Topic/CMFCCaptionBar::SetButtonPressed.md)|Especifica se o botão permanece pressionado.|  
|[CMFCCaptionBar::SetButtonToolTip](../Topic/CMFCCaptionBar::SetButtonToolTip.md)|Define a dica de ferramenta para o botão.|  
|[CMFCCaptionBar::SetFlatBorder](../Topic/CMFCCaptionBar::SetFlatBorder.md)|Defina o estilo de borda da barra de título.|  
|[CMFCCaptionBar::SetIcon](../Topic/CMFCCaptionBar::SetIcon.md)|Define o ícone para uma barra de título.|  
|[CMFCCaptionBar::SetImageToolTip](../Topic/CMFCCaptionBar::SetImageToolTip.md)|Define a dica de ferramenta para a imagem para a barra de título.|  
|[CMFCCaptionBar::SetMargin](../Topic/CMFCCaptionBar::SetMargin.md)|Define a distância entre a borda do elemento da barra de título e a borda do controle de barra de título.|  
|[CMFCCaptionBar::SetText](../Topic/CMFCCaptionBar::SetText.md)|Define o rótulo de texto da barra de título.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCCaptionBar::OnDrawBackground](../Topic/CMFCCaptionBar::OnDrawBackground.md)|Chamado pela estrutura para preencher o plano de fundo da barra de título.|  
|[CMFCCaptionBar::OnDrawBorder](../Topic/CMFCCaptionBar::OnDrawBorder.md)|Chamado pela estrutura para desenhar a borda da barra de título.|  
|[CMFCCaptionBar::OnDrawButton](../Topic/CMFCCaptionBar::OnDrawButton.md)|Chamado pela estrutura para desenhar o botão da barra de título.|  
|[CMFCCaptionBar::OnDrawImage](../Topic/CMFCCaptionBar::OnDrawImage.md)|Chamado pela estrutura para desenhar uma imagem da barra de título.|  
|[CMFCCaptionBar::OnDrawText](../Topic/CMFCCaptionBar::OnDrawText.md)|Chamado pela estrutura para desenhar o texto da barra de título.|  
  
### Membros de Dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCCaptionBar::m\_clrBarBackground](../Topic/CMFCCaptionBar::m_clrBarBackground.md)|A cor do plano de fundo da barra de título.|  
|[CMFCCaptionBar::m\_clrBarBorder](../Topic/CMFCCaptionBar::m_clrBarBorder.md)|A cor da borda da barra de título.|  
|[CMFCCaptionBar::m\_clrBarText](../Topic/CMFCCaptionBar::m_clrBarText.md)|A cor do texto da barra de título.|  
  
## Comentários  
 Para criar uma barra de título, siga estas etapas:  
  
1.  Construir o objeto de `CMFCCaptionBar` .  Normalmente, você adicionaria a barra de título a uma classe de janela do quadro.  
  
2.  Chame o método de [CMFCCaptionBar::Create](../Topic/CMFCCaptionBar::Create.md) para criar o controle de barra de título e para anexá\-la ao objeto de `CMFCCaptionBar` .  
  
3.  Chame [CMFCCaptionBar::SetButton](../Topic/CMFCCaptionBar::SetButton.md), [CMFCCaptionBar::SetText](../Topic/CMFCCaptionBar::SetText.md), [CMFCCaptionBar::SetIcon](../Topic/CMFCCaptionBar::SetIcon.md), e [CMFCCaptionBar::SetBitmap](../Topic/CMFCCaptionBar::SetBitmap.md) para definir os elementos da barra de título.  
  
 Quando você definir o elemento de botão, você deve atribuir uma identificação de comando para o botão.  Quando o usuário clica no botão, a barra de título rotear mensagens de `WM_COMMAND` que têm essa identificação para a janela pai do quadro.  
  
 A barra de título também pode trabalhar no modo da barra de mensagens, que emula a barra de mensagem que aparece no Microsoft Office 2007 aplicativos.  No modo da barra de mensagens, a barra de título exibe um bitmap, uma mensagem, e um botão \(que é normalmente uma caixa de diálogo.\) Você pode atribuir uma dica de ferramenta para o bitmap.  
  
 Para ativar o modo da barra de mensagens, chame [CMFCCaptionBar::Create](../Topic/CMFCCaptionBar::Create.md) e define o quarto parâmetro \(\) bIsMessageBarMode a `TRUE`.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCCaptionBar` .  O exemplo a seguir mostra como criar o controle de barra de título, defina uma borda 3D da barra de título, defina a distância, em pixels, entre a borda dos elementos da barra de título e a borda do controle de barra de título, defina o botão da barra de título, defina a dica de ferramenta para o botão, defina o rótulo de texto da barra de título, defina a imagem de bitmap para a barra de título, e defina a dica de ferramenta para a imagem na barra de título.  Este trecho de código é parte de [Exemplo 2007 de demonstração de MS Office](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_MSOffice2007Demo#1](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_MSOffice2007Demo#1)]  
[!CODE [NVC_MFC_MSOffice2007Demo#2](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_MSOffice2007Demo#2)]  
  
## Hierarquia de Herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCCaptionBar](../../mfc/reference/cmfccaptionbar-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxcaptionbar.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)