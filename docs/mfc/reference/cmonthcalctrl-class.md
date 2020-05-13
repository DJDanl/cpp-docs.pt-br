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
ms.openlocfilehash: 8c24c638d7006be112a53ec1e4f622ad528e348c
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752824"
---
# <a name="cmonthcalctrl-class"></a>Classe CMonthCalCtrl

Encapsula a funcionalidade de um mês de controle de calendário.

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
|[CMonthCalCtrl::Criar](#create)|Cria um controle de calendário de `CMonthCalCtrl` um mês e o anexa ao objeto.|
|[CMonthCalCtrl::GetCalendarBorder](#getcalendarborder)|Recupera a largura da borda do controle do calendário do mês atual.|
|[CMonthCalCtrl::GetCalendarCount](#getcalendarcount)|Recupera o número de calendários exibidos no controle do calendário do mês atual.|
|[CMonthCalCtrl::GetCalendarGridInfo](#getcalendargridinfo)|Recupera informações sobre o controle do calendário do mês atual.|
|[CMonthCalCtrl::GetCalID](#getcalid)|Recupera o identificador de calendário para o controle do calendário do mês atual.|
|[CMonthCalCtrl::GetColor](#getcolor)|Obtém a cor de uma área especificada de um mês de controle de calendário.|
|[CMonthCalCtrl::GetCurrentView](#getcurrentview)|Recupera a exibição que é exibida atualmente pelo controle do calendário do mês atual.|
|[CMonthCalCtrl::GetCurSel](#getcursel)|Recupera o tempo do sistema conforme indicado pela data atualmente selecionada.|
|[CMonthCalCtrl::GetFirstDayOfWeek](#getfirstdayofweek)|O primeiro dia da semana será exibido na coluna mais à esquerda do calendário.|
|[CMonthCalCtrl::GetMaxSelCount](#getmaxselcount)|Recupera o número máximo atual de dias que podem ser selecionados em um mês de controle do calendário.|
|[CMonthCalCtrl::GetMaxTodayWidth](#getmaxtodaywidth)|Recupera a largura máxima da seqüência "Today" para o controle do calendário do mês atual.|
|[CMonthCalCtrl::GetMinReqRect](#getminreqrect)|Recupera o tamanho mínimo necessário para mostrar um mês inteiro em um mês de controle de calendário.|
|[CMonthCalCtrl::GetMonthDelta](#getmonthdelta)|Recupera a taxa de rolagem para um mês de controle de calendário.|
|[CMonthCalCtrl::GetMonthRange](#getmonthrange)|Recupera as informações de data que representam os limites altos e baixos do visor do controle de calendário de um mês.|
|[CMonthCalCtrl::GetRange](#getrange)|Recupera as datas mínimas e máximas atuais definidas em um mês de controle de calendário.|
|[CMonthCalCtrl::GetSelRange](#getselrange)|Recupera as informações de data representando os limites superiore e inferior da faixa de data atualmente selecionada pelo usuário.|
|[CMonthCalCtrl::GetToday](#gettoday)|Recupera as informações de data para a data especificada como "hoje" para um mês de controle de calendário.|
|[CMonthCalCtrl::HitTest](#hittest)|Determina qual seção de um mês de controle de calendário está em um determinado ponto na tela.|
|[CMonthCalCtrl::IsCenturyView](#iscenturyview)|Indica se a visão atual do controle do calendário do mês atual é a visão do século.|
|[CMonthCalCtrl::IsDecadeView](#isdecadeview)|Indica se a visão atual do controle do calendário do mês atual é a visualização da década.|
|[CMonthCalCtrl::IsMonthView](#ismonthview)|Indica se a visão atual do controle do calendário do mês atual é a visualização do mês.|
|[CMonthCalCtrl::IsYearView](#isyearview)|Indica se a visão atual do controle do calendário do mês atual é a exibição do ano.|
|[CMonthCalCtrl::SetCalendarBorder](#setcalendarborder)|Define a largura da borda do controle do calendário do mês atual.|
|[CMonthCalCtrl::SetCalendarBorderDefault](#setcalendarborderdefault)|Define a largura padrão da borda do controle do calendário do mês atual.|
|[CMonthCalCtrl::SetCalID](#setcalid)|Define o identificador de calendário para o controle do calendário do mês atual.|
|[CMonthCalCtrl::SetCenturyView](#setcenturyview)|Define o controle do calendário do mês atual para exibir a exibição do século.|
|[CMonthCalCtrl::SetColor](#setcolor)|Define a cor de uma área especificada de um mês de controle de calendário.|
|[CMonthCalCtrl::SetCurrentView](#setcurrentview)|Define o controle do calendário do mês atual para exibir a exibição especificada.|
|[CMonthCalCtrl::SetCurSel](#setcursel)|Define a data selecionada no momento para um mês de controle do calendário.|
|[CMonthCalCtrl::SetDayState](#setdaystate)|Define o visor por dias em um mês de controle de calendário.|
|[CMonthCalCtrl::SetDecadeView](#setdecadeview)|Define o controle do calendário do mês atual para a visualização da década.|
|[CMonthCalCtrl::SetFirstDayOfWeek](#setfirstdayofweek)|Define o dia da semana a ser exibido na coluna mais à esquerda do calendário.|
|[CMonthCalCtrl::SetMaxSelCount](#setmaxselcount)|Define o número máximo de dias que podem ser selecionados em um mês de controle do calendário.|
|[CMonthCalCtrl::SetMonthDelta](#setmonthdelta)|Define a taxa de rolagem para um mês de controle de calendário.|
|[CMonthCalCtrl::SetMonthView](#setmonthview)|Define o controle do calendário do mês atual para exibir a exibição do mês.|
|[CMonthCalCtrl::SetRange](#setrange)|Define as datas mínimas e máximas permitidas para um mês de controle do calendário.|
|[CMonthCalCtrl::SetSelRange](#setselrange)|Define a seleção para um mês de controle de calendário para um determinado intervalo de datas.|
|[CMonthCalCtrl::SetToday](#settoday)|Define o controle do calendário para o dia atual.|
|[CMonthCalCtrl::SetYearView](#setyearview)|Define o controle do calendário do mês atual para a exibição do ano.|
|[CMonthCalCtrl::SizeMinReq](#sizeminreq)|Repinta o controle do calendário do mês ao seu tamanho mínimo de um mês.|
|[CMonthCalCtrl::SizeRectToMin](#sizerecttomin)|Para o controle do calendário do mês atual, calcula o menor retângulo que pode conter todos os calendários que se encaixam em um retângulo especificado.|

## <a name="remarks"></a>Comentários

O controle do calendário do mês fornece ao usuário uma interface de calendário simples, a partir da qual o usuário pode selecionar uma data. O usuário pode alterar o display por:

- Rolando para trás e para frente, de mês a mês.

- Clicando no texto de hoje para exibir o dia atual (se o estilo MCS_NOTODAY não for usado).

- Escolhendo um mês ou um ano de um menu pop-up.

Você pode personalizar o controle do calendário do mês aplicando uma variedade de estilos ao objeto ao criá-lo. Esses estilos são descritos em [Month Calendar Control Styles](/windows/win32/Controls/month-calendar-control-styles) no Windows SDK.

O controle do calendário do mês pode exibir mais de um mês, e pode indicar dias especiais (como feriados) aneando a data.

Para obter mais informações sobre como usar o controle do calendário do mês, consulte [Usando CMonthCalCtrl](../../mfc/using-cmonthcalctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CMonthCalCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdtctl.h

## <a name="cmonthcalctrlcmonthcalctrl"></a><a name="cmonthcalctrl"></a>CMonthCalCtrl::CMonthCalCtrl

Constrói um objeto `CMonthCalCtrl`.

```
CMonthCalCtrl();
```

### <a name="remarks"></a>Comentários

Você deve `Create` ligar depois de construir o objeto.

## <a name="cmonthcalctrlcreate"></a><a name="create"></a>CMonthCalCtrl::Criar

Cria um controle de calendário de `CMonthCalCtrl` um mês e o anexa ao objeto.

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

*Dwstyle*<br/>
Especifica a combinação de estilos do Windows aplicados ao controle do calendário do mês. Consulte [Month Calendar Control Styles](/windows/win32/Controls/month-calendar-control-styles) no Windows SDK para obter mais informações sobre os estilos.

*Rect*<br/>
Uma referência a uma estrutura [RECT.](/windows/win32/api/windef/ns-windef-rect) Contém a posição e o tamanho do controle do calendário do mês.

*pt*<br/>
Uma referência a uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) que identifica a localização do controle do calendário do mês.

*Pparentwnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle do calendário do mês. Não deve ser NULO.

*nID*<br/>
Especifica o ID de controle de controle do calendário do mês.

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Crie um controle de calendário de um mês em duas etapas:

1. Ligue para [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md) para construir um `CMonthCalCtrl` objeto.

1. Ligue para esta função de membro, que cria `CMonthCalCtrl` um controle de calendário de um mês e a anexa ao objeto.

Quando você `Create`chama, os controles comuns são inicializados. A versão `Create` de chamada determina como ela é dimensionada:

- Para que o MFC dimensione automaticamente o controle para um mês, ligue para o override que usa o parâmetro *pt.*

- Para dimensionar o controle você mesmo, chame a substituição desta função que usa o parâmetro *rect.*

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#1](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_1.cpp)]

## <a name="cmonthcalctrlgetcalendarborder"></a><a name="getcalendarborder"></a>CMonthCalCtrl::GetCalendarBorder

Recupera a largura da borda do controle do calendário do mês atual.

```
int GetCalendarBorder() const;
```

### <a name="return-value"></a>Valor retornado

A largura da borda de controle, em pixels.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [MCM_GETCALENDARBORDER,](/windows/win32/Controls/mcm-getcalendarborder) que é descrita no SDK do Windows.

## <a name="cmonthcalctrlgetcalendarcount"></a><a name="getcalendarcount"></a>CMonthCalCtrl::GetCalendarCount

Recupera o número de calendários exibidos no controle do calendário do mês atual.

```
int GetCalendarCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de calendários atualmente exibidos no controle do calendário do mês. O número máximo permitido de calendários é 12.

### <a name="remarks"></a>Comentários

Este método envia a [mensagem MCM_GETCALENDARCOUNT,](/windows/win32/Controls/mcm-getcalendarcount) que é descrita no SDK do Windows.

## <a name="cmonthcalctrlgetcalendargridinfo"></a><a name="getcalendargridinfo"></a>CMonthCalCtrl::GetCalendarGridInfo

Recupera informações sobre o controle do calendário do mês atual.

```
BOOL GetCalendarGridInfo(PMCGRIDINFO pmcGridInfo) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pmcGridInfo*|[fora] Pointer para uma estrutura [MCGRIDINFO](/windows/win32/api/commctrl/ns-commctrl-mcgridinfo) que recebe informações sobre o controle do calendário do mês atual. O interlocutor é responsável por alocar e inicializar essa estrutura.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [MCM_GETCALENDARGRIDINFO,](/windows/win32/Controls/mcm-getcalendargridinfo) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_monthCalCtrl`seguir define a variável, que é usada para acessar programáticamente o controle do calendário do mês. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de `GetCalendarGridInfo` código a seguir usa o método para recuperar a data do calendário que o controle de calendário do mês atual exibe.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#3](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_3.cpp)]

## <a name="cmonthcalctrlgetcalid"></a><a name="getcalid"></a>CMonthCalCtrl::GetCalID

Recupera o identificador de calendário para o controle do calendário do mês atual.

```
CALID GetCalID() const;
```

### <a name="return-value"></a>Valor retornado

Uma das constantes de identificador de [calendário.](/windows/win32/Intl/calendar-identifiers)

### <a name="remarks"></a>Comentários

Um identificador de calendário denota um calendário específico da região, como os calendários gregoriano (localizado), japonês ou hijri. Seu aplicativo pode usar um identificador de calendário que tenha várias funções de suporte ao idioma.

Este método envia a mensagem [MCM_GETCALID,](/windows/win32/Controls/mcm-getcalid) que é descrita no SDK do Windows.

## <a name="cmonthcalctrlgetcolor"></a><a name="getcolor"></a>CMonthCalCtrl::GetColor

Recupera a cor de uma área do controle do calendário do mês especificada por *nRegion*.

```
COLORREF GetColor(int nRegion) const;
```

### <a name="parameters"></a>Parâmetros

*nRegião*<br/>
A região do controle do calendário do mês a partir da qual a cor é recuperada. Para obter uma lista de valores, consulte o parâmetro *nRegion* de [SetColor](#setcolor).

### <a name="return-value"></a>Valor retornado

Um [valor COLORREF](/windows/win32/gdi/colorref) especificando a cor associada à parte do controle do calendário do mês, se for bem-sucedido. Caso contrário, esta função de membro retorna -1.

## <a name="cmonthcalctrlgetcurrentview"></a><a name="getcurrentview"></a>CMonthCalCtrl::GetCurrentView

Recupera a exibição que é exibida atualmente pelo controle do calendário do mês atual.

```
DWORD GetCurrentView() const;
```

### <a name="return-value"></a>Valor retornado

A visão atual, que é indicada por um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|MCMV_MONTH|Vista mensal|
|MCMV_YEAR|Visão anual|
|MCMV_DECADE|Visão da década|
|MCMV_CENTURY|Visão do século|

### <a name="remarks"></a>Comentários

Este método envia a mensagem [MCM_GETCURRENTVIEW,](/windows/win32/Controls/mcm-getcurrentview) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_monthCalCtrl`seguir define a variável, que é usada para acessar programáticamente o controle do calendário do mês. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir relata que visualizam o controle do calendário do mês atualmente exibido.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#7](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_4.cpp)]

## <a name="cmonthcalctrlgetcursel"></a><a name="getcursel"></a>CMonthCalCtrl::GetCurSel

Recupera o tempo do sistema conforme indicado pela data atualmente selecionada.

```
BOOL GetCurSel(COleDateTime& refDateTime) const;  BOOL GetCurSel(CTime& refDateTime) const;

BOOL GetCurSel(LPSYSTEMTIME pDateTime) const;
```

### <a name="parameters"></a>Parâmetros

*refDateTime*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou a um objeto [CTime.](../../atl-mfc-shared/reference/ctime-class.md) Recebe o tempo atual.

*pDateTime*<br/>
Um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que receberá as informações de data selecionadas no momento. Este parâmetro deve ser um endereço válido e não pode ser NULO.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/mcm-getcursel)MCM_GETCURSEL do Win32, conforme descrito no SDK do Windows.

> [!NOTE]
> Esta função de membro falha se o estilo MCS_MULTISELECT estiver definido.

Na implementação `GetCurSel`do MFC, você `COleDateTime` pode `CTime` especificar um `SYSTEMTIME` uso, um uso ou um uso de estrutura.

## <a name="cmonthcalctrlgetfirstdayofweek"></a><a name="getfirstdayofweek"></a>CMonthCalCtrl::GetFirstDayOfWeek

O primeiro dia da semana será exibido na coluna mais à esquerda do calendário.

```
int GetFirstDayOfWeek(BOOL* pbLocal = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*pbLocal*<br/>
Um ponteiro para um valor BOOL. Se o valor não for zero, a configuração do controle não corresponde à configuração no painel de controle.

### <a name="return-value"></a>Valor retornado

Um valor inteiro que representa o primeiro dia da semana. Consulte **Observações** para obter mais informações sobre o que esses inteiros representam.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_GETFIRSTDAYOFWEEK](/windows/win32/Controls/mcm-getfirstdayofweek)de mensagem Win32 , conforme descrito no SDK do Windows. Os dias da semana são representados como inteiros, como segue.

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

  Veja o exemplo de [CMonthCalCtrl::SetFirstDayOfWeek](#setfirstdayofweek).

## <a name="cmonthcalctrlgetmaxselcount"></a><a name="getmaxselcount"></a>CMonthCalCtrl::GetMaxSelCount

Recupera o número máximo atual de dias que podem ser selecionados em um mês de controle do calendário.

```
int GetMaxSelCount() const;
```

### <a name="return-value"></a>Valor retornado

Um valor inteiro que representa o número total de dias que podem ser selecionados para o controle.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_GETMAXSELCOUNT](/windows/win32/Controls/mcm-getmaxselcount)de mensagem Win32 , conforme descrito no SDK do Windows. Use esta função de membro para controles com o conjunto de MCS_MULTISELECT estilo.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMonthCalCtrl::SetMaxSelCount](#setmaxselcount).

## <a name="cmonthcalctrlgetmaxtodaywidth"></a><a name="getmaxtodaywidth"></a>CMonthCalCtrl::GetMaxTodayWidth

Recupera a largura máxima da seqüência "Today" para o controle do calendário do mês atual.

```
DWORD GetMaxTodayWidth() const;
```

### <a name="return-value"></a>Valor retornado

A largura da seqüência "Today", em pixels.

### <a name="example"></a>Exemplo

O exemplo de código a `m_monthCalCtrl`seguir define a variável, que é usada para acessar programáticamente o controle do calendário do mês. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de `GetMaxTodayWidth` código a seguir demonstra o método.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_5.cpp)]

### <a name="remarks"></a>Comentários

O usuário pode retornar à data atual clicando na seqüência "Hoje", que é exibida no controle do calendário do final do mês. A seqüência "Today" inclui texto de rótulo e texto de data.

Este método envia a mensagem [MCM_GETMAXTODAYWIDTH,](/windows/win32/Controls/mcm-getmaxtodaywidth) que é descrita no SDK do Windows.

## <a name="cmonthcalctrlgetminreqrect"></a><a name="getminreqrect"></a>CMonthCalCtrl::GetMinReqRect

Recupera o tamanho mínimo necessário para mostrar um mês inteiro em um mês de controle de calendário.

```
BOOL GetMinReqRect(RECT* pRect) const;
```

### <a name="parameters"></a>Parâmetros

*pRect*<br/>
Um ponteiro para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que receberá informações delimitadoras do retângulo. Este parâmetro deve ser um endereço válido e não pode ser NULO.

### <a name="return-value"></a>Valor retornado

Se for bem-sucedida, esta `lpRect` função membro retorna não zero e recebe as informações delimitadoras aplicáveis. Se não tiver sucesso, a função de membro retorna 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/mcm-getminreqrect)Win32 MCM_GETMINREQRECT , conforme descrito no SDK do Windows.

## <a name="cmonthcalctrlgetmonthdelta"></a><a name="getmonthdelta"></a>CMonthCalCtrl::GetMonthDelta

Recupera a taxa de rolagem para um mês de controle de calendário.

```
int GetMonthDelta() const;
```

### <a name="return-value"></a>Valor retornado

A taxa de rolagem para o controle do calendário do mês. A taxa de rolagem é o número de meses que o controle move sua exibição quando o usuário clica em um botão de rolagem uma vez.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_GETMONTHDELTA](/windows/win32/Controls/mcm-getmonthdelta)de mensagem Win32, conforme descrito no SDK do Windows.

## <a name="cmonthcalctrlgetmonthrange"></a><a name="getmonthrange"></a>CMonthCalCtrl::GetMonthRange

Recupera as informações de data que representam os limites altos e baixos do visor do controle de calendário de um mês.

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
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) contendo a data mínima permitida.

*refMaxRange*<br/>
Uma referência `COleDateTime` a `CTime` um ou objeto contendo a data máxima permitida.

*pMinRange*<br/>
Um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) contendo a data na extremidade mais baixa do intervalo.

*pMaxRange*<br/>
Um ponteiro `SYSTEMTIME` para uma estrutura contendo a data na extremidade mais alta da gama.

*dwFlags*<br/>
Valor especificando o escopo dos limites de intervalo a serem recuperados. Este valor deve ser um dos seguintes.

|Valor|Significado|
|-----------|-------------|
|GMR_DAYSTATE|Inclua meses anteriores e de alcance visível que são exibidos apenas parcialmente.|
|GMR_VISIBLE|Inclua apenas os meses que são totalmente exibidos.|

### <a name="return-value"></a>Valor retornado

Um inteiro que representa o intervalo, em meses, se estende pelos dois limites indicados por *refMinRange* e *refMaxRange* na primeira e segunda versões, ou *pMinRange* e *pMaxRange* na terceira versão.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_GETMONTHRANGE](/windows/win32/Controls/mcm-getmonthrange)de mensagem Win32 , conforme descrito no SDK do Windows. `GetMonthRange`Na implementação do MFC, `COleDateTime` você pode `CTime` especificar `SYSTEMTIME` o uso, um uso ou um uso de estrutura.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMonthCalCtrl::SetDayState](#setdaystate).

## <a name="cmonthcalctrlgetrange"></a><a name="getrange"></a>CMonthCalCtrl::GetRange

Recupera as datas mínimas e máximas atuais definidas em um mês de controle de calendário.

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
Um ponteiro `COleDateTime` para um `CTime` objeto, um objeto ou estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) contendo a data na extremidade mais baixa do intervalo.

*pMaxRange*<br/>
Um ponteiro `COleDateTime` para um `CTime` objeto, um objeto ou estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) contendo a data na extremidade mais alta do intervalo.

### <a name="return-value"></a>Valor retornado

Um DWORD que pode ser zero (nenhum limite é definido) ou uma combinação dos seguintes valores que especificam informações de limite.

|Valor|Significado|
|-----------|-------------|
|GDTR_MAX|Um limite máximo é definido para o controle; *o pMaxRange* é válido e contém as informações de data aplicáveis.|
|GDTR_MIN|Um limite mínimo é definido para o controle; *o pMinRange* é válido e contém as informações de data aplicáveis.|

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_GETRANGE](/windows/win32/Controls/mcm-getrange)de mensagem Win32 , conforme descrito no SDK do Windows. Na implementação `GetRange`do MFC, você `COleDateTime` pode `CTime` especificar um `SYSTEMTIME` uso, um uso ou um uso de estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#2](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_6.cpp)]

## <a name="cmonthcalctrlgetselrange"></a><a name="getselrange"></a>CMonthCalCtrl::GetSelRange

Recupera as informações de data representando os limites superiore e inferior da faixa de data atualmente selecionada pelo usuário.

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
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) contendo a data mínima permitida.

*refMaxRange*<br/>
Uma referência `COleDateTime` a `CTime` um ou objeto contendo a data máxima permitida.

*pMinRange*<br/>
Um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) contendo a data na extremidade mais baixa do intervalo.

*pMaxRange*<br/>
Um ponteiro `SYSTEMTIME` para uma estrutura contendo a data na extremidade mais alta da gama.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_GETSELRANGE](/windows/win32/Controls/mcm-getselrange)de mensagem Win32 , conforme descrito no SDK do Windows. `GetSelRange`falhará se aplicado a um controle de calendário de um mês que não use o estilo MCS_MULTISELECT.

`GetSelRange`Na implementação do MFC, `COleDateTime` você pode `CTime` especificar `SYSTEMTIME` o uso, um uso ou um uso de estrutura.

## <a name="cmonthcalctrlgettoday"></a><a name="gettoday"></a>CMonthCalCtrl::GetToday

Recupera as informações de data para a data especificada como "hoje" para um mês de controle de calendário.

```
BOOL GetToday(COleDateTime& refDateTime) const;  BOOL GetToday(COleDateTime& refDateTime) const;

BOOL GetToday(LPSYSTEMTIME pDateTime) const;
```

### <a name="parameters"></a>Parâmetros

*refDateTime*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) indicando o dia atual.

*pDateTime*<br/>
Um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que receberá as informações da data. Este parâmetro deve ser um endereço válido e não pode ser NULO.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_GETTODAY](/windows/win32/Controls/mcm-gettoday)de mensagem Win32 , conforme descrito no SDK do Windows. Na implementação `GetToday`do MFC, você `COleDateTime` pode `CTime` especificar um `SYSTEMTIME` uso, um uso ou um uso de estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#3](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_7.cpp)]

## <a name="cmonthcalctrlhittest"></a><a name="hittest"></a>CMonthCalCtrl::HitTest

Determina qual controle de calendário mensal, se houver, está em uma posição especificada.

```
DWORD HitTest(PMCHITTESTINFO pMCHitTest);
```

### <a name="parameters"></a>Parâmetros

*pMCHitTest*<br/>
Um ponteiro para uma estrutura [MCHITTESTINFO](/windows/win32/api/commctrl/ns-commctrl-mchittestinfo) contendo pontos de teste de acerto para o controle do calendário do mês.

### <a name="return-value"></a>Valor retornado

Um valor DWORD. Igual ao **membro uHit** da `MCHITTESTINFO` estrutura.

### <a name="remarks"></a>Comentários

`HitTest`usa `MCHITTESTINFO` a estrutura, que contém informações sobre o teste de acerto.

## <a name="cmonthcalctrliscenturyview"></a><a name="iscenturyview"></a>CMonthCalCtrl::IsCenturyView

Indica se a visão atual do controle do calendário do mês atual é a visão do século.

```
BOOL IsCenturyView() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se a visão atual é a visão do século; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [MCM_GETCURRENTVIEW,](/windows/win32/Controls/mcm-getcurrentview) que é descrita no SDK do Windows. Se essa mensagem retornar MCMV_CENTURY, este método reatornou TRUE.

## <a name="cmonthcalctrlisdecadeview"></a><a name="isdecadeview"></a>CMonthCalCtrl::IsDecadeView

Indica se a visão atual do controle do calendário do mês atual é a visualização da década.

```
BOOL IsDecadeView() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se a visão atual é a visão da década; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [MCM_GETCURRENTVIEW,](/windows/win32/Controls/mcm-getcurrentview) que é descrita no SDK do Windows. Se essa mensagem retornar MCMV_DECADE, este método reatornou TRUE.

## <a name="cmonthcalctrlismonthview"></a><a name="ismonthview"></a>CMonthCalCtrl::IsMonthView

Indica se a visão atual do controle do calendário do mês atual é a visualização do mês.

```
BOOL IsMonthView() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se a visão atual for a exibição do mês; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [MCM_GETCURRENTVIEW,](/windows/win32/Controls/mcm-getcurrentview) que é descrita no SDK do Windows. Se essa mensagem retornar MCMV_MONTH, este método reatornou TRUE.

## <a name="cmonthcalctrlisyearview"></a><a name="isyearview"></a>CMonthCalCtrl::IsYearView

Indica se a visão atual do controle do calendário do mês atual é a exibição do ano.

```
BOOL IsYearView() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se a visão atual for a visualização do ano; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [MCM_GETCURRENTVIEW,](/windows/win32/Controls/mcm-getcurrentview) que é descrita no SDK do Windows. Se essa mensagem retornar MCMV_YEAR, este método retorna TRUE.

## <a name="cmonthcalctrlsetcalendarborder"></a><a name="setcalendarborder"></a>CMonthCalCtrl::SetCalendarBorder

Define a largura da borda do controle do calendário do mês atual.

```cpp
void SetCalendarBorder(int cxyBorder);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*cxyBorder*|[em] A largura da borda, em pixels.|

### <a name="remarks"></a>Comentários

Se este método for bem sucedido, a largura da borda será definida para o parâmetro *cxyBorder.* Caso contrário, a largura da borda é redefinida para o valor padrão especificado pelo [tema](/windows/win32/Controls/visual-styles-overview)atual , ou zero se os temas não forem usados.

Este método envia a mensagem [MCM_SETCALENDARBORDER,](/windows/win32/Controls/mcm-setcalendarborder) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_monthCalCtrl`seguir define a variável, que é usada para acessar programáticamente o controle do calendário do mês. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a largura de borda do controle do calendário do mês para oito pixels. Use o método [CMonthCalCtrl::GetCalendarBorder](#getcalendarborder) para determinar se esse método foi bem sucedido.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#6](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_8.cpp)]

## <a name="cmonthcalctrlsetcalendarborderdefault"></a><a name="setcalendarborderdefault"></a>CMonthCalCtrl::SetCalendarBorderDefault

Define a largura padrão da borda do controle do calendário do mês atual.

```cpp
void SetCalendarBorderDefault();
```

### <a name="remarks"></a>Comentários

A largura da borda é definida para o valor padrão especificado pelo [tema](/windows/win32/Controls/visual-styles-overview)atual , ou zero se os temas não forem usados.

Este método envia a mensagem [MCM_SETCALENDARBORDER,](/windows/win32/Controls/mcm-setcalendarborder) que é descrita no SDK do Windows.

## <a name="cmonthcalctrlsetcalid"></a><a name="setcalid"></a>CMonthCalCtrl::SetCalID

Define o identificador de calendário para o controle do calendário do mês atual.

```
BOOL SetCalID(CALID calid);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*calid*|[em] Uma das constantes de identificador de [calendário.](/windows/win32/Intl/calendar-identifiers)|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um identificador de calendário especifica um calendário específico da região, como os calendários gregoriano (localizado), japonês ou hijri. Use `SetCalID` o método para exibir um calendário especificado pelo parâmetro *calid* se o local que contém o calendário estiver instalado no seu computador.

Este método envia a mensagem [MCM_SETCALID,](/windows/win32/Controls/mcm-setcalid) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_monthCalCtrl`seguir define a variável, que é usada para acessar programáticamente o controle do calendário do mês. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo do código a seguir define o controle do calendário do mês para exibir o calendário da Era do Imperador Japonês. O `SetCalID` método só é bem sucedido se esse calendário estiver instalado no seu computador.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#4](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_9.cpp)]

## <a name="cmonthcalctrlsetcenturyview"></a><a name="setcenturyview"></a>CMonthCalCtrl::SetCenturyView

Define o controle do calendário do mês atual para exibir a exibição do século.

```
BOOL SetCenturyView();
```

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método usa o método [CMonthCalCtrl::SetCurrentView](#setcurrentview) para definir a exibição `MCMV_CENTURY`, que representa a exibição do século.

## <a name="cmonthcalctrlsetcolor"></a><a name="setcolor"></a>CMonthCalCtrl::SetColor

Define a cor de uma área especificada de um mês de controle de calendário.

```
COLORREF SetColor(
    int nRegion,
    COLORREF ref);
```

### <a name="parameters"></a>Parâmetros

*nRegião*<br/>
Um valor inteiro especificando qual cor do calendário do mês a definir. Este valor pode ser um dos seguintes.

|Valor|Significado|
|-----------|-------------|
|MCSC_BACKGROUND|A cor de fundo exibida entre meses.|
|MCSC_MONTHBK|A cor de fundo exibida dentro de um mês.|
|MCSC_TEXT|A cor usada para exibir texto dentro de um mês.|
|MCSC_TITLEBK|A cor de fundo exibida no título do calendário.|
|MCSC_TITLETEXT|A cor usada para exibir texto dentro do título do calendário.|
|MCSC_TRAILINGTEXT|A cor usada para exibir cabeçalho e texto de dia de arrasto. Os dias de cabeçalho e de saque são os dias dos meses anteriores e seguintes que aparecem no calendário atual.|

*ref*<br/>
Um valor COLORREF para a nova configuração de cor para a parte especificada do controle do calendário do mês.

### <a name="return-value"></a>Valor retornado

Um valor COLORREF que representa a configuração de cor anterior para a parte especificada do controle do calendário do mês, se for bem sucedido. Caso contrário, esta mensagem retorna -1.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_SETCOLOR](/windows/win32/Controls/mcm-setcolor)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#4](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_10.cpp)]

## <a name="cmonthcalctrlsetcurrentview"></a><a name="setcurrentview"></a>CMonthCalCtrl::SetCurrentView

Define o controle do calendário do mês atual para exibir a exibição especificada.

```
BOOL SetCurrentView(DWORD dwNewView);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*dwNewView*|[em] Um dos seguintes valores que especifica uma visão mensal, anual, década ou centenário.<br /><br /> MCMV_MONTH: Vista mensal<br /><br /> MCMV_YEAR: Visão anual<br /><br /> MCMV_DECADE: Visão da década<br /><br /> MCMV_CENTURY: Visão do século|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [MCM_SETCURRENTVIEW,](/windows/win32/Controls/mcm-setcurrentview) que é descrita no SDK do Windows.

## <a name="cmonthcalctrlsetcursel"></a><a name="setcursel"></a>CMonthCalCtrl::SetCurSel

Define a data selecionada no momento para um mês de controle do calendário.

```
BOOL SetCurSel(const COleDateTime& refDateTime);
BOOL SetCurSel(const CTime& refDateTime);
BOOL SetCurSel(const LPSYSTEMTIME pDateTime);
```

### <a name="parameters"></a>Parâmetros

*refDateTime*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou [CTime](../../atl-mfc-shared/reference/ctime-class.md) indicando o controle de calendário do mês selecionado no momento.

*pDateTime*<br/>
Ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém a data a ser definida como a seleção atual.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/mcm-setcursel)MCM_SETCURSEL do Win32, conforme descrito no SDK do Windows. Na implementação `SetCurSel`do MFC, você `COleDateTime` pode `CTime` especificar um `SYSTEMTIME` uso, um uso ou um uso de estrutura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#5](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_11.cpp)]

## <a name="cmonthcalctrlsetdaystate"></a><a name="setdaystate"></a>CMonthCalCtrl::SetDayState

Define o visor por dias em um mês de controle de calendário.

```
BOOL SetDayState(
    int nMonths,
    LPMONTHDAYSTATE pStates);
```

### <a name="parameters"></a>Parâmetros

*nMeses*<br/>
Valor indicando quantos elementos estão na matriz que *pStates* aponta.

*pEstados*<br/>
Um ponteiro para uma matriz de valores [MONTHDAYSTATE](/windows/win32/Controls/monthdaystate) que define como o controle do calendário do mês será sorteado todos os dias em seu display. O tipo de dados MONTHDAYSTATE é um campo de bits, onde cada bit (1 a 31) representa o estado de um dia em um mês. Se um pouco estiver ligado, o dia correspondente será exibido em negrito; caso contrário, será exibido sem ênfase.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/mcm-setdaystate)Win32 MCM_SETDAYSTATE , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#6](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_12.cpp)]

## <a name="cmonthcalctrlsetdecadeview"></a><a name="setdecadeview"></a>CMonthCalCtrl::SetDecadeView

Define o controle do calendário do mês atual para a visualização da década.

```
BOOL SetDecadeView();
```

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método usa o método [CMonthCalCtrl::SetCurrentView](#setcurrentview) para definir a `MCMV_DECADE`exibição, o que representa a exibição da década.

## <a name="cmonthcalctrlsetfirstdayofweek"></a><a name="setfirstdayofweek"></a>CMonthCalCtrl::SetFirstDayOfWeek

Define o dia da semana a ser exibido na coluna mais à esquerda do calendário.

```
BOOL SetFirstDayOfWeek(
    int iDay,
    int* lpnOld = NULL);
```

### <a name="parameters"></a>Parâmetros

*Iday*<br/>
Um valor inteiro representando qual dia deve ser definido como o primeiro dia da semana. Este valor deve ser um dos números do dia. Consulte [GetFirstDayOfWeek](#getfirstdayofweek) para obter uma descrição dos números do dia.

*lpnOld*<br/>
Um ponteiro para um inteiro indicando o primeiro dia da semana previamente definido.

### <a name="return-value"></a>Valor retornado

Não zero se o primeiro dia anterior da semana for definido para um valor diferente do de LOCALE_IFIRSTDAYOFWEEK, que é o dia indicado na configuração do painel de controle. Caso contrário, esta função retorna 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/mcm-setfirstdayofweek)MCM_SETFIRSTDAYOFWEEK do Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#7](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_13.cpp)]

## <a name="cmonthcalctrlsetmaxselcount"></a><a name="setmaxselcount"></a>CMonthCalCtrl::SetMaxSelCount

Define o número máximo de dias que podem ser selecionados em um mês de controle do calendário.

```
BOOL SetMaxSelCount(int nMax);
```

### <a name="parameters"></a>Parâmetros

*Nmax*<br/>
O valor que será definido para representar o número máximo de dias selecionáveis.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_SETMAXSELCOUNT](/windows/win32/Controls/mcm-setmaxselcount)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CMonthCalCtrl#8](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_14.cpp)]

## <a name="cmonthcalctrlsetmonthdelta"></a><a name="setmonthdelta"></a>CMonthCalCtrl::SetMonthDelta

Define a taxa de rolagem para um mês de controle de calendário.

```
int SetMonthDelta(int iDelta);
```

### <a name="parameters"></a>Parâmetros

*iDelta*<br/>
O número de meses a serem definidos como taxa de rolagem do controle. Se esse valor for zero, o delta do mês será redefinido para o padrão, que é o número de meses exibido susceptino no controle.

### <a name="return-value"></a>Valor retornado

A taxa de rolagem anterior. Se a taxa de rolagem não tiver sido definida anteriormente, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [MCM_SETMONTHDELTA](/windows/win32/Controls/mcm-setmonthdelta)de mensagem Win32, conforme descrito no SDK do Windows.

## <a name="cmonthcalctrlsetmonthview"></a><a name="setmonthview"></a>CMonthCalCtrl::SetMonthView

Define o controle do calendário do mês atual para exibir a exibição do mês.

```
BOOL SetMonthView();
```

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método usa o método [CMonthCalCtrl::SetCurrentView](#setcurrentview) para definir a exibição para MCMV_MONTH, o que representa a exibição do mês.

### <a name="example"></a>Exemplo

O exemplo de código a `m_monthCalCtrl`seguir define a variável, que é usada para acessar programáticamente o controle do calendário do mês. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#9](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_2.h)]

### <a name="example"></a>Exemplo

O exemplo do código a seguir define o controle do calendário do mês para exibir as visualizações do mês, ano, década e século.

[!code-cpp[NVC_MFC_CMonthCalCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cmonthcalctrl-class_15.cpp)]

## <a name="cmonthcalctrlsetrange"></a><a name="setrange"></a>CMonthCalCtrl::SetRange

Define as datas mínimas e máximas permitidas para um mês de controle do calendário.

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
Um ponteiro `COleDateTime` para um `CTime` objeto, um objeto ou estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) contendo a data na extremidade mais baixa do intervalo.

*pMaxRange*<br/>
Um ponteiro `COleDateTime` para um `CTime` objeto, `SYSTEMTIME` um objeto ou estrutura contendo a data na extremidade mais alta do intervalo.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/mcm-setrange)Win32 MCM_SETRANGE , conforme descrito no SDK do Windows. `SetRange`Na implementação do MFC, `COleDateTime` você pode `CTime` especificar `SYSTEMTIME` o uso, um uso ou um uso de estrutura.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMonthCalCtrl::GetRange](#getrange).

## <a name="cmonthcalctrlsetselrange"></a><a name="setselrange"></a>CMonthCalCtrl::SetSelRange

Define a seleção para um mês de controle de calendário para um determinado intervalo de datas.

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
Um ponteiro `COleDateTime` para um `CTime` objeto, um objeto ou estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) contendo a data na extremidade mais baixa do intervalo.

*pMaxRange*<br/>
Um ponteiro `COleDateTime` para um `CTime` objeto, `SYSTEMTIME` um objeto ou estrutura contendo a data na extremidade mais alta do intervalo.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/mcm-setselrange)Win32 MCM_SETSELRANGE , conforme descrito no SDK do Windows. `SetSelRange`Na implementação do MFC, `COleDateTime` você pode `CTime` especificar `SYSTEMTIME` o uso, um uso ou um uso de estrutura.

## <a name="cmonthcalctrlsettoday"></a><a name="settoday"></a>CMonthCalCtrl::SetToday

Define o controle do calendário para o dia atual.

```cpp
void SetToday(const COleDateTime& refDateTime);
void SetToday(const CTime* pDateTime);
void SetToday(const LPSYSTEMTIME pDateTime);
```

### <a name="parameters"></a>Parâmetros

*refDateTime*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que contém a data atual.

*pDateTime*<br/>
Na segunda versão, um ponteiro para um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) contendo as informações da data atual. Na terceira versão, um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que contém as informações de data atual.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/mcm-settoday)MCM_SETTODAY do Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CMonthCalCtrl::GetToday](#gettoday).

## <a name="cmonthcalctrlsetyearview"></a><a name="setyearview"></a>CMonthCalCtrl::SetYearView

Define o controle do calendário do mês atual para a exibição do ano.

```
BOOL SetYearView();
```

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método usa o método [CMonthCalCtrl::SetCurrentView](#setcurrentview) para definir a exibição para MCMV_YEAR, o que representa a exibição anual.

## <a name="cmonthcalctrlsizeminreq"></a><a name="sizeminreq"></a>CMonthCalCtrl::SizeMinReq

Exibe o controle do calendário do mês para o tamanho mínimo que exibe um mês.

```
BOOL SizeMinReq(BOOL bRepaint = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bRepaint*<br/>
Especifica se o controle deve ser repintado. Por padrão, TRUE. Se FALSO, não ocorre repintura.

### <a name="return-value"></a>Valor retornado

Não zero se o controle do calendário do mês for dimensionado ao mínimo; caso contrário, 0.

### <a name="remarks"></a>Comentários

A `SizeMinReq` chamada exibe com sucesso o controle do calendário do mês inteiro para um mês de calendário.

## <a name="cmonthcalctrlsizerecttomin"></a><a name="sizerecttomin"></a>CMonthCalCtrl::SizeRectToMin

Para o controle do calendário do mês atual, calcula o menor retângulo que pode conter todos os calendários que se encaixam em um retângulo especificado.

```
LPRECT SizeRectToMin(LPRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Lprect*|[em] Ponteiro para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que define um retângulo que contém o número desejado de calendários.|

### <a name="return-value"></a>Valor retornado

Pointer para uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) que define um retângulo cujo tamanho é menor ou igual ao retângulo definido pelo parâmetro *lpRect.*

### <a name="remarks"></a>Comentários

Este método calcula quantos calendários podem caber no retângulo especificado pelo parâmetro *lpRect* e, em seguida, retorna o menor retângulo que pode conter esse número de calendários. Na verdade, este método encolhe o retângulo especificado para exatamente se encaixar no número desejado de calendários.

Este método envia a mensagem [MCM_SIZERECTTOMIN,](/windows/win32/Controls/mcm-sizerecttomin) que é descrita no SDK do Windows.

## <a name="see-also"></a>Confira também

[Amostra de MFC CMNCTRL1](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDateTimeCtrl](../../mfc/reference/cdatetimectrl-class.md)
