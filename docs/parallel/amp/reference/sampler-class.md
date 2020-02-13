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
ms.openlocfilehash: 8f47bf6e9b88dba1e94e9e2ed2b93c8d2d3f9b8c
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77126339"
---
# <a name="sampler-class"></a>Classe de amostra

A classe de amostra agrega informações de configuração de amostragem a serem usadas para amostragem de textura.

## <a name="syntax"></a>Sintaxe

```cpp
class sampler;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de amostras](#ctor)|Sobrecarregado. Constrói uma instância de amostra.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[get_address_mode](#get_address_mode)|Retorna o `address_mode` associado ao objeto de amostra.|
|[get_border_color](#get_border_color)|Retorna a cor da borda associada ao objeto de amostra.|
|[get_filter_mode](#get_filter_mode)|Retorna o `filter_mode` associado ao objeto de amostra.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Sobrecarregado. Operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[address_mode](#address_mode)|Obtém o modo de endereço do objeto `sampler`.|
|[border_color](#border_color)|Obtém a cor da borda do objeto `sampler`.|
|[filter_mode](#filter_mode)|Obtém o modo de filtro do objeto `sampler`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`sampler`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amp_graphics. h

**Namespace:** simultaneidade:: Graphics

## <a name="ctor"></a>cores

Constrói uma instância da classe de [amostra](sampler-class.md).

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
O modo de filtro a ser usado na amostragem.

*_Address_mode*<br/>
O modo de endereçamento a ser usado na amostragem para todas as dimensões.

*_Border_color*<br/>
A cor da borda a ser usada se o modo de endereço for address_border. O valor padrão é `float_4(0.0f, 0.0f, 0.0f, 0.0f)`.

*_Other*<br/>
[5] Construtor de cópia o objeto `sampler` a ser copiado para a nova instância de `sampler`.

[6] mover o Construtor o objeto `sampler` para mover para a nova instância de `sampler`.

## <a name="address_mode"></a>address_mode

Obtém o modo de endereço do objeto `sampler`.

```cpp
__declspec(property(get= get_address_mode)) Concurrency::graphics::address_mode address_mode;
```

## <a name="border_color"></a>border_color

Obtém a cor da borda do objeto `sampler`.

```cpp
__declspec(property(get= get_border_color)) Concurrency::graphics::float_4 border_color;
```

## <a name="filter_mode"></a>filter_mode

Obtém o modo de filtro do objeto `sampler`.

```cpp
__declspec(property(get= get_filter_mode)) Concurrency::graphics::filter_mode filter_mode;
```

## <a name="get_address_mode"></a>get_address_mode

Retorna o modo de filtro configurado para este `sampler`.

```cpp
Concurrency::graphics::address_mode get_address_mode() const __GPU;
```

### <a name="return-value"></a>Valor retornado

O modo de endereço configurado para a amostra.

## <a name="get_border_color"></a>get_border_color

Retorna a cor de borda configurada para este `sampler`.

```cpp
Concurrency::graphics::float_4 get_border_color() const restrict(amp, cpu);
```

### <a name="return-value"></a>Valor retornado

Uma float_4 que contém a cor da borda.

## <a name="get_filter_mode"></a>get_filter_mode

Retorna o modo de filtro configurado para este `sampler`.

```cpp
Concurrency::graphics::filter_mode get_filter_mode() const restrict(amp, cpu);
```

### <a name="return-value"></a>Valor retornado

O modo de filtro configurado para o classificador.

## <a name="operator_eq"></a>operador =

Atribui o valor de outro objeto de amostra a uma amostra existente.

```cpp
sampler& operator= (    // [1] copy assignment operator
    const sampler& _Other) restrict(amp, cpu);

sampler& operator= (    // [2] move assignment operator
    sampler&& _Other) restrict(amp, cpu);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
[1] operador de atribuição de cópia o objeto `sampler` a ser copiado para este `sampler`.

[2] mover o operador de atribuição para o objeto `sampler` para passar para esse `sampler`.

### <a name="return-value"></a>Valor retornado

Uma referência a esta instância de amostra.

## <a name="see-also"></a>Consulte também

[Namespace Concurrency::graphics](concurrency-graphics-namespace.md)
