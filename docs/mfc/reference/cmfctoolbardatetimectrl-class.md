---
title: Classe CMFCToolBarDateTimeCtrl
ms.date: 11/04/2016
f1_keywords:
- CMFCToolBarDateTimeCtrl
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::CMFCToolBarDateTimeCtrl
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::CanBeStretched
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::CopyFrom
- AFXTOOLBARDATETIMECTRL/CMFCToolBarButton::ExportToMenuButton
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetByCmd
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetDateTimeCtrl
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetHwnd
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetTime
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::GetTimeAll
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::HaveHotBorder
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::NotifyCommand
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnAddToCustomizePage
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnChangeParentWnd
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnClick
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnCtlColor
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnMove
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnShow
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::OnUpdateToolTip
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::SetTime
- AFXTOOLBARDATETIMECTRL/CMFCToolBarDateTimeCtrl::SetTimeAll
helpviewer_keywords:
- CMFCToolBarDateTimeCtrl [MFC], CMFCToolBarDateTimeCtrl
- CMFCToolBarDateTimeCtrl [MFC], CanBeStretched
- CMFCToolBarDateTimeCtrl [MFC], CopyFrom
- CMFCToolBarButton [MFC], ExportToMenuButton
- CMFCToolBarDateTimeCtrl [MFC], GetByCmd
- CMFCToolBarDateTimeCtrl [MFC], GetDateTimeCtrl
- CMFCToolBarDateTimeCtrl [MFC], GetHwnd
- CMFCToolBarDateTimeCtrl [MFC], GetTime
- CMFCToolBarDateTimeCtrl [MFC], GetTimeAll
- CMFCToolBarDateTimeCtrl [MFC], HaveHotBorder
- CMFCToolBarDateTimeCtrl [MFC], NotifyCommand
- CMFCToolBarDateTimeCtrl [MFC], OnAddToCustomizePage
- CMFCToolBarDateTimeCtrl [MFC], OnChangeParentWnd
- CMFCToolBarDateTimeCtrl [MFC], OnClick
- CMFCToolBarDateTimeCtrl [MFC], OnCtlColor
- CMFCToolBarDateTimeCtrl [MFC], OnGlobalFontsChanged
- CMFCToolBarDateTimeCtrl [MFC], OnMove
- CMFCToolBarDateTimeCtrl [MFC], OnShow
- CMFCToolBarDateTimeCtrl [MFC], OnUpdateToolTip
- CMFCToolBarDateTimeCtrl [MFC], SetTime
- CMFCToolBarDateTimeCtrl [MFC], SetTimeAll
ms.assetid: a3853cb9-8ebc-444f-a1e4-9cf905e24c18
ms.openlocfilehash: dfe1d3dc058371dd13cc335968b9c3a89e057da2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62218469"
---
# <a name="cmfctoolbardatetimectrl-class"></a>Classe CMFCToolBarDateTimeCtrl

Um botão de barra de ferramentas que contém um controle de seletor de data e hora.

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarDateTimeCtrl : public CMFCToolBarButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarDateTimeCtrl::CMFCToolBarDateTimeCtrl](#cmfctoolbardatetimectrl)|Constrói um objeto `CMFCToolBarDateTimeCtrl`.|
|`CMFCToolBarDateTimeCtrl::~CMFCToolBarDateTimeCtrl`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarDateTimeCtrl::CanBeStretched](#canbestretched)|Especifica se um usuário pode ampliar o botão durante a personalização. (Substitui [CMFCToolBarButton::CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched).)|
|[CMFCToolBarDateTimeCtrl::CopyFrom](#copyfrom)|Copia as propriedades de outro botão de barra de ferramentas para o botão atual. (Substitui [CMFCToolBarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|
|`CMFCToolBarDateTimeCtrl::DuplicateData`|Reservado para uso futuro.|
|[CMFCToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)|Copia o texto do botão da barra de ferramentas a um menu.|
|`CMFCToolBarDateTimeCtrl::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|[CMFCToolBarDateTimeCtrl::GetByCmd](#getbycmd)|Recupera o primeiro `CMFCToolBarDateTimeCtrl` objeto no aplicativo que tem a ID de comando especificado.|
|[CMFCToolBarDateTimeCtrl::GetDateTimeCtrl](#getdatetimectrl)|Retorna um ponteiro para o controle de seletor de data e hora.|
|[CMFCToolBarDateTimeCtrl::GetHwnd](#gethwnd)|Recupera o identificador de janela que está associado com o botão de barra de ferramentas. (Substitui [CMFCToolBarButton::GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd).)|
|`CMFCToolBarDateTimeCtrl::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCToolBarDateTimeCtrl::GetTime](#gettime)|Obtém o tempo selecionado de um controle de seletor de data e hora e o coloca em um especificado [SYSTEMTIME](/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) estrutura.|
|[CMFCToolBarDateTimeCtrl::GetTimeAll](#gettimeall)|Retorna o tempo selecionado do botão de controle de seletor de tempo que tem uma ID de comando especificado.|
|[CMFCToolBarDateTimeCtrl::HaveHotBorder](#havehotborder)|Determina se uma borda do botão é exibida quando um usuário seleciona o botão. (Substitui [CMFCToolBarButton::HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder).)|
|[CMFCToolBarDateTimeCtrl::NotifyCommand](#notifycommand)|Especifica se o botão processa os [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagem. (Substitui [CMFCToolBarButton::NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand).)|
|[CMFCToolBarDateTimeCtrl::OnAddToCustomizePage](#onaddtocustomizepage)|Chamado pelo framework quando o botão é adicionado a um **personalizar** caixa de diálogo. (Substitui [CMFCToolBarButton::OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage).)|
|`CMFCToolBarDateTimeCtrl::OnCalculateSize`|Chamado pelo framework para calcular o tamanho do botão para o contexto de dispositivo especificado e o estado de encaixe. (Substitui [CMFCToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|
|[CMFCToolBarDateTimeCtrl::OnChangeParentWnd](#onchangeparentwnd)|Chamado pelo framework quando o botão é inserido em uma nova barra de ferramentas. (Substitui [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|
|[CMFCToolBarDateTimeCtrl::OnClick](#onclick)|Chamado pelo framework quando o usuário clica no controle. (Substitui [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|
|[CMFCToolBarDateTimeCtrl::OnCtlColor](#onctlcolor)|Chamado pelo framework quando a barra de ferramentas pai manipula uma WM_CTLCOLOR (mensagem). (Substitui [CMFCToolBarButton::OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor).)|
|`CMFCToolBarDateTimeCtrl::OnDraw`|Chamado pelo framework para desenhar o botão usando as opções e estilos especificados. (Substitui [CMFCToolBarButton::OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|
|`CMFCToolBarDateTimeCtrl::OnDrawOnCustomizeList`|Chamado pelo framework para desenhar o botão na **comandos** painel da **personalizar** caixa de diálogo. (Substitui [CMFCToolBarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|
|[CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged](#onglobalfontschanged)|Chamado pelo framework quando a fonte global foi alterada. (Substitui [CMFCToolBarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged).)|
|[CMFCToolBarDateTimeCtrl::OnMove](#onmove)|Chamado pelo framework quando move a barra de ferramentas pai. (Substitui [CMFCToolBarButton::OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove).)|
|[CMFCToolBarDateTimeCtrl::OnShow](#onshow)|Chamado pelo framework quando o botão se torna visível ou invisível. (Substitui [CMFCToolBarButton::OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow).)|
|`CMFCToolBarDateTimeCtrl::OnSize`|Chamado pelo framework quando a barra de ferramentas pai altera seu tamanho ou posição e essa alteração faz com que o botão para alterar o tamanho. (Substitui [CMFCToolBarButton::OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize).)|
|[CMFCToolBarDateTimeCtrl::OnUpdateToolTip](#onupdatetooltip)|Chamado pelo framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta. (Substitui [CMFCToolBarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip).)|
|`CMFCToolBarDateTimeCtrl::Serialize`|Lê esse objeto de um arquivo morto ou grava-o em um arquivo morto, (substitui [CMFCToolBarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|
|`CMFCToolBarDateTimeCtrl::SetStyle`|Define o estilo do botão de barra de ferramentas. (Substitui [CMFCToolBarButton::SetStyle](../../mfc/reference/cmfctoolbarbutton-class.md#setstyle).)|
|[CMFCToolBarDateTimeCtrl::SetTime](#settime)|Define a data e hora em que o controle de seletor de tempo.|
|[CMFCToolBarDateTimeCtrl::SetTimeAll](#settimeall)|Define a data e hora em todas as instâncias do controle de seletor de tempo que têm uma ID de comando especificado.|

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar um controle de seletor de data e hora, consulte o projeto de exemplo ToolbarDateTimePicker. Para obter informações sobre como adicionar botões de controle para barras de ferramentas, consulte [passo a passo: Colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)

[CMFCToolBarDateTimeCtrl](../../mfc/reference/cmfctoolbardatetimectrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbardatetimectrl.h

##  <a name="canbestretched"></a>  CMFCToolBarDateTimeCtrl::CanBeStretched

Especifica se um usuário pode ampliar o botão durante a personalização.

```
virtual BOOL CanBeStretched() const;
```

### <a name="return-value"></a>Valor de retorno

Esse método retornará TRUE.

### <a name="remarks"></a>Comentários

Por padrão, o framework permite ao usuário Alongar um botão de barra de ferramentas durante a personalização. Este método estende a implementação da classe base ( [CMFCToolBarButton::CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched)), permitindo que o usuário Alongar um botão de barra de ferramentas de data e hora durante a personalização.

##  <a name="cmfctoolbardatetimectrl"></a>  CMFCToolBarDateTimeCtrl::CMFCToolBarDateTimeCtrl

Cria e inicializa um [CMFCToolBarDateTimeCtrl](../../mfc/reference/cmfctoolbardatetimectrl-class.md) objeto.

```
CMFCToolBarDateTimeCtrl(
    UINT uiID,
    int iImage,
    DWORD dwStyle=0,
    int iWidth=0);
```

### <a name="parameters"></a>Parâmetros

*uiID*<br/>
[in] A ID do controle.

*iImage*<br/>
[in] O índice da imagem na barra de ferramentas `CMFCToolBarImages` objeto.

*dwStyle*<br/>
[in] O estilo do `CMFCToolBarDateTimeCtrlImpl` janela que é criada quando um usuário clica no botão.

*iWidth*<br/>
[in] A largura do controle, em pixels.

### <a name="remarks"></a>Comentários

Este objeto é inicializado para a data do sistema e a hora. O estilo da janela de interno `CMFCToolBarDateTimeCtrlImpl` objeto inclui o *dwStyle* parâmetro e os estilos WS_CHILD e WS_VISIBLE. Você não pode alterar esses estilos usando `CMFCToolBarDateTimeCtrl::SetStyle`. Use `SetStyle` para alterar o estilo do `CMFCToolBarDateTimeCtrl` controle.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto do `CMFCToolBarDateTimeCtrl` classe. Este trecho de código é parte do [exemplo de seletor de data e hora da barra de ferramentas](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_ToolbarDateTimePicker#1](../../mfc/reference/codesnippet/cpp/cmfctoolbardatetimectrl-class_1.cpp)]

##  <a name="copyfrom"></a>  CMFCToolBarDateTimeCtrl::CopyFrom

Copia as propriedades de outro botão de barra de ferramentas para o botão atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[in] Uma referência para o botão de origem da qual copiar.

### <a name="remarks"></a>Comentários

Chame esse método para copiar de outro botão de barra de ferramentas para este botão de barra de ferramentas. *src* deve ser do tipo `CMFCToolBarDateTimeCtrl`.

##  <a name="exporttomenubutton"></a>  CMFCToolBarDateTimeCtrl::ExportToMenuButton

Copia o texto do botão da barra de ferramentas a um menu.

```
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;
```

### <a name="parameters"></a>Parâmetros

*menuButton*<br/>
[in] Uma referência para o botão de menu de destino.

### <a name="return-value"></a>Valor de retorno

Esse método retornará TRUE.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base ( [CMFCToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)) ao carregar o recurso de cadeia de caracteres que está associado com a ID de comando do controle. Para obter mais informações sobre os recursos de cadeia de caracteres, consulte [CStringT::LoadString](../../atl-mfc-shared/reference/cstringt-class.md#loadstring).

##  <a name="getbycmd"></a>  CMFCToolBarDateTimeCtrl::GetByCmd

Recupera o primeiro `CMFCToolBarDateTimeCtrl` objeto no aplicativo que tem a ID de comando especificado.

```
static CMFCToolBarDateTimeCtrl* __stdcall GetByCmd(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
[in] A ID de comando do botão para recuperar.

### <a name="return-value"></a>Valor de retorno

A primeira `CMFCToolBarDateTimeCtrl` objeto no aplicativo que tem o ID de comando especificada ou nulo se nenhum `CMFCToolBarDateTimeCtrl` objetos têm a ID do comando especificado.

### <a name="remarks"></a>Comentários

Esse método de utilitário compartilhado é usado pelos métodos como [CMFCToolBarDateTimeCtrl::SetTimeAll](#settimeall) e [CMFCToolBarDateTimeCtrl::GetTimeAll](#gettimeall) para definir ou obter a hora e data de todas as instâncias do tempo controle de seletor que têm uma ID de comando especificado.

##  <a name="getdatetimectrl"></a>  CMFCToolBarDateTimeCtrl::GetDateTimeCtrl

Retorna um ponteiro para o controle de seletor de data e hora.

```
CDateTimeCtrl* GetDateTimeCtrl() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para controle de seletor de data e hora. ou nulo se o controle não existe.

### <a name="remarks"></a>Comentários

O `CMFCToolBarDateTimeCtrl` classe inicializa o `m_pWndDateTime` membro de dados quando você insere um `CMFCToolBarDateTimeCtrl` objeto em uma barra de ferramentas.

##  <a name="gethwnd"></a>  CMFCToolBarDateTimeCtrl::GetHwnd

Recupera o identificador de janela que está associado com o botão de barra de ferramentas.

```
virtual HWND GetHwnd();
```

### <a name="return-value"></a>Valor de retorno

O identificador de janela que está associado com o botão de barra de ferramentas de data e hora.

### <a name="remarks"></a>Comentários

Esse método substitui o [CMFCToolBarButton::GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd) método.

##  <a name="gettime"></a>  CMFCToolBarDateTimeCtrl::GetTime

Obtém o tempo selecionado da data associada e controle de seletor de tempo e o coloca em um especificado [SYSTEMTIME](/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) estrutura

```
BOOL GetTime(COleDateTime& timeDest) const;
DWORD GetTime(CTime& timeDest) const;
DWORD GetTime(LPSYSTEMTIME pTimeDest) const;
```

### <a name="parameters"></a>Parâmetros

*timeDest*<br/>
[out] Na primeira sobrecarga, uma [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que receberá as informações de hora do sistema. Na segunda sobrecarga, uma [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que receberá as informações de hora do sistema.

*pTimeDest*<br/>
[out] Um ponteiro para o [SYSTEMTIME](/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) estrutura que receberá as informações de hora do sistema. Não deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Na primeira sobrecarga, diferente de zero se o tempo é gravado com êxito para o [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto; caso contrário, 0. As sobrecargas de segunda e terceira, o valor de retorno é um DWORD que é igual ao que foi definido no membro dwFlag a [NMDATETIMECHANGE](/windows/desktop/api/commctrl/ns-commctrl-tagnmdatetimechange) estrutura.

### <a name="remarks"></a>Comentários

Método define a [NMDATETIMECHANGE](/windows/desktop/api/commctrl/ns-commctrl-tagnmdatetimechange) estrutura membro dwFlags para indicar se o seletor de data e hora é definido como uma data e hora. Se o valor for igual a GDT_NONE, o controle é definido como `no date` status e usa o estilo DTS_SHOWNONE. Se o valor retornado for igual a GDT_VALID, a hora do sistema com êxito é armazenada no local de destino.

##  <a name="gettimeall"></a>  CMFCToolBarDateTimeCtrl::GetTimeAll

Retorna o tempo selecionado pelo usuário no botão de controle de seletor de tempo que tem uma ID de comando especificado.

```
static BOOL GetTimeAll(
    UINT uiCmd,
    COleDateTime& timeDest);

static DWORD GetTimeAll(
    UINT uiCmd,
    CTime& timeDest);

static DWORD GetTimeAll(
    UINT uiCmd,
    LPSYSTEMTIME pTimeDest);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
[in] Especifica a ID de comando de. de um botão barra de ferramentas

*timeDest*<br/>
[out] Na primeira sobrecarga, uma [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que receberá as informações de hora do sistema. Na segunda sobrecarga, uma [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que receberá as informações de hora do sistema.

*pTimeDest*<br/>
[out] Um ponteiro para o [SYSTEMTIME](/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) estrutura que receberá as informações de hora do sistema. Não deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Se a estrutura não é possível localizar um botão de barra de ferramentas que corresponde à ID do comando *uiCmd*, o valor retornado será zero na primeira sobrecarga e GDT_NONE em outras sobrecargas. Se o botão de barra de ferramentas for encontrado, o valor de retorno é o mesmo que o valor retornado de uma chamada para [CMFCToolBarDateTimeCtrl::GetTime](#gettime) nesse botão. Retornar de um valor de zero ou GDT_NONE pode ocorrer quando o botão for encontrado, o que indica que a chamada para `GetTime` não retornou uma data válida por algum outro motivo.

### <a name="remarks"></a>Comentários

Esse método procura por um botão de barra de ferramentas que possui a ID de comando especificada e chama [CMFCToolBarDateTimeCtrl::GetTime](#gettime) método nesse botão.

##  <a name="havehotborder"></a>  CMFCToolBarDateTimeCtrl::HaveHotBorder

Determina se uma borda do botão é exibida quando um usuário seleciona o botão.

```
virtual BOOL HaveHotBorder() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se um botão exibe sua borda quando selecionada; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método retorna um valor diferente de zero se o controle está visível.

##  <a name="notifycommand"></a>  CMFCToolBarDateTimeCtrl::NotifyCommand

Especifica se o botão processa os [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagem.

```
virtual BOOL NotifyCommand(int iNotifyCode);
```

### <a name="parameters"></a>Parâmetros

*iNotifyCode*<br/>
[in] A mensagem de notificação que está associada com o comando.

### <a name="return-value"></a>Valor de retorno

TRUE se o botão processa a mensagem WM_COMMAND, ou FALSE para indicar que a mensagem deve ser tratada pela barra de ferramentas pai.

### <a name="remarks"></a>Comentários

O framework chama esse método quando ele está prestes a enviar uma [WM_COMMAND](/windows/desktop/menurc/wm-command) mensagem para a janela pai.

Este método estende a implementação da classe base ( [CMFCToolBarButton::NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand)) pelo processamento de [DTN_DATETIMECHANGE](/windows/desktop/Controls/dtn-datetimechange) notificação. Ele atualiza o status do tempo interno e atualiza a propriedade de tempo de todos os `CMFCToolBarDateTimeCtrl` objetos com a mesma ID de comando

##  <a name="onaddtocustomizepage"></a>  CMFCToolBarDateTimeCtrl::OnAddToCustomizePage

Chamado pelo framework quando o botão é adicionado a um **personalizar** caixa de diálogo.

```
virtual void OnAddToCustomizePage();
```

### <a name="remarks"></a>Comentários

Este método estende a implementação de classe base [CMFCToolBarButton::OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage), por cópia das propriedades da primeira data e a hora de controle em qualquer barra de ferramentas que tem a mesma ID de comando como este objeto. Esse método não fará nada se nenhuma barra de ferramentas tem um controle de data e hora que tem a mesma ID de comando como este objeto.

Para obter mais informações sobre o **personalizar** caixa de diálogo, consulte [classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).

##  <a name="onchangeparentwnd"></a>  CMFCToolBarDateTimeCtrl::OnChangeParentWnd

Chamado pelo framework quando o botão é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[in] A nova janela pai.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base ( [CMFCToolBarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)), recriando o interno `CMFCToolBarDateTimeCtrlImpl` objeto.

##  <a name="onclick"></a>  CMFCToolBarDateTimeCtrl::OnClick

Chamado pelo framework quando o usuário clica no controle.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
[in] Não utilizado.

*bDelay*<br/>
[in] Não utilizado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão processa a mensagem de clique; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação de classe base [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick), retornando um valor diferente de zero se o interno `CMFCToolBarDateTimeCtrlImpl` objeto está visível.

##  <a name="onctlcolor"></a>  CMFCToolBarDateTimeCtrl::OnCtlColor

Chamado pelo framework quando a barra de ferramentas pai manipula uma WM_CTLCOLOR (mensagem).

```
virtual HBRUSH OnCtlColor(
    CDC* pDC,
    UINT nCtlColor);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] O contexto de dispositivo que exibe o botão.

*nCtlColor*<br/>
[in] Não utilizado.

### <a name="return-value"></a>Valor de retorno

Um identificador para o pincel global que a estrutura usa para pintar a tela de fundo do botão.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação de classe base [CMFCToolBarButton::OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor), ao definir o texto e em segundo plano as cores do contexto de dispositivo fornecido ao texto global e cores de plano de fundo, respectivamente.

Para obter mais informações sobre opções globais que estão disponíveis para seu aplicativo, consulte [estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).

##  <a name="onglobalfontschanged"></a>  CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged

Chamado pelo framework quando a fonte global foi alterada.

```
virtual void OnGlobalFontsChanged();
```

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base ( [CMFCToolBarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged)) alterando a fonte do controle da fonte global.

Para obter mais informações sobre opções globais que estão disponíveis para seu aplicativo, consulte [estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).

##  <a name="onmove"></a>  CMFCToolBarDateTimeCtrl::OnMove

Chamado pelo framework quando move a barra de ferramentas pai.

```
virtual void OnMove();
```

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe padrão ( [CMFCToolBarButton::OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove)), atualizando a posição do interno `CMFCToolBarDateTimeCtrlImpl` objeto.

##  <a name="onshow"></a>  CMFCToolBarDateTimeCtrl::OnShow

Chamado pelo framework quando o botão se torna visível ou invisível.

```
virtual void OnShow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*bShow*<br/>
[in] Especifica se o botão está visível. Se esse parâmetro for TRUE, o botão está visível. Caso contrário, o botão não está visível.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base ( [CMFCToolBarButton::OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow)), exibindo o botão se *bMostrar* é TRUE. Caso contrário, esse método oculta o botão.

##  <a name="onsize"></a>  CMFCToolBarDateTimeCtrl::OnSize

Chamado pelo framework quando a barra de ferramentas pai altera seu tamanho ou posição e essa alteração faz com que o botão para alterar o tamanho.

```
virtual void OnSize(int iSize);
```

### <a name="parameters"></a>Parâmetros

*iSize*<br/>
[in] A nova largura do botão, em pixels.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe padrão ( [CMFCToolBarButton::OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize)), atualizando o tamanho e posição do interno `CMFCToolBarDateTimeCtrlImpl` objeto.

##  <a name="onupdatetooltip"></a>  CMFCToolBarDateTimeCtrl::OnUpdateToolTip

Chamado pelo framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta.

```
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,
    int iButtonIndex,
    CToolTipCtrl& wndToolTip,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[in] A janela pai.

*iButtonIndex*<br/>
[in] O índice baseado em zero do botão na coleção de botões de pai.

*wndToolTip*<br/>
[in] O controle que exibe o texto de dica de ferramenta.

*str*<br/>
[out] Um `CString` objeto que recebe o texto de dica de ferramenta atualizada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método atualiza o texto de dica de ferramenta; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base ( [CMFCToolBarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip)), exibindo o texto de dica de ferramenta que está associado com o botão. Se o botão não está encaixado na horizontal, esse método não faz nada e retornará FALSE.

##  <a name="settime"></a>  CMFCToolBarDateTimeCtrl::SetTime

Define a data e hora em que o controle de seletor de tempo.

```
BOOL SetTime(const COleDateTime& timeNew);
BOOL SetTime(const CTime* timeNew);
BOOL SetTime(LPSYSTEMTIME pTimeNew=NULL);
```

### <a name="parameters"></a>Parâmetros

*timeNew*<br/>
[in] Na primeira versão, uma referência a um [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a hora para o qual o controle será definido. Na segunda versão, um ponteiro para um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora para o qual o controle será definido.

*pTimeNew*<br/>
[in] Um ponteiro para o [SYSTEMTIME](/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) estrutura que contém a hora para o qual o controle será definido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Define o tempo em um controle de seletor de data e hora, chamando [CDateTimeCtrl::SetTime](../../mfc/reference/cdatetimectrl-class.md#settime).

##  <a name="settimeall"></a>  CMFCToolBarDateTimeCtrl::SetTimeAll

Define a data e hora em todas as instâncias do controle de seletor de tempo que têm uma ID de comando especificado.

```
static BOOL SetTimeAll(
    UINT uiCmd,
    const COleDateTime& timeNew);

static BOOL SetTimeAll(
    UINT uiCmd,
    const CTime* pTimeNew);

static BOOL SetTimeAll(
    UINT uiCmd,
    LPSYSTEMTIME pTimeNew=NULL);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
[in] Especifica a ID de comando de. de um botão barra de ferramentas

*timeNew*<br/>
[in] Na primeira versão, uma [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que contém a hora para o qual o controle será definido. Na segunda versão, um ponteiro para um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora para o qual o controle será definido.

*pTimeNew*<br/>
[in] Um ponteiro para o [SYSTEMTIME](/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) estrutura que contém a hora para o qual o controle será definido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Procura um botão de barra de ferramentas com a ID de comando especificada e define o tempo em um controle de seletor de data e hora, chamando [CMFCToolBarDateTimeCtrl::SetTime](#settime).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Passo a passo: colocar controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
