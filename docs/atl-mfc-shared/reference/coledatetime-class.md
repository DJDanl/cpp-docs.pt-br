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
ms.openlocfilehash: 610cbec6cb65d4e9616c5e0e0d64e729f39febcc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317746"
---
# <a name="coledatetime-class"></a>Classe COleDateTime

Encapsula o `DATE` tipo de dados usado na automação OLE.

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
|[COleDateTime::Formato](#format)|Gera uma representação de `COleDateTime` string formatado de um objeto.|
|[COleDateTime::GetAsDBTIMESTAMP](#getasdbtimestamp)|Chame este método para obter `COleDateTime` o `DBTIMESTAMP` tempo no objeto como uma estrutura de dados.|
|[COleDateTime::GetAsSystemTime](#getassystemtime)|Chame este método para obter `COleDateTime` o tempo no objeto como uma estrutura de dados [SYSTEMTIME.](/windows/win32/api/minwinbase/ns-minwinbase-systemtime)|
|[COleDateTime::GetAsUDATE](#getasudate)|Chame este método para obter `COleDateTime` o `UDATE` tempo na estrutura de dados.|
|[COleDateTime::GetCurrentTime](#getcurrenttime)|Cria `COleDateTime` um objeto que representa o tempo atual (função de membro estático).|
|[COleDateTime::GetDay](#getday)|Retorna no `COleDateTime` dia em que este objeto representa (1 - 31).|
|[COleDateTime::GetDayOfWeek](#getdayofweek)|Retorna no dia da `COleDateTime` semana que este objeto representa (domingo = 1).|
|[COleDateTime::GetDayOfYear](#getdayofyear)|Retorna no dia do `COleDateTime` ano que este objeto representa (Jan 1 = 1).|
|[COleDateTime::GetHour](#gethour)|Retorna a `COleDateTime` hora que este objeto representa (0 - 23).|
|[COleDateTime::GetMinute](#getminute)|Retorna no `COleDateTime` minuto em que este objeto representa (0 - 59).|
|[COleDateTime::GetMonth](#getmonth)|Retorna no `COleDateTime` mês que este objeto representa (1 - 12).|
|[COleDateTime::GetSecond](#getsecond)|Retorna no `COleDateTime` segundo em que este objeto representa (0 - 59).|
|[COleDateTime::GetStatus](#getstatus)|Obtém o status (validade) deste `COleDateTime` objeto.|
|[COleDateTime::GetYear](#getyear)|Retorna o `COleDateTime` ano que este objeto representa.|
|[COleDateTime::ParseDateTime](#parsedatetime)|Lê um valor de data/hora de uma `COleDateTime`string e define o valor de .|
|[COleDateTime::SetDate](#setdate)|Define o valor `COleDateTime` deste objeto para o valor especificado somente para datas.|
|[COleDateTime::SetDateTime](#setdatetime)|Define o valor `COleDateTime` deste objeto para o valor de data/hora especificado.|
|[COleDateTime::SetStatus](#setstatus)|Define o status (validade) `COleDateTime` deste objeto.|
|[COleDateTime::SetTime](#settime)|Define o valor `COleDateTime` deste objeto para o valor somente de tempo especificado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime::operator ==, COleDateTime::operator <, etc.](#coledatetime_relational_operators)|Compare `COleDateTime` dois valores.|
|[COleDateTime::operador +, COleDateTime::operador](#operator_add_-)|Adicionar e `COleDateTime` subtrair valores.|
|[COleDateTime::operador +=, COleDateTime::operador -=](#operator_add_eq_-_eq)|Adicione e subtraia `COleDateTime` `COleDateTime` um valor deste objeto.|
|[COleDateTime::operador =](#operator_eq)|Copia `COleDateTime` um valor.|
|[COleDateTime::operator DATE, COleDateTime::operator Date*](#operator_date)|Converte `COleDateTime` um valor `DATE` em `DATE*`um ou um .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime::m_dt](#m_dt)|Contém o `DATE` subjacente `COleDateTime` a este objeto.|
|[COleDateTime::m_status](#m_status)|Contém o status `COleDateTime` deste objeto.|

## <a name="remarks"></a>Comentários

`COleDateTime`não tem uma classe base.

É um dos tipos possíveis para o tipo de dados [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) da automação OLE. Um `COleDateTime` valor representa um valor absoluto de data e hora.

O `DATE` tipo é implementado como um valor de ponto flutuante. Os dias são medidos a partir de 30 de dezembro de 1899, à meia-noite. A tabela a seguir mostra algumas datas e seus valores associados:

|Data|Valor|
|----------|-----------|
|29 de dezembro de 1899, meia-noite|-1.0|
|29 de dezembro de 1899, 6 da manhã|-1.25|
|30 de dezembro de 1899, meia-noite|0.0|
|31 de dezembro de 1899, meia-noite|1.0|
|1 de janeiro de 1900, 6 da manhã.|2.25|

> [!CAUTION]
> Na tabela acima, embora os valores do dia se tornem negativos antes da meia-noite de 30 de dezembro de 1899, os valores do dia não. Por exemplo, 6:00 AM é sempre representado por um valor fracionado 0,25, independentemente de o inteiro representando o dia ser positivo (após 30 de dezembro de 1899) ou negativo (antes de 30 de dezembro de 1899). Isso significa que uma simples comparação de pontos `COleDateTime` flutuantes classificaria erroneamente uma representando 6:00 AM em 29/12/1899 como **mais tarde** do que um representando 7:00 AM no mesmo dia.

A `COleDateTime` aula tem datas de 1º de janeiro de 100 a 31 de dezembro de 9999. A `COleDateTime` classe usa o calendário gregoriano; não suporta datas julian. `COleDateTime`ignora o horário de verão. (Veja [data e hora: suporte à automação](../../atl-mfc-shared/date-and-time-automation-support.md).)

> [!NOTE]
> Você pode `%y` usar o formato para recuperar um ano de dois dígitos apenas para datas a partir de 1900. Se você `%y` usar o formato em uma data antes de 1900, o código gerará uma falha do ASSERT.

Esse tipo também é usado para representar valores somente dataou somente de tempo. Por convenção, a data 0 (30 de dezembro de 1899) é usada para valores somente por tempo e a hora 00:00 (meia-noite) é usada para valores somente de data.

Se você `COleDateTime` criar um objeto usando uma data menor que 100, `GetYear` `GetMonth`a `GetDay` `GetHour`data `GetMinute`é `GetSecond` aceita, mas as chamadas subseqüentes para , , , , , e falham e retornam -1. Anteriormente, você poderia usar datas de dois dígitos, mas as datas devem ser de 100 ou mais em MFC 4.2 e posteriores.

Para evitar problemas, especifique uma data de quatro dígitos. Por exemplo:

[!code-cpp[NVC_ATLMFC_Utilities#1](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_1.cpp)]

Operações aritméticas `COleDateTime` básicas para os valores usam a classe companheira [COleDateTimeSpan](../../atl-mfc-shared/reference/coledatetimespan-class.md). `COleDateTimeSpan`os valores definem um intervalo de tempo. A relação entre essas classes é semelhante à entre [CTime](../../atl-mfc-shared/reference/ctime-class.md) e [CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md).

Para obter mais `COleDateTime` `COleDateTimeSpan` informações sobre as aulas e as aulas, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLComTime.h

## <a name="coledatetime-relational-operators"></a><a name="coledatetime_relational_operators"></a>Operadores relacionais COleDateTime

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
> Um ATLASSERT ocorrerá se um dos dois operands for inválido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#13](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_2.cpp)]

### <a name="example"></a>Exemplo

Os **>=** operadores, **>** ** \< **e **<** afirmarão se `COleDateTime` o objeto estiver definido como nulo.

[!code-cpp[NVC_ATLMFC_Utilities#170](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_3.cpp)]

## <a name="coledatetimecoledatetime"></a><a name="coledatetime"></a>COleDateTime::COleDateTime

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

*dataSrc*<br/>
Um objeto `COleDateTime` existente a ser copiado para o novo `COleDateTime` objeto.

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Uma estrutura `VARIANT` de dados `COleVariant` existente (possivelmente um objeto) a ser convertida em um valor `COleDateTime` de data/hora (VT_DATE) e copiada para o novo objeto.

*dtSrc*<br/>
Um valor de`DATE`data/hora ( ) `COleDateTime` a ser copiado para o novo objeto.

*timeSrc*<br/>
Um `time_t` `__time64_t` ou valor a ser convertido em um valor de `COleDateTime` data/hora e copiado para o novo objeto.

*systimeSrc*<br/>
Uma `SYSTEMTIME` estrutura a ser convertida em um valor de `COleDateTime` data/hora e copiada para o novo objeto.

*filetimeSrc*<br/>
Uma `FILETIME` estrutura a ser convertida em um valor de `COleDateTime` data/hora e copiada para o novo objeto. A `FILETIME` usa o Universal Coordinated Time (UTC), portanto, se você passar um horário local na estrutura, seus resultados estarão incorretos. Consulte [File Times](/windows/win32/SysInfo/file-times) no Windows SDK para obter mais informações.

*nYear*, *nMonth*, *nDay*, *nHour,* *nMin,* *nSec*<br/>
Indique os valores de data `COleDateTime` e hora a serem copiados para o novo objeto.

*wDosDate*, *wDostime*<br/>
Os valores de data e hora do MS-DOS a serem `COleDateTime` convertidos em um valor de data/hora e copiados para o novo objeto.

*Timestamp*<br/>
Uma referência a uma estrutura [DBTimeStamp](/dotnet/api/system.data.oledb.oledbtype) contendo a hora local atual.

### <a name="remarks"></a>Comentários

Todos esses construtores `COleDateTime` criam novos objetos inicializados para o valor especificado. A tabela a seguir mostra intervalos válidos para cada componente de data e hora:

|Componente de data/hora|Intervalo válido|
|--------------------------|-----------------|
|year|100 - 9999|
|month|0 - 12|
|dia|0 - 31|
|hour|0 - 23|
|minute|0 - 59|
|second|0 - 59|

Observe que o limite superior real para o componente do dia varia de acordo com os componentes do mês e do ano. Para obter detalhes, consulte as `SetDate` funções ou `SetDateTime` membros.

A seguir está uma breve descrição de cada construtor:

- `COleDateTime(`**)** Constrói `COleDateTime` um objeto iniciado a 0 (meia-noite de 30 de dezembro de 1899).

- `COleDateTime(``dateSrc` **)** Constrói `COleDateTime` um objeto a `COleDateTime` partir de um objeto existente.

- `COleDateTime(`*varSrc* **)** Constrói `COleDateTime` um objeto. Tentativas de `VARIANT` converter uma estrutura ou objeto [COleVariant](../../mfc/reference/colevariant-class.md) em um valor de data/hora ( `VT_DATE`). Se essa conversão for bem sucedida, o valor `COleDateTime` convertido será copiado para o novo objeto. Caso não esteja, o `COleDateTime` valor do objeto é definido como 0 (meia-noite de 30 de dezembro de 1899) e seu status como inválido.

- `COleDateTime(``dtSrc` **)** Constrói `COleDateTime` um objeto `DATE` a partir de um valor.

- `COleDateTime(``timeSrc` **)** Constrói `COleDateTime` um objeto `time_t` a partir de um valor.

- `COleDateTime(`*systimeSrc* **)** Constrói `COleDateTime` um `SYSTEMTIME` objeto a partir de um valor.

- `COleDateTime(``filetimeSrc` **)** Constrói `COleDateTime` um objeto `FILETIME` a partir de um valor. . A `FILETIME` usa o Universal Coordinated Time (UTC), portanto, se você passar um horário local na estrutura, seus resultados estarão incorretos. Para obter mais informações, consulte [File Times](/windows/win32/SysInfo/file-times) no Windows SDK.

- `COleDateTime(``nYear`, `nMonth` `nDay`, `nHour` `nMin`, `nSec` **)** , ) `COleDateTime` ) Constrói um objeto a partir dos valores numéricos especificados.

- `COleDateTime(``wDosDate`, `wDosTime` **)** Constrói `COleDateTime` um objeto a partir dos valores de data e hora especificados do MS-DOS.

Para obter mais `time_t` informações sobre o tipo de dados, consulte a função [de tempo](../../c-runtime-library/reference/time-time32-time64.md) na *referência da biblioteca em tempo de execução*.

Para obter mais informações, consulte as estruturas [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) e [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) no SDK do Windows.

Para obter mais informações `COleDateTime` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

> [!NOTE]
> O construtor `DBTIMESTAMP` usando parâmetro só está disponível quando o OLEDB.h estiver incluído.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#2](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_4.cpp)]

## <a name="coledatetimeformat"></a><a name="format"></a>COleDateTime::Formato

Cria uma representação formatada do valor de data/hora.

```
CString Format(DWORD dwFlags = 0,  LCID lcid = LANG_USER_DEFAULT) const;
CString Format(LPCTSTR lpszFormat) const;
CString Format(UINT nFormatID) const;
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Indica uma das seguintes bandeiras locais:

- LOCALE_NOUSEROVERRIDE Use as configurações de localização padrão do sistema, em vez de configurações personalizadas do usuário.

- VAR_TIMEVALUEONLY Ignorar a parte da data durante a análise.

- VAR_DATEVALUEONLY Ignore a parte de tempo durante a análise.

*Lcid*<br/>
Indica id local para uso para a conversão. Para obter mais informações sobre identificadores de idiomas, consulte [Identificadores de idiomas](/windows/win32/Intl/language-identifiers).

*lpszFormat*<br/>
Uma seqüência de `printf` formatação semelhante à seqüência de formatação. Cada código de formatação, precedido por um sinal de um percent ( `%`) é substituído pelo componente correspondente. `COleDateTime` Outros caracteres da seqüência de formatação são copiados inalterados para a seqüência retornada. Para obter mais informações, consulte o tempo de execução [strftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md). O valor e o significado dos `Format` códigos de formatação são:

- `%H`Horas no dia atual

- `%M`Minutos na hora atual

- `%S`Segundos no minuto atual

- `%%`Sinal percentual

*Nformatid*<br/>
O ID de recurso para a seqüência de controle de formato.

### <a name="return-value"></a>Valor retornado

A `CString` que contém o valor de data/hora formatado.

### <a name="remarks"></a>Comentários

Se o status `COleDateTime` deste objeto for nulo, o valor de retorno será uma seqüência de string vazia. Se o status for inválido, a seqüência de retorno será especificada pelo recurso string ATL_IDS_DATETIME_INVALID.

Segue-se uma breve descrição dos três formulários para esta função:

`Format`*(dwFlags*, *lcid*)<br/>
Este formulário formata o valor usando as especificações de idioma (IDs locais) para data e hora. Usando os parâmetros padrão, este formulário imprimirá a data e a hora, a menos que a parte da hora seja 0 (meia-noite), nesse caso, imprimirá apenas a data, ou a parte da data é 0 (30 de dezembro de 1899), nesse caso imprimirá apenas a hora. Se o valor de data/hora for 0 (30 de dezembro de 1899, meia-noite), este formulário com os parâmetros padrão imprimirá meia-noite.

`Format`*(lpszFormat)*<br/>
Este formulário formata o valor usando a seqüência de formatos que contém códigos `printf`especiais de formatação precedidos por um sinal percentual (%), como em . A seqüência de formatação é passada como um parâmetro para a função. Para obter mais informações sobre os códigos de formatação, consulte [strftime, wcsftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) na referência da biblioteca run-time.

`Format`( *nFormatID*)<br/>
Este formulário formata o valor usando a seqüência de formatos que contém códigos `printf`especiais de formatação precedidos por um sinal percentual (%), como em . A seqüência de formatação é um recurso. O ID deste recurso de string é passado como parâmetro. Para obter mais informações sobre os códigos de formatação, consulte [strftime, wcsftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) na *referência da biblioteca run-time*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#3](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_5.cpp)]

## <a name="coledatetimegetasdbtimestamp"></a><a name="getasdbtimestamp"></a>COleDateTime::GetAsDBTIMESTAMP

Chame este método para obter `COleDateTime` o `DBTIMESTAMP` tempo no objeto como uma estrutura de dados.

```
bool GetAsDBTIMESTAMP(DBTIMESTAMP& timeStamp) const throw();
```

### <a name="parameters"></a>Parâmetros

*Timestamp*<br/>
Uma referência a uma estrutura [DBTimeStamp.](/dotnet/api/system.data.oledb.oledbtype)

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Armazena o tempo resultante na estrutura *de carimbo de tempo* referenciada. A `DBTIMESTAMP` estrutura de dados inicializada `fraction` por esta função terá seu membro definido como zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#4](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_6.cpp)]

## <a name="coledatetimegetassystemtime"></a><a name="getassystemtime"></a>COleDateTime::GetAsSystemTime

Chame este método para obter `COleDateTime` o `SYSTEMTIME` tempo no objeto como uma estrutura de dados.

```
bool GetAsSystemTime(SYSTEMTIME& sysTime) const throw();
```

### <a name="parameters"></a>Parâmetros

*sysTime*<br/>
Uma referência a uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) para receber o `COleDateTime` valor de data/hora convertido do objeto.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se for bem sucedido; FALSO se a conversão falhar, ou se o `COleDateTime` objeto for NULO ou inválido.

### <a name="remarks"></a>Comentários

`GetAsSystemTime`armazena o tempo resultante no objeto *sysTime* referenciado. A `SYSTEMTIME` estrutura de dados inicializada `wMilliseconds` por esta função terá seu membro definido como zero.

Para obter mais informações sobre `COleDateTime` as informações de status mantidas em um objeto, consulte [GetStatus](#getstatus).

## <a name="coledatetimegetasudate"></a><a name="getasudate"></a>COleDateTime::GetAsUDATE

Chame este método para obter `COleDateTime` o `UDATE` tempo no objeto como uma estrutura de dados.

```
bool GetAsUDATE(UDATE& uDate) const throw();
```

### <a name="parameters"></a>Parâmetros

*Udate*<br/>
Uma referência `UDATE` a uma estrutura para receber o `COleDateTime` valor de data/hora convertido do objeto.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se for bem sucedido; FALSO se a conversão falhar, ou se o `COleDateTime` objeto for NULO ou inválido.

### <a name="remarks"></a>Comentários

Uma `UDATE` estrutura representa uma data "descompactada".

## <a name="coledatetimegetcurrenttime"></a><a name="getcurrenttime"></a>COleDateTime::GetCurrentTime

Chame esta função de membro estático para retornar o valor de data/hora atual.

```
static COleDateTime WINAPI GetCurrentTime() throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#5](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_7.cpp)]

## <a name="coledatetimegetday"></a><a name="getday"></a>COleDateTime::GetDay

Obtém o dia do mês representado por esta data/valor de hora.

```
int GetDay() const throw();
```

### <a name="return-value"></a>Valor retornado

O dia do mês representado pelo `COleDateTime` valor `COleDateTime::error` deste objeto ou se o dia não pôde ser obtido.

### <a name="remarks"></a>Comentários

Os valores de retorno válidos variam entre 1 e 31.

Para obter informações sobre outras funções `COleDateTime` de membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getmonth](#getmonth)

- [Getyear](#getyear)

- [Gethour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [Getdayofyear](#getdayofyear)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#6](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_8.cpp)]

## <a name="coledatetimegetdayofweek"></a><a name="getdayofweek"></a>COleDateTime::GetDayOfWeek

Obtém o dia do mês representado por esta data/valor de hora.

```
int GetDayOfWeek() const throw();
```

### <a name="return-value"></a>Valor retornado

O dia da semana representado pelo `COleDateTime` valor `COleDateTime::error` deste objeto ou se o dia da semana não pôde ser obtido.

### <a name="remarks"></a>Comentários

Os valores de retorno válidos variam entre 1 e 7, onde 1=domingo, 2=segunda-feira, e assim por diante.

Para obter informações sobre outras funções `COleDateTime` de membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getmonth](#getmonth)

- [Getyear](#getyear)

- [Gethour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [Getdayofyear](#getdayofyear)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#7](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_9.cpp)]

## <a name="coledatetimegetdayofyear"></a><a name="getdayofyear"></a>COleDateTime::GetDayOfYear

Obtém o dia do ano representado por esta data/hora.

```
int GetDayOfYear() const throw();
```

### <a name="return-value"></a>Valor retornado

O dia do ano representado pelo `COleDateTime` valor `COleDateTime::error` deste objeto ou se o dia do ano não pôde ser obtido.

### <a name="remarks"></a>Comentários

Os valores de retorno válidos variam entre 1 e 366, onde 1 de janeiro = 1.

Para obter informações sobre outras funções `COleDateTime` de membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getmonth](#getmonth)

- [Getyear](#getyear)

- [Gethour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#8](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_10.cpp)]

## <a name="coledatetimegethour"></a><a name="gethour"></a>COleDateTime::GetHour

Obtém a hora representada por este valor de data/hora.

```
int GetHour() const throw();
```

### <a name="return-value"></a>Valor retornado

A hora representada pelo `COleDateTime` valor `COleDateTime::error` deste objeto ou se a hora não pôde ser obtida.

### <a name="remarks"></a>Comentários

Os valores de retorno válidos variam entre 0 e 23.

Para obter informações sobre outras funções `COleDateTime` de membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getmonth](#getmonth)

- [Getyear](#getyear)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [Getdayofyear](#getdayofyear)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#9](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_11.cpp)]

## <a name="coledatetimegetminute"></a><a name="getminute"></a>COleDateTime::GetMinute

Obtém o minuto representado por este valor de data/hora.

```
int GetMinute() const throw();
```

### <a name="return-value"></a>Valor retornado

O minuto representado pelo `COleDateTime` valor `COleDateTime::error` deste objeto ou se o minuto não pôde ser obtido.

### <a name="remarks"></a>Comentários

Os valores de retorno válidos variam entre 0 e 59.

Para obter informações sobre outras funções `COleDateTime` de membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getmonth](#getmonth)

- [Getyear](#getyear)

- [Gethour](#gethour)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [Getdayofyear](#getdayofyear)

### <a name="example"></a>Exemplo

Veja o exemplo de [GetHour](#gethour).

## <a name="coledatetimegetmonth"></a><a name="getmonth"></a>COleDateTime::GetMonth

Obtém o mês representado por essa data/hora.

```
int GetMonth() const throw();
```

### <a name="return-value"></a>Valor retornado

O mês representado pelo `COleDateTime` valor `COleDateTime::error` deste objeto ou se o mês não pôde ser obtido.

### <a name="remarks"></a>Comentários

Os valores de retorno válidos variam entre 1 e 12.

Para obter informações sobre outras funções `COleDateTime` de membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getyear](#getyear)

- [Gethour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [Getdayofyear](#getdayofyear)

### <a name="example"></a>Exemplo

Veja o exemplo de [GetDay](#getday).

## <a name="coledatetimegetsecond"></a><a name="getsecond"></a>COleDateTime::GetSecond

Obtém o segundo representado por este valor de data/hora.

```
int GetSecond() const throw();
```

### <a name="return-value"></a>Valor retornado

O segundo representado pelo `COleDateTime` valor `COleDateTime::error` deste objeto ou se o segundo não pôde ser obtido.

### <a name="remarks"></a>Comentários

Os valores de retorno válidos variam entre 0 e 59.

> [!NOTE]
> A `COleDateTime` classe não suporta segundos de salto.

Para obter mais informações `COleDateTime`sobre a implementação, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

Para obter informações sobre outras funções `COleDateTime` de membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getmonth](#getmonth)

- [Getyear](#getyear)

- [Gethour](#gethour)

- [GetMinute](#getminute)

- [GetDayOfWeek](#getdayofweek)

- [Getdayofyear](#getdayofyear)

### <a name="example"></a>Exemplo

Veja o exemplo de [GetHour](#gethour).

## <a name="coledatetimegetstatus"></a><a name="getstatus"></a>COleDateTime::GetStatus

Obtém o status (validade) `COleDateTime` de um determinado objeto.

```
DateTimeStatus GetStatus() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o status `COleDateTime` deste valor. Se você `GetStatus` chamar `COleDateTime` um objeto construído com o padrão, ele voltará válido. Se você `GetStatus` chamar `COleDateTime` um objeto inicializado com o `GetStatus` construtor definido como nulo, retornará nulo.

### <a name="remarks"></a>Comentários

O valor de retorno `DateTimeStatus` é definido pelo tipo enumerado, que é definido dentro da `COleDateTime` classe.

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

- `COleDateTime::error`Indica que ocorreu um erro ao tentar obter parte do valor de data/hora.

- `COleDateTime::valid`Indica que `COleDateTime` este objeto é válido.

- `COleDateTime::invalid`Indica que `COleDateTime` este objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleDateTime::null`Indica que `COleDateTime` este objeto é nulo, ou seja, que nenhum valor foi fornecido para este objeto. (Isso é "nulo" no sentido de banco de dados de "não ter valor", ao contrário do C++ NULL.)

O status `COleDateTime` de um objeto é inválido nos seguintes casos:

- Se seu valor for `VARIANT` `COleVariant` definido a partir de um ou valor que não pode ser convertido em um valor de data/hora.

- Se seu valor for `time_t` `SYSTEMTIME`definido `FILETIME` a partir de um , ou valor que não poderia ser convertido em um valor de data/hora válido.

- Se o valor `SetDateTime` for definido com valores de parâmetro inválidos.

- Se este objeto tiver experimentado um estouro ou subfluxo durante `+=` uma `-=`operação de atribuição aritmética, ou seja, ou .

- Se um valor inválido for atribuído a este objeto.

- Se o status deste objeto foi explicitamente `SetStatus`definido como inválido usando .

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte as seguintes funções de membro:

- [Coledatetime](#coledatetime)

- [Setdatetime](#setdatetime)

- [operador +, -](#operator_add_-)

- [operador +=, -=](#operator_add_eq_-_eq)

Para obter mais informações `COleDateTime` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#10](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_12.cpp)]

## <a name="coledatetimegetyear"></a><a name="getyear"></a>COleDateTime::GetYear

Obtém o ano representado por essa data/hora.

```
int GetYear() const throw();
```

### <a name="return-value"></a>Valor retornado

O ano representado pelo `COleDateTime` valor `COleDateTime::error` deste objeto ou se o ano não pôde ser obtido.

### <a name="remarks"></a>Comentários

Os valores de retorno válidos variam entre 100 e 9999, o que inclui o século.

Para obter informações sobre outras funções `COleDateTime` de membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getmonth](#getmonth)

- [Gethour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [Getdayofyear](#getdayofyear)

Para obter mais informações `COleDateTime` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [GetDay](#getday).

## <a name="coledatetimem_dt"></a><a name="m_dt"></a>COleDateTime::m_dt

A estrutura `DATE` subjacente `COleDateTime` para este objeto.

```
DATE m_dt;
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
> Alterar o valor `DATE` no objeto acessado pelo ponteiro retornado por esta `COleDateTime` função mudará o valor deste objeto. Não altera o status `COleDateTime` deste objeto.

Para obter mais informações `DATE` sobre a implementação do objeto, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimem_status"></a><a name="m_status"></a>COleDateTime::m_status

Contém o status `COleDateTime` deste objeto.

```
DateTimeStatus m_status;
```

### <a name="remarks"></a>Comentários

O tipo deste membro de dados `DateTimeStatus`é o tipo `COleDateTime` enumerado, que é definido dentro da classe. Para obter mais informações, consulte [COleDateTime::GetStatus](#getstatus).

> [!CAUTION]
> Este membro de dados é para situações avançadas de programação. Você deve usar as funções de membro inline [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para obter mais precauções sobre a definição explícita deste membro de dados.

## <a name="coledatetimeoperator-"></a><a name="operator_eq"></a>COleDateTime::operador =

Copia `COleDateTime` um valor.

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

Esses operadores de atribuição sobrecarregados copiam `COleDateTime` o valor de data/hora de origem para este objeto. Segue-se uma breve descrição de cada um desses operadores de atribuição sobrecarregados:

- **operador =(** `dateSrc` **)** O valor e o status do operand são copiados para este `COleDateTime` objeto.

- operador *=(varSrc* **operator =(** **)** Se a conversão do valor [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) (ou objeto [COleVariant)](../../mfc/reference/colevariant-class.md) para uma data/hora (VT_DATE) `COleDateTime` for bem sucedida, o valor convertido será copiado para este objeto e seu status será definido como válido. Se a conversão não for bem sucedida, o valor deste objeto será definido como zero (30 de dezembro de 1899, meia-noite) e seu status para inválido.

- **operador =(** `dtSrc` **)** O `DATE` valor é copiado para este `COleDateTime` objeto e seu status é definido como válido.

- **operador =(** `timeSrc` **)** O `time_t` `__time64_t` valor ou é convertido e `COleDateTime` copiado para este objeto. Se a conversão for bem sucedida, o status deste objeto será definido como válido; se não tiver sucesso, é definido como inválido.

- operador *=(systimeSrc* **)** **operator =(** O valor [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) é convertido e `COleDateTime` copiado para este objeto. Se a conversão for bem sucedida, o status deste objeto será definido como válido; se não tiver sucesso, é definido como inválido.

- **operador =(** `uDate` **)** O `UDATE` valor é convertido e `COleDateTime` copiado para este objeto. Se a conversão for bem sucedida, o status deste objeto será definido como válido; se não tiver sucesso, é definido como inválido. Uma `UDATE` estrutura representa uma data "descompactada". Para obter mais informações, consulte a função [VarDateFromUdate](/windows/win32/api/oleauto/nf-oleauto-vardatefromudate).

- **operador =(** `filetimeSrc` **)** O valor [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) é convertido e `COleDateTime` copiado para este objeto. Se a conversão for bem sucedida, o status deste objeto será definido como válido; caso contrário, ele é definido como inválido. `FILETIME`usa o Universal Coordinated Time (UTC), portanto, se você passar um tempo UTC na estrutura, seus resultados serão convertidos do horário UTC para o horário local, e serão armazenados como tempo de variante. Esse comportamento é o mesmo do Visual C++ 6.0 e visual C++.NET 2003 SP2. Para obter mais informações, consulte [File Times](/windows/win32/SysInfo/file-times) no Windows SDK.

Para obter mais informações, consulte a entrada [VARIANT](/windows/win32/api/oaidl/ns-oaidl-variant) no SDK do Windows.

Para obter mais `time_t` informações sobre o tipo de dados, consulte a função [de tempo](../../c-runtime-library/reference/time-time32-time64.md) na *referência da biblioteca em tempo de execução*.

Para obter mais informações, consulte as estruturas [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) e [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) no SDK do Windows.

Para obter mais informações `COleDateTime` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimeoperator---"></a><a name="operator_add_-"></a>COleDateTime::operador +, -

Adicionar e `ColeDateTime` subtrair valores.

```
COleDateTime operator+(COleDateTimeSpan dateSpan) const throw();
COleDateTime operator-(COleDateTimeSpan dateSpan) const throw();
COleDateTimeSpan operator-(const COleDateTime& date) const throw();
```

### <a name="remarks"></a>Comentários

`COleDateTime`objetos representam tempos absolutos. Os objetos [COleDateTimeSpan](../../atl-mfc-shared/reference/coledatetimespan-class.md) representam tempos relativos. Os dois primeiros operadores permitem que `COleDateTimeSpan` você adicione `COleDateTime` e subtraia um valor de um valor. O terceiro operador permite que `COleDateTime` você subtraia `COleDateTimeSpan` um valor de outro para produzir um valor.

Se qualquer um dos operands for nulo, o status do valor resultante `COleDateTime` é nulo.

Se o `COleDateTime` valor resultante estiver fora dos limites dos valores aceitáveis, o status desse `COleDateTime` valor será inválido.

Se um dos operands for inválido e o outro não `COleDateTime` for nulo, o status do valor resultante será inválido.

Os **+** **-** operadores e operadores afirmarão se o `COleDateTime` objeto estiver definido como nulo. Consulte [COleDateTime Relational Operators](#coledatetime_relational_operators) para obter um exemplo.

Para obter mais informações sobre os valores de status válidos, inválidos e nulos, consulte a variável [membro m_status.](#m_status)

Para obter mais informações `COleDateTime` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#12](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_13.cpp)]

## <a name="coledatetimeoperator---"></a><a name="operator_add_eq_-_eq"></a>COleDateTime::operador +=, -=

Adicione e subtraia `ColeDateTime` `COleDateTime` um valor deste objeto.

```
COleDateTime& operator+=(COleDateTimeSpan dateSpan) throw();
COleDateTime& operator-=(COleDateTimeSpan dateSpan) throw();
```

### <a name="remarks"></a>Comentários

Esses operadores permitem que você `COleDateTimeSpan` adicione e subtraia um valor para e a partir disso `COleDateTime`. Se qualquer um dos operands for nulo, o status do valor resultante `COleDateTime` é nulo.

Se o `COleDateTime` valor resultante estiver fora dos limites dos valores aceitáveis, o status deste `COleDateTime` valor será definido como inválido.

Se um dos operands for inválido e outro não for `COleDateTime` nulo, o status do valor resultante será inválido.

Para obter mais informações sobre os valores de status válidos, inválidos e nulos, consulte a variável [membro m_status.](#m_status)

Os **+=** **-=** operadores e operadores afirmarão se o `COleDateTime` objeto estiver definido como nulo. Consulte [COleDateTime Relational Operators](#coledatetime_relational_operators) para obter um exemplo.

Para obter mais informações `COleDateTime` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimeoperator-date"></a><a name="operator_date"></a>COleDateTime::operator DATE

Converte `ColeDateTime` um valor `DATE`em um .

```
operator DATE() const throw();
```

### <a name="remarks"></a>Comentários

Este operador `DATE` retorna um objeto cujo `COleDateTime` valor é copiado deste objeto. Para obter mais informações `DATE` sobre a implementação do objeto, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

O `DATE` operador afirmará `COleDateTime` se o objeto estiver definido como nulo. Consulte [COleDateTime Relational Operators](#coledatetime_relational_operators) para obter um exemplo.

## <a name="coledatetimeparsedatetime"></a><a name="parsedatetime"></a>COleDateTime::ParseDateTime

Analisa uma seqüência para ler um valor de data/hora.

```
bool ParseDateTime(
    LPCTSTR lpszDate,
    DWORD dwFlags = 0,
    LCID lcid = LANG_USER_DEFAULT) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszDate*<br/>
Um ponteiro para a seqüência de terminadas nula que deve ser analisado. Para obter detalhes, consulte Observações.

*dwFlags*<br/>
Indica bandeiras para configurações locais e análises. Uma ou mais das seguintes bandeiras:

- LOCALE_NOUSEROVERRIDE Use as configurações locais padrão do sistema, em vez de configurações personalizadas do usuário.

- VAR_TIMEVALUEONLY Ignorar a parte da data durante a análise.

- VAR_DATEVALUEONLY Ignore a parte de tempo durante a análise.

*Lcid*<br/>
Indica id local para uso para a conversão.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a seqüência foi convertida com sucesso em um valor de data/hora, caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Se a seqüência foi convertida com sucesso em `COleDateTime` um valor de data/hora, o valor deste objeto será definido como esse valor e seu status para válido.

> [!NOTE]
> Os valores do ano devem ficar entre 100 e 9999, inclusive.

O parâmetro *lpszDate* pode ter uma variedade de formatos. Por exemplo, as seguintes strings contêm formatos de data/hora aceitáveis:

`"25 January 1996"`

`"8:30:00"`

`"20:30:00"`

`"January 25, 1996 8:30:00"`

`"8:30:00 Jan. 25, 1996"`

`"1/25/1996 8:30:00"  // always specify the full year, even in a 'short date' format`

O ID local também afetará se o formato de string é aceitável para conversão para um valor de data/hora.

No caso de VAR_DATEVALUEONLY, o valor da hora é definido como 0, ou meia-noite. No caso de VAR_TIMEVALUEONLY, o valor da data é definido até a data 0, ou seja, 30 de dezembro de 1899.

Se a seqüência não puder ser convertida em um valor de data/hora ou `COleDateTime` se houve um estouro numérico, o status deste objeto será inválido.

Para obter mais informações sobre `COleDateTime` os limites e a implementação dos valores, consulte o artigo [Data e hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimesetdate"></a><a name="setdate"></a>COleDateTime::SetDate

Define a data `COleDateTime` deste objeto.

```
int SetDate(
    int nYear,
    int nMonth,
    int nDay) throw();
```

### <a name="parameters"></a>Parâmetros

*nYear*, *nMonth,* *nDay*<br/>
Indique os componentes de `COleDateTime` data a serem copiados para este objeto.

### <a name="return-value"></a>Valor retornado

Zero se o `COleDateTime` valor deste objeto foi definido com sucesso; caso contrário, 1. Este valor de retorno `DateTimeStatus` é baseado no tipo enumerado. Para obter mais informações, consulte a função [setStatus](#setstatus) member.

### <a name="remarks"></a>Comentários

A data é definida como valores especificados. A hora está marcada para o tempo 0, meia-noite.

Veja a tabela a seguir para limites para os valores dos parâmetros:

|Parâmetro|Limites|
|---------------|------------|
|*nAno*|100 - 9999|
|*nMês*|1 - 12|
|*nDay*|0 - 31|

Se o dia do mês transbordar, ele é convertido para o dia correto do próximo mês e o mês e/ou ano é incrementado em conformidade. Um valor diário de zero indica o último dia do mês anterior. O comportamento é `SystemTimeToVariantTime`o mesmo que .

Se o valor da data especificado pelos parâmetros não for `COleDateTime::invalid`válido, o status deste objeto será definido como . Você deve usar [getstatus](#getstatus) para verificar `DATE` a validade do valor e não deve assumir que o valor de [m_dt](#m_dt) permanecerá não modificado.

Aqui estão alguns exemplos de valores de data:

|*nAno*|*nMês*|*nDay*|Valor|
|-------------|--------------|------------|-----------|
|2000|2|29|29 de fevereiro de 2000|
|1776|7|4|4 de julho de 1776|
|1925|4|35|35 de abril de 1925 (data inválida)|
|10000|1|1|1 de Janeiro de 10000 (data inválida)|

Para definir a data e a hora, consulte [COleDateTime::SetDateTime](#setdatetime).

Para obter informações sobre funções de `COleDateTime` membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getmonth](#getmonth)

- [Getyear](#getyear)

- [Gethour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [Getdayofyear](#getdayofyear)

Para obter mais informações `COleDateTime` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#11](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_14.cpp)]

## <a name="coledatetimesetdatetime"></a><a name="setdatetime"></a>COleDateTime::SetDateTime

Define a data e `COleDateTime` a hora deste objeto.

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

*nYear*, *nMonth*, *nDay*, *nHour,* *nMin,* *nSec*<br/>
Indique os componentes de data `COleDateTime` e hora a serem copiados para este objeto.

### <a name="return-value"></a>Valor retornado

Zero se o `COleDateTime` valor deste objeto foi definido com sucesso; caso contrário, 1. Este valor de retorno `DateTimeStatus` é baseado no tipo enumerado. Para obter mais informações, consulte a função [setStatus](#setstatus) member.

### <a name="remarks"></a>Comentários

Veja a tabela a seguir para limites para os valores dos parâmetros:

|Parâmetro|Limites|
|---------------|------------|
|*nAno*|100 - 9999|
|*nMês*|1 - 12|
|*nDay*|0 - 31|
|*nHour*|0 - 23|
|*Nmin*|0 - 59|
|*Nsec*|0 - 59|

Se o dia do mês transbordar, ele é convertido para o dia correto do próximo mês e o mês e/ou ano é incrementado em conformidade. Um valor diário de zero indica o último dia do mês anterior. O comportamento é o mesmo do [SystemTimeToVariantTime](/windows/win32/api/oleauto/nf-oleauto-systemtimetovarianttime).

Se o valor de data ou hora especificado pelos parâmetros não for válido, o status deste objeto será definido como inválido e o valor deste objeto não será alterado.

Aqui estão alguns exemplos de valores de tempo:

|*nHour*|*Nmin*|*Nsec*|Valor|
|-------------|------------|------------|-----------|
|1|3|3|01:03:03|
|23|45|0|23:45:00|
|25|30|0|Inválido|
|9|60|0|Inválido|

Aqui estão alguns exemplos de valores de data:

|*nAno*|*nMês*|*nDay*|Valor|
|-------------|--------------|------------|-----------|
|1995|4|15|15 de abril de 1995|
|1789|7|14|17 de julho de 1789|
|1925|2|30|Inválido|
|10000|1|1|Inválido|

Para definir apenas a data, consulte [COleDateTime::SetDate](#setdate). Para definir apenas a hora, consulte [COleDateTime::SetTime](#settime).

Para obter informações sobre funções de `COleDateTime` membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getmonth](#getmonth)

- [Getyear](#getyear)

- [Gethour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [Getdayofyear](#getdayofyear)

Para obter mais informações `COleDateTime` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [GetStatus](#getstatus).

## <a name="coledatetimesetstatus"></a><a name="setstatus"></a>COleDateTime::SetStatus

Define o status `COleDateTime` deste objeto.

```
void SetStatus(DateTimeStatus status) throw();
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O novo valor `COleDateTime` de status para este objeto.

### <a name="remarks"></a>Comentários

O valor do parâmetro *de status* é definido pelo `DateTimeStatus` tipo `COleDateTime` enumerado, que é definido dentro da classe. Consulte [COleDateTime::GetStatus](#getstatus) para obter detalhes.

> [!CAUTION]
> Esta função é para situações avançadas de programação. Esta função não altera os dados neste objeto. Na maioria das vezes, será usado para definir o status **como nulo** ou **inválido**. O operador de atribuição[(operador =](#operator_eq)) e [o SetDateTime](#setdatetime) definem o status do objeto com base no valor de origem(s).

### <a name="example"></a>Exemplo

Veja o exemplo de [GetStatus](#getstatus).

## <a name="coledatetimesettime"></a><a name="settime"></a>COleDateTime::SetTime

Define a hora `COleDateTime` deste objeto.

```
int SetTime(
    int nHour,
    int nMin,
    int nSec) throw();
```

### <a name="parameters"></a>Parâmetros

*nHour,* *nMin,* *nSec*<br/>
Indique os componentes de `COleDateTime` tempo a serem copiados para este objeto.

### <a name="return-value"></a>Valor retornado

Zero se o `COleDateTime` valor deste objeto foi definido com sucesso; caso contrário, 1. Este valor de retorno `DateTimeStatus` é baseado no tipo enumerado. Para obter mais informações, consulte a função [setStatus](#setstatus) member.

### <a name="remarks"></a>Comentários

A hora é definida como os valores especificados. A data está marcada para 0, ou seja, 30 de dezembro de 1899.

Veja a tabela a seguir para limites para os valores dos parâmetros:

|Parâmetro|Limites|
|---------------|------------|
|*nHour*|0 - 23|
|*Nmin*|0 - 59|
|*Nsec*|0 - 59|

Se o valor de tempo especificado pelos parâmetros não for válido, o status deste objeto será definido como inválido e o valor deste objeto não será alterado.

Aqui estão alguns exemplos de valores de tempo:

|*nHour*|*Nmin*|*Nsec*|Valor|
|-------------|------------|------------|-----------|
|1|3|3|01:03:03|
|23|45|0|23:45:00|
|25|30|0|Inválido|
|9|60|0|Inválido|

Para definir a data e a hora, consulte [COleDateTime::SetDateTime](#setdatetime).

Para obter informações sobre funções de `COleDateTime` membro que consultam o valor deste objeto, consulte as seguintes funções de membro:

- [Getday](#getday)

- [Getmonth](#getmonth)

- [Getyear](#getyear)

- [Gethour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [Getdayofyear](#getdayofyear)

Para obter mais informações `COleDateTime` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [SetDate](#setdate).

## <a name="see-also"></a>Confira também

[Classe COleVariant](../../mfc/reference/colevariant-class.md)<br/>
[Classe CTime](../../atl-mfc-shared/reference/ctime-class.md)<br/>
[Classe CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
