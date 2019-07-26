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
ms.openlocfilehash: 4c537b7dfdd23ba641438e0caf6306cf5549b2d7
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454300"
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
|[permanência](#duration)|Constrói um objeto `duration`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[count](#count)|Retorna o número de tiques do relógio no intervalo de tempo.|
|[max](#max)|Estático. Retorna o valor máximo permitido do parâmetro de modelo `Ref`.|
|[min](#min)|Estático. Retorna o menor valor permitido do parâmetro de modelo `Ref`.|
|[zero](#zero)|Estático. Na verdade, retorna `Rep`(0).|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[duration::operator-](#operator-)|Retorna uma cópia do objeto `duration` junto com uma contagem de tiques negados.|
|[duration::operator--](#operator--)|Diminui a contagem de tiques armazenados.|
|[duration::operator=](#op_eq)|Reduz o módulo de contagem de tiques armazenados de um valor especificado.|
|[duration::operator*=](#op_star_eq)|Multiplica de contagem de tiques armazenados por um valor especificado.|
|[duration::operator/=](#op_div_eq)|Divide a contagem de tiques armazenados pela contagem de tiques de um objeto `duration` especificado.|
|[duration::operator+](#op_add)|Retorna `*this`.|
|[duration::operator++](#op_add_add)|Aumenta a contagem de tiques armazenados.|
|[duration::operator+=](#op_add_eq)|Adiciona a contagem de tiques de um objeto `duration` especificado para a contagem de tiques armazenados.|
|[duration::operator-=](#operator-_eq)|Subtrai a contagem de tiques de um objeto `duration` especificado da contagem de tiques armazenados.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> Chrono

**Namespace:** std::chrono

## <a name="count"></a>  duration::count

Recupera o número de tiques do relógio no intervalo de tempo.

```cpp
constexpr Rep count() const;
```

### <a name="return-value"></a>Valor de retorno

O número de tiques do relógio no intervalo de tempo.

## <a name="duration"></a>  Construtor duration::duration

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

*Period2*\
Uma especialização de modelo `std::ratio` para representar o período de tiques em unidades de segundos.

*R*\
O número de tiques de período padrão.

*Duração*\
O número de tiques do período especificado por *Period2*.

### <a name="remarks"></a>Comentários

O construtor padrão constrói um objeto que não foi inicializado. A inicialização de valor usando chaves vazias inicializa um objeto que representa um intervalo de tempo de zero tique do relógio.

O segundo, um construtor de argumento de modelo, constrói um objeto que representa um intervalo  de tempo de tiques de relógio de R `std::ratio<1>`usando um período padrão de. Para evitar arredondamento de contagens em escala, é um erro construir um objeto Duration de um tipo de representação *Rep2* que pode ser tratado como um tipo de ponto flutuante quando `duration::rep` não pode ser tratado como um tipo de ponto flutuante.

O terceiro construtor de argumento de dois modelos constrói um objeto que representa um intervalo de tempo cujo comprimento é o intervalo de tempo especificado por *dur*. Para evitar o truncamento de contagens de tique, é um erro construir um objeto de duração de outro objeto de duração cujo tipo é *incomensurável* com o tipo de destino.

Um tipo de duração `D1` é *incomensurável* com outro tipo de duração `D2` se `D2` não puder ser tratado como um tipo de ponto flutuante e [ratio_divide\<D1::period, D2::period>::type::den](../standard-library/ratio.md) não for 1.

A menos que *Rep2* seja implicitamente `rep` conversível `treat_as_floating_point<rep>`e *mantenha true* ou `treat_as_floating_point<Rep2>` *mantenha false*, o segundo construtor não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

A menos que nenhum estouro seja induzido na conversão e for `treat_as_floating_point<rep>`*verdadeiro* ou `ratio_divide<Period2, period>::den` for igual a 1 e `treat_as_floating_point<Rep2>`*falso*, o terceiro construtor não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

## <a name="max"></a>  duration::max

O método estático que retorna o limite superior para valores de tipo de parâmetro de modelo `Ref`.

```cpp
static constexpr duration max();
```

### <a name="return-value"></a>Valor de retorno

Na verdade, retorna `duration(duration_values<rep>::max())`.

## <a name="min"></a>  duration::min

O método estático que retorna o limite inferior para valores de tipo de parâmetro de modelo `Ref`.

```cpp
static constexpr duration min();
```

### <a name="return-value"></a>Valor de retorno

Na verdade, retorna `duration(duration_values<rep>::min())`.

## <a name="operator-"></a>  duration::operator-

Retorna uma cópia do objeto `duration` junto com uma contagem de tiques negados.

```cpp
constexpr duration operator-() const;
```

## <a name="operator--"></a>  duration::operator--

Diminui a contagem de tiques armazenados.

```cpp
duration& operator--();

duration operator--(int);
```

### <a name="return-value"></a>Valor de retorno

O primeiro método retorna `*this`.

O segundo método retorna uma cópia de `*this` que é feita antes do decremento.

## <a name="op_eq"></a>  duration::operator=

Reduz o módulo de contagem de tiques armazenados de um valor especificado.

```cpp
duration& operator%=(const rep& Div);

duration& operator%=(const duration& Div);
```

### <a name="parameters"></a>Parâmetros

*Marca*\
Para o primeiro método, *div* representa uma contagem de tiques. Para o segundo método, *div* é um `duration` objeto que contém uma contagem de tiques.

### <a name="return-value"></a>Valor de retorno

O objeto `duration` após a operação do módulo é executado.

## <a name="op_star_eq"></a>  duration::operator*=

Multiplica de contagem de tiques armazenados por um valor especificado.

```cpp
duration& operator*=(const rep& Mult);
```

### <a name="parameters"></a>Parâmetros

*Mult*\
Um valor do tipo especificado por `duration::rep`.

### <a name="return-value"></a>Valor de retorno

O objeto `duration` após a multiplicação é executado.

## <a name="op_div_eq"></a>  duration::operator/=

Divide a contagem de tiques armazenados por um valor especificado.

```cpp
duration& operator/=(const rep& Div);
```

### <a name="parameters"></a>Parâmetros

*Marca*\
Um valor do tipo especificado por `duration::rep`.

### <a name="return-value"></a>Valor de retorno

O objeto `duration` após a divisão é executado.

## <a name="op_add"></a>  duration::operator+

Retorna `*this`.

```cpp
constexpr duration operator+() const;
```

## <a name="op_add_add"></a>  duration::operator++

Aumenta a contagem de tiques armazenados.

```cpp
duration& operator++();

duration operator++(int);
```

### <a name="return-value"></a>Valor de retorno

O primeiro método retorna `*this`.

O segundo método retorna uma cópia de `*this` que é feita antes do incremento.

## <a name="op_add_eq"></a>  duration::operator+=

Adiciona a contagem de tiques de um objeto `duration` especificado para a contagem de tiques armazenados.

```cpp
duration& operator+=(const duration& Dur);
```

### <a name="parameters"></a>Parâmetros

*Duração*\
Um objeto `duration`.

### <a name="return-value"></a>Valor de retorno

O objeto `duration` depois que a adição é executada.

## <a name="operator-_eq"></a>  duration::operator-=

Subtrai a contagem de tiques de um objeto `duration` especificado da contagem de tiques armazenados.

```cpp
duration& operator-=(const duration& Dur);
```

### <a name="parameters"></a>Parâmetros

*Duração*\
Um objeto `duration`.

### <a name="return-value"></a>Valor de retorno

O objeto `duration` depois que a subtração é executada.

## <a name="zero"></a>  duration::zero

Retorna `duration(duration_values<rep>::zero())`.

```cpp
static constexpr duration zero();
```

## <a name="op_mod_eq"></a>  duration::operator mod=

Reduz o módulo de contagem de tiques armazenados Div ou Div.count().

```cpp
duration& operator%=(const rep& Div);duration& operator%=(const duration& Div);
```

### <a name="parameters"></a>Parâmetros

*Marca*\
O divisor, que é um objeto de duração ou um valor que representa as contagens de tiques.

### <a name="remarks"></a>Comentários

A primeira função de membro reduz do módulo de contagem de tiques armazenados Div e retorna *this. A segunda função de membro reduz do módulo de contagem de tiques armazenados Div.count() e retorna \*this.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<chrono>](../standard-library/chrono.md)\
[Estrutura duration_values](../standard-library/duration-values-structure.md)
