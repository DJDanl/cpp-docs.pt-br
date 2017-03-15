---
title: Classe COleControl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleControl
dev_langs:
- C++
helpviewer_keywords:
- OLE controls, MFC
- windowless controls, MFC
- windowless controls
- controls [MFC], OLE
- controls [MFC], windowless
- COleControl class
ms.assetid: 53e95299-38e8-447b-9c5f-a381d27f5123
caps.latest.revision: 25
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
ms.openlocfilehash: 7ef5621aaf940be3ebe2806971dfc65d06972a5a
ms.lasthandoff: 02/25/2017

---
# <a name="colecontrol-class"></a>Classe COleControl
Uma classe base poderosa para desenvolvimento de controles OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleControl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleControl::COleControl](#colecontrol)|Cria um objeto `COleControl`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleControl::AmbientAppearance](#ambientappearance)|Recupera a aparência atual do controle.|  
|[COleControl::AmbientBackColor](#ambientbackcolor)|Retorna o valor da propriedade BackColor ambiente.|  
|[COleControl::AmbientDisplayName](#ambientdisplayname)|Retorna o nome do controle conforme especificado pelo contêiner.|  
|[COleControl::AmbientFont](#ambientfont)|Retorna o valor da propriedade de fonte de ambiente.|  
|[COleControl::AmbientForeColor](#ambientforecolor)|Retorna o valor da propriedade ForeColor ambiente.|  
|[COleControl::AmbientLocaleID](#ambientlocaleid)|Retorna a ID da localidade. do contêiner|  
|[COleControl::AmbientScaleUnits](#ambientscaleunits)|Retorna o tipo de unidades usadas pelo contêiner.|  
|[COleControl::AmbientShowGrabHandles](#ambientshowgrabhandles)|Determina se os identificadores de captura devem ser exibidos.|  
|[COleControl::AmbientShowHatching](#ambientshowhatching)|Determina se a hachura deve ser exibida.|  
|[COleControl::AmbientTextAlign](#ambienttextalign)|Retorna o tipo de alinhamento de texto especificado pelo contêiner.|  
|[COleControl::AmbientUIDead](#ambientuidead)|Determina se o controle deve responder às ações de interface do usuário.|  
|[COleControl::AmbientUserMode](#ambientusermode)|Determina o modo do contêiner.|  
|[COleControl::BoundPropertyChanged](#boundpropertychanged)|Notifica o contêiner que uma propriedade vinculada foi alterada.|  
|[COleControl::BoundPropertyRequestEdit](#boundpropertyrequestedit)|Solicita permissão para editar o valor da propriedade.|  
|[COleControl::ClientToParent](#clienttoparent)|Converte um ponto em relação à origem do controle para um ponto em relação à origem do respectivo contêiner.|  
|[COleControl::ClipCaretRect](#clipcaretrect)|Ajusta um retângulo de cursor se sobreposto por um controle.|  
|[COleControl::ControlInfoChanged](#controlinfochanged)|Chame essa função depois que o conjunto de mnemônicos tratados pelo controle é alterado.|  
|[COleControl::DisplayError](#displayerror)|Exibe eventos de erro de estoque ao usuário do controle.|  
|[COleControl::DoClick](#doclick)|Implementação das ações `DoClick` método.|  
|[COleControl::DoPropExchange](#dopropexchange)|Serializa as propriedades de uma `COleControl` objeto.|  
|[COleControl::DoSuperclassPaint](#dosuperclasspaint)|Redesenha a um controle OLE que tenha sido derivado de um controle do Windows.|  
|[COleControl::EnableSimpleFrame](#enablesimpleframe)|Habilita o suporte de quadro simples para um controle.|  
|[COleControl::ExchangeExtent](#exchangeextent)|Serializa a largura e altura do controle.|  
|[COleControl::ExchangeStockProps](#exchangestockprops)|Serializa as propriedades de estoque do controle.|  
|[COleControl::ExchangeVersion](#exchangeversion)|Serializa o número da versão do controle.|  
|[COleControl::FireClick](#fireclick)|Dispara o estoque `Click` eventos.|  
|[COleControl::FireDblClick](#firedblclick)|Dispara o estoque `DblClick` eventos.|  
|[COleControl::FireError](#fireerror)|Dispara o estoque `Error` eventos.|  
|[COleControl::FireEvent](#fireevent)|Dispara um evento personalizado.|  
|[COleControl::FireKeyDown](#firekeydown)|Dispara o estoque `KeyDown` eventos.|  
|[COleControl::FireKeyPress](#firekeypress)|Dispara o estoque `KeyPress` eventos.|  
|[COleControl::FireKeyUp](#firekeyup)|Dispara o estoque `KeyUp` eventos.|  
|[COleControl::FireMouseDown](#firemousedown)|Dispara o estoque `MouseDown` eventos.|  
|[COleControl::FireMouseMove](#firemousemove)|Dispara o estoque `MouseMove` eventos.|  
|[COleControl::FireMouseUp](#firemouseup)|Dispara o estoque `MouseUp` eventos.|  
|[COleControl::FireReadyStateChange](#firereadystatechange)|Dispara um evento quando o estado pronto do controle é alterado.|  
|[COleControl::GetActivationPolicy](#getactivationpolicy)|Altera o comportamento padrão de ativação de um controle que suporta o `IPointerInactive` interface.|  
|[COleControl::GetAmbientProperty](#getambientproperty)|Retorna o valor da propriedade de ambiente especificada.|  
|[COleControl::GetAppearance](#getappearance)|Retorna o valor da propriedade Appearance estoque.|  
|[COleControl::GetBackColor](#getbackcolor)|Retorna o valor da propriedade BackColor estoque.|  
|[COleControl::GetBorderStyle](#getborderstyle)|Retorna o valor da propriedade BorderStyle estoque.|  
|[COleControl::GetCapture](#getcapture)|Determina se um objeto de controle sem janelas, ativado tem a captura do mouse.|  
|[COleControl::GetClassID](#getclassid)|Recupera a ID de classe OLE do controle.|  
|[COleControl::GetClientOffset](#getclientoffset)|Recupera a diferença entre o canto superior esquerdo da área retangular do controle e o canto superior esquerdo da sua área de cliente.|  
|[COleControl::GetClientRect](#getclientrect)|Recupera o tamanho da área do cliente do controle.|  
|[COleControl::GetClientSite](#getclientsite)|Consultas de um objeto para o ponteiro para o seu site atual do cliente dentro do seu contêiner.|  
|[COleControl::GetControlFlags](#getcontrolflags)|Recupera as configurações de sinalizador de controle.|  
|[COleControl::GetControlSize](#getcontrolsize)|Retorna a posição e o tamanho do controle OLE.|  
|[COleControl::GetDC](#getdc)|Fornece um meio para um controle sem janelas para obter um contexto de dispositivo de seu contêiner.|  
|[COleControl::GetEnabled](#getenabled)|Retorna o valor do estoque propriedade Enabled.|  
|[COleControl::GetExtendedControl](#getextendedcontrol)|Recupera um ponteiro para um objeto de controle estendido que pertence ao contêiner.|  
|[COleControl::GetFocus](#getfocus)|Determina se o controle tem o foco.|  
|[COleControl::GetFont](#getfont)|Retorna o valor da propriedade Font estoque.|  
|[COleControl::GetFontTextMetrics](#getfonttextmetrics)|Retorna as métricas de um `CFontHolder` objeto.|  
|[COleControl::GetForeColor](#getforecolor)|Retorna o valor da propriedade ForeColor estoque.|  
|[COleControl::GetHwnd](#gethwnd)|Retorna o valor da propriedade hWnd de estoque.|  
|[COleControl::GetMessageString](#getmessagestring)|Fornece o texto da barra de status para um item de menu.|  
|[COleControl::GetNotSupported](#getnotsupported)|Impede o acesso ao valor de propriedade do controle do usuário.|  
|[COleControl::GetReadyState](#getreadystate)|Retorna o estado de prontidão do controle.|  
|[COleControl::GetRectInContainer](#getrectincontainer)|Retorna o retângulo do controle em relação ao respectivo contêiner.|  
|[COleControl::GetStockTextMetrics](#getstocktextmetrics)|Retorna as métricas da propriedade fonte estoque.|  
|[COleControl::GetText](#gettext)|Retorna o valor da propriedade Text ou Caption estoque.|  
|[COleControl::GetWindowlessDropTarget](#getwindowlessdroptarget)|Substitua para permitir um controle sem janelas ser o destino de arrastar e soltar operações.|  
|[COleControl::InitializeIIDs](#initializeiids)|Informa a classe base das IIDs irá usar o controle.|  
|[COleControl::InternalGetFont](#internalgetfont)|Retorna um `CFontHolder` objeto para a propriedade fonte estoque.|  
|[COleControl::InternalGetText](#internalgettext)|Recupera a propriedade de estoque legenda ou texto.|  
|[COleControl::InternalSetReadyState](#internalsetreadystate)|Define o estado de prontidão do controle e dispara o evento de alteração de estado de pronto.|  
|[COleControl::InvalidateControl](#invalidatecontrol)|Invalida uma área do controle exibida, fazendo com que ele seja redesenhado.|  
|[COleControl::InvalidateRgn](#invalidatergn)|Invalida a área de cliente da janela do contêiner em determinada região. Pode ser usado para redesenhar controles sem janelas na região.|  
|[COleControl::IsConvertingVBX](#isconvertingvbx)|Permite o carregamento especializado de um controle OLE.|  
|[COleControl::IsModified](#ismodified)|Determina se o estado do controle é alterado.|  
|[COleControl::IsOptimizedDraw](#isoptimizeddraw)|Indica se o contêiner suporta desenho otimizado para a operação de desenho atual.|  
|[COleControl::IsSubclassedControl](#issubclassedcontrol)|Chamado para determinar se o controle subdivide um Windows controle.|  
|[COleControl::Load](#load)|Redefine quaisquer dados assíncronos anteriores e inicia uma nova carga de propriedade assíncrona do controle.|  
|[COleControl::LockInPlaceActive](#lockinplaceactive)|Determina se o controle pode ser desativado pelo contêiner.|  
|[COleControl::OnAmbientPropertyChange](#onambientpropertychange)|Chamado quando uma propriedade de ambiente é alterada.|  
|[COleControl::OnAppearanceChanged](#onappearancechanged)|Chamado quando a propriedade de estoque aparência é alterada.|  
|[COleControl::OnBackColorChanged](#onbackcolorchanged)|Chamado quando a propriedade BackColor estoque é alterada.|  
|[COleControl::OnBorderStyleChanged](#onborderstylechanged)|Chamado quando a propriedade BorderStyle estoque é alterada.|  
|[COleControl::OnClick](#onclick)|Chamado para acionar o estoque, clique em eventos.|  
|[COleControl::OnClose](#onclose)|Notifica o controle que `IOleControl::Close` foi chamado.|  
|[COleControl::OnDoVerb](#ondoverb)|Chamado depois de um verbo de controle foi executado.|  
|[COleControl::OnDraw](#ondraw)|Chamado quando um controle é solicitado a ser redesenhado.|  
|[COleControl::OnDrawMetafile](#ondrawmetafile)|Chamado pelo contêiner quando um controle é solicitado para redesenhar o próprio usando um contexto de dispositivo de metarquivo.|  
|[COleControl::OnEdit](#onedit)|Chamado pelo contêiner para ativar a interface do usuário de um controle OLE.|  
|[COleControl::OnEnabledChanged](#onenabledchanged)|Chamado quando o propriedade Enabled do estoque é alterado.|  
|[COleControl::OnEnumVerbs](#onenumverbs)|Chamado pelo contêiner para enumerar os verbos do controle.|  
|[COleControl::OnEventAdvise](#oneventadvise)|Chamado quando os manipuladores de eventos estão conectados ou desconectados de um controle.|  
|[COleControl::OnFontChanged](#onfontchanged)|Chamado quando a propriedade Font estoque é alterada.|  
|[COleControl::OnForeColorChanged](#onforecolorchanged)|Chamado quando a propriedade ForeColor estoque é alterada.|  
|[COleControl::OnFreezeEvents](#onfreezeevents)|Chamado quando os eventos de controle são congelados ou descongelados.|  
|[COleControl::OnGetColorSet](#ongetcolorset)|Notifica o controle que `IOleObject::GetColorSet` foi chamado.|  
|[COleControl::OnGetControlInfo](#ongetcontrolinfo)|Fornece informações mnemônicas para o contêiner.|  
|[COleControl::OnGetDisplayString](#ongetdisplaystring)|Chamado para obter uma cadeia de caracteres para representar um valor de propriedade.|  
|[COleControl::OnGetInPlaceMenu](#ongetinplacemenu)|Solicita o identificador do menu de controle que será mesclado com o menu de contêiner.|  
|[COleControl::OnGetNaturalExtent](#ongetnaturalextent)|Substitua para recuperar o tamanho de exibição do controle mais próximo para o modo de tamanho e a extensão proposto.|  
|[COleControl::OnGetPredefinedStrings](#ongetpredefinedstrings)|Retorna as cadeias de caracteres que representa os valores possíveis para uma propriedade.|  
|[COleControl::OnGetPredefinedValue](#ongetpredefinedvalue)|Retorna o valor correspondente a uma cadeia de caracteres predefinida.|  
|[COleControl::OnGetViewExtent](#ongetviewextent)|Substitua para recuperar o tamanho das áreas de exibição do controle (pode ser usado para habilitar o desenho de dois passos).|  
|[COleControl::OnGetViewRect](#ongetviewrect)|Substituição para converter o tamanho do controle em um retângulo que começa em uma posição específica.|  
|[COleControl::OnGetViewStatus](#ongetviewstatus)|Substitua para recuperar o status de exibição do controle.|  
|[COleControl::OnHideToolBars](#onhidetoolbars)|Chamado pelo contêiner quando o controle é desativado pela IU.|  
|[COleControl::OnInactiveMouseMove](#oninactivemousemove)|Substituição para que o contêiner para o controle inativo sob a expedição de ponteiro de mouse `WM_MOUSEMOVE` mensagens para o controle.|  
|[COleControl::OnInactiveSetCursor](#oninactivesetcursor)|Substituição para que o contêiner para o controle inativo sob a expedição de ponteiro de mouse `WM_SETCURSOR` mensagens para o controle.|  
|[COleControl::OnKeyDownEvent](#onkeydownevent)|Chamado depois que o evento KeyDown estoque tiver sido acionado.|  
|[COleControl::OnKeyPressEvent](#onkeypressevent)|Chamado depois que o evento KeyPress estoque tiver sido acionado.|  
|[COleControl::OnKeyUpEvent](#onkeyupevent)|Chamado depois que o evento KeyUp estoque tiver sido acionado.|  
|[COleControl::OnMapPropertyToPage](#onmappropertytopage)|Indica qual página de propriedade a ser usado para editar uma propriedade.|  
|[COleControl::OnMnemonic](#onmnemonic)|Chamado quando uma tecla mnemônica do controle foi pressionada.|  
|[COleControl::OnProperties](#onproperties)|Chamado quando o verbo de "Propriedades" do controle foi invocado.|  
|[COleControl::OnQueryHitPoint](#onqueryhitpoint)|Substitua a consulta se a exibição do controle se sobrepõe a um determinado ponto.|  
|[COleControl::OnQueryHitRect](#onqueryhitrect)|Substitua a consulta se qualquer ponto em um retângulo determinado se sobrepõe a exibição do controle.|  
|[COleControl::OnRenderData](#onrenderdata)|Chamado pela estrutura para recuperar dados no formato especificado.|  
|[COleControl::OnRenderFileData](#onrenderfiledata)|Chamado pela estrutura para recuperar dados de um arquivo no formato especificado.|  
|[COleControl::OnRenderGlobalData](#onrenderglobaldata)|Chamado pela estrutura para recuperar dados de memória global no formato especificado.|  
|[COleControl::OnResetState](#onresetstate)|Redefine as propriedades de um controle com os valores padrão.|  
|[COleControl::OnSetClientSite](#onsetclientsite)|Notifica o controle que `IOleControl::SetClientSite` foi chamado.|  
|[COleControl::OnSetData](#onsetdata)|Substitui os dados do controle com outro valor.|  
|[COleControl::OnSetExtent](#onsetextent)|Chamado depois que a extensão do controle é alterado.|  
|[COleControl::OnSetObjectRects](#onsetobjectrects)|Chamado após as dimensões do controle foram alteradas.|  
|[COleControl::OnShowToolBars](#onshowtoolbars)|Chamado quando o controle foi ativado pela IU.|  
|[COleControl::OnTextChanged](#ontextchanged)|Chamado quando o estoque texto ou a propriedade Caption é alterada.|  
|[COleControl::OnWindowlessMessage](#onwindowlessmessage)|Processa as mensagens de janela (diferente de mensagens de mouse e teclado) de controles sem janelas.|  
|[COleControl::ParentToClient](#parenttoclient)|Converte um ponto em relação à origem do contêiner para um ponto em relação à origem do controle.|  
|[COleControl::PostModalDialog](#postmodaldialog)|Notifica o contêiner que uma caixa de diálogo modal foi fechada.|  
|[COleControl::PreModalDialog](#premodaldialog)|Notifica o contêiner que uma caixa de diálogo modal está prestes a ser exibido.|  
|[COleControl::RecreateControlWindow](#recreatecontrolwindow)|Destrói e recria a janela do controle.|  
|[COleControl::Refresh](#refresh)|Força um redesenho da aparência do controle.|  
|[COleControl::ReleaseCapture](#releasecapture)|Libera a captura do mouse.|  
|[COleControl::ReleaseDC](#releasedc)|Libera o contexto de dispositivo de exibição de um contêiner de um controle sem janelas.|  
|[COleControl::ReparentControlWindow](#reparentcontrolwindow)|Redefine o pai da janela de controle.|  
|[COleControl::ResetStockProps](#resetstockprops)|Inicializa `COleControl` stock propriedades com seus valores padrão.|  
|[COleControl::ResetVersion](#resetversion)|Inicializa o número de versão para um determinado valor.|  
|[COleControl::ScrollWindow](#scrollwindow)|Permite que um controle sem janelas rolar uma área dentro de sua imagem ativa no local na tela.|  
|[COleControl::SelectFontObject](#selectfontobject)|Seleciona uma propriedade de fonte personalizada em um contexto de dispositivo.|  
|[COleControl::SelectStockFont](#selectstockfont)|Seleciona a propriedade Font estoque em um contexto de dispositivo.|  
|[COleControl::SerializeExtent](#serializeextent)|Serializa ou inicializa o espaço de exibição para o controle.|  
|[COleControl::SerializeStockProps](#serializestockprops)|Serializa ou inicializa o `COleControl` propriedades de estoque.|  
|[COleControl::SerializeVersion](#serializeversion)|Serializa ou inicializa as informações de versão do controle.|  
|[COleControl::SetAppearance](#setappearance)|Define o valor da propriedade Appearance estoque.|  
|[COleControl::SetBackColor](#setbackcolor)|Define o valor da propriedade BackColor estoque.|  
|[COleControl::SetBorderStyle](#setborderstyle)|Define o valor da propriedade BorderStyle estoque.|  
|[COleControl::SetCapture](#setcapture)|Faz com que a janela do controle contêiner tomar posse da captura do mouse no nome do controle.|  
|[COleControl::SetControlSize](#setcontrolsize)|Define a posição e o tamanho do controle OLE.|  
|[COleControl::SetEnabled](#setenabled)|Define o valor do estoque propriedade Enabled.|  
|[COleControl::SetFocus](#setfocus)|Faz com que a janela do controle contêiner tomar posse do foco de entrada em nome do controle.|  
|[COleControl::SetFont](#setfont)|Define o valor da propriedade Font estoque.|  
|[COleControl::SetForeColor](#setforecolor)|Define o valor da propriedade ForeColor estoque.|  
|[COleControl::SetInitialSize](#setinitialsize)|Define o tamanho de um controle OLE quando exibido pela primeira vez em um contêiner.|  
|[COleControl::SetModifiedFlag](#setmodifiedflag)|Altera o estado de um controle modificado.|  
|[COleControl::SetNotPermitted](#setnotpermitted)|Indica que uma solicitação de edição falhou.|  
|[COleControl::SetNotSupported](#setnotsupported)|Impede a modificação para o valor da propriedade do controle do usuário.|  
|[COleControl::SetRectInContainer](#setrectincontainer)|Define o retângulo do controle em relação ao respectivo contêiner.|  
|[COleControl::SetText](#settext)|Define o valor da propriedade Text ou Caption estoque.|  
|[COleControl::ThrowError](#throwerror)|Indica que ocorreu um erro em um controle OLE.|  
|[COleControl::TransformCoords](#transformcoords)|Transformações coordenam valores entre um contêiner e o controle.|  
|[COleControl::TranslateColor](#translatecolor)|Converte um **OLE_COLOR** valor para um **COLORREF** valor.|  
|[COleControl::WillAmbientsBeValidDuringLoad](#willambientsbevalidduringload)|Determina se as propriedades de ambiente estará disponíveis na próxima vez que o controle for carregado.|  
|[COleControl::WindowProc](#windowproc)|Fornece um procedimento do Windows para uma `COleControl` objeto.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleControl::DrawContent](#drawcontent)|Chamado pela estrutura quando a aparência do controle precisa ser atualizado.|  
|[COleControl::DrawMetafile](#drawmetafile)|Chamado pela estrutura quando o contexto de dispositivo de metarquivo está sendo usado.|  
|[COleControl::IsInvokeAllowed](#isinvokeallowed)|Permite a invocação de método de automação.|  
|[COleControl::SetInitialDataFormats](#setinitialdataformats)|Chamado pela estrutura para inicializar a lista de formatos de dados suportados pelo controle.|  
  
## <a name="remarks"></a>Comentários  
 Derivado de `CWnd`, essa classe herda todas as funcionalidades de um objeto de janela Windows mais funcionalidades adicionais específicas ao OLE, como o acionamento de evento e a capacidade de oferecer suporte a métodos e propriedades.  
  
 Controles OLE podem ser inseridos em aplicativos de contêiner OLE e se comunicar com o contêiner usando um sistema bidirecional de acionamento de evento e expor métodos e propriedades para o contêiner. Observe que os contêineres OLE padrão dão suporte apenas a funcionalidade básica de um controle OLE. Eles são capazes de dar suporte a recursos estendidos de um controle OLE. Acionamento de evento ocorre quando eventos são enviados para o contêiner como resultado de determinadas ações que ocorrem no controle. Por sua vez, o contêiner se comunica com o controle usando um conjunto exposto de métodos e propriedades análogas às funções de membro e membros de dados de uma classe C++. Essa abordagem permite que o desenvolvedor controlar a aparência do controle e notificar o contêiner quando certas ações ocorrem.  
  
## <a name="windowless-controls"></a>Controles sem janelas  
 Controles OLE podem ser ativo no local usado sem uma janela. Controles sem janelas tem vantagens significativas:  
  
-   Controles sem janelas podem ser transparente e não retangulares  
  
-   Controles sem janelas reduzem o tempo de criação e o tamanho de instância do objeto  
  
 Controles não precisa de uma janela. Serviços que oferece uma janela facilmente podem ser fornecidos por meio de uma única janela compartilhada (geralmente do contêiner) e um pouco de código de expedição. Ter uma janela é principalmente uma complicação desnecessária no objeto.  
  
 Quando a ativação sem janelas for usada, o contêiner (que tem uma janela) é responsável por fornecer serviços caso contrário, terá sido fornecidos pela janela do controle. Por exemplo, se o seu controle precisa consultar o foco do teclado, consulte a captura do mouse ou obter um contexto de dispositivo, essas operações são gerenciadas pelo contêiner. O `COleControl` [funções de membro de operação sem janelas](http://msdn.microsoft.com/en-us/e9e28f79-9a70-4ae4-a5aa-b3e92f1904df) invocar essas operações no contêiner.  
  
 Quando a ativação sem janelas estiver habilitada, os delegados de contêiner do controle de mensagens de entrada `IOleInPlaceObjectWindowless` interface (uma extensão do [IOleInPlaceObject](http://msdn.microsoft.com/library/windows/desktop/ms692646) para suporte sem janelas). `COleControl`da implementação dessa interface enviará essas mensagens por meio do mapa da mensagem do controle, depois de ajustar o mouse coordena adequadamente. Você pode processar essas mensagens como mensagens de janela comum, adicionando as entradas correspondentes ao mapa da mensagem.  
  
 Em um controle sem janelas, você sempre deve usar o `COleControl` funções de membro em vez de correspondente `CWnd` funções de membro ou as funções de API do Windows relacionadas.  
  
 Objetos de controle OLE também podem criar uma janela somente quando eles se tornam ativos, mas aumenta a quantidade de trabalho necessário para a transição de ativos inativos e a velocidade da transição é desativado. Há casos em que esse é um problema: como exemplo, considere uma grade de caixas de texto. Quando o cursor para cima e para baixo pela coluna, cada controle deve ser local ativado e desativado, em seguida. A velocidade da transição ativo/inativo irá afetar diretamente a velocidade de rolagem.  
  
 Para obter mais informações sobre como desenvolver uma estrutura de controle OLE, consulte os artigos [controles ActiveX MFC](../../mfc/mfc-activex-controls.md) e [visão geral: Criando um programa de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md). Para obter informações sobre como otimizar os controles OLE, incluindo controles sem janelas e cintilação, consulte [controles ActiveX MFC: otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `COleControl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl.h  
  
##  <a name="a-nameambientbackcolora--colecontrolambientbackcolor"></a><a name="ambientbackcolor"></a>COleControl::AmbientBackColor  
 Retorna o valor da propriedade BackColor ambiente.  
  
```  
OLE_COLOR AmbientBackColor();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor atual do contêiner ambiente BackColor propriedade, se houver. Se a propriedade não é suportada, esta função retorna a cor de plano de fundo do Windows definidos pelo sistema.  
  
### <a name="remarks"></a>Comentários  
 A propriedade BackColor do ambiente está disponível para todos os controles e é definida pelo contêiner. Observe que o contêiner não é necessário para dar suporte a essa propriedade.  
  
##  <a name="a-nameambientdisplaynamea--colecontrolambientdisplayname"></a><a name="ambientdisplayname"></a>COleControl::AmbientDisplayName  
 O nome que do contêiner foi atribuído ao controle pode ser usado em mensagens de erro exibidas para o usuário.  
  
```  
CString AmbientDisplayName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do controle OLE. O padrão é uma cadeia de caracteres de comprimento zero.  
  
### <a name="remarks"></a>Comentários  
 Observe que o contêiner não é necessário para dar suporte a essa propriedade.  
  
##  <a name="a-nameambientfonta--colecontrolambientfont"></a><a name="ambientfont"></a>COleControl::AmbientFont  
 Retorna o valor da propriedade de fonte de ambiente.  
  
```  
LPFONTDISP AmbientFont();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a interface de expedição de fonte de ambiente do contêiner. O valor padrão é **nulo**. Se o retorno não é igual a **nulo**, você é responsável por liberar a fonte chamando seu [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms682317) função de membro.  
  
### <a name="remarks"></a>Comentários  
 A propriedade fonte do ambiente é definido pelo contêiner e disponível para todos os controles. Observe que o contêiner não é necessário para dar suporte a essa propriedade.  
  
##  <a name="a-nameambientforecolora--colecontrolambientforecolor"></a><a name="ambientforecolor"></a>COleControl::AmbientForeColor  
 Retorna o valor da propriedade ForeColor ambiente.  
  
```  
OLE_COLOR AmbientForeColor();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor atual do contêiner ambiente ForeColor propriedade, se houver. Se não houver suporte, esta função retorna a cor do texto definido pelo sistema Windows.  
  
### <a name="remarks"></a>Comentários  
 A propriedade ForeColor ambiente está disponível para todos os controles e é definida pelo contêiner. Observe que o contêiner não é necessário para dar suporte a essa propriedade.  
  
##  <a name="a-nameambientlocaleida--colecontrolambientlocaleid"></a><a name="ambientlocaleid"></a>COleControl::AmbientLocaleID  
 Retorna a ID da localidade. do contêiner  
  
```  
LCID AmbientLocaleID();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor da propriedade de identificação de localidade do contêiner, se houver. Se não há suporte para essa propriedade, essa função retornará 0.  
  
### <a name="remarks"></a>Comentários  
 O controle pode usar a identificação de localidade para adaptar sua interface do usuário para idiomas específicos. Observe que o contêiner não é necessário para dar suporte a essa propriedade.  
  
##  <a name="a-nameambientappearancea--colecontrolambientappearance"></a><a name="ambientappearance"></a>COleControl::AmbientAppearance  
 Recupera a configuração atual de aparência para o objeto de controle.  
  
```  
short AmbientAppearance();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A aparência do controle:  
  
- **0** simples aparência  
  
- **1** aparência 3D  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar o valor atual de **DISPID_AMBIENT_APPEARANCE** propriedade do controle.  
  
##  <a name="a-nameambientscaleunitsa--colecontrolambientscaleunits"></a><a name="ambientscaleunits"></a>COleControl::AmbientScaleUnits  
 Retorna o tipo de unidades usadas pelo contêiner.  
  
```  
CString AmbientScaleUnits();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém o ambiente ScaleUnits do contêiner. Se não há suporte para essa propriedade, essa função retorna uma cadeia de caracteres de comprimento zero.  
  
### <a name="remarks"></a>Comentários  
 Propriedade ScaleUnits de ambiente do contêiner pode ser usada para exibir posições ou dimensões, rotulados com a unidade escolhida, como twips ou centímetros. Observe que o contêiner não é necessário para dar suporte a essa propriedade.  
  
##  <a name="a-nameambientshowgrabhandlesa--colecontrolambientshowgrabhandles"></a><a name="ambientshowgrabhandles"></a>COleControl::AmbientShowGrabHandles  
 Determina se o contêiner permite o controle exibir as alças de captura para si mesmo quando ativo.  
  
```  
BOOL AmbientShowGrabHandles();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se captura alças devem ser exibidas; Caso contrário, 0. Se não há suporte para essa propriedade, essa função retorna zero.  
  
### <a name="remarks"></a>Comentários  
 Observe que o contêiner não é necessário para dar suporte a essa propriedade.  
  
##  <a name="a-nameambientshowhatchinga--colecontrolambientshowhatching"></a><a name="ambientshowhatching"></a>COleControl::AmbientShowHatching  
 Determina se o contêiner permite o controle para exibir a mesmo com um tracejada padrão quando ativo de interface do usuário.  
  
```  
BOOL AmbientShowHatching();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o padrão hachurado deve ser mostrado; Caso contrário, 0. Se não há suporte para essa propriedade, essa função retorna zero.  
  
### <a name="remarks"></a>Comentários  
 Observe que o contêiner não é necessário para dar suporte a essa propriedade.  
  
##  <a name="a-nameambienttextaligna--colecontrolambienttextalign"></a><a name="ambienttextalign"></a>COleControl::AmbientTextAlign  
 Determina o alinhamento do texto de ambiente preferido pelo contêiner de controle.  
  
```  
short AmbientTextAlign();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O status da propriedade TextAlign de ambiente do contêiner. Se não há suporte para essa propriedade, essa função retornará 0.  
  
 A seguir está uma lista de valores de retornos válidos:  
  
|Valor retornado|Significado|  
|------------------|-------------|  
|0|Alinhamento geral (números ao texto à direita, à esquerda).|  
|1|Justificar à esquerda|  
|2|Centralizado |  
|3|Justificar à direita|  
  
### <a name="remarks"></a>Comentários  
 Essa propriedade está disponível para todos os controles incorporados e é definida pelo contêiner. Observe que o contêiner não é necessário para dar suporte a essa propriedade.  
  
##  <a name="a-nameambientuideada--colecontrolambientuidead"></a><a name="ambientuidead"></a>COleControl::AmbientUIDead  
 Determina se o contêiner quiser o controle para responder às ações de interface do usuário.  
  
```  
BOOL AmbientUIDead();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle deve responder às ações de interface do usuário; Caso contrário, 0. Se não há suporte para essa propriedade, essa função retornará 0.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, um contêiner pode configurar isso para **TRUE** no modo de design.  
  
##  <a name="a-nameambientusermodea--colecontrolambientusermode"></a><a name="ambientusermode"></a>COleControl::AmbientUserMode  
 Determina se o contêiner está em modo de design ou modo de usuário.  
  
```  
BOOL AmbientUserMode();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o contêiner estiver no modo de usuário; Caso contrário, 0 (no modo de design). Se não há suporte para essa propriedade, essa função retornará TRUE.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, um contêiner pode configurar isso para **FALSE** no modo de design.  
  
##  <a name="a-nameboundpropertychangeda--colecontrolboundpropertychanged"></a><a name="boundpropertychanged"></a>COleControl::BoundPropertyChanged  
 Indica que o valor da propriedade associada foi alterado.  
  
```  
void BoundPropertyChanged(DISPID dispid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição de uma propriedade vinculada do controle.  
  
### <a name="remarks"></a>Comentários  
 Isso deve ser chamado sempre que o valor das alterações de propriedade, mesmo nos casos em que a alteração não foi feita por meio da propriedade método Set. Prestar atenção especial de propriedades associadas que são mapeadas para variáveis de membro. Sempre que tal um membro variável for alterado, `BoundPropertyChanged` deve ser chamado.  
  
##  <a name="a-nameboundpropertyrequestedita--colecontrolboundpropertyrequestedit"></a><a name="boundpropertyrequestedit"></a>COleControl::BoundPropertyRequestEdit  
 Solicitações de permissão do `IPropertyNotifySink` interface para alterar um valor de propriedade ligada fornecido pelo controle.  
  
```  
BOOL BoundPropertyRequestEdit(DISPID dispid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição de uma propriedade vinculada do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a alteração é permitida; Caso contrário, 0. O valor padrão é diferente de zero.  
  
### <a name="remarks"></a>Comentários  
 Se a permissão for negada, o controle não deve deixar o valor da alteração de propriedade. Isso pode ser feito por ignorando ou falha da ação que tentou alterar o valor da propriedade.  
  
##  <a name="a-nameclienttoparenta--colecontrolclienttoparent"></a><a name="clienttoparent"></a>COleControl::ClientToParent  
 Converte as coordenadas do `pPoint` em coordenadas pai.  
  
```  
virtual void ClientToParent(
    LPCRECT lprcBounds, 
    LPPOINT pPoint) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lprcBounds`  
 Ponteiro para os limites do controle OLE dentro do contêiner. A área do controle inteiro incluindo bordas e barras de rolagem, mas não a área do cliente.  
  
 `pPoint`  
 Ponteiro para o ponto de área de cliente OLE ser traduzida para as coordenadas do pai (contêiner).  
  
### <a name="remarks"></a>Comentários  
 Na entrada `pPoint` é relativo à origem da área do cliente do controle OLE (canto superior esquerdo da área do cliente do controle). Na saída `pPoint` é relativo à origem do pai (canto superior esquerdo do contêiner).  
  
##  <a name="a-nameclipcaretrecta--colecontrolclipcaretrect"></a><a name="clipcaretrect"></a>COleControl::ClipCaretRect  
 Ajusta um retângulo de cursor se ele for parcial ou totalmente coberto pelos objetos sobrepostos, opacos.  
  
```  
BOOL ClipCaretRect(LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Na entrada, um ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) estrutura que contém a área de cursor a ser ajustado. Na saída, a área de cursor ajustado, ou **nulo** se o retângulo do cursor é completamente coberto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um cursor é uma linha, bloquear ou bitmap que normalmente indica onde texto ou elementos gráficos serão inseridos intermitente.  
  
 Um objeto sem janelas com segurança não pode mostrar um cursor sem verificar primeiro se o cursor está parcialmente ou totalmente oculta por objetos sobrepostos. Para que possibilitam, pode usar um objeto `ClipCaretRect` para obter o cursor ajustado (reduzido) para garantir que ela se encaixa na região de recorte.  
  
 Criando um cursor de objetos devem enviar o retângulo de cursor para `ClipCaretRect` e usar o retângulo ajustado para o cursor. Se o cursor estiver totalmente oculto, este método retornará **FALSE** e o cursor não deve ser mostrado em todos os nesse caso.  
  
##  <a name="a-namecolecontrola--colecontrolcolecontrol"></a><a name="colecontrol"></a>COleControl::COleControl  
 Constrói um objeto `COleControl`.  
  
```  
COleControl();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função normalmente não é chamada diretamente. Em vez disso, o controle OLE é geralmente criado por sua fábrica de classes.  
  
##  <a name="a-namecontrolinfochangeda--colecontrolcontrolinfochanged"></a><a name="controlinfochanged"></a>COleControl::ControlInfoChanged  
 Chame essa função quando o conjunto de mnemônicos suportados pelo controle é alterada.  
  
```  
void ControlInfoChanged();
```  
  
### <a name="remarks"></a>Comentários  
 Ao receber esta notificação, o contêiner do controle obtém o novo conjunto de mnemônicos, fazendo uma chamada para [IOleControl::GetControlInfo](http://msdn.microsoft.com/library/windows/desktop/ms693730). Observe que o contêiner não é necessário para responder a essa notificação.  
  
##  <a name="a-namedisplayerrora--colecontroldisplayerror"></a><a name="displayerror"></a>COleControl::DisplayError  
 Chamado pela estrutura depois que o evento de erro de estoque foi tratado (a menos que o manipulador de eventos tiver suprimido a exibição do erro).  
  
```  
virtual void DisplayError(
    SCODE scode,  
    LPCTSTR lpszDescription,  
    LPCTSTR lpszSource,  
    LPCTSTR lpszHelpFile,  
    UINT nHelpID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *SCODE*  
 O valor de código de status a ser relatado. Para obter uma lista completa de códigos de possíveis, consulte o artigo [controles ActiveX: tópicos avançados](../../mfc/mfc-activex-controls-advanced-topics.md).  
  
 `lpszDescription`  
 A descrição do erro está sendo relatado.  
  
 *lpszSource*  
 O nome do módulo gera o erro (normalmente, o nome do módulo de controle OLE).  
  
 `lpszHelpFile`  
 O nome do arquivo de Ajuda que contém uma descrição do erro.  
  
 `nHelpID`  
 A ID do contexto de Ajuda do erro está sendo relatado.  
  
### <a name="remarks"></a>Comentários  
 O comportamento padrão exibe uma caixa de mensagem que contém a descrição do erro, contido no `lpszDescription`.  
  
 Substitua essa função para personalizar como os erros são exibidos.  
  
##  <a name="a-namedoclicka--colecontroldoclick"></a><a name="doclick"></a>COleControl::DoClick  
 Simula um mouse clique em ação no controle.  
  
```  
void DoClick();
```  
  
### <a name="remarks"></a>Comentários  
 O substituível `COleControl::OnClick` será chamada uma função de membro e um clique em evento será acionado, se houver suporte o controle de estoque.  
  
 Essa função é suportado pelo `COleControl` classe base como um método de estoque, chamado DoClick. Para obter mais informações, consulte o artigo [controles ActiveX: métodos](../../mfc/mfc-activex-controls-methods.md).  
  
##  <a name="a-namedopropexchangea--colecontroldopropexchange"></a><a name="dopropexchange"></a>COleControl::DoPropExchange  
 Chamado pela estrutura ao carregar ou armazenar um controle de uma representação de armazenamento persistente, como um conjunto de fluxo ou propriedade.  
  
```  
virtual void DoPropExchange(CPropExchange* pPX);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Um ponteiro para um `CPropExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de propriedade, incluindo sua direção.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função faz chamadas para o **PX_** família de funções para carregar ou armazenar propriedades específicas definidas pelo usuário de um controle OLE.  
  
 Se o Assistente de controle tiver sido usado para criar o projeto de controle OLE, a versão substituída dessa função serializa as propriedades das ações suportadas pelo `COleControl` com uma chamada para a função de classe base, `COleControl::DoPropExchange`. Conforme você adiciona propriedades definidas pelo usuário para seu controle OLE, você precisará modificar essa função para serializar as novas propriedades. Para obter mais informações sobre serialização, consulte o artigo [controles ActiveX: serializando](../../mfc/mfc-activex-controls-serializing.md).  
  
##  <a name="a-namedosuperclasspainta--colecontroldosuperclasspaint"></a><a name="dosuperclasspaint"></a>COleControl::DoSuperclassPaint  
 Redesenha a um controle OLE que tenha sido derivado de um controle do Windows.  
  
```  
void DoSuperclassPaint(
    CDC* pDC,  
    const CRect& rcBounds);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para o contexto de dispositivo do contêiner de controle.  
  
 `rcBounds`  
 A área na qual o controle será desenhado.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para manipular adequadamente a pintura de um controle OLE inativo. Essa função só deve ser usada se o OLE controla subclasses de um controle do Windows e deve ser chamado no `OnDraw` função do seu controle.  
  
 Para obter mais informações sobre esta função e subclasses de um controle do Windows, consulte o artigo [controles ActiveX: subclasses de um controle de Windows](../../mfc/mfc-activex-controls-subclassing-a-windows-control.md).  
  
##  <a name="a-namedrawcontenta--colecontroldrawcontent"></a><a name="drawcontent"></a>COleControl::DrawContent  
 Chamado pela estrutura quando a aparência do controle precisa ser atualizado.  
  
```  
void DrawContent(
    CDC* pDC,  
    CRect& rc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para o contexto do dispositivo.  
  
 `rc`  
 Área retangular a ser desenhada em.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama diretamente o substituível `OnDraw` função.  
  
##  <a name="a-namedrawmetafilea--colecontroldrawmetafile"></a><a name="drawmetafile"></a>COleControl::DrawMetafile  
 Chamado pela estrutura quando o contexto de dispositivo de metarquivo está sendo usado.  
  
```  
void DrawMetafile(
    CDC* pDC,  
    CRect& rc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para o contexto de dispositivo de metarquivo.  
  
 `rc`  
 Área retangular a ser desenhada em.  
  
##  <a name="a-nameenablesimpleframea--colecontrolenablesimpleframe"></a><a name="enablesimpleframe"></a>COleControl::EnableSimpleFrame  
 Habilita a característica de quadro simples para um controle OLE.  
  
```  
void EnableSimpleFrame();
```  
  
### <a name="remarks"></a>Comentários  
 Essa característica permite um controle dar suporte a visual confinamento de outros controles, mas isso não é verdade confinamento de OLE. Um exemplo seria com vários controles dentro de uma caixa de grupo. Esses controles não são OLE contido, mas eles estão na mesma caixa de grupo.  
  
##  <a name="a-nameexchangeextenta--colecontrolexchangeextent"></a><a name="exchangeextent"></a>COleControl::ExchangeExtent  
 Serializa ou inicializa o estado da extensão do controle (suas dimensões em **HIMETRIC** unidades).  
  
```  
BOOL ExchangeExtent(CPropExchange* pPX);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Um ponteiro para um [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto. O framework fornece esse objeto para estabelecer o contexto de troca de propriedade, incluindo sua direção.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função é chamada pela implementação padrão de `COleControl::DoPropExchange`.  
  
##  <a name="a-nameexchangestockpropsa--colecontrolexchangestockprops"></a><a name="exchangestockprops"></a>COleControl::ExchangeStockProps  
 Serializa ou inicializa o estado do controle propriedades de estoque.  
  
```  
void ExchangeStockProps(CPropExchange* pPX);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Um ponteiro para um [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto. O framework fornece esse objeto para estabelecer o contexto de troca de propriedade, incluindo sua direção.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa função é chamada pela implementação padrão de `COleControl::DoPropExchange`.  
  
##  <a name="a-nameexchangeversiona--colecontrolexchangeversion"></a><a name="exchangeversion"></a>COleControl::ExchangeVersion  
 Serializa ou inicializa o estado das informações de versão do controle.  
  
```  
BOOL ExchangeVersion(
    CPropExchange* pPX,  
    DWORD dwVersionDefault,  
    BOOL bConvert = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Um ponteiro para um `CPropExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de propriedade, incluindo sua direção.  
  
 `dwVersionDefault`  
 O número de versão atual do controle.  
  
 `bConvert`  
 Indica se os dados persistentes devem ser convertidos para o formato mais recente quando salvo ou mantidos no mesmo formato que foi carregado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero da função foi bem-sucedida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, isso será a primeira função chamada pela substituição do controle de `COleControl::DoPropExchange`. Ao carregar, essa função lê o número de versão dos dados persistentes e define o atributo da versão do [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto adequadamente. Ao salvar, essa função grava o número de versão dos dados persistentes.  
  
 Para obter mais informações sobre como persistência e controle de versão, consulte o artigo [controles ActiveX: serializando](../../mfc/mfc-activex-controls-serializing.md).  
  
##  <a name="a-namefireclicka--colecontrolfireclick"></a><a name="fireclick"></a>COleControl::FireClick  
 Chamado pela estrutura quando o mouse é clicado sobre um controle ativo.  
  
```  
void FireClick();
```  
  
### <a name="remarks"></a>Comentários  
 Se esse evento é definido como um evento personalizado, você deve determinar quando o evento é disparado.  
  
 Para acionamento automático de um evento de clique a ocorrer, o mapa de evento do controle deve ter uma ação, clique em eventos definidos.  
  
##  <a name="a-namefiredblclicka--colecontrolfiredblclick"></a><a name="firedblclick"></a>COleControl::FireDblClick  
 Chamado pela estrutura quando o mouse é clicado duas vezes em um controle ativo.  
  
```  
void FireDblClick();
```  
  
### <a name="remarks"></a>Comentários  
 Se esse evento é definido como um evento personalizado, você deve determinar quando o evento é disparado.  
  
 Para acionamento automático de um evento DblClick ocorrer, o mapa de evento do controle deve ter um evento DblClick estoque definido.  
  
##  <a name="a-namefireerrora--colecontrolfireerror"></a><a name="fireerror"></a>COleControl::FireError  
 Dispara o evento de erro de estoque.  
  
```  
void FireError(
    SCODE scode,  
    LPCTSTR lpszDescription,  
    UINT nHelpID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *SCODE*  
 O valor de código de status a ser relatado. Para obter uma lista completa de códigos de possíveis, consulte o artigo [controles ActiveX: tópicos avançados](../../mfc/mfc-activex-controls-advanced-topics.md).  
  
 `lpszDescription`  
 A descrição do erro está sendo relatado.  
  
 `nHelpID`  
 A identificação de Ajuda do erro está sendo relatado.  
  
### <a name="remarks"></a>Comentários  
 Esse evento fornece uma maneira de sinalização em locais apropriados no seu código, que ocorreu um erro dentro de seu controle. Ao contrário de outros eventos de estoque, como clique ou MouseMove, erro nunca é acionado pela estrutura.  
  
 Para relatar um erro que ocorre durante uma função de get de propriedade, função de conjunto de propriedade ou método de automação, chame [COleControl::ThrowError](#throwerror).  
  
 A implementação do erro de estoque de um controle OLE evento usa um `SCODE` valor. Se o controle usa esse evento e se destina a ser usado no Visual Basic 4.0, você receberá erros porque o `SCODE` valor não é suportado no Visual Basic.  
  
 Para corrigir esse problema, altere manualmente a `SCODE` parâmetro do controle. Arquivo ODL um **longo**. Além disso, qualquer evento personalizado, método ou propriedade que usa um `SCODE` parâmetro também faz com que o mesmo problema.  
  
##  <a name="a-namefireeventa--colecontrolfireevent"></a><a name="fireevent"></a>COleControl::FireEvent  
 Dispara um evento definido pelo usuário de seu controle com qualquer número de argumentos opcionais.  
  
```  
void AFX_CDECL FireEvent(
    DISPID dispid,  
    BYTE* pbParams,  
 ...);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição do evento seja acionado.  
  
 `pbParams`  
 Um descritor de tipos de parâmetro do evento.  
  
### <a name="remarks"></a>Comentários  
 Geralmente essa função não deve ser chamada diretamente. Em vez disso, você chamará as funções de acionamento de evento na seção de mapa de evento da declaração de classe do controle.  
  
 O `pbParams` argumento é uma lista separada por espaço de **VTS_**. Um ou mais desses valores, separados por espaços (não vírgulas), especifica a lista de parâmetros da função. Os valores possíveis são:  
  
|Símbolo|Tipo de parâmetro|  
|------------|--------------------|  
|**VTS_COLOR**|**OLE_COLOR**|  
|**VTS_FONT**|**IFontDisp\***|  
|**VTS_HANDLE**|`HWND`|  
|**VTS_PICTURE**|**IPictureDisp\***|  
|**VTS_OPTEXCLUSIVE**|**OLE_OPTEXCLUSIVE\***|  
|**VTS_TRISTATE**|**OLE_TRISTATE**|  
|**VTS_XPOS_HIMETRIC**|**OLE_XPOS_HIMETRIC**|  
|**VTS_YPOS_HIMETRIC**|**OLE_YPOS_HIMETRIC**|  
|**VTS_XPOS_PIXELS**|**OLE_XPOS_PIXELS**|  
|**VTS_YPOS_PIXELS**|**OLE_YPOS_PIXELS**|  
|**VTS_XSIZE_PIXELS**|**OLE_XSIZE_PIXELS**|  
|**VTS_YSIZE_PIXELS**|**OLE_XSIZE_PIXELS**|  
|**VTS_XSIZE_HIMETRIC**|**OLE_XSIZE_HIMETRIC**|  
|**VTS_YSIZE_HIMETRIC**|**OLE_XSIZE_HIMETRIC**|  
  
> [!NOTE]
>  Constantes variantes adicionais foram definidas para todos os tipos variantes, com exceção de **VTS_FONT** e **VTS_PICTURE**, que fornecem um ponteiro para a constante de dados variant. Essas constantes são nomeados usando o **VTS_P** `constantname` convenção. Por exemplo, **VTS_PCOLOR** é um ponteiro para um **VTS_COLOR** constante.  
  
##  <a name="a-namefirekeydowna--colecontrolfirekeydown"></a><a name="firekeydown"></a>COleControl::FireKeyDown  
 Chamado pela estrutura quando uma tecla é pressionada enquanto o controle é a interface de usuário ativa.  
  
```  
void FireKeyDown(
    USHORT* pnChar,  
    short nShiftState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pnChar`  
 Ponteiro para o valor de código de tecla virtual da tecla pressionada. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h  
  
 `nShiftState`  
 Contém uma combinação dos sinalizadores a seguir:  
  
- **SHIFT_MASK** foi pressionada a tecla SHIFT durante a ação.  
  
- **CTRL_MASK** o CTRL foi pressionada durante a ação.  
  
- **ALT_MASK** o ALT foi pressionada durante a ação.  
  
### <a name="remarks"></a>Comentários  
 Se esse evento é definido como um evento personalizado, você deve determinar quando o evento é disparado.  
  
 Para acionamento automático de um evento KeyDown ocorra, o mapa de evento do controle deve ter um evento KeyDown estoque definido.  
  
##  <a name="a-namefirekeypressa--colecontrolfirekeypress"></a><a name="firekeypress"></a>COleControl::FireKeyPress  
 Chamado pela estrutura quando uma tecla é pressionada e liberada enquanto o controle personalizado está ativo de interface do usuário dentro do contêiner.  
  
```  
void FireKeyPress(USHORT* pnChar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pnChar`  
 Um ponteiro para o valor do caractere da tecla pressionada.  
  
### <a name="remarks"></a>Comentários  
 Se esse evento é definido como um evento personalizado, você deve determinar quando o evento é disparado.  
  
 O destinatário do evento pode modificar `pnChar`, por exemplo, converter todos os caracteres minúsculos em maiusculos. Se você quiser examinar o caractere modificado, substituir `OnKeyPressEvent`.  
  
 Para acionamento automático de um evento KeyPress ocorra, o mapa de evento do controle deve ter um evento KeyPress estoque definido.  
  
##  <a name="a-namefirekeyupa--colecontrolfirekeyup"></a><a name="firekeyup"></a>COleControl::FireKeyUp  
 Chamado pela estrutura quando uma tecla é liberada enquanto o controle personalizado está ativo de interface do usuário dentro do contêiner.  
  
```  
void FireKeyUp(
    USHORT* pnChar,  
    short nShiftState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pnChar`  
 Ponteiro para o valor de código de tecla virtual da chave lançada. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h  
  
 `nShiftState`  
 Contém uma combinação dos sinalizadores a seguir:  
  
- **SHIFT_MASK** foi pressionada a tecla SHIFT durante a ação.  
  
- **CTRL_MASK** o CTRL foi pressionada durante a ação.  
  
- **ALT_MASK** o ALT foi pressionada durante a ação.  
  
### <a name="remarks"></a>Comentários  
 Se esse evento é definido como um evento personalizado, você deve determinar quando o evento é disparado.  
  
 Para acionamento automático de um evento KeyUp ocorra, o mapa de evento do controle deve ter um evento KeyUp estoque definido.  
  
##  <a name="a-namefiremousedowna--colecontrolfiremousedown"></a><a name="firemousedown"></a>COleControl::FireMouseDown  
 Chamado pela estrutura quando um botão do mouse é pressionado sobre um controle personalizado ativo.  
  
```  
void FireMouseDown(
    short nButton,  
    short nShiftState,  
    OLE_XPOS_PIXELS x,  
    OLE_YPOS_PIXELS y);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nButton`  
 O valor numérico do botão do mouse pressionado. Ele pode conter um dos seguintes valores:  
  
- **LEFT_BUTTON** o botão esquerdo do mouse foi pressionado.  
  
- **MIDDLE_BUTTON** o botão do meio foi pressionado.  
  
- **RIGHT_BUTTON** o botão direito do mouse foi pressionado.  
  
 `nShiftState`  
 Contém uma combinação dos sinalizadores a seguir:  
  
- **SHIFT_MASK** foi pressionada a tecla SHIFT durante a ação.  
  
- **CTRL_MASK** o CTRL foi pressionada durante a ação.  
  
- **ALT_MASK** o ALT foi pressionada durante a ação.  
  
 *x*  
 A coordenada x do cursor quando um botão do mouse foi pressionado. A coordenada é relativa ao canto superior esquerdo da janela do controle.  
  
 *y*  
 A coordenada y do cursor quando um botão do mouse foi pressionado. A coordenada é relativa ao canto superior esquerdo da janela do controle.  
  
### <a name="remarks"></a>Comentários  
 Se esse evento é definido como um evento personalizado, você deve determinar quando o evento é disparado.  
  
 Para acionamento automático de um evento MouseDown ocorra, o mapa de evento do controle deve ter um evento MouseDown estoque definido.  
  
##  <a name="a-namefiremousemovea--colecontrolfiremousemove"></a><a name="firemousemove"></a>COleControl::FireMouseMove  
 Chamado pela estrutura quando o cursor é movido sobre um controle personalizado ativo.  
  
```  
void FireMouseMove(
    short nButton,  
    short nShiftState,  
    OLE_XPOS_PIXELS x,  
    OLE_YPOS_PIXELS y);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nButton`  
 O valor numérico dos botões do mouse pressionado. Contém uma combinação dos seguintes valores:  
  
- **LEFT_BUTTON** o botão esquerdo foi pressionado durante a ação.  
  
- **MIDDLE_BUTTON** o botão do meio foi pressionado durante a ação.  
  
- **RIGHT_BUTTON** o botão direito do mouse foi pressionado durante a ação.  
  
 `nShiftState`  
 Contém uma combinação dos sinalizadores a seguir:  
  
- **SHIFT_MASK** foi pressionada a tecla SHIFT durante a ação.  
  
- **CTRL_MASK** o CTRL foi pressionada durante a ação.  
  
- **ALT_MASK** o ALT foi pressionada durante a ação.  
  
 *x*  
 A coordenada x do cursor. A coordenada é relativa ao canto superior esquerdo da janela do controle.  
  
 *y*  
 A coordenada y do cursor. A coordenada é relativa ao canto superior esquerdo da janela do controle.  
  
### <a name="remarks"></a>Comentários  
 Se esse evento é definido como um evento personalizado, você deve determinar quando o evento é disparado.  
  
 Para acionamento automático de um evento MouseMove ocorra, o mapa de evento do controle deve ter um evento MouseMove estoque definido.  
  
##  <a name="a-namefiremouseupa--colecontrolfiremouseup"></a><a name="firemouseup"></a>COleControl::FireMouseUp  
 Chamado pela estrutura quando um botão do mouse é solto sobre um controle personalizado ativo.  
  
```  
void FireMouseUp(
    short nButton,  
    short nShiftState,  
    OLE_XPOS_PIXELS x,  
    OLE_YPOS_PIXELS y);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nButton`  
 O valor numérico do botão do mouse liberado. Ele pode ter um dos seguintes valores:  
  
- **LEFT_BUTTON** o botão esquerdo foi liberado.  
  
- **MIDDLE_BUTTON** o botão do meio foi lançado.  
  
- **RIGHT_BUTTON** o botão direito do mouse foi lançado.  
  
 `nShiftState`  
 Contém uma combinação dos sinalizadores a seguir:  
  
- **SHIFT_MASK** foi pressionada a tecla SHIFT durante a ação.  
  
- **CTRL_MASK** o CTRL foi pressionada durante a ação.  
  
- **ALT_MASK** o ALT foi pressionada durante a ação.  
  
 *x*  
 A coordenada x do cursor quando um botão do mouse foi lançado. A coordenada é relativa ao canto superior esquerdo da janela do controle.  
  
 *y*  
 A coordenada y de um cursor quando um botão do mouse foi lançado. A coordenada é relativa ao canto superior esquerdo da janela do controle.  
  
### <a name="remarks"></a>Comentários  
 Se esse evento é definido como um evento personalizado, você deve determinar quando o evento é disparado.  
  
 Para acionamento automático de um evento MouseUp ocorra, o mapa de evento do controle deve ter um evento MouseUp estoque definido.  
  
##  <a name="a-namefirereadystatechangea--colecontrolfirereadystatechange"></a><a name="firereadystatechange"></a>COleControl::FireReadyStateChange  
 Dispara um evento com o valor atual do estado pronto do controle.  
  
```  
void FireReadyStateChange();
```  
  
### <a name="remarks"></a>Comentários  
 O estado pronto pode ser um dos seguintes valores:  
  
 **READYSTATE_UNINITIALIZED**  
 Estado de inicialização padrão  
  
 **READYSTATE_LOADING**  
 Controle atualmente está carregando suas propriedades  
  
 **READYSTATE_LOADED**  
 Controle foi inicializado  
  
 **READYSTATE_INTERACTIVE**  
 Controle tem dados suficientes para ser interativa, mas dados não assíncronos ainda são carregados  
  
 `READYSTATE_COMPLETE`  
 Controle tem todos os seus dados  
  
 Use [GetReadyState](#getreadystate) para determinar a preparação atual do controle.  
  
 [InternalSetReadyState](#internalsetreadystate) altera o estado pronto para o valor fornecido e, em seguida, chama `FireReadyStateChange`.  
  
##  <a name="a-namegetactivationpolicya--colecontrolgetactivationpolicy"></a><a name="getactivationpolicy"></a>COleControl::GetActivationPolicy  
 Altera o comportamento padrão de ativação de um controle que suporta o `IPointerInactive` interface.  
  
```  
virtual DWORD GetActivationPolicy();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação de sinalizadores do **POINTERINACTIVE** enumeração. Sinalizadores de possíveis são:  
  
 **POINTERINACTIVE_ACTIVATEONENTRY**  
 O objeto deve ser ativado quando o mouse passa sobre ele durante uma operação de movimentação do mouse no local.  
  
 **POINTERINACTIVE_DEACTIVATEONLEAVE**  
 O objeto deve ser desativado quando o mouse sai do objeto durante uma operação de movimentação do mouse.  
  
 **POINTERINACTIVE_ACTIVATEONDRAG**  
 O objeto deve ser local ativado quando o mouse é arrastado sobre ele durante uma operação arrastar e soltar a operação.  
  
### <a name="remarks"></a>Comentários  
 Quando o `IPointerInactive` interface está habilitada, o contêiner delegará `WM_SETCURSOR` e `WM_MOUSEMOVE` mensagens a ele. `COleControl`da implementação dessa interface enviará essas mensagens por meio do mapa da mensagem do controle, depois de ajustar o mouse coordena adequadamente.  
  
 Sempre que o contêiner recebe um `WM_SETCURSOR` ou `WM_MOUSEMOVE` mensagem com o ponteiro do mouse sobre um objeto inativo que oferece suporte `IPointerInactive`, é necessário chamar `GetActivationPolicy` na interface e sinalizadores de retornos do **POINTERINACTIVE** enumeração.  
  
 Você pode processar essas mensagens apenas como mensagens de janela comum, adicionando as entradas correspondentes ao mapa da mensagem. Em seus manipuladores, evite usar o `m_hWnd` variável de membro (ou quaisquer funções de membro que utiliza) sem primeiro verificar se o valor é não - **nulo**.  
  
 Qualquer objeto destinado a mais do que definir o cursor do mouse e/ou disparar um evento de movimentação do mouse, tais como fornecer feedback visual especial, devem retornar o **POINTERINACTIVE_ACTIVATEONENTRY** sinalizar e desenhar os comentários quando ativo. Se o objeto retorna esse sinalizador, o contêiner deve ativá-lo em vigor imediatamente e encaminhá-la a mesma mensagem que disparou a chamada para `GetActivationPolicy`.  
  
 Se o **POINTERINACTIVE_ACTIVATEONENTRY** e **POINTERINACTIVE_DEACTIVATEONLEAVE** sinalizadores são retornados, em seguida, o objeto só será ativado quando o mouse está sobre o objeto. Se apenas o **POINTERINACTIVE_ACTIVATEONENTRY** sinalizador é retornado, em seguida, o objeto somente será ativado quando quando o mouse entra pela primeira vez o objeto.  
  
 Você também pode ser um controle inativo para ser o destino de arrastar um OLE e solte a operação. Isso requer ativando o controle no momento em que o usuário arrasta um objeto, para que a janela do controle pode ser registrada como um destino de soltar. Para fazer com que a ativação ocorre durante uma operação arrastar, retornar o **POINTERINACTIVE_ACTIVATEONDRAG** sinalizador:  
  
 [!code-cpp[NVC_MFCAxCtl n º&1;](../../mfc/reference/codesnippet/cpp/colecontrol-class_1.cpp)]  
  
 As informações comunicadas por `GetActivationPolicy` não deverão ficar em cache por um contêiner. Em vez disso, esse método deve ser chamado sempre que o mouse passa sobre um objeto inativo.  
  
 Se um objeto inativo não solicitar para ser ativado quando o mouse passa sobre ele no local, o contêiner deve expedir subsequentes `WM_SETCURSOR` mensagens para esse objeto chamando [OnInactiveSetCursor](#oninactivesetcursor) enquanto o ponteiro do mouse fica sobre o objeto.  
  
 Habilitando o `IPointerInactive` interface normalmente significa que você deseja que o controle seja capaz de processar mensagens do mouse em todos os momentos. Para obter esse comportamento em um contêiner que não oferece suporte a `IPointerInactive` interface, você precisará ter o controle sempre ativado quando visível, que significa que o controle deve ter o **OLEMISC_ACTIVATEWHENVISIBLE** sinalizador entre seus diversos sinalizadores. No entanto, para evitar que esse sinalizador de levar o efeito em um contêiner que dá suporte `IPointerInactive`, você também pode especificar o **OLEMISC_IGNOREACTIVATEWHENVISIBLE** sinalizador:  
  
 [!code-cpp[NVC_MFCAxCtl n º&10;](../../mfc/reference/codesnippet/cpp/colecontrol-class_2.cpp)]  
  
##  <a name="a-namegetambientpropertya--colecontrolgetambientproperty"></a><a name="getambientproperty"></a>COleControl::GetAmbientProperty  
 Obtém o valor de uma propriedade de ambiente do contêiner.  
  
```  
BOOL GetAmbientProperty(
    DISPID dispid,  
    VARTYPE vtProp,  
    void* pvProp);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwDispid*  
 A ID de expedição da propriedade ambiente desejada.  
  
 `vtProp`  
 Uma marca de tipo variant que especifica o tipo do valor a ser retornado em `pvProp`.  
  
 `pvProp`  
 Um ponteiro para o endereço da variável que receberá o valor da propriedade ou valor de retorno. O tipo real deste ponteiro deve corresponder ao tipo especificado pelo `vtProp`.  
  
|vtProp|Tipo de pvProp|  
|------------|--------------------|  
|`VT_BOOL`|**BOOL\***|  
|`VT_BSTR`|**CString\***|  
|`VT_I2`|**curto\***|  
|`VT_I4`|**Longas\***|  
|`VT_R4`|**float\***|  
|`VT_R8`|**duplo\***|  
|`VT_CY`|**CY\***|  
|**VT_COLOR**|**OLE_COLOR\***|  
|**VT_DISPATCH**|**LPDISPATCH\***|  
|**VT_FONT**|**LPFONTDISP\***|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se há suporte para a propriedade do ambiente; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se você usar `GetAmbientProperty` para recuperar as propriedades DisplayName e ScaleUnits ambiente, defina `vtProp` para `VT_BSTR` e `pvProp` para **CString\***. Se você estiver recuperando a propriedade fonte do ambiente, defina `vtProp` para **VT_FONT** e `pvProp` para **LPFONTDISP\***.  
  
 Observe que funções já foram fornecidas para propriedades comuns do ambiente, como [AmbientBackColor](#ambientbackcolor) e [AmbientFont](#ambientfont).  
  
##  <a name="a-namegetappearancea--colecontrolgetappearance"></a><a name="getappearance"></a>COleControl::GetAppearance  
 Implementa a função Get de propriedade das ações de aparência do controle.  
  
```  
short GetAppearance ();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno Especifica a configuração de aparência atual como uma **curto** ( `VT_I2`) valor, se for bem-sucedido. Esse valor é zero se a aparência do controle é simples e 1 se a aparência do controle é 3D.  
  
##  <a name="a-namegetbackcolora--colecontrolgetbackcolor"></a><a name="getbackcolor"></a>COleControl::GetBackColor  
 Implementa a função Get da propriedade BackColor de estoque do controle.  
  
```  
OLE_COLOR GetBackColor();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno Especifica a cor de plano de fundo atual como uma **OLE_COLOR** valor, se for bem-sucedido. Esse valor pode ser convertido para um **COLORREF** valor com uma chamada para `TranslateColor`.  
  
##  <a name="a-namegetborderstylea--colecontrolgetborderstyle"></a><a name="getborderstyle"></a>COleControl::GetBorderStyle  
 Implementa a função Get de propriedade BorderStyle de estoque do controle.  
  
```  
short GetBorderStyle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 1 se o controle terá uma borda normal; 0 se o controle não tem nenhuma borda.  
  
##  <a name="a-namegetcapturea--colecontrolgetcapture"></a><a name="getcapture"></a>COleControl::GetCapture  
 Determina se o `COleControl` objeto tem a captura do mouse.  
  
```  
CWnd* GetCapture();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o controle é ativado e sem janelas, retornará **isso** se o controle tem a captura do mouse (conforme determinado pelo contêiner do controle), ou **nulo** se não tiver a captura.  
  
 Caso contrário, retorna o `CWnd` objeto que tem a captura do mouse (mesmo que `CWnd::GetCapture`).  
  
### <a name="remarks"></a>Comentários  
 Um controle sem janelas ativado recebe o mouse capturar quando [SetCapture](#setcapture) é chamado.  
  
##  <a name="a-namegetclassida--colecontrolgetclassid"></a><a name="getclassid"></a>COleControl::GetClassID  
 Chamado pela estrutura para recuperar a ID de classe OLE do controle.  
  
```  
virtual HRESULT GetClassID(LPCLSID pclsid) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pclsid*  
 Ponteiro para o local da ID da classe.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chamada não foi bem sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Geralmente é implementado pelo [IMPLEMENT_OLECREATE_EX](class-factories-and-licensing.md#implement_olecreate_ex).  
  
##  <a name="a-namegetclientoffseta--colecontrolgetclientoffset"></a><a name="getclientoffset"></a>COleControl::GetClientOffset  
 Recupera a diferença entre o canto superior esquerdo da área retangular do controle e o canto superior esquerdo da sua área de cliente.  
  
```  
virtual void GetClientOffset(long* pdxOffset, long* pdyOffset) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pdxOffset*  
 Ponteiro para o deslocamento horizontal da área do cliente do controle OLE.  
  
 *pdyOffset*  
 Ponteiro para o deslocamento vertical da área do cliente do controle OLE.  
  
### <a name="remarks"></a>Comentários  
 O controle OLE tem uma área retangular dentro do seu contêiner. O cliente do controle é a área de controle excluindo bordas e barras de rolagem. O deslocamento é recuperada por `GetClientOffset` é a diferença entre o canto superior esquerdo da área retangular do controle e o canto superior esquerdo da sua área de cliente. Se o controle tiver elementos não clientes diferentes do padrão bordas e barras de rolagem, substitua essa função de membro para especificar o deslocamento.  
  
##  <a name="a-namegetclientrecta--colecontrolgetclientrect"></a><a name="getclientrect"></a>COleControl::GetClientRect  
 Recupera o tamanho da área do cliente do controle.  
  
```  
virtual void GetClientRect(LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Ponteiro para uma `RECT` estrutura que contém as dimensões da área do cliente do controle sem janelas; ou seja, o tamanho do controle menos bordas das janelas, quadros, barras de rolagem e assim por diante. O `lpRect` parâmetro indica o tamanho do retângulo do cliente do controle, não sua posição.  
  
##  <a name="a-namegetclientsitea--colecontrolgetclientsite"></a><a name="getclientsite"></a>COleControl::GetClientSite  
 Consultas de um objeto para o ponteiro para o seu site atual do cliente dentro do seu contêiner.  
  
```  
LPOLECLIENTSITE GetClientSite();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o site de cliente atual do controle em seu contêiner.  
  
### <a name="remarks"></a>Comentários  
 O ponteiro retornado aponta para uma instância de `IOleClientSite`. O `IOleClientSite` interface implementada por contêineres, é o modo de exibição do objeto de seu contexto: onde ela está ancorada no documento, onde ele obtém seu armazenamento, a interface do usuário e outros recursos.  
  
##  <a name="a-namegetcontrolflagsa--colecontrolgetcontrolflags"></a><a name="getcontrolflags"></a>COleControl::GetControlFlags  
 Recupera as configurações de sinalizador de controle.  
  
```  
virtual DWORD GetControlFlags();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação ORed dos sinalizadores na enumeração ControlFlags:  
  
 `enum ControlFlags {`  
  
 `fastBeginPaint = 0x0001,`  
  
 `clipPaintDC = 0x0002,`  
  
 `pointerInactive = 0x0004,`  
  
 `noFlickerActivate = 0x0008,`  
  
 `windowlessActivate = 0x0010,`  
  
 `canOptimizeDraw = 0x0020,`  
  
 `};`  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `GetControlFlags` retorna `fastBeginPaint | clipPaintDC`.  
  
 `fastBeginPaint`  
 Se definido, usa uma pintura begin função personalizada para controles OLE em vez do [BeginPaint](http://msdn.microsoft.com/library/windows/desktop/dd183362) API (definido por padrão).  
  
 `clipPaintDC`  
 Se não for definido, desabilita a chamada para `IntersectClipRect` feitas pelo `COleControl` e obtém uma vantagem da velocidade pequeno. Se você estiver usando ativação sem janelas, o sinalizador não tem efeito.  
  
 `pointerInactive`  
 Se definido, fornece interação do mouse enquanto o controle estiver inativo, permitindo `COleControl`da implementação do `IPointerInactive` interface, que é desativado por padrão.  
  
 `noFlickerActivate`  
 Se definido, elimina a cintilação visual que acompanha este artigo e operações de desenho extra. Use quando o controle desenha próprio idênticos nos Estados inativos e ativos. Se você estiver usando ativação sem janelas, o sinalizador não tem efeito.  
  
 `windowlessActivate`  
 Se configurado, indica que o controle usa ativação sem janelas.  
  
 `canOptimizeDraw`  
 Se configurado, indica que o controle irá executar desenho otimizado, se o contêiner for compatível.  
  
 Para obter mais informações sobre `GetControlFlags` e outras otimizações de controles OLE, consulte [controles ActiveX: otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
##  <a name="a-namegetcontrolsizea--colecontrolgetcontrolsize"></a><a name="getcontrolsize"></a>COleControl::GetControlSize  
 Recupera o tamanho da janela de controle OLE.  
  
```  
void GetControlSize(
    int* pcx,  
    int* pcy);
```  
  
### <a name="parameters"></a>Parâmetros  
 *PCX*  
 Especifica a largura do controle em pixels.  
  
 *pcy*  
 Especifica a altura do controle em pixels.  
  
### <a name="remarks"></a>Comentários  
 Observe que todas as coordenadas para o windows de controle são relativas ao canto superior esquerdo do controle.  
  
##  <a name="a-namegetdca--colecontrolgetdc"></a><a name="getdc"></a>COleControl::GetDC  
 Fornece um objeto sem janelas get uma tela (ou compatíveis) contexto de dispositivo de seu contêiner.  
  
```  
CDC* GetDC(
    LPCRECT lprcRect = NULL,
    DWORD dwFlags = OLEDC_PAINTBKGND);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lprcRect*  
 Um ponteiro para o retângulo do controle sem janelas deseja redesenhar nas coordenadas do cliente do controle. **NULO** significa a extensão do objeto completo.  
  
 `dwFlags`  
 Atributos de desenho do contexto do dispositivo. As opções são:  
  
- **OLEDC_NODRAW** indica que o objeto não usa o contexto de dispositivo para executar qualquer desenho mas simplesmente para obter informações sobre o dispositivo de vídeo. O contêiner deve simplesmente passar DC da janela sem processamento adicional.  
  
- **OLEDC_PAINTBKGND** solicita que o contêiner de pintar o plano de fundo antes de retornar o controlador de domínio. Um objeto deve usar esse sinalizador se ele está solicitando um controlador de domínio para redesenhar uma área com um plano de fundo transparente.  
  
- **OLEDC_OFFSCREEN** informa o contêiner que o objeto deseja renderizar em um bitmap fora da tela que deve ser copiado para a tela. Um objeto deve usar esse sinalizador quando ele está prestes a executar a operação de desenho gera muita cintilação. O contêiner está livre para aceitar a solicitação ou não. No entanto, se este sinalizador não for definido, o contêiner deve devolver uma tela DC. Isso permite que os objetos executar operações diretamente na tela como mostrar uma seleção (por meio de um **XOR** operação).  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o contexto de dispositivo de exibição para o contêiner `CWnd` área do cliente se bem-sucedido; caso contrário, o valor de retorno será **nulo**. O contexto de dispositivo de exibição pode ser usado em funções GDI subsequentes para desenhar na área cliente da janela do contêiner.  
  
### <a name="remarks"></a>Comentários  
 O [ReleaseDC](#releasedc) função de membro deve ser chamada para liberar o contexto depois de pintura. Ao chamar `GetDC`, objetos passam o retângulo que desejarem desenhar em seus próprios coordenadas do cliente. `GetDC`converte em coordenadas da área do cliente de contêiner. O objeto não deve solicitar um retângulo de desenho desejado maior que sua própria retângulo área do cliente, do tamanho que pode ser recuperado com [GetClientRect](#getclientrect). Isso impede que objetos inadvertidamente desenho onde eles não deveriam.  
  
##  <a name="a-namegetenableda--colecontrolgetenabled"></a><a name="getenabled"></a>COleControl::GetEnabled  
 Implementa a função Get da propriedade Enabled de estoque do controle.  
  
```  
BOOL GetEnabled();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle estiver habilitado; Caso contrário, 0.  
  
##  <a name="a-namegetextendedcontrola--colecontrolgetextendedcontrol"></a><a name="getextendedcontrol"></a>COleControl::GetExtendedControl  
 Obtém um ponteiro para um objeto mantido pelo contêiner que representa o controle com um extenso conjunto de propriedades.  
  
```  
LPDISPATCH GetExtendedControl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o contêiner estendidos do objeto de controle. Se não houver nenhum objeto disponível, o valor será **nulo**.  
  
 Esse objeto pode ser manipulado por meio de seu `IDispatch` interface. Você também pode usar `QueryInterface` para obter outras interfaces disponíveis fornecidos pelo objeto. No entanto, o objeto não é necessário para dar suporte a um conjunto específico de interfaces. Observe que contar com os recursos específicos do objeto de controle estendido do contêiner limita a portabilidade do seu controle para outros contêineres arbitrários.  
  
### <a name="remarks"></a>Comentários  
 A função que chama essa função é responsável por liberar o ponteiro quando terminar com o objeto. Observe que o contêiner não é necessário para dar suporte a esse objeto.  
  
##  <a name="a-namegetfocusa--colecontrolgetfocus"></a><a name="getfocus"></a>COleControl::GetFocus  
 Determina se o `COleControl` objeto tem o foco.  
  
```  
CWnd* GetFocus();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o controle é ativado e sem janelas, retornará **isso** se o controle tem o foco do teclado (conforme determinado pelo contêiner do controle), ou **nulo** se não tiver o foco.  
  
 Caso contrário, retorna o `CWnd` objeto que tem o foco (mesmo que `CWnd::GetFocus`).  
  
### <a name="remarks"></a>Comentários  
 Um controle sem janelas ativado recebe o foco quando [SetFocus](#setfocus) é chamado.  
  
##  <a name="a-namegetfonta--colecontrolgetfont"></a><a name="getfont"></a>COleControl::GetFont  
 Implementa a função Get da propriedade fonte estoque.  
  
```  
LPFONTDISP GetFont();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a interface de expedição de fonte de estoque do controle propriedade Font.  
  
### <a name="remarks"></a>Comentários  
 Observe que o chamador deve liberar o objeto quando terminar. Dentro da implementação do controle, use `InternalGetFont` para acessar o objeto de fonte das ações do controle. Para obter mais informações sobre o uso de fontes em seu controle, consulte o artigo [controles ActiveX: usando fontes em um controle ActiveX](../../mfc/mfc-activex-controls-using-fonts.md).  
  
##  <a name="a-namegetfonttextmetricsa--colecontrolgetfonttextmetrics"></a><a name="getfonttextmetrics"></a>COleControl::GetFontTextMetrics  
 Mede as métricas de texto para qualquer `CFontHolder` objeto possuído pelo controle.  
  
```  
void GetFontTextMetrics(
    LPTEXTMETRIC lptm,  
    CFontHolder& fontHolder);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lptm`  
 Ponteiro para uma [TEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd145132) estrutura.  
  
 `fontHolder`  
 Referência a um [CFontHolder](../../mfc/reference/cfontholder-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A fonte pode ser selecionada com a [COleControl::SelectFontObject](#selectfontobject) função. `GetFontTextMetrics`inicializa o `TEXTMETRIC` estrutura apontada por `lptm` com informações válidas de métricas sobre `fontHolder`da fonte se for bem-sucedido, ou preencher a estrutura com zeros, se não for bem-sucedido. Você deve usar essa função em vez de [GetTextMetrics](http://msdn.microsoft.com/library/windows/desktop/dd144941) quando pintando seu controle como controles, como qualquer inserido o objeto OLE, podem ser necessário para renderizar a próprios em um metarquivo.  
  
 O `TEXTMETRIC` estrutura para a fonte padrão é atualizada quando o [SelectFontObject](#selectfontobject) função é chamada. Você deve chamar `GetFontTextMetrics` somente depois de selecionar a propriedade Font ações para garantir que as informações fornecidas é válido.  
  
##  <a name="a-namegetforecolora--colecontrolgetforecolor"></a><a name="getforecolor"></a>COleControl::GetForeColor  
 Implementa a função Get da propriedade ForeColor estoque.  
  
```  
OLE_COLOR GetForeColor();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno Especifica a cor de primeiro plano atual como uma **OLE_COLOR** valor, se for bem-sucedido. Esse valor pode ser convertido para um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor com uma chamada para `TranslateColor`.  
  
##  <a name="a-namegethwnda--colecontrolgethwnd"></a><a name="gethwnd"></a>COleControl::GetHwnd  
 Implementa a função Get da propriedade hWnd de estoque.  
  
```  
OLE_HANDLE GetHwnd();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador de janela do controle OLE, se houver; Caso contrário, **nulo**.  
  
##  <a name="a-namegetmessagestringa--colecontrolgetmessagestring"></a><a name="getmessagestring"></a>COleControl::GetMessageString  
 Chamado pela estrutura para obter uma cadeia de caracteres curta que descreve a finalidade do item de menu identificado por `nID`.  
  
```  
virtual void GetMessageString(
    UINT nID,  
    CString& rMessage) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Uma ID do item de menu.  
  
 `rMessage`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto por meio do qual uma cadeia de caracteres será retornada.  
  
### <a name="remarks"></a>Comentários  
 Isso pode ser usado para obter uma mensagem para exibição em uma barra de status enquanto o item de menu é realçado. A implementação padrão tenta carregar um recurso de cadeia de caracteres identificado por `nID`.  
  
##  <a name="a-namegetnotsupporteda--colecontrolgetnotsupported"></a><a name="getnotsupported"></a>COleControl::GetNotSupported  
 Impede o acesso ao valor de propriedade do controle do usuário.  
  
```  
void GetNotSupported();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função em vez da função Get de qualquer propriedade onde não há suporte para recuperação da propriedade pelo usuário do controle. Um exemplo seria uma propriedade que é somente gravação.  
  
##  <a name="a-namegetreadystatea--colecontrolgetreadystate"></a><a name="getreadystate"></a>COleControl::GetReadyState  
 Retorna o estado de prontidão do controle.  
  
```  
long GetReadyState();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O estado de prontidão do controle, um dos seguintes valores:  
  
 **READYSTATE_UNINITIALIZED**  
 Estado de inicialização padrão  
  
 **READYSTATE_LOADING**  
 Controle atualmente está carregando suas propriedades  
  
 **READYSTATE_LOADED**  
 Controle foi inicializado  
  
 **READYSTATE_INTERACTIVE**  
 Controle tem dados suficientes para ser interativa, mas dados não assíncronos ainda são carregados  
  
 `READYSTATE_COMPLETE`  
 Controle tem todos os seus dados  
  
### <a name="remarks"></a>Comentários  
 A maioria dos controles simples nunca precisa diferenciar entre **LOADED** e `INTERACTIVE`. No entanto, os controles que oferecem suporte a propriedades de caminho de dados podem não estar prontos para ser interativa até que pelo menos alguns dados são recebidos assincronicamente. Um controle deve tentar tornar-se interativos assim que possível.  
  
##  <a name="a-namegetrectincontainera--colecontrolgetrectincontainer"></a><a name="getrectincontainer"></a>COleControl::GetRectInContainer  
 Obtém as coordenadas do retângulo do controle relativo ao contêiner, expressado em unidades de dispositivo.  
  
```  
BOOL GetRectInContainer(LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Um ponteiro para a estrutura de retângulo na qual as coordenadas do controle serão copiadas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle está ativo no local; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O retângulo só será válido se o controle está ativo no local.  
  
##  <a name="a-namegetstocktextmetricsa--colecontrolgetstocktextmetrics"></a><a name="getstocktextmetrics"></a>COleControl::GetStockTextMetrics  
 Mede a métrica de texto para a propriedade do controle estoque fonte, que pode ser selecionada com a [SelectStockFont](#selectstockfont) função.  
  
```  
void GetStockTextMetrics(LPTEXTMETRIC lptm);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lptm`  
 Um ponteiro para um [TEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd145132) estrutura.  
  
### <a name="remarks"></a>Comentários  
 O `GetStockTextMetrics` função inicializará o `TEXTMETRIC` estrutura apontada por `lptm` com informações de métricas válido se for bem-sucedido ou preenchimento a estrutura com zeros, se não for bem-sucedido. Use essa função em vez de [GetTextMetrics](http://msdn.microsoft.com/library/windows/desktop/dd144941) quando pintando seu controle como controles, como qualquer inserido o objeto OLE, podem ser necessário para renderizar a próprios em um metarquivo.  
  
 O `TEXTMETRIC` estrutura para a fonte padrão é atualizada quando o `SelectStockFont` função é chamada. Você deve chamar essa função somente depois de selecionar a fonte de estoque para garantir que as informações fornecidas é válido.  
  
##  <a name="a-namegettexta--colecontrolgettext"></a><a name="gettext"></a>COleControl::GetText  
 Implementa a função Get da propriedade Text ou Caption estoque.  
  
```  
BSTR GetText();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor atual da cadeia de caracteres de texto do controle ou uma cadeia de caracteres de comprimento zero se nenhuma cadeia de caracteres estiver presente.  
  
> [!NOTE]
>  Para obter mais informações sobre o `BSTR` tipo de dados, consulte [tipos de dados](../../mfc/reference/data-types-mfc.md) na seção Macros e globais.  
  
### <a name="remarks"></a>Comentários  
 Observe que o chamador dessa função deve chamar `SysFreeString` a cadeia de caracteres retornada para gratuitamente o recurso. Dentro da implementação do controle, use `InternalGetText` para acessar a propriedade Text ou Caption estoque do controle.  
  
##  <a name="a-namegetwindowlessdroptargeta--colecontrolgetwindowlessdroptarget"></a><a name="getwindowlessdroptarget"></a>COleControl::GetWindowlessDropTarget  
 Substituir `GetWindowlessDropTarget` quando desejar um controle sem janelas para ser o destino de um OLE arrastar e soltar a operação.  
  
```  
virtual IDropTarget* GetWindowlessDropTarget();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o objeto `IDropTarget` interface. Desde que ele não tem uma janela, um objeto sem janelas não pode registrar um `IDropTarget` interface. No entanto, para participar de arrastar e soltar, um objeto sem janelas pode ainda implementam a interface e retorná-lo no `GetWindowlessDropTarget`.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, isso exigiria que a janela do controle ser registrado como um destino de soltar. Mas, desde que o controle não tem nenhuma janela própria, o contêiner usará sua própria janela como um destino de soltar. O controle simplesmente precisa fornecer uma implementação de `IDropTarget` interface para que o contêiner pode delegar chamadas no momento apropriado. Por exemplo:  
  
 [!code-cpp[NVC_MFCAxCtl n º&2;](../../mfc/reference/codesnippet/cpp/colecontrol-class_3.cpp)]  
  
##  <a name="a-nameinitializeiidsa--colecontrolinitializeiids"></a><a name="initializeiids"></a>COleControl::InitializeIIDs  
 Informa a classe base das IIDs irá usar o controle.  
  
```  
void InitializeIIDs(
    const IID* piidPrimary,
    const IID* piidEvents);
```  
  
### <a name="parameters"></a>Parâmetros  
 *piidPrimary*  
 Ponteiro para a identificação da interface de expedição principal do controle.  
  
 *piidEvents*  
 Ponteiro para a identificação da interface de eventos do controle.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função no construtor do controle para informar a classe base da interface IDs usando o seu controle.  
  
##  <a name="a-nameinternalgetfonta--colecontrolinternalgetfont"></a><a name="internalgetfont"></a>COleControl::InternalGetFont  
 Acessa a propriedade fonte estoque do seu controle  
  
```  
CFontHolder& InternalGetFont();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um [CFontHolder](../../mfc/reference/cfontholder-class.md) objeto que contém o objeto de fonte de estoque.  
  
##  <a name="a-nameinternalgettexta--colecontrolinternalgettext"></a><a name="internalgettext"></a>COleControl::InternalGetText  
 Acessa a propriedade Text ou Caption estoque do seu controle.  
  
```  
const CString& InternalGetText();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a cadeia de caracteres de texto do controle.  
  
##  <a name="a-nameinternalsetreadystatea--colecontrolinternalsetreadystate"></a><a name="internalsetreadystate"></a>COleControl::InternalSetReadyState  
 Define o estado de prontidão do controle.  
  
```  
void InternalSetReadyState(long lNewReadyState);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lNewReadyState*  
 O estado de prontidão para definir para o controle, um dos seguintes valores:  
  
 **READYSTATE_UNINITIALIZED**  
 Estado de inicialização padrão  
  
 **READYSTATE_LOADING**  
 Controle atualmente está carregando suas propriedades  
  
 **READYSTATE_LOADED**  
 Controle foi inicializado  
  
 **READYSTATE_INTERACTIVE**  
 Controle tem dados suficientes para ser interativa, mas dados não assíncronos ainda são carregados  
  
 `READYSTATE_COMPLETE`  
 Controle tem todos os seus dados  
  
### <a name="remarks"></a>Comentários  
 A maioria dos controles simples nunca precisa diferenciar entre **LOADED** e `INTERACTIVE`. No entanto, os controles que oferecem suporte a propriedades de caminho de dados podem não estar prontos para ser interativa até que pelo menos alguns dados são recebidos assincronicamente. Um controle deve tentar tornar-se interativos assim que possível.  
  
##  <a name="a-nameinvalidatecontrola--colecontrolinvalidatecontrol"></a><a name="invalidatecontrol"></a>COleControl::InvalidateControl  
 Força o controle ser redesenhado.  
  
```  
void InvalidateControl(
    LPCRECT lpRect = NULL,  
    BOOL bErase = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Um ponteiro para a região do controle a ser invalidado.  
  
 `bErase`  
 Especifica se o plano de fundo dentro da região de atualização deve ser apagada quando a região de atualização é processada.  
  
### <a name="remarks"></a>Comentários  
 Se `lpRect` tem um **nulo** valor, todo o controle será ser redesenhado. Se `lpRect` não é **nulo**, isso indica que a parte do retângulo do controle a ser invalidado. Em casos onde o controle não tem nenhuma janela ou não está ativo no momento, o retângulo é ignorado, e é feita uma chamada para o site do cliente [IAdviseSink::OnViewChange](http://msdn.microsoft.com/library/windows/desktop/ms694337) função de membro. Use essa função em vez de `CWnd::InvalidateRect` ou `InvalidateRect`.  
  
##  <a name="a-nameinvalidatergna--colecontrolinvalidatergn"></a><a name="invalidatergn"></a>COleControl::InvalidateRgn  
 Invalida a área de cliente da janela do contêiner em determinada região.  
  
```  
void InvalidateRgn(CRgn* pRgn, BOOL bErase = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRgn`  
 Um ponteiro para um [CRgn](../../mfc/reference/crgn-class.md) objeto que identifica a região de exibição do objeto OLE para invalidar, nas coordenadas do cliente da janela. Se esse parâmetro for **nulo**, a extensão é o objeto inteiro.  
  
 `bErase`  
 Especifica se o plano de fundo dentro da região invalidado deve ser apagados. Se **TRUE**, o plano de fundo é apagado. Se **FALSE**, o plano de fundo permanece inalterado.  
  
### <a name="remarks"></a>Comentários  
 Isso pode ser usado para redesenhar controles sem janelas dentro do contêiner. A região invalidada, juntamente com todas as outras áreas na região de atualização, é marcada para pintura quando o próximo [WM_PAINT](http://msdn.microsoft.com/library/windows/desktop/dd145213) mensagem é enviada.  
  
 Se `bErase` é **TRUE** para qualquer parte da região de atualização, o plano de fundo em toda a região, não apenas na parte determinada, é apagado.  
  
##  <a name="a-nameisconvertingvbxa--colecontrolisconvertingvbx"></a><a name="isconvertingvbx"></a>COleControl::IsConvertingVBX  
 Permite o carregamento especializado de um controle OLE.  
  
```  
BOOL IsConvertingVBX();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle está sendo convertido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Quando a conversão de um formulário que usa VBX controles para um que usa controles OLE, código de carregamento especial para os controles OLE pode ser necessário. Por exemplo, se você estiver carregando uma instância do seu controle OLE, você pode ter uma chamada para [PX_Font](persistence-of-ole-controls.md#px_font) em seu `DoPropExchange`:  
  
 [!code-cpp[NVC_MFCAxCtl n º&3;](../../mfc/reference/codesnippet/cpp/colecontrol-class_4.cpp)]  
  
 No entanto, os controles VBX não tem um objeto de fonte; cada propriedade de fonte foi salvo individualmente. Nesse caso, você usaria `IsConvertingVBX` para distinguir entre esses dois casos:  
  
 [!code-cpp[NVC_MFCAxCtl n º&4;](../../mfc/reference/codesnippet/cpp/colecontrol-class_5.cpp)]  
  
 Outro caso seria se o seu controle VBX salvo proprietários dados binários (em seu **VBM_SAVEPROPERTY** manipulador de mensagens), e seu controle OLE salva os dados binários em um formato diferente. Se desejar que seu controle OLE seja compatível com o controle VBX, você pode ler dois formatos novos e antigos usando o `IsConvertingVBX` função distinguir se o controle VBX ou o controle OLE estava sendo carregado.  
  
 Em seu controle `DoPropExchange` função, você pode verificar essa condição e se for verdadeiro, executar código de carga específico para essa conversão (como nos exemplos anteriores). Se o controle não está sendo convertido, você pode executar o código de carga normal. Esse recurso só é aplicável aos controles que está sendo convertidos de contrapartes VBX.  
  
##  <a name="a-nameisinvokealloweda--colecontrolisinvokeallowed"></a><a name="isinvokeallowed"></a>COleControl::IsInvokeAllowed  
 Permite a invocação de método de automação.  
  
```  
BOOL IsInvokeAllowed(DISPID dispid);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle tiver sido inicializado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação da estrutura de **IDispatch:: Invoke** chamadas **IsInvokeAllowed** para determinar se uma determinada função (identificado por `dispid`) podem ser chamados. O comportamento padrão para um controle OLE é permitir que os métodos de automação a ser invocado apenas se o controle tiver sido inicializado; No entanto, **IsInvokeAllowed** é uma função virtual e pode ser substituído se necessário (por exemplo, quando o controle está sendo usado como um servidor de automação). Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q166472, "como: usar um controle OLE como um servidor de automação." Artigos da Base de Conhecimento estão disponíveis na documentação da biblioteca MSDN Visual Studio ou no [http://support.microsoft.com](http://support.microsoft.com/).  
  
##  <a name="a-nameismodifieda--colecontrolismodified"></a><a name="ismodified"></a>COleControl::IsModified  
 Determina se o estado do controle foi modificado.  
  
```  
BOOL IsModified();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o estado do controle tiver sido modificado desde que ele foi salvo pela última vez; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O estado de um controle é modificado quando uma propriedade de valor alterado.  
  
##  <a name="a-nameisoptimizeddrawa--colecontrolisoptimizeddraw"></a><a name="isoptimizeddraw"></a>COleControl::IsOptimizedDraw  
 Determina se o contêiner suporta desenho otimizado para a operação de desenho atual.  
  
```  
BOOL IsOptimizedDraw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o contêiner oferece suporte otimizado para a operação atual de desenho de desenho; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Se houver suporte para desenho otimizado, o controle necessário não selecionar objetos antigos (canetas, pincéis, fontes, etc.) no contexto de dispositivo ao desenho for concluído.  
  
##  <a name="a-nameissubclassedcontrola--colecontrolissubclassedcontrol"></a><a name="issubclassedcontrol"></a>COleControl::IsSubclassedControl  
 Chamado pela estrutura para determinar se o controle subdivide um Windows controle.  
  
```  
virtual BOOL IsSubclassedControl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle é uma subclasse; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você deve substituir essa função e retornar **TRUE** se o OLE controle subclasses de um controle do Windows.  
  
##  <a name="a-nameloada--colecontrolload"></a><a name="load"></a>COleControl::Load  
 Redefine todos os dados anteriores carregados de forma assíncrona e inicia um novo carregamento da propriedade assíncrona do controle.  
  
```  
void Load(LPCTSTR strNewPath, CDataPathProperty& prop);
```  
  
### <a name="parameters"></a>Parâmetros  
 *strNewPath*  
 Um ponteiro para uma cadeia de caracteres que contém o caminho que faz referência a localização absoluta da propriedade controle assíncrono.  
  
 *prop*  
 A [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md) objeto que implementa uma propriedade de controle assíncrono.  
  
##  <a name="a-namelockinplaceactivea--colecontrollockinplaceactive"></a><a name="lockinplaceactive"></a>COleControl::LockInPlaceActive  
 Impede que o contêiner desativar seu controle.  
  
```  
BOOL LockInPlaceActive(BOOL bLock);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bLock`  
 **TRUE** se o estado ativo no local do controle a ser bloqueada; **FALSE** se ela deve ser desbloqueado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o bloqueio foi bem sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Observe que cada bloqueio do controle deve ser emparelhado com um desbloqueio do controle quando terminar. Você só deve bloquear seu controle por curtos períodos, como ao acionar um evento.  
  
##  <a name="a-nameonambientpropertychangea--colecontrolonambientpropertychange"></a><a name="onambientpropertychange"></a>COleControl::OnAmbientPropertyChange  
 Chamado pela estrutura quando uma propriedade de ambiente do contêiner tiver alterado o valor.  
  
```  
virtual void OnAmbientPropertyChange(DISPID dispid);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dispID*  
 A ID de expedição da propriedade ambiente que foi alterado, ou **DISPID_UNKNOWN** se várias propriedades foram alteradas.  
  
##  <a name="a-nameonappearancechangeda--colecontrolonappearancechanged"></a><a name="onappearancechanged"></a>COleControl::OnAppearanceChanged  
 Chamado pela estrutura quando o valor da propriedade Appearance estoque foi alterado.  
  
```  
virtual void OnAppearanceChanged ();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se desejar notificação após essa alteração de propriedade. As chamadas de implementação padrão `InvalidateControl`.  
  
##  <a name="a-nameonbackcolorchangeda--colecontrolonbackcolorchanged"></a><a name="onbackcolorchanged"></a>COleControl::OnBackColorChanged  
 Chamado pela estrutura quando o valor da propriedade BackColor estoque foi alterado.  
  
```  
virtual void OnBackColorChanged();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se desejar notificação após essa alteração de propriedade. As chamadas de implementação padrão `InvalidateControl`.  
  
##  <a name="a-nameonborderstylechangeda--colecontrolonborderstylechanged"></a><a name="onborderstylechanged"></a>COleControl::OnBorderStyleChanged  
 Chamado pela estrutura quando o valor da propriedade BorderStyle estoque foi alterado.  
  
```  
virtual void OnBorderStyleChanged();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão `InvalidateControl`.  
  
 Substitua essa função se desejar notificação após essa alteração de propriedade.  
  
##  <a name="a-nameonclicka--colecontrolonclick"></a><a name="onclick"></a>COleControl::OnClick  
 Chamado pela estrutura quando um botão do mouse foi clicado ou o método de estoque DoClick foi invocado.  
  
```  
virtual void OnClick(USHORT iButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iButton*  
 Índice de um botão do mouse. Pode ter um dos seguintes valores:  
  
- **LEFT_BUTTON** o botão esquerdo do mouse foi clicado.  
  
- **MIDDLE_BUTTON** o botão do meio do mouse foi clicado.  
  
- **RIGHT_BUTTON** o botão direito do mouse foi clicado.  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão `COleControl::FireClick`.  
  
 Substitua essa função de membro para modificar ou estender o tratamento padrão.  
  
##  <a name="a-nameonclosea--colecontrolonclose"></a><a name="onclose"></a>COleControl::OnClose  
 Chamado pela estrutura quando o contêiner é chamado do controle **IOleControl:: Close** função.  
  
```  
virtual void OnClose(DWORD dwSaveOption);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwSaveOption`  
 Sinalizador que indica se o objeto deve ser salvo antes de carregar. Os valores válidos são:  
  
- `OLECLOSE_SAVEIFDIRTY`  
  
- `OLECLOSE_NOSAVE`  
  
- `OLECLOSE_PROMPTSAVE`  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `OnClose` salva o objeto de controle se ele tiver sido modificado e `dwSaveOption` seja `OLECLOSE_SAVEIFDIRTY` ou `OLECLOSE_PROMPTSAVE`.  
  
##  <a name="a-nameondoverba--colecontrolondoverb"></a><a name="ondoverb"></a>COleControl::OnDoVerb  
 Chamado pela estrutura quando o contêiner chama o **IOleObject:: DoVerb** função de membro.  
  
```  
virtual BOOL OnDoVerb(
    LONG iVerb,  
    LPMSG lpMsg,  
    HWND hWndParent,  
    LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iVerb`  
 O índice do verbo de controle a ser chamado.  
  
 `lpMsg`  
 Um ponteiro para a mensagem do Windows que causou o verbo a ser chamado.  
  
 `hWndParent`  
 O identificador para a janela pai do controle. Se a execução do verbo cria uma janela (ou windows), `hWndParent` deve ser usado como o pai.  
  
 `lpRect`  
 Um ponteiro para uma estrutura RECT nos quais as coordenadas do controle, relativo ao contêiner, serão copiadas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chamada foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão usa a `ON_OLEVERB` e `ON_STDOLEVERB` entradas de mapa para determinar a função adequada para invocar de mensagem.  
  
 Substitua essa função para alterar o tratamento padrão de verbo.  
  
##  <a name="a-nameondrawa--colecontrolondraw"></a><a name="ondraw"></a>COleControl::OnDraw  
 Chamado pela estrutura para desenhar o controle OLE no retângulo delimitador especificado usando o contexto de dispositivo especificado.  
  
```  
virtual void OnDraw(
    CDC* pDC,  
    const CRect& rcBounds,  
    const CRect& rcInvalid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 O contexto de dispositivo no qual ocorre o desenho.  
  
 `rcBounds`  
 A área retangular do controle, incluindo a borda.  
  
 `rcInvalid`  
 A área retangular do controle que é inválido.  
  
### <a name="remarks"></a>Comentários  
 `OnDraw`normalmente é chamado para exibição na tela, passando um contexto de dispositivo de tela como `pDC`. O `rcBounds` parâmetro identifica o retângulo no contexto do dispositivo de destino (em relação ao modo de mapeamento atual). O `rcInvalid` parâmetro é o retângulo real é inválido. Em alguns casos, isso será uma área menor que `rcBounds`.  
  
##  <a name="a-nameondrawmetafilea--colecontrolondrawmetafile"></a><a name="ondrawmetafile"></a>COleControl::OnDrawMetafile  
 Chamado pela estrutura para desenhar o controle OLE no retângulo delimitador especificado usando o contexto de dispositivo de metarquivo especificado.  
  
```  
virtual void OnDrawMetafile(
    CDC* pDC,  
    const CRect& rcBounds);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 O contexto de dispositivo no qual ocorre o desenho.  
  
 `rcBounds`  
 A área retangular do controle, incluindo a borda.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão chama o [OnDraw](#ondraw) função.  
  
##  <a name="a-nameonedita--colecontrolonedit"></a><a name="onedit"></a>COleControl::OnEdit  
 Faz com que o controle esteja ativada de interface do usuário.  
  
```  
virtual BOOL OnEdit(
    LPMSG lpMsg,  
    HWND hWndParent,  
    LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMsg`  
 Um ponteiro para a mensagem do Windows que invocou o verbo.  
  
 `hWndParent`  
 Um identificador para a janela pai do controle.  
  
 `lpRect`  
 Um ponteiro para o retângulo usado pelo controle no contêiner.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chamada for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso tem o mesmo efeito de invocar o controle `OLEIVERB_UIACTIVATE` verbo.  
  
 Esta função geralmente é usada como a função de manipulador para um `ON_OLEVERB` mensagem de entrada do mapa. Isso disponibiliza um verbo "Editar" no menu de "Objeto" do controle. Por exemplo:  
  
 [!code-cpp[NVC_MFCAxCtl n º&5;](../../mfc/reference/codesnippet/cpp/colecontrol-class_6.cpp)]  
  
##  <a name="a-nameonenabledchangeda--colecontrolonenabledchanged"></a><a name="onenabledchanged"></a>COleControl::OnEnabledChanged  
 Chamado pela estrutura quando o valor da propriedade Enabled de estoque foi alterado.  
  
```  
virtual void OnEnabledChanged();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se desejar notificação após essa alteração de propriedade. As chamadas de implementação padrão [InvalidateControl](#invalidatecontrol).  
  
##  <a name="a-nameonenumverbsa--colecontrolonenumverbs"></a><a name="onenumverbs"></a>COleControl::OnEnumVerbs  
 Chamado pela estrutura quando o contêiner chama o **IOleObject::EnumVerbs** função de membro.  
  
```  
virtual BOOL OnEnumVerbs(LPENUMOLEVERB* ppenumOleVerb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppenumOleVerb`  
 Um ponteiro para o **IEnumOLEVERB** objeto que enumera os verbos do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o verbo está disponível; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Enumera a implementação padrão de `ON_OLEVERB` entradas no mapa de mensagens.  
  
 Substitua essa função para alterar o modo padrão de enumeração verbos.  
  
##  <a name="a-nameoneventadvisea--colecontroloneventadvise"></a><a name="oneventadvise"></a>COleControl::OnEventAdvise  
 Chamado pela estrutura quando um manipulador de eventos está conectado ou desconectado de um controle OLE.  
  
```  
virtual void OnEventAdvise(BOOL bAdvise);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAdvise`  
 **TRUE** indica que um manipulador de eventos está conectado ao controle. **FALSE** indica que um manipulador de eventos foi desconectado do controle.  
  
##  <a name="a-nameonfontchangeda--colecontrolonfontchanged"></a><a name="onfontchanged"></a>COleControl::OnFontChanged  
 Chamado pela estrutura quando o valor da propriedade stock Font é alterada.  
  
```  
virtual void OnFontChanged();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão `COleControl::InvalidateControl`. Se o controle é subclasses de um controle do Windows, a implementação padrão também envia um **WM_SETFONT** mensagem para a janela do controle.  
  
 Substitua essa função se desejar notificação após essa alteração de propriedade.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAxCtl n º&6;](../../mfc/reference/codesnippet/cpp/colecontrol-class_7.cpp)]  
  
##  <a name="a-nameonforecolorchangeda--colecontrolonforecolorchanged"></a><a name="onforecolorchanged"></a>COleControl::OnForeColorChanged  
 Chamado pela estrutura quando o valor da propriedade ForeColor estoque foi alterado.  
  
```  
virtual void OnForeColorChanged();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão `InvalidateControl`.  
  
 Substitua essa função se desejar notificação após essa alteração de propriedade.  
  
##  <a name="a-nameonfreezeeventsa--colecontrolonfreezeevents"></a><a name="onfreezeevents"></a>COleControl::OnFreezeEvents  
 Chamado pela estrutura depois de chamar o contêiner **IOleControl:: FreezeEvents**.  
  
```  
virtual void OnFreezeEvents(BOOL bFreeze);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bFreeze`  
 **TRUE** se o controle manipulação de eventos é congelado; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada.  
  
 Substitua essa função se você quiser o comportamento adicional ao tratamento de eventos é congelado ou descongelado.  
  
##  <a name="a-nameongetcolorseta--colecontrolongetcolorset"></a><a name="ongetcolorset"></a>COleControl::OnGetColorSet  
 Chamado pela estrutura quando o contêiner chama o **IViewObject::GetColorSet** função de membro.  
  
```  
virtual BOOL OnGetColorSet(
    DVTARGETDEVICE* ptd,  
    HDC hicTargetDev,  
    LPLOGPALETTE* ppColorSet);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptd`  
 Aponta para o dispositivo de destino para o qual a imagem deve ser processada. Se esse valor for **nulo**, a imagem deve ser processada para um dispositivo de destino padrão, geralmente um dispositivo de vídeo.  
  
 `hicTargetDev`  
 Especifica o contexto de informações no dispositivo de destino indicado por `ptd`. Esse parâmetro pode ser um contexto de dispositivo, mas não é necessariamente. If `ptd` is **NULL**, `hicTargetDev` should also be **NULL**.  
  
 *ppColorSet*  
 Um ponteiro para o local no qual o conjunto de cores que seria usado deve ser copiado. Se a função não retorna o conjunto de cores, **nulo** é retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for retornado um conjunto de cores válidos; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O contêiner chama essa função para obter todas as cores necessárias para desenhar o controle OLE. O contêiner pode usar os conjuntos de cor obtidos junto com as cores que ele precisa definir a paleta de cores geral. Retorna a implementação padrão **FALSE**.  
  
 Substitua essa função para fazer qualquer processamento especial dessa solicitação.  
  
##  <a name="a-nameongetcontrolinfoa--colecontrolongetcontrolinfo"></a><a name="ongetcontrolinfo"></a>COleControl::OnGetControlInfo  
 Chamado pela estrutura quando o contêiner do controle solicitou informações sobre o controle.  
  
```  
virtual void OnGetControlInfo(LPCONTROLINFO pControlInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pControlInfo`  
 Ponteiro para uma [CONTROLINFO](http://msdn.microsoft.com/library/windows/desktop/ms680734) estrutura a ser preenchido.  
  
### <a name="remarks"></a>Comentários  
 Essas informações consistem basicamente uma descrição das chaves mnemônico do controle. Preencher a implementação padrão `pControlInfo` com as informações padrão.  
  
 Substitua essa função se o seu controle precisa processar chaves mnemônicas.  
  
##  <a name="a-nameongetdisplaystringa--colecontrolongetdisplaystring"></a><a name="ongetdisplaystring"></a>COleControl::OnGetDisplayString  
 Chamado pela estrutura para obter uma cadeia de caracteres que representa o valor atual da propriedade identificado por `dispid`.  
  
```  
virtual BOOL OnGetDisplayString(
    DISPID dispid,  
    CString& strValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 `strValue`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto por meio do qual uma cadeia de caracteres será retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se foram retornada em uma cadeia de caracteres *strValue;* caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se seu controle possui uma propriedade cujo valor não pode ser convertido diretamente em uma cadeia de caracteres e você desejar que o valor da propriedade a ser exibida em um navegador de propriedade fornecido pelo contêiner.  
  
##  <a name="a-nameongetinplacemenua--colecontrolongetinplacemenu"></a><a name="ongetinplacemenu"></a>COleControl::OnGetInPlaceMenu  
 Chamado pela estrutura quando o controle é ativado para obter o menu a ser mesclada em menu existente do contêiner de interface do usuário.  
  
```  
virtual HMENU OnGetInPlaceMenu();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do menu de controle, ou **nulo** se o controle não tiver nenhum. Retorna a implementação padrão **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre a mesclagem de recursos OLE, consulte o artigo [Menus e recursos (OLE)](../../mfc/menus-and-resources-ole.md).  
  
##  <a name="a-nameongetnaturalextenta--colecontrolongetnaturalextent"></a><a name="ongetnaturalextent"></a>COleControl::OnGetNaturalExtent  
 Chamado pela estrutura em resposta a um contêiner **IViewObjectEx::GetNaturalExtent** solicitação.  
  
```  
virtual BOOL OnGetNaturalExtent(
    DWORD dwAspect,
    LONG lindex,
    DVTARGETDEVICE* ptd,
    HDC hicTargetDev,
    DVEXTENTINFO* pExtentInfo,
    LPSIZEL psizel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwAspect`  
 Especifica como o objeto deve ser representado. Representações incluem conteúdo, um ícone, uma miniatura ou um documento impresso. Os valores válidos são tirados da enumeração [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) ou **DVASPECT2**.  
  
 *lindex*  
 A parte do objeto que é de interesse. -1 no momento, somente é válido.  
  
 `ptd`  
 Aponta para a [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) estrutura definindo o dispositivo de destino para o qual o tamanho do objeto deve ser retornado.  
  
 `hicTargetDev`  
 Especifica as informações de contexto para o dispositivo de destino indicada pela `ptd` parâmetro do qual o objeto pode extrair métricas de dispositivo e testar os recursos do dispositivo. Se `ptd` é **nulo**, o objeto deve ignorar o valor de `hicTargetDev` parâmetro.  
  
 *pExtentInfo*  
 Aponta para a **DVEXTENTINFO** estrutura que especifica o dimensionamento de dados. O **DVEXTENTINFO** estrutura é:  
  
 `typedef struct  tagExtentInfo`  
  
 `{`  
  
 `UINT cb;`  
  
 `DWORD dwExtentMode;`  
  
 `SIZEL sizelProposed;`  
  
 `}   DVEXTENTINFO;`  
  
 O membro de estrutura `dwExtentMode` pode ter um dos dois valores:  
  
- **DVEXTENT_CONTENT** consultar o tamanho máximo que o controle deve ser ajustar exatamente conteúdo (snap para tamanho)  
  
- **DVEXTENT_INTEGRAL** ao redimensionar, passe o tamanho proposto para controle  
  
 `psizel`  
 Pontos de dados retornados pelo controle de dimensionamento. Os dados retornados de dimensionamento são definidos como -1 para qualquer dimensão não foi ajustado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se ele retorna com êxito ou ajusta o tamanho; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para retornar o tamanho de exibição do objeto mais próximo para o modo de tamanho e a extensão proposto no **DVEXTENTINFO** estrutura. Retorna a implementação padrão **FALSE** e não faz com que nenhum ajuste ao tamanho.  
  
##  <a name="a-nameongetpredefinedstringsa--colecontrolongetpredefinedstrings"></a><a name="ongetpredefinedstrings"></a>COleControl::OnGetPredefinedStrings  
 Chamado pela estrutura para obter um conjunto de cadeias de caracteres predefinidas que representam os valores possíveis para uma propriedade.  
  
```  
virtual BOOL OnGetPredefinedStrings(
    DISPID dispid,  
    CStringArray* pStringArray,  
    CDWordArray* pCookieArray);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 `pStringArray`  
 Uma matriz de cadeia de caracteres a ser preenchido com valores de retorno.  
  
 `pCookieArray`  
 A `DWORD` matriz a ser preenchido com valores de retorno.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se elementos foram adicionados ao `pStringArray` e `pCookieArray`.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se o controle tem uma propriedade com um conjunto de valores possíveis que podem ser representadas por cadeias de caracteres. Para cada elemento adicionado ao `pStringArray`, você deve adicionar um elemento correspondente do "cookie" para *pCookieArray.* Esses valores de "cookie" posteriormente podem ser passados pela estrutura para o `COleControl::OnGetPredefinedValue` função.  
  
##  <a name="a-nameongetpredefinedvaluea--colecontrolongetpredefinedvalue"></a><a name="ongetpredefinedvalue"></a>COleControl::OnGetPredefinedValue  
 Chamado pela estrutura para obter o valor correspondente a uma das cadeias de caracteres predefinidas anteriormente retornadas por uma substituição de `COleControl::OnGetPredefinedStrings`.  
  
```  
virtual BOOL OnGetPredefinedValue(
    DISPID dispid,  
    DWORD dwCookie,  
    VARIANT* lpvarOut);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 `dwCookie`  
 Um valor de cookie retornado anteriormente pela substituição de `COleControl::OnGetPredefinedStrings`.  
  
 `lpvarOut`  
 Ponteiro para uma **VARIANT** estrutura por meio da qual um valor de propriedade será retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um valor foi retornado em `lpvarOut`; caso contrário, 0.  
  
##  <a name="a-nameongetviewextenta--colecontrolongetviewextent"></a><a name="ongetviewextent"></a>COleControl::OnGetViewExtent  
 Chamado pela estrutura em resposta a um contêiner [IViewObject2::GetExtent](http://msdn.microsoft.com/library/windows/desktop/ms684032) solicitação.  
  
```  
virtual BOOL OnGetViewExtent(
    DWORD dwDrawAspect,
    LONG lindex,
    DVTARGETDEVICE* ptd,
    LPSIZEL lpsizel);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwDrawAspect*  
 `DWORD`Descrever o formulário ou aspecto, de um objeto é exibido. Os valores válidos são tirados da enumeração [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) ou **DVASPECT2**.  
  
 *lindex*  
 A parte do objeto que é de interesse. –&1; no momento, somente é válido.  
  
 `ptd`  
 Aponta para a [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) estrutura definindo o dispositivo de destino para o qual o tamanho do objeto deve ser retornado.  
  
 *lpsizel*  
 Aponta para o local onde o tamanho do objeto é retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se informações de extensão são retornadas com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se o controle usa o desenho de dois passos e suas partes transparentes e opacos têm dimensões diferentes.  
  
##  <a name="a-nameongetviewrecta--colecontrolongetviewrect"></a><a name="ongetviewrect"></a>COleControl::OnGetViewRect  
 Chamado pela estrutura em resposta a um contêiner **IViewObjectEx::GetRect** solicitação.  
  
```  
virtual BOOL OnGetViewRect(DWORD dwAspect, LPRECTL pRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwAspect`  
 `DWORD`Descrever o formulário ou aspecto, de um objeto é exibido. Os valores válidos são tirados da enumeração [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) ou **DVASPECT2**:  
  
- `DVASPECT_CONTENT`Retângulo delimitador do objeto inteiro. O canto superior esquerdo na origem do objeto e o tamanho igual a extensão retornado por **GetViewExtent***.*  
  
- **DVASPECT_OPAQUE** objetos com uma região retangular de opaco retornam esse retângulo. Outros não.  
  
- **DVASPECT_TRANSPARENT** retângulo abrangendo todas as partes transparentes ou irregulares.  
  
 `pRect`  
 Aponta para a [RECTL](http://msdn.microsoft.com/library/windows/desktop/dd162907) estrutura especificando o retângulo no qual o objeto deve ser desenhado. Esse parâmetro controla o posicionamento e alongamento do objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o retângulo dimensionado para o objeto é retornado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Tamanho do objeto é convertido pelo `OnGetViewRect` em um retângulo que começa em uma posição específica (o padrão é o canto superior esquerdo da tela). Substitua essa função se o controle usa o desenho de dois passos e suas partes transparentes e opacos têm dimensões diferentes.  
  
##  <a name="a-nameongetviewstatusa--colecontrolongetviewstatus"></a><a name="ongetviewstatus"></a>COleControl::OnGetViewStatus  
 Chamado pela estrutura em resposta a um contêiner **IViewObjectEx::GetViewStatus** solicitação.  
  
```  
virtual DWORD OnGetViewStatus();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores da **VIEWSTATUS** enumeração se bem-sucedido; caso contrário, 0. Os valores possíveis são qualquer combinação das seguintes opções:  
  
 **VIEWSTATUS_OPAQUE**  
 Objeto é completamente opaco. Se este bit não está definido, o objeto contém partes transparentes. Esse bit aplica-se somente aos aspectos relacionados ao conteúdo e não ao `DVASPECT_ICON` ou `DVASPECT_DOCPRINT`.  
  
 **VIEWSTATUS_SOLIDBKGND**  
 O objeto tem um plano de fundo sólido (consistindo em uma cor sólida, não é um padrão de pincel). Esse bit é significativa somente se **VIEWSTATUS_OPAQUE** é definido e se aplica somente aos aspectos relacionados ao conteúdo e não ao `DVASPECT_ICON` ou `DVASPECT_DOCPRINT`.  
  
 **VIEWSTATUS_DVASPECTOPAQUE**  
 Objeto oferece suporte a **DVASPECT_OPAQUE**. Todos os **IViewObjectEx** métodos que têm um aspecto de desenho como um parâmetro pode ser chamado com esse aspecto.  
  
 **VIEWSTATUS_DVASPECTTRANSPARENT**  
 Objeto oferece suporte a **DVASPECT_TRANSPARENT**. Todos os **IViewObjectEx** métodos que têm um aspecto de desenho como um parâmetro pode ser chamado com esse aspecto.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se o controle usa o desenho de dois passos. Retorna a implementação padrão **VIEWSTATUS_OPAQUE**.  
  
##  <a name="a-nameonhidetoolbarsa--colecontrolonhidetoolbars"></a><a name="onhidetoolbars"></a>COleControl::OnHideToolBars  
 Chamado pela estrutura quando o controle é desativado pela IU.  
  
```  
virtual void OnHideToolBars();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação deve ocultar todas as barras de ferramentas exibidas por `OnShowToolbars`.  
  
##  <a name="a-nameoninactivemousemovea--colecontroloninactivemousemove"></a><a name="oninactivemousemove"></a>COleControl::OnInactiveMouseMove  
 Chamado pelo contêiner para o objeto inativo sob o ponteiro do mouse no recebimento de um `WM_MOUSEMOVE` mensagem.  
  
```  
virtual void OnInactiveMouseMove(
    LPCRECT lprcBounds,
    long x,
    long y,
    DWORD dwKeyState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lprcBounds`  
 O objeto delimitadora retângulo, nas coordenadas do cliente da janela. Informa ao objeto seu tamanho e posição exata na tela quando o `WM_MOUSEMOVE` mensagem foi recebida.  
  
 *x*  
 A coordenada x do local do mouse nas coordenadas do cliente da janela.  
  
 *y*  
 A coordenada y do local do mouse nas coordenadas do cliente da janela.  
  
 `dwKeyState`  
 Identifica o estado atual das teclas modificadoras do teclado. Os valores válidos podem ser uma combinação de qualquer um dos sinalizadores **MK_CONTROL**, **MK_SHIFT**, **MK_ALT**, **MK_BUTTON**, **MK_LBUTTON**, **MK_MBUTTON**, e **MK_RBUTTON**.  
  
### <a name="remarks"></a>Comentários  
 Observe que as coordenadas do cliente de janela (pixels) são usadas para passar a posição do cursor do mouse. Isso é possibilitado também passando o retângulo delimitador do objeto no mesmo sistema de coordenadas.  
  
##  <a name="a-nameoninactivesetcursora--colecontroloninactivesetcursor"></a><a name="oninactivesetcursor"></a>COleControl::OnInactiveSetCursor  
 Chamado pelo contêiner para o objeto inativo sob o ponteiro do mouse no recebimento de um `WM_SETCURSOR` mensagem.  
  
```  
virtual BOOL OnInactiveSetCursor(
    LPCRECT lprcBounds,
    long x,
    long y,
    DWORD dwMouseMsg,
    BOOL bSetAlways);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lprcBounds`  
 O objeto delimitadora retângulo, nas coordenadas do cliente da janela. Informa ao objeto seu tamanho e posição exata na tela quando o `WM_SETCURSOR` mensagem foi recebida.  
  
 *x*  
 A coordenada x do local do mouse nas coordenadas do cliente da janela.  
  
 *y*  
 A coordenada y do local do mouse nas coordenadas do cliente da janela.  
  
 *dwMouseMsg*  
 O identificador da mensagem do mouse para o qual um `WM_SETCURSOR` ocorreu.  
  
 *bSetAlways*  
 Especifica se o objeto deve definir o cursor. Se **TRUE**, o objeto deve definir o cursor; se **FALSE**, o cursor não é obrigado a definir o cursor e deve retornar **S_FALSE** nesse caso.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Observe que as coordenadas do cliente de janela (pixels) são usadas para passar a posição do cursor do mouse. Isso é possibilitado também passando o retângulo delimitador do objeto no mesmo sistema de coordenadas.  
  
##  <a name="a-nameonkeydowneventa--colecontrolonkeydownevent"></a><a name="onkeydownevent"></a>COleControl::OnKeyDownEvent  
 Chamado pela estrutura após o processamento de um evento KeyDown estoque.  
  
```  
virtual void OnKeyDownEvent(
    USHORT nChar,  
    USHORT nShiftState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nChar`  
 O valor de código de tecla virtual da tecla pressionada. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h  
  
 `nShiftState`  
 Contém uma combinação dos sinalizadores a seguir:  
  
- **SHIFT_MASK** foi pressionada a tecla SHIFT durante a ação.  
  
- **CTRL_MASK** o CTRL foi pressionada durante a ação.  
  
- **ALT_MASK** o ALT foi pressionada durante a ação.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se seu controle precisa acessar as informações da chave depois que o evento foi disparado.  
  
##  <a name="a-nameonkeypresseventa--colecontrolonkeypressevent"></a><a name="onkeypressevent"></a>COleControl::OnKeyPressEvent  
 Chamado pela estrutura após o evento KeyPress tiver sido acionado de estoque.  
  
```  
virtual void OnKeyPressEvent(USHORT nChar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nChar`  
 Contém o valor de código de tecla virtual da tecla pressionada. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h  
  
### <a name="remarks"></a>Comentários  
 Observe que o `nChar` valor pode ter sido modificado pelo contêiner.  
  
 Substitua essa função se desejar notificação depois que esse evento ocorre.  
  
##  <a name="a-nameonkeyupeventa--colecontrolonkeyupevent"></a><a name="onkeyupevent"></a>COleControl::OnKeyUpEvent  
 Chamado pela estrutura após o processamento de um evento KeyDown estoque.  
  
```  
virtual void OnKeyUpEvent(
    USHORT nChar,  
    USHORT nShiftState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nChar`  
 O valor de código de tecla virtual da tecla pressionada. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h  
  
 `nShiftState`  
 Contém uma combinação dos sinalizadores a seguir:  
  
- **SHIFT_MASK** foi pressionada a tecla SHIFT durante a ação.  
  
- **CTRL_MASK** o CTRL foi pressionada durante a ação.  
  
- **ALT_MASK** o ALT foi pressionada durante a ação.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se seu controle precisa acessar as informações da chave depois que o evento foi disparado.  
  
##  <a name="a-nameonmappropertytopagea--colecontrolonmappropertytopage"></a><a name="onmappropertytopage"></a>COleControl::OnMapPropertyToPage  
 Chamado pela estrutura para obter a ID de classe de uma página de propriedade que implementa a edição da propriedade especificada.  
  
```  
virtual BOOL OnMapPropertyToPage(
    DISPID dispid,  
    LPCLSID lpclsid,  
    BOOL* pbPageOptional);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 `lpclsid`  
 Ponteiro para uma **CLSID** estrutura por meio da qual uma identificação de classe será retornada.  
  
 *pbPageOptional*  
 Retorna um indicador de se o uso da página de propriedades especificada é opcional.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma ID de classe foi retornada em `lpclsid`; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para fornecer uma maneira de invocar páginas de propriedades do controle de navegador de propriedade do contêiner.  
  
##  <a name="a-nameonmnemonica--colecontrolonmnemonic"></a><a name="onmnemonic"></a>COleControl::OnMnemonic  
 Chamado pela estrutura quando o contêiner detectou que uma tecla mnemônica do controle OLE foi pressionada.  
  
```  
virtual void OnMnemonic(LPMSG pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMsg`  
 Ponteiro para a mensagem do Windows gerado por um pressionamento de tecla mnemônico.  
  
##  <a name="a-nameonpropertiesa--colecontrolonproperties"></a><a name="onproperties"></a>COleControl::OnProperties  
 Chamado pela estrutura quando o verbo de propriedades do controle foi chamado pelo contêiner.  
  
```  
virtual BOOL OnProperties(
    LPMSG lpMsg,  
    HWND hWndParent,  
    LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMsg`  
 Um ponteiro para a mensagem do Windows que invocou o verbo.  
  
 `hWndParent`  
 Um identificador para a janela pai do controle.  
  
 `lpRect`  
 Um ponteiro para o retângulo usado pelo controle no contêiner.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chamada for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão exibe uma caixa de diálogo modal de propriedade.  
  
 Você também pode usar esta função para fazer com que a exibição das páginas de propriedade do controle. Fazer uma chamada para o `OnProperties` função, passando o identificador do pai do controle no `hWndParent` parâmetro. Nesse caso, os valores de `lpMsg` e `lpRect` os parâmetros são ignorados.  
  
##  <a name="a-nameonqueryhitpointa--colecontrolonqueryhitpoint"></a><a name="onqueryhitpoint"></a>COleControl::OnQueryHitPoint  
 Chamado pela estrutura em resposta a um contêiner **IViewObjectEx::QueryHitPoint** solicitação.  
  
```  
virtual BOOL OnQueryHitPoint(
    DWORD dwAspect,
    LPCRECT pRectBounds,
    POINT ptlLoc,
    LONG lCloseHint,
    DWORD* pHitResult);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwAspect`  
 Especifica como o objeto é representado. Os valores válidos são tirados da enumeração [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) ou **DVASPECT2**.  
  
 `pRectBounds`  
 Ponteiro para uma `RECT` estrutura especificando o retângulo delimitador da área do cliente de controle OLE.  
  
 `ptlLoc`  
 Ponteiro para o **ponto** estrutura especificando o ponto a ser verificada para um sucesso. O ponto é especificado nas coordenadas da área cliente OLE.  
  
 `lCloseHint`  
 A distância que define "Fechar" para o ponto check ocorrência.  
  
 `pHitResult`  
 Ponteiro para o resultado da consulta de ocorrências. Um dos seguintes valores:  
  
- **HITRESULT_OUTSIDE** `ptlLoc` está fora do OLE do objeto e não fechada.  
  
- **HITRESULT_TRANSPARENT** *ptlLoc* está dentro dos limites do objeto OLE, mas não próximo a imagem. Por exemplo, pode ser um ponto no meio de um círculo transparente **HITRESULT_TRANSPARENT**.  
  
- **HITRESULT_CLOSE** `ptlLoc` está dentro ou fora do objeto OLE, mas fechar o suficiente para o objeto a ser considerado dentro. Objetos pequenos, finos ou detalhados podem usar esse valor. Mesmo se um ponto está fora do limite retângulo de um objeto pode ainda ser fechar (Isso é necessário para atingir objetos pequenos).  
  
- **HITRESULT_HIT** `ptlLoc` está dentro da imagem do objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um resultado ocorrência é retornado com êxito; Caso contrário, 0. Um acerto é uma sobreposição com a área de exibição de controle OLE.  
  
### <a name="remarks"></a>Comentários  
 Consultas se o retângulo de exibição de um objeto se sobrepõe a ponto específico (atinge o ponto). `QueryHitPoint`pode ser substituído para testar ocorrências para objetos não retangulares.  
  
##  <a name="a-nameonqueryhitrecta--colecontrolonqueryhitrect"></a><a name="onqueryhitrect"></a>COleControl::OnQueryHitRect  
 Chamado pela estrutura em resposta a um contêiner **IViewObjectEx::QueryHitRect** solicitação.  
  
```  
virtual BOOL OnQueryHitRect(
    DWORD dwAspect,  
    LPCRECT pRectBounds,  
    LPCRECT prcLoc,  
    LONG lCloseHint,  
    DWORD* pHitResult);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwAspect`  
 Especifica como o objeto deve ser representado. Os valores válidos são tirados da enumeração [DVASPECT](http://msdn.microsoft.com/library/windows/desktop/ms690318) ou **DVASPECT2**.  
  
 `pRectBounds`  
 Ponteiro para uma `RECT` estrutura especificando o retângulo delimitador da área do cliente de controle OLE.  
  
 *prcLoc*  
 Ponteiro para o `RECT` estrutura especificando o retângulo a ser verificada para um acerto (sobreposição com o retângulo de objeto), em relação ao canto superior esquerdo do objeto.  
  
 `lCloseHint`  
 Não usado.  
  
 `pHitResult`  
 Ponteiro para o resultado da consulta de ocorrências. Um dos seguintes valores:  
  
- **HITRESULT_OUTSIDE** nenhum ponto no retângulo for atingido, o objeto OLE.  
  
- **HITRESULT_HIT** pelo menos um ponto no retângulo seria um impacto no objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um resultado ocorrência é retornado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Consulta se o retângulo de exibição de um objeto se sobrepuser a qualquer ponto no retângulo determinado (atinge o retângulo). `QueryHitRect`pode ser substituído para testar ocorrências para objetos não retangulares.  
  
##  <a name="a-nameonrenderdataa--colecontrolonrenderdata"></a><a name="onrenderdata"></a>COleControl::OnRenderData  
 Chamado pela estrutura para recuperar dados no formato especificado.  
  
```  
virtual BOOL OnRenderData(
    LPFORMATETC lpFormatEtc,  
    LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato no qual as informações são solicitadas.  
  
 `lpStgMedium`  
 Aponta para um [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura na qual os dados são a ser retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente no objeto de controle usando o [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) ou [DelayRenderFileData](../../mfc/reference/coledatasource-class.md#delayrenderfiledata) funções de membro para renderização atrasada. A implementação padrão dessa função chama `OnRenderFileData` ou `OnRenderGlobalData`, respectivamente, se a mídia de armazenamento fornecido é um arquivo ou memória. Se o formato solicitado é `CF_METAFILEPICT` ou a propriedade persistente formato, a implementação padrão processa os dados apropriados e retorna zero. Caso contrário, ele retorna 0 e não faz nada.  
  
 Se *lpStgMedium-> tymed* é **TYMED_NULL**, o **STGMEDIUM** deve ser alocado e preenchida conforme especificado por *lpFormatEtc-> tymed*. Se não **TYMED_NULL**, o **STGMEDIUM** deve ser preenchido no local com os dados.  
  
 Substitua essa função para fornecer os dados no formato solicitado e mídia. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se os dados forem pequenos e com o tamanho fixo, substituir `OnRenderGlobalData`. Se os dados estiverem em um arquivo ou é de tamanho variável, substituir `OnRenderFileData`.  
  
 Para obter mais informações, consulte o **FORMATETC** e **STGMEDIUM** estruturas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameonrenderfiledataa--colecontrolonrenderfiledata"></a><a name="onrenderfiledata"></a>COleControl::OnRenderFileData  
 Chamado pela estrutura para recuperar dados no formato especificado quando a mídia de armazenamento é um arquivo.  
  
```  
virtual BOOL OnRenderFileData(
    LPFORMATETC lpFormatEtc,  
    CFile* pFile);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato no qual as informações são solicitadas.  
  
 `pFile`  
 Aponta para um [CFile](../../mfc/reference/cfile-class.md) objeto no qual os dados a serem processados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente no objeto de controle usando o [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) a função de membro para processamento posterior. A implementação padrão dessa função simplesmente retorna **FALSE**.  
  
 Substitua essa função para fornecer os dados no formato solicitado e mídia. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular várias mídias de armazenamento, substituir `OnRenderData`. Se os dados estiverem em um arquivo ou é de tamanho variável, substituir `OnRenderFileData`.  
  
 Para obter mais informações, consulte o **FORMATETC** estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameonrenderglobaldataa--colecontrolonrenderglobaldata"></a><a name="onrenderglobaldata"></a>COleControl::OnRenderGlobalData  
 Chamado pela estrutura para recuperar dados no formato especificado quando a mídia de armazenamento especificado é memória global.  
  
```  
virtual BOOL OnRenderGlobalData(
    LPFORMATETC lpFormatEtc,  
    HGLOBAL* phGlobal);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato no qual as informações são solicitadas.  
  
 `phGlobal`  
 Aponta para um identificador de memória global na qual os dados são a ser retornado. Se nenhuma memória foi alocada, esse parâmetro pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente no objeto de controle usando o [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) a função de membro para processamento posterior. A implementação padrão dessa função simplesmente retorna **FALSE**.  
  
 Se `phGlobal` é **nulo**, em seguida, um novo `HGLOBAL` deve ser alocado e retornados em `phGlobal`. Caso contrário, o `HGLOBAL` especificado por `phGlobal` deve ser preenchido com os dados. A quantidade de dados colocados no `HGLOBAL` não deve exceder o tamanho atual do bloco de memória. Além disso, o bloco não pode ser realocado para um tamanho maior.  
  
 Substitua essa função para fornecer os dados no formato solicitado e mídia. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular várias mídias de armazenamento, substituir `OnRenderData`. Se os dados estiverem em um arquivo ou é de tamanho variável, substituir `OnRenderFileData`.  
  
 Para obter mais informações, consulte o **FORMATETC** estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameonresetstatea--colecontrolonresetstate"></a><a name="onresetstate"></a>COleControl::OnResetState  
 Chamado pela estrutura quando as propriedades do controle devem ser definidas para seus valores padrão.  
  
```  
virtual void OnResetState();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão [DoPropExchange](#dopropexchange), passando uma `CPropExchange` objeto que faz com que propriedades sejam definidas para seus valores padrão.  
  
 O gravador de controle pode inserir o código de inicialização para o controle OLE neste substituível. Essa função é chamada quando [IPersistStream::Load](http://msdn.microsoft.com/library/windows/desktop/ms680568) ou [IPersistStorage::Load](http://msdn.microsoft.com/library/windows/desktop/ms680557) falhar, ou [IPersistStreamInit::InitNew](http://msdn.microsoft.com/library/windows/desktop/ms690234) ou [IPersistStorage::InitNew](http://msdn.microsoft.com/library/windows/desktop/ms687194) é chamado, sem primeiro chamar **IPersistStream::Load** ou **IPersistStorage::Load**.  
  
##  <a name="a-nameonsetclientsitea--colecontrolonsetclientsite"></a><a name="onsetclientsite"></a>COleControl::OnSetClientSite  
 Chamado pela estrutura quando o contêiner é chamado do controle **IOleControl::SetClientSite** função.  
  
```  
virtual void OnSetClientSite();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `OnSetClientSite` verifica se as propriedades de caminho de dados são carregadas e, se houver, chama `DoDataPathPropExchange`.  
  
 Substitua essa função para fazer qualquer processamento especial dessa notificação. Em particular, as substituições dessa função devem chamar a classe base.  
  
##  <a name="a-nameonsetdataa--colecontrolonsetdata"></a><a name="onsetdata"></a>COleControl::OnSetData  
 Chamado pela estrutura para substituir os dados do controle com os dados especificados.  
  
```  
virtual BOOL OnSetData(
    LPFORMATETC lpFormatEtc,
    LPSTGMEDIUM lpStgMedium,
    BOOL bRelease);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato dos dados.  
  
 `lpStgMedium`  
 Ponteiro para uma [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura na qual os dados residem.  
  
 `bRelease`  
 **TRUE** se o controle deve liberar a mídia de armazenamento; **FALSE** se o controle deve liberar a mídia de armazenamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se os dados estão na propriedade persistente de formato definidos, a implementação padrão modifica o estado do controle adequadamente. Caso contrário, a implementação padrão não faz nada. Se `bRelease` é **TRUE**, em seguida, uma chamada para **ReleaseStgMedium** for feita; caso contrário, não.  
  
 Substitua essa função para substituir os dados do controle com os dados especificados.  
  
 Para obter mais informações, consulte o **FORMATETC** e **STGMEDIUM** estruturas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameonsetextenta--colecontrolonsetextent"></a><a name="onsetextent"></a>COleControl::OnSetExtent  
 Chamado pela estrutura quando a extensão do controle precisa ser alterado, como resultado de uma chamada para [IOleObject::SetExtent](http://msdn.microsoft.com/library/windows/desktop/ms694330).  
  
```  
virtual BOOL OnSetExtent(LPSIZEL lpSizeL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSizeL`  
 Um ponteiro para o **como** estrutura que usa inteiros longos para representar a largura e altura do controle, expressada em **HIMETRIC** unidades.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a alteração de tamanho foi aceito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão manipula o redimensionamento de extensão do controle. Se o controle está ativo no local, uma chamada para o contêiner **OnPosRectChanged** é feita.  
  
 Substitua essa função para alterar o padrão de redimensionamento do seu controle.  
  
##  <a name="a-nameonsetobjectrectsa--colecontrolonsetobjectrects"></a><a name="onsetobjectrects"></a>COleControl::OnSetObjectRects  
 Chamado pela estrutura para implementar uma chamada para [IOleInPlaceObject::SetObjectRects](http://msdn.microsoft.com/library/windows/desktop/ms683767).  
  
```  
virtual BOOL OnSetObjectRects(
    LPCRECT lpRectPos,  
    LPCRECT lpRectClip);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRectPos*  
 Um ponteiro para uma estrutura RECT que indica a nova posição e tamanho relativo ao contêiner do controle.  
  
 `lpRectClip`  
 Um ponteiro para um `RECT` estrutura indicando uma área retangular ao qual o controle é recortado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o reposicionamento foi aceito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão automaticamente manipula o reposicionamento e redimensionamento de janela de controle e retorna **TRUE**.  
  
 Substitua essa função para alterar o comportamento padrão dessa função.  
  
##  <a name="a-nameonshowtoolbarsa--colecontrolonshowtoolbars"></a><a name="onshowtoolbars"></a>COleControl::OnShowToolBars  
 Chamado pela estrutura quando o controle foi ativado pela IU.  
  
```  
virtual void OnShowToolBars();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada.  
  
##  <a name="a-nameontextchangeda--colecontrolontextchanged"></a><a name="ontextchanged"></a>COleControl::OnTextChanged  
 Chamado pela estrutura quando o valor da propriedade legenda ou texto estoque foi alterado.  
  
```  
virtual void OnTextChanged();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão `InvalidateControl`.  
  
 Substitua essa função se desejar notificação após essa alteração de propriedade.  
  
##  <a name="a-nameonwindowlessmessagea--colecontrolonwindowlessmessage"></a><a name="onwindowlessmessage"></a>COleControl::OnWindowlessMessage  
 Chamado pela estrutura em resposta a um contêiner **IOleInPlaceObjectWindowless::OnWindowMessage** solicitação.  
  
```  
virtual BOOL OnWindowlessMessage(
    UINT msg,
    WPARAM wParam,
    LPARAM lParam,
    LRESULT* plResult);
```  
  
### <a name="parameters"></a>Parâmetros  
 `msg`  
 Identificador da mensagem passados pelo Windows.  
  
 `wParam`  
 Passados pelo Windows. Especifica informações adicionais de mensagem específica. O conteúdo deste parâmetro depende do valor da `msg` parâmetro.  
  
 `lParam`  
 Passados pelo Windows. Especifica informações adicionais de mensagem específica. O conteúdo deste parâmetro depende do valor da `msg` parâmetro.  
  
 *plResult*  
 Código de resultado do Windows. Especifica o resultado do processamento da mensagem e depende da mensagem enviada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Processa as mensagens de janela de controles sem janelas. `COleControl`do `OnWindowlessMessage` deve ser usado para mensagens de janela diferentes mensagens de mouse e teclado. `COleControl`Fornece [SetCapture](#setcapture) e [SetFocus](#setfocus) especificamente para obter o foco de teclado e de captura do mouse para os objetos OLE sem janelas.  
  
 Como objetos sem janelas não tem uma janela, eles precisam de um mecanismo para permitir que as mensagens de expedição de contêiner para eles. Um objeto OLE sem janelas obtém mensagens de seu contêiner, por meio de `OnWindowMessage` método o `IOleInPlaceObjectWindowless` interface (uma extensão de [IOleInPlaceObject](http://msdn.microsoft.com/library/windows/desktop/ms692646) para suporte sem janelas). `OnWindowMessage`não tem um `HWND` parâmetro.  
  
##  <a name="a-nameparenttoclienta--colecontrolparenttoclient"></a><a name="parenttoclient"></a>COleControl::ParentToClient  
 Converte as coordenadas do `pPoint` nas coordenadas do cliente.  
  
```  
virtual UINT ParentToClient(
    LPCRECT lprcBounds,
    LPPOINT pPoint,
    BOOL bHitTest = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lprcBounds`  
 Ponteiro para os limites do controle OLE dentro do contêiner. A área do controle inteiro incluindo bordas e barras de rolagem, mas não a área do cliente.  
  
 `pPoint`  
 Ponteiro para o pai (contêiner) do ponto a ser convertido em coordenadas da área do cliente do controle.  
  
 `bHitTest`  
 Especifica se é ou não teste de clique a ser feito no ponto de.  
  
### <a name="return-value"></a>Valor de retorno  
 Se `bHitTest` é **FALSE**, retorna **HTNOWHERE**. Se `bHitTest` é **TRUE**, retorna o local em que o pai (contêiner) aponte descarregou na área do cliente do controle OLE e é um dos seguinte mouse valores de teste de clique:  
  
- **HTBORDER** na borda de uma janela que não tem uma borda de dimensionamento.  
  
- **HTBOTTOM** na borda horizontal inferior da janela.  
  
- **HTBOTTOMLEFT** no canto inferior esquerdo da borda da janela.  
  
- **HTBOTTOMRIGHT** no canto inferior direito da borda da janela.  
  
- **HTCAPTION** em uma área da barra de título.  
  
- **HTCLIENT** em uma área do cliente.  
  
- **HTERROR** no plano de fundo de tela ou em uma linha divisória entre as janelas (mesmo que **HTNOWHERE** exceto que o **DefWndProc** função Windows produz um bipe do sistema para indicar um erro).  
  
- **HTGROWBOX** em uma caixa de tamanho.  
  
- **HTHSCROLL** na barra de rolagem horizontal.  
  
- **HTLEFT** na borda esquerda da janela.  
  
- **HTMAXBUTTON** em maximizar a um botão.  
  
- **HTMENU** em uma área de menu.  
  
- **HTMINBUTTON** em minimizar um botão.  
  
- **HTNOWHERE** no plano de fundo de tela ou em uma linha divisória entre as janelas.  
  
- **HTREDUCE** em minimizar um botão.  
  
- **HTRIGHT** na borda direita da janela.  
  
- **HTSIZE** em uma caixa de tamanho (mesmo que **HTGROWBOX**).  
  
- **HTSYSMENU** em um menu de controle ou em um botão de fechamento em uma janela filho.  
  
- **HTTOP** na borda superior horizontal da janela.  
  
- **HTTOPLEFT** no canto superior esquerdo da borda da janela.  
  
- **HTTOPRIGHT** no canto superior direito da borda da janela.  
  
- **HTTRANSPARENT** em uma janela no momento é coberta por outra janela.  
  
- **HTVSCROLL** na barra de rolagem vertical.  
  
- **HTZOOM** em maximizar a um botão.  
  
### <a name="remarks"></a>Comentários  
 Na entrada `pPoint` é relativo à origem do pai (canto superior esquerdo do contêiner). Na saída `pPoint` é relativo à origem da área do cliente do controle OLE (canto superior esquerdo da área do cliente do controle).  
  
##  <a name="a-namepostmodaldialoga--colecontrolpostmodaldialog"></a><a name="postmodaldialog"></a>COleControl::PostModalDialog  
 Notifica o contêiner que uma caixa de diálogo modal foi fechada.  
  
```  
void PostModalDialog(HWND hWndParent = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 Identificador para a janela pai da caixa de diálogo modal.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função depois de exibir qualquer caixa de diálogo modal. Você deve chamar essa função para que o contêiner pode habilitar qualquer janelas de nível superior desabilitadas por `PreModalDialog`. Essa função deve ser combinada com uma chamada para `PreModalDialog`.  
  
##  <a name="a-namepremodaldialoga--colecontrolpremodaldialog"></a><a name="premodaldialog"></a>COleControl::PreModalDialog  
 Notifica o contêiner que uma caixa de diálogo modal está prestes a ser exibido.  
  
```  
void PreModalDialog(HWND hWndParent = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 Identificador para a janela pai da caixa de diálogo modal.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função antes de exibir qualquer caixa de diálogo modal. Você deve chamar essa função para que o contêiner pode desabilitar todas as janelas de nível superior. Depois que a caixa de diálogo modal foi exibida, você deve chamar `PostModalDialog`.  
  
##  <a name="a-namerecreatecontrolwindowa--colecontrolrecreatecontrolwindow"></a><a name="recreatecontrolwindow"></a>COleControl::RecreateControlWindow  
 Destrói e recria a janela do controle.  
  
```  
void RecreateControlWindow();
```  
  
### <a name="remarks"></a>Comentários  
 Isso pode ser necessário se você precisar alterar os bits de estilo da janela.  
  
##  <a name="a-namerefresha--colecontrolrefresh"></a><a name="refresh"></a>COleControl::Refresh  
 Força um redesenho do controle OLE.  
  
```  
void Refresh();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função é suportado pelo `COleControl` classe base como um método de estoque, chamado de atualização. Isso permite que os usuários do seu controle OLE redesenhar o controle em um momento específico. Para obter mais informações sobre esse método, consulte o artigo [controles ActiveX: métodos](../../mfc/mfc-activex-controls-methods.md).  
  
##  <a name="a-namereleasecapturea--colecontrolreleasecapture"></a><a name="releasecapture"></a>COleControl::ReleaseCapture  
 Libera a captura do mouse.  
  
```  
BOOL ReleaseCapture();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o controle tem a captura do mouse, a captura é liberada. Caso contrário, essa função não tem nenhum efeito.  
  
##  <a name="a-namereleasedca--colecontrolreleasedc"></a><a name="releasedc"></a>COleControl::ReleaseDC  
 Libera o contexto de dispositivo de exibição de um contêiner de um controle sem janelas, liberando o contexto de dispositivo para uso por outros aplicativos.  
  
```  
int ReleaseDC(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Identifica o contexto de dispositivo de contêiner seja liberado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O aplicativo deve chamar `ReleaseDC` para cada chamada para [GetDC](#getdc).  
  
##  <a name="a-namereparentcontrolwindowa--colecontrolreparentcontrolwindow"></a><a name="reparentcontrolwindow"></a>COleControl::ReparentControlWindow  
 Define o pai do controle.  
  
```  
virtual void ReparentControlWindow(
    HWND hWndOuter,  
    HWND hWndParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hWndOuter*  
 O identificador da janela de controle.  
  
 `hWndParent`  
 O identificador da nova janela pai.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para redefinir o pai da janela de controle.  
  
##  <a name="a-nameresetstockpropsa--colecontrolresetstockprops"></a><a name="resetstockprops"></a>COleControl::ResetStockProps  
 Inicializa o estado do `COleControl` stock propriedades com seus valores padrão.  
  
```  
void ResetStockProps();
```  
  
### <a name="remarks"></a>Comentários  
 As propriedades são: aparência, BackColor, BorderStyle, legenda, habilitado, fonte, cor de primeiro plano, hWnd e texto. Para obter uma descrição das propriedades de estoque, consulte [controles ActiveX: Adicionando propriedades de estoque](../../mfc/mfc-activex-controls-adding-stock-properties.md).  
  
 Você pode melhorar o desempenho de inicialização binário de um controle usando `ResetStockProps` e `ResetVersion` para substituir `COleControl::OnResetState`. Consulte o exemplo abaixo. Para obter mais informações sobre como otimizar a inicialização, consulte [controles ActiveX: otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAxCtl&#7;](../../mfc/reference/codesnippet/cpp/colecontrol-class_8.cpp)]  
  
##  <a name="a-nameresetversiona--colecontrolresetversion"></a><a name="resetversion"></a>COleControl::ResetVersion  
 Inicializa o número de versão para o valor especificado.  
  
```  
void ResetVersion(DWORD dwVersionDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwVersionDefault`  
 O número de versão a ser atribuído ao controle.  
  
### <a name="remarks"></a>Comentários  
 Você pode melhorar o desempenho de inicialização binário de um controle usando `ResetVersion` e `ResetStockProps` para substituir `COleControl::OnResetState`. Consulte o exemplo em [ResetStockProps](#resetstockprops). Para obter mais informações sobre como otimizar a inicialização, consulte [controles ActiveX: otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
##  <a name="a-namescrollwindowa--colecontrolscrollwindow"></a><a name="scrollwindow"></a>COleControl::ScrollWindow  
 Permite que um objeto OLE sem janelas rolar uma área dentro de sua imagem ativa no local na tela.  
  
```  
void ScrollWindow(
    int xAmount,
    int yAmount,
    LPCRECT lpRect = NULL,
    LPCRECT lpClipRect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `xAmount`  
 Especifica a quantidade, em unidades de dispositivo, de rolagem horizontal. Esse parâmetro deve ser um valor negativo para rolar para a esquerda.  
  
 `yAmount`  
 Especifica a quantidade, em unidades de dispositivo de rolagem vertical. Esse parâmetro deve ser um valor negativo para rolar para cima.  
  
 `lpRect`  
 Aponta para um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou estrutura RECT que especifica a parte da área do cliente do objeto OLE rolar, nas coordenadas do cliente da janela. Se `lpRect` é **nulo**, área do cliente do objeto OLE inteiro é rolada.  
  
 `lpClipRect`  
 Aponta para um `CRect` objeto ou `RECT` que especifica o retângulo clipe à estrutura. Apenas os pixels dentro do retângulo serão rolados. Bits fora do retângulo não são afetadas, mesmo se eles estiverem no `lpRect` retângulo. Se `lpClipRect` é **nulo**, sem recorte é executada no retângulo rolagem.  
  
##  <a name="a-nameselectfontobjecta--colecontrolselectfontobject"></a><a name="selectfontobject"></a>COleControl::SelectFontObject  
 Seleciona uma fonte em um contexto de dispositivo.  
  
```  
CFont* SelectFontObject(
    CDC* pDC,  
    CFontHolder& fontHolder);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para um objeto de contexto de dispositivo.  
  
 `fontHolder`  
 Referência para o [CFontHolder](../../mfc/reference/cfontholder-class.md) objeto que representa a fonte a ser selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a fonte selecionada anteriormente. Quando o chamador concluiu todas as operações de desenho que usam *fontHolder,* deve selecionar novamente a fonte selecionada anteriormente, passando-o como um parâmetro para [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject).  
  
##  <a name="a-nameselectstockfonta--colecontrolselectstockfont"></a><a name="selectstockfont"></a>COleControl::SelectStockFont  
 Seleciona a propriedade Font estoque em um contexto de dispositivo.  
  
```  
CFont* SelectStockFont(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 O contexto de dispositivo no qual a fonte será selecionada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o selecionado anteriormente `CFont` objeto. Você deve usar [CDC::SelectObject](../../mfc/reference/cdc-class.md#selectobject) para selecionar essa fonte novamente no contexto do dispositivo quando tiver terminado.  
  
##  <a name="a-nameserializeextenta--colecontrolserializeextent"></a><a name="serializeextent"></a>COleControl::SerializeExtent  
 Serializa ou inicializa o estado do vídeo espaço alocado para o controle.  
  
```  
void SerializeExtent(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ar`  
 Um `CArchive` objeto a ser serializado para ou de.  
  
### <a name="remarks"></a>Comentários  
 Você pode melhorar o desempenho de persistência binário de um controle usando `SerializeExtent`, `SerializeStockProps`, e `SerializeVersion` para substituir **COleControl::Serialize**. Consulte o exemplo abaixo. Para obter mais informações sobre como otimizar a inicialização, consulte [controles ActiveX: otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCAxCtl n º&8;](../../mfc/reference/codesnippet/cpp/colecontrol-class_9.cpp)]  
  
##  <a name="a-nameserializestockpropsa--colecontrolserializestockprops"></a><a name="serializestockprops"></a>COleControl::SerializeStockProps  
 Serializa ou inicializa o estado do `COleControl` propriedades de estoque: aparência, BackColor, BorderStyle, legenda, habilitado, fonte, cor de primeiro plano e texto.  
  
```  
void SerializeStockProps(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ar`  
 Um `CArchive` objeto a ser serializado para ou de.  
  
### <a name="remarks"></a>Comentários  
 Para obter uma descrição das propriedades de estoque, consulte [controles ActiveX: Adicionando propriedades de estoque](../../mfc/mfc-activex-controls-adding-stock-properties.md).  
  
 Você pode melhorar o desempenho de persistência binário de um controle usando `SerializeStockProps`, `SerializeExtent`, e `SerializeVersion` para substituir **COleControl::Serialize**. Para obter um exemplo, consulte o código em [SerializeExtent](#serializeextent). Para obter mais informações sobre como otimizar a inicialização, consulte [controles ActiveX: otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
##  <a name="a-nameserializeversiona--colecontrolserializeversion"></a><a name="serializeversion"></a>COleControl::SerializeVersion  
 Serializa ou inicializa o estado das informações de versão do controle.  
  
```  
DWORD SerializeVersion(
    CArchive& ar,
    DWORD dwVersionDefault,
    BOOL bConvert = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ar`  
 Um `CArchive` objeto a ser serializado para ou de.  
  
 `dwVersionDefault`  
 O número de versão atual do controle.  
  
 `bConvert`  
 Indica se os dados persistentes devem ser convertidos para o formato mais recente quando ele é salvo ou mantido no mesmo formato que tinha quando foi carregado.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de versão do controle. Se o arquivo especificado está carregando, `SerializeVersion` retorna a versão carregada a partir desse arquivo. Caso contrário, ele retorna a versão carregada atualmente.  
  
### <a name="remarks"></a>Comentários  
 Você pode melhorar o desempenho de persistência binário de um controle usando `SerializeVersion`, `SerializeExtent`, e `SerializeStockProps` para substituir **COleControl::Serialize**. Para obter um exemplo, consulte o código em [SerializeExtent](#serializeextent). Para obter mais informações sobre como otimizar a inicialização, consulte [controles ActiveX: otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
##  <a name="a-namesetappearancea--colecontrolsetappearance"></a><a name="setappearance"></a>COleControl::SetAppearance  
 Define o valor da propriedade Appearance estoque do seu controle.  
  
```  
void SetAppearance (short sAppearance);
```  
  
### <a name="parameters"></a>Parâmetros  
 *sAppearance*  
 A **curto** ( `VT_I2`) a ser usada para a aparência de seu controle. Um valor de zero define a aparência do controle para simples e um valor de 1 define a aparência do controle para 3D.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre propriedades de estoque, consulte [controles ActiveX: propriedades](../../mfc/mfc-activex-controls-properties.md).  
  
##  <a name="a-namesetbackcolora--colecontrolsetbackcolor"></a><a name="setbackcolor"></a>COleControl::SetBackColor  
 Define o valor da propriedade BackColor estoque do seu controle.  
  
```  
void SetBackColor(OLE_COLOR dwBackColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwBackColor*  
 Um **OLE_COLOR** valor a ser usado para o plano de fundo de desenho do seu controle.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre como usar essa propriedade e outras propriedades relacionadas, consulte o artigo [controles ActiveX: propriedades](../../mfc/mfc-activex-controls-properties.md).  
  
##  <a name="a-namesetborderstylea--colecontrolsetborderstyle"></a><a name="setborderstyle"></a>COleControl::SetBorderStyle  
 Define o valor da propriedade BorderStyle estoque do seu controle.  
  
```  
void SetBorderStyle(short sBorderStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *sBorderStyle*  
 O novo estilo de borda do controle; 0 não indica que nenhuma borda e 1 indica uma borda normal.  
  
### <a name="remarks"></a>Comentários  
 A janela de controle será recriada e `OnBorderStyleChanged` chamado.  
  
##  <a name="a-namesetcapturea--colecontrolsetcapture"></a><a name="setcapture"></a>COleControl::SetCapture  
 Faz com que a janela do controle contêiner tomar posse da captura do mouse no nome do controle.  
  
```  
CWnd* SetCapture();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o **CWnd** objeto window que recebeu entrada do mouse.  
  
### <a name="remarks"></a>Comentários  
 Se o controle é ativado e sem janelas, essa função faz com que a janela do controle contêiner tomar posse da captura do mouse, em nome do controle. Caso contrário, essa função faz com que o controle propriamente dito para tomar posse da captura do mouse (mesmo que `CWnd::SetCapture`).  
  
##  <a name="a-namesetcontrolsizea--colecontrolsetcontrolsize"></a><a name="setcontrolsize"></a>COleControl::SetControlSize  
 Define o tamanho da janela de controle OLE e notifica o contêiner que está mudando o site do controle.  
  
```  
BOOL SetControlSize(int cx, int cy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cx`  
 Especifica a nova largura do controle em pixels.  
  
 `cy`  
 Especifica a nova altura do controle em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chamada foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função não deve ser usada no construtor do controle.  
  
 Observe que todas as coordenadas para o windows de controle são relativas ao canto superior esquerdo do controle.  
  
##  <a name="a-namesetenableda--colecontrolsetenabled"></a><a name="setenabled"></a>COleControl::SetEnabled  
 Define o valor da propriedade Enabled do controle de estoque.  
  
```  
void SetEnabled(BOOL bEnabled);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnabled`  
 **TRUE** se o controle for habilitado; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Depois de definir essa propriedade, **OnEnabledChange** é chamado.  
  
##  <a name="a-namesetfocusa--colecontrolsetfocus"></a><a name="setfocus"></a>COleControl::SetFocus  
 Faz com que a janela do controle contêiner tomar posse do foco de entrada em nome do controle.  
  
```  
CWnd* SetFocus();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o **CWnd** objeto window que anteriormente tinha o foco de entrada, ou **nulo** se não houver nenhuma janela.  
  
### <a name="remarks"></a>Comentários  
 Se o controle é ativado e sem janelas, essa função faz com que a janela do controle contêiner tomar posse do foco de entrada, em nome do controle. O foco de entrada direciona a entrada do teclado para a janela do contêiner e o contêiner envia todas as mensagens subsequentes do teclado para o objeto OLE que chama `SetFocus`. Perde qualquer janela que anteriormente tinha o foco de entrada.  
  
 Se o controle for sem janela, essa função faz com que o controle propriamente dito para tomar posse do foco de entrada (mesmo que `CWnd::SetFocus`).  
  
##  <a name="a-namesetfonta--colecontrolsetfont"></a><a name="setfont"></a>COleControl::SetFont  
 Define a propriedade fonte estoque do seu controle.  
  
```  
void SetFont(LPFONTDISP pFontDisp);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pFontDisp*  
 Um ponteiro para uma interface de expedição de fonte.  
  
##  <a name="a-namesetforecolora--colecontrolsetforecolor"></a><a name="setforecolor"></a>COleControl::SetForeColor  
 Define o valor da propriedade ForeColor estoque do seu controle.  
  
```  
void SetForeColor(OLE_COLOR dwForeColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwForeColor*  
 Um **OLE_COLOR** valor a ser usado para desenho de controle de primeiro plano.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre como usar essa propriedade e outras propriedades relacionadas, consulte o artigo [controles ActiveX: propriedades](../../mfc/mfc-activex-controls-properties.md).  
  
##  <a name="a-namesetinitialdataformatsa--colecontrolsetinitialdataformats"></a><a name="setinitialdataformats"></a>COleControl::SetInitialDataFormats  
 Chamado pela estrutura para inicializar a lista de formatos de dados suportados pelo controle.  
  
```  
virtual void SetInitialDataFormats();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão especifica dois formatos: `CF_METAFILEPICT` e a propriedade persistente definida.  
  
##  <a name="a-namesetinitialsizea--colecontrolsetinitialsize"></a><a name="setinitialsize"></a>COleControl::SetInitialSize  
 Define o tamanho de um controle OLE quando exibido pela primeira vez em um contêiner.  
  
```  
void SetInitialSize(
    int cx,  
    int cy);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cx`  
 A largura inicial do controle OLE em pixels.  
  
 `cy`  
 A altura inicial do controle OLE em pixels.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função em seu construtor para definir o tamanho inicial do seu controle. O tamanho inicial é medido em unidades de dispositivo ou pixels. É recomendável que essa chamada seja feita no construtor do controle.  
  
##  <a name="a-namesetmodifiedflaga--colecontrolsetmodifiedflag"></a><a name="setmodifiedflag"></a>COleControl::SetModifiedFlag  
 Altera o estado de um controle modificado.  
  
```  
void SetModifiedFlag(BOOL bModified = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bModified`  
 O novo valor para o controle modificada do sinalizador. **TRUE** indica que o estado do controle foi modificado; **FALSE** indica que o estado do controle apenas foi salva.  
  
### <a name="remarks"></a>Comentários  
 Esta função sempre que ocorre uma alteração que afetam o estado persistente do controle de chamada. Por exemplo, se o valor de uma propriedade persistente for alterado, chame essa função com `bModified` **TRUE**.  
  
##  <a name="a-namesetnotpermitteda--colecontrolsetnotpermitted"></a><a name="setnotpermitted"></a>COleControl::SetNotPermitted  
 Indica que uma solicitação de edição falhou.  
  
```  
void SetNotPermitted();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função quando `BoundPropertyRequestEdit` falhar. Essa função gera uma exceção do tipo **COleDispScodeException** para indicar que a operação não foi permitida.  
  
##  <a name="a-namesetnotsupporteda--colecontrolsetnotsupported"></a><a name="setnotsupported"></a>COleControl::SetNotSupported  
 Impede a modificação para o valor da propriedade do controle do usuário.  
  
```  
void SetNotSupported();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função em vez da função de conjunto de qualquer propriedade que não há suporte para a modificação do valor da propriedade pelo usuário do controle. Um exemplo seria uma propriedade é somente leitura.  
  
##  <a name="a-namesetrectincontainera--colecontrolsetrectincontainer"></a><a name="setrectincontainer"></a>COleControl::SetRectInContainer  
 Define as coordenadas do retângulo do controle relativo ao contêiner, expressado em unidades de dispositivo.  
  
```  
BOOL SetRectInContainer(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Um ponteiro para um retângulo que contém novas coordenadas do controle relativo ao contêiner.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chamada foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o controle estiver aberto, ele é redimensionado; Caso contrário, o contêiner **OnPosRectChanged** função é chamada.  
  
##  <a name="a-namesettexta--colecontrolsettext"></a><a name="settext"></a>COleControl::SetText  
 Define o valor da propriedade estoque de legenda ou o texto do controle.  
  
```  
void SetText(LPCTSTR pszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszText`  
 Um ponteiro para uma cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Observe que as propriedades de legenda e o texto de estoque são mapeadas para o mesmo valor. Isso significa que as alterações feitas em qualquer propriedade alterará automaticamente as duas propriedades. Em geral, um controle deve oferecer suporte o legenda de estoque ou propriedade de texto, mas não ambos.  
  
##  <a name="a-namethrowerrora--colecontrolthrowerror"></a><a name="throwerror"></a>COleControl::ThrowError  
 Indica a ocorrência de um erro em seu controle.  
  
```  
void ThrowError(
    SCODE sc,  
    UINT nDescriptionID,  
    UINT nHelpID = -1);

 
void ThrowError(
    SCODE sc,  
    LPCTSTR pszDescription = NULL,  
    UINT nHelpID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `sc`  
 O valor de código de status a ser relatado. Para obter uma lista completa de códigos de possíveis, consulte o artigo [controles ActiveX: tópicos avançados](../../mfc/mfc-activex-controls-advanced-topics.md).  
  
 `nDescriptionID`  
 A ID de recurso de cadeia de caracteres da exceção sejam relatados.  
  
 `nHelpID`  
 A ID do tópico ajuda a serem relatados.  
  
 `pszDescription`  
 Uma cadeia de caracteres que contém uma explicação sobre a exceção a ser relatado.  
  
### <a name="remarks"></a>Comentários  
 Essa função só deve ser chamada de dentro de uma função de Get ou Set de uma propriedade OLE ou a implementação de um método de automação OLE. Se você precisa sinalizar erros que ocorrem em outros momentos, você deve disparar o evento de erro estoque.  
  
##  <a name="a-nametransformcoordsa--colecontroltransformcoords"></a><a name="transformcoords"></a>COleControl::TransformCoords  
 Transformações coordenam os valores entre **HIMETRIC** unidades e as nativo do contêiner.  
  
```  
void TransformCoords(
    POINTL* lpptlHimetric,  
    POINTF* lpptfContainer,  
    DWORD flags);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpptlHimetric*  
 Ponteiro para uma **POINTL** estrutura que contém coordenadas em **HIMETRIC** unidades.  
  
 *lpptfContainer*  
 Ponteiro para uma **POINTF** estrutura que contém coordenadas no tamanho da unidade do contêiner.  
  
 `flags`  
 Uma combinação dos seguintes valores:  
  
- **XFORMCOORDS_POSITION** uma posição no contêiner.  
  
- **XFORMCOORDS_SIZE** um tamanho no contêiner.  
  
- **XFORMCOORDS_HIMETRICTOCONTAINER** transformação **HIMETRIC** unidades para unidades do contêiner.  
  
- **XFORMCOORDS_CONTAINERTOHIMETRIC** transformação unidades do contêiner para **HIMETRIC** unidades.  
  
### <a name="remarks"></a>Comentários  
 Os primeiros dois sinalizadores, **XFORMCOORDS_POSITION** e **XFORMCOORDS_SIZE**, indicar se as coordenadas devem ser tratadas como uma posição ou um tamanho. Os dois sinalizadores restantes indicam a direção da transformação.  
  
##  <a name="a-nametranslatecolora--colecontroltranslatecolor"></a><a name="translatecolor"></a>COleControl::TranslateColor  
 Converte um valor de cor do **OLE_COLOR** de tipo de dados para o [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) tipo de dados.  
  
```  
COLORREF TranslateColor(
    OLE_COLOR clrColor,  
    HPALETTE hpal = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clrColor`  
 A **OLE_COLOR** tipo de dados. Para obter mais informações, consulte o Windows [OleTranslateColor](http://msdn.microsoft.com/library/windows/desktop/ms694353) função.  
  
 `hpal`  
 Um identificador para uma paleta opcional; pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de 32 bits de cor RGB (vermelho, verde, azul) que define sólido de cores mais próximo do `clrColor` valor que pode representar o dispositivo.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil para converter as propriedades ForeColor e BackColor estoque para **COLORREF** tipos usados por [CDC](../../mfc/reference/cdc-class.md) funções de membro.  
  
##  <a name="a-namewillambientsbevalidduringloada--colecontrolwillambientsbevalidduringload"></a><a name="willambientsbevalidduringload"></a>COleControl::WillAmbientsBeValidDuringLoad  
 Determina se o controle deve usar os valores das propriedades de ambiente como valores padrão, quando ele for carregado subsequentemente do estado persistente.  
  
```  
BOOL WillAmbientsBeValidDuringLoad();
```  
  
### <a name="return-value"></a>Valor de retorno  
 NonZero indica que as propriedades do ambiente será válidas; Caso contrário, propriedades de ambiente não serão válidas.  
  
### <a name="remarks"></a>Comentários  
 Em alguns contêineres, o controle pode não ter acesso às propriedades do seus ambiente durante a chamada inicial para a substituição de `COleControl::DoPropExchange`. Esse é o caso se o contêiner chama [IPersistStreamInit::Load](http://msdn.microsoft.com/library/windows/desktop/ms680730) ou [IPersistStorage::Load](http://msdn.microsoft.com/library/windows/desktop/ms680557) antes de chamar [IOleObject::SetClientSite](http://msdn.microsoft.com/library/windows/desktop/ms684013) (isto é, se ele não cumpre o **OLEMISC_SETCLIENTSITEFIRST** bits de status).  
  
##  <a name="a-namewindowproca--colecontrolwindowproc"></a><a name="windowproc"></a>COleControl::WindowProc  
 Fornece um procedimento do Windows para uma `COleControl` objeto.  
  
```  
virtual LRESULT WindowProc(
    UINT message,  
    WPARAM wParam,  
    LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 `message`  
 Especifica a mensagem do Windows a serem processados.  
  
 `wParam`  
 Fornece informações adicionais usadas no processamento da mensagem. O valor do parâmetro depende da mensagem.  
  
 `lParam`  
 Fornece informações adicionais usadas no processamento da mensagem. O valor do parâmetro depende da mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno da mensagem enviada.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para enviar mensagens específicas por meio do mapa da mensagem do controle.  
  
## <a name="see-also"></a>Consulte também  
 [CIRC3 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Exemplo MFC TESTHELP](../../visual-cpp-samples.md)   
 [Classe COlePropertyPage](../../mfc/reference/colepropertypage-class.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CFontHolder](../../mfc/reference/cfontholder-class.md)   
 [Classe CPictureHolder](../../mfc/reference/cpictureholder-class.md)

