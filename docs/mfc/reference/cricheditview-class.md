---
title: "Classe de CRichEditView | Microsoft Docs"
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
  - "CRichEditView"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CRichEditView"
  - "arquitetura do documento/exibição, controles de edição ricos"
  - "Contêiner VELHOS, edição rico"
  - "controles de edição ricos, Contêiner OLE"
ms.assetid: bd576b10-4cc0-4050-8f76-e1a0548411e4
caps.latest.revision: 25
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CRichEditView
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Com [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) e [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md), fornece a funcionalidade do controle de edição rico dentro do contexto da arquitetura de exibição de documento MFC.  
  
## Sintaxe  
  
```  
  
class CRichEditView : public CCtrlView  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRichEditView::CRichEditView](../Topic/CRichEditView::CRichEditView.md)|Constrói um objeto de `CRichEditView` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRichEditView::AdjustDialogPosition](../Topic/CRichEditView::AdjustDialogPosition.md)|Move uma caixa de diálogo para que ele não oculte a seleção atual.|  
|[CRichEditView::CanPaste](../Topic/CRichEditView::CanPaste.md)|Informa se a área de transferência contém dados que podem ser colados rica no modo de edição.|  
|[CRichEditView::DoPaste](../Topic/CRichEditView::DoPaste.md)|Cola um item OLE em esta rica o modo de edição.|  
|[CRichEditView::FindText](../Topic/CRichEditView::FindText.md)|Localiza o texto especificado, invocando o cursor de espera.|  
|[CRichEditView::FindTextSimple](../Topic/CRichEditView::FindTextSimple.md)|Localiza o texto especificado.|  
|[CRichEditView::GetCharFormatSelection](../Topic/CRichEditView::GetCharFormatSelection.md)|Recupera os atributos de formatação de caracteres para a seleção atual.|  
|[CRichEditView::GetDocument](../Topic/CRichEditView::GetDocument.md)|Recupera um ponteiro para [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)relacionados.|  
|[CRichEditView::GetInPlaceActiveItem](../Topic/CRichEditView::GetInPlaceActiveItem.md)|Recupera o item OLE que está atualmente ativa no lugar rica no modo de edição.|  
|[CRichEditView::GetMargins](../Topic/CRichEditView::GetMargins.md)|Recupera as margens para essa rica o modo de edição.|  
|[CRichEditView::GetPageRect](../Topic/CRichEditView::GetPageRect.md)|Recupera o retângulo da página para essa rica o modo de edição.|  
|[CRichEditView::GetPaperSize](../Topic/CRichEditView::GetPaperSize.md)|Retorna o tamanho de papel para essa rica o modo de edição.|  
|[CRichEditView::GetParaFormatSelection](../Topic/CRichEditView::GetParaFormatSelection.md)|Recupera os atributos de formatação de parágrafo para a seleção atual.|  
|[CRichEditView::GetPrintRect](../Topic/CRichEditView::GetPrintRect.md)|Recupera o retângulo de impressão para essa rica o modo de edição.|  
|[CRichEditView::GetPrintWidth](../Topic/CRichEditView::GetPrintWidth.md)|Obtém a largura de impressão para essa rica o modo de edição.|  
|[CRichEditView::GetRichEditCtrl](../Topic/CRichEditView::GetRichEditCtrl.md)|Recupera o controle de edição rico.|  
|[CRichEditView::GetSelectedItem](../Topic/CRichEditView::GetSelectedItem.md)|Recupera o item selecionado rica do modo de edição.|  
|[CRichEditView::GetTextLength](../Topic/CRichEditView::GetTextLength.md)|Retorna o tamanho do texto rica no modo de edição.|  
|[CRichEditView::GetTextLengthEx](../Topic/CRichEditView::GetTextLengthEx.md)|Retorna o número de caracteres ou rica de bytes no modo de edição.  Lista de sinalizador expandida para o método para determinar o comprimento.|  
|[CRichEditView::InsertFileAsObject](../Topic/CRichEditView::InsertFileAsObject.md)|Insere um arquivo como um item OLE.|  
|[CRichEditView::InsertItem](../Topic/CRichEditView::InsertItem.md)|Insere um novo item como um item OLE.|  
|[CRichEditView::IsRichEditFormat](../Topic/CRichEditView::IsRichEditFormat.md)|Informa se a área de transferência contém dados em uma edição ou em um formato de texto rico.|  
|[CRichEditView::OnCharEffect](../Topic/CRichEditView::OnCharEffect.md)|Alterna \/desativar formatação de caracteres para a seleção atual.|  
|[CRichEditView::OnParaAlign](../Topic/CRichEditView::OnParaAlign.md)|Altera o alinhamento dos parágrafos.|  
|[CRichEditView::OnUpdateCharEffect](../Topic/CRichEditView::OnUpdateCharEffect.md)|Atualiza o comando interface do usuário para funções de membro de chaves pública de caracteres.|  
|[CRichEditView::OnUpdateParaAlign](../Topic/CRichEditView::OnUpdateParaAlign.md)|Atualiza o comando interface de usuário para funções de membro de pública do parágrafo.|  
|[CRichEditView::PrintInsideRect](../Topic/CRichEditView::PrintInsideRect.md)|Formata o texto especificado dentro do retângulo especificado.|  
|[CRichEditView::PrintPage](../Topic/CRichEditView::PrintPage.md)|Formata o texto especificado dentro da página dada.|  
|[CRichEditView::SetCharFormat](../Topic/CRichEditView::SetCharFormat.md)|Defina os atributos de formatação de caracteres para a seleção atual.|  
|[CRichEditView::SetMargins](../Topic/CRichEditView::SetMargins.md)|Defina as margens para essa rica o modo de edição.|  
|[CRichEditView::SetPaperSize](../Topic/CRichEditView::SetPaperSize.md)|Defina o tamanho de papel para essa rica o modo de edição.|  
|[CRichEditView::SetParaFormat](../Topic/CRichEditView::SetParaFormat.md)|Defina os atributos de formatação de parágrafo para a seleção atual.|  
|[CRichEditView::TextNotFound](../Topic/CRichEditView::TextNotFound.md)|Redefine o estado interno de pesquisa do controle.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRichEditView::GetClipboardData](../Topic/CRichEditView::GetClipboardData.md)|Recupera um objeto da área de transferência para um intervalo em esta rica o modo de edição.|  
|[CRichEditView::GetContextMenu](../Topic/CRichEditView::GetContextMenu.md)|Recupera um menu de contexto para usar o para baixo em um botão direito do mouse.|  
|[CRichEditView::IsSelected](../Topic/CRichEditView::IsSelected.md)|Indica se o item já foi selecionado ou OLE não.|  
|[CRichEditView::OnFindNext](../Topic/CRichEditView::OnFindNext.md)|Localiza a próxima ocorrência de uma subcadeia de caracteres.|  
|[CRichEditView::OnInitialUpdate](../Topic/CRichEditView::OnInitialUpdate.md)|Atualiza uma exibição quando primeira é anexado a um documento.|  
|[CRichEditView::OnPasteNativeObject](../Topic/CRichEditView::OnPasteNativeObject.md)|Recupera dados nativos de um item OLE.|  
|[CRichEditView::OnPrinterChanged](../Topic/CRichEditView::OnPrinterChanged.md)|Defina as características de impressão para o dispositivo dado.|  
|[CRichEditView::OnReplaceAll](../Topic/CRichEditView::OnReplaceAll.md)|Substitua todas as ocorrências de uma cadeia de caracteres fornecida com uma nova cadeia de caracteres.|  
|[CRichEditView::OnReplaceSel](../Topic/CRichEditView::OnReplaceSel.md)|Substitui a seleção atual.|  
|[CRichEditView::OnTextNotFound](../Topic/CRichEditView::OnTextNotFound.md)|Trata a notificação de usuário que o texto solicitado não foi encontrado.|  
|[CRichEditView::QueryAcceptData](../Topic/CRichEditView::QueryAcceptData.md)|Consultas a consulta sobre os dados em `IDataObject`.|  
|[CRichEditView::WrapChanged](../Topic/CRichEditView::WrapChanged.md)|Ajustar o dispositivo de saída de destino para essa rica o modo de edição, com base no valor de `m_nWordWrap`.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CRichEditView::m\_nBulletIndent](../Topic/CRichEditView::m_nBulletIndent.md)|Indica a quantidade de clipping para listas de marcador.|  
|[CRichEditView::m\_nWordWrap](../Topic/CRichEditView::m_nWordWrap.md)|Indica as restrições de quebra automática de linha.|  
  
## Comentários  
 “Um controle de edição rico” é uma janela com que o usuário pode inserir e editar texto.  Texto pode ser atribuído a formatação de caracteres e de parágrafo, e pode incluir VELHOS objetos inseridos.  Controles de edição ricos fornecem uma interface de programação para formatar o texto.  Em o entanto, um aplicativo deve implementar todos os componentes necessários da interface do usuário efetuar operações de formatação disponíveis para o usuário.  
  
 `CRichEditView` mantém a característica de texto e de formatação de texto.  `CRichEditDoc` mantém a lista de itens VELHOS de cliente que estão no modo.  `CRichEditCntrItem` fornece acesso de contêiner\- OLE item ao lado do cliente.  
  
 Este controle comum do windows \(e portanto [CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md) e classes relacionadas\) estão disponíveis somente para programas que executam sob as versões 3,51 \/98 Windows 95 e Windows NT e posterior.  
  
 Para um exemplo de como usar uma rica o modo de edição em um aplicativo MFC, consulte o aplicativo de exemplo [WORDPAD](../../top/visual-cpp-samples.md) .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CView](../Topic/CView%20Class.md)  
  
 [CCtrlView](../../mfc/reference/cctrlview-class.md)  
  
 `CRichEditView`  
  
## Requisitos  
 **Cabeçalho:** afxrich.h  
  
## Consulte também  
 [O MFC exemplos WORDPAD](../../top/visual-cpp-samples.md)   
 [Classe de CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)   
 [Classe de CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md)