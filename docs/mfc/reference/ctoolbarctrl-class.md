---
title: "Classe de CToolBarCtrl | Microsoft Docs"
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
  - "CToolBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CToolBarCtrl"
  - "dicas de ferramenta [C++], notificações"
  - "controles de barra de ferramentas [MFC], Classe de CToolBarCtrl"
  - "Controles comuns do Windows [C++], CToolBarCtrl"
ms.assetid: 8f2f8ad2-05d7-4975-8715-3f2eed795248
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CToolBarCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade do controle comum da barra de ferramentas do windows.  
  
## Sintaxe  
  
```  
class CToolBarCtrl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CToolBarCtrl::CToolBarCtrl](../Topic/CToolBarCtrl::CToolBarCtrl.md)|Constrói um objeto de `CToolBarCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CToolBarCtrl::AddBitmap](../Topic/CToolBarCtrl::AddBitmap.md)|Adiciona uma ou mais imagens do botão de bitmap à lista de imagens do botão disponíveis para um controle de barra de ferramentas.|  
|[CToolBarCtrl::AddButtons](../Topic/CToolBarCtrl::AddButtons.md)|Adiciona um ou mais botões a um controle de barra de ferramentas.|  
|[CToolBarCtrl::AddString](../Topic/CToolBarCtrl::AddString.md)|Adiciona uma nova cadeia de caracteres, passada como um ID de recurso, a lista interna da barra de ferramentas de cadeias de caracteres.|  
|[CToolBarCtrl::AddStrings](../Topic/CToolBarCtrl::AddStrings.md)|Adiciona uma nova cadeia de caracteres ou cadeias de caracteres, passada como um ponteiro para um buffer de cadeias de caracteres NULL\- separada, a lista interna da barra de ferramentas de cadeias de caracteres.|  
|[CToolBarCtrl::AutoSize](../Topic/CToolBarCtrl::AutoSize.md)|Redimensiona um controle de barra de ferramentas.|  
|[CToolBarCtrl::ChangeBitmap](../Topic/CToolBarCtrl::ChangeBitmap.md)|Altera o bitmap de um botão no controle de barra de ferramentas atual.|  
|[CToolBarCtrl::CheckButton](../Topic/CToolBarCtrl::CheckButton.md)|Verifica ou limpa um determinado botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::CommandToIndex](../Topic/CToolBarCtrl::CommandToIndex.md)|Retorna o índice com base zero para o botão associado com o identificador de comando especificado.|  
|[CToolBarCtrl::Create](../Topic/CToolBarCtrl::Create.md)|Cria um controle de barra de ferramentas e anexá\-la a um objeto de `CToolBarCtrl` .|  
|[CToolBarCtrl::CreateEx](../Topic/CToolBarCtrl::CreateEx.md)|Cria um controle de barra de ferramentas com os estilos estendidos o windows especificados e anexá\-la a um objeto de `CToolBarCtrl` .|  
|[CToolBarCtrl::Customize](../Topic/CToolBarCtrl::Customize.md)|Exibe a caixa de diálogo da barra de ferramentas personalizar.|  
|[CToolBarCtrl::DeleteButton](../Topic/CToolBarCtrl::DeleteButton.md)|Exclui um botão de controle de barra de ferramentas.|  
|[CToolBarCtrl::EnableButton](../Topic/CToolBarCtrl::EnableButton.md)|Habilita ou desabilita o botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetAnchorHighlight](../Topic/CToolBarCtrl::GetAnchorHighlight.md)|Recupera a configuração de realce de âncora para uma barra de ferramentas.|  
|[CToolBarCtrl::GetBitmap](../Topic/CToolBarCtrl::GetBitmap.md)|Retorna o índice de bitmap associado com um botão na barra de ferramentas.|  
|[CToolBarCtrl::GetBitmapFlags](../Topic/CToolBarCtrl::GetBitmapFlags.md)|Obtém os sinalizadores associados com o bitmap da barra de ferramentas.|  
|[CToolBarCtrl::GetButton](../Topic/CToolBarCtrl::GetButton.md)|Recupera informações sobre o botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetButtonCount](../Topic/CToolBarCtrl::GetButtonCount.md)|Recupera uma contagem dos botões no controle de barra de ferramentas.|  
|[CToolBarCtrl::GetButtonInfo](../Topic/CToolBarCtrl::GetButtonInfo.md)|Recupera informações para um botão na barra de ferramentas.|  
|[CToolBarCtrl::GetButtonSize](../Topic/CToolBarCtrl::GetButtonSize.md)|Obtém a largura e altura atuais dos botões da barra de ferramentas, em pixels.|  
|[CToolBarCtrl::GetColorScheme](../Topic/CToolBarCtrl::GetColorScheme.md)|Recupera o esquema de cores de controle de barra de ferramentas atual.|  
|[CToolBarCtrl::GetDisabledImageList](../Topic/CToolBarCtrl::GetDisabledImageList.md)|Recupera a lista de imagem que um controle de barra de ferramentas usa para exibir os botões desativados.|  
|[CToolBarCtrl::GetDropTarget](../Topic/CToolBarCtrl::GetDropTarget.md)|Recupera a interface de [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) para um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetExtendedStyle](../Topic/CToolBarCtrl::GetExtendedStyle.md)|Recupera os estilos estendidos para um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetHotImageList](../Topic/CToolBarCtrl::GetHotImageList.md)|Recupera a lista de imagem que um controle de barra de ferramentas usa para exibir os botões “quentes”.  Um botão quente aparece realçado quando o ponteiro do mouse está acima de ele.|  
|[CToolBarCtrl::GetHotItem](../Topic/CToolBarCtrl::GetHotItem.md)|Retorna o índice do item quente em uma barra de ferramentas.|  
|[CToolBarCtrl::GetImageList](../Topic/CToolBarCtrl::GetImageList.md)|Recupera a lista de imagem que um controle de barra de ferramentas usa para exibir os botões em seu estado padrão.|  
|[CToolBarCtrl::GetInsertMark](../Topic/CToolBarCtrl::GetInsertMark.md)|Recupera a marca de inserção atual para a barra de ferramentas.|  
|[CToolBarCtrl::GetInsertMarkColor](../Topic/CToolBarCtrl::GetInsertMarkColor.md)|Recupera a cor usada para desenhar a marca de inserção para a barra de ferramentas.|  
|[CToolBarCtrl::GetItemRect](../Topic/CToolBarCtrl::GetItemRect.md)|Recupera o retângulo delimitador de um botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetMaxSize](../Topic/CToolBarCtrl::GetMaxSize.md)|Retorna o tamanho total de todos os botões e separadores visíveis na barra de ferramentas.|  
|[CToolBarCtrl::GetMaxTextRows](../Topic/CToolBarCtrl::GetMaxTextRows.md)|Retorna o número máximo de linhas de texto exibido em um botão da barra de ferramentas.|  
|[CToolBarCtrl::GetMetrics](../Topic/CToolBarCtrl::GetMetrics.md)|Recupera métricas de um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetPadding](../Topic/CToolBarCtrl::GetPadding.md)|Recupera o preenchimento horizontal e vertical do controle de barra de ferramentas atual.|  
|[CToolBarCtrl::GetPressedImageList](../Topic/CToolBarCtrl::GetPressedImageList.md)|Recupera a lista de imagem que o controle de barra de ferramentas atual usa para representar os botões o estado pressionado.|  
|[CToolBarCtrl::GetRect](../Topic/CToolBarCtrl::GetRect.md)|Recupera o retângulo delimitador de um botão da barra de ferramentas especificado.|  
|[CToolBarCtrl::GetRows](../Topic/CToolBarCtrl::GetRows.md)|Retorna o número de linhas de botões exibidos na barra de ferramentas.|  
|[CToolBarCtrl::GetState](../Topic/CToolBarCtrl::GetState.md)|Recupera informações sobre o estado do botão especificado em um controle de barra de ferramentas, como se estiver ativado, pressionado, ou verificado.|  
|[CToolBarCtrl::GetString](../Topic/CToolBarCtrl::GetString.md)|Recupera uma cadeia de caracteres de barra de ferramentas.|  
|[CToolBarCtrl::GetStyle](../Topic/CToolBarCtrl::GetStyle.md)|Recupera os estilos atualmentes em uso para um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetToolTips](../Topic/CToolBarCtrl::GetToolTips.md)|Recupera a alça de controle dica de ferramenta, se houver, associado ao controle de barra de ferramentas.|  
|[CToolBarCtrl::HideButton](../Topic/CToolBarCtrl::HideButton.md)|Oculta ou mostra o botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::HitTest](../Topic/CToolBarCtrl::HitTest.md)|Determina onde um ponto está em um controle de barra de ferramentas.|  
|[CToolBarCtrl::Indeterminate](../Topic/CToolBarCtrl::Indeterminate.md)|Define ou limpa o estado \(cinza\) indefinido do botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::InsertButton](../Topic/CToolBarCtrl::InsertButton.md)|Insere um botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::InsertMarkHitTest](../Topic/CToolBarCtrl::InsertMarkHitTest.md)|Recupera informações de marca para um ponto de inserção em uma barra de ferramentas.|  
|[CToolBarCtrl::IsButtonChecked](../Topic/CToolBarCtrl::IsButtonChecked.md)|Informa se o botão especificado em um controle de barra de ferramentas é verificado.|  
|[CToolBarCtrl::IsButtonEnabled](../Topic/CToolBarCtrl::IsButtonEnabled.md)|Informa se o botão especificado em um controle de barra de ferramentas está habilitado.|  
|[CToolBarCtrl::IsButtonHidden](../Topic/CToolBarCtrl::IsButtonHidden.md)|Informa se o botão especificado em um controle de barra de ferramentas está oculto.|  
|[CToolBarCtrl::IsButtonHighlighted](../Topic/CToolBarCtrl::IsButtonHighlighted.md)|Verifica o estado de realce de botão da barra de ferramentas.|  
|[CToolBarCtrl::IsButtonIndeterminate](../Topic/CToolBarCtrl::IsButtonIndeterminate.md)|Informa se o estado do botão especificado em um controle de barra de ferramentas é indefinido \(cinza\).|  
|[CToolBarCtrl::IsButtonPressed](../Topic/CToolBarCtrl::IsButtonPressed.md)|Informa se o botão especificado em um controle de barra de ferramentas está pressionada.|  
|[CToolBarCtrl::LoadImages](../Topic/CToolBarCtrl::LoadImages.md)|Bitmaps carrega a imagem de um controle de barra de ferramentas lista.|  
|[CToolBarCtrl::MapAccelerator](../Topic/CToolBarCtrl::MapAccelerator.md)|Mapeia um caractere de aceleradores a um botão da barra de ferramentas.|  
|[CToolBarCtrl::MarkButton](../Topic/CToolBarCtrl::MarkButton.md)|Define o estado de realce de um determinado botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::MoveButton](../Topic/CToolBarCtrl::MoveButton.md)|Move um botão de um índice para outro.|  
|[CToolBarCtrl::PressButton](../Topic/CToolBarCtrl::PressButton.md)|Pressiona o botão ou versões especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::ReplaceBitmap](../Topic/CToolBarCtrl::ReplaceBitmap.md)|Substitui o projeto existente no controle de barra de ferramentas atual com um novo projeto.|  
|[CToolBarCtrl::RestoreState](../Topic/CToolBarCtrl::RestoreState.md)|Restaura o estado do controle de barra de ferramentas.|  
|[CToolBarCtrl::SaveState](../Topic/CToolBarCtrl::SaveState.md)|Salvar o estado do controle de barra de ferramentas.|  
|[CToolBarCtrl::SetAnchorHighlight](../Topic/CToolBarCtrl::SetAnchorHighlight.md)|Define a configuração de realce de âncora para uma barra de ferramentas.|  
|[CToolBarCtrl::SetBitmapSize](../Topic/CToolBarCtrl::SetBitmapSize.md)|Defina o tamanho das imagens bitmap a ser adicionadas a um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetButtonInfo](../Topic/CToolBarCtrl::SetButtonInfo.md)|Define informações de um botão existente em uma barra de ferramentas.|  
|[CToolBarCtrl::SetButtonSize](../Topic/CToolBarCtrl::SetButtonSize.md)|Defina o tamanho dos botões para ser adicionados a um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetButtonStructSize](../Topic/CToolBarCtrl::SetButtonStructSize.md)|Especifica o tamanho da estrutura de `TBBUTTON` .|  
|[CToolBarCtrl::SetButtonWidth](../Topic/CToolBarCtrl::SetButtonWidth.md)|Define o mínimo e máximo as larguras de botão no controle de barra de ferramentas.|  
|[CToolBarCtrl::SetCmdID](../Topic/CToolBarCtrl::SetCmdID.md)|Define o identificador de comando para ser enviadas para a janela do proprietário quando o botão é pressionado especificado.|  
|[CToolBarCtrl::SetColorScheme](../Topic/CToolBarCtrl::SetColorScheme.md)|Defina o esquema de cores de controle de barra de ferramentas atual.|  
|[CToolBarCtrl::SetDisabledImageList](../Topic/CToolBarCtrl::SetDisabledImageList.md)|Define a lista de imagem que o controle de barra de ferramentas usará para exibir os botões desativados.|  
|[CToolBarCtrl::SetDrawTextFlags](../Topic/CToolBarCtrl::SetDrawTextFlags.md)|Defina os sinalizadores na função [DrawText](http://msdn.microsoft.com/library/windows/desktop/dd162498)Win32, que é usada para desenhar texto no retângulo especificado, formatado de acordo com os sinalizadores são definidos como.|  
|[CToolBarCtrl::SetExtendedStyle](../Topic/CToolBarCtrl::SetExtendedStyle.md)|Define estilos estendidos para um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetHotImageList](../Topic/CToolBarCtrl::SetHotImageList.md)|Define a lista de imagem que o controle de barra de ferramentas usará para exibir os botões “quentes”.|  
|[CToolBarCtrl::SetHotItem](../Topic/CToolBarCtrl::SetHotItem.md)|Define o item quente em uma barra de ferramentas.|  
|[CToolBarCtrl::SetImageList](../Topic/CToolBarCtrl::SetImageList.md)|Define a lista de imagem que a barra de ferramentas usará para exibir botões que estão em seu estado padrão.|  
|[CToolBarCtrl::SetIndent](../Topic/CToolBarCtrl::SetIndent.md)|Define o recuo para o primeiro botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetInsertMark](../Topic/CToolBarCtrl::SetInsertMark.md)|Define a marca de inserção atual para a barra de ferramentas.|  
|[CToolBarCtrl::SetInsertMarkColor](../Topic/CToolBarCtrl::SetInsertMarkColor.md)|Define a cor usada para desenhar a marca de inserção para a barra de ferramentas.|  
|[CToolBarCtrl::SetMaxTextRows](../Topic/CToolBarCtrl::SetMaxTextRows.md)|Define o número máximo de linhas de texto exibido em um botão da barra de ferramentas.|  
|[CToolBarCtrl::SetMetrics](../Topic/CToolBarCtrl::SetMetrics.md)|Define métricas de um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetOwner](../Topic/CToolBarCtrl::SetOwner.md)|Define a janela para receber notificações do controle de barra de ferramentas.|  
|[CToolBarCtrl::SetPadding](../Topic/CToolBarCtrl::SetPadding.md)|Define o preenchimento horizontal e vertical do controle de barra de ferramentas atual.|  
|[CToolBarCtrl::SetPressedImageList](../Topic/CToolBarCtrl::SetPressedImageList.md)|Define a lista de imagem que o controle de barra de ferramentas atual usa para representar os botões o estado pressionado.|  
|[CToolBarCtrl::SetRows](../Topic/CToolBarCtrl::SetRows.md)|Define o número de linhas de botões exibidos na barra de ferramentas.|  
|[CToolBarCtrl::SetState](../Topic/CToolBarCtrl::SetState.md)|Define o estado do botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetStyle](../Topic/CToolBarCtrl::SetStyle.md)|Defina os estilos de um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetToolTips](../Topic/CToolBarCtrl::SetToolTips.md)|Associa um controle dica de ferramenta com o controle de barra de ferramentas.|  
|[CToolBarCtrl::SetWindowTheme](../Topic/CToolBarCtrl::SetWindowTheme.md)|Defina o estilo visual de um controle de barra de ferramentas.|  
  
## Comentários  
 Este controle \(e portanto a classe de `CToolBarCtrl` \) estão disponíveis somente para programas que executam na versão 3,51 do \/98 Windows 95 e Windows NT e posterior.  
  
 Um controle comum da barra de ferramentas do windows é uma janela filho retangular que contém um ou mais botões.  Esses botões podem exibir uma imagem de bitmap, uma cadeia de caracteres, ou ambos.  Quando o usuário escolhe um botão, envia uma mensagem de comando na janela do proprietário da barra de ferramentas.  Normalmente, os botões na barra de ferramentas correspondem aos itens no menu de aplicativo; fornecem uma maneira mais direta para que o usuário acessa os comandos de um aplicativo.  
  
 Os objetos de`CToolBarCtrl` contêm várias estruturas de dados internas importantes: uma lista de bitmaps de imagem do botão ou uma lista de imagem, uma lista de cadeias de caracteres de rótulo do botão, e uma lista de estruturas de `TBBUTTON` que associam uma imagem e\/ou uma cadeia de caracteres com a posição, suporta, indicam comando, e a identificação do botão.  Cada um dos elementos de essas estruturas de dados é referenciado por um índice com base zero.  Antes de usar um objeto de `CToolBarCtrl` , você deve configurar essas estruturas de dados.  A lista de cadeias de caracteres somente pode ser usada para rótulos do botão; você não pode recuperar cadeias de caracteres de barra de ferramentas.  
  
 Para usar um objeto de `CToolBarCtrl` , você normalmente irá seguir estas etapas:  
  
1.  Construir o objeto de `CToolBarCtrl` .  
  
2.  Chame [Criar](../Topic/CToolBarCtrl::Create.md) para criar o controle comum da barra de ferramentas do windows para e anexá\-la ao objeto de `CToolBarCtrl` .  Indica o estilo da barra de ferramentas usando estilos, como **TBSTYLE\_TRANSPARENT** para uma barra de ferramentas transparente ou **TBSTYLE\_DROPDOWN** para uma barra de ferramentas que suporta os botões lista de estilo.  
  
3.  Identifica como você deseja que os botões na barra de ferramentas exibida:  
  
    -   Para usar imagens de bitmap para adicionar botões, bitmaps de botão à barra de ferramentas chamando [AddBitmap](../Topic/CToolBarCtrl::AddBitmap.md).  
  
    -   Para usar imagens exibidas de uma imagem para listar os botões, especifique a lista de imagem chamando [SetImageList](../Topic/CToolBarCtrl::SetImageList.md), [SetHotImageList](../Topic/CToolBarCtrl::SetHotImageList.md), ou [SetDisabledImageList](../Topic/CToolBarCtrl::SetDisabledImageList.md).  
  
    -   Para usar rótulos de cadeia de caracteres para os botões, adicione as cadeias de caracteres para a barra de ferramentas chamando [AddString](../Topic/CToolBarCtrl::AddString.md) e\/ou [AddStrings](../Topic/CToolBarCtrl::AddStrings.md).  
  
4.  Adicione estruturas de botão à barra de ferramentas chamando [AddButtons](../Topic/CToolBarCtrl::AddButtons.md).  
  
5.  Se você deseja dica de ferramenta para um botão da barra de ferramentas para uma janela proprietária que não é `CFrameWnd`, você precisar manipular as mensagens de **TTN\_NEEDTEXT** na janela do proprietário da barra de ferramentas como descrito em [Notificações de dica de ferramenta de manipulação](../../mfc/handling-tool-tip-notifications.md).  Se a janela pai da barra de ferramentas é derivada de `CFrameWnd`, dicas de ferramenta são exibidas sem nenhum esforço extra de como você `CFrameWnd` fornece um manipulador padrão.  
  
6.  Se você desejar que o usuário poderá personalizar a barra de ferramentas, manipular notificações de personalização na janela do proprietário como descrito em [Notificações de manipulação de personalização](../Topic/Handling%20Customization%20Notifications.md).  
  
 Você pode usar [SaveState](../Topic/CToolBarCtrl::SaveState.md) para salvar o estado atual de um controle de barra de ferramentas para o Registro e em [RestoreState](../Topic/CToolBarCtrl::RestoreState.md) para restaurar o estado baseado nas informações armazenadas anteriormente no Registro.  Além de salvar o estado da barra de ferramentas entre os usos de aplicativo, armazenamento de aplicativos normalmente o estado antes que o usuário começar a personalizar a barra de ferramentas caso que o usuário deseja posteriormente para restaurar a barra de ferramentas para seu estado original.  
  
## Suporte para a versão do Internet Explorer 4,0 e posterior  
 Para oferecer suporte à funcionalidade introduzida no Internet Explorer, a versão 4,0 e posterior, MFC fornece suporte a lista de imagem e estilos transparentes e lisos para controles de barra de ferramentas.  
  
 Uma barra de ferramentas transparente permite que o cliente na barra de ferramentas mostra completamente.  Para criar uma barra de ferramentas transparente, use estilos de **TBSTYLE\_FLAT** e de **TBSTYLE\_TRANSPARENT** .  As barras de ferramentas transparentes apresentam o rastreamento quente; isto é, quando o ponteiro do mouse se move sobre quente um botão na barra de ferramentas, a aparência do botão muda.  As barras de ferramentas criadas com apenas o estilo de **TBSTYLE\_FLAT** conterão os botões que não são transparentes.  
  
 Suporte a lista de imagem permite a um controle maior flexibilidade para o comportamento padrão, imagens, imagens e quentes desativado.  Use [GetImageList](../Topic/CToolBarCtrl::GetImageList.md), [GetHotImageList](../Topic/CToolBarCtrl::GetHotImageList.md), e [GetDisabledImageList](../Topic/CToolBarCtrl::GetDisabledImageList.md) com a barra de ferramentas transparente para manipular a imagem de acordo com seu estado:  
  
 Para obter mais informações sobre como usar `CToolBarCtrl`, consulte [Controles](../../mfc/controls-mfc.md) e [usando CToolBarCtrl](../../mfc/using-ctoolbarctrl.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CToolBarCtrl`  
  
## Requisitos  
 **Cabeçalho:** afxcmn.h  
  
## Consulte também  
 [O MFC exemplos CMNCTRL1](../../top/visual-cpp-samples.md)   
 [Exemplo MFCIE MFC](../../top/visual-cpp-samples.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CToolBar](../../mfc/reference/ctoolbar-class.md)