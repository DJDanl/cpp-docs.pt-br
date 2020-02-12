---
title: Classe accelerator_view
ms.date: 03/27/2019
f1_keywords:
- accelerator_view
- AMPRT/accelerator_view
- AMPRT/Concurrency::accelerator_view::accelerator_view
- AMPRT/Concurrency::accelerator_view::create_marker
- AMPRT/Concurrency::accelerator_view::flush
- AMPRT/Concurrency::accelerator_view::get_accelerator
- AMPRT/Concurrency::accelerator_view::get_is_auto_selection
- AMPRT/Concurrency::accelerator_view::get_is_debug
- AMPRT/Concurrency::accelerator_view::get_queuing_mode
- AMPRT/Concurrency::accelerator_view::get_version
- AMPRT/Concurrency::accelerator_view::wait
- AMPRT/Concurrency::accelerator_view::accelerator
- AMPRT/Concurrency::accelerator_view::is_auto_selection
- AMPRT/Concurrency::accelerator_view::is_debug
- AMPRT/Concurrency::accelerator_view::queuing_mode
- AMPRT/Concurrency::accelerator_view::version
helpviewer_keywords:
- accelerator_view class
ms.assetid: 9f298c21-bf62-46e0-88b8-01c5c78ef144
ms.openlocfilehash: 8990566fb3a700d61de324f725dea3ec00006d04
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127169"
---
# <a name="accelerator_view-class"></a>Classe accelerator_view

Representa uma abstração de dispositivo virtual em C++ um acelerador de dados-paralelo de amp.

## <a name="syntax"></a>Sintaxe

```cpp
class accelerator_view;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Construtor de accelerator_view](#ctor)|Inicializa uma nova instância da classe `accelerator_view`.|
|[~ accelerator_view destruidor](#dtor)|Destrói o objeto `accelerator_view`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[create_marker](#create_marker)|Retorna um futuro para acompanhar a conclusão de todos os comandos enviados até esse `accelerator_view` objeto.|
|[flush](#flush)|Envia todos os comandos pendentes na fila para o objeto `accelerator_view` para o acelerador para execução.|
|[get_accelerator](#get_accelerator)|Retorna o objeto `accelerator` para o objeto `accelerator_view`.|
|[get_is_auto_selection](#get_is_auto_selection)|Retorna um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o objeto `accelerator_view` for passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).|
|[get_is_debug](#get_is_debug)|Retorna um valor booliano que indica se o objeto de `accelerator_view` tem a camada de depuração habilitada para o relatório de erros extensivo.|
|[get_queuing_mode](#get_queuing_mode)|Retorna o modo de enfileiramento do objeto `accelerator_view`.|
|[get_version](#get_version)|Retorna a versão do `accelerator_view`.|
|[esperado](#wait)|Aguarda a conclusão de todos os comandos enviados para a `accelerator_view` objeto.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)|Compara esse `accelerator_view` objeto com outro e retorna **false** se eles forem os mesmos; caso contrário, retornará **true**.|
|[operator=](#operator_eq)|Copia o conteúdo do objeto `accelerator_view` especificado para este.|
|[operator==](#operator_eq_eq)|Compara esse `accelerator_view` objeto com outro e retorna **true** se eles forem os mesmos; caso contrário, retornará **false**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Accelerator](#accelerator)|Obtém o objeto `accelerator` para o objeto `accelerator_view`.|
|[is_auto_selection](#is_auto_selection)|Obtém um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o objeto `accelerator_view` for passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).|
|[is_debug](#is_debug)|Obtém um valor booliano que indica se o objeto de `accelerator_view` tem a camada de depuração habilitada para o relatório de erros extensivo.|
|[queuing_mode](#queuing_mode)|Obtém o modo de enfileiramento do objeto `accelerator_view`.|
|[version](#version)|Obtém a versão do acelerador.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`accelerator_view`

### <a name="remarks"></a>Comentários

Um objeto `accelerator_view` representa uma exibição lógica e isolada de um acelerador. Um único dispositivo de computação física pode ter muitos objetos de `accelerator_view` lógicos e isolados. Cada acelerador tem um objeto de `accelerator_view` padrão. Objetos `accelerator_view` adicionais podem ser criados.

Os dispositivos físicos podem ser compartilhados entre vários threads de cliente. Os threads de cliente podem usar de forma cooperativa o mesmo objeto de `accelerator_view` de um acelerador, ou cada cliente pode se comunicar com um dispositivo de computação por meio de um objeto de `accelerator_view` independente para isolamento de outros threads de cliente.

Um objeto `accelerator_view` pode ter um dos dois Estados de [enumeração queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) . Se o modo de enfileiramento for `immediate`, comandos como `copy` e `parallel_for_each` serão enviados para o dispositivo acelerador correspondente assim que retornar ao chamador. Se o modo de enfileiramento for `deferred`, esses comandos serão colocados em fila em uma fila de comando que corresponde ao objeto `accelerator_view`. Os comandos não são realmente enviados para o dispositivo até que `flush()` seja chamado.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** amprt. h

**Namespace:** Simultaneidade

## <a name="accelerator"></a>Accelerator

Obtém o objeto de acelerador para o objeto de accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_accelerator)) Concurrency::accelerator accelerator;
```

## <a name="ctor"></a>accelerator_view

Inicializa uma nova instância da classe accelerator_view copiando um objeto `accelerator_view` existente.

### <a name="syntax"></a>Sintaxe

```cpp
accelerator_view( const accelerator_view & other );
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
O objeto `accelerator_view` a ser copiado.

## <a name="create_marker"></a>create_marker

Retorna um futuro para acompanhar a conclusão de todos os comandos enviados até esse `accelerator_view` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
concurrency::completion_future create_marker();
```

### <a name="return-value"></a>Valor retornado

Um futuro para acompanhar a conclusão de todos os comandos enviados até esse `accelerator_view` objeto.

## <a name="flush"></a>flush

Envia todos os comandos pendentes na fila para o objeto accelerator_view para o acelerador para execução.

### <a name="syntax"></a>Sintaxe

```cpp
void flush();
```

### <a name="return-value"></a>Valor retornado

Retorna `void`.

## <a name="get_accelerator"></a>get_accelerator

Retorna o objeto Accelerator do objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
accelerator get_accelerator() const;
```

### <a name="return-value"></a>Valor retornado

O objeto Accelerator para o objeto accelerator_view.

## <a name="get_is_auto_selection"></a>get_is_auto_selection

Retorna um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o accelerator_view for passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).

### <a name="syntax"></a>Sintaxe

```cpp
bool get_is_auto_selection() const;
```

### <a name="return-value"></a>Valor retornado

**true** se o tempo de execução selecionar automaticamente um acelerador apropriado; caso contrário, **false**.

## <a name="get_is_debug"></a>get_is_debug

Retorna um valor booliano que indica se o objeto de accelerator_view tem a camada de depuração habilitada para o relatório de erros extensivo.

### <a name="syntax"></a>Sintaxe

```cpp
bool get_is_debug() const;
```

### <a name="return-value"></a>Valor retornado

Um valor booliano que indica se o objeto de `accelerator_view` tem a camada de depuração habilitada para relatórios de erros extensos.

## <a name="get_queuing_mode"></a>get_queuing_mode

Retorna o modo de enfileiramento do objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
queuing_mode get_queuing_mode() const;
```

### <a name="return-value"></a>Valor retornado

O modo de enfileiramento para o objeto `accelerator_view`.

## <a name="get_version"></a>get_version

Retorna a versão do accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned int get_version() const;
```

### <a name="return-value"></a>Valor retornado

A versão do `accelerator_view`.

## <a name="is_auto_selection"></a>is_auto_selection

Obtém um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o accelerator_view for passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_is_auto_selection)) bool is_auto_selection;
```

## <a name="is_debug"></a>is_debug

Obtém um valor booliano que indica se o objeto de accelerator_view tem a camada de depuração habilitada para o relatório de erros extensivo.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_is_debug)) bool is_debug;
```

## <a name="operator_neq"></a>operador! =

Compara esse accelerator_view objeto com outro e retorna **false** se eles forem os mesmos; caso contrário, retornará **true**.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator!= ( const accelerator_view & other ) const;
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
O objeto `accelerator_view` a ser comparado com este.

### <a name="return-value"></a>Valor retornado

**false** se os dois objetos forem os mesmos; caso contrário, **true**.

## <a name="operator_eq"></a>operador =

Copia o conteúdo do objeto accelerator_view especificado para este.

### <a name="syntax"></a>Sintaxe

```cpp
accelerator_view & operator= ( const accelerator_view & other );
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
O objeto `accelerator_view` do qual copiar.

### <a name="return-value"></a>Valor retornado

Uma referência ao objeto `accelerator_view` modificado.

## <a name="operator_eq_eq"></a>operador = =

Compara esse accelerator_view objeto com outro e retorna **true** se eles forem os mesmos; caso contrário, retornará **false**.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator== ( const accelerator_view & other ) const;
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
O objeto `accelerator_view` a ser comparado com este.

### <a name="return-value"></a>Valor retornado

**true** se os dois objetos forem os mesmos; caso contrário, **false**.

## <a name="queuing_mode"></a>queuing_mode

Obtém o modo de enfileiramento do objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_queuing_mode)) Concurrency::queuing_mode queuing_mode;
```

## <a name="version"></a>version

Obtém a versão do accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_version)) unsigned int version;
```

## <a name="wait"></a>wait

Aguarda a conclusão de todos os comandos enviados para a accelerator_view objeto.

### <a name="syntax"></a>Sintaxe

```cpp
void wait();
```

### <a name="return-value"></a>Valor retornado

Retorna `void`.

### <a name="remarks"></a>Comentários

Se o [queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) for `immediate`, esse método retornará imediatamente sem bloqueio.

## <a name="dtor"></a>~ accelerator_view

Destrói o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
~accelerator_view();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
