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
ms.openlocfilehash: 06a5fa9a2d7e645c46b90ace957d31251baed81c
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127797"
---
# <a name="index-class"></a>Classe index

Define um vetor de índice *N*-dimensional.

## <a name="syntax"></a>Sintaxe

```cpp
template <int _Rank>
class index;
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação ou o número de dimensões.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de índice](#index_ctor)|Inicializa uma nova instância da classe `index`.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator--](#operator--)|Decrementa cada elemento do objeto `index`.|
|[operator%=](#operator_mod_eq)|Calcula o módulo (restante) de cada elemento no objeto `index` quando esse elemento é dividido por um número.|
|[operator*=](#operator_star_eq)|Multiplica cada elemento do objeto `index` por um número.|
|[operator/=](#operator_div_eq)|Divide cada elemento do `index` objeto por um número.|
|[index:: Operator\[\]](#operator_at)|Retorna o elemento que está no índice especificado.|
|[operator++](#operator_add_add)|Incrementa cada elemento do objeto `index`.|
|[operator+=](#operator_add_eq)|Adiciona o número especificado a cada elemento do `index` objeto.|
|[operator=](#operator_eq)|Copia o conteúdo do objeto `index` especificado para este.|
|[operator-=](#operator_-_eq)|Subtrai o número especificado de cada elemento do objeto `index`.|

### <a name="public-constants"></a>Constantes Públicas

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Constante de classificação](#rank)|Armazena a classificação do objeto `index`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`index`

## <a name="remarks"></a>Comentários

A estrutura de `index` representa um vetor de coordenadas de *N* inteiros que especifica uma posição exclusiva em um espaço *N*-dimensional. Os valores no vetor são ordenados do mais significativo para o menos significativo. Você pode recuperar os valores dos componentes usando o [operador =](#operator_eq).

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="index_ctor"></a>Construtor de índice

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
O local do índice em um índice unidimensional.

*_I0*<br/>
O comprimento da dimensão mais significativa.

*_I1*<br/>
O comprimento da dimensão de próximo a mais significativa.

*_I2*<br/>
O comprimento da dimensão menos significativa.

*_Other*<br/>
Um objeto de índice no qual o novo objeto de índice é baseado.

## <a name="operator--"></a>operador--

Decrementa cada elemento do objeto de índice.

```cpp
index<_Rank>& operator--() restrict(amp,cpu);

index operator--(
   int
) restrict(amp,cpu);
```

### <a name="return-values"></a>Valores retornados

Para o operador Prefix, o objeto Index (* this). Para o operador de sufixo, um novo objeto de índice.

## <a name="operator_mod_eq"></a>operador% =

Calcula o módulo (restante) de cada elemento no objeto de índice quando esse elemento é dividido pelo número especificado.

```cpp
index<_Rank>& operator%=(
   int _Rhs
) restrict(cpu, amp);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número a ser dividido por para localizar o módulo.

## <a name="return-value"></a>Valor retornado

O objeto de índice.

## <a name="operator_star_eq"></a>operador * =

Multiplica cada elemento no objeto de índice pelo número especificado.

```cpp
index<_Rank>& operator*=(
   int _Rhs
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número a ser multiplicado.

## <a name="operator_div_eq"></a>operador/=

Divide cada elemento no objeto de índice pelo número especificado.

```cpp
index<_Rank>& operator/=(
   int _Rhs
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número pelo qual dividir.

## <a name="operator_at"></a>  operator\[\]

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
Um inteiro de 0 até a classificação menos 1.

### <a name="return-value"></a>Valor retornado

O elemento que está no índice especificado.

### <a name="remarks"></a>Comentários

Este exemplo a seguir exibe os valores de componente do índice.

```cpp
// Prints 1 2 3.
concurrency::index<3> idx(1, 2, 3);
std::cout << idx[0] << "\n";
std::cout << idx[1] << "\n";
std::cout << idx[2] << "\n";
```

## <a name="operator_add_add"></a>operador + +

Incrementa cada elemento do objeto de índice.

```cpp
index<_Rank>& operator++() restrict(amp,cpu);

index<_Rank> operator++(
   int
) restrict(amp,cpu);
```

### <a name="return-value"></a>Valor retornado

Para o operador Prefix, o objeto Index (* this). Para o operador de sufixo, um novo objeto de índice.

## <a name="operator_add_eq"></a>operador + =

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

## <a name="operator_eq"></a>  operator=

Copia o conteúdo do objeto de índice especificado para este.

```cpp
index<_Rank>& operator=(
   const index<_Rank>& _Other
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto de índice do qual copiar.

### <a name="return-value"></a>Valor retornado

Uma referência a este objeto de índice.

## <a name="operator_-_eq"></a>operador-=

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
O número a ser subtraído.

### <a name="return-value"></a>Valor retornado

O objeto de índice.

## <a name="rank"></a>Fique

Obtém a classificação do objeto de índice.

```cpp
static const int rank = _Rank;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
