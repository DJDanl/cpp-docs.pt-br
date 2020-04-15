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
ms.openlocfilehash: 7173fa0b6261ea718a02d399d944a1b5bb98b9f6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317734"
---
# <a name="coledatetimespan-class"></a>Classe COleDateTimeSpan

Representa um tempo relativo, um período de tempo.

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
|[COleDateTimeSpan::Formato](#format)|Gera uma representação de `COleDateTimeSpan` string formatado de um objeto.|
|[COleDateTimeSpan::GetDays](#getdays)|Retorna a parte do `COleDateTimeSpan` dia do comprimento que este objeto representa.|
|[COleDateTimeSpan::GetHours](#gethours)|Retorna a porção de `COleDateTimeSpan` hora do comprimento que este objeto representa.|
|[COleDateTimeSpan::GetMinutes](#getminutes)|Retorna a porção minuciosa `COleDateTimeSpan` do comprimento que este objeto representa.|
|[COleDateTimeSpan::GetSeconds](#getseconds)|Retorna a segunda parte `COleDateTimeSpan` do comprimento que este objeto representa.|
|[COleDateTimeSpan::GetStatus](#getstatus)|Obtém o status (validade) deste `COleDateTimeSpan` objeto.|
|[COleDateTimeSpan::GetTotalDays](#gettotaldays)|Retorna o número `COleDateTimeSpan` de dias que este objeto representa.|
|[COleDateTimeSpan::GetTotalHours](#gettotalhours)|Retorna o número `COleDateTimeSpan` de horas que este objeto representa.|
|[COleDateTimeSpan::GetTotalMinutes](#gettotalminutes)|Retorna o número `COleDateTimeSpan` de minutos que este objeto representa.|
|[COleDateTimeSpan::GetTotalSeconds](#gettotalseconds)|Retorna o número `COleDateTimeSpan` de segundos que este objeto representa.|
|[COleDateTimeSpan::SetDateTimeSpan](#setdatetimespan)|Define o valor `COleDateTimeSpan` deste objeto.|
|[COleDateTimeSpan::SetStatus](#setstatus)|Define o status (validade) `COleDateTimeSpan` deste objeto.|

### <a name="public-operators"></a>Operadores públicos

|||
|-|-|
|[operador +, -](#operator_add_-)|Adicionar, subtrair e alterar `COleDateTimeSpan` o sinal de valores.|
|[operador +=, -=](#operator_add_eq_-_eq)|Adicione e subtraia `COleDateTimeSpan` `COleDateTimeSpan` um valor desse valor.|
|[operador =](#operator_eq)|Copia `COleDateTimeSpan` um valor.|
|[operador ==, <, <=](#coledatetimespan_relational_operators)|Compare `COleDateTimeSpan` dois valores.|
|[Operador double](#operator_double)|Converte `COleDateTimeSpan` esse valor em um **duplo**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDateTimeSpan::m_span](#m_span)|Contém o **duplo** subjacente `COleDateTimeSpan` para este objeto.|
|[COleDateTimeSpan::m_status](#m_status)|Contém o status `COleDateTimeSpan` deste objeto.|

## <a name="remarks"></a>Comentários

`COleDateTimeSpan`não tem uma classe base.

Um `COleDateTimeSpan` tempo de folga em dias.

`COleDateTimeSpan`é usado com sua classe companheira [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md). `COleDateTime`encapsula o `DATE` tipo de dados da automação OLE. `COleDateTime`representa valores de tempo absolutos. Todos `COleDateTime` os `COleDateTimeSpan` cálculos envolvem valores. A relação entre essas classes é análoga à entre [CTime](../../atl-mfc-shared/reference/ctime-class.md) e [CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md).

Para obter mais `COleDateTime` `COleDateTimeSpan` informações sobre as aulas e as aulas, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLComTime.h

## <a name="coledatetimespan-relational-operators"></a><a name="coledatetimespan_relational_operators"></a>Operadores relacionais COleDateTimeSpan

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
O `COleDateTimeSpan` a ser comparado.

### <a name="return-value"></a>Valor retornado

Esses operadores comparam dois valores de data/período e retornam TRUE se a condição for verdadeira; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Um ATLASSERT ocorrerá se o operadores for inválido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#25](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_1.cpp)]

[!code-cpp[NVC_ATLMFC_Utilities#26](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_2.cpp)]

## <a name="coledatetimespancoledatetimespan"></a><a name="coledatetimespan"></a>COleDateTimeSpan::COleDateTimeSpan

Constrói um objeto `COleDateTimeSpan`.

```
COleDateTimeSpan() throw();
COleDateTimeSpan(double dblSpanSrc) throw();
COleDateTimeSpan(LONG lDays, int nHours, int nMins, int nSecs) throw();
```

### <a name="parameters"></a>Parâmetros

*dblSpanSrc*<br/>
O número de dias a serem `COleDateTimeSpan` copiados para o novo objeto.

*lDays,* *nHours,* *nMins,* *nSecs*<br/>
Indique os valores de dia `COleDateTimeSpan` e hora a serem copiados para o novo objeto.

### <a name="remarks"></a>Comentários

Todos esses construtores criam `COleDateTimeSpan` novos objetos inicializados para o valor especificado. Segue-se uma breve descrição de cada um desses construtores:

- **COleDateTimeSpan( )** Constrói um `COleDateTimeSpan` objeto inicializado a 0.

- **COleDateTimeSpan(** `dblSpanSrc` **)** Constrói um `COleDateTimeSpan` objeto a partir de um valor de ponto flutuante.

- **COleDateTimeSpan(** `lDays` **,** `nHours` **,** `nMins` **)** `nSecs` **)** Constrói um `COleDateTimeSpan` objeto inicializado aos valores numéricos especificados.

O status do `COleDateTimeSpan` novo objeto está definido como válido.

Para obter mais informações `COleDateTimeSpan` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#14](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_3.cpp)]

## <a name="coledatetimespanformat"></a><a name="format"></a>COleDateTimeSpan::Formato

Gera uma representação de `COleDateTimeSpan` string formatado de um objeto.

```
CString Format(LPCTSTR pFormat) const;
CString Format(UINT nID) const;
```

### <a name="parameters"></a>Parâmetros

*Pformat*<br/>
Uma seqüência de `printf` formatação semelhante à seqüência de formatação. Os códigos de formatação,`%`precedidos por um sinal `COleDateTimeSpan` de porcentagem () são substituídos pelo componente correspondente. Outros caracteres da seqüência de formatação são copiados inalterados para a seqüência retornada. O valor e o significado dos `Format` códigos de formatação estão listados abaixo:

- **%H** Horas no dia atual

- **%M** Minutos na hora atual

- **%S** Segundos no minuto atual

- **%%** Sinal percentual

Os quatro códigos de formato listados acima são os únicos códigos que o Format aceitará.

-

*nID*<br/>
O ID de recurso para a seqüência de controle de formato.

### <a name="return-value"></a>Valor retornado

A `CString` que contém o valor formatado de data/período de tempo.

### <a name="remarks"></a>Comentários

Chame essas funções para criar uma representação formatada do valor do período de tempo. Se o status `COleDateTimeSpan` deste objeto for nulo, o valor de retorno será uma seqüência de string vazia. Se o status for inválido, a seqüência de retorno será especificada pelo recurso string IDS_INVALID_DATETIMESPAN.

Segue-se uma breve descrição dos formulários para esta função:

**Formato** *(pFormat)* **)**<br/>
Este formulário formata o valor usando a seqüência de formatoque contém códigos `printf`especiais de formatação precedidos por um sinal percentual (%), como em . A seqüência de formatação é passada como um parâmetro para a função.

**Formato (** *nID* **)**<br/>
Este formulário formata o valor usando a seqüência de formatoque contém códigos `printf`especiais de formatação precedidos por um sinal percentual (%), como em . A seqüência de formatação é um recurso. O ID deste recurso de string é passado como parâmetro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#15](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_4.cpp)]

## <a name="coledatetimespangetdays"></a><a name="getdays"></a>COleDateTimeSpan::GetDays

Recupera a parte do dia deste valor de data/período de tempo.

```
LONG GetDays() const throw();
```

### <a name="return-value"></a>Valor retornado

A parte do dia deste valor de data/período de tempo.

### <a name="remarks"></a>Comentários

Os valores de retorno desta função variam entre aproximadamente - 3.615.000 e 3.615.000.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetHours](#gethours)

- [Getminutes](#getminutes)

- [Getseconds](#getseconds)

- [GetTotalDays](#gettotaldays)

- [Obterhoras totais](#gettotalhours)

- [ObterMinutos Totais](#gettotalminutes)

- [ObterTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#16](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_5.cpp)]

## <a name="coledatetimespangethours"></a><a name="gethours"></a>COleDateTimeSpan::GetHours

Recupera a parte de hora deste valor de data/período de tempo.

```
LONG GetHours() const throw();
```

### <a name="return-value"></a>Valor retornado

A parte de horas deste valor de data/período de tempo.

### <a name="remarks"></a>Comentários

Os valores de retorno desta função variam entre - 23 e 23.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [Getminutes](#getminutes)

- [Getseconds](#getseconds)

- [GetTotalDays](#gettotaldays)

- [Obterhoras totais](#gettotalhours)

- [ObterMinutos Totais](#gettotalminutes)

- [ObterTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#17](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_6.cpp)]

## <a name="coledatetimespangetminutes"></a><a name="getminutes"></a>COleDateTimeSpan::GetMinutes

Recupera a parte minuciosa deste valor de data/período de tempo.

```
LONG GetMinutes() const throw();
```

### <a name="return-value"></a>Valor retornado

A parte de minutos deste valor de data/período de tempo.

### <a name="remarks"></a>Comentários

Os valores de retorno desta função variam entre - 59 e 59.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getseconds](#getseconds)

- [GetTotalDays](#gettotaldays)

- [Obterhoras totais](#gettotalhours)

- [ObterMinutos Totais](#gettotalminutes)

- [ObterTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#18](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_7.cpp)]

## <a name="coledatetimespangetseconds"></a><a name="getseconds"></a>COleDateTimeSpan::GetSeconds

Recupera a segunda parte deste valor de data/período de tempo.

```
LONG GetSeconds() const throw();
```

### <a name="return-value"></a>Valor retornado

A parte de segundos deste valor de data/período de tempo.

### <a name="remarks"></a>Comentários

Os valores de retorno desta função variam entre - 59 e 59.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutes](#getminutes)

- [GetTotalDays](#gettotaldays)

- [Obterhoras totais](#gettotalhours)

- [ObterMinutos Totais](#gettotalminutes)

- [ObterTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#19](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_8.cpp)]

## <a name="coledatetimespangetstatus"></a><a name="getstatus"></a>COleDateTimeSpan::GetStatus

Obtém o status (validade) deste `COleDateTimeSpan` objeto.

```
DateTimeSpanStatus GetStatus() const throw();
```

### <a name="return-value"></a>Valor retornado

O status `COleDateTimeSpan` deste valor.

### <a name="remarks"></a>Comentários

O valor de retorno `DateTimeSpanStatus` é definido pelo tipo enumerado, que é definido dentro da `COleDateTimeSpan` classe.

```
enum DateTimeSpanStatus{
   valid = 0,
   invalid = 1,
   null = 2,
};
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleDateTimeSpan::valid`Indica que `COleDateTimeSpan` este objeto é válido.

- `COleDateTimeSpan::invalid`Indica que `COleDateTimeSpan` este objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleDateTimeSpan::null`Indica que `COleDateTimeSpan` este objeto é nulo, ou seja, que nenhum valor foi fornecido para este objeto. (Isso é "nulo" no sentido de banco de dados de "não ter valor", ao contrário do C++ NULL.)

O status `COleDateTimeSpan` de um objeto é inválido nos seguintes casos:

- Se este objeto tiver experimentado um estouro ou subfluxo durante `+=` uma `-=`operação de atribuição aritmética, ou seja, ou .

- Se um valor inválido for atribuído a este objeto.

- Se o status deste objeto foi explicitamente `SetStatus`definido como inválido usando .

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte [COleDateTimeSpan::operator +,](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_-) e [COleDateTimeSpan::operator +=, -=](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_eq_-_eq).

Para obter mais informações `COleDateTimeSpan` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimespangettotaldays"></a><a name="gettotaldays"></a>COleDateTimeSpan::GetTotalDays

Recupera este valor de data/período expresso em dias.

```
double GetTotalDays() const throw();
```

### <a name="return-value"></a>Valor retornado

Este valor de data/período expresso em dias. Embora esta função seja protótipo para retornar um duplo, ele sempre retornará um valor inteiro.

### <a name="remarks"></a>Comentários

Os valores de retorno desta função variam entre aproximadamente - 3,65e6 e 3,65e6.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutes](#getminutes)

- [Getseconds](#getseconds)

- [Obterhoras totais](#gettotalhours)

- [ObterMinutos Totais](#gettotalminutes)

- [ObterTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#20](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_9.cpp)]

## <a name="coledatetimespangettotalhours"></a><a name="gettotalhours"></a>COleDateTimeSpan::GetTotalHours

Recupera este valor de data/período expresso em horas.

```
double GetTotalHours() const throw();
```

### <a name="return-value"></a>Valor retornado

Este valor de data/período expresso em horas. Embora esta função seja protótipo para retornar um duplo, ele sempre retornará um valor inteiro.

### <a name="remarks"></a>Comentários

Os valores de retorno desta função variam entre aproximadamente - 8,77e7 e 8,77e7.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutes](#getminutes)

- [Getseconds](#getseconds)

- [GetTotalDays](#gettotaldays)

- [ObterMinutos Totais](#gettotalminutes)

- [ObterTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

Veja o exemplo de [GetTotalDays](#gettotaldays).

## <a name="coledatetimespangettotalminutes"></a><a name="gettotalminutes"></a>COleDateTimeSpan::GetTotalMinutes

Recupera este valor de data/período expresso em minutos.

```
double GetTotalMinutes() const throw();
```

### <a name="return-value"></a>Valor retornado

Este valor de data/período de tempo expressa em minutos. Embora esta função seja protótipo para retornar um duplo, ele sempre retornará um valor inteiro.

### <a name="remarks"></a>Comentários

Os valores de retorno desta função variam entre aproximadamente - 5.26e9 e 5.26e9.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutes](#getminutes)

- [Getseconds](#getseconds)

- [GetTotalDays](#gettotaldays)

- [Obterhoras totais](#gettotalhours)

- [ObterTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

Veja o exemplo de [GetTotalDays](#gettotaldays).

## <a name="coledatetimespangettotalseconds"></a><a name="gettotalseconds"></a>COleDateTimeSpan::GetTotalSeconds

Recupera este valor de data/período de tempo expresso em segundos.

```
double GetTotalSeconds() const throw();
```

### <a name="return-value"></a>Valor retornado

Este valor de data/período de tempo expressa em segundos. Embora esta função seja protótipo para retornar um duplo, ele sempre retornará um valor inteiro.

### <a name="remarks"></a>Comentários

Os valores de retorno desta função variam entre aproximadamente - 3.16e11 a 3.16e11.

Para outras funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutes](#getminutes)

- [Getseconds](#getseconds)

- [GetTotalDays](#gettotaldays)

- [Obterhoras totais](#gettotalhours)

- [ObterMinutos Totais](#gettotalminutes)

### <a name="example"></a>Exemplo

Veja o exemplo de [GetTotalDays](#gettotaldays).

## <a name="coledatetimespanm_span"></a><a name="m_span"></a>COleDateTimeSpan::m_span

O valor **duplo** subjacente `COleDateTime` para este objeto.

```
double m_span;
```

### <a name="remarks"></a>Comentários

Este valor expressa a data/período de tempo em dias.

> [!CAUTION]
> Alterar o valor no membro de dados `COleDateTimeSpan` **duplos** mudará o valor deste objeto. Não altera o status `COleDateTimeSpan` deste objeto.

## <a name="coledatetimespanm_status"></a><a name="m_status"></a>COleDateTimeSpan::m_status

O tipo para este membro de `DateTimeSpanStatus`dados é o `COleDateTimeSpan` tipo enumerado, que é definido dentro da classe.

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

- `COleDateTimeSpan::valid`Indica que `COleDateTimeSpan` este objeto é válido.

- `COleDateTimeSpan::invalid`Indica que `COleDateTimeSpan` este objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleDateTimeSpan::null`Indica que `COleDateTimeSpan` este objeto é nulo, ou seja, que nenhum valor foi fornecido para este objeto. (Isso é "nulo" no sentido de banco de dados de "não ter valor", ao contrário do C++ NULL.)

O status `COleDateTimeSpan` de um objeto é inválido nos seguintes casos:

- Se este objeto tiver experimentado um estouro ou subfluxo durante `+=` uma `-=`operação de atribuição aritmética, ou seja, ou .

- Se um valor inválido for atribuído a este objeto.

- Se o status deste objeto foi explicitamente definido como inválido usando [SetStatus](#setstatus).

Para obter mais informações sobre as operações que podem definir o status como inválido, consulte [COleDateTimeSpan::operator +,](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_-) e [COleDateTimeSpan::operator +=, -=](../../atl-mfc-shared/reference/coledatetime-class.md#operator_add_eq_-_eq).

> [!CAUTION]
> Este membro de dados é para situações avançadas de programação. Você deve usar as funções de membro inline [GetStatus](#getstatus) e [SetStatus](#setstatus). Consulte `SetStatus` para obter mais precauções sobre a definição explícita deste membro de dados.

Para obter mais informações `COleDateTimeSpan` sobre os limites dos valores, consulte o artigo [Data e Hora: Suporte à Automação](../../atl-mfc-shared/date-and-time-automation-support.md).

## <a name="coledatetimespanoperator-"></a><a name="operator_eq"></a>COleDateTimeSpan::operador =

Copia `COleDateTimeSpan` um valor.

```
COleDateTimeSpan& operator=(double dblSpanSrc) throw();
```

### <a name="remarks"></a>Comentários

Este operador de atribuição sobrecarregado copia o valor `COleDateTimeSpan` de data/tempo de origem para este objeto.

## <a name="coledatetimespanoperator---"></a><a name="operator_add_-"></a>COleDateTimeSpan::operador +, -

Adicionar, subtrair e alterar `COleDateTimeSpan` o sinal de valores.

```
COleDateTimeSpan operator+(const COleDateTimeSpan& dateSpan) const throw();
COleDateTimeSpan operator-(const COleDateTimeSpan& dateSpan) const throw();
COleDateTimeSpan operator-() const throw();
```

### <a name="remarks"></a>Comentários

Os dois primeiros operadores permitem adicionar e subtrair valores de data/período de tempo. O terceiro permite alterar o sinal de um valor de data/período de tempo.

Se qualquer um dos operands for nulo, o status do valor resultante `COleDateTimeSpan` é nulo.

Se um dos operands for inválido e o outro não `COleDateTimeSpan` for nulo, o status do valor resultante será inválido.

Para obter mais informações sobre os valores de status válidos, inválidos e nulos, consulte a variável [membro m_status.](#m_status)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#23](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_10.cpp)]

## <a name="coledatetimespanoperator---"></a><a name="operator_add_eq_-_eq"></a>COleDateTimeSpan::operador +=, -=

Adicione e subtraia `COleDateTimeSpan` `COleDateTimeSpan` um valor desse valor.

```
COleDateTimeSpan& operator+=(const COleDateTimeSpan dateSpan) throw();
COleDateTimeSpan& operator-=(const COleDateTimeSpan dateSpan) throw();
```

### <a name="remarks"></a>Comentários

Esses operadores permitem adicionar e subtrair valores `COleDateTimeSpan` de data/período a partir deste objeto. Se qualquer um dos operands for nulo, o status do valor resultante `COleDateTimeSpan` é nulo.

Se um dos operands for inválido e o outro não `COleDateTimeSpan` for nulo, o status do valor resultante será inválido.

Para obter mais informações sobre os valores de status válidos, inválidos e nulos, consulte a variável [membro m_status.](#m_status)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#24](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_11.cpp)]

## <a name="coledatetimespanoperator-double"></a><a name="operator_double"></a>COleDateTimeSpan::operador duplo

Converte `COleDateTimeSpan` esse valor em um **duplo**.

```
operator double() const throw();
```

### <a name="remarks"></a>Comentários

Este operador retorna o `COleDateTimeSpan` valor deste valor como um número de ponto flutuante de dias.

## <a name="coledatetimespansetdatetimespan"></a><a name="setdatetimespan"></a>COleDateTimeSpan::SetDateTimeSpan

Define o valor deste valor de data/período de tempo.

```
void SetDateTimeSpan(LONG lDays, int nHours, int nMins, int nSecs) throw();
```

### <a name="parameters"></a>Parâmetros

*lDays,* *nHours,* *nMins,* *nSecs*<br/>
Indique os valores de período de data `COleDateTimeSpan` e período de tempo a serem copiados para este objeto.

### <a name="remarks"></a>Comentários

Para obter funções que consultam o valor de um `COleDateTimeSpan` objeto, consulte as seguintes funções de membro:

- [GetDays](#getdays)

- [GetHours](#gethours)

- [Getminutes](#getminutes)

- [Getseconds](#getseconds)

- [GetTotalDays](#gettotaldays)

- [Obterhoras totais](#gettotalhours)

- [ObterMinutos Totais](#gettotalminutes)

- [ObterTotalSeconds](#gettotalseconds)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#21](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_12.cpp)]

## <a name="coledatetimespansetstatus"></a><a name="setstatus"></a>COleDateTimeSpan::SetStatus

Define o status (validade) `COleDateTimeSpan` deste objeto.

```
void SetStatus(DateTimeSpanStatus status) throw();
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O novo valor `COleDateTimeSpan` de status para este objeto.

### <a name="remarks"></a>Comentários

O valor *do* parâmetro Status `DateTimeSpanStatus` é definido pelo tipo enumerado, que é definido dentro da `COleDateTimeSpan` classe.

```
enum DateTimeSpanStatus{
   valid = 0,
   invalid = 1,
   null = 2,
   };
```

Para obter uma breve descrição desses valores de status, consulte a lista a seguir:

- `COleDateTimeSpan::valid`Indica que `COleDateTimeSpan` este objeto é válido.

- `COleDateTimeSpan::invalid`Indica que `COleDateTimeSpan` este objeto é inválido; ou seja, seu valor pode estar incorreto.

- `COleDateTimeSpan::null`Indica que `COleDateTimeSpan` este objeto é nulo, ou seja, que nenhum valor foi fornecido para este objeto. (Isso é "nulo" no sentido de banco de dados de "não ter valor", ao contrário do C++ NULL.)

   > [!CAUTION]
   > Esta função é para situações avançadas de programação. Esta função não altera os dados neste objeto. Na maioria das vezes, será usado para definir o status **como nulo** ou **inválido**. Observe que o operador de atribuição[(operador =](#operator_eq)) e [o SetDateTimeSpan](#setdatetimespan) definem o status do objeto com base no valor de origem(s).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#22](../../atl-mfc-shared/codesnippet/cpp/coledatetimespan-class_13.cpp)]

## <a name="see-also"></a>Confira também

[Classe COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)<br/>
[Classe CTime](../../atl-mfc-shared/reference/ctime-class.md)<br/>
[Classe CTimeSpan](../../atl-mfc-shared/reference/ctimespan-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
