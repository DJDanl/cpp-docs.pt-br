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
ms.openlocfilehash: 14aa5eb52e2c631a92e40ae7053c566284e00e57
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317498"
---
# <a name="ctimespan-class"></a>Classe CTimeSpan

Uma quantidade de tempo, que é armazenado internamente como o número de segundos no período de tempo.

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
|[CTimeSpan::Formato](#format)|Converte `CTimeSpan` um em uma seqüência formatada.|
|[Ctimespan::getDays](#getdays)|Retorna um valor que representa o número `CTimeSpan`de dias completos neste .|
|[CTimeSpan::getHours](#gethours)|Retorna um valor que representa o número de horas no dia atual (-23 a 23).|
|[CTimeSpan::getMinutes](#getminutes)|Retorna um valor que representa o número de minutos na hora atual (-59 a 59).|
|[CTimeSpan::getSeconds](#getseconds)|Retorna um valor que representa o número de segundos no minuto atual (-59 a 59).|
|[CTimeSpan::getTimespan](#gettimespan)|Retorna o valor `CTimeSpan` do objeto.|
|[Ctimespan::getTotalHours](#gettotalhours)|Retorna um valor que representa o número `CTimeSpan`total de horas completas neste .|
|[CTimeSpan::getTotalMinutes](#gettotalminutes)|Retorna um valor que representa o número `CTimeSpan`total de minutos completos neste .|
|[CTimeSpan::getTotalSeconds](#gettotalseconds)|Retorna um valor que representa o número `CTimeSpan`total de segundos completos neste .|
|[CTimeSpan::Serialize64](#serialize64)|Serializa dados para ou a partir de um arquivo.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador + -](#operator_add_-)|Adiciona e subtrai objetos. `CTimeSpan`|
|[operador += -=](#operator_add_eq_-_eq)|Adiciona e subtrai `CTimeSpan` um objeto `CTimeSpan`para e a partir disso .|
|[operador == < etc.](#ctimespan_comparison_operators)|Compara dois valores de tempo relativos.|

## <a name="remarks"></a>Comentários

`CTimeSpan`não tem uma classe base.

`CTimeSpan`funções convertem segundos em várias combinações de dias, horas, minutos e segundos.

O `CTimeSpan` objeto é armazenado em uma estrutura **__time64_t,** que é de 8 bytes.

Uma classe companheira, [CTime,](../../atl-mfc-shared/reference/ctime-class.md)representa um tempo absoluto.

As `CTime` `CTimeSpan` classes e não são projetadas para derivação. Como não há funções virtuais, `CTime` o `CTimeSpan` tamanho de ambos e objetos é exatamente de 8 bytes. A maioria das funções dos membros estão em linha.

Para obter mais `CTimeSpan`informações sobre como usar, consulte os artigos [Data e Hora](../../atl-mfc-shared/date-and-time.md)e Gerenciamento de [Tempo](../../c-runtime-library/time-management.md) na Referência da Biblioteca em Tempo *de Execução*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atltime.h

## <a name="ctimespan-comparison-operators"></a><a name="ctimespan_comparison_operators"></a>Operadores de comparação CTimeSpan

Operadores de comparação.

```
bool operator==(CTimeSpan span) const throw();
bool operator!=(CTimeSpan span) const throw();
bool operator<(CTimeSpan span) const throw();
bool operator>(CTimeSpan span) const throw();
bool operator<=(CTimeSpan span) const throw();
bool operator>=(CTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*<br/>
O objeto a comparar.

### <a name="return-value"></a>Valor retornado

Esses operadores comparam dois valores de tempo relativos. Eles retornam TRUE se a condição for verdadeira; caso contrário, FALSO.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#169](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_1.cpp)]

## <a name="ctimespanctimespan"></a><a name="ctimespan"></a>CTimeSpan::CTimeSpan

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

### <a name="parameters"></a>Parâmetros

*timeSpanSrc*<br/>
Um `CTimeSpan` objeto que já existe.

*time*<br/>
Um **__time64_t** valor de tempo, que é o número de segundos no período de tempo.

*lDays,* *nHours,* *nMins,* *nSecs*<br/>
Dias, horas, minutos e segundos, respectivamente.

### <a name="remarks"></a>Comentários

Todos esses construtores criam `CTimeSpan` um novo objeto inicializado com o tempo relativo especificado. Cada construtor é descrito abaixo:

- `CTimeSpan( );`Constrói um objeto `CTimeSpan` não inicializado.

- `CTimeSpan( const CTimeSpan& );`Constrói um `CTimeSpan` objeto `CTimeSpan` a partir de outro valor.

- `CTimeSpan( __time64_t );`Constrói um `CTimeSpan` objeto de um **tipo __time64_t.**

- `CTimeSpan( LONG, int, int, int );`Constrói um `CTimeSpan` objeto a partir de componentes com cada componente restrito às seguintes faixas:

   |Componente|Intervalo|
   |---------------|-----------|
   |*lDays*|0-25.000 (aproximadamente)|
   |*nHoras*|0-23|
   |*nMins*|0-59|
   |*nSecs*|0-59|

Observe que a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma se um ou mais dos componentes do dia-a-dia estão fora de alcance. É sua responsabilidade validar os argumentos antes de ligar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#162](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_2.cpp)]

## <a name="ctimespanformat"></a><a name="format"></a>CTimeSpan::Formato

Gera uma seqüência formatada que corresponde a isso `CTimeSpan`.

```
CString Format(LPCSTR pFormat) const;
CString Format(LPCTSTR pszFormat) const;
CString Format(UINT nID) const;
```

### <a name="parameters"></a>Parâmetros

*pFormat*, *pszFormat*<br/>
Uma seqüência de `printf` formatação semelhante à seqüência de formatação. Os códigos de formatação,`%`precedidos por um sinal `CTimeSpan` de porcentagem () são substituídos pelo componente correspondente. Outros caracteres da seqüência de formatação são copiados inalterados para a seqüência retornada. O valor e o significado dos `Format` códigos de formatação estão listados abaixo:

- **%D** Total de dias neste`CTimeSpan`

- **%H** Horas no dia atual

- **%M** Minutos na hora atual

- **%S** Segundos no minuto atual

- **%%** Sinal percentual

*nID*<br/>
O ID da string que identifica este formato.

### <a name="return-value"></a>Valor retornado

Um `CString` objeto que contém o tempo formatado.

### <a name="remarks"></a>Comentários

A versão Debug da biblioteca verifica os códigos de formatação e afirma se o código não está na lista acima.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#163](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_3.cpp)]

## <a name="ctimespangetdays"></a><a name="getdays"></a>Ctimespan::getDays

Retorna um valor que representa o número `CTimeSpan`de dias completos neste .

```
LONGLONG GetDays() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de dias completos de 24 horas no período de tempo. Esse valor pode ser negativo se o intervalo de tempo for negativo.

### <a name="remarks"></a>Comentários

Observe que o horário `GetDays` de verão pode causar o retorno de um resultado potencialmente surpreendente. Por exemplo, quando o DST está em vigor, `GetDays` relata o número de dias entre 1º de abril e 1º de maio como 29, não 30, porque um dia em abril é encurtado em uma hora e, portanto, não conta como um dia completo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#164](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_4.cpp)]

## <a name="ctimespangethours"></a><a name="gethours"></a>CTimeSpan::getHours

Retorna um valor que representa o número de horas no dia atual (-23 a 23).

```
LONG GetHours() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de horas no dia atual. O alcance é de -23 a 23.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#165](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_5.cpp)]

## <a name="ctimespangetminutes"></a><a name="getminutes"></a>CTimeSpan::getMinutes

Retorna um valor que representa o número de minutos na hora atual (-59 a 59).

```
LONG GetMinutes() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de minutos na hora atual. O alcance é de -59 a 59.

### <a name="example"></a>Exemplo

Veja o exemplo de [GetHours](#gethours).

## <a name="ctimespangetseconds"></a><a name="getseconds"></a>CTimeSpan::getSeconds

Retorna um valor que representa o número de segundos no minuto atual (-59 a 59).

```
LONG GetSeconds() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de segundos no minuto atual. O alcance é de -59 a 59.

### <a name="example"></a>Exemplo

Veja o exemplo de [GetHours](#gethours).

## <a name="ctimespangettimespan"></a><a name="gettimespan"></a>CTimeSpan::getTimespan

Retorna o valor `CTimeSpan` do objeto.

```
__ time64_t GetTimeSpan() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor `CTimeSpan` atual do objeto.

## <a name="ctimespangettotalhours"></a><a name="gettotalhours"></a>Ctimespan::getTotalHours

Retorna um valor que representa o número `CTimeSpan`total de horas completas neste .

```
LONGLONG GetTotalHours() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número total de `CTimeSpan`horas completas neste .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#166](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_6.cpp)]

## <a name="ctimespangettotalminutes"></a><a name="gettotalminutes"></a>CTimeSpan::getTotalMinutes

Retorna um valor que representa o número `CTimeSpan`total de minutos completos neste .

```
LONGLONG GetTotalMinutes() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número total de `CTimeSpan`minutos completos neste .

### <a name="example"></a>Exemplo

Veja o exemplo de [GetTotalHours](#gettotalhours).

## <a name="ctimespangettotalseconds"></a><a name="gettotalseconds"></a>CTimeSpan::getTotalSeconds

Retorna um valor que representa o número `CTimeSpan`total de segundos completos neste .

```
LONGLONG GetTotalSeconds() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número total de `CTimeSpan`segundos completos neste .

### <a name="example"></a>Exemplo

Veja o exemplo de [GetTotalHours](#gettotalhours).

## <a name="ctimespanoperator---"></a><a name="operator_add_-"></a>CTimeSpan::operador +, -

Adiciona e subtrai objetos. `CTimeSpan`

```
CTimeSpan operator+(CTimeSpan span) const throw();
CTimeSpan operator-(CTimeSpan span) const throw();
```

### <a name="parameters"></a>Parâmetros

*Span*<br/>
O valor a `CTimeSpan` ser adicionado ao objeto.

### <a name="return-value"></a>Valor retornado

Um `CTimeSpan` objeto representando o resultado da operação.

### <a name="remarks"></a>Comentários

Esses dois operadores permitem que `CTimeSpan` você adicione e subtraia objetos entre e para o outro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#167](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_7.cpp)]

## <a name="ctimespanoperator---"></a><a name="operator_add_eq_-_eq"></a>CTimeSpan::operador +=, -=

Adiciona e subtrai `CTimeSpan` um objeto `CTimeSpan`para e a partir disso .

```
CTimeSpan& operator+=(CTimeSpan span) throw();
CTimeSpan& operator-=(CTimeSpan span) throw();
```

### <a name="parameters"></a>Parâmetros

*Span*<br/>
O valor a `CTimeSpan` ser adicionado ao objeto.

### <a name="return-value"></a>Valor retornado

O `CTimeSpan` objeto atualizado.

### <a name="remarks"></a>Comentários

Esses operadores permitem que você `CTimeSpan` adicione e subtraia um objeto para e a partir disso `CTimeSpan`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATLMFC_Utilities#168](../../atl-mfc-shared/codesnippet/cpp/ctimespan-class_8.cpp)]

## <a name="ctimespanserialize64"></a><a name="serialize64"></a>CTimeSpan::Serialize64

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

[asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)<br/>
[_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)<br/>
[strftime, wcsftime, _strftime_l, _wcsftime_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)<br/>
[time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
