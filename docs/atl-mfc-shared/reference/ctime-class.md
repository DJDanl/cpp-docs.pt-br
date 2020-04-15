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
ms.openlocfilehash: e6e471fe648c5fa370cce750e8569e158eb1ffe4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317564"
---
# <a name="ctime-class"></a>Classe CTime

Representa uma data e hora absolutas.

## <a name="syntax"></a>Sintaxe

```
class CTime
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTime::CTime](#ctime)|Constrói `CTime` objetos de várias maneiras.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTime::Formato](#format)|Converte `CTime` um objeto em uma seqüência formatada — com base no fuso horário local.|
|[CTime::FormatGmt](#formatgmt)|Converte `CTime` um objeto em uma seqüência formatada — com base em UTC.|
|[CTime::GetAsDBTIMESTAMP](#getasdbtimestamp)|Converte as informações de `CTime` tempo armazenadas no objeto para uma estrutura DBTIMESTAMP compatível com Win32.|
|[CTime::getAsSystemTime](#getassystemtime)|Converte as informações de `CTime` tempo armazenadas no objeto para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) compatível com Win32.|
|[CTime::getCurrentTime](#getcurrenttime)|Cria `CTime` um objeto que representa o tempo atual (função de membro estático).|
|[CTime::GetDay](#getday)|Retorna o dia `CTime` representando pelo objeto.|
|[Ctime::GetDayOfWeek](#getdayofweek)|Retorna o dia da semana `CTime` representado pelo objeto.|
|[CTime::GetGmtTm](#getgmttm)|Divide um `CTime` objeto em componentes — com base em UTC.|
|[CTime::getHour](#gethour)|Retorna a hora `CTime` representada pelo objeto.|
|[CTime::GetLocalTm](#getlocaltm)|Divide um `CTime` objeto em componentes — com base no fuso horário local.|
|[CTime::getMinute](#getminute)|Retorna o minuto `CTime` representado pelo objeto.|
|[CTime::getMonth](#getmonth)|Retorna o mês `CTime` representado pelo objeto.|
|[CTime::GetSecond](#getsecond)|Retorna o segundo `CTime` representado pelo objeto.|
|[CTime::getTime](#gettime)|Retorna **__time64_t** um valor __time64_t `CTime` para o objeto dado.|
|[CTime::GetYear](#getyear)|Retorna o ano `CTime` representado pelo objeto.|
|[CTime::Serialize64](#serialize64)|Serializa dados para ou a partir de um arquivo.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador + -](#operator_add_-)|Esses operadores adicionam `CTimeSpan` `CTime` e subtraem objetos.|
|[operador +=, -=](#operator_add_eq_-_eq)|Esses operadores adicionam `CTimeSpan` e subtraem `CTime` um objeto para e a partir deste objeto.|
|[operador =](#operator_eq)|O operador de atribuição.|
|[operador ==, <, etc.](#ctime_comparison_operators)|Operadores de comparação.|

## <a name="remarks"></a>Comentários

`CTime`não tem uma classe base.

`CTime`os valores são baseados no tempo universal coordenado (UTC), que equivale ao tempo universal coordenado (Greenwich Mean Time, GMT). Consulte [o Time Management](../../c-runtime-library/time-management.md) para obter informações sobre como o fuso horário é determinado.

Quando você `CTime` criar um `nDST` objeto, defina o parâmetro para 0 para indicar que o tempo padrão está em vigor, ou para um valor maior que 0 para indicar que o horário de verão está em vigor, ou para um valor menor que zero para que o código de biblioteca de tempo de execução C compor se o horário padrão ou o horário de verão está em vigor. `tm_isdst` é um campo obrigatório. Se não for definido, seu valor é indefinido e o valor de retorno do [mktime](../../c-runtime-library/reference/mktime-mktime32-mktime64.md) é imprevisível. Se `timeptr` aponta para uma estrutura tm retornada por uma chamada `tm_isdst` anterior para [asctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md), [_gmtime_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)ou [localtime_s,](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)o campo contém o valor correto.

Uma classe companheira, [CTimeSpan,](../../atl-mfc-shared/reference/ctimespan-class.md)representa um intervalo de tempo.

As `CTime` `CTimeSpan` classes e não são projetadas para derivação. Como não há funções virtuais, `CTime` `CTimeSpan` o tamanho e objetos são exatamente 8 bytes. A maioria das funções dos membros estão em linha.

> [!NOTE]
> O limite de data superior é 31/12/3000. O limite inferior é 1/1/1970 12:00 AM GMT.

Para obter mais `CTime`informações sobre o uso, consulte os artigos [Data e Hora](../../atl-mfc-shared/date-and-time.md)e Gerenciamento de [Tempo](../../c-runtime-library/time-management.md) na Referência da Biblioteca em Tempo de Execução.

> [!NOTE]
> A `CTime` estrutura passou de MFC 7.1 para MFC 8.0. Se você serializar uma `CTime` estrutura usando o operador ** <<** em MFC 8.0 ou uma versão posterior, o arquivo resultante não será legível em versões mais antigas do MFC.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltime.h

## <a name="ctime-comparison-operators"></a><a name="ctime_comparison_operators"></a>Operadores de comparação de ctime

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

Esses operadores comparam dois tempos absolutos e retornam TRUE se a condição for verdadeira; caso contrário, FALSO.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#161](../../atl-mfc-shared/codesnippet/cpp/ctime-class_1.cpp)]

## <a name="ctimectime"></a><a name="ctime"></a>CTime::CTime

Cria um `CTime` novo objeto inicializado com o tempo especificado.

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
Indica `CTime` um objeto que já existe.

*time*<br/>
Um `__time64_t` valor de tempo, que é o número de segundos após 1 de janeiro de 1970 UTC. Observe que isso será ajustado para o seu horário local. Por exemplo, se você estiver em `CTime` Nova York e criar um objeto passando um parâmetro de 0, [CTime::GetMonth](#getmonth) retornará 12.

*nYear*, *nMonth*, *nDay*, *nHour,* *nMin,* *nSec*<br/>
Indica os valores de data e `CTime` hora a serem copiados para o novo objeto.

*Ndst*<br/>
Indica se o horário de verão está em vigor. Pode ter um dos três valores:

- *nDST* definido como 0Tempo padrão está em vigor.

- *nDST* definido para um valor maior que 0Tempo de poupança está em vigor.

- *nDST* definido como um valor menor que 0O padrão. Calcule automaticamente se o horário padrão ou o horário de verão estão em vigor.

*wDosDate*, *wDostime*<br/>
Os valores de data e hora do MS-DOS a serem `CTime` convertidos em um valor de data/hora e copiados para o novo objeto.

*st*<br/>
Uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) a ser convertida em um valor de `CTime` data/hora e copiada para o novo objeto.

*Ft*<br/>
Uma estrutura [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) a ser convertida em um valor de `CTime` data/hora e copiada para o novo objeto.

*Dbts*<br/>
Uma referência a uma estrutura DBTIMESTAMP contendo a hora local atual.

### <a name="remarks"></a>Comentários

Cada construtor é descrito abaixo:

- `CTime();`Constrói um objeto `CTime` não inicializado. Este construtor permite que `CTime` você defina matrizes de objetos. Você deve inicializar tais matrizes com tempos válidos antes de usar.

- `CTime( const CTime& );`Constrói um `CTime` objeto `CTime` a partir de outro valor.

- `CTime( __time64_t );`Constrói um `CTime` objeto de um **tipo __time64_t.** Este construtor espera um tempo UTC e converte o resultado em um horário local antes de armazenar o resultado.

- `CTime( int, int, ...);`Constrói um `CTime` objeto a partir de componentes de horário local com cada componente restrito às seguintes faixas:

   |Componente|Intervalo|
   |---------------|-----------|
   |*nAno*|1970-3000|
   |*nMês*|1-12|
   |*nDay*|1-31|
   |*nHour*|0-23|
   |*Nmin*|0-59|
   |*Nsec*|0-59|

   Este construtor faz a conversão apropriada para UTC. A versão Debug da Biblioteca de Classes da Microsoft Foundation afirma se um ou mais componentes do tempo estão fora de alcance. Você deve validar os argumentos antes de ligar. Este construtor espera uma hora local.

- `CTime( WORD, WORD );`Constrói um `CTime` objeto a partir dos valores de data e hora do MS-DOS especificados. Este construtor espera uma hora local.

- `CTime( const SYSTEMTIME& );`Constrói um `CTime` objeto `SYSTEMTIME` a partir de uma estrutura. Este construtor espera uma hora local.

- `CTime( const FILETIME& );`Constrói um `CTime` objeto `FILETIME` a partir de uma estrutura. Você provavelmente não `CTime FILETIME` usará a inicialização diretamente. Se você `CFile` usar um objeto `CFile::GetStatus` para manipular um arquivo, recuperará o carimbo de tempo do arquivo para você através de um `CTime` objeto inicializado com uma `FILETIME` estrutura. Este construtor assume um tempo baseado em UTC e converte automaticamente o valor para o horário local antes de armazenar o resultado.

   > [!NOTE]
   > O construtor `DBTIMESTAMP` usando parâmetro só está disponível quando o OLEDB.h estiver incluído.

Para obter mais informações, consulte a estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) e [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) no SDK do Windows. Veja também a entrada [De Data e Hora do MS-DOS](/windows/win32/SysInfo/ms-dos-date-and-time) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#148](../../atl-mfc-shared/codesnippet/cpp/ctime-class_2.cpp)]

## <a name="ctimeformat"></a><a name="format"></a>CTime::Formato

Chame esta função de membro para criar uma representação formatada do valor de data-hora.

```
CString Format(LPCTSTR pszFormat) const;
CString Format(UINT nFormatID) const;
```

### <a name="parameters"></a>Parâmetros

*Pszformat*<br/>
Uma seqüência de `printf` formatação semelhante à seqüência de formatação. Os códigos de formatação,`%`precedidos por um sinal `CTime` de porcentagem () são substituídos pelo componente correspondente. Outros caracteres da seqüência de formatação são copiados inalterados para a seqüência retornada. Consulte o tempo de execução [strftime](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) para obter uma lista de códigos de formatação.

*Nformatid*<br/>
O ID da string que identifica este formato.

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o tempo formatado.

### <a name="remarks"></a>Comentários

Se o status `CTime` deste objeto for nulo, o valor de retorno será uma seqüência de string vazia.

Este método abre uma exceção se o valor de data-hora para o formato não variar de meia-noite, 1 de janeiro de 1970 a 31 de dezembro de 3000 Universal Coordinated Time (UTC).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#149](../../atl-mfc-shared/codesnippet/cpp/ctime-class_3.cpp)]

## <a name="ctimeformatgmt"></a><a name="formatgmt"></a>CTime::FormatGmt

Gera uma seqüência formatada que corresponde a este `CTime` objeto.

```
CString FormatGmt(LPCTSTR pszFormat) const;
CString FormatGmt(UINT nFormatID) const;
```

### <a name="parameters"></a>Parâmetros

*Pszformat*<br/>
Especifica uma seqüência de `printf` formatação semelhante à seqüência de formatação. Consulte o tempo de execução [para obter](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md) detalhes.

*Nformatid*<br/>
O ID da string que identifica este formato.

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o tempo formatado.

### <a name="remarks"></a>Comentários

O valor do tempo não é convertido e, portanto, reflete UTC.

Este método abre uma exceção se o valor de data-hora para o formato não variar de meia-noite, 1 de janeiro de 1970 a 31 de dezembro de 3000 Universal Coordinated Time (UTC).

### <a name="example"></a>Exemplo

Veja o exemplo de [CTime::Format](#format).

## <a name="ctimegetasdbtimestamp"></a><a name="getasdbtimestamp"></a>CTime::GetAsDBTIMESTAMP

Chame esta função de membro para `CTime` converter as informações de tempo armazenadas no objeto para uma estrutura DBTIMESTAMP compatível com Win32.

```
bool GetAsDBTIMESTAMP(DBTIMESTAMP& dbts) const throw();
```

### <a name="parameters"></a>Parâmetros

*Dbts*<br/>
Uma referência a uma estrutura DBTIMESTAMP contendo a hora local atual.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Armazena o tempo resultante na estrutura *dbts* referenciada. A `DBTIMESTAMP` estrutura de dados inicializada `fraction` por esta função terá seu membro definido como zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#150](../../atl-mfc-shared/codesnippet/cpp/ctime-class_4.cpp)]

## <a name="ctimegetassystemtime"></a><a name="getassystemtime"></a>CTime::getAsSystemTime

Chame esta função de membro para `CTime` converter as informações de tempo armazenadas no objeto para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) compatível com Win32.

```
bool GetAsSystemTime(SYSTEMTIME& st) const throw();
```

### <a name="parameters"></a>Parâmetros

*tempoDest*<br/>
Uma referência a uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que manterá o `CTime` valor de data/hora convertido do objeto.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

`GetAsSystemTime`armazena o tempo resultante na estrutura *de dest tempo* referenciado. A `SYSTEMTIME` estrutura de dados inicializada `wMilliseconds` por esta função terá seu membro definido como zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#151](../../atl-mfc-shared/codesnippet/cpp/ctime-class_5.cpp)]

## <a name="ctimegetcurrenttime"></a><a name="getcurrenttime"></a>CTime::getCurrentTime

Retorna `CTime` um objeto que representa o tempo atual.

```
static CTime WINAPI GetCurrentTime() throw();
```

### <a name="remarks"></a>Comentários

Retorna a data e a hora atuais do sistema em Tempo Universal Coordenado (UTC).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#152](../../atl-mfc-shared/codesnippet/cpp/ctime-class_6.cpp)]

## <a name="ctimegetday"></a><a name="getday"></a>CTime::GetDay

Retorna o dia `CTime` representando pelo objeto.

```
int GetDay() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna no dia do mês, com base no horário local, na faixa de 1 a 31.

### <a name="remarks"></a>Comentários

Esta função `GetLocalTm`chama , que usa um buffer interno, estáticamente alocado. Os dados neste buffer são substituídos `CTime` por causa de chamadas para outras funções de membros.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#153](../../atl-mfc-shared/codesnippet/cpp/ctime-class_7.cpp)]

## <a name="ctimegetdayofweek"></a><a name="getdayofweek"></a>Ctime::GetDayOfWeek

Retorna o dia da semana `CTime` representado pelo objeto.

```
int GetDayOfWeek() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o dia da semana com base no horário local; 1 = Domingo, 2 = Segunda- feira, a 7 = Sábado.

### <a name="remarks"></a>Comentários

Esta função `GetLocalTm`chama , que usa um buffer localizado estáticamente interno. Os dados neste buffer são substituídos `CTime` por causa de chamadas para outras funções de membros.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#154](../../atl-mfc-shared/codesnippet/cpp/ctime-class_8.cpp)]

## <a name="ctimegetgmttm"></a><a name="getgmttm"></a>CTime::GetGmtTm

Obtém uma **estrutura tm** que contém uma decomposição `CTime` do tempo contido neste objeto.

```
struct tm* GetGmtTm(struct tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Ptm*<br/>
Aponta para um buffer que receberá os dados de tempo. Se este ponteiro for NULO, uma exceção será lançada.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura de **struct** preenchida tm conforme definido no arquivo INCLUIR TIME. H. Veja [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) para o layout da estrutura.

### <a name="remarks"></a>Comentários

`GetGmtTm`retorna UTC.

*ptm* não pode ser NULO. Se você quiser reverter para o comportamento antigo, no qual *ptm* poderia ser NULL para indicar que um buffer interno, estáticamente alocado deve ser usado, então desdefinir _SECURE_ATL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#155](../../atl-mfc-shared/codesnippet/cpp/ctime-class_9.cpp)]

## <a name="ctimegethour"></a><a name="gethour"></a>CTime::getHour

Retorna a hora `CTime` representada pelo objeto.

```
int GetHour() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a hora, com base no horário local, na faixa de 0 a 23.

### <a name="remarks"></a>Comentários

Esta função `GetLocalTm`chama , que usa um buffer localizado estáticamente interno. Os dados neste buffer são substituídos `CTime` por causa de chamadas para outras funções de membros.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#156](../../atl-mfc-shared/codesnippet/cpp/ctime-class_10.cpp)]

## <a name="ctimegetlocaltm"></a><a name="getlocaltm"></a>CTime::GetLocalTm

Obtém uma **estrutura tm** contendo uma decomposição do `CTime` tempo contido neste objeto.

```
struct tm* GetLocalTm(struct tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Ptm*<br/>
Aponta para um buffer que receberá os dados de tempo. Se este ponteiro for NULO, uma exceção será lançada.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura de **struct** preenchida tm conforme definido no arquivo INCLUIR TIME. H. Veja [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) para o layout da estrutura.

### <a name="remarks"></a>Comentários

`GetLocalTm`retorna no horário local.

*ptm* não pode ser NULO. Se você quiser reverter para o comportamento antigo, no qual *ptm* poderia ser NULL para indicar que um buffer interno, estáticamente alocado deve ser usado, então desdefinir _SECURE_ATL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#157](../../atl-mfc-shared/codesnippet/cpp/ctime-class_11.cpp)]

## <a name="ctimegetminute"></a><a name="getminute"></a>CTime::getMinute

Retorna o minuto `CTime` representado pelo objeto.

```
int GetMinute() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o minuto, com base no horário local, na faixa de 0 a 59.

### <a name="remarks"></a>Comentários

Esta função `GetLocalTm`chama , que usa um buffer localizado estáticamente interno. Os dados neste buffer são substituídos `CTime` por causa de chamadas para outras funções de membros.

### <a name="example"></a>Exemplo

Veja o exemplo de [GetHour](#gethour).

## <a name="ctimegetmonth"></a><a name="getmonth"></a>CTime::getMonth

Retorna o mês `CTime` representado pelo objeto.

```
int GetMonth() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o mês, com base no horário local, na faixa de 1 a 12 (1 = janeiro).

### <a name="remarks"></a>Comentários

Esta função `GetLocalTm`chama , que usa um buffer localizado estáticamente interno. Os dados neste buffer são substituídos `CTime` por causa de chamadas para outras funções de membros.

### <a name="example"></a>Exemplo

Veja o exemplo de [GetDay](#getday).

## <a name="ctimegetsecond"></a><a name="getsecond"></a>CTime::GetSecond

Retorna o segundo `CTime` representado pelo objeto.

```
int GetSecond() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o segundo, baseado no horário local, na faixa de 0 a 59.

### <a name="remarks"></a>Comentários

Esta função `GetLocalTm`chama , que usa um buffer localizado estáticamente interno. Os dados neste buffer são substituídos `CTime` por causa de chamadas para outras funções de membros.

### <a name="example"></a>Exemplo

Veja o exemplo de [GetHour](#gethour).

## <a name="ctimegettime"></a><a name="gettime"></a>CTime::getTime

Retorna **__time64_t** um valor __time64_t `CTime` para o objeto dado.

```
__time64_t GetTime() const throw();
```

### <a name="return-value"></a>Valor retornado

`GetTime`retornará o número de `CTime` segundos entre o objeto atual e 1 º de janeiro de 1970.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#158](../../atl-mfc-shared/codesnippet/cpp/ctime-class_12.cpp)]

## <a name="ctimegetyear"></a><a name="getyear"></a>CTime::GetYear

Retorna o ano `CTime` representado pelo objeto.

```
int GetYear();
```

### <a name="return-value"></a>Valor retornado

Retorna o ano, com base no horário local, na faixa de 1,1970 de janeiro de 2070, a 18 de janeiro de 2038 (inclusive).

### <a name="remarks"></a>Comentários

Esta função `GetLocalTm`chama , que usa um buffer localizado estáticamente interno. Os dados neste buffer são substituídos `CTime` por causa de chamadas para outras funções de membros.

### <a name="example"></a>Exemplo

Veja o exemplo de [GetDay](#getday).

## <a name="ctimeoperator-"></a><a name="operator_eq"></a>CTime::operador =

O operador de atribuição.

```
CTime& operator=(__time64_t time) throw();
```

### <a name="parameters"></a>Parâmetros

*time*<br/>
O novo valor de data/hora.

### <a name="return-value"></a>Valor retornado

O `CTime` objeto atualizado.

### <a name="remarks"></a>Comentários

Este operador de atribuição sobrecarregado `CTime` copia o tempo de origem para este objeto. O armazenamento de `CTime` tempo interno em um objeto é independente do fuso horário. A conversão de fuso horário não é necessária durante a atribuição.

## <a name="ctimeoperator---"></a><a name="operator_add_-"></a>CTime::operador +, -

Esses operadores adicionam `CTimeSpan` `CTime` e subtraem objetos.

```
CTime operator+(CTimeSpan timeSpan) const throw();
CTime operator-(CTimeSpan timeSpan) const throw();
CTimeSpan operator-(CTime time) const throw();
```

### <a name="parameters"></a>Parâmetros

*Timespan*<br/>
O `CTimeSpan` objeto a ser adicionado ou subtraído.

*time*<br/>
O `CTime` objeto a ser subtraído.

### <a name="return-value"></a>Valor retornado

Um `CTime` `CTimeSpan` ou objeto representando o resultado da operação.

### <a name="remarks"></a>Comentários

`CTime`objetos representam `CTimeSpan` tempo absoluto, objetos representam tempo relativo. Os dois primeiros operadores permitem adicionar `CTimeSpan` e subtrair objetos de `CTime` e para objetos. O terceiro operador permite que `CTime` você subtraia `CTimeSpan` um objeto de outro para produzir um objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#159](../../atl-mfc-shared/codesnippet/cpp/ctime-class_13.cpp)]

## <a name="ctimeoperator---"></a><a name="operator_add_eq_-_eq"></a>CTime::operador +=, -=

Esses operadores adicionam `CTimeSpan` e subtraem `CTime` um objeto para e a partir deste objeto.

```
CTime& operator+=(CTimeSpan span) throw();
CTime& operator-=(CTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*Span*<br/>
O `CTimeSpan` objeto a ser adicionado ou subtraído.

### <a name="return-value"></a>Valor retornado

O `CTime` objeto atualizado.

### <a name="remarks"></a>Comentários

Esses operadores permitem que você `CTimeSpan` adicione e subtraia um objeto para e a partir deste `CTime` objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#160](../../atl-mfc-shared/codesnippet/cpp/ctime-class_14.cpp)]

## <a name="ctimeserialize64"></a><a name="serialize64"></a>CTime::Serialize64

> [!NOTE]
> Este método só está disponível em projetos de MFC.

Serializa os dados associados à variável membro para ou a partir de um arquivo.

```
CArchive& Serialize64(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
O `CArchive` objeto que você deseja atualizar.

### <a name="return-value"></a>Valor retornado

O `CArchive` objeto atualizado.

## <a name="see-also"></a>Confira também

[asctime_s, _wasctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)<br/>
[_ftime_s, _ftime32_s, _ftime64_s](../../c-runtime-library/reference/ftime-s-ftime32-s-ftime64-s.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)<br/>
[strftime, wcsftime, _strftime_l, _wcsftime_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)<br/>
[time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)<br/>
[Classe CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
