---
title: "Classe de CMFCRibbonEdit | Microsoft Docs"
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
  - "CMFCRibbonEdit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonEdit"
ms.assetid: 9b85f1f2-446b-454e-9af9-104fdad8a897
caps.latest.revision: 25
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonEdit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um controle de edição localizado em uma barra de fita.  
  
## Sintaxe  
  
```  
class CMFCRibbonEdit : public CMFCRibbonButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonEdit::CMFCRibbonEdit](../Topic/CMFCRibbonEdit::CMFCRibbonEdit.md)|Constrói um objeto de `CMFCRibbonEdit` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonEdit::CanBeStretched](../Topic/CMFCRibbonEdit::CanBeStretched.md)|Indica se a altura do controle de `CMFCRibbonEdit` pode aumentar verticalmente a altura de uma linha de fita.|  
|[CMFCRibbonEdit::CMFCRibbonEdit](../Topic/CMFCRibbonEdit::CMFCRibbonEdit.md)|Constrói um objeto de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::CopyFrom](../Topic/CMFCRibbonEdit::CopyFrom.md)|Copia o estado do objeto especificado de `CMFCRibbonEdit` ao objeto atual de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::CreateEdit](../Topic/CMFCRibbonEdit::CreateEdit.md)|Cria uma nova caixa de texto para o objeto de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::DestroyCtrl](../Topic/CMFCRibbonEdit::DestroyCtrl.md)|Destrói o objeto de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::DropDownList](../Topic/CMFCRibbonEdit::DropDownList.md)|Soltar para baixo uma caixa de listagem.|  
|[CMFCRibbonEdit::EnableSpinButtons](../Topic/CMFCRibbonEdit::EnableSpinButtons.md)|Permite e define o intervalo de botão de rotação da caixa de texto.|  
|[CMFCRibbonEdit::GetCompactSize](../Topic/CMFCRibbonEdit::GetCompactSize.md)|Retorna o tamanho compacta do objeto de `CFMCRibbonEdit` .|  
|[CMFCRibbonEdit::GetEditText](../Topic/CMFCRibbonEdit::GetEditText.md)|Recupera o texto na caixa de texto.|  
|[CMFCRibbonEdit::GetIntermediateSize](../Topic/CMFCRibbonEdit::GetIntermediateSize.md)|Retorna o tamanho intermediário do objeto de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::GetTextAlign](../Topic/CMFCRibbonEdit::GetTextAlign.md)|Recupera o alinhamento de texto na caixa de texto.|  
|[CMFCRibbonEdit::GetWidth](../Topic/CMFCRibbonEdit::GetWidth.md)|Obtém a largura, em pixels, de controle de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::HasCompactMode](../Topic/CMFCRibbonEdit::HasCompactMode.md)|Indica se o tamanho de exibição para o controle de `CMFCRibbonEdit` pode ser compacto.|  
|[CMFCRibbonEdit::HasFocus](../Topic/CMFCRibbonEdit::HasFocus.md)|Indica se o controle de `CMFCRIbbonEdit` tem o foco.|  
|[CMFCRibbonEdit::HasLargeMode](../Topic/CMFCRibbonEdit::HasLargeMode.md)|Indica se o tamanho de exibição para o controle de `CMFCRibbonEdit` pode ser grande.|  
|[CMFCRibbonEdit::HasSpinButtons](../Topic/CMFCRibbonEdit::HasSpinButtons.md)|Indica se a caixa de texto tem um botão de rotação.|  
|[CMFCRibbonEdit::IsHighlighted](../Topic/CMFCRibbonEdit::IsHighlighted.md)|Indica se o controle de `CMFCRibbonEdit` é realçado.|  
|[CMFCRibbonEdit::OnAfterChangeRect](../Topic/CMFCRibbonEdit::OnAfterChangeRect.md)|Chamado pela estrutura quando as dimensões do retângulo de exibição para as alterações de controle de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::OnDraw](../Topic/CMFCRibbonEdit::OnDraw.md)|Chamado pela estrutura para desenhar o controle de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::OnDrawLabelAndImage](../Topic/CMFCRibbonEdit::OnDrawLabelAndImage.md)|Chamado pela estrutura para desenhar o rótulo e a imagem para o controle de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::OnDrawOnList](../Topic/CMFCRibbonEdit::OnDrawOnList.md)|Chamado pela estrutura para desenhar o controle de `CMFCRibbonEdit` em uma caixa de listagem de comandos.|  
|[CMFCRibbonEdit::OnEnable](../Topic/CMFCRibbonEdit::OnEnable.md)|Chamado pela estrutura para ativar ou desativar o controle de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::OnHighlight](../Topic/CMFCRibbonEdit::OnHighlight.md)|Chamado pela estrutura quando o ponteiro inserir ou sair dos limites do controle de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::OnKey](../Topic/CMFCRibbonEdit::OnKey.md)|Chamado pela estrutura quando o usuário pressiona um keytip e o controle de `CMFCRibbonEdit` tem o foco.|  
|[CMFCRibbonEdit::OnLButtonDown](../Topic/CMFCRibbonEdit::OnLButtonDown.md)|Chamado pela estrutura para atualizar o controle de `CMFCRibbonEdit` quando o usuário pressionar o botão esquerdo do mouse no controle.|  
|[CMFCRibbonEdit::OnLButtonUp](../Topic/CMFCRibbonEdit::OnLButtonUp.md)|Chamado pela estrutura quando o usuário liberar o botão esquerdo do mouse.|  
|[CMFCRibbonEdit::OnRTLChanged](../Topic/CMFCRibbonEdit::OnRTLChanged.md)|Chamado pela estrutura para atualizar o controle de `CMFCRibbonEdit` quando o layout modificar a direção.|  
|[CMFCRibbonEdit::OnShow](../Topic/CMFCRibbonEdit::OnShow.md)|Chamado pela estrutura para mostrar ou ocultar o controle de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::Redraw](../Topic/CMFCRibbonEdit::Redraw.md)|Atualize a exibição de controle de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::SetACCData](../Topic/CMFCRibbonEdit::SetACCData.md)|Defina os dados de acessibilidade para o objeto de `CMFCRibbonEdit` .|  
|[CMFCRibbonEdit::SetEditText](../Topic/CMFCRibbonEdit::SetEditText.md)|Define o texto na caixa de texto.|  
|[CMFCRibbonEdit::SetTextAlign](../Topic/CMFCRibbonEdit::SetTextAlign.md)|Define o alinhamento de texto da caixa de texto.|  
|[CMFCRibbonEdit::SetWidth](../Topic/CMFCRibbonEdit::SetWidth.md)|Defina a largura da caixa de texto para o controle de `CMFCRibbonEdit` .|  
  
## Comentários  
  
## Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCRibbonEdit` , mostra os botões de rotação próximo ao controle de edição, e define o texto do controle de edição.  Este trecho de código é parte de [Exemplo 2007 de demonstração de MS Office](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_MSOffice2007Demo#7](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_MSOffice2007Demo#7)]  
  
## Requisitos  
 **Cabeçalho:** afxRibbonEdit.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)   
 [Classe de CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)