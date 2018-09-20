---
title: Classe CDateTimeCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDateTimeCtrl
- AFXDTCTL/CDateTimeCtrl
- AFXDTCTL/CDateTimeCtrl::CDateTimeCtrl
- AFXDTCTL/CDateTimeCtrl::CloseMonthCal
- AFXDTCTL/CDateTimeCtrl::Create
- AFXDTCTL/CDateTimeCtrl::GetDateTimePickerInfo
- AFXDTCTL/CDateTimeCtrl::GetIdealSize
- AFXDTCTL/CDateTimeCtrl::GetMonthCalColor
- AFXDTCTL/CDateTimeCtrl::GetMonthCalCtrl
- AFXDTCTL/CDateTimeCtrl::GetMonthCalFont
- AFXDTCTL/CDateTimeCtrl::GetMonthCalStyle
- AFXDTCTL/CDateTimeCtrl::GetRange
- AFXDTCTL/CDateTimeCtrl::GetTime
- AFXDTCTL/CDateTimeCtrl::SetFormat
- AFXDTCTL/CDateTimeCtrl::SetMonthCalColor
- AFXDTCTL/CDateTimeCtrl::SetMonthCalFont
- AFXDTCTL/CDateTimeCtrl::SetMonthCalStyle
- AFXDTCTL/CDateTimeCtrl::SetRange
- AFXDTCTL/CDateTimeCtrl::SetTime
dev_langs:
- C++
helpviewer_keywords:
- CDateTimeCtrl [MFC], CDateTimeCtrl
- CDateTimeCtrl [MFC], CloseMonthCal
- CDateTimeCtrl [MFC], Create
- CDateTimeCtrl [MFC], GetDateTimePickerInfo
- CDateTimeCtrl [MFC], GetIdealSize
- CDateTimeCtrl [MFC], GetMonthCalColor
- CDateTimeCtrl [MFC], GetMonthCalCtrl
- CDateTimeCtrl [MFC], GetMonthCalFont
- CDateTimeCtrl [MFC], GetMonthCalStyle
- CDateTimeCtrl [MFC], GetRange
- CDateTimeCtrl [MFC], GetTime
- CDateTimeCtrl [MFC], SetFormat
- CDateTimeCtrl [MFC], SetMonthCalColor
- CDateTimeCtrl [MFC], SetMonthCalFont
- CDateTimeCtrl [MFC], SetMonthCalStyle
- CDateTimeCtrl [MFC], SetRange
- CDateTimeCtrl [MFC], SetTime
ms.assetid: 7113993b-5d37-4148-939f-500a190c5bdc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 57e2b990e8fddbcb81d942cb7327ed8b9d448e6b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46420238"
---
# <a name="cdatetimectrl-class"></a>Classe CDateTimeCtrl

Encapsula a funcionalidade de um controle de seletor de data e hora.

## <a name="syntax"></a>Sintaxe

```
class CDateTimeCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDateTimeCtrl::CDateTimeCtrl](#cdatetimectrl)|Constrói um objeto `CDateTimeCtrl`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDateTimeCtrl::CloseMonthCal](#closemonthcal)|Fecha o controle de seletor de data e hora atual.|
|[CDateTimeCtrl::Create](#create)|Cria o controle de seletor de data e hora e anexa-o para o `CDateTimeCtrl` objeto.|
|[CDateTimeCtrl::GetDateTimePickerInfo](#getdatetimepickerinfo)|Recupera informações sobre o controle de seletor de data e hora atual.|
|[CDateTimeCtrl::GetIdealSize](#getidealsize)|Retorna o tamanho ideal do controle de seletor de data e hora em que é necessário para exibir a data ou hora atual.|
|[CDateTimeCtrl::GetMonthCalColor](#getmonthcalcolor)|Recupera a cor para uma determinada parte do calendário mensal dentro do controle de seletor de data e hora.|
|[CDateTimeCtrl::GetMonthCalCtrl](#getmonthcalctrl)|Recupera o `CMonthCalCtrl` objeto associado com o controle de seletor de data e hora.|
|[CDateTimeCtrl::GetMonthCalFont](#getmonthcalfont)|Recupera a fonte usada no momento, a data e o controle de calendário de mês de filho do controle do seletor de tempo.|
|[CDateTimeCtrl::GetMonthCalStyle](#getmonthcalstyle)|Obtém o estilo do controle de seletor de data e hora atual.|
|[CDateTimeCtrl::GetRange](#getrange)|Recupera o atual mínimo e máximo permitido de horários do sistema para um controle de seletor de data e hora.|
|[CDateTimeCtrl::GetTime](#gettime)|Recupera a hora selecionada no momento de um controle de seletor de data e hora e o coloca em um especificado `SYSTEMTIME` estrutura.|
|[CDateTimeCtrl::SetFormat](#setformat)|Define a exibição de um controle de seletor de data e tempo de acordo com uma cadeia de caracteres de formato fornecido.|
|[CDateTimeCtrl::SetMonthCalColor](#setmonthcalcolor)|Define a cor para uma determinada parte do calendário mensal dentro de um controle de seletor de data e hora.|
|[CDateTimeCtrl::SetMonthCalFont](#setmonthcalfont)|Define a fonte que usará o controle de calendário de mês de data e hora seletor do controle filho.|
|[CDateTimeCtrl::SetMonthCalStyle](#setmonthcalstyle)|Define o estilo do controle de seletor de data e hora atual.|
|[CDateTimeCtrl::SetRange](#setrange)|Define os horários de sistema permitido mínimo e máximo para um controle de seletor de data e hora.|
|[CDateTimeCtrl::SetTime](#settime)|Define o tempo em um controle de seletor de data e hora.|

## <a name="remarks"></a>Comentários

O controle de seletor data e hora (controle DTP) fornece uma interface simples para trocar informações de data e hora com um usuário. Essa interface contém campos, cada um deles exibindo uma parte das informações de data e hora armazenadas no controle. O usuário pode alterar as informações armazenadas no controle, alterando o conteúdo da cadeia de caracteres em um determinado campo. O usuário pode mover de um campo para usar o mouse ou teclado.

Você pode personalizar o controle de seletor de data e hora por meio da aplicação de uma variedade de estilos para o objeto quando ela é criada. Ver [data e hora estilos de controle de seletor](/windows/desktop/Controls/date-and-time-picker-control-styles) no SDK do Windows para obter mais informações sobre estilos específicos para o controle de seletor de data e hora. Você pode definir o formato de exibição do controle DTP usando estilos de formato. Esses estilos de formato são descritos em "Estilos de formato" no tópico SDK do Windows [data e hora estilos de controle de seletor de](/windows/desktop/Controls/date-and-time-picker-control-styles).

O controle de seletor de data e hora também usa notificações e retornos de chamada, que são descritos em [usando CDateTimeCtrl](../../mfc/using-cdatetimectrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CDateTimeCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdtctl.h

##  <a name="cdatetimectrl"></a>  CDateTimeCtrl::CDateTimeCtrl

Constrói um objeto `CDateTimeCtrl`.

```
CDateTimeCtrl();
```

##  <a name="closemonthcal"></a>  CDateTimeCtrl::CloseMonthCal

Fecha o controle de seletor de data e hora atual.

```
void CloseMonthCal() const;
```

### <a name="remarks"></a>Comentários

Esse método envia o [DTM_CLOSEMONTHCAL](/windows/desktop/Controls/dtm-closemonthcal) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável *m_dateTimeCtrl*, que é usado para acessar programaticamente o controle de seletor de data e hora. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir fecha o calendário suspenso para o controle de seletor de data e hora atual.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#5](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_2.cpp)]

##  <a name="create"></a>  CDateTimeCtrl::Create

Cria o controle de seletor de data e hora e anexa-o para o `CDateTimeCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica a combinação de estilos de controle de tempo de data. Ver [data e hora estilos de controle de seletor](/windows/desktop/Controls/date-and-time-picker-control-styles) no SDK do Windows para obter mais informações sobre estilos de seletor de data e hora.

*Rect*<br/>
Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, que é a posição e o tamanho do controle de seletor de data e hora.

*pParentWnd*<br/>
Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle de seletor de data e hora. Ele não deve ser NULL.

*nID*<br/>
Especifica a ID de controle de. Data e hora seletor do controle

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a criação for bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

##### <a name="to-create-a-date-and-time-picker-control"></a>Para criar um controle de seletor de data e hora

1. Chame [CDateTimeCtrl](#cdatetimectrl) para construir um `CDateTimeCtrl` objeto.

1. Chame essa função de membro, que cria o controle de seletor de data e hora do Windows e anexa-o para o `CDateTimeCtrl` objeto.

Quando você chama `Create`, os controles comuns são inicializados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_3.cpp)]

##  <a name="getdatetimepickerinfo"></a>  CDateTimeCtrl::GetDateTimePickerInfo

Recupera informações sobre o controle de seletor de data e hora atual.

```
BOOL GetDateTimePickerInfo(LPDATETIMEPICKERINFO pDateTimePickerInfo) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pDateTimePickerInfo*|[out] Um ponteiro para um [DATETIMEPICKERINFO](/windows/desktop/api/commctrl/ns-commctrl-tagdatetimepickerinfo) estrutura que recebe uma descrição do que o controle de seletor de data e hora atual.<br /><br /> O chamador é responsável por alocar esta estrutura. No entanto, esse método inicializa o *cbSize* membro da estrutura.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia o [DTM_GETDATETIMEPICKERINFO](/windows/desktop/Controls/dtm-getdatetimepickerinfo) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável *m_dateTimeCtrl*, que é usado para acessar programaticamente o controle de seletor de data e hora. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir indica se, com êxito, ele recupera informações sobre o controle de seletor de data e hora atual.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#4](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_4.cpp)]

##  <a name="getmonthcalcolor"></a>  CDateTimeCtrl::GetMonthCalColor

Recupera a cor para uma determinada parte do calendário mensal dentro do controle de seletor de data e hora.

```
COLORREF GetMonthCalColor(int iColor) const;
```

### <a name="parameters"></a>Parâmetros

*iColor*<br/>
Uma **int** valor que especifica qual área de cor de calendário mensal para recuperar. Para obter uma lista de valores, consulte o *iColor* parâmetro para [SetMonthCalColor](#setmonthcalcolor).

### <a name="return-value"></a>Valor de retorno

Um valor COLORREF que representa a definição de cor para a parte especificada do controle de calendário mensal se for bem-sucedido. A função retornará -1 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [DTM_GETMCCOLOR](/windows/desktop/Controls/dtm-getmccolor), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#2](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_5.cpp)]

##  <a name="getmonthcalctrl"></a>  CDateTimeCtrl::GetMonthCalCtrl

Recupera o `CMonthCalCtrl` objeto associado com o controle de seletor de data e hora.

```
CMonthCalCtrl* GetMonthCalCtrl() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md) de objeto ou nulo se não for bem-sucedido ou se a janela não estiver visível.

### <a name="remarks"></a>Comentários

Controles de seletor de data e hora criar um controle de calendário mensal filho quando o usuário clica na seta suspensa. Quando o `CMonthCalCtrl` objeto não for mais necessário, é destruído, portanto, seu aplicativo não deve confiar sobre como armazenar o objeto que representa o calendário de mês do filho do controle data hora seletor.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#3](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_6.cpp)]

##  <a name="getmonthcalfont"></a>  CDateTimeCtrl::GetMonthCalFont

Obtém a fonte usada no momento, a data e o controle de calendário mensal do controle do seletor de tempo.

```
CFont* GetMonthCalFont() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um [CFont](../../mfc/reference/cfont-class.md) do objeto ou nulo se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O `CFont` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

##  <a name="getmonthcalstyle"></a>  CDateTimeCtrl::GetMonthCalStyle

Obtém o estilo do controle de calendário mensal de lista suspensa que está associado com o controle de seletor de data e hora atual.

```
DWORD GetMonthCalStyle() const;
```

### <a name="return-value"></a>Valor de retorno

O estilo do controle de calendário mensal de lista suspensa, que é uma combinação bit a bit (ou) de estilos de controle de seletor de data e hora. Para obter mais informações, consulte [estilos de controle de calendário do mês](/windows/desktop/Controls/month-calendar-control-styles).

### <a name="remarks"></a>Comentários

Esse método envia o [DTM_GETMCSTYLE](/windows/desktop/Controls/dtm-getmcstyle) mensagem, que é descrita no SDK do Windows.

##  <a name="getrange"></a>  CDateTimeCtrl::GetRange

Recupera o atual mínimo e máximo permitido de horários do sistema para um controle de seletor de data e hora.

```
DWORD GetRange(
    COleDateTime* pMinRange,
    COleDateTime* pMaxRange) const;

DWORD GetRange(
    CTime* pMinRange,
    CTime* pMaxRange) const;
```

### <a name="parameters"></a>Parâmetros

*pMinRange*<br/>
Um ponteiro para um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto ou uma [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora mais antiga permitida no `CDateTimeCtrl` objeto.

*pMaxRange*<br/>
Um ponteiro para um `COleDateTime` objeto ou uma `CTime` objeto que contém a hora mais recente permitida no `CDateTimeCtrl` objeto.

### <a name="return-value"></a>Valor de retorno

Um valor DWORD que contém sinalizadores que indicam quais intervalos são definidos. If

`return value & GDTR_MAX` == 0

em seguida, o segundo parâmetro é válido. Da mesma forma, se

`return value & GDTR_MIN` == 0

em seguida, o primeiro parâmetro é válido.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [DTM_GETRANGE](/windows/desktop/Controls/dtm-getrange), conforme descrito no SDK do Windows. Na implementação do MFC, você pode especificar `COleDateTime` ou `CTime` usos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#4](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_7.cpp)]

##  <a name="gettime"></a>  CDateTimeCtrl::GetTime

Recupera a hora selecionada no momento de um controle de seletor de data e hora e o coloca em um especificado `SYSTEMTIME` estrutura.

```
BOOL GetTime(COleDateTime& timeDest) const;
DWORD GetTime(CTime& timeDest) const;
DWORD GetTime(LPSYSTEMTIME pTimeDest) const;
```

### <a name="parameters"></a>Parâmetros

*timeDest*<br/>
Na primeira versão, uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto que receberá as informações de hora do sistema. Na segunda versão, uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que receberá as informações de hora do sistema.

*pTimeDest*<br/>
Um ponteiro para o [SYSTEMTIME](https://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que receberá as informações de hora do sistema. Não deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Na primeira versão, diferente de zero se o tempo é gravado com êxito o `COleDateTime` objeto; caso contrário, 0. Nas versões do segunda e terceira, um DWORD igual ao valor da *dwFlag* conjunto de membros a [NMDATETIMECHANGE](/windows/desktop/api/commctrl/ns-commctrl-tagnmdatetimechange) estrutura. Consulte a **comentários** seção abaixo para obter mais informações.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [DTM_GETSYSTEMTIME](/windows/desktop/Controls/dtm-getsystemtime), conforme descrito no SDK do Windows. Na implementação do MFC `GetTime`, você pode usar `COleDateTime` ou `CTime` classes, ou você pode usar um `SYSTEMTIME` estrutura para armazenar as informações de hora.

O valor de retorno DWORD nas versões do segunda e terceira, acima, indica se o controle de seletor de data e hora é definido como o status de "nenhuma data", conforme indicado na [NMDATETIMECHANGE](/windows/desktop/api/commctrl/ns-commctrl-tagnmdatetimechange) membro da estrutura *dwFlags* . Se o valor retornado for igual a GDT_NONE, o controle é definido para o status de "nenhuma data" e usa o estilo DTS_SHOWNONE. Se o valor retornado for igual a GDT_VALID, a hora do sistema com êxito é armazenada no local de destino.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#5](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_8.cpp)]

##  <a name="getidealsize"></a>  CDateTimeCtrl::GetIdealSize

Retorna o tamanho ideal do controle de seletor de data e hora em que é necessário para exibir a data ou hora atual.

```
BOOL GetIdealSize(LPSIZE psize) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*psize*|[out] Ponteiro para um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que contém o tamanho ideal para o controle.|

### <a name="return-value"></a>Valor de retorno

O valor retornado é sempre TRUE.

### <a name="remarks"></a>Comentários

Esse método envia o [DTM_GETIDEALSIZE](/windows/desktop/Controls/dtm-getidealsize) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável *m_dateTimeCtrl*, que é usado para acessar programaticamente o controle de seletor de data e hora. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera o tamanho ideal para exibir o controle de seletor de data e hora.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_9.cpp)]

##  <a name="setformat"></a>  CDateTimeCtrl::SetFormat

Define a exibição de um controle de seletor de data e tempo de acordo com uma cadeia de caracteres de formato fornecido.

```
BOOL SetFormat(LPCTSTR pstrFormat);
```

### <a name="parameters"></a>Parâmetros

*pstrFormat*<br/>
Um ponteiro para uma cadeia de caracteres de formato terminada em zero que define a exibição desejada. Definir esse parâmetro como NULL, o controle será redefinido como a cadeia de caracteres de formato padrão para o estilo atual.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

> [!NOTE]
>  Entrada do usuário não determina o êxito ou falha para esta chamada.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [DTM_SETFORMAT](/windows/desktop/Controls/dtm-setformat), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#6](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_10.cpp)]

##  <a name="setmonthcalcolor"></a>  CDateTimeCtrl::SetMonthCalColor

Define a cor para uma determinada parte do calendário mensal dentro de um controle de seletor de data e hora.

```
COLORREF SetMonthCalColor(
    int iColor,
    COLORREF ref);
```

### <a name="parameters"></a>Parâmetros

*iColor*<br/>
**int** valor que especifica qual área de controle de calendário mensal para definir. Esse valor pode ser uma das seguintes opções:

|Valor|Significado|
|-----------|-------------|
|MCSC_BACKGROUND|Defina a cor do plano de fundo exibida entre os meses.|
|MCSC_MONTHBK|Defina a cor do plano de fundo exibida dentro de um mês.|
|MCSC_TEXT|Defina a cor usada para exibir o texto dentro de um mês.|
|MCSC_TITLEBK|Defina a cor de plano de fundo exibida no título do calendário.|
|MCSC_TITLETEXT|Defina a cor usada para exibir texto no título do calendário.|
|MCSC_TRAILINGTEXT|Defina a cor usada para exibir o cabeçalho e o texto de dias à direita. Cabeçalho e à direita dias foram os dias dos meses anteriores e seguintes que aparecem no calendário atual.|

*ref*<br/>
Um valor COLORREF que representa a cor que será definida para a área especificada do calendário mensal.

### <a name="return-value"></a>Valor de retorno

Um valor COLORREF que representa a configuração de cor anterior para a parte especificada do controle de calendário mensal se for bem-sucedido. Caso contrário, a mensagem retornará -1.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [DTM_SETMCCOLOR](/windows/desktop/Controls/dtm-setmccolor), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CDateTimeCtrl::GetMonthCalColor](#getmonthcalcolor).

##  <a name="setmonthcalfont"></a>  CDateTimeCtrl::SetMonthCalFont

Define a fonte que usará o controle de calendário de mês de data e hora seletor do controle filho.

```
void SetMonthCalFont(
    HFONT hFont,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*hFont*<br/>
Identificador para a fonte que será definida.

*bRedraw*<br/>
Especifica se o controle deve ser redesenhado imediatamente após a definição da fonte. Definir esse parâmetro como TRUE faz com que o controle para redesenhar a mesmo.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [DTM_SETMCFONT](/windows/desktop/Controls/dtm-setmcfont), conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#7](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_11.cpp)]

> [!NOTE]
>  Se você usar esse código, você desejará fazer com que um membro de sua `CDialog`-chamado de classe derivada *m_MonthFont* do tipo `CFont`.

##  <a name="setmonthcalstyle"></a>  CDateTimeCtrl::SetMonthCalStyle

Define o estilo do controle de calendário mensal de lista suspensa que está associado com o controle de seletor de data e hora atual.

```
DWORD SetMonthCalStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*dwStyle*|[in] Estilo de controle, que é uma combinação bit a bit (OR) de estilos de controle de calendário do mês do calendário de um novo mês. Para obter mais informações, consulte [estilos de controle de calendário do mês](/windows/desktop/Controls/month-calendar-control-styles).|

### <a name="return-value"></a>Valor de retorno

O estilo anterior do controle de calendário mensal suspenso.

### <a name="remarks"></a>Comentários

Esse método envia o [DTM_SETMCSTYLE](/windows/desktop/Controls/dtm-setmcstyle) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável *m_dateTimeCtrl*, que é usado para acessar programaticamente o controle de seletor de data e hora. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o controle de seletor de data e hora para exibir os números de semana, nomes abreviados dos dias da semana e nenhum indicador de hoje.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#3](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_12.cpp)]

##  <a name="setrange"></a>  CDateTimeCtrl::SetRange

Define os horários de sistema permitido mínimo e máximo para um controle de seletor de data e hora.

```
BOOL SetRange(
    const COleDateTime* pMinRange,
    const COleDateTime* pMaxRange);


BOOL SetRange(
    const CTime* pMinRange,
    const CTime* pMaxRange);
```

### <a name="parameters"></a>Parâmetros

*pMinRange*<br/>
Um ponteiro para um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto ou uma [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora mais antiga permitida no `CDateTimeCtrl` objeto.

*pMaxRange*<br/>
Um ponteiro para um `COleDateTime` objeto ou uma `CTime` objeto que contém a hora mais recente permitida no `CDateTimeCtrl` objeto.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [DTM_SETRANGE](/windows/desktop/Controls/dtm-setrange), conforme descrito no SDK do Windows. Na implementação do MFC, você pode especificar `COleDateTime` ou `CTime` usos. Se o `COleDateTime` objeto tem um status NULL, o intervalo será removido. Se o `CTime` ponteiro ou o `COleDateTime` ponteiro for NULL, o intervalo será removido.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CDateTimeCtrl::GetRange](#getrange).

##  <a name="settime"></a>  CDateTimeCtrl::SetTime

Define o tempo em um controle de seletor de data e hora.

```
BOOL SetTime(const COleDateTime& timeNew);
BOOL SetTime(const CTime* pTimeNew);
BOOL SetTime(LPSYSTEMTIME pTimeNew = NULL);
```

### <a name="parameters"></a>Parâmetros

*timeNew*<br/>
Uma referência a um [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto contendo o para que o controle será definido.

*pTimeNew*<br/>
Na segunda versão acima, um ponteiro para um [CTime](../../atl-mfc-shared/reference/ctime-class.md) objeto que contém a hora para o qual o controle será definido. Na terceira versão acima, um ponteiro para um [SYSTEMTIME](https://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que contém a hora para o qual o controle será definido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função membro implementa o comportamento da mensagem do Win32 [DTM_SETSYSTEMTIME](/windows/desktop/Controls/dtm-setsystemtime), conforme descrito no SDK do Windows. Na implementação do MFC `SetTime`, você pode usar o `COleDateTime` ou `CTime` classes, ou você pode usar um `SYSTEMTIME` estrutura para definir as informações de tempo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#8](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_13.cpp)]

## <a name="see-also"></a>Consulte também

[CMNCTRL1 de exemplo do MFC](../../visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)
