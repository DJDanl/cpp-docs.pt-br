---
title: Classe COleDateTimeSpan
ms.date: 03/27/2019
f1_keywords:
- COleDateTimeSpan
- ATLCOMTIME/ATL::COleDateTimeSpan
- ATLCOMTIME/ATL::COleDateTimeSpan::COleDateTimeSpan
- ATLCOMTIME/ATL::COleDateTimeSpan::Format
- ATLCOMTIME/ATL::COleDateTimeSpan::GetDays
- ATLCOMTIME/ATL::COleDateTimeSpan::GetHours
- ATLCOMTIME/ATL::COleDateTimeSpan::GetMinutes
- ATLCOMTIME/ATL::COleDateTimeSpan::GetSeconds
- ATLCOMTIME/ATL::COleDateTimeSpan::GetStatus
- ATLCOMTIME/ATL::COleDateTimeSpan::GetTotalDays
- ATLCOMTIME/ATL::COleDateTimeSpan::GetTotalHours
- ATLCOMTIME/ATL::COleDateTimeSpan::GetTotalMinutes
- ATLCOMTIME/ATL::COleDateTimeSpan::GetTotalSeconds
- ATLCOMTIME/ATL::COleDateTimeSpan::SetDateTimeSpan
- ATLCOMTIME/ATL::COleDateTimeSpan::SetStatus
- ATLCOMTIME/ATL::COleDateTimeSpan::m_span
- ATLCOMTIME/ATL::COleDateTimeSpan::m_status
helpviewer_keywords:
- timespan
- time span
- shared classes, COleDateTimeSpan
- Date data type, MFC encapsulation of
- COleDateTimeSpan class
ms.assetid: 7441526d-a30a-4019-8fb3-3fee6f897cbe
ms.openlocfilehash: 5934a456b519d14def14018f966c7bff8206c3c4
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500131"
---
# <a name="coledatetimespan-class"></a>Classe COleDateTimeSpan

Representa uma hora relativa, um período de tempo.

## <a name="syntax"></a>Sintaxe

```
class COleDateTimeSpan
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTimeSpan::COleDateTimeSpan](#coledatetimespan)|Constrói um objeto `COleDateTimeSpan`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTimeSpan:: Format](#format)|Gera uma representação de cadeia de caracteres formatada de um `COleDateTimeSpan` objeto.|
|[COleDateTimeSpan:: GetDays](#getdays)|Retorna a parte do dia do intervalo que este `COleDateTimeSpan` objeto representa.|
|[COleDateTimeSpan:: getHours](#gethours)|Retorna a parte de hora do intervalo que este `COleDateTimeSpan` objeto representa.|
|[COleDateTimeSpan:: getminutos](#getminutes)|Retorna a parte de minuto do intervalo que este `COleDateTimeSpan` objeto representa.|
|[COleDateTimeSpan:: getsegundos](#getseconds)|Retorna a segunda parte do intervalo que este `COleDateTimeSpan` objeto representa.|
|[COleDateTimeSpan:: GetStatus](#getstatus)|Obtém o status (validade) deste `COleDateTimeSpan` objeto.|
|[COleDateTimeSpan::GetTotalDays](#gettotaldays)|Retorna o número de dias que este `COleDateTimeSpan` objeto representa.|
|[COleDateTimeSpan::GetTotalHours](#gettotalhours)|Retorna o número de horas que este `COleDateTimeSpan` objeto representa.|
|[COleDateTimeSpan::GetTotalMinutes](#gettotalminutes)|Retorna o número de minutos que esse `COleDateTimeSpan` objeto representa.|
|[COleDateTimeSpan::GetTotalSeconds](#gettotalseconds)|Retorna o número de segundos que este `COleDateTimeSpan` objeto representa.|
|[COleDateTimeSpan::SetDateTimeSpan](#setdatetimespan)|Define o valor deste `COleDateTimeSpan` objeto.|
|[COleDateTimeSpan:: SetStatus](#setstatus)|Define o status (validade) deste `COleDateTimeSpan` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|-|-|
|[operador +,-](#operator_add_-)|Adicione, subtraia e altere o sinal de `COleDateTimeSpan` valores.|
|[operador + =,-=](#operator_add_eq_-_eq)|Adicione e subtraia um `COleDateTimeSpan` valor desse `COleDateTimeSpan` valor.|
|[operador =](#operator_eq)|Copia um `COleDateTimeSpan` valor.|
|[Operator = =, <, <=](#coledatetimespan_relational_operators)|Compare dois `COleDateTimeSpan` valores.|
|[Operador double](#operator_double)|Converte esse `COleDateTimeSpan` valor em um **`double`** .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTimeSpan:: m_span](#m_span)|Contém o subjacente **`double`** para este `COleDateTimeSpan` objeto.|
|[COleDateTimeSpan:: m_status](#m_status)|Contém o status deste `COleDateTimeSpan` objeto.|

## <a name="remarks"></a>Comentários

`COleDateTimeSpan` Não tem uma classe base.

A `COleDateTimeSpan` mantém tempo em dias.

`COleDateTimeSpan` é usado com sua classe complementar [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md). `COleDateTime` encapsula o `DATE` tipo de dados da automação OLE. `COleDateTime` representa valores de tempo absolutos. Todos os `COleDateTime` cálculos envolvem `COleDateTimeSpan` valores. A relação entre essas classes é análoga à entre [CTime](../../atl-mfc-shared/reference/ctime-class.md) e [CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md).

Para obter mais informações sobre `COleDateTime` as `COleDateTimeSpan` classes e, consulte a [data e hora do artigo: suporte à automação](../date-and-time.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLComTime. h

## <a name="coledatetimespan-relational-operators"></a><a name="coledatetimespan_relational_operators"></a> Operadores relacionais do COleDateTimeSpan

Operadores de comparação.

```
bool operator==(const COleDateTimeSpan& dateSpan) const throw();
bool operator!=(const COleDateTimeSpan& dateSpan) const throw();
bool operator<(const COleDateTimeSpan& dateSpan) const throw();
bool operator>(const COleDateTimeSpan& dateSpan) const throw();
bool operator<=(const COleDateTimeSpan& dateSpan) const throw();
bool operator>=(const COleDateTimeSpan& dateSpan) const throw();
```

### <a name="parameters"></a>Parâmetros

*dateSpan*<br/>
O `COleDateTimeSpan` de comparação.

### <a name="return-value"></a>Valor Retornado

Esses operadores comparam dois valores de intervalo de data/hora e retornam TRUE se a condição for verdadeira; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Um ATLASSERT ocorrerá se um dos operandos for inválido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#25](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_1.cpp)]

[!code-cpp[NVC_ATLMFC_Utilities#26](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_2.cpp)]

## <a name="coledatetimespancoledatetimespan"></a><a name="coledatetimespan"></a> COleDateTimeSpan::COleDateTimeSpan

Constrói um objeto `COleDateTimeSpan`.

```
COleDateTimeSpan() throw();
COleDateTimeSpan(double dblSpanSrc) throw();
COleDateTimeSpan(LONG lDays, int nHours, int nMins, int nSecs) throw();
```

### <a name="parameters"></a>Parâmetros

*dblSpanSrc*<br/>
O número de dias a serem copiados para o novo `COleDateTimeSpan` objeto.

*lDays*, *nHours*, *nMins*, *nSecs*<br/>
Indique os valores de dia e hora a serem copiados para o novo `COleDateTimeSpan` objeto.

### <a name="remarks"></a>Comentários

Todos esses construtores criam novos `COleDateTimeSpan` objetos inicializados para o valor especificado. Segue uma breve descrição de cada um desses construtores:

- **COleDateTimeSpan ()** Constrói um `COleDateTimeSpan` objeto inicializado como 0.

- **COleDateTimeSpan (** `dblSpanSrc` **)** constrói um `COleDateTimeSpan` objeto a partir de um valor de ponto flutuante.

- **COleDateTimeSpan (** `lDays` **,** `nHours` **,** `nMins` **,** `nSecs` **)** constrói um `COleDateTimeSpan` objeto inicializado para os valores numéricos especificados.

O status do novo `COleDateTimeSpan` objeto é definido como válido.

Para obter mais informações sobre os limites de `COleDateTimeSpan` valores, consulte a [data e hora do artigo: suporte à automação](../date-and-time.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#14](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_3.cpp)]

## <a name="coledatetimespanformat"></a><a name="format"></a> COleDateTimeSpan:: Format

Gera uma representação de cadeia de caracteres formatada de um `COleDateTimeSpan` objeto.

```
CString Format(LPCTSTR pFormat) const;
CString Format(UINT nID) const;
```

### <a name="parameters"></a>Parâmetros

*pFormat*<br/>
Uma cadeia de caracteres de formatação semelhante à `printf` cadeia de caracteres de formatação. Os códigos de formatação, precedidos por um sinal de porcentagem ( `%` ), são substituídos pelo `COleDateTimeSpan` componente correspondente. Outros caracteres na cadeia de caracteres de formatação são copiados inalterados para a cadeia de caracteres retornada. O valor e o significado dos códigos de formatação para `Format` estão listados abaixo:

- **% H** Horas no dia atual

- **% M** Minutos na hora atual

- **% S** Segundos no minuto atual

- **%%** Sinal de porcentagem

Os quatro códigos de formato listados acima são os únicos códigos que o formato aceitará.

-

*nID*<br/>
A ID de recurso para a cadeia de caracteres de controle de formato.

### <a name="return-value"></a>Valor Retornado

Uma `CString` que contém o valor formatado de data/hora-intervalo.

### <a name="remarks"></a>Comentários

Chame essas funções para criar uma representação formatada do valor de intervalo de tempo. Se o status desse `COleDateTimeSpan` objeto for nulo, o valor de retorno será uma cadeia de caracteres vazia. Se o status for inválido, a cadeia de caracteres de retorno será especificada pelo recurso de cadeia de caracteres IDS_INVALID_DATETIMESPAN.

Segue uma breve descrição dos formulários para essa função:

**Format (** *pFormat* **)**<br/>
Esse formulário formata o valor usando a cadeia de caracteres de formato que contém códigos de formatação especiais precedidos por um sinal de porcentagem (%), como em `printf` . A cadeia de caracteres de formatação é passada como um parâmetro para a função.

**Format (** *NID* **)**<br/>
Esse formulário formata o valor usando a cadeia de caracteres de formato que contém códigos de formatação especiais precedidos por um sinal de porcentagem (%), como em `printf` . A cadeia de caracteres de formatação é um recurso. A ID desse recurso de cadeia de caracteres é passada como o parâmetro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#15](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_4.cpp)]

## <a name="coledatetimespangetdays"></a><a name="getdays"></a> COleDateTimeSpan:: GetDays

Recupera a parte do dia deste valor de data/hora de intervalo.

```
LONG GetDays() const throw();
```

### <a name="return-value"></a>Valor Retornado

A parte do dia deste valor de data/hora de intervalo.

### <a name="remarks"></a>Comentários

Os valores de retorno desse intervalo de função entre aproximadamente-3.615.000 e 3.615.000.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetHours](#gethours)

- [Getminutos](#getminutes)

- [Getsegundos](#getseconds)

- [GetTotalDays](#gettotaldays)

- [GetTotalHours](#gettotalhours)

- [GetTotalMinutes](#gettotalminutes)

- [GetTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#16](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_5.cpp)]

## <a name="coledatetimespangethours"></a><a name="gethours"></a> COleDateTimeSpan:: getHours

Recupera a parte de hora deste valor de data/hora de intervalo.

```
LONG GetHours() const throw();
```

### <a name="return-value"></a>Valor Retornado

A parte de horas deste valor de data/hora de intervalo.

### <a name="remarks"></a>Comentários

Os valores de retorno desse intervalo de função entre-23 e 23.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [Getminutos](#getminutes)

- [Getsegundos](#getseconds)

- [GetTotalDays](#gettotaldays)

- [GetTotalHours](#gettotalhours)

- [GetTotalMinutes](#gettotalminutes)

- [GetTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#17](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_6.cpp)]

## <a name="coledatetimespangetminutes"></a><a name="getminutes"></a> COleDateTimeSpan:: getminutos

Recupera a parte de minuto deste valor de data/hora de intervalo.

```
LONG GetMinutes() const throw();
```

### <a name="return-value"></a>Valor Retornado

A parte de minutos deste valor de data/hora de intervalo.

### <a name="remarks"></a>Comentários

Os valores de retorno desse intervalo de função entre-59 e 59.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getsegundos](#getseconds)

- [GetTotalDays](#gettotaldays)

- [GetTotalHours](#gettotalhours)

- [GetTotalMinutes](#gettotalminutes)

- [GetTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#18](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_7.cpp)]

## <a name="coledatetimespangetseconds"></a><a name="getseconds"></a> COleDateTimeSpan:: getsegundos

Recupera a segunda parte deste valor de data/hora de intervalo.

```
LONG GetSeconds() const throw();
```

### <a name="return-value"></a>Valor Retornado

A parte de segundos deste valor de data/hora de intervalo.

### <a name="remarks"></a>Comentários

Os valores de retorno desse intervalo de função entre-59 e 59.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutos](#getminutes)

- [GetTotalDays](#gettotaldays)

- [GetTotalHours](#gettotalhours)

- [GetTotalMinutes](#gettotalminutes)

- [GetTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#19](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_8.cpp)]

## <a name="coledatetimespangetstatus"></a><a name="getstatus"></a> COleDateTimeSpan:: GetStatus

Obtém o status (validade) deste `COleDateTimeSpan` objeto.

```
DateTimeSpanStatus GetStatus() const throw();
```

### <a name="return-value"></a>Valor Retornado

O status desse `COleDateTimeSpan` valor.

### <a name="remarks"></a>Comentários

O valor de retorno é definido pelo `DateTimeSpanStatus` tipo enumerado, que é definido dentro da `COleDateTimeSpan` classe.

```
enum DateTimeSpanStatus{
   valid = 0,
   invalid = 1,
   null = 2,
};
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleDateTimeSpan::valid` Indica que este `COleDateTimeSpan` objeto é válido.

- `COleDateTimeSpan::invalid` Indica que este `COleDateTimeSpan` objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleDateTimeSpan::null` Indica que esse `COleDateTimeSpan` objeto é nulo, ou seja, que nenhum valor foi fornecido para esse objeto. (Isso é "NULL" no sentido do banco de dados de "sem valor", em oposição ao C++ NULL.)

O status de um `COleDateTimeSpan` objeto é inválido nos seguintes casos:

- Se esse objeto tiver ocorrido um estouro ou negativo durante uma operação de atribuição aritmética, ou seja, `+=` ou `-=` .

- Se um valor inválido foi atribuído a esse objeto.

- Se o status deste objeto foi definido explicitamente como inválido usando `SetStatus` .

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte [COleDateTimeSpan:: operator +,-](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_-) e [COleDateTimeSpan:: operator + =,-=](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_eq_-_eq).

Para obter mais informações sobre os limites de `COleDateTimeSpan` valores, consulte a [data e hora do artigo: suporte à automação](../date-and-time.md).

## <a name="coledatetimespangettotaldays"></a><a name="gettotaldays"></a> COleDateTimeSpan::GetTotalDays

Recupera esse valor de data/hora de intervalo expresso em dias.

```
double GetTotalDays() const throw();
```

### <a name="return-value"></a>Valor Retornado

Esse valor de intervalo de data/hora expresso em dias. Embora essa função tenha sido protótipo para retornar um Double, ela sempre retornará um valor inteiro.

### <a name="remarks"></a>Comentários

Os valores de retorno desse intervalo de função entre 3.65 E6 e 3.65 E6.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutos](#getminutes)

- [Getsegundos](#getseconds)

- [GetTotalHours](#gettotalhours)

- [GetTotalMinutes](#gettotalminutes)

- [GetTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#20](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_9.cpp)]

## <a name="coledatetimespangettotalhours"></a><a name="gettotalhours"></a> COleDateTimeSpan::GetTotalHours

Recupera esse valor de data/hora de intervalo expresso em horas.

```
double GetTotalHours() const throw();
```

### <a name="return-value"></a>Valor Retornado

Esse valor de intervalo de data/hora expresso em horas. Embora essa função tenha sido protótipo para retornar um Double, ela sempre retornará um valor inteiro.

### <a name="remarks"></a>Comentários

Os valores de retorno desse intervalo de função entre 8.77 E7 e 8.77 E7.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutos](#getminutes)

- [Getsegundos](#getseconds)

- [GetTotalDays](#gettotaldays)

- [GetTotalMinutes](#gettotalminutes)

- [GetTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

Consulte o exemplo de [GetTotalDays](#gettotaldays).

## <a name="coledatetimespangettotalminutes"></a><a name="gettotalminutes"></a> COleDateTimeSpan::GetTotalMinutes

Recupera esse valor de data/hora de intervalo expresso em minutos.

```
double GetTotalMinutes() const throw();
```

### <a name="return-value"></a>Valor Retornado

Esse valor de intervalo de data/hora expresso em minutos. Embora essa função tenha sido protótipo para retornar um Double, ela sempre retornará um valor inteiro.

### <a name="remarks"></a>Comentários

Os valores de retorno desse intervalo de função entre 5.26 E9 e 5.26 E9.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutos](#getminutes)

- [Getsegundos](#getseconds)

- [GetTotalDays](#gettotaldays)

- [GetTotalHours](#gettotalhours)

- [GetTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

Consulte o exemplo de [GetTotalDays](#gettotaldays).

## <a name="coledatetimespangettotalseconds"></a><a name="gettotalseconds"></a> COleDateTimeSpan::GetTotalSeconds

Recupera esse valor de data/hora de intervalo expresso em segundos.

```
double GetTotalSeconds() const throw();
```

### <a name="return-value"></a>Valor Retornado

Esse valor de intervalo de data/hora expresso em segundos. Embora essa função tenha sido protótipo para retornar um Double, ela sempre retornará um valor inteiro.

### <a name="remarks"></a>Comentários

Os valores de retorno desse intervalo de função entre aproximadamente-3.16 E11 para 3.16 E11.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutos](#getminutes)

- [Getsegundos](#getseconds)

- [GetTotalDays](#gettotaldays)

- [GetTotalHours](#gettotalhours)

- [GetTotalMinutes](#gettotalminutes)

### <a name="example"></a>Exemplo

Consulte o exemplo de [GetTotalDays](#gettotaldays).

## <a name="coledatetimespanm_span"></a><a name="m_span"></a> COleDateTimeSpan:: m_span

O **`double`** valor subjacente deste `COleDateTime` objeto.

```
double m_span;
```

### <a name="remarks"></a>Comentários

Esse valor expressa a data/intervalo de tempo em dias.

> [!CAUTION]
> Alterar o valor no **`double`** membro de dados alterará o valor desse `COleDateTimeSpan` objeto. Ele não altera o status desse `COleDateTimeSpan` objeto.

## <a name="coledatetimespanm_status"></a><a name="m_status"></a> COleDateTimeSpan:: m_status

O tipo para esse membro de dados é o tipo enumerado `DateTimeSpanStatus` , que é definido dentro da `COleDateTimeSpan` classe.

```
DateTimeSpanStatus m_status;
```

### <a name="remarks"></a>Comentários

```
enum DateTimeSpanStatus{
   valid = 0,
   invalid = 1,
   null = 2,
   };
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleDateTimeSpan::valid` Indica que este `COleDateTimeSpan` objeto é válido.

- `COleDateTimeSpan::invalid` Indica que este `COleDateTimeSpan` objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleDateTimeSpan::null` Indica que esse `COleDateTimeSpan` objeto é nulo, ou seja, que nenhum valor foi fornecido para esse objeto. (Isso é "NULL" no sentido do banco de dados de "sem valor", em oposição ao C++ NULL.)

O status de um `COleDateTimeSpan` objeto é inválido nos seguintes casos:

- Se esse objeto tiver ocorrido um estouro ou negativo durante uma operação de atribuição aritmética, ou seja, `+=` ou `-=` .

- Se um valor inválido foi atribuído a esse objeto.

- Se o status deste objeto foi explicitamente definido como inválido usando [SetStatus](#setstatus).

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte [COleDateTimeSpan:: operator +,-](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_-) e [COleDateTimeSpan:: operator + =,-=](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_eq_-_eq).

> [!CAUTION]
> Esse membro de dados destina-se a situações de programação avançada. Você deve usar as funções membro embutido [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para obter mais precauções sobre como definir explicitamente esse membro de dados.

Para obter mais informações sobre os limites de `COleDateTimeSpan` valores, consulte a [data e hora do artigo: suporte à automação](../date-and-time.md).

## <a name="coledatetimespanoperator-"></a><a name="operator_eq"></a> COleDateTimeSpan:: Operator =

Copia um `COleDateTimeSpan` valor.

```
COleDateTimeSpan& operator=(double dblSpanSrc) throw();
```

### <a name="remarks"></a>Comentários

Esse operador de atribuição sobrecarregado copia o valor de data/hora de origem para esse `COleDateTimeSpan` objeto.

## <a name="coledatetimespanoperator---"></a><a name="operator_add_-"></a> COleDateTimeSpan:: operator +,-

Adicione, subtraia e altere o sinal de `COleDateTimeSpan` valores.

```
COleDateTimeSpan operator+(const COleDateTimeSpan& dateSpan) const throw();
COleDateTimeSpan operator-(const COleDateTimeSpan& dateSpan) const throw();
COleDateTimeSpan operator-() const throw();
```

### <a name="remarks"></a>Comentários

Os primeiros dois operadores permitem adicionar e subtrair valores de data/hora. O terceiro permite que você altere o sinal de um valor de data/hora.

Se um dos operandos for nulo, o status do `COleDateTimeSpan` valor resultante será NULL.

Se qualquer um dos operandos for inválido e o outro não for nulo, o status do valor resultante `COleDateTimeSpan` será inválido.

Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte a variável de membro [m_status](#m_status) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#23](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_10.cpp)]

## <a name="coledatetimespanoperator---"></a><a name="operator_add_eq_-_eq"></a> COleDateTimeSpan:: operator + =,-=

Adicione e subtraia um `COleDateTimeSpan` valor desse `COleDateTimeSpan` valor.

```
COleDateTimeSpan& operator+=(const COleDateTimeSpan dateSpan) throw();
COleDateTimeSpan& operator-=(const COleDateTimeSpan dateSpan) throw();
```

### <a name="remarks"></a>Comentários

Esses operadores permitem que você adicione e subtraia valores de data/hora do intervalo desse `COleDateTimeSpan` objeto. Se um dos operandos for nulo, o status do `COleDateTimeSpan` valor resultante será NULL.

Se qualquer um dos operandos for inválido e o outro não for nulo, o status do valor resultante `COleDateTimeSpan` será inválido.

Para obter mais informações sobre os valores de status válido, inválido e nulo, consulte a variável de membro [m_status](#m_status) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#24](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_11.cpp)]

## <a name="coledatetimespanoperator-double"></a><a name="operator_double"></a> COleDateTimeSpan:: Operador Double

Converte esse `COleDateTimeSpan` valor em um **`double`** .

```
operator double() const throw();
```

### <a name="remarks"></a>Comentários

Esse operador retorna o valor desse `COleDateTimeSpan` valor como um número de dias flutuantes.

## <a name="coledatetimespansetdatetimespan"></a><a name="setdatetimespan"></a> COleDateTimeSpan::SetDateTimeSpan

Define o valor desse valor de data/hora/intervalo.

```cpp
void SetDateTimeSpan(LONG lDays, int nHours, int nMins, int nSecs) throw();
```

### <a name="parameters"></a>Parâmetros

*lDays*, *nHours*, *nMins*, *nSecs*<br/>
Indique os valores de intervalo de data e hora a serem copiados para esse `COleDateTimeSpan` objeto.

### <a name="remarks"></a>Comentários

Para funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutos](#getminutes)

- [Getsegundos](#getseconds)

- [GetTotalDays](#gettotaldays)

- [GetTotalHours](#gettotalhours)

- [GetTotalMinutes](#gettotalminutes)

- [GetTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#21](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_12.cpp)]

## <a name="coledatetimespansetstatus"></a><a name="setstatus"></a> COleDateTimeSpan:: SetStatus

Define o status (validade) deste `COleDateTimeSpan` objeto.

```cpp
void SetStatus(DateTimeSpanStatus status) throw();
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O novo valor de status deste `COleDateTimeSpan` objeto.

### <a name="remarks"></a>Comentários

O valor do parâmetro *status* é definido pelo `DateTimeSpanStatus` tipo enumerado, que é definido dentro da `COleDateTimeSpan` classe.

```
enum DateTimeSpanStatus{
   valid = 0,
   invalid = 1,
   null = 2,
   };
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleDateTimeSpan::valid` Indica que este `COleDateTimeSpan` objeto é válido.

- `COleDateTimeSpan::invalid` Indica que este `COleDateTimeSpan` objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleDateTimeSpan::null` Indica que esse `COleDateTimeSpan` objeto é nulo, ou seja, que nenhum valor foi fornecido para esse objeto. (Isso é "NULL" no sentido do banco de dados de "sem valor", em oposição ao C++ NULL.)

   > [!CAUTION]
   > Essa função é para situações de programação avançada. Essa função não altera os dados neste objeto. Com mais frequência, ele será usado para definir o status como **nulo** ou **inválido**. Observe que o operador de atribuição ([operador =](#operator_eq)) e [SetDateTimeSpan](#setdatetimespan) definem o status do objeto com base no (s) valor (es) de origem.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#22](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_13.cpp)]

## <a name="see-also"></a>Confira também

[Classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)<br/>
[Classe CTime](../../atl-mfc-shared/reference/ctime-class.md)<br/>
[Classe CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
