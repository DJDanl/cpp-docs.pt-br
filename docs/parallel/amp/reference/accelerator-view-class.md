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
ms.openlocfilehash: f3be8cc3ab9a0f36027cc38c88f026570d1fdb55
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370882"
---
# <a name="accelerator_view-class"></a>Classe accelerator_view

Representa uma abstração de dispositivo virtual em um acelerador c++ data-parallel.

## <a name="syntax"></a>Sintaxe

```cpp
class accelerator_view;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[construtor accelerator_view](#ctor)|Inicia uma nova instância da classe `accelerator_view`.|
|[~accelerator_view Destructor](#dtor)|Destrói o `accelerator_view` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[create_marker](#create_marker)|Retorna um futuro para acompanhar a conclusão de todos `accelerator_view` os comandos enviados até agora a este objeto.|
|[flush](#flush)|Submete todos os comandos pendentes `accelerator_view` enfileirados ao objeto para execução.|
|[get_accelerator](#get_accelerator)|Retorna o objeto `accelerator` para o objeto `accelerator_view`.|
|[get_is_auto_selection](#get_is_auto_selection)|Retorna um valor booleano que indica se o tempo `accelerator_view` de execução selecionará automaticamente um acelerador apropriado quando o objeto for passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).|
|[get_is_debug](#get_is_debug)|Retorna um valor booleano `accelerator_view` que indica se o objeto tem a camada DEBUG ativada para relatórios de erros extensos.|
|[get_queuing_mode](#get_queuing_mode)|Retorna o modo de `accelerator_view` fila para o objeto.|
|[get_version](#get_version)|Retorna a versão `accelerator_view`do .|
|[Esperar](#wait)|Aguarda que todos os comandos `accelerator_view` enviados ao objeto terminem.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador!=](#operator_neq)|Compara `accelerator_view` este objeto com outro e retorna **falso** se eles forem os mesmos; caso contrário, retorna **verdadeiro.**|
|[operador=](#operator_eq)|Copia o conteúdo do `accelerator_view` objeto especificado para este.|
|[operador==](#operator_eq_eq)|Compara `accelerator_view` este objeto com outro e retorna **verdadeiro** se eles forem os mesmos; caso contrário, retorna **falso**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[Acelerador](#accelerator)|Obtém o objeto `accelerator` para o objeto `accelerator_view`.|
|[is_auto_selection](#is_auto_selection)|Obtém um valor booleano que indica se o tempo `accelerator_view` de execução selecionará automaticamente um acelerador apropriado quando o objeto for passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).|
|[is_debug](#is_debug)|Obtém um valor booleano que indica se o `accelerator_view` objeto tem a camada DEBUG ativada para relatórios de erros extensos.|
|[queuing_mode](#queuing_mode)|Obtém o modo de `accelerator_view` fila para o objeto.|
|[versão](#version)|Fica a versão do acelerador.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`accelerator_view`

### <a name="remarks"></a>Comentários

Um `accelerator_view` objeto representa uma visão lógica e isolada de um acelerador. Um único dispositivo de computação física `accelerator_view` pode ter muitos objetos lógicos e isolados. Cada acelerador tem `accelerator_view` um objeto padrão. Objetos adicionais `accelerator_view` podem ser criados.

Dispositivos físicos podem ser compartilhados entre muitos threads do cliente. Os segmentos do cliente `accelerator_view` podem usar cooperativamente o mesmo objeto de um acelerador, ou cada cliente pode se comunicar com um dispositivo de computação através de um objeto independente `accelerator_view` para isolamento de outros segmentos do cliente.

Um `accelerator_view` objeto pode ter um dos dois [estados queuing_mode Enumeração.](concurrency-namespace-enums-amp.md#queuing_mode) Se o modo de `immediate`fila estiver, os comandos like `copy` e `parallel_for_each` serão enviados para o dispositivo correspondente do acelerador assim que retornarem ao chamador. Se o modo de `deferred`fila estiver, esses comandos serão enfileirados em `accelerator_view` uma fila de comandos que corresponde ao objeto. Os comandos não são realmente enviados para o dispositivo até que `flush()` seja chamado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt.h

**Namespace:** Simultaneidade

## <a name="accelerator"></a><a name="accelerator"></a>Acelerador

Obtém o objeto do acelerador para o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_accelerator)) Concurrency::accelerator accelerator;
```

## <a name="accelerator_view"></a><a name="ctor"></a>accelerator_view

Inicializa uma nova instância da classe accelerator_view copiando um objeto existente. `accelerator_view`

### <a name="syntax"></a>Sintaxe

```cpp
accelerator_view( const accelerator_view & other );
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
O objeto `accelerator_view` a ser copiado.

## <a name="create_marker"></a><a name="create_marker"></a>create_marker

Retorna um futuro para acompanhar a conclusão de todos `accelerator_view` os comandos enviados até agora a este objeto.

### <a name="syntax"></a>Sintaxe

```cpp
concurrency::completion_future create_marker();
```

### <a name="return-value"></a>Valor retornado

Um futuro para acompanhar a conclusão de todos os `accelerator_view` comandos enviados até agora a este objeto.

## <a name="flush"></a>flush

Submete todos os comandos pendentes enfileirados ao objeto accelerator_view ao acelerador para execução.

### <a name="syntax"></a>Sintaxe

```cpp
void flush();
```

### <a name="return-value"></a>Valor retornado

Retorna `void`.

## <a name="get_accelerator"></a><a name="get_accelerator"></a>get_accelerator

Retorna o objeto do acelerador para o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
accelerator get_accelerator() const;
```

### <a name="return-value"></a>Valor retornado

O objeto do acelerador para o objeto accelerator_view.

## <a name="get_is_auto_selection"></a><a name="get_is_auto_selection"></a>get_is_auto_selection

Retorna um valor booleano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o accelerator_view for passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).

### <a name="syntax"></a>Sintaxe

```cpp
bool get_is_auto_selection() const;
```

### <a name="return-value"></a>Valor retornado

**verdade** se o tempo de execução selecionar automaticamente um acelerador apropriado; caso contrário, **falso**.

## <a name="get_is_debug"></a><a name="get_is_debug"></a>get_is_debug

Retorna um valor booleano que indica se o objeto accelerator_view tem a camada DEBUG ativada para relatórios de erros extensos.

### <a name="syntax"></a>Sintaxe

```cpp
bool get_is_debug() const;
```

### <a name="return-value"></a>Valor retornado

Um valor booleano `accelerator_view` que indica se o objeto tem a camada DEBUG ativada para relatórios extensivos de erros.

## <a name="get_queuing_mode"></a><a name="get_queuing_mode"></a>get_queuing_mode

Retorna o modo de fila para o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
queuing_mode get_queuing_mode() const;
```

### <a name="return-value"></a>Valor retornado

O modo de fila `accelerator_view` para o objeto.

## <a name="get_version"></a><a name="get_version"></a>get_version

Retorna a versão do accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned int get_version() const;
```

### <a name="return-value"></a>Valor retornado

A versão `accelerator_view`do .

## <a name="is_auto_selection"></a><a name="is_auto_selection"></a>is_auto_selection

Obtém um valor booleano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando a accelerator_view for passada para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_is_auto_selection)) bool is_auto_selection;
```

## <a name="is_debug"></a><a name="is_debug"></a>is_debug

Obtém um valor booleano que indica se o objeto accelerator_view tem a camada DEBUG ativada para relatórios de erros extensos.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_is_debug)) bool is_debug;
```

## <a name="operator"></a><a name="operator_neq"></a>operador!=

Compara este objeto accelerator_view com outro e retorna **falso** se for o mesmo; caso contrário, retorna **verdadeiro.**

### <a name="syntax"></a>Sintaxe

```cpp
bool operator!= ( const accelerator_view & other ) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
O `accelerator_view` objeto para comparar com este.

### <a name="return-value"></a>Valor retornado

**falso** se os dois objetos são os mesmos; caso contrário, **é verdade.**

## <a name="operator"></a><a name="operator_eq"></a>operador=

Copia o conteúdo do objeto accelerator_view especificado para este.

### <a name="syntax"></a>Sintaxe

```cpp
accelerator_view & operator= ( const accelerator_view & other );
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
O `accelerator_view` objeto para copiar.

### <a name="return-value"></a>Valor retornado

Uma referência ao `accelerator_view` objeto modificado.

## <a name="operator"></a><a name="operator_eq_eq"></a>operador==

Compara este objeto accelerator_view com outro e retorna **verdadeiro** se forem iguais; caso contrário, retorna **falso**.

### <a name="syntax"></a>Sintaxe

```cpp
bool operator== ( const accelerator_view & other ) const;
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
O `accelerator_view` objeto para comparar com este.

### <a name="return-value"></a>Valor retornado

**verdade** se os dois objetos são os mesmos; caso contrário, **falso**.

## <a name="queuing_mode"></a><a name="queuing_mode"></a>queuing_mode

Obtém o modo de fila para o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_queuing_mode)) Concurrency::queuing_mode queuing_mode;
```

## <a name="version"></a>version

Fica a versão do accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
__declspec(property(get= get_version)) unsigned int version;
```

## <a name="wait"></a>wait

Aguarda todos os comandos submetidos ao objeto accelerator_view a ser concluído.

### <a name="syntax"></a>Sintaxe

```cpp
void wait();
```

### <a name="return-value"></a>Valor retornado

Retorna `void`.

### <a name="remarks"></a>Comentários

Se [queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) o `immediate`queuing_mode for, este método retorna imediatamente sem bloqueio.

## <a name="accelerator_view"></a><a name="dtor"></a>~ACCELERATOR_VIEW

Destrói o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```cpp
~accelerator_view();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
