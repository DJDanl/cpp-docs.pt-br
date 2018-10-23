---
title: Classe COleDateTime | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- shared classes, COleDateTime
- time-only values
- Date data type, MFC encapsulation of
- COleDateTime class
- dates, handling in MFC
- time, handling in MFC
ms.assetid: e718f294-16ec-4649-88b6-a4dbae5178fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 92761508a5e93c7ef0d0a4099dde587987a50dad
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49809155"
---
# <a name="coledatetime-class"></a>Classe COleDateTime

Encapsula o `DATE` tipo de dados que é usado na automação OLE.

## <a name="syntax"></a>Sintaxe

```
class COleDateTime
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime::COleDateTime](#coledatetime)|Constrói um objeto `COleDateTime`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime::Format](#format)|Gera uma representação de cadeia de caracteres formatada de um `COleDateTime` objeto.|
|[COleDateTime::GetAsDBTIMESTAMP](#getasdbtimestamp)|Chame esse método para obter a hora no `COleDateTime` objeto como um `DBTIMESTAMP` estrutura de dados.|
|[COleDateTime::GetAsSystemTime](#getassystemtime)|Chame esse método para obter a hora no `COleDateTime` objeto como uma [SYSTEMTIME](https://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura de dados.|
|[COleDateTime::GetAsUDATE](#getasudate)|Chame esse método para obter a hora no `COleDateTime` como um `UDATE` estrutura de dados.|
|[COleDateTime::GetCurrentTime](#getcurrenttime)|Cria um `COleDateTime` objeto que representa a hora atual (função de membro estático).|
|[COleDateTime::GetDay](#getday)|Retorna o dia isso `COleDateTime` (1 a 31) do objeto representa.|
|[COleDateTime::GetDayOfWeek](#getdayofweek)|Retorna o dia da semana isso `COleDateTime` representa (domingo = 1) do objeto.|
|[COleDateTime::GetDayOfYear](#getdayofyear)|Retorna o dia do ano isso `COleDateTime` objeto (1 de janeiro = 1).|
|[COleDateTime::GetHour](#gethour)|Retorna a hora isso `COleDateTime` objeto (0 – 23).|
|[COleDateTime::GetMinute](#getminute)|Retorna o minuto isso `COleDateTime` objeto (0 – 59).|
|[COleDateTime::GetMonth](#getmonth)|Retorna o mês isso `COleDateTime` objeto representa (1 a 12).|
|[COleDateTime::GetSecond](#getsecond)|Retorna o segundo isso `COleDateTime` objeto (0 – 59).|
|[COleDateTime::GetStatus](#getstatus)|Obtém o status (validade) deste `COleDateTime` objeto.|
|[COleDateTime::GetYear](#getyear)|Retorna o ano isso `COleDateTime` objeto representa.|
|[COleDateTime::ParseDateTime](#parsedatetime)|Lê um valor de data/hora de uma cadeia de caracteres e define o valor de `COleDateTime`.|
|[COleDateTime::SetDate](#setdate)|Define o valor deste `COleDateTime` objeto para o valor especificado somente Data.|
|[COleDateTime::SetDateTime](#setdatetime)|Define o valor deste `COleDateTime` objeto para o valor de data/hora especificada.|
|[COleDateTime::SetStatus](#setstatus)|Define o status (validade) deste `COleDateTime` objeto.|
|[COleDateTime::SetTime](#settime)|Define o valor deste `COleDateTime` objeto para o valor especificado somente em tempo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime::operator COleDateTime::operator = = <, etc.](#coledatetime_relational_operators)|Comparar dois `COleDateTime` valores.|
|[COleDateTime::operator + COleDateTime::operator-](#operator_add_-)|Adicionar e subtrair `COleDateTime` valores.|
|[+ = De COleDateTime::operator, COleDateTime::operator =](#operator_add_eq_-_eq)|Adicionar e subtrair um `COleDateTime` valor deste `COleDateTime` objeto.|
|[COleDateTime::operator =](#operator_eq)|Copia um `COleDateTime` valor.|
|[COleDateTime::operator data, COleDateTime::operator data *](#operator_date)|Converte um `COleDateTime` de valor em uma `DATE` ou um `DATE*`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTime::m_dt](#m_dt)|Contém subjacente `DATE` para este `COleDateTime` objeto.|
|[COleDateTime::m_status](#m_status)|Contém o status deste `COleDateTime` objeto.|

## <a name="remarks"></a>Comentários

`COleDateTime` não tem uma classe base.

É um dos tipos possíveis para o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) tipo de dados de automação OLE. Um `COleDateTime` valor representa uma data absoluta e o valor de hora.

O `DATE` tipo é implementado como um valor de ponto flutuante. Dias são medidos a partir de 30 de dezembro de 1899, à meia-noite. A tabela a seguir mostra algumas datas e seus valores associados:

|Date|Valor|
|----------|-----------|
|Meia-noite do dia 29 de dezembro de 1899|-1.0|
|29 de dezembro de 1899, da manhã de 6|-1.25|
|Meia-noite do dia 30 de dezembro de 1899|0.0|
|Meia-noite de 31 de dezembro de 1899|1.0|
|1 de janeiro de 1900, 6h|2.25|

> [!CAUTION]
> Na tabela acima, observe que embora os valores de dia se tornam negativos antes da meia-noite no dia 30 de dezembro de 1899, valores de hora do dia não. Por exemplo, das 6H00 sempre é representada por um valor fracionário 0,25, independentemente se o inteiro que representa o dia é positivo (após 30 de dezembro de 1899) ou negativo (antes de 30 de dezembro de 1899). Isso significa que uma comparação de ponto flutuante simples seria classificar incorretamente um `COleDateTime` representando 6H00 12/29/1899 como **posteriormente** daquela representando 7H00 no mesmo dia.

O `COleDateTime` classe manipula datas desde 1 de janeiro de 100 até 31 de dezembro de 9999. O `COleDateTime` classe usa o calendário gregoriano; ele não dá suporte a datas do calendário juliano. `COleDateTime` ignora o horário de verão. (Consulte [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).)

> [!NOTE]
> Você pode usar o `%y` formato para recuperar um ano de dois dígitos somente para datas começando com 1900. Se você usar o `%y` formato em uma data antes de 1900, o código gera uma falha ASSERT.

Esse tipo também é usado para representar valores de data-hora somente ou. Por convenção, a data 0 (30 de dezembro de 1899) é usada para valores de hora e hora 00:00 (meia-noite) é usado para valores de data.

Se você criar uma `COleDateTime` objeto por meio de uma data menor que 100 e a data é aceitas, mas subsequentes chamadas para `GetYear`, `GetMonth`, `GetDay`, `GetHour`, `GetMinute`, e `GetSecond` falhará e retornará -1. Anteriormente, você pode usar as datas de dois dígitos, mas as datas devem estar 100 ou maior no MFC 4.2 e posterior.

Para evitar problemas, especifique uma data de quatro dígitos. Por exemplo:

[!code-cpp[NVC_ATLMFC_Utilities#1](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_1.cpp)]

Operações aritméticas básicas para o `COleDateTime` valores usam a classe complementar [COleDateTimeSpan](../../atl-mfc-shared/reference/coledatetimespan-class.md). `COleDateTimeSpan` valores definem um intervalo de tempo. A relação entre essas classes é semelhante entre [CTime](../../atl-mfc-shared/reference/ctime-class.md) e [CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md).

Para obter mais informações sobre o `COleDateTime` e `COleDateTimeSpan` classes, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atlcomtime

##  <a name="coledatetime_relational_operators"></a>  Operadores relacionais de COleDateTime

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

*Data*<br/>
O objeto `COleDateTime` a ser comparado.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Uma {1&gt;ATLASSERT&lt;1 ocorrerá se qualquer um dos dois operandos é inválido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#13](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_2.cpp)]

### <a name="example"></a>Exemplo

Os operadores **>=**, **\< =**, **>**, e **<**, declarará se o `COleDateTime` objeto é definido como null.

[!code-cpp[NVC_ATLMFC_Utilities#170](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_3.cpp)]

##  <a name="coledatetime"></a>  COleDateTime::COleDateTime

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
COleDateTime(const DBTIMESTAMP& dbts) throw();
```

### <a name="parameters"></a>Parâmetros

*dateSrc*<br/>
Um existente `COleDateTime` o objeto a ser copiado para o novo `COleDateTime` objeto.

*varSrc*<br/>
Um existente `VARIANT` estrutura de dados (possivelmente um `COleVariant` objeto) a ser convertido em um valor de data/hora (VT_DATE) e copiado no novo `COleDateTime` objeto.

*dtSrc*<br/>
Um valor de data/hora (`DATE`) o valor a ser copiado para o novo `COleDateTime` objeto.

*timeSrc*<br/>
Um `time_t` ou `__time64_t` valor a ser convertido em um valor de data/hora e copiado no novo `COleDateTime` objeto.

*systimeSrc*<br/>
Um `SYSTEMTIME` estrutura a ser convertido em um valor de data/hora e copiado no novo `COleDateTime` objeto.

*filetimeSrc*<br/>
Um `FILETIME` estrutura a ser convertido em um valor de data/hora e copiado no novo `COleDateTime` objeto. Observe que `FILETIME` usa o Horário Coordenado Universal (UTC), portanto, se você passar uma hora local na estrutura, os resultados estarão incorretos. Ver [tempos de arquivo](/windows/desktop/SysInfo/file-times) no SDK do Windows para obter mais informações.

*nYear*, *nMonth*, *nDay*, *Nhora*, *Nmín*, *nSec*  
Indique os valores de data e hora a ser copiado para o novo `COleDateTime` objeto.

*wDosDate*, *wDosTime*  
Valores de data e hora do MS-DOS para ser convertido em um valor de data/hora e copiado no novo `COleDateTime` objeto.

*DBTS*<br/>
Uma referência a um [DBTimeStamp](https://msdn.microsoft.com/library/system.data.oledb.oledbtype) estrutura que contém a hora local atual.

### <a name="remarks"></a>Comentários

Todos esses construtores criam novos `COleDateTime` objetos inicializados ao valor especificado. A tabela a seguir mostra os intervalos válidos para cada componente de data e hora:

|Componente de data/hora|Intervalo válido|
|--------------------------|-----------------|
|ano|100 - 9999|
|mês|0 - 12|
|dia|0 - 31|
|hora|0 - 23|
|minuto|0 - 59|
|segundo|0 - 59|

Observe que o limite superior real para o componente de dia varia com base nos componentes de mês e ano. Para obter detalhes, consulte o `SetDate` ou `SetDateTime` funções de membro.

A seguir está uma breve descrição de cada construtor:

- `COleDateTime(` **)** Constrói um `COleDateTime` objeto inicializado como 0 (meia-noite, 30 de dezembro de 1899).

- `COleDateTime(` `dateSrc` **)** Constrói uma `COleDateTime` objeto de uma já existente `COleDateTime` objeto.

- `COleDateTime(` *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3* **)** constrói um `COleDateTime` objeto. Tenta converter um `VARIANT` estrutura ou [COleVariant](../../mfc/reference/colevariant-class.md) objeto em uma data/hora ( `VT_DATE`) valor. Se essa conversão for bem-sucedida, o valor convertido é copiado no novo `COleDateTime` objeto. Se não estiver, o valor da `COleDateTime` objeto é definido como 0 (meia-noite, 30 de dezembro de 1899) e seu status como inválido.

- `COleDateTime(` `dtSrc` **)** Constrói uma `COleDateTime` do objeto de um `DATE` valor.

- `COleDateTime(` `timeSrc` **)** Constrói uma `COleDateTime` do objeto de um `time_t` valor.

- `COleDateTime(` *systimeSrc* **)** constrói uma `COleDateTime` do objeto de um `SYSTEMTIME` valor.

- `COleDateTime(` `filetimeSrc` **)** Constrói uma `COleDateTime` do objeto de um `FILETIME` valor. . Observe que `FILETIME` usa o Horário Coordenado Universal (UTC), portanto, se você passar uma hora local na estrutura, os resultados estarão incorretos. Ver [tempos de arquivo](/windows/desktop/SysInfo/file-times) no SDK do Windows para obter mais informações.

- `COleDateTime(` `nYear``nMonth`, `nDay`, `nHour`, `nMin`, `nSec` **)** Constrói um `COleDateTime` objeto a partir de valores numéricos especificados.

- `COleDateTime(` `wDosDate``wDosTime` **)** Constrói um `COleDateTime` objeto entre os valores de data e hora de MS-DOS especificados.

Para obter mais informações sobre o `time_t` tipo de dados, consulte a [tempo](../../c-runtime-library/reference/time-time32-time64.md) funcionar no *referência de biblioteca de tempo de execução*.

Para obter mais informações, consulte o [SYSTEMTIME](https://msdn.microsoft.com/library/windows/desktop/ms724950) e [FILETIME](https://msdn.microsoft.com/library/windows/desktop/ms724284) estruturas no SDK do Windows.

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

> [!NOTE]
> O construtor usando `DBTIMESTAMP` parâmetro está disponível apenas quando OLEDB é incluído.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#2](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_4.cpp)]

##  <a name="format"></a>  COleDateTime::Format

Cria uma representação formatada do valor de data/hora.

```
CString Format(DWORD dwFlags = 0,  LCID lcid = LANG_USER_DEFAULT) const;
CString Format(LPCTSTR lpszFormat) const;
CString Format(UINT nFormatID) const;
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Indica que um dos seguintes sinalizadores de localidade:

- LOCALE_NOUSEROVERRIDE usar as configurações de localidade do sistema padrão, em vez de configurações do usuário personalizadas.

- VAR_TIMEVALUEONLY ignorar a parte de data durante a análise.

- VAR_DATEVALUEONLY ignorar a parte de hora durante a análise.

*lcid*<br/>
Indica a ID de localidade a ser usado para a conversão. Para obter mais informações sobre identificadores de idioma, consulte [identificadores de idioma](/windows/desktop/Intl/language-identifiers).

*lpszFormat*<br/>
Uma formatação de cadeia de caracteres semelhante ao `printf` cadeia de caracteres de formatação. Cada uma formatação de código, precedido por uma porcentagem ( `%`) entre, é substituído pelo correspondente `COleDateTime` componente. Outros caracteres na cadeia de caracteres de formatação são copiados sem alterações para a cadeia de caracteres retornada. Consulte a função de tempo de execução [strftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter mais informações. O valor e o significado dos códigos de formatação para `Format` são:

- `%H` Horas do dia atual

- `%M` Minutos da hora atual

- `%S` Segundos do minuto atual

- `%%` Sinal de porcentagem

*nFormatID*<br/>
A ID de recurso para a cadeia de caracteres de controle de formato.

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém o valor de data/hora formatada.

### <a name="remarks"></a>Comentários

Se o status deste `COleDateTime` objeto for nulo, o valor retornado é uma cadeia de caracteres vazia. Se o status for inválido, a cadeia de caracteres de retornada é especificada pelo recurso de cadeia de caracteres ATL_IDS_DATETIME_INVALID.

Uma breve descrição das três formas para essa função é:

`Format`( *dwFlags*, *lcid*)  
Este formulário formata o valor usando as especificações da linguagem (IDs de localidade) para data e hora. Usando os parâmetros padrão, esse formulário imprimirá a data e hora, a menos que a parte de hora é 0 (meia-noite), caso em que ele imprimirá apenas a data ou a parte de data é 0 (30 de dezembro de 1899) nesse caso, ele imprimirá apenas a hora. Se o valor de data/hora é 0 (30 de dezembro de 1899, meia-noite), este formulário com os parâmetros padrão imprimirá a meia-noite.

`Format`( *lpszFormat*)  
Este formulário formata o valor usando a cadeia de caracteres de formato que contém códigos de formatação especial que são precedidos por um sinal de porcentagem (%), como em `printf`. A cadeia de caracteres de formatação é passada como um parâmetro para a função. Para obter mais informações sobre os códigos de formatação, consulte [strftime, wcsftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) na referência da biblioteca de tempo de execução.

`Format`( *nFormatID*)  
Este formulário formata o valor usando a cadeia de caracteres de formato que contém códigos de formatação especial que são precedidos por um sinal de porcentagem (%), como em `printf`. A cadeia de caracteres de formatação é um recurso. A ID desse recurso de cadeia de caracteres é passada como o parâmetro. Para obter mais informações sobre os códigos de formatação, consulte [strftime, wcsftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) na *referência de biblioteca de tempo de execução*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#3](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_5.cpp)]

##  <a name="getasdbtimestamp"></a>  COleDateTime::GetAsDBTIMESTAMP

Chame esse método para obter a hora no `COleDateTime` objeto como um `DBTIMESTAMP` estrutura de dados.

```
bool GetAsDBTIMESTAMP(DBTIMESTAMP& dbts) const throw();
```

### <a name="parameters"></a>Parâmetros

*DBTS*<br/>
Uma referência a um [DBTimeStamp](https://msdn.microsoft.com/library/system.data.oledb.oledbtype) estrutura.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Armazena a hora resultante em referenciado *dbts* estrutura. O `DBTIMESTAMP` estrutura de dados inicializada por essa função terá seu `fraction` membro definido como zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#4](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_6.cpp)]

##  <a name="getassystemtime"></a>  COleDateTime::GetAsSystemTime

Chame esse método para obter a hora no `COleDateTime` objeto como um `SYSTEMTIME` estrutura de dados.

```
bool GetAsSystemTime(SYSTEMTIME& sysTime) const throw();
```

### <a name="parameters"></a>Parâmetros

*sysTime*<br/>
Uma referência a um [SYSTEMTIME](https://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que receberá o valor de data/hora convertido do `COleDateTime` objeto.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se bem-sucedido; FALSE se a conversão falhar, ou se o `COleDateTime` objeto é nulo ou inválido.

### <a name="remarks"></a>Comentários

`GetAsSystemTime` armazena a hora resultante em referenciado *sysTime* objeto. O `SYSTEMTIME` estrutura de dados inicializada por essa função terá seu `wMilliseconds` membro definido como zero.

Ver [GetStatus](#getstatus) para obter mais informações sobre as informações de status são mantidos em um `COleDateTime` objeto.

##  <a name="getasudate"></a>  COleDateTime::GetAsUDATE

Chame esse método para obter a hora no `COleDateTime` objeto como um `UDATE` estrutura de dados.

```
bool GetAsUDATE(UDATE& udate) const throw();
```

### <a name="parameters"></a>Parâmetros

*udate*<br/>
Uma referência a um `UDATE` estrutura que receberá o valor de data/hora convertido do `COleDateTime` objeto.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se bem-sucedido; FALSE se a conversão falhar, ou se o `COleDateTime` objeto é nulo ou inválido.

### <a name="remarks"></a>Comentários

Um `UDATE` estrutura representa uma data de "descompactada".

##  <a name="getcurrenttime"></a>  COleDateTime::GetCurrentTime

Chame essa função de membro estático para retornar o valor de data/hora atual.

```
static COleDateTime WINAPI GetCurrentTime() throw();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#5](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_7.cpp)]

##  <a name="getday"></a>  COleDateTime::GetDay

Obtém o dia do mês representado por esse valor de data/hora.

```
int GetDay() const throw();
```

### <a name="return-value"></a>Valor de retorno

O dia do mês representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o dia não pôde ser obtido.

### <a name="remarks"></a>Comentários

Intervalo de valores de retorno válido entre 1 e 31.

Para obter informações sobre outras funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetHour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#6](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_8.cpp)]

##  <a name="getdayofweek"></a>  COleDateTime::GetDayOfWeek

Obtém o dia do mês representado por esse valor de data/hora.

```
int GetDayOfWeek() const throw();
```

### <a name="return-value"></a>Valor de retorno

O dia da semana representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o dia da semana não pôde ser obtido.

### <a name="remarks"></a>Comentários

Valores de retorno válido variam entre 1 e 7, em que 1 = domingo, 2 = segunda-feira e assim por diante.

Para obter informações sobre outras funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetHour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#7](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_9.cpp)]

##  <a name="getdayofyear"></a>  COleDateTime::GetDayOfYear

Obtém o dia do ano representado por esse valor de data/hora.

```
int GetDayOfYear() const throw();
```

### <a name="return-value"></a>Valor de retorno

O dia do ano que representa o valor deste `COleDateTime` objeto ou `COleDateTime::error` se não foi possível obter o dia do ano.

### <a name="remarks"></a>Comentários

Valores de retorno válido variam entre 1 e 366, onde 1 de janeiro = 1.

Para obter informações sobre outras funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetHour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#8](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_10.cpp)]

##  <a name="gethour"></a>  COleDateTime::GetHour

Obtém a hora representada por esse valor de data/hora.

```
int GetHour() const throw();
```

### <a name="return-value"></a>Valor de retorno

A hora representada pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se a hora não pôde ser obtida.

### <a name="remarks"></a>Comentários

Intervalo de valores de retorno válido entre 0 e 23.

Para obter informações sobre outras funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#9](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_11.cpp)]

##  <a name="getminute"></a>  COleDateTime::GetMinute

Obtém o minuto representado por esse valor de data/hora.

```
int GetMinute() const throw();
```

### <a name="return-value"></a>Valor de retorno

O minuto representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se não foi possível obter o minuto.

### <a name="remarks"></a>Comentários

Intervalo de valores de retorno válido entre 0 e 59.

Para obter informações sobre outras funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetHour](#gethour)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

Veja o exemplo de [GetHour](#gethour).

##  <a name="getmonth"></a>  COleDateTime::GetMonth

Obtém o mês representado por esse valor de data/hora.

```
int GetMonth() const throw();
```

### <a name="return-value"></a>Valor de retorno

Mês representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o mês não pôde ser obtido.

### <a name="remarks"></a>Comentários

Intervalo de valores de retorno válido entre 1 e 12.

Para obter informações sobre outras funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetYear](#getyear)

- [GetHour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

Veja o exemplo de [GetDay](#getday).

##  <a name="getsecond"></a>  COleDateTime::GetSecond

Obtém o segundo representado por esse valor de data/hora.

```
int GetSecond() const throw();
```

### <a name="return-value"></a>Valor de retorno

O segundo representado pelo valor deste `COleDateTime` objeto ou `COleDateTime::error` se o segundo não pôde ser obtido.

### <a name="remarks"></a>Comentários

Intervalo de valores de retorno válido entre 0 e 59.

> [!NOTE]
>  O `COleDateTime` classe não oferece suporte para segundos intercalares.

Para obter mais informações sobre a implementação de `COleDateTime`, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

Para obter informações sobre outras funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetHour](#gethour)

- [GetMinute](#getminute)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

### <a name="example"></a>Exemplo

Veja o exemplo de [GetHour](#gethour).

##  <a name="getstatus"></a>  COleDateTime::GetStatus

Obtém o status (validade) de um determinado `COleDateTime` objeto.

```
DateTimeStatus GetStatus() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o status deste `COleDateTime` valor. Se você chamar `GetStatus` em um `COleDateTime` objeto construído com o padrão, ele retornará válido. Se você chamar `GetStatus` em um `COleDateTime` objeto inicializado com o conjunto de construtor para null, `GetStatus` retornará nulo. Ver **comentários** para obter mais informações.

### <a name="remarks"></a>Comentários

O valor de retorno é definido pela `DateTimeStatus` enumerados tipo, que é definido dentro de `COleDateTime` classe.

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

- `COleDateTime::error` Indica que ocorreu um erro ao tentar obter a parte do valor de data/hora.

- `COleDateTime::valid` Indica que este `COleDateTime` objeto é válido.

- `COleDateTime::invalid` Indica que este `COleDateTime` objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleDateTime::null` Indica que este `COleDateTime` objeto for nulo, ou seja, se nenhum valor foi fornecido para este objeto. (Isso é "null" no sentido de banco de dados de "não ter nenhum valor," em vez de nulo do C++)

O status de um `COleDateTime` objeto é inválido nos seguintes casos:

- Se seu valor é definido de uma `VARIANT` ou `COleVariant` valor que não pôde ser convertido para um valor de data/hora.

- Se seu valor é definido de uma `time_t`, `SYSTEMTIME`, ou `FILETIME` valor que não pôde ser convertido para um valor de data/hora válido.

- Se seu valor é definido pela `SetDateTime` com valores de parâmetro inválido.

- Se esse objeto experimentou um estouro ou estouro negativo durante uma operação aritmética de atribuição, ou seja, `+=` ou `-=`.

- Se um valor inválido foi atribuído a esse objeto.

- Se o status desse objeto foi definido explicitamente como inválidos usando `SetStatus`.

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte as seguintes funções de membro:

- [COleDateTime](#coledatetime)

- [SetDateTime](#setdatetime)

- [operador +, -](#operator_add_-)

- [Operator + =-=](#operator_add_eq_-_eq)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#10](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_12.cpp)]

##  <a name="getyear"></a>  COleDateTime::GetYear

Obtém o ano representado por esse valor de data/hora.

```
int GetYear() const throw();
```

### <a name="return-value"></a>Valor de retorno

Ano que representa o valor deste `COleDateTime` objeto ou `COleDateTime::error` se o ano não pôde ser obtido.

### <a name="remarks"></a>Comentários

Intervalo de valores de retorno válido entre 100 e 9999, que inclui o século.

Para obter informações sobre outras funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetHour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [GetDay](#getday).

##  <a name="m_dt"></a>  COleDateTime::m_dt

Subjacente `DATE` estrutura para este `COleDateTime` objeto.

```
DATE m_dt;
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
>  Alterando o valor de `DATE` objeto acessado pelo ponteiro retornado por essa função será alterado o valor deste `COleDateTime` objeto. Ele não altera o status deste `COleDateTime` objeto.

Para obter mais informações sobre a implementação do `DATE` do objeto, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

##  <a name="m_status"></a>  COleDateTime::m_status

Contém o status deste `COleDateTime` objeto.

```
DateTimeStatus m_status;
```

### <a name="remarks"></a>Comentários

O tipo desse membro de dados é o tipo enumerado `DateTimeStatus`, que é definido dentro de `COleDateTime` classe. Ver [COleDateTime::GetStatus](#getstatus) para obter detalhes.

> [!CAUTION]
>  Este membro de dados é para situações de programação avançadas. Você deve usar as funções de membro embutidas [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para cuidados adicionais em relação à configuração explícita este membro de dados.

##  <a name="operator_eq"></a>  COleDateTime::operator =

Copia um `COleDateTime` valor.

```
COleDateTime& operator=(const VARIANT& varSrc) throw();
COleDateTime& operator=(DATE dtSrc) throw();
COleDateTime& operator=(const time_t& timeSrc) throw();
COleDateTime& operator=(const __time64_t& timeSrc) throw();
COleDateTime& operator=(const SYSTEMTIME& systimeSrc) throw();
COleDateTime& operator=(const FILETIME& filetimeSrc) throw();
COleDateTime& operator=(const UDATE& udate) throw();
```

### <a name="remarks"></a>Comentários

Esses operadores de atribuição sobrecarregados copie o valor de data/hora de origem para isso `COleDateTime` objeto. Uma breve descrição de cada uma dessas sobrecarregado operadores de atribuição da seguinte maneira:

- **operador = (** `dateSrc` **)** o valor e o status do operando são copiados para isso `COleDateTime` objeto.

- **operador = (** *1&gt;Operator=(&lt;1}{2&gt;varsrc&lt;2}{3&gt;)&lt;3* **)** se a conversão do [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) valor (ou [COleVariant](../../mfc/reference/colevariant-class.md) objeto) em uma data/hora (VT_ Data) for bem-sucedida, o valor convertido é copiado para esse `COleDateTime` objeto e seu status é definido como válido. Se a conversão não for bem-sucedida, o valor desse objeto é definido como zero (30 de dezembro de 1899, meia-noite) e seu status para inválida.

- **operador = (** `dtSrc` **)** o `DATE` valor é copiado para esse `COleDateTime` objeto e seu status é definido como válido.

- **operador = (** `timeSrc` **)** o `time_t` ou `__time64_t` valor é convertido e copiado para isso `COleDateTime` objeto. Se a conversão for bem-sucedida, o status desse objeto é definido como válido. Se bem-sucedido, ele será definido para inválida.

- **operador = (** *systimeSrc* **)** o [SYSTEMTIME](https://msdn.microsoft.com/library/windows/desktop/ms724950) valor é convertido e copiado para isso `COleDateTime` objeto. Se a conversão for bem-sucedida, o status desse objeto é definido como válido. Se bem-sucedido, ele será definido para inválida.

- **operador = (** `udate` **)** o `UDATE` valor é convertido e copiado para isso `COleDateTime` objeto. Se a conversão for bem-sucedida, o status desse objeto é definido como válido. Se bem-sucedido, ele será definido para inválida. Um `UDATE` estrutura representa uma data de "descompactada". Consulte a função [VarDateFromUdate](/previous-versions/windows/desktop/api/oleauto/nf-oleauto-vardatefromudate) para obter mais detalhes.

- **operador = (** `filetimeSrc` **)** o [FILETIME](https://msdn.microsoft.com/library/windows/desktop/ms724284) valor é convertido e copiado para isso `COleDateTime` objeto. Se a conversão for bem-sucedida, o status desse objeto é definido como válido. Caso contrário, ele é definido para inválida. `FILETIME` usa o Horário Coordenado Universal (UTC), portanto, se você passar uma hora UTC na estrutura, seus resultados serão convertidos da hora UTC em hora local e serão armazenados como variante. Esse comportamento é o mesmo do Visual C++ 6.0 e do Visual C++ .NET 2003 SP2. Ver [tempos de arquivo](/windows/desktop/SysInfo/file-times) no SDK do Windows para obter mais informações.

Para obter mais informações, consulte o [VARIANT](/previous-versions/windows/desktop/api/oaidl/ns-oaidl-tagvariant) entrada no SDK do Windows.

Para obter mais informações sobre o `time_t` tipo de dados, consulte a [tempo](../../c-runtime-library/reference/time-time32-time64.md) funcionar no *referência de biblioteca de tempo de execução*.

Para obter mais informações, consulte o [SYSTEMTIME](https://msdn.microsoft.com/library/windows/desktop/ms724950) e [FILETIME](https://msdn.microsoft.com/library/windows/desktop/ms724284) estruturas no SDK do Windows.

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

##  <a name="operator_add_-"></a>  COleDateTime::operator +, -

Adicionar e subtrair `ColeDateTime` valores.

```
COleDateTime operator+(COleDateTimeSpan dateSpan) const throw();
COleDateTime operator-(COleDateTimeSpan dateSpan) const throw();
COleDateTimeSpan operator-(const COleDateTime& date) const throw();
```

### <a name="remarks"></a>Comentários

`COleDateTime` objetos representam o tempo absoluto. [COleDateTimeSpan](../../atl-mfc-shared/reference/coledatetimespan-class.md) objetos representam o tempo relativo. Os primeiros dois operadores permitem que você adicionar e subtrair um `COleDateTimeSpan` valor de uma `COleDateTime` valor. O terceiro operador permite que você subtrair um `COleDateTime` valor de outro para produzir um `COleDateTimeSpan` valor.

Se qualquer um dos operandos for null, o status de resultante `COleDateTime` valor é nulo.

Se resultante `COleDateTime` valor está fora dos limites de valores aceitáveis, o status do que `COleDateTime` o valor é inválido.

Se qualquer um dos operandos for inválido e o outro não for nulo, o status de resultante `COleDateTime` valor é inválido.

O **+** e **-** operadores declarará se o `COleDateTime` objeto é definido como null. Ver [COleDateTime de operadores relacionais](#coledatetime_relational_operators) para obter um exemplo.

Para obter mais informações sobre os valores de status válidos, inválidas e nulo, consulte o [m_status](#m_status) variável de membro.

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#12](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_13.cpp)]

##  <a name="operator_add_eq_-_eq"></a>  + = De COleDateTime::operator-=

Adicionar e subtrair um `ColeDateTime` valor deste `COleDateTime` objeto.

```
COleDateTime& operator+=(COleDateTimeSpan dateSpan) throw();
COleDateTime& operator-=(COleDateTimeSpan dateSpan) throw();
```

### <a name="remarks"></a>Comentários

Esses operadores permitem que você adicionar e subtrair um `COleDateTimeSpan` valor de e para isso `COleDateTime`. Se qualquer um dos operandos for null, o status de resultante `COleDateTime` valor é nulo.

Se resultante `COleDateTime` valor está fora dos limites de valores aceitáveis, o status deste `COleDateTime` valor é definido para inválida.

Se qualquer um dos operandos for inválido e outro não é nulo, o status de resultante `COleDateTime` valor é inválido.

Para obter mais informações sobre os valores de status válidos, inválidas e nulo, consulte o [m_status](#m_status) variável de membro.

O **+=** e **-=** operadores declarará se o `COleDateTime` objeto é definido como null. Ver [COleDateTime de operadores relacionais](#coledatetime_relational_operators) para obter um exemplo.

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

##  <a name="operator_date"></a>  COleDateTime::operator data

Converte um `ColeDateTime` de valor em um `DATE`.

```
operator DATE() const throw();
```

### <a name="remarks"></a>Comentários

Esse operador retornará um `DATE` objeto cujo valor é copiado deste `COleDateTime` objeto. Para obter mais informações sobre a implementação do `DATE` do objeto, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

O `DATE` operador declarará se o `COleDateTime` objeto é definido como null. Ver [COleDateTime de operadores relacionais](#coledatetime_relational_operators) para obter um exemplo.

##  <a name="parsedatetime"></a>  COleDateTime::ParseDateTime

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
Indica os sinalizadores para as configurações de localidade e a análise. Um ou mais dos seguintes sinalizadores:

- LOCALE_NOUSEROVERRIDE usar as configurações de localidade do sistema padrão, em vez de configurações do usuário personalizadas.

- VAR_TIMEVALUEONLY ignorar a parte de data durante a análise.

- VAR_DATEVALUEONLY ignorar a parte de hora durante a análise.

*lcid*<br/>
Indica a ID de localidade a ser usado para a conversão.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a cadeia de caracteres foi convertida com êxito para um valor de data/hora, caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se a cadeia de caracteres foi convertida com êxito em um valor de data/hora de valor, o valor deste `COleDateTime` objeto é definido como valor e seu status como válido.

> [!NOTE]
>  Valores de ano devem estar entre 100 e 9999, inclusive.

O *lpszDate* parâmetro pode assumir uma variedade de formatos. Por exemplo, as cadeias de caracteres a seguir contêm os formatos de data/hora aceitável:

`"25 January 1996"`

`"8:30:00"`

`"20:30:00"`

`"January 25, 1996 8:30:00"`

`"8:30:00 Jan. 25, 1996"`

`"1/25/1996 8:30:00"  // always specify the full year, even in a 'short date' format`

Observe que a ID de localidade também afeta se o formato de cadeia de caracteres é aceitável para a conversão para um valor de data/hora.

No caso de VAR_DATEVALUEONLY, o valor de hora é definido como 0 ou meia-noite de tempo. No caso de VAR_TIMEVALUEONLY, o valor de data é definido como data 0, o que significa que 30 de dezembro de 1899.

Se a cadeia de caracteres não pôde ser convertida para um valor de data/hora ou se houve um estouro numérico, o status deste `COleDateTime` objeto é inválido.

Para obter mais informações sobre os limites e a implementação para `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

##  <a name="setdate"></a>  COleDateTime::SetDate

Define a data desta `COleDateTime` objeto.

```
int SetDate(  
int nYear,
int nMonth,
int nDay) throw();
```

### <a name="parameters"></a>Parâmetros

*nYear*, *nMonth*, *nDay*  
Indique os componentes de data a ser copiado para isso `COleDateTime` objeto.

### <a name="return-value"></a>Valor de retorno

Zero se o valor deste `COleDateTime` objeto foi definido com êxito; caso contrário, 1. Esse valor de retorno se baseia o `DateTimeStatus` tipo enumerado. Para obter mais informações, consulte o [SetStatus](#setstatus) função de membro.

### <a name="remarks"></a>Comentários

A data é definida com os valores especificados. A hora é definida como hora 0, meia-noite.

Consulte a tabela a seguir para limites para os valores de parâmetro:

|Parâmetro|Limites|
|---------------|------------|
|*nYear*|100 - 9999|
|*nMonth*|1 - 12|
|*nDay*|0 - 31|

Se o dia do mês estourar, ele será convertido para o dia do próximo mês e o mês e/ou ano é incrementado adequadamente. Um valor de dia zero indica o último dia do mês anterior. O comportamento é o mesmo que `SystemTimeToVariantTime`.

Se o valor de data especificado pelos parâmetros não é válido, o status desse objeto é definido como `COleDateTime::invalid`. Você deve usar [GetStatus](#getstatus) para verificar a validade da `DATE` de valor e não deve presumir que o valor de [m_dt](#m_dt) permanecerá inalterado.

Aqui estão alguns exemplos de valores de data:

|*nYear*|*nMonth*|*nDay*|Valor|
|-------------|--------------|------------|-----------|
|2000|2|29|29 de fevereiro de 2000|
|1776|7|4|De 1776 4 de julho|
|1925|4|35|35 de 1925 abril (data inválida)|
|10000|1|1|1º de janeiro 10000 (data inválida)|

Para definir a data e hora, consulte [COleDateTime::SetDateTime](#setdatetime).

Para obter informações sobre funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetHour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#11](../../atl-mfc-shared/codesnippet/cpp/coledatetime-class_14.cpp)]

##  <a name="setdatetime"></a>  COleDateTime::SetDateTime

Define a data e hora deste `COleDateTime` objeto.

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

*nYear*, *nMonth*, *nDay*, *Nhora*, *Nmín*, *nSec*  
Indique os componentes de data e hora a ser copiado para isso `COleDateTime` objeto.

### <a name="return-value"></a>Valor de retorno

Zero se o valor deste `COleDateTime` objeto foi definido com êxito; caso contrário, 1. Esse valor de retorno se baseia o `DateTimeStatus` tipo enumerado. Para obter mais informações, consulte o [SetStatus](#setstatus) função de membro.

### <a name="remarks"></a>Comentários

Consulte a tabela a seguir para limites para os valores de parâmetro:

|Parâmetro|Limites|
|---------------|------------|
|*nYear*|100 - 9999|
|*nMonth*|1 - 12|
|*nDay*|0 - 31|
|*Nhora*|0 - 23|
|*Nmín*|0 - 59|
|*nSec*|0 - 59|

Se o dia do mês estourar, ele será convertido para o dia do próximo mês e o mês e/ou ano é incrementado adequadamente. Um valor de dia zero indica o último dia do mês anterior. O comportamento é igual a [SystemTimeToVariantTime](/previous-versions/windows/desktop/api/oleauto/nf-oleauto-systemtimetovarianttime).

Se o valor de data ou hora especificado pelos parâmetros não é válido, que o status desse objeto é definido como inválido e o valor desse objeto não será alterada.

Aqui estão alguns exemplos de valores de hora:

|*Nhora*|*Nmín*|*nSec*|Valor|
|-------------|------------|------------|-----------|
|1|3|3|01:03:03|
|23|45|0|23:45:00|
|25|30|0|Inválido|
|9|60|0|Inválido|

Aqui estão alguns exemplos de valores de data:

|*nYear*|*nMonth*|*nDay*|Valor|
|-------------|--------------|------------|-----------|
|1995|4|15|15 de abril de 1995|
|1789|7|14|De 1789 17 de julho|
|1925|2|30|Inválido|
|10000|1|1|Inválido|

Para definir apenas a data, consulte [COleDateTime::SetDate](#setdate). Para definir apenas a hora, consulte [COleDateTime::SetTime](#settime).

Para obter informações sobre funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetHour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [GetStatus](#getstatus).

##  <a name="setstatus"></a>  COleDateTime::SetStatus

Define o status deste `COleDateTime` objeto.

```
void SetStatus(DateTimeStatus status) throw();
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O novo valor de status para esse `COleDateTime` objeto.

### <a name="remarks"></a>Comentários

O *status* o valor do parâmetro é definido pela `DateTimeStatus` enumerados tipo, que é definido dentro a `COleDateTime` classe. Ver [COleDateTime::GetStatus](#getstatus) para obter detalhes.

> [!CAUTION]
>  Essa função é para situações de programação avançadas. Essa função não altera os dados neste objeto. Ele geralmente será usado para definir o status como **nulo** ou **inválido**. Observe que o operador de atribuição ( [operador =](#eq)) e [SetDateTime](#setdatetime) definir o status do objeto com base em valores de origem.

### <a name="example"></a>Exemplo

Veja o exemplo de [GetStatus](#getstatus).

##  <a name="settime"></a>  COleDateTime::SetTime

Define o tempo isso `COleDateTime` objeto.

```
int SetTime(  
int nHour,
int nMin,
int nSec) throw();
```

### <a name="parameters"></a>Parâmetros

*Nhora*, *Nmín*, *nSec*  
Indique os componentes de tempo a ser copiado para isso `COleDateTime` objeto.

### <a name="return-value"></a>Valor de retorno

Zero se o valor deste `COleDateTime` objeto foi definido com êxito; caso contrário, 1. Esse valor de retorno se baseia o `DateTimeStatus` tipo enumerado. Para obter mais informações, consulte o [SetStatus](#setstatus) função de membro.

### <a name="remarks"></a>Comentários

A hora é definida com os valores especificados. A data é definida como data 0, o que significa que 30 de dezembro de 1899.

Consulte a tabela a seguir para limites para os valores de parâmetro:

|Parâmetro|Limites|
|---------------|------------|
|*Nhora*|0 - 23|
|*Nmín*|0 - 59|
|*nSec*|0 - 59|

Se o tempo especificado pelos parâmetros de valor não for válido, o status desse objeto é definido como inválido e o valor desse objeto não será alterado.

Aqui estão alguns exemplos de valores de hora:

|*Nhora*|*Nmín*|*nSec*|Valor|
|-------------|------------|------------|-----------|
|1|3|3|01:03:03|
|23|45|0|23:45:00|
|25|30|0|Inválido|
|9|60|0|Inválido|

Para definir a data e hora, consulte [COleDateTime::SetDateTime](#setdatetime).

Para obter informações sobre funções de membro que consultar o valor deste `COleDateTime` de objeto, consulte as seguintes funções de membro:

- [GetDay](#getday)

- [GetMonth](#getmonth)

- [GetYear](#getyear)

- [GetHour](#gethour)

- [GetMinute](#getminute)

- [GetSecond](#getsecond)

- [GetDayOfWeek](#getdayofweek)

- [GetDayOfYear](#getdayofyear)

Para obter mais informações sobre os limites de `COleDateTime` valores, consulte o artigo [data e hora: suporte de automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

Veja o exemplo de [SetDate](#setdate).

## <a name="see-also"></a>Consulte também

[Classe COleVariant](../../mfc/reference/colevariant-class.md)<br/>
[Classe CTime](../../atl-mfc-shared/reference/ctime-class.md)<br/>
[Classe CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)

