---
title: Classe time_get
ms.date: 11/04/2016
f1_keywords:
- xloctime/std::time_get
- locale/std::time_get::char_type
- locale/std::time_get::iter_type
- locale/std::time_get::date_order
- locale/std::time_get::do_date_order
- locale/std::time_get::do_get
- locale/std::time_get::do_get_date
- locale/std::time_get::do_get_monthname
- locale/std::time_get::do_get_time
- locale/std::time_get::do_get_weekday
- locale/std::time_get::do_get_year
- locale/std::time_get::get
- locale/std::time_get::get_date
- locale/std::time_get::get_monthname
- locale/std::time_get::get_time
- locale/std::time_get::get_weekday
- locale/std::time_get::get_year
helpviewer_keywords:
- std::time_get [C++]
- std::time_get [C++], char_type
- std::time_get [C++], iter_type
- std::time_get [C++], date_order
- std::time_get [C++], do_date_order
- std::time_get [C++], do_get
- std::time_get [C++], do_get_date
- std::time_get [C++], do_get_monthname
- std::time_get [C++], do_get_time
- std::time_get [C++], do_get_weekday
- std::time_get [C++], do_get_year
- std::time_get [C++], get
- std::time_get [C++], get_date
- std::time_get [C++], get_monthname
- std::time_get [C++], get_time
- std::time_get [C++], get_weekday
- std::time_get [C++], get_year
ms.assetid: 869d5f5b-dbab-4628-8333-bdea7e272023
ms.openlocfilehash: 9aebdaffc8bf3754bdbda08247f72ae08475711f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368044"
---
# <a name="time_get-class"></a>Classe time_get

O modelo de classe descreve um objeto que pode servir como uma faceta local para controlar conversões de seqüências de valores de tipo `CharType` para tempo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType,
    class InputIterator = istreambuf_iterator<CharType>>
class time_get : public time_base;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres.

*Inseriterador*\
O iterador do qual os valores de tempo são lidos.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[time_get](#time_get)|O construtor para objetos do tipo `time_get`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo que é usado para descrever um caractere usado por uma localidade.|
|[iter_type](#iter_type)|Um tipo que descreve um iterador de entrada.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[date_order](#date_order)|Retorna a ordem de data usada por uma faceta.|
|[do_date_order](#do_date_order)|Uma função membro virtual protegida que é chamada para retornar a ordem de data usada por uma faceta.|
|[do_get](#do_get)|Lê e converte dados de caractere em um valor de tempo.|
|[do_get_date](#do_get_date)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como a data gerada pelo especificador `x` para `strftime`.|
|[do_get_monthname](#do_get_monthname)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do mês.|
|[do_get_time](#do_get_time)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como a data gerada pelo especificador `X` para `strftime`.|
|[do_get_weekday](#do_get_weekday)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do dia da semana.|
|[do_get_year](#do_get_year)|Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do ano.|
|[get](#get)|Lê de uma origem de dados de caracteres e converte esses dados em uma hora que é armazenada em um struct de tempo.|
|[get_date](#get_date)|Analise uma cadeia de caracteres como a data gerada pelo especificador `x` para `strftime`.|
|[get_monthname](#get_monthname)|Analisa uma cadeia de caracteres como o nome do mês.|
|[get_time](#get_time)|Analise uma cadeia de caracteres como a data gerada pelo especificador `X` para `strftime`.|
|[get_weekday](#get_weekday)|Analisa uma cadeia de caracteres como o nome do dia da semana.|
|[get_year](#get_year)|Analisa uma cadeia de caracteres como o nome do ano.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="time_getchar_type"></a><a name="char_type"></a>time_get:char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo **CharType**.

## <a name="time_getdate_order"></a><a name="date_order"></a>time_get::date_order

Retorna a ordem de data usada por uma faceta.

```cpp
dateorder date_order() const;
```

### <a name="return-value"></a>Valor retornado

A ordem de data usada por uma faceta.

### <a name="remarks"></a>Comentários

A função membro retorna [do_date_order](#do_date_order).

### <a name="example"></a>Exemplo

```cpp
// time_get_date_order.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;
void po( char *p )
{
   locale loc( p );

   time_get <char>::dateorder order = use_facet <time_get <char> >( loc ).date_order ( );
   cout << loc.name( );
   switch (order){
      case time_base::dmy: cout << "(day, month, year)" << endl;
      break;
      case time_base::mdy: cout << "(month, day, year)" << endl;
      break;
      case time_base::ydm: cout << "(year, day, month)" << endl;
      break;
      case time_base::ymd: cout << "(year, month, day)"<< endl;
      break;
      case time_base::no_order: cout << "(no_order)"<< endl;
      break;
   }
}

int main( )
{
   po( "C" );
   po( "german" );
   po( "English_Britain" );
}
```

```Output
C(month, day, year)
German_Germany.1252(day, month, year)
English_United Kingdom.1252(day, month, year)
```

## <a name="time_getdo_date_order"></a><a name="do_date_order"></a>time_get::do_date_order

Uma função membro virtual protegida que é chamada para retornar a ordem de data usada por uma faceta.

```cpp
virtual dateorder do_date_order() const;
```

### <a name="return-value"></a>Valor retornado

A ordem de data usada por uma faceta.

### <a name="remarks"></a>Comentários

A função membro virtual protegida retorna um valor do tipo **time_base::dateorder**, que descreve a ordem na qual os componentes de data são correspondidos por [do_get_date](#do_get_date). Nessa implementação, o valor é **time_base::mdy**, correspondente às datas do formato 2 de dezembro de 1979.

### <a name="example"></a>Exemplo

Consulte o exemplo de [date_order](#date_order), que chama `do_date_order`.

## <a name="time_getdo_get"></a><a name="do_get"></a>time_get::do_get

Lê e converte dados de caractere em um valor de tempo. Aceita um especificador e modificador de conversão.

```cpp
virtual iter_type
    do_get(
iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm,
    char fmt,
    char mod) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Um iterador de Entrada que indica o início da sequência a ser convertido.

*Última*\
Um iterador de Entrada que indica o final da sequência.

*iosbase*\
Um objeto de fluxo.

*Estado*\
Um campo no iosbase onde os elementos apropriados da máscara de bit são definidos para indicar erros.

*Ptm*\
Um ponteiro para a estrutura de tempo na qual o tempo deve ser armazenado.

*Fmt*\
Um caractere especificador de conversão.

*Mod*\
Um caractere modificador opcional.

### <a name="return-value"></a>Valor retornado

Retorna um iterador que designa o primeiro elemento não convertido. Uma falha `ios_base::failbit` de `state` conversão define e retorna *primeiro*.

### <a name="remarks"></a>Comentários

A função membro virtual converte e pula um ou`first` `last`mais elementos de entrada na faixa `*pt`[ , ) para determinar os valores armazenados em um ou mais membros de . Uma falha `ios_base::failbit` de `state` conversão define e retorna *primeiro*. Caso contrário, a função retornará um iterador que designa o primeiro elemento não convertido.

Os especificadores de conversão são:

`'a'` ou `'A'` – tem o mesmo comportamento que [time_get::get_weekday](#get_weekday).

`'b'`, `'B'` ou `'h'` – tem o mesmo comportamento que [time_get::get_monthname](#get_monthname).

`'c'` – tem o mesmo comportamento que `"%b %d %H : %M : %S %Y"`.

`'C'` – converte um campo de entrada decimal no intervalo [0, 99] no valor `val` e armazena `val * 100 - 1900` em `pt-&tm_year`.

`'d'` ou `'e'` – converte um campo de entrada decimal no intervalo [1, 31] e armazena o valor em `pt-&tm_mday`.

`'D'` – tem o mesmo comportamento que `"%m / %d / %y"`.

`'H'` – converte um campo de entrada decimal no intervalo [0, 23] e armazena o valor em `pt-&tm_hour`.

`'I'` – converte um campo de entrada decimal no intervalo [0, 11] e armazena o valor em `pt-&tm_hour`.

`'j'` – converte um campo de entrada decimal no intervalo [1, 366] e armazena o valor em `pt-&tm_yday`.

`'m'` – converte um campo de entrada decimal no intervalo [1, 12] no valor `val` e armazena `val - 1` em e armazena o valor em `pt-&tm_mon`.

`'M'` – converte um campo de entrada decimal no intervalo [0, 59] e armazena o valor em `pt-&tm_min`.

`'n'` ou `'t'` – tem o mesmo comportamento que `" "`.

`'p'` – converte “AM” ou “am” em zero e “PM” ou “PM” em 12 e adiciona esse valor a `pt-&tm_hour`.

`'r'` – tem o mesmo comportamento que `"%I : %M : %S %p"`.

`'R'` – tem o mesmo comportamento que `"%H %M"`.

`'S'` – converte um campo de entrada decimal no intervalo [0, 59] e armazena o valor em `pt-&tm_sec`.

`'T'` ou `'X'` – tem o mesmo comportamento que `"%H : %M : S"`.

`'U'` – converte um campo de entrada decimal no intervalo [0, 53] e armazena o valor em `pt-&tm_yday`.

`'w'` – converte um campo de entrada decimal no intervalo [0, 6] e armazena o valor em `pt-&tm_wday`.

`'W'` – converte um campo de entrada decimal no intervalo [0, 53] e armazena o valor em `pt-&tm_yday`.

`'x'` – tem o mesmo comportamento que `"%d / %m / %y"`.

`'y'` – converte um campo de entrada decimal no intervalo [0, 99] no valor `val` e armazena `val < 69  val + 100 : val` em `pt-&tm_year`.

`'Y'` – tem o mesmo comportamento que [time_get::get_year](#get_year).

Todos os outros especificadores de conversão definem `ios_base::failbit` em `state` e retornam. Nessa implementação, qualquer modificador não tem nenhum efeito.

## <a name="time_getdo_get_date"></a><a name="do_get_date"></a>time_get::do_get_date

Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como a data produzida pelo especificador *x* de `strftime`.

```cpp
virtual iter_type do_get_date(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório.

*Estado*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de data devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro virtual protegida tenta corresponder elementos sequenciais, começando pelo primeiro na sequência [`first`, `last`] até ter reconhecido um campo de entrada de data completo e não vazio. Se for bem-sucedido, converte este campo para seu valor equivalente como os componentes **\_tm::tm mon**, **tm::tm\_day**e **\_tm::tm year**, e armazena os resultados em `ptm->tm_mon`, `ptm->tm_day`e `ptm->tm_year`, respectivamente. Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de data. Caso contrário, a `iosbase::failbit` função se configura no *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de data válido. Em ambos os casos, se o valor `ios_base::eofbit` de retorno for igual ao *último,* a função se configura no *estado*.

O formato do campo de entrada de data é dependente da localidade. Para a localidade padrão, o campo de entrada de data tem o formato MMM DD, YYYY, em que:

- MMM é correspondido pela chamada a [get_monthname](#get_monthname), considerando o mês.

- DD é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [1, 31], considerando o dia do mês.

- YYYY é correspondido pela chamada a [get_year](#get_year), considerando o ano.

Os espaços e as vírgulas do literal devem corresponder a elementos correspondentes na sequência de entrada.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_date](#get_date), que chama `do_get_date`.

## <a name="time_getdo_get_monthname"></a><a name="do_get_monthname"></a>time_get::do_get_monthname

Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do mês.

```cpp
virtual iter_type do_get_monthname(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Não utilizado.

*Estado*\
Um parâmetro de saída que define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de mês devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro virtual protegida tenta corresponder elementos sequenciais, começando pelo primeiro na sequência [`first`, `last`] até ter reconhecido um campo de entrada de mês completo e não vazio. Se for bem-sucedido, converte este campo para seu valor equivalente como o componente `ptm->tm_mon` **tm::tm\_mon**, e armazena o resultado em . Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de mês. Caso contrário, a `ios_base::failbit` função se configura no *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de mês válido. Em ambos os casos, se o valor `ios_base::eofbit` de retorno for igual ao *último,* a função se configura no *estado*.

O campo de entrada de mês é uma sequência que corresponde à sequência mais longa de um conjunto de sequências específicas à localidade, como jan, janeiro, fev, fevereiro e assim por diante. O valor convertido é o número de meses desde janeiro.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_monthname](#get_monthname), que chama `do_get_monthname`.

## <a name="time_getdo_get_time"></a><a name="do_get_time"></a>time_get::do_get_time

Uma função de membro virtual protegido que é chamada para analisar uma `strftime`seqüência como a data produzida pelo *especificador X* para .

```cpp
virtual iter_type do_get_time(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Não utilizado.

*Estado*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de data devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro virtual protegida tenta corresponder elementos sequenciais, começando pelo primeiro na sequência [`first`, `last`] até ter reconhecido um campo de entrada de hora completo e não vazio. Se for bem sucedido, converte este campo `tm::tm_hour`em `tm::tm_min`seu `tm::tm_sec`valor equivalente como `ptm->tm_hour` `ptm->tm_min`componentes, e armazena os resultados em , e `ptm->tm_sec`, respectivamente. Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de hora. Caso contrário, a `ios_base::failbit` função se configura no *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de hora válido. Em ambos os casos, se o valor `ios_base::eofbit` de retorno for igual ao *último,* a função se configura no *estado*.

Nessa implementação, o campo de entrada de hora tem o formato HH:MM:SS, em que:

- HH é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [0, 24], considerando a hora do dia.

- MM é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [0, 60], fornecendo os minutos após a hora.

- SS é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [0, 60], fornecendo os segundos após o minuto.

Os dois-pontos do literal devem corresponder a elementos correspondentes na sequência de entrada.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_time](#get_time), que chama `do_get_time`.

## <a name="time_getdo_get_weekday"></a><a name="do_get_weekday"></a>time_get::do_get_weekday

Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do dia da semana.

```cpp
virtual iter_type do_get_weekday(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório.

*Estado*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de dia da semana devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função de membro protegido virtual tenta combinar elementos seqüenciais a partir *do início* da seqüência até `first` `last`que tenha reconhecido um campo de entrada completo e não vazio durante a semana. Se for bem-sucedido, converte este campo para seu valor equivalente como o componente `ptm->tm_wday` **tm::tm\_wday**, e armazena o resultado em . Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de dia da semana. Caso contrário, a `ios_base::failbit` função se configura no *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de dia da semana válido. Em ambos os casos, se o valor `ios_base::eofbit` de retorno for igual ao *último,* a função se configura no *estado*.

O campo de entrada de dia da semana é uma sequência que corresponde à sequência mais longa de um conjunto de sequências específicas à localidade, como dom, domingo, seg, segunda-feira e assim por diante. O valor convertido é o número de dias desde domingo.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_weekday](#get_weekday), que chama `do_get_weekday`.

## <a name="time_getdo_get_year"></a><a name="do_get_year"></a>time_get::do_get_year

Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do ano.

```cpp
virtual iter_type do_get_year(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório.

*Estado*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de ano devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função de membro protegido virtual tenta combinar elementos seqüenciais a partir *do início* da seqüência até `first` `last`que tenha reconhecido um campo de entrada de ano completo e não vazio. Se for bem-sucedido, converte este campo para seu valor equivalente como o `ptm->tm_year`componente **tm::tm\_ano**, e armazena o resultado em . Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de ano. Caso contrário, a `ios_base::failbit` função se configura no *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de ano válido. Em ambos os casos, se o valor `ios_base::eofbit` de retorno for igual ao *último,* a função se configura no *estado*.

O campo de entrada de ano é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [1900, 2036]. O valor armazenado é esse valor menos 1900. Nessa implementação, os valores no intervalo [69, 136] representam o intervalo de anos [1969, 2036]. Valores no intervalo [0, 69] também são permitidos, mas podem representar o intervalo de anos [1900, 1969] ou [2000, 2069], dependendo do ambiente de translação específico.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_year](#get_year), que chama `do_get_year`.

## <a name="time_getget"></a><a name="get"></a>time_get::get

Lê de uma origem de dados de caracteres e converte esses dados em uma hora que é armazenada em um struct de tempo. A primeira função aceita um especificador e modificador de conversão, enquanto a segunda aceita vários.

```cpp
iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm,
    char fmt,
    char mod) const;

iter_type get(
    iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm,
    char_type* fmt_first,
    char_type* fmt_last) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que indica o início da sequência a ser convertido.

*Última*\
Iterador de entrada que indica o final da sequência a ser convertido.

*iosbase*\
O fluxo.

*Estado*\
Os elementos de bitmask apropriados são definidos para o estado de fluxo para indicar erros.

*Ptm*\
Ponteiro para a estrutura de tempo na qual o tempo deve ser armazenado.

*Fmt*\
Um caractere especificador de conversão.

*Mod*\
Um caractere modificador opcional.

*fmt_first*\
Aponta para o início das diretivas de formato.

*fmt_last*\
Aponta para o final das diretivas de formato.

### <a name="return-value"></a>Valor retornado

Retorna um iterador ao primeiro caractere após os dados que foram `*ptm`usados para atribuir a estrutura de tempo .

### <a name="remarks"></a>Comentários

A primeira função membro retorna `do_get(first, last, iosbase, state, ptm, fmt, mod)`.

A segunda função membro chama `do_get` sob o controle do formato delimitado por `[fmt_first, fmt_last)`. Ela trata o formato como uma sequência de campos, em que cada uma delas determina a conversão de zero ou mais elementos de entrada delimitados por `[first, last)`. Ela retorna um iterador que designa o primeiro elemento não convertido. Há três tipos de campos:

A% (%) no formato, seguido por um *mod* modificador opcional no conjunto [EOQ#], seguido por um especificador `do_get(first, last, iosbase, state, ptm, fmt, mod)`de conversão *fmt*, substitui *primeiro* com o valor retornado por . Uma falha `ios_base::failbit` de conversão define em *estado* e retorna.

Um elemento de espaço em branco no formato ignora após zero ou mais elementos de espaço em branco de entrada.

Qualquer outro elemento no formato deve corresponder ao próximo elemento de entrada, que é ignorado. Uma falha `ios_base::failbit` de partida define em *estado* e retorna.

## <a name="time_getget_date"></a><a name="get_date"></a>time_get:get_date

Analisa uma cadeia de caracteres como a data produzida pelo especificador *x* para `strftime`.

```cpp
iter_type get_date(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório.

*Estado*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de data devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função do`first`membro `last` `iosbase`retorna `state` `ptm` [do_get_date](#do_get_date)( , , , , ).

Observe que os meses são contados de 0 a 11.

### <a name="example"></a>Exemplo

```cpp
// time_get_get_date.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;
int main( )
{
   locale loc;
   basic_stringstream< char > pszGetF, pszPutF, pszGetI, pszPutI;
   ios_base::iostate st = 0;
   struct tm t;
   memset(&t, 0, sizeof(struct tm));

   pszGetF << "July 4, 2000";
   pszGetF.imbue( loc );
   basic_istream<char>::_Iter i = use_facet <time_get<char> >
   (loc).get_date(basic_istream<char>::_Iter(pszGetF.rdbuf( ) ),
            basic_istream<char>::_Iter(0), pszGetF, st, &t);

   if ( st & ios_base::failbit )
      cout << "time_get("<< pszGetF.rdbuf( )->str( )<< ") FAILED on char: " << *i << endl;
   else

      cout << "time_get("<< pszGetF.rdbuf( )->str( )<< ") ="
      << "\ntm_sec: " << t.tm_sec
      << "\ntm_min: " << t.tm_min
      << "\ntm_hour: " << t.tm_hour
      << "\ntm_mday: " << t.tm_mday
      << "\ntm_mon: " << t.tm_mon
      << "\ntm_year: " << t.tm_year
      << "\ntm_wday: " << t.tm_wday
      << "\ntm_yday: " << t.tm_yday
      << "\ntm_isdst: " << t.tm_isdst
      << endl;
}
```

```Output
time_get(July 4, 2000) =
tm_sec: 0
tm_min: 0
tm_hour: 0
tm_mday: 4
tm_mon: 6
tm_year: 100
tm_wday: 0
tm_yday: 0
tm_isdst: 0
```

## <a name="time_getget_monthname"></a><a name="get_monthname"></a>time_get::get_monthname

Analisa uma cadeia de caracteres como o nome do mês.

```cpp
iter_type get_monthname(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Não utilizado.

*Estado*\
Um parâmetro de saída que define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de mês devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função do`first`membro `last` `iosbase`retorna `state` `ptm` [do_get_monthname](#do_get_monthname)( , , , , ).

### <a name="example"></a>Exemplo

```cpp
// time_get_get_monthname.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;
int main( )
{
   locale loc ( "French" );
   basic_stringstream<char> pszGetF, pszPutF, pszGetI, pszPutI;
   ios_base::iostate st = 0;
   struct tm t;
   memset( &t, 0, sizeof( struct tm ) );

   pszGetF << "juillet";
   pszGetF.imbue( loc );
   basic_istream<char>::_Iter i = use_facet <time_get <char> >
   (loc).get_monthname(basic_istream<char>::_Iter(pszGetF.rdbuf( )),
              basic_istream<char>::_Iter(0), pszGetF, st, &t);

   if (st & ios_base::failbit)
      cout << "time_get("<< pszGetF.rdbuf( )->str( )<< ") FAILED on char: " << *i << endl;
   else

      cout << "time_get("<< pszGetF.rdbuf( )->str( )<< ") ="
      << "\ntm_sec: " << t.tm_sec
      << "\ntm_min: " << t.tm_min
      << "\ntm_hour: " << t.tm_hour
      << "\ntm_mday: " << t.tm_mday
      << "\ntm_mon: " << t.tm_mon
      << "\ntm_year: " << t.tm_year
      << "\ntm_wday: " << t.tm_wday
      << "\ntm_yday: " << t.tm_yday
      << "\ntm_isdst: " << t.tm_isdst
      << endl;
}
```

```Output
time_get(juillet) =
tm_sec: 0
tm_min: 0
tm_hour: 0
tm_mday: 0
tm_mon: 6
tm_year: 0
tm_wday: 0
tm_yday: 0
tm_isdst: 0
```

## <a name="time_getget_time"></a><a name="get_time"></a>time_get:get_time

Analisa uma seqüência como a data produzida `strftime`pelo *especificador X* para .

```cpp
iter_type get_time(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Não utilizado.

*Estado*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de data devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função do`first`membro `last` `iosbase`retorna `state` `ptm` [do_get_time](#do_get_time)( , , , , ).

### <a name="example"></a>Exemplo

```cpp
// time_get_get_time.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;
int main( )
{
   locale loc;
   basic_stringstream<char> pszGetF, pszPutF, pszGetI, pszPutI;
   ios_base::iostate st = 0;
   struct tm t;
   memset( &t, 0, sizeof( struct tm ) );

   pszGetF << "11:13:20";
   pszGetF.imbue( loc );
   basic_istream<char>::_Iter i = use_facet
      <time_get <char> >
      (loc).get_time(basic_istream<char>::_Iter(pszGetF.rdbuf( )),
               basic_istream<char>::_Iter(0), pszGetF, st, &t);

   if (st & ios_base::failbit)
      cout << "time_get::get_time("<< pszGetF.rdbuf( )->str( )<< ") FAILED on char: " << *i << endl;
   else

      cout << "time_get::get_time("<< pszGetF.rdbuf( )->str( )<< ") ="
      << "\ntm_sec: " << t.tm_sec
      << "\ntm_min: " << t.tm_min
      << "\ntm_hour: " << t.tm_hour
      << endl;
}
```

```Output
time_get::get_time(11:13:20) =
tm_sec: 20
tm_min: 13
tm_hour: 11
```

## <a name="time_getget_weekday"></a><a name="get_weekday"></a>time_get:get_weekday

Analisa uma cadeia de caracteres como o nome do dia da semana.

```cpp
iter_type get_weekday(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório.

*Estado*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de dia da semana devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função do`first`membro `last` `iosbase`retorna `state` `ptm` [do_get_weekday](#do_get_weekday)( , , , , ).

### <a name="example"></a>Exemplo

```cpp
// time_get_get_weekday.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;
int main( )
{
   locale loc ( "French" );
   basic_stringstream< char > pszGetF, pszPutF, pszGetI, pszPutI;
   ios_base::iostate st = 0;
   struct tm t;
   memset( &t, 0, sizeof( struct tm ) );

   pszGetF << "mercredi";
   pszGetF.imbue(loc);
   basic_istream<char>::_Iter i = use_facet
      <time_get<char> >
      (loc).get_weekday(basic_istream<char>::_Iter(pszGetF.rdbuf( )),
               basic_istream<char>::_Iter(0), pszGetF, st, &t);

   if (st & ios_base::failbit)
      cout << "time_get::get_time("<< pszGetF.rdbuf( )->str( )<< ") FAILED on char: " << *i << endl;
   else

      cout << "time_get::get_time("<< pszGetF.rdbuf( )->str( )<< ") ="
      << "\ntm_wday: " << t.tm_wday
      << endl;
}
```

```Output
time_get::get_time(mercredi) =
tm_wday: 3
```

## <a name="time_getget_year"></a><a name="get_year"></a>time_get:get_year

Analisa uma cadeia de caracteres como o nome do ano.

```cpp
iter_type get_year(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

*Primeiro*\
Iterador de entrada que trata o início da sequência a ser convertido.

*Última*\
Iterador de entrada que trata o fim da sequência a ser convertido.

*iosbase*\
Um sinalizador de formato que quando definido indica que o símbolo de moeda é opcional; caso contrário, será obrigatório.

*Estado*\
Define os elementos de bitmask apropriados para o estado de fluxo, dependendo se as operações foram bem-sucedidas.

*Ptm*\
Um ponteiro para o local em que as informações de ano devem ser armazenadas.

### <a name="return-value"></a>Valor retornado

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função do`first`membro `last` `iosbase`retorna `state` `ptm` [do_get_year](#do_get_year)( , , , , ).

### <a name="example"></a>Exemplo

```cpp
// time_get_get_year.cpp
// compile with: /EHsc
#include <locale>
#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;
int main( )
{
   locale loc;
   basic_stringstream<char> pszGetF, pszPutF, pszGetI, pszPutI;
   ios_base::iostate st = 0;
   struct tm t;
   memset( &t, 0, sizeof( struct tm ) );

   pszGetF << "1928";

   pszGetF.imbue( loc );
   basic_istream<char>::_Iter i = use_facet
      <time_get<char> >
      (loc).get_year(basic_istream<char>::_Iter(pszGetF.rdbuf( )),
               basic_istream<char>::_Iter(0), pszGetF, st, &t);

   if (st & ios_base::failbit)
      cout << "time_get::get_year("<< pszGetF.rdbuf( )->str( )<< ") FAILED on char: " << *i << endl;
   else

      cout << "time_get::get_year("<< pszGetF.rdbuf( )->str( )<< ") ="
      << "\ntm_year: " << t.tm_year
      << endl;
}
```

```Output
time_get::get_year(1928) =
tm_year: 28
```

## <a name="time_getiter_type"></a><a name="iter_type"></a>time_get:iter_type

Um tipo que descreve um iterador de entrada.

```cpp
typedef InputIterator iter_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **InputIterator**.

## <a name="time_gettime_get"></a><a name="time_get"></a>time_get:time_get

O construtor para objetos do tipo `time_get`.

```cpp
explicit time_get(size_t refs = 0);
```

### <a name="parameters"></a>Parâmetros

*Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro *dos árbitros* e sua significância são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \>1: Esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com **localidade::**[faceta](../standard-library/locale-class.md#facet_class)(`refs`).

## <a name="see-also"></a>Confira também

[\<local>](../standard-library/locale.md)\
[classe time_base](../standard-library/time-base-class.md)\
[Segurança de threads na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
