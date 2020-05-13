---
title: Rotinas de troca dos dados da caixa de diálogo padrão
ms.date: 11/04/2016
helpviewer_keywords:
- standard dialog, data exchange routines
ms.assetid: c6adb7f3-f9af-4cc5-a9ea-315c5b60ad1a
ms.openlocfilehash: 83d4a66cd3ec41008506b55f0b351fd9bcbc24b5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372925"
---
# <a name="standard-dialog-data-exchange-routines"></a>Rotinas de troca dos dados da caixa de diálogo padrão

Este tópico lista as rotinas padrão de troca de dados de diálogo (DDX) usadas para controles comuns de diálogo MFC.

> [!NOTE]
> As rotinas padrão de troca de dados de diálogo são definidas no arquivo de cabeçalho afxdd_.h. No entanto, os aplicativos devem incluir afxwin.h.

### <a name="ddx-functions"></a>Funções DDX

|||
|-|-|
|[DDX_CBIndex](#ddx_cbindex)|Inicializa ou recupera o índice da seleção atual de um controle de caixa combo.|
|[DDX_CBString](#ddx_cbstring)|Inicializa ou recupera o conteúdo atual do campo de edição de um controle de caixa combo.|
|[DDX_CBStringExact](#ddx_cbstringexact)|Inicializa ou recupera o conteúdo atual do campo de edição de um controle de caixa combo.|
|[DDX_Check](#ddx_check)|Inicializa ou recupera o estado atual de um controle de caixa de seleção.|
|[DDX_Control](#ddx_control)|Subclasses de um determinado controle dentro de uma caixa de diálogo.|
|[DDX_DateTimeCtrl](#ddx_datetimectrl)|Inicializa ou recupera dados de data e/ou hora de um controle de seleção de data e hora.|
|[DDX_IPAddress](#ddx_ipaddress)|Inicializa ou recupera o valor atual de um controle de endereço IP.|
|[DDX_LBIndex](#ddx_lbindex)|Inicializa ou recupera o índice da seleção atual de um controle de caixa de lista.|
|[DDX_LBString](#ddx_lbstring)|Inicializa ou recupera a seleção atual dentro de um controle de caixa de lista.|
|[DDX_LBStringExact](#ddx_lbstringexact)|Inicializa ou recupera a seleção atual dentro de um controle de caixa de lista.|
|[DDX_ManagedControl](#ddx_managedcontrol)|Cria um controle .NET que corresponde ao ID de recurso do controle.|
|[DDX_MonthCalCtrl](#ddx_monthcalctrl)|Inicializa ou recupera o valor atual de um mês de controle de calendário.|
|[DDX_Radio](#ddx_radio)|Inicializa ou recupera o índice baseado em 0 do controle de rádio que atualmente é verificado dentro de um grupo de controle de rádio.|
|[DDX_Scroll](#ddx_scroll)|Inicializa ou recupera a posição atual do polegar de um controle de rolagem.|
|[DDX_Slider](#ddx_slider)|Inicializa ou recupera a posição atual do polegar de um controle deslizante.|
|[DDX_Text](#ddx_text)|Inicializa ou recupera o valor atual de um controle de edição.|

## <a name="ddx_cbindex"></a><a name="ddx_cbindex"></a>DDX_CBIndex

A `DDX_CBIndex` função gerencia a transferência de dados **int** entre um controle de caixa de combinação em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados **int** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_CBIndex(
    CDataExchange* pDX,
    int nIDC,
    int& index);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle da caixa de combinação associado à propriedade de controle.

*Índice*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_CBIndex` é chamado, o *índice* é definido para o índice da seleção atual da caixa de combinação. Se nenhum item for selecionado, *o índice* será definido como 0.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_cbstring"></a><a name="ddx_cbstring"></a>DDX_CBString

A `DDX_CBString` função gerencia a `CString` transferência de dados entre o controle de edição de um controle de `CString` caixa de combinação em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_CBString(
    CDataExchange* pDX,
    int nIDC,
    CString& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle da caixa de combinação associado à propriedade de controle.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_CBString` é chamado, o *valor* é definido para a seleção atual da caixa de combinação. Se nenhum item for selecionado, *o valor* será definido como uma seqüência de comprimento zero.

> [!NOTE]
> Se a caixa de combinação for uma caixa de lista parada, o valor trocado será limitado a 255 caracteres.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_cbstringexact"></a><a name="ddx_cbstringexact"></a>DDX_CBStringExact

A `DDX_CBStringExact` função gerencia a `CString` transferência de dados entre o controle de edição de um controle de `CString` caixa de combinação em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_CBStringExact(
    CDataExchange* pDX,
    int nIDC,
    CString& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle da caixa de combinação associado à propriedade de controle.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_CBStringExact` é chamado, o *valor* é definido para a seleção atual da caixa de combinação. Se nenhum item for selecionado, *o valor* será definido como uma seqüência de comprimento zero.

> [!NOTE]
> Se a caixa de combinação for uma caixa de lista parada, o valor trocado será limitado a 255 caracteres.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_check"></a><a name="ddx_check"></a>DDX_Check

A `DDX_Check` função gerencia a transferência de dados **int** entre um controle de caixa de seleção em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados **int** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_Check(
    CDataExchange* pDX,
    int nIDC,
    int& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle da caixa de seleção associado à propriedade de controle.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_Check` é chamado, o *valor* é definido para o estado atual do controle da caixa de seleção. Para obter uma lista dos possíveis valores de estado, consulte [BM_GETCHECK](/windows/win32/Controls/bm-getcheck) no SDK do Windows.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_control"></a><a name="ddx_control"></a>Ddx_control

A `DDX_Control` função subclasses o controle, especificado por *nIDC,* da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_Control(
    CDataExchange* pDX,
    int nIDC,
    CWnd& rControl);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md)

*nIDC*<br/>
O iD de recurso do controle a ser subclassificado.

*rControl*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle relacionado ao controle especificado.

### <a name="remarks"></a>Comentários

O objeto *pDX* é fornecido `DoDataExchange` pela estrutura quando a função é chamada. Portanto, `DDX_Control` só deve ser chamado dentro `DoDataExchange`de sua substituição de .

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_datetimectrl"></a><a name="ddx_datetimectrl"></a>DDX_DateTimeCtrl

A `DDX_DateTimeCtrl` função gerencia a transferência de dados de data e/ou hora entre um controle de seleção de data e hora [(CDateTimeCtrl)](../../mfc/reference/cdatetimectrl-class.md)em uma caixa de diálogo ou objeto de exibição de formulário e um membro de dados [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) da caixa de diálogo ou objeto de exibição de formulário.

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

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção. Você não precisa excluir este objeto.

*nIDC*<br/>
O ID de recurso do controle de data e hora do seletor associado à variável membro.

*value*<br/>
Nas duas primeiras versões, `CTime` `COleDateTime` uma referência a uma variável ou membro, caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados. Na terceira versão, uma `CString` referência a um objeto de exibição de controle de membro de dados.

### <a name="remarks"></a>Comentários

Quando `DDX_DateTimeCtrl` é chamado, o *valor* é definido para o estado atual do controle de data e seleção de tempo, ou o controle é definido como *valor,* dependendo da direção da troca.

Na terceira versão `DDX_DateTimeCtrl` acima, gerencia `CString` a transferência de dados entre um controle de data e um membro de dados [CString](../../atl-mfc-shared/reference/cstringt-class.md) do objeto de exibição de controle. A seqüência é formatado usando as regras do local atual para formatação de datas e horários.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_managedcontrol"></a><a name="ddx_managedcontrol"></a>Ddx_managedcontrol

Cria um controle .NET que corresponde ao ID de recurso do controle.

### <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
void DDX_ManagedControl(
   CDataExchange* pDX,
   int nIDC,
   CWinFormsControl<T>& control );
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange Class.](cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O id de recurso do controle associado à propriedade de controle.

*Controle*<br/>
Uma referência a um objeto [CWinFormsControl Class.](cwinformscontrol-class.md)

### <a name="remarks"></a>Comentários

`DDX_ManagedControl`chama [CWinFormsControl::CreateManagedControl](cwinformscontrol-class.md#createmanagedcontrol) para criar um controle que corresponda ao ID de controle de recursos. Use `DDX_ManagedControl` para criar controles a partir de IDs de recursos em [CDialog::OnInitDialog](cdialog-class.md#oninitdialog). Para a troca de dados, você não precisa usar as funções DDX/DDV com controles do Windows Forms.

Para obter mais informações, [consulte Como: Fazer a vinculação de dados DDX/DDV com formulários do Windows](../../dotnet/how-to-do-ddx-ddv-data-binding-with-windows-forms.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h

## <a name="ddx_ipaddress"></a><a name="ddx_ipaddress"></a>DDX_IPAddress

A `DDX_IPAddress` função gerencia a transferência de dados entre um controle de endereço IP e um membro de dados do objeto de exibição de controle.

```cpp
void AFXAPI DDX_IPAddress(
    CDataExchange* pDX,
    int nIDC,
    DWORD& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle de endereço IP associado à propriedade de controle.

*value*<br/>
Uma referência ao DWORD contendo o valor de quatro campos do controle de endereço IP. Os campos são preenchidos ou lidos da seguinte forma.

|Campo|Bits contendo o valor do campo|
|-----------|-------------------------------------|
|3|0 a 7|
|2|8 a 15|
|1|16 a 23|
|0|24 a 31|

Use o [IPM_GETADDRESS](/windows/win32/Controls/ipm-getaddress) Do32 para ler o valor ou use [IPM_SETADDRESS](/windows/win32/Controls/ipm-setaddress) para preencher o valor. Essas mensagens são descritas no Windows SDK.

### <a name="remarks"></a>Comentários

Quando `DDX_IPAddress` é chamado, o *valor* é lido no controle de endereço IP ou o *valor* é gravado no controle, dependendo da direção da troca.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_lbindex"></a><a name="ddx_lbindex"></a>DDX_LBIndex

A `DDX_LBIndex` função gerencia a transferência de dados **int** entre um controle de caixa de lista em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados **int** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_LBIndex(
    CDataExchange* pDX,
    int nIDC,
    int& index);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle da caixa de lista associado à propriedade de controle.

*Índice*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_LBIndex` é chamado, o *índice* é definido para o índice da seleção atual da caixa de lista. Se nenhum item for selecionado, *o índice* será definido como -1.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_lbstring"></a><a name="ddx_lbstring"></a>DDX_LBString

A `DDX_LBString` função gerencia a `CString` transferência de dados entre um controle de caixa de lista `CString` em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_LBString(
    CDataExchange* pDX,
    int nIDC,
    CString& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle da caixa de lista associado à propriedade de controle.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_LBString` é chamado para transferir dados para um controle de caixa de lista, o primeiro item no controle cujo *valor* de partida corresponde é selecionado. (Para combinar com o item inteiro em vez de apenas um prefixo, use [DDX_LBStringExact](#ddx_lbstringexact).) Se não houver correspondências, nenhum item será selecionado. A correspondência é insensível ao caso.

Quando `DDX_LBString` é chamado para transferir dados de um controle de caixa de lista, o *valor* é definido para a seleção atual da caixa de lista. Se nenhum item for selecionado, *o valor* será definido como uma seqüência de comprimento zero.

> [!NOTE]
> Se a caixa de lista for uma caixa de lista para dada, o valor trocado será limitado a 255 caracteres.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_lbstringexact"></a><a name="ddx_lbstringexact"></a>DDX_LBStringExact

A `DDX_CBStringExact` função gerencia a `CString` transferência de dados entre o controle de edição de um controle de `CString` caixa de lista em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_LBStringExact(
    CDataExchange* pDX,
    int nIDC,
    CString& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle da caixa de lista associado à propriedade de controle.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_LBStringExact` é chamado para transferir dados para um controle de caixa de lista, o primeiro item no controle que corresponde ao *valor* é selecionado. (Para combinar apenas um prefixo em vez de todo o item, use [DDX_LBString](#ddx_lbstring).) Se não houver correspondências, nenhum item será selecionado. A correspondência é insensível ao caso.

Quando `DDX_CBStringExact` é chamado para transferir dados de um controle de caixa de lista, o *valor* é definido para a seleção atual da caixa de lista. Se nenhum item for selecionado, *o valor* será definido como uma seqüência de comprimento zero.

> [!NOTE]
> Se a caixa de lista for uma caixa de lista para dada, o valor trocado será limitado a 255 caracteres.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_monthcalctrl"></a><a name="ddx_monthcalctrl"></a>DDX_MonthCalCtrl

A `DDX_MonthCalCtrl` função gerencia a transferência de dados de data entre um controle de calendário de um mês [(CMonthCalCtrl)](../../mfc/reference/cmonthcalctrl-class.md)em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

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

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção. Você não precisa excluir este objeto.

*nIDC*<br/>
O id de recurso do controle do calendário do mês associado à variável membro.

*value*<br/>
Uma referência `CTime` a `COleDateTime` uma variável ou membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

> [!NOTE]
> O controle gerencia apenas um valor de data. Os campos de tempo no objeto de tempo são definidos para refletir o tempo de `CMonthCalCtrl::SetCurSel`criação da janela de controle, ou qualquer tempo definido no controle com uma chamada para .

Quando `DDX_MonthCalCtrl` é chamado, o *valor* é definido para o estado atual do controle do calendário do mês.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_radio"></a><a name="ddx_radio"></a>DDX_Radio

A `DDX_Radio` função gerencia a transferência de dados **int** entre um grupo de controle de rádio em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados **int** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle. O valor do membro de dados **int** é determinado de acordo com qual botão de rádio dentro do grupo é selecionado.

```cpp
void AFXAPI DDX_Radio(
    CDataExchange* pDX,
    int nIDC,
    int& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A id de recurso do primeiro controle de rádio do grupo.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_Radio` é chamado, o *valor* é definido para o estado atual do grupo de controle de rádio. O valor é definido como um índice baseado em 0 do controle de rádio que está atualmente verificado, ou -1 se nenhum controle de rádio for verificado.

Por exemplo, caso o primeiro botão de rádio do grupo seja verificado (o botão com WS_GROUP estilo) o valor do membro **int** é 0 e assim por diante.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_scroll"></a><a name="ddx_scroll"></a>DDX_Scroll

A `DDX_Scroll` função gerencia a transferência de dados **int** entre um controle de barra de rolagem em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados **int** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_Scroll(
    CDataExchange* pDX,
    int nIDC,
    int& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle da barra de rolagem associado à propriedade de controle.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_Scroll` é chamado, o *valor* é definido para a posição atual do polegar do controle. Para obter mais informações sobre os valores associados à posição atual do polegar do controle, consulte [GetScrollPos](/windows/win32/api/winuser/nf-winuser-getscrollpos) no SDK do Windows.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_slider"></a><a name="ddx_slider"></a>Ddx_slider

A `DDX_Slider` função gerencia a transferência de dados **int** entre um controle de controle deslizante em uma caixa de diálogo ou exibição de formulário e um membro de dados **int** da caixa de diálogo ou objeto de exibição de formulário.

```cpp
void AFXAPI DDX_Slider(
    CDataExchange* pDX,
    int nIDC,
    int& value);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O id de recurso do controle deslizante.

*value*<br/>
Uma referência ao valor a ser trocado. Este parâmetro mantém ou define a posição atual do controle deslizante.

### <a name="remarks"></a>Comentários

Quando `DDX_Slider` é chamado, o *valor* é definido para a posição atual do polegar do controle, ou o valor recebe a posição, dependendo da direção da troca.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre controles deslizantes, consulte [Usando CSliderCtrl](../../mfc/using-csliderctrl.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddx_text"></a><a name="ddx_text"></a>Ddx_text

A `DDX_Text` função gerencia a transferência de **int,** **UINT**, **long** `CString`, DWORD, , **float**, ou **dados duplos** entre um controle de edição em uma caixa de diálogo, exibição de formulário ou exibição de controle e um membro de dados [CString](../../atl-mfc-shared/reference/cstringt-class.md) da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

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

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de um controle de edição na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*value*<br/>
Uma referência a um membro de dados na caixa de diálogo, exibição de formulário ou objeto de exibição de controle. O tipo de *valor* dos dados depende de `DDX_Text` qual das versões sobrecarregadas de você usa.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="see-also"></a>Confira também

[Rotinas de validação dos dados da caixa de diálogo padrão](standard-dialog-data-validation-routines.md)<br/>
[Macros e globais](mfc-macros-and-globals.md)<br/>
[CWinFormsControl::CreateManagedControl](cwinformscontrol-class.md#createmanagedcontrol)<br/>
[CDialog::OnInitDialog](cdialog-class.md#oninitdialog)
