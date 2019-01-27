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
ms.openlocfilehash: 42c89bcfa064bbb151f9d110cbd25763dbd44185
ms.sourcegitcommit: c85c8a1226d8fbbaa29f4691ed719f8e6cc6575c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/24/2019
ms.locfileid: "54893932"
---
# <a name="cfiletime-class"></a>Classe CFileTime

Essa classe fornece métodos para gerenciar os valores de data e hora associados a um arquivo.

## <a name="syntax"></a>Sintaxe

```
class CFileTime :  public FILETIME
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTime::CFileTime](#cfiletime)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTime::GetCurrentTime](#getcurrenttime)|Chame essa função estática para recuperar um `CFileTime` objeto que representa a data atual do sistema e a hora.|
|[CFileTime::GetTime](#gettime)|Chame esse método para recuperar o tempo desde o `CFileTime` objeto.|
|[CFileTime::LocalToUTC](#localtoutc)|Chame esse método para converter uma hora de arquivo local em uma hora de arquivo com base no tempo Universal Coordenado (UTC).|
|[CFileTime::SetTime](#settime)|Chame esse método para definir a data e hora armazenados pelo `CFileTime` objeto.|
|[CFileTime::UTCToLocal](#utctolocal)|Chame esse método para converter a hora com base no tempo Universal Coordenado (UTC) para o horário de arquivo local.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CFileTime::operator-](#operator_-)|Esse operador é usado para realizar a subtração em um `CFileTime` ou `CFileTimeSpan` objeto.|
|[CFileTime::operator! =](#operator_neq)|Esse operador compara dois `CFileTime` objetos quanto à desigualdade.|
|[CFileTime::operator +](#operator_add)|Esse operador é usado para executar uma adição em um `CFileTimeSpan` objeto.|
|[+ CFileTime::operator =](#operator_add_eq)|Esse operador é usado para executar uma adição em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.|
|[CFileTime::operator &lt;](#operator_lt)|Esse operador compara dois `CFileTime` objetos para determinar o menor.|
|[CFileTime::operator &lt;=](#operator_lt_eq)|Esse operador compara dois `CFileTime` objetos para determinar igualdade ou o menor.|
|[CFileTime::operator =](#operator_eq)|O operador de atribuição.|
|[CFileTime::operator =](#operator_-_eq)|Esse operador é usado para realizar a subtração em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.|
|[CFileTime::operator ==](#operator_eq_eq)|Esse operador compara dois `CFileTime` objetos quanto à igualdade.|
|[CFileTime::operator &gt;](#operator_gt)|Esse operador compara dois `CFileTime` objetos para determinar o maior.|
|[CFileTime::operator &gt;=](#operator_gt_eq)|Esse operador compara dois `CFileTime` objetos para determinar igualdade ou maior.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[CFileTime::Day](#day)|Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem um dia.|
|[CFileTime::Hour](#hour)|Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem uma hora.|
|[CFileTime::Millisecond](#millisecond)|Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem um milissegundo.|
|[CFileTime::Minute](#minute)|Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem um minuto.|
|[CFileTime::Second](#second)|Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem um segundo.|
|[CFileTime::Week](#week)|Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem uma semana.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para gerenciar os valores de data e hora associados com a criação, acesso e modificação de arquivos. Os métodos e os dados dessa classe são frequentemente usados em conjunto com `CFileTimeSpan` objetos, que lidam com valores de tempo relativo.

O valor de data e hora é armazenado como um valor de 64 bits que representa o número de intervalos de 100 nanossegundos desde 1 de janeiro de 1601. Este é o formato de tempo Universal Coordenado (UTC).

As seguintes variáveis de membro constantes estático são fornecidas para simplificar cálculos:

|Variável de membro|Número de intervalos de 100 nanossegundos|
|---------------------|-----------------------------------------|
|Milissegundo|10,000|
|Segundo|Milissegundo \* 1.000|
|Minuto|Segundo \* 60|
|Hora|Minuto \* 60|
|Dia|Hora \* 24|
|Semana|Dia \* 7|

**Observação** nem todos os sistemas de arquivos podem gravar a criação e a hora do último acesso e nem todos os sistemas de arquivos registrá-los da mesma maneira. Por exemplo, no sistema de arquivos FAT do Windows NT, criar tempo tem uma resolução de 10 milissegundos, tempo de gravação tem uma resolução de 2 segundos e tempo de acesso tem uma resolução de 1 dia (a data de acesso). Em NTFS, o tempo de acesso tem uma resolução de 1 hora. Além disso, FAT registra vezes em disco na hora local, mas NTFS registra vezes no disco em UTC. Para obter mais informações, consulte [tempos de arquivo](/windows/desktop/SysInfo/file-times).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`FILETIME`

`CFileTime`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltime.h

##  <a name="cfiletime"></a>  CFileTime::CFileTime

O construtor.

```
CFileTime() throw();
CFileTime(const FILETIME& ft) throw();
CFileTime(ULONGLONG nTime) throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
Um [FILETIME](/windows/desktop/api/minwinbase/ns-minwinbase-filetime) estrutura.

*nTime*<br/>
A data e hora expressada como um valor de 64 bits.

### <a name="remarks"></a>Comentários

O `CFileTime` objeto pode ser criado usando uma existente de data e hora de um `FILETIME` estrutura ou expresso como um valor de 64 bits (no local ou formatos de hora (UTC) Tempo Universal Coordenado). O construtor padrão define o tempo como 0.

##  <a name="day"></a>  CFileTime::Day

Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem um dia.

```
static const ULONGLONG Day = Hour* 24;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

##  <a name="getcurrenttime"></a>  CFileTime::GetCurrentTime

Chame essa função estática para recuperar um `CFileTime` objeto que representa a data atual do sistema e a hora.

```
static CFileTime GetCurrentTime() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a data atual do sistema e a hora no formato Tempo Universal Coordenado (UTC).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#41](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_1.cpp)]

##  <a name="gettime"></a>  CFileTime::GetTime

Chame esse método para recuperar o tempo desde o `CFileTime` objeto.

```
ULONGLONG GetTime() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna a data e hora como um número de 64 bits, que pode ser em formato Tempo Universal Coordenado (UTC) ou local.

##  <a name="hour"></a>  CFileTime::Hour

Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem uma hora.

```
static const ULONGLONG Hour = Minute* 60;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

##  <a name="localtoutc"></a>  CFileTime::LocalToUTC

Chame esse método para converter uma hora de arquivo local em uma hora de arquivo com base no tempo Universal Coordenado (UTC).

```
CFileTime LocalToUTC() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTime` objeto que contém a hora no formato UTC.

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::UTCToLocal](#utctolocal).

##  <a name="millisecond"></a>  CFileTime::Millisecond

Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem um milissegundo.

```
static const ULONGLONG Millisecond = 10000;
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#44](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_2.cpp)]

##  <a name="minute"></a>  CFileTime::Minute

Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem um minuto.

```
static const ULONGLONG Minute = Second* 60;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

##  <a name="operator_-"></a>  CFileTime::operator -

Esse operador é usado para realizar a subtração em um `CFileTime` ou `CFileTimeSpan` objeto.

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

##  <a name="operator_neq"></a>  CFileTime::operator! =

Esse operador compara dois `CFileTime` objetos quanto à desigualdade.

```
bool operator!=(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o item que está sendo comparado não for igual ao `CFileTime` objeto, caso contrário, FALSE.

##  <a name="operator_add"></a>  CFileTime::operator +

Esse operador é usado para executar uma adição em um `CFileTimeSpan` objeto.

```
CFileTime operator+(CFileTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTime` objeto que representa o resultado da hora original mais um tempo relativo.

##  <a name="operator_add_eq"></a>  CFileTime::operator +=

Esse operador é usado para executar uma adição em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.

```
CFileTime& operator+=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um objeto `CFileTimeSpan`.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CFileTime` objeto, que representa o resultado da hora original mais um tempo relativo.

##  <a name="operator_lt"></a>  CFileTime::operator &lt;

Esse operador compara dois `CFileTime` objetos para determinar o menor.

```
bool operator<(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se o primeiro objeto for menor (anteriormente no tempo) que o segundo, FALSE caso contrário.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#43](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_3.cpp)]

##  <a name="operator_lt_eq"></a>  CFileTime::operator &lt;=

Esse operador compara dois `CFileTime` objetos para determinar igualdade ou o menor.

```
bool operator<=(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o primeiro objeto é menor que (anterior no tempo) ou igual à segunda, caso contrário, FALSE.

##  <a name="operator_eq"></a>  CFileTime::operator =

O operador de atribuição.

```
CFileTime& operator=(const FILETIME& ft) throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
Um `CFileTime` objeto que contém a nova data e hora.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CFileTime` objeto.

##  <a name="operator_-_eq"></a>  CFileTime::operator -=

Esse operador é usado para realizar a subtração em um `CFileTimeSpan` de objeto e atribuir o resultado para o objeto atual.

```
CFileTime& operator-=(CFileTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*span*<br/>
Um `CFileTimeSpan` objeto que contém o tempo relativo a ser subtraído.

### <a name="return-value"></a>Valor de retorno

Retorna o atualizada `CFileTime` objeto.

##  <a name="operator_eq_eq"></a>  CFileTime::operator ==

Esse operador compara dois `CFileTime` objetos quanto à igualdade.

```
bool operator==(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se os objetos forem iguais, caso contrário, FALSE.

##  <a name="operator_gt"></a>  CFileTime::operator &gt;

Esse operador compara dois `CFileTime` objetos para determinar o maior.

```
bool operator>(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o primeiro objeto é maior que (posterior no tempo) que a segunda, caso contrário, FALSE.

##  <a name="operator_gt_eq"></a>  CFileTime::operator &gt;=

Esse operador compara dois `CFileTime` objetos para determinar igualdade ou maior.

```
bool operator>=(CFileTime ft) const throw();
```

### <a name="parameters"></a>Parâmetros

*ft*<br/>
O objeto `CFileTime` a ser comparado.

### <a name="return-value"></a>Valor de retorno

Retorna VERDADEIRO se o primeiro objeto for maior (mais tarde no horário) ou igual à segunda, caso contrário, FALSE.

##  <a name="second"></a>  CFileTime::Second

Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem um dia.

```
static const ULONGLONG Second = Millisecond* 1000;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

##  <a name="settime"></a>  CFileTime::SetTime

Chame esse método para definir a data e hora armazenados pelo `CFileTime` objeto.

```
void SetTime(ULONGLONG nTime) throw();
```

### <a name="parameters"></a>Parâmetros

*nTime*<br/>
O valor de 64 bits que representa a data e hora, no local ou formato Tempo Universal Coordenado (UTC).

##  <a name="utctolocal"></a>  CFileTime::UTCToLocal

Chame esse método para converter a hora com base no tempo Universal Coordenado (UTC) para o horário de arquivo local.

```
CFileTime UTCToLocal() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um `CFileTime` objeto que contém a hora no formato de hora do arquivo local.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCFiles#42](../../atl-mfc-shared/reference/codesnippet/cpp/cfiletime-class_4.cpp)]

##  <a name="week"></a>  CFileTime::Week

Um membro de dados estáticos que armazenar o número de intervalos de 100 nanossegundos que compõem uma semana.

```
static const ULONGLONG Week = Day* 7;
```

### <a name="example"></a>Exemplo

Veja o exemplo de [CFileTime::Millisecond](#millisecond).

## <a name="see-also"></a>Consulte também

[FILETIME](/windows/desktop/api/minwinbase/ns-minwinbase-filetime)<br/>
[Classe CFileTimeSpan](../../atl-mfc-shared/reference/cfiletimespan-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
