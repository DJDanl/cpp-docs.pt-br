---
title: Classe index
ms.date: 03/27/2019
f1_keywords:
- AMP/index
- AMP/Concurrency::index::index
- AMP/Concurrency::index::rank
helpviewer_keywords:
- index structure
ms.assetid: cbe79b08-0ba7-474c-9828-f1a71da39eb3
ms.openlocfilehash: 50222015e6b365dc161fd4334067c26c7f288337
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365160"
---
# <a name="index-class"></a>Classe index

Define *um*vetor de índice n-dimensional.

## <a name="syntax"></a>Sintaxe

```cpp
template <int _Rank>
class index;
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação, ou número de dimensões.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[construtor de índices](#index_ctor)|Inicia uma nova instância da classe `index`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador -](#operator--)|Decreta cada elemento do `index` objeto.|
|[operador%=](#operator_mod_eq)|Calcula o módulo (restante) de cada `index` elemento no objeto quando esse elemento é dividido por um número.|
|[operador*=](#operator_star_eq)|Multiplica cada elemento `index` do objeto por um número.|
|[operador/=](#operator_div_eq)|Divide cada elemento `index` do objeto por um número.|
|[índice::operador\[\]](#operator_at)|Retorna o elemento que está no índice especificado.|
|[operador++](#operator_add_add)|Incrementa cada elemento `index` do objeto.|
|[operador+=](#operator_add_eq)|Adiciona o número especificado a `index` cada elemento do objeto.|
|[operador=](#operator_eq)|Copia o conteúdo do `index` objeto especificado para este.|
|[operador-=](#operator_-_eq)|Subtrai o número especificado de `index` cada elemento do objeto.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[classificação Constante](#rank)|Armazena a classificação do `index` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`index`

## <a name="remarks"></a>Comentários

A `index` estrutura representa um vetor de coordenadas de *inteiros N* que especifica uma posição única em um espaço *n-dimensional.* Os valores no vetor são ordenados de mais significativos para menos significativos. Você pode recuperar os valores dos componentes usando [o operador=](#operator_eq).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp.h

**Namespace:** Simultaneidade

## <a name="index-constructor"></a><a name="index_ctor"></a>construtor de índices

Inicializa uma nova instância da classe de índice.

```cpp
index() restrict(amp,cpu);

index(
   const index<_Rank>& _Other
) restrict(amp,cpu);

explicit index(
   int _I
) restrict(amp,cpu);

index(
   int _I0,
   int _I1
) restrict(amp,cpu);

index(
   int _I0,
   int _I1,
   int _I2
) restrict(amp,cpu);

explicit index(
   const int _Array[_Rank]
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Array*<br/>
Uma matriz unidimensional com os valores de classificação.

*_I*<br/>
A localização do índice em um índice unidimensional.

*_I0*<br/>
O comprimento da dimensão mais significativa.

*_I1*<br/>
O comprimento da dimensão mais significativa.

*_I2*<br/>
O comprimento da dimensão menos significativa.

*_Other*<br/>
Um objeto de índice no qual o novo objeto de índice é baseado.

## <a name="operator--"></a><a name="operator--"></a>operador -

Decreta cada elemento do objeto de índice.

```cpp
index<_Rank>& operator--() restrict(amp,cpu);

index operator--(
   int
) restrict(amp,cpu);
```

### <a name="return-values"></a>Valores retornados

Para o operador de prefixo, o objeto de índice (*isso). Para o operador de sufixo, um novo objeto de índice.

## <a name="operator"></a><a name="operator_mod_eq"></a>operador%=

Calcula o módulo (restante) de cada elemento no objeto de índice quando esse elemento é dividido pelo número especificado.

```cpp
index<_Rank>& operator%=(
   int _Rhs
) restrict(cpu, amp);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número para dividir para encontrar o módulo.

## <a name="return-value"></a>Valor retornado

O objeto de índice.

## <a name="operator"></a><a name="operator_star_eq"></a>operador*=

Multiplica cada elemento no objeto de índice pelo número especificado.

```cpp
index<_Rank>& operator*=(
   int _Rhs
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número para multiplicar.

## <a name="operator"></a><a name="operator_div_eq"></a>operador/=

Divide cada elemento no objeto de índice pelo número especificado.

```cpp
index<_Rank>& operator/=(
   int _Rhs
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número para dividir.

## <a name="operator"></a><a name="operator_at"></a>Operador\[\]

Retorna o componente do índice no local especificado.

```cpp
int operator[] (
   unsigned _Index
) const restrict(amp,cpu);

int& operator[] (
   unsigned _Index
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Index*<br/>
Um inteiro de 0 a menos 1.

### <a name="return-value"></a>Valor retornado

O elemento que está no índice especificado.

### <a name="remarks"></a>Comentários

Este exemplo a seguir exibe os valores componentes do índice.

```cpp
// Prints 1 2 3.
concurrency::index<3> idx(1, 2, 3);
std::cout << idx[0] << "\n";
std::cout << idx[1] << "\n";
std::cout << idx[2] << "\n";
```

## <a name="operator"></a><a name="operator_add_add"></a>operador++

Incrementa cada elemento do objeto de índice.

```cpp
index<_Rank>& operator++() restrict(amp,cpu);

index<_Rank> operator++(
   int
) restrict(amp,cpu);
```

### <a name="return-value"></a>Valor retornado

Para o operador de prefixo, o objeto de índice (*isso). Para o operador de sufixo, um novo objeto de índice.

## <a name="operator"></a><a name="operator_add_eq"></a>operador+=

Adiciona o número especificado a cada elemento do objeto de índice.

```cpp
index<_Rank>& operator+=(
   const index<_Rank>& _Rhs
) restrict(amp,cpu);

index<_Rank>& operator+=(
   int _Rhs
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número a ser adicionado.

### <a name="return-value"></a>Valor retornado

O objeto de índice.

## <a name="operator"></a><a name="operator_eq"></a>operador=

Copia o conteúdo do objeto de índice especificado para este.

```cpp
index<_Rank>& operator=(
   const index<_Rank>& _Other
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto de índice a ser copiado.

### <a name="return-value"></a>Valor retornado

Uma referência a este objeto de índice.

## <a name="operator-"></a><a name="operator_-_eq"></a>operador-=

Subtrai o número especificado de cada elemento do objeto de índice.

```cpp
index<_Rank>& operator-=(
   const index<_Rank>& _Rhs
) restrict(amp,cpu);

index<_Rank>& operator-=(
   int _Rhs
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número para subtrair.

### <a name="return-value"></a>Valor retornado

O objeto de índice.

## <a name="rank"></a><a name="rank"></a>Rank

Obtém a classificação do objeto de índice.

```cpp
static const int rank = _Rank;
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
