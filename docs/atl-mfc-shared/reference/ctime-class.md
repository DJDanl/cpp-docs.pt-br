---
title: Classe CTime
ms.date: 10/18/2018
f1_keywords:
- ATLTIME/ATL::CTime
- ATLTIME/ATL::CTime::CTime
- ATLTIME/ATL::CTime::Format
- ATLTIME/ATL::CTime::FormatGmt
- ATLTIME/ATL::CTime::GetAsDBTIMESTAMP
- ATLTIME/ATL::CTime::GetAsSystemTime
- ATLTIME/ATL::CTime::GetCurrentTime
- ATLTIME/ATL::CTime::GetDay
- ATLTIME/ATL::CTime::GetDayOfWeek
- ATLTIME/ATL::CTime::GetGmtTm
- ATLTIME/ATL::CTime::GetHour
- ATLTIME/ATL::CTime::GetLocalTm
- ATLTIME/ATL::CTime::GetMinute
- ATLTIME/ATL::CTime::GetMonth
- ATLTIME/ATL::CTime::GetSecond
- ATLTIME/ATL::CTime::GetTime
- ATLTIME/ATL::CTime::GetYear
- ATLTIME/ATL::CTime::Serialize64
helpviewer_keywords:
- CTime class
- shared classes, CTime
ms.assetid: 0a299544-485b-48dc-9d3c-fdc30f57d612
ms.openlocfilehash: a1d62cca42e3110974b07dae143bafcf807fed7e
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440492"
---
# <a name="ctime-class"></a>Classe CTime

Representa uma data e hora absoluta.

## <a name="syntax"></a>Sintaxe

```
class CTime
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CTime::CTime](#ctime)|Constrói `CTime` objetos de várias maneiras.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CTime:: Format](#format)|Converte um objeto `CTime` em uma cadeia de caracteres formatada — com base no fuso horário local.|
|[CTime::FormatGmt](#formatgmt)|Converte um objeto `CTime` em uma cadeia de caracteres formatada — com base em UTC.|
|[CTime::GetAsDBTIMESTAMP](#getasdbtimestamp)|Converte as informações de hora armazenadas no objeto `CTime` em uma estrutura DBTIMESTAMP compatível com Win32.|
|[CTime::GetAsSystemTime](#getassystemtime)|Converte as informações de hora armazenadas no objeto `CTime` em uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) compatível com Win32.|
|[CTime:: getactualtime](#getcurrenttime)|Cria um objeto `CTime` que representa a hora atual (função de membro estático).|
|[CTime::GetDay](#getday)|Retorna o dia representado pelo objeto `CTime`.|
|[CTime:: GetDayOfWeek](#getdayofweek)|Retorna o dia da semana representado pelo objeto `CTime`.|
|[CTime::GetGmtTm](#getgmttm)|Divide um objeto `CTime` em componentes — com base em UTC.|
|[CTime:: gethora](#gethour)|Retorna a hora representada pelo objeto `CTime`.|
|[CTime::GetLocalTm](#getlocaltm)|Divide um objeto `CTime` em componentes — com base no fuso horário local.|
|[CTime:: GetMinute](#getminute)|Retorna o minuto representado pelo objeto `CTime`.|
|[CTime::GetMonth](#getmonth)|Retorna o mês representado pelo objeto `CTime`.|
|[CTime:: GetSecond](#getsecond)|Retorna o segundo representado pelo objeto `CTime`.|
|[CTime:: getTime](#gettime)|Retorna um valor **__time64_t** para o objeto `CTime` fornecido.|
|[CTime:: GetYear](#getyear)|Retorna o ano representado pelo objeto `CTime`.|
|[CTime::Serialize64](#serialize64)|Serializa dados de ou para um arquivo morto.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador +-](#operator_add_-)|Esses operadores adicionam e subtraim objetos `CTimeSpan` e `CTime`.|
|[operador + =,-=](#operator_add_eq_-_eq)|Esses operadores adicionam e subtraim um objeto de `CTimeSpan` de e para esse objeto `CTime`.|
|[operador =](#operator_eq)|O operador de atribuição.|
|[Operator = =, <, etc.](#ctime_comparison_operators)|Operadores de comparação.|

## <a name="remarks"></a>Comentários

`CTime` não tem uma classe base.

`CTime` valores se baseiam em UTC (tempo Universal Coordenado), que é equivalente ao tempo universal coordenado (Greenwich Mean Time, GMT). Consulte [Gerenciamento de tempo](../../c-runtime-library/time-management.md) para obter informações sobre como o fuso horário é determinado.

Quando você cria um objeto de `CTime`, defina o parâmetro `nDST` como 0 para indicar que o horário padrão está em vigor ou com um valor maior que 0 para indicar que o horário de verão está em vigor ou com um valor menor que zero para que a computação de código de biblioteca de tempo de execução C seja computada, independentemente do horário padrão ou da hora de verão em vigor. `tm_isdst` é um campo obrigatório. Se não estiver definido, seu valor será indefinido e o valor de retorno de [mktime](../../c-runtime-library/reference/mktime-mktime32-mktime64.md) será imprevisível. Se `timeptr` apontar para uma estrutura TM retornada por uma chamada anterior para [asctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md), [_gmtime_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)ou [localtime_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md), o campo `tm_isdst` conterá o valor correto.

Uma classe complementar, [CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md), representa um intervalo de tempo.

As classes `CTime` e `CTimeSpan` não são projetadas para derivação. Como não há nenhuma função virtual, o tamanho dos objetos `CTime` e `CTimeSpan` é exatamente 8 bytes. A maioria das funções de membro é embutida.

> [!NOTE]
>  O limite de datas superiores é 12/31/3000. O limite inferior é 1/1/1970 12:00:00 AM GMT.

Para obter mais informações sobre como usar `CTime`, consulte os artigos [data e hora](../../atl-mfc-shared/date-and-time.md)e [Gerenciamento de hora](../../c-runtime-library/time-management.md) na referência da biblioteca de tempo de execução.

> [!NOTE]
>  A estrutura de `CTime` mudou de MFC 7,1 para MFC 8,0. Se você serializar uma estrutura de `CTime` usando o **operador < <** sob o MFC 8,0 ou uma versão posterior, o arquivo resultante não será legível em versões mais antigas do MFC.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atltime. h

##  <a name="ctime_comparison_operators"></a>Operadores de comparação de CTime

Operadores de comparação.

```
bool operator==(CTime time) const throw();
bool operator!=(CTime time) const throw();
bool operator<(CTime time) const throw();
bool operator>(CTime time) const throw();
bool operator<=(CTime time) const throw();
bool operator>=(CTime time) const throw();
```

### <a name="parameters"></a>Parâmetros

*time*<br/>
O objeto `CTime` a ser comparado.

### <a name="return-value"></a>Valor retornado

Esses operadores comparam duas horas absolutas e retornarão TRUE se a condição for verdadeira; caso contrário, FALSE.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#161](../../atl-mfc-shared/codesnippet/cpp/ctime-class_1.cpp)]

##  <a name="ctime"></a>CTime::CTime

Cria um novo objeto `CTime` inicializado com o tempo especificado.

```
CTime() throw();
CTime(__time64_t time) throw();
CTime(int nYear, int nMonth, int nDay,
      int nHour, int nMin, int nSec, int nDST = -1);
CTime(WORD wDosDate, WORD wDosTime, int nDST = -1);
CTime(const SYSTEMTIME& st, int nDST = - 1) throw();
CTime(const FILETIME& ft, int nDST = - 1);
CTime(const DBTIMESTAMP& dbts, int nDST = -1) throw();
```

### <a name="parameters"></a>Parâmetros

*timeSrc*<br/>
Indica um objeto `CTime` que já existe.

*time*<br/>
Um valor de `__time64_t` hora, que é o número de segundos após 1º de janeiro de 1970 UTC. Observe que isso será ajustado para a hora local. Por exemplo, se você estiver em Nova York e criar um objeto `CTime` passando um parâmetro de 0, [CTime:: GetMonth](#getmonth) retornará 12.

*nYear*, *nMonth*, *ndia*, *nhora*, *nmín*, *NSEC*<br/>
Indica os valores de data e hora a serem copiados para o novo objeto `CTime`.

*nDST*<br/>
Indica se o horário de verão está em vigor. Pode ter um destes três valores:

- *nDST* definido como 0Standard time está em vigor.

- *nDST* definido como um valor maior que o tempo de economia de 0Daylight está em vigor.

- *nDST* definido como um valor menor que 0The padrão. Computa automaticamente se a hora padrão ou o horário de verão está em vigor.

*wDosDate*, *wDosTime*<br/>
Valores de data e hora do MS-DOS a serem convertidos em um valor de data/hora e copiados para o novo objeto `CTime`.

*St*<br/>
Uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) a ser convertida em um valor de data/hora e copiada para o novo objeto `CTime`.

*ft*<br/>
Uma estrutura [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) a ser convertida em um valor de data/hora e copiada para o novo objeto `CTime`.

*DBTS*<br/>
Uma referência a uma estrutura DBTIMESTAMP que contém a hora local atual.

### <a name="remarks"></a>Comentários

Cada construtor é descrito abaixo:

- `CTime();` constrói um objeto de `CTime` não inicializado. Esse construtor permite que você defina `CTime` matrizes de objeto. Você deve inicializar essas matrizes com horários válidos antes de usar o.

- `CTime( const CTime& );` constrói um objeto `CTime` de outro valor `CTime`.

- `CTime( __time64_t );` constrói um objeto de `CTime` de um tipo de **__time64_t** . Esse construtor espera uma hora UTC e converte o resultado em uma hora local antes de armazenar o resultado.

- `CTime( int, int, ...);` constrói um objeto `CTime` de componentes de hora local com cada componente restrito aos seguintes intervalos:

   |Componente|Intervalo|
   |---------------|-----------|
   |*nYear*|1970-3000|
   |*nMonth*|1-12|
   |*Ndia*|1-31|
   |*Nhora*|0-23|
   |*Nmín*|0-59|
   |*nSec*|0-59|

   Esse construtor faz a conversão apropriada para o UTC. A versão de depuração do biblioteca MFC afirma se um ou mais dos componentes de tempo estão fora do intervalo. Você deve validar os argumentos antes de chamar. Esse construtor espera uma hora local.

- `CTime( WORD, WORD );` constrói um objeto `CTime` dos valores de data e hora do MS-DOS especificados. Esse construtor espera uma hora local.

- `CTime( const SYSTEMTIME& );` constrói um objeto de `CTime` de uma estrutura de `SYSTEMTIME`. Esse construtor espera uma hora local.

- `CTime( const FILETIME& );` constrói um objeto de `CTime` de uma estrutura de `FILETIME`. Provavelmente, você não usará `CTime FILETIME` inicialização diretamente. Se você usar um objeto `CFile` para manipular um arquivo, `CFile::GetStatus` recuperará o carimbo de data/hora do arquivo por meio de um objeto `CTime` inicializado com uma estrutura de `FILETIME`. Esse construtor assume um tempo baseado em UTC e converte automaticamente o valor em hora local antes de armazenar o resultado.

   > [!NOTE]
   > O construtor usando `DBTIMESTAMP` parâmetro só está disponível quando OLEDB. h está incluído.

Para obter mais informações, consulte a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) e [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) na SDK do Windows. Consulte também a entrada de [data e hora do MS-dos](/windows/win32/SysInfo/ms-dos-date-and-time) no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#148](../../atl-mfc-shared/codesnippet/cpp/ctime-class_2.cpp)]

##  <a name="format"></a>CTime:: Format

Chame essa função de membro para criar uma representação formatada do valor de data e hora.

```
CString Format(LPCTSTR pszFormat) const;
CString Format(UINT nFormatID) const;
```

### <a name="parameters"></a>Parâmetros

*pszFormat*<br/>
Uma cadeia de caracteres de formatação semelhante à `printf` cadeia de caracteres de formatação. Os códigos de formatação, precedidos por um sinal de porcentagem (`%`), são substituídos pelo componente `CTime` correspondente. Outros caracteres na cadeia de caracteres de formatação são copiados inalterados para a cadeia de caracteres retornada. Consulte a função de tempo de execução [strftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter uma lista de códigos de formatação.

*nFormatID*<br/>
A ID da cadeia de caracteres que identifica esse formato.

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o tempo formatado.

### <a name="remarks"></a>Comentários

Se o status dessa `CTime` objeto for nulo, o valor de retorno será uma cadeia de caracteres vazia.

Esse método gera uma exceção se o valor de data-hora a ser formatado não varia da meia-noite, de 1º de janeiro de 1970 até 31 de dezembro de 3000, UTC (tempo coordenado universal).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#149](../../atl-mfc-shared/codesnippet/cpp/ctime-class_3.cpp)]

##  <a name="formatgmt"></a>CTime::FormatGmt

Gera uma cadeia de caracteres formatada que corresponde a este objeto de `CTime`.

```
CString FormatGmt(LPCTSTR pszFormat) const;
CString FormatGmt(UINT nFormatID) const;
```

### <a name="parameters"></a>Parâmetros

*pszFormat*<br/>
Especifica uma cadeia de caracteres de formatação semelhante à `printf` cadeia de caracteres de formatação. Consulte a função de tempo de execução [strftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter detalhes.

*nFormatID*<br/>
A ID da cadeia de caracteres que identifica esse formato.

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o tempo formatado.

### <a name="remarks"></a>Comentários

O valor de hora não é convertido e, portanto, reflete o UTC.

Esse método gera uma exceção se o valor de data-hora a ser formatado não varia da meia-noite, de 1º de janeiro de 1970 até 31 de dezembro de 3000, UTC (tempo coordenado universal).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo de [CTime:: Format](#format).

##  <a name="getasdbtimestamp"></a>CTime::GetAsDBTIMESTAMP

Chame essa função de membro para converter as informações de hora armazenadas no objeto `CTime` em uma estrutura DBTIMESTAMP compatível com Win32.

```
bool GetAsDBTIMESTAMP(DBTIMESTAMP& dbts) const throw();
```

### <a name="parameters"></a>Parâmetros

*DBTS*<br/>
Uma referência a uma estrutura DBTIMESTAMP que contém a hora local atual.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Armazena o tempo resultante na estrutura *DBTS* referenciada. A estrutura de dados `DBTIMESTAMP` inicializada por essa função terá seu membro `fraction` definido como zero.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#150](../../atl-mfc-shared/codesnippet/cpp/ctime-class_4.cpp)]

##  <a name="getassystemtime"></a>CTime::GetAsSystemTime

Chame essa função de membro para converter as informações de hora armazenadas no objeto `CTime` em uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) compatível com Win32.

```
bool GetAsSystemTime(SYSTEMTIME& st) const throw();
```

### <a name="parameters"></a>Parâmetros

*timeDest*<br/>
Uma referência a uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que manterá o valor de data/hora convertido do objeto `CTime`.

### <a name="return-value"></a>Valor retornado

Verdadeiro se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`GetAsSystemTime` armazena o tempo resultante na estrutura *timeDest* referenciada. A estrutura de dados `SYSTEMTIME` inicializada por essa função terá seu membro `wMilliseconds` definido como zero.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#151](../../atl-mfc-shared/codesnippet/cpp/ctime-class_5.cpp)]

##  <a name="getcurrenttime"></a>CTime:: getactualtime

Retorna um objeto `CTime` que representa a hora atual.

```
static CTime WINAPI GetCurrentTime() throw();
```

### <a name="remarks"></a>Comentários

Retorna a data e a hora atuais do sistema no UTC (tempo Universal Coordenado).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#152](../../atl-mfc-shared/codesnippet/cpp/ctime-class_6.cpp)]

##  <a name="getday"></a>CTime::GetDay

Retorna o dia representado pelo objeto `CTime`.

```
int GetDay() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o dia do mês, com base na hora local, no intervalo de 1 a 31.

### <a name="remarks"></a>Comentários

Essa função chama `GetLocalTm`, que usa um buffer interno e alocado estaticamente. Os dados nesse buffer são substituídos devido a chamadas para outras funções de membro de `CTime`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#153](../../atl-mfc-shared/codesnippet/cpp/ctime-class_7.cpp)]

##  <a name="getdayofweek"></a>CTime:: GetDayOfWeek

Retorna o dia da semana representado pelo objeto `CTime`.

```
int GetDayOfWeek() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o dia da semana com base na hora local; 1 = domingo, 2 = segunda-feira, até 7 = sábado.

### <a name="remarks"></a>Comentários

Essa função chama `GetLocalTm`, que usa um buffer interno alocado estaticamente. Os dados nesse buffer são substituídos devido a chamadas para outras funções de membro de `CTime`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#154](../../atl-mfc-shared/codesnippet/cpp/ctime-class_8.cpp)]

##  <a name="getgmttm"></a>CTime::GetGmtTm

Obtém uma **struct tm** que contém uma decomposição da hora contida neste `CTime` objeto.

```
struct tm* GetGmtTm(struct tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*ptm*<br/>
Aponta para um buffer que receberá os dados de tempo. Se esse ponteiro for nulo, uma exceção será lançada.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma **struct tm** preenchida, conforme definido na hora do arquivo de inclusão. T. Consulte [gmtime, _gmtime32 _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) para o layout da estrutura.

### <a name="remarks"></a>Comentários

`GetGmtTm` retorna UTC.

*PTM* não pode ser nulo. Se você quiser reverter para o comportamento antigo, no qual *PTM* poderia ser nulo para indicar que um buffer interno, alocado estaticamente, deve ser usado e, em seguida, undefine _SECURE_ATL.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#155](../../atl-mfc-shared/codesnippet/cpp/ctime-class_9.cpp)]

##  <a name="gethour"></a>CTime:: gethora

Retorna a hora representada pelo objeto `CTime`.

```
int GetHour() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a hora, com base na hora local, no intervalo de 0 a 23.

### <a name="remarks"></a>Comentários

Essa função chama `GetLocalTm`, que usa um buffer interno alocado estaticamente. Os dados nesse buffer são substituídos devido a chamadas para outras funções de membro de `CTime`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#156](../../atl-mfc-shared/codesnippet/cpp/ctime-class_10.cpp)]

##  <a name="getlocaltm"></a>CTime::GetLocalTm

Obtém uma **struct tm** que contém uma decomposição da hora contida neste `CTime` objeto.

```
struct tm* GetLocalTm(struct tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*ptm*<br/>
Aponta para um buffer que receberá os dados de tempo. Se esse ponteiro for nulo, uma exceção será lançada.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma **struct tm** preenchida, conforme definido na hora do arquivo de inclusão. T. Consulte [gmtime, _gmtime32 _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) para o layout da estrutura.

### <a name="remarks"></a>Comentários

`GetLocalTm` retorna a hora local.

*PTM* não pode ser nulo. Se você quiser reverter para o comportamento antigo, no qual *PTM* poderia ser nulo para indicar que um buffer interno, alocado estaticamente, deve ser usado e, em seguida, undefine _SECURE_ATL.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#157](../../atl-mfc-shared/codesnippet/cpp/ctime-class_11.cpp)]

##  <a name="getminute"></a>CTime:: GetMinute

Retorna o minuto representado pelo objeto `CTime`.

```
int GetMinute() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o minuto, com base na hora local, no intervalo de 0 a 59.

### <a name="remarks"></a>Comentários

Essa função chama `GetLocalTm`, que usa um buffer interno alocado estaticamente. Os dados nesse buffer são substituídos devido a chamadas para outras funções de membro de `CTime`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo de [gethora](#gethour).

##  <a name="getmonth"></a>CTime::GetMonth

Retorna o mês representado pelo objeto `CTime`.

```
int GetMonth() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o mês, com base na hora local, no intervalo de 1 a 12 (1 = Janeiro).

### <a name="remarks"></a>Comentários

Essa função chama `GetLocalTm`, que usa um buffer interno alocado estaticamente. Os dados nesse buffer são substituídos devido a chamadas para outras funções de membro de `CTime`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo de [getDay](#getday).

##  <a name="getsecond"></a>CTime:: GetSecond

Retorna o segundo representado pelo objeto `CTime`.

```
int GetSecond() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o segundo, com base na hora local, no intervalo de 0 a 59.

### <a name="remarks"></a>Comentários

Essa função chama `GetLocalTm`, que usa um buffer interno alocado estaticamente. Os dados nesse buffer são substituídos devido a chamadas para outras funções de membro de `CTime`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo de [gethora](#gethour).

##  <a name="gettime"></a>CTime:: getTime

Retorna um valor **__time64_t** para o objeto `CTime` fornecido.

```
__time64_t GetTime() const throw();
```

### <a name="return-value"></a>Valor retornado

`GetTime` retornará o número de segundos entre o objeto `CTime` atual e 1º de janeiro de 1970.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#158](../../atl-mfc-shared/codesnippet/cpp/ctime-class_12.cpp)]

##  <a name="getyear"></a>CTime:: GetYear

Retorna o ano representado pelo objeto `CTime`.

```
int GetYear();
```

### <a name="return-value"></a>Valor retornado

Retorna o ano, com base na hora local, no intervalo de 1º de janeiro de 1970, até 18 de janeiro de 2038 (inclusivo).

### <a name="remarks"></a>Comentários

Essa função chama `GetLocalTm`, que usa um buffer interno alocado estaticamente. Os dados nesse buffer são substituídos devido a chamadas para outras funções de membro de `CTime`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Consulte o exemplo de [getDay](#getday).

##  <a name="operator_eq"></a>CTime:: Operator =

O operador de atribuição.

```
CTime& operator=(__time64_t time) throw();
```

### <a name="parameters"></a>Parâmetros

*time*<br/>
O novo valor de data/hora.

### <a name="return-value"></a>Valor retornado

O objeto `CTime` atualizado.

### <a name="remarks"></a>Comentários

Esse operador de atribuição sobrecarregado copia o tempo de origem para esse `CTime` objeto. O armazenamento de horário interno em um objeto `CTime` é independente do fuso horário. A conversão de fuso horário não é necessária durante a atribuição.

##  <a name="operator_add_-"></a>CTime:: operator +,-

Esses operadores adicionam e subtraim objetos `CTimeSpan` e `CTime`.

```
CTime operator+(CTimeSpan timeSpan) const throw();
CTime operator-(CTimeSpan timeSpan) const throw();
CTimeSpan operator-(CTime time) const throw();
```

### <a name="parameters"></a>Parâmetros

*Período*<br/>
O objeto `CTimeSpan` a ser adicionado ou subtraído.

*time*<br/>
O objeto `CTime` a ser subtraído.

### <a name="return-value"></a>Valor retornado

Um objeto `CTime` ou `CTimeSpan` que representa o resultado da operação.

### <a name="remarks"></a>Comentários

`CTime` objetos representam o tempo absoluto, `CTimeSpan` objetos representam o tempo relativo. Os primeiros dois operadores permitem adicionar e subtrair `CTimeSpan` objetos de e para objetos `CTime`. O terceiro operador permite subtrair um objeto `CTime` de outro para gerar um objeto `CTimeSpan`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#159](../../atl-mfc-shared/codesnippet/cpp/ctime-class_13.cpp)]

##  <a name="operator_add_eq_-_eq"></a>CTime:: operator + =,-=

Esses operadores adicionam e subtraim um objeto de `CTimeSpan` de e para esse objeto `CTime`.

```
CTime& operator+=(CTimeSpan span) throw();
CTime& operator-=(CTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*compreende*<br/>
O objeto `CTimeSpan` a ser adicionado ou subtraído.

### <a name="return-value"></a>Valor retornado

O objeto `CTime` atualizado.

### <a name="remarks"></a>Comentários

Esses operadores permitem adicionar e subtrair um objeto de `CTimeSpan` de e para esse objeto `CTime`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATLMFC_Utilities#160](../../atl-mfc-shared/codesnippet/cpp/ctime-class_14.cpp)]

##  <a name="serialize64"></a>CTime::Serialize64

> [!NOTE]
> Esse método só está disponível em projetos MFC.

Serializa os dados associados à variável de membro de ou para um arquivo morto.

```
CArchive& Serialize64(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*multi-hop*<br/>
O objeto `CArchive` que você deseja atualizar.

### <a name="return-value"></a>Valor retornado

O objeto `CArchive` atualizado.

## <a name="see-also"></a>Consulte também

[asctime_s, _wasctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)<br/>
[_ftime_s, _ftime32_s, _ftime64_s](../../c-runtime-library/reference/ftime-s-ftime32-s-ftime64-s.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)<br/>
[strftime, wcsftime, _strftime_l, _wcsftime_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)<br/>
[time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)<br/>
[Classe CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
