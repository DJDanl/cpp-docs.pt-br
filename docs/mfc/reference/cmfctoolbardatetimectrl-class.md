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
ms.openlocfilehash: 7ab6a240a403e70446ebc1860474f6cb9e1d71e3
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504769"
---
# <a name="cmfctoolbardatetimectrl-class"></a>Classe CMFCToolBarDateTimeCtrl

Um botão da barra de ferramentas que contém um controle seletor de data e hora.

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
|[CMFCToolBarDateTimeCtrl::CanBeStretched](#canbestretched)|Especifica se um usuário pode alongar o botão durante a personalização. (Substitui [CMFCToolBarButton:: CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched).)|
|[CMFCToolBarDateTimeCtrl::CopyFrom](#copyfrom)|Copia as propriedades de outro botão da barra de ferramentas para o botão atual. (Substitui [CMFCToolBarButton:: CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|
|`CMFCToolBarDateTimeCtrl::DuplicateData`|Reservado para uso futuro.|
|[CMFCToolBarButton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)|Copia o texto do botão da barra de ferramentas para um menu.|
|`CMFCToolBarDateTimeCtrl::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCToolBarDateTimeCtrl::GetByCmd](#getbycmd)|Recupera o primeiro `CMFCToolBarDateTimeCtrl` objeto no aplicativo que tem a ID de comando especificada.|
|[CMFCToolBarDateTimeCtrl::GetDateTimeCtrl](#getdatetimectrl)|Retorna um ponteiro para o controle do seletor de data e hora.|
|[CMFCToolBarDateTimeCtrl::GetHwnd](#gethwnd)|Recupera o identificador de janela que está associado ao botão da barra de ferramentas. (Substitui [CMFCToolBarButton:: GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd).)|
|`CMFCToolBarDateTimeCtrl::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCToolBarDateTimeCtrl::GetTime](#gettime)|Obtém o tempo selecionado de um controle de seletor de data e hora e o coloca em uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) especificada.|
|[CMFCToolBarDateTimeCtrl::GetTimeAll](#gettimeall)|Retorna a hora selecionada do botão de controle de seletor de tempo que tem uma ID de comando especificada.|
|[CMFCToolBarDateTimeCtrl::HaveHotBorder](#havehotborder)|Determina se uma borda do botão é exibida quando um usuário seleciona o botão. (Substitui [CMFCToolBarButton:: HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder).)|
|[CMFCToolBarDateTimeCtrl::NotifyCommand](#notifycommand)|Especifica se o botão processa a mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) . (Substitui [CMFCToolBarButton:: NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand).)|
|[CMFCToolBarDateTimeCtrl::OnAddToCustomizePage](#onaddtocustomizepage)|Chamado pelo Framework quando o botão é adicionado a uma caixa de diálogo **Personalizar** . (Substitui [CMFCToolBarButton:: OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage).)|
|`CMFCToolBarDateTimeCtrl::OnCalculateSize`|Chamado pelo Framework para calcular o tamanho do botão para o contexto do dispositivo especificado e o estado de encaixe. (Substitui [CMFCToolBarButton:: OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|
|[CMFCToolBarDateTimeCtrl::OnChangeParentWnd](#onchangeparentwnd)|Chamado pelo Framework quando o botão é inserido em uma nova barra de ferramentas. (Substitui [CMFCToolBarButton:: OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|
|[CMFCToolBarDateTimeCtrl::OnClick](#onclick)|Chamado pelo Framework quando o usuário clica no controle. (Substitui [CMFCToolBarButton:: OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|
|[CMFCToolBarDateTimeCtrl::OnCtlColor](#onctlcolor)|Chamado pelo Framework quando a barra de ferramentas pai manipula uma mensagem WM_CTLCOLOR. (Substitui [CMFCToolBarButton:: OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor).)|
|`CMFCToolBarDateTimeCtrl::OnDraw`|Chamado pelo Framework para desenhar o botão usando os estilos e as opções especificadas. (Substitui [CMFCToolBarButton:: OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|
|`CMFCToolBarDateTimeCtrl::OnDrawOnCustomizeList`|Chamado pelo Framework para desenhar o botão no painel **comandos** da caixa de diálogo **Personalizar** . (Substitui [CMFCToolBarButton:: OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|
|[CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged](#onglobalfontschanged)|Chamado pelo Framework quando a fonte global é alterada. (Substitui [CMFCToolBarButton:: OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged).)|
|[CMFCToolBarDateTimeCtrl::OnMove](#onmove)|Chamado pelo Framework quando a barra de ferramentas pai é movida. (Substitui [CMFCToolBarButton:: OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove).)|
|[CMFCToolBarDateTimeCtrl::OnShow](#onshow)|Chamado pelo Framework quando o botão fica visível ou invisível. (Substitui [CMFCToolBarButton:: OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow).)|
|`CMFCToolBarDateTimeCtrl::OnSize`|Chamado pelo Framework quando a barra de ferramentas pai altera seu tamanho ou posição e essa alteração faz com que o botão mude de tamanho. (Substitui [CMFCToolBarButton:: OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize).)|
|[CMFCToolBarDateTimeCtrl::OnUpdateToolTip](#onupdatetooltip)|Chamado pelo Framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta. (Substitui [CMFCToolBarButton:: OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip).)|
|`CMFCToolBarDateTimeCtrl::Serialize`|Lê este objeto de um arquivo ou grava-o em um arquivo morto (Substitui [CMFCToolBarButton:: Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|
|`CMFCToolBarDateTimeCtrl::SetStyle`|Define o estilo do botão de barra de ferramentas. (Substitui [CMFCToolBarButton:: SetStyle](../../mfc/reference/cmfctoolbarbutton-class.md#setstyle).)|
|[CMFCToolBarDateTimeCtrl::SetTime](#settime)|Define a data e a hora no controle seletor de tempo.|
|[CMFCToolBarDateTimeCtrl::SetTimeAll](#settimeall)|Define a data e a hora em todas as instâncias do controle de seletor de tempo que têm uma ID de comando especificada.|

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar um controle seletor de data e hora, consulte o projeto de exemplo ToolbarDateTimePicker. Para obter informações sobre como adicionar botões de controle a barras de ferramentas [, consulte Passo a passos: Colocando controles em barras de](../../mfc/walkthrough-putting-controls-on-toolbars.md)ferramentas.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)

[CMFCToolBarDateTimeCtrl](../../mfc/reference/cmfctoolbardatetimectrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbardatetimectrl. h

##  <a name="canbestretched"></a>  CMFCToolBarDateTimeCtrl::CanBeStretched

Especifica se um usuário pode alongar o botão durante a personalização.

```
virtual BOOL CanBeStretched() const;
```

### <a name="return-value"></a>Valor de retorno

Esse método retorna TRUE.

### <a name="remarks"></a>Comentários

Por padrão, a estrutura não permite que o usuário alongue um botão da barra de ferramentas durante a personalização. Esse método estende a implementação da classe base ( [CMFCToolBarButton:: CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched)) permitindo que o usuário alongue um botão da barra de ferramentas de data e hora durante a personalização.

##  <a name="cmfctoolbardatetimectrl"></a>CMFCToolBarDateTimeCtrl::CMFCToolBarDateTimeCtrl

Cria e inicializa um objeto [CMFCToolBarDateTimeCtrl](../../mfc/reference/cmfctoolbardatetimectrl-class.md) .

```
CMFCToolBarDateTimeCtrl(
    UINT uiID,
    int iImage,
    DWORD dwStyle=0,
    int iWidth=0);
```

### <a name="parameters"></a>Parâmetros

*uiID*<br/>
no A ID de controle.

*iImage*<br/>
no O índice da imagem no objeto da `CMFCToolBarImages` barra de ferramentas.

*dwStyle*<br/>
no O estilo da `CMFCToolBarDateTimeCtrlImpl` janela que é criada quando um usuário clica no botão.

*iWidth*<br/>
no A largura do controle, em pixels.

### <a name="remarks"></a>Comentários

Esse objeto é inicializado para a data e hora do sistema. O estilo de janela do objeto `CMFCToolBarDateTimeCtrlImpl` interno inclui o parâmetro *dwStyle* e os estilos WS_CHILD e WS_VISIBLE. Você não pode alterar esses estilos usando `CMFCToolBarDateTimeCtrl::SetStyle`o. Use `SetStyle` para alterar o estilo `CMFCToolBarDateTimeCtrl` do controle.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um objeto da `CMFCToolBarDateTimeCtrl` classe. Este trecho de código faz parte da [amostra](../../overview/visual-cpp-samples.md)do seletor de data e hora da barra de ferramentas.

[!code-cpp[NVC_MFC_ToolbarDateTimePicker#1](../../mfc/reference/codesnippet/cpp/cmfctoolbardatetimectrl-class_1.cpp)]

##  <a name="copyfrom"></a>CMFCToolBarDateTimeCtrl::CopyFrom

Copia as propriedades de outro botão da barra de ferramentas para o botão atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
no Uma referência ao botão de origem a partir do qual copiar.

### <a name="remarks"></a>Comentários

Chame esse método para copiar outro botão da barra de ferramentas para este botão da barra de ferramentas. *src* deve ser do tipo `CMFCToolBarDateTimeCtrl`.

##  <a name="exporttomenubutton"></a>CMFCToolBarDateTimeCtrl::ExportToMenuButton

Copia o texto do botão da barra de ferramentas para um menu.

```
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;
```

### <a name="parameters"></a>Parâmetros

*menuButton*<br/>
no Uma referência ao botão de menu de destino.

### <a name="return-value"></a>Valor de retorno

Esse método retorna TRUE.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base ( [CMFCToolBarButton:: ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)) carregando o recurso de cadeia de caracteres que está associado à ID de comando do controle. Para obter mais informações sobre recursos de cadeia de caracteres, consulte [CStringT:: LoadString](../../atl-mfc-shared/reference/cstringt-class.md#loadstring).

##  <a name="getbycmd"></a>  CMFCToolBarDateTimeCtrl::GetByCmd

Recupera o primeiro `CMFCToolBarDateTimeCtrl` objeto no aplicativo que tem a ID de comando especificada.

```
static CMFCToolBarDateTimeCtrl* __stdcall GetByCmd(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*uiCmd*<br/>
no A ID de comando do botão a ser recuperado.

### <a name="return-value"></a>Valor de retorno

O primeiro `CMFCToolBarDateTimeCtrl` objeto no aplicativo que tem a ID de comando especificada ou NULL se nenhum `CMFCToolBarDateTimeCtrl` objeto tiver a ID de comando especificada.

### <a name="remarks"></a>Comentários

Esse método de utilitário compartilhado é usado por métodos como [CMFCToolBarDateTimeCtrl:: SetTimeAll](#settimeall) e [CMFCToolBarDateTimeCtrl:: GetTimeAll](#gettimeall) para definir ou obter a hora e a data de todas as instâncias do controle de seletor de tempo que têm uma ID de comando especificada.

##  <a name="getdatetimectrl"></a>  CMFCToolBarDateTimeCtrl::GetDateTimeCtrl

Retorna um ponteiro para o controle do seletor de data e hora.

```
CDateTimeCtrl* GetDateTimeCtrl() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o controle do seletor de data e hora; ou NULL se o controle não existir.

### <a name="remarks"></a>Comentários

A `CMFCToolBarDateTimeCtrl` classe Inicializa o `m_pWndDateTime` membro de dados quando você insere `CMFCToolBarDateTimeCtrl` um objeto em uma barra de ferramentas.

##  <a name="gethwnd"></a>  CMFCToolBarDateTimeCtrl::GetHwnd

Recupera o identificador de janela que está associado ao botão da barra de ferramentas.

```
virtual HWND GetHwnd();
```

### <a name="return-value"></a>Valor de retorno

O identificador de janela que está associado ao botão da barra de ferramentas de data e hora.

### <a name="remarks"></a>Comentários

Esse método substitui o método [CMFCToolBarButton:: GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd) .

##  <a name="gettime"></a>  CMFCToolBarDateTimeCtrl::GetTime

Obtém a hora selecionada do controle seletor de data e hora associado e a coloca em uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) especificada

```
BOOL GetTime(COleDateTime& timeDest) const;
DWORD GetTime(CTime& timeDest) const;
DWORD GetTime(LPSYSTEMTIME pTimeDest) const;
```

### <a name="parameters"></a>Parâmetros

*timeDest*<br/>
fora Na primeira sobrecarga, um objeto de [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que receberá as informações de hora do sistema. Na segunda sobrecarga, um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que receberá as informações de hora do sistema.

*pTimeDest*<br/>
fora Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) para receber as informações de hora do sistema. Não deve ser nulo.

### <a name="return-value"></a>Valor de retorno

Na primeira sobrecarga, diferente de zero, se a hora for gravada com êxito no objeto da [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ; caso contrário, 0. Na segunda e terceira sobrecargas, o valor de retorno é um DWORD que é igual ao membro dwFlag que foi definido na estrutura [NMDATETIMECHANGE](/windows/win32/api/commctrl/ns-commctrl-nmdatetimechange) .

### <a name="remarks"></a>Comentários

O método define o membro da estrutura [NMDATETIMECHANGE](/windows/win32/api/commctrl/ns-commctrl-nmdatetimechange) dwFlags para indicar se o seletor de data e hora está definido como uma data e hora. Se o valor for igual a GDT_NONE, o controle será `no date` definido como status e usará o estilo DTS_SHOWNONE. Se o valor retornado for igual a GDT_VALID, a hora do sistema será armazenada com êxito no local de destino.

##  <a name="gettimeall"></a>  CMFCToolBarDateTimeCtrl::GetTimeAll

Retorna o tempo selecionado pelo usuário do botão de controle de seletor de tempo que tem uma ID de comando especificada.

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
no Especifica a ID de comando de um botão da barra de ferramentas.

*timeDest*<br/>
fora Na primeira sobrecarga, um objeto de [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que receberá as informações de hora do sistema. Na segunda sobrecarga, um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que receberá as informações de hora do sistema.

*pTimeDest*<br/>
fora Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) para receber as informações de hora do sistema. Não deve ser nulo.

### <a name="return-value"></a>Valor de retorno

Se a estrutura não puder localizar um botão da barra de ferramentas que corresponda à ID de comando *uiCmd*, o valor de retorno será zero na primeira sobrecarga e GDT_NONE nas outras sobrecargas. Se o botão da barra de ferramentas for encontrado, o valor de retorno será o mesmo que o valor de retorno de uma chamada para [CMFCToolBarDateTimeCtrl:: getTime](#gettime) nesse botão. Um valor de retorno de zero ou GDT_NONE pode ocorrer quando o botão é encontrado, o que indica que a `GetTime` chamada para não retornou uma data válida por algum outro motivo.

### <a name="remarks"></a>Comentários

Esse método procura um botão da barra de ferramentas que tenha a ID de comando especificada e chama o método [CMFCToolBarDateTimeCtrl:: getTime](#gettime) nesse botão.

##  <a name="havehotborder"></a>  CMFCToolBarDateTimeCtrl::HaveHotBorder

Determina se uma borda do botão é exibida quando um usuário seleciona o botão.

```
virtual BOOL HaveHotBorder() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se um botão exibir sua borda quando selecionado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método retornará um valor diferente de zero se o controle estiver visível.

##  <a name="notifycommand"></a>CMFCToolBarDateTimeCtrl::NotifyCommand

Especifica se o botão processa a mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) .

```
virtual BOOL NotifyCommand(int iNotifyCode);
```

### <a name="parameters"></a>Parâmetros

*iNotifyCode*<br/>
no A mensagem de notificação associada ao comando.

### <a name="return-value"></a>Valor de retorno

TRUE se o botão processar a mensagem WM_COMMAND ou FALSE para indicar que a mensagem deve ser tratada pela barra de ferramentas pai.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando está prestes a enviar uma mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) para a janela pai.

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: NotifyCommand](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand)) processando a notificação [DTN_DATETIMECHANGE](/windows/win32/Controls/dtn-datetimechange) . Ele atualiza o status de tempo interno e atualiza a propriedade time de `CMFCToolBarDateTimeCtrl` todos os objetos com a mesma ID de comando.

##  <a name="onaddtocustomizepage"></a>  CMFCToolBarDateTimeCtrl::OnAddToCustomizePage

Chamado pelo Framework quando o botão é adicionado a uma caixa de diálogo **Personalizar** .

```
virtual void OnAddToCustomizePage();
```

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base, [CMFCToolBarButton:: OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage), copiando as propriedades do primeiro controle de data e hora em qualquer barra de ferramentas que tenha a mesma ID de comando que esse objeto. Esse método não fará nada se nenhuma barra de ferramentas tiver um controle de data e hora que tenha a mesma ID de comando que esse objeto.

Para obter mais informações sobre a caixa de diálogo **Personalizar** , consulte [Classe CMFCToolBarsCustomizeDialog](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).

##  <a name="onchangeparentwnd"></a>  CMFCToolBarDateTimeCtrl::OnChangeParentWnd

Chamado pelo Framework quando o botão é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no A nova janela pai.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base ( [CMFCToolBarButton:: OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)) recriando o `CMFCToolBarDateTimeCtrlImpl` objeto interno.

##  <a name="onclick"></a>  CMFCToolBarDateTimeCtrl::OnClick

Chamado pelo Framework quando o usuário clica no controle.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
no Não utilizado.

*bDelay*<br/>
no Não utilizado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o botão processar a mensagem de clique; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base, [CMFCToolBarButton:: OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick), retornando um valor diferente de zero `CMFCToolBarDateTimeCtrlImpl` se o objeto interno estiver visível.

##  <a name="onctlcolor"></a>  CMFCToolBarDateTimeCtrl::OnCtlColor

Chamado pelo Framework quando a barra de ferramentas pai manipula uma mensagem WM_CTLCOLOR.

```
virtual HBRUSH OnCtlColor(
    CDC* pDC,
    UINT nCtlColor);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no O contexto do dispositivo que exibe o botão.

*nCtlColor*<br/>
no Não utilizado.

### <a name="return-value"></a>Valor de retorno

Um identificador para o pincel global que a estrutura usa para pintar o plano de fundo do botão.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação da classe base, [CMFCToolBarButton:: OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor), definindo o texto e as cores de plano de fundo do contexto do dispositivo fornecido para o texto global e as cores do plano de fundo, respectivamente.

Para obter mais informações sobre as opções globais disponíveis para seu aplicativo, consulte [Estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).

##  <a name="onglobalfontschanged"></a>  CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged

Chamado pelo Framework quando a fonte global é alterada.

```
virtual void OnGlobalFontsChanged();
```

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged)) alterando a fonte do controle para a da fonte global.

Para obter mais informações sobre as opções globais disponíveis para seu aplicativo, consulte [Estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md).

##  <a name="onmove"></a>  CMFCToolBarDateTimeCtrl::OnMove

Chamado pelo Framework quando a barra de ferramentas pai é movida.

```
virtual void OnMove();
```

### <a name="remarks"></a>Comentários

Esse método substitui a implementação de classe padrão ( [CMFCToolBarButton:: OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove)) atualizando a posição do objeto `CMFCToolBarDateTimeCtrlImpl` interno.

##  <a name="onshow"></a>  CMFCToolBarDateTimeCtrl::OnShow

Chamado pelo Framework quando o botão fica visível ou invisível.

```
virtual void OnShow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*bShow*<br/>
no Especifica se o botão está visível. Se esse parâmetro for TRUE, o botão ficará visível. Caso contrário, o botão não estará visível.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow)) exibindo o botão se *bShow* for true. Caso contrário, esse método ocultará o botão.

##  <a name="onsize"></a>  CMFCToolBarDateTimeCtrl::OnSize

Chamado pelo Framework quando a barra de ferramentas pai altera seu tamanho ou posição e essa alteração faz com que o botão mude de tamanho.

```
virtual void OnSize(int iSize);
```

### <a name="parameters"></a>Parâmetros

*iSize*<br/>
no A nova largura do botão, em pixels.

### <a name="remarks"></a>Comentários

Esse método substitui a implementação de classe padrão ( [CMFCToolBarButton:: OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize)) atualizando o tamanho e a posição do `CMFCToolBarDateTimeCtrlImpl` objeto interno.

##  <a name="onupdatetooltip"></a>  CMFCToolBarDateTimeCtrl::OnUpdateToolTip

Chamado pelo Framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta.

```
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,
    int iButtonIndex,
    CToolTipCtrl& wndToolTip,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
no A janela pai.

*iButtonIndex*<br/>
no O índice de base zero do botão na coleção de botões pai.

*wndToolTip*<br/>
no O controle que exibe o texto da dica de ferramenta.

*str*<br/>
fora Um `CString` objeto que recebe o texto da dica de ferramenta atualizado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o método atualizar o texto da dica de ferramenta; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método estende a implementação da classe base ( [CMFCToolBarButton:: OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip)) exibindo o texto da dica de ferramenta que está associado ao botão. Se o botão não for encaixado horizontalmente, esse método não fará nada e retornará FALSE.

##  <a name="settime"></a>  CMFCToolBarDateTimeCtrl::SetTime

Define a data e a hora no controle seletor de tempo.

```
BOOL SetTime(const COleDateTime& timeNew);
BOOL SetTime(const CTime* timeNew);
BOOL SetTime(LPSYSTEMTIME pTimeNew=NULL);
```

### <a name="parameters"></a>Parâmetros

*timeNew*<br/>
no Na primeira versão, uma referência a um objeto de [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que contém a hora em que o controle será definido. Na segunda versão, um ponteiro para um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém a hora em que o controle será definido.

*pTimeNew*<br/>
no Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a hora até a qual o controle será definido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Define a hora em um controle de seletor de data e hora chamando [CDateTimeCtrl:: SetTime](../../mfc/reference/cdatetimectrl-class.md#settime).

##  <a name="settimeall"></a>CMFCToolBarDateTimeCtrl::SetTimeAll

Define a data e a hora em todas as instâncias do controle de seletor de tempo que têm uma ID de comando especificada.

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
no Especifica a ID de comando de um botão da barra de ferramentas.

*timeNew*<br/>
no Na primeira versão, um objeto de [classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que contém a hora em que o controle será definido. Na segunda versão, um ponteiro para um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém a hora em que o controle será definido.

*pTimeNew*<br/>
no Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a hora até a qual o controle será definido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Procura um botão da barra de ferramentas com a ID de comando especificada e define a hora em um controle seletor de data e hora chamando [CMFCToolBarDateTimeCtrl:: SetTime](#settime).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Passo a passo: colocar controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
