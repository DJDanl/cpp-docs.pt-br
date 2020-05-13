---
title: Classe duration
ms.date: 03/27/2016
f1_keywords:
- chrono/std::chrono::duration
- chrono/std::chrono::duration::duration
- chrono/std::chrono::duration::count
- chrono/std::chrono::duration::max
- chrono/std::chrono::duration::min
- chrono/std::chrono::duration::zero
ms.assetid: 06b863b3-65be-4ded-a72e-6e1eb1531077
helpviewer_keywords:
- std::chrono [C++], duration
ms.openlocfilehash: 3669935bf094f476ca24a8170a0388dff29e0a0c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368762"
---
# <a name="duration-class"></a>Classe duration

Descreve um tipo que contém um *intervalo de tempo*, que é um tempo decorrido entre dois pontos de tempo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Rep, class Period = ratio<1>>
class duration;
template <class Rep, class Period>
class duration;
template <class Rep, class Period1, class Period2>
class duration <duration<Rep, Period1>, Period2>;
```

## <a name="remarks"></a>Comentários

O argumento de modelo `Rep` descreve o tipo que é usado para manter o número de tiques do relógio no intervalo. O argumento de modelo `Period` é uma instanciação de [taxa](../standard-library/ratio.md) que descreve o tamanho do intervalo que representa cada tique.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|Typedef duration::period|Representa um sinônimo para o parâmetro de modelo `Period`.|
|Typedef duration::rep|Representa um sinônimo para o parâmetro de modelo `Rep`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Duração](#duration)|Constrói um objeto `duration`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[contagem](#count)|Retorna o número de tiques do relógio no intervalo de tempo.|
|[max](#max)|Estático. Retorna o valor máximo permitido do parâmetro de modelo `Ref`.|
|[Min](#min)|Estático. Retorna o menor valor permitido do parâmetro de modelo `Ref`.|
|[Zero](#zero)|Estático. Na verdade, retorna `Rep`(0).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[duração::operador-](#operator-)|Retorna uma cópia do objeto `duration` junto com uma contagem de tiques negados.|
|[duração::operador--](#operator--)|Diminui a contagem de tiques armazenados.|
|[duração::operador=](#op_eq)|Reduz o módulo de contagem de tiques armazenados de um valor especificado.|
|[duration::operator*=](#op_star_eq)|Multiplica de contagem de tiques armazenados por um valor especificado.|
|[duração::operador/=](#op_div_eq)|Divide a contagem de tiques armazenados pela contagem de tiques de um objeto `duration` especificado.|
|[duração::operador+](#op_add)|Retorna `*this`.|
|[duração::operador++](#op_add_add)|Aumenta a contagem de tiques armazenados.|
|[duração::operador+=](#op_add_eq)|Adiciona a contagem de tiques de um objeto `duration` especificado para a contagem de tiques armazenados.|
|[duração::operador-=](#operator-_eq)|Subtrai a contagem de tiques de um objeto `duration` especificado da contagem de tiques armazenados.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<crono>

**Namespace:** std::chrono

## <a name="durationcount"></a><a name="count"></a>duração::contagem

Recupera o número de tiques do relógio no intervalo de tempo.

```cpp
constexpr Rep count() const;
```

### <a name="return-value"></a>Valor retornado

O número de tiques do relógio no intervalo de tempo.

## <a name="durationduration-constructor"></a><a name="duration"></a>duração: construtor :duration

Constrói um objeto `duration`.

```cpp
constexpr duration() = default;

template <class Rep2>
constexpr explicit duration(const Rep2& R);

template <class Rep2, class Period2>
constexpr duration(const duration<Rep2, Period2>& Dur);
```

### <a name="parameters"></a>Parâmetros

*Rep2*\
Um tipo aritmético para representar o número de tiques.

*Período2*\
Uma especialização de modelo `std::ratio` para representar o período de tiques em unidades de segundos.

*R*\
O número de tiques de período padrão.

*Dur*\
O número de carrapatos do período especificado pelo *Período2*.

### <a name="remarks"></a>Comentários

O construtor padrão constrói um objeto que não foi inicializado. A inicialização de valor usando chaves vazias inicializa um objeto que representa um intervalo de tempo de zero tique do relógio.

O segundo, um construtor de argumento de modelo, constrói *R* um objeto que representa `std::ratio<1>`um intervalo de tempo de marcadores de relógio R usando um período padrão de . Para evitar a repetição da contagem de carrapatos, é um erro construir um objeto de duração `duration::rep` a partir de um tipo de representação *Rep2* que pode ser tratado como um tipo de ponto flutuante quando não pode ser tratado como um tipo de ponto flutuante.

O terceiro, construtor de argumento de dois modelos, constrói um objeto que representa um intervalo de tempo cujo comprimento é o intervalo de tempo especificado por *Dur*. Para evitar o truncamento de contagens de tique, é um erro construir um objeto de duração de outro objeto de duração cujo tipo é *incomensurável* com o tipo de destino.

Um tipo de duração `D1` é *incomensurável* com outro tipo de duração `D2` se `D2` não puder ser tratado como um tipo de ponto flutuante e [ratio_divide\<D1::period, D2::period>::type::den](../standard-library/ratio.md) não for 1.

A menos que *o Rep2* seja implicitamente conversível `rep` e `treat_as_floating_point<rep>` *mantenha-se verdadeiro* ou `treat_as_floating_point<Rep2>` *mantenha falso,* o segundo construtor não participa na resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

A menos que nenhum estouro seja induzido na conversão e for `treat_as_floating_point<rep>`*verdadeiro* ou `ratio_divide<Period2, period>::den` for igual a 1 e `treat_as_floating_point<Rep2>`*falso*, o terceiro construtor não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

## <a name="durationmax"></a><a name="max"></a>duração::máx

O método estático que retorna o limite superior para valores de tipo de parâmetro de modelo `Ref`.

```cpp
static constexpr duration max();
```

### <a name="return-value"></a>Valor retornado

Na verdade, retorna `duration(duration_values<rep>::max())`.

## <a name="durationmin"></a><a name="min"></a>duração::min

O método estático que retorna o limite inferior para valores de tipo de parâmetro de modelo `Ref`.

```cpp
static constexpr duration min();
```

### <a name="return-value"></a>Valor retornado

Na verdade, retorna `duration(duration_values<rep>::min())`.

## <a name="durationoperator-"></a><a name="operator-"></a>duração::operador-

Retorna uma cópia do objeto `duration` junto com uma contagem de tiques negados.

```cpp
constexpr duration operator-() const;
```

## <a name="durationoperator--"></a><a name="operator--"></a>duração::operador--

Diminui a contagem de tiques armazenados.

```cpp
duration& operator--();

duration operator--(int);
```

### <a name="return-value"></a>Valor retornado

O primeiro método retorna `*this`.

O segundo método retorna uma cópia de `*this` que é feita antes do decremento.

## <a name="durationoperator"></a><a name="op_eq"></a>duração::operador=

Reduz o módulo de contagem de tiques armazenados de um valor especificado.

```cpp
duration& operator%=(const rep& Div);

duration& operator%=(const duration& Div);
```

### <a name="parameters"></a>Parâmetros

*Div*\
Para o primeiro método, *Div* representa uma contagem de carrapatos. Para o segundo método, `duration` *Div* é um objeto que contém uma contagem de carrapatos.

### <a name="return-value"></a>Valor retornado

O objeto `duration` após a operação do módulo é executado.

## <a name="durationoperator"></a><a name="op_star_eq"></a>duração::operador*=

Multiplica de contagem de tiques armazenados por um valor especificado.

```cpp
duration& operator*=(const rep& Mult);
```

### <a name="parameters"></a>Parâmetros

*Mult*\
Um valor do tipo especificado por `duration::rep`.

### <a name="return-value"></a>Valor retornado

O objeto `duration` após a multiplicação é executado.

## <a name="durationoperator"></a><a name="op_div_eq"></a>duração::operador/=

Divide a contagem de tiques armazenados por um valor especificado.

```cpp
duration& operator/=(const rep& Div);
```

### <a name="parameters"></a>Parâmetros

*Div*\
Um valor do tipo especificado por `duration::rep`.

### <a name="return-value"></a>Valor retornado

O objeto `duration` após a divisão é executado.

## <a name="durationoperator"></a><a name="op_add"></a>duração::operador+

Retorna `*this`.

```cpp
constexpr duration operator+() const;
```

## <a name="durationoperator"></a><a name="op_add_add"></a>duração::operador++

Aumenta a contagem de tiques armazenados.

```cpp
duration& operator++();

duration operator++(int);
```

### <a name="return-value"></a>Valor retornado

O primeiro método retorna `*this`.

O segundo método retorna uma cópia de `*this` que é feita antes do incremento.

## <a name="durationoperator"></a><a name="op_add_eq"></a>duração::operador+=

Adiciona a contagem de tiques de um objeto `duration` especificado para a contagem de tiques armazenados.

```cpp
duration& operator+=(const duration& Dur);
```

### <a name="parameters"></a>Parâmetros

*Dur*\
Um objeto `duration` .

### <a name="return-value"></a>Valor retornado

O objeto `duration` depois que a adição é executada.

## <a name="durationoperator-"></a><a name="operator-_eq"></a>duração::operador-=

Subtrai a contagem de tiques de um objeto `duration` especificado da contagem de tiques armazenados.

```cpp
duration& operator-=(const duration& Dur);
```

### <a name="parameters"></a>Parâmetros

*Dur*\
Um objeto `duration` .

### <a name="return-value"></a>Valor retornado

O objeto `duration` depois que a subtração é executada.

## <a name="durationzero"></a><a name="zero"></a>duração::zero

Retorna `duration(duration_values<rep>::zero())`.

```cpp
static constexpr duration zero();
```

## <a name="durationoperator-mod"></a><a name="op_mod_eq"></a>duração::operador mod=

Reduz o módulo de contagem de tiques armazenados Div ou Div.count().

```cpp
duration& operator%=(const rep& Div);duration& operator%=(const duration& Div);
```

### <a name="parameters"></a>Parâmetros

*Div*\
O divisor, que é um objeto de duração ou um valor que representa as contagens de tiques.

### <a name="remarks"></a>Comentários

A primeira função de membro reduz do módulo de contagem de tiques armazenados Div e retorna *this. A segunda função de membro reduz do módulo de contagem de tiques armazenados Div.count() e retorna \*this.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<crono>](../standard-library/chrono.md)\
[Estrutura duration_values](../standard-library/duration-values-structure.md)
