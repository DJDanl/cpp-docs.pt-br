---
title: "Classe de CMFCToolBar | Microsoft Docs"
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
  - "CMFCToolBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCToolBar"
ms.assetid: e7679c01-fb94-44c0-98c6-3af955292fb5
caps.latest.revision: 48
caps.handback.revision: 36
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCToolBar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCToolBar` é semelhante a [Classe de CToolBar](../../mfc/reference/ctoolbar-class.md), mas fornece suporte adicional para recursos de interface do usuário.  Esses incluem barras de ferramentas lisas, toolbars com imagens, ícones grandes quentes, botões de paginação, barras de ferramentas com barreira, controles do rebar em texto, imagens, imagens de plano de fundo, e barras de ferramentas com guias.  A classe de `CMFCToolBar` também contém suporte interno para a personalização do usuário de barras de ferramentas e menus, o arrastar e soltar entre barras de ferramentas e menus, botões da caixa de combinação, botões de caixa de edição, as desbastadoras máquinas de cor, e botões de rolagem \- anterior.  
  
## Sintaxe  
  
```  
class CMFCToolBar : public CMFCBaseToolBar  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|`CMFCToolBar::CMFCToolBar`|Construtor padrão.|  
|`CMFCToolBar::~CMFCToolBar`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBar::AddBasicCommand](../Topic/CMFCToolBar::AddBasicCommand.md)|Adiciona um comando de menu à lista de comandos que são sempre exibidos quando um usuário abre um menu.|  
|[CMFCToolBar::AddCommandUsage](../Topic/CMFCToolBar::AddCommandUsage.md)|Sai por um contador o que está associado com o comando dado.|  
|[CMFCToolBar::AddToolBarForImageCollection](../Topic/CMFCToolBar::AddToolBarForImageCollection.md)|Adicionar imagens dos recursos de interface do usuário à coleção de imagens no aplicativo.|  
|[CMFCToolBar::AdjustLayout](../Topic/CMFCToolBar::AdjustLayout.md)|Recalcula o tamanho e a posição de uma barra de ferramentas.  Overrides \( [CBasePane::AdjustLayout](../Topic/CBasePane::AdjustLayout.md)\).|  
|[CMFCToolBar::AdjustSize](../Topic/CMFCToolBar::AdjustSize.md)|Recalcula o tamanho da barra de ferramentas.|  
|[CMFCToolBar::AllowChangeTextLabels](../Topic/CMFCToolBar::AllowChangeTextLabels.md)|Especifica se os rótulos de texto podem ser mostradas em imagens nos botões da barra de ferramentas.|  
|[CMFCToolBar::AreTextLabels](../Topic/CMFCToolBar::AreTextLabels.md)|Especifica se os rótulos de texto em imagens são exibidas atualmente nos botões da barra de ferramentas.|  
|[CMFCToolBar::AutoGrayInactiveImages](../Topic/CMFCToolBar::AutoGrayInactiveImages.md)|Ativar ou desativa verificação que a geração automática de botão inativo imagens.|  
|[CMFCToolBar::ButtonToIndex](../Topic/CMFCToolBar::ButtonToIndex.md)|Retorna o índice de um objeto especificado de [Classe de CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md) na barra de ferramentas.|  
|[CMFCToolBar::CalcFixedLayout](../Topic/CMFCToolBar::CalcFixedLayout.md)|Calcula o tamanho horizontal da barra de ferramentas.  Overrides \( [CBasePane::CalcFixedLayout](../Topic/CBasePane::CalcFixedLayout.md).\)|  
|[CMFCToolBar::CalcSize](../Topic/CMFCToolBar::CalcSize.md)|Chamado pela estrutura como parte do processo de cálculo de layout.  Overrides \( [CPane::CalcSize](../Topic/CPane::CalcSize.md).\)|  
|[CMFCToolBar::CanHandleSiblings](../Topic/CMFCToolBar::CanHandleSiblings.md)|Determina se a barra de ferramentas e seu irmão são posicionados no mesmo painel.|  
|[CMFCToolBar::CleanUpImages](../Topic/CMFCToolBar::CleanUpImages.md)|Libera os recursos do sistema atribuídos para imagens da barra de ferramentas.|  
|[CMFCToolBar::CleanUpLockedImages](../Topic/CMFCToolBar::CleanUpLockedImages.md)|Libera os recursos do sistema atribuídos para imagens com barreira da barra de ferramentas.|  
|[CMFCToolBar::CanBeClosed](../Topic/CMFCToolBar::CanBeClosed.md)|Especifica se um usuário pode fechar a barra de ferramentas.  Overrides \( [CBasePane::CanBeClosed](../Topic/CBasePane::CanBeClosed.md).\)|  
|[CMFCToolBar::CanBeRestored](../Topic/CMFCToolBar::CanBeRestored.md)|Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização.|  
|[CMFCToolBar::CanFocus](../Topic/CMFCToolBar::CanFocus.md)|Especifica se o painel pode receber o foco.  Overrides \( [CBasePane::CanFocus](../Topic/CBasePane::CanFocus.md).\)|  
|[CMFCToolBar::CanHandleSiblings](../Topic/CMFCToolBar::CanHandleSiblings.md)|Determina se a barra de ferramentas e seu irmão são posicionados no mesmo painel.|  
|[CMFCToolBar::CommandToIndex](../Topic/CMFCToolBar::CommandToIndex.md)|Retorna o índice de botão na barra de ferramentas com um certo ID de comando|  
|[CMFCToolBar::Create](../Topic/CMFCToolBar::Create.md)|Cria um objeto de `CMFCToolBar` .|  
|[CMFCToolBar::CreateEx](../Topic/CMFCToolBar::CreateEx.md)|Cria um objeto de `CMFCToolBar` que use opções adicionais de estilo, como ícones grandes.|  
|[CMFCToolBar::Deactivate](../Topic/CMFCToolBar::Deactivate.md)|Desativa a barra de ferramentas.|  
|[CMFCToolBar::EnableCustomizeButton](../Topic/CMFCToolBar::EnableCustomizeButton.md)|Habilita ou desabilita o botão de **Adicionar ou Remover Botões** que aparece no final da barra de ferramentas.|  
|[CMFCToolBar::EnableDocking](../Topic/CMFCToolBar::EnableDocking.md)|Permite que o encaixe do painel para o quadro chave.  Overrides \( [CBasePane::EnableDocking](../Topic/CBasePane::EnableDocking.md).\)|  
|[CMFCToolBar::EnableLargeIcons](../Topic/CMFCToolBar::EnableLargeIcons.md)|Habilita ou desabilita ícones grandes nos botões da barra de ferramentas.|  
|[CMFCToolBar::EnableQuickCustomization](../Topic/CMFCToolBar::EnableQuickCustomization.md)|Habilita ou desabilita a personalização rápido de barras de ferramentas para que o usuário pode pressionar a tecla de **Alt** e arraste um botão para um novo local.|  
|[CMFCToolBar::EnableReflections](../Topic/CMFCToolBar::EnableReflections.md)|Habilita ou reflexo de comando desativa.|  
|[CMFCToolBar::EnableTextLabels](../Topic/CMFCToolBar::EnableTextLabels.md)|Habilita ou desabilita rótulos de texto em imagens do botão da barra de ferramentas.|  
|[CMFCToolBar::FromHandlePermanent](../Topic/CMFCToolBar::FromHandlePermanent.md)|Recupera um ponteiro para o objeto de `CMFCToolBar` que contém o identificador de janela dado.|  
|[CMFCToolBar::GetAllButtons](../Topic/CMFCToolBar::GetAllButtons.md)|Retorna uma lista somente leitura de botões na barra de ferramentas.|  
|[CMFCToolBar::GetAllToolbars](../Topic/CMFCToolBar::GetAllToolbars.md)|Retorna uma lista somente leitura de todas as barras de ferramentas para o aplicativo.|  
|[CMFCToolBar::GetBasicCommands](../Topic/CMFCToolBar::GetBasicCommands.md)|Retorna uma lista somente leitura de comandos básicos definidos no aplicativo.|  
|[CMFCToolBar::GetButton](../Topic/CMFCToolBar::GetButton.md)|Retorna um ponteiro para o objeto de `CMFCToolBarButton` que possui um índice especificado do botão da barra de ferramentas.|  
|[CMFCToolBar::GetButtonInfo](../Topic/CMFCToolBar::GetButtonInfo.md)|Retorna a identificação de comando, o estilo, e o índice da imagem de botão em um índice especificado.|  
|[CMFCToolBar::GetButtonSize](../Topic/CMFCToolBar::GetButtonSize.md)|Retorna as dimensões de cada botão na barra de ferramentas.|  
|[CMFCToolBar::GetButtonStyle](../Topic/CMFCToolBar::GetButtonStyle.md)|Retorna o estilo atual do botão da barra de ferramentas que está localizado no índice especificado.|  
|[CMFCToolBar::GetButtonText](../Topic/CMFCToolBar::GetButtonText.md)|Retorna o rótulo de texto de um botão que possui um índice especificado.|  
|[CMFCToolBar::GetColdImages](../Topic/CMFCToolBar::GetColdImages.md)|Retorna um ponteiro para a coleção de imagens frias do botão da barra de ferramentas para o aplicativo.|  
|[CMFCToolBar::GetColumnWidth](../Topic/CMFCToolBar::GetColumnWidth.md)|Retorna a largura dos botões da barra de ferramentas.|  
|[CMFCToolBar::GetCommandButtons](../Topic/CMFCToolBar::GetCommandButtons.md)|Retorna uma lista de botões que têm uma identificação especificado de comando de todas as barras de ferramentas para o aplicativo.|  
|[CMFCToolBar::GetCount](../Topic/CMFCToolBar::GetCount.md)|Retorna o número de botões e separadores da barra de ferramentas.|  
|[CMFCToolBar::GetCustomizeButton](../Topic/CMFCToolBar::GetCustomizeButton.md)|Recupera um ponteiro para o objeto de `CMFCCustomizeButton` que está associado com a barra de ferramentas.|  
|[CMFCToolBar::GetDefaultImage](../Topic/CMFCToolBar::GetDefaultImage.md)|Retorna o índice da imagem padrão para um botão da barra de ferramentas com um certo ID de comando|  
|[CMFCToolBar::GetDisabledImages](../Topic/CMFCToolBar::GetDisabledImages.md)|Retorna um ponteiro para a coleção de imagens que são usadas para os botões da barra de ferramentas desativados no aplicativo.|  
|[CMFCToolBar::GetDisabledMenuImages](../Topic/CMFCToolBar::GetDisabledMenuImages.md)|Retorna um ponteiro para a coleção de imagens que são usadas para os botões desativados no menu no aplicativo.|  
|[CMFCToolBar::GetDroppedDownMenu](../Topic/CMFCToolBar::GetDroppedDownMenu.md)|Recupera um ponteiro para o objeto botão de menu que está exibindo atualmente o submenu.|  
|[CMFCToolBar::GetGrayDisabledButtons](../Topic/CMFCToolBar::GetGrayDisabledButtons.md)|Especifica se as imagens dos botões estão desativados versões permanecerá esmaecido imagens normais do botão, ou extraído da coleção do botão desativado imagens.|  
|[CMFCToolBar::GetHighlightedButton](../Topic/CMFCToolBar::GetHighlightedButton.md)|Retorna um ponteiro para o botão da barra de ferramentas que é realçado no momento.|  
|[CMFCToolBar::GetHotBorder](../Topic/CMFCToolBar::GetHotBorder.md)|Determina se os botões da barra de ferramentas quente\- são rastreadas.|  
|[CMFCToolBar::GetHotTextColor](../Topic/CMFCToolBar::GetHotTextColor.md)|Retorna a cor do texto dos botões da barra de ferramentas realçadas.|  
|[CMFCToolBar::GetHwndLastFocus](../Topic/CMFCToolBar::GetHwndLastFocus.md)|Retorna um identificador para a janela que tem o foco de entrada imediatamente antes da barra de ferramentas fez.|  
|[CMFCToolBar::GetIgnoreSetText](../Topic/CMFCToolBar::GetIgnoreSetText.md)|Especifica se chamadas aos rótulos de conjunto de botões são ignorados.|  
|[CMFCToolBar::GetImageSize](../Topic/CMFCToolBar::GetImageSize.md)|Retorna o tamanho atual de imagens do botão da barra de ferramentas.|  
|[CMFCToolBar::GetImages](../Topic/CMFCToolBar::GetImages.md)|Retorna um ponteiro para a coleção de imagens do botão padrão no aplicativo.|  
|[CMFCToolBar::GetImagesOffset](../Topic/CMFCToolBar::GetImagesOffset.md)|Retorna o deslocamento do índice usado para localizar as imagens do botão da barra de ferramentas para a barra de ferramentas para a lista global de imagens do botão da barra de ferramentas.|  
|[CMFCToolBar::GetInvalidateItemRect](../Topic/CMFCToolBar::GetInvalidateItemRect.md)|Recupera a região da área cliente que deve ser redesenhada no botão no índice especificado.|  
|[CMFCToolBar::GetItemID](../Topic/CMFCToolBar::GetItemID.md)|Retorna a identificação de comando do botão da barra de ferramentas em um índice especificado.|  
|[CMFCToolBar::GetItemRect](../Topic/CMFCToolBar::GetItemRect.md)|Retorna o retângulo delimitador de botão em um índice especificado.|  
|[CMFCToolBar::GetLargeColdImages](../Topic/CMFCToolBar::GetLargeColdImages.md)|Retorna um ponteiro para a coleção de grandes imagens frias do botão da barra de ferramentas para o aplicativo.|  
|[CMFCToolBar::GetLargeDisabledImages](../Topic/CMFCToolBar::GetLargeDisabledImages.md)|Retorna um ponteiro para a coleção de imagens grandes desativados do botão da barra de ferramentas para o aplicativo.|  
|[CMFCToolBar::GetLargeImages](../Topic/CMFCToolBar::GetLargeImages.md)|Retorna um ponteiro para a coleção de grandes imagens do botão da barra de ferramentas para o aplicativo.|  
|[CMFCToolBar::GetLockedColdImages](../Topic/CMFCToolBar::GetLockedColdImages.md)|Retorna um ponteiro para a coleção de imagens frias bloqueados na barra de ferramentas.|  
|[CMFCToolBar::GetLockedDisabledImages](../Topic/CMFCToolBar::GetLockedDisabledImages.md)|Retorna um ponteiro para a coleção de imagens com barreira desativado na barra de ferramentas.|  
|[CMFCToolBar::GetLockedImages](../Topic/CMFCToolBar::GetLockedImages.md)|Retorna um ponteiro para a coleção de imagens com barreira de botão na barra de ferramentas.|  
|[CMFCToolBar::GetLockedImageSize](../Topic/CMFCToolBar::GetLockedImageSize.md)|Retorna o tamanho padrão de imagens com barreira da barra de ferramentas.|  
|[CMFCToolBar::GetLockedMenuImages](../Topic/CMFCToolBar::GetLockedMenuImages.md)|Retorna um ponteiro para a coleção de imagens com barreira de menu da barra de ferramentas na barra de ferramentas.|  
|[CMFCToolBar::GetMenuButtonSize](../Topic/CMFCToolBar::GetMenuButtonSize.md)|Retorna o tamanho dos botões de menu no aplicativo.|  
|[CMFCToolBar::GetMenuImageSize](../Topic/CMFCToolBar::GetMenuImageSize.md)|Retorna o tamanho de imagens do botão de menu no aplicativo.|  
|[CMFCToolBar::GetMenuImages](../Topic/CMFCToolBar::GetMenuImages.md)|Retorna um ponteiro para a coleção de imagens do botão de menu no aplicativo.|  
|[CMFCToolBar::GetOrigButtons](../Topic/CMFCToolBar::GetOrigButtons.md)|Recupera a coleção de botões não personalizados da barra de ferramentas.|  
|[CMFCToolBar::GetOrigResetButtons](../Topic/CMFCToolBar::GetOrigResetButtons.md)|Recupera a coleção de botões de reinicialização não personalizados da barra de ferramentas.|  
|[CMFCToolBar::GetResourceID](../Topic/CMFCToolBar::GetResourceID.md)|Recupera a identificação de recurso da barra de ferramentas.|  
|[CMFCToolBar::GetRouteCommandsViaFrame](../Topic/CMFCToolBar::GetRouteCommandsViaFrame.md)|Determina qual objeto, o elemento pai ou o proprietário, envia comandos para a barra de ferramentas.|  
|[CMFCToolBar::GetRowHeight](../Topic/CMFCToolBar::GetRowHeight.md)|Retorna a altura dos botões da barra de ferramentas.|  
|[CMFCToolBar::GetShowTooltips](../Topic/CMFCToolBar::GetShowTooltips.md)|Especifica se as dicas de ferramenta são exibidas para os botões da barra de ferramentas.|  
|[CMFCToolBar::GetSiblingToolBar](../Topic/CMFCToolBar::GetSiblingToolBar.md)|Recupera o irmão da barra de ferramentas.|  
|[CMFCToolBar::GetUserImages](../Topic/CMFCToolBar::GetUserImages.md)|Retorna um ponteiro para a coleção de imagens definidas pelo usuário do botão da barra de ferramentas para o aplicativo.|  
|[CMFCToolBar::HitTest](../Topic/CMFCToolBar::HitTest.md)|Retorna o índice do botão da barra de ferramentas que está localizado na posição especificada.|  
|[CMFCToolBar::InsertButton](../Topic/CMFCToolBar::InsertButton.md)|Insere um botão na barra de ferramentas.|  
|[CMFCToolBar::InsertSeparator](../Topic/CMFCToolBar::InsertSeparator.md)|Insere um separador na barra de ferramentas.|  
|[CMFCToolBar::InvalidateButton](../Topic/CMFCToolBar::InvalidateButton.md)|Invalida a área cliente do botão da barra de ferramentas que existe no índice fornecido.|  
|[CMFCToolBar::IsAddRemoveQuickCustomize](../Topic/CMFCToolBar::IsAddRemoveQuickCustomize.md)|Determina se um usuário pode adicionar ou remover os botões da barra de ferramentas usando a opção de menu de **Personalizar** .|  
|[CMFCToolBar::IsAltCustomizeMode](../Topic/CMFCToolBar::IsAltCustomizeMode.md)|Especifica se *a personalização rápido* sendo usado para arrastar um botão.|  
|[CMFCToolBar::IsAutoGrayInactiveImages](../Topic/CMFCToolBar::IsAutoGrayInactiveImages.md)|Especifica se a geração automática de imagens \(não\) realçadas inativos do botão está habilitado.|  
|[CMFCToolBar::IsBasicCommand](../Topic/CMFCToolBar::IsBasicCommand.md)|Determina se um comando está na lista de comandos básicos.|  
|[CMFCToolBar::IsButtonExtraSizeAvailable](../Topic/CMFCToolBar::IsButtonExtraSizeAvailable.md)|Determina se a barra de ferramentas pode exibir botões que estenderam bordas.|  
|[CMFCToolBar::IsButtonHighlighted](../Topic/CMFCToolBar::IsButtonHighlighted.md)|Determina se um botão na barra de ferramentas é realçado.|  
|[CMFCToolBar::IsCommandPermitted](../Topic/CMFCToolBar::IsCommandPermitted.md)|Determina se um comando é permitido.|  
|[CMFCToolBar::IsCommandRarelyUsed](../Topic/CMFCToolBar::IsCommandRarelyUsed.md)|Determina se um comando é raramente usados \(consulte [CMFCToolBar::SetCommandUsageOptions](../Topic/CMFCToolBar::SetCommandUsageOptions.md)\).|  
|[CMFCToolBar::IsCustomizeMode](../Topic/CMFCToolBar::IsCustomizeMode.md)|Especifica se a estrutura da barra de ferramentas está no modo de personalização.|  
|[CMFCToolBar::IsDragButton](../Topic/CMFCToolBar::IsDragButton.md)|Determina se um botão da barra de ferramentas está sendo arrastado.|  
|[CMFCToolBar::IsExistCustomizeButton](../Topic/CMFCToolBar::IsExistCustomizeButton.md)|Determina se a barra de ferramentas contém o botão de **Personalizar** .|  
|[CMFCToolBar::IsFloating](../Topic/CMFCToolBar::IsFloating.md)|Determina se a barra de ferramentas está flutuantes.|  
|[CMFCToolBar::IsLargeIcons](../Topic/CMFCToolBar::IsLargeIcons.md)|Especifica se as barras de ferramentas para o aplicativo atualmente exibe ícones grandes.|  
|[CMFCToolBar::IsLastCommandFromButton](../Topic/CMFCToolBar::IsLastCommandFromButton.md)|Determina se o comando recentemente executado foi enviado do botão da barra de ferramentas especificado.|  
|[CMFCToolBar::IsLocked](../Topic/CMFCToolBar::IsLocked.md)|Determina se a barra de ferramentas é bloqueada.|  
|[CMFCToolBar::IsOneRowWithSibling](../Topic/CMFCToolBar::IsOneRowWithSibling.md)|Determina se a barra de ferramentas e sua barra de ferramentas irmãos são posicionadas na mesma linha.|  
|[CMFCToolBar::IsUserDefined](../Topic/CMFCToolBar::IsUserDefined.md)|Especifica se a barra de ferramentas é definido pelo usuário.|  
|[CMFCToolBar::LoadBitmap](../Topic/CMFCToolBar::LoadBitmap.md)|Imagens da barra de ferramentas carrega os recursos do aplicativo.|  
|[CMFCToolBar::LoadBitmapEx](../Topic/CMFCToolBar::LoadBitmapEx.md)|Imagens da barra de ferramentas carrega os recursos do aplicativo.  Inclui grandes imagens.|  
|[CMFCToolBar::LoadParameters](../Topic/CMFCToolBar::LoadParameters.md)|Carrega opções globais da barra de ferramentas de Registro do Windows.|  
|[CMFCToolBar::LoadState](../Topic/CMFCToolBar::LoadState.md)|Carregar informações de estado da barra de ferramentas de Registro do Windows.  Overrides \( [CPane::LoadState](../Topic/CPane::LoadState.md).\)|  
|[CMFCToolBar::LoadToolBar](../Topic/CMFCToolBar::LoadToolBar.md)|Carrega a barra de ferramentas os recursos do aplicativo.|  
|[CMFCToolBar::LoadToolBarEx](../Topic/CMFCToolBar::LoadToolBarEx.md)|Carrega a barra de ferramentas os recursos do aplicativo usando a classe auxiliar de `CMFCToolBarInfo` para ativar o aplicativo para usar imagens grandes.|  
|[CMFCToolBar::OnChangeHot](../Topic/CMFCToolBar::OnChangeHot.md)|Chamado pela estrutura quando um usuário seleciona um botão na barra de ferramentas.|  
|[CMFCToolBar::OnFillBackground](../Topic/CMFCToolBar::OnFillBackground.md)|Chamado pela estrutura de [CBasePane::DoPaint](../Topic/CBasePane::DoPaint.md) para preencher o plano de fundo da barra de ferramentas.|  
|[CMFCToolBar::OnReset](../Topic/CMFCToolBar::OnReset.md)|Restaura a barra de ferramentas para seu estado original.|  
|[CMFCToolBar::OnSetAccData](../Topic/CMFCToolBar::OnSetAccData.md)|Overrides \( [CBasePane::OnSetAccData](../Topic/CBasePane::OnSetAccData.md).\)|  
|[CMFCToolBar::OnSetDefaultButtonText](../Topic/CMFCToolBar::OnSetDefaultButtonText.md)|Restaura o texto de um botão da barra de ferramentas para seu estado padrão.|  
|`CMFCToolBar::OnUpdateCmdUI`|Usado internamente.|  
|[CMFCToolBar::RemoveAllButtons](../Topic/CMFCToolBar::RemoveAllButtons.md)|Remove todos os botões da barra de ferramentas.|  
|[CMFCToolBar::RemoveButton](../Topic/CMFCToolBar::RemoveButton.md)|Remove o botão com o índice especificado da barra de ferramentas.|  
|[CMFCToolBar::RemoveStateFromRegistry](../Topic/CMFCToolBar::RemoveStateFromRegistry.md)|Exclui as informações do estado da barra de ferramentas do Registro do Windows.|  
|[CMFCToolBar::ReplaceButton](../Topic/CMFCToolBar::ReplaceButton.md)|Substitui um botão da barra de ferramentas com outro botão da barra de ferramentas.|  
|[CMFCToolBar::ResetAll](../Topic/CMFCToolBar::ResetAll.md)|Restaura todas as barras de ferramentas para seus estados originais.|  
|[CMFCToolBar::ResetAllImages](../Topic/CMFCToolBar::ResetAllImages.md)|Limpa todas as coleções de imagem da barra de ferramentas para o aplicativo.|  
|[CMFCToolBar::RestoreOriginalState](../Topic/CMFCToolBar::RestoreOriginalState.md)|Restaura o estado original de uma barra de ferramentas.|  
|[CMFCToolBar::SaveState](../Topic/CMFCToolBar::SaveState.md)|Salva informações do estado da barra de ferramentas no Registro do Windows.  Overrides \( [CPane::SaveState](../Topic/CPane::SaveState.md).\)|  
|`CMFCToolBar::Serialize`|Overrides \( `CBasePane::Serialize`.\)|  
|[CMFCToolBar::SetBasicCommands](../Topic/CMFCToolBar::SetBasicCommands.md)|Define a lista de comandos que são sempre exibidos quando um usuário abre um menu.|  
|[CMFCToolBar::SetButtonInfo](../Topic/CMFCToolBar::SetButtonInfo.md)|Define a identificação do comando, o estilo, e a identificação de imagem de um botão da barra de ferramentas.|  
|[CMFCToolBar::SetButtonStyle](../Topic/CMFCToolBar::SetButtonStyle.md)|Defina o estilo do botão da barra de ferramentas no índice especificado.|  
|[CMFCToolBar::SetButtonText](../Topic/CMFCToolBar::SetButtonText.md)|Define o rótulo de texto de um botão da barra de ferramentas.|  
|[CMFCToolBar::SetButtons](../Topic/CMFCToolBar::SetButtons.md)|Defina os botões da barra de ferramentas.|  
|[CMFCToolBar::SetCommandUsageOptions](../Topic/CMFCToolBar::SetCommandUsageOptions.md)|Especifica quando os comandos raramente usados não aparecem no menu do aplicativo.|  
|[CMFCToolBar::SetCustomizeMode](../Topic/CMFCToolBar::SetCustomizeMode.md)|Habilita ou desabilita o modo de personalização para todas as barras de ferramentas para o aplicativo.|  
|[CMFCToolBar::SetGrayDisabledButtons](../Topic/CMFCToolBar::SetGrayDisabledButtons.md)|Especifica se os botões desativados na barra de ferramentas ficão escurecidos ou se as imagens desativado são usadas para os botões desativados.|  
|[CMFCToolBar::SetHeight](../Topic/CMFCToolBar::SetHeight.md)|Defina a altura da barra de ferramentas.|  
|[CMFCToolBar::SetHotBorder](../Topic/CMFCToolBar::SetHotBorder.md)|Especifica se os botões da barra de ferramentas quente\- são rastreadas.|  
|[CMFCToolBar::SetHotTextColor](../Topic/CMFCToolBar::SetHotTextColor.md)|Define a cor do texto dos botões da barra de ferramentas quentes.|  
|[CMFCToolBar::SetLargeIcons](../Topic/CMFCToolBar::SetLargeIcons.md)|Especifica se os botões da barra de ferramentas exibe ícones grandes.|  
|[CMFCToolBar::SetLockedSizes](../Topic/CMFCToolBar::SetLockedSizes.md)|Defina os tamanhos dos botões bloqueados e de imagens bloqueadas na barra de ferramentas.|  
|[CMFCToolBar::SetMenuSizes](../Topic/CMFCToolBar::SetMenuSizes.md)|Defina o tamanho dos botões de menu a barra de ferramentas e das suas figuras.|  
|[CMFCToolBar::SetNonPermittedCommands](../Topic/CMFCToolBar::SetNonPermittedCommands.md)|Define a lista de comandos que não podem ser executados pelo usuário.|  
|[CMFCToolBar::SetOneRowWithSibling](../Topic/CMFCToolBar::SetOneRowWithSibling.md)|Posiciona a barra de ferramentas e seu irmão no mesmo linhas.|  
|[CMFCToolBar::SetPermament](../Topic/CMFCToolBar::SetPermament.md)|Especifica se um usuário pode fechar a barra de ferramentas.|  
|[CMFCToolBar::SetRouteCommandsViaFrame](../Topic/CMFCToolBar::SetRouteCommandsViaFrame.md)|Especifica se o elemento pai ou o proprietário envia comandos para a barra de ferramentas.|  
|[CMFCToolBar::SetShowTooltips](../Topic/CMFCToolBar::SetShowTooltips.md)|Especifica se a estrutura exibe a dica de ferramenta.|  
|[CMFCToolBar::SetSiblingToolBar](../Topic/CMFCToolBar::SetSiblingToolBar.md)|Especifica o irmão da barra de ferramentas.|  
|[CMFCToolBar::SetSizes](../Topic/CMFCToolBar::SetSizes.md)|Especifica os tamanhos dos botões e imagens em todas as barras de ferramentas.|  
|[CMFCToolBar::SetToolBarBtnText](../Topic/CMFCToolBar::SetToolBarBtnText.md)|Especifica propriedades de um botão na barra de ferramentas.|  
|[CMFCToolBar::SetTwoRowsWithSibling](../Topic/CMFCToolBar::SetTwoRowsWithSibling.md)|Posiciona a barra de ferramentas e seu irmão em termos separados.|  
|[CMFCToolBar::SetUserImages](../Topic/CMFCToolBar::SetUserImages.md)|Define a coleção de imagens definidas pelo usuário no aplicativo.|  
|[CMFCToolBar::StretchPane](../Topic/CMFCToolBar::StretchPane.md)|Redimensiona a barra de ferramentas verticalmente ou horizontalmente. Overrides \( [CBasePane::StretchPane](../Topic/CBasePane::StretchPane.md).\)|  
|[CMFCToolBar::TranslateChar](../Topic/CMFCToolBar::TranslateChar.md)|Executa um comando do botão se o código de chave especificado corresponde a um atalho de teclado válido.|  
|[CMFCToolBar::UpdateButton](../Topic/CMFCToolBar::UpdateButton.md)|Atualiza o estado do botão especificado.|  
|[CMFCToolBar::WrapToolBar](../Topic/CMFCToolBar::WrapToolBar.md)|Reposiciona os botões da barra de ferramentas dentro das dimensões disponíveis.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBar::AllowShowOnList](../Topic/CMFCToolBar::AllowShowOnList.md)|Determina se a barra de ferramentas é exibida na lista no painel de **Barras de Ferramentas** da caixa de diálogo de **Personalizar** .|  
|[CMFCToolBar::CalcMaxButtonHeight](../Topic/CMFCToolBar::CalcMaxButtonHeight.md)|Calcula a altura máximo de um botão na barra de ferramentas.|  
|[CMFCToolBar::DoPaint](../Topic/CMFCToolBar::DoPaint.md)|Repintura uma barra de ferramentas.|  
|[CMFCToolBar::DrawButton](../Topic/CMFCToolBar::DrawButton.md)|Repintura um botão da barra de ferramentas.|  
|[CMFCToolBar::DrawSeparator](../Topic/CMFCToolBar::DrawSeparator.md)|Repintura um separador em uma barra de ferramentas.|  
|[CMFCToolBar::OnUserToolTip](../Topic/CMFCToolBar::OnUserToolTip.md)|Chamado pela estrutura quando a dica de ferramenta para um botão está prestes a ser exibido.|  
  
### Membros de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCToolBar::m\_bDontScaleImages](../Topic/CMFCToolBar::m_bDontScaleImages.md)|Especifica se dimensionar ou não imagens da barra de ferramentas no modo alto de DPI.|  
|[CMFCToolBar::m\_dblLargeImageRatio](../Topic/CMFCToolBar::m_dblLargeImageRatio.md)|Especifica a taxa entre a dimensão \(altura ou largura\) de grandes imagens e dimensão de imagens normal.|  
  
## Comentários  
 Para inserir um objeto de `CMFCToolBar` em seu aplicativo, siga estas etapas:  
  
1.  Adicionar um objeto de `CMFCToolBar` a janela de quadro chave.  
  
2.  Quando você processa a mensagem de `WM_CREATE` para a janela do quadro chave, chame [CMFCToolBar::Create](../Topic/CMFCToolBar::Create.md) ou [CMFCToolBar::CreateEx](../Topic/CMFCToolBar::CreateEx.md) para criar a barra de ferramentas e para especificar o estilo.  
  
3.  Chame [CBasePane::EnableDocking](../Topic/CBasePane::EnableDocking.md) para especificar o estilo de encaixe.  
  
 Para inserir um botão especial, como uma caixa de combinação ou uma barra de ferramentas lista suspensa, permitindo um botão fictício recurso no pai, e substitua o botão fictício em tempo de execução usando [CMFCToolBar::ReplaceButton](../Topic/CMFCToolBar::ReplaceButton.md).  Para mais informações, consulte [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md).  
  
 `CMFCToolBar` é a classe base para as classes [Classe de CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md), [Classe CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md), e [Classe de CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)de biblioteca MFC.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCToolBar` .  O exemplo a seguir mostra como definir o texto do rótulo da janela de barra de ferramentas, defina as bordas, defina o estilo do, e ativar o botão de **Adicionar ou Remover Botões** que aparece no final da barra de ferramentas.  Este trecho de código é parte de [Exemplo de demonstração de IE](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo#6](../../mfc/reference/codesnippet/CPP/cmfctoolbar-class_1.h)]  
[!code-cpp[NVC_MFC_IEDemo#8](../../mfc/reference/codesnippet/CPP/cmfctoolbar-class_2.cpp)]  
  
## Requisitos  
 **Cabeçalho:** afxtoolbar.h  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md)   
 [Classe CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md)   
 [Classe de CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)   
 [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)