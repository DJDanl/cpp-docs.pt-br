---
title: "Classe de CMFCToolBarButton | Microsoft Docs"
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
  - "CMFCToolBarButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolBarButton"
ms.assetid: 8a6ecffb-86b0-4f5c-8211-a9146b463efd
caps.latest.revision: 34
caps.handback.revision: 23
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolBarButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do botão para barras de ferramentas.  
  
## Sintaxe  
  
```  
class CMFCToolBarButton : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarButton::CMFCToolBarButton](../Topic/CMFCToolBarButton::CMFCToolBarButton.md)|As compilações e inicializam um objeto de `CMFCToolBarButton` .|  
|`CMFCToolBarButton::~CMFCToolBarButton`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarButton::CanBeDropped](../Topic/CMFCToolBarButton::CanBeDropped.md)|Especifica se um usuário pode posicionar um botão na barra de ferramentas ou o menu durante a personalização.|  
|[CMFCToolBarButton::CanBeStored](../Topic/CMFCToolBarButton::CanBeStored.md)|Especifica se o botão pode ser armazenado.|  
|[CMFCToolBarButton::CanBeStretched](../Topic/CMFCToolBarButton::CanBeStretched.md)|Especifica se um usuário pode redimensionar o botão durante a personalização.|  
|[CMFCToolBarButton::CompareWith](../Topic/CMFCToolBarButton::CompareWith.md)|Compara com essa instância do objeto fornecido `CMFCToolBarButton` .|  
|[CMFCToolBarButton::CopyFrom](../Topic/CMFCToolBarButton::CopyFrom.md)|Copia as propriedades de outro botão da barra de ferramentas para o botão atual.|  
|[CMFCToolBarButton::CreateFromOleData](../Topic/CMFCToolBarButton::CreateFromOleData.md)|Cria um objeto de `CMFCToolBarButton` do objeto fornecido de `COleDataObject` .|  
|`CMFCToolBarButton::CreateObject`|Usado pela estrutura dinâmica para criar uma instância de esse tipo da classe.|  
|[CMFCToolBarButton::EnableWindow](../Topic/CMFCToolBarButton::EnableWindow.md)|Habilita ou desabilita a entrada de mouse e teclado.|  
|[CMFCToolBarButton::ExportToMenuButton](../Topic/CMFCToolBarButton::ExportToMenuButton.md)|Copia texto do botão da barra de ferramentas para um menu.|  
|[CMFCToolBarButton::GetClipboardFormat](../Topic/CMFCToolBarButton::GetClipboardFormat.md)|Recupera o formato global da área de transferência para o aplicativo.|  
|[CMFCToolBarButton::GetHwnd](../Topic/CMFCToolBarButton::GetHwnd.md)|Recupera o identificador de janela que está associado com o botão da barra de ferramentas.|  
|[CMFCToolBarButton::GetImage](../Topic/CMFCToolBarButton::GetImage.md)|Retorna o índice de imagem do botão.|  
|[CMFCToolBarButton::GetInvalidateRect](../Topic/CMFCToolBarButton::GetInvalidateRect.md)|Recupera a região da área cliente do botão que deve ser redesenhado.|  
|[CMFCToolBarButton::GetParentWnd](../Topic/CMFCToolBarButton::GetParentWnd.md)|Recupera a janela pai do botão.|  
|[CMFCToolBarButton::GetProtectedCommands](../Topic/CMFCToolBarButton::GetProtectedCommands.md)|Recupera a lista de comandos que o usuário não pode personalizar.|  
|[CMFCToolBarButton::GetTextSize](../Topic/CMFCToolBarButton::GetTextSize.md)|Retorna o tamanho do texto do botão.|  
|[CMFCToolBarButton::HasFocus](../Topic/CMFCToolBarButton::HasFocus.md)|Determina se o botão tem o foco de entrada atual.|  
|[CMFCToolBarButton::HaveHotBorder](../Topic/CMFCToolBarButton::HaveHotBorder.md)|Determina se uma borda do botão é exibida quando um usuário selecione.|  
|[CMFCToolBarButton::IsDrawImage](../Topic/CMFCToolBarButton::IsDrawImage.md)|Determina se uma imagem é exibida no botão.|  
|[CMFCToolBarButton::IsDrawText](../Topic/CMFCToolBarButton::IsDrawText.md)|Determina se um rótulo de texto é exibida no botão.|  
|[CMFCToolBarButton::IsDroppedDown](../Topic/CMFCToolBarButton::IsDroppedDown.md)|Determina se o botão exibe um submenu.|  
|[CMFCToolBarButton::IsEditable](../Topic/CMFCToolBarButton::IsEditable.md)|Determina se o botão pode ser personalizado.|  
|[CMFCToolBarButton::IsExtraSize](../Topic/CMFCToolBarButton::IsExtraSize.md)|Determina se o botão pode ser exibido com uma borda estendido.|  
|[CMFCToolBarButton::IsFirstInGroup](../Topic/CMFCToolBarButton::IsFirstInGroup.md)|Determina se o botão está na primeira posição em seu grupo de botões.|  
|[CMFCToolBarButton::IsHidden](../Topic/CMFCToolBarButton::IsHidden.md)|Determina se o botão está oculto.|  
|[CMFCToolBarButton::IsHorizontal](../Topic/CMFCToolBarButton::IsHorizontal.md)|Determina se o botão está localizado em uma barra de ferramentas horizontal.|  
|[CMFCToolBarButton::IsLastInGroup](../Topic/CMFCToolBarButton::IsLastInGroup.md)|Especifica se o botão está na posição a última em seu grupo de botões.|  
|[CMFCToolBarButton::IsLocked](../Topic/CMFCToolBarButton::IsLocked.md)|Determina se o botão está em uma barra de ferramentas \(não\) personalizável bloqueado.|  
|[CMFCToolBarButton::IsOwnerOf](../Topic/CMFCToolBarButton::IsOwnerOf.md)|Determina se o botão é o proprietário do identificador de janela fornecido.|  
|[CMFCToolBarButton::IsVisible](../Topic/CMFCToolBarButton::IsVisible.md)|Determina se o botão na barra de ferramentas é visível.|  
|[CMFCToolBarButton::IsWindowVisible](../Topic/CMFCToolBarButton::IsWindowVisible.md)|Determina se o identificador de janela subjacente do botão é visível.|  
|[CMFCToolBarButton::NotifyCommand](../Topic/CMFCToolBarButton::NotifyCommand.md)|Especifica se o botão processa a mensagem de [WM\_COMMAND](http://msdn.microsoft.com/library/windows/desktop/ms647591) .|  
|[CMFCToolBarButton::OnAddToCustomizePage](../Topic/CMFCToolBarButton::OnAddToCustomizePage.md)|Chamado pela estrutura quando o botão é adicionado a uma caixa de diálogo de **Personalizar** .|  
|[CMFCToolBarButton::OnBeforeDrag](../Topic/CMFCToolBarButton::OnBeforeDrag.md)|Especifica se o botão pode ser arrastado.|  
|[CMFCToolBarButton::OnBeforeDrop](../Topic/CMFCToolBarButton::OnBeforeDrop.md)|Especifica se um usuário pode soltar o botão na barra de ferramentas de destino.|  
|[CMFCToolBarButton::OnCalculateSize](../Topic/CMFCToolBarButton::OnCalculateSize.md)|Chamado pela estrutura para calcular o tamanho do botão para o contexto de dispositivo e o estado de encaixe especificados.|  
|[CMFCToolBarButton::OnCancelMode](../Topic/CMFCToolBarButton::OnCancelMode.md)|Chamado pela estrutura para manipular a mensagem de [WM\_CANCELMODE](http://msdn.microsoft.com/library/windows/desktop/ms632615) .|  
|[CMFCToolBarButton::OnChangeParentWnd](../Topic/CMFCToolBarButton::OnChangeParentWnd.md)|Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas.|  
|[CMFCToolBarButton::OnClick](../Topic/CMFCToolBarButton::OnClick.md)|Chamado pela estrutura quando o usuário clica no botão do mouse.|  
|[CMFCToolBarButton::OnClickUp](../Topic/CMFCToolBarButton::OnClickUp.md)|Chamado pela estrutura quando o usuário liberar o botão do mouse.|  
|[CMFCToolBarButton::OnContextHelp](../Topic/CMFCToolBarButton::OnContextHelp.md)|Chamado pela estrutura quando a barra de ferramentas pai manipular uma mensagem de `WM_HELPHITTEST` .|  
|[CMFCToolBarButton::OnCtlColor](../Topic/CMFCToolBarButton::OnCtlColor.md)|Chamado pela estrutura quando a barra de ferramentas pai manipular uma mensagem de `WM_CTLCOLOR` .|  
|[CMFCToolBarButton::OnCustomizeMenu](../Topic/CMFCToolBarButton::OnCustomizeMenu.md)|Permite que o botão modifique o menu fornecido quando o aplicativo exibe um menu de atalho na barra de ferramentas pai.|  
|[CMFCToolBarButton::OnDblClk](../Topic/CMFCToolBarButton::OnDblClk.md)|Chamado pela estrutura quando a barra de ferramentas pai manipular uma mensagem de [WM\_LBUTTONDBLCLK](http://msdn.microsoft.com/library/windows/desktop/ms645606) .|  
|[CMFCToolBarButton::OnDraw](../Topic/CMFCToolBarButton::OnDraw.md)|Chamado pela estrutura para desenhar o botão usando os estilos e opções especificadas.|  
|[CMFCToolBarButton::OnDrawOnCustomizeList](../Topic/CMFCToolBarButton::OnDrawOnCustomizeList.md)|Chamado pela estrutura para desenhar o botão no painel de **Comandos** da caixa de diálogo de **Personalizar** .|  
|[CMFCToolBarButton::OnGetCustomToolTipText](../Topic/CMFCToolBarButton::OnGetCustomToolTipText.md)|Chamado pela estrutura para recuperar o texto personalizado de dica de ferramenta para o botão.|  
|[CMFCToolBarButton::OnGlobalFontsChanged](../Topic/CMFCToolBarButton::OnGlobalFontsChanged.md)|Chamado pela estrutura quando a fonte global alterar.|  
|[CMFCToolBarButton::OnMove](../Topic/CMFCToolBarButton::OnMove.md)|Chamado pela estrutura quando a barra de ferramentas pai mover.|  
|[CMFCToolBarButton::OnShow](../Topic/CMFCToolBarButton::OnShow.md)|Chamado pela estrutura quando o botão se torna visível ou invisível.|  
|[CMFCToolBarButton::OnSize](../Topic/CMFCToolBarButton::OnSize.md)|Chamado pela estrutura quando a barra de ferramentas pai se altera sua posição e tamanho ou essa alteração requerem o botão alterar o tamanho.|  
|[CMFCToolBarButton::OnToolHitTest](../Topic/CMFCToolBarButton::OnToolHitTest.md)|Chamado pela estrutura quando a barra de ferramentas pai deve determinar se um ponto está no retângulo delimitador do botão.|  
|[CMFCToolBarButton::OnUpdateToolTip](../Topic/CMFCToolBarButton::OnUpdateToolTip.md)|Chamado pela estrutura quando a barra de ferramentas pai atualizar o texto de tooltip.|  
|[CMFCToolBarButton::PrepareDrag](../Topic/CMFCToolBarButton::PrepareDrag.md)|Chamado pela estrutura quando o botão é o ponto de executar uma operação de arrastar e soltar.|  
|[CMFCToolBarButton::Rect](../Topic/CMFCToolBarButton::Rect.md)|Recupera o retângulo delimitador do botão.|  
|[CMFCToolBarButton::ResetImageToDefault](../Topic/CMFCToolBarButton::ResetImageToDefault.md)|Defina o valor padrão a imagem que está associada com o botão.|  
|[CMFCToolBarButton::SaveBarState](../Topic/CMFCToolBarButton::SaveBarState.md)|Salvar o estado do botão da barra de ferramentas.|  
|[CMFCToolBarButton::Serialize](../Topic/CMFCToolBarButton::Serialize.md)|Este objeto ler de um arquivo ou neutro o grava em um arquivo neutro.  Overrides \( [CObject::Serialize](../Topic/CObject::Serialize.md).\)|  
|[CMFCToolBarButton::SetACCData](../Topic/CMFCToolBarButton::SetACCData.md)|Preenche o objeto fornecido de `CAccessibilityData` com dados de acessibilidade do botão da barra de ferramentas.|  
|[CMFCToolBarButton::SetClipboardFormatName](../Topic/CMFCToolBarButton::SetClipboardFormatName.md)|Renomeie o formato global da área de transferência.|  
|[CMFCToolBarButton::SetImage](../Topic/CMFCToolBarButton::SetImage.md)|Define o índice de imagem do botão.|  
|[CMFCToolBarButton::SetProtectedCommands](../Topic/CMFCToolBarButton::SetProtectedCommands.md)|Define a lista de comandos que o usuário não pode personalizar.|  
|[CMFCToolBarButton::SetRadio](../Topic/CMFCToolBarButton::SetRadio.md)|Chamado pela estrutura quando um botão mude seu estado selecionado.|  
|[CMFCToolBarButton::SetRect](../Topic/CMFCToolBarButton::SetRect.md)|Define o retângulo delimitador do botão.|  
|[CMFCToolBarButton::SetStyle](../Topic/CMFCToolBarButton::SetStyle.md)|Defina o estilo do botão.|  
|[CMFCToolBarButton::SetVisible](../Topic/CMFCToolBarButton::SetVisible.md)|Especifica se o botão é visível.|  
|[CMFCToolBarButton::Show](../Topic/CMFCToolBarButton::Show.md)|Mostra ou oculta o botão.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBarButton::m\_bImage](../Topic/CMFCToolBarButton::m_bImage.md)|Especifica se uma imagem é exibida no botão.|  
|[CMFCToolBarButton::m\_bText](../Topic/CMFCToolBarButton::m_bText.md)|Especifica se um rótulo de texto é exibida no botão.|  
|[CMFCToolBarButton::m\_bTextBelow](../Topic/CMFCToolBarButton::m_bTextBelow.md)|Especifica se o rótulo de texto é exibida embaixo de imagem no botão.|  
|[CMFCToolBarButton::m\_bUserButton](../Topic/CMFCToolBarButton::m_bUserButton.md)|Especifica se o botão tem uma imagem definido pelo usuário.|  
|[CMFCToolBarButton::m\_bWholeText](../Topic/CMFCToolBarButton::m_bWholeText.md)|Especifica se o botão exibe seu rótulo de texto completo mesmo se não couber no retângulo delimitador.|  
|[CMFCToolBarButton::m\_bWrap](../Topic/CMFCToolBarButton::m_bWrap.md)|Especifica se o botão próximo a um separador será colocado na próxima linha.|  
|[CMFCToolBarButton::m\_bWrapText](../Topic/CMFCToolBarButton::m_bWrapText.md)|Especifica se multi\-linha rótulos de texto está habilitada.|  
|[CMFCToolBarButton::m\_nID](../Topic/CMFCToolBarButton::m_nID.md)|A identificação de comando do botão.|  
|[CMFCToolBarButton::m\_nStyle](../Topic/CMFCToolBarButton::m_nStyle.md)|O estilo do botão.|  
|[CMFCToolBarButton::m\_strText](../Topic/CMFCToolBarButton::m_strText.md)|O rótulo de texto do botão.|  
  
## Comentários  
 Um objeto de `CMFCToolbarButton` é um controle que reside em uma barra de ferramentas.  Seu comportamento lembra a de um botão comum.  Você pode atribuir uma imagem e um rótulo de texto para este objeto.  Um botão na barra de ferramentas também pode ter uma identificação de comando  Quando o usuário clica no botão da barra de ferramentas, a estrutura executa o comando que essa identificação especificar.  
  
 Normalmente, os botões da barra de ferramentas podem ser personalizados: o usuário pode arrastar os botões da barra de ferramentas para outra, e colar, copiar, excluir, editar e rótulos e imagens de texto.  Para impedir que o usuário personaliza a barra de ferramentas, você pode bloquear a barra de ferramentas de duas maneiras.  Ou define o parâmetro de `bLocked` a `TRUE` quando você chama [CMFCToolBar::LoadToolBar](../Topic/CMFCToolBar::LoadToolBar.md), ou adiciona a identificação de comando de um botão individual para a lista global de comandos protegidos usando o método de [CMFCToolBarButton::SetProtectedCommands](../Topic/CMFCToolBarButton::SetProtectedCommands.md) .  
  
 Imagens de exibição de objetos de`CMFCToolBarButton` das coleções globais da barra de ferramentas imagens no aplicativo.  Essas coleções são mantidas pela barra de ferramentas pai, [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md).  Para mais informações, consulte [Classe de CMFCToolBarImages](../../mfc/reference/cmfctoolbarimages-class.md).  
  
 Quando o usuário clica em um botão da barra de ferramentas, sua barra de ferramentas pai processa a mensagem de mouse e comunica as ações apropriadas para o botão.  Se o botão tem um identificador válido de comando, a barra de ferramentas pai envia a mensagem de `WM_COMMAND` para o elemento pai.  
  
 A classe de `CMFCToolBarButton` é a classe base para outras classes de botão da barra de ferramentas, como [Classe de CMFCToolBarMenuButton](../../mfc/reference/cmfctoolbarmenubutton-class.md), [Classe de CMFCToolBarEditBoxButton](../Topic/CMFCToolBarEditBoxButton%20Class.md), e [Classe de CMFCToolBarComboBoxButton](../Topic/CMFCToolBarComboBoxButton%20Class.md).  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar um objeto de `CMFCToolBarButton` usando vários métodos na classe de `CMFCToolBarButton` .  O exemplo ilustra como habilitar a entrada de mouse e teclado, defina o índice da imagem do botão, defina o retângulo delimitador do botão, e fazer o botão visível.  Este trecho de código é parte de [Exemplo de controle da guia](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_TabControl#1](../../mfc/reference/codesnippet/CPP/cmfctoolbarbutton-class_1.cpp)]  
[!code-cpp[NVC_MFC_TabControl#2](../../mfc/reference/codesnippet/CPP/cmfctoolbarbutton-class_2.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxtoolbarbutton.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe de CMFCToolBarImages](../../mfc/reference/cmfctoolbarimages-class.md)   
 [CMFCToolBarButton::OnClick](../Topic/CMFCToolBarButton::OnClick.md)   
 [CMFCToolBarButton::NotifyCommand](../Topic/CMFCToolBarButton::NotifyCommand.md)