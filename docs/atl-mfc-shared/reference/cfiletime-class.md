---
title: Classe CFileTime
ms.date: 10/18/2018
f1_keywords:
- CFileTime
- ATLTIME/ATL::CFileTime
- ATLTIME/ATL::CFileTime::CFileTime
- ATLTIME/ATL::CFileTime::GetCurrentTime
- ATLTIME/ATL::CFileTime::GetTime
- ATLTIME/ATL::CFileTime::LocalToUTC
- ATLTIME/ATL::CFileTime::SetTime
- ATLTIME/ATL::CFileTime::UTCToLocal
- ATLTIME/ATL::CFileTime::Day
- ATLTIME/ATL::CFileTime::Hour
- ATLTIME/ATL::CFileTime::Millisecond
- ATLTIME/ATL::CFileTime::Minute
- ATLTIME/ATL::CFileTime::Second
- ATLTIME/ATL::CFileTime::Week
helpviewer_keywords:
- CFileTime class
- shared classes, CFileTime
ms.assetid: 1a358a65-1383-4124-b0d4-59b026e6860f
ms.openlocfilehash: fd19d941365c7772363417ce3e9225bd9b0300b2
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748845"
---
# <a name="cfiletime-class"></a>Classe CFileTime

Esta classe fornece métodos para gerenciar os valores de data e hora associados a um arquivo.

## <a name="syntax"></a>Sintaxe

```
class CFileTime :  public FILETIME
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTime::CFileTime](#cfiletime)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTime::getCurrentTime](#getcurrenttime)|Chame esta função estática para recuperar um `CFileTime` objeto que representa a data e a hora atuais do sistema.|
|[CFileTime::getTime](#gettime)|Chame este método para recuperar `CFileTime` o tempo do objeto.|
|[CFileTime::LocalToUTC](#localtoutc)|Chame este método para converter um tempo de arquivo local para um tempo de arquivo com base no Tempo Universal Coordenado (UTC).|
|[CFileTime::SetTime](#settime)|Chame este método para definir a `CFileTime` data e a hora armazenadas pelo objeto.|
|[CFileTime::UTCToLocal](#utctolocal)|Chame este método para converter o tempo com base no Tempo Universal Coordenado (UTC) para o tempo de arquivo local.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTime::operador -](#operator_-)|Este operador é usado para `CFileTime` executar `CFileTimeSpan` subtração em um ou objeto.|
|[CFileTime::operador !=](#operator_neq)|Este operador compara dois `CFileTime` objetos à desigualdade.|
|[CFileTime::operador +](#operator_add)|Este operador é usado para `CFileTimeSpan` executar a adição em um objeto.|
|[CFileTime::operador +=](#operator_add_eq)|Este operador é usado para `CFileTimeSpan` executar a adição em um objeto e atribuir o resultado ao objeto atual.|
|[CFileTime::operador&lt;](#operator_lt)|Este operador compara dois `CFileTime` objetos para determinar o menor.|
|[CFileTime::operador&lt;=](#operator_lt_eq)|Este operador compara dois `CFileTime` objetos para determinar a igualdade ou o menor.|
|[CFileTime::operador =](#operator_eq)|O operador de atribuição.|
|[CFileTime::operador -=](#operator_-_eq)|Este operador é usado para `CFileTimeSpan` executar subtração em um objeto e atribuir o resultado ao objeto atual.|
|[CFileTime::operador ==](#operator_eq_eq)|Este operador compara dois `CFileTime` objetos para a igualdade.|
|[CFileTime::operador&gt;](#operator_gt)|Este operador compara dois `CFileTime` objetos para determinar o maior.|
|[CFileTime::operador&gt;=](#operator_gt_eq)|Este operador compara dois `CFileTime` objetos para determinar a igualdade ou o maior.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[CFileTime::Day](#day)|Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem um dia.|
|[CFileTime::Hora](#hour)|Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem uma hora.|
|[CFileTime::Milissegundo](#millisecond)|Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem um milissegundo.|
|[CFileTime::Minute](#minute)|Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem um minuto.|
|[CFileTime::Segundo](#second)|Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem um segundo.|
|[CFileTime::Semana](#week)|Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem uma semana.|

## <a name="remarks"></a>Comentários

Esta classe fornece métodos para gerenciar os valores de data e hora associados à criação, acesso e modificação de arquivos. Os métodos e dados desta classe são `CFileTimeSpan` frequentemente usados em conjunto com objetos, que lidam com valores de tempo relativos.

O valor de data e hora é armazenado como um valor de 64 bits representando o número de intervalos de 100 nanossegundos desde 1 de janeiro de 1601. Este é o formato Tempo Universal Coordenado (UTC).

As seguintes variáveis de membros do const estático são fornecidas para simplificar os cálculos:

|Variável de membro|Número de intervalos de 100 nanossegundos|
|---------------------|-----------------------------------------|
|Milissegundos|10.000|
|Segundo|Milissegundos \* 1.000|
|Minuto|Segundo \* 60|
|Hora|Minuto \* 60|
|Dia|Hora \* 24|
|Semana|Dia \* 7.|

**Nota** Nem todos os sistemas de arquivos podem registrar a criação e o tempo de acesso da última vez e nem todos os sistemas de arquivos os registram da mesma maneira. Por exemplo, no sistema de arquivos WINDOWS NT FAT, o tempo de criação tem uma resolução de 10 milissegundos, o tempo de gravação tem uma resolução de 2 segundos e o tempo de acesso tem uma resolução de 1 dia (a data de acesso). No NTFS, o tempo de acesso tem uma resolução de 1 hora. Além disso, o FAT registra tempos em disco em tempo local, mas o NTFS registra os tempos em disco em UTC. Para obter mais informações, consulte [File Times](/windows/win32/SysInfo/file-times).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`FILETIME`

`CFileTime`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltime.h

## <a name="cfiletimecfiletime"></a><a name="cfiletime"></a>CFileTime::CFileTime

O construtor.

```
CFileTime() throw();
CFileTime(const FILETIME& ft) throw();
CFileTime(ULONGLONG nTime) throw();
```

### <a name="parameters"></a>Parâmetros

*Ft*<br/>
Uma estrutura [FILETIME.](/windows/win32/api/minwinbase/ns-minwinbase-filetime)

*Ntime*<br/>
A data e a hora expressas como um valor de 64 bits.

### <a name="remarks"></a>Comentários

O `CFileTime` objeto pode ser criado usando uma data `FILETIME` e hora existentes a partir de uma estrutura, ou expresso como um valor de 64 bits (em formatos de tempo local ou coordenado de Tempo Universal (UTC). O construtor padrão define o tempo para 0.

## <a name="cfiletimeday"></a><a name="day"></a>CFileTime::Day

Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem um dia.

```
static const ULONGLONG Day = Hour* 24;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

## <a name="cfiletimegetcurrenttime"></a><a name="getcurrenttime"></a>CFileTime::getCurrentTime

Chame esta função estática para recuperar um `CFileTime` objeto que representa a data e a hora atuais do sistema.

```
static CFileTime GetCurrentTime() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a data e a hora atuais do sistema no formato UTC (Coordinated Universal Time, tempo universal coordenado).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#41](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_1.cpp)]

## <a name="cfiletimegettime"></a><a name="gettime"></a>CFileTime::getTime

Chame este método para recuperar `CFileTime` o tempo do objeto.

```
ULONGLONG GetTime() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a data e a hora como um número de 64 bits, que pode estar no formato UTC (Local ou Coordinated Universal Time, hora universal coordenada).

## <a name="cfiletimehour"></a><a name="hour"></a>CFileTime::Hora

Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem uma hora.

```
static const ULONGLONG Hour = Minute* 60;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

## <a name="cfiletimelocaltoutc"></a><a name="localtoutc"></a>CFileTime::LocalToUTC

Chame este método para converter um tempo de arquivo local para um tempo de arquivo com base no Tempo Universal Coordenado (UTC).

```
CFileTime LocalToUTC() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna `CFileTime` um objeto contendo o tempo no formato UTC.

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::UTCToLocal](#utctolocal).

## <a name="cfiletimemillisecond"></a><a name="millisecond"></a>CFileTime::Milissegundo

Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem um milissegundo.

```
static const ULONGLONG Millisecond = 10000;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#44](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_2.cpp)]

## <a name="cfiletimeminute"></a><a name="minute"></a>CFileTime::Minute

Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem um minuto.

```
static const ULONGLONG Minute = Second* 60;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

## <a name="cfiletimeoperator--"></a><a name="operator_-"></a>CFileTime::operador -

Este operador é usado para `CFileTime` executar `CFileTimeSpan` subtração em um ou objeto.

```
CFileTime operator-(CFileTimeSpan span) const throw();
CFileTimeSpan operator-(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*<br/>
Um objeto `CFileTimeSpan` .

*Ft*<br/>
Um objeto `CFileTime` .

### <a name="return-value"></a>Valor retornado

Retorna `CFileTime` um objeto `CFileTimeSpan` ou um objeto representando o resultado da diferença de tempo entre os dois objetos.

## <a name="cfiletimeoperator-"></a><a name="operator_neq"></a>CFileTime::operador !=

Este operador compara dois `CFileTime` objetos à desigualdade.

```
bool operator!=(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o item que `CFileTime` está sendo comparado não for igual ao objeto, caso contrário, FALSO.

## <a name="cfiletimeoperator-"></a><a name="operator_add"></a>CFileTime::operador +

Este operador é usado para `CFileTimeSpan` executar a adição em um objeto.

```
CFileTime operator+(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*<br/>
Um objeto `CFileTimeSpan` .

### <a name="return-value"></a>Valor retornado

Retorna `CFileTime` um objeto representando o resultado do tempo original mais um tempo relativo.

## <a name="cfiletimeoperator-"></a><a name="operator_add_eq"></a>CFileTime::operador +=

Este operador é usado para `CFileTimeSpan` executar a adição em um objeto e atribuir o resultado ao objeto atual.

```
CFileTime& operator+=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*Span*<br/>
Um objeto `CFileTimeSpan` .

### <a name="return-value"></a>Valor retornado

Retorna o `CFileTime` objeto atualizado, representando o resultado do tempo original mais um tempo relativo.

## <a name="cfiletimeoperator-lt"></a><a name="operator_lt"></a>CFileTime::operador&lt;

Este operador compara dois `CFileTime` objetos para determinar o menor.

```
bool operator<(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for menor (mais cedo no tempo) do que o segundo, FALSO de outra forma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#43](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_3.cpp)]

## <a name="cfiletimeoperator-lt"></a><a name="operator_lt_eq"></a>CFileTime::operador&lt;=

Este operador compara dois `CFileTime` objetos para determinar a igualdade ou o menor.

```
bool operator<=(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for menor do que (anteriormente) ou igual ao segundo, caso contrário, FALSO.

## <a name="cfiletimeoperator-"></a><a name="operator_eq"></a>CFileTime::operador =

O operador de atribuição.

```
CFileTime& operator=(const FILETIME& ft) throw();
```

### <a name="parameters"></a>Parâmetros

*Ft*<br/>
Um `CFileTime` objeto contendo a nova hora e data.

### <a name="return-value"></a>Valor retornado

Retorna o `CFileTime` objeto atualizado.

## <a name="cfiletimeoperator--"></a><a name="operator_-_eq"></a>CFileTime::operador -=

Este operador é usado para `CFileTimeSpan` executar subtração em um objeto e atribuir o resultado ao objeto atual.

```
CFileTime& operator-=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*Span*<br/>
Um `CFileTimeSpan` objeto contendo o tempo relativo para subtrair.

### <a name="return-value"></a>Valor retornado

Retorna o `CFileTime` objeto atualizado.

## <a name="cfiletimeoperator-"></a><a name="operator_eq_eq"></a>CFileTime::operador ==

Este operador compara dois `CFileTime` objetos para a igualdade.

```
bool operator==(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se os objetos forem iguais, caso contrário, FALSO.

## <a name="cfiletimeoperator-gt"></a><a name="operator_gt"></a>CFileTime::operador&gt;

Este operador compara dois `CFileTime` objetos para determinar o maior.

```
bool operator>(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for maior do que (mais tarde no tempo) do que o segundo, caso contrário, FALSO.

## <a name="cfiletimeoperator-gt"></a><a name="operator_gt_eq"></a>CFileTime::operador&gt;=

Este operador compara dois `CFileTime` objetos para determinar a igualdade ou o maior.

```
bool operator>=(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o primeiro objeto for maior do que (mais tarde no tempo) ou igual ao segundo, caso contrário, FALSO.

## <a name="cfiletimesecond"></a><a name="second"></a>CFileTime::Segundo

Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem um dia.

```
static const ULONGLONG Second = Millisecond* 1000;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

## <a name="cfiletimesettime"></a><a name="settime"></a>CFileTime::SetTime

Chame este método para definir a `CFileTime` data e a hora armazenadas pelo objeto.

```cpp
void SetTime(ULONGLONG nTime) throw();
```

### <a name="parameters"></a>Parâmetros

*Ntime*<br/>
O valor de 64 bits representando a data e a hora, no formato UTC (Local ou Coordinated Universal Time, hora universal coordenada).

## <a name="cfiletimeutctolocal"></a><a name="utctolocal"></a>CFileTime::UTCToLocal

Chame este método para converter o tempo com base no Tempo Universal Coordenado (UTC) para o tempo de arquivo local.

```
CFileTime UTCToLocal() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna `CFileTime` um objeto contendo o tempo no formato de tempo do arquivo local.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#42](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_4.cpp)]

## <a name="cfiletimeweek"></a><a name="week"></a>CFileTime::Semana

Um membro de dados estático armazenando o número de intervalos de 100 nanossegundos que compõem uma semana.

```
static const ULONGLONG Week = Day* 7;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

## <a name="see-also"></a>Confira também

[FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime)<br/>
[Classe CFileTimeSpan](../../atl-mfc-shared/reference/cfiletimespan-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
