---
title: Classe extent (C++ AMP)
ms.date: 03/27/2019
f1_keywords:
- extent
- AMP/extent
- AMP/Concurrency::extent::extent
- AMP/Concurrency::extent::contains
- AMP/Concurrency::extent::size
- AMP/Concurrency::extent::tile
- AMP/Concurrency::extent::rank Constant
helpviewer_keywords:
- extent structure
ms.assetid: edb5de3d-3935-4dbb-8365-4cc6c4fb0269
ms.openlocfilehash: b9fd0ffb0c3ac6e0b80823e9f31c3615a045262b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222726"
---
# <a name="extent-class-c-amp"></a>Classe extent (C++ AMP)

Representa um vetor de *N* valores inteiros que especificam os limites de um espaço *N*-dimensional que tem uma origem de 0. Os valores no vetor são ordenados do mais significativo para o menos significativo.

## <a name="syntax"></a>Sintaxe

```cpp
template <int _Rank>
class extent;
```

### <a name="parameters"></a>parâmetros

*_Rank*<br/>
A classificação do `extent` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h

**Namespace:** Simultaneidade

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de extensão](#ctor)|Inicializa uma nova instância da classe `extent`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[contains](#contains)|Verifica se o objeto especificado `extent` tem a classificação especificada.|
|[size](#size)|Retorna o tamanho linear total da extensão (em unidades de elementos).|
|[bloco](#tile)|Produz um `tiled_extent` objeto com as extensões de bloco dadas pelas dimensões especificadas.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador](#operator_min)|Retorna um novo `extent` objeto criado com a subtração dos `index` elementos dos `extent` elementos correspondentes.|
|[operador--](#operator_min_min)|Decrementa cada elemento do `extent` objeto.|
|[operador% =](#operator_mod_eq)|Calcula o módulo (restante) de cada elemento no `extent` objeto quando esse elemento é dividido por um número.|
|[operador * =](#operator_star_eq)|Multiplica cada elemento do `extent` objeto por um número.|
|[operador/=](#operator_min_eq)|Divide cada elemento do `extent` objeto por um número.|
|[operador de extensão::\[\]](#operator_at)|Retorna o elemento que está no índice especificado.|
|[operador +](#operator_add)|Retorna um novo `extent` objeto que é criado adicionando os `index` elementos e correspondentes `extent` .|
|[operador + +](#operator_add_add)|Incrementa cada elemento do `extent` objeto.|
|[operador + =](#operator_add_eq)|Adiciona o número especificado a cada elemento do `extent` objeto.|
|[operador =](#operator_eq)|Copia o conteúdo de outro `extent` objeto para este.|
|[operador-=](#operator_min_eq)|Subtrai o número especificado de cada elemento do `extent` objeto.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante de classificação](#rank_constant)|Obtém a classificação do `extent` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`extent`

## <a name="contains"></a><a name="contains"></a>terá

Indica se o valor de [índice](index-class.md) especificado está contido no objeto ' extensão '.

### <a name="syntax"></a>Sintaxe

```cpp
bool contains(const index<rank>& _Index) const restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Index*<br/>
O valor `index` para testar.

### <a name="return-value"></a>Valor retornado

**`true`** Se o valor de *índice* especificado estiver contido no `extent` objeto; caso contrário, **`false`** .

## <a name="extent"></a><a name="ctor"></a>tention

Inicializa uma nova instância da classe ' extensão '.

### <a name="syntax"></a>Sintaxe

```cpp
extent() restrict(amp,cpu);
extent(const extent<_Rank>& _Other) restrict(amp,cpu);
explicit extent(int _I) restrict(amp,cpu);
extent(int _I0,  int _I1) restrict(amp,cpu);
extent(int _I0,  int _I1, int _I2) restrict(amp,cpu);
explicit extent(const int _Array[_Rank])restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Array*<br/>
Uma matriz de `_Rank` inteiros que é usada para criar o novo `extent` objeto.

*_I*<br/>
O comprimento da extensão.

*_I0*<br/>
O comprimento da dimensão mais significativa.

*_I1*<br/>
O comprimento da dimensão de próximo a mais significativa.

*_I2*<br/>
O comprimento da dimensão menos significativa.

*_Other*<br/>
Um `extent` objeto no qual o novo `extent` objeto é baseado.

## <a name="remarks"></a>Comentários

O construtor padrão Inicializa um `extent` objeto que tem uma classificação de três.

Se uma matriz for usada para construir um `extent` objeto, o comprimento da matriz deverá corresponder à classificação do `extent` objeto.

## <a name="operator"></a><a name="operator_mod_eq"></a>operador% =

Calcula o módulo (restante) de cada elemento na ' extensão ' quando esse elemento é dividido por um número.

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank>& operator%=(int _Rhs) restrict(cpu, direct3d);
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
O número do qual encontrar o módulo.

### <a name="return-value"></a>Valor retornado

O objeto `extent`.

## <a name="operator"></a><a name="operator_star_eq"></a>operador * =

Multiplica cada elemento no objeto ' extensão ' pelo número especificado.

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank>& operator*=(int _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
O número a ser multiplicado.

### <a name="return-value"></a>Valor retornado

O objeto `extent`.

## <a name="operator"></a><a name="operator_add"></a>operador +

Retorna um novo `extent` objeto criado adicionando os `index` elementos e correspondentes `extent` .

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank> operator+(const index<_Rank>& _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
O `index` objeto que contém os elementos a serem adicionados.

### <a name="return-value"></a>Valor retornado

O novo objeto `extent`.

## <a name="operator"></a><a name="operator_add_add"></a>operador + +

Incrementa cada elemento do objeto ' extensão '.

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank>& operator++() restrict(amp,cpu);
extent<_Rank> operator++(int)restrict(amp,cpu);
```

### <a name="return-value"></a>Valor retornado

Para o operador Prefix, o `extent` objeto ( **`*this`** ). Para o operador de sufixo, um novo `extent` objeto.

## <a name="operator"></a><a name="operator_add_eq"></a>operador + =

Adiciona o número especificado a cada elemento do objeto ' extensão '.

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank>& operator+=(const extent<_Rank>& _Rhs) restrict(amp,cpu);
extent<_Rank>& operator+=(const index<_Rank>& _Rhs) restrict(amp,cpu);
extent<_Rank>& operator+=(int _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
O número, o índice ou a extensão a ser adicionada.

### <a name="return-value"></a>Valor retornado

O tipo do objeto `extent` resultante.

## <a name="operator-"></a><a name="operator_min"></a>operador

Cria um novo `extent` objeto subtraindo cada elemento no objeto especificado `index` do elemento correspondente neste `extent` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank> operator-(const index<_Rank>& _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
O `index` objeto que contém os elementos a serem subtraídos.

### <a name="return-value"></a>Valor retornado

O novo objeto `extent`.

## <a name="operator--"></a><a name="operator_min_min"></a>operador--

Decrementa cada elemento no objeto ' extensão '.

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank>& operator--() restrict(amp,cpu);
extent<_Rank> operator--(int)restrict(amp,cpu);
```

### <a name="return-value"></a>Valor retornado

Para o operador Prefix, o `extent` objeto ( **`*this`** ). Para o operador de sufixo, um novo `extent` objeto.

## <a name="operator"></a><a name="operator_div_eq"></a>operador/=

Divide cada elemento no objeto ' extensão ' pelo número especificado.

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank>& operator/=(int _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
O número pelo qual dividir.

### <a name="return-value"></a>Valor retornado

O objeto `extent`.

## <a name="operator-"></a><a name="operator_min_eq"></a>operador-=

Subtrai o número especificado de cada elemento do objeto ' extensão '.

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank>& operator-=(const extent<_Rank>& _Rhs) restrict(amp,cpu);
extent<_Rank>& operator-=(const index<_Rank>& _Rhs) restrict(amp,cpu);
extent<_Rank>& operator-=(int _Rhs) restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Rhs*<br/>
O número a ser subtraído.

### <a name="return-value"></a>Valor retornado

O tipo do objeto `extent` resultante.

## <a name="operator"></a><a name="operator_eq"></a>operador =

Copia o conteúdo de outro objeto ' extensão ' para este.

### <a name="syntax"></a>Sintaxe

```cpp
extent<_Rank>& operator=(const extent<_Rank>& _Other) restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Other*<br/>
O `extent` objeto do qual copiar.

### <a name="return-value"></a>Valor retornado

Uma referência a este `extent` objeto.

## <a name="extentoperator-"></a><a name="operator_at"></a>operador de extensão::\[\]

Retorna o elemento que está no índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
int operator[](unsigned int _Index) const restrict(amp,cpu);
int& operator[](unsigned int _Index) restrict(amp,cpu);
```

### <a name="parameters"></a>parâmetros

*_Index*<br/>
Um inteiro de 0 até a classificação menos 1.

### <a name="return-value"></a>Valor retornado

O elemento que está no índice especificado.

## <a name="rank"></a><a name="rank_constant"></a>Fique

Armazena a classificação do objeto ' extensão '.

### <a name="syntax"></a>Sintaxe

```cpp
static const int rank = _Rank;
```

## <a name="size"></a><a name="size"></a>tamanho

Retorna o tamanho linear total do `extent` objeto (em unidades de elementos).

### <a name="syntax"></a>Sintaxe

```cpp
unsigned int size() const restrict(amp,cpu);
```

## <a name="tile"></a><a name="tile"></a>bloco

Produz um objeto tiled_extent com as dimensões de bloco especificadas.

```cpp
template <int _Dim0>
tiled_extent<_Dim0> tile() const ;

template <int _Dim0, int _Dim1>
tiled_extent<_Dim0, _Dim1> tile() const ;

template <int _Dim0, int _Dim1, int _Dim2>
tiled_extent<_Dim0, _Dim1, _Dim2> tile() const ;
```

### <a name="parameters"></a>parâmetros

*_Dim0*<br/>
O componente mais significativo da extensão do lado do ladrilho.
*_Dim1*<br/>
O componente mais significativo do ponto lado a lado.
*_Dim2*<br/>
O componente menos significativo da extensão do lado do ladrilho.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
