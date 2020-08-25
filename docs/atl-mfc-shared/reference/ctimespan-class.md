---
title: Classe CTimeSpan
ms.date: 10/18/2018
f1_keywords:
- CTimeSpan
- ATLTIME/ATL::CTimeSpan
- ATLTIME/ATL::CTimeSpan::CTimeSpan
- ATLTIME/ATL::CTimeSpan::Format
- ATLTIME/ATL::CTimeSpan::GetDays
- ATLTIME/ATL::CTimeSpan::GetHours
- ATLTIME/ATL::CTimeSpan::GetMinutes
- ATLTIME/ATL::CTimeSpan::GetSeconds
- ATLTIME/ATL::CTimeSpan::GetTimeSpan
- ATLTIME/ATL::CTimeSpan::GetTotalHours
- ATLTIME/ATL::CTimeSpan::GetTotalMinutes
- ATLTIME/ATL::CTimeSpan::GetTotalSeconds
- ATLTIME/ATL::CTimeSpan::Serialize64
helpviewer_keywords:
- elapsed time, CTimeSpan object
- timespan
- time span
- CTimeSpan class
- shared classes, CTimeSpan
- time, elapsed
ms.assetid: ee1e42f6-1839-477a-8435-fb26ad475140
ms.openlocfilehash: 0c13aa0d8f6c46db3b018283ab2a408a3f9531e1
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832016"
---
# <a name="ctimespan-class"></a>Classe CTimeSpan

Uma quantidade de tempo, que é armazenada internamente como o número de segundos no período de tempo.

## <a name="syntax"></a>Sintaxe

```
class CTimeSpan
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTimeSpan::CTimeSpan](#ctimespan)|Constrói `CTimeSpan` objetos de várias maneiras.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTimeSpan:: Format](#format)|Converte um `CTimeSpan` em uma cadeia de caracteres formatada.|
|[CTimeSpan:: GetDays](#getdays)|Retorna um valor que representa o número de dias completos neste `CTimeSpan` .|
|[CTimeSpan:: getHours](#gethours)|Retorna um valor que representa o número de horas no dia atual (-23 a 23).|
|[CTimeSpan:: getminutos](#getminutes)|Retorna um valor que representa o número de minutos na hora atual (-59 até 59).|
|[CTimeSpan:: getsegundos](#getseconds)|Retorna um valor que representa o número de segundos no minuto atual (-59 até 59).|
|[CTimeSpan:: gettimespan](#gettimespan)|Retorna o valor do `CTimeSpan` objeto.|
|[CTimeSpan::GetTotalHours](#gettotalhours)|Retorna um valor que representa o número total de horas completas neste `CTimeSpan` .|
|[CTimeSpan::GetTotalMinutes](#gettotalminutes)|Retorna um valor que representa o número total de minutos completos neste `CTimeSpan` .|
|[CTimeSpan::GetTotalSeconds](#gettotalseconds)|Retorna um valor que representa o número total de segundos completos neste `CTimeSpan` .|
|[CTimeSpan::Serialize64](#serialize64)|Serializa dados de ou para um arquivo morto.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador +-](#operator_add_-)|Adiciona e subtrai `CTimeSpan` objetos.|
|[operador + =-=](#operator_add_eq_-_eq)|Adiciona e subtrai um `CTimeSpan` objeto de e para isso `CTimeSpan` .|
|[Operator = = < etc.](#ctimespan_comparison_operators)|Compara dois valores de tempo relativos.|

## <a name="remarks"></a>Comentários

`CTimeSpan` Não tem uma classe base.

`CTimeSpan` as funções convertem segundos em várias combinações de dias, horas, minutos e segundos.

O `CTimeSpan` objeto é armazenado em uma estrutura de **__time64_t** , que é de 8 bytes.

Uma classe complementar, [CTime](../../atl-mfc-shared/reference/ctime-class.md), representa uma hora absoluta.

As `CTime` `CTimeSpan` classes e não são projetadas para derivação. Como não há nenhuma função virtual, o tamanho dos dois `CTime` `CTimeSpan` objetos e é exatamente 8 bytes. A maioria das funções de membro é embutida.

Para obter mais informações sobre como usar `CTimeSpan` o, consulte os artigos [data e hora](../../atl-mfc-shared/date-and-time.md)e [Gerenciamento de hora](../../c-runtime-library/time-management.md) na *referência da biblioteca de tempo de execução*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltime. h

## <a name="ctimespan-comparison-operators"></a><a name="ctimespan_comparison_operators"></a> Operadores de comparação de CTimeSpan

Operadores de comparação.

```
bool operator==(CTimeSpan span) const throw();
bool operator!=(CTimeSpan span) const throw();
bool operator<(CTimeSpan span) const throw();
bool operator>(CTimeSpan span) const throw();
bool operator<=(CTimeSpan span) const throw();
bool operator>=(CTimeSpan span) const throw();
```

### <a name="parameters"></a>parâmetros

*compreende*<br/>
O objeto a ser comparado.

### <a name="return-value"></a>Valor Retornado

Esses operadores comparam dois valores de tempo relativos. Eles retornarão TRUE se a condição for true; caso contrário, FALSE.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#169](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_1.cpp)]

## <a name="ctimespanctimespan"></a><a name="ctimespan"></a> CTimeSpan::CTimeSpan

Constrói `CTimeSpan` objetos de várias maneiras.

```
CTimeSpan() throw();
CTimeSpan(__time64_t time) throw();

CTimeSpan(
    LONG lDays,
    int nHours,
    int nMins,
    int nSecs) throw();
```

### <a name="parameters"></a>parâmetros

*timeSpanSrc*<br/>
Um `CTimeSpan` objeto que já existe.

*time*<br/>
Um valor de **__time64_t** hora, que é o número de segundos no período de tempo.

*lDays*, *nHours*, *nMins*, *nSecs*<br/>
Dias, horas, minutos e segundos, respectivamente.

### <a name="remarks"></a>Comentários

Todos esses construtores criam um novo `CTimeSpan` objeto inicializado com o tempo relativo especificado. Cada construtor é descrito abaixo:

- `CTimeSpan( );` Constrói um objeto não inicializado `CTimeSpan` .

- `CTimeSpan( const CTimeSpan& );` Constrói um `CTimeSpan` objeto a partir de outro `CTimeSpan` valor.

- `CTimeSpan( __time64_t );` Constrói um `CTimeSpan` objeto a partir de um tipo de **__time64_t** .

- `CTimeSpan( LONG, int, int, int );` Constrói um `CTimeSpan` objeto de componentes com cada componente restrito aos seguintes intervalos:

   |Componente|Intervalo|
   |---------------|-----------|
   |*lDays*|0-25000 (aproximadamente)|
   |*nHours*|0-23|
   |*nMins*|0-59|
   |*nSecs*|0-59|

Observe que a versão de depuração do biblioteca MFC afirma se um ou mais dos componentes do dia útil estão fora do intervalo. É sua responsabilidade validar os argumentos antes de chamar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#162](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_2.cpp)]

## <a name="ctimespanformat"></a><a name="format"></a> CTimeSpan:: Format

Gera uma cadeia de caracteres formatada que corresponde a isso `CTimeSpan` .

```
CString Format(LPCSTR pFormat) const;
CString Format(LPCTSTR pszFormat) const;
CString Format(UINT nID) const;
```

### <a name="parameters"></a>parâmetros

*pFormat*, *pszFormat*<br/>
Uma cadeia de caracteres de formatação semelhante à `printf` cadeia de caracteres de formatação. Os códigos de formatação, precedidos por um sinal de porcentagem ( `%` ), são substituídos pelo `CTimeSpan` componente correspondente. Outros caracteres na cadeia de caracteres de formatação são copiados inalterados para a cadeia de caracteres retornada. O valor e o significado dos códigos de formatação para `Format` estão listados abaixo:

- **% D** Total de dias neste `CTimeSpan`

- **% H** Horas no dia atual

- **% M** Minutos na hora atual

- **% S** Segundos no minuto atual

- **%%** Sinal de porcentagem

*nID*<br/>
A ID da cadeia de caracteres que identifica esse formato.

### <a name="return-value"></a>Valor Retornado

Um `CString` objeto que contém a hora formatada.

### <a name="remarks"></a>Comentários

A versão de depuração da biblioteca verifica os códigos de formatação e as declarações se o código não estiver na lista acima.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#163](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_3.cpp)]

## <a name="ctimespangetdays"></a><a name="getdays"></a> CTimeSpan:: GetDays

Retorna um valor que representa o número de dias completos neste `CTimeSpan` .

```
LONGLONG GetDays() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número de dias de 24 horas completos no período de tempo. Esse valor pode ser negativo se o período de tempo for negativo.

### <a name="remarks"></a>Comentários

Observe que o horário de Verão pode causar `GetDays` o retorno de um resultado potencialmente surpreendente. Por exemplo, quando o horário de verão estiver em vigor, `GetDays` o relatará o número de dias entre 1º de abril e 1 a 29, e não 30, porque um dia em abril é reduzido em uma hora e, portanto, não conta como um dia completo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#164](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_4.cpp)]

## <a name="ctimespangethours"></a><a name="gethours"></a> CTimeSpan:: getHours

Retorna um valor que representa o número de horas no dia atual (-23 a 23).

```
LONG GetHours() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número de horas no dia atual. O intervalo é de-23 a 23.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#165](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_5.cpp)]

## <a name="ctimespangetminutes"></a><a name="getminutes"></a> CTimeSpan:: getminutos

Retorna um valor que representa o número de minutos na hora atual (-59 até 59).

```
LONG GetMinutes() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número de minutos na hora atual. O intervalo é de-59 a 59.

### <a name="example"></a>Exemplo

Consulte o exemplo de [getHours](#gethours).

## <a name="ctimespangetseconds"></a><a name="getseconds"></a> CTimeSpan:: getsegundos

Retorna um valor que representa o número de segundos no minuto atual (-59 até 59).

```
LONG GetSeconds() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número de segundos no minuto atual. O intervalo é de-59 a 59.

### <a name="example"></a>Exemplo

Consulte o exemplo de [getHours](#gethours).

## <a name="ctimespangettimespan"></a><a name="gettimespan"></a> CTimeSpan:: gettimespan

Retorna o valor do `CTimeSpan` objeto.

```
__ time64_t GetTimeSpan() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o valor atual do `CTimeSpan` objeto.

## <a name="ctimespangettotalhours"></a><a name="gettotalhours"></a> CTimeSpan::GetTotalHours

Retorna um valor que representa o número total de horas completas neste `CTimeSpan` .

```
LONGLONG GetTotalHours() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número total de horas completas neste `CTimeSpan` .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#166](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_6.cpp)]

## <a name="ctimespangettotalminutes"></a><a name="gettotalminutes"></a> CTimeSpan::GetTotalMinutes

Retorna um valor que representa o número total de minutos completos neste `CTimeSpan` .

```
LONGLONG GetTotalMinutes() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número total de minutos completos neste `CTimeSpan` .

### <a name="example"></a>Exemplo

Consulte o exemplo de [GetTotalHours](#gettotalhours).

## <a name="ctimespangettotalseconds"></a><a name="gettotalseconds"></a> CTimeSpan::GetTotalSeconds

Retorna um valor que representa o número total de segundos completos neste `CTimeSpan` .

```
LONGLONG GetTotalSeconds() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número total de segundos completos neste `CTimeSpan` .

### <a name="example"></a>Exemplo

Consulte o exemplo de [GetTotalHours](#gettotalhours).

## <a name="ctimespanoperator---"></a><a name="operator_add_-"></a> CTimeSpan:: operator +,-

Adiciona e subtrai `CTimeSpan` objetos.

```
CTimeSpan operator+(CTimeSpan span) const throw();
CTimeSpan operator-(CTimeSpan span) const throw();
```

### <a name="parameters"></a>parâmetros

*compreende*<br/>
O valor a ser adicionado ao `CTimeSpan` objeto.

### <a name="return-value"></a>Valor Retornado

Um `CTimeSpan` objeto que representa o resultado da operação.

### <a name="remarks"></a>Comentários

Esses dois operadores permitem adicionar e subtrair `CTimeSpan` objetos entre si.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#167](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_7.cpp)]

## <a name="ctimespanoperator---"></a><a name="operator_add_eq_-_eq"></a> CTimeSpan:: operator + =,-=

Adiciona e subtrai um `CTimeSpan` objeto de e para isso `CTimeSpan` .

```
CTimeSpan& operator+=(CTimeSpan span) throw();
CTimeSpan& operator-=(CTimeSpan span) throw();
```

### <a name="parameters"></a>parâmetros

*compreende*<br/>
O valor a ser adicionado ao `CTimeSpan` objeto.

### <a name="return-value"></a>Valor Retornado

O `CTimeSpan` objeto atualizado.

### <a name="remarks"></a>Comentários

Esses operadores permitem adicionar e subtrair um `CTimeSpan` objeto de e para isso `CTimeSpan` .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#168](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_8.cpp)]

## <a name="ctimespanserialize64"></a><a name="serialize64"></a> CTimeSpan::Serialize64

> [!NOTE]
> Esse método só está disponível em projetos MFC.

Serializa os dados associados à variável de membro de ou para um arquivo morto.

```
CArchive& Serialize64(CArchive& ar);
```

### <a name="parameters"></a>parâmetros

*multi-hop*<br/>
O `CArchive` objeto que você deseja atualizar.

### <a name="return-value"></a>Valor Retornado

O `CArchive` objeto atualizado.

## <a name="see-also"></a>Confira também

[asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)<br/>
[_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)<br/>
[strftime, wcsftime, _strftime_l, _wcsftime_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)<br/>
[time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
