---
title: Classe time_get | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7c3db9edd974d111881b17b6f1a53c1b4ac3b336
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="timeget-class"></a>Classe time_get

A classe de modelo descreve um objeto que pode servir como uma faceta de localidade para controlar conversões de sequências do tipo `CharType` em valores de tempo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType,
    class InputIterator = istreambuf_iterator<CharType>>
class time_get : public time_base;
```

### <a name="parameters"></a>Parâmetros

`CharType` O tipo usado dentro de um programa para codificar caracteres.

`InputIterator` O iterador da qual os valores de tempo são lidos.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[time_get](#time_get)|O construtor para objetos do tipo `time_get`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
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

## <a name="char_type"></a>  time_get::char_type

Um tipo que é usado para descrever um caractere usado por uma localidade.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **CharType**.

## <a name="date_order"></a>  time_get::date_order

Retorna a ordem de data usada por uma faceta.

```cpp
dateorder date_order() const;
```

### <a name="return-value"></a>Valor de retorno

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

## <a name="do_date_order"></a>  time_get::do_date_order

Uma função membro virtual protegida que é chamada para retornar a ordem de data usada por uma faceta.

```cpp
virtual dateorder do_date_order() const;
```

### <a name="return-value"></a>Valor de retorno

A ordem de data usada por uma faceta.

### <a name="remarks"></a>Comentários

A função membro virtual protegida retorna um valor do tipo **time_base::dateorder**, que descreve a ordem na qual os componentes de data são correspondidos por [do_get_date](#do_get_date). Nessa implementação, o valor é **time_base::mdy**, correspondente às datas do formato 2 de dezembro de 1979.

### <a name="example"></a>Exemplo

Consulte o exemplo de [date_order](#date_order), que chama `do_date_order`.

## <a name="do_get"></a>  time_get::do_get

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

`first` Um iterador de entrada que indica o início da sequência de converter.

`last` Um iterador de entrada que indica o final da sequência.

`iosbase` Um objeto de fluxo.

`state` Um campo na iosbase onde os elementos apropriados de máscara de bits são definidos para indicar erros.

`ptm` Um ponteiro para a estrutura de tempo em que o tempo é a ser armazenado.

`fmt` Um caractere de especificador de conversão.

`mod` Um caractere de modificador opcional.

### <a name="return-value"></a>Valor de retorno

Retorna um iterador que designa o primeiro elemento não convertido. Uma falha de conversão define `ios_base::failbit` em `state` e retorna `first`.

### <a name="remarks"></a>Comentários

A função de membro virtual converte e ignora um ou mais elementos no intervalo de entrada [`first`, `last`) para determinar os valores armazenados em um ou mais membros do `*pt`. Uma falha de conversão define `ios_base::failbit` em `state` e retorna `first`. Caso contrário, a função retornará um iterador que designa o primeiro elemento não convertido.

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

## <a name="do_get_date"></a>  time_get::do_get_date

Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como a data produzida pelo especificador *x* de `strftime`.

```cpp
virtual iter_type do_get_date(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Um formato de sinalizador que quando o conjunto de indica que o símbolo de moeda é opcional. Caso contrário, é necessário.

`state` Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações de data são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro virtual protegida tenta corresponder elementos sequenciais, começando pelo primeiro na sequência [`first`, `last`] até ter reconhecido um campo de entrada de data completo e não vazio. Se for bem-sucedido, ele converte este campo em seu valor equivalente que os componentes **tm::tm\_seg**, **tm::tm\_dia**, e **tm::tm\_ano** e armazena os resultados em `ptm->tm_mon`, `ptm->tm_day`, e `ptm->tm_year`, respectivamente. Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de data. Caso contrário, a função define `iosbase::failbit` em `state`. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de data válido. Em ambos os casos, se o valor retornado for igual a `last`, a função definirá `ios_base::eofbit` em `state`.

O formato do campo de entrada de data é dependente da localidade. Para a localidade padrão, o campo de entrada de data tem o formato MMM DD, YYYY, em que:

- MMM é correspondido pela chamada a [get_monthname](#get_monthname), considerando o mês.

- DD é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [1, 31], considerando o dia do mês.

- YYYY é correspondido pela chamada a [get_year](#get_year), considerando o ano.

Os espaços e as vírgulas do literal devem corresponder a elementos correspondentes na sequência de entrada.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_date](#get_date), que chama `do_get_date`.

## <a name="do_get_monthname"></a>  time_get::do_get_monthname

Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do mês.

```cpp
virtual iter_type do_get_monthname(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Não usado.

`state` Um parâmetro de saída que define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações do mês são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro virtual protegida tenta corresponder elementos sequenciais, começando pelo primeiro na sequência [`first`, `last`] até ter reconhecido um campo de entrada de mês completo e não vazio. Se for bem-sucedido, ele converte este campo em seu valor equivalente como o componente **tm::tm\_seg**e armazena o resultado em `ptm->tm_mon`. Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de mês. Caso contrário, a função define `ios_base::failbit` na *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de mês válido. Em ambos os casos, se o valor de retorno é igual a `last`, os conjuntos de função `ios_base::eofbit` na *estado*.

O campo de entrada de mês é uma sequência que corresponde à sequência mais longa de um conjunto de sequências específicas à localidade, como jan, janeiro, fev, fevereiro e assim por diante. O valor convertido é o número de meses desde janeiro.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_monthname](#get_monthname), que chama `do_get_monthname`.

## <a name="do_get_time"></a>  time_get::do_get_time

Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como a data produzida pelo especificador *X* de `strftime`.

```cpp
virtual iter_type do_get_time(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Não usado.

`state` Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações de data são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro virtual protegida tenta corresponder elementos sequenciais, começando pelo primeiro na sequência [`first`, `last`] até ter reconhecido um campo de entrada de hora completo e não vazio. Se for bem-sucedido, ele converte este campo em seu valor equivalente que os componentes **tm::tm_hour**, **tm::tm_min**, e **tm::tm_sec**e armazena os resultados em `ptm->tm_hour`, `ptm->tm_min`, e `ptm->tm_sec`, respectivamente. Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de hora. Caso contrário, a função define `ios_base::failbit` na *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de hora válido. Em ambos os casos, se o valor de retorno é igual a `last`, os conjuntos de função `ios_base::eofbit` na *estado*.

Nessa implementação, o campo de entrada de hora tem o formato HH:MM:SS, em que:

- HH é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [0, 24], considerando a hora do dia.

- MM é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [0, 60], fornecendo os minutos após a hora.

- SS é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [0, 60], fornecendo os segundos após o minuto.

Os dois-pontos do literal devem corresponder a elementos correspondentes na sequência de entrada.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_time](#get_time), que chama `do_get_time`.

## <a name="do_get_weekday"></a>  time_get::do_get_weekday

Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do dia da semana.

```cpp
virtual iter_type do_get_weekday(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Um formato de sinalizador que quando o conjunto de indica que o símbolo de moeda é opcional. Caso contrário, é necessário.

`state` Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações de dia da semana são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro virtual protegida tenta corresponder elementos sequenciais, começando em `first` na sequência [`first`, `last`] até ter reconhecido um campo de entrada de dia da semana completo e não vazio. Se for bem-sucedido, ele converte este campo em seu valor equivalente como o componente **tm::tm\_wdiadasemana**e armazena o resultado em `ptm->tm_wday`. Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de dia da semana. Caso contrário, a função define `ios_base::failbit` na *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de dia da semana válido. Em ambos os casos, se o valor de retorno é igual a `last`, os conjuntos de função `ios_base::eofbit` na *estado*.

O campo de entrada de dia da semana é uma sequência que corresponde à sequência mais longa de um conjunto de sequências específicas à localidade, como dom, domingo, seg, segunda-feira e assim por diante. O valor convertido é o número de dias desde domingo.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_weekday](#get_weekday), que chama `do_get_weekday`.

## <a name="do_get_year"></a>  time_get::do_get_year

Uma função membro virtual protegida que é chamada para analisar uma cadeia de caracteres como o nome do ano.

```cpp
virtual iter_type do_get_year(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Um formato de sinalizador que quando o conjunto de indica que o símbolo de moeda é opcional. Caso contrário, é necessário.

`state` Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações de ano são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro virtual protegida tenta corresponder elementos sequenciais, começando em `first` na sequência [`first`, `last`] até ter reconhecido um campo de entrada de ano completo e não vazio. Se for bem-sucedido, ele converte este campo em seu valor equivalente como o componente **tm::tm\_ano**e armazena o resultado em `ptm->tm_year`. Ela retorna um iterador que designa o primeiro elemento após o campo de entrada de ano. Caso contrário, a função define `ios_base::failbit` na *estado*. Ela retorna um iterador que designa o primeiro elemento após qualquer prefixo de um campo de entrada de ano válido. Em ambos os casos, se o valor de retorno é igual a `last`, os conjuntos de função `ios_base::eofbit` na *estado*.

O campo de entrada de ano é uma sequência de dígitos decimais cujo valor numérico correspondente deve estar no intervalo [1900, 2036]. O valor armazenado é esse valor menos 1900. Nessa implementação, os valores no intervalo [69, 136] representam o intervalo de anos [1969, 2036]. Valores no intervalo [0, 69] também são permitidos, mas podem representar o intervalo de anos [1900, 1969] ou [2000, 2069], dependendo do ambiente de translação específico.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get_year](#get_year), que chama `do_get_year`.

## <a name="get"></a>  time_get::get

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

`first` Iterador de entrada que indica qual começa a sequência a ser convertido.

`last` Iterador de entrada que indica o final da sequência a ser convertido.

`iosbase` O fluxo.

`state` Os elementos de bitmask apropriadas são definidos para o estado de fluxo indicar erros.

`ptm` Ponteiro para a estrutura de tempo em que o tempo é a ser armazenado.

`fmt` Um caractere de especificador de conversão.

`mod` Um caractere de modificador opcional.

`fmt_first` Aponta para onde iniciar as diretivas de formato.

`fmt_last` Pontos no final das diretivas de formato.

### <a name="return-value"></a>Valor de retorno

Retorna um iterador para o primeiro caractere depois que os dados que foi usados para atribuir a estrutura de hora `*ptm`.

### <a name="remarks"></a>Comentários

A primeira função membro retorna `do_get(first, last, iosbase, state, ptm, fmt, mod)`.

A segunda função membro chama `do_get` sob o controle do formato delimitado por `[fmt_first, fmt_last)`. Ela trata o formato como uma sequência de campos, em que cada uma delas determina a conversão de zero ou mais elementos de entrada delimitados por `[first, last)`. Ela retorna um iterador que designa o primeiro elemento não convertido. Há três tipos de campos:

Um por cento (%) no formato, seguido por um modificador opcional `mod` no conjunto de EOQ [#], seguido por um especificador de conversão `fmt`, substitui `first` com o valor retornado por `do_get(first, last, iosbase, state, ptm, fmt, mod)`. Uma falha de conversão define `ios_base::failbit` em `state` e retorna.

Um elemento de espaço em branco no formato ignora após zero ou mais elementos de espaço em branco de entrada.

Qualquer outro elemento no formato deve corresponder ao próximo elemento de entrada, que é ignorado. Uma falha de correspondência define `ios_base::failbit` em `state` e retorna.

## <a name="get_date"></a>  time_get::get_date

Analisa uma cadeia de caracteres como a data produzida pelo especificador *x* para `strftime`.

```cpp
iter_type get_date(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Um formato de sinalizador que quando o conjunto de indica que o símbolo de moeda é opcional. Caso contrário, é necessário.

`state` Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações de data são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro retorna [do_get_date](#do_get_date)( `first`, `last`, `iosbase`, `state`, `ptm`).

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

## <a name="get_monthname"></a>  time_get::get_monthname

Analisa uma cadeia de caracteres como o nome do mês.

```cpp
iter_type get_monthname(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Não usado.

`state` Um parâmetro de saída que define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações do mês são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro retorna [do_get_monthname](#do_get_monthname)( `first`, `last`, `iosbase`, `state`, `ptm`).

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

## <a name="get_time"></a>  time_get::get_time

Analisa uma cadeia de caracteres como a data produzida pelo especificador *X* para `strftime`.

```cpp
iter_type get_time(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Não usado.

`state` Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações de data são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro retorna [do_get_time](#do_get_time)( `first`, `last`, `iosbase`, `state`, `ptm`).

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

## <a name="get_weekday"></a>  time_get::get_weekday

Analisa uma cadeia de caracteres como o nome do dia da semana.

```cpp
iter_type get_weekday(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Um formato de sinalizador que quando o conjunto de indica que o símbolo de moeda é opcional. Caso contrário, é necessário.

`state` Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações de dia da semana são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro retorna [do_get_weekday](#do_get_weekday)( `first`, `last`, `iosbase`, `state`, `ptm`).

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

## <a name="get_year"></a>  time_get::get_year

Analisa uma cadeia de caracteres como o nome do ano.

```cpp
iter_type get_year(iter_type first,
    iter_type last,
    ios_base& iosbase,
    ios_base::iostate& state,
    tm* ptm) const;
```

### <a name="parameters"></a>Parâmetros

`first` Início da sequência a ser convertida de endereçamento de iterador de entrada.

`last` O final da sequência a ser convertida de endereçamento de iterador de entrada.

`iosbase` Um formato de sinalizador que quando o conjunto de indica que o símbolo de moeda é opcional. Caso contrário, é necessário.

`state` Define os elementos de bitmask apropriado para o estado de fluxo de acordo com se as operações foram bem-sucedidas.

`ptm` Um ponteiro para onde as informações de ano são a ser armazenado.

### <a name="return-value"></a>Valor de retorno

Um iterador de entrada que trata o primeiro elemento após o campo de entrada.

### <a name="remarks"></a>Comentários

A função membro retorna [do_get_year](#do_get_year)( `first`, `last`, `iosbase`, `state`, `ptm`).

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

## <a name="iter_type"></a>  time_get::iter_type

Um tipo que descreve um iterador de entrada.

```cpp
typedef InputIterator iter_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **InputIterator**.

## <a name="time_get"></a>  time_get::time_get

O construtor para objetos do tipo `time_get`.

```cpp
explicit time_get(size_t refs = 0);
```

### <a name="parameters"></a>Parâmetros

`refs` Valor inteiro usado para especificar o tipo de gerenciamento de memória para o objeto.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro `refs` e sua significância são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \> 1: esses valores não são definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com **locale::**[facet](../standard-library/locale-class.md#facet_class)( `refs`).

## <a name="see-also"></a>Consulte também

[\<locale>](../standard-library/locale.md)<br/>
[Classe time_base](../standard-library/time-base-class.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
