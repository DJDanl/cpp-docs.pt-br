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
ms.openlocfilehash: 577dde7f4f4209f15590825fdb87fe23f788a1ce
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754615"
---
# <a name="cdatetimectrl-class"></a>Classe CDateTimeCtrl

Encapsula a funcionalidade de um controle de seleção de data e hora.

## <a name="syntax"></a>Sintaxe

```
class CDateTimeCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDateTimeCtrl::CDateTimeCtrl](#cdatetimectrl)|Constrói um objeto `CDateTimeCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDateTimeCtrl::CloseMonthCal](#closemonthcal)|Fecha o controle atual de data e seleção de horários.|
|[CDateTimeCtrl::Criar](#create)|Cria o controle do seletor de `CDateTimeCtrl` data e hora e o anexa ao objeto.|
|[CDateTimeCtrl::GetDateTimePickerinfo](#getdatetimepickerinfo)|Recupera informações sobre o controle atual de data e seleção de horários.|
|[CDateTimeCtrl::GetIdealSize](#getidealsize)|Retorna o tamanho ideal do controle de data e seletor de horas necessário para exibir a data ou hora atuais.|
|[CDateTimeCtrl::GetMonthCalColor](#getmonthcalcolor)|Recupera a cor para uma determinada parte do calendário do mês dentro do controle de data e seleção de horas.|
|[CDateTimeCtrl::GetMonthCalCtrl](#getmonthcalctrl)|Recupera o `CMonthCalCtrl` objeto associado ao controle de data e seleção de horários.|
|[CDateTimeCtrl::GetMonthCalFont](#getmonthcalfont)|Recupera a fonte atualmente usada pelo controle de calendário do mês de criança do controle de data e hora do seletor de horários.|
|[CDateTimeCtrl::GetMonthCalStyle](#getmonthcalstyle)|Obtém o estilo do controle atual de data e seleção de horários.|
|[CDateTimeCtrl::GetRange](#getrange)|Recupera os tempos mínimos e máximos atuais do sistema para um controle de seleção de data e hora.|
|[CDateTimeCtrl::GetTime](#gettime)|Recupera a hora atualmente selecionada a partir de um controle de `SYSTEMTIME` seleção de datae hora e hora e coloca-a em uma estrutura especificada.|
|[CDateTimeCtrl::SetFormat](#setformat)|Define a exibição de um controle de seleção de data e hora de acordo com uma seqüência de formato dada.|
|[CDateTimeCtrl::SetMonthCalColor](#setmonthcalcolor)|Define a cor para uma determinada parte do calendário do mês dentro de um controle de data e seleção de horas.|
|[CDateTimeCtrl::SetMonthCalFont](#setmonthcalfont)|Define a fonte que o controle de data e hora do controle do mês filho usará.|
|[CDateTimeCtrl::SetMonthCalStyle](#setmonthcalstyle)|Define o estilo do controle de data e seleção de data e hora atuais.|
|[CDateTimeCtrl::SetRange](#setrange)|Define os tempos mínimos e máximos permitidos do sistema para um controle de seleção de data e hora.|
|[CDateTimeCtrl::SetTime](#settime)|Define a hora em um controle de seleção de data e hora.|

## <a name="remarks"></a>Comentários

O controle de seleção de data e hora (controle DTP) fornece uma interface simples para trocar informações de data e hora com um usuário. Esta interface contém campos, cada um dos quais exibe uma parte das informações de data e hora armazenadas no controle. O usuário pode alterar as informações armazenadas no controle alterando o conteúdo da string em um determinado campo. O usuário pode mover-se de campo para campo usando o mouse ou o teclado.

Você pode personalizar o controle do seletor de data e hora aplicando uma variedade de estilos ao objeto ao criá-lo. Consulte [Os estilos de controle do seletor](/windows/win32/Controls/date-and-time-picker-control-styles) de data e hora no SDK do Windows para obter mais informações sobre estilos específicos para o controle de data e hora do seletor. Você pode definir o formato de exibição do controle DTP usando estilos de formato. Esses estilos de formato são descritos em "Estilos de formato" no tópico SDK do Windows [Estilos de controle de data e hora](/windows/win32/Controls/date-and-time-picker-control-styles).

O controle do seletor de datae hora também usa notificações e retornos de chamadas, que são descritos em [Using CDateTimeCtrl](../../mfc/using-cdatetimectrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CDateTimeCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdtctl.h

## <a name="cdatetimectrlcdatetimectrl"></a><a name="cdatetimectrl"></a>CDateTimeCtrl::CDateTimeCtrl

Constrói um objeto `CDateTimeCtrl`.

```
CDateTimeCtrl();
```

## <a name="cdatetimectrlclosemonthcal"></a><a name="closemonthcal"></a>CDateTimeCtrl::CloseMonthCal

Fecha o controle atual de data e seleção de horários.

```cpp
void CloseMonthCal() const;
```

### <a name="remarks"></a>Comentários

Este método envia a mensagem [DTM_CLOSEMONTHCAL,](/windows/win32/Controls/dtm-closemonthcal) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_dateTimeCtrl*, que é usada para acessar programáticamente o controle de data e hora do seletor. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir fecha o calendário de isenção para o controle atual de data e seleção de horários.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#5](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_2.cpp)]

## <a name="cdatetimectrlcreate"></a><a name="create"></a>CDateTimeCtrl::Criar

Cria o controle do seletor de `CDateTimeCtrl` data e hora e o anexa ao objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica a combinação de estilos de controle de data-hora. Consulte [Os estilos de controle do seletor](/windows/win32/Controls/date-and-time-picker-control-styles) de data e hora no SDK do Windows para obter mais informações sobre os estilos de seleção de data e hora.

*Rect*<br/>
Uma referência a uma estrutura [RECT,](/windows/win32/api/windef/ns-windef-rect) que é a posição e o tamanho do controle de data e seleção de tempo.

*Pparentwnd*<br/>
Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle de seleção de data e hora. Não deve ser NULO.

*nID*<br/>
Especifica o ID de controle de controle de data e hora do seletor.

### <a name="return-value"></a>Valor retornado

Não zero se a criação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

##### <a name="to-create-a-date-and-time-picker-control"></a>Para criar um controle de seleção de data e hora

1. Ligue para [CDateTimeCtrl](#cdatetimectrl) para construir um `CDateTimeCtrl` objeto.

1. Ligue para esta função de membro, que cria o controle `CDateTimeCtrl` de seleção de data e hora do Windows e o anexa ao objeto.

Quando você `Create`chama, os controles comuns são inicializados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_3.cpp)]

## <a name="cdatetimectrlgetdatetimepickerinfo"></a><a name="getdatetimepickerinfo"></a>CDateTimeCtrl::GetDateTimePickerinfo

Recupera informações sobre o controle atual de data e seleção de horários.

```
BOOL GetDateTimePickerInfo(LPDATETIMEPICKERINFO pDateTimePickerInfo) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pDateTimePickerInfo*|[fora] Um ponteiro para uma estrutura [DATETIMEPICKERINFO](/windows/win32/api/commctrl/ns-commctrl-datetimepickerinfo) que recebe uma descrição do controle atual de data e seleção de horários.<br /><br /> O interlocutor é responsável por alocar essa estrutura. No entanto, este método inicializa o *membro cbSize* da estrutura.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [DTM_GETDATETIMEPICKERINFO,](/windows/win32/Controls/dtm-getdatetimepickerinfo) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_dateTimeCtrl*, que é usada para acessar programáticamente o controle de data e hora do seletor. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir indica se ele recupera com sucesso informações sobre o controle atual de data e seleção de horários.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#4](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_4.cpp)]

## <a name="cdatetimectrlgetmonthcalcolor"></a><a name="getmonthcalcolor"></a>CDateTimeCtrl::GetMonthCalColor

Recupera a cor para uma determinada parte do calendário do mês dentro do controle de data e seleção de horas.

```
COLORREF GetMonthCalColor(int iColor) const;
```

### <a name="parameters"></a>Parâmetros

*iColor*<br/>
Um **valor int** especificando qual área de cor do calendário do mês a recuperar. Para obter uma lista de valores, consulte o parâmetro *iColor* para [SetMonthCalColor](#setmonthcalcolor).

### <a name="return-value"></a>Valor retornado

Um valor COLORREF que representa a configuração de cor para a parte especificada do controle do calendário do mês se for bem-sucedido. A função retorna -1 se não tiver sucesso.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/dtm-getmccolor)Win32 DTM_GETMCCOLOR , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#2](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_5.cpp)]

## <a name="cdatetimectrlgetmonthcalctrl"></a><a name="getmonthcalctrl"></a>CDateTimeCtrl::GetMonthCalCtrl

Recupera o `CMonthCalCtrl` objeto associado ao controle de data e seleção de horários.

```
CMonthCalCtrl* GetMonthCalCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md) ou NULL se não tiver sucesso ou se a janela não estiver visível.

### <a name="remarks"></a>Comentários

Os controles do seletor de data e hora criam um controle de calendário do mês das crianças quando o usuário clica na seta suspensa. Quando `CMonthCalCtrl` o objeto não é mais necessário, ele é destruído, portanto, sua aplicação não deve depender de armazenar o objeto representando o calendário do mês do mês do filho do seletor de data.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#3](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_6.cpp)]

## <a name="cdatetimectrlgetmonthcalfont"></a><a name="getmonthcalfont"></a>CDateTimeCtrl::GetMonthCalFont

Obtém a fonte atualmente usada pelo controle do calendário do controle de data e hora do seletor.

```
CFont* GetMonthCalFont() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CFont](../../mfc/reference/cfont-class.md) ou NULL se não tiver sucesso.

### <a name="remarks"></a>Comentários

O `CFont` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.

## <a name="cdatetimectrlgetmonthcalstyle"></a><a name="getmonthcalstyle"></a>CDateTimeCtrl::GetMonthCalStyle

Obtém o estilo do controle de calendário do mês de suspensa que está associado ao controle atual de data e seleção de horários.

```
DWORD GetMonthCalStyle() const;
```

### <a name="return-value"></a>Valor retornado

O estilo do controle de calendário do mês suspensa, que é uma combinação bitwise (OR) dos estilos de controle de data e hora do seletor. Para obter mais informações, consulte [Month Calendar Control Styles](/windows/win32/Controls/month-calendar-control-styles).

### <a name="remarks"></a>Comentários

Este método envia a mensagem [DTM_GETMCSTYLE,](/windows/win32/Controls/dtm-getmcstyle) que é descrita no SDK do Windows.

## <a name="cdatetimectrlgetrange"></a><a name="getrange"></a>CDateTimeCtrl::GetRange

Recupera os tempos mínimos e máximos atuais do sistema para um controle de seleção de data e hora.

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
Um ponteiro para um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) contendo o tempo mais antigo permitido no `CDateTimeCtrl` objeto.

*pMaxRange*<br/>
Um ponteiro `COleDateTime` para um `CTime` objeto ou um objeto `CDateTimeCtrl` contendo o último tempo permitido no objeto.

### <a name="return-value"></a>Valor retornado

Um valor DWORD contendo sinalizadores que indicam quais intervalos estão definidos. Se

`return value & GDTR_MAX`== 0

então o segundo parâmetro é válido. Da mesma forma, se

`return value & GDTR_MIN`== 0

então o primeiro parâmetro é válido.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [DTM_GETRANGE](/windows/win32/Controls/dtm-getrange)de mensagem Win32, conforme descrito no SDK do Windows. Na implementação do MFC, `COleDateTime` você `CTime` pode especificar ou usos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#4](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_7.cpp)]

## <a name="cdatetimectrlgettime"></a><a name="gettime"></a>CDateTimeCtrl::GetTime

Recupera a hora atualmente selecionada a partir de um controle de `SYSTEMTIME` seleção de datae hora e hora e coloca-a em uma estrutura especificada.

```
BOOL GetTime(COleDateTime& timeDest) const;
DWORD GetTime(CTime& timeDest) const;
DWORD GetTime(LPSYSTEMTIME pTimeDest) const;
```

### <a name="parameters"></a>Parâmetros

*tempoDest*<br/>
Na primeira versão, uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) que receberá as informações de tempo do sistema. Na segunda versão, uma referência a um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) que receberá as informações de tempo do sistema.

*pTimeDest*<br/>
Um ponteiro para a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) para receber as informações de tempo do sistema. Não deve ser NULO.

### <a name="return-value"></a>Valor retornado

Na primeira versão, não zero se o `COleDateTime` tempo for gravado com sucesso no objeto; caso contrário, 0. Na segunda e terceira versões, um valor DWORD igual ao membro *dwFlag* definido na estrutura [NMDATETIMECHANGE.](/windows/win32/api/commctrl/ns-commctrl-nmdatetimechange) Consulte a seção **Observações** abaixo para obter mais informações.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/dtm-getsystemtime)Win32 DTM_GETSYSTEMTIME , conforme descrito no SDK do Windows. Na implementação do `GetTime`MFC, `COleDateTime` `CTime` você pode usar ou `SYSTEMTIME` classes, ou pode usar uma estrutura, para armazenar as informações de tempo.

O valor de devolução DWORD nas segunda e terceira versões acima, indica se o controle de data e hora do seletor está definido para o status "sem data", conforme indicado no *dwFlags*membro da estrutura [NMDATETIMECHANGE](/windows/win32/api/commctrl/ns-commctrl-nmdatetimechange) . Se o valor retornado for igual a GDT_NONE, o controle será definido como status "sem data" e usará o estilo DTS_SHOWNONE. Se o valor retornado for igual a GDT_VALID, o tempo do sistema será armazenado com sucesso no local de destino.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#5](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_8.cpp)]

## <a name="cdatetimectrlgetidealsize"></a><a name="getidealsize"></a>CDateTimeCtrl::GetIdealSize

Retorna o tamanho ideal do controle de data e seletor de horas necessário para exibir a data ou hora atuais.

```
BOOL GetIdealSize(LPSIZE psize) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Psize*|[fora] Pointer para uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) que contém o tamanho ideal para o controle.|

### <a name="return-value"></a>Valor retornado

O valor de retorno é sempre VERDADEIRO.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [DTM_GETIDEALSIZE,](/windows/win32/Controls/dtm-getidealsize) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_dateTimeCtrl*, que é usada para acessar programáticamente o controle de data e hora do seletor. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir recupera o tamanho ideal para exibir o controle do seletor de data e hora.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_9.cpp)]

## <a name="cdatetimectrlsetformat"></a><a name="setformat"></a>CDateTimeCtrl::SetFormat

Define a exibição de um controle de seleção de data e hora de acordo com uma seqüência de formato dada.

```
BOOL SetFormat(LPCTSTR pstrFormat);
```

### <a name="parameters"></a>Parâmetros

*pstrFormat*<br/>
Um ponteiro para uma seqüência de formato com término zero que define a exibição desejada. A definição deste parâmetro para NULL redefinirá o controle para a seqüência de formato padrão para o estilo atual.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

> [!NOTE]
> A entrada do usuário não determina o sucesso ou a falha desta chamada.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [DTM_SETFORMAT](/windows/win32/Controls/dtm-setformat)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#6](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_10.cpp)]

## <a name="cdatetimectrlsetmonthcalcolor"></a><a name="setmonthcalcolor"></a>CDateTimeCtrl::SetMonthCalColor

Define a cor para uma determinada parte do calendário do mês dentro de um controle de data e seleção de horas.

```
COLORREF SetMonthCalColor(
    int iColor,
    COLORREF ref);
```

### <a name="parameters"></a>Parâmetros

*iColor*<br/>
**int** valor especificando qual área do controle de calendário do mês a definir. Este valor pode ser um dos seguintes.

|Valor|Significado|
|-----------|-------------|
|MCSC_BACKGROUND|Defina a cor de fundo exibida entre meses.|
|MCSC_MONTHBK|Defina a cor de fundo exibida dentro de um mês.|
|MCSC_TEXT|Defina a cor usada para exibir o texto dentro de um mês.|
|MCSC_TITLEBK|Defina a cor de fundo exibida no título do calendário.|
|MCSC_TITLETEXT|Defina a cor usada para exibir o texto dentro do título do calendário.|
|MCSC_TRAILINGTEXT|Defina a cor usada para exibir o cabeçalho e o texto do dia seguinte. Os dias de cabeçalho e de saque são os dias dos meses anteriores e seguintes que aparecem no calendário atual.|

*ref*<br/>
Um valor COLORREF representando a cor que será definida para a área especificada do calendário do mês.

### <a name="return-value"></a>Valor retornado

Um valor COLORREF que representa a configuração de cor anterior para a parte especificada do controle do calendário do mês se for bem-sucedido. Caso contrário, a mensagem retorna -1.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [DTM_SETMCCOLOR](/windows/win32/Controls/dtm-setmccolor)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CDateTimeCtrl::GetMonthCalColor](#getmonthcalcolor).

## <a name="cdatetimectrlsetmonthcalfont"></a><a name="setmonthcalfont"></a>CDateTimeCtrl::SetMonthCalFont

Define a fonte que o controle de data e hora do controle do mês filho usará.

```cpp
void SetMonthCalFont(
    HFONT hFont,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Hfont*<br/>
Manuseie a fonte que será definida.

*Bredraw*<br/>
Especifica se o controle deve ser redesenhado imediatamente ao definir a fonte. Definir este parâmetro como TRUE faz com que o controle se refaça.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [DTM_SETMCFONT](/windows/win32/Controls/dtm-setmcfont)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#7](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_11.cpp)]

> [!NOTE]
> Se você usar este código, você vai querer `CDialog`fazer um membro da `CFont`sua classe derivada chamado *m_MonthFont* do tipo .

## <a name="cdatetimectrlsetmonthcalstyle"></a><a name="setmonthcalstyle"></a>CDateTimeCtrl::SetMonthCalStyle

Define o estilo do controle de calendário do mês de suspensa que está associado ao controle atual de data e seleção de horários.

```
DWORD SetMonthCalStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Dwstyle*|[em] Um novo estilo de controle de calendário do mês, que é uma combinação bitwise (OR) dos estilos de controle de calendário do mês. Para obter mais informações, consulte [Month Calendar Control Styles](/windows/win32/Controls/month-calendar-control-styles).|

### <a name="return-value"></a>Valor retornado

O estilo anterior do controle de calendário do mês suspensa.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [DTM_SETMCSTYLE,](/windows/win32/Controls/dtm-setmcstyle) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_dateTimeCtrl*, que é usada para acessar programáticamente o controle de data e hora do seletor. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o controle de data e hora do seletor para exibir números da semana, nomes abreviados de dias da semana e nenhum indicador de hoje.

[!code-cpp[NVC_MFC_CDateTimeCtrl_s1#3](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_12.cpp)]

## <a name="cdatetimectrlsetrange"></a><a name="setrange"></a>CDateTimeCtrl::SetRange

Define os tempos mínimos e máximos permitidos do sistema para um controle de seleção de data e hora.

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
Um ponteiro para um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) ou um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) contendo o tempo mais antigo permitido no `CDateTimeCtrl` objeto.

*pMaxRange*<br/>
Um ponteiro `COleDateTime` para um `CTime` objeto ou um objeto `CDateTimeCtrl` contendo o último tempo permitido no objeto.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/dtm-setrange)Win32 DTM_SETRANGE , conforme descrito no SDK do Windows. Na implementação do MFC, `COleDateTime` você `CTime` pode especificar ou usos. Se `COleDateTime` o objeto tiver um status NULL, o intervalo será removido. Se `CTime` o ponteiro `COleDateTime` ou o ponteiro forEM NUC, o intervalo será removido.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CDateTimeCtrl::GetRange](#getrange).

## <a name="cdatetimectrlsettime"></a><a name="settime"></a>CDateTimeCtrl::SetTime

Define a hora em um controle de seleção de data e hora.

```
BOOL SetTime(const COleDateTime& timeNew);
BOOL SetTime(const CTime* pTimeNew);
BOOL SetTime(LPSYSTEMTIME pTimeNew = NULL);
```

### <a name="parameters"></a>Parâmetros

*timeNew*<br/>
Uma referência a um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) contendo o para o qual o controle será definido.

*pTimeNew*<br/>
Na segunda versão acima, um ponteiro para um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) contendo o tempo para o qual o controle será definido. Na terceira versão acima, um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) contendo o tempo para o qual o controle será definido.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/dtm-setsystemtime)Win32 DTM_SETSYSTEMTIME , conforme descrito no SDK do Windows. Na implementação do `SetTime`MFC, `COleDateTime` você `CTime` pode usar as `SYSTEMTIME` classes ou pode usar uma estrutura, para definir as informações de tempo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CDateTimeCtrl#8](../../mfc/reference/codesnippet/cpp/cdatetimectrl-class_13.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC CMNCTRL1](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)
