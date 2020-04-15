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
ms.openlocfilehash: 9aebd55f19a6687554d8d8378ef84ed5932025a2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372169"
---
# <a name="cmfctoolbardatetimectrl-class"></a>Classe CMFCToolBarDateTimeCtrl

Um botão de barra de ferramentas que contém um controle de seleção de data e hora.

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
|[CMFCToolBarDateTimeCtrl::CanBeStretched](#canbestretched)|Especifica se um usuário pode esticar o botão durante a personalização. (Substitui [cmfctoolbarbutton::CanBeStretched](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched).)|
|[CMFCToolBarDateTimeCtrl::CopyFrom](#copyfrom)|Copia as propriedades de outro botão de barra de ferramentas para o botão atual. (Substitui [cmfctoolbarButton::CopyFrom](../../mfc/reference/cmfctoolbarbutton-class.md#copyfrom).)|
|`CMFCToolBarDateTimeCtrl::DuplicateData`|Reservado para uso futuro.|
|[CMFCToolBarbutton::ExportToMenuButton](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)|Copia o texto do botão da barra de ferramentas para um menu.|
|`CMFCToolBarDateTimeCtrl::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCToolBarDateTimeCtrl::GetByCmd](#getbycmd)|Recupera o `CMFCToolBarDateTimeCtrl` primeiro objeto no aplicativo que tem o ID de comando especificado.|
|[CMFCToolBarDateTimeCtrl::GetDateTimeCtrl](#getdatetimectrl)|Retorna um ponteiro para o controle de data e hora do seletor.|
|[CMFCToolBarDateTimeCtrl::GetHwnd](#gethwnd)|Recupera a alça da janela associada ao botão da barra de ferramentas. (Substitui [cmfctoolbarbutton::GetHwnd](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd).)|
|`CMFCToolBarDateTimeCtrl::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCToolBarDateTimeCtrl::GetTime](#gettime)|Obtém a hora selecionada a partir de um controle de seleção de data e hora e coloca-a em uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) especificada.|
|[CMFCToolBarDateTimeCtrl::GetTimeAll](#gettimeall)|Retorna o tempo selecionado do botão de controle do seletor de tempo que tem um ID de comando especificado.|
|[CMFCToolBarDateTimeCtrl::HaveHotBorder](#havehotborder)|Determina se uma borda do botão é exibida quando um usuário seleciona o botão. (Substitui [cmfctoolbarButton::HaveHotBorder](../../mfc/reference/cmfctoolbarbutton-class.md#havehotborder).)|
|[CMFCToolBarDateTimeCtrl::Notificarcomando](#notifycommand)|Especifica se o botão processa a [mensagem WM_COMMAND.](/windows/win32/menurc/wm-command) (Substitui [cmfcToolBarButton::Notificarcomando](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand).)|
|[CMFCToolBarDateTimeCtrl::OnAddToCustomPage](#onaddtocustomizepage)|Chamado pela estrutura quando o botão é adicionado a uma caixa de diálogo **Personalizar.** (Substitui [cmfcToolBarButton::OnAddToCustomPage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage).)|
|`CMFCToolBarDateTimeCtrl::OnCalculateSize`|Chamado pela estrutura para calcular o tamanho do botão para o contexto do dispositivo especificado e o estado de acoplamento. (Substitui [cmfcToolBarButton::OnCalculateSize](../../mfc/reference/cmfctoolbarbutton-class.md#oncalculatesize).)|
|[CMFCToolBarDateTimeCtrl::OnChangeParentWnd](#onchangeparentwnd)|Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas. (Substitui [cmfctoolbarButton::OnChangeParentWnd](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd).)|
|[CMFCToolBarDateTimeCtrl::OnClick](#onclick)|Chamado pela estrutura quando o usuário clica no controle. (Substitui [cmfctoolbarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick).)|
|[CMFCToolBarDateTimeCtrl::OnCtlColor](#onctlcolor)|Chamado pela estrutura quando a barra de ferramentas dos pais lida com uma mensagem WM_CTLCOLOR. (Substitui [cmfctoolbarButton::OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor).)|
|`CMFCToolBarDateTimeCtrl::OnDraw`|Chamado pela estrutura para desenhar o botão usando os estilos e opções especificados. (Substitui [cmfctoolbarButton::OnDraw](../../mfc/reference/cmfctoolbarbutton-class.md#ondraw).)|
|`CMFCToolBarDateTimeCtrl::OnDrawOnCustomizeList`|Chamado pela estrutura para desenhar o botão no painel **Comandos** da caixa de diálogo **Personalizar.** (Substitui [cmfctoolbarButton::OnDrawOnCustomizeList](../../mfc/reference/cmfctoolbarbutton-class.md#ondrawoncustomizelist).)|
|[CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged](#onglobalfontschanged)|Chamado pelo framework quando a fonte global foi alterada. (Substitui [cmfctoolbarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged).)|
|[CMFCToolBarDateTimeCtrl::OnMove](#onmove)|Chamada pela estrutura quando a barra de ferramentas dos pais se move. (Substitui [cmfctoolbarButton::OnMove](../../mfc/reference/cmfctoolbarbutton-class.md#onmove).)|
|[CMFCToolBarDateTimeCtrl::OnShow](#onshow)|Chamado pela estrutura quando o botão se torna visível ou invisível. (Substitui [cmfctoolbarbutton::OnShow](../../mfc/reference/cmfctoolbarbutton-class.md#onshow).)|
|`CMFCToolBarDateTimeCtrl::OnSize`|Chamada pela estrutura quando a barra de ferramentas pai muda seu tamanho ou posição e essa alteração faz com que o botão mude de tamanho. (Substitui [cmfcToolbarButton::OnSize](../../mfc/reference/cmfctoolbarbutton-class.md#onsize).)|
|[CMFCToolBarDateTimeCtrl::OnUpdateToolTip](#onupdatetooltip)|Chamada pela framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta. (Substitui [cmfctoolbarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip).)|
|`CMFCToolBarDateTimeCtrl::Serialize`|Lê esse objeto de um arquivo ou grava-o em um arquivo(Substitui [cmfcToolBarButton::Serialize](../../mfc/reference/cmfctoolbarbutton-class.md#serialize).)|
|`CMFCToolBarDateTimeCtrl::SetStyle`|Define o estilo do botão de barra de ferramentas. (Substitui [cmfctoolbarButton::SetStyle](../../mfc/reference/cmfctoolbarbutton-class.md#setstyle).)|
|[CMFCToolBarDateTimeCtrl::SetTime](#settime)|Define a hora e a data no controle do seletor de tempo.|
|[CMFCToolBarDateTimeCtrl::SetTimeAll](#settimeall)|Define a hora e a data em todas as instâncias do controle do seletor de tempo que possuem um ID de comando especificado.|

## <a name="remarks"></a>Comentários

Para obter um exemplo de como usar um controle de seleção de datas e horas, consulte o projeto de amostra ToolbarDateTimePicker. Para obter informações sobre como adicionar botões de controle às barras de ferramentas, consulte [Passo a Passo: Colocando controles nas barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfctoolbarbutton](../../mfc/reference/cmfctoolbarbutton-class.md)

[Cmfctoolbardatetimectrl](../../mfc/reference/cmfctoolbardatetimectrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbardatectrl.h

## <a name="cmfctoolbardatetimectrlcanbestretched"></a><a name="canbestretched"></a>CMFCToolBarDateTimeCtrl::CanBeStretched

Especifica se um usuário pode esticar o botão durante a personalização.

```
virtual BOOL CanBeStretched() const;
```

### <a name="return-value"></a>Valor retornado

Este método retorna TRUE.

### <a name="remarks"></a>Comentários

Por padrão, a estrutura não permite que o usuário estique um botão de barra de ferramentas durante a personalização. Este método estende a implementação da classe base [(CMFCToolBarButton::CanBeStretched)](../../mfc/reference/cmfctoolbarbutton-class.md#canbestretched)permitindo que o usuário estique um botão de barra de ferramentas de data e hora durante a personalização.

## <a name="cmfctoolbardatetimectrlcmfctoolbardatetimectrl"></a><a name="cmfctoolbardatetimectrl"></a>CMFCToolBarDateTimeCtrl::CMFCToolBarDateTimeCtrl

Cria e inicializa um objeto [CMFCToolBarDateCtrl.](../../mfc/reference/cmfctoolbardatetimectrl-class.md)

```
CMFCToolBarDateTimeCtrl(
    UINT uiID,
    int iImage,
    DWORD dwStyle=0,
    int iWidth=0);
```

### <a name="parameters"></a>Parâmetros

*Uiid*<br/>
[em] A id de controle.

*Iimage*<br/>
[em] O índice da imagem no objeto `CMFCToolBarImages` da barra de ferramentas.

*Dwstyle*<br/>
[em] O estilo `CMFCToolBarDateTimeCtrlImpl` da janela que é criado quando um usuário clica no botão.

*iWidth*<br/>
[em] A largura do controle, em pixels.

### <a name="remarks"></a>Comentários

Este objeto é inicializado para a data e hora do sistema. O estilo de `CMFCToolBarDateTimeCtrlImpl` janela do objeto interno inclui o parâmetro *dwStyle* e os estilos WS_CHILD e WS_VISIBLE. Você não pode alterar `CMFCToolBarDateTimeCtrl::SetStyle`esses estilos usando . Use `SetStyle` para mudar o `CMFCToolBarDateTimeCtrl` estilo do controle.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCToolBarDateTimeCtrl` construir um objeto da classe. Este trecho de código faz parte da amostra de [Seletor de Data de Data da barra](../../overview/visual-cpp-samples.md)de ferramentas .

[!code-cpp[NVC_MFC_ToolbarDateTimePicker#1](../../mfc/reference/codesnippet/cpp/cmfctoolbardatetimectrl-class_1.cpp)]

## <a name="cmfctoolbardatetimectrlcopyfrom"></a><a name="copyfrom"></a>CMFCToolBarDateTimeCtrl::CopyFrom

Copia as propriedades de outro botão de barra de ferramentas para o botão atual.

```
virtual void CopyFrom(const CMFCToolBarButton& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
[em] Uma referência ao botão de origem a partir do qual copiar.

### <a name="remarks"></a>Comentários

Chame este método para copiar outro botão de barra de ferramentas para este botão de barra de ferramentas. *src* deve ser `CMFCToolBarDateTimeCtrl`do tipo .

## <a name="cmfctoolbardatetimectrlexporttomenubutton"></a><a name="exporttomenubutton"></a>CMFCToolBarDateTimeCtrl::ExportToMenuButton

Copia o texto do botão da barra de ferramentas para um menu.

```
virtual BOOL ExportToMenuButton(CMFCToolBarMenuButton& menuButton) const;
```

### <a name="parameters"></a>Parâmetros

*menuButton*<br/>
[em] Uma referência ao botão de menu de destino.

### <a name="return-value"></a>Valor retornado

Este método retorna TRUE.

### <a name="remarks"></a>Comentários

Este método substitui a implementação da classe base [(CMFCToolBarButton::ExportToMenuButton)](../../mfc/reference/cmfctoolbarbutton-class.md#exporttomenubutton)carregando o recurso string associado ao ID de comando do controle. Para obter mais informações sobre os recursos de seqüência, consulte [CStringT::LoadString](../../atl-mfc-shared/reference/cstringt-class.md#loadstring).

## <a name="cmfctoolbardatetimectrlgetbycmd"></a><a name="getbycmd"></a>CMFCToolBarDateTimeCtrl::GetByCmd

Recupera o `CMFCToolBarDateTimeCtrl` primeiro objeto no aplicativo que tem o ID de comando especificado.

```
static CMFCToolBarDateTimeCtrl* __stdcall GetByCmd(UINT uiCmd);
```

### <a name="parameters"></a>Parâmetros

*Uicmd*<br/>
[em] O id de comando do botão para recuperar.

### <a name="return-value"></a>Valor retornado

O `CMFCToolBarDateTimeCtrl` primeiro objeto no aplicativo que tem o ID `CMFCToolBarDateTimeCtrl` de comando especificado ou NULL se nenhum objeto tiver o ID de comando especificado.

### <a name="remarks"></a>Comentários

Este método de utilidade compartilhada é usado por métodos como [CMFCToolBarDateTimeCtrl::SetTimeAll](#settimeall) e [CMFCToolBarDateDateCtrl::GetTimeAll](#gettimeall) para definir ou obter a hora e a data de todas as instâncias do controle do seletor de tempo que têm um ID de comando especificado.

## <a name="cmfctoolbardatetimectrlgetdatetimectrl"></a><a name="getdatetimectrl"></a>CMFCToolBarDateTimeCtrl::GetDateTimeCtrl

Retorna um ponteiro para o controle de data e hora do seletor.

```
CDateTimeCtrl* GetDateTimeCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para controle de seleção de data e hora; ou NULO se o controle não existir.

### <a name="remarks"></a>Comentários

A `CMFCToolBarDateTimeCtrl` classe inicializa `m_pWndDateTime` o membro de `CMFCToolBarDateTimeCtrl` dados quando você insere um objeto em uma barra de ferramentas.

## <a name="cmfctoolbardatetimectrlgethwnd"></a><a name="gethwnd"></a>CMFCToolBarDateTimeCtrl::GetHwnd

Recupera a alça da janela associada ao botão da barra de ferramentas.

```
virtual HWND GetHwnd();
```

### <a name="return-value"></a>Valor retornado

A alça da janela associada ao botão barra de ferramentas de data e hora.

### <a name="remarks"></a>Comentários

Este método substitui o [método CMFCToolBarButton::GetHwnd.](../../mfc/reference/cmfctoolbarbutton-class.md#gethwnd)

## <a name="cmfctoolbardatetimectrlgettime"></a><a name="gettime"></a>CMFCToolBarDateTimeCtrl::GetTime

Obtém o tempo selecionado a partir do controle de seleção de data e hora associados e coloca-o em uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) especificada

```
BOOL GetTime(COleDateTime& timeDest) const;
DWORD GetTime(CTime& timeDest) const;
DWORD GetTime(LPSYSTEMTIME pTimeDest) const;
```

### <a name="parameters"></a>Parâmetros

*tempoDest*<br/>
[fora] Na primeira sobrecarga, um objeto [COleDateTime Class](../../atl-mfc-shared/reference/coledatetime-class.md) que receberá as informações de tempo do sistema. Na segunda sobrecarga, um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que receberá as informações de tempo do sistema.

*pTimeDest*<br/>
[fora] Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) para receber as informações de tempo do sistema. Não deve ser NULO.

### <a name="return-value"></a>Valor retornado

Na primeira sobrecarga, não zero se o tempo for gravado com sucesso no objeto [COleDateTime Class;](../../atl-mfc-shared/reference/coledatetime-class.md) caso contrário, 0. Na segunda e terceira sobrecargas, o valor de retorno é um DWORD que é igual ao membro dwFlag que foi definido na estrutura [NMDATETIMECHANGE.](/windows/win32/api/commctrl/ns-commctrl-nmdatetimechange)

### <a name="remarks"></a>Comentários

O método define o membro da estrutura [NMDATETIMECHANGE](/windows/win32/api/commctrl/ns-commctrl-nmdatetimechange) dwFlags para indicar se o seletor de data e hora está definido como data e hora. Se o valor for igual a `no date` GDT_NONE, o controle é definido como status e usa o estilo DTS_SHOWNONE. Se o valor retornado for igual a GDT_VALID, o tempo do sistema será armazenado com sucesso no local de destino.

## <a name="cmfctoolbardatetimectrlgettimeall"></a><a name="gettimeall"></a>CMFCToolBarDateTimeCtrl::GetTimeAll

Retorna o tempo selecionado pelo usuário a partir do botão de controle do seletor de tempo que tem um ID de comando especificado.

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

*Uicmd*<br/>
[em] Especifica o ID de comando de um botão de barra de ferramentas.

*tempoDest*<br/>
[fora] Na primeira sobrecarga, um objeto [COleDateTime Class](../../atl-mfc-shared/reference/coledatetime-class.md) que receberá as informações de tempo do sistema. Na segunda sobrecarga, um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que receberá as informações de tempo do sistema.

*pTimeDest*<br/>
[fora] Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) para receber as informações de tempo do sistema. Não deve ser NULO.

### <a name="return-value"></a>Valor retornado

Se a estrutura não conseguir encontrar um botão de barra de ferramentas que corresponda ao comando ID *uiCmd,* o valor de retorno é zero na primeira sobrecarga e GDT_NONE nas outras sobrecargas. Se o botão da barra de ferramentas for encontrado, o valor de retorno será o mesmo que o valor de retorno de uma chamada para [CMFCToolBarDateCtrl::GetTime](#gettime) nesse botão. Um valor de retorno de zero ou GDT_NONE pode ocorrer quando `GetTime` o botão é encontrado, o que indica que a chamada para não retornou uma data válida por algum outro motivo.

### <a name="remarks"></a>Comentários

Este método procura um botão de barra de ferramentas que tem o ID de comando especificado e chama [CMFCToolBarDateCtrl::GetTime](#gettime) método nesse botão.

## <a name="cmfctoolbardatetimectrlhavehotborder"></a><a name="havehotborder"></a>CMFCToolBarDateTimeCtrl::HaveHotBorder

Determina se uma borda do botão é exibida quando um usuário seleciona o botão.

```
virtual BOOL HaveHotBorder() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se um botão exibir sua borda quando selecionado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método retorna um valor não zero se o controle estiver visível.

## <a name="cmfctoolbardatetimectrlnotifycommand"></a><a name="notifycommand"></a>CMFCToolBarDateTimeCtrl::Notificarcomando

Especifica se o botão processa a [mensagem WM_COMMAND.](/windows/win32/menurc/wm-command)

```
virtual BOOL NotifyCommand(int iNotifyCode);
```

### <a name="parameters"></a>Parâmetros

*iNotifyCode*<br/>
[em] A mensagem de notificação que está associada ao comando.

### <a name="return-value"></a>Valor retornado

TRUE se o botão processa a mensagem WM_COMMAND ou FALSE para indicar que a mensagem deve ser tratada pela barra de ferramentas pai.

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando ele está prestes a enviar uma mensagem [WM_COMMAND](/windows/win32/menurc/wm-command) para a janela pai.

Este método amplia a implementação da classe base [(CMFCToolBarButton::NotifyCommand)](../../mfc/reference/cmfctoolbarbutton-class.md#notifycommand)processando a notificação [DTN_DATETIMECHANGE.](/windows/win32/Controls/dtn-datetimechange) Ele atualiza o status do tempo interno e `CMFCToolBarDateTimeCtrl` atualiza a propriedade de tempo de todos os objetos com o mesmo ID de comando.

## <a name="cmfctoolbardatetimectrlonaddtocustomizepage"></a><a name="onaddtocustomizepage"></a>CMFCToolBarDateTimeCtrl::OnAddToCustomPage

Chamado pela estrutura quando o botão é adicionado a uma caixa de diálogo **Personalizar.**

```
virtual void OnAddToCustomizePage();
```

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base, [CMFCToolBarButton::OnAddToCustomizePage](../../mfc/reference/cmfctoolbarbutton-class.md#onaddtocustomizepage), copiando as propriedades do primeiro controle de data e hora em qualquer barra de ferramentas que tenha o mesmo ID de comando que este objeto. Este método não faz nada se nenhuma barra de ferramentas tiver um controle de data e hora que tenha o mesmo ID de comando que este objeto.

Para obter mais informações sobre a caixa de diálogo **Personalizar,** consulte [CMFCToolBarsPersonalizeSala de diálogo](../../mfc/reference/cmfctoolbarscustomizedialog-class.md).

## <a name="cmfctoolbardatetimectrlonchangeparentwnd"></a><a name="onchangeparentwnd"></a>CMFCToolBarDateTimeCtrl::OnChangeParentWnd

Chamado pela estrutura quando o botão é inserido em uma nova barra de ferramentas.

```
virtual void OnChangeParentWnd(CWnd* pWndParent);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] A nova janela dos pais.

### <a name="remarks"></a>Comentários

Este método substitui a implementação da classe base [(CMFCToolBarButton::OnChangeParentWnd)](../../mfc/reference/cmfctoolbarbutton-class.md#onchangeparentwnd)recriando o objeto interno. `CMFCToolBarDateTimeCtrlImpl`

## <a name="cmfctoolbardatetimectrlonclick"></a><a name="onclick"></a>CMFCToolBarDateTimeCtrl::OnClick

Chamado pela estrutura quando o usuário clica no controle.

```
virtual BOOL OnClick(
    CWnd* pWnd,
    BOOL bDelay = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] Utilizadas.

*bAtraso*<br/>
[em] Utilizadas.

### <a name="return-value"></a>Valor retornado

Não zero se o botão processa a mensagem de clique; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método substitui a implementação da classe base, [CMFCToolBarButton::OnClick](../../mfc/reference/cmfctoolbarbutton-class.md#onclick), `CMFCToolBarDateTimeCtrlImpl` retornando um valor não zero se o objeto interno estiver visível.

## <a name="cmfctoolbardatetimectrlonctlcolor"></a><a name="onctlcolor"></a>CMFCToolBarDateTimeCtrl::OnCtlColor

Chamado pela estrutura quando a barra de ferramentas dos pais lida com uma mensagem WM_CTLCOLOR.

```
virtual HBRUSH OnCtlColor(
    CDC* pDC,
    UINT nCtlColor);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] O contexto do dispositivo que exibe o botão.

*nCtlColor*<br/>
[em] Utilizadas.

### <a name="return-value"></a>Valor retornado

Uma alça para o pincel global que a estrutura usa para pintar o fundo do botão.

### <a name="remarks"></a>Comentários

Este método substitui a implementação da classe base, [CMFCToolBarButton::OnCtlColor](../../mfc/reference/cmfctoolbarbutton-class.md#onctlcolor), definindo as cores de texto e de fundo do contexto do dispositivo fornecido para as cores globais de texto e de fundo, respectivamente.

Para obter mais informações sobre as opções globais disponíveis para o seu aplicativo, consulte [AFX_GLOBAL_DATA Estrutura](../../mfc/reference/afx-global-data-structure.md).

## <a name="cmfctoolbardatetimectrlonglobalfontschanged"></a><a name="onglobalfontschanged"></a>CMFCToolBarDateTimeCtrl::OnGlobalFontsChanged

Chamado pelo framework quando a fonte global foi alterada.

```
virtual void OnGlobalFontsChanged();
```

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base [(CMFCToolBarButton::OnGlobalFontsChanged](../../mfc/reference/cmfctoolbarbutton-class.md#onglobalfontschanged)) alterando a fonte do controle para a da fonte global.

Para obter mais informações sobre as opções globais disponíveis para o seu aplicativo, consulte [AFX_GLOBAL_DATA Estrutura](../../mfc/reference/afx-global-data-structure.md).

## <a name="cmfctoolbardatetimectrlonmove"></a><a name="onmove"></a>CMFCToolBarDateTimeCtrl::OnMove

Chamada pela estrutura quando a barra de ferramentas dos pais se move.

```
virtual void OnMove();
```

### <a name="remarks"></a>Comentários

Este método substitui a implementação de classe padrão [(CMFCToolBarButton::OnMove)](../../mfc/reference/cmfctoolbarbutton-class.md#onmove)atualizando a posição do objeto interno. `CMFCToolBarDateTimeCtrlImpl`

## <a name="cmfctoolbardatetimectrlonshow"></a><a name="onshow"></a>CMFCToolBarDateTimeCtrl::OnShow

Chamado pela estrutura quando o botão se torna visível ou invisível.

```
virtual void OnShow(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
[em] Especifica se o botão está visível. Se este parâmetro for TRUE, o botão será visível. Caso contrário, o botão não é visível.

### <a name="remarks"></a>Comentários

Este método estende a implementação da classe base [(CMFCToolBarButton::OnShow)](../../mfc/reference/cmfctoolbarbutton-class.md#onshow)exibindo o botão se *bShow* for TRUE. Caso contrário, este método esconde o botão.

## <a name="cmfctoolbardatetimectrlonsize"></a><a name="onsize"></a>CMFCToolBarDateTimeCtrl::OnSize

Chamada pela estrutura quando a barra de ferramentas pai muda seu tamanho ou posição e essa alteração faz com que o botão mude de tamanho.

```
virtual void OnSize(int iSize);
```

### <a name="parameters"></a>Parâmetros

*iSize*<br/>
[em] A nova largura do botão, em pixels.

### <a name="remarks"></a>Comentários

Este método substitui a implementação de classe padrão [(CMFCToolBarButton::OnSize)](../../mfc/reference/cmfctoolbarbutton-class.md#onsize)atualizando o tamanho e a posição do objeto interno. `CMFCToolBarDateTimeCtrlImpl`

## <a name="cmfctoolbardatetimectrlonupdatetooltip"></a><a name="onupdatetooltip"></a>CMFCToolBarDateTimeCtrl::OnUpdateToolTip

Chamada pela framework quando a barra de ferramentas pai atualiza seu texto de dica de ferramenta.

```
virtual BOOL OnUpdateToolTip(
    CWnd* pWndParent,
    int iButtonIndex,
    CToolTipCtrl& wndToolTip,
    CString& str);
```

### <a name="parameters"></a>Parâmetros

*pWndParent*<br/>
[em] A janela dos pais.

*iButtonIndex*<br/>
[em] O índice baseado em zero do botão na coleção de botões pai.

*wndToolTip*<br/>
[em] O controle que exibe o texto da dica de ferramenta.

*Str*<br/>
[fora] Um `CString` objeto que recebe o texto atualizado da dica de ferramenta.

### <a name="return-value"></a>Valor retornado

Não zero se o método atualizar o texto da dica de ferramenta; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método amplia a implementação da classe base [(CMFCToolBarButton::OnUpdateToolTip](../../mfc/reference/cmfctoolbarbutton-class.md#onupdatetooltip)) exibindo o texto da dica de ferramenta que está associado ao botão. Se o botão não estiver encaixado horizontalmente, este método não faz nada e retorna FALSO.

## <a name="cmfctoolbardatetimectrlsettime"></a><a name="settime"></a>CMFCToolBarDateTimeCtrl::SetTime

Define a hora e a data no controle do seletor de tempo.

```
BOOL SetTime(const COleDateTime& timeNew);
BOOL SetTime(const CTime* timeNew);
BOOL SetTime(LPSYSTEMTIME pTimeNew=NULL);
```

### <a name="parameters"></a>Parâmetros

*timeNew*<br/>
[em] Na primeira versão, uma referência a um objeto [COleDateTime Class](../../atl-mfc-shared/reference/coledatetime-class.md) que contém o tempo para o qual o controle será definido. Na segunda versão, um ponteiro para um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém o tempo para o qual o controle será definido.

*pTimeNew*<br/>
[em] Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém o tempo para o qual o controle será definido.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Define a hora em um controle de seleção de data e hora chamando [CDateTimeCtrl::SetTime](../../mfc/reference/cdatetimectrl-class.md#settime).

## <a name="cmfctoolbardatetimectrlsettimeall"></a><a name="settimeall"></a>CMFCToolBarDateTimeCtrl::SetTimeAll

Define a hora e a data em todas as instâncias do controle do seletor de tempo que possuem um ID de comando especificado.

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

*Uicmd*<br/>
[em] Especifica o ID de comando de um botão de barra de ferramentas.

*timeNew*<br/>
[em] Na primeira versão, um objeto [COleDateTime Class](../../atl-mfc-shared/reference/coledatetime-class.md) que contém o tempo para o qual o controle será definido. Na segunda versão, um ponteiro para um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém o tempo para o qual o controle será definido.

*pTimeNew*<br/>
[em] Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém o tempo para o qual o controle será definido.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Procura um botão de barra de ferramentas com o ID de comando especificado e define a hora em um controle de seleção de data e hora, chamando [CMFCToolBarDateTimeCtrl::SetTime](#settime).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
