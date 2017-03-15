---
title: Classe CToolBarCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CToolBarCtrl
dev_langs:
- C++
helpviewer_keywords:
- CToolBarCtrl class
- Windows common controls [C++], CToolBarCtrl
- toolbar controls [MFC], CToolBarCtrl class
- tool tips [C++], notifications
ms.assetid: 8f2f8ad2-05d7-4975-8715-3f2eed795248
caps.latest.revision: 22
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
ms.openlocfilehash: 2d3ec23d6147299d9a615e9edb0d3f90680bbfac
ms.lasthandoff: 02/25/2017

---
# <a name="ctoolbarctrl-class"></a>Classe CToolBarCtrl
Fornece a funcionalidade do controle de barra de ferramentas do Windows comuns.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CToolBarCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CToolBarCtrl::CToolBarCtrl](#ctoolbarctrl)|Constrói um objeto `CToolBarCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CToolBarCtrl::AddBitmap](#addbitmap)|Adiciona uma ou mais imagens de botão de bitmap para a lista de imagens de botão disponíveis para um controle de barra de ferramentas.|  
|[CToolBarCtrl::AddButtons](#addbuttons)|Adiciona um ou mais botões a um controle de barra de ferramentas.|  
|[CToolBarCtrl::AddString](#addstring)|Adiciona uma nova cadeia de caracteres passada como uma ID de recurso para a lista interna da barra de ferramentas de cadeias de caracteres.|  
|[CToolBarCtrl::AddStrings](#addstrings)|Adiciona uma nova cadeia de caracteres ou cadeias de caracteres passadas como um ponteiro para um buffer de cadeias de caracteres null separados, para a lista interna da barra de ferramentas de cadeias de caracteres.|  
|[CToolBarCtrl::AutoSize](#autosize)|Redimensiona um controle de barra de ferramentas.|  
|[CToolBarCtrl::ChangeBitmap](#changebitmap)|Altera o bitmap de um botão no controle de barra de ferramentas atual.|  
|[CToolBarCtrl::CheckButton](#checkbutton)|Marca ou desmarca um determinado botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::CommandToIndex](#commandtoindex)|Retorna o índice baseado em zero do botão associado ao identificador de comando especificado.|  
|[CToolBarCtrl::Create](#create)|Cria um controle de barra de ferramentas e a anexa a um `CToolBarCtrl` objeto.|  
|[CToolBarCtrl::CreateEx](#createex)|Cria um controle de barra de ferramentas com os estilos estendidos do Windows especificados e a anexa a um `CToolBarCtrl` objeto.|  
|[CToolBarCtrl::Customize](#customize)|Exibe a caixa de diálogo Personalizar barra de ferramentas.|  
|[CToolBarCtrl::DeleteButton](#deletebutton)|Exclui um botão do controle da barra de ferramentas.|  
|[CToolBarCtrl::EnableButton](#enablebutton)|Habilita ou desabilita o botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetAnchorHighlight](#getanchorhighlight)|Recupera o realce de âncora definindo para uma barra de ferramentas.|  
|[CToolBarCtrl::GetBitmap](#getbitmap)|Recupera o índice do bitmap associado a um botão na barra de ferramentas.|  
|[CToolBarCtrl::GetBitmapFlags](#getbitmapflags)|Obtém sinalizadores associados com o bitmap da barra de ferramentas.|  
|[CToolBarCtrl::GetButton](#getbutton)|Recupera informações sobre o botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetButtonCount](#getbuttoncount)|Recupera uma contagem dos botões no momento no controle de barra de ferramentas.|  
|[CToolBarCtrl::GetButtonInfo](#getbuttoninfo)|Recupera as informações para um botão na barra de ferramentas.|  
|[CToolBarCtrl::GetButtonSize](#getbuttonsize)|Recupera a largura atual e a altura dos botões de barra de ferramentas, em pixels.|  
|[CToolBarCtrl::GetColorScheme](#getcolorscheme)|Recupera o esquema de cores do controle da barra de ferramentas atual.|  
|[CToolBarCtrl::GetDisabledImageList](#getdisabledimagelist)|Recupera a lista de imagens que usa um controle de barra de ferramentas para botões de exibição desabilitada.|  
|[CToolBarCtrl::GetDropTarget](#getdroptarget)|Recupera o [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) interface para um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetExtendedStyle](#getextendedstyle)|Recupera os estilos estendidos para um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetHotImageList](#gethotimagelist)|Recupera a lista de imagens que usa um controle de barra de ferramentas para exibir os botões "hot". Um ponto crítico é realçado quando o ponteiro do mouse está acima dela.|  
|[CToolBarCtrl::GetHotItem](#gethotitem)|Recupera o índice do item ativo na barra de ferramentas.|  
|[CToolBarCtrl::GetImageList](#getimagelist)|Recupera a lista de imagens que usa um controle de barra de ferramentas para exibir os botões em seu estado padrão.|  
|[CToolBarCtrl::GetInsertMark](#getinsertmark)|Recupera a marca de inserção atual da barra de ferramentas.|  
|[CToolBarCtrl::GetInsertMarkColor](#getinsertmarkcolor)|Recupera a cor usada para desenhar a marca de inserção para a barra de ferramentas.|  
|[CToolBarCtrl::GetItemRect](#getitemrect)|Recupera o retângulo delimitador de um botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetMaxSize](#getmaxsize)|Recupera o tamanho total de todos os botões visíveis e os separadores na barra de ferramentas.|  
|[CToolBarCtrl::GetMaxTextRows](#getmaxtextrows)|Recupera o número máximo de linhas de texto exibido no botão da barra de ferramentas.|  
|[CToolBarCtrl::GetMetrics](#getmetrics)|Recupera as métricas de um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetPadding](#getpadding)|Recupera o preenchimento horizontal e vertical do controle da barra de ferramentas atual.|  
|[CToolBarCtrl::GetPressedImageList](#getpressedimagelist)|Recupera a lista de imagens que o controle de barra de ferramentas atual usa para representar botões no estado pressionado.|  
|[CToolBarCtrl::GetRect](#getrect)|Recupera o retângulo delimitador para um botão da barra de ferramentas especificada.|  
|[CToolBarCtrl::GetRows](#getrows)|Recupera o número de linhas de botões exibidos na barra de ferramentas.|  
|[CToolBarCtrl::GetState](#getstate)|Recupera informações sobre o estado do botão especificado em um controle de barra de ferramentas, como se ele é habilitado, pressionado ou marcado.|  
|[CToolBarCtrl::GetString](#getstring)|Recupera uma cadeia de caracteres de barra de ferramentas.|  
|[CToolBarCtrl::GetStyle](#getstyle)|Recupera os estilos atualmente em uso para um controle de barra de ferramentas.|  
|[CToolBarCtrl::GetToolTips](#gettooltips)|Recupera a alça de controle de dica de ferramenta, se houver, associado com o controle de barra de ferramentas.|  
|[CToolBarCtrl::HideButton](#hidebutton)|Oculta ou mostra o botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::HitTest](#hittest)|Determina onde se encontra um ponto em um controle de barra de ferramentas.|  
|[CToolBarCtrl::Indeterminate](#indeterminate)|Define ou limpa o estado indeterminado (cinza) do botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::InsertButton](#insertbutton)|Insere um botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::InsertMarkHitTest](#insertmarkhittest)|Recupera as informações de marca de inserção de um ponto em uma barra de ferramentas.|  
|[CToolBarCtrl::IsButtonChecked](#isbuttonchecked)|Indica se o botão especificado em um controle de barra de ferramentas é verificado.|  
|[CToolBarCtrl::IsButtonEnabled](#isbuttonenabled)|Indica se o botão especificado em um controle de barra de ferramentas está habilitado.|  
|[CToolBarCtrl::IsButtonHidden](#isbuttonhidden)|Indica se o botão especificado em um controle de barra de ferramentas está oculta.|  
|[CToolBarCtrl::IsButtonHighlighted](#isbuttonhighlighted)|Verifica o estado de realce do botão da barra de ferramentas.|  
|[CToolBarCtrl::IsButtonIndeterminate](#isbuttonindeterminate)|Informa se o estado do botão especificado em um controle de barra de ferramentas está indeterminada (cinza).|  
|[CToolBarCtrl::IsButtonPressed](#isbuttonpressed)|Indica se o botão especificado em um controle de barra de ferramentas é pressionado.|  
|[CToolBarCtrl::LoadImages](#loadimages)|Carrega bitmaps na lista de imagens de um controle barra de ferramentas.|  
|[CToolBarCtrl::MapAccelerator](#mapaccelerator)|Um caractere de aceleração é mapeado para um botão da barra de ferramentas.|  
|[CToolBarCtrl::MarkButton](#markbutton)|Define o estado de realce de um determinado botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::MoveButton](#movebutton)|Move um botão de um índice para outro.|  
|[CToolBarCtrl::PressButton](#pressbutton)|Pressiona ou libera o botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::ReplaceBitmap](#replacebitmap)|Substitui o bitmap existente no controle de barra de ferramentas atual com um novo bitmap.|  
|[CToolBarCtrl::RestoreState](#restorestate)|Restaura o estado do controle da barra de ferramentas.|  
|[CToolBarCtrl::SaveState](#savestate)|Salva o estado do controle da barra de ferramentas.|  
|[CToolBarCtrl::SetAnchorHighlight](#setanchorhighlight)|Define o realce de âncora definindo para uma barra de ferramentas.|  
|[CToolBarCtrl::SetBitmapSize](#setbitmapsize)|Define o tamanho das imagens bitmap a ser adicionado a um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetButtonInfo](#setbuttoninfo)|Define as informações de um botão existente em uma barra de ferramentas.|  
|[CToolBarCtrl::SetButtonSize](#setbuttonsize)|Define o tamanho dos botões a serem adicionados a um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetButtonStructSize](#setbuttonstructsize)|Especifica o tamanho do `TBBUTTON` estrutura.|  
|[CToolBarCtrl::SetButtonWidth](#setbuttonwidth)|Define as larguras mínima e máxima de botão no controle de barra de ferramentas.|  
|[CToolBarCtrl::SetCmdID](#setcmdid)|Define o identificador de comando para serem enviadas para a janela do proprietário quando é pressionado o botão especificado.|  
|[CToolBarCtrl::SetColorScheme](#setcolorscheme)|Define o esquema de cores do controle da barra de ferramentas atual.|  
|[CToolBarCtrl::SetDisabledImageList](#setdisabledimagelist)|Define a lista de imagens que irá usar o controle de barra de ferramentas para botões de exibição desabilitada.|  
|[CToolBarCtrl::SetDrawTextFlags](#setdrawtextflags)|Define os sinalizadores na função Win32 [DrawText](http://msdn.microsoft.com/library/windows/desktop/dd162498), que é usado para desenhar o texto no retângulo especificado, formatado de acordo com como os sinalizadores são definidos.|  
|[CToolBarCtrl::SetExtendedStyle](#setextendedstyle)|Define os estilos estendidos para um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetHotImageList](#sethotimagelist)|Define a lista de imagens que irá usar o controle de barra de ferramentas para exibir os botões "hot".|  
|[CToolBarCtrl::SetHotItem](#sethotitem)|Define o item ativo na barra de ferramentas.|  
|[CToolBarCtrl::SetImageList](#setimagelist)|Define a lista de imagens que usará a barra de ferramentas para exibir os botões que estão em seu estado padrão.|  
|[CToolBarCtrl::SetIndent](#setindent)|Define o recuo do primeiro botão em um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetInsertMark](#setinsertmark)|Define a marca de inserção atual da barra de ferramentas.|  
|[CToolBarCtrl::SetInsertMarkColor](#setinsertmarkcolor)|Define a cor usada para desenhar a marca de inserção para a barra de ferramentas.|  
|[CToolBarCtrl::SetMaxTextRows](#setmaxtextrows)|Define o número máximo de linhas de texto exibido no botão da barra de ferramentas.|  
|[CToolBarCtrl::SetMetrics](#setmetrics)|Define as métricas de um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetOwner](#setowner)|Define a janela para receber mensagens de notificação do controle da barra de ferramentas.|  
|[CToolBarCtrl::SetPadding](#setpadding)|Define o preenchimento horizontal e vertical do controle da barra de ferramentas atual.|  
|[CToolBarCtrl::SetPressedImageList](#setpressedimagelist)|Define a lista de imagens que o controle de barra de ferramentas atual usa para representar botões no estado pressionado.|  
|[CToolBarCtrl::SetRows](#setrows)|Define o número de linhas de botões exibidos na barra de ferramentas.|  
|[CToolBarCtrl::SetState](#setstate)|Define o estado do botão especificado em um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetStyle](#setstyle)|Define os estilos de um controle de barra de ferramentas.|  
|[CToolBarCtrl::SetToolTips](#settooltips)|Associa um controle de dica de ferramenta com o controle de barra de ferramentas.|  
|[CToolBarCtrl::SetWindowTheme](#setwindowtheme)|Define o estilo visual de um controle de barra de ferramentas.|  
  
## <a name="remarks"></a>Comentários  
 Esse controle (e, portanto, a `CToolBarCtrl` classe) está disponível apenas para programas em execução na versão do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Um controle comum de barra de ferramentas do Windows é uma janela filho retangular que contém um ou mais botões. Esses botões podem exibir uma imagem de bitmap, uma cadeia de caracteres ou ambos. Quando o usuário escolhe um botão, ele envia uma mensagem de comando para a janela do proprietário da barra de ferramentas. Normalmente, os botões na barra de ferramentas correspondem aos itens de menu do aplicativo. eles fornecem uma maneira mais direta do usuário acessar os comandos de um aplicativo.  
  
 `CToolBarCtrl`os objetos contêm várias estruturas de dados interno importantes: uma lista dos bitmaps de imagem de botão ou uma lista de imagens, uma lista de cadeias de caracteres de rótulo de botão e uma lista de `TBBUTTON` estruturas que associar uma imagem e/ou cadeia de caracteres com a posição, o estilo, estado e identificação do botão de comando. Cada um dos elementos dessas estruturas de dados é chamada por um índice baseado em zero. Antes de usar um `CToolBarCtrl` do objeto, você deve configurar essas estruturas de dados. A lista de cadeias de caracteres pode ser usada apenas para rótulos de botões; não é possível recuperar cadeias de caracteres na barra de ferramentas.  
  
 Para usar um `CToolBarCtrl` do objeto, você normalmente seguirá estas etapas:  
  
1.  Construir o `CToolBarCtrl` objeto.  
  
2.  Chamar [criar](#create) para criar o controle de barra de ferramentas do Windows comuns e anexá-lo a `CToolBarCtrl` objeto. Indica o estilo da barra de ferramentas usando estilos, como **TBSTYLE_TRANSPARENT** para uma barra de ferramentas transparente ou **TBSTYLE_DROPDOWN** para uma barra de ferramentas que oferece suporte a botões no estilo de lista suspensa.  
  
3.  Identifique como você deseja que os botões na barra de ferramentas exibida:  
  
    -   Para usar imagens de bitmap para os botões, adicione os bitmaps de botão na barra de ferramentas chamando [AddBitmap](#addbitmap).  
  
    -   Para usar imagens exibidas a partir de uma lista de imagens para os botões, especifique a lista de imagens chamando [SetImageList](#setimagelist), [SetHotImageList](#sethotimagelist), ou [SetDisabledImageList](#setdisabledimagelist).  
  
    -   Para usar rótulos de cadeia de caracteres para botões, adicionar as cadeias de caracteres na barra de ferramentas chamando [AddString](#addstring) e/ou [AddStrings](#addstrings).  
  
4.  Adicionar estruturas de botão na barra de ferramentas chamando [AddButtons](#addbuttons).  
  
5.  Se você quiser dicas de ferramenta para um botão da barra de ferramentas em uma janela do proprietário que não é um `CFrameWnd`, você precisa manipular o **TTN_NEEDTEXT** mensagens na janela do proprietário da barra de ferramentas, conforme descrito em [manipulando notificações de dica de ferramenta](../../mfc/handling-tool-tip-notifications.md). Se a janela pai da barra de ferramentas é derivada de `CFrameWnd`, dicas de ferramenta são exibidas sem esforço adicional de você porque `CFrameWnd` fornece um manipulador padrão.  
  
6.  Se você quiser que o usuário seja capaz de personalizar a barra de ferramentas, lidar com mensagens de notificação de personalização na janela do proprietário conforme descrito em [manipulando notificações de personalização](../../mfc/handling-customization-notifications.md).  
  
 Você pode usar [SaveState](#savestate) para salvar o estado atual de um controle de barra de ferramentas no registro e [RestoreState](#restorestate) para restaurar o estado com base nas informações armazenadas anteriormente no registro. Além de salvar o estado da barra de ferramentas entre as utilizações do aplicativo, aplicativos normalmente armazenam o estado antes do usuário começa a personalizar a barra de ferramentas no caso do usuário deseja posteriormente restaurar a barra de ferramentas para seu estado original.  
  
## <a name="support-for-internet-explorer-version-40-and-later"></a>Suporte para a versão do Internet Explorer 4.0 e posterior  
 Para dar suporte à funcionalidade introduzida no Internet Explorer, versão 4.0 e posterior, o MFC fornece suporte à lista de imagem e estilos simples e transparentes para os controles de barra de ferramentas.  
  
 Uma barra de ferramentas transparente permite que o cliente sob a barra de ferramentas Mostrar. Para criar uma barra de ferramentas transparente, use ambos **TBSTYLE_FLAT** e **TBSTYLE_TRANSPARENT** estilos. Barras de ferramentas transparentes recurso rastrear quente; ou seja, quando o ponteiro do mouse se move sobre um botão de acesso na barra de ferramentas, altera a aparência do botão. Barras de ferramentas criadas com apenas o **TBSTYLE_FLAT** estilo contém botões que não são transparentes.  
  
 Suporte à lista de imagem permite uma controle maior flexibilidade para imagens desabilitadas, hot imagens e comportamento padrão. Use [GetImageList](#getimagelist), [GetHotImageList](#gethotimagelist), e [GetDisabledImageList](#getdisabledimagelist) com a barra de ferramentas transparente para manipular a imagem de acordo com seu estado:  
  
 Para obter mais informações sobre como usar o `CToolBarCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [CToolBarCtrl usando](../../mfc/using-ctoolbarctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CToolBarCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="a-nameaddbitmapa--ctoolbarctrladdbitmap"></a><a name="addbitmap"></a>CToolBarCtrl::AddBitmap  
 Adiciona uma ou mais imagens de botão para a lista de imagens de botão armazenada no controle de barra de ferramentas.  
  
```  
int AddBitmap(
    int nNumButtons,  
    UINT nBitmapID);

 
int AddBitmap(
    int nNumButtons,  
    CBitmap* pBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNumButtons`  
 Número de imagens de botão no bitmap.  
  
 `nBitmapID`  
 Identificador de recurso do bitmap que contém a imagem de botão ou imagens para adicionar.  
  
 `pBitmap`  
 Ponteiro para o `CBitmap` objeto que contém a imagem de botão ou imagens para adicionar.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice baseado em zero da primeira imagem nova se for bem-sucedida; Caso contrário, – 1.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar a API do Windows [CreateMappedBitmap](http://msdn.microsoft.com/library/windows/desktop/bb787467) para mapear as cores antes de adicionar o bitmap na barra de ferramentas. Se você passar um ponteiro para um **CBitMap** do objeto, você deve garantir que o bitmap não será destruído até depois que a barra de ferramentas é destruída.  
  
##  <a name="a-nameaddbuttonsa--ctoolbarctrladdbuttons"></a><a name="addbuttons"></a>CToolBarCtrl::AddButtons  
 Adiciona um ou mais botões a um controle de barra de ferramentas.  
  
```  
BOOL AddButtons(
    int nNumButtons,  
    LPTBBUTTON lpButtons);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNumButtons`  
 Número de botões para adicionar.  
  
 `lpButtons`  
 Endereço de uma matriz de `TBBUTTON` estruturas que contém informações sobre os botões para adicionar. Deve haver o mesmo número de elementos na matriz como botões especificado por `nNumButtons`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 O `lpButtons` ponteiro aponta para uma matriz de `TBBUTTON` estruturas. Cada `TBBUTTON` estrutura associa o botão que está sendo adicionado com o estilo do botão, o estado de imagem e/ou cadeia de caracteres, ID de comando e dados definidos pelo usuário:  
  
 `typedef struct _TBBUTTON {`  
  
 `int iBitmap;// zero-based index of button image`  
  
 `int idCommand;  // command to be sent when button pressed`  
  
 `BYTE fsState;   // button state--see below`  
  
 `BYTE fsStyle;   // button style--see below`  
  
 `DWORD dwData;   // application-defined value`  
  
 `int iString;// zero-based index of button label string`  
  
 `} TBBUTTON;`  
  
 Os membros são os seguintes:  
  
 **iBitmap**  
 Índice baseado em zero da imagem do botão, -1 se nenhuma imagem desse botão.  
  
 **idCommand**  
 Identificador de comando associado ao botão. Esse identificador é enviado em uma **WM_COMMAND** mensagens quando o botão é selecionado. Se o **fsStyle** membro tem o `TBSTYLE_SEP` valor, esse membro deve ser zero.  
  
 **fsState**  
 Sinalizadores de estado do botão. Pode ser uma combinação dos valores listados abaixo:  
  
- `TBSTATE_CHECKED`O botão tem o **TBSTYLE_CHECKED** de estilo e está sendo pressionado.  
  
- `TBSTATE_ENABLED`O botão aceita entrada do usuário. Um botão que não tenha esse estado não aceita entrada do usuário e ficará indisponível.  
  
- `TBSTATE_HIDDEN`O botão não estiver visível e não pode receber entrada do usuário.  
  
- `TBSTATE_INDETERMINATE`O botão ficará indisponível.  
  
- `TBSTATE_PRESSED`O botão está sendo pressionado.  
  
- `TBSTATE_WRAP`Uma quebra de linha segue o botão. O botão também deve ter o `TBSTATE_ENABLED` estado.  
  
 **fsStyle**  
 Estilo de botão. Pode ser uma combinação dos valores listados abaixo:  
  
- `TBSTYLE_BUTTON`Cria um botão de ação padrão.  
  
- `TBSTYLE_CHECK`Cria um botão que alterna entre os estados pressionados e não pressionados cada vez que o usuário clica nele. O botão tem uma cor de plano de fundo diferente quando ele estiver no estado pressionado.  
  
- `TBSTYLE_CHECKGROUP`Cria um botão de seleção permanece pressionado até que o outro no grupo é pressionado.  
  
- `TBSTYLE_GROUP`Cria um botão que permanece pressionado até que o outro no grupo é pressionado.  
  
- `TBSTYLE_SEP`Cria um separador, fornecendo um pequeno intervalo entre grupos de botões. Um botão que possui este estilo não recebe entrada do usuário.  
  
 `dwData`  
 Dados definidos pelo usuário.  
  
 **iString**  
 Índice baseado em zero da cadeia de caracteres para usar como o botão do rótulo, -1 se não houver nenhuma cadeia de caracteres para esse botão.  
  
 A imagem e/ou a cadeia de caracteres cujo índice você fornecer deve anteriormente foram adicionado para o controle de barra de ferramentas lista usando [AddBitmap](#addbitmap), [AddString](#addstring), e/ou [AddStrings](#addstrings).  
  
##  <a name="a-nameaddstringa--ctoolbarctrladdstring"></a><a name="addstring"></a>CToolBarCtrl::AddString  
 Adiciona uma nova cadeia de caracteres passada como uma ID de recurso para a lista interna da barra de ferramentas de cadeias de caracteres.  
  
```  
int AddString(UINT nStringID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nStringID*  
 Identificador de recurso do recurso de cadeia de caracteres para adicionar à lista de cadeia de caracteres do controle da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da primeira sequência do novo adicionado se for bem-sucedida; Caso contrário,-1.  
  
##  <a name="a-nameaddstringsa--ctoolbarctrladdstrings"></a><a name="addstrings"></a>CToolBarCtrl::AddStrings  
 Adiciona uma nova cadeia de caracteres ou cadeias de caracteres para a lista de cadeias de caracteres disponíveis para um controle de barra de ferramentas.  
  
```  
int AddStrings(LPCTSTR lpszStrings);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszStrings*  
 Endereço de um buffer que contém um ou mais cadeias de terminação nula para adicionar à lista de cadeia de caracteres da barra de ferramentas. A última sequência de caracteres deve terminar com dois caracteres nulos.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da primeira sequência do novo adicionado se for bem-sucedida; Caso contrário,-1.  
  
### <a name="remarks"></a>Comentários  
 Cadeias de caracteres no buffer devem ser separadas por um caractere nulo. Certifique-se de que a última sequência de caracteres tem dois terminadores nulos. Para formatar uma cadeia de caracteres constante corretamente, você pode escrever-o como:  
  
 [!code-cpp[NVC_MFCControlLadenDialog&#72;](../../mfc/codesnippet/cpp/ctoolbarctrl-class_1.cpp)]  
  
 ou:  
  
 [!code-cpp[NVC_MFCControlLadenDialog&#73;](../../mfc/codesnippet/cpp/ctoolbarctrl-class_2.cpp)]  
  
 Você não deve passar um `CString` objeto para essa função, pois ele não é possível ter mais de um caractere null em um `CString`.  
  
##  <a name="a-nameautosizea--ctoolbarctrlautosize"></a><a name="autosize"></a>CToolBarCtrl::AutoSize  
 Redimensiona o controle de barra de ferramentas inteira.  
  
```  
void AutoSize();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar essa função quando altera o tamanho da janela pai ou quando altera o tamanho da barra de ferramentas (por exemplo, quando você define o tamanho do botão ou bitmap ou adicionar cadeias de caracteres).  
  
##  <a name="a-namechangebitmapa--ctoolbarctrlchangebitmap"></a><a name="changebitmap"></a>CToolBarCtrl::ChangeBitmap  
 Altera o bitmap de um botão no controle de barra de ferramentas atual.  
  
```  
BOOL ChangeBitmap(
    int idButton,   
    int iBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `idButton`|Identificador de comando do botão que receberá um novo bitmap.|  
|[in] `iBitmap`|Índice baseado em zero de uma imagem na lista de imagens do controle de barra de ferramentas atual.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se esse método for bem-sucedido, o sistema exibe a imagem especificada no botão especificado.  
  
 Esse método envia o [TB_CHANGEBITMAP](http://msdn.microsoft.com/library/windows/desktop/bb787301) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir altera o bitmap para a **salvar arquivo** botão no bitmap para o **sobre** botão.  
  
 [!code-cpp[NVC_MFC_CToolBarCtrl_s1 n º&1;](../../mfc/reference/codesnippet/cpp/ctoolbarctrl-class_3.cpp)]  
  
##  <a name="a-namecheckbuttona--ctoolbarctrlcheckbutton"></a><a name="checkbutton"></a>CToolBarCtrl::CheckButton  
 Marca ou desmarca um determinado botão em um controle de barra de ferramentas.  
  
```  
BOOL CheckButton(
    int nID,  
    BOOL bCheck = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador do botão para marcar ou desmarcar o comando.  
  
 *bVerificar*  
 **TRUE** para verificar se o botão **FALSE** removê-la.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Quando um botão é verificado, ele parece foram pressionadas. Se você quiser alterar mais de um estado de botão, considere a possibilidade de chamar [SetState](#setstate) em vez disso.  
  
##  <a name="a-namecommandtoindexa--ctoolbarctrlcommandtoindex"></a><a name="commandtoindex"></a>CToolBarCtrl::CommandToIndex  
 Retorna o índice baseado em zero do botão associado ao identificador de comando especificado.  
  
```  
UINT CommandToIndex(UINT nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 ID do comando cujo botão índice que você deseja localizar.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do botão associado com a ID de comando.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecreatea--ctoolbarctrlcreate"></a><a name="create"></a>CToolBarCtrl::Create  
 Cria um controle de barra de ferramentas e a anexa a um `CToolBarCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle de barra de ferramentas. Barras de ferramentas devem sempre ter a **WS_CHILD** estilo. Além disso, você pode especificar qualquer combinação de estilos de barra de ferramentas e janela conforme descrito em **comentários**.  
  
 `rect`  
 Opcionalmente, especifica o tamanho e a posição do controle da barra de ferramentas. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura.  
  
 `pParentWnd`  
 Especifica a janela pai do controle de barra de ferramentas. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a identificação. do controle de barra de ferramentas  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CToolBarCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida, chame **criar**, que cria o controle de barra de ferramentas e anexa-o para o `CToolBarCtrl` objeto. Aplica os seguintes estilos de janela a um controle de barra de ferramentas.  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** geral  
  
- **WS_DISABLED** raramente  
  
 Consulte [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma descrição dos estilos de janela.  
  
 Opcionalmente, aplique uma combinação de [estilos de controle comum](http://msdn.microsoft.com/library/windows/desktop/bb775498), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Aplica uma combinação de estilos de barra de ferramentas para o controle ou os botões em si. Os estilos são descritos no tópico [controle de barra de ferramentas e os estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb760439) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para usar estilos de barra de ferramentas estendido, chame [SetExtendedStyle](#setextendedstyle) depois de você chamar **criar**. Para criar uma barra de ferramentas com estilos de janela estendidos, chame [CToolBarCtrl::CreateEx](#createex) em vez de **criar**.  
  
 O controle de barra de ferramentas define automaticamente o tamanho e a posição da janela de ferramentas. A altura é baseada na altura dos botões na barra de ferramentas. A largura é o mesmo que a largura da área de cliente da janela pai. O `CCS_TOP` e `CCS_BOTTOM` estilos determinam se a barra de ferramentas é posicionada ao longo da parte superior ou inferior da área do cliente. Por padrão, uma barra de ferramentas tem o `CCS_TOP` estilo.  
  
##  <a name="a-namecreateexa--ctoolbarctrlcreateex"></a><a name="createex"></a>CToolBarCtrl::CreateEx  
 Cria um controle (uma janela filho) e o associa a `CToolBarCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwStyle`  
 Especifica o estilo do controle de barra de ferramentas. Barras de ferramentas devem sempre ter a **WS_CHILD** estilo. Além disso, você pode especificar qualquer combinação de estilos de barra de ferramentas e janela conforme descrito na **comentários** seção [criar](#create).  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido Windows **WS_EX_**. **CreateEx** cria o controle com os estilos estendidos do Windows especificados pela `dwExStyle`. Conjunto específico de um controle usando estilos estendidos [SetExtendedStyle](#setextendedstyle). Por exemplo, use `CreateEx` para definir esses estilos como **WS_EX_CONTEXTHELP**, mas usar `SetExtendedStyle` para definir esses estilos como **TBSTYLE_EX_DRAWDDARROWS**. Para obter mais informações, consulte os estilos descritos em [estilos estendidos de barra de ferramentas](http://msdn.microsoft.com/library/windows/desktop/bb760430) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namectoolbarctrla--ctoolbarctrlctoolbarctrl"></a><a name="ctoolbarctrl"></a>CToolBarCtrl::CToolBarCtrl  
 Constrói um objeto `CToolBarCtrl`.  
  
```  
CToolBarCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [criar](#create) para poder utilizar a barra de ferramentas.  
  
##  <a name="a-namecustomizea--ctoolbarctrlcustomize"></a><a name="customize"></a>CToolBarCtrl::Customize  
 Exibe a caixa de diálogo Personalizar barra de ferramentas.  
  
```  
void Customize();
```  
  
### <a name="remarks"></a>Comentários  
 Essa caixa de diálogo permite que o usuário personalize a barra de ferramentas, adicionando e excluindo botões. Para oferecer suporte a personalização, janela de pai da sua barra de ferramentas deve tratar as mensagens de notificação de personalização conforme descrito em [manipulando notificações de personalização](../../mfc/handling-customization-notifications.md). A barra de ferramentas também deve ter sido criada com o `CCS_ADJUSTABLE` de estilo, conforme descrito em [CToolBarCtrl::Create](#create).  
  
 Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q241850: PRB: chamada a CToolBarCtrl::Customize não mantém visível a caixa de diálogo Personalizar.  
  
##  <a name="a-namedeletebuttona--ctoolbarctrldeletebutton"></a><a name="deletebutton"></a>CToolBarCtrl::DeleteButton  
 Exclui um botão do controle da barra de ferramentas.  
  
```  
BOOL DeleteButton(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice baseado em zero do botão Excluir.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenablebuttona--ctoolbarctrlenablebutton"></a><a name="enablebutton"></a>CToolBarCtrl::EnableButton  
 Habilita ou desabilita o botão especificado em um controle de barra de ferramentas.  
  
```  
BOOL EnableButton(
    int nID,  
    BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador do botão para ativar ou desativar o comando.  
  
 `bEnable`  
 **TRUE** para habilitar o botão; **FALSE** para desabilitar o botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Quando um botão estiver habilitado, pode ser pressionado e verificada. Se você quiser alterar mais de um estado de botão, considere a possibilidade de chamar [SetState](#setstate) em vez disso.  
  
##  <a name="a-namegetanchorhighlighta--ctoolbarctrlgetanchorhighlight"></a><a name="getanchorhighlight"></a>CToolBarCtrl::GetAnchorHighlight  
 Recupera o realce de âncora definindo para uma barra de ferramentas.  
  
```  
BOOL GetAnchorHighlight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for diferente de zero, realce de âncora está habilitado. Se for zero, realce de âncora está desabilitado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETANCHORHIGHLIGHT](http://msdn.microsoft.com/library/windows/desktop/bb787313), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetbitmapa--ctoolbarctrlgetbitmap"></a><a name="getbitmap"></a>CToolBarCtrl::GetBitmap  
 Recupera o índice do bitmap associado a um botão na barra de ferramentas.  
  
```  
int GetBitmap(int nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador de comando do botão cujo índice de bitmap deve ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o índice de bitmap se for bem-sucedido, ou zero caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Implementa a funcionalidade de [TB_GETBITMAP](http://msdn.microsoft.com/library/windows/desktop/bb787315) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetbitmapflagsa--ctoolbarctrlgetbitmapflags"></a><a name="getbitmapflags"></a>CToolBarCtrl::GetBitmapFlags  
 Recupera os sinalizadores de bitmap na barra de ferramentas.  
  
```  
UINT GetBitmapFlags() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **UINT** que tem o **TBBF_LARGE** sinalizador definido se a exibição pode oferecer suporte a bitmaps grandes da barra de ferramentas, caso contrário, desmarque.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamá-lo depois de criar a barra de ferramentas, mas antes de adicionar bitmaps na barra de ferramentas. O valor de retorno indica se a exibição suporta bitmaps grandes ou não. Se a exibição dá suporte a bitmaps grandes e se você quiser usá-los, chame [SetBitmapSize](#setbitmapsize) e [SetButtonSize](#setbuttonsize) antes de adicionar o bitmap grande usando [AddBitmap](#addbitmap).  
  
##  <a name="a-namegetbuttona--ctoolbarctrlgetbutton"></a><a name="getbutton"></a>CToolBarCtrl::GetButton  
 Recupera informações sobre o botão especificado em um controle de barra de ferramentas.  
  
```  
BOOL GetButton(
    int nIndex,  
    LPTBBUTTON lpButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice baseado em zero do botão para o qual recuperar informações.  
  
 `lpButton`  
 Endereço do `TBBUTTON` estrutura que deve receber uma cópia das informações de botão. Consulte [CToolBarCtrl::AddButtons](#addbuttons) para obter informações sobre o `TBBUTTON` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
##  <a name="a-namegetbuttoncounta--ctoolbarctrlgetbuttoncount"></a><a name="getbuttoncount"></a>CToolBarCtrl::GetButtonCount  
 Recupera uma contagem dos botões no momento no controle de barra de ferramentas.  
  
```  
int GetButtonCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem dos botões.  
  
##  <a name="a-namegetbuttoninfoa--ctoolbarctrlgetbuttoninfo"></a><a name="getbuttoninfo"></a>CToolBarCtrl::GetButtonInfo  
 Recupera as informações para um botão na barra de ferramentas.  
  
```  
int GetButtonInfo(
    int nID,  
    TBBUTTONINFO* ptbbi) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 O identificador do botão.  
  
 `ptbbi`  
 Um ponteiro para um [TBBUTTONINFO](http://msdn.microsoft.com/library/windows/desktop/bb760478) estrutura que recebe as informações do botão.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do botão, se for bem-sucedido; Caso contrário, retornará-1.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETBUTTONINFO](http://msdn.microsoft.com/library/windows/desktop/bb787321), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetbuttonsizea--ctoolbarctrlgetbuttonsize"></a><a name="getbuttonsize"></a>CToolBarCtrl::GetButtonSize  
 Obtém o tamanho de um botão da barra de ferramentas.  
  
```  
DWORD GetButtonSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` valor que contém os valores de largura e altura no LOWORD e HIWORD, respectivamente.  
  
##  <a name="a-namegetbuttontexta--ctoolbarctrlgetbuttontext"></a><a name="getbuttontext"></a>CToolBarCtrl::GetButtonText  
 Recupera o texto de exibição de um botão especificado no controle de barra de ferramentas atual.  
  
```  
CString GetButtonText(int idButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `idButton`|O identificador do botão cujo texto é recuperado.|  
  
### <a name="return-value"></a>Valor de retorno  
 A [CString](../../atl-mfc-shared/using-cstring.md) que contém o texto de exibição do botão especificado.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TB_GETBUTTONTEXT](http://msdn.microsoft.com/library/windows/desktop/bb787325) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="a-namegetcolorschemea--ctoolbarctrlgetcolorscheme"></a><a name="getcolorscheme"></a>CToolBarCtrl::GetColorScheme  
 Recupera o esquema de cores do controle da barra de ferramentas atual.  
  
```  
BOOL GetColorScheme(COLORSCHEME* lpColorScheme) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] `lpColorScheme`|Ponteiro para uma [COLORSCHEME](http://msdn.microsoft.com/library/windows/desktop/bb775502) estrutura que recebe as informações de esquema de cores. Quando este método retorna, a estrutura descreve as cores de realce e sombra do controle da barra de ferramentas.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TB_GETCOLORSCHEME](http://msdn.microsoft.com/library/windows/desktop/bb787327) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetdisabledimagelista--ctoolbarctrlgetdisabledimagelist"></a><a name="getdisabledimagelist"></a>CToolBarCtrl::GetDisabledImageList  
 Recupera a lista de imagens que usa um controle de barra de ferramentas para botões de exibição desabilitada.  
  
```  
CImageList* GetDisabledImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto, ou **nulo** se nenhuma lista de imagens desabilitado está definida.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETDISABLEDIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb787329), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. A implementação do MFC de `GetDisabledImageList` usa um `CImageList` objeto que contém o botão do controle da barra de ferramentas de imagens, em vez de um identificador para uma lista de imagens.  
  
##  <a name="a-namegetdroptargeta--ctoolbarctrlgetdroptarget"></a><a name="getdroptarget"></a>CToolBarCtrl::GetDropTarget  
 Recupera o [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) interface para um controle de barra de ferramentas.  
  
```  
HRESULT GetDropTarget(IDropTarget** ppDropTarget) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppDropTarget`  
 Um ponteiro para um [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) ponteiro de interface. Se ocorrer um erro, uma **nulo** ponteiro é colocado nesse endereço.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `HRESULT` valor indicando êxito ou falha da operação.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787343), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetextendedstylea--ctoolbarctrlgetextendedstyle"></a><a name="getextendedstyle"></a>CToolBarCtrl::GetExtendedStyle  
 Recupera os estilos estendidos para um controle de barra de ferramentas.  
  
```  
DWORD GetExtendedStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` que representa os estilos estendidos atualmente em uso para o controle de barra de ferramentas. Para obter uma lista de estilos, consulte [estilos estendidos de barra de ferramentas](http://msdn.microsoft.com/library/windows/desktop/bb760430), além de [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETEXTENDEDSTYLE](http://msdn.microsoft.com/library/windows/desktop/bb787331), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegethotimagelista--ctoolbarctrlgethotimagelist"></a><a name="gethotimagelist"></a>CToolBarCtrl::GetHotImageList  
 Recupera a lista de imagens que usa um controle de barra de ferramentas para exibir os botões "hot". Um ponto crítico é realçado quando o ponteiro do mouse está acima dela.  
  
```  
CImageList* GetHotImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto, ou **nulo** se nenhuma lista de imagens desabilitado está definida.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETHOTIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb787334), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Um ponto crítico é realçado quando o ponteiro do mouse está acima dela.  
  
##  <a name="a-namegethotitema--ctoolbarctrlgethotitem"></a><a name="gethotitem"></a>CToolBarCtrl::GetHotItem  
 Recupera o índice do item ativo na barra de ferramentas.  
  
```  
int GetHotItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do item ativo na barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETHOTITEM](http://msdn.microsoft.com/library/windows/desktop/bb787336), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetimagelista--ctoolbarctrlgetimagelist"></a><a name="getimagelist"></a>CToolBarCtrl::GetImageList  
 Recupera a lista de imagens que usa um controle de barra de ferramentas para exibir os botões em seu estado padrão.  
  
```  
CImageList* GetImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto, ou **nulo** se nenhuma lista de imagens é definida.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb787337), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetinsertmarka--ctoolbarctrlgetinsertmark"></a><a name="getinsertmark"></a>CToolBarCtrl::GetInsertMark  
 Recupera a marca de inserção atual da barra de ferramentas.  
  
```  
void GetInsertMark(TBINSERTMARK* ptbim) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptbim`  
 Um ponteiro para um [TBINSERTMARK](http://msdn.microsoft.com/library/windows/desktop/bb760480) estrutura que recebe a marca de inserção.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETINSERTMARK](http://msdn.microsoft.com/library/windows/desktop/bb787338), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetinsertmarkcolora--ctoolbarctrlgetinsertmarkcolor"></a><a name="getinsertmarkcolor"></a>CToolBarCtrl::GetInsertMarkColor  
 Recupera a cor usada para desenhar a marca de inserção para a barra de ferramentas.  
  
```  
COLORREF GetInsertMarkColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **COLORREF** valor que contém a cor atual da marca de inserção.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETINSERTMARKCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb787339), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetitemrecta--ctoolbarctrlgetitemrect"></a><a name="getitemrect"></a>CToolBarCtrl::GetItemRect  
 Recupera o retângulo delimitador de um botão em um controle de barra de ferramentas.  
  
```  
BOOL GetItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice baseado em zero do botão para o qual recuperar informações.  
  
 `lpRect`  
 Endereço de uma [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que recebe as coordenadas do retângulo delimitador.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função não recupera o retângulo delimitador para os botões cujo estado é definido como `TBSTATE_HIDDEN`.  
  
##  <a name="a-namegetmaxsizea--ctoolbarctrlgetmaxsize"></a><a name="getmaxsize"></a>CToolBarCtrl::GetMaxSize  
 Recupera o tamanho total de todos os botões visíveis e os separadores na barra de ferramentas.  
  
```  
BOOL GetMaxSize(LPSIZE pSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSize`  
 Um ponteiro para um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que recebe o tamanho dos itens.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETMAXSIZE](http://msdn.microsoft.com/library/windows/desktop/bb787341), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetmaxtextrowsa--ctoolbarctrlgetmaxtextrows"></a><a name="getmaxtextrows"></a>CToolBarCtrl::GetMaxTextRows  
 Recupera o número máximo de linhas de texto exibido no botão da barra de ferramentas.  
  
```  
int GetMaxTextRows() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número máximo de linhas de texto exibido no botão da barra de ferramentas.  
  
##  <a name="a-namegetmetricsa--ctoolbarctrlgetmetrics"></a><a name="getmetrics"></a>CToolBarCtrl::GetMetrics  
 Recupera as métricas do `CToolBarCtrl` objeto.  
  
```  
void GetMetrics(LPTBMETRICS ptbm) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptbm`  
 Um ponteiro para o [TBMETRICS](http://msdn.microsoft.com/library/windows/desktop/bb760482) estrutura do `CToolBarCtrl` objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [TB_GETMETRICS](http://msdn.microsoft.com/library/windows/desktop/bb787342) mensagem, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetpaddinga--ctoolbarctrlgetpadding"></a><a name="getpadding"></a>CToolBarCtrl::GetPadding  
 Recupera o preenchimento horizontal e vertical do controle da barra de ferramentas atual.  
  
```  
BOOL GetPadding(
    int* pnHorzPadding,   
    int* pnVertPadding) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] `pnHorzPadding`|Um inteiro que recebe o preenchimento horizontal do controle da barra de ferramentas, em pixels.|  
|[out] `pnVertPadding`|Um inteiro que recebe o preenchimento vertical do controle da barra de ferramentas, em pixels.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TB_GETPADDING](http://msdn.microsoft.com/library/windows/desktop/bb787344) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetpressedimagelista--ctoolbarctrlgetpressedimagelist"></a><a name="getpressedimagelist"></a>CToolBarCtrl::GetPressedImageList  
 Recupera a lista de imagens que o controle de barra de ferramentas atual usa para representar botões no estado pressionado.  
  
```  
CImageList* GetPressedImageList();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma [CImageList](../../mfc/reference/cimagelist-class.md) que contém a lista de imagens para o controle atual, ou `NULL` se nenhuma dessas listas de imagem é definida.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TB_GETPRESSEDIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb787345) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetrecta--ctoolbarctrlgetrect"></a><a name="getrect"></a>CToolBarCtrl::GetRect  
 Recupera o retângulo delimitador para um botão da barra de ferramentas especificada.  
  
```  
BOOL GetRect(
    int nID,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 O identificador do botão.  
  
 `lpRect`  
 Um ponteiro para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura para receber as informações de retângulo delimitador.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se bem-sucedido; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETRECT](http://msdn.microsoft.com/library/windows/desktop/bb787346), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetrowsa--ctoolbarctrlgetrows"></a><a name="getrows"></a>CToolBarCtrl::GetRows  
 Recupera o número de linhas atualmente exibidas pelo controle de barra de ferramentas de botões.  
  
```  
int GetRows() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Número de linhas de botões atualmente exibidos na barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Observe que o número de linhas sempre será um menos que a barra de ferramentas foi criada com o `TBSTYLE_WRAPABLE` estilo.  
  
##  <a name="a-namegetstatea--ctoolbarctrlgetstate"></a><a name="getstate"></a>CToolBarCtrl::GetState  
 Recupera informações sobre o estado do botão especificado em um controle de barra de ferramentas, como se ele é habilitado, pressionado ou marcado.  
  
```  
int GetState(int nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador de comando do botão para o qual recuperar informações.  
  
### <a name="return-value"></a>Valor de retorno  
 As informações de estado do botão se for bem-sucedido ou -1 caso contrário. As informações de estado do botão podem ser uma combinação dos valores listados na [CToolBarCtrl::AddButtons](#addbuttons).  
  
### <a name="remarks"></a>Comentários  
 Essa função é especialmente útil se você desejar recuperar mais de um dos Estados do botão. Para recuperar apenas um estado, use uma das seguintes funções de membro: [IsButtonEnabled](#isbuttonenabled), [IsButtonChecked](#isbuttonchecked), [IsButtonPressed](#isbuttonpressed), [IsButtonHidden](#isbuttonhidden), ou [IsButtonIndeterminate](#isbuttonindeterminate). No entanto, o `GetState` função de membro é a única maneira de detectar o `TBSTATE_WRAP` estado de botão.  
  
##  <a name="a-namegetstringa--ctoolbarctrlgetstring"></a><a name="getstring"></a>CToolBarCtrl::GetString  
 Recupera uma cadeia de caracteres de barra de ferramentas.  
  
```  
int GetString(
    int nString,  
    LPTSTR lpstrString,  
    int cchMaxLen) const;  
  
int GetString(
    int nString,  
    CString& str) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nString*  
 Índice da cadeia de caracteres.  
  
 *lpstrString*  
 Ponteiro para um buffer usado para retornar a cadeia de caracteres.  
  
 *cchMaxLen*  
 Tamanho do buffer em bytes.  
  
 `str`  
 A cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da cadeia de caracteres se for bem-sucedido, -1 se não.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_GETSTRING](http://msdn.microsoft.com/library/windows/desktop/bb787349), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetstylea--ctoolbarctrlgetstyle"></a><a name="getstyle"></a>CToolBarCtrl::GetStyle  
 Obtém os estilos atualmente aplicados a um controle de barra de ferramentas.  
  
```  
DWORD GetStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A `DWORD` que contém uma combinação de [estilos de controle de barra de ferramentas](http://msdn.microsoft.com/library/windows/desktop/bb760439), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegettooltipsa--ctoolbarctrlgettooltips"></a><a name="gettooltips"></a>CToolBarCtrl::GetToolTips  
 Recupera a alça de controle de dica de ferramenta, se houver, associado com o controle de barra de ferramentas.  
  
```  
CToolTipCtrl* GetToolTips() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) objeto associado a essa barra de ferramentas ou **nulo** se a barra de ferramentas não tem nenhum controle de dica de ferramenta associado.  
  
### <a name="remarks"></a>Comentários  
 Como o controle de barra de ferramentas normalmente cria e mantém seu próprio controle de dica de ferramenta, a maioria dos programas não precisa chamar essa função.  
  
##  <a name="a-namehittesta--ctoolbarctrlhittest"></a><a name="hittest"></a>CToolBarCtrl::HitTest  
 Determina onde se encontra um ponto em um controle de barra de ferramentas.  
  
```  
int HitTest(LPPOINT ppt) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppt`  
 Um ponteiro para um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) estrutura que contém a coordenada x do teste de clique no **x** membro e a coordenada y do impacto de teste no **y** membro. As coordenadas são em relação à área do cliente da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor inteiro que indica o local de um ponto em uma barra de ferramentas. Se o valor for zero ou um valor positivo, esse valor de retorno é o índice baseado em zero do item nonseparator em que se encontra o ponto.  
  
 Se o valor de retorno for negativo, o ponto não residem dentro de um botão. O valor absoluto do valor de retorno é o índice de um item de separador ou o item nonseparator mais próximo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_HITTEST](http://msdn.microsoft.com/library/windows/desktop/bb787360), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namehidebuttona--ctoolbarctrlhidebutton"></a><a name="hidebutton"></a>CToolBarCtrl::HideButton  
 Oculta ou mostra o botão especificado em um controle de barra de ferramentas.  
  
```  
BOOL HideButton(
    int nID,  
    BOOL bHide = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador do botão para ocultar ou mostrar o comando.  
  
 `bHide`  
 **TRUE** para ocultar o botão **FALSE** para mostrá-la.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser alterar mais de um estado de botão, considere a possibilidade de chamar [SetState](#setstate) em vez disso.  
  
##  <a name="a-nameindeterminatea--ctoolbarctrlindeterminate"></a><a name="indeterminate"></a>CToolBarCtrl::Indeterminate  
 Define ou limpa o estado indeterminado do botão especificado em um controle de barra de ferramentas.  
  
```  
BOOL Indeterminate(
    int nID,  
    BOOL bIndeterminate = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador de comando do botão cujo estado indeterminado deve ser definido ou limpo.  
  
 *bIndeterminate*  
 **TRUE** para definir o estado indeterminado para o botão especificado, **FALSE** removê-la.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Indeterminada botões são exibidos cinza, como a forma o botão negrito na barra de ferramentas de um processador de texto aparece quando o texto selecionado contém caracteres em negrito e normais. Se você quiser alterar mais de um estado de botão, considere a possibilidade de chamar [SetState](#setstate) em vez disso.  
  
##  <a name="a-nameinsertbuttona--ctoolbarctrlinsertbutton"></a><a name="insertbutton"></a>CToolBarCtrl::InsertButton  
 Insere um botão em um controle de barra de ferramentas.  
  
```  
BOOL InsertButton(
    int nIndex,  
    LPTBBUTTON lpButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice baseado em zero de um botão. Essa função insere o novo botão à esquerda desse botão.  
  
 `lpButton`  
 Endereço de uma `TBBUTTON` estrutura que contém informações sobre o botão Inserir. Consulte [CToolBarCtrl::AddButtons](#addbuttons) para obter uma descrição de `TBBUTTON` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 A imagem e/ou a cadeia de caracteres cujo índice você fornecer deve anteriormente foram adicionado para o controle de barra de ferramentas lista usando [AddBitmap](#addbitmap), [AddString](#addstring), e/ou [AddStrings](#addstrings).  
  
##  <a name="a-nameinsertmarkhittesta--ctoolbarctrlinsertmarkhittest"></a><a name="insertmarkhittest"></a>CToolBarCtrl::InsertMarkHitTest  
 Recupera as informações de marca de inserção de um ponto em uma barra de ferramentas.  
  
```  
BOOL InsertMarkHitTest(
    LPPOINT ppt,  
    LPTBINSERTMARK ptbim) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppt`  
 Um ponteiro para um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) coordenadas de estrutura que contém o teste de clique, relativo a área do cliente da barra de ferramentas.  
  
 `ptbim`  
 Um ponteiro para um [TBINSERTMARK](http://msdn.microsoft.com/library/windows/desktop/bb760480) estrutura que recebe as informações de marca de inserção.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_INSERTMARKHITTEST](http://msdn.microsoft.com/library/windows/desktop/bb787367), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameisbuttoncheckeda--ctoolbarctrlisbuttonchecked"></a><a name="isbuttonchecked"></a>CToolBarCtrl::IsButtonChecked  
 Determina se o botão especificado em um controle de barra de ferramentas é verificado.  
  
```  
BOOL IsButtonChecked(int nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador de comando do botão na barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão está marcado. Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Considere a possibilidade de chamar [GetState](#getstate) se você desejar recuperar mais de um estado de botão.  
  
##  <a name="a-nameisbuttonenableda--ctoolbarctrlisbuttonenabled"></a><a name="isbuttonenabled"></a>CToolBarCtrl::IsButtonEnabled  
 Determina se o botão especificado em um controle de barra de ferramentas está habilitado.  
  
```  
BOOL IsButtonEnabled(int nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador de comando do botão na barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão estiver habilitado; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Considere a possibilidade de chamar [GetState](#getstate) se você desejar recuperar mais de um estado de botão.  
  
##  <a name="a-nameisbuttonhiddena--ctoolbarctrlisbuttonhidden"></a><a name="isbuttonhidden"></a>CToolBarCtrl::IsButtonHidden  
 Determina se o botão especificado em um controle de barra de ferramentas está oculta.  
  
```  
BOOL IsButtonHidden(int nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador de comando do botão na barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão estiver oculto; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Considere a possibilidade de chamar [GetState](#getstate) se você desejar recuperar mais de um estado de botão.  
  
##  <a name="a-nameisbuttonhighlighteda--ctoolbarctrlisbuttonhighlighted"></a><a name="isbuttonhighlighted"></a>CToolBarCtrl::IsButtonHighlighted  
 Verifica o estado de realce de um botão da barra de ferramentas.  
  
```  
BOOL IsButtonHighlighted(int nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 A ID de comando para o botão da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro positivo se o botão estiver realçado, 0 se o botão não é realçado, ou -1 se um erro ocorrerá.  
  
##  <a name="a-nameisbuttonindeterminatea--ctoolbarctrlisbuttonindeterminate"></a><a name="isbuttonindeterminate"></a>CToolBarCtrl::IsButtonIndeterminate  
 Determina se o botão especificado em um controle de barra de ferramentas é indeterminado.  
  
```  
BOOL IsButtonIndeterminate(int nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 Identificador de comando do botão na barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Número inteiro positivo se o botão está indeterminado, zero se o botão não é indeterminado, ou -1 se um erro ocorre.  
  
### <a name="remarks"></a>Comentários  
 Botões indeterminados serão exibidos esmaecidos, como a forma o botão negrito na barra de ferramentas de um processador de texto é exibido quando o texto selecionado contém caracteres em negrito e normais. Considere a possibilidade de chamar [GetState](#getstate) se você desejar recuperar mais de um estado de botão.  
  
##  <a name="a-nameisbuttonpresseda--ctoolbarctrlisbuttonpressed"></a><a name="isbuttonpressed"></a>CToolBarCtrl::IsButtonPressed  
 Determina se o botão especificado em um controle de barra de ferramentas é pressionado.  
  
```  
BOOL IsButtonPressed(int nID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador de comando do botão na barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão é pressionado, caso contrário zero.  
  
### <a name="remarks"></a>Comentários  
 Considere a possibilidade de chamar [GetState](#getstate) se você desejar recuperar mais de um estado de botão.  
  
##  <a name="a-nameloadimagesa--ctoolbarctrlloadimages"></a><a name="loadimages"></a>CToolBarCtrl::LoadImages  
 Carrega bitmaps na lista de imagens de um controle barra de ferramentas.  
  
```  
void LoadImages(
    int iBitmapID,  
    HINSTANCE hinst);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iBitmapID*  
 ID de um bitmap que contém as imagens a serem carregadas. Para especificar seu próprio recurso de bitmap, defina este parâmetro para a identificação de um recurso de bitmap e defina `hInst` para **nulo**. O recurso de bitmap será adicionado à lista de imagens como uma única imagem. Você pode adicionar bitmaps padrão definidos pelo sistema, definindo *hinst* para **HINST_COMMCTRL** e definir esse parâmetro como um dos seguintes IDs:  
  
|ID de bitmap|Descrição|  
|---------------|-----------------|  
|IDB_HIST_LARGE_COLOR|Explorer bitmaps em tamanho grande|  
|IDB_HIST_SMALL_COLOR|Explorer bitmaps de tamanho pequeno|  
|IDB_STD_LARGE_COLOR|Bitmaps padrão de tamanho grande|  
|IDB_STD_SMALL_COLOR|Bitmaps padrão de tamanho pequeno|  
|IDB_VIEW_LARGE_COLOR|Exibição de bitmaps de tamanho grande|  
|IDB_VIEW_SMALL_COLOR|Exibição de bitmaps de tamanho pequeno|  
  
 *HINST*  
 Identificador de instância do programa para o aplicativo de chamada. Esse parâmetro pode ser **HINST_COMMCTRL** para carregar uma lista de imagem padrão.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_LOADIMAGES](http://msdn.microsoft.com/library/windows/desktop/bb787381), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namemapacceleratora--ctoolbarctrlmapaccelerator"></a><a name="mapaccelerator"></a>CToolBarCtrl::MapAccelerator  
 Um caractere de aceleração é mapeado para um botão da barra de ferramentas.  
  
```  
BOOL MapAccelerator(
    TCHAR chAccel,  
    UINT* pIDBtn);
```  
  
### <a name="parameters"></a>Parâmetros  
 `chAccel`  
 Caractere de acelerador a ser mapeado. Esse caractere é o mesmo caractere sublinhado no texto do botão.  
  
 *pIDBtn*  
 Um ponteiro para um **UINT** que recebe o identificador de comando do botão que corresponde ao accelerator especificado em `chAccel`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_MAPACCELERATOR](http://msdn.microsoft.com/library/windows/desktop/bb787383), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namemarkbuttona--ctoolbarctrlmarkbutton"></a><a name="markbutton"></a>CToolBarCtrl::MarkButton  
 Define o estado de realce de um determinado botão em um controle de barra de ferramentas.  
  
```  
BOOL MarkButton(
    int nID,  
    BOOL fHighlight = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 O identificador do botão.  
  
 `fHighlight`  
 Especifica o estado de realce a ser definido. Por padrão, **TRUE**. Se definido como **FALSE**, o botão está definido para seu estado padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_MARKBUTTON](http://msdn.microsoft.com/library/windows/desktop/bb787385), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namemovebuttona--ctoolbarctrlmovebutton"></a><a name="movebutton"></a>CToolBarCtrl::MoveButton  
 Move um botão de um índice para outro.  
  
```  
BOOL MoveButton(
    UINT nOldPos,  
    UINT nNewPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nOldPos*  
 O índice baseado em zero do botão a ser movido.  
  
 *nNewPos*  
 O índice baseado em zero do destino do botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_MOVEBUTTON](http://msdn.microsoft.com/library/windows/desktop/bb787387), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namepressbuttona--ctoolbarctrlpressbutton"></a><a name="pressbutton"></a>CToolBarCtrl::PressButton  
 Pressiona ou libera o botão especificado em um controle de barra de ferramentas.  
  
```  
BOOL PressButton(int nID, BOOL bPress = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 Identificador do botão pressiona ou libera o comando.  
  
 [in] `bPress`  
 `true`Pressione o botão especificado; `false` para liberar o botão especificado. O valor padrão é `true`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método for bem-sucedido; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser alterar mais de um estado de botão, considere a possibilidade de chamar [SetState](#setstate) em vez disso.  
  
 Esse método envia o [TB_PRESSBUTTON](http://msdn.microsoft.com/library/windows/desktop/bb787389) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namereplacebitmapa--ctoolbarctrlreplacebitmap"></a><a name="replacebitmap"></a>CToolBarCtrl::ReplaceBitmap  
 Substitui o bitmap existente no controle de barra de ferramentas atual com um novo bitmap.  
  
```  
BOOL ReplaceBitmap(LPTBREPLACEBITMAP pReplaceBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `pReplaceBitmap`|Ponteiro para uma [TBREPLACEBITMAP](http://msdn.microsoft.com/library/windows/desktop/bb760484) estrutura que descreve o bitmap a ser substituído e o novo bitmap.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TB_REPLACEBITMAP](http://msdn.microsoft.com/library/windows/desktop/bb787391) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir substitui o bitmap de barra de ferramentas padrão com um bitmap diferente.  
  
 [!code-cpp[NVC_MFC_CToolBarCtrl_s1 n º&2;](../../mfc/reference/codesnippet/cpp/ctoolbarctrl-class_4.cpp)]  
  
##  <a name="a-namerestorestatea--ctoolbarctrlrestorestate"></a><a name="restorestate"></a>CToolBarCtrl::RestoreState  
 Restaura o estado do controle da barra de ferramentas do local do registro especificado pelos parâmetros.  
  
```  
void RestoreState(
    HKEY hKeyRoot,  
    LPCTSTR lpszSubKey,  
    LPCTSTR lpszValueName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hKeyRoot`  
 Identifica uma chave aberta no momento no registro ou qualquer um dos seguintes valores identificadores reservados predefinidos:  
  
- **HKEY_CLASSES_ROOT**  
  
- **HKEY_CURRENT_USER**  
  
- **HKEY_LOCAL_MACHINE**  
  
- **HKEY_USERS**  
  
 `lpszSubKey`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome da subchave ao qual um valor está associado. Esse parâmetro pode ser null ou um ponteiro para uma cadeia de caracteres vazia. Se o parâmetro for **nulo**, o valor será adicionado à chave identificado pelo `hKeyRoot` parâmetro.  
  
 `lpszValueName`  
 Aponta para uma cadeia de caracteres contendo o nome do valor a ser recuperado. Se um valor com este nome já não estiver presente na chave, a função adiciona à chave.  
  
##  <a name="a-namesavestatea--ctoolbarctrlsavestate"></a><a name="savestate"></a>CToolBarCtrl::SaveState  
 Salva o estado do controle da barra de ferramentas no local do registro especificado pelos parâmetros.  
  
```  
void SaveState(
    HKEY hKeyRoot,  
    LPCTSTR lpszSubKey,  
    LPCTSTR lpszValueName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hKeyRoot`  
 Identifica uma chave aberta no momento no registro ou qualquer um dos seguintes valores identificadores reservados predefinidos:  
  
- **HKEY_CLASSES_ROOT**  
  
- **HKEY_CURRENT_USER**  
  
- **HKEY_LOCAL_MACHINE**  
  
- **HKEY_USERS**  
  
 `lpszSubKey`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome da subchave ao qual um valor está associado. Esse parâmetro pode ser null ou um ponteiro para uma cadeia de caracteres vazia. Se o parâmetro for **nulo**, o valor será adicionado à chave identificado pelo `hKeyRoot` parâmetro.  
  
 `lpszValueName`  
 Aponta para uma cadeia de caracteres que contém o nome do valor a ser definido. Se um valor com este nome já não estiver presente na chave, a função adiciona à chave.  
  
##  <a name="a-namesetanchorhighlighta--ctoolbarctrlsetanchorhighlight"></a><a name="setanchorhighlight"></a>CToolBarCtrl::SetAnchorHighlight  
 Define o realce de âncora definindo para uma barra de ferramentas.  
  
```  
BOOL SetAnchorHighlight(BOOL fAnchor = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `fAnchor`  
 Especifica se o realce de âncora está habilitado ou desabilitado. Se esse valor for diferente de zero, o realce de âncora será habilitado. Se esse valor for zero, realce de âncora será desativado  
  
### <a name="return-value"></a>Valor de retorno  
 A configuração anterior de âncora. Se o realce foi habilitado, esse valor é diferente de zero. Se o realce não estiver habilitado, esse valor é zero.  
  
### <a name="remarks"></a>Comentários  
 Este método implementa o comportamento da mensagem Win32 [TB_SETANCHORHIGHLIGHT](http://msdn.microsoft.com/library/windows/desktop/bb787396), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetbitmapsizea--ctoolbarctrlsetbitmapsize"></a><a name="setbitmapsize"></a>CToolBarCtrl::SetBitmapSize  
 Define o tamanho das imagens bitmap reais a ser adicionado a um controle de barra de ferramentas.  
  
```  
BOOL SetBitmapSize(CSize size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 Largura e altura em pixels, das imagens de bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada somente antes de adicionar qualquer bitmaps na barra de ferramentas. Se o aplicativo não definir explicitamente o tamanho do bitmap, o padrão é 16 por 15 pixels.  
  
##  <a name="a-namesetbuttoninfoa--ctoolbarctrlsetbuttoninfo"></a><a name="setbuttoninfo"></a>CToolBarCtrl::SetButtonInfo  
 Define as informações de um botão existente em uma barra de ferramentas.  
  
```  
BOOL SetButtonInfo(
    int nID,  
    TBBUTTONINFO* ptbbi);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 O identificador do botão.  
  
 `ptbbi`  
 Um ponteiro para um [TBBUTTONINFO](http://msdn.microsoft.com/library/windows/desktop/bb760478) estrutura que recebe as informações do botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A função de membro implementa o comportamento da mensagem Win32 [TB_SETBUTTONINFO](http://msdn.microsoft.com/library/windows/desktop/bb787413), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetbuttonsizea--ctoolbarctrlsetbuttonsize"></a><a name="setbuttonsize"></a>CToolBarCtrl::SetButtonSize  
 Define o tamanho dos botões no controle de barra de ferramentas.  
  
```  
BOOL SetButtonSize(CSize size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 Largura e altura em pixels, dos botões.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Sempre deve ser pelo menos tão grande quanto o tamanho de bitmap que envolva o tamanho do botão. Essa função deve ser chamada somente antes de adicionar qualquer bitmaps na barra de ferramentas. Se o aplicativo não definir explicitamente o tamanho do botão, o padrão é 24 por 22 pixels.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CToolBar::GetToolBarCtrl](../../mfc/reference/ctoolbar-class.md#gettoolbarctrl).  
  
##  <a name="a-namesetbuttonstructsizea--ctoolbarctrlsetbuttonstructsize"></a><a name="setbuttonstructsize"></a>CToolBarCtrl::SetButtonStructSize  
 Especifica o tamanho do `TBBUTTON` estrutura.  
  
```  
void SetButtonStructSize(int nSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSize`  
 Tamanho, em bytes, do `TBBUTTON` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser armazenar dados extras no `TBBUTTON` estrutura, você pode derivar uma nova estrutura de `TBBUTTON`, adicionando os membros é necessária, ou criar uma nova estrutura que contém um `TBBUTTON` estrutura como seu primeiro membro. Em seguida, você chamaria essa função para informar o controle de barra de ferramentas o tamanho da nova estrutura.  
  
 Consulte [CToolBarCtrl::AddButtons](#addbuttons) para obter mais informações sobre o `TBBUTTON` estrutura.  
  
##  <a name="a-namesetbuttonwidtha--ctoolbarctrlsetbuttonwidth"></a><a name="setbuttonwidth"></a>CToolBarCtrl::SetButtonWidth  
 Define as larguras mínima e máxima de botão no controle de barra de ferramentas.  
  
```  
BOOL SetButtonWidth(
    int cxMin,  
    int cxMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cxMin`  
 Largura do botão mínimo, em pixels. Botões da barra de ferramentas nunca serão mais estreitas do que esse valor.  
  
 *cxMax*  
 Largura do botão máxima, em pixels. Se o texto do botão é grande demais, o controle exibe por pontos de elipse.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_SETBUTTONWIDTH](http://msdn.microsoft.com/library/windows/desktop/bb787417), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetcmdida--ctoolbarctrlsetcmdid"></a><a name="setcmdid"></a>CToolBarCtrl::SetCmdID  
 Define o identificador de comando que será enviado para a janela do proprietário quando é pressionado o botão especificado.  
  
```  
BOOL SetCmdID(
    int nIndex,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice baseado em zero do botão cuja ID de comando deve ser definido.  
  
 `nID`  
 A ID de comando para definir o botão selecionado para.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna zero se for bem-sucedida; Caso contrário, zero.  
  
##  <a name="a-namesetcolorschemea--ctoolbarctrlsetcolorscheme"></a><a name="setcolorscheme"></a>CToolBarCtrl::SetColorScheme  
 Define o esquema de cores do controle da barra de ferramentas atual.  
  
```  
void SetColorScheme(const COLORSCHEME* lpColorScheme);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `lpColorScheme`|Ponteiro para uma [COLORSCHEME](http://msdn.microsoft.com/library/windows/desktop/bb775502) estrutura que descreve as cores de realce e sombra do controle da barra de ferramentas.|  
  
### <a name="remarks"></a>Comentários  
 Esse método não tem nenhum efeito se um [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)] tema visual é definido.  
  
 Esse método envia o [TB_SETCOLORSCHEME](http://msdn.microsoft.com/library/windows/desktop/bb787421) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o esquema de cores para o controle de barra de ferramentas atual. O exemplo de código faz com que as bordas esquerdas e superior de cada botão de ferramenta vermelho e as bordas direita e inferior azul. Quando o usuário pressiona o botão, as bordas vermelhas do botão Ativar azuis e as bordas azuis ficam vermelhas.  
  
 [!code-cpp[NVC_MFC_CToolBarCtrl_s1 n º&3;](../../mfc/reference/codesnippet/cpp/ctoolbarctrl-class_5.cpp)]  
  
##  <a name="a-namesetdisabledimagelista--ctoolbarctrlsetdisabledimagelist"></a><a name="setdisabledimagelist"></a>CToolBarCtrl::SetDisabledImageList  
 Define a lista de imagens que irá usar o controle de barra de ferramentas para botões de exibição desabilitada.  
  
```  
CImageList* SetDisabledImageList(CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pImageList`  
 Um ponteiro para um `CImageList` objeto que contém as imagens a serem usadas pelo controle de barra de ferramentas para imagens de botão de exibição desabilitada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto que foi usado anteriormente pelo controle de barra de ferramentas para imagens de botão de exibição desabilitada.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_SETDISABLEDIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb787423), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. A implementação do MFC de `SetDisabledImageList` usa um `CImageList` objeto contendo botões desabilitados do controle da barra de ferramentas de imagens, em vez de um identificador para uma lista de imagens.  
  
##  <a name="a-namesetdrawtextflagsa--ctoolbarctrlsetdrawtextflags"></a><a name="setdrawtextflags"></a>CToolBarCtrl::SetDrawTextFlags  
 Define os sinalizadores na função Win32 [DrawText](http://msdn.microsoft.com/library/windows/desktop/dd162498), que é usado para desenhar o texto no retângulo especificado, formatado de acordo com como os sinalizadores são definidos.  
  
```  
DWORD SetDrawTextFlags(
    DWORD dwMask,  
    DWORD dwDTFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwMask`  
 Uma combinação de um ou mais sinalizadores DT_, especificados na função Win32 [DrawText](http://msdn.microsoft.com/library/windows/desktop/dd162498), que indica que o bits `dwDTFlags` será usado ao desenhar o texto.  
  
 `dwDTFlags`  
 Uma combinação de um ou mais sinalizadores DT_, especificados na função Win32 `DrawText`, que indicam como o texto do botão será desenhado. Esse valor é passado para `DrawText` quando o texto do botão é desenhado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` que contém o sinalizadores de desenho de texto anterior.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_SETDRAWTEXTFLAGS](http://msdn.microsoft.com/library/windows/desktop/bb787425), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Essa função membro define os sinalizadores na função Win32 `DrawText`, que desenha o texto no retângulo especificado, formatado de acordo com como os sinalizadores são definidos.  
  
##  <a name="a-namesetextendedstylea--ctoolbarctrlsetextendedstyle"></a><a name="setextendedstyle"></a>CToolBarCtrl::SetExtendedStyle  
 Define os estilos estendidos para um controle de barra de ferramentas.  
  
```  
DWORD SetExtendedStyle(DWORD dwExStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Um valor que especifica os novos estilos estendidos. Esse parâmetro pode ser uma combinação da barra de ferramentas estilos estendidos.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` que representa o anterior estilos estendidos. Para obter uma lista de estilos, consulte [estilos estendidos de barra de ferramentas](http://msdn.microsoft.com/library/windows/desktop/bb760430), além de [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_SETEXTENDEDSTYLE](http://msdn.microsoft.com/library/windows/desktop/bb787427), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesethotimagelista--ctoolbarctrlsethotimagelist"></a><a name="sethotimagelist"></a>CToolBarCtrl::SetHotImageList  
 Define a lista de imagens que irá usar o controle de barra de ferramentas para exibir os botões "hot".  
  
```  
CImageList* SetHotImageList(CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pImageList`  
 Um ponteiro para um `CImageList` objeto que contém as imagens a serem usadas pelo controle de barra de ferramentas para exibir imagens indispensável.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto que foi usado anteriormente pelo controle de barra de ferramentas para exibir imagens indispensável.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_SETHOTIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb787429), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 A implementação do MFC de `SetHotImageList` usa um `CImageList` objeto contendo indispensável do controle da barra de ferramentas de imagens, em vez de um identificador para uma lista de imagens. Um ponto crítico é realçado quando o ponteiro estiver acima dela.  
  
##  <a name="a-namesethotitema--ctoolbarctrlsethotitem"></a><a name="sethotitem"></a>CToolBarCtrl::SetHotItem  
 Define o item ativo na barra de ferramentas.  
  
```  
int SetHotItem(int nHot);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nHot*  
 O número de índice baseado em zero do item que ficará ativo. Se esse valor for -1, nenhum dos itens será quente.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item hot anterior, ou -1 se não houvesse nenhum item ativa.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_SETHOTITEM](http://msdn.microsoft.com/library/windows/desktop/bb787431), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetimagelista--ctoolbarctrlsetimagelist"></a><a name="setimagelist"></a>CToolBarCtrl::SetImageList  
 Define a lista de imagens que usará a barra de ferramentas para exibir os botões que estão em seu estado padrão.  
  
```  
CImageList* SetImageList(CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pImageList`  
 Um ponteiro para um `CImageList` objeto que contém as imagens a serem usadas pelo controle de barra de ferramentas para exibir imagens de botão em seu estado padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto que foi usado anteriormente pelo controle de barra de ferramentas para exibir imagens de botão em seu estado padrão.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_SETIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb787433), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 A implementação do MFC de `SetImageList` usa um `CImageList` objeto que contém o botão do controle da barra de ferramentas de imagens, em vez de um identificador para uma lista de imagens.  
  
##  <a name="a-namesetindenta--ctoolbarctrlsetindent"></a><a name="setindent"></a>CToolBarCtrl::SetIndent  
 Define o recuo do primeiro botão em um controle de barra de ferramentas.  
  
```  
BOOL SetIndent(int iIndent);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iIndent*  
 O valor que especifica o recuo, em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
##  <a name="a-namesetinsertmarka--ctoolbarctrlsetinsertmark"></a><a name="setinsertmark"></a>CToolBarCtrl::SetInsertMark  
 Define a marca de inserção atual da barra de ferramentas.  
  
```  
void SetInsertMark(TBINSERTMARK* ptbim);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptbim`  
 Um ponteiro para o [TBINSERTMARK](http://msdn.microsoft.com/library/windows/desktop/bb760480) estrutura que contém a marca de inserção.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_SETINSERTMARK](http://msdn.microsoft.com/library/windows/desktop/bb787437), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetinsertmarkcolora--ctoolbarctrlsetinsertmarkcolor"></a><a name="setinsertmarkcolor"></a>CToolBarCtrl::SetInsertMarkColor  
 Define a cor usada para desenhar a marca de inserção para a barra de ferramentas.  
  
```  
COLORREF SetInsertMarkColor(COLORREF clrNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clrNew`  
 A **COLORREF** valor que contém a nova cor de marca de inserção.  
  
### <a name="return-value"></a>Valor de retorno  
 A **COLORREF** valor que contém a cor da marca de inserção anterior.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [TB_SETINSERTMARKCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb787439), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetmaxtextrowsa--ctoolbarctrlsetmaxtextrows"></a><a name="setmaxtextrows"></a>CToolBarCtrl::SetMaxTextRows  
 Define o número máximo de linhas de texto exibido no botão da barra de ferramentas.  
  
```  
BOOL SetMaxTextRows(int iMaxRows);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iMaxRows*  
 Número máximo de linhas a ser definido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
##  <a name="a-namesetmetricsa--ctoolbarctrlsetmetrics"></a><a name="setmetrics"></a>CToolBarCtrl::SetMetrics  
 Define as métricas do `CToolBarCtrl` objeto.  
  
```  
void SetMetrics(LPTBMETRICS ptbm);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptbm`  
 Um ponteiro para o [TBMETRICS](http://msdn.microsoft.com/library/windows/desktop/bb760482) estrutura do `CToolBarCtrl` objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [TB_SETMETRICS](http://msdn.microsoft.com/library/windows/desktop/bb787446) mensagem, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetownera--ctoolbarctrlsetowner"></a><a name="setowner"></a>CToolBarCtrl::SetOwner  
 Define a janela do proprietário para o controle de barra de ferramentas.  
  
```  
void SetOwner(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Ponteiro para o `CWnd` ou `CWnd`-derivados do objeto que será a nova janela de proprietário para o controle de barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 A janela do proprietário é a janela que recebe notificações na barra de ferramentas.  
  
##  <a name="a-namesetpaddinga--ctoolbarctrlsetpadding"></a><a name="setpadding"></a>CToolBarCtrl::SetPadding  
 Define o preenchimento horizontal e vertical do controle da barra de ferramentas atual.  
  
```  
DWORD SetPadding(
    int nHorzPadding,   
    int nVertPadding);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `nHorzPadding`|Especifica o preenchimento horizontal do controle da barra de ferramentas, em pixels.|  
|[in] `nVertPadding`|Especifica o preenchimento vertical do controle da barra de ferramentas, em pixels.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` cuja palavra inferior contém o valor de preenchimento horizontal anterior e cuja palavra superior contém o valor de preenchimento anterior. Os valores de preenchimento são medidos em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TB_SETPADDING](http://msdn.microsoft.com/library/windows/desktop/bb787448) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o preenchimento horizontal e vertical do controle da barra de ferramentas atual a 20 pixels.  
  
 [!code-cpp[NVC_MFC_CToolBarCtrl_s1 n º&4;](../../mfc/reference/codesnippet/cpp/ctoolbarctrl-class_6.cpp)]  
  
##  <a name="a-namesetpressedimagelista--ctoolbarctrlsetpressedimagelist"></a><a name="setpressedimagelist"></a>CToolBarCtrl::SetPressedImageList  
 Define a lista de imagens que o controle de barra de ferramentas atual usa para representar botões no estado pressionado.  
  
```  
CImagelist* SetPressedImageList(
    int iImageID,   
    CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iImageID`|O índice baseado em zero da lista de imagens. Defina esse parâmetro como zero se você usar apenas uma lista de imagens.|  
|[in] `pImageList`|Ponteiro para uma [CImageList](../../mfc/reference/cimagelist-class.md) que contém a nova lista de imagem.|  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma [CImageList](../../mfc/reference/cimagelist-class.md) que contém a lista anterior de imagem para o controle atual, ou `NULL` se nenhuma dessas listas de imagem foi definida.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TB_SETPRESSEDIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb787453) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a lista de imagem pressionada para ser o mesmo que a lista de imagens padrão.  
  
 [!code-cpp[NVC_MFC_CToolBarCtrl_s1 n º&5;](../../mfc/reference/codesnippet/cpp/ctoolbarctrl-class_7.cpp)]  
  
##  <a name="a-namesetrowsa--ctoolbarctrlsetrows"></a><a name="setrows"></a>CToolBarCtrl::SetRows  
 Solicita que o controle de barra de ferramentas para redimensionar a mesmo para o número de linhas solicitado.  
  
```  
void SetRows(
    int nRows,  
    BOOL bLarger,  
    LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRows`  
 Número de linhas solicitado.  
  
 `bLarger`  
 Indica se deve usar mais linhas ou menos linhas se a barra de ferramentas não pode ser redimensionada para o número de linhas solicitado.  
  
 `lpRect`  
 Aponta para a [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que receberão o novo retângulo delimitador da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Se a barra de ferramentas não é possível redimensionar próprio para o número solicitado de linhas, ele será redimensionado como o próximo maior ou próximo menor tamanho válido, dependendo do valor de `bLarger`. Se `bLarger` é **TRUE**, o número de linhas será maior que o número solicitado. Se `bLarger` é **FALSE**, o número de linhas será menor do que o número solicitado.  
  
 Um determinado número de linhas é válido para a barra de ferramentas se os botões podem ser organizados de modo que todas as linhas tenham o mesmo número de botões (exceto talvez a última linha). Por exemplo, uma barra de ferramentas contém quatro botões não pode ser dimensionada para três linhas porque as duas últimas linhas teriam de ser mais curto. Se você tentou dimensioná-lo para três linhas, você obterá quatro linhas se `bLarger` foi **TRUE** e duas linhas se `bLarger` foi **FALSE**.  
  
 Se houver separadores na barra de ferramentas, as regras para quando um determinado número de linhas é válido são mais complicadas. O layout é calculado, de modo que os grupos de botões (botões com um separador antes do primeiro) e o último botão no grupo são nunca divididos em várias linhas, a menos que o grupo não couberem em uma linha.  
  
 Se um grupo não couber em uma linha, o próximo grupo iniciará na próxima linha, mesmo que caibam na linha onde o grupo grande terminou. A finalidade dessa regra é tornar a separação entre grupos grandes mais visíveis. Os separadores verticais resultantes são contados como linhas.  
  
 Observe também que o `SetRows` função membro sempre escolher o layout que resulta em menor tamanho de barra de ferramentas. Criando uma barra de ferramentas com o `TBSTYLE_WRAPABLE` estilo e, em seguida, redimensionar o controle simplesmente aplicar o método descrito acima, dada a largura do controle.  
  
 Essa função só pode ser chamada para barras de ferramentas que foram criadas com o `TBSTYLE_WRAPABLE` estilo.  
  
##  <a name="a-namesetstatea--ctoolbarctrlsetstate"></a><a name="setstate"></a>CToolBarCtrl::SetState  
 Define o estado do botão especificado em um controle de barra de ferramentas.  
  
```  
BOOL SetState(
    int nID,  
    UINT nState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Identificador de comando do botão.  
  
 `nState`  
 Sinalizadores de estado. Pode ser uma combinação dos valores listados para estados de botão no [CToolBarCtrl::AddButtons](#addbuttons).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função é especialmente útil se você deseja definir mais de um dos Estados do botão. Para definir apenas um estado, use uma das seguintes funções de membro: [EnableButton](#enablebutton), [CheckButton](#checkbutton), [HideButton](#hidebutton), [indeterminado](#indeterminate), ou [PressButton](#pressbutton).  
  
##  <a name="a-namesetstylea--ctoolbarctrlsetstyle"></a><a name="setstyle"></a>CToolBarCtrl::SetStyle  
 Define os estilos de um controle de barra de ferramentas.  
  
```  
void SetStyle(DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 A `DWORD` que contém uma combinação de [estilos de controle de barra de ferramentas](http://msdn.microsoft.com/library/windows/desktop/bb760439), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesettooltipsa--ctoolbarctrlsettooltips"></a><a name="settooltips"></a>CToolBarCtrl::SetToolTips  
 Associa um controle de dica de ferramenta com um controle de barra de ferramentas.  
  
```  
void SetToolTips(CToolTipCtrl* pTip);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pTip*  
 Ponteiro para o [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) objeto.  
  
##  <a name="a-namesetwindowthemea--ctoolbarctrlsetwindowtheme"></a><a name="setwindowtheme"></a>CToolBarCtrl::SetWindowTheme  
 Define o estilo visual do `CToolBarCtrl` objeto.  
  
```  
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszSubAppName`  
 Um ponteiro para uma cadeia de caracteres Unicode que contém o estilo visual da barra de ferramentas para definir.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno não é usado.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [TB_SETWINDOWTHEME](http://msdn.microsoft.com/library/windows/desktop/bb787465) mensagem, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [CMNCTRL1 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Exemplo MFC MFCIE](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CToolBar](../../mfc/reference/ctoolbar-class.md)

