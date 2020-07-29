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
ms.openlocfilehash: 454c03aeb1a4666543a28759d02405a512453ffc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217786"
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
|[duration](#duration)|Constrói um objeto `duration`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[contagem](#count)|Retorna o número de tiques do relógio no intervalo de tempo.|
|[max](#max)|Estático. Retorna o valor máximo permitido do parâmetro de modelo `Ref`.|
|[min](#min)|Estático. Retorna o menor valor permitido do parâmetro de modelo `Ref`.|
|[zero](#zero)|Estático. Na verdade, retorna `Rep`(0).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Duração:: operador-](#operator-)|Retorna uma cópia do objeto `duration` junto com uma contagem de tiques negados.|
|[Duração:: operador--](#operator--)|Diminui a contagem de tiques armazenados.|
|[Duração:: operador =](#op_eq)|Reduz o módulo de contagem de tiques armazenados de um valor especificado.|
|[duration::operator*=](#op_star_eq)|Multiplica de contagem de tiques armazenados por um valor especificado.|
|[Duração:: operador/=](#op_div_eq)|Divide a contagem de tiques armazenados pela contagem de tiques de um objeto `duration` especificado.|
|[Duração:: operador +](#op_add)|Retorna **`*this`** .|
|[Duração:: operador + +](#op_add_add)|Aumenta a contagem de tiques armazenados.|
|[Duração:: operador + =](#op_add_eq)|Adiciona a contagem de tiques de um objeto `duration` especificado para a contagem de tiques armazenados.|
|[Duração:: operador-=](#operator-_eq)|Subtrai a contagem de tiques de um objeto `duration` especificado da contagem de tiques armazenados.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<chrono>

**Namespace:** std::chrono

## <a name="durationcount"></a><a name="count"></a>Duração:: contagem

Recupera o número de tiques do relógio no intervalo de tempo.

```cpp
constexpr Rep count() const;
```

### <a name="return-value"></a>Valor retornado

O número de tiques do relógio no intervalo de tempo.

## <a name="durationduration-constructor"></a><a name="duration"></a>Duração::d Construtor de uração

Constrói um objeto `duration`.

```cpp
constexpr duration() = default;

template <class Rep2>
constexpr explicit duration(const Rep2& R);

template <class Rep2, class Period2>
constexpr duration(const duration<Rep2, Period2>& Dur);
```

### <a name="parameters"></a>parâmetros

*Rep2*\
Um tipo aritmético para representar o número de tiques.

*Period2*\
Uma especialização de modelo `std::ratio` para representar o período de tiques em unidades de segundos.

*D*\
O número de tiques de período padrão.

*Duração*\
O número de tiques do período especificado por *Period2*.

### <a name="remarks"></a>Comentários

O construtor padrão constrói um objeto que não foi inicializado. A inicialização de valor usando chaves vazias inicializa um objeto que representa um intervalo de tempo de zero tique do relógio.

O segundo, um construtor de argumento de modelo, constrói um objeto que representa um intervalo de tempo de tiques de relógio de *R* usando um período padrão de `std::ratio<1>` . Para evitar arredondamento de contagens em escala, é um erro construir um objeto Duration de um tipo de representação *Rep2* que pode ser tratado como um tipo de ponto flutuante quando `duration::rep` não pode ser tratado como um tipo de ponto flutuante.

O terceiro construtor de argumento de dois modelos constrói um objeto que representa um intervalo de tempo cujo comprimento é o intervalo de tempo especificado por *dur*. Para evitar o truncamento de contagens de tique, é um erro construir um objeto de duração de outro objeto de duração cujo tipo é *incomensurável* com o tipo de destino.

Um tipo de duração `D1` é *incommensurable* com outro tipo de duração `D2` se `D2` não puder ser tratado como um tipo de ponto flutuante e [ratio_divide \<D1::period, D2::period> :: Type::d en](../standard-library/ratio.md) não for 1.

A menos que *Rep2* seja implicitamente conversível `rep` e `treat_as_floating_point<rep>` *mantenha true* ou `treat_as_floating_point<Rep2>` *mantenha false*, o segundo construtor não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

A menos que nenhum estouro seja induzido na conversão e for `treat_as_floating_point<rep>`*verdadeiro* ou `ratio_divide<Period2, period>::den` for igual a 1 e `treat_as_floating_point<Rep2>`*falso*, o terceiro construtor não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

## <a name="durationmax"></a><a name="max"></a>Duração:: máx.

O método estático que retorna o limite superior para valores de tipo de parâmetro de modelo `Ref`.

```cpp
static constexpr duration max();
```

### <a name="return-value"></a>Valor retornado

Na verdade, retorna `duration(duration_values<rep>::max())`.

## <a name="durationmin"></a><a name="min"></a>Duração:: mín.

O método estático que retorna o limite inferior para valores de tipo de parâmetro de modelo `Ref`.

```cpp
static constexpr duration min();
```

### <a name="return-value"></a>Valor retornado

Na verdade, retorna `duration(duration_values<rep>::min())`.

## <a name="durationoperator-"></a><a name="operator-"></a>Duração:: operador-

Retorna uma cópia do objeto `duration` junto com uma contagem de tiques negados.

```cpp
constexpr duration operator-() const;
```

## <a name="durationoperator--"></a><a name="operator--"></a>Duração:: operador--

Diminui a contagem de tiques armazenados.

```cpp
duration& operator--();

duration operator--(int);
```

### <a name="return-value"></a>Valor retornado

O primeiro método retorna **`*this`** .

O segundo método retorna uma cópia de **`*this`** que é feita antes do decréscimo.

## <a name="durationoperator"></a><a name="op_eq"></a>Duração:: operador =

Reduz o módulo de contagem de tiques armazenados de um valor especificado.

```cpp
duration& operator%=(const rep& Div);

duration& operator%=(const duration& Div);
```

### <a name="parameters"></a>parâmetros

*Marca*\
Para o primeiro método, *div* representa uma contagem de tiques. Para o segundo método, *div* é um `duration` objeto que contém uma contagem de tiques.

### <a name="return-value"></a>Valor retornado

O objeto `duration` após a operação do módulo é executado.

## <a name="durationoperator"></a><a name="op_star_eq"></a>Duração:: operador * =

Multiplica de contagem de tiques armazenados por um valor especificado.

```cpp
duration& operator*=(const rep& Mult);
```

### <a name="parameters"></a>parâmetros

*Mult*\
Um valor do tipo especificado por `duration::rep`.

### <a name="return-value"></a>Valor retornado

O objeto `duration` após a multiplicação é executado.

## <a name="durationoperator"></a><a name="op_div_eq"></a>Duração:: operador/=

Divide a contagem de tiques armazenados por um valor especificado.

```cpp
duration& operator/=(const rep& Div);
```

### <a name="parameters"></a>parâmetros

*Marca*\
Um valor do tipo especificado por `duration::rep`.

### <a name="return-value"></a>Valor retornado

O objeto `duration` após a divisão é executado.

## <a name="durationoperator"></a><a name="op_add"></a>Duração:: operador +

Retorna **`*this`** .

```cpp
constexpr duration operator+() const;
```

## <a name="durationoperator"></a><a name="op_add_add"></a>Duração:: operador + +

Aumenta a contagem de tiques armazenados.

```cpp
duration& operator++();

duration operator++(int);
```

### <a name="return-value"></a>Valor retornado

O primeiro método retorna **`*this`** .

O segundo método retorna uma cópia de **`*this`** que é feita antes do incremento.

## <a name="durationoperator"></a><a name="op_add_eq"></a>Duração:: operador + =

Adiciona a contagem de tiques de um objeto `duration` especificado para a contagem de tiques armazenados.

```cpp
duration& operator+=(const duration& Dur);
```

### <a name="parameters"></a>parâmetros

*Duração*\
Um objeto `duration`.

### <a name="return-value"></a>Valor retornado

O objeto `duration` depois que a adição é executada.

## <a name="durationoperator-"></a><a name="operator-_eq"></a>Duração:: operador-=

Subtrai a contagem de tiques de um objeto `duration` especificado da contagem de tiques armazenados.

```cpp
duration& operator-=(const duration& Dur);
```

### <a name="parameters"></a>parâmetros

*Duração*\
Um objeto `duration`.

### <a name="return-value"></a>Valor retornado

O objeto `duration` depois que a subtração é executada.

## <a name="durationzero"></a><a name="zero"></a>Duração:: zero

Retorna `duration(duration_values<rep>::zero())`.

```cpp
static constexpr duration zero();
```

## <a name="durationoperator-mod"></a><a name="op_mod_eq"></a>Duração:: operador Mod =

Reduz o módulo de contagem de tiques armazenados Div ou Div.count().

```cpp
duration& operator%=(const rep& Div);duration& operator%=(const duration& Div);
```

### <a name="parameters"></a>parâmetros

*Marca*\
O divisor, que é um objeto de duração ou um valor que representa as contagens de tiques.

### <a name="remarks"></a>Comentários

A primeira função de membro reduz do módulo de contagem de tiques armazenados Div e retorna *this. A segunda função de membro reduz do módulo de contagem de tiques armazenados Div.count() e retorna \*this.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<chrono>](../standard-library/chrono.md)\
[Estrutura duration_values](../standard-library/duration-values-structure.md)
