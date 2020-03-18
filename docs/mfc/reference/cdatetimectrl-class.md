---
title: Classe CDateTimeCtrl
ms.date: 11/04/2016
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
ms.openlocfilehash: ec9060ba60c4d9877e5ee32bc68da0134f0ccf20
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418681"
---
# <a name="cdatetimectrl-class"></a>Classe CDateTimeCtrl

Encapsula a funcionalidade de um controle seletor de data e hora.

## <a name="syntax"></a>Sintaxe

```
class CDateTimeCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDateTimeCtrl::CDateTimeCtrl](#cdatetimectrl)|Constrói um objeto `CDateTimeCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CDateTimeCtrl::CloseMonthCal](#closemonthcal)|Fecha o controle do seletor de data e hora atual.|
|[CDateTimeCtrl:: criar](#create)|Cria o controle seletor de data e hora e o anexa ao objeto `CDateTimeCtrl`.|
|[CDateTimeCtrl::GetDateTimePickerInfo](#getdatetimepickerinfo)|Recupera informações sobre o controle do seletor de data e hora atual.|
|[CDateTimeCtrl::GetIdealSize](#getidealsize)|Retorna o tamanho ideal do controle seletor de data e hora necessário para exibir a data ou a hora atual.|
|[CDateTimeCtrl::GetMonthCalColor](#getmonthcalcolor)|Recupera a cor de uma determinada parte do calendário mensal dentro do controle seletor de data e hora.|
|[CDateTimeCtrl::GetMonthCalCtrl](#getmonthcalctrl)|Recupera o objeto `CMonthCalCtrl` associado ao controle seletor de data e hora.|
|[CDateTimeCtrl::GetMonthCalFont](#getmonthcalfont)|Recupera a fonte usada atualmente pelo controle de calendário de mês filho do controle seletor de data e hora.|
|[CDateTimeCtrl::GetMonthCalStyle](#getmonthcalstyle)|Obtém o estilo do controle do seletor de data e hora atual.|
|[CDateTimeCtrl:: GetRange](#getrange)|Recupera os horários de sistema mínimos e máximos permitidos no momento para um controle de seletor de data e hora.|
|[CDateTimeCtrl:: getTime](#gettime)|Recupera a hora atualmente selecionada de um controle seletor de data e hora e a coloca em uma estrutura de `SYSTEMTIME` especificada.|
|[CDateTimeCtrl:: SetFormat](#setformat)|Define a exibição de um controle de seletor de data e hora de acordo com uma determinada cadeia de caracteres de formato.|
|[CDateTimeCtrl::SetMonthCalColor](#setmonthcalcolor)|Define a cor de uma determinada parte do calendário mensal dentro de um controle de seletor de data e hora.|
|[CDateTimeCtrl::SetMonthCalFont](#setmonthcalfont)|Define a fonte que o controle de calendário do mês filho do controle do seletor de data e hora usará.|
|[CDateTimeCtrl::SetMonthCalStyle](#setmonthcalstyle)|Define o estilo do controle do seletor de data e hora atual.|
|[CDateTimeCtrl:: SetRange](#setrange)|Define os tempos mínimos e máximos do sistema permitidos para um controle do seletor de data e hora.|
|[CDateTimeCtrl:: SetTime](#settime)|Define a hora em um controle de seletor de data e hora.|

## <a name="remarks"></a>Comentários

O controle seletor de data e hora (controle DTP) fornece uma interface simples para trocar informações de data e hora com um usuário. Essa interface contém campos, cada um dos quais exibe uma parte das informações de data e hora armazenadas no controle. O usuário pode alterar as informações armazenadas no controle alterando o conteúdo da cadeia de caracteres em um determinado campo. O usuário pode mover de campo para campo usando o mouse ou o teclado.

Você pode personalizar o controle seletor de data e hora aplicando uma variedade de estilos ao objeto ao criá-lo. Consulte [estilos de controle do seletor de data e hora](/windows/win32/Controls/date-and-time-picker-control-styles) na SDK do Windows para obter mais informações sobre estilos específicos do controle do seletor de data e hora. Você pode definir o formato de exibição do controle DTP usando estilos de formato. Esses estilos de formato são descritos em "Formatar estilos" nas SDK do Windows [estilos de controle de data e hora do tópico seletor](/windows/win32/Controls/date-and-time-picker-control-styles).

O controle seletor de data e hora também usa notificações e retornos de chamada, que são descritos em [usando CDateTimeCtrl](../../mfc/using-cdatetimectrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CDateTimeCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDTCTL. h

##  <a name="cdatetimectrl"></a>CDateTimeCtrl::CDateTimeCtrl

Constrói um objeto `CDateTimeCtrl`.

```
CDateTimeCtrl();
```

##  <a name="closemonthcal"></a>CDateTimeCtrl::CloseMonthCal

Fecha o controle do seletor de data e hora atual.

```
void CloseMonthCal() const;
```

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [DTM_CLOSEMONTHCAL](/windows/win32/Controls/dtm-closemonthcal) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_dateTimeCtrl*, que é usada para acessar programaticamente o controle do seletor de data e hora. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir fecha o calendário suspenso para o controle do seletor de data e hora atual.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#5](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_2.cpp)]

##  <a name="create"></a>CDateTimeCtrl:: criar

Cria o controle seletor de data e hora e o anexa ao objeto `CDateTimeCtrl`.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>parâmetros

*dwStyle*<br/>
Especifica a combinação de estilos de controle de data e hora. Consulte [estilos de controle de seletor de data e hora](/windows/win32/Controls/date-and-time-picker-control-styles) na SDK do Windows para obter mais informações sobre estilos de seletor de data e hora.

*Rect*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) , que é a posição e o tamanho do controle seletor de data e hora.

*pParentWnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle do seletor de data e hora. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID de controle do controle do seletor de data e hora.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a criação tiver sido bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

##### <a name="to-create-a-date-and-time-picker-control"></a>Para criar um controle de seletor de data e hora

1. Chame [CDateTimeCtrl](#cdatetimectrl) para construir um objeto de `CDateTimeCtrl`.

1. Chame essa função de membro, que cria o controle seletor de data e hora do Windows e o anexa ao objeto `CDateTimeCtrl`.

Quando você chama `Create`, os controles comuns são inicializados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_3.cpp)]

##  <a name="getdatetimepickerinfo"></a>CDateTimeCtrl::GetDateTimePickerInfo

Recupera informações sobre o controle do seletor de data e hora atual.

```
BOOL GetDateTimePickerInfo(LPDATETIMEPICKERINFO pDateTimePickerInfo) const;
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*pDateTimePickerInfo*|fora Um ponteiro para uma estrutura [DATETIMEPICKERINFO](/windows/win32/api/commctrl/ns-commctrl-datetimepickerinfo) que recebe uma descrição do controle do seletor de data e hora atual.<br /><br /> O chamador é responsável por alocar essa estrutura. No entanto, esse método inicializa o membro *cbSize* da estrutura.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [DTM_GETDATETIMEPICKERINFO](/windows/win32/Controls/dtm-getdatetimepickerinfo) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_dateTimeCtrl*, que é usada para acessar programaticamente o controle do seletor de data e hora. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir indica se ele recupera com êxito informações sobre o controle do seletor de data e hora atual.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#4](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_4.cpp)]

##  <a name="getmonthcalcolor"></a>CDateTimeCtrl::GetMonthCalColor

Recupera a cor de uma determinada parte do calendário mensal dentro do controle seletor de data e hora.

```
COLORREF GetMonthCalColor(int iColor) const;
```

### <a name="parameters"></a>parâmetros

*iColor*<br/>
Um valor **inteiro** que especifica qual área de cor do calendário mensal será recuperada. Para obter uma lista de valores, consulte o parâmetro *iColor* para [SetMonthCalColor](#setmonthcalcolor).

### <a name="return-value"></a>Valor retornado

Um valor COLORREF que representa a configuração de cor para a parte especificada do controle de calendário mensal se for bem-sucedido. A função retornará-1 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [DTM_GETMCCOLOR](/windows/win32/Controls/dtm-getmccolor)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#2](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_5.cpp)]

##  <a name="getmonthcalctrl"></a>CDateTimeCtrl::GetMonthCalCtrl

Recupera o objeto `CMonthCalCtrl` associado ao controle seletor de data e hora.

```
CMonthCalCtrl* GetMonthCalCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md) ou nulo se não for bem-sucedido ou se a janela não estiver visível.

### <a name="remarks"></a>Comentários

Os controles de seletor de data e hora criam um controle de calendário mensal filho quando o usuário clica na seta suspensa. Quando o objeto `CMonthCalCtrl` não é mais necessário, ele é destruído e, portanto, seu aplicativo não deve confiar no armazenamento do objeto que representa o calendário do mês filho do controle do seletor de data e hora.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#3](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_6.cpp)]

##  <a name="getmonthcalfont"></a>CDateTimeCtrl::GetMonthCalFont

Obtém a fonte usada atualmente pelo controle de calendário mensal do controle seletor de data e hora.

```
CFont* GetMonthCalFont() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CFont](../../mfc/reference/cfont-class.md) ou nulo se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O objeto de `CFont` apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

##  <a name="getmonthcalstyle"></a>CDateTimeCtrl::GetMonthCalStyle

Obtém o estilo do controle de calendário do mês suspenso que está associado ao controle do seletor de data e hora atual.

```
DWORD GetMonthCalStyle() const;
```

### <a name="return-value"></a>Valor retornado

O estilo do controle de calendário do mês suspenso, que é uma combinação bit-a-ponto (ou) de estilos de controle do seletor de data e hora. Para obter mais informações, consulte os [estilos de controle de calendário mensal](/windows/win32/Controls/month-calendar-control-styles).

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [DTM_GETMCSTYLE](/windows/win32/Controls/dtm-getmcstyle) , que é descrita na SDK do Windows.

##  <a name="getrange"></a>CDateTimeCtrl:: GetRange

Recupera os horários de sistema mínimos e máximos permitidos no momento para um controle de seletor de data e hora.

```
DWORD GetRange(
    COleDateTime* pMinRange,
    COleDateTime* pMaxRange) const;

DWORD GetRange(
    CTime* pMinRange,
    CTime* pMaxRange) const;
```

### <a name="parameters"></a>parâmetros

*pMinRange*<br/>
Um ponteiro para um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém a hora mais antiga permitida no objeto `CDateTimeCtrl`.

*pMaxRange*<br/>
Um ponteiro para um objeto `COleDateTime` ou um objeto `CTime` que contém a hora mais recente permitida no objeto `CDateTimeCtrl`.

### <a name="return-value"></a>Valor retornado

Um valor DWORD que contém sinalizadores que indicam quais intervalos estão definidos. Se

`return value & GDTR_MAX` = = 0

em seguida, o segundo parâmetro é válido. Da mesma forma, se

`return value & GDTR_MIN` = = 0

em seguida, o primeiro parâmetro é válido.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [DTM_GETRANGE](/windows/win32/Controls/dtm-getrange)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC, você pode especificar `COleDateTime` ou `CTime` usos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#4](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_7.cpp)]

##  <a name="gettime"></a>CDateTimeCtrl:: getTime

Recupera a hora atualmente selecionada de um controle seletor de data e hora e a coloca em uma estrutura de `SYSTEMTIME` especificada.

```
BOOL GetTime(COleDateTime& timeDest) const;
DWORD GetTime(CTime& timeDest) const;
DWORD GetTime(LPSYSTEMTIME pTimeDest) const;
```

### <a name="parameters"></a>parâmetros

*timeDest*<br/>
Na primeira versão, uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que receberá as informações de hora do sistema. Na segunda versão, uma referência a um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que receberá as informações de hora do sistema.

*pTimeDest*<br/>
Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) para receber as informações de hora do sistema. Não deve ser nulo.

### <a name="return-value"></a>Valor retornado

Na primeira versão, diferente de zero se a hora for gravada com êxito no objeto `COleDateTime`; caso contrário, 0. Na segunda e terceira versões, um valor DWORD igual ao conjunto de membros *dwFlag* na estrutura [NMDATETIMECHANGE](/windows/win32/api/commctrl/ns-commctrl-nmdatetimechange) . Consulte a seção **comentários** abaixo para obter mais informações.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [DTM_GETSYSTEMTIME](/windows/win32/Controls/dtm-getsystemtime)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC de `GetTime`, você pode usar `COleDateTime` ou `CTime` classes ou pode usar uma estrutura de `SYSTEMTIME` para armazenar as informações de tempo.

O valor de retorno DWORD na segunda e terceira versões, acima, indica se o controle do seletor de data e hora está definido como o status "sem data", conforme indicado no membro da estrutura [NMDATETIMECHANGE](/windows/win32/api/commctrl/ns-commctrl-nmdatetimechange) *dwFlags*. Se o valor retornado for igual a GDT_NONE, o controle será definido como o status "sem data" e usará o estilo de DTS_SHOWNONE. Se o valor retornado for igual a GDT_VALID, a hora do sistema será armazenada com êxito no local de destino.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#5](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_8.cpp)]

##  <a name="getidealsize"></a>CDateTimeCtrl::GetIdealSize

Retorna o tamanho ideal do controle seletor de data e hora necessário para exibir a data ou a hora atual.

```
BOOL GetIdealSize(LPSIZE psize) const;
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*psize*|fora Ponteiro para uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) que contém o tamanho ideal para o controle.|

### <a name="return-value"></a>Valor retornado

O valor de retorno é sempre verdadeiro.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [DTM_GETIDEALSIZE](/windows/win32/Controls/dtm-getidealsize) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_dateTimeCtrl*, que é usada para acessar programaticamente o controle do seletor de data e hora. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera o tamanho ideal para exibir o controle de seletor de data e hora.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_9.cpp)]

##  <a name="setformat"></a>CDateTimeCtrl:: SetFormat

Define a exibição de um controle de seletor de data e hora de acordo com uma determinada cadeia de caracteres de formato.

```
BOOL SetFormat(LPCTSTR pstrFormat);
```

### <a name="parameters"></a>parâmetros

*pstrFormat*<br/>
Um ponteiro para uma cadeia de caracteres de formato terminada em zero que define a exibição desejada. Definir esse parâmetro como NULL redefinirá o controle para a cadeia de caracteres de formato padrão para o estilo atual.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

> [!NOTE]
>  A entrada do usuário não determina o êxito ou a falha para essa chamada.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [DTM_SETFORMAT](/windows/win32/Controls/dtm-setformat)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#6](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_10.cpp)]

##  <a name="setmonthcalcolor"></a>CDateTimeCtrl::SetMonthCalColor

Define a cor de uma determinada parte do calendário mensal dentro de um controle de seletor de data e hora.

```
COLORREF SetMonthCalColor(
    int iColor,
    COLORREF ref);
```

### <a name="parameters"></a>parâmetros

*iColor*<br/>
valor **int** que especifica qual área do controle de calendário mensal definir. Esse valor pode ser um dos seguintes.

|Valor|Significado|
|-----------|-------------|
|MCSC_BACKGROUND|Defina a cor do plano de fundo exibida entre meses.|
|MCSC_MONTHBK|Defina a cor do plano de fundo exibida em um mês.|
|MCSC_TEXT|Defina a cor usada para exibir o texto em um mês.|
|MCSC_TITLEBK|Defina a cor do plano de fundo exibida no título do calendário.|
|MCSC_TITLETEXT|Defina a cor usada para exibir texto dentro do título do calendário.|
|MCSC_TRAILINGTEXT|Defina a cor usada para exibir o texto do cabeçalho e do dia final. Os dias de cabeçalho e à direita são os dias dos meses anteriores e seguintes que aparecem no calendário atual.|

*ref*<br/>
Um valor de COLORREF que representa a cor que será definida para a área especificada do calendário mensal.

### <a name="return-value"></a>Valor retornado

Um valor COLORREF que representa a configuração de cor anterior para a parte especificada do controle de calendário mensal se for bem-sucedido. Caso contrário, a mensagem retornará-1.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [DTM_SETMCCOLOR](/windows/win32/Controls/dtm-setmccolor)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CDateTimeCtrl:: GetMonthCalColor](#getmonthcalcolor).

##  <a name="setmonthcalfont"></a>CDateTimeCtrl::SetMonthCalFont

Define a fonte que o controle de calendário do mês filho do controle do seletor de data e hora usará.

```
void SetMonthCalFont(
    HFONT hFont,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>parâmetros

*hFont*<br/>
Identificador para a fonte que será definida.

*bRedraw*<br/>
Especifica se o controle deve ser redesenhado imediatamente após a configuração da fonte. Definir esse parâmetro como TRUE faz com que o controle seja redesenhado.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [DTM_SETMCFONT](/windows/win32/Controls/dtm-setmcfont)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#7](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_11.cpp)]

> [!NOTE]
>  Se você usar esse código, você desejará tornar um membro de sua classe derivada de `CDialog`chamada *m_MonthFont* do tipo `CFont`.

##  <a name="setmonthcalstyle"></a>CDateTimeCtrl::SetMonthCalStyle

Define o estilo do controle de calendário do mês suspenso que está associado ao controle do seletor de data e hora atual.

```
DWORD SetMonthCalStyle(DWORD dwStyle);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*dwStyle*|no Um novo estilo de controle de calendário de mês, que é uma combinação bit a bit (ou) dos estilos de controle de calendário mensal. Para obter mais informações, consulte os [estilos de controle de calendário mensal](/windows/win32/Controls/month-calendar-control-styles).|

### <a name="return-value"></a>Valor retornado

O estilo anterior do controle de calendário do mês suspenso.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [DTM_SETMCSTYLE](/windows/win32/Controls/dtm-setmcstyle) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_dateTimeCtrl*, que é usada para acessar programaticamente o controle do seletor de data e hora. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o controle do seletor de data e hora para exibir números de semana, nomes abreviados de dias da semana e nenhum indicador de hoje.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#3](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_12.cpp)]

##  <a name="setrange"></a>CDateTimeCtrl:: SetRange

Define os tempos mínimos e máximos do sistema permitidos para um controle do seletor de data e hora.

```
BOOL SetRange(
    const COleDateTime* pMinRange,
    const COleDateTime* pMaxRange);

BOOL SetRange(
    const CTime* pMinRange,
    const CTime* pMaxRange);
```

### <a name="parameters"></a>parâmetros

*pMinRange*<br/>
Um ponteiro para um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém a hora mais antiga permitida no objeto `CDateTimeCtrl`.

*pMaxRange*<br/>
Um ponteiro para um objeto `COleDateTime` ou um objeto `CTime` que contém a hora mais recente permitida no objeto `CDateTimeCtrl`.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [DTM_SETRANGE](/windows/win32/Controls/dtm-setrange)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC, você pode especificar `COleDateTime` ou `CTime` usos. Se o objeto `COleDateTime` tiver um status nulo, o intervalo será removido. Se o ponteiro de `CTime` ou o ponteiro de `COleDateTime` for nulo, o intervalo será removido.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CDateTimeCtrl:: GetRange](#getrange).

##  <a name="settime"></a>CDateTimeCtrl:: SetTime

Define a hora em um controle de seletor de data e hora.

```
BOOL SetTime(const COleDateTime& timeNew);
BOOL SetTime(const CTime* pTimeNew);
BOOL SetTime(LPSYSTEMTIME pTimeNew = NULL);
```

### <a name="parameters"></a>parâmetros

*timeNew*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que contém o para o qual o controle será definido.

*pTimeNew*<br/>
Na segunda versão acima, um ponteiro para um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém a hora até a qual o controle será definido. Na terceira versão acima, um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a hora até a qual o controle será definido.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [DTM_SETSYSTEMTIME](/windows/win32/Controls/dtm-setsystemtime)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC de `SetTime`, você pode usar as classes `COleDateTime` ou `CTime`, ou pode usar uma estrutura de `SYSTEMTIME` para definir as informações de hora.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#8](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_13.cpp)]

## <a name="see-also"></a>Confira também

[Exemplo de CMNCTRL1 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)
