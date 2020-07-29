---
title: Rotinas de troca dos dados da caixa de diálogo padrão
ms.date: 11/04/2016
helpviewer_keywords:
- standard dialog, data exchange routines
ms.assetid: c6adb7f3-f9af-4cc5-a9ea-315c5b60ad1a
ms.openlocfilehash: 378cbba4787df843509d856b581b6986497983ef
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213990"
---
# <a name="standard-dialog-data-exchange-routines"></a>Rotinas de troca dos dados da caixa de diálogo padrão

Este tópico lista as rotinas de troca de dados de caixa de diálogo padrão (campo DDX) usadas para controles de caixa de diálogo comuns do MFC.

> [!NOTE]
> As rotinas de troca de dados de diálogo padrão são definidas no arquivo de cabeçalho afxdd_. h. No entanto, os aplicativos devem incluir afxwin. h.

### <a name="ddx-functions"></a>Funções campo DDX

|||
|-|-|
|[DDX_CBIndex](#ddx_cbindex)|Inicializa ou recupera o índice da seleção atual de um controle de caixa de combinação.|
|[DDX_CBString](#ddx_cbstring)|Inicializa ou recupera o conteúdo atual do campo de edição de um controle de caixa de combinação.|
|[DDX_CBStringExact](#ddx_cbstringexact)|Inicializa ou recupera o conteúdo atual do campo de edição de um controle de caixa de combinação.|
|[DDX_Check](#ddx_check)|Inicializa ou recupera o estado atual de um controle de caixa de seleção.|
|[DDX_Control](#ddx_control)|Subclasses de um determinado controle dentro de uma caixa de diálogo.|
|[DDX_DateTimeCtrl](#ddx_datetimectrl)|Inicializa ou recupera dados de data e/ou hora de um controle seletor de data e hora.|
|[DDX_IPAddress](#ddx_ipaddress)|Inicializa ou recupera o valor atual de um controle de endereço IP.|
|[DDX_LBIndex](#ddx_lbindex)|Inicializa ou recupera o índice da seleção atual de um controle de caixa de listagem.|
|[DDX_LBString](#ddx_lbstring)|Inicializa ou recupera a seleção atual em um controle de caixa de listagem.|
|[DDX_LBStringExact](#ddx_lbstringexact)|Inicializa ou recupera a seleção atual em um controle de caixa de listagem.|
|[DDX_ManagedControl](#ddx_managedcontrol)|Cria um controle .NET que corresponde à ID de recurso do controle.|
|[DDX_MonthCalCtrl](#ddx_monthcalctrl)|Inicializa ou recupera o valor atual de um controle de calendário mensal.|
|[DDX_Radio](#ddx_radio)|Inicializa ou recupera o índice baseado em 0 do controle Radio que está atualmente marcado em um grupo de controle de rádio.|
|[DDX_Scroll](#ddx_scroll)|Inicializa ou recupera a posição atual do Thumb de um controle de rolagem.|
|[DDX_Slider](#ddx_slider)|Inicializa ou recupera a posição atual do Thumb de um controle deslizante.|
|[DDX_Text](#ddx_text)|Inicializa ou recupera o valor atual de um controle de edição.|

## <a name="ddx_cbindex"></a><a name="ddx_cbindex"></a>DDX_CBIndex

A `DDX_CBIndex` função gerencia a transferência de **`int`** dados entre um controle de caixa de combinação em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um **`int`** membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_CBIndex(
    CDataExchange* pDX,
    int nIDC,
    int& index);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de caixa de combinação associada à propriedade de controle.

*index*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_CBIndex` é chamado, *índice* é definido como o índice da seleção atual da caixa de combinação. Se nenhum item for selecionado, o *índice* será definido como 0.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_cbstring"></a><a name="ddx_cbstring"></a>DDX_CBString

A `DDX_CBString` função gerencia a transferência de `CString` dados entre o controle de edição de um controle de caixa de combinação em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um `CString` membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_CBString(
    CDataExchange* pDX,
    int nIDC,
    CString& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de caixa de combinação associada à propriedade de controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_CBString` é chamado, o *valor* é definido como a seleção atual da caixa de combinação. Se nenhum item for selecionado, *valor* será definido como uma cadeia de caracteres de comprimento zero.

> [!NOTE]
> Se a caixa de combinação for uma caixa de listagem suspensa, o valor trocado será limitado a 255 caracteres.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_cbstringexact"></a><a name="ddx_cbstringexact"></a>DDX_CBStringExact

A `DDX_CBStringExact` função gerencia a transferência de `CString` dados entre o controle de edição de um controle de caixa de combinação em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um `CString` membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_CBStringExact(
    CDataExchange* pDX,
    int nIDC,
    CString& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de caixa de combinação associada à propriedade de controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_CBStringExact` é chamado, o *valor* é definido como a seleção atual da caixa de combinação. Se nenhum item for selecionado, *valor* será definido como uma cadeia de caracteres de comprimento zero.

> [!NOTE]
> Se a caixa de combinação for uma caixa de listagem suspensa, o valor trocado será limitado a 255 caracteres.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_check"></a><a name="ddx_check"></a>DDX_Check

A `DDX_Check` função gerencia a transferência de **`int`** dados entre um controle de caixa de seleção em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um **`int`** membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_Check(
    CDataExchange* pDX,
    int nIDC,
    int& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de caixa de seleção associada à propriedade de controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_Check` é chamado, o *valor* é definido como o estado atual do controle da caixa de seleção. Para obter uma lista dos possíveis valores de estado, consulte [BM_GETCHECK](/windows/win32/Controls/bm-getcheck) no SDK do Windows.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_control"></a><a name="ddx_control"></a>DDX_Control

A `DDX_Control` função subclasses o controle, especificado por *nIDC*, da caixa de diálogo, da exibição de formulário ou do objeto de exibição de controle.

```cpp
void AFXAPI DDX_Control(
    CDataExchange* pDX,
    int nIDC,
    CWnd& rControl);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) .

*nIDC*<br/>
A ID de recurso do controle a ser subclasse.

*rControl*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle relacionado ao controle especificado.

### <a name="remarks"></a>Comentários

O objeto *PDX* é fornecido pela estrutura quando a `DoDataExchange` função é chamada. Portanto, `DDX_Control` só deve ser chamado dentro de sua substituição de `DoDataExchange` .

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_datetimectrl"></a><a name="ddx_datetimectrl"></a>DDX_DateTimeCtrl

A `DDX_DateTimeCtrl` função gerencia a transferência de dados de data e/ou hora entre um controle seletor de data e hora ( [CDateTimeCtrl](../../mfc/reference/cdatetimectrl-class.md)) em uma caixa de diálogo ou objeto de exibição de formulário e um membro de dados [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) da caixa de diálogo ou do objeto de exibição de formulário.

```cpp
void AFXAPI DDX_DateTimeCtrl(
    CDataExchange* pDX,
    int nIDC,
    CTime& value);

void AFXAPI DDX_DateTimeCtrl(
    CDataExchange* pDX,
    int nIDC,
    COleDateTime& value);

void AFXAPI DDX_DateTimeCtrl(
    CDataExchange* pDX,
    int nIDC,
    CString& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção. Você não precisa excluir este objeto.

*nIDC*<br/>
A ID de recurso do controle de seletor de data e hora associado à variável de membro.

*value*<br/>
Nas duas primeiras versões, uma referência a uma `CTime` variável de `COleDateTime` membro, caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados. Na terceira versão, uma referência a um `CString` objeto de exibição de controle de membro de dados.

### <a name="remarks"></a>Comentários

Quando `DDX_DateTimeCtrl` é chamado, o *valor* é definido como o estado atual do controle do seletor de data e hora ou o controle é definido como *valor*, dependendo da direção da troca.

Na terceira versão acima, `DDX_DateTimeCtrl` o gerencia a transferência de `CString` dados entre um controle de data e hora e um membro de dados [CString](../../atl-mfc-shared/reference/cstringt-class.md) do objeto de exibição de controle. A cadeia de caracteres é formatada usando as regras da localidade atual para formatar datas e horas.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_managedcontrol"></a><a name="ddx_managedcontrol"></a>DDX_ManagedControl

Cria um controle .NET que corresponde à ID de recurso do controle.

### <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
void DDX_ManagedControl(
   CDataExchange* pDX,
   int nIDC,
   CWinFormsControl<T>& control );
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto de [classe CDataExchange](cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle associado à propriedade de controle.

*control*<br/>
Uma referência a um objeto de [classe CWinFormsControl](cwinformscontrol-class.md) .

### <a name="remarks"></a>Comentários

`DDX_ManagedControl`chama [CWinFormsControl:: CreateManagedControl](cwinformscontrol-class.md#createmanagedcontrol) para criar um controle que corresponda à ID de controle do recurso. Use `DDX_ManagedControl` para criar controles de IDs de recurso em [CDialog:: OnInitDialog](cdialog-class.md#oninitdialog). Para a troca de dados, você não precisa usar as funções campo DDX/DDV com controles Windows Forms.

Para obter mais informações, consulte [como: fazer a associação de dados campo DDX/DDV com Windows Forms](../../dotnet/how-to-do-ddx-ddv-data-binding-with-windows-forms.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms. h

## <a name="ddx_ipaddress"></a><a name="ddx_ipaddress"></a>DDX_IPAddress

A `DDX_IPAddress` função gerencia a transferência de dados entre um controle de endereço IP e um membro de dados do objeto de exibição de controle.

```cpp
void AFXAPI DDX_IPAddress(
    CDataExchange* pDX,
    int nIDC,
    DWORD& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de endereço IP associado à propriedade de controle.

*value*<br/>
Uma referência ao DWORD que contém o valor de quatro campos do controle de endereço IP. Os campos são preenchidos ou lidos da seguinte maneira.

|Campo|Bits que contém o valor do campo|
|-----------|-------------------------------------|
|3|0 a 7|
|2|8 a 15|
|1|16 a 23|
|0|24 a 31|

Use o [IPM_GETADDRESS](/windows/win32/Controls/ipm-getaddress) do Win32 para ler o valor ou use [IPM_SETADDRESS](/windows/win32/Controls/ipm-setaddress) para preencher o valor. Essas mensagens são descritas na SDK do Windows.

### <a name="remarks"></a>Comentários

Quando `DDX_IPAddress` é chamado, o *valor* é lido do controle de endereço IP, ou o *valor* é gravado no controle, dependendo da direção da troca.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_lbindex"></a><a name="ddx_lbindex"></a>DDX_LBIndex

A `DDX_LBIndex` função gerencia a transferência de **`int`** dados entre um controle de caixa de listagem em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um **`int`** membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_LBIndex(
    CDataExchange* pDX,
    int nIDC,
    int& index);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de caixa de listagem associada à propriedade de controle.

*index*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_LBIndex` é chamado, *índice* é definido como o índice da seleção atual da caixa de listagem. Se nenhum item for selecionado, o *índice* será definido como-1.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_lbstring"></a><a name="ddx_lbstring"></a>DDX_LBString

A `DDX_LBString` função gerencia a transferência de `CString` dados entre um controle de caixa de listagem em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um `CString` membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_LBString(
    CDataExchange* pDX,
    int nIDC,
    CString& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de caixa de listagem associada à propriedade de controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_LBString` é chamado para transferir dados para um controle de caixa de listagem, o primeiro item no controle cujo *valor* de início corresponde é selecionado. (Para corresponder ao item inteiro em vez de apenas um prefixo, use [DDX_LBStringExact](#ddx_lbstringexact).) Se não houver nenhuma correspondência, nenhum item será selecionado. A correspondência não diferencia maiúsculas de minúsculas.

Quando `DDX_LBString` é chamado para transferir dados de um controle de caixa de listagem, *Value* é definido como a seleção da caixa de listagem atual. Se nenhum item for selecionado, *valor* será definido como uma cadeia de caracteres de comprimento zero.

> [!NOTE]
> Se a caixa de listagem for uma caixa de listagem suspensa, o valor trocado será limitado a 255 caracteres.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_lbstringexact"></a><a name="ddx_lbstringexact"></a>DDX_LBStringExact

A `DDX_CBStringExact` função gerencia a transferência de `CString` dados entre o controle de edição de um controle de caixa de listagem em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um `CString` membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_LBStringExact(
    CDataExchange* pDX,
    int nIDC,
    CString& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de caixa de listagem associada à propriedade de controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_LBStringExact` é chamado para transferir dados para um controle de caixa de listagem, o primeiro item do controle que corresponde ao *valor* é selecionado. (Para corresponder apenas a um prefixo em vez de ao item inteiro, use [DDX_LBString](#ddx_lbstring).) Se não houver nenhuma correspondência, nenhum item será selecionado. A correspondência não diferencia maiúsculas de minúsculas.

Quando `DDX_CBStringExact` é chamado para transferir dados de um controle de caixa de listagem, *Value* é definido como a seleção da caixa de listagem atual. Se nenhum item for selecionado, *valor* será definido como uma cadeia de caracteres de comprimento zero.

> [!NOTE]
> Se a caixa de listagem for uma caixa de listagem suspensa, o valor trocado será limitado a 255 caracteres.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_monthcalctrl"></a><a name="ddx_monthcalctrl"></a>DDX_MonthCalCtrl

A `DDX_MonthCalCtrl` função gerencia a transferência de dados de data entre um controle de calendário mensal ( [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)) em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_MonthCalCtrl(
    CDataExchange* pDX,
    int nIDC,
    CTime& value);

void AFXAPI DDX_MonthCalCtrl(
    CDataExchange* pDX,
    int nIDC,
    COleDateTime& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção. Você não precisa excluir este objeto.

*nIDC*<br/>
A ID de recurso do controle de calendário de mês associada à variável de membro.

*value*<br/>
Uma referência a uma `CTime` `COleDateTime` variável de membro ou da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

> [!NOTE]
> O controle gerencia apenas um valor de data. Os campos de hora no objeto de hora são definidos para refletir a hora de criação da janela de controle ou qualquer hora definida no controle com uma chamada para `CMonthCalCtrl::SetCurSel` .

Quando `DDX_MonthCalCtrl` é chamado, o *valor* é definido como o estado atual do controle de calendário mensal.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_radio"></a><a name="ddx_radio"></a>DDX_Radio

A `DDX_Radio` função gerencia a transferência de **`int`** dados entre um grupo de controle de rádio em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um **`int`** membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle. O valor do **`int`** membro de dados é determinado de acordo com o botão de opção dentro do grupo selecionado.

```cpp
void AFXAPI DDX_Radio(
    CDataExchange* pDX,
    int nIDC,
    int& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do primeiro controle de opção no grupo.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_Radio` é chamado, o *valor* é definido como o estado atual do grupo de controle de rádio. O valor é definido como um índice baseado em 0 do controle de rádio selecionado no momento, ou-1 se nenhum controle de rádio estiver marcado.

Por exemplo, caso o primeiro botão de opção no grupo esteja marcado (o botão com WS_GROUP estilo) o valor do **`int`** membro é 0 e assim por diante.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_scroll"></a><a name="ddx_scroll"></a>DDX_Scroll

A `DDX_Scroll` função gerencia a transferência de **`int`** dados entre um controle de barra de rolagem em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um **`int`** membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_Scroll(
    CDataExchange* pDX,
    int nIDC,
    int& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de barra de rolagem associado à propriedade de controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_Scroll` é chamado, o *valor* é definido como a posição atual do Thumb do controle. Para obter mais informações sobre os valores associados à posição atual do Thumb do controle, consulte [GetScrollPos](/windows/win32/api/winuser/nf-winuser-getscrollpos) no SDK do Windows.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_slider"></a><a name="ddx_slider"></a>DDX_Slider

A `DDX_Slider` função gerencia a transferência de **`int`** dados entre um controle deslizante em uma caixa de diálogo ou modo de exibição de formulário e um **`int`** membro de dados da caixa de diálogo ou do objeto de exibição de formulário.

```cpp
void AFXAPI DDX_Slider(
    CDataExchange* pDX,
    int nIDC,
    int& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID do recurso do controle deslizante.

*value*<br/>
Uma referência ao valor a ser trocado. Esse parâmetro mantém ou define a posição atual do controle deslizante.

### <a name="remarks"></a>Comentários

Quando `DDX_Slider` é chamado, o *valor* é definido como a posição atual do Thumb do controle ou o valor recebe a posição, dependendo da direção da troca.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre controles deslizantes, consulte [usando CSliderCtrl](../../mfc/using-csliderctrl.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddx_text"></a><a name="ddx_text"></a>DDX_Text

A `DDX_Text` função gerencia a transferência de **`int`** , **uint**,, **`long`** DWORD, `CString` , **`float`** ou **`double`** dados entre um controle de edição em uma caixa de diálogo, modo de exibição de formulário ou modo de exibição de controle e um membro de dados [CString](../../atl-mfc-shared/reference/cstringt-class.md) da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    BYTE& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    short& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    int& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    UINT& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    long& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    DWORD& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    CString& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    float& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    double& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    COleCurrency& value);

void AFXAPI DDX_Text(
    CDataExchange* pDX,
    int nIDC,
    COleDateTime& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle de edição na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*value*<br/>
Uma referência a um membro de dados na caixa de diálogo, exibição de formulário ou objeto de exibição de controle. O tipo de dados de *valor* depende de qual das versões sobrecarregadas do `DDX_Text` você usa.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="see-also"></a>Confira também

[Rotinas de validação de dados de diálogo padrão](standard-dialog-data-validation-routines.md)<br/>
[Macros e globais](mfc-macros-and-globals.md)<br/>
[CWinFormsControl::CreateManagedControl](cwinformscontrol-class.md#createmanagedcontrol)<br/>
[CDialog:: OnInitDialog](cdialog-class.md#oninitdialog)
