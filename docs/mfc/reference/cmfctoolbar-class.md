---
title: Classe CMFCToolBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCToolBar
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBar class
ms.assetid: e7679c01-fb94-44c0-98c6-3af955292fb5
caps.latest.revision: 48
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: a34997b4b68ddcc8f42869466f17d67f32141d7c
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctoolbar-class"></a>Classe CMFCToolBar
O `CMFCToolBar` é semelhante a classe [classe CToolBar](../../mfc/reference/ctoolbar-class.md), mas fornece suporte adicional para recursos de interface do usuário. Isso inclui barras de ferramentas simples, barras de ferramentas com hot imagens, ícones grandes, botões de pager, bloqueadas barras de ferramentas, controles rebar, texto em imagens, imagens de plano de fundo e com guias barras de ferramentas. O `CMFCToolBar` classe também contém suporte interno para personalização do usuário das barras de ferramentas e menus, arrastar e soltar entre barras de ferramentas e menus, botões da caixa de combinação, editar caixa botões, selecionadores de cores e botões de acumulação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBar : public CMFCBaseToolBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCToolBar::CMFCToolBar`|Construtor padrão.|  
|`CMFCToolBar::~CMFCToolBar`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBar::AddBasicCommand](#addbasiccommand)|Adiciona um comando de menu para a lista de comandos que sempre são exibidos quando um usuário abre um menu.|  
|[CMFCToolBar::AddCommandUsage](#addcommandusage)|Aumenta em incrementos de um, o contador está associado com o comando especificado.|  
|[CMFCToolBar::AddToolBarForImageCollection](#addtoolbarforimagecollection)|Adiciona imagens dos recursos de interface de usuário à coleção de imagens no aplicativo.|  
|[CMFCToolBar::AdjustLayout](#adjustlayout)|Recalcula o tamanho e a posição de uma barra de ferramentas. (Substitui [CBasePane::AdjustLayout](../../mfc/reference/cbasepane-class.md#adjustlayout)).|  
|[CMFCToolBar::AdjustSize](#adjustsize)|Recalcula o tamanho da barra de ferramentas.|  
|[CMFCToolBar::AllowChangeTextLabels](#allowchangetextlabels)|Especifica se os rótulos de texto podem ser mostrados em imagens dos botões de barra de ferramentas.|  
|[CMFCToolBar::AreTextLabels](#aretextlabels)|Especifica se os rótulos de texto em imagens atualmente são exibidos nos botões de barra de ferramentas.|  
|[CMFCToolBar::AutoGrayInactiveImages](#autograyinactiveimages)|Habilitar ou desabilita a geração automática de imagens de botão inativo.|  
|[CMFCToolBar::ButtonToIndex](#buttontoindex)|Retorna o índice de um [CMFCToolBarButton classe](../../mfc/reference/cmfctoolbarbutton-class.md) objeto essa barra de ferramentas.|  
|[CMFCToolBar::CalcFixedLayout](#calcfixedlayout)|Calcula o tamanho horizontal da barra de ferramentas. (Substitui [CBasePane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|  
|[CMFCToolBar::CalcSize](#calcsize)|Chamado pela estrutura como parte do processo de cálculo de layout. (Substitui [CPane::CalcSize](../../mfc/reference/cpane-class.md#calcsize).)|  
|[CMFCToolBar::CanHandleSiblings](#canhandlesiblings)|Determina se a barra de ferramentas e seu irmão estiver localizados no mesmo painel.|  
|[CMFCToolBar::CleanUpImages](#cleanupimages)|Libera os recursos do sistema alocados para imagens de barra de ferramentas.|  
|[CMFCToolBar::CleanUpLockedImages](#cleanuplockedimages)|Libera os recursos do sistema alocados para imagens bloqueado da barra de ferramentas.|  
|[CMFCToolBar::CanBeClosed](#canbeclosed)|Especifica se o usuário pode fechar a barra de ferramentas. (Substitui [CBasePane::CanBeClosed](../../mfc/reference/cbasepane-class.md#canbeclosed).)|  
|[CMFCToolBar::CanBeRestored](#canberestored)|Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização.|  
|[CMFCToolBar::CanFocus](#canfocus)|Especifica se o painel pode receber o foco. (Substitui [CBasePane::CanFocus](../../mfc/reference/cbasepane-class.md#canfocus).)|  
|[CMFCToolBar::CanHandleSiblings](#canhandlesiblings)|Determina se a barra de ferramentas e seu irmão estiver localizados no mesmo painel.|  
|[CMFCToolBar::CommandToIndex](#commandtoindex)|Retorna o índice do botão na barra de ferramentas com uma ID de comando especificado.|  
|[CMFCToolBar::Create](#create)|Cria um objeto `CMFCToolBar`.|  
|[CMFCToolBar::CreateEx](#createex)|Cria um `CMFCToolBar` objeto que usa opções de estilo adicionais, como ícones grandes.|  
|[CMFCToolBar::Deactivate](#deactivate)|Desativa a barra de ferramentas.|  
|[CMFCToolBar::EnableCustomizeButton](#enablecustomizebutton)|Habilita ou desabilita o **adicionar ou remover botões** botão é exibido no final da barra de ferramentas.|  
|[CMFCToolBar::EnableDocking](#enabledocking)|Habilita o encaixe do painel para o quadro principal. (Substitui [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking).)|  
|[CMFCToolBar::EnableLargeIcons](#enablelargeicons)|Habilita ou desabilita os ícones grandes em botões da barra de ferramentas.|  
|[CMFCToolBar::EnableQuickCustomization](#enablequickcustomization)|Habilita ou desabilita a personalização rápida das barras de ferramentas para que o usuário pode pressionar a **Alt** de chave e arraste um botão para um novo local.|  
|[CMFCToolBar::EnableReflections](#enablereflections)|Habilita ou desabilita a reflexão de comando.|  
|[CMFCToolBar::EnableTextLabels](#enabletextlabels)|Habilita ou desabilita os rótulos de texto em imagens de botão da barra de ferramentas.|  
|[CMFCToolBar::FromHandlePermanent](#fromhandlepermanent)|Recupera um ponteiro para o `CMFCToolBar` objeto que contém o identificador de janela determinada.|  
|[CMFCToolBar::GetAllButtons](#getallbuttons)|Retorna uma lista somente leitura dos botões na barra de ferramentas.|  
|[CMFCToolBar::GetAllToolbars](#getalltoolbars)|Retorna uma lista somente leitura de todas as barras de ferramentas do aplicativo.|  
|[CMFCToolBar::GetBasicCommands](#getbasiccommands)|Retorna uma lista somente leitura dos comandos básicos definidos no aplicativo.|  
|[CMFCToolBar::GetButton](#getbutton)|Retorna um ponteiro para o `CMFCToolBarButton` objeto que tem um índice de botão da barra de ferramentas especificada.|  
|[CMFCToolBar::GetButtonInfo](#getbuttoninfo)|Retorna a ID de comando, o estilo e o índice da imagem do botão em um índice especificado.|  
|[CMFCToolBar::GetButtonSize](#getbuttonsize)|Retorna as dimensões de cada botão na barra de ferramentas.|  
|[CMFCToolBar::GetButtonStyle](#getbuttonstyle)|Retorna o estilo atual do botão da barra de ferramentas que está localizado no índice especificado.|  
|[CMFCToolBar::GetButtonText](#getbuttontext)|Retorna o rótulo de texto de um botão que tem um índice especificado.|  
|[CMFCToolBar::GetColdImages](#getcoldimages)|Retorna um ponteiro para a coleção de imagens de botão da barra de ferramentas frio no aplicativo.|  
|[CMFCToolBar::GetColumnWidth](#getcolumnwidth)|Retorna a largura da barra de ferramentas.|  
|[CMFCToolBar::GetCommandButtons](#getcommandbuttons)|Retorna uma lista de botões que têm uma ID de comando especificado de todas as barras de ferramentas do aplicativo.|  
|[CMFCToolBar::GetCount](#getcount)|Retorna o número de botões e separadores na barra de ferramentas.|  
|[CMFCToolBar::GetCustomizeButton](#getcustomizebutton)|Recupera um ponteiro para o `CMFCCustomizeButton` objeto que está associado com a barra de ferramentas.|  
|[CMFCToolBar::GetDefaultImage](#getdefaultimage)|Retorna o índice da imagem padrão para um botão da barra de ferramentas com uma ID de comando especificado.|  
|[CMFCToolBar::GetDisabledImages](#getdisabledimages)|Retorna um ponteiro para a coleção de imagens que são usadas para botões de barra de ferramentas desativado no aplicativo.|  
|[CMFCToolBar::GetDisabledMenuImages](#getdisabledmenuimages)|Retorna um ponteiro para a coleção de imagens que são usadas para os botões de menu desativado no aplicativo.|  
|[CMFCToolBar::GetDroppedDownMenu](#getdroppeddownmenu)|Recupera um ponteiro para o objeto de botão de menu que atualmente está exibindo o submenu correspondente.|  
|[CMFCToolBar::GetGrayDisabledButtons](#getgraydisabledbuttons)|Especifica se as imagens de botões desabilitados são esmaecidas versões das imagens button normal, ou da coleção de imagens de botões desabilitados.|  
|[CMFCToolBar::GetHighlightedButton](#gethighlightedbutton)|Retorna um ponteiro para o botão de barra de ferramentas está realçado no momento.|  
|[CMFCToolBar::GetHotBorder](#gethotborder)|Determina se os botões da barra de ferramentas são rastreadas quente.|  
|[CMFCToolBar::GetHotTextColor](#gethottextcolor)|Retorna a cor do texto dos botões da barra de ferramentas realçado.|  
|[CMFCToolBar::GetHwndLastFocus](#gethwndlastfocus)|Retorna um identificador para a janela que tinha o foco de entrada antes que a barra de ferramentas.|  
|[CMFCToolBar::GetIgnoreSetText](#getignoresettext)|Especifica se as chamadas para definir rótulos de botões são ignoradas.|  
|[CMFCToolBar::GetImageSize](#getimagesize)|Retorna o tamanho atual de imagens de botão da barra de ferramentas.|  
|[CMFCToolBar::GetImages](#getimages)|Retorna um ponteiro para a coleção de padrão imagens de botão no aplicativo.|  
|[CMFCToolBar::GetImagesOffset](#getimagesoffset)|Retorna o deslocamento de índice usado para localizar imagens de botão de barra de ferramentas para essa barra de ferramentas da lista global de imagens de botão da barra de ferramentas.|  
|[CMFCToolBar::GetInvalidateItemRect](#getinvalidateitemrect)|Recupera a região da área do cliente que precisa ser redesenhada do botão no índice especificado.|  
|[CMFCToolBar::GetItemID](#getitemid)|Retorna a ID de comando do botão da barra de ferramentas em um índice especificado.|  
|[CMFCToolBar::GetItemRect](#getitemrect)|Retorna o retângulo delimitador do botão em um índice especificado.|  
|[CMFCToolBar::GetLargeColdImages](#getlargecoldimages)|Retorna um ponteiro para a coleção de imagens de botão da barra de ferramentas frio grandes no aplicativo.|  
|[CMFCToolBar::GetLargeDisabledImages](#getlargedisabledimages)|Retorna um ponteiro para a coleção de imagens de botão grande ferramentas desabilitado no aplicativo.|  
|[CMFCToolBar::GetLargeImages](#getlargeimages)|Retorna um ponteiro para a coleção de imagens de botão da barra de ferramentas grandes no aplicativo.|  
|[CMFCToolBar::GetLockedColdImages](#getlockedcoldimages)|Retorna um ponteiro para a coleção de imagens frios bloqueadas na barra de ferramentas.|  
|[CMFCToolBar::GetLockedDisabledImages](#getlockeddisabledimages)|Retorna um ponteiro para a coleção de imagens desabilitadas bloqueadas na barra de ferramentas.|  
|[CMFCToolBar::GetLockedImages](#getlockedimages)|Retorna um ponteiro para a coleção de imagens de botão bloqueados na barra de ferramentas.|  
|[CMFCToolBar::GetLockedImageSize](#getlockedimagesize)|Retorna o tamanho padrão das imagens bloqueado da barra de ferramentas.|  
|[CMFCToolBar::GetLockedMenuImages](#getlockedmenuimages)|Retorna um ponteiro para a coleção de ferramentas bloqueada imagens de menu na barra de ferramentas.|  
|[CMFCToolBar::GetMenuButtonSize](#getmenubuttonsize)|Retorna o tamanho dos botões de menu do aplicativo.|  
|[CMFCToolBar::GetMenuImageSize](#getmenuimagesize)|Retorna o tamanho das imagens de botão de menu do aplicativo.|  
|[CMFCToolBar::GetMenuImages](#getmenuimages)|Retorna um ponteiro para a coleção de imagens de botão de menu do aplicativo.|  
|[CMFCToolBar::GetOrigButtons](#getorigbuttons)|Recupera a coleção de botões não personalizado da barra de ferramentas.|  
|[CMFCToolBar::GetOrigResetButtons](#getorigresetbuttons)|Recupera a coleção de redefinição não personalizada botões da barra de ferramentas.|  
|[CMFCToolBar::GetResourceID](#getresourceid)|Recupera a ID de recurso da barra de ferramentas.|  
|[CMFCToolBar::GetRouteCommandsViaFrame](#getroutecommandsviaframe)|Determina qual objeto, quadro principal ou o proprietário, envia comandos para a barra de ferramentas.|  
|[CMFCToolBar::GetRowHeight](#getrowheight)|Retorna a altura dos botões da barra de ferramentas.|  
|[CMFCToolBar::GetShowTooltips](#getshowtooltips)|Especifica se as dicas de ferramenta são exibidas para os botões da barra de ferramentas.|  
|[CMFCToolBar::GetSiblingToolBar](#getsiblingtoolbar)|Recupera o irmão da barra de ferramentas.|  
|[CMFCToolBar::GetUserImages](#getuserimages)|Retorna um ponteiro para a coleção de imagens de botão da barra de ferramentas definidas pelo usuário no aplicativo.|  
|[CMFCToolBar::HitTest](#hittest)|Retorna o índice do botão da barra de ferramentas que está localizado na posição especificada.|  
|[CMFCToolBar::InsertButton](#insertbutton)|Insere um botão na barra de ferramentas.|  
|[CMFCToolBar::InsertSeparator](#insertseparator)|Insere um separador de barra de ferramentas.|  
|[CMFCToolBar::InvalidateButton](#invalidatebutton)|Invalida a área do cliente do botão da barra de ferramentas que existe no índice fornecido.|  
|[CMFCToolBar::IsAddRemoveQuickCustomize](#isaddremovequickcustomize)|Determina se um usuário pode adicionar ou remover botões da barra de ferramentas usando o **personalizar** opção de menu.|  
|[CMFCToolBar::IsAltCustomizeMode](#isaltcustomizemode)|Especifica se *personalização rápida* está sendo usada para arrastar um botão.|  
|[CMFCToolBar::IsAutoGrayInactiveImages](#isautograyinactiveimages)|Especifica se a geração automática de imagens de botão inativo (não realçada) está habilitada.|  
|[CMFCToolBar::IsBasicCommand](#isbasiccommand)|Determina se um comando está na lista de comandos básicos.|  
|[CMFCToolBar::IsButtonExtraSizeAvailable](#isbuttonextrasizeavailable)|Determina se a barra de ferramentas pode exibir botões que tem estendido bordas.|  
|[CMFCToolBar::IsButtonHighlighted](#isbuttonhighlighted)|Determina se um botão na barra de ferramentas é realçado.|  
|[CMFCToolBar::IsCommandPermitted](#iscommandpermitted)|Determina se um comando é permitido.|  
|[CMFCToolBar::IsCommandRarelyUsed](#iscommandrarelyused)|Determina se um comando raramente é usado (consulte [CMFCToolBar::SetCommandUsageOptions](#setcommandusageoptions)).|  
|[CMFCToolBar::IsCustomizeMode](#iscustomizemode)|Especifica se a estrutura da barra de ferramentas está no modo de personalização.|  
|[CMFCToolBar::IsDragButton](#isdragbutton)|Determina se um botão de barra de ferramentas está sendo arrastado.|  
|[CMFCToolBar::IsExistCustomizeButton](#isexistcustomizebutton)|Determina se a barra de ferramentas contém o **personalizar** botão.|  
|[CMFCToolBar::IsFloating](#isfloating)|Determina se a barra de ferramentas é flutuante.|  
|[CMFCToolBar::IsLargeIcons](#islargeicons)|Especifica se as barras de ferramentas no aplicativo atualmente exibem ícones grandes.|  
|[CMFCToolBar::IsLastCommandFromButton](#islastcommandfrombutton)|Determina se executado o último comando foi enviado a partir do botão de barra de ferramentas especificada.|  
|[CMFCToolBar::IsLocked](#islocked)|Determina se a barra de ferramentas está bloqueada.|  
|[CMFCToolBar::IsOneRowWithSibling](#isonerowwithsibling)|Determina se a barra de ferramentas e barra de ferramentas seu irmão são posicionados na mesma linha.|  
|[CMFCToolBar::IsUserDefined](#isuserdefined)|Especifica se a barra de ferramentas é definida pelo usuário.|  
|[CMFCToolBar::LoadBitmap](#loadbitmap)|Carrega imagens da barra de ferramentas de recursos do aplicativo.|  
|[CMFCToolBar::LoadBitmapEx](#loadbitmapex)|Carrega imagens da barra de ferramentas de recursos do aplicativo. Inclui imagens grandes.|  
|[CMFCToolBar::LoadParameters](#loadparameters)|Carrega as opções de barra de ferramentas global do registro do Windows.|  
|[CMFCToolBar::LoadState](#loadstate)|Carrega as informações de estado da barra de ferramentas do registro do Windows. (Substitui [CPane::LoadState](../../mfc/reference/cpane-class.md#loadstate).)|  
|[CMFCToolBar::LoadToolBar](#loadtoolbar)|Carrega a barra de ferramentas de recursos do aplicativo.|  
|[CMFCToolBar::LoadToolBarEx](#loadtoolbarex)|Carrega a barra de ferramentas de recursos do aplicativo usando o `CMFCToolBarInfo` classe auxiliar para ativar o aplicativo para usar imagens grandes.|  
|[CMFCToolBar::OnChangeHot](#onchangehot)|Chamado pela estrutura quando um usuário seleciona um botão na barra de ferramentas.|  
|[CMFCToolBar::OnFillBackground](#onfillbackground)|Chamado pela estrutura de [CBasePane::DoPaint](../../mfc/reference/cbasepane-class.md#dopaint) para preencher o plano de fundo da barra de ferramentas.|  
|[CMFCToolBar::OnReset](#onreset)|Restaura a barra de ferramentas para seu estado original.|  
|[CMFCToolBar::OnSetAccData](#onsetaccdata)|(Substitui [CBasePane::OnSetAccData](../../mfc/reference/cbasepane-class.md#onsetaccdata).)|  
|[CMFCToolBar::OnSetDefaultButtonText](#onsetdefaultbuttontext)|Restaura o texto de um botão da barra de ferramentas para seu estado padrão.|  
|`CMFCToolBar::OnUpdateCmdUI`|Usado internamente.|  
|[CMFCToolBar::RemoveAllButtons](#removeallbuttons)|Remove todos os botões da barra de ferramentas.|  
|[CMFCToolBar::RemoveButton](#removebutton)|Remove o botão com o índice especificado na barra de ferramentas.|  
|[CMFCToolBar::RemoveStateFromRegistry](#removestatefromregistry)|Exclui as informações de estado da barra de ferramentas do registro do Windows.|  
|[CMFCToolBar::ReplaceButton](#replacebutton)|Substitui um botão da barra de ferramentas com outro botão da barra de ferramentas.|  
|[CMFCToolBar::ResetAll](#resetall)|Restaura todas as barras de ferramentas para seu estado original.|  
|[CMFCToolBar::ResetAllImages](#resetallimages)|Limpa todas as coleções de imagem da barra de ferramentas do aplicativo.|  
|[CMFCToolBar::RestoreOriginalState](#restoreoriginalstate)|Restaura o estado original de uma barra de ferramentas.|  
|[CMFCToolBar::SaveState](#savestate)|Salva as informações de estado da barra de ferramentas no registro do Windows. (Substitui [CPane::SaveState](../../mfc/reference/cpane-class.md#savestate).)|  
|`CMFCToolBar::Serialize`|(Substitui `CBasePane::Serialize`.)|  
|[CMFCToolBar::SetBasicCommands](#setbasiccommands)|Define a lista de comandos que sempre são exibidos quando um usuário abre um menu.|  
|[CMFCToolBar::SetButtonInfo](#setbuttoninfo)|Define a ID de comando, o estilo e a ID da imagem de um botão da barra de ferramentas.|  
|[CMFCToolBar::SetButtonStyle](#setbuttonstyle)|Define o estilo do botão da barra de ferramentas no índice especificado.|  
|[CMFCToolBar::SetButtonText](#setbuttontext)|Define o rótulo de texto de um botão da barra de ferramentas.|  
|[CMFCToolBar::SetButtons](#setbuttons)|Define os botões da barra de ferramentas.|  
|[CMFCToolBar::SetCommandUsageOptions](#setcommandusageoptions)|Especifica quando os comandos usados raramente não aparecem no menu do aplicativo.|  
|[CMFCToolBar::SetCustomizeMode](#setcustomizemode)|Habilita ou desabilita o modo de personalização para todas as barras de ferramentas do aplicativo.|  
|[CMFCToolBar::SetGrayDisabledButtons](#setgraydisabledbuttons)|Especifica se os botões desabilitados na barra de ferramentas estão esmaecidos ou se desabilitado imagens são usadas para os botões desabilitados.|  
|[CMFCToolBar::SetHeight](#setheight)|Define a altura da barra de ferramentas.|  
|[CMFCToolBar::SetHotBorder](#sethotborder)|Especifica se os botões da barra de ferramentas são rastreados hot.|  
|[CMFCToolBar::SetHotTextColor](#sethottextcolor)|Define a cor do texto para botões da barra de ferramentas ativa.|  
|[CMFCToolBar::SetLargeIcons](#setlargeicons)|Especifica se os botões da barra de ferramentas exibem ícones grandes.|  
|[CMFCToolBar::SetLockedSizes](#setlockedsizes)|Define os tamanhos de botões bloqueado e imagens bloqueadas na barra de ferramentas.|  
|[CMFCToolBar::SetMenuSizes](#setmenusizes)|Define o tamanho dos botões de menu e suas imagens.|  
|[CMFCToolBar::SetNonPermittedCommands](#setnonpermittedcommands)|Define a lista de comandos que não pode ser executado pelo usuário.|  
|[CMFCToolBar::SetOneRowWithSibling](#setonerowwithsibling)|Posiciona a barra de ferramentas e seu irmão na mesma linha.|  
|[CMFCToolBar::SetPermament](#setpermament)|Especifica se o usuário pode fechar a barra de ferramentas.|  
|[CMFCToolBar::SetRouteCommandsViaFrame](#setroutecommandsviaframe)|Especifica se o quadro pai ou o proprietário envia comandos para a barra de ferramentas.|  
|[CMFCToolBar::SetShowTooltips](#setshowtooltips)|Especifica se o framework exibe dicas de ferramenta.|  
|[CMFCToolBar::SetSiblingToolBar](#setsiblingtoolbar)|Especifica o irmão da barra de ferramentas.|  
|[CMFCToolBar::SetSizes](#setsizes)|Especifica os tamanhos de botões e imagens em todas as barras de ferramentas.|  
|[CMFCToolBar::SetToolBarBtnText](#settoolbarbtntext)|Especifica as propriedades de um botão na barra de ferramentas.|  
|[CMFCToolBar::SetTwoRowsWithSibling](#settworowswithsibling)|Posiciona a barra de ferramentas e seu irmão em linhas separadas.|  
|[CMFCToolBar::SetUserImages](#setuserimages)|Define uma coleção de imagens definidas pelo usuário no aplicativo.|  
|[CMFCToolBar::StretchPane](#stretchpane)|Expande a barra de ferramentas verticalmente ou horizontalmente. (Substitui [CBasePane::StretchPane](../../mfc/reference/cbasepane-class.md#stretchpane).)|  
|[CMFCToolBar::TranslateChar](#translatechar)|Executa um comando de botão se o código de chave especificado corresponde a um atalho de teclado válido.|  
|[CMFCToolBar::UpdateButton](#updatebutton)|Atualiza o estado do botão especificado.|  
|[CMFCToolBar::WrapToolBar](#wraptoolbar)|Reposiciona botões dentro das dimensões determinadas.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBar::AllowShowOnList](#allowshowonlist)|Determina se a barra de ferramentas é exibida na lista no **barras de ferramentas** painel do **personalizar** caixa de diálogo.|  
|[CMFCToolBar::CalcMaxButtonHeight](#calcmaxbuttonheight)|Calcula a altura máxima de um botão na barra de ferramentas.|  
|[CMFCToolBar::DoPaint](#dopaint)|Redesenha uma barra de ferramentas.|  
|[CMFCToolBar::DrawButton](#drawbutton)|Redesenha a um botão da barra de ferramentas.|  
|[CMFCToolBar::DrawSeparator](#drawseparator)|Redesenha um separador em uma barra de ferramentas.|  
|[CMFCToolBar::OnUserToolTip](#onusertooltip)|Chamado pela estrutura quando a dica de ferramenta para um botão está prestes a ser exibido.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBar::m_bDontScaleImages](#m_bdontscaleimages)|Especifica se dimensionar ou não as imagens de barra de ferramentas no modo DPI alta.|  
|[CMFCToolBar::m_dblLargeImageRatio](#m_dbllargeimageratio)|Especifica a proporção entre a dimensão (altura ou largura) de imagens grandes e a dimensão de imagens regulares.|  
  
## <a name="remarks"></a>Comentários  
 Para incorporar um `CMFCToolBar` de objeto em seu aplicativo, siga estas etapas:  
  
1.  Adicionar uma `CMFCToolBar` objeto para a janela do quadro principal.  
  
2.  Ao processar o `WM_CREATE` de mensagem para a janela do quadro principal, chame o [CMFCToolBar::Create](#create) ou [CMFCToolBar::CreateEx](#createex) para criar a barra de ferramentas e especifique seu estilo.  
  
3.  Chamar [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking) para especificar o estilo de encaixe.  
  
 Para inserir um botão especial, como uma caixa de combinação ou a barra de ferramentas da lista suspensa, reservar um botão fictício no recurso pai e substitua o botão fictício em tempo de execução usando [CMFCToolBar::ReplaceButton](#replacebutton). Para obter mais informações, consulte [passo a passo: colocando controles em barras de ferramentas](../walkthrough-putting-controls-on-toolbars.md).  
  
 `CMFCToolBar`é a classe base para as classes de biblioteca MFC [CMFCMenuBar classe](../../mfc/reference/cmfcmenubar-class.md), [CMFCPopupMenuBar classe](../../mfc/reference/cmfcpopupmenubar-class.md), e [CMFCDropDownToolBar classe](../../mfc/reference/cmfcdropdowntoolbar-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCToolBar` classe. O exemplo mostra como definir o texto do rótulo da janela da barra de ferramentas, as bordas, defina o estilo do painel e habilitar o **adicionar ou remover botões** botão é exibido no final da barra de ferramentas. Este trecho de código é parte do [exemplo IE demonstração](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo n º&6;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_1.h)]  
[!code-cpp[NVC_MFC_IEDemo n º&8;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbar. h  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 `CMFCToolBar`  
  
##  <a name="a-nameaddbasiccommanda--cmfctoolbaraddbasiccommand"></a><a name="addbasiccommand"></a>CMFCToolBar::AddBasicCommand  
 Adiciona um comando de menu para a lista de comandos que sempre são exibidos quando um usuário abre um menu.  
  
```  
static void __stdcall AddBasicCommand(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 Especifica o comando para adicionar.  
  
### <a name="remarks"></a>Comentários  
 Um comando básico sempre é exibido quando o menu é aberto. Esse método é significativo quando o usuário opta por exibir comandos usados recentemente.  
  
 Use o [CMFCToolBar::SetBasicCommands](#setbasiccommands) método para definir a lista de comandos que sempre são exibidos quando um usuário abre um menu. Use o [CMFCToolBar::GetBasicCommands](#getbasiccommands) método para recuperar a lista de comandos básicos que é usada pelo seu aplicativo.  
  
##  <a name="a-nameaddcommandusagea--cmfctoolbaraddcommandusage"></a><a name="addcommandusage"></a>CMFCToolBar::AddCommandUsage  
 Aumenta em incrementos de um, o contador está associado com o comando especificado.  
  
```  
static void __stdcall AddCommandUsage(UINT uiCommand);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCommand`  
 Especifica o contador de comando seja incrementado.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando o usuário seleciona um item de menu.  
  
 A estrutura usa contadores para exibição recentemente usados itens de menu de comando.  
  
 Esse método incrementa o contador de comando usando o [CMFCCmdUsageCount::AddCmd](../../mfc/reference/cmfccmdusagecount-class.md#addcmd) método.  
  
##  <a name="a-nameaddtoolbarforimagecollectiona--cmfctoolbaraddtoolbarforimagecollection"></a><a name="addtoolbarforimagecollection"></a>CMFCToolBar::AddToolBarForImageCollection  
 Adiciona imagens dos recursos de interface de usuário à coleção de imagens no aplicativo.  
  
```  
static BOOL __stdcall AddToolBarForImageCollection(
    UINT uiResID,  
    UINT uiBmpResID=0,  
    UINT uiColdResID=0,  
    UINT uiMenuResID=0,  
    UINT uiDisabledResID=0,  
    UINT uiMenuDisabledResID=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiResID`  
 ID de recurso da barra de ferramentas com imagens para carregar.  
  
 [in] `uiBmpResID`  
 ID de recurso de um bitmap com imagens da barra de ferramentas.  
  
 [in] `uiColdResID`  
 ID de recurso de um bitmap com imagens "frio" barra de ferramentas.  
  
 [in] `uiMenuResID`  
 ID de recurso de um bitmap com imagens do menu.  
  
 [in] `uiDisabledResID`  
 ID de recurso de um bitmap com imagens de barra de ferramentas desativado.  
  
 [in] `uiMenuDisabledResID`  
 ID de recurso de um bitmap com imagens de menu desativado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método for bem-sucedido; `FALSE` se `uiResID` ou `uiBmpResID` não especificar recursos válidos, ou outro erro ocorre.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para carregar um bitmap com imagens da barra de ferramentas e adicioná-la à coleção de imagens da barra de ferramentas. Esse método cria um objeto temporário da barra de ferramentas e chamadas [CMFCToolBar::LoadToolBar](#loadtoolbar).  
  
##  <a name="a-nameadjustlayouta--cmfctoolbaradjustlayout"></a><a name="adjustlayout"></a>CMFCToolBar::AdjustLayout  
 Recalcula o tamanho e a posição de uma barra de ferramentas.  
  
```  
virtual void AdjustLayout();
```  
  
### <a name="remarks"></a>Comentários  
 Chame esse método quando a barra de ferramentas foi criada para recalcular sua posição e tamanho.  
  
 O framework chama esse método sempre que o layout da barra de ferramentas deve ser alterado. Por exemplo, o layout deve alterar quando o usuário move outra barra de controle, redimensiona a janela do aplicativo ou personaliza a barra de ferramentas.  
  
 Substitui esse método para fornecer seu próprio layout dinâmico em classes que derivam de `CMFCToolbar`.  
  
##  <a name="a-nameadjustsizea--cmfctoolbaradjustsize"></a><a name="adjustsize"></a>CMFCToolBar::AdjustSize  
 Recalcula o tamanho da barra de ferramentas.  
  
```  
void AdjustSize();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método garante que a barra de ferramentas se encaixa os limites do quadro principal. Esse método não fará nada se a barra de ferramentas não tem nenhum quadro principal.  
  
 O [CMFCToolBar::AdjustLayout](#adjustlayout) método chama esse método para recalcular o tamanho se o pai da barra de ferramentas não é um `CMFCReBar` objeto.  
  
##  <a name="a-nameallowchangetextlabelsa--cmfctoolbarallowchangetextlabels"></a><a name="allowchangetextlabels"></a>CMFCToolBar::AllowChangeTextLabels  
 Especifica se os rótulos de texto podem ser mostrados em imagens dos botões de barra de ferramentas.  
  
```  
virtual BOOL AllowChangeTextLabels() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se ele tem permissão para exibir rótulos de texto abaixo de imagens; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela caixa de diálogo de personalização para determinar se deve habilitar um **Mostrar rótulos de texto** caixa de seleção no **barras de ferramentas** página da barra de ferramentas selecionada.  
  
 Retorna a implementação padrão `TRUE`.  
  
 Substitua esse método em um objeto derivado de `CMFCToolBar` e retornar `FALSE` quando você não deseja que o usuário decida se os rótulos de texto são exibidos nos botões de barra de ferramentas em imagens.  
  
##  <a name="a-nameallowshowonlista--cmfctoolbarallowshowonlist"></a><a name="allowshowonlist"></a>CMFCToolBar::AllowShowOnList  
 Determina se a barra de ferramentas é exibida na lista de barras de ferramentas sobre o **barras de ferramentas** painel do **personalizar** caixa de diálogo.  
  
```  
virtual BOOL AllowShowOnList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o objeto de barra de ferramentas pode ser exibido na caixa de listagem na página de personalização da barra de ferramentas; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura para determinar se a lista na página de personalização da barra de ferramentas deve incluir um objeto específico derivado de `CMFCToolBar`.  
  
 A implementação padrão sempre retorna `TRUE`. Substitua este método quando você deseja não aparecer na lista de barras de ferramentas na caixa de diálogo de personalização em uma barra de ferramentas.  
  
##  <a name="a-namearetextlabelsa--cmfctoolbararetextlabels"></a><a name="aretextlabels"></a>CMFCToolBar::AreTextLabels  
 Especifica se os rótulos de texto em imagens atualmente são exibidos nos botões de barra de ferramentas.  
  
```  
BOOL AreTextLabels() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se os botões da barra de ferramentas exibem rótulos de texto abaixo de imagens; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use [CMFCToolBar::EnableTextLabels](#enabletextlabels) para especificar se o texto é exibido. O valor padrão é `FALSE`. Chamar [CMFCToolBar::AllowChangeTextLabels](#allowchangetextlabels) para especificar se o usuário pode alterar essa configuração na caixa de diálogo de personalização.  
  
##  <a name="a-nameautograyinactiveimagesa--cmfctoolbarautograyinactiveimages"></a><a name="autograyinactiveimages"></a>CMFCToolBar::AutoGrayInactiveImages  
 Habilitar ou desabilita a geração automática de imagens de botão inativo.  
  
```  
static void AutoGrayInactiveImages(
    BOOL bEnable=TRUE,  
    int nGrayImagePercentage=0,  
    BOOL bRedrawAllToolbars=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 Um valor booleano que especifica se a dim imagens inativas. Se esse parâmetro for `TRUE`, imagens inativas estão esmaecidas. Caso contrário, as imagens inativas não ficam acinzentadas.  
  
 [in] `nGrayImagePercentage`  
 Especifica a porcentagem de luminância para imagens inativas. Se `bEnable` é `FALSE`, esse valor é ignorado.  
  
 [in] `bRedrawAllToolbars`  
 Um valor booleano que especifica se a redesenhar todas as barras de ferramentas do aplicativo. Se esse parâmetro for `TRUE`, esse método redesenha todas as barras de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Se `bEnable` é `TRUE`, a estrutura usa `nGrayImagePercentage` para gerar imagens inativas entre as imagens regulares. Caso contrário, você deve fornecer o conjunto de imagens inativos usando o [CMFCToolBar::GetColdImages](#getcoldimages) método. Por padrão, essa opção está desabilitada.  
  
 Para obter mais informações sobre o `nGrayImagePercentage` parâmetro, consulte [CMFCToolBarImages::GrayImages](../../mfc/reference/cmfctoolbarimages-class.md#grayimages).  
  
##  <a name="a-namebuttontoindexa--cmfctoolbarbuttontoindex"></a><a name="buttontoindex"></a>CMFCToolBar::ButtonToIndex  
 Retorna o índice de um [CMFCToolBarButton classe](../../mfc/reference/cmfctoolbarbutton-class.md) objeto essa barra de ferramentas.  
  
```  
int ButtonToIndex(const CMFCToolBarButton* pButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Um ponteiro para o objeto de botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice de `pButton` na lista de botões da barra de ferramentas; ou -1 se o botão especificado não estiver nessa barra de ferramentas interna.  
  
##  <a name="a-namecalcfixedlayouta--cmfctoolbarcalcfixedlayout"></a><a name="calcfixedlayout"></a>CMFCToolBar::CalcFixedLayout  
 Calcula o tamanho horizontal da barra de ferramentas.  
  
```  
virtual CSize CalcFixedLayout(
    BOOL bStretch,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bStretch`  
 `TRUE`para ampliar a barra de ferramentas para o tamanho do quadro principal.  
  
 [in] `bHorz`  
 `TRUE`para orientar a barra de ferramentas horizontalmente; `FALSE` para orientar a barra de ferramentas verticalmente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que especifica o tamanho da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Esse método calcula o tamanho da barra de ferramentas usando o `CMFCToolBar::CalcLayout` método. Ele passa o `LM_STRETCH` sinalizar para o `dwMode` parâmetro se `bStretch` é `TRUE`. Ele passa o `LM_HORZ` sinalizador se `bHorz` é `TRUE`.  
  
 Consulte o exemplo VisualStudioDemo para obter um exemplo que usa esse método.  
  
##  <a name="a-namecalcmaxbuttonheighta--cmfctoolbarcalcmaxbuttonheight"></a><a name="calcmaxbuttonheight"></a>CMFCToolBar::CalcMaxButtonHeight  
 Calcula a altura máxima dos botões na barra de ferramentas.  
  
```  
virtual int CalcMaxButtonHeight();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura máxima de botões.  
  
### <a name="remarks"></a>Comentários  
 Esse método calcula a altura máxima entre todos os botões de barra de ferramentas na barra de ferramentas. A altura pode variar dependendo de fatores como o estado de encaixe da barra de ferramentas atual.  
  
 Substitua esse método em uma classe derivada de `CMFCToolBar` para fornecer seu próprio cálculo de altura.  
  
##  <a name="a-namecalcsizea--cmfctoolbarcalcsize"></a><a name="calcsize"></a>CMFCToolBar::CalcSize  
 Chamado pela estrutura como parte do processo de cálculo de layout.  
  
```  
virtual CSize CalcSize(BOOL bVertDock);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bVertDock`  
 `TRUE`para especificar que a barra de ferramentas é encaixada verticalmente; `FALSE` para especificar que a barra de ferramentas está ancorada horizontalmente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que especifica o tamanho total dos botões na barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Esse método considera os atributos que afetam o tamanho de cada botão, como a área do rótulo de texto e o tamanho da borda.  
  
 Se a barra de ferramentas contém botões não, esse método retorna o tamanho reservado de um único botão usando o [CMFCToolBar::GetButtonSize](#getbuttonsize) método.  
  
##  <a name="a-namecanbecloseda--cmfctoolbarcanbeclosed"></a><a name="canbeclosed"></a>CMFCToolBar::CanBeClosed  
 Especifica se o usuário pode fechar a barra de ferramentas.  
  
```  
virtual BOOL CanBeClosed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas pode ser fechada pelo usuário. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar se o usuário pode fechar uma barra de ferramentas. Se o método retornar `TRUE`, o framework permite que o comando SC_CLOSE no menu de sistema da barra de ferramentas e o usuário pode fechar a barra de ferramentas usando uma caixa de seleção na lista de barras de ferramentas na caixa de diálogo de personalização.  
  
 Retorna a implementação padrão `TRUE`. Substitua esse método em uma classe derivada de `CMFCToolBar` para tornar os objetos de barra de ferramentas que não podem ser fechados pelo usuário.  
  
##  <a name="a-namecanberestoreda--cmfctoolbarcanberestored"></a><a name="canberestored"></a>CMFCToolBar::CanBeRestored  
 Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização.  
  
```  
virtual BOOL CanBeRestored() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas pode ser restaurada a partir de recursos do aplicativo; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar se uma barra de ferramentas pode ser retornada ao seu estado original após a personalização. O estado original é carregado dos recursos do aplicativo.  
  
 Se `CanBeRestored` retorna `TRUE`, o **barras de ferramentas** página da caixa de diálogo de personalização permite o **redefinir** botão da barra de ferramentas selecionada.  
  
 Retorna a implementação padrão `TRUE` se a ID de recurso original da barra de ferramentas quando ele foi carregado é diferente de zero. Geralmente, apenas barras de ferramentas definidas pelo usuário não podem ser restauradas.  
  
 Você pode substituir o `CanBeRestored` método personalizar esse comportamento em classes derivadas.  
  
##  <a name="a-namecanfocusa--cmfctoolbarcanfocus"></a><a name="canfocus"></a>CMFCToolBar::CanFocus  
 Especifica se o painel pode receber o foco.  
  
```  
virtual BOOL CanFocus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método substitui a implementação da classe base, [CBasePane::CanFocus](../../mfc/reference/cbasepane-class.md#canfocus), como objetos de barra de ferramentas não podem receber foco.  
  
##  <a name="a-namecanhandlesiblingsa--cmfctoolbarcanhandlesiblings"></a><a name="canhandlesiblings"></a>CMFCToolBar::CanHandleSiblings  
 Determina se a barra de ferramentas e seu irmão estiver localizados no mesmo painel.  
  
```  
BOOL CanHandleSiblings();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas tem um irmão e barra de ferramentas e seu irmão estiver localizados no mesmo painel; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O método CMFCCustomizeButton::CreatePopupMenu interno chama esse método para determinar como exibir o **personalizar** menu pop-up. Se esse método retornar `TRUE`, exibe a estrutura de **Mostrar botões em uma linha** ou **Mostrar botões em duas linhas** botões.  
  
 Normalmente, você não precisa usar esse método. Para habilitar o **personalizar** botão aparece na barra de ferramentas, chamada de [CMFCToolBar::EnableCustomizeButton](#enablecustomizebutton) método. Para habilitar o **Mostrar botões em uma linha** ou **Mostrar botões em duas linhas** botões, chame [CMFCToolBar::SetSiblingToolBar](#setsiblingtoolbar).  
  
##  <a name="a-namecleanupimagesa--cmfctoolbarcleanupimages"></a><a name="cleanupimages"></a>CMFCToolBar::CleanUpImages  
 Libera os recursos do sistema alocados para imagens de barra de ferramentas.  
  
```  
static void CMFCToolBar::CleanUpImages();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando um aplicativo é desligado.  
  
##  <a name="a-namecleanuplockedimagesa--cmfctoolbarcleanuplockedimages"></a><a name="cleanuplockedimages"></a>CMFCToolBar::CleanUpLockedImages  
 Libera os recursos do sistema alocados para imagens bloqueado da barra de ferramentas.  
  
```  
void CleanUpLockedImages();
```  
  
### <a name="remarks"></a>Comentários  
 Chame esse método quando altera o estilo visual do seu aplicativo. Consulte o exemplo VisualStudioDemo para obter um exemplo que usa esse método.  
  
##  <a name="a-namecommandtoindexa--cmfctoolbarcommandtoindex"></a><a name="commandtoindex"></a>CMFCToolBar::CommandToIndex  
 Retorna o índice do botão na barra de ferramentas com uma ID de comando especificado.  
  
```  
int CommandToIndex(
    UINT nIDFind,  
    int iIndexFirst=0) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIDFind`  
 Especifica a ID de comando.  
  
 [in] `iIndexFirst`  
 Especifica o índice inicial para iniciar a partir de.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice baseado em zero do botão da barra de ferramentas se o método teve êxito; -1 se não houver nenhum botão com a ID especificada.  
  
### <a name="remarks"></a>Comentários  
 Um `CMFCToolBar` objeto mantém uma lista interna dos botões na barra de ferramentas. Chame essa função para recuperar o índice de um botão na lista fornecida a ID de comando do botão.  
  
 Se `iIndex` é maior que 0, esse método ignora qualquer botão na barra de ferramentas que tem um índice menor que `iIndex`.  
  
##  <a name="a-namecreatea--cmfctoolbarcreate"></a><a name="create"></a>CMFCToolBar::Create  
 Cria um objeto `CMFCToolBar`.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwStyle=AFX_DEFAULT_TOOLBAR_STYLE,  
    UINT nID=AFX_IDW_TOOLBAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentWnd`  
 Um ponteiro para a janela pai da barra de ferramentas.  
  
 [in] `dwStyle`  
 O estilo de barra de ferramentas. Consulte [controle de barra de ferramentas e os estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb760439) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para a lista de estilos.  
  
 [in] `nID`  
 A ID da janela filho da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria uma barra de controle e anexa-o na barra de ferramentas. Ele cria a barra de controle com o `TBSTYLE_FLAT` estilo. Chamar [CMFCToolBar::CreateEx](#createex) se você quiser um estilo de barra de controle diferentes.  
  
##  <a name="a-namecreateexa--cmfctoolbarcreateex"></a><a name="createex"></a>CMFCToolBar::CreateEx  
 Cria um `CMFCToolBar` objeto que usa opções de estilo adicionais, como ícones grandes.  
  
```  
virtual BOOL CreateEx(
    CWnd* pParentWnd,  
    DWORD dwCtrlStyle=TBSTYLE_FLAT,  
    DWORD dwStyle=AFX_DEFAULT_TOOLBAR_STYLE,  
    CRect rcBorders=CRect(1,
    1,
    1,
    1),  
    UINT nID=AFX_IDW_TOOLBAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentWnd`  
 Um ponteiro para a janela pai da barra de ferramentas.  
  
 [in] `dwCtrlStyle`  
 Estilos adicionais para criar o objeto de barra de controle inserido.  
  
 [in] `dwStyle`  
 O estilo de barra de ferramentas. Consulte [estilos de botão e controle de barra de ferramentas](http://msdn.microsoft.com/library/windows/desktop/bb760439) para obter uma lista dos estilos apropriados.  
  
 [in] `rcBorders`  
 Um `CRect` objeto que especifica a largura das bordas da janela de ferramentas.  
  
 [in] `nID`  
 A ID da janela filho da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se esse método for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria uma barra de controle e anexa-o na barra de ferramentas.  
  
 Chamar esse método em vez de [CMFCToolBar::Create](#create) quando você deseja fornecer estilos específicos. Por exemplo, defina `dwCtrlStyle` para `TBSTYLE_FLAT | TBSTYLE_TRANSPARENT` para criar uma barra de ferramentas que se parece com as barras de ferramentas que são usadas pelo Internet Explorer 4.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `CreateEx` método o `CMFCToolBar` classe. Este trecho de código é parte do [exemplo IE demonstração](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo n º&6;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_1.h)]  
[!code-cpp[NVC_MFC_IEDemo&#7;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_3.cpp)]  
  
##  <a name="a-namedeactivatea--cmfctoolbardeactivate"></a><a name="deactivate"></a>CMFCToolBar::Deactivate  
 Desativa a barra de ferramentas.  
  
```  
virtual void Deactivate();
```  
  
### <a name="remarks"></a>Comentários  
 Este método desativa a barra de ferramentas, removendo o foco no botão da barra de ferramentas realçado. O framework chama esse método quando a barra de ferramentas perde o foco ou destruída.  
  
##  <a name="a-namedopainta--cmfctoolbardopaint"></a><a name="dopaint"></a>CMFCToolBar::DoPaint  
 Redesenha uma barra de ferramentas.  
  
```  
virtual void DoPaint(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pela estrutura quando uma parte da barra de ferramentas deve ser pintada novamente.  
  
 Substituir este método para personalizar a aparência de um objeto derivado de `CMFCToolBar`.  
  
##  <a name="a-namedrawbuttona--cmfctoolbardrawbutton"></a><a name="drawbutton"></a>CMFCToolBar::DrawButton  
 Redesenha a um botão da barra de ferramentas.  
  
```  
virtual BOOL DrawButton(
    CDC* pDC,  
    CMFCToolBarButton* pButton,  
    CMFCToolBarImages* pImages,  
    BOOL bHighlighted,  
    BOOL bDrawDisabledImages);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `pButton`  
 Um ponteiro para um botão para desenhar.  
  
 [in] `pImages`  
 Um ponteiro para as imagens da barra de ferramentas.  
  
 [in] `bHighlighted`  
 `TRUE`Se o botão é realçado; Caso contrário, `FALSE`.  
  
 [in] `bDrawDisabledImages`  
 `TRUE`Se os botões desabilitados são esmaecidos; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão foi redesenhado; `FALSE` se o botão estiver oculto.  
  
### <a name="remarks"></a>Comentários  
 O [CMFCToolBar::DrawButton](#drawbutton) método chama esse método quando um botão de barra de ferramentas deve ser pintada novamente.  
  
 Substitua este método se você quiser personalizar a aparência dos botões na barra de ferramentas.  
  
##  <a name="a-namedrawseparatora--cmfctoolbardrawseparator"></a><a name="drawseparator"></a>CMFCToolBar::DrawSeparator  
 Redesenha um separador em uma barra de ferramentas.  
  
```  
virtual void DrawSeparator(
    CDC* pDC,  
    const CRect& rect,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 O retângulo delimitador do local onde o separador é desenhado, em pixels.  
  
 [in] `bHorz`  
 `TRUE`Se o separador é horizontal, `FALSE` se o separador é vertical.  
  
### <a name="remarks"></a>Comentários  
 [CMFCToolBar::DoPaint](#dopaint) chama esse método para cada [CMFCToolBar::DrawSeparator](#drawseparator) objeto que tem o `TBBS_SEPARATOR` estilos, em vez de chamar [CMFCToolBar::DrawButton](#drawbutton) para esses botões.  
  
 Substitua esse método em uma classe derivada de [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) para personalizar a aparência de separadores na barra de ferramentas. As chamadas de implementação padrão [CMFCVisualManager::OnDrawSeparator](../../mfc/reference/cmfcvisualmanager-class.md#ondrawseparator) para desenhar um separador cuja aparência é determinada pelo Gerenciador de visual atual.  
  
##  <a name="a-nameenablecustomizebuttona--cmfctoolbarenablecustomizebutton"></a><a name="enablecustomizebutton"></a>CMFCToolBar::EnableCustomizeButton  
 Habilita ou desabilita o botão Personalizar que aparece na barra de ferramentas.  
  
```  
void EnableCustomizeButton(
    BOOL bEnable,  
    int iCustomizeCmd,  
    const CString& strCustomizeText,  
    BOOL bQuickCustomize=TRUE);

 
void EnableCustomizeButton(
    BOOL bEnable,  
    int iCustomizeCmd,  
    UINT uiCustomizeTextResId,  
    BOOL bQuickCustomize=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 Habilita ou desabilita o botão Personalizar.  
  
 [in] `iCustomizeCmd`  
 A ID de comando do botão Personalizar.  
  
 [in] `strCustomizeText`  
 O rótulo de texto do botão Personalizar.  
  
 [in] `uiCustomizeTextResId`  
 A ID da cadeia de caracteres de recurso do rótulo do botão Personalizar.  
  
 [in] `bQuickCustomize`  
 Habilita ou desabilita o **adicionar ou remover botões** opção no menu suspenso do botão.  
  
### <a name="remarks"></a>Comentários  
 Se `iCustomizeCmd` é -1, o exibe framework Personalizar botão quando vários botões de barra de ferramentas não se encaixam na área da barra de ferramentas. O botão exibe um double esquerda apontando seta ou divisa, que indica que há mais botões.  
  
 Se `iCustomizeCmd` Especifica uma ID de comando válidos, e `bEnable` é `TRUE`, no botão Personalizar sempre é exibido. O botão tem uma pequena seta para baixo e abre um menu que contém um comando. Esse comando usa o rótulo de texto especificado por `strCustomizeText`. Se `bQuickCustomize` também é `TRUE`, o menu exibe o **adicionar ou remover botões** opção.  
  
 O framework adiciona dinamicamente ao menu os botões que não cabem na área de antes do item que é especificado pelo `iCustomizeCmd`. É exibida a divisa ao lado da seta para baixo.  
  
##  <a name="a-nameenabledockinga--cmfctoolbarenabledocking"></a><a name="enabledocking"></a>CMFCToolBar::EnableDocking  
 Habilita o encaixe do painel para o quadro principal.  
  
```  
virtual void EnableDocking(DWORD dwAlignment);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwAlignment`  
 Especifica o alinhamento de encaixe para habilitar.  
  
### <a name="remarks"></a>Comentários  
 Esse método estende a implementação da classe base, [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking), definindo o `CBasePane::m_dwControlBarStyle` membro de dados para `AFX_CBRS_FLOAT`. Esse método passa `dwAlignment` para a implementação da classe base.  
  
##  <a name="a-nameenablelargeiconsa--cmfctoolbarenablelargeicons"></a><a name="enablelargeicons"></a>CMFCToolBar::EnableLargeIcons  
 Habilita ou desabilita os ícones grandes em botões da barra de ferramentas.  
  
```  
void EnableLargeIcons(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar ícones grandes, `FALSE` desativar ícones grandes.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, os ícones grandes são habilitados.  
  
##  <a name="a-nameenablequickcustomizationa--cmfctoolbarenablequickcustomization"></a><a name="enablequickcustomization"></a>CMFCToolBar::EnableQuickCustomization  
 Habilita ou desabilita a personalização rápida das barras de ferramentas para que o usuário pode pressionar a **Alt** de chave e arraste um botão para um novo local.  
  
```  
static void EnableQuickCustomization(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar a personalização rápida, `FALSE` para desativar a personalização rápida.  
  
##  <a name="a-nameenablereflectionsa--cmfctoolbarenablereflections"></a><a name="enablereflections"></a>CMFCToolBar::EnableReflections  
 Habilita ou desabilita a reflexão de comando.  
  
```  
void EnableReflections(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar a reflexão de comando; `FALSE` para desabilitar a reflexão de comando.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para habilitar a reflexão de comando para botões da barra de ferramentas que contêm controles incorporados, como caixas de combinação.  
  
 Para obter mais informações sobre reflexão de comando, consulte [TN062: reflexão de mensagem para controles de Windows](../../mfc/tn062-message-reflection-for-windows-controls.md).  
  
##  <a name="a-nameenabletextlabelsa--cmfctoolbarenabletextlabels"></a><a name="enabletextlabels"></a>CMFCToolBar::EnableTextLabels  
 Habilita ou desabilita os rótulos de texto em imagens de botão da barra de ferramentas.  
  
```  
void EnableTextLabels(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 `TRUE`Se os rótulos de texto aparecem em imagens de botão da barra de ferramentas; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se rótulos de texto estiverem habilitados, todos os botões na barra de ferramentas são ampliados para fornecer espaço para os rótulos a serem exibidos em imagens. A caixa de diálogo de personalização tem um **Mostrar rótulos de texto** caixa de seleção no **barras de ferramentas** página. Quando o usuário seleciona uma barra de ferramentas e verifica essa opção, a estrutura chama `EnableTextLabels` da barra de ferramentas selecionada. Você pode desabilitar a caixa de seleção para um objeto derivado de [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) retornando `FALSE` de [CMFCToolBar::AllowChangeTextLabels](#allowchangetextlabels) .  
  
##  <a name="a-namefromhandlepermanenta--cmfctoolbarfromhandlepermanent"></a><a name="fromhandlepermanent"></a>CMFCToolBar::FromHandlePermanent  
 Recupera um ponteiro para o `CMFCToolBar` objeto que contém o identificador de janela determinada.  
  
```  
static CMFCToolBar* __stdcall FromHandlePermanent(HWND hwnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hwnd`  
 O identificador de janela Procurar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CMFCToolBar` objeto que contém o identificador de janela determinado ou `NULL` se nenhum correspondente `CMFCToolBar` objeto existe.  
  
### <a name="remarks"></a>Comentários  
 Esse método compartilhado examina cada barra de ferramentas do aplicativo para o `CMFCToolBar` objeto que contém o identificador de janela determinada.  
  
##  <a name="a-namegetallbuttonsa--cmfctoolbargetallbuttons"></a><a name="getallbuttons"></a>CMFCToolBar::GetAllButtons  
 Retorna uma lista somente leitura dos botões na barra de ferramentas.  
  
```  
const CObList& GetAllButtons() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência constante para um [CObList classe](../../mfc/reference/coblist-class.md) objeto, que contém uma coleção de [CMFCToolBarButton classe](../../mfc/reference/cmfctoolbarbutton-class.md) objetos.  
  
##  <a name="a-namegetalltoolbarsa--cmfctoolbargetalltoolbars"></a><a name="getalltoolbars"></a>CMFCToolBar::GetAllToolbars  
 Retorna uma lista somente leitura de todas as barras de ferramentas do aplicativo.  
  
```  
static const CObList& GetAllToolbars();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Referência a uma constante para um [CObList classe](../../mfc/reference/coblist-class.md) objeto que contém uma coleção de `CMFCToolBar` objetos.  
  
##  <a name="a-namegetbasiccommandsa--cmfctoolbargetbasiccommands"></a><a name="getbasiccommands"></a>CMFCToolBar::GetBasicCommands  
 Retorna uma lista somente leitura dos comandos básicos definidos no aplicativo.  
  
```  
static const CList<UINT,UINT>& GetBasicCommands();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Referência a uma constante para um [classe CList](../../mfc/reference/clist-class.md) objeto que contém uma coleção de comandos básicos.  
  
### <a name="remarks"></a>Comentários  
 Adicionar comandos básicos chamando [CMFCToolBar::AddBasicCommand](#addbasiccommand) ou [CMFCToolBar::SetBasicCommands](#setbasiccommands).  
  
##  <a name="a-namegetbuttona--cmfctoolbargetbutton"></a><a name="getbutton"></a>CMFCToolBar::GetButton  
 Retorna um ponteiro para o [CMFCToolBarButton classe](../../mfc/reference/cmfctoolbarbutton-class.md) objeto em um índice especificado.  
  
```  
CMFCToolBarButton* GetButton(int iIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 Especifica o índice do botão para retornar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o botão da barra de ferramentas se ele existir. ou `NULL` se não houver nenhum esse botão.  
  
##  <a name="a-namegetbuttoninfoa--cmfctoolbargetbuttoninfo"></a><a name="getbuttoninfo"></a>CMFCToolBar::GetButtonInfo  
 Retorna a ID de comando, o estilo e o índice da imagem do botão em um índice especificado.  
  
```  
void GetButtonInfo(
    int nIndex,  
    UINT& nID,  
    UINT& nStyle,  
    int& iImage) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice do botão na lista de botões na barra de ferramentas.  
  
 [out] `nID`  
 A ID de um botão de comando.  
  
 [out] `nStyle`  
 O estilo do botão.  
  
 [out] `iImage`  
 O índice da imagem do botão.  
  
### <a name="remarks"></a>Comentários  
 O `GetButtonInfo` método localiza um botão da barra de ferramentas no índice especificado e retorna o índice de comando ID, o estilo e a imagem do botão.  
  
 Se o botão no índice especificado não existir, a estrutura define `nID` e `nStyle` como 0, e `iImage` como -1 quando o método retorna.  
  
##  <a name="a-namegetbuttonsizea--cmfctoolbargetbuttonsize"></a><a name="getbuttonsize"></a>CMFCToolBar::GetButtonSize  
 Retorna as dimensões de cada botão na barra de ferramentas.  
  
```  
CSize GetButtonSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CSize classe](../../atl-mfc-shared/reference/csize-class.md) objeto que especifica as dimensões de cada botão na barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CMFCToolBar::SetSizes](#setsizes) ou [CMFCToolBar::SetLockedSizes](#setlockedsizes) para definir as dimensões de cada botão na barra de ferramentas.  
  
##  <a name="a-namegetbuttonstylea--cmfctoolbargetbuttonstyle"></a><a name="getbuttonstyle"></a>CMFCToolBar::GetButtonStyle  
 Retorna o estilo atual do botão da barra de ferramentas que está localizado no índice especificado.  
  
```  
UINT GetButtonStyle(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice de um botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que especifica o estilo do botão da barra de ferramentas. . Consulte [estilos de controle de barra de ferramentas](../../mfc/reference/toolbar-control-styles.md) para obter uma lista dos estilos possíveis.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CMFCToolBar::SetButtonStyle](#setbuttonstyle) para definir o estilo de botão da barra de ferramentas  
  
##  <a name="a-namegetbuttontexta--cmfctoolbargetbuttontext"></a><a name="getbuttontext"></a>CMFCToolBar::GetButtonText  
 Retorna o rótulo de texto de um botão que tem um índice especificado.  
  
```  
CString GetButtonText(int nIndex) const;  
  
void GetButtonText(
    int nIndex,  
    CString& rString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice de um botão da barra de ferramentas.  
  
 [out] `rString`  
 O texto do rótulo do botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 O texto do rótulo do botão da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CMFCToolBar::SetButtonText](#setbuttontext) ou [CMFCToolBar::SetToolBarBtnText](#settoolbarbtntext) para definir o rótulo de texto.  
  
##  <a name="a-namegetcoldimagesa--cmfctoolbargetcoldimages"></a><a name="getcoldimages"></a>CMFCToolBar::GetColdImages  
 Retorna um ponteiro para a coleção de imagens de botão da barra de ferramentas frio no aplicativo.  
  
```  
static CMFCToolBarImages* GetColdImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens de botão da barra de ferramentas frio.  
  
### <a name="remarks"></a>Comentários  
 Imagens COLD são as imagens que são usadas quando o usuário não está interagindo com os botões da barra de ferramentas. Chamar [CMFCToolBar::LoadBitmapEx](#loadbitmapex) ou [CMFCToolBar::LoadBitmap](#loadbitmap) para carregar as imagens frios.  
  
##  <a name="a-namegetcolumnwidtha--cmfctoolbargetcolumnwidth"></a><a name="getcolumnwidth"></a>CMFCToolBar::GetColumnWidth  
 Retorna a largura da barra de ferramentas.  
  
```  
virtual int GetColumnWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que especifica a largura dos botões da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para calcular o layout da barra de ferramentas. Substitua esse método em uma classe derivada para especificar uma largura de coluna diferente para sua barra de ferramentas.  
  
##  <a name="a-namegetcommandbuttonsa--cmfctoolbargetcommandbuttons"></a><a name="getcommandbuttons"></a>CMFCToolBar::GetCommandButtons  
 Retorna uma lista de botões que têm uma ID de comando especificado de todas as barras de ferramentas do aplicativo.  
  
```  
static int GetCommandButtons(
    UINT uiCmd,  
    CObList& listButtons);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID de comando dos botões.  
  
 [out] `listButtons`  
 Uma referência a um [CObList classe](../../mfc/reference/coblist-class.md) objeto que recebe a lista de botões da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de botões que têm a ID do comando especificado.  
  
##  <a name="a-namegetcounta--cmfctoolbargetcount"></a><a name="getcount"></a>CMFCToolBar::GetCount  
 Retorna o número de botões e separadores na barra de ferramentas.  
  
```  
int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de botões e separadores na barra de ferramentas.  
  
##  <a name="a-namegetcustomizebuttona--cmfctoolbargetcustomizebutton"></a><a name="getcustomizebutton"></a>CMFCToolBar::GetCustomizeButton  
 Recupera um ponteiro para o `CMFCCustomizeButton` objeto que está associado com a barra de ferramentas.  
  
```  
CMFCCustomizeButton* GetCustomizeButton();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CMFCCustomizeButton` objeto que está associado com a barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Esse método recupera o **personalizar** botão que aparece no final da barra de ferramentas. Use o [CMFCToolBar::EnableCustomizeButton](#enablecustomizebutton) para adicionar o **personalizar** botão à barra de ferramentas.  
  
 Você pode chamar o [CMFCToolBar::IsExistCustomizeButton](#isexistcustomizebutton) método para determinar se a barra de ferramentas contém válido `CMFCCustomizeButton` objeto.  
  
##  <a name="a-namegetdefaultimagea--cmfctoolbargetdefaultimage"></a><a name="getdefaultimage"></a>CMFCToolBar::GetDefaultImage  
 Retorna o índice da imagem padrão para um botão da barra de ferramentas com uma ID de comando especificado.  
  
```  
static int GetDefaultImage(UINT uiID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
 Especifica a ID de comando do botão.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice da imagem da barra de ferramentas na lista de imagens compartilhada.  
  
### <a name="remarks"></a>Comentários  
 Use este método compartilhado para recuperar o índice da imagem padrão para um botão da barra de ferramentas com a ID de comando especificado. O valor de retorno é um índice na coleção de imagens de botão da barra de ferramentas para todas as barras de ferramentas no aplicativo compartilhado. Chamar o [CMFCToolBar::GetImages](#getimages) método para obter um ponteiro para essa coleção.  
  
##  <a name="a-namegetdisabledimagesa--cmfctoolbargetdisabledimages"></a><a name="getdisabledimages"></a>CMFCToolBar::GetDisabledImages  
 Retorna um ponteiro para a coleção de imagens que são usadas para botões de barra de ferramentas desativado no aplicativo.  
  
```  
static CMFCToolBarImages* __stdcall GetDisabledImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens de botão da barra de ferramentas desativado.  
  
### <a name="remarks"></a>Comentários  
 Carregar as imagens do botão da barra de ferramentas desabilitado usando o [CMFCToolBarEditBoxButton classe](../../mfc/reference/cmfctoolbareditboxbutton-class.md) e [CMFCToolBar::LoadBitmap](#loadbitmap) métodos.  
  
##  <a name="a-namegetdisabledmenuimagesa--cmfctoolbargetdisabledmenuimages"></a><a name="getdisabledmenuimages"></a>CMFCToolBar::GetDisabledMenuImages  
 Retorna um ponteiro para a coleção de imagens que são usadas para os botões de menu desativado no aplicativo.  
  
```  
static CMFCToolBarImages* __stdcall GetDisabledMenuImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens de menu desativado.  
  
### <a name="remarks"></a>Comentários  
 Carregar as imagens desabilitadas usando o [CMFCToolBarEditBoxButton classe](../../mfc/reference/cmfctoolbareditboxbutton-class.md) método.  
  
##  <a name="a-namegetdroppeddownmenua--cmfctoolbargetdroppeddownmenu"></a><a name="getdroppeddownmenu"></a>CMFCToolBar::GetDroppedDownMenu  
 Recupera um ponteiro para o objeto de botão de menu que atualmente está exibindo o submenu correspondente.  
  
```  
CMFCToolBarMenuButton* GetDroppedDownMenu(int* pIndex = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `pIndex`  
 Recebe o índice do botão na coleção de botões de barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto de botão de menu que está exibindo o submenu correspondente ou `NULL` se nenhum menu estiver exibindo um submenu correspondente.  
  
### <a name="remarks"></a>Comentários  
 Se esse método retornar um não - `NULL` valor e `pIndex` não é `NULL`, o valor apontado por `pIndex` é definida para o índice do botão de menu na coleção de botões de barra de ferramentas.  
  
##  <a name="a-namegetgraydisabledbuttonsa--cmfctoolbargetgraydisabledbuttons"></a><a name="getgraydisabledbuttons"></a>CMFCToolBar::GetGrayDisabledButtons  
 Especifica se as imagens de botões desabilitados são esmaecidas versões das imagens button normal, ou da coleção de imagens de botões desabilitados.  
  
```  
BOOL GetGrayDisabledButtons() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`para esmaecer as imagens de botões desabilitados; `FALSE`para obter imagens da coleção de imagens desabilitadas.  
  
### <a name="remarks"></a>Comentários  
 Use [CMFCToolBar::SetGrayDisabledButtons](#setgraydisabledbuttons) para alternar entre imagens esmaecidas e as imagens da coleção de imagens desabilitadas.  
  
##  <a name="a-namegethighlightedbuttona--cmfctoolbargethighlightedbutton"></a><a name="gethighlightedbutton"></a>CMFCToolBar::GetHighlightedButton  
 Retorna um ponteiro para o botão de barra de ferramentas está realçado no momento.  
  
```  
CMFCToolBarButton* GetHighlightedButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um objeto de botão da barra de ferramentas; ou `NULL` se nenhum botão é realçado.  
  
### <a name="remarks"></a>Comentários  
 Um botão de barra de ferramentas é realçado se ele tem o foco do teclado. Um botão de barra de ferramentas também é realçado se os botões da barra de ferramentas são hot rastreados neste aplicativo (para obter mais informações, consulte [CMFCToolBar::GetHotBorder](#gethotborder) e [CMFCToolBar::SetHotBorder](#sethotborder)) e o mouse está apontando, quando nenhum botão ou item de menu tem o foco do teclado.  
  
##  <a name="a-namegethotbordera--cmfctoolbargethotborder"></a><a name="gethotborder"></a>CMFCToolBar::GetHotBorder  
 Determina se os botões da barra de ferramentas são *controlados hot*. Se um botão de controle de acesso, ele é realçado quando o mouse se move sobre ele.  
  
```  
BOOL GetHotBorder() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se os botões da barra de ferramentas são rastreados quente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, os botões de barra de ferramentas são rastreados quente.  
  
##  <a name="a-namegethottextcolora--cmfctoolbargethottextcolor"></a><a name="gethottextcolor"></a>CMFCToolBar::GetHotTextColor  
 Retorna a cor do texto dos botões da barra de ferramentas realçado.  
  
```  
static COLORREF GetHotTextColor();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que representam a cor do texto realçado.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CMFCToolBar::SetHotTextColor](#sethottextcolor) para definir uma nova cor de texto para botões da barra de destaque.  
  
##  <a name="a-namegethwndlastfocusa--cmfctoolbargethwndlastfocus"></a><a name="gethwndlastfocus"></a>CMFCToolBar::GetHwndLastFocus  
 Retorna um identificador para a janela que tinha o foco de entrada antes que a barra de ferramentas.  
  
```  
HWND GetHwndLastFocus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de janela que não é derivada de [CMFCBaseToolBar classe](../../mfc/reference/cmfcbasetoolbar-class.md), que anteriormente tinha o foco de entrada; ou `NULL` se não houver nenhuma janela.  
  
### <a name="remarks"></a>Comentários  
 Quando um `CMFCToolBar` controle recebe o foco de entrada, ele armazena um identificador para a janela que perdeu o foco para que ele poderá restaurá-lo mais tarde.  
  
##  <a name="a-namegetignoresettexta--cmfctoolbargetignoresettext"></a><a name="getignoresettext"></a>CMFCToolBar::GetIgnoreSetText  
 Especifica se as chamadas para definir rótulos de botões são ignoradas.  
  
```  
BOOL GetIgnoreSetText() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se chamadas para definir rótulos de botões são ignoradas; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetimagesa--cmfctoolbargetimages"></a><a name="getimages"></a>CMFCToolBar::GetImages  
 Retorna um ponteiro para a coleção de padrão imagens de botão no aplicativo.  
  
```  
static CMFCToolBarImages* GetImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CMFCToolBarImages classe](../../mfc/reference/cmfctoolbarimages-class.md) objeto que contém a coleção de imagens padrão para todas as barras de ferramentas do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Esse método compartilhado fornece acesso à coleção de padrão de todas as imagens da barra de ferramentas para o aplicativo. Chamar o [CMFCToolBar::LoadBitmap](#loadbitmap) para adicionar imagens à coleção.  
  
##  <a name="a-namegetimagesizea--cmfctoolbargetimagesize"></a><a name="getimagesize"></a>CMFCToolBar::GetImageSize  
 Retorna o tamanho atual de imagens de botão da barra de ferramentas.  
  
```  
CSize GetImageSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CSize classe](../../atl-mfc-shared/reference/csize-class.md) objeto que representa o tamanho atual de imagens de botão da barra de ferramentas.  
  
##  <a name="a-namegetimagesoffseta--cmfctoolbargetimagesoffset"></a><a name="getimagesoffset"></a>CMFCToolBar::GetImagesOffset  
 Retorna o deslocamento de índice usado para localizar imagens de botão de barra de ferramentas para essa barra de ferramentas da lista global de imagens de botão da barra de ferramentas.  
  
```  
int GetImagesOffset() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O deslocamento de índice das imagens da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Todas as imagens de padrão de barra de ferramentas são armazenadas no global [CMFCToolBarImages classe](../../mfc/reference/cmfctoolbarimages-class.md) lista. As imagens para cada botão na barra de ferramentas são armazenadas consecutivamente nessa lista. Para calcular o índice da imagem, adicione o índice do botão na barra de ferramentas para o deslocamento do início da lista de imagens para um botão da barra de ferramentas.  
  
 Chamar [CMFCToolBar::ButtonToIndex](#buttontoindex) para obter o índice de um botão de barra de ferramentas, dado um ponteiro para o botão.  
  
 Chamar [CMFCToolBar::GetImages](#getimages) para obter um ponteiro para a coleção de imagens da barra de ferramentas.  
  
##  <a name="a-namegetinvalidateitemrecta--cmfctoolbargetinvalidateitemrect"></a><a name="getinvalidateitemrect"></a>CMFCToolBar::GetInvalidateItemRect  
 Recupera a região da área do cliente que precisa ser redesenhada do botão no índice especificado.  
  
```  
virtual void GetInvalidateItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice do botão para o qual recuperar a área do cliente.  
  
 [out] `lpRect`  
 Um ponteiro para um `RECT` objeto que recebe a região da área do cliente.  
  
### <a name="remarks"></a>Comentários  
 O `lpRect` parâmetro não deve ser `NULL`. Se nenhum botão existe no índice fornecido, `lpRect` recebe uma `RECT` objeto que é inicializado com zero.  
  
##  <a name="a-namegetitemida--cmfctoolbargetitemid"></a><a name="getitemid"></a>CMFCToolBar::GetItemID  
 Retorna a ID de comando do botão da barra de ferramentas em um índice especificado.  
  
```  
UINT GetItemID(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice do botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de comando do botão da barra de ferramentas; ou zero se o botão com o índice especificado não existe.  
  
##  <a name="a-namegetitemrecta--cmfctoolbargetitemrect"></a><a name="getitemrect"></a>CMFCToolBar::GetItemRect  
 Retorna o retângulo delimitador do botão em um índice especificado.  
  
```  
virtual void GetItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice de um botão da barra de ferramentas.  
  
 [out] `lpRect`  
 Um ponteiro para `CRect` objeto que recebe as coordenadas da imagem delimitadora retângulo.  
  
### <a name="remarks"></a>Comentários  
 O `CRect` objeto ao qual `lpRect` pontos é definido como 0 se não existir um botão no índice especificado.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `GetItemRect` método o `CMFCToolBar` classe. Este trecho de código é parte do [exemplo IE demonstração](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo n º&6;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_1.h)]  
[!code-cpp[NVC_MFC_IEDemo n º&9;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_4.cpp)]  
  
##  <a name="a-namegetlargecoldimagesa--cmfctoolbargetlargecoldimages"></a><a name="getlargecoldimages"></a>CMFCToolBar::GetLargeColdImages  
 Retorna um ponteiro para a coleção de imagens de botão da barra de ferramentas frio grandes no aplicativo.  
  
```  
static CMFCToolBarImages* GetLargeColdImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens frios grandes.  
  
### <a name="remarks"></a>Comentários  
 Imagens COLD são as imagens que são usadas quando o usuário não está interagindo com os botões da barra de ferramentas. Chamar [CMFCToolBar::LoadBitmapEx](#loadbitmapex) para carregar as imagens frios grandes.  
  
##  <a name="a-namegetlargedisabledimagesa--cmfctoolbargetlargedisabledimages"></a><a name="getlargedisabledimages"></a>CMFCToolBar::GetLargeDisabledImages  
 Retorna um ponteiro para a coleção de imagens de botão grande ferramentas desabilitado no aplicativo.  
  
```  
static CMFCToolBarImages* GetLargeDisabledImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de grande desabilitado imagens de botão da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Imagens grandes são grandes versões das imagens de botão de barra de ferramentas normais. Chamar [CMFCToolBar::LoadBitmapEx](#loadbitmapex) ou [CMFCToolBar::LoadBitmap](#loadbitmap) para carregar as imagens grandes.  
  
##  <a name="a-namegetlargeimagesa--cmfctoolbargetlargeimages"></a><a name="getlargeimages"></a>CMFCToolBar::GetLargeImages  
 Retorna um ponteiro para a coleção de imagens de botão da barra de ferramentas grandes no aplicativo.  
  
```  
static CMFCToolBarImages* GetLargeImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens de botão da barra de ferramentas grande.  
  
### <a name="remarks"></a>Comentários  
 Imagens grandes são grandes versões das imagens de botão de barra de ferramentas normais. Chamar [CMFCToolBar::LoadBitmapEx](#loadbitmapex) para carregar as imagens grandes.  
  
##  <a name="a-namegetlockedcoldimagesa--cmfctoolbargetlockedcoldimages"></a><a name="getlockedcoldimages"></a>CMFCToolBar::GetLockedColdImages  
 Retorna um ponteiro para a coleção de imagens frios bloqueadas na barra de ferramentas.  
  
```  
CMFCToolBarImages* GetLockedColdImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens frios bloqueadas, ou `NULL` se a barra de ferramentas não está bloqueada.  
  
### <a name="remarks"></a>Comentários  
 Imagens bloqueadas são versões das imagens de botão de barra de ferramentas normais que a estrutura usa quando o usuário não é possível personalizar a barra de ferramentas. Imagens COLD são as imagens que são usadas quando o usuário não está interagindo com os botões da barra de ferramentas.  
  
 Esse método retorna `NULL` se a barra de ferramentas não está bloqueada. Esse método também gera uma falha de asserção em compilações de depuração se a barra de ferramentas não está bloqueada. Para obter mais informações sobre barras de ferramentas bloqueadas, consulte [CMFCToolBar::IsLocked](#islocked).  
  
 Chamar o [CMFCToolBar::LoadBitmapEx](#loadbitmapex) método para carregar as imagens frios bloqueadas.  
  
##  <a name="a-namegetlockeddisabledimagesa--cmfctoolbargetlockeddisabledimages"></a><a name="getlockeddisabledimages"></a>CMFCToolBar::GetLockedDisabledImages  
 Retorna um ponteiro para a coleção de imagens desabilitadas bloqueadas na barra de ferramentas.  
  
```  
CMFCToolBarImages* GetLockedDisabledImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens desabilitadas bloqueadas, ou `NULL` se a barra de ferramentas não está bloqueada.  
  
### <a name="remarks"></a>Comentários  
 Imagens bloqueadas são versões das imagens de botão de barra de ferramentas normais que a estrutura usa quando o usuário não é possível personalizar a barra de ferramentas. Imagens desabilitadas são as imagens que a estrutura usa quando um botão tem o `TBBS_DISABLED` estilo.  
  
 Esse método retorna `NULL` se a barra de ferramentas não está bloqueada. Esse método também gera uma falha de asserção em compilações de depuração se a barra de ferramentas não está bloqueada. Para obter mais informações sobre barras de ferramentas bloqueadas, consulte [CMFCToolBar::IsLocked](#islocked).  
  
 Chamar o [CMFCToolBar::LoadBitmapEx](#loadbitmapex) método para carregar o bloqueado desabilitado imagens.  
  
##  <a name="a-namegetlockedimagesa--cmfctoolbargetlockedimages"></a><a name="getlockedimages"></a>CMFCToolBar::GetLockedImages  
 Retorna um ponteiro para a coleção de imagens de botão bloqueados na barra de ferramentas.  
  
```  
CMFCToolBarImages* GetLockedImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens de botão de barra de ferramentas bloqueadas ou `NULL` se a barra de ferramentas não está bloqueada.  
  
### <a name="remarks"></a>Comentários  
 Imagens bloqueadas são versões das imagens de botão de barra de ferramentas normais que a estrutura usa quando o usuário não é possível personalizar a barra de ferramentas.  
  
 Esse método retorna `NULL` se a barra de ferramentas não está bloqueada. Esse método também gera uma falha de asserção em compilações de depuração se a barra de ferramentas não está bloqueada. Para obter mais informações sobre barras de ferramentas bloqueadas, consulte [CMFCToolBar::IsLocked](#islocked).  
  
##  <a name="a-namegetlockedimagesizea--cmfctoolbargetlockedimagesize"></a><a name="getlockedimagesize"></a>CMFCToolBar::GetLockedImageSize  
 Retorna o tamanho padrão das imagens bloqueado da barra de ferramentas.  
  
```  
CSize GetLockedImageSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A `CSize` estrutura que especifica o tamanho das imagens de barra de ferramentas bloqueadas ou vazio `CSize` estrutura se a barra de ferramentas não está bloqueada.  
  
### <a name="remarks"></a>Comentários  
 Imagens bloqueadas são versões das imagens de botão de barra de ferramentas normais que a estrutura usa quando o usuário não é possível personalizar a barra de ferramentas.  
  
 Esse método retorna um `CSize` estrutura com tamanho zero e de largura zero se a barra de ferramentas não está bloqueada. Esse método também gera uma falha de asserção em compilações de depuração se a barra de ferramentas não está bloqueada. Para obter mais informações sobre barras de ferramentas bloqueadas, consulte [CMFCToolBar::IsLocked](#islocked).  
  
 Chamar o [CMFCToolBar::SetLockedSizes](#setlockedsizes) método para especificar o tamanho da imagem travada.  
  
##  <a name="a-namegetlockedmenuimagesa--cmfctoolbargetlockedmenuimages"></a><a name="getlockedmenuimages"></a>CMFCToolBar::GetLockedMenuImages  
 Retorna um ponteiro para a coleção de ferramentas bloqueada imagens de menu na barra de ferramentas.  
  
```  
CMFCToolBarImages* GetLockedMenuImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens do menu Ferramentas bloqueados, ou `NULL` se a barra de ferramentas não está bloqueada.  
  
### <a name="remarks"></a>Comentários  
 Imagens bloqueadas são versões das imagens do menu Ferramentas regular que a estrutura usa quando o usuário não é possível personalizar a barra de ferramentas.  
  
 Esse método retorna `NULL` se a barra de ferramentas não está bloqueada. Esse método também gera uma falha de asserção em compilações de depuração se a barra de ferramentas não está bloqueada. Para obter mais informações sobre barras de ferramentas bloqueadas, consulte [CMFCToolBar::IsLocked](#islocked).  
  
 Chamar o [CMFCToolBar::LoadBitmapEx](#loadbitmapex) método para carregar as imagens do menu bloqueado.  
  
##  <a name="a-namegetmenubuttonsizea--cmfctoolbargetmenubuttonsize"></a><a name="getmenubuttonsize"></a>CMFCToolBar::GetMenuButtonSize  
 Retorna o tamanho dos botões de menu do aplicativo.  
  
```  
static CSize GetMenuButtonSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que representa o tamanho dos botões de menu, em pixels.  
  
### <a name="remarks"></a>Comentários  
 O tamanho dos botões de menu nas barras de ferramentas é mantido como uma variável global e pode ser recuperado por esse método estático.  
  
 Chamar [CMFCToolBar::SetMenuSizes](#setmenusizes) para definir essa variável global.  
  
##  <a name="a-namegetmenuimagesa--cmfctoolbargetmenuimages"></a><a name="getmenuimages"></a>CMFCToolBar::GetMenuImages  
 Retorna um ponteiro para a coleção de imagens de botão de menu do aplicativo.  
  
```  
static CMFCToolBarImages* GetMenuImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens do menu.  
  
### <a name="remarks"></a>Comentários  
 Chamar o [CMFCToolBar::LoadBitmapEx](#loadbitmapex) método para carregar as imagens do menu.  
  
 Chamar o [CMFCToolBar::SetMenuSizes](#setmenusizes) método para definir o tamanho dos botões e suas imagens.  
  
##  <a name="a-namegetmenuimagesizea--cmfctoolbargetmenuimagesize"></a><a name="getmenuimagesize"></a>CMFCToolBar::GetMenuImageSize  
 Retorna o tamanho das imagens de botão de menu do aplicativo.  
  
```  
static CSize GetMenuImageSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que representa o tamanho das imagens de menu.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna o tamanho das imagens nos botões de menu da barra de ferramentas que é mantida como uma variável global. Chamar [CMFCToolBar::SetMenuSizes](#setmenusizes) para definir essa variável global.  
  
##  <a name="a-namegetorigbuttonsa--cmfctoolbargetorigbuttons"></a><a name="getorigbuttons"></a>CMFCToolBar::GetOrigButtons  
 Recupera a coleção de botões não personalizado da barra de ferramentas.  
  
```  
const CObList& GetOrigButtons() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a lista de botões não personalizado da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 O framework cria uma cópia dos botões da barra de ferramentas antes de eles são personalizados pelo usuário. O [CMFCToolBar::SetButtons](#setbuttons) método adiciona uma cópia de cada botão na matriz fornecida para a lista de botões originais. O [CMFCToolBar::RestoreOriginalState](#restoreoriginalstate) método restaura o estado original da barra de ferramentas, carregá-lo ao arquivo de recurso.  
  
 Para definir a lista de botões originais para sua barra de ferramentas, chame o [CMFCToolBar::SetOrigButtons](#setorigbuttons) método.  
  
##  <a name="a-namegetorigresetbuttonsa--cmfctoolbargetorigresetbuttons"></a><a name="getorigresetbuttons"></a>CMFCToolBar::GetOrigResetButtons  
 Recupera a coleção de redefinição não personalizada botões da barra de ferramentas.  
  
```  
const CObList& GetOrigResetButtons() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a lista de botões de redefinição não personalizado da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário clica o **redefinir** botão durante o modo de personalização, a estrutura usa esse método para restaurar os botões que foram removidos da barra de ferramentas.  
  
 O [CMFCToolBar::SetButtons](#setbuttons) método adiciona uma cópia de cada botão da barra de ferramentas para a lista de botões de redefinição original depois de chamar o [CMFCToolBar::OnReset](#onreset) método. Você pode substituir o [CMFCToolBar::OnReset](#onreset) método para personalizar a aparência dos botões após o usuário pressiona o **redefinir** botão.  
  
##  <a name="a-namegetresourceida--cmfctoolbargetresourceid"></a><a name="getresourceid"></a>CMFCToolBar::GetResourceID  
 Recupera a ID de recurso da barra de ferramentas.  
  
```  
UINT GetResourceID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de recurso da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Chamar o [CMFCToolBar::LoadToolBarEx](#loadtoolbarex) método para definir a ID de recurso da barra de ferramentas.  
  
##  <a name="a-namegetroutecommandsviaframea--cmfctoolbargetroutecommandsviaframe"></a><a name="getroutecommandsviaframe"></a>CMFCToolBar::GetRouteCommandsViaFrame  
 Determina qual objeto, quadro principal ou o proprietário, envia comandos para a barra de ferramentas.  
  
```  
BOOL GetRouteCommandsViaFrame();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o quadro principal envia comandos para a barra de ferramentas. 0 se o proprietário envia comandos para a barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o quadro principal envia comandos para a barra de ferramentas. Chamar [CMFCToolBar::SetRouteCommandsViaFrame](#setroutecommandsviaframe) para alterar esse comportamento.  
  
 Se esse método retorna um valor diferente de zero, você pode recuperar um ponteiro para o objeto de quadro pai usando o `CMFCToolBar::GetCommandTarget` método. Consulte o exemplo VisualStudioDemo para obter um exemplo que usa esse método.  
  
##  <a name="a-namegetrowheighta--cmfctoolbargetrowheight"></a><a name="getrowheight"></a>CMFCToolBar::GetRowHeight  
 Retorna a altura dos botões da barra de ferramentas.  
  
```  
virtual int GetRowHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura dos botões de barra de ferramentas, em pixels.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para calcular o layout da barra de ferramentas. Substitua esse método em uma classe derivada para especificar uma altura diferente para sua barra de ferramentas.  
  
##  <a name="a-namegetshowtooltipsa--cmfctoolbargetshowtooltips"></a><a name="getshowtooltips"></a>CMFCToolBar::GetShowTooltips  
 Especifica se as dicas de ferramenta são exibidas para os botões da barra de ferramentas.  
  
```  
static BOOL GetShowTooltips();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as dicas de ferramenta são mostradas para botões da barra de ferramentas; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, as dicas de ferramenta são mostradas. Você pode alterar esse sinalizador estático chamando [CMFCToolBar::SetShowTooltips](#setshowtooltips).  
  
##  <a name="a-namegetsiblingtoolbara--cmfctoolbargetsiblingtoolbar"></a><a name="getsiblingtoolbar"></a>CMFCToolBar::GetSiblingToolBar  
 Recupera o irmão da barra de ferramentas.  
  
```  
CMFCToolBar* GetSiblingToolBar();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a barra de ferramentas do irmão.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre como habilitar o **Mostrar botões em uma linha** e **Mostrar botões em duas linhas** botões, consulte [CMFCToolBar::SetSiblingToolBar](#setsiblingtoolbar).  
  
##  <a name="a-namegetuserimagesa--cmfctoolbargetuserimages"></a><a name="getuserimages"></a>CMFCToolBar::GetUserImages  
 Retorna um ponteiro para a coleção de imagens de botão da barra de ferramentas definidas pelo usuário no aplicativo.  
  
```  
static CMFCToolBarImages* GetUserImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a coleção de imagens de botão da barra de ferramentas definidas pelo usuário para todas as barras de ferramentas do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Chamar o [CMFCToolBar::SetUserImages](#setuserimages) método para definir o conjunto de imagens definidas pelo usuário no aplicativo.  
  
##  <a name="a-namehittesta--cmfctoolbarhittest"></a><a name="hittest"></a>CMFCToolBar::HitTest  
 Retorna o índice do botão da barra de ferramentas que está localizado na posição especificada.  
  
```  
virtual int HitTest(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 O ponto a ser testada, nas coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do botão que está localizado na posição especificada, ou -1 se não houver nenhum esse botão ou é um separador.  
  
##  <a name="a-nameinsertbuttona--cmfctoolbarinsertbutton"></a><a name="insertbutton"></a>CMFCToolBar::InsertButton  
 Insere um botão na barra de ferramentas.  
  
```  
virtual int InsertButton(
    const CMFCToolBarButton& button,  
    INT_PTR iInsertAt=-1);

 
virtual int InsertButton(
    CMFCToolBarButton* pButton,  
    int iInsertAt=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `button`  
 Especifica o botão Inserir.  
  
 [in] `iInsertAt`  
 Especifica a posição baseada em zero para inserir o botão no.  
  
### <a name="return-value"></a>Valor de retorno  
 A posição em que o botão foi inserido ou -1 se um erro ocorre.  
  
### <a name="remarks"></a>Comentários  
 Se `iInsertAt` é -1, este método adiciona o botão ao final da lista de botões da barra de ferramentas.  
  
 Chamar o [CMFCToolBar::InsertSeparator](#insertseparator) método para inserir um separador de barra de ferramentas.  
  
##  <a name="a-nameinsertseparatora--cmfctoolbarinsertseparator"></a><a name="insertseparator"></a>CMFCToolBar::InsertSeparator  
 Insere um separador de barra de ferramentas.  
  
```  
virtual int InsertSeparator(INT_PTR iInsertAt=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iInsertAt`  
 Especifica a posição de base zero para inserir o separador em. Esse parâmetro deve ser maior que 0.  
  
### <a name="return-value"></a>Valor de retorno  
 A posição em que o separador foi inserido ou -1 se um erro ocorre.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para inserir um separador entre dois botões existentes. Se `iInsertAt` é -1, este método adiciona o separador no final da lista de botões da barra de ferramentas.  
  
 Você não pode usar esse método para adicionar um separador de uma barra de ferramentas vazia.  
  
 Chamar o [CMFCToolBar::InsertButton](#insertbutton) método para inserir um botão na barra de ferramentas.  
  
##  <a name="a-nameinvalidatebuttona--cmfctoolbarinvalidatebutton"></a><a name="invalidatebutton"></a>CMFCToolBar::InvalidateButton  
 Invalida a área do cliente do botão da barra de ferramentas que existe no índice fornecido.  
  
```  
CMFCToolBarButton* InvalidateButton(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice baseado em zero do botão na barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `CMFCToolBarButton` objeto existe no índice fornecido ou `NULL` se esse objeto não existe.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele atualiza a área do cliente que está associada um botão da barra de ferramentas. Ele chama o [CWnd::InvalidateRect](../../mfc/reference/cwnd-class.md#invalidaterect) método com o retângulo do cliente do `CMFCToolBarButton` objeto existe no índice fornecido.  
  
##  <a name="a-nameisaddremovequickcustomizea--cmfctoolbarisaddremovequickcustomize"></a><a name="isaddremovequickcustomize"></a>CMFCToolBar::IsAddRemoveQuickCustomize  
 Determina se um usuário pode adicionar ou remover botões da barra de ferramentas usando o **personalizar** opção de menu.  
  
```  
BOOL IsAddRemoveQuickCustomize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se um usuário pode usar o **personalizar** opção de menu para modificar a barra de ferramentas; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisaltcustomizemodea--cmfctoolbarisaltcustomizemode"></a><a name="isaltcustomizemode"></a>CMFCToolBar::IsAltCustomizeMode  
 Especifica se *personalização rápida* está sendo usada para arrastar um botão. Quando a personalização rápida está habilitada, um usuário pode pressione e segure a tecla Alt e arrastar um botão para um novo local.  
  
```  
static BOOL __stdcall IsAltCustomizeMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a personalização rápida está sendo usada para arrastar um botão; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisautograyinactiveimagesa--cmfctoolbarisautograyinactiveimages"></a><a name="isautograyinactiveimages"></a>CMFCToolBar::IsAutoGrayInactiveImages  
 Especifica se a geração automática de imagens de botão inativo (não realçada) está habilitada.  
  
```  
static BOOL IsAutoGrayInactiveImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a opção automaticamente esmaecer imagens inativas estiver habilitada; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Você pode habilitar ou desabilitar o esmaecimento automática de imagens inativas chamando [CMFCToolBar::AutoGrayInactiveImages](#autograyinactiveimages).  
  
##  <a name="a-nameisbasiccommanda--cmfctoolbarisbasiccommand"></a><a name="isbasiccommand"></a>CMFCToolBar::IsBasicCommand  
 Determina se um comando está na lista de comandos básicos.  
  
```  
static BOOL IsBasicCommand(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 Especifica o comando para verificar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o comando especificado pertence à lista de comandos básicos; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método estático determina se o comando especificado por `uiCmd` pertence à lista global de comandos básicos. Você pode alterar a lista de comandos básicos chamando [CMFCToolBar::AddBasicCommand](#addbasiccommand) ou [CMFCToolBar::SetBasicCommands](#setbasiccommands).  
  
##  <a name="a-nameisbuttonextrasizeavailablea--cmfctoolbarisbuttonextrasizeavailable"></a><a name="isbuttonextrasizeavailable"></a>CMFCToolBar::IsButtonExtraSizeAvailable  
 Determina se a barra de ferramentas pode exibir botões que tem estendido bordas.  
  
```  
virtual BOOL IsButtonExtraSizeAvailable() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra pode exibir botões com o tamanho da borda extra; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Retorna o objeto de barra de ferramentas `TRUE` se ele pode exibir botões que tem estendido bordas. Um botão chama esse método quando ele lida com a [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd) notificação e definirá o sinalizador de tamanho extra de borda interna adequadamente. Esse sinalizador interno pode ser recuperada posteriormente chamando [CMFCToolBarButton::IsExtraSize](../../mfc/reference/cmfctoolbarbutton-class.md#isextrasize).  
  
 Substitua esse método em uma classe derivada de `CMFCToolBar` e retornar `TRUE` se a barra pode exibir os botões da barra de ferramentas com o tamanho da borda extras e retornar `FALSE` caso contrário. Retorna a implementação padrão `TRUE`.  
  
##  <a name="a-nameisbuttonhighlighteda--cmfctoolbarisbuttonhighlighted"></a><a name="isbuttonhighlighted"></a>CMFCToolBar::IsButtonHighlighted  
 Determina se o botão especificado é realçado.  
  
```  
BOOL IsButtonHighlighted(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iButton`  
 Especifica o índice de um botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão especificado é realçado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameiscommandpermitteda--cmfctoolbariscommandpermitted"></a><a name="iscommandpermitted"></a>CMFCToolBar::IsCommandPermitted  
 Determina se um comando é permitido.  
  
```  
static BOOL IsCommandPermitted(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 Especifica o comando para verificar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o comando especificado é permitido; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método estático determina se o comando especificado por `uiCmd` pertence à lista global de comandos não permitido.  
  
 Você pode alterar a lista de comandos não permitido chamando [CMFCToolBar::SetNonPermittedCommands](#setnonpermittedcommands).  
  
##  <a name="a-nameiscommandrarelyuseda--cmfctoolbariscommandrarelyused"></a><a name="iscommandrarelyused"></a>CMFCToolBar::IsCommandRarelyUsed  
 Determina se um comando raramente é usado.  
  
```  
static BOOL IsCommandRarelyUsed(UINT uiCmd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 Especifica o comando para verificar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o comando especificado raramente é usado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O `IsCommandRarelyUsed` método retorna `FALSE` quando um ou mais das seguintes condições ocorrer:  
  
-   O comando especificado pertence à lista de comandos básicos  
  
-   O comando especificado é um dos comandos padrão  
  
-   O framework está em modo de personalização  
  
-   A lista de comandos está vazia  
  
-   Mais de 20% das chamadas de comando são chamadas para o comando especificado.  
  
##  <a name="a-nameiscustomizemodea--cmfctoolbariscustomizemode"></a><a name="iscustomizemode"></a>CMFCToolBar::IsCustomizeMode  
 Especifica se a estrutura da barra de ferramentas está no modo de personalização.  
  
```  
static BOOL IsCustomizeMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o framework estiver no modo de personalização. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Você pode alternar o modo de personalização, chamando [CMFCToolBar::SetCustomizeMode](#setcustomizemode).  
  
 O framework altera o modo quando o usuário invoca a caixa de diálogo de personalização ( [CMFCToolBarsCustomizeDialog classe](../../mfc/reference/cmfctoolbarscustomizedialog-class.md)).  
  
##  <a name="a-nameisdragbuttona--cmfctoolbarisdragbutton"></a><a name="isdragbutton"></a>CMFCToolBar::IsDragButton  
 Determina se um botão de barra de ferramentas está sendo arrastado.  
  
```  
BOOL IsDragButton(const CMFCToolBarButton* pButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Ponteiro para um botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão especificado está sendo arrastado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisexistcustomizebuttona--cmfctoolbarisexistcustomizebutton"></a><a name="isexistcustomizebutton"></a>CMFCToolBar::IsExistCustomizeButton  
 Determina se a barra de ferramentas contém o **personalizar** botão.  
  
```  
BOOL IsExistCustomizeButton();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas contém o **personalizar** botão; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se esse método retornar `TRUE`, o [CMFCToolBar::GetCustomizeButton](#getcustomizebutton) método retorna um ponteiro para o **personalizar** botão que aparece no final da barra de ferramentas.  
  
 Use o [CMFCToolBar::EnableCustomizeButton](#enablecustomizebutton) para adicionar o **personalizar** botão à barra de ferramentas.  
  
##  <a name="a-nameisfloatinga--cmfctoolbarisfloating"></a><a name="isfloating"></a>CMFCToolBar::IsFloating  
 Determina se a barra de ferramentas é flutuante.  
  
```  
virtual BOOL IsFloating() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas estiver flutuando; Caso contrário, `FALSE`.  
  
##  <a name="a-nameislargeiconsa--cmfctoolbarislargeicons"></a><a name="islargeicons"></a>CMFCToolBar::IsLargeIcons  
 Especifica se as barras de ferramentas no aplicativo atualmente exibem ícones grandes.  
  
```  
static BOOL IsLargeIcons();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o aplicativo está usando ícones grandes; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CMFCToolBar::SetLargeIcons](#setlargeicons) para alternar entre os ícones grandes ícones regulares.  
  
 O framework altera o modo automaticamente quando o usuário alterna o **ícones grandes** caixa de seleção no **opções** página do **personalização** caixa de diálogo.  
  
##  <a name="a-nameislastcommandfrombuttona--cmfctoolbarislastcommandfrombutton"></a><a name="islastcommandfrombutton"></a>CMFCToolBar::IsLastCommandFromButton  
 Determina se executado o último comando foi enviado a partir do botão de barra de ferramentas especificada.  
  
```  
static BOOL IsLastCommandFromButton(CMFCToolBarButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Ponteiro para o botão.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o último comando foi enviado a partir do botão que `pButton` Especifica; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método obtém um ponteiro para um [estrutura MSG](../../mfc/reference/msg-structure1.md) chamando `CWnd::GetCurrentMessage`. Ele então compara o `HWND` do botão com o `MSG::lParam` e `MSG::hwnd` membros para determinar se o botão foi a origem do comando.  
  
##  <a name="a-nameislockeda--cmfctoolbarislocked"></a><a name="islocked"></a>CMFCToolBar::IsLocked  
 Determina se a barra de ferramentas está bloqueada.  
  
```  
BOOL IsLocked() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas está bloqueada; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna `TRUE` quando o usuário não pode executar tarefas de personalização, como reposicionar os botões da barra de ferramentas.  
  
 Barras de ferramentas bloqueadas usam listas de imagens separadas. Para obter mais informações sobre essas listas de imagens, consulte [CMFCToolBar::LoadBitmapEx](#loadbitmapex).  
  
##  <a name="a-nameisonerowwithsiblinga--cmfctoolbarisonerowwithsibling"></a><a name="isonerowwithsibling"></a>CMFCToolBar::IsOneRowWithSibling  
 Determina se a barra de ferramentas e barra de ferramentas seu irmão são posicionados na mesma linha.  
  
```  
BOOL IsOneRowWithSibling();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas e seu irmão são posicionados na mesma linha; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O [CMFCCustomizeButton::CreatePopupMenu](http://msdn.microsoft.com/en-us/e501083e-f78e-4d8d-900c-40bd6e2bb7f8) método chama esse método para determinar como exibir o **personalizar** menu pop-up. Se esse método retornar `TRUE`, exibe a estrutura de **Mostrar botões em uma linha** botão. Caso contrário, exibe a estrutura de **Mostrar botões em duas linhas** botão.  
  
 Normalmente, você não precisa usar esse método. Para habilitar o **Mostrar botões em uma linha** ou **Mostrar botões em duas linhas** botões, chame [CMFCToolBar::SetSiblingToolBar](#setsiblingtoolbar).  
  
##  <a name="a-nameisresourcechangeda--cmfctoolbarisresourcechanged"></a><a name="isresourcechanged"></a>CMFCToolBar::IsResourceChanged  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL IsResourceChanged() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameissiblinga--cmfctoolbarissibling"></a><a name="issibling"></a>CMFCToolBar::IsSibling  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsSibling();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisuserdefineda--cmfctoolbarisuserdefined"></a><a name="isuserdefined"></a>CMFCToolBar::IsUserDefined  
 Especifica se a barra de ferramentas é definida pelo usuário.  
  
```  
BOOL IsUserDefined() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas foi criada pelo usuário. Caso contrário, `FALSE`.  
  
##  <a name="a-nameloadbitmapa--cmfctoolbarloadbitmap"></a><a name="loadbitmap"></a>CMFCToolBar::LoadBitmap  
 Carrega imagens da barra de ferramentas de recursos do aplicativo.  
  
```  
virtual BOOL LoadBitmap(
    UINT uiResID,  
    UINT uiColdResID=0,  
    UINT uiMenuResID=0,  
    BOOL bLocked=FALSE,  
    UINT uiDisabledResID=0,  
    UINT uiMenuDisabledResID=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiResID`  
 A ID de recurso do bitmap que se refere às imagens de barra de ferramentas ativa.  
  
 [in] `uiColdResID`  
 A ID de recurso do bitmap que se refere às imagens de barra de ferramentas frio.  
  
 [in] `uiMenuResID`  
 A ID de recurso do bitmap que se refere às imagens do menu regular.  
  
 [in] `bLocked`  
 `TRUE`para bloquear a barra de ferramentas. Caso contrário, `FALSE`.  
  
 [in] `uiDisabledResID`  
 A ID de recurso do bitmap que se refere às imagens de barra de ferramentas desativado.  
  
 [in] `uiMenuDisabledResID`  
 A ID de recurso do bitmap que se refere às imagens do menu desativado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O [CMFCToolBar::LoadToolBarEx](#loadtoolbarex) método chama esse método para carregar as imagens que estão associadas com a barra de ferramentas. Substitua este método para executar o carregamento personalizado de recursos de imagem.  
  
 Chamar o `LoadBitmapEx` método para carregar imagens adicionais depois de criar a barra de ferramentas.  
  
##  <a name="a-nameloadbitmapexa--cmfctoolbarloadbitmapex"></a><a name="loadbitmapex"></a>CMFCToolBar::LoadBitmapEx  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL LoadBitmapEx(
    CMFCToolBarInfo& params,  
    BOOL bLocked = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `params`  
 [in] `bLocked`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameloadlargeiconsstatea--cmfctoolbarloadlargeiconsstate"></a><a name="loadlargeiconsstate"></a>CMFCToolBar::LoadLargeIconsState  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static BOOL __stdcall LoadLargeIconsState(LPCTSTR lpszProfileName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameloadparametersa--cmfctoolbarloadparameters"></a><a name="loadparameters"></a>CMFCToolBar::LoadParameters  
 Carrega as opções de barra de ferramentas global do registro do Windows.  
  
```  
static BOOL LoadParameters(LPCTSTR lpszProfileName=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Especifica o caminho relativo da chave do registro do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método carrega parâmetros globais como o tipo de animação de menu, o menu de estilo de sombra e se deseja exibir ícones grandes do registro do Windows.  
  
 O [CWinAppEx::LoadState](../../mfc/reference/cwinappex-class.md#loadstate) método chama esse método como parte do processo de inicialização do aplicativo.  
  
##  <a name="a-nameloadstatea--cmfctoolbarloadstate"></a><a name="loadstate"></a>CMFCToolBar::LoadState  
 Carrega as informações de estado da barra de ferramentas do registro do Windows.  
  
```  
virtual BOOL LoadState(
    LPCTSTR lpszProfileName=NULL,  
    int nIndex=-1,  
    UINT uiID=(UINT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Especifica o caminho relativo da chave do registro do Windows.  
  
 [in] `nIndex`  
 Especifica a ID do controle da barra de ferramentas.  
  
 [in] `uiID`  
 Especifica a ID de recurso da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método como parte do processo de inicialização do aplicativo. Para obter mais informações, consulte [CWinAppEx::LoadState](../../mfc/reference/cwinappex-class.md#loadstate).  
  
##  <a name="a-nameloadtoolbara--cmfctoolbarloadtoolbar"></a><a name="loadtoolbar"></a>CMFCToolBar::LoadToolBar  
 Carrega a barra de ferramentas de recursos do aplicativo.  
  
```  
virtual BOOL LoadToolBar(
    UINT uiResID,  
    UINT uiColdResID=0,  
    UINT uiMenuResID=0,  
    BOOL bLocked=FALSE,  
    UINT uiDisabledResID=0,  
    UINT uiMenuDisabledResID=0,  
    UINT uiHotResID=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiResID`  
 A ID de recurso da barra de ferramentas.  
  
 [in] `uiColdResID`  
 A ID de recurso do bitmap que se refere às imagens de barra de ferramentas frio.  
  
 [in] `uiMenuResID`  
 A ID de recurso do bitmap que se refere às imagens do menu regular.  
  
 [in] `bLocked`  
 Um valor booleano que especifica se a barra de ferramentas está bloqueada ou não. Se esse parâmetro for `TRUE`, a barra de ferramentas está bloqueada. Caso contrário, a barra de ferramentas não está bloqueada.  
  
 [in] `uiDisabledResID`  
 A ID de recurso do bitmap que se refere às imagens de barra de ferramentas desativado.  
  
 [in] `uiMenuDisabledResID`  
 A ID de recurso do bitmap que se refere às imagens do menu desativado.  
  
 [in] `uiHotResID`  
 A ID de recurso do bitmap que se refere às imagens de barra de ferramentas ativa.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método durante a inicialização para carregar as imagens que estão associadas com a barra de ferramentas.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `LoadToolBar` método o `CMFCToolBar` classe. Este trecho de código é parte do [exemplo IE demonstração](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo n º&6;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_1.h)]  
[!code-cpp[NVC_MFC_IEDemo&#7;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_3.cpp)]  
  
##  <a name="a-nameloadtoolbarexa--cmfctoolbarloadtoolbarex"></a><a name="loadtoolbarex"></a>CMFCToolBar::LoadToolBarEx  
 Carrega a barra de ferramentas de recursos do aplicativo usando o `CMFCToolBarInfo` classe auxiliar para ativar o aplicativo para usar imagens grandes.  
  
```  
virtual BOOL LoadToolBarEx(
    UINT uiToolbarResID,  
    CMFCToolBarInfo& params,  
    BOOL bLocked=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiToolbarResID`  
 A ID de recurso da barra de ferramentas.  
  
 [in] `params`  
 Uma referência a um `CMFCToolBarInfo` objeto que contém o recurso IDs para as imagens da barra de ferramentas.  
  
 [in] `bLocked`  
 Um valor booleano que especifica se a barra de ferramentas está bloqueada ou não. Se esse parâmetro for `TRUE`, a barra de ferramentas está bloqueada. Caso contrário, a barra de ferramentas não está bloqueada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para carregar imagens da barra de ferramentas de recursos do aplicativo.  
  
##  <a name="a-namemdbllargeimageratioa--cmfctoolbarmdbllargeimageratio"></a><a name="m_dbllargeimageratio"></a>CMFCToolBar::m_dblLargeImageRatio  
 Especifica a proporção entre a dimensão (altura ou largura) de imagens grandes e a dimensão de imagens regulares.  
  
```  
AFX_IMPORT_DATA static double m_dblLargeImageRatio;  
```  
  
### <a name="remarks"></a>Comentários  
 A taxa padrão é 2. Você pode alterar esse valor para que as imagens de barra de ferramentas grande maior ou menor.  
  
 A estrutura usa esse membro de dados quando você não especificar um conjunto de imagens grandes. Por exemplo, se você fornece apenas o conjunto de imagens pequenas com tamanho de 16x16 e deseja que as imagens grandes para que o tamanho de 24 x 24, defina este membro de dados para 1.5.  
  
##  <a name="a-namenextmenua--cmfctoolbarnextmenu"></a><a name="nextmenu"></a>CMFCToolBar::NextMenu  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL NextMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonbeforeremovebuttona--cmfctoolbaronbeforeremovebutton"></a><a name="onbeforeremovebutton"></a>CMFCToolBar::OnBeforeRemoveButton  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnBeforeRemoveButton(
    CMFCToolBarButton* pButton,  
    DROPEFFECT dropEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Não utilizado.  
  
 [in] `dropEffect`  
 Não utilizado.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonchangehota--cmfctoolbaronchangehot"></a><a name="onchangehot"></a>CMFCToolBar::OnChangeHot  
 Chamado pela estrutura quando um usuário seleciona um botão na barra de ferramentas.  
  
```  
virtual void OnChangeHot(int iHot);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iHot`  
 Especifica o índice do botão da barra de ferramentas está selecionado. ou -1 se nenhum botão da barra de ferramentas estiver selecionado.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para processar notificações que o usuário selecionou um botão da barra de ferramentas.  
  
##  <a name="a-nameonchangevisualmanagera--cmfctoolbaronchangevisualmanager"></a><a name="onchangevisualmanager"></a>CMFCToolBar::OnChangeVisualManager  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnChangeVisualManager();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonfillbackgrounda--cmfctoolbaronfillbackground"></a><a name="onfillbackground"></a>CMFCToolBar::OnFillBackground  
 Chamado pela estrutura de [CBasePane::DoPaint](../../mfc/reference/cbasepane-class.md#dopaint) para preencher o plano de fundo da barra de ferramentas.  
  
```  
virtual void OnFillBackground(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 [CMFCToolBar::DoPaint](#dopaint) chama esse método quando o plano de fundo da barra de ferramentas tenha sido preenchido. A implementação padrão não faz nada.  
  
 Substitua este método para desenhar o plano de fundo personalizado em classes derivadas.  
  
##  <a name="a-nameonglobalfontschangeda--cmfctoolbaronglobalfontschanged"></a><a name="onglobalfontschanged"></a>CMFCToolBar::OnGlobalFontsChanged  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnGlobalFontsChanged();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonreseta--cmfctoolbaronreset"></a><a name="onreset"></a>CMFCToolBar::OnReset  
 Restaura a barra de ferramentas para seu estado original.  
  
```  
virtual void OnReset();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para manipular a notificação sobre uma redefinição de barra de ferramentas.  
  
 A implementação padrão não faz nada. Substituir `OnReset` em uma classe derivada de `CMFCToolBar` quando a barra de ferramentas tem botões fictício que devem ser substituído quando a barra de ferramentas retorna ao estado original.  
  
##  <a name="a-nameonsetaccdataa--cmfctoolbaronsetaccdata"></a><a name="onsetaccdata"></a>CMFCToolBar::OnSetAccData  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnSetAccData(long lVal);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lVal`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonsetdefaultbuttontexta--cmfctoolbaronsetdefaultbuttontext"></a><a name="onsetdefaultbuttontext"></a>CMFCToolBar::OnSetDefaultButtonText  
 Restaura o texto de um botão da barra de ferramentas para seu estado padrão.  
  
```  
virtual BOOL OnSetDefaultButtonText(CMFCToolBarButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Aponta para um botão, cujo texto está sendo definido.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`que o texto foi restaurado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para processar notificações que o texto de um botão da barra de ferramentas está sendo alterado para o padrão.  
  
 A implementação padrão carrega o texto de um botão de recursos do aplicativo.  
  
##  <a name="a-nameonusertooltipa--cmfctoolbaronusertooltip"></a><a name="onusertooltip"></a>CMFCToolBar::OnUserToolTip  
 Chamado pela estrutura quando a dica de ferramenta para um botão está prestes a ser exibido.  
  
```  
virtual BOOL OnUserToolTip(
    CMFCToolBarButton* pButton,  
    CString& strTTText) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Aponta para um botão da barra de ferramentas para que uma dica de ferramenta é exibida.  
  
 [out] `strTTText`  
 Uma referência a `CString` objeto que recebe o texto da dica de ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se `strTTText` foi preenchido com texto de dica de ferramenta; caso contrário `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando a dica de ferramenta para um botão da barra de ferramentas está prestes a ser exibido. Se `OnUserToolTip` retorna `TRUE`, a estrutura exibe uma dica de ferramenta que contém o texto retornado por `OnUserToolTip` em `strTTText`. Caso contrário, a dica de ferramenta contém o texto do botão.  
  
 Substituir `OnUserToolTip` personalizar dicas de ferramentas de botões da barra de ferramentas. As chamadas de implementação padrão [CMFCToolBar::OnUserToolTip](#onusertooltip) para obter o texto de dica de ferramenta.  
  
##  <a name="a-nameprevmenua--cmfctoolbarprevmenu"></a><a name="prevmenu"></a>CMFCToolBar::PrevMenu  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL PrevMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameprocesscommanda--cmfctoolbarprocesscommand"></a><a name="processcommand"></a>CMFCToolBar::ProcessCommand  
 Postagens um `WM_COMMAND` mensagem para a janela que possui a barra de ferramentas.  
  
```  
BOOL ProcessCommand(CMFCToolBarButton* pButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Ponteiro para um botão na barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método deve retornar sempre `TRUE`. O MFC usa `FALSE` valores internamente.  
  
### <a name="remarks"></a>Comentários  
 Esse método lança um `WM_COMMAND` mensagem para a janela que possui a barra de ferramentas chamando [CWnd::PostMessage](../../mfc/reference/cwnd-class.md#postmessage) e passar a ID de comando do botão especificado como o `wParam` parâmetro.  
  
 Use o [ON_COMMAND](http://msdn.microsoft.com/library/f24f8bda-2cf4-49d5-aa3d-6f2e6bb003f2) macro para mapear o `WM_COMMAND` mensagem para uma função de membro.  
  
##  <a name="a-nameremoveallbuttonsa--cmfctoolbarremoveallbuttons"></a><a name="removeallbuttons"></a>CMFCToolBar::RemoveAllButtons  
 Remove todos os separadores e botões da barra de ferramentas.  
  
```  
virtual void RemoveAllButtons();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele recria ou destrói uma barra de ferramentas.  
  
##  <a name="a-nameremovebuttona--cmfctoolbarremovebutton"></a><a name="removebutton"></a>CMFCToolBar::RemoveButton  
 Remove a barra de ferramentas no botão que tem o índice especificado.  
  
```  
virtual BOOL RemoveButton(int iIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 Especifica o índice baseado em zero do botão para remover.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método for bem-sucedido, ou `FALSE` se o índice especificado é inválido ou o índice refere-se para o **personalizar** botão.  
  
### <a name="remarks"></a>Comentários  
 Esse método atualiza os atributos da barra de ferramentas adicionais que são afetados pela remoção do botão. Por exemplo, esse método Remove os separadores não essenciais da barra de ferramentas e recria a tabela de teclas de atalho.  
  
 Para obter mais informações sobre o **personalizar** botão, consulte [CMFCToolBar::EnableCustomizeButton](#enablecustomizebutton).  
  
##  <a name="a-nameremovestatefromregistrya--cmfctoolbarremovestatefromregistry"></a><a name="removestatefromregistry"></a>CMFCToolBar::RemoveStateFromRegistry  
 Exclui as informações de estado da barra de ferramentas do registro do Windows.  
  
```  
virtual BOOL RemoveStateFromRegistry(
    LPCTSTR lpszProfileName=NULL,  
    int nIndex=-1,  
    UINT uiID=(UINT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Especifica a chave do registro onde as informações de estado estão localizadas.  
  
 [in] `nIndex`  
 A ID do controle da barra de ferramentas.  
  
 [in] `uiID`  
 A ID de recurso da barra de ferramentas. Se esse parâmetro for -1, esse método usa o [CWnd::GetDlgCtrlID](../../mfc/reference/cwnd-class.md#getdlgctrlid) método para recuperar a ID do recurso.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando exclui uma barra de ferramentas definidas pelo usuário.  
  
 Substitua este método se você armazenar informações adicionais de estado no registro do Windows.  
  
##  <a name="a-namereplacebuttona--cmfctoolbarreplacebutton"></a><a name="replacebutton"></a>CMFCToolBar::ReplaceButton  
 Substitui um botão da barra de ferramentas com outro botão da barra de ferramentas.  
  
```  
int ReplaceButton(
    UINT uiCmd,  
    const CMFCToolBarButton& button,  
    BOOL bAll=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmd`  
 A ID do botão de comando para substituir.  
  
 [in] `button`  
 Uma referência para o `CMFCToolBarButton` para inserir.  
  
 [in] `bAll`  
 Um valor booleano que especifica se deve substituir todos os botões que tem a ID de comando especificada por `uiCmd`. Se esse parâmetro for `TRUE`, todos os botões que têm a ID de comando especificado são substituídos. Caso contrário, o primeiro botão é substituído.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de botões que são substituídos. Esse método retorna 0 se não existir um botão com a ID de comando especificada na barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método quando desejar adicionar botões de barra de ferramentas que não podem ser carregados a partir de recursos. Você pode criar um botão de espaço reservado em tempo de design e substitua esse botão com um botão personalizado ao inicializar a barra de ferramentas. Consulte o exemplo VisualStudioDemo para obter um exemplo que usa esse método.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `ReplaceButton` método o `CMFCToolBar` classe. Este trecho de código é parte do [exemplo IE demonstração](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_IEDemo n º&6;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_1.h)]  
[!code-cpp[NVC_MFC_IEDemo n º&10;](../../mfc/reference/codesnippet/cpp/cmfctoolbar-class_5.cpp)]  
  
##  <a name="a-nameresetalla--cmfctoolbarresetall"></a><a name="resetall"></a>CMFCToolBar::ResetAll  
 Restaura todas as barras de ferramentas para seu estado original.  
  
```  
static void __stdcall ResetAll();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método chama o [CMFCToolBar::RestoreOriginalState](#restoreoriginalstate) método em cada barra de ferramentas do aplicativo que pode ser restaurado. Ele usa o [CMFCToolBar::CanBeRestored](#canberestored) método para determinar se uma barra de ferramentas pode ser restaurada.  
  
##  <a name="a-nameresetallimagesa--cmfctoolbarresetallimages"></a><a name="resetallimages"></a>CMFCToolBar::ResetAllImages  
 Limpa todas as coleções de imagem da barra de ferramentas do aplicativo.  
  
```  
static void __stdcall ResetAllImages();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método limpa as coleções de imagem são inicializadas pelo [CMFCToolBar::LoadToolBar](#loadtoolbar) e [CMFCToolBar::LoadBitmap](#loadbitmap) métodos.  
  
##  <a name="a-nameresetimagesa--cmfctoolbarresetimages"></a><a name="resetimages"></a>CMFCToolBar::ResetImages  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void ResetImages();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namerestorefocusa--cmfctoolbarrestorefocus"></a><a name="restorefocus"></a>CMFCToolBar::RestoreFocus  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void RestoreFocus();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namerestoreoriginalstatea--cmfctoolbarrestoreoriginalstate"></a><a name="restoreoriginalstate"></a>CMFCToolBar::RestoreOriginalState  
 Restaura o estado original de uma barra de ferramentas.  
  
```  
virtual BOOL RestoreOriginalState();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` se o método for bem-sucedido ou `FALSE` se o método falhar ou a barra de ferramentas for definida pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Esse método carrega a barra de ferramentas do arquivo de recursos usando o [CMFCToolBar::LoadToolBar](#loadtoolbar) método.  
  
 O framework chama esse método quando o usuário escolhe o **Redefinir tudo** botão o **barras de ferramentas** página da caixa de diálogo de personalização.  
  
##  <a name="a-namesaveparametersa--cmfctoolbarsaveparameters"></a><a name="saveparameters"></a>CMFCToolBar::SaveParameters  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static BOOL __stdcall SaveParameters(LPCTSTR lpszProfileName = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesavestatea--cmfctoolbarsavestate"></a><a name="savestate"></a>CMFCToolBar::SaveState  
 Salva as informações de estado da barra de ferramentas no registro do Windows.  
  
```  
virtual BOOL SaveState(
    LPCTSTR lpszProfileName=NULL,  
    int nIndex=-1,  
    UINT uiID=(UINT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszProfileName`  
 Especifica o caminho relativo da chave do registro do Windows.  
  
 [in] `nIndex`  
 A ID do controle da barra de ferramentas.  
  
 [in] `uiID`  
 A ID de recurso da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele salva o estado do aplicativo no registro. Para obter mais informações, consulte [CWinAppEx::SaveState](../../mfc/reference/cwinappex-class.md#savestate).  
  
##  <a name="a-namesetbasiccommandsa--cmfctoolbarsetbasiccommands"></a><a name="setbasiccommands"></a>CMFCToolBar::SetBasicCommands  
 Define a lista de comandos que sempre são exibidos quando um usuário abre um menu.  
  
```  
static void __stdcall SetBasicCommands(CList<UINT,UINT>& lstCommands);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lstCommands`  
 Uma referência a um `CList` objeto que contém uma coleção de comandos.  
  
### <a name="remarks"></a>Comentários  
 Um comando básico sempre é exibido quando o menu é aberto. Esse método é significativo quando o usuário opta por exibir comandos usados recentemente.  
  
 Use o [CMFCToolBar::AddBasicCommand](#addbasiccommand) para adicionar um comando à lista de comandos básicos. Use o [CMFCToolBar::GetBasicCommands](#getbasiccommands) método para recuperar a lista de comandos básicos que é usada pelo seu aplicativo.  
  
 Consulte o exemplo de Gerenciador para obter um exemplo que usa esse método.  
  
##  <a name="a-namesetbuttoninfoa--cmfctoolbarsetbuttoninfo"></a><a name="setbuttoninfo"></a>CMFCToolBar::SetButtonInfo  
 Define a ID de comando, o estilo e a ID da imagem de um botão da barra de ferramentas.  
  
```  
void SetButtonInfo(
    int nIndex,  
    UINT nID,  
    UINT nStyle,  
    int iImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice baseado em zero do botão cujas propriedades são definidas.  
  
 [in] `nID`  
 A ID de comando do botão.  
  
 [in] `nStyle`  
 O estilo do botão. Consulte [estilos de controle de barra de ferramentas](../../mfc/reference/toolbar-control-styles.md) para a lista de estilos de botão da barra de ferramentas disponíveis.  
  
 [in] `iImage`  
 O índice de imagem com base em zero do botão (ou seja, o índice da coleção de imagens da barra de ferramentas).  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para definir as propriedades de um botão da barra de ferramentas.  
  
 Em compilações de depuração, esse método gera uma falha de asserção se o índice especificado pelo `nIndex` é inválido.  
  
 Chamar o [CMFCToolBar::SetButtonStyle](#setbuttonstyle) método para definir apenas o estilo do botão.  
  
##  <a name="a-namesetbuttonsa--cmfctoolbarsetbuttons"></a><a name="setbuttons"></a>CMFCToolBar::SetButtons  
 Define os botões da barra de ferramentas.  
  
```  
virtual BOOL SetButtons(
    const UINT* lpIDArray,  
    int nIDCount,  
    BOOL bRemapImages=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpIDArray`  
 Um ponteiro para a matriz de IDs de comando dos botões para inserir.  
  
 [in] `nIDCount`  
 O número de itens em `lpIDArray`.  
  
 [in] `bRemapImages`  
 Um valor booleano que especifica se deve associar as imagens do botão existente com os botões inseridos. Se esse parâmetro for `TRUE`, as imagens são remapeadas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para remover botões existentes da barra de ferramentas e inserir uma coleção de novos botões.  
  
 Este método adiciona o **personalizar** botão à barra de ferramentas e envia o `AFX_WM_RESETTOOLBAR` mensagem para a janela pai da barra de ferramentas. Para obter mais informações sobre o **personalizar** botão, consulte [CMFCToolBar::EnableCustomizeButton](#enablecustomizebutton).  
  
##  <a name="a-namesetbuttonstylea--cmfctoolbarsetbuttonstyle"></a><a name="setbuttonstyle"></a>CMFCToolBar::SetButtonStyle  
 Define o estilo do botão da barra de ferramentas no índice especificado.  
  
```  
virtual void SetButtonStyle(
    int nIndex,  
    UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice baseado em zero do botão cujo estilo deve ser definido.  
  
 [in] `nStyle`  
 O estilo do botão. Consulte [estilos de controle de barra de ferramentas](../../mfc/reference/toolbar-control-styles.md) para a lista de estilos de botão da barra de ferramentas disponíveis.  
  
### <a name="remarks"></a>Comentários  
 Este método remove a `TBBS_PRESSED` estilo se `nStyle` é `TBBS_DISABLED` porque o usuário não é possível clicar em um botão desabilitado.  
  
##  <a name="a-namesetbuttontexta--cmfctoolbarsetbuttontext"></a><a name="setbuttontext"></a>CMFCToolBar::SetButtonText  
 Define o rótulo de texto de um botão da barra de ferramentas.  
  
```  
BOOL SetButtonText(
    int nIndex,  
    LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice do botão da barra de ferramentas.  
  
 [in] `lpszText`  
 O rótulo de texto do botão da barra de ferramentas. Deve ser não - `NULL`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método for bem-sucedido; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna `FALSE` se o índice fornecido não faz referência a um botão da barra de ferramentas válido.  
  
##  <a name="a-namesetcommandusageoptionsa--cmfctoolbarsetcommandusageoptions"></a><a name="setcommandusageoptions"></a>CMFCToolBar::SetCommandUsageOptions  
 Especifica quando os comandos usados raramente não aparecem no menu do aplicativo.  
  
```  
static BOOL SetCommandUsageOptions(
    UINT nStartCount,  
    UINT nMinUsagePercentage=5);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nStartCount`  
 Especifica o número de vezes que comandos deve ser executado antes que a estrutura mostra somente os comandos básicos e usados recentemente.  
  
 [in] `nMinUsagePercentage`  
 A porcentagem de vezes que um comando deve ser executado para ser considerado um comando usados recentemente.  
  
### <a name="return-value"></a>Valor de retorno  
 `FALSE`Se `nMinUsagePercentage` é igual ou maior que 100; caso contrário `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para personalizar o algoritmo que usa o framework para determinar como básica e usados recentemente itens de menu aparecem. Para obter mais informações sobre os comandos básicos, consulte [CMFCToolBar::AddBasicCommand](#addbasiccommand).  
  
 Essa classe usa o `CMFCCmdUsageCount` classe para controlar a contagem de uso de comandos. Para obter mais informações sobre essa classe, consulte [CMFCCmdUsageCount classe](../../mfc/reference/cmfccmdusagecount-class.md).  
  
##  <a name="a-namesetcustomizemodea--cmfctoolbarsetcustomizemode"></a><a name="setcustomizemode"></a>CMFCToolBar::SetCustomizeMode  
 Habilita ou desabilita o modo de personalização para todas as barras de ferramentas do aplicativo.  
  
```  
static BOOL __stdcall SetCustomizeMode(BOOL bSet=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 Um valor booleano que especifica se deseja habilitar ou desabilitar o modo de personalização. Definir esse parâmetro como `TRUE` para habilitar o modo de personalização ou `FALSE` para desabilitá-lo.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se chamar esse método altera o modo de personalização; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método ajusta o layout do e redesenha cada barra de ferramentas do aplicativo. Chamar o [CMFCToolBar::IsCustomizeMode](#iscustomizemode) método para determinar se o aplicativo está no modo de personalização  
  
##  <a name="a-namesetgraydisabledbuttonsa--cmfctoolbarsetgraydisabledbuttons"></a><a name="setgraydisabledbuttons"></a>CMFCToolBar::SetGrayDisabledButtons  
 Especifica se os botões disponíveis na barra de ferramentas estão esmaecidos, ou se as imagens de botão disponíveis são usadas.  
  
```  
void SetGrayDisabledButtons(BOOL bGrayDisabledButtons);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bGrayDisabledButtons`  
 Um valor booleano que especifica como exibir botões indisponível. Se esse parâmetro for `TRUE`, o framework esmaece os botões. Caso contrário, a estrutura usa a coleção de imagens disponíveis com o botão.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, os botões disponíveis estão esmaecidos.  
  
##  <a name="a-namesetheighta--cmfctoolbarsetheight"></a><a name="setheight"></a>CMFCToolBar::SetHeight  
 Define a altura da barra de ferramentas.  
  
```  
void SetHeight(int cyHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `cyHeight`  
 A altura da barra de ferramentas, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método redesenha a barra de ferramentas depois que ele define a altura.  
  
##  <a name="a-namesethelpmodea--cmfctoolbarsethelpmode"></a><a name="sethelpmode"></a>CMFCToolBar::SetHelpMode  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
static void __stdcall SetHelpMode(BOOL bOn = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bOn`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesethota--cmfctoolbarsethot"></a><a name="sethot"></a>CMFCToolBar::SetHot  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL SetHot(CMFCToolBarButton* pMenuButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMenuButton`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesethotbordera--cmfctoolbarsethotborder"></a><a name="sethotborder"></a>CMFCToolBar::SetHotBorder  
 Especifica se os botões da barra de ferramentas são rastreados hot.  
  
```  
void SetHotBorder(BOOL bShowHotBorder);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShowHotBorder`  
 Um valor booleano que especifica se a botões de barra de ferramentas de rastreamento quente. Se esse parâmetro for `TRUE`, o barra de ferramentas hot-controla seus botões. Caso contrário, a barra de ferramentas não hot-rastrear seus botões.  
  
### <a name="remarks"></a>Comentários  
 Se um botão de controle de acesso, o framework destaca o botão quando o mouse se move sobre ele. Por padrão, cada barra de ferramentas hot-controla seus botões.  
  
 Chamar o [CMFCToolBar::GetHotBorder](#gethotborder) método para determinar se a barra de ferramentas hot-controla seus botões.  
  
##  <a name="a-namesethottextcolora--cmfctoolbarsethottextcolor"></a><a name="sethottextcolor"></a>CMFCToolBar::SetHotTextColor  
 Define a cor do texto para botões da barra de ferramentas ativa.  
  
```  
static void SetHotTextColor(COLORREF clrText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `clrText`  
 Especifica a cor do texto para botões de barra de ferramentas que são rastreados quente.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre botões de barra de ferramentas de controle de acesso, consulte [CMFCToolBar::GetHotBorder](#gethotborder) e [CMFCToolBar::SetHotBorder](#sethotborder).  
  
##  <a name="a-namesetignoresettexta--cmfctoolbarsetignoresettext"></a><a name="setignoresettext"></a>CMFCToolBar::SetIgnoreSetText  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetIgnoreSetText(BOOL bValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bValue`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetlargeiconsa--cmfctoolbarsetlargeicons"></a><a name="setlargeicons"></a>CMFCToolBar::SetLargeIcons  
 Especifica se os botões da barra de ferramentas exibem ícones grandes.  
  
```  
static void SetLargeIcons(BOOL bLargeIcons=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bLargeIcons`  
 Um valor booleano que especifica quais ícones que serão usados. Se esse parâmetro for `TRUE`, o framework exibe ícones grandes. Caso contrário, o framework exibe ícones regulares.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando o usuário altera o estado do **ícones grandes** caixa de seleção o **opções** guia o **personalizar** caixa de diálogo. Esse método redimensiona todas as barras de ferramentas do aplicativo.  
  
 Por padrão, o framework exibe ícones regulares.  
  
 Para obter mais informações sobre o **personalizar** caixa de diálogo, consulte [CMFCToolBarsCustomizeDialog classe](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).  
  
##  <a name="a-namesetlockedsizesa--cmfctoolbarsetlockedsizes"></a><a name="setlockedsizes"></a>CMFCToolBar::SetLockedSizes  
 Define os tamanhos de botões bloqueado e imagens bloqueadas na barra de ferramentas.  
  
```  
void SetLockedSizes(
    SIZE sizeButton,  
    SIZE sizeImage,  
    BOOL bDontScale = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `sizeButton`  
 Especifica o tamanho dos botões de barra de ferramentas bloqueado.  
  
 [in] `sizeImage`  
 Especifica o tamanho das imagens bloqueado da barra de ferramentas.  
  
 `bDontScale`  
 Especifica se a dimensionar ou não bloqueada imagens da barra de ferramentas no modo DPI alta.  
  
### <a name="remarks"></a>Comentários  
 O tamanho padrão dos botões bloqueado é 23 x 22 pixels. O tamanho padrão das imagens bloqueados é 15 x 16 pixels.  
  
 Chamar o [CMFCToolBar::GetLockedImageSize](#getlockedimagesize) bloqueado de método para recuperar o tamanho de imagens. Chamar o [CMFCToolBar::GetButtonSize](#getbuttonsize) bloqueado de método para recuperar o tamanho de botões da barra de ferramentas.  
  
##  <a name="a-namesetmaskmodea--cmfctoolbarsetmaskmode"></a><a name="setmaskmode"></a>CMFCToolBar::SetMaskMode  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetMaskMode(BOOL bMasked);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bMasked`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetmenusizesa--cmfctoolbarsetmenusizes"></a><a name="setmenusizes"></a>CMFCToolBar::SetMenuSizes  
 Define o tamanho dos botões de menu e suas imagens.  
  
```  
static void __stdcall SetMenuSizes(
    SIZE sizeButton,  
    SIZE sizeImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `sizeButton`  
 Especifica o tamanho dos botões da barra de ferramentas, em pixels.  
  
 [in] `sizeImage`  
 Especifica o tamanho das imagens da barra de ferramentas, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, os botões de menu e as imagens têm um tamanho indefinido.  
  
 Chamar o [CMFCToolBar::GetMenuButtonSize](#getmenubuttonsize) método para determinar o tamanho dos botões de menu e o [CMFCToolBar::GetMenuImageSize](#getmenuimagesize) método para determinar o tamanho das imagens de botão de menu.  
  
 Consulte os exemplos IEDemo e MSMoneyDemo para exemplos que usam esse método.  
  
##  <a name="a-namesetnonpermittedcommandsa--cmfctoolbarsetnonpermittedcommands"></a><a name="setnonpermittedcommands"></a>CMFCToolBar::SetNonPermittedCommands  
 Define a lista de comandos que não pode ser executado pelo usuário.  
  
```  
static void SetNonPermittedCommands(CList<UINT,UINT>& lstCommands);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lstCommands`  
 Uma referência a um `CList` objeto que contém os comandos que não podem ser executados pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para impedir que o usuário selecione determinados comandos. Por exemplo, você talvez queira impedir que o usuário selecione determinados comandos por motivos de segurança. Consulte os exemplos MDITabsDemo e MenuSubSet para exemplos que usam esse método.  
  
 Esse método limpa a lista anterior de comandos não permitido. Por padrão, a lista de comandos não permitido está vazia.  
  
##  <a name="a-namesetonerowwithsiblinga--cmfctoolbarsetonerowwithsibling"></a><a name="setonerowwithsibling"></a>CMFCToolBar::SetOneRowWithSibling  
 Posiciona a barra de ferramentas e seu irmão na mesma linha.  
  
```  
void SetOneRowWithSibling();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando o usuário clica o **Mostrar botões em uma linha** botão.  
  
 Chamar o [CMFCToolBar::SetSiblingToolBar](#setsiblingtoolbar) método para habilitar o **Mostrar botões em uma linha** ou **Mostrar botões em duas linhas** botões. Se você chamar [CMFCToolBar::SetSiblingToolBar](#setsiblingtoolbar) para essa barra de ferramentas, a barra de ferramentas irmão é movida para a linha dessa barra de ferramentas. Caso contrário, essa barra de ferramentas é movida para a linha do irmão.  
  
 O framework chama o [CMFCToolBar::SetTwoRowsWithSibling](#settworowswithsibling) método quando o usuário clica o **Mostrar botões em duas linhas** botão.  
  
##  <a name="a-namesetorigbuttonsa--cmfctoolbarsetorigbuttons"></a><a name="setorigbuttons"></a>CMFCToolBar::SetOrigButtons  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetOrigButtons(const CObList& lstOrigButtons);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lstOrigButtons`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetpermamenta--cmfctoolbarsetpermament"></a><a name="setpermament"></a>CMFCToolBar::SetPermament  
 Especifica se o usuário pode fechar a barra de ferramentas.  
  
```  
void SetPermament(BOOL bPermament=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bPermament`  
 Um valor booleano que especifica se o usuário pode fechar a barra de ferramentas. Se esse parâmetro for `TRUE`, um usuário não é possível fechar a barra de ferramentas. Caso contrário, um usuário pode fechar a barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, um usuário pode fechar cada barra de ferramentas.  
  
 Chamar o [CMFCToolBar::CanBeClosed](#canbeclosed) método para determinar se um usuário pode fechar a barra de ferramentas.  
  
##  <a name="a-namesetroutecommandsviaframea--cmfctoolbarsetroutecommandsviaframe"></a><a name="setroutecommandsviaframe"></a>CMFCToolBar::SetRouteCommandsViaFrame  
 Especifica se o quadro pai ou o proprietário envia comandos para a barra de ferramentas.  
  
```  
void SetRouteCommandsViaFrame(BOOL bValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bValue`  
 Se esse parâmetro for `TRUE`, quadro principal envia comandos para a barra de ferramentas. Caso contrário, o proprietário envia comandos para a barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o quadro principal envia comandos para a barra de ferramentas. Chamar o [CMFCToolBar::GetRouteCommandsViaFrame](#getroutecommandsviaframe) método para determinar se o quadro pai ou o proprietário envia comandos para a barra de ferramentas.  
  
##  <a name="a-namesetshowtooltipsa--cmfctoolbarsetshowtooltips"></a><a name="setshowtooltips"></a>CMFCToolBar::SetShowTooltips  
 Especifica se o framework exibe dicas de ferramenta.  
  
```  
static void SetShowTooltips(BOOL bValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bValue`  
 Se esse parâmetro for `TRUE`, o framework mostra dicas de ferramenta. Caso contrário, o framework oculta dicas de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o framework mostra dicas de ferramenta.  
  
 Chamar o [CMFCToolBar::GetShowTooltips](#getshowtooltips) método para determinar se a estrutura mostra dicas de ferramenta.  
  
##  <a name="a-namesetsiblingtoolbara--cmfctoolbarsetsiblingtoolbar"></a><a name="setsiblingtoolbar"></a>CMFCToolBar::SetSiblingToolBar  
 Especifica o irmão da barra de ferramentas.  
  
```  
void SetSiblingToolBar(CMFCToolBar* pBrotherToolbar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBrotherToolbar`  
 Um ponteiro para a barra de ferramentas do irmão.  
  
### <a name="remarks"></a>Comentários  
 Este método permite que o **Mostrar botões em uma linha** ou **Mostrar botões em duas linhas** botões que são exibidas quando o usuário exibe o **personalizar** menu pop-up. Chame esse método quando quiser permitir que o usuário especificar se as barras de ferramentas relacionadas são exibidos na mesma linha ou em linhas diferentes.  
  
 Chamar esse método depois de habilitar o **personalizar** botão aparece na barra de ferramentas. Para habilitar o **personalizar** botão, chame o [CMFCToolBar::EnableCustomizeButton](#enablecustomizebutton) método.  
  
 Para recuperar o irmão da barra de ferramentas, chame [CMFCToolBar::GetSiblingToolBar](#getsiblingtoolbar).  
  
##  <a name="a-namesetsizesa--cmfctoolbarsetsizes"></a><a name="setsizes"></a>CMFCToolBar::SetSizes  
 Especifica os tamanhos de botões e imagens em todas as barras de ferramentas.  
  
```  
static void __stdcall SetSizes(
    SIZE sizeButton,  
    SIZE sizeImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `sizeButton`  
 O tamanho dos botões da barra de ferramentas, em pixels.  
  
 [in] `sizeImage`  
 O tamanho das imagens de botão da barra de ferramentas, em pixels.  
  
### <a name="remarks"></a>Comentários  
 O tamanho padrão dos botões da barra de ferramentas é 23 x 22 pixels. O tamanho padrão das imagens de botão da barra de ferramentas é 15 x 16 pixels.  
  
 Chamar o [CMFCToolBar::GetImageSize](#getimagesize) método para recuperar o tamanho das imagens de botão da barra de ferramentas. Chamar o [CMFCToolBar::GetButtonSize](#getbuttonsize) método para recuperar o tamanho dos botões da barra de ferramentas.  
  
##  <a name="a-namesettoolbarbtntexta--cmfctoolbarsettoolbarbtntext"></a><a name="settoolbarbtntext"></a>CMFCToolBar::SetToolBarBtnText  
 Especifica as propriedades de um botão na barra de ferramentas.  
  
```  
void SetToolBarBtnText(
    UINT nBtnIndex,  
    LPCTSTR szText=NULL,  
    BOOL bShowText=TRUE,  
    BOOL bShowImage=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nBtnIndex`  
 O índice baseado em zero do botão da barra de ferramentas na lista de botões da barra de ferramentas.  
  
 [in] `szText`  
 Especifica o rótulo de texto do botão da barra de ferramentas.  
  
 [in] `bShowText`  
 Se esse parâmetro for `TRUE`, o framework mostra o rótulo de texto. Caso contrário, o framework oculta o rótulo de texto.  
  
 [in] `bShowImage`  
 Se esse parâmetro for `TRUE`, o framework mostra a imagem do botão da barra de ferramentas. Caso contrário, o framework oculta a imagem do botão da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o framework mostra as imagens dos botões da barra de ferramentas, mas não mostra o rótulo de texto dos botões da barra de ferramentas.  
  
 Em compilações de depuração, esse método gera uma falha de asserção se `nBtnIndex` não se refere a uma barra de ferramentas válida botão ou barra de ferramentas é um separador.  
  
##  <a name="a-namesettworowswithsiblinga--cmfctoolbarsettworowswithsibling"></a><a name="settworowswithsibling"></a>CMFCToolBar::SetTwoRowsWithSibling  
 Posiciona a barra de ferramentas e seu irmão em linhas separadas.  
  
```  
void SetTwoRowsWithSibling();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando o usuário clica o **Mostrar botões em duas linhas** botão.  
  
 Chamar o [CMFCToolBar::SetSiblingToolBar](#setsiblingtoolbar) método para habilitar o **Mostrar botões em uma linha** ou **Mostrar botões em duas linhas** botões. Se você chamar [CMFCToolBar::SetSiblingToolBar](#setsiblingtoolbar) para essa barra de ferramentas, a barra de ferramentas irmão é movida para uma linha separada. Caso contrário, essa barra de ferramentas é movida para uma linha separada.  
  
 O framework chama o [CMFCToolBar::SetOneRowWithSibling](#setonerowwithsibling) método quando o usuário clica o **Mostrar botões em uma linha** botão.  
  
##  <a name="a-namesetuserimagesa--cmfctoolbarsetuserimages"></a><a name="setuserimages"></a>CMFCToolBar::SetUserImages  
 Define uma coleção de imagens definidas pelo usuário no aplicativo.  
  
```  
static BOOL SetUserImages(CMFCToolBarImages* pUserImages);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pUserImages`  
 Um ponteiro para a coleção de imagens definidas pelo usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o método for bem-sucedido; Caso contrário, 0 se especificado `CMFCToolBarImages` objeto não é válido ou tem um tamanho de imagem que difere do tamanho da imagem padrão da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa imagens definidas pelo usuário para desenhar os botões de barra de ferramentas que são personalizados pelo usuário. A lista de imagem especificada por `pUserImages` é compartilhado entre todas as barras de ferramentas do aplicativo.  
  
 Esse método gera uma falha de asserção em compilações de depuração se especificado `CMFCToolBarImages` objeto não é válido ou tem um tamanho de imagem que difere do tamanho da imagem padrão da barra de ferramentas.  
  
 Os exemplos de OutlookDemo, ToolTipDemo e VisualStudioDemo usam esse método para definir o conjunto global de imagens definidas pelo usuário. Eles carregam o arquivo chamado UserImages.bmp, que está localizado no diretório de trabalho do aplicativo.  
  
 Chamar o [CMFCToolBar::GetUserImages](#getuserimages) método para recuperar a coleção de imagens definidas pelo usuário no aplicativo.  
  
##  <a name="a-namestretchpanea--cmfctoolbarstretchpane"></a><a name="stretchpane"></a>CMFCToolBar::StretchPane  
 Alonga barra vertical ou horizontalmente e reposiciona os botões, se necessário.  
  
```  
virtual CSize StretchPane(
    int nLength,  
    BOOL bVert);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nLength`  
 A quantidade, em pixels, pelo qual deseja ampliar o painel.  
  
 [in] `bVert`  
 Se `TRUE`, alonga painel verticalmente. Se `FALSE`, alonga painel horizontalmente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que especifica o tamanho da área da barra de ferramentas do cliente.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama [CMFCToolBar::WrapToolBar](#wraptoolbar) para reposicionar os botões na barra de ferramentas alongado.  
  
 O valor de retorno é determinado chamando [CMFCToolBar::CalcSize](#calcsize).  
  
##  <a name="a-nametranslatechara--cmfctoolbartranslatechar"></a><a name="translatechar"></a>CMFCToolBar::TranslateChar  
 Executa um comando de botão se o código de chave especificado corresponde a um atalho de teclado válido.  
  
```  
virtual BOOL TranslateChar(UINT nChar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nChar`  
 Especifica um código de tecla virtual. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h  
  
### <a name="return-value"></a>Valor de retorno  
 `FALSE`Se o código de chave especificado é não imprimíveis ou não corresponde a um atalho de teclado válido; `TRUE` se o código de chave especificado corresponde a uma opção de menu suspenso; caso contrário, o valor de retorno de [CMFCToolBar::ProcessCommand](#processcommand).  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando uma tecla é pressionada junto com a tecla Alt.  
  
##  <a name="a-nameupdatebuttona--cmfctoolbarupdatebutton"></a><a name="updatebutton"></a>CMFCToolBar::UpdateButton  
 Atualiza o estado do botão especificado.  
  
```  
void UpdateButton(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice baseado em zero do botão Atualizar.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namewraptoolbara--cmfctoolbarwraptoolbar"></a><a name="wraptoolbar"></a>CMFCToolBar::WrapToolBar  
 Reposiciona botões dentro das dimensões determinadas.  
  
```  
int WrapToolBar(
    int nWidth,  
    int nHeight = 32767,  
    CDC* pDC = NULL,  
    int nColumnWidth = -1,  
    int nRowHeight = -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nWidth`  
 Largura máxima da barra de ferramentas.  
  
 [in] `nHeight`  
 Altura máxima da barra de ferramentas. Não usado se a barra de ferramentas é flutuante.  
  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo. Se for NULL, o contexto de dispositivo para a barra de ferramentas é usado.  
  
 [in] `nColumnWidth`  
 Largura do botão. Se-1, a largura atual será usada.  
  
 [m in]`nRowHeight`  
 Altura do botão. Se-1, a altura atual será usada.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de linhas de botões na barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Esse método reposiciona botões na barra de ferramentas, encapsulando os botões para linhas adicionais, se necessário.  
  
##  <a name="a-namembdontscaleimagesa--cmfctoolbarmbdontscaleimages"></a><a name="m_bdontscaleimages"></a>CMFCToolBar::m_bDontScaleImages  
 Especifica se deve ou não Dimensionar imagens da barra de ferramentas no modo DPI alta.  
  
```  
AFX_IMPORT_DATA static BOOL m_bDontScaleImages;  
```  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCMenuBar](../../mfc/reference/cmfcmenubar-class.md)   
 [Classe CMFCPopupMenuBar](../../mfc/reference/cmfcpopupmenubar-class.md)   
 [Classe CMFCDropDownToolBar](../../mfc/reference/cmfcdropdowntoolbar-class.md)   
 [Passo a passo: Colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)




