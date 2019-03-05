---
title: Classe index
ms.date: 11/04/2016
f1_keywords:
- AMP/index
- AMP/Concurrency::index::index
- AMP/Concurrency::index::rank
helpviewer_keywords:
- index structure
ms.assetid: cbe79b08-0ba7-474c-9828-f1a71da39eb3
ms.openlocfilehash: 054db83e4d8e140af37dcff9a7664ffdf7902325
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57284639"
---
# <a name="index-class"></a>Classe index

Define uma *N*-dimensional índice pographics cpp amp.md.

## <a name="syntax"></a>Sintaxe

```
template <int _Rank>
class index;
```

#### <a name="parameters"></a>Parâmetros

*_Rank*<br/>
A classificação ou o número de dimensões.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de índice](#ctor)|Inicializa uma nova instância da classe `index`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator--](#operator--)|Decrementa cada elemento do `index` objeto.|
|[operator(mod)=](#operator_mod_eq)|Calcula o módulo (resto) de cada elemento no `index` objeto quando esse elemento é dividido por um número.|
|[operator*=](#operator_star_eq)|Multiplica cada elemento do `index` objeto por um número.|
|[operator/=](#operator_div_eq)|Divide cada elemento do `index` objeto por um número.|
|[index::operator\[\]](#operator_at)|Retorna o elemento que está no índice especificado.|
|[operator++](#operator_add_add)|Incrementa cada elemento do `index` objeto.|
|[operator+=](#operator_add_eq)|Adiciona o número especificado para cada elemento do `index` objeto.|
|[operator=](#operator_eq)|Copia o conteúdo especificado `index` esse objeto.|
|[operator-=](#operator_-_eq)|Subtrai o número especificado de cada elemento do `index` objeto.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[Constante de classificação](#rank)|Armazena a classificação do `index` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`index`

## <a name="remarks"></a>Comentários

O `index` estrutura representa um vetor de coordenadas de *N* inteiros que especifica uma posição única em um *N*-espaço dimensional. Os valores no vetor são ordenados do mais significativo para o menos significativo. Você pode recuperar os valores dos componentes usando [operador =](#operator_eq).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp. h

**Namespace:** Concorrência

## <a name="index_ctor"></a> Construtor de índice

Inicializa uma nova instância da classe de índice.

```
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
O comprimento da dimensão para a maioria-significativos.

*_I2*<br/>
O comprimento da dimensão menos significativa.

*_Other*<br/>
Um objeto de índice no qual o novo objeto de índice é baseado.

## <a name="operator--"></a>  operator--

Decrementa cada elemento do objeto index.
```
index<_Rank>& operator--() restrict(amp,cpu);

index operator--(
   int
) restrict(amp,cpu);
```

### <a name="return-values"></a>Valores de retorno

Para o operador de prefixo, o objeto de índice (* isso). Para o operador de sufixo, um novo objeto de índice.

## <a name="operator_mod_eq"></a>  operator(mod)=

Calcula o módulo (resto) de cada elemento no objeto de índice quando esse elemento é dividido pelo número especificado.

```
index<_Rank>& operator%=(
   int _Rhs
) restrict(cpu, amp);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número a dividir por para localizar o resto.

## <a name="return-value"></a>Valor de retorno
O objeto de índice.

## <a name="operator_star_eq"></a>  operator*=

Multiplica cada elemento no objeto de índice pelo número especificado.
```
index<_Rank>& operator*=(
   int _Rhs
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número a multiplicar.

## <a name="operator_div_eq"></a>  operator/=

Divide cada elemento no objeto de índice pelo número especificado.

```
index<_Rank>& operator/=(
   int _Rhs
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O número pelo qual dividir.

## <a name="operator_at"></a>  operator\[\]

Retorna o componente do índice no local especificado.

```
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

### <a name="return-value"></a>Valor de retorno

O elemento que está no índice especificado.

### <a name="remarks"></a>Comentários

O exemplo a seguir exibe os valores de componente do índice.
```
// Prints 1 2 3.
concurrency::index<3> idx(1, 2, 3);
std::cout << idx[0] << "\n";
std::cout << idx[1] << "\n";
std::cout << idx[2] << "\n";
```

## <a name="operator_add_add"></a>  operator++

Incrementa cada elemento do objeto index.
```
index<_Rank>& operator++() restrict(amp,cpu);

index<_Rank> operator++(
   int
) restrict(amp,cpu);
```

### <a name="return-value"></a>Valor de retorno

Para o operador de prefixo, o objeto de índice (* isso). Para o operador de sufixo, um novo objeto de índice.

## <a name="operator_add_eq"></a>  operator+=

Adiciona o número especificado para cada elemento do objeto index.
```
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

### <a name="return-value"></a>Valor de retorno

O objeto de índice.

## <a name="operator_eq"></a>  operator=

Copia o conteúdo do objeto de índice especificado para esse outro.
```
index<_Rank>& operator=(
   const index<_Rank>& _Other
) restrict(amp,cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O objeto de índice para copiar de.

### <a name="return-value"></a>Valor de retorno

Uma referência a esse objeto de índice.

## <a name="operator_-_eq"></a>  operator-=

Subtrai o número especificado de cada elemento do objeto index.
```
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

### <a name="return-value"></a>Valor de retorno

O objeto de índice.

## <a name="rank"></a>  Rank
  Obtém a classificação do objeto index.
```
static const int rank = _Rank;
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
