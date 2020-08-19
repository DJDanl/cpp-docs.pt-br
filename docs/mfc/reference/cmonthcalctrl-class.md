---
title: Classe CMonthCalCtrl
ms.date: 11/04/2016
f1_keywords:
- CMonthCalCtrl
- AFXDTCTL/CMonthCalCtrl
- AFXDTCTL/CMonthCalCtrl::CMonthCalCtrl
- AFXDTCTL/CMonthCalCtrl::Create
- AFXDTCTL/CMonthCalCtrl::GetCalendarBorder
- AFXDTCTL/CMonthCalCtrl::GetCalendarCount
- AFXDTCTL/CMonthCalCtrl::GetCalendarGridInfo
- AFXDTCTL/CMonthCalCtrl::GetCalID
- AFXDTCTL/CMonthCalCtrl::GetColor
- AFXDTCTL/CMonthCalCtrl::GetCurrentView
- AFXDTCTL/CMonthCalCtrl::GetCurSel
- AFXDTCTL/CMonthCalCtrl::GetFirstDayOfWeek
- AFXDTCTL/CMonthCalCtrl::GetMaxSelCount
- AFXDTCTL/CMonthCalCtrl::GetMaxTodayWidth
- AFXDTCTL/CMonthCalCtrl::GetMinReqRect
- AFXDTCTL/CMonthCalCtrl::GetMonthDelta
- AFXDTCTL/CMonthCalCtrl::GetMonthRange
- AFXDTCTL/CMonthCalCtrl::GetRange
- AFXDTCTL/CMonthCalCtrl::GetSelRange
- AFXDTCTL/CMonthCalCtrl::GetToday
- AFXDTCTL/CMonthCalCtrl::HitTest
- AFXDTCTL/CMonthCalCtrl::IsCenturyView
- AFXDTCTL/CMonthCalCtrl::IsDecadeView
- AFXDTCTL/CMonthCalCtrl::IsMonthView
- AFXDTCTL/CMonthCalCtrl::IsYearView
- AFXDTCTL/CMonthCalCtrl::SetCalendarBorder
- AFXDTCTL/CMonthCalCtrl::SetCalendarBorderDefault
- AFXDTCTL/CMonthCalCtrl::SetCalID
- AFXDTCTL/CMonthCalCtrl::SetCenturyView
- AFXDTCTL/CMonthCalCtrl::SetColor
- AFXDTCTL/CMonthCalCtrl::SetCurrentView
- AFXDTCTL/CMonthCalCtrl::SetCurSel
- AFXDTCTL/CMonthCalCtrl::SetDayState
- AFXDTCTL/CMonthCalCtrl::SetDecadeView
- AFXDTCTL/CMonthCalCtrl::SetFirstDayOfWeek
- AFXDTCTL/CMonthCalCtrl::SetMaxSelCount
- AFXDTCTL/CMonthCalCtrl::SetMonthDelta
- AFXDTCTL/CMonthCalCtrl::SetMonthView
- AFXDTCTL/CMonthCalCtrl::SetRange
- AFXDTCTL/CMonthCalCtrl::SetSelRange
- AFXDTCTL/CMonthCalCtrl::SetToday
- AFXDTCTL/CMonthCalCtrl::SetYearView
- AFXDTCTL/CMonthCalCtrl::SizeMinReq
- AFXDTCTL/CMonthCalCtrl::SizeRectToMin
helpviewer_keywords:
- CMonthCalCtrl [MFC], CMonthCalCtrl
- CMonthCalCtrl [MFC], Create
- CMonthCalCtrl [MFC], GetCalendarBorder
- CMonthCalCtrl [MFC], GetCalendarCount
- CMonthCalCtrl [MFC], GetCalendarGridInfo
- CMonthCalCtrl [MFC], GetCalID
- CMonthCalCtrl [MFC], GetColor
- CMonthCalCtrl [MFC], GetCurrentView
- CMonthCalCtrl [MFC], GetCurSel
- CMonthCalCtrl [MFC], GetFirstDayOfWeek
- CMonthCalCtrl [MFC], GetMaxSelCount
- CMonthCalCtrl [MFC], GetMaxTodayWidth
- CMonthCalCtrl [MFC], GetMinReqRect
- CMonthCalCtrl [MFC], GetMonthDelta
- CMonthCalCtrl [MFC], GetMonthRange
- CMonthCalCtrl [MFC], GetRange
- CMonthCalCtrl [MFC], GetSelRange
- CMonthCalCtrl [MFC], GetToday
- CMonthCalCtrl [MFC], HitTest
- CMonthCalCtrl [MFC], IsCenturyView
- CMonthCalCtrl [MFC], IsDecadeView
- CMonthCalCtrl [MFC], IsMonthView
- CMonthCalCtrl [MFC], IsYearView
- CMonthCalCtrl [MFC], SetCalendarBorder
- CMonthCalCtrl [MFC], SetCalendarBorderDefault
- CMonthCalCtrl [MFC], SetCalID
- CMonthCalCtrl [MFC], SetCenturyView
- CMonthCalCtrl [MFC], SetColor
- CMonthCalCtrl [MFC], SetCurrentView
- CMonthCalCtrl [MFC], SetCurSel
- CMonthCalCtrl [MFC], SetDayState
- CMonthCalCtrl [MFC], SetDecadeView
- CMonthCalCtrl [MFC], SetFirstDayOfWeek
- CMonthCalCtrl [MFC], SetMaxSelCount
- CMonthCalCtrl [MFC], SetMonthDelta
- CMonthCalCtrl [MFC], SetMonthView
- CMonthCalCtrl [MFC], SetRange
- CMonthCalCtrl [MFC], SetSelRange
- CMonthCalCtrl [MFC], SetToday
- CMonthCalCtrl [MFC], SetYearView
- CMonthCalCtrl [MFC], SizeMinReq
- CMonthCalCtrl [MFC], SizeRectToMin
ms.assetid: a42f6bd6-ab5c-4335-82f8-839982fc64a2
ms.openlocfilehash: d986aa5f8e232f0ab94858dbdfae5754536ccdb9
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562136"
---
# <a name="cmonthcalctrl-class"></a>Classe CMonthCalCtrl

Encapsula a funcionalidade de um controle de calendário mensal.

## <a name="syntax"></a>Sintaxe

```
class CMonthCalCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMonthCalCtrl::CMonthCalCtrl](#cmonthcalctrl)|Constrói um objeto `CMonthCalCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMonthCalCtrl:: criar](#create)|Cria um controle de calendário mensal e anexa-o ao `CMonthCalCtrl` objeto.|
|[CMonthCalCtrl::GetCalendarBorder](#getcalendarborder)|Recupera a largura da borda do controle de calendário do mês atual.|
|[CMonthCalCtrl::GetCalendarCount](#getcalendarcount)|Recupera o número de calendários exibidos no controle de calendário do mês atual.|
|[CMonthCalCtrl::GetCalendarGridInfo](#getcalendargridinfo)|Recupera informações sobre o controle de calendário do mês atual.|
|[CMonthCalCtrl::GetCalID](#getcalid)|Recupera o identificador de calendário do controle de calendário do mês atual.|
|[CMonthCalCtrl:: GetColor](#getcolor)|Obtém a cor de uma área especificada de um controle de calendário mensal.|
|[CMonthCalCtrl::GetCurrentView](#getcurrentview)|Recupera a exibição que é exibida atualmente pelo controle de calendário do mês atual.|
|[CMonthCalCtrl:: GetCurSel](#getcursel)|Recupera a hora do sistema conforme indicado pela data atualmente selecionada.|
|[CMonthCalCtrl:: getFirstDayOfWeek](#getfirstdayofweek)|Obtém o primeiro dia da semana a ser exibido na coluna mais à esquerda do calendário.|
|[CMonthCalCtrl::GetMaxSelCount](#getmaxselcount)|Recupera o número máximo atual de dias que podem ser selecionados em um controle de calendário mensal.|
|[CMonthCalCtrl::GetMaxTodayWidth](#getmaxtodaywidth)|Recupera a largura máxima da cadeia de caracteres "hoje" para o controle de calendário do mês atual.|
|[CMonthCalCtrl::GetMinReqRect](#getminreqrect)|Recupera o tamanho mínimo necessário para mostrar um mês inteiro em um controle de calendário mensal.|
|[CMonthCalCtrl::GetMonthDelta](#getmonthdelta)|Recupera a taxa de rolagem para um controle de calendário mensal.|
|[CMonthCalCtrl::GetMonthRange](#getmonthrange)|Recupera as informações de data que representam os limites altos e baixos da exibição de um controle de calendário mensal.|
|[CMonthCalCtrl:: GetRange](#getrange)|Recupera as datas mínimas e máximas atuais definidas em um controle de calendário mensal.|
|[CMonthCalCtrl::GetSelRange](#getselrange)|Recupera informações de data que representam os limites superior e inferior do intervalo de datas selecionado no momento pelo usuário.|
|[CMonthCalCtrl:: gethoje](#gettoday)|Recupera as informações de data da data especificada como "hoje" para um controle de calendário mensal.|
|[CMonthCalCtrl:: HitTest](#hittest)|Determina qual seção de um controle de calendário mensal está em um determinado ponto na tela.|
|[CMonthCalCtrl::IsCenturyView](#iscenturyview)|Indica se a exibição atual do controle de calendário do mês atual é a exibição do século.|
|[CMonthCalCtrl::IsDecadeView](#isdecadeview)|Indica se a exibição atual do controle de calendário mensal atual é a exibição de década.|
|[CMonthCalCtrl::IsMonthView](#ismonthview)|Indica se a exibição atual do controle de calendário do mês atual é a exibição de mês.|
|[CMonthCalCtrl::IsYearView](#isyearview)|Indica se a exibição atual do controle de calendário do mês atual é a exibição de ano.|
|[CMonthCalCtrl::SetCalendarBorder](#setcalendarborder)|Define a largura da borda do controle de calendário do mês atual.|
|[CMonthCalCtrl::SetCalendarBorderDefault](#setcalendarborderdefault)|Define a largura padrão da borda do controle de calendário do mês atual.|
|[CMonthCalCtrl::SetCalID](#setcalid)|Define o identificador de calendário para o controle de calendário mensal atual.|
|[CMonthCalCtrl::SetCenturyView](#setcenturyview)|Define o controle de calendário do mês atual para exibir a exibição do século.|
|[CMonthCalCtrl:: setColor](#setcolor)|Define a cor de uma área especificada de um controle de calendário mensal.|
|[CMonthCalCtrl::SetCurrentView](#setcurrentview)|Define o controle de calendário do mês atual para exibir a exibição especificada.|
|[CMonthCalCtrl:: setcurseal](#setcursel)|Define a data atualmente selecionada para um controle de calendário mensal.|
|[CMonthCalCtrl::SetDayState](#setdaystate)|Define a exibição para dias em um controle de calendário mensal.|
|[CMonthCalCtrl::SetDecadeView](#setdecadeview)|Define o controle de calendário do mês atual como a exibição de década.|
|[CMonthCalCtrl:: setFirstDayOfWeek](#setfirstdayofweek)|Define o dia da semana a ser exibido na coluna mais à esquerda do calendário.|
|[CMonthCalCtrl::SetMaxSelCount](#setmaxselcount)|Define o número máximo de dias que podem ser selecionados em um controle de calendário mensal.|
|[CMonthCalCtrl::SetMonthDelta](#setmonthdelta)|Define a taxa de rolagem para um controle de calendário mensal.|
|[CMonthCalCtrl::SetMonthView](#setmonthview)|Define o controle de calendário do mês atual para exibir a exibição de mês.|
|[CMonthCalCtrl:: SetRange](#setrange)|Define as datas mínimas e máximas permitidas para um controle de calendário mensal.|
|[CMonthCalCtrl::SetSelRange](#setselrange)|Define a seleção de um controle de calendário de mês para um determinado intervalo de datas.|
|[CMonthCalCtrl:: sethoje](#settoday)|Define o controle de calendário para o dia atual.|
|[CMonthCalCtrl::SetYearView](#setyearview)|Define o controle de calendário do mês atual como exibição de ano.|
|[CMonthCalCtrl::SizeMinReq](#sizeminreq)|Redesenha o controle de calendário mensal para seu tamanho mínimo de um mês.|
|[CMonthCalCtrl::SizeRectToMin](#sizerecttomin)|Para o controle de calendário mensal atual, calcula o menor retângulo que pode conter todos os calendários que se ajustam a um retângulo especificado.|

## <a name="remarks"></a>Comentários

O controle de calendário mensal fornece ao usuário uma interface de calendário simples, na qual o usuário pode selecionar uma data. O usuário pode alterar a exibição por:

- Rolando para trás e para frente, de mês a mês.

- Clicando no texto hoje para exibir o dia atual (se o estilo de MCS_NOTODAY não for usado).

- Selecionando um mês ou um ano a partir de um menu pop-up.

Você pode personalizar o controle de calendário mensal aplicando uma variedade de estilos ao objeto ao criá-lo. Esses estilos são descritos em [estilos de controle de calendário mensal](/windows/win32/Controls/month-calendar-control-styles) na SDK do Windows.

O controle de calendário mensal pode exibir mais de um mês e pode indicar dias especiais (como feriados) ao negrito da data.

Para obter mais informações sobre como usar o controle de calendário mensal, consulte [usando CMonthCalCtrl](../../mfc/using-cmonthcalctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CMonthCalCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDTCTL. h

## <a name="cmonthcalctrlcmonthcalctrl"></a><a name="cmonthcalctrl"></a> CMonthCalCtrl::CMonthCalCtrl

Constrói um objeto `CMonthCalCtrl`.

```
CMonthCalCtrl();
```

### <a name="remarks"></a>Comentários

Você deve chamar `Create` depois de construir o objeto.

## <a name="cmonthcalctrlcreate"></a><a name="create"></a> CMonthCalCtrl:: criar

Cria um controle de calendário mensal e anexa-o ao `CMonthCalCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);

virtual BOOL Create(
    DWORD dwStyle,
    const POINT& pt,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica a combinação de estilos do Windows aplicada ao controle de calendário mensal. Consulte [estilos de controle de calendário mensal](/windows/win32/Controls/month-calendar-control-styles) na SDK do Windows para obter mais informações sobre os estilos.

*Rect*<br/>
Uma referência a uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) . Contém a posição e o tamanho do controle de calendário mensal.

*pt*<br/>
Uma referência a uma estrutura de [ponto](/windows/win32/api/windef/ns-windef-point) que identifica o local do controle de calendário mensal.

*pParentWnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle de calendário mensal. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID de controle do controle de calendário de mês.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a inicialização tiver sido bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Crie um controle de calendário mensal em duas etapas:

1. Chame [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md) para construir um `CMonthCalCtrl` objeto.

1. Chame essa função de membro, que cria um controle de calendário mensal e o anexa ao `CMonthCalCtrl` objeto.

Quando você chama `Create` , os controles comuns são inicializados. A versão da `Create` chamada determina como ele é dimensionado:

- Para que o MFC dimensione automaticamente o controle para um mês, chame a substituição que usa o parâmetro *pt* .

- Para dimensionar o controle por conta própria, chame a substituição dessa função que usa o parâmetro *Rect* .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#1](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_1.cpp)]

## <a name="cmonthcalctrlgetcalendarborder"></a><a name="getcalendarborder"></a> CMonthCalCtrl::GetCalendarBorder

Recupera a largura da borda do controle de calendário do mês atual.

```
int GetCalendarBorder() const;
```

### <a name="return-value"></a>Valor retornado

A largura da borda do controle, em pixels.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [MCM_GETCALENDARBORDER](/windows/win32/Controls/mcm-getcalendarborder) , que é descrita na SDK do Windows.

## <a name="cmonthcalctrlgetcalendarcount"></a><a name="getcalendarcount"></a> CMonthCalCtrl::GetCalendarCount

Recupera o número de calendários exibidos no controle de calendário do mês atual.

```
int GetCalendarCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de calendários atualmente exibidos no controle de calendário mensal. O número máximo permitido de calendários é 12.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [MCM_GETCALENDARCOUNT](/windows/win32/Controls/mcm-getcalendarcount) , que é descrita na SDK do Windows.

## <a name="cmonthcalctrlgetcalendargridinfo"></a><a name="getcalendargridinfo"></a> CMonthCalCtrl::GetCalendarGridInfo

Recupera informações sobre o controle de calendário do mês atual.

```
BOOL GetCalendarGridInfo(PMCGRIDINFO pmcGridInfo) const;
```

### <a name="parameters"></a>Parâmetros

*pmcGridInfo*\
fora Ponteiro para uma estrutura [MCGRIDINFO](/windows/win32/api/commctrl/ns-commctrl-mcgridinfo) que recebe informações sobre o controle de calendário do mês atual. O chamador é responsável por alocar e inicializar essa estrutura.

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [MCM_GETCALENDARGRIDINFO](/windows/win32/Controls/mcm-getcalendargridinfo) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_monthCalCtrl` , que é usada para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir usa o `GetCalendarGridInfo` método para recuperar a data do calendário que o controle de calendário do mês atual exibe.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#3](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_3.cpp)]

## <a name="cmonthcalctrlgetcalid"></a><a name="getcalid"></a> CMonthCalCtrl::GetCalID

Recupera o identificador de calendário do controle de calendário do mês atual.

```
CALID GetCalID() const;
```

### <a name="return-value"></a>Valor retornado

Uma das constantes de [identificador de calendário](/windows/win32/Intl/calendar-identifiers) .

### <a name="remarks"></a>Comentários

Um identificador de calendário denota um calendário específico da região, como os calendários gregoriano (localizado), japonês ou islâmico. Seu aplicativo pode usar um identificador de calendário que tem várias funções de suporte de idioma.

Esse método envia a mensagem de [MCM_GETCALID](/windows/win32/Controls/mcm-getcalid) , que é descrita na SDK do Windows.

## <a name="cmonthcalctrlgetcolor"></a><a name="getcolor"></a> CMonthCalCtrl:: GetColor

Recupera a cor de uma área do controle de calendário mensal especificada por *nRegion*.

```
COLORREF GetColor(int nRegion) const;
```

### <a name="parameters"></a>Parâmetros

*nRegion*<br/>
A região do controle de calendário mensal do qual a cor é recuperada. Para obter uma lista de valores, consulte o parâmetro *nRegion* de [setColor](#setcolor).

### <a name="return-value"></a>Valor retornado

Um valor de [COLORREF](/windows/win32/gdi/colorref) que especifica a cor associada à parte do controle de calendário mensal, se for bem-sucedido. Caso contrário, essa função de membro retornará-1.

## <a name="cmonthcalctrlgetcurrentview"></a><a name="getcurrentview"></a> CMonthCalCtrl::GetCurrentView

Recupera a exibição que é exibida atualmente pelo controle de calendário do mês atual.

```
DWORD GetCurrentView() const;
```

### <a name="return-value"></a>Valor retornado

A exibição atual, que é indicada por um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|MCMV_MONTH|Exibição mensal|
|MCMV_YEAR|Exibição anual|
|MCMV_DECADE|Exibição de década|
|MCMV_CENTURY|Exibição do século|

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [MCM_GETCURRENTVIEW](/windows/win32/Controls/mcm-getcurrentview) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_monthCalCtrl` , que é usada para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir relata qual exibição do controle de calendário mensal exibe atualmente.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#7](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_4.cpp)]

## <a name="cmonthcalctrlgetcursel"></a><a name="getcursel"></a> CMonthCalCtrl:: GetCurSel

Recupera a hora do sistema conforme indicado pela data atualmente selecionada.

```
BOOL GetCurSel(COleDateTime& refDateTime) const;  BOOL GetCurSel(CTime& refDateTime) const;

BOOL GetCurSel(LPSYSTEMTIME pDateTime) const;
```

### <a name="parameters"></a>Parâmetros

*refDateTime*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou a um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) . Recebe a hora atual.

*pDateTime*<br/>
Um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que receberá as informações de data atualmente selecionadas. Esse parâmetro deve ser um endereço válido e não pode ser nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; otherwize 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_GETCURSEL](/windows/win32/Controls/mcm-getcursel)de mensagens Win32, conforme descrito no SDK do Windows.

> [!NOTE]
> Essa função de membro falhará se o MCS_MULTISELECT de estilo estiver definido.

Na implementação do MFC do `GetCurSel` , você pode especificar um uso `COleDateTime` , um uso `CTime` ou um `SYSTEMTIME` uso de estrutura.

## <a name="cmonthcalctrlgetfirstdayofweek"></a><a name="getfirstdayofweek"></a> CMonthCalCtrl:: getFirstDayOfWeek

Obtém o primeiro dia da semana a ser exibido na coluna mais à esquerda do calendário.

```
int GetFirstDayOfWeek(BOOL* pbLocal = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*pbLocal*<br/>
Um ponteiro para um valor BOOL. Se o valor for diferente de zero, a configuração do controle não corresponderá à configuração no painel de controle.

### <a name="return-value"></a>Valor retornado

Um valor inteiro que representa o primeiro dia da semana. Consulte **comentários** para obter mais informações sobre o que esses inteiros representam.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_GETFIRSTDAYOFWEEK](/windows/win32/Controls/mcm-getfirstdayofweek)de mensagens Win32, conforme descrito no SDK do Windows. Os dias da semana são representados como inteiros, da seguinte maneira.

|Valor|Dia da semana|
|-----------|---------------------|
|0|Monday|
|1|Terça-feira|
|2|Quarta-feira|
|3|Quinta-feira|
|4|Friday|
|5|Sábado|
|6|Sunday|

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMonthCalCtrl:: setFirstDayOfWeek](#setfirstdayofweek).

## <a name="cmonthcalctrlgetmaxselcount"></a><a name="getmaxselcount"></a> CMonthCalCtrl::GetMaxSelCount

Recupera o número máximo atual de dias que podem ser selecionados em um controle de calendário mensal.

```
int GetMaxSelCount() const;
```

### <a name="return-value"></a>Valor retornado

Um valor inteiro que representa o número total de dias que podem ser selecionados para o controle.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_GETMAXSELCOUNT](/windows/win32/Controls/mcm-getmaxselcount)de mensagens Win32, conforme descrito no SDK do Windows. Use essa função de membro para controles com o estilo de MCS_MULTISELECT definido.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMonthCalCtrl:: SetMaxSelCount](#setmaxselcount).

## <a name="cmonthcalctrlgetmaxtodaywidth"></a><a name="getmaxtodaywidth"></a> CMonthCalCtrl::GetMaxTodayWidth

Recupera a largura máxima da cadeia de caracteres "hoje" para o controle de calendário do mês atual.

```
DWORD GetMaxTodayWidth() const;
```

### <a name="return-value"></a>Valor retornado

A largura da cadeia de caracteres "Today", em pixels.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_monthCalCtrl` , que é usada para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra o `GetMaxTodayWidth` método.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_5.cpp)]

### <a name="remarks"></a>Comentários

O usuário pode retornar à data atual clicando na cadeia de caracteres "hoje", que é exibida na parte inferior do controle de calendário mensal. A cadeia de caracteres "hoje" inclui texto de rótulo e texto de data.

Esse método envia a mensagem de [MCM_GETMAXTODAYWIDTH](/windows/win32/Controls/mcm-getmaxtodaywidth) , que é descrita na SDK do Windows.

## <a name="cmonthcalctrlgetminreqrect"></a><a name="getminreqrect"></a> CMonthCalCtrl::GetMinReqRect

Recupera o tamanho mínimo necessário para mostrar um mês inteiro em um controle de calendário mensal.

```
BOOL GetMinReqRect(RECT* pRect) const;
```

### <a name="parameters"></a>Parâmetros

*pRect*<br/>
Um ponteiro para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) que receberá informações de retângulo delimitador. Esse parâmetro deve ser um endereço válido e não pode ser nulo.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedida, essa função de membro retornará zero e `lpRect` receberá as informações delimitadas aplicáveis. Se não for bem-sucedida, a função de membro retornará 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_GETMINREQRECT](/windows/win32/Controls/mcm-getminreqrect)de mensagens Win32, conforme descrito no SDK do Windows.

## <a name="cmonthcalctrlgetmonthdelta"></a><a name="getmonthdelta"></a> CMonthCalCtrl::GetMonthDelta

Recupera a taxa de rolagem para um controle de calendário mensal.

```
int GetMonthDelta() const;
```

### <a name="return-value"></a>Valor retornado

A taxa de rolagem do controle de calendário mensal. A taxa de rolagem é o número de meses que o controle move sua exibição quando o usuário clica em um botão de rolagem uma vez.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_GETMONTHDELTA](/windows/win32/Controls/mcm-getmonthdelta)de mensagens Win32, conforme descrito no SDK do Windows.

## <a name="cmonthcalctrlgetmonthrange"></a><a name="getmonthrange"></a> CMonthCalCtrl::GetMonthRange

Recupera as informações de data que representam os limites altos e baixos da exibição de um controle de calendário mensal.

```
int GetMonthRange(
    COleDateTime& refMinRange,
    COleDateTime& refMaxRange,
    DWORD dwFlags) const;

int GetMonthRange(
    CTime& refMinRange,
    CTime& refMaxRange,
    DWORD dwFlags) const;

int GetMonthRange(
    LPSYSTEMTIME pMinRange,
    LPSYSTEMTIME pMaxRange,
    DWORD dwFlags) const;
```

### <a name="parameters"></a>Parâmetros

*refMinRange*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém a data mínima permitida.

*refMaxRange*<br/>
Uma referência a um `COleDateTime` `CTime` objeto ou que contém a data máxima permitida.

*pMinRange*<br/>
Um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a data na extremidade inferior do intervalo.

*pMaxRange*<br/>
Um ponteiro para uma `SYSTEMTIME` estrutura que contém a data na extremidade mais alta do intervalo.

*dwFlags*<br/>
Valor que especifica o escopo dos limites de intervalo a serem recuperados. Esse valor deve ser um dos seguintes.

|Valor|Significado|
|-----------|-------------|
|GMR_DAYSTATE|Incluir meses anteriores e posteriores do intervalo visível que são exibidos apenas parcialmente.|
|GMR_VISIBLE|Inclua somente os meses que são totalmente exibidos.|

### <a name="return-value"></a>Valor retornado

Um inteiro que representa o intervalo, em meses, estendido pelos dois limites indicados por *refMinRange* e *refMaxRange* na primeira e segunda versões, ou *pMinRange* e *pMaxRange* na terceira versão.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_GETMONTHRANGE](/windows/win32/Controls/mcm-getmonthrange)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC do `GetMonthRange` , você pode especificar `COleDateTime` uso, um `CTime` uso ou um `SYSTEMTIME` uso de estrutura.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMonthCalCtrl:: SetDayState](#setdaystate).

## <a name="cmonthcalctrlgetrange"></a><a name="getrange"></a> CMonthCalCtrl:: GetRange

Recupera as datas mínimas e máximas atuais definidas em um controle de calendário mensal.

```
DWORD GetRange(
    COleDateTime* pMinRange,
    COleDateTime* pMaxRange) const;

DWORD GetRange(
    CTime* pMinRange,
    CTime* pMaxRange) const;

DWORD GetRange(
    LPSYSTEMTIME pMinRange,
    LPSYSTEMTIME pMaxRange) const;
```

### <a name="parameters"></a>Parâmetros

*pMinRange*<br/>
Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto ou uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a data na extremidade inferior do intervalo.

*pMaxRange*<br/>
Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto ou uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a data na extremidade mais alta do intervalo.

### <a name="return-value"></a>Valor retornado

Um DWORD que pode ser zero (nenhum limite é definido) ou uma combinação dos valores a seguir que especificam informações de limite.

|Valor|Significado|
|-----------|-------------|
|GDTR_MAX|Um limite máximo é definido para o controle; *pMaxRange* é válido e contém as informações de data aplicáveis.|
|GDTR_MIN|Um limite mínimo é definido para o controle; *pMinRange* é válido e contém as informações de data aplicáveis.|

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_GETRANGE](/windows/win32/Controls/mcm-getrange)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC do `GetRange` , você pode especificar um uso `COleDateTime` , um uso `CTime` ou um `SYSTEMTIME` uso de estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#2](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_6.cpp)]

## <a name="cmonthcalctrlgetselrange"></a><a name="getselrange"></a> CMonthCalCtrl::GetSelRange

Recupera informações de data que representam os limites superior e inferior do intervalo de datas selecionado no momento pelo usuário.

```
BOOL GetSelRange(
    COleDateTime& refMinRange,
    COleDateTime& refMaxRange) const;

BOOL GetSelRange(
    CTime& refMinRange,
    CTime& refMaxRange) const;

BOOL GetSelRange(
    LPSYSTEMTIME pMinRange,
    LPSYSTEMTIME pMaxRange) const;
```

### <a name="parameters"></a>Parâmetros

*refMinRange*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém a data mínima permitida.

*refMaxRange*<br/>
Uma referência a um `COleDateTime` `CTime` objeto ou que contém a data máxima permitida.

*pMinRange*<br/>
Um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a data na extremidade inferior do intervalo.

*pMaxRange*<br/>
Um ponteiro para uma `SYSTEMTIME` estrutura que contém a data na extremidade mais alta do intervalo.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_GETSELRANGE](/windows/win32/Controls/mcm-getselrange)de mensagens Win32, conforme descrito no SDK do Windows. `GetSelRange` falhará se aplicado a um controle de calendário de mês que não usa o estilo de MCS_MULTISELECT.

Na implementação do MFC do `GetSelRange` , você pode especificar `COleDateTime` uso, um `CTime` uso ou um `SYSTEMTIME` uso de estrutura.

## <a name="cmonthcalctrlgettoday"></a><a name="gettoday"></a> CMonthCalCtrl:: gethoje

Recupera as informações de data da data especificada como "hoje" para um controle de calendário mensal.

```
BOOL GetToday(COleDateTime& refDateTime) const;  BOOL GetToday(COleDateTime& refDateTime) const;

BOOL GetToday(LPSYSTEMTIME pDateTime) const;
```

### <a name="parameters"></a>Parâmetros

*refDateTime*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) que indica o dia atual.

*pDateTime*<br/>
Um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que receberá as informações de data. Esse parâmetro deve ser um endereço válido e não pode ser nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_GETTODAY](/windows/win32/Controls/mcm-gettoday)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC do `GetToday` , você pode especificar um uso `COleDateTime` , um uso `CTime` ou um `SYSTEMTIME` uso de estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#3](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_7.cpp)]

## <a name="cmonthcalctrlhittest"></a><a name="hittest"></a> CMonthCalCtrl:: HitTest

Determina qual controle de calendário mensal, se houver, está em uma posição especificada.

```
DWORD HitTest(PMCHITTESTINFO pMCHitTest);
```

### <a name="parameters"></a>Parâmetros

*pMCHitTest*<br/>
Um ponteiro para uma estrutura [MCHITTESTINFO](/windows/win32/api/commctrl/ns-commctrl-mchittestinfo) que contém pontos de teste de clique para o controle de calendário mensal.

### <a name="return-value"></a>Valor retornado

Um valor DWORD. Igual ao membro **uHit** da `MCHITTESTINFO` estrutura.

### <a name="remarks"></a>Comentários

`HitTest` usa a `MCHITTESTINFO` estrutura, que contém informações sobre o teste de clique.

## <a name="cmonthcalctrliscenturyview"></a><a name="iscenturyview"></a> CMonthCalCtrl::IsCenturyView

Indica se a exibição atual do controle de calendário do mês atual é a exibição do século.

```
BOOL IsCenturyView() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a exibição atual for a exibição do século; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [MCM_GETCURRENTVIEW](/windows/win32/Controls/mcm-getcurrentview) , que é descrita na SDK do Windows. Se essa mensagem retornar MCMV_CENTURY, esse método retornará TRUE.

## <a name="cmonthcalctrlisdecadeview"></a><a name="isdecadeview"></a> CMonthCalCtrl::IsDecadeView

Indica se a exibição atual do controle de calendário mensal atual é a exibição de década.

```
BOOL IsDecadeView() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a exibição atual for a exibição de década; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [MCM_GETCURRENTVIEW](/windows/win32/Controls/mcm-getcurrentview) , que é descrita na SDK do Windows. Se essa mensagem retornar MCMV_DECADE, esse método retornará TRUE.

## <a name="cmonthcalctrlismonthview"></a><a name="ismonthview"></a> CMonthCalCtrl::IsMonthView

Indica se a exibição atual do controle de calendário do mês atual é a exibição de mês.

```
BOOL IsMonthView() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a exibição atual for o modo de exibição de mês; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [MCM_GETCURRENTVIEW](/windows/win32/Controls/mcm-getcurrentview) , que é descrita na SDK do Windows. Se essa mensagem retornar MCMV_MONTH, esse método retornará TRUE.

## <a name="cmonthcalctrlisyearview"></a><a name="isyearview"></a> CMonthCalCtrl::IsYearView

Indica se a exibição atual do controle de calendário do mês atual é a exibição de ano.

```
BOOL IsYearView() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a exibição atual for a exibição de ano; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [MCM_GETCURRENTVIEW](/windows/win32/Controls/mcm-getcurrentview) , que é descrita na SDK do Windows. Se essa mensagem retornar MCMV_YEAR, esse método retornará TRUE.

## <a name="cmonthcalctrlsetcalendarborder"></a><a name="setcalendarborder"></a> CMonthCalCtrl::SetCalendarBorder

Define a largura da borda do controle de calendário do mês atual.

```cpp
void SetCalendarBorder(int cxyBorder);
```

### <a name="parameters"></a>Parâmetros

*cxyBorder*\
no A largura da borda, em pixels.

### <a name="remarks"></a>Comentários

Se esse método tiver sucesso, a largura da borda será definida como o parâmetro *cxyBorder* . Caso contrário, a largura da borda será redefinida para o valor padrão especificado pelo [tema](/windows/win32/Controls/visual-styles-overview)atual ou zero se os temas não forem usados.

Esse método envia a mensagem de [MCM_SETCALENDARBORDER](/windows/win32/Controls/mcm-setcalendarborder) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_monthCalCtrl` , que é usada para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a largura da borda do controle de calendário mensal como oito pixels. Use o método [CMonthCalCtrl:: GetCalendarBorder](#getcalendarborder) para determinar se esse método foi bem-sucedido.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#6](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_8.cpp)]

## <a name="cmonthcalctrlsetcalendarborderdefault"></a><a name="setcalendarborderdefault"></a> CMonthCalCtrl::SetCalendarBorderDefault

Define a largura padrão da borda do controle de calendário do mês atual.

```cpp
void SetCalendarBorderDefault();
```

### <a name="remarks"></a>Comentários

A largura da borda será definida como o valor padrão especificado pelo [tema](/windows/win32/Controls/visual-styles-overview)atual ou zero se os temas não forem usados.

Esse método envia a mensagem de [MCM_SETCALENDARBORDER](/windows/win32/Controls/mcm-setcalendarborder) , que é descrita na SDK do Windows.

## <a name="cmonthcalctrlsetcalid"></a><a name="setcalid"></a> CMonthCalCtrl::SetCalID

Define o identificador de calendário para o controle de calendário mensal atual.

```
BOOL SetCalID(CALID calid);
```

### <a name="parameters"></a>Parâmetros

*calid*\
no Uma das constantes de [identificador de calendário](/windows/win32/Intl/calendar-identifiers) .

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um identificador de calendário especifica um calendário específico da região, como os calendários gregoriano (localizado), japonês ou islâmico. Use o `SetCalID` método para exibir um calendário especificado pelo parâmetro *calid* se a localidade que contém o calendário estiver instalada no computador.

Esse método envia a mensagem de [MCM_SETCALID](/windows/win32/Controls/mcm-setcalid) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_monthCalCtrl` , que é usada para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o controle de calendário mensal para exibir o calendário da era do imperador japonês. O `SetCalID` método terá sucesso apenas se esse calendário estiver instalado no seu computador.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#4](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_9.cpp)]

## <a name="cmonthcalctrlsetcenturyview"></a><a name="setcenturyview"></a> CMonthCalCtrl::SetCenturyView

Define o controle de calendário do mês atual para exibir a exibição do século.

```
BOOL SetCenturyView();
```

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método usa o método [CMonthCalCtrl:: SetCurrentView](#setcurrentview) para definir a exibição como `MCMV_CENTURY` , que representa a exibição de Century.

## <a name="cmonthcalctrlsetcolor"></a><a name="setcolor"></a> CMonthCalCtrl:: setColor

Define a cor de uma área especificada de um controle de calendário mensal.

```
COLORREF SetColor(
    int nRegion,
    COLORREF ref);
```

### <a name="parameters"></a>Parâmetros

*nRegion*<br/>
Um valor inteiro que especifica qual cor de calendário de mês definir. Esse valor pode ser um dos seguintes.

|Valor|Significado|
|-----------|-------------|
|MCSC_BACKGROUND|A cor do plano de fundo exibida entre meses.|
|MCSC_MONTHBK|A cor do plano de fundo exibida no mês.|
|MCSC_TEXT|A cor usada para exibir o texto em um mês.|
|MCSC_TITLEBK|A cor do plano de fundo exibida no título do calendário.|
|MCSC_TITLETEXT|A cor usada para exibir texto dentro do título do calendário.|
|MCSC_TRAILINGTEXT|A cor usada para exibir o texto do cabeçalho e do dia final. Os dias de cabeçalho e à direita são os dias dos meses anteriores e seguintes que aparecem no calendário atual.|

*referência*<br/>
Um valor de COLORREF para a nova configuração de cor para a parte especificada do controle de calendário mensal.

### <a name="return-value"></a>Valor retornado

Um valor de COLORREF que representa a configuração de cor anterior para a parte especificada do controle de calendário mensal, se for bem-sucedido. Caso contrário, essa mensagem retornará-1.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_SETCOLOR](/windows/win32/Controls/mcm-setcolor)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#4](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_10.cpp)]

## <a name="cmonthcalctrlsetcurrentview"></a><a name="setcurrentview"></a> CMonthCalCtrl::SetCurrentView

Define o controle de calendário do mês atual para exibir a exibição especificada.

```
BOOL SetCurrentView(DWORD dwNewView);
```

### <a name="parameters"></a>Parâmetros

*dwNewView*\
no Um dos valores a seguir que especifica uma exibição mensal, anual, década ou Century.

- `MCMV_MONTH`: Exibição mensal
- `MCMV_YEAR`: Exibição anual
- `MCMV_DECADE`: Exibição de década
- `MCMV_CENTURY`: Exibição de século

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [MCM_SETCURRENTVIEW](/windows/win32/Controls/mcm-setcurrentview) , que é descrita na SDK do Windows.

## <a name="cmonthcalctrlsetcursel"></a><a name="setcursel"></a> CMonthCalCtrl:: setcurseal

Define a data atualmente selecionada para um controle de calendário mensal.

```
BOOL SetCurSel(const COleDateTime& refDateTime);
BOOL SetCurSel(const CTime& refDateTime);
BOOL SetCurSel(const LPSYSTEMTIME pDateTime);
```

### <a name="parameters"></a>Parâmetros

*refDateTime*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) que indica o controle de calendário de mês selecionado atualmente.

*pDateTime*<br/>
Ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a data a ser definida como a seleção atual.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_SETCURSEL](/windows/win32/Controls/mcm-setcursel)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC do `SetCurSel` , você pode especificar um uso `COleDateTime` , um uso `CTime` ou um `SYSTEMTIME` uso de estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#5](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_11.cpp)]

## <a name="cmonthcalctrlsetdaystate"></a><a name="setdaystate"></a> CMonthCalCtrl::SetDayState

Define a exibição para dias em um controle de calendário mensal.

```
BOOL SetDayState(
    int nMonths,
    LPMONTHDAYSTATE pStates);
```

### <a name="parameters"></a>Parâmetros

*nMonths*<br/>
Valor indicando quantos elementos estão na matriz para a qual *pStates* aponta.

*pStates*<br/>
Um ponteiro para uma matriz [MONTHDAYSTATE](/windows/win32/Controls/monthdaystate) de valores que define como o controle de calendário mensal será desenhado todos os dias em sua exibição. O tipo de dados MONTHDAYSTATE é um campo de bits, em que cada bit (de 1 a 31) representa o estado de um dia em um mês. Se um bit for on, o dia correspondente será exibido em negrito; caso contrário, ele será exibido sem ênfase.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_SETDAYSTATE](/windows/win32/Controls/mcm-setdaystate)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#6](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_12.cpp)]

## <a name="cmonthcalctrlsetdecadeview"></a><a name="setdecadeview"></a> CMonthCalCtrl::SetDecadeView

Define o controle de calendário do mês atual como a exibição de década.

```
BOOL SetDecadeView();
```

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método usa o método [CMonthCalCtrl:: SetCurrentView](#setcurrentview) para definir a exibição como `MCMV_DECADE` , que representa a exibição de década.

## <a name="cmonthcalctrlsetfirstdayofweek"></a><a name="setfirstdayofweek"></a> CMonthCalCtrl:: setFirstDayOfWeek

Define o dia da semana a ser exibido na coluna mais à esquerda do calendário.

```
BOOL SetFirstDayOfWeek(
    int iDay,
    int* lpnOld = NULL);
```

### <a name="parameters"></a>Parâmetros

*iDay*<br/>
Um valor inteiro que representa qual dia deve ser definido como o primeiro dia da semana. Esse valor deve ser um dos números do dia. Consulte [getFirstDayOfWeek](#getfirstdayofweek) para obter uma descrição dos números do dia.

*lpnOld*<br/>
Um ponteiro para um inteiro que indica o primeiro dia da semana definido anteriormente.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o primeiro dia da semana anterior for definido como um valor diferente do LOCALE_IFIRSTDAYOFWEEK, que é o dia indicado na configuração do painel de controle. Caso contrário, essa função retornará 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_SETFIRSTDAYOFWEEK](/windows/win32/Controls/mcm-setfirstdayofweek)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#7](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_13.cpp)]

## <a name="cmonthcalctrlsetmaxselcount"></a><a name="setmaxselcount"></a> CMonthCalCtrl::SetMaxSelCount

Define o número máximo de dias que podem ser selecionados em um controle de calendário mensal.

```
BOOL SetMaxSelCount(int nMax);
```

### <a name="parameters"></a>Parâmetros

*Nmáx*<br/>
O valor que será definido para representar o número máximo de dias selecionáveis.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_SETMAXSELCOUNT](/windows/win32/Controls/mcm-setmaxselcount)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#8](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_14.cpp)]

## <a name="cmonthcalctrlsetmonthdelta"></a><a name="setmonthdelta"></a> CMonthCalCtrl::SetMonthDelta

Define a taxa de rolagem para um controle de calendário mensal.

```
int SetMonthDelta(int iDelta);
```

### <a name="parameters"></a>Parâmetros

*iDelta*<br/>
O número de meses a serem definidos como a taxa de rolagem do controle. Se esse valor for zero, o Delta do mês será redefinido para o padrão, que é o número de meses exibidos no controle.

### <a name="return-value"></a>Valor retornado

A taxa de rolagem anterior. Se a taxa de rolagem não tiver sido definida anteriormente, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_SETMONTHDELTA](/windows/win32/Controls/mcm-setmonthdelta)de mensagens Win32, conforme descrito no SDK do Windows.

## <a name="cmonthcalctrlsetmonthview"></a><a name="setmonthview"></a> CMonthCalCtrl::SetMonthView

Define o controle de calendário do mês atual para exibir a exibição de mês.

```
BOOL SetMonthView();
```

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método usa o método [CMonthCalCtrl:: SetCurrentView](#setcurrentview) para definir a exibição como MCMV_MONTH, que representa a exibição de mês.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_monthCalCtrl` , que é usada para acessar programaticamente o controle de calendário mensal. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o controle de calendário mensal para exibir as exibições mês, ano, década e século.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_15.cpp)]

## <a name="cmonthcalctrlsetrange"></a><a name="setrange"></a> CMonthCalCtrl:: SetRange

Define as datas mínimas e máximas permitidas para um controle de calendário mensal.

```
BOOL SetRange(
    const COleDateTime* pMinRange,
    const COleDateTime* pMaxRange);

BOOL SetRange(
    const CTime* pMinRange,
    const CTime* pMaxRange);

BOOL SetRange(
    const LPSYSTEMTIME pMinRange,
    const LPSYSTEMTIME pMaxRange);
```

### <a name="parameters"></a>Parâmetros

*pMinRange*<br/>
Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto ou uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a data na extremidade inferior do intervalo.

*pMaxRange*<br/>
Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto ou uma `SYSTEMTIME` estrutura que contém a data na extremidade mais alta do intervalo.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_SETRANGE](/windows/win32/Controls/mcm-setrange)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC do `SetRange` , você pode especificar `COleDateTime` uso, um `CTime` uso ou um `SYSTEMTIME` uso de estrutura.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CMonthCalCtrl:: GetRange](#getrange).

## <a name="cmonthcalctrlsetselrange"></a><a name="setselrange"></a> CMonthCalCtrl::SetSelRange

Define a seleção de um controle de calendário de mês para um determinado intervalo de datas.

```
BOOL SetSelRange(
    const COleDateTime& pMinRange,
    const COleDateTime& pMaxRange);

BOOL SetSelRange(
    const CTime& pMinRange,
    const CTime& pMaxRange);

BOOL SetSelRange(
    const LPSYSTEMTIME pMinRange,
    const LPSYSTEMTIME pMaxRange);
```

### <a name="parameters"></a>Parâmetros

*pMinRange*<br/>
Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto ou uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a data na extremidade inferior do intervalo.

*pMaxRange*<br/>
Um ponteiro para um `COleDateTime` objeto, um `CTime` objeto ou uma `SYSTEMTIME` estrutura que contém a data na extremidade mais alta do intervalo.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_SETSELRANGE](/windows/win32/Controls/mcm-setselrange)de mensagens Win32, conforme descrito no SDK do Windows. Na implementação do MFC do `SetSelRange` , você pode especificar `COleDateTime` uso, um `CTime` uso ou um `SYSTEMTIME` uso de estrutura.

## <a name="cmonthcalctrlsettoday"></a><a name="settoday"></a> CMonthCalCtrl:: sethoje

Define o controle de calendário para o dia atual.

```cpp
void SetToday(const COleDateTime& refDateTime);
void SetToday(const CTime* pDateTime);
void SetToday(const LPSYSTEMTIME pDateTime);
```

### <a name="parameters"></a>Parâmetros

*refDateTime*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que contém a data atual.

*pDateTime*<br/>
Na segunda versão, um ponteiro para um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que contém as informações de data atuais. Na terceira versão, um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém as informações de data atuais.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [MCM_SETTODAY](/windows/win32/Controls/mcm-settoday)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CMonthCalCtrl:: gethoje](#gettoday).

## <a name="cmonthcalctrlsetyearview"></a><a name="setyearview"></a> CMonthCalCtrl::SetYearView

Define o controle de calendário do mês atual como exibição de ano.

```
BOOL SetYearView();
```

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método usa o método [CMonthCalCtrl:: SetCurrentView](#setcurrentview) para definir a exibição como MCMV_YEAR, que representa a exibição anual.

## <a name="cmonthcalctrlsizeminreq"></a><a name="sizeminreq"></a> CMonthCalCtrl::SizeMinReq

Exibe o controle de calendário de mês para o tamanho mínimo que exibe um mês.

```
BOOL SizeMinReq(BOOL bRepaint = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bRepaint*<br/>
Especifica se o controle deve ser redesenhado. Por padrão, TRUE. Se for FALSE, não ocorrerá repintura.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o controle de calendário mensal for dimensionado para seu mínimo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chamar `SizeMinReq` com êxito exibe o controle de calendário mensal inteiro para o calendário de um mês.

## <a name="cmonthcalctrlsizerecttomin"></a><a name="sizerecttomin"></a> CMonthCalCtrl::SizeRectToMin

Para o controle de calendário mensal atual, calcula o menor retângulo que pode conter todos os calendários que se ajustam a um retângulo especificado.

```
LPRECT SizeRectToMin(LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*lpRect*\
no Ponteiro para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) que define um retângulo que contém o número de calendários desejado.

### <a name="return-value"></a>Valor retornado

Ponteiro para uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) que define um retângulo cujo tamanho é menor ou igual ao retângulo definido pelo parâmetro *lpRect* .

### <a name="remarks"></a>Comentários

Esse método calcula quantos calendários podem caber no retângulo especificado pelo parâmetro *lpRect* e, em seguida, retorna o menor retângulo que pode conter esse número de calendários. Em vigor, esse método reduz o retângulo especificado para se ajustar exatamente ao número desejado de calendários.

Esse método envia a mensagem de [MCM_SIZERECTTOMIN](/windows/win32/Controls/mcm-sizerecttomin) , que é descrita na SDK do Windows.

## <a name="see-also"></a>Confira também

[Exemplo de CMNCTRL1 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDateTimeCtrl](../../mfc/reference/cdatetimectrl-class.md)
