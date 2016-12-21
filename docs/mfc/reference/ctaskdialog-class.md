---
title: "Classe de CTaskDialog | Microsoft Docs"
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
  - "CTaskDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTaskDialog"
ms.assetid: 1991ec98-ae56-4483-958b-233809c8c559
caps.latest.revision: 29
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTaskDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma caixa de diálogo pop\-up que funciona como uma caixa de mensagem mas pode exibir informações adicionais para o usuário.  `CTaskDialog` também inclui a funcionalidade para coletar informações do usuário.  
  
## Sintaxe  
  
```  
class CTaskDialog : public CObject  
```  
  
## Membros  
  
### Construtores  
  
|||  
|-|-|  
|[CTaskDialog::CTaskDialog](../Topic/CTaskDialog::CTaskDialog.md)|Constrói um objeto de `CTaskDialog` .|  
  
### Métodos  
  
|||  
|-|-|  
|[CTaskDialog::AddCommandControl](../Topic/CTaskDialog::AddCommandControl.md)|Adiciona um controle de botão de comando a `CTaskDialog`.|  
|[CTaskDialog::AddRadioButton](../Topic/CTaskDialog::AddRadioButton.md)|Adicionar um botão de opção a `CTaskDialog`.|  
|[CTaskDialog::ClickCommandControl](../Topic/CTaskDialog::ClickCommandControl.md)|Clica em um controle de botão de comando ou um botão comuns de programação.|  
|[CTaskDialog::ClickRadioButton](../Topic/CTaskDialog::ClickRadioButton.md)|Clica em um botão de opção por meio de programação.|  
|[CTaskDialog::DoModal](../Topic/CTaskDialog::DoModal.md)|Exibe `CTaskDialog`.|  
|[CTaskDialog::GetCommonButtonCount](../Topic/CTaskDialog::GetCommonButtonCount.md)|Retorna o número de botões comuns disponíveis.|  
|[CTaskDialog::GetCommonButtonFlag](../Topic/CTaskDialog::GetCommonButtonFlag.md)|Converte o de um botão padrão para o tipo comum associado com a classe de `CTaskDialog` .|  
|[CTaskDialog::GetCommonButtonId](../Topic/CTaskDialog::GetCommonButtonId.md)|Converte um dos tipos comuns do botão associados com a classe de `CTaskDialog` ao padrão do windows.|  
|[CTaskDialog::GetOptions](../Topic/CTaskDialog::GetOptions.md)|Retorna os sinalizadores da opção para este `CTaskDialog`.|  
|[CTaskDialog::GetSelectedCommandControlID](../Topic/CTaskDialog::GetSelectedCommandControlID.md)|Retorna o controle selecionado de botão de comando.|  
|[CTaskDialog::GetSelectedRadioButtonID](../Topic/CTaskDialog::GetSelectedRadioButtonID.md)|Retorna o botão de opção selecionado.|  
|[CTaskDialog::GetVerificationCheckboxState](../Topic/CTaskDialog::GetVerificationCheckboxState.md)|Recupera o estado da caixa de seleção de verificação.|  
|[CTaskDialog::IsCommandControlEnabled](../Topic/CTaskDialog::IsCommandControlEnabled.md)|Determina se um controle de botão de comando ou um botão comuns estão habilitados.|  
|[CTaskDialog::IsRadioButtonEnabled](../Topic/CTaskDialog::IsRadioButtonEnabled.md)|Determina se um botão de opção está habilitado.|  
|[CTaskDialog::IsSupported](../Topic/CTaskDialog::IsSupported.md)|Determina se o computador que está executando o aplicativo suporta `CTaskDialog`.|  
|[CTaskDialog::LoadCommandControls](../Topic/CTaskDialog::LoadCommandControls.md)|Adiciona controles de botão de comando usando dados da tabela de cadeia de caracteres.|  
|[CTaskDialog::LoadRadioButtons](../Topic/CTaskDialog::LoadRadioButtons.md)|Adiciona botões de opção usando dados da tabela de cadeia de caracteres.|  
|[CTaskDialog::NavigateTo](../Topic/CTaskDialog::NavigateTo.md)|Transfere o foco para outro `CTaskDialog`.|  
|[CTaskDialog::OnCommandControlClick](../Topic/CTaskDialog::OnCommandControlClick.md)|A estrutura chama esse método quando o usuário clica em um controle de botão de comando.|  
|[CTaskDialog::OnCreate](../Topic/CTaskDialog::OnCreate.md)|A estrutura chama esse método após criar `CTaskDialog`.|  
|[CTaskDialog::OnDestroy](../Topic/CTaskDialog::OnDestroy.md)|A estrutura chama esse método for imediatamente antes de `CTaskDialog`.|  
|[CTaskDialog::OnExpandButtonClick](../Topic/CTaskDialog::OnExpandButtonClick.md)|A estrutura chama esse método quando o usuário clica no botão de expansão.|  
|[CTaskDialog::OnHelp](../Topic/CTaskDialog::OnHelp.md)|A estrutura chama esse método quando um usuário solicita ajudam.|  
|[CTaskDialog::OnHyperlinkClick](../Topic/CTaskDialog::OnHyperlinkClick.md)|A estrutura chama esse método quando o usuário clicar em um hyperlink.|  
|[CTaskDialog::OnInit](../Topic/CTaskDialog::OnInit.md)|A estrutura chama esse método `CTaskDialog` quando é inicializado.|  
|[CTaskDialog::OnNavigatePage](../Topic/CTaskDialog::OnNavigatePage.md)|A estrutura chama esse método quando o usuário move o foco em relação a controles em `CTaskDialog`.|  
|[CTaskDialog::OnRadioButtonClick](../Topic/CTaskDialog::OnRadioButtonClick.md)|A estrutura chama esse método quando o usuário seleciona um controle de botão de opção.|  
|[CTaskDialog::OnTimer](../Topic/CTaskDialog::OnTimer.md)|A estrutura chama esse método quando o timer expira.|  
|[CTaskDialog::OnVerificationCheckboxClick](../Topic/CTaskDialog::OnVerificationCheckboxClick.md)|A estrutura chama esse método quando o usuário clica na caixa de seleção de verificação.|  
|[CTaskDialog::RemoveAllCommandControls](../Topic/CTaskDialog::RemoveAllCommandControls.md)|Remove todos os controles de comando de `CTaskDialog`.|  
|[CTaskDialog::RemoveAllRadioButtons](../Topic/CTaskDialog::RemoveAllRadioButtons.md)|Remove todos os botões de opção de `CTaskDialog`.|  
|[CTaskDialog::SetCommandControlOptions](../Topic/CTaskDialog::SetCommandControlOptions.md)|Atualiza um controle de botão de comando em `CTaskDialog`.|  
|[CTaskDialog::SetCommonButtonOptions](../Topic/CTaskDialog::SetCommonButtonOptions.md)|Atualiza um subconjunto dos botões comuns a ser ativados e exigem para elevar UAC.|  
|[CTaskDialog::SetCommonButtons](../Topic/CTaskDialog::SetCommonButtons.md)|Adiciona os botões comuns a `CTaskDialog`.|  
|[CTaskDialog::SetContent](../Topic/CTaskDialog::SetContent.md)|Atualiza o conteúdo de `CTaskDialog`.|  
|[CTaskDialog::SetDefaultCommandControl](../Topic/CTaskDialog::SetDefaultCommandControl.md)|Especifica o padrão controle de botão de comando.|  
|[CTaskDialog::SetDefaultRadioButton](../Topic/CTaskDialog::SetDefaultRadioButton.md)|Especifica o botão de opção padrão.|  
|[CTaskDialog::SetDialogWidth](../Topic/CTaskDialog::SetDialogWidth.md)|Ajustar a largura de `CTaskDialog`.|  
|[CTaskDialog::SetExpansionArea](../Topic/CTaskDialog::SetExpansionArea.md)|Atualiza a área de expansão de `CTaskDialog`.|  
|[CTaskDialog::SetFooterIcon](../Topic/CTaskDialog::SetFooterIcon.md)|Atualiza o ícone de rodapé para `CTaskDialog`.|  
|[CTaskDialog::SetFooterText](../Topic/CTaskDialog::SetFooterText.md)|Atualiza o texto no rodapé de `CTaskDialog`.|  
|[CTaskDialog::SetMainIcon](../Topic/CTaskDialog::SetMainIcon.md)|Atualiza o ícone de chave de `CTaskDialog`.|  
|[CTaskDialog::SetMainInstruction](../Topic/CTaskDialog::SetMainInstruction.md)|Atualiza a instrução principal de `CTaskDialog`.|  
|[CTaskDialog::SetOptions](../Topic/CTaskDialog::SetOptions.md)|Configurar as opções para `CTaskDialog`.|  
|[CTaskDialog::SetProgressBarMarquee](../Topic/CTaskDialog::SetProgressBarMarquee.md)|Configurar uma barra de famoso para `CTaskDialog` e adicioná\-la à caixa de diálogo.|  
|[CTaskDialog::SetProgressBarPosition](../Topic/CTaskDialog::SetProgressBarPosition.md)|Ajustar a posição de barra de progresso.|  
|[CTaskDialog::SetProgressBarRange](../Topic/CTaskDialog::SetProgressBarRange.md)|Ajustar o intervalo de barra de progresso.|  
|[CTaskDialog::SetProgressBarState](../Topic/CTaskDialog::SetProgressBarState.md)|Define o estado de barra de progresso e o exibe em `CTaskDialog`.|  
|[CTaskDialog::SetRadioButtonOptions](../Topic/CTaskDialog::SetRadioButtonOptions.md)|Habilita ou desabilita um botão de opção.|  
|[CTaskDialog::SetVerificationCheckbox](../Topic/CTaskDialog::SetVerificationCheckbox.md)|Define o estado selecionado da caixa de seleção de verificação.|  
|[CTaskDialog::SetVerificationCheckboxText](../Topic/CTaskDialog::SetVerificationCheckboxText.md)|Define o texto no lado direito da caixa de seleção de verificação.|  
|[CTaskDialog::SetWindowTitle](../Topic/CTaskDialog::SetWindowTitle.md)|Define o título de `CTaskDialog`.|  
|[CTaskDialog::ShowDialog](../Topic/CTaskDialog::ShowDialog.md)|Cria e exibe `CTaskDialog`.|  
|[CTaskDialog::TaskDialogCallback](../Topic/CTaskDialog::TaskDialogCallback.md)|A estrutura chama essa em resposta às várias mensagens do windows.|  
  
### Membros de dados  
  
|||  
|-|-|  
|`m_aButtons`|A matriz de controles botão de comando para `CTaskDialog`.|  
|`m_aRadioButtons`|A matriz de controles de botão de opção para `CTaskDialog`.|  
|`m_bVerified`|`TRUE` indica que a caixa de seleção de verificação é verificada; `FALSE` indica que não é.|  
|`m_footerIcon`|O ícone no rodapé de `CTaskDialog`.|  
|`m_hWnd`|Um identificador para a janela para `CTaskDialog`.|  
|`m_mainIcon`|O ícone de chave de `CTaskDialog`.|  
|`m_nButtonDisabled`|Uma máscara que indica quais botões comuns estão desativados.|  
|`m_nButtonElevation`|Uma máscara que indica que exigem comuns dos botões para elevar UAC.|  
|`m_nButtonId`|A identificação de O controle selecionado de botão de comando.|  
|`m_nCommonButton`|Uma máscara que indica quais botões comuns são exibidos em `CTaskDialog`.|  
|`m_nDefaultCommandControl`|A identificação do controle de botão de comando que é selecionado quando `CTaskDialog` é exibido.|  
|`m_nDefaultRadioButton`|A identificação do controle de botão de opção que é selecionado quando `CTaskDialog` é exibido.|  
|`m_nFlags`|Uma máscara que indica as opções para `CTaskDialog`.|  
|`m_nProgressPos`|A posição atual para a barra de progresso.  Esse valor deve estar entre `m_nProgressRangeMin` e `m_nProgressRangeMax`.|  
|`m_nProgressRangeMax`|O valor médio da barra de progresso.|  
|`m_nProgressRangeMin`|O valor médio da barra de progresso.|  
|`m_nProgressState`|O estado de barra de progresso.  Para mais informações, consulte [CTaskDialog::SetProgressBarState](../Topic/CTaskDialog::SetProgressBarState.md).|  
|`m_nRadioId`|A identificação de O controle selecionado de botão de opção.|  
|`m_nWidth`|A largura de `CTaskDialog` em pixels.|  
|`m_strCollapse`|A cadeia de caracteres que `CTaskDialog` exibe à direita da caixa de expansão quando informação é expandida oculta.|  
|`m_strContent`|a cadeia de caracteres de conteúdo de `CTaskDialog`.|  
|`m_strExpand`|A cadeia de caracteres que `CTaskDialog` exibe à direita da caixa de expansão quando informação expandida é exibida.|  
|`m_strFooter`|o rodapé de `CTaskDialog`.|  
|`m_strInformation`|Informações expandida para `CTaskDialog`.|  
|`m_strMainInstruction`|a instrução principal de `CTaskDialog`.|  
|`m_strTitle`|o título de `CTaskDialog`.|  
|`m_strVerification`|A cadeia de caracteres que `CTaskDialog` exibe à direita da caixa de seleção de verificação.|  
  
## Comentários  
 A classe de `CTaskDialog` substitui a caixa de mensagem padrão do windows e possui funcionalidades adicionais como os novos controles para coletar informações do usuário.  Essa classe é na biblioteca MFC em [!INCLUDE[vs_dev10_long](../../build/includes/vs_dev10_long_md.md)].  `CTaskDialog` deve começar com [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)]disponível.  Versões anteriores do windows não podem exibir o objeto de `CTaskDialog` .  Use `CTaskDialog::IsSupported` para determinar o tempo de execução se o usuário atual pode exibir a caixa de diálogo de tarefas.  A caixa de mensagem do windows padrão ainda tem suporte em [!INCLUDE[vs_dev10_long](../../build/includes/vs_dev10_long_md.md)].  
  
 `CTaskDialog` está disponível apenas quando você compila seu aplicativo usando a biblioteca Unicode.  
  
 `CTaskDialog` tem dois construtores diferentes.  Um construtor permite especificar dois botões de comando e um máximo de seis controles normais do botão.  Você pode adicionar mais botões de comando depois de criar `CTaskDialog`.  O segundo construtor não tem suporte para botões de comando, mas você pode adicionar um número ilimitado de controles normais do botão.  Para obter mais informações sobre os construtores, consulte [CTaskDialog::CTaskDialog](../Topic/CTaskDialog::CTaskDialog.md).  
  
 A imagem a seguir mostra um exemplo `CTaskDialog` para ilustrar o local dos controles.  
  
 ![Exemplo de um CTaskDialog](../../mfc/reference/media/ctaskdialogsample.png "CTaskDialogSample")  
Exemplo de CTaskDialog  
  
## Requisitos  
 **O sistema operacional requerido mínimo:** [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)]  
  
 **Cabeçalho:** afxtaskdialog.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Instruções passo a passo: adicionando um CTaskDialog a um aplicativo](../../mfc/walkthrough-adding-a-ctaskdialog-to-an-application.md)