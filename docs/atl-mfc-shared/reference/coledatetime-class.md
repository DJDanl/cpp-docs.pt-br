---
title: Classe COleDateTime
ms.date: 03/27/2019
f1_keywords:
- COleDateTime
- ATLCOMTIME/ATL::COleDateTime
- ATLCOMTIME/ATL::COleDateTime::COleDateTime
- ATLCOMTIME/ATL::COleDateTime::Format
- ATLCOMTIME/ATL::COleDateTime::GetAsDBTIMESTAMP
- ATLCOMTIME/ATL::COleDateTime::GetAsSystemTime
- ATLCOMTIME/ATL::COleDateTime::GetAsUDATE
- ATLCOMTIME/ATL::COleDateTime::GetCurrentTime
- ATLCOMTIME/ATL::COleDateTime::GetDay
- ATLCOMTIME/ATL::COleDateTime::GetDayOfWeek
- ATLCOMTIME/ATL::COleDateTime::GetDayOfYear
- ATLCOMTIME/ATL::COleDateTime::GetHour
- ATLCOMTIME/ATL::COleDateTime::GetMinute
- ATLCOMTIME/ATL::COleDateTime::GetMonth
- ATLCOMTIME/ATL::COleDateTime::GetSecond
- ATLCOMTIME/ATL::COleDateTime::GetStatus
- ATLCOMTIME/ATL::COleDateTime::GetYear
- ATLCOMTIME/ATL::COleDateTime::ParseDateTime
- ATLCOMTIME/ATL::COleDateTime::SetDate
- ATLCOMTIME/ATL::COleDateTime::SetDateTime
- ATLCOMTIME/ATL::COleDateTime::SetStatus
- ATLCOMTIME/ATL::COleDateTime::SetTime
- ATLCOMTIME/ATL::COleDateTime::m_dt
- ATLCOMTIME/ATL::COleDateTime::m_status
helpviewer_keywords:
- shared classes, COleDateTime
- time-only values
- Date data type, MFC encapsulation of
- COleDateTime class
- dates, handling in MFC
- time, handling in MFC
ms.assetid: e718f294-16ec-4649-88b6-a4dbae5178fb
ms.openlocfilehash: 5cbc131a81afef1ee94069f39e79f22ce7addfcb
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562461"
---
# <a name="coledatetime-class"></a>Classe COleDateTime

Encapsula o `DATE` tipo de dados que é usado na automação OLE.

## <a name="syntax"></a>Sintaxe

```
class COleDateTime
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime::COleDateTime](#coledatetime)|Constrói um objeto `COleDateTime`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime:: Format](#format)|Gera uma representação de cadeia de caracteres formatada de um `COleDateTime` objeto.|
|[COleDateTime::GetAsDBTIMESTAMP](#getasdbtimestamp)|Chame esse método para obter a hora no `COleDateTime` objeto como uma `DBTIMESTAMP` estrutura de dados.|
|[COleDateTime::GetAsSystemTime](#getassystemtime)|Chame esse método para obter a hora no `COleDateTime` objeto como uma estrutura de dados [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) .|
|[COleDateTime::GetAsUDATE](#getasudate)|Chame esse método para obter a hora no `COleDateTime` como uma `UDATE` estrutura de dados.|
|[COleDateTime:: getactualtime](#getcurrenttime)|Cria um `COleDateTime` objeto que representa a hora atual (função de membro estático).|
|[COleDateTime::GetDay](#getday)|Retorna o dia que este `COleDateTime` objeto representa (1-31).|
|[COleDateTime:: GetDayOfWeek](#getdayofweek)|Retorna o dia da semana que este `COleDateTime` objeto representa (domingo = 1).|
|[COleDateTime::GetDayOfYear](#getdayofyear)|Retorna o dia do ano que este `COleDateTime` objeto representa (1º de janeiro = 1).|
|[COleDateTime:: gethora](#gethour)|Retorna a hora que este `COleDateTime` objeto representa (0-23).|
|[COleDateTime:: GetMinute](#getminute)|Retorna o minuto que este `COleDateTime` objeto representa (0-59).|
|[COleDateTime::GetMonth](#getmonth)|Retorna o mês que este `COleDateTime` objeto representa (1-12).|
|[COleDateTime:: GetSecond](#getsecond)|Retorna o segundo que este `COleDateTime` objeto representa (0-59).|
|[COleDateTime:: GetStatus](#getstatus)|Obtém o status (validade) deste `COleDateTime` objeto.|
|[COleDateTime:: GetYear](#getyear)|Retorna o ano que este `COleDateTime` objeto representa.|
|[COleDateTime::P arseDateTime](#parsedatetime)|Lê um valor de data/hora de uma cadeia de caracteres e define o valor de `COleDateTime` .|
|[COleDateTime:: SetDate](#setdate)|Define o valor desse `COleDateTime` objeto para o valor de somente data especificado.|
|[COleDateTime:: SetDateTime](#setdatetime)|Define o valor desse `COleDateTime` objeto como o valor de data/hora especificado.|
|[COleDateTime:: SetStatus](#setstatus)|Define o status (validade) deste `COleDateTime` objeto.|
|[COleDateTime:: SetTime](#settime)|Define o valor desse `COleDateTime` objeto para o valor de tempo somente especificado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime:: operator = =, COleDateTime:: Operator <, etc.](#coledatetime_relational_operators)|Compare dois `COleDateTime` valores.|
|[COleDateTime:: operator +, COleDateTime:: Operator-](#operator_add_-)|Adicione e subtraia `COleDateTime` valores.|
|[COleDateTime:: operator + =, COleDateTime:: Operator-=](#operator_add_eq_-_eq)|Adicione e subtraia um `COleDateTime` valor desse `COleDateTime` objeto.|
|[COleDateTime:: Operator =](#operator_eq)|Copia um `COleDateTime` valor.|
|[COleDateTime:: Operator DATE, COleDateTime:: operador Date *](#operator_date)|Converte um `COleDateTime` valor em um `DATE` ou um `DATE*` .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime:: m_dt](#m_dt)|Contém o subjacente `DATE` para este `COleDateTime` objeto.|
|[COleDateTime:: m_status](#m_status)|Contém o status deste `COleDateTime` objeto.|

## <a name="remarks"></a>Comentários

`COleDateTime` Não tem uma classe base.

É um dos tipos possíveis para o tipo de dados [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) da automação OLE. Um `COleDateTime` valor representa um valor de data e hora absoluto.

O `DATE` tipo é implementado como um valor de ponto flutuante. Os dias são medidos a partir de 30 de dezembro de 1899, à meia-noite. A tabela a seguir mostra algumas datas e seus valores associados:

|Data|Valor|
|----------|-----------|
|29 de dezembro de 1899, meia-noite|-1,0|
|29 de dezembro de 1899, 6 A. M|-1,25|
|30 de dezembro de 1899, meia-noite|0.0|
|31 de dezembro de 1899, meia-noite|1.0|
|1º de janeiro de 1900, 18h|2.25|

> [!CAUTION]
> Na tabela acima, embora os valores de dia se tornem negativos antes da meia-noite em 30 de dezembro de 1899, os valores de hora do dia não são. Por exemplo, 6:00 AM é sempre representado por um valor fracionário 0,25, independentemente de o inteiro que representa o dia ser positivo (após 30 de dezembro de 1899) ou negativo (antes de 30 de dezembro de 1899). Isso significa que uma comparação de ponto flutuante simples classificaria erroneamente um `COleDateTime` representando 6:00 am em 12/29/1899 como **depois** de um representando 7:00 am no mesmo dia.

A `COleDateTime` classe lida com datas de 1º de janeiro de 100 até 31 de dezembro de 9999. A `COleDateTime` classe usa o calendário gregoriano; ela não oferece suporte a datas do Juliano. `COleDateTime` ignora o horário de verão. (Consulte [data e hora: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).)

> [!NOTE]
> Você pode usar o `%y` formato para recuperar um ano de dois dígitos apenas para datas a partir de 1900. Se você usar o `%y` formato em uma data anterior a 1900, o código gerará uma falha de asserção.

Esse tipo também é usado para representar valores somente de data ou de tempo. Por convenção, a data 0 (30 de dezembro de 1899) é usada para valores somente de tempo e a hora 00:00 (meia-noite) é usada para valores somente de data.

Se você criar um `COleDateTime` objeto usando uma data menor que 100, a data será aceita, mas as chamadas subsequentes para `GetYear` , `GetMonth` ,,, `GetDay` `GetHour` `GetMinute` e `GetSecond` falharão e retornarão-1. Anteriormente, você poderia usar datas de dois dígitos, mas as datas devem ser 100 ou maiores no MFC 4,2 e posterior.

Para evitar problemas, especifique uma data de quatro dígitos. Por exemplo:

[!code-cpp[NVC_ATLMFC_Utilities#1](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_1.cpp)]

As operações aritméticas básicas para os `COleDateTime` valores usam a classe complementar [COleDateTimeSpan](../../atl-mfc-shared/reference/coledatetimespan-class.md). `COleDateTimeSpan` os valores definem um intervalo de tempo. A relação entre essas classes é semelhante à entre [CTime](../../atl-mfc-shared/reference/ctime-class.md) e [CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md).

Para obter mais informações sobre `COleDateTime` as `COleDateTimeSpan` classes e, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLComTime. h

## <a name="coledatetime-relational-operators"></a><a name="coledatetime_relational_operators"></a> Operadores relacionais do COleDateTime

Operadores de comparação.

```
bool operator==(const COleDateTime& date) const throw();
bool operator!=(const COleDateTime& date) const throw();
bool operator<(const COleDateTime& date) const throw();
bool operator>(const COleDateTime& date) const throw();
bool operator<=(const COleDateTime& date) const throw();
bool operator>=(const COleDateTime& date) const throw();
```

### <a name="parameters"></a>Parâmetros

*date*<br/>
O objeto `COleDateTime` a ser comparado.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Um ATLASSERT ocorrerá se qualquer um dos dois operandos for inválido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#13](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_2.cpp)]

### <a name="example"></a>Exemplo

Os operadores **>=** , **\<=**, **>** e **<** , serão afirmados se o `COleDateTime` objeto for definido como nulo.

[!code-cpp[NVC_ATLMFC_Utilities#170](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_3.cpp)]

## <a name="coledatetimecoledatetime"></a><a name="coledatetime"></a> COleDateTime::COleDateTime

Constrói um objeto `COleDateTime`.

```
COleDateTime() throw();
COleDateTime(const VARIANT& varSrc) throw();
COleDateTime(DATE dtSrc) throw();
COleDateTime(time_t timeSrc) throw();
COleDateTime(__time64_t timeSrc) throw();
COleDateTime(const SYSTEMTIME& systimeSrc) throw();
COleDateTime(const FILETIME& filetimeSrc) throw();

COleDateTime(int nYear,
    int nMonth,
    int nDay,
    int nHour,
    int nMin,
    int nSec) throw();

COleDateTime(WORD wDosDate,
    WORD wDosTime) throw();
COleDateTime(const DBTIMESTAMP& timeStamp) throw();
```

### <a name="parameters"></a>Parâmetros

*dateSrc*<br/>
Um `COleDateTime` objeto existente a ser copiado para o novo `COleDateTime` objeto.

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Uma `VARIANT` estrutura de dados existente (possivelmente um `COleVariant` objeto) a ser convertida em um valor de data/hora (VT_DATE) e copiada para o novo `COleDateTime` objeto.

*dtSrc*<br/>
Um valor de data/hora ( `DATE` ) a ser copiado para o novo `COleDateTime` objeto.

*timeSrc*<br/>
Um `time_t` `__time64_t` valor ou a ser convertido em um valor de data/hora e copiado para o novo `COleDateTime` objeto.

*systimeSrc*<br/>
Uma `SYSTEMTIME` estrutura a ser convertida em um valor de data/hora e copiada para o novo `COleDateTime` objeto.

*filetimeSrc*<br/>
Uma `FILETIME` estrutura a ser convertida em um valor de data/hora e copiada para o novo `COleDateTime` objeto. Um `FILETIME` usa UTC (horário coordenado universal), portanto, se você passar uma hora local na estrutura, os resultados ficarão incorretos. Consulte os [horários de arquivo](/windows/win32/SysInfo/file-times) no SDK do Windows para obter mais informações.

*nYear*, *nMonth*, *ndia*, *nhora*, *nmín*, *NSEC*<br/>
Indique os valores de data e hora a serem copiados para o novo `COleDateTime` objeto.

*wDosDate*, *wDosTime*<br/>
Valores de data e hora do MS-DOS a serem convertidos em um valor de data/hora e copiados para o novo `COleDateTime` objeto.

*Estampa*<br/>
Uma referência a uma estrutura [DBTIMESTAMP](/dotnet/api/system.data.oledb.oledbtype) que contém a hora local atual.

### <a name="remarks"></a>Comentários

Todos esses construtores criam novos `COleDateTime` objetos inicializados para o valor especificado. A tabela a seguir mostra intervalos válidos para cada componente de data e hora:

|Componente de data/hora|Intervalo válido|
|--------------------------|-----------------|
|year|100-9999|
|month|0 - 12|
|dia|0 - 31|
|hour|0 - 23|
|minute|0 - 59|
|second|0 - 59|

Observe que o limite superior real do componente de dia varia de acordo com os componentes mês e ano. Para obter detalhes, consulte `SetDate` as `SetDateTime` funções de membro ou.

Veja a seguir uma breve descrição de cada Construtor:

- `COleDateTime(`**)** Constrói um `COleDateTime` objeto inicializado como 0 (meia-noite, 30 de dezembro de 1899).

- `COleDateTime(``dateSrc` **)** Constrói um `COleDateTime` objeto a partir de um `COleDateTime` objeto existente.

- `COleDateTime(`*varSrc* **)** constrói um `COleDateTime` objeto. Tenta converter uma `VARIANT` estrutura ou um objeto [COleVariant](../../mfc/reference/colevariant-class.md) em um valor de data/hora ( `VT_DATE` ). Se essa conversão for bem-sucedida, o valor convertido será copiado para o novo `COleDateTime` objeto. Se não for, o valor do `COleDateTime` objeto será definido como 0 (meia-noite, 30 de dezembro de 1899) e seu status como inválido.

- `COleDateTime(``dtSrc` **)** Constrói um `COleDateTime` objeto a partir de um `DATE` valor.

- `COleDateTime(``timeSrc` **)** Constrói um `COleDateTime` objeto a partir de um `time_t` valor.

- `COleDateTime(`*systimeSrc* **)** constrói um `COleDateTime` objeto a partir de um `SYSTEMTIME` valor.

- `COleDateTime(``filetimeSrc` **)** Constrói um `COleDateTime` objeto a partir de um `FILETIME` valor. . Um `FILETIME` usa UTC (horário coordenado universal), portanto, se você passar uma hora local na estrutura, os resultados ficarão incorretos. Para obter mais informações, consulte [horas de arquivo](/windows/win32/SysInfo/file-times) no SDK do Windows.

- `COleDateTime(``nYear`, `nMonth` , `nDay` , `nHour` , `nMin` , `nSec` **)** Constrói um `COleDateTime` objeto a partir dos valores numéricos especificados.

- `COleDateTime(``wDosDate`, `wDosTime` **)** Constrói um `COleDateTime` objeto dos valores de data e hora do MS-dos especificados.

Para obter mais informações sobre o `time_t` tipo de dados, consulte a função [time](../../c-runtime-library/reference/time-time32-time64.md) na referência da biblioteca de *tempo de execução*.

Para obter mais informações, consulte as estruturas [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) e [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) no SDK do Windows.

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

> [!NOTE]
> O construtor que usa o `DBTIMESTAMP` parâmetro só estará disponível quando OLEDB. h estiver incluído.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#2](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_4.cpp)]

## <a name="coledatetimeformat"></a><a name="format"></a> COleDateTime:: Format

Cria uma representação formatada do valor de data/hora.

```
CString Format(DWORD dwFlags = 0,  LCID lcid = LANG_USER_DEFAULT) const;
CString Format(LPCTSTR lpszFormat) const;
CString Format(UINT nFormatID) const;
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Indica um dos seguintes sinalizadores de localidade:

- LOCALE_NOUSEROVERRIDE usar as configurações de localidade padrão do sistema, em vez de configurações de usuário personalizadas.

- VAR_TIMEVALUEONLY ignorar a parte de data durante a análise.

- VAR_DATEVALUEONLY ignorar a parte de tempo durante a análise.

*lcid*<br/>
Indica a ID de localidade a ser usada para a conversão. Para obter mais informações sobre identificadores de idioma, consulte [identificadores de idioma](/windows/win32/Intl/language-identifiers).

*lpszFormat*<br/>
Uma cadeia de caracteres de formatação semelhante à `printf` cadeia de caracteres de formatação. Cada código de formatação, precedido por um sinal de porcentagem ( `%` ), é substituído pelo `COleDateTime` componente correspondente. Outros caracteres na cadeia de caracteres de formatação são copiados inalterados para a cadeia de caracteres retornada. Para obter mais informações, consulte a função de tempo de execução [strftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md). O valor e o significado dos códigos de formatação para o `Format` são:

- `%H` Horas no dia atual

- `%M` Minutos na hora atual

- `%S` Segundos no minuto atual

- `%%` Sinal de porcentagem

*nFormatID*<br/>
A ID de recurso para a cadeia de caracteres de controle de formato.

### <a name="return-value"></a>Valor retornado

Uma `CString` que contém o valor de data/hora formatado.

### <a name="remarks"></a>Comentários

Se o status desse `COleDateTime` objeto for nulo, o valor de retorno será uma cadeia de caracteres vazia. Se o status for inválido, a cadeia de caracteres de retorno será especificada pelo recurso de cadeia de caracteres ATL_IDS_DATETIME_INVALID.

Segue uma breve descrição dos três formulários para essa função:

`Format`( *dwFlags*, *LCID*)<br/>
Esse formulário formata o valor usando as especificações de idioma (IDs de localidade) para data e hora. Usando os parâmetros padrão, esse formulário imprimirá a data e a hora, a menos que a parte de hora seja 0 (meia-noite). nesse caso, ela será impressa apenas na data ou a parte da data será 0 (30 de dezembro de 1899). nesse caso, ela será impressa apenas no momento. Se o valor de data/hora for 0 (30 de dezembro de 1899, meia-noite), esse formulário com os parâmetros padrão será impresso na meia-noite.

`Format`( *lpszFormat*)<br/>
Esse formulário formata o valor usando a cadeia de caracteres de formato que contém códigos de formatação especiais precedidos por um sinal de porcentagem (%), como em `printf` . A cadeia de caracteres de formatação é passada como um parâmetro para a função. Para obter mais informações sobre os códigos de formatação, consulte [strftime, wcsftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) na referência da biblioteca de tempo de execução.

`Format`( *nFormatID*)<br/>
Esse formulário formata o valor usando a cadeia de caracteres de formato que contém códigos de formatação especiais precedidos por um sinal de porcentagem (%), como em `printf` . A cadeia de caracteres de formatação é um recurso. A ID desse recurso de cadeia de caracteres é passada como o parâmetro. Para obter mais informações sobre os códigos de formatação, consulte [strftime, wcsftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) na *referência da biblioteca de tempo de execução*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#3](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_5.cpp)]

## <a name="coledatetimegetasdbtimestamp"></a><a name="getasdbtimestamp"></a> COleDateTime::GetAsDBTIMESTAMP

Chame esse método para obter a hora no `COleDateTime` objeto como uma `DBTIMESTAMP` estrutura de dados.

```
bool GetAsDBTIMESTAMP(DBTIMESTAMP& timeStamp) const throw();
```

### <a name="parameters"></a>Parâmetros

*Estampa*<br/>
Uma referência a uma estrutura [DBTIMESTAMP](/dotnet/api/system.data.oledb.oledbtype) .

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Armazena o tempo resultante na estrutura de *carimbo de data/hora* referenciada. A `DBTIMESTAMP` estrutura de dados inicializada por essa função terá seu `fraction` membro definido como zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#4](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_6.cpp)]

## <a name="coledatetimegetassystemtime"></a><a name="getassystemtime"></a> COleDateTime::GetAsSystemTime

Chame esse método para obter a hora no `COleDateTime` objeto como uma `SYSTEMTIME` estrutura de dados.

```
bool GetAsSystemTime(SYSTEMTIME& sysTime) const throw();
```

### <a name="parameters"></a>Parâmetros

*sysTime*<br/>
Uma referência a uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) para receber o valor de data/hora convertido do `COleDateTime` objeto.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se for bem-sucedido; FALSE se a conversão falhar ou se o `COleDateTime` objeto for nulo ou inválido.

### <a name="remarks"></a>Comentários

`GetAsSystemTime` armazena o tempo resultante no objeto *SysTime* referenciado. A `SYSTEMTIME` estrutura de dados inicializada por essa função terá seu `wMilliseconds` membro definido como zero.

Para obter mais informações sobre as informações de status mantidas em um `COleDateTime` objeto, consulte [GetStatus](#getstatus).

## <a name="coledatetimegetasudate"></a><a name="getasudate"></a> COleDateTime::GetAsUDATE

Chame esse método para obter a hora no `COleDateTime` objeto como uma `UDATE` estrutura de dados.

```
bool GetAsUDATE(UDATE& uDate) const throw();
```

### <a name="parameters"></a>Parâmetros

*uDate*<br/>
Uma referência a uma `UDATE` estrutura para receber o valor de data/hora convertido do `COleDateTime` objeto.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se for bem-sucedido; FALSE se a conversão falhar ou se o `COleDateTime` objeto for nulo ou inválido.

### <a name="remarks"></a>Comentários

Uma `UDATE` estrutura representa uma data "desempacotada".

## <a name="coledatetimegetcurrenttime"></a><a name="getcurrenttime"></a> COleDateTime:: getactualtime

Chame essa função de membro estático para retornar o valor de data/hora atual.

```
static COleDateTime WINAPI GetCurrentTime() throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#5](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_7.cpp)]

## <a name="coledatetimegetday"></a><a name="getday"></a> COleDateTime::GetDay

Obtém o dia do mês representado por esse valor de data/hora.

```
int GetDay() const throw();
```

### <a name="return-value"></a>Valor retornado

O dia do mês representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o dia não pôde ser obtido.

### <a name="remarks"></a>Comentários

Valores de retorno válidos variam entre 1 e 31.

Para obter informações sobre outras funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [Gethora](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#6](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_8.cpp)]

## <a name="coledatetimegetdayofweek"></a><a name="getdayofweek"></a> COleDateTime:: GetDayOfWeek

Obtém o dia do mês representado por esse valor de data/hora.

```
int GetDayOfWeek() const throw();
```

### <a name="return-value"></a>Valor retornado

O dia da semana representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o dia da semana não pôde ser obtido.

### <a name="remarks"></a>Comentários

Valores de retorno válidos variam entre 1 e 7, em que 1 = domingo, 2 = segunda-feira e assim por diante.

Para obter informações sobre outras funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [Gethora](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#7](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_9.cpp)]

## <a name="coledatetimegetdayofyear"></a><a name="getdayofyear"></a> COleDateTime::GetDayOfYear

Obtém o dia do ano representado por esse valor de data/hora.

```
int GetDayOfYear() const throw();
```

### <a name="return-value"></a>Valor retornado

O dia do ano representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o dia do ano não pôde ser obtido.

### <a name="remarks"></a>Comentários

Valores de retorno válidos variam entre 1 e 366, em que 1º de janeiro = 1.

Para obter informações sobre outras funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [Gethora](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#8](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_10.cpp)]

## <a name="coledatetimegethour"></a><a name="gethour"></a> COleDateTime:: gethora

Obtém a hora representada por esse valor de data/hora.

```
int GetHour() const throw();
```

### <a name="return-value"></a>Valor retornado

A hora representada pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se a hora não pôde ser obtida.

### <a name="remarks"></a>Comentários

Valores de retorno válidos variam entre 0 e 23.

Para obter informações sobre outras funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#9](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_11.cpp)]

## <a name="coledatetimegetminute"></a><a name="getminute"></a> COleDateTime:: GetMinute

Obtém o minuto representado por esse valor de data/hora.

```
int GetMinute() const throw();
```

### <a name="return-value"></a>Valor retornado

O minuto representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o minuto não puder ser obtido.

### <a name="remarks"></a>Comentários

Valores de retorno válidos variam entre 0 e 59.

Para obter informações sobre outras funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [Gethora](#gethour)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

Consulte o exemplo de [gethora](#gethour).

## <a name="coledatetimegetmonth"></a><a name="getmonth"></a> COleDateTime::GetMonth

Obtém o mês representado por esse valor de data/hora.

```
int GetMonth() const throw();
```

### <a name="return-value"></a>Valor retornado

O mês representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o mês não pôde ser obtido.

### <a name="remarks"></a>Comentários

Valores de retorno válidos variam entre 1 e 12.

Para obter informações sobre outras funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetYear](#getyear)

- [Gethora](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

Consulte o exemplo de [getDay](#getday).

## <a name="coledatetimegetsecond"></a><a name="getsecond"></a> COleDateTime:: GetSecond

Obtém o segundo representado por esse valor de data/hora.

```
int GetSecond() const throw();
```

### <a name="return-value"></a>Valor retornado

O segundo é representado pelo valor desse `COleDateTime` objeto ou `COleDateTime::error` se o segundo não pôde ser obtido.

### <a name="remarks"></a>Comentários

Valores de retorno válidos variam entre 0 e 59.

> [!NOTE]
> A `COleDateTime` classe não dá suporte a segundos bissextos.

Para obter mais informações sobre a implementação do `COleDateTime` , consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

Para obter informações sobre outras funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [Gethora](#gethour)

- [GetMinute](#getminute)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

Consulte o exemplo de [gethora](#gethour).

## <a name="coledatetimegetstatus"></a><a name="getstatus"></a> COleDateTime:: GetStatus

Obtém o status (validade) de um determinado `COleDateTime` objeto.

```
DateTimeStatus GetStatus() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o status desse `COleDateTime` valor. Se você chamar `GetStatus` em um `COleDateTime` objeto construído com o padrão, ele retornará válido. Se você chamar `GetStatus` em um `COleDateTime` objeto inicializado com o Construtor definido como NULL, `GetStatus` retornará NULL.

### <a name="remarks"></a>Comentários

O valor de retorno é definido pelo `DateTimeStatus` tipo enumerado, que é definido dentro da `COleDateTime` classe.

```
enum DateTimeStatus
{
   error = -1,
   valid = 0,
   invalid = 1,    // Invalid date (out of range, etc.)
   null = 2,       // Literally has no value
};
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleDateTime::error` Indica que ocorreu um erro ao tentar obter parte do valor de data/hora.

- `COleDateTime::valid` Indica que este `COleDateTime` objeto é válido.

- `COleDateTime::invalid` Indica que este `COleDateTime` objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleDateTime::null` Indica que esse `COleDateTime` objeto é nulo, ou seja, que nenhum valor foi fornecido para esse objeto. (Isso é "NULL" no sentido do banco de dados de "sem valor", em oposição ao C++ NULL.)

O status de um `COleDateTime` objeto é inválido nos seguintes casos:

- Se seu valor for definido de um `VARIANT` `COleVariant` valor ou que não pôde ser convertido em um valor de data/hora.

- Se seu valor for definido de um `time_t` `SYSTEMTIME` valor,, ou `FILETIME` que não pôde ser convertido em um valor de data/hora válido.

- Se seu valor for definido por `SetDateTime` com valores de parâmetro inválidos.

- Se esse objeto tiver ocorrido um estouro ou negativo durante uma operação de atribuição aritmética, ou seja, `+=` ou `-=` .

- Se um valor inválido foi atribuído a esse objeto.

- Se o status deste objeto foi definido explicitamente como inválido usando `SetStatus` .

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte as seguintes funções de membro:

- [COleDateTime](#coledatetime)

- [SetDateTime](#setdatetime)

- [operador +,-](#operator_add_-)

- [operador + =,-=](#operator_add_eq_-_eq)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#10](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_12.cpp)]

## <a name="coledatetimegetyear"></a><a name="getyear"></a> COleDateTime:: GetYear

Obtém o ano representado por esse valor de data/hora.

```
int GetYear() const throw();
```

### <a name="return-value"></a>Valor retornado

O ano representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o ano não pôde ser obtido.

### <a name="remarks"></a>Comentários

Os valores de retorno válidos variam entre 100 e 9999, que inclui o século.

Para obter informações sobre outras funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [Gethora](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

Consulte o exemplo de [getDay](#getday).

## <a name="coledatetimem_dt"></a><a name="m_dt"></a> COleDateTime:: m_dt

A `DATE` estrutura subjacente deste `COleDateTime` objeto.

```
DATE m_dt;
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
> Alterar o valor no `DATE` objeto acessado pelo ponteiro retornado por essa função alterará o valor desse `COleDateTime` objeto. Ele não altera o status desse `COleDateTime` objeto.

Para obter mais informações sobre a implementação do `DATE` objeto, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimem_status"></a><a name="m_status"></a> COleDateTime:: m_status

Contém o status deste `COleDateTime` objeto.

```
DateTimeStatus m_status;
```

### <a name="remarks"></a>Comentários

O tipo desse membro de dados é o tipo enumerado `DateTimeStatus` , que é definido dentro da `COleDateTime` classe. Para obter mais informações, consulte [COleDateTime:: GetStatus](#getstatus).

> [!CAUTION]
> Esse membro de dados destina-se a situações de programação avançada. Você deve usar as funções membro embutido [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para obter mais precauções sobre como definir explicitamente esse membro de dados.

## <a name="coledatetimeoperator-"></a><a name="operator_eq"></a> COleDateTime:: Operator =

Copia um `COleDateTime` valor.

```
COleDateTime& operator=(const VARIANT& varSrc) throw();
COleDateTime& operator=(DATE dtSrc) throw();
COleDateTime& operator=(const time_t& timeSrc) throw();
COleDateTime& operator=(const __time64_t& timeSrc) throw();
COleDateTime& operator=(const SYSTEMTIME& systimeSrc) throw();
COleDateTime& operator=(const FILETIME& filetimeSrc) throw();
COleDateTime& operator=(const UDATE& uDate) throw();
```

### <a name="remarks"></a>Comentários

Esses operadores de atribuição sobrecarregados copiam o valor de data/hora de origem nesse `COleDateTime` objeto. Segue uma breve descrição de cada um dos operadores de atribuição sobrecarregados:

- **Operator = (** `dateSrc` **)** o valor e o status do operando são copiados para `COleDateTime` esse objeto.

- **Operator = (** *varSrc* **)** Se a conversão do valor da [variante](/windows/win32/api/oaidl/ns-oaidl-variant) (ou objeto [COleVariant](../../mfc/reference/colevariant-class.md) ) em uma data/hora (VT_DATE) for bem-sucedida, o valor convertido será copiado para esse `COleDateTime` objeto e seu status será definido como válido. Se a conversão não for bem-sucedida, o valor desse objeto será definido como zero (30 de dezembro de 1899, meia-noite) e seu status como inválido.

- **Operator = (** `dtSrc` **)** o `DATE` valor é copiado para esse `COleDateTime` objeto e seu status é definido como válido.

- **Operator = (** `timeSrc` **)** o `time_t` `__time64_t` valor or é convertido e copiado para esse `COleDateTime` objeto. Se a conversão for bem-sucedida, o status desse objeto será definido como válido; Se não for bem-sucedida, ele será definido como inválido.

- **Operator = (** *systimeSrc* **)** O valor de [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) é convertido e copiado para esse `COleDateTime` objeto. Se a conversão for bem-sucedida, o status desse objeto será definido como válido; Se não for bem-sucedida, ele será definido como inválido.

- **Operator = (** `uDate` **)** o `UDATE` valor é convertido e copiado para esse `COleDateTime` objeto. Se a conversão for bem-sucedida, o status desse objeto será definido como válido; Se não for bem-sucedida, ele será definido como inválido. Uma `UDATE` estrutura representa uma data "desempacotada". Para obter mais informações, consulte a função [VarDateFromUdate](/windows/win32/api/oleauto/nf-oleauto-vardatefromudate).

- **Operator = (** `filetimeSrc` **)** o valor [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) é convertido e copiado para esse `COleDateTime` objeto. Se a conversão for bem-sucedida, o status desse objeto será definido como válido; caso contrário, ele será definido como inválido. `FILETIME` usa UTC (horário coordenado universal), portanto, se você passar uma hora UTC na estrutura, os resultados serão convertidos da hora UTC para a hora local e serão armazenados como hora da variante. Esse comportamento é o mesmo de Visual C++ 6,0 e Visual C++ .NET 2003 SP2. Para obter mais informações, consulte [horas de arquivo](/windows/win32/SysInfo/file-times) no SDK do Windows.

Para obter mais informações, consulte a entrada [variante](/windows/win32/api/oaidl/ns-oaidl-variant) na SDK do Windows.

Para obter mais informações sobre o `time_t` tipo de dados, consulte a função [time](../../c-runtime-library/reference/time-time32-time64.md) na referência da biblioteca de *tempo de execução*.

Para obter mais informações, consulte as estruturas [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) e [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) no SDK do Windows.

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimeoperator---"></a><a name="operator_add_-"></a> COleDateTime:: operator +,-

Adicione e subtraia `ColeDateTime` valores.

```
COleDateTime operator+(COleDateTimeSpan dateSpan) const throw();
COleDateTime operator-(COleDateTimeSpan dateSpan) const throw();
COleDateTimeSpan operator-(const COleDateTime& date) const throw();
```

### <a name="remarks"></a>Comentários

`COleDateTime` os objetos representam tempos absolutos. Os objetos [COleDateTimeSpan](../../atl-mfc-shared/reference/coledatetimespan-class.md) representam tempos relativos. Os primeiros dois operadores permitem adicionar e subtrair um `COleDateTimeSpan` valor de um `COleDateTime` valor. O terceiro operador permite subtrair um `COleDateTime` valor de outro para gerar um `COleDateTimeSpan` valor.

Se um dos operandos for nulo, o status do `COleDateTime` valor resultante será NULL.

Se o `COleDateTime` valor resultante ficar fora dos limites dos valores aceitáveis, o status desse `COleDateTime` valor será inválido.

Se qualquer um dos operandos for inválido e o outro não for nulo, o status do valor resultante `COleDateTime` será inválido.

Os **+** **-** operadores e serão afirmados se o `COleDateTime` objeto for definido como nulo. Consulte [operadores relacionais do COleDateTime](#coledatetime_relational_operators) para obter um exemplo.

Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte a variável de membro [m_status](#m_status) .

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#12](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_13.cpp)]

## <a name="coledatetimeoperator---"></a><a name="operator_add_eq_-_eq"></a> COleDateTime:: operator + =,-=

Adicione e subtraia um `ColeDateTime` valor desse `COleDateTime` objeto.

```
COleDateTime& operator+=(COleDateTimeSpan dateSpan) throw();
COleDateTime& operator-=(COleDateTimeSpan dateSpan) throw();
```

### <a name="remarks"></a>Comentários

Esses operadores permitem adicionar e subtrair um `COleDateTimeSpan` valor de e para isso `COleDateTime` . Se um dos operandos for nulo, o status do `COleDateTime` valor resultante será NULL.

Se o `COleDateTime` valor resultante ficar fora dos limites dos valores aceitáveis, o status desse `COleDateTime` valor será definido como inválido.

Se um dos operandos for inválido e outro não for nulo, o status do `COleDateTime` valor resultante será inválido.

Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte a variável de membro [m_status](#m_status) .

Os **+=** **-=** operadores e serão afirmados se o `COleDateTime` objeto for definido como nulo. Consulte [operadores relacionais do COleDateTime](#coledatetime_relational_operators) para obter um exemplo.

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimeoperator-date"></a><a name="operator_date"></a> COleDateTime:: data do operador

Converte um `ColeDateTime` valor em um `DATE` .

```
operator DATE() const throw();
```

### <a name="remarks"></a>Comentários

Esse operador retorna um `DATE` objeto cujo valor é copiado deste `COleDateTime` objeto. Para obter mais informações sobre a implementação do `DATE` objeto, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

O `DATE` operador irá declarar se o `COleDateTime` objeto for definido como nulo. Consulte [operadores relacionais do COleDateTime](#coledatetime_relational_operators) para obter um exemplo.

## <a name="coledatetimeparsedatetime"></a><a name="parsedatetime"></a> COleDateTime::P arseDateTime

Analisa uma cadeia de caracteres para ler um valor de data/hora.

```
bool ParseDateTime(
    LPCTSTR lpszDate,
    DWORD dwFlags = 0,
    LCID lcid = LANG_USER_DEFAULT) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszDate*<br/>
Um ponteiro para a cadeia de caracteres terminada em nulo que deve ser analisado. Para obter detalhes, consulte Observações.

*dwFlags*<br/>
Indica sinalizadores para configurações de localidade e análise. Um ou mais dos seguintes sinalizadores:

- LOCALE_NOUSEROVERRIDE usar as configurações de localidade padrão do sistema, em vez de configurações personalizadas do usuário.

- VAR_TIMEVALUEONLY ignorar a parte de data durante a análise.

- VAR_DATEVALUEONLY ignorar a parte de tempo durante a análise.

*lcid*<br/>
Indica a ID de localidade a ser usada para a conversão.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se a cadeia de caracteres tiver sido convertida com êxito em um valor de data/hora, caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se a cadeia de caracteres tiver sido convertida com êxito em um valor de data/hora, o valor desse `COleDateTime` objeto será definido como esse valor e seu status como válido.

> [!NOTE]
> Os valores de ano devem estar entre 100 e 9999, inclusive.

O parâmetro *lpszDate* pode usar uma variedade de formatos. Por exemplo, as seguintes cadeias de caracteres contêm formatos de data/hora aceitáveis:

`"25 January 1996"`

`"8:30:00"`

`"20:30:00"`

`"January 25, 1996 8:30:00"`

`"8:30:00 Jan. 25, 1996"`

`"1/25/1996 8:30:00"  // always specify the full year, even in a 'short date' format`

A identificação de localidade também afetará se o formato da cadeia de caracteres é aceitável para conversão em um valor de data/hora.

No caso de VAR_DATEVALUEONLY, o valor de hora é definido como hora 0 ou meia-noite. No caso de VAR_TIMEVALUEONLY, o valor de data é definido como data 0, significando 30 de dezembro de 1899.

Se a cadeia de caracteres não puder ser convertida em um valor de data/hora ou se houvesse um estouro numérico, o status desse `COleDateTime` objeto será inválido.

Para obter mais informações sobre os limites e a implementação de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimesetdate"></a><a name="setdate"></a> COleDateTime:: SetDate

Define a data deste `COleDateTime` objeto.

```
int SetDate(
    int nYear,
    int nMonth,
    int nDay) throw();
```

### <a name="parameters"></a>Parâmetros

*nYear*\
Indica o ano a ser copiado para esse `COleDateTime` objeto.

*nMonth*\
Indica o mês a ser copiado para esse `COleDateTime` objeto.

*Ndia*\
Indica o dia para copiar nesse `COleDateTime` objeto.

### <a name="return-value"></a>Valor retornado

Zero se o valor deste `COleDateTime` objeto foi definido com êxito; caso contrário, 1. Esse valor de retorno é baseado no `DateTimeStatus` tipo enumerado. Para obter mais informações, consulte a função de membro [SetStatus](#setstatus) .

### <a name="remarks"></a>Comentários

A data é definida com os valores especificados. A hora é definida como hora 0, meia-noite.

Consulte a tabela a seguir para obter os limites para os valores de parâmetro:

|Parâmetro|Limites|
|---------------|------------|
|*nYear*|100-9999|
|*nMonth*|1 - 12|
|*Ndia*|0 - 31|

Se o dia do mês estourar, ele será convertido no dia correto do próximo mês e o mês e/ou ano será incrementado de acordo. Um valor de dia igual a zero indica o último dia do mês anterior. O comportamento é o mesmo que `SystemTimeToVariantTime` .

Se o valor de data especificado pelos parâmetros não for válido, o status desse objeto será definido como `COleDateTime::invalid` . Você deve usar [GetStatus](#getstatus) para verificar a validade do `DATE` valor e não deve pressupor que o valor de [m_dt](#m_dt) permanecerá inalterado.

Aqui estão alguns exemplos de valores de data:

|*nYear*|*nMonth*|*Ndia*|Valor|
|-------------|--------------|------------|-----------|
|2000|2|29|29 de fevereiro de 2000|
|1776|7|4|4 de julho de 1776|
|1925|4|35|35 de abril de 1925 (data inválida)|
|10000|1|1|1 de janeiro de 10000 (data inválida)|

Para definir a data e a hora, consulte [COleDateTime:: SetDateTime](#setdatetime).

Para obter informações sobre funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [Gethora](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#11](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_14.cpp)]

## <a name="coledatetimesetdatetime"></a><a name="setdatetime"></a> COleDateTime:: SetDateTime

Define a data e a hora deste `COleDateTime` objeto.

```
int SetDateTime(
    int nYear,
    int nMonth,
    int nDay,
    int nHour,
    int nMin,
    int nSec) throw();
```

### <a name="parameters"></a>Parâmetros

*nYear*, *nMonth*, *ndia*, *nhora*, *nmín*, *NSEC*<br/>
Indique os componentes de data e hora a serem copiados para esse `COleDateTime` objeto.

### <a name="return-value"></a>Valor retornado

Zero se o valor deste `COleDateTime` objeto foi definido com êxito; caso contrário, 1. Esse valor de retorno é baseado no `DateTimeStatus` tipo enumerado. Para obter mais informações, consulte a função de membro [SetStatus](#setstatus) .

### <a name="remarks"></a>Comentários

Consulte a tabela a seguir para obter os limites para os valores de parâmetro:

|Parâmetro|Limites|
|---------------|------------|
|*nYear*|100-9999|
|*nMonth*|1 - 12|
|*Ndia*|0 - 31|
|*Nhora*|0 - 23|
|*Nmín*|0 - 59|
|*nSec*|0 - 59|

Se o dia do mês estourar, ele será convertido no dia correto do próximo mês e o mês e/ou ano será incrementado de acordo. Um valor de dia igual a zero indica o último dia do mês anterior. O comportamento é o mesmo que [SystemTimeToVariantTime](/windows/win32/api/oleauto/nf-oleauto-systemtimetovarianttime).

Se o valor de data ou hora especificado pelos parâmetros não for válido, o status desse objeto será definido como inválido e o valor desse objeto não será alterado.

Aqui estão alguns exemplos de valores de tempo:

|*Nhora*|*Nmín*|*nSec*|Valor|
|-------------|------------|------------|-----------|
|1|3|3|01:03:03|
|23|45|0|23:45:00|
|25|30|0|Inválido|
|9|60|0|Inválido|

Aqui estão alguns exemplos de valores de data:

|*nYear*|*nMonth*|*Ndia*|Valor|
|-------------|--------------|------------|-----------|
|1995|4|15|15 de abril de 1995|
|1789|7|14|17 de julho de 1789|
|1925|2|30|Inválido|
|10000|1|1|Inválido|

Para definir apenas a data, consulte [COleDateTime:: SetDate](#setdate). Para definir apenas a hora, consulte [COleDateTime:: SetTime](#settime).

Para obter informações sobre funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [Gethora](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

Consulte o exemplo de [GetStatus](#getstatus).

## <a name="coledatetimesetstatus"></a><a name="setstatus"></a> COleDateTime:: SetStatus

Define o status deste `COleDateTime` objeto.

```cpp
void SetStatus(DateTimeStatus status) throw();
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O novo valor de status deste `COleDateTime` objeto.

### <a name="remarks"></a>Comentários

O valor do parâmetro *status* é definido pelo `DateTimeStatus` tipo enumerado, que é definido dentro da `COleDateTime` classe. Consulte [COleDateTime:: GetStatus](#getstatus) para obter detalhes.

> [!CAUTION]
> Essa função é para situações de programação avançada. Essa função não altera os dados neste objeto. Com mais frequência, ele será usado para definir o status como **nulo** ou **inválido**. O operador de atribuição ([operador =](#operator_eq)) e [SetDateTime](#setdatetime) definem o status do objeto com base no (s) valor (es) de origem.

### <a name="example"></a>Exemplo

Consulte o exemplo de [GetStatus](#getstatus).

## <a name="coledatetimesettime"></a><a name="settime"></a> COleDateTime:: SetTime

Define a hora deste `COleDateTime` objeto.

```
int SetTime(
    int nHour,
    int nMin,
    int nSec) throw();
```

### <a name="parameters"></a>Parâmetros

*nhora*, *nmín*, *NSEC*<br/>
Indique os componentes de tempo a serem copiados para esse `COleDateTime` objeto.

### <a name="return-value"></a>Valor retornado

Zero se o valor deste `COleDateTime` objeto foi definido com êxito; caso contrário, 1. Esse valor de retorno é baseado no `DateTimeStatus` tipo enumerado. Para obter mais informações, consulte a função de membro [SetStatus](#setstatus) .

### <a name="remarks"></a>Comentários

A hora é definida com os valores especificados. A data é definida para a data 0, significando 30 de dezembro de 1899.

Consulte a tabela a seguir para obter os limites para os valores de parâmetro:

|Parâmetro|Limites|
|---------------|------------|
|*Nhora*|0 - 23|
|*Nmín*|0 - 59|
|*nSec*|0 - 59|

Se o valor de hora especificado pelos parâmetros não for válido, o status desse objeto será definido como inválido e o valor desse objeto não será alterado.

Aqui estão alguns exemplos de valores de tempo:

|*Nhora*|*Nmín*|*nSec*|Valor|
|-------------|------------|------------|-----------|
|1|3|3|01:03:03|
|23|45|0|23:45:00|
|25|30|0|Inválido|
|9|60|0|Inválido|

Para definir a data e a hora, consulte [COleDateTime:: SetDateTime](#setdatetime).

Para obter informações sobre funções de membro que consultam o valor desse `COleDateTime` objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [Gethora](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte a [data e hora do artigo: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

Consulte o exemplo de [SetDate](#setdate).

## <a name="see-also"></a>Confira também

[Classe COleVariant](../../mfc/reference/colevariant-class.md)<br/>
[Classe CTime](../../atl-mfc-shared/reference/ctime-class.md)<br/>
[Classe CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
