---
title: Classe Extent (AMP C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: reference
f1_keywords:
- extent
- AMP/extent
- AMP/Concurrency::extent::extent
- AMP/Concurrency::extent::contains
- AMP/Concurrency::extent::size
- AMP/Concurrency::extent::tile
- AMP/Concurrency::extent::rank Constant
dev_langs:
- C++
helpviewer_keywords:
- extent structure
ms.assetid: edb5de3d-3935-4dbb-8365-4cc6c4fb0269
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 65113616b93917e46738a0d7f3bc39bdd79553f1
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50060034"
---
# <a name="extent-class-c-amp"></a>Classe extent (C++ AMP)

Representa um vetor de *N* valores inteiros que especificam os limites de um *N*-espaço dimensional que tenha uma origem de 0. Os valores no vetor são ordenados do mais significativo para o menos significativo.

### <a name="syntax"></a>Sintaxe

```
template <int _Rank>
class extent;
```

### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação do `extent` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de extensão](#ctor)|Inicializa uma nova instância da classe `extent`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Contém](#contains)|Verifica se o especificado `extent` objeto tem a ordem especificada.|
|[size](#size)|Retorna o tamanho total linear da extensão (em unidades de elementos).|
|[lado a lado](#tile)|Produz um `tiled_extent` dimensões do objeto com as extensões de tile determinadas pelo especificadas.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator-](#operator_min)|Retorna um novo `extent` objeto que é criado subtraindo os `index` elementos correspondentes `extent` elementos.|
|[operator--](#operator_min_min)|Decrementa cada elemento do `extent` objeto.|
|[operator%=](#operator_mod_eq)|Calcula o módulo (resto) de cada elemento no `extent` objeto quando esse elemento é dividido por um número.|
|[operator*=](#operator_star_eq)|Multiplica cada elemento do `extent` objeto por um número.|
|[operator/=](#operator_min_eq)|Divide cada elemento do `extent` objeto por um número.|
|[extent::operator\[\]](#operator_at)|Retorna o elemento que está no índice especificado.|
|[operator+](#operator_add)|Retorna um novo `extent` objeto que é criado adicionando correspondente `index` e `extent` elementos.|
|[operator++](#operator_add_add)|Incrementa cada elemento do `extent` objeto.|
|[operator+=](#operator_add_eq)|Adiciona o número especificado para cada elemento do `extent` objeto.|
|[operator=](#operator_eq)|Copia o conteúdo de outro `extent` esse objeto.|
|[operator-=](#operator_min_eq)|Subtrai o número especificado de cada elemento do `extent` objeto.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante de classificação](#rank)|Obtém a classificação do `extent` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`extent`

## <a name="contains"></a> Contém

Indica se a especificada [índice](index-class.md) valor está contido dentro do objeto 'extensão'.

### <a name="syntax"></a>Sintaxe

```
bool contains(const index<rank>& _Index) const restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*Index*<br/>
O `index` valor a ser testado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se especificado *índice* valor está contido no `extent` do objeto; caso contrário, **false**.

##  <a name="ctor"></a> extensão

Inicializa uma nova instância da classe 'extensão'.

### <a name="syntax"></a>Sintaxe

```
extent() restrict(amp,cpu);
extent(const extent<_Rank>& _Other) restrict(amp,cpu);
explicit extent(int _I) restrict(amp,cpu);
extent(int _I0,  int _I1) restrict(amp,cpu);
extent(int _I0,  int _I1, int _I2) restrict(amp,cpu);
explicit extent(const int _Array[_Rank])restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*Array*<br/>
Uma matriz de `_Rank` inteiros que é usado para criar o novo `extent` objeto.

*_I*<br/>
O comprimento da extensão.

*_I0*<br/>
O comprimento da dimensão mais significativa.

*_I1*<br/>
O comprimento da dimensão para a maioria-significativos.

*_I2*<br/>
O comprimento da dimensão menos significativa.

*Outro*<br/>
Uma `extent` objeto no qual o novo `extent` com base em objeto.

## <a name="remarks"></a>Comentários

O construtor sem parâmetros inicializa um `extent` objeto que tem uma classificação três.

Se uma matriz é usada para construir um `extent` do objeto, o comprimento da matriz deve coincidir com a classificação do `extent` objeto.

##  <a name="operator_mod_eq"></a> operador % =

Calcula o módulo (resto) de cada elemento em que a extensão quando esse elemento é dividido por um número.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank>& operator%=(int _Rhs) restrict(cpu, direct3d);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número para localizar o módulo de.

### <a name="return-value"></a>Valor de retorno

O objeto `extent`.

##  <a name="operator_star_eq"></a> operador * =

Multiplica cada elemento no objeto 'extensão' pelo número especificado.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank>& operator*=(int _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número a multiplicar.

### <a name="return-value"></a>Valor de retorno

O objeto `extent`.

## <a name="operator_add"></a> operador +

Retorna um novo `extent` objeto criado pela adição de correspondente `index` e `extent` elementos.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank> operator+(const index<_Rank>& _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O `index` objeto que contém os elementos a serem adicionados.

### <a name="return-value"></a>Valor de retorno

O novo objeto `extent`.

##  <a name="operator_add_add"></a> operador + +

Incrementa cada elemento do objeto 'extensão'.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank>& operator++() restrict(amp,cpu);
extent<_Rank> operator++(int)restrict(amp,cpu);
```

### <a name="return-value"></a>Valor de retorno

Para o operador de prefixo, o `extent` objeto (`*this`). Para o operador de sufixo, um novo `extent` objeto.

##  <a name="operator_add_eq"></a> Operator + =

Adiciona o número especificado para cada elemento do objeto 'extensão'.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank>& operator+=(const extent<_Rank>& _Rhs) restrict(amp,cpu);
extent<_Rank>& operator+=(const index<_Rank>& _Rhs) restrict(amp,cpu);
extent<_Rank>& operator+=(int _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número, índice ou extensão para adicionar.

### <a name="return-value"></a>Valor de retorno

O tipo do objeto `extent` resultante.

##  <a name="operator_min"></a> operador-

Cria um novo `extent` objeto subtraindo cada elemento especificado na `index` objeto do elemento correspondente neste `extent` objeto.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank> operator-(const index<_Rank>& _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O `index` objeto que contém os elementos para subtrair.

### <a name="return-value"></a>Valor de retorno

O novo objeto `extent`.

##  <a name="operator_min_min"></a> operador-

Decrementa cada elemento no objeto 'extensão'.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank>& operator--() restrict(amp,cpu);
extent<_Rank> operator--(int)restrict(amp,cpu);
```

### <a name="return-value"></a>Valor de retorno

Para o operador de prefixo, o `extent` objeto (`*this`). Para o operador de sufixo, um novo `extent` objeto.

##  <a name="operator_div_eq"></a> operador / =

Divide cada elemento no objeto 'extensão' pelo número especificado.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank>& operator/=(int _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número pelo qual dividir.

### <a name="return-value"></a>Valor de retorno

O objeto `extent`.

##  <a name="operator_min_eq"></a> operador =

Subtrai o número especificado de cada elemento do objeto 'extensão'.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank>& operator-=(const extent<_Rank>& _Rhs) restrict(amp,cpu);
extent<_Rank>& operator-=(const index<_Rank>& _Rhs) restrict(amp,cpu);
extent<_Rank>& operator-=(int _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número para subtrair.

### <a name="return-value"></a>Valor de retorno

O tipo do objeto `extent` resultante.

##  <a name="operator_eq"></a> operador =

Copia o conteúdo de outro objeto 'extensão' para esse outro.

### <a name="syntax"></a>Sintaxe

```
extent<_Rank>& operator=(const extent<_Rank>& _Other) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*Outro*<br/>
O `extent` objeto do qual copiar.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `extent` objeto.

##  <a name="operator_at"></a> operador Extent:: \[\]

Retorna o elemento que está no índice especificado.

### <a name="syntax"></a>Sintaxe

```
int operator[](unsigned int _Index) const restrict(amp,cpu);
int& operator[](unsigned int _Index) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*Index*<br/>
Um inteiro de 0 até a classificação menos 1.

### <a name="return-value"></a>Valor de retorno

O elemento que está no índice especificado.

##  <a name="rank_constant"></a> classificação

Armazena a classificação do objeto 'extensão'.

### <a name="syntax"></a>Sintaxe

```
static const int rank = _Rank;
```

##  <a name="size"></a> Tamanho

Retorna o tamanho total linear do `extent` objeto (em unidades de elementos).

### <a name="syntax"></a>Sintaxe

```
unsigned int size() const restrict(amp,cpu);
```

## <a name="tile"></a> lado a lado

Produz um objeto tiled_extent com as dimensões do bloco especificado.

```
template <int _Dim0>
tiled_extent<_Dim0> tile() const ;

template <int _Dim0, int _Dim1>
tiled_extent<_Dim0, _Dim1> tile() const ;

template <int _Dim0, int _Dim1, int _Dim2>
tiled_extent<_Dim0, _Dim1, _Dim2> tile() const ;
```

### <a name="parameters"></a>Parâmetros

*_Dim0*<br/>
O componente mais significativo da extensão lado a lado.
*_Dim1*<br/>
O componente next-para-mais significativo da extensão lado a lado.
*_Dim2*<br/>
O componente menos significativo da extensão agrupada.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
