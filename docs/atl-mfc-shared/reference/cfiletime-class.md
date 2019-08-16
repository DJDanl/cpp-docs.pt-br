---
title: Classe de testcfiletime
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
ms.openlocfilehash: b24d1e4d3e670a820c41735617b7db6780ff137c
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491478"
---
# <a name="cfiletime-class"></a>Classe de testcfiletime

Essa classe fornece métodos para gerenciar os valores de data e hora associados a um arquivo.

## <a name="syntax"></a>Sintaxe

```
class CFileTime :  public FILETIME
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Testcfiletime:: recfiletime](#cfiletime)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTime::GetCurrentTime](#getcurrenttime)|Chame essa função estática para recuperar um `CFileTime` objeto que representa a data e a hora atuais do sistema.|
|[CFileTime::GetTime](#gettime)|Chame esse método para recuperar a hora do `CFileTime` objeto.|
|[CFileTime::LocalToUTC](#localtoutc)|Chame esse método para converter uma hora de arquivo local em uma hora de arquivo com base no tempo universal coordenado (UTC).|
|[CFileTime::SetTime](#settime)|Chame esse método para definir a data e a hora armazenadas pelo `CFileTime` objeto.|
|[CFileTime::UTCToLocal](#utctolocal)|Chame esse método para converter a hora com base no tempo universal coordenado (UTC) para o arquivo local.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Testcfiletime:: operador-](#operator_-)|Esse operador é usado para executar a subtração em `CFileTime` um `CFileTimeSpan` objeto ou.|
|[Testcfiletime:: operador! =](#operator_neq)|Esse operador compara dois `CFileTime` objetos para desigualdade.|
|[Testcfiletime:: operador +](#operator_add)|Esse operador é usado para executar adição em um `CFileTimeSpan` objeto.|
|[Testcfiletime:: operador + =](#operator_add_eq)|Esse operador é usado para executar adição em um `CFileTimeSpan` objeto e atribuir o resultado ao objeto atual.|
|[Recfiletime:: operador&lt;](#operator_lt)|Esse operador compara dois `CFileTime` objetos para determinar o menor.|
|[Recfiletime:: operador&lt;=](#operator_lt_eq)|Esse operador compara dois `CFileTime` objetos para determinar a igualdade ou o menor.|
|[Testcfiletime:: operador =](#operator_eq)|O operador de atribuição.|
|[Testcfiletime:: operador-=](#operator_-_eq)|Esse operador é usado para executar a subtração em `CFileTimeSpan` um objeto e atribuir o resultado ao objeto atual.|
|[Testcfiletime:: operador = =](#operator_eq_eq)|Esse operador compara dois `CFileTime` objetos para igualdade.|
|[Recfiletime:: operador&gt;](#operator_gt)|Esse operador compara dois `CFileTime` objetos para determinar o maior.|
|[Recfiletime:: operador&gt;=](#operator_gt_eq)|Esse operador compara dois `CFileTime` objetos para determinar a igualdade ou maior.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Recfiletime::D](#day)|Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem um dia.|
|[CFileTime::Hour](#hour)|Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem uma hora.|
|[CFileTime::Millisecond](#millisecond)|Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem um milissegundo.|
|[Recfiletime:: minuto](#minute)|Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem um minuto.|
|[CFileTime::Second](#second)|Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem um segundo.|
|[Testcfiletime:: semana](#week)|Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem uma semana.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para gerenciar os valores de data e hora associados à criação, ao acesso e à modificação de arquivos. Os métodos e os dados dessa classe são frequentemente usados em conjunto com `CFileTimeSpan` objetos, que lidam com valores de tempo relativos.

O valor de data e hora é armazenado como um valor de 64 bits que representa o número de intervalos de 100 nanossegundos desde 1º de janeiro de 1601. Este é o formato UTC (tempo Universal Coordenado).

As variáveis de membro const estáticos a seguir são fornecidas para simplificar os cálculos:

|Variável de membro|Número de intervalos de 100 a nanossegundos|
|---------------------|-----------------------------------------|
|Milissegundo|10.000|
|Segundo|Milissegundo \* 1.000|
|Minuto|Segundo \* 60|
|Hora|Minuto \* 60|
|Day|Hora \* 24|
|Emana|Dia \* 7|

**Observação** Nem todos os sistemas de arquivos podem registrar a criação e o último tempo de acesso, e nem todos os sistemas de arquivos os registram da mesma maneira. Por exemplo, no sistema de arquivos FAT do Windows NT, a criação de tempo tem uma resolução de 10 milissegundos, o tempo de gravação tem uma resolução de 2 segundos e o tempo de acesso tem uma resolução de 1 dia (a data de acesso). No NTFS, o tempo de acesso tem uma resolução de 1 hora. Além disso, o FAT registra os horários no disco na hora local, mas o NTFS registra os horários em disco em UTC. Para obter mais informações, consulte [horas de arquivo](/windows/win32/SysInfo/file-times).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`FILETIME`

`CFileTime`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltime. h

##  <a name="cfiletime"></a>Testcfiletime:: recfiletime

O construtor.

```
CFileTime() throw();
CFileTime(const FILETIME& ft) throw();
CFileTime(ULONGLONG nTime) throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
Uma estrutura [FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime) .

*nTime*<br/>
A data e a hora expressas como um valor de 64 bits.

### <a name="remarks"></a>Comentários

O `CFileTime` objeto pode ser criado usando uma data e hora existentes de uma `FILETIME` estrutura, ou expresso como um valor de 64 bits (em formatos de hora UTC (tempo universal) e local ou coordenado). O construtor padrão define o tempo como 0.

##  <a name="day"></a>Recfiletime::D

Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem um dia.

```
static const ULONGLONG Day = Hour* 24;
```

### <a name="example"></a>Exemplo

Consulte o exemplo de [Testcfiletime:: milissegundo](#millisecond).

##  <a name="getcurrenttime"></a>  CFileTime::GetCurrentTime

Chame essa função estática para recuperar um `CFileTime` objeto que representa a data e a hora atuais do sistema.

```
static CFileTime GetCurrentTime() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a data e a hora atuais do sistema no formato UTC (tempo Universal Coordenado).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#41](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_1.cpp)]

##  <a name="gettime"></a>  CFileTime::GetTime

Chame esse método para recuperar a hora do `CFileTime` objeto.

```
ULONGLONG GetTime() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a data e a hora como um número de 64 bits, que pode estar no formato UTC (tempo Universal Coordenado) ou local.

##  <a name="hour"></a>  CFileTime::Hour

Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem uma hora.

```
static const ULONGLONG Hour = Minute* 60;
```

### <a name="example"></a>Exemplo

Consulte o exemplo de [Testcfiletime:: milissegundo](#millisecond).

##  <a name="localtoutc"></a>  CFileTime::LocalToUTC

Chame esse método para converter uma hora de arquivo local em uma hora de arquivo com base no tempo universal coordenado (UTC).

```
CFileTime LocalToUTC() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTime` objeto que contém a hora no formato UTC.

### <a name="example"></a>Exemplo

Consulte o exemplo de [Testcfiletime:: UTCToLocal](#utctolocal).

##  <a name="millisecond"></a>Testcfiletime:: milissegundo

Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem um milissegundo.

```
static const ULONGLONG Millisecond = 10000;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#44](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_2.cpp)]

##  <a name="minute"></a>Recfiletime:: minuto

Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem um minuto.

```
static const ULONGLONG Minute = Second* 60;
```

### <a name="example"></a>Exemplo

Consulte o exemplo de [Testcfiletime:: milissegundo](#millisecond).

##  <a name="operator_-"></a>Testcfiletime:: operador-

Esse operador é usado para executar a subtração em `CFileTime` um `CFileTimeSpan` objeto ou.

```
CFileTime operator-(CFileTimeSpan span) const throw();
CFileTimeSpan operator-(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

*ft*<br/>
Um objeto `CFileTime`.

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTime` objeto ou um `CFileTimeSpan` objeto que representa o resultado da diferença de tempo entre os dois objetos.

##  <a name="operator_neq"></a>Testcfiletime:: operador! =

Esse operador compara dois `CFileTime` objetos para desigualdade.

```
bool operator!=(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará true se o item que está sendo comparado não for igual `CFileTime` ao objeto, caso contrário, false.

##  <a name="operator_add"></a>Testcfiletime:: operador +

Esse operador é usado para executar adição em um `CFileTimeSpan` objeto.

```
CFileTime operator+(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTime` objeto que representa o resultado da hora original mais uma hora relativa.

##  <a name="operator_add_eq"></a>Testcfiletime:: operador + =

Esse operador é usado para executar adição em um `CFileTimeSpan` objeto e atribuir o resultado ao objeto atual.

```
CFileTime& operator+=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CFileTime` atualizado, representando o resultado da hora original mais uma hora relativa.

##  <a name="operator_lt"></a>Recfiletime:: operador&lt;

Esse operador compara dois `CFileTime` objetos para determinar o menor.

```
bool operator<(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o primeiro objeto for menor (antes do tempo) do que o segundo; caso contrário, FALSE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#43](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_3.cpp)]

##  <a name="operator_lt_eq"></a>Recfiletime:: operador&lt;=

Esse operador compara dois `CFileTime` objetos para determinar a igualdade ou o menor.

```
bool operator<=(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o primeiro objeto for menor que (antes do tempo) ou igual ao segundo, caso contrário, FALSE.

##  <a name="operator_eq"></a>Testcfiletime:: operador =

O operador de atribuição.

```
CFileTime& operator=(const FILETIME& ft) throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
Um `CFileTime` objeto que contém a nova data e hora.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CFileTime` atualizado.

##  <a name="operator_-_eq"></a>Testcfiletime:: operador-=

Esse operador é usado para executar a subtração em `CFileTimeSpan` um objeto e atribuir o resultado ao objeto atual.

```
CFileTime& operator-=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um `CFileTimeSpan` objeto que contém o tempo relativo a ser subtraído.

### <a name="return-value"></a>Valor de retorno

Retorna o objeto `CFileTime` atualizado.

##  <a name="operator_eq_eq"></a>Testcfiletime:: operador = =

Esse operador compara dois `CFileTime` objetos para igualdade.

```
bool operator==(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se os objetos forem iguais; caso contrário, FALSE.

##  <a name="operator_gt"></a>Recfiletime:: operador&gt;

Esse operador compara dois `CFileTime` objetos para determinar o maior.

```
bool operator>(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o primeiro objeto for maior que (mais tarde no tempo) do que o segundo; caso contrário, FALSE.

##  <a name="operator_gt_eq"></a>Recfiletime:: operador&gt;=

Esse operador compara dois `CFileTime` objetos para determinar a igualdade ou maior.

```
bool operator>=(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o primeiro objeto for maior que (mais tarde no tempo) ou igual ao segundo, caso contrário, FALSE.

##  <a name="second"></a>  CFileTime::Second

Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem um dia.

```
static const ULONGLONG Second = Millisecond* 1000;
```

### <a name="example"></a>Exemplo

Consulte o exemplo de [Testcfiletime:: milissegundo](#millisecond).

##  <a name="settime"></a>  CFileTime::SetTime

Chame esse método para definir a data e a hora armazenadas pelo `CFileTime` objeto.

```
void SetTime(ULONGLONG nTime) throw();
```

### <a name="parameters"></a>Parâmetros

*nTime*<br/>
O valor de 64 bits que representa a data e a hora, no formato local ou UTC (tempo Universal Coordenado).

##  <a name="utctolocal"></a>  CFileTime::UTCToLocal

Chame esse método para converter a hora com base no tempo universal coordenado (UTC) para o arquivo local.

```
CFileTime UTCToLocal() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTime` objeto que contém a hora no formato de hora do arquivo local.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#42](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_4.cpp)]

##  <a name="week"></a>  CFileTime::Week

Um membro de dados estáticos que armazena o número de intervalos de 100 a nanossegundos que compõem uma semana.

```
static const ULONGLONG Week = Day* 7;
```

### <a name="example"></a>Exemplo

Consulte o exemplo de [Testcfiletime:: milissegundo](#millisecond).

## <a name="see-also"></a>Consulte também

[FILETIME](/windows/win32/api/minwinbase/ns-minwinbase-filetime)<br/>
[Classe CFileTimeSpan](../../atl-mfc-shared/reference/cfiletimespan-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
