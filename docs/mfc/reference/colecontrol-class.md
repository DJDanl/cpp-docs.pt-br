---
title: "Classe de COleControl | Microsoft Docs"
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
  - "COleControl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleControl"
  - "controles [MFC], O OLE"
  - "controles [MFC], sem o windows"
  - "controles OLE, MFC"
  - "controles sem o windows"
  - "controles sem o windows, MFC"
ms.assetid: 53e95299-38e8-447b-9c5f-a381d27f5123
caps.latest.revision: 25
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleControl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe base poderosa para controladores OLE desenvolvimento.  
  
## Sintaxe  
  
```  
class COleControl : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControl::COleControl](../Topic/COleControl::COleControl.md)|Cria um objeto de `COleControl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControl::AmbientAppearance](../Topic/COleControl::AmbientAppearance.md)|Recupera a aparência do controle atual.|  
|[COleControl::AmbientBackColor](../Topic/COleControl::AmbientBackColor.md)|Retorna o valor da propriedade de ambiente BackColor.|  
|[COleControl::AmbientDisplayName](../Topic/COleControl::AmbientDisplayName.md)|Retorna o nome do controle como especificado pelo recipiente.|  
|[COleControl::AmbientFont](../Topic/COleControl::AmbientFont.md)|Retorna o valor da propriedade de ambiente de fonte.|  
|[COleControl::AmbientForeColor](../Topic/COleControl::AmbientForeColor.md)|Retorna o valor da propriedade de ambiente de ForeColor.|  
|[COleControl::AmbientLocaleID](../Topic/COleControl::AmbientLocaleID.md)|Retorna a identificação da localidade de contêiner|  
|[COleControl::AmbientScaleUnits](../Topic/COleControl::AmbientScaleUnits.md)|Retorna o tipo de unidades usadas pelo recipiente.|  
|[COleControl::AmbientShowGrabHandles](../Topic/COleControl::AmbientShowGrabHandles.md)|Determina se a captura alças são exibidas.|  
|[COleControl::AmbientShowHatching](../Topic/COleControl::AmbientShowHatching.md)|Determina se chocar é exibido.|  
|[COleControl::AmbientTextAlign](../Topic/COleControl::AmbientTextAlign.md)|Retorna o tipo de alinhamento de texto especificado pelo recipiente.|  
|[COleControl::AmbientUIDead](../Topic/COleControl::AmbientUIDead.md)|Determina se o controle responder às ações da interface do usuário.|  
|[COleControl::AmbientUserMode](../Topic/COleControl::AmbientUserMode.md)|Determina o modo de contêiner.|  
|[COleControl::BoundPropertyChanged](../Topic/COleControl::BoundPropertyChanged.md)|Notifica o contêiner que uma propriedade que foi alterada.|  
|[COleControl::BoundPropertyRequestEdit](../Topic/COleControl::BoundPropertyRequestEdit.md)|Solicitar permissão para editar o valor da propriedade.|  
|[COleControl::ClientToParent](../Topic/COleControl::ClientToParent.md)|Converte um ponto em relação à origem do controle a um ponto em relação à fonte do seu contêiner.|  
|[COleControl::ClipCaretRect](../Topic/COleControl::ClipCaretRect.md)|Ajustar um retângulo caret se é sobreposta por um controle.|  
|[COleControl::ControlInfoChanged](../Topic/COleControl::ControlInfoChanged.md)|Chamar essa função após o conjunto de mnemônicos tratadas pelo controle foi alterado.|  
|[COleControl::DisplayError](../Topic/COleControl::DisplayError.md)|Exibe os eventos de erro para o usuário do controle.|  
|[COleControl::DoClick](../Topic/COleControl::DoClick.md)|Implementação do método de stock de `DoClick` .|  
|[COleControl::DoPropExchange](../Topic/COleControl::DoPropExchange.md)|Serializa as propriedades de um objeto de `COleControl` .|  
|[COleControl::DoSuperclassPaint](../Topic/COleControl::DoSuperclassPaint.md)|Redesenho do OLE um controlador que tenha sido derivado de um controle do windows.|  
|[COleControl::EnableSimpleFrame](../Topic/COleControl::EnableSimpleFrame.md)|Permite suporte simples de quadro chave para um controle.|  
|[COleControl::ExchangeExtent](../Topic/COleControl::ExchangeExtent.md)|Serializa a largura e a altura do controle.|  
|[COleControl::ExchangeStockProps](../Topic/COleControl::ExchangeStockProps.md)|Serializa as propriedades do estoque de controle.|  
|[COleControl::ExchangeVersion](../Topic/COleControl::ExchangeVersion.md)|Serializa o número de versão do controle.|  
|[COleControl::FireClick](../Topic/COleControl::FireClick.md)|O evento é acionado de stock de `Click` .|  
|[COleControl::FireDblClick](../Topic/COleControl::FireDblClick.md)|O evento é acionado de stock de `DblClick` .|  
|[COleControl::FireError](../Topic/COleControl::FireError.md)|O evento é acionado de stock de `Error` .|  
|[COleControl::FireEvent](../Topic/COleControl::FireEvent.md)|Aciona um evento personalizado.|  
|[COleControl::FireKeyDown](../Topic/COleControl::FireKeyDown.md)|O evento é acionado de stock de `KeyDown` .|  
|[COleControl::FireKeyPress](../Topic/COleControl::FireKeyPress.md)|O evento é acionado de stock de `KeyPress` .|  
|[COleControl::FireKeyUp](../Topic/COleControl::FireKeyUp.md)|O evento é acionado de stock de `KeyUp` .|  
|[COleControl::FireMouseDown](../Topic/COleControl::FireMouseDown.md)|O evento é acionado de stock de `MouseDown` .|  
|[COleControl::FireMouseMove](../Topic/COleControl::FireMouseMove.md)|O evento é acionado de stock de `MouseMove` .|  
|[COleControl::FireMouseUp](../Topic/COleControl::FireMouseUp.md)|O evento é acionado de stock de `MouseUp` .|  
|[COleControl::FireReadyStateChange](../Topic/COleControl::FireReadyStateChange.md)|Acionar um evento quando as alterações de estado pronto do controle.|  
|[COleControl::GetActivationPolicy](../Topic/COleControl::GetActivationPolicy.md)|Altera o comportamento padrão de ativação de um controle que oferece suporte a interface de `IPointerInactive` .|  
|[COleControl::GetAmbientProperty](../Topic/COleControl::GetAmbientProperty.md)|Retorna o valor da propriedade de ambiente especificada.|  
|[COleControl::GetAppearance](../Topic/COleControl::GetAppearance.md)|Retorna o valor da propriedade conservada em estoque de aparência.|  
|[COleControl::GetBackColor](../Topic/COleControl::GetBackColor.md)|Retorna o valor da propriedade conservada em estoque BackColor.|  
|[COleControl::GetBorderStyle](../Topic/COleControl::GetBorderStyle.md)|Retorna o valor da propriedade conservada em estoque de BorderStyle.|  
|[COleControl::GetCapture](../Topic/COleControl::GetCapture.md)|Determina se um objeto sem janelas, ativada de controle tem a captura do mouse.|  
|[COleControl::GetClassID](../Topic/COleControl::GetClassID.md)|Recupera o OLE identificação de classe do controle.|  
|[COleControl::GetClientOffset](../Topic/COleControl::GetClientOffset.md)|Recupera a diferença entre o canto superior esquerdo da área retangular do controle e o canto superior esquerdo da área cliente.|  
|[COleControl::GetClientRect](../Topic/COleControl::GetClientRect.md)|Retorna o tamanho da área cliente do controle.|  
|[COleControl::GetClientSite](../Topic/COleControl::GetClientSite.md)|Consulta a um objeto para o ponteiro ao seu site atual do cliente dentro de seu recipiente.|  
|[COleControl::GetControlFlags](../Topic/COleControl::GetControlFlags.md)|Recupera as configurações de sinalizador de controle.|  
|[COleControl::GetControlSize](../Topic/COleControl::GetControlSize.md)|Retorna a posição e tamanho do controlador o OLE.|  
|[COleControl::GetDC](../Topic/COleControl::GetDC.md)|Fornece um meio para que um controle sem janelas obtém um contexto de dispositivo de seu recipiente.|  
|[COleControl::GetEnabled](../Topic/COleControl::GetEnabled.md)|Retorna o valor da propriedade ativado conservada estoque.|  
|[COleControl::GetExtendedControl](../Topic/COleControl::GetExtendedControl.md)|Recupera um ponteiro para um objeto estendido de controle que pertence ao contêiner.|  
|[COleControl::GetFocus](../Topic/COleControl::GetFocus.md)|Determina se o controle tem o foco.|  
|[COleControl::GetFont](../Topic/COleControl::GetFont.md)|Retorna o valor da propriedade conservada em estoque da fonte.|  
|[COleControl::GetFontTextMetrics](../Topic/COleControl::GetFontTextMetrics.md)|Retorna métricas de um objeto de `CFontHolder` .|  
|[COleControl::GetForeColor](../Topic/COleControl::GetForeColor.md)|Retorna o valor da propriedade conservada em estoque. de ForeColor|  
|[COleControl::GetHwnd](../Topic/COleControl::GetHwnd.md)|Retorna o valor da propriedade conservada em estoque do hWnd.|  
|[COleControl::GetMessageString](../Topic/COleControl::GetMessageString.md)|Fornece o texto da barra de status para um item de menu.|  
|[COleControl::GetNotSupported](../Topic/COleControl::GetNotSupported.md)|Impede o acesso ao valor da propriedade de um controle pelo usuário.|  
|[COleControl::GetReadyState](../Topic/COleControl::GetReadyState.md)|Retorna o estado de prontidão do controle.|  
|[COleControl::GetRectInContainer](../Topic/COleControl::GetRectInContainer.md)|Retorna o retângulo de controle em relação ao recipiente.|  
|[COleControl::GetStockTextMetrics](../Topic/COleControl::GetStockTextMetrics.md)|Retorna métricas de propriedade conservada em estoque da fonte.|  
|[COleControl::GetText](../Topic/COleControl::GetText.md)|Retorna o valor da propriedade conservada em estoque de texto ou da legenda.|  
|[COleControl::GetWindowlessDropTarget](../Topic/COleControl::GetWindowlessDropTarget.md)|Substituição para permitir que um controle sem o windows é o destino de arrastar e solte operações.|  
|[COleControl::InitializeIIDs](../Topic/COleControl::InitializeIIDs.md)|Informa a classe base de IIDs que o controle usará.|  
|[COleControl::InternalGetFont](../Topic/COleControl::InternalGetFont.md)|Retorna um objeto de `CFontHolder` para a propriedade conservada em estoque da fonte.|  
|[COleControl::InternalGetText](../Topic/COleControl::InternalGetText.md)|Recupera a propriedade conservada em estoque de legenda ou de texto.|  
|[COleControl::InternalSetReadyState](../Topic/COleControl::InternalSetReadyState.md)|Define o estado de prontidão do controle e aciona o evento de pronto\-estado\- alteração.|  
|[COleControl::InvalidateControl](../Topic/COleControl::InvalidateControl.md)|Invalida uma área do controle exibido, causando o a ser redesenhado.|  
|[COleControl::InvalidateRgn](../Topic/COleControl::InvalidateRgn.md)|Invalida a área cliente da janela contêiner dentro da região determinada.  Pode ser usado para redesenhar controles sem janelas na região.|  
|[COleControl::IsConvertingVBX](../Topic/COleControl::IsConvertingVBX.md)|Allows especializou a carga de um controlador do OLE.|  
|[COleControl::IsModified](../Topic/COleControl::IsModified.md)|Determina se o estado de controle for alterado.|  
|[COleControl::IsOptimizedDraw](../Topic/COleControl::IsOptimizedDraw.md)|Indica se o contêiner suporta o desenho otimizado para a operação atual de desenho.|  
|[COleControl::IsSubclassedControl](../Topic/COleControl::IsSubclassedControl.md)|Chamado para determinar se as subclasses de controle do windows.|  
|[COleControl::Load](../Topic/COleControl::Load.md)|Reinicializa todos os dados assíncronas anteriores e iniciar uma nova de carregamento assíncrono propriedade do controle.|  
|[COleControl::LockInPlaceActive](../Topic/COleControl::LockInPlaceActive.md)|Determina se o controle pode ser desativado pelo recipiente.|  
|[COleControl::OnAmbientPropertyChange](../Topic/COleControl::OnAmbientPropertyChange.md)|Chamado quando uma propriedade de ambiente é alterada.|  
|[COleControl::OnAppearanceChanged](../Topic/COleControl::OnAppearanceChanged.md)|Chamado quando a propriedade conservada em estoque de aparência é alterada.|  
|[COleControl::OnBackColorChanged](../Topic/COleControl::OnBackColorChanged.md)|Chamado quando a propriedade BackColor de estoque é alterada.|  
|[COleControl::OnBorderStyleChanged](../Topic/COleControl::OnBorderStyleChanged.md)|Chamado quando a propriedade de BorderStyle de estoque é alterada.|  
|[COleControl::OnClick](../Topic/COleControl::OnClick.md)|Chamado para acionar o evento de stock de clique.|  
|[COleControl::OnClose](../Topic/COleControl::OnClose.md)|Notifica o controle que `IOleControl::Close` foi chamado.|  
|[COleControl::OnDoVerb](../Topic/COleControl::OnDoVerb.md)|Chamado após um verbo do controle foi executado.|  
|[COleControl::OnDraw](../Topic/COleControl::OnDraw.md)|Chamado quando um controle é solicitado para se redesenho.|  
|[COleControl::OnDrawMetafile](../Topic/COleControl::OnDrawMetafile.md)|Chamado pelo contêiner quando um controle é solicitado para se redesenho que usa um contexto do dispositivo de metarquivo.|  
|[COleControl::OnEdit](../Topic/COleControl::OnEdit.md)|Chamado pelo recipiente a interface do usuário ativar um controlador do OLE.|  
|[COleControl::OnEnabledChanged](../Topic/COleControl::OnEnabledChanged.md)|Chamado quando a propriedade ativado conservada em estoque é alterada.|  
|[COleControl::OnEnumVerbs](../Topic/COleControl::OnEnumVerbs.md)|Chamado pelo recipiente para enumerar os verbos de um controle.|  
|[COleControl::OnEventAdvise](../Topic/COleControl::OnEventAdvise.md)|Chamado quando os manipuladores de eventos estejam conectados ou desconectados de um controle.|  
|[COleControl::OnFontChanged](../Topic/COleControl::OnFontChanged.md)|Chamado quando a propriedade conservada em estoque da fonte é alterada.|  
|[COleControl::OnForeColorChanged](../Topic/COleControl::OnForeColorChanged.md)|Chamado quando a propriedade de ForeColor de estoque é alterada.|  
|[COleControl::OnFreezeEvents](../Topic/COleControl::OnFreezeEvents.md)|Chamado quando os eventos de um controle são congelados ou descongelados.|  
|[COleControl::OnGetColorSet](../Topic/COleControl::OnGetColorSet.md)|Notifica o controle que `IOleObject::GetColorSet` foi chamado.|  
|[COleControl::OnGetControlInfo](../Topic/COleControl::OnGetControlInfo.md)|Fornece informações mnemônicos para o contêiner.|  
|[COleControl::OnGetDisplayString](../Topic/COleControl::OnGetDisplayString.md)|Chamado para obter uma cadeia de caracteres para representar um valor de propriedade.|  
|[COleControl::OnGetInPlaceMenu](../Topic/COleControl::OnGetInPlaceMenu.md)|Solicitar a alça de menu de controle que será mesclado com o menu do recipiente.|  
|[COleControl::OnGetNaturalExtent](../Topic/COleControl::OnGetNaturalExtent.md)|Substituição para recuperar o tamanho de exibição de controle mais próximo do modo proposta de tamanho e a extensão.|  
|[COleControl::OnGetPredefinedStrings](../Topic/COleControl::OnGetPredefinedStrings.md)|Retorna o qual a representação de valores possíveis para uma propriedade.|  
|[COleControl::OnGetPredefinedValue](../Topic/COleControl::OnGetPredefinedValue.md)|Retorna o valor que corresponde a uma cadeia de caracteres pré\-definida.|  
|[COleControl::OnGetViewExtent](../Topic/COleControl::OnGetViewExtent.md)|Substituição para recuperar o tamanho das áreas de exibição do controle \(pode ser usado para habilitar o desenho de duas passagem.\)|  
|[COleControl::OnGetViewRect](../Topic/COleControl::OnGetViewRect.md)|Substituição para converter o tamanho do controle em um retângulo que começa em uma posição específica.|  
|[COleControl::OnGetViewStatus](../Topic/COleControl::OnGetViewStatus.md)|Substituição para recuperar o status de exibição de controle.|  
|[COleControl::OnHideToolBars](../Topic/COleControl::OnHideToolBars.md)|Chamado pelo contêiner quando o controle é interface do usuário desativou.|  
|[COleControl::OnInactiveMouseMove](../Topic/COleControl::OnInactiveMouseMove.md)|Substituição para o contêiner para o controle inativo nas mensagens de `WM_MOUSEMOVE` de distribuição do ponteiro do mouse no controle.|  
|[COleControl::OnInactiveSetCursor](../Topic/COleControl::OnInactiveSetCursor.md)|Substituição para o contêiner para o controle inativo nas mensagens de `WM_SETCURSOR` de distribuição do ponteiro do mouse no controle.|  
|[COleControl::OnKeyDownEvent](../Topic/COleControl::OnKeyDownEvent.md)|Chamado depois que o evento KeyDown de estoque foi acionado.|  
|[COleControl::OnKeyPressEvent](../Topic/COleControl::OnKeyPressEvent.md)|Chamado depois que o evento KeyPress de estoque foi acionado.|  
|[COleControl::OnKeyUpEvent](../Topic/COleControl::OnKeyUpEvent.md)|Chamado depois que o evento de KeyUp de estoque foi acionado.|  
|[COleControl::OnMapPropertyToPage](../Topic/COleControl::OnMapPropertyToPage.md)|Indica que a página de propriedades para usar para editar uma propriedade.|  
|[COleControl::OnMnemonic](../Topic/COleControl::OnMnemonic.md)|Chamado quando uma chave mnemônicos do controle é pressionada.|  
|[COleControl::OnProperties](../Topic/COleControl::OnProperties.md)|Chamado quando o verbo de “” propriedades do controle é chamado.|  
|[COleControl::OnQueryHitPoint](../Topic/COleControl::OnQueryHitPoint.md)|Substituição para ver se a exibição de um controle sobrepõem um determinado ponto.|  
|[COleControl::OnQueryHitRect](../Topic/COleControl::OnQueryHitRect.md)|Substituição para ver se a exibição de um controle sobrepostos qualquer ponto em um retângulo especificado.|  
|[COleControl::OnRenderData](../Topic/COleControl::OnRenderData.md)|Chamado pela estrutura para recuperar dados no formato especificado.|  
|[COleControl::OnRenderFileData](../Topic/COleControl::OnRenderFileData.md)|Chamado pela estrutura para recuperar dados de um arquivo no formato especificado.|  
|[COleControl::OnRenderGlobalData](../Topic/COleControl::OnRenderGlobalData.md)|Chamado pela estrutura para recuperar dados de memória global no formato especificado.|  
|[COleControl::OnResetState](../Topic/COleControl::OnResetState.md)|Redefinir as propriedades de um controle para valores padrão.|  
|[COleControl::OnSetClientSite](../Topic/COleControl::OnSetClientSite.md)|Notifica o controle que `IOleControl::SetClientSite` foi chamado.|  
|[COleControl::OnSetData](../Topic/COleControl::OnSetData.md)|Substitui os dados de controle com outro valor.|  
|[COleControl::OnSetExtent](../Topic/COleControl::OnSetExtent.md)|Chamado após a extensão do controle foi alterado.|  
|[COleControl::OnSetObjectRects](../Topic/COleControl::OnSetObjectRects.md)|Chamado depois que as dimensões do controle foram alteradas.|  
|[COleControl::OnShowToolBars](../Topic/COleControl::OnShowToolBars.md)|Quando o controle foi interface do usuário ativou chamado.|  
|[COleControl::OnTextChanged](../Topic/COleControl::OnTextChanged.md)|Chamado quando a propriedade conservada em estoque de texto ou de legenda é alterada.|  
|[COleControl::OnWindowlessMessage](../Topic/COleControl::OnWindowlessMessage.md)|Mensagens de janela dos processos \(diferente de mensagens de mouse e teclado\) para controles sem janelas.|  
|[COleControl::ParentToClient](../Topic/COleControl::ParentToClient.md)|Converte um ponto em relação à fonte do recipiente para um ponto em relação à origem do controle.|  
|[COleControl::PostModalDialog](../Topic/COleControl::PostModalDialog.md)|Notifica o contêiner que uma caixa de diálogo modal foi fechada.|  
|[COleControl::PreModalDialog](../Topic/COleControl::PreModalDialog.md)|Notifica o contêiner que uma caixa de diálogo modal está prestes a ser exibida.|  
|[COleControl::RecreateControlWindow](../Topic/COleControl::RecreateControlWindow.md)|Destrói e recria a janela do controle.|  
|[COleControl::Refresh](../Topic/COleControl::Refresh.md)|Força redesenhar a aparência de um controle.|  
|[COleControl::ReleaseCapture](../Topic/COleControl::ReleaseCapture.md)|Captura do mouse versões.|  
|[COleControl::ReleaseDC](../Topic/COleControl::ReleaseDC.md)|Libera o contexto do dispositivo de vídeo de um contêiner de um controle sem janelas.|  
|[COleControl::ReparentControlWindow](../Topic/COleControl::ReparentControlWindow.md)|Redefine o pai da janela de controle.|  
|[COleControl::ResetStockProps](../Topic/COleControl::ResetStockProps.md)|Inicializa as propriedades do estoque de `COleControl` para seus valores padrão.|  
|[COleControl::ResetVersion](../Topic/COleControl::ResetVersion.md)|Inicializa o número de versão para um determinado valor.|  
|[COleControl::ScrollWindow](../Topic/COleControl::ScrollWindow.md)|Permite que um controle sem janelas role uma área dentro da imagem ativo no lugar na exibição.|  
|[COleControl::SelectFontObject](../Topic/COleControl::SelectFontObject.md)|Seleciona uma propriedade de fonte personalizado em um contexto de dispositivo.|  
|[COleControl::SelectStockFont](../Topic/COleControl::SelectStockFont.md)|Selecione a propriedade conservada em estoque da fonte em um contexto de dispositivo.|  
|[COleControl::SerializeExtent](../Topic/COleControl::SerializeExtent.md)|Serializa ou inicializa o espaço de exibição para o controle.|  
|[COleControl::SerializeStockProps](../Topic/COleControl::SerializeStockProps.md)|Serializa ou inicializa as propriedades do estoque de `COleControl` .|  
|[COleControl::SerializeVersion](../Topic/COleControl::SerializeVersion.md)|Serializa ou inicializa as informações de versão do controle.|  
|[COleControl::SetAppearance](../Topic/COleControl::SetAppearance.md)|Defina o valor da propriedade conservada em estoque de aparência.|  
|[COleControl::SetBackColor](../Topic/COleControl::SetBackColor.md)|Defina o valor da propriedade conservada em estoque BackColor.|  
|[COleControl::SetBorderStyle](../Topic/COleControl::SetBorderStyle.md)|Defina o valor da propriedade conservada em estoque de BorderStyle.|  
|[COleControl::SetCapture](../Topic/COleControl::SetCapture.md)|Faz com que a janela do contêiner do controle utiliza um possessão de captura do mouse no nome do controle.|  
|[COleControl::SetControlSize](../Topic/COleControl::SetControlSize.md)|Define a posição e tamanho do controlador o OLE.|  
|[COleControl::SetEnabled](../Topic/COleControl::SetEnabled.md)|Defina o valor da propriedade ativado conservada estoque.|  
|[COleControl::SetFocus](../Topic/COleControl::SetFocus.md)|Faz com que a janela do contêiner do controle utiliza um possessão de foco de entrada em favor do controle.|  
|[COleControl::SetFont](../Topic/COleControl::SetFont.md)|Defina o valor da propriedade conservada em estoque da fonte.|  
|[COleControl::SetForeColor](../Topic/COleControl::SetForeColor.md)|Defina o valor da propriedade conservada em estoque. de ForeColor|  
|[COleControl::SetInitialSize](../Topic/COleControl::SetInitialSize.md)|Defina o tamanho de um controlador do OLE quando exibido pela primeira vez em um contêiner.|  
|[COleControl::SetModifiedFlag](../Topic/COleControl::SetModifiedFlag.md)|Altera o estado modificado de um controle.|  
|[COleControl::SetNotPermitted](../Topic/COleControl::SetNotPermitted.md)|Indica que uma solicitação de edição falhou.|  
|[COleControl::SetNotSupported](../Topic/COleControl::SetNotSupported.md)|Impede a alteração no valor da propriedade de um controle pelo usuário.|  
|[COleControl::SetRectInContainer](../Topic/COleControl::SetRectInContainer.md)|Define o retângulo de controle em relação ao recipiente.|  
|[COleControl::SetText](../Topic/COleControl::SetText.md)|Defina o valor da propriedade conservada em estoque de texto ou da legenda.|  
|[COleControl::ThrowError](../Topic/COleControl::ThrowError.md)|Sinais que ocorreu um erro em um controlador do OLE.|  
|[COleControl::TransformCoords](../Topic/COleControl::TransformCoords.md)|Transforma valores de coordenadas entre um contêiner e o controle.|  
|[COleControl::TranslateColor](../Topic/COleControl::TranslateColor.md)|Converter um valor de **OLE\_COLOR** a um valor de **COLORREF** .|  
|[COleControl::WillAmbientsBeValidDuringLoad](../Topic/COleControl::WillAmbientsBeValidDuringLoad.md)|Determina se as propriedades de ambiente estarão disponíveis o controle são carregadas na próxima vez.|  
|[COleControl::WindowProc](../Topic/COleControl::WindowProc.md)|Fornece um procedimento do windows para um objeto de `COleControl` .|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControl::DrawContent](../Topic/COleControl::DrawContent.md)|Chamado pela estrutura quando a aparência de controle precisa ser atualizada.|  
|[COleControl::DrawMetafile](../Topic/COleControl::DrawMetafile.md)|Chamado pela estrutura quando o contexto do dispositivo de metarquivo é usado.|  
|[COleControl::IsInvokeAllowed](../Topic/COleControl::IsInvokeAllowed.md)|Permite que a chamada ao método de automação.|  
|[COleControl::SetInitialDataFormats](../Topic/COleControl::SetInitialDataFormats.md)|Chamado pela estrutura para inicializar a lista de formatos de dados suportados pelo controle.|  
  
## Comentários  
 Derivado de `CWnd`, essa classe herda todas as funcionalidades de um objeto da janela do windows mais específico do OLE funcionalidades adicionais, como o acionamento do evento e a capacidade suportar métodos e propriedades.  
  
 Controladores OLE podem ser inseridos em aplicativos de contêiner VELHOS e se comunicar com o recipiente usando um sistema bidirecional do acionamento do evento e expõe métodos e propriedades para o contêiner.  Observe que o recipiente VELHOS padrão oferecem suporte somente a funcionalidade básica de um controlador do OLE.  Não são de suportar recursos estendidos um controlador do OLE.  O evento ocorre quando o acionamento dos eventos são enviados para o contêiner resultado de certas ações que ocorrem no controle.  Por sua vez, o contêiner se comunica com o controle usando expõe um conjunto de métodos e propriedades análogas a membros de funções de membro e dados de C\+\+ classe.  Essa abordagem permite que o desenvolvedor para controlar a aparência do controle e notifique o contêiner quando certas ações ocorrem.  
  
## Controles sem o windows  
 Controladores OLE podem ser ativos no lugar usado sem uma janela.  Os controles sem o windows têm vantagens significativa:  
  
-   Os controles sem o windows podem ser transparentes e não retangulares  
  
-   Os controles sem janelas reduzem o tamanho da instância e a hora de criação do objeto  
  
 Os controles não precisam uma janela.  Os serviços que oferece uma janela podem ser facilmente fornecidos por uma única janela compartilhada \(geralmente o contêiner\) e um bit de distribuir o código.  Ter uma janela é basicamente uma complicação desnecessárias no objeto.  
  
 Quando a ativação sem janelas for usada, o recipiente \(que tem uma janela\) é responsável para fornecer serviços que devem ser fornecidos de outra forma por própria janela do controle.  Por exemplo, se seu controle precisa consulte o foco do teclado, consulte da captura do mouse, ou de obter um contexto de dispositivo, essas operações são gerenciadas pelo recipiente.  `COleControl`[funções de membro de janelas\- operação sem](http://msdn.microsoft.com/pt-br/e9e28f79-9a70-4ae4-a5aa-b3e92f1904df) chama essas operações no recipiente.  
  
 Quando a ativação sem o windows estiver ativada, as mensagens de entrada de representantes do recipiente para `IOleInPlaceObjectWindowless` de controle interfaces \(uma extensão de [IOleInPlaceObject](http://msdn.microsoft.com/library/windows/desktop/ms692646) para suporte sem janelas\).  A implementação de `COleControl` de esta interface despachará essas mensagens através do mapa de mensagem do seu controle, após definir as coordenadas do mouse adequadamente.  Você pode processar mensagens como essas mensagens comuns da janela, adicionando entradas correspondentes no mapa de mensagem.  
  
 Em um controle sem janelas, você sempre deve usar as funções de membro de `COleControl` em vez das funções de membro correspondentes de `CWnd` ou de suas funções da API do windows relacionadas.  
  
 Os objetos do controlador OLE também podem criar uma janela somente quando se tornam ativos, mas a quantidade de trabalho necessária para a transição inativo\- ativa sobe e a velocidade de transição vá para baixo.  Há casos quando isso é um problema: como exemplo, considere uma grade das caixas de texto.  A o cursoring para cima e para baixo através de coluna, cada controle no lugar deve ser ativada e desativada em.  A velocidade transição inativo ativa\/afetará diretamente a velocidade de rolagem.  
  
 Para obter mais informações sobre como desenvolver uma estrutura do controlador OLE, consulte os artigos [Controles ActiveX MFC](../../mfc/mfc-activex-controls.md) e [visão geral: Criando um programa do controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md).  Para obter informações sobre como otimizar controladores OLE, incluindo controles sem janelas e cintilação\- livre, consulte [Controles ActiveX MFC: Otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `COleControl`  
  
## Requisitos  
 **Cabeçalho:** afxctl.h  
  
## Consulte também  
 [O MFC exemplos CIRC3](../../top/visual-cpp-samples.md)   
 [Exemplo TESTHELP MFC](../../top/visual-cpp-samples.md)   
 [Classe de COlePropertyPage](../../mfc/reference/colepropertypage-class.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFontHolder](../../mfc/reference/cfontholder-class.md)   
 [Classe de CPictureHolder](../../mfc/reference/cpictureholder-class.md)