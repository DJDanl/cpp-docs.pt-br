---
title: Classe duration | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- chrono/std::chrono::duration
- chrono/std::chrono::duration::duration
- chrono/std::chrono::duration::count
- chrono/std::chrono::duration::max
- chrono/std::chrono::duration::min
- chrono/std::chrono::duration::zero
dev_langs:
- C++
ms.assetid: 06b863b3-65be-4ded-a72e-6e1eb1531077
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
helpviewer_keywords:
- std::chrono [C++], duration
ms.workload:
- cplusplus
ms.openlocfilehash: 5f7e1b7bcf1cfa91a3b1a5d528ee77552e56dad5
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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

### <a name="public-methods"></a>Métodos Públicos

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

**Cabeçalho:** \<chrono >

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

`Rep2` Um tipo aritmético para representar o número de tiques.

`Period2` Um `std::ratio` especialização de modelo para representar o período de escala em unidades de segundos.

`R` O número de tiques do período padrão.

`Dur` O número de tiques do período especificado pelo `Period2`.

### <a name="remarks"></a>Comentários

O construtor padrão constrói um objeto que não foi inicializado. A inicialização de valor usando chaves vazias inicializa um objeto que representa um intervalo de tempo de zero tique do relógio.

O segundo, um construtor de argumento do modelo, constrói um objeto que representa um intervalo de tempo de `R` tiques de relógio usando um período padrão de `std::ratio<1>`. Para evitar o arredondamento de contagens de tique, é um erro construir um objeto de duração de um tipo de representação `Rep2` que pode ser tratado como um tipo de ponto flutuante quando `duration::rep` não pode ser tratado como um tipo de ponto flutuante.

O terceiro, dois construtores de argumento de modelo, constrói um objeto que representa um intervalo de tempo cujo tamanho é o intervalo de tempo especificado por `Dur`. Para evitar o truncamento de contagens de tique, é um erro construir um objeto de duração de outro objeto de duração cujo tipo é *incomensurável* com o tipo de destino.

Um tipo de duração `D1` é *incomensurável* com outro tipo de duração `D2` se `D2` não puder ser tratado como um tipo de ponto flutuante e [ratio_divide\<D1::period, D2::period>::type::den](../standard-library/ratio.md) não for 1.

A menos que `Rep2` seja implicitamente conversível em `rep` e for `treat_as_floating_point<rep>`*verdadeiro* ou `treat_as_floating_point<Rep2>`*falso*, o segundo construtor não participará da resolução de sobrecarga. Para obter mais informações, consulte [<type_traits>](../standard-library/type-traits.md).

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

## <a name="duration__operator-"></a>  duration::operator-

Retorna uma cópia do objeto `duration` junto com uma contagem de tiques negados.

```cpp
constexpr duration operator-() const;
```

## <a name="duration__operator--"></a>  duration::operator--

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

`Div` Para o primeiro método, `Div` representa uma contagem em escala. Para o segundo método, `Div` é um objeto `duration` que contém uma contagem de tiques.

### <a name="return-value"></a>Valor de retorno

O objeto `duration` após a operação do módulo é executado.

## <a name="op_star_eq"></a>  duration::operator*=

Multiplica de contagem de tiques armazenados por um valor especificado.

```cpp
duration& operator*=(const rep& Mult);
```

### <a name="parameters"></a>Parâmetros

`Mult` Um valor do tipo especificado pelo `duration::rep`.

### <a name="return-value"></a>Valor de retorno

O objeto `duration` após a multiplicação é executado.

## <a name="op_div_eq"></a>  duration::operator/=

Divide a contagem de tiques armazenados por um valor especificado.

```cpp
duration& operator/=(const rep& Div);
```

### <a name="parameters"></a>Parâmetros

`Div` Um valor do tipo especificado pelo `duration::rep`.

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

`Dur` Um `duration` objeto.

### <a name="return-value"></a>Valor de retorno

O objeto `duration` depois que a adição é executada.

## <a name="duration__operator-_eq"></a>  duration::operator-=

Subtrai a contagem de tiques de um objeto `duration` especificado da contagem de tiques armazenados.

```cpp
duration& operator-=(const duration& Dur);
```

### <a name="parameters"></a>Parâmetros

`Dur` Um `duration` objeto.

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

`Div` O divisor, que é um objeto de duração ou um valor que representa as contagens em escala.

### <a name="remarks"></a>Comentários

A primeira função de membro reduz do módulo de contagem de tiques armazenados Div e retorna *this. A segunda função de membro reduz do módulo de contagem de tiques armazenados Div.count() e retorna \*this.

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<chrono>](../standard-library/chrono.md)<br/>
[Estrutura duration_values](../standard-library/duration-values-structure.md)<br/>
