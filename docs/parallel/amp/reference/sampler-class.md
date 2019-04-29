---
title: Classe de amostra
ms.date: 06/28/2018
f1_keywords:
- sampler
- AMP_GRAPHICS/sampler
- AMP_GRAPHICS/concurrency::sampler::graphics::sampler
- AMP_GRAPHICS/concurrency::sampler::graphics::get_address_mode
- AMP_GRAPHICS/concurrency::sampler::graphics::get_border_color
- AMP_GRAPHICS/concurrency::sampler::graphics::get_filter_mode
- AMP_GRAPHICS/concurrency::sampler::graphics::address_mode
- AMP_GRAPHICS/concurrency::sampler::graphics::border_color
- AMP_GRAPHICS/concurrency::sampler::graphics::filter_mode
ms.assetid: 9a6a9807-497d-402d-b092-8c4d86275b80
ms.openlocfilehash: 1a66e4d025a7592b78839dbe5f25f9103da41224
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62352587"
---
# <a name="sampler-class"></a>Classe de amostra

A classe sampler agrega informações de configuração de amostragem a ser usado para amostragem de textura.

## <a name="syntax"></a>Sintaxe

```cpp
class sampler;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[amostra de construtor](#ctor)|Sobrecarregado. Constrói uma instância de demonstrador.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[get_address_mode](#get_address_mode)|Retorna o `address_mode` associado o objeto da amostra.|
|[get_border_color](#get_border_color)|Retorna a cor da borda que está associada com o objeto da amostra.|
|[get_filter_mode](#get_filter_mode)|Retorna o `filter_mode` associado o objeto da amostra.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Sobrecarregado. Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[address_mode](#address_mode)|Obtém o modo de endereço do `sampler` objeto.|
|[border_color](#border_color)|Obtém a cor da borda a `sampler` objeto.|
|[filter_mode](#filter_mode)|Obtém o modo de filtro do `sampler` objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`sampler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amp_graphics. h

**Namespace:** Concurrency:: Graphics

##  <a name="ctor"></a> amostra

Constrói uma instância do [classe sampler](sampler-class.md).

```cpp
sampler() restrict(cpu);    // [1] default constructor

sampler(                    // [2] constructor
    filter_mode _Filter_mode) restrict(cpu);

sampler(                    // [3] constructor
    address_mode _Address_mode,
    float_4 _Border_color = float_4(0.0f,
    0.0f,
    0.0f,
    0.0f)) restrict(cpu);

sampler(                    // [4] constructor
    filter_mode _Filter_mode,
    address_mode _Address_mode,
    float_4 _Border_color = float_4(0.0f,
    0.0f,
    0.0f,
    0.0f)) restrict(cpu);

sampler(                    // [5] copy constructor
    const sampler& _Other) restrict(amp,
    cpu);

sampler(                    // [6] move constructor
    sampler&& _Other) restrict(amp,
    cpu);
```

### <a name="parameters"></a>Parâmetros

*_Filter_mode*<br/>
O modo de filtro a ser usado em amostragem.

*_Address_mode*<br/>
O modo de endereçando a ser usado em amostragem para todas as dimensões.

*_Border_color*<br/>
A cor da borda a ser usado se o modo de endereço for address_border. O valor padrão é `float_4(0.0f, 0.0f, 0.0f, 0.0f)`.

*_Other*<br/>
[5] construtor de cópia o `sampler` objeto a ser copiado no novo `sampler` instância.

[6] construtor de movimentação a `sampler` objeto a ser movido para a nova `sampler` instância.

##  <a name="address_mode"></a> address_mode

Obtém o modo de endereço do `sampler` objeto.

```cpp
__declspec(property(get= get_address_mode)) Concurrency::graphics::address_mode address_mode;
```

##  <a name="border_color"></a> border_color

Obtém a cor da borda a `sampler` objeto.

```cpp
__declspec(property(get= get_border_color)) Concurrency::graphics::float_4 border_color;
```

##  <a name="filter_mode"></a> filter_mode

Obtém o modo de filtro do `sampler` objeto.

```cpp
__declspec(property(get= get_filter_mode)) Concurrency::graphics::filter_mode filter_mode;
```

##  <a name="get_address_mode"></a> get_address_mode

Retorna o modo de filtro que é configurado para este `sampler`.

```cpp
Concurrency::graphics::address_mode get_address_mode() const __GPU;
```

### <a name="return-value"></a>Valor de retorno

O modo de endereço que é configurado para a amostra.

##  <a name="get_border_color"></a> get_border_color

Retorna a cor da borda que está configurada para este `sampler`.

```cpp
Concurrency::graphics::float_4 get_border_color() const restrict(amp, cpu);
```

### <a name="return-value"></a>Valor de retorno

Um float_4 que contém a cor da borda.

##  <a name="get_filter_mode"></a> get_filter_mode

Retorna o modo de filtro que é configurado para este `sampler`.

```cpp
Concurrency::graphics::filter_mode get_filter_mode() const restrict(amp, cpu);
```

### <a name="return-value"></a>Valor de retorno

O modo de filtro que é configurado para a amostra.

##  <a name="operator_eq"></a> operator=

Atribui o valor de outro objeto do demonstrador a um demonstrador existente.

```cpp
sampler& operator= (    // [1] copy assignment operator
    const sampler& _Other) restrict(amp, cpu);

sampler& operator= (    // [2] move assignment operator
    sampler&& _Other) restrict(amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
[1] operador de atribuição de cópia o `sampler` o objeto a ser copiado neste `sampler`.

[2] operador de atribuição de movimentação o `sampler` objeto a ser movido para este `sampler`.

### <a name="return-value"></a>Valor de retorno

Uma referência a esta instância de amostra.

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
