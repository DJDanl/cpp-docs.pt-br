---
title: "Classe de CWindow | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL.CWindow"
  - "ATL::CWindow"
  - "CWindow"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CWindow"
ms.assetid: fefa00c8-f053-4bcf-87bc-dc84f5386683
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CWindow
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para manipular uma janela.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CWindow  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWindow::CWindow](../Topic/CWindow::CWindow.md)|Construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWindow::ArrangeIconicWindows](../Topic/CWindow::ArrangeIconicWindows.md)|Organiza todas as janelas filho minimizadas.|  
|[CWindow::Attach](../Topic/CWindow::Attach.md)|Anexar uma janela para o objeto de `CWindow` .|  
|[CWindow::BeginPaint](../Topic/CWindow::BeginPaint.md)|Preparar a janela pintando.|  
|[CWindow::BringWindowToTop](../Topic/CWindow::BringWindowToTop.md)|Traz a janela na parte superior da ordem Z.|  
|[CWindow::CenterWindow](../Topic/CWindow::CenterWindow.md)|Centraliza a janela em uma dada a janela.|  
|[CWindow::ChangeClipboardChain](../Topic/CWindow::ChangeClipboardChain.md)|Remove a janela da cadeia de Visualizador da Área de Transferência.|  
|[CWindow::CheckDlgButton](../Topic/CWindow::CheckDlgButton.md)|Alterar o estado de seleção do botão especificado.|  
|[CWindow::CheckRadioButton](../Topic/CWindow::CheckRadioButton.md)|Verifica o botão de opção especificado.|  
|[CWindow::ChildWindowFromPoint](../Topic/CWindow::ChildWindowFromPoint.md)|Recupera a janela filho que contém o ponto especificado.|  
|[CWindow::ChildWindowFromPointEx](../Topic/CWindow::ChildWindowFromPointEx.md)|Recupera um tipo específico de janela filho que contém o ponto especificado.|  
|[CWindow::ClientToScreen](../Topic/CWindow::ClientToScreen.md)|Coordenadas do cliente converte para selecionar coordenadas.|  
|[CWindow::Create](../Topic/CWindow::Create.md)|Cria uma janela.|  
|[CWindow::CreateCaret](../Topic/CWindow::CreateCaret.md)|Cria uma nova maneira para o sinal de intercalação.|  
|[CWindow::CreateGrayCaret](../Topic/CWindow::CreateGrayCaret.md)|Cria um retângulo cinza para o sinal de intercalação.|  
|[CWindow::CreateSolidCaret](../Topic/CWindow::CreateSolidCaret.md)|Cria um retângulo contínuo para o sinal de intercalação.|  
|[CWindow::DeferWindowPos](../Topic/CWindow::DeferWindowPos.md)|Atualiza a estrutura de múltiplo\-janela\- posição especificada para a janela especificada.|  
|[CWindow::DestroyWindow](../Topic/CWindow::DestroyWindow.md)|A janela for associada com o objeto de `CWindow` .|  
|[CWindow::Detach](../Topic/CWindow::Detach.md)|Dispara a janela do objeto de `CWindow` .|  
|[CWindow::DlgDirList](../Topic/CWindow::DlgDirList.md)|Preenche uma caixa de listagem com os nomes de todos os arquivos que correspondam um caminho ou nome de arquivo especificado.|  
|[CWindow::DlgDirListComboBox](../Topic/CWindow::DlgDirListComboBox.md)|Preenche uma caixa de combinação com os nomes de todos os arquivos que correspondam um caminho ou nome de arquivo especificado.|  
|[CWindow::DlgDirSelect](../Topic/CWindow::DlgDirSelect.md)|Recupera a seleção atual de uma caixa de listagem.|  
|[CWindow::DlgDirSelectComboBox](../Topic/CWindow::DlgDirSelectComboBox.md)|Recupera a seleção atual de uma caixa de combinação.|  
|[CWindow::DragAcceptFiles](../Topic/CWindow::DragAcceptFiles.md)|Registra se a janela aceita arquivos arrastados.|  
|[CWindow::DrawMenuBar](../Topic/CWindow::DrawMenuBar.md)|Redesenha a barra de menus da janela.|  
|[CWindow::EnableScrollBar](../Topic/CWindow::EnableScrollBar.md)|Habilita ou desabilita as setas na barra de rolagem.|  
|[CWindow::EnableWindow](../Topic/CWindow::EnableWindow.md)|Habilita ou desabilita a entrada.|  
|[CWindow::EndPaint](../Topic/CWindow::EndPaint.md)|Marca end de pintura.|  
|[CWindow::FlashWindow](../Topic/CWindow::FlashWindow.md)|A janela pisca uma vez.|  
|[CWindow::GetClientRect](../Topic/CWindow::GetClientRect.md)|Recupera as coordenadas da área cliente.|  
|[CWindow::GetDC](../Topic/CWindow::GetDC.md)|Recupera um contexto de dispositivo para a área cliente.|  
|[CWindow::GetDCEx](../Topic/CWindow::GetDCEx.md)|Recupera um contexto de dispositivo para a área cliente e reserva\-o recortar opções.|  
|[CWindow::GetDescendantWindow](../Topic/CWindow::GetDescendantWindow.md)|Recupera a janela especificada descendente.|  
|[CWindow::GetDlgControl](../Topic/CWindow::GetDlgControl.md)|Recupera uma interface especificada no controle.|  
|[CWindow::GetDlgCtrlID](../Topic/CWindow::GetDlgCtrlID.md)|Recupera o identificador de janela \(para janelas filho somente\).|  
|[CWindow::GetDlgHost](../Topic/CWindow::GetDlgHost.md)|Recupera um ponteiro a interface para o controle de ATL que hospeda o recipiente.|  
|[CWindow::GetDlgItem](../Topic/CWindow::GetDlgItem.md)|Recupera a janela filho especificada.|  
|[CWindow::GetDlgItemInt](../Topic/CWindow::GetDlgItemInt.md)|Converte o texto de um controle a um número inteiro.|  
|[CWindow::GetDlgItemText](../Topic/CWindow::GetDlgItemText.md)|Recupera o texto de um controle.|  
|[CWindow::GetExStyle](../Topic/CWindow::GetExStyle.md)|Recupera os estilos estendidos da janela.|  
|[CWindow::GetFont](../Topic/CWindow::GetFont.md)|Recupera a fonte atual da janela.|  
|[CWindow::GetHotKey](../Topic/CWindow::GetHotKey.md)|Determina a tecla de acesso associadas com a janela.|  
|[CWindow::GetIcon](../Topic/CWindow::GetIcon.md)|Recupera o ícone grande ou pequeno da janela.|  
|[CWindow::GetLastActivePopup](../Topic/CWindow::GetLastActivePopup.md)|Recupera a janela pop\-up ativo mais recentemente.|  
|[CWindow::GetMenu](../Topic/CWindow::GetMenu.md)|Recupera o menu da janela.|  
|[CWindow::GetNextDlgGroupItem](../Topic/CWindow::GetNextDlgGroupItem.md)|Recupera o controle anterior ou próximo em um grupo de controles.|  
|[CWindow::GetNextDlgTabItem](../Topic/CWindow::GetNextDlgTabItem.md)|Recupera o controle anterior ou próximo que tem o estilo de **WS\_TABSTOP** .|  
|[CWindow::GetParent](../Topic/CWindow::GetParent.md)|Recupera a janela pai imediato.|  
|[CWindow::GetScrollInfo](../Topic/CWindow::GetScrollInfo.md)|Recupera os parâmetros de uma barra de rolagem.|  
|[CWindow::GetScrollPos](../Topic/CWindow::GetScrollPos.md)|Retorna a posição da caixa de rolagem.|  
|[CWindow::GetScrollRange](../Topic/CWindow::GetScrollRange.md)|Retorna o intervalo de barra de rolagem.|  
|[CWindow::GetStyle](../Topic/CWindow::GetStyle.md)|Recupera os estilos de janela.|  
|[CWindow::GetSystemMenu](../Topic/CWindow::GetSystemMenu.md)|Cria uma cópia do menu do sistema para a alteração.|  
|[CWindow::GetTopLevelParent](../Topic/CWindow::GetTopLevelParent.md)|Recupera a janela de alto nível do pai ou do proprietário.|  
|[CWindow::GetTopLevelWindow](../Topic/CWindow::GetTopLevelWindow.md)|Recupera a janela de alto nível do proprietário.|  
|[CWindow::GetTopWindow](../Topic/CWindow::GetTopWindow.md)|Recupera a janela filho de nível superior.|  
|[CWindow::GetUpdateRect](../Topic/CWindow::GetUpdateRect.md)|Recupera as coordenadas do retângulo menor que inclui completamente a área de atualização.|  
|[CWindow::GetUpdateRgn](../Topic/CWindow::GetUpdateRgn.md)|Recupera a região de atualização e o copie em uma região especificada.|  
|[CWindow::GetWindow](../Topic/CWindow::GetWindow.md)|Recupera a janela especificada.|  
|[CWindow::GetWindowContextHelpId](../Topic/CWindow::GetWindowContextHelpId.md)|Recupera o identificador do contexto da ajuda da janela.|  
|[CWindow::GetWindowDC](../Topic/CWindow::GetWindowDC.md)|Recupera um contexto de dispositivo para a janela inteira.|  
|[CWindow::GetWindowLong](../Topic/CWindow::GetWindowLong.md)|Recupera um valor de 32 bits em um deslocamento especificado na memória adicional da janela.|  
|[CWindow::GetWindowLongPtr](../Topic/CWindow::GetWindowLongPtr.md)|Recupera informações sobre a janela especificada, incluindo um valor em um deslocamento especificado na memória adicional da janela.|  
|[CWindow::GetWindowPlacement](../Topic/CWindow::GetWindowPlacement.md)|Recupera o estado e as posições de apresentação.|  
|[CWindow::GetWindowProcessID](../Topic/CWindow::GetWindowProcessID.md)|Recupera o identificador do processo que criou a janela.|  
|[CWindow::GetWindowRect](../Topic/CWindow::GetWindowRect.md)|Recupera as dimensões delimitador da janela.|  
|[CWindow::GetWindowRgn](../Topic/CWindow::GetWindowRgn.md)|Obtém uma cópia da região da janela de uma janela.|  
|[CWindow::GetWindowText](../Topic/CWindow::GetWindowText.md)|Recupera o texto da janela.|  
|[CWindow::GetWindowTextLength](../Topic/CWindow::GetWindowTextLength.md)|Retorna o tamanho do texto da janela.|  
|[CWindow::GetWindowThreadID](../Topic/CWindow::GetWindowThreadID.md)|Recupera o identificador do segmento que criou a janela especificada.|  
|[CWindow::GetWindowWord](../Topic/CWindow::GetWindowWord.md)|Recupera um valor de 16 bits em um deslocamento especificado na memória adicional da janela.|  
|[CWindow::GotoDlgCtrl](../Topic/CWindow::GotoDlgCtrl.md)|Defina o foco do teclado para um controle na caixa de diálogo.|  
|[CWindow::HideCaret](../Topic/CWindow::HideCaret.md)|Oculta o sinal de intercalação.|  
|[CWindow::HiliteMenuItem](../Topic/CWindow::HiliteMenuItem.md)|Realça ou remover o realce de um item de menu de nível superior.|  
|[CWindow::Invalidate](../Topic/CWindow::Invalidate.md)|Invalida toda a área cliente.|  
|[CWindow::InvalidateRect](../Topic/CWindow::InvalidateRect.md)|Invalida a área cliente dentro do retângulo especificado.|  
|[CWindow::InvalidateRgn](../Topic/CWindow::InvalidateRgn.md)|Invalida a área cliente dentro da região especificada.|  
|[CWindow::IsChild](../Topic/CWindow::IsChild.md)|Determina se a janela especificada é uma janela filho.|  
|[CWindow::IsDialogMessage](../Topic/CWindow::IsDialogMessage.md)|Determina se uma mensagem é destinada para a caixa de diálogo especificada.|  
|[CWindow::IsDlgButtonChecked](../Topic/CWindow::IsDlgButtonChecked.md)|Determina o estado de seleção do botão.|  
|[CWindow::IsIconic](../Topic/CWindow::IsIconic.md)|Determina se a janela estiver minimizada.|  
|[CWindow::IsParentDialog](../Topic/CWindow::IsParentDialog.md)|Determina se a janela pai de um controle é uma janela da caixa de diálogo.|  
|[CWindow::IsWindow](../Topic/CWindow::IsWindow.md)|Determina se o identificador de janela especificado identifica uma janela existente.|  
|[CWindow::IsWindowEnabled](../Topic/CWindow::IsWindowEnabled.md)|Determina se a janela estiver ativada para a entrada.|  
|[CWindow::IsWindowUnicode](../Topic/CWindow::IsWindowUnicode.md)|Determina se a janela especificada é uma janela nativo Unicode.|  
|[CWindow::IsWindowVisible](../Topic/CWindow::IsWindowVisible.md)|Determina o estado de visibilidade da janela.|  
|[CWindow::IsZoomed](../Topic/CWindow::IsZoomed.md)|Determina se a janela estiver maximizada.|  
|[CWindow::KillTimer](../Topic/CWindow::KillTimer.md)|For um evento de timer.|  
|[CWindow::LockWindowUpdate](../Topic/CWindow::LockWindowUpdate.md)|As desativa verificação ou permitem o desenho na janela.|  
|[CWindow::MapWindowPoints](../Topic/CWindow::MapWindowPoints.md)|Converte um conjunto de pontos de espaço de coordenadas da janela para o espaço de coordenadas de outra janela.|  
|[CWindow::MessageBox](../Topic/CWindow::MessageBox.md)|Exibe uma caixa de mensagem.|  
|[CWindow::ModifyStyle](../Topic/CWindow::ModifyStyle.md)|Altera os estilos de janela.|  
|[CWindow::ModifyStyleEx](../Topic/CWindow::ModifyStyleEx.md)|Altera os estilos estendidos da janela.|  
|[CWindow::MoveWindow](../Topic/CWindow::MoveWindow.md)|Altera o tamanho e a posição da janela.|  
|[CWindow::NextDlgCtrl](../Topic/CWindow::NextDlgCtrl.md)|Defina o foco do teclado para o próximo controle na caixa de diálogo.|  
|[CWindow::OpenClipboard](../Topic/CWindow::OpenClipboard.md)|Abre a área de transferência.|  
|[CWindow::PostMessage](../Topic/CWindow::PostMessage.md)|Coloca uma mensagem na fila de mensagem associada com o segmento que criou a janela.  Retorna sem esperar que o segmento para processar a mensagem.|  
|[CWindow::PrevDlgCtrl](../Topic/CWindow::PrevDlgCtrl.md)|Defina o foco do teclado ao controle anterior na caixa de diálogo.|  
|[CWindow::Print](../Topic/CWindow::Print.md)|As solicitações a janela que são desenhados em um contexto específico de dispositivo.|  
|[CWindow::PrintClient](../Topic/CWindow::PrintClient.md)|As solicitações que a área cliente da janela são desenhados em um contexto específico de dispositivo.|  
|[CWindow::RedrawWindow](../Topic/CWindow::RedrawWindow.md)|Atualiza um retângulo ou região especificada na área cliente.|  
|[CWindow::ReleaseDC](../Topic/CWindow::ReleaseDC.md)|Libera um contexto de dispositivo.|  
|[CWindow::ResizeClient](../Topic/CWindow::ResizeClient.md)|Redimensiona a janela.|  
|[CWindow::ScreenToClient](../Topic/CWindow::ScreenToClient.md)|Coordenadas da tela converte para coordenadas do cliente.|  
|[CWindow::ScrollWindow](../Topic/CWindow::ScrollWindow.md)|Rola a área especificada de cliente.|  
|[CWindow::ScrollWindowEx](../Topic/CWindow::ScrollWindowEx.md)|Rola a área especificada de cliente com recursos adicionais.|  
|[CWindow::SendDlgItemMessage](../Topic/CWindow::SendDlgItemMessage.md)|Enviar uma mensagem a um controle.|  
|[CWindow::SendMessage](../Topic/CWindow::SendMessage.md)|Envia uma mensagem à janela e não retorna até que o procedimento de janela processa a mensagem.|  
|[CWindow::SendMessageToDescendants](../Topic/CWindow::SendMessageToDescendants.md)|Enviar uma mensagem ao especificadas descendente.|  
|[CWindow::SendNotifyMessage](../Topic/CWindow::SendNotifyMessage.md)|Envia uma mensagem à janela.  Se a janela foi criada pelo segmento de chamada, `SendNotifyMessage` não retorna até que o procedimento de janela processa a mensagem.  Caso contrário, retorna imediatamente.|  
|[CWindow::SetActiveWindow](../Topic/CWindow::SetActiveWindow.md)|Alterna a janela.|  
|[CWindow::SetCapture](../Topic/CWindow::SetCapture.md)|Envia qualquer o mouse subseqüente entrada para a janela.|  
|[CWindow::SetClipboardViewer](../Topic/CWindow::SetClipboardViewer.md)|Adiciona a janela para a cadeia do Visualizador da Área de Transferência.|  
|[CWindow::SetDlgCtrlID](../Topic/CWindow::SetDlgCtrlID.md)|Altera o identificador da janela.|  
|[CWindow::SetDlgItemInt](../Topic/CWindow::SetDlgItemInt.md)|Altera o texto de um controle à representação de cadeia de caracteres de um valor inteiro.|  
|[CWindow::SetDlgItemText](../Topic/CWindow::SetDlgItemText.md)|Altera o texto de um controle.|  
|[CWindow::SetFocus](../Topic/CWindow::SetFocus.md)|Defina o foco de entrada para a janela.|  
|[CWindow::SetFont](../Topic/CWindow::SetFont.md)|Altera a fonte atual da janela.|  
|[CWindow::SetHotKey](../Topic/CWindow::SetHotKey.md)|Associa uma tecla de acesso com a janela.|  
|[CWindow::SetIcon](../Topic/CWindow::SetIcon.md)|Alterar o ícone grande ou pequeno da janela.|  
|[CWindow::SetMenu](../Topic/CWindow::SetMenu.md)|Altera o menu atual da janela.|  
|[CWindow::SetParent](../Topic/CWindow::SetParent.md)|Altera a janela pai.|  
|[CWindow::SetRedraw](../Topic/CWindow::SetRedraw.md)|Define ou limpa o sinalizador redesenho.|  
|[CWindow::SetScrollInfo](../Topic/CWindow::SetScrollInfo.md)|Defina os parâmetros de uma barra de rolagem.|  
|[CWindow::SetScrollPos](../Topic/CWindow::SetScrollPos.md)|Altera a posição da caixa de rolagem.|  
|[CWindow::SetScrollRange](../Topic/CWindow::SetScrollRange.md)|Altera o intervalo de barra de rolagem.|  
|[CWindow::SetTimer](../Topic/CWindow::SetTimer.md)|Cria um evento de timer.|  
|[CWindow::SetWindowContextHelpId](../Topic/CWindow::SetWindowContextHelpId.md)|Define o identificador do contexto da ajuda da janela.|  
|[CWindow::SetWindowLong](../Topic/CWindow::SetWindowLong.md)|Define um valor de 32 bits em um deslocamento especificado na memória adicional da janela.|  
|[CWindow::SetWindowLongPtr](../Topic/CWindow::SetWindowLongPtr.md)|Altera o atributo da janela especificada, e também define um valor no deslocamento especificado na memória adicional da janela.|  
|[CWindow::SetWindowPlacement](../Topic/CWindow::SetWindowPlacement.md)|Define o estado e as posições de apresentação.|  
|[CWindow::SetWindowPos](../Topic/CWindow::SetWindowPos.md)|Defina o tamanho, posição, e ordem Z.|  
|[CWindow::SetWindowRgn](../Topic/CWindow::SetWindowRgn.md)|Define a região da janela de uma janela.|  
|[CWindow::SetWindowText](../Topic/CWindow::SetWindowText.md)|Altera o texto da janela.|  
|[CWindow::SetWindowWord](../Topic/CWindow::SetWindowWord.md)|Define um valor de 16 bits em um deslocamento especificado na memória adicional da janela.|  
|[CWindow::ShowCaret](../Topic/CWindow::ShowCaret.md)|Exibe o sinal de intercalação.|  
|[CWindow::ShowOwnedPopups](../Topic/CWindow::ShowOwnedPopups.md)|Mostra ou oculta janelas pop\-up possuídos pela janela.|  
|[CWindow::ShowScrollBar](../Topic/CWindow::ShowScrollBar.md)|Mostra ou oculta um a barra de rolagem.|  
|[CWindow::ShowWindow](../Topic/CWindow::ShowWindow.md)|Define o estado de apresentação da janela.|  
|[CWindow::ShowWindowAsync](../Topic/CWindow::ShowWindowAsync.md)|Define o estado de apresentação de uma janela projetada por um segmento diferente.|  
|[CWindow::UpdateWindow](../Topic/CWindow::UpdateWindow.md)|Atualiza a área cliente.|  
|[CWindow::ValidateRect](../Topic/CWindow::ValidateRect.md)|Valida a área cliente dentro do retângulo especificado.|  
|[CWindow::ValidateRgn](../Topic/CWindow::ValidateRgn.md)|Valida a área cliente dentro da região especificada.|  
|[CWindow::WinHelp](../Topic/CWindow::WinHelp.md)|Inicia a ajuda do windows.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWindow::operator HWND](../Topic/CWindow::operator%20HWND.md)|Converte o objeto de `CWindow` a `HWND`.|  
|[CWindow::operator \=](../Topic/CWindow::operator%20=.md)|Atribui `HWND` ao objeto de `CWindow` .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CWindow::m\_hWnd](../Topic/CWindow::m_hWnd.md)|O identificador para a janela associada com o objeto de `CWindow` .|  
|[CWindow::rcDefault](../Topic/CWindow::rcDefault.md)|Contém dimensões de janela padrão.|  
  
## Comentários  
 `CWindow` fornece a funcionalidade básica para manipular uma janela em ATL.  Muitos dos métodos de `CWindow` envolvem simplesmente uma das funções da API do Win32.  Por exemplo, compare os protótipos para `CWindow::ShowWindow` e `ShowWindow`:  
  
|Método de CWindow|Função Win32|  
|-----------------------|------------------|  
|**BOOL ShowWindow\( int**  `nCmdShow` **\);**|**BOOL ShowWindow\( HWND**  `hWnd` **, int**  `nCmdShow` **\);**|  
  
 `CWindow::ShowWindow` chama a função `ShowWindow` Win32 `CWindow::m_hWnd` passando como o primeiro parâmetro.  Cada método de `CWindow` que envolve diretamente uma função do Win32 passa o membro de `m_hWnd` ; portanto, grande parte da documentação de `CWindow` referir\-lhe\-á [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
> [!NOTE]
>  Cada função não relacionado windows Win32 é empacotada por `CWindow`, e não cada método de `CWindow` envolve uma função do Win32.  
  
 `CWindow::m_hWnd` armazena `HWND` que identifica uma janela.  `HWND` é anexado ao objeto quando você:  
  
-   Especificar `HWND` no construtor de `CWindow`.  
  
-   Chame `CWindow::Attach`.  
  
-   Use **operator \=**de `CWindow`.  
  
-   Crie ou subclasse de uma janela usando uma das seguintes classes derivada de `CWindow`:  
  
     [CWindowImpl](../Topic/CWindowImpl%20Class.md) permite que você crie uma nova janela ou uma subclasse uma janela existente.  
  
     [CContainedWindow](../Topic/CContainedWindowT%20Class.md) implementa uma janela contida dentro de outro objeto.  Você pode criar uma nova janela ou uma subclasse uma janela existente.  
  
     [CDialogImpl](../Topic/CDialogImpl%20Class.md) permite que você crie uma caixa de diálogo modal ou sem janela restrita.  
  
 Para obter mais informações sobre windows, consulte [Janelas](http://msdn.microsoft.com/library/windows/desktop/ms632595) e tópicos posteriores em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  Para obter mais informações sobre como usar o windows em ATL, consulte o artigo [A janela de ATL classes](../Topic/ATL%20Window%20Classes.md).  
  
## Requisitos  
 **Cabeçalho:** atlwin.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)