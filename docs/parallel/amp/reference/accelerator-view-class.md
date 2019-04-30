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
ms.openlocfilehash: 4075051ec07fc1331d815534a715c0411160fe14
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405632"
---
# <a name="acceleratorview-class"></a>Classe accelerator_view

Representa uma abstração de dispositivo virtual em um acelerador de dados paralelo do C++ AMP.

### <a name="syntax"></a>Sintaxe

```
class accelerator_view;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[accelerator_view construtor](#ctor)|Inicializa uma nova instância da classe `accelerator_view`.|
|[~ accelerator_view destruidor](#dtor)|Destrói o `accelerator_view` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[create_marker](#create_marker)|Retorna um futuro para controlar a conclusão de todos os comandos enviados até agora a este `accelerator_view` objeto.|
|[flush](#flush)|Envia todos os comandos pendentes na fila para o `accelerator_view` objeto para o acelerador para execução.|
|[get_accelerator](#get_accelerator)|Retorna o `accelerator` do objeto para o `accelerator_view` objeto.|
|[get_is_auto_selection](#get_is_auto_selection)|Retorna um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o `accelerator_view` objeto é passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).|
|[get_is_debug](#get_is_debug)|Retorna um valor booliano que indica se o `accelerator_view` objeto tem a camada DEBUG ativada para o relatório de erro extensos.|
|[get_queuing_mode](#get_queuing_mode)|Retorna o modo de fila para o `accelerator_view` objeto.|
|[get_version](#get_version)|Retorna a versão do `accelerator_view`.|
|[wait](#wait)|Aguarda todos os comandos enviados para o `accelerator_view` objeto ao fim.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)|Compara essa `accelerator_view` objeto com outro e retorna **falsos** se eles forem iguais; caso contrário, retornará **true**.|
|[operator=](#operator_eq)|Copia o conteúdo especificado `accelerator_view` esse objeto.|
|[operator==](#operator_eq_eq)|Compara essa `accelerator_view` objeto com outro e retorna **verdadeira** se eles forem iguais; caso contrário, retornará **false**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[accelerator](#accelerator)|Obtém o objeto `accelerator` para o objeto `accelerator_view`.|
|[is_auto_selection](#is_auto_selection)|Obtém um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o `accelerator_view` objeto é passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).|
|[is_debug](#is_debug)|Obtém um valor booliano que indica se o `accelerator_view` objeto tem a camada DEBUG ativada para o relatório de erro extensos.|
|[queuing_mode](#queuing_mode)|Obtém o modo de fila para o `accelerator_view` objeto.|
|[version](#version)|Obtém a versão do accelerator.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`accelerator_view`

### <a name="remarks"></a>Comentários

Um `accelerator_view` objeto representa uma exibição isolada, lógica de um acelerador. Um dispositivo de computação físico único pode ter muitas isolada, lógica `accelerator_view` objetos. Cada Acelerador tem um padrão `accelerator_view` objeto. Adicionais `accelerator_view` objetos podem ser criados.

Dispositivos físicos podem ser compartilhados entre vários segmentos de cliente. Segmentos de cliente podem cooperativamente usar o mesmo `accelerator_view` objeto de um acelerador, ou cada cliente pode se comunicar com um dispositivo de computação por meio de um independente `accelerator_view` objeto para o isolamento de outros threads de cliente.

Uma `accelerator_view` objeto pode ter um dos dois [enumeração queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) estados. Se for o modo de fila `immediate`, comandos como `copy` e `parallel_for_each` são enviadas para o dispositivo do acelerador correspondente assim que eles retornarem ao chamador. Se for o modo de fila `deferred`, esses comandos serão enfileirados em uma fila de comando que corresponde ao `accelerator_view` objeto. Comandos não são realmente enviados para o dispositivo até que `flush()` é chamado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Concorrência

## <a name="accelerator"></a> Acelerador

Obtém o objeto de acelerador para o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```
__declspec(property(get= get_accelerator)) Concurrency::accelerator accelerator;
```

## <a name="ctor"></a> accelerator_view

Inicializa uma nova instância da classe accelerator_view copiando uma existente `accelerator_view` objeto.

### <a name="syntax"></a>Sintaxe

```
accelerator_view( const accelerator_view & other );
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
O `accelerator_view` objeto a ser copiado.

## <a name="createmarker"></a>create_marker

Retorna um futuro para controlar a conclusão de todos os comandos enviados até agora a este `accelerator_view` objeto.

### <a name="syntax"></a>Sintaxe

```
concurrency::completion_future create_marker();
```

### <a name="return-value"></a>Valor de retorno

Um futuro para controlar a conclusão de todos os comandos enviados até agora a este `accelerator_view` objeto.

## <a name="flush"></a>flush

Envia que todos os comandos pendentes na fila para o objeto accelerator_view para o acelerador para execução.

### <a name="syntax"></a>Sintaxe

```
void flush();
```

### <a name="return-value"></a>Valor de retorno

Retorna `void`.

## <a name="getaccelerator"></a>get_accelerator

Retorna o objeto acelerador para o objeto accelerator_view.
### <a name="syntax"></a>Sintaxe

```
accelerator get_accelerator() const;
```

### <a name="return-value"></a>Valor de retorno

O objeto acelerador para o objeto accelerator_view.

## <a name="getisautoselection"></a>get_is_auto_selection

Retorna um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando accelerator_view for passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).

### <a name="syntax"></a>Sintaxe

```
bool get_is_auto_selection() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o tempo de execução selecionará automaticamente um acelerador apropriado; caso contrário, **falso**.

## <a name="getisdebug"></a>get_is_debug

Retorna um valor booliano que indica se o objeto accelerator_view tem a camada DEBUG ativada para o relatório de erro extensos.

### <a name="syntax"></a>Sintaxe

```
bool get_is_debug() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor booliano que indica se o `accelerator_view` objeto tem a camada DEBUG ativada para o relatório de erro extensos.

## <a name="getqueuingmode"></a>get_queuing_mode

Retorna o modo de fila para o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```
queuing_mode get_queuing_mode() const;
```

### <a name="return-value"></a>Valor de retorno

O modo de fila para o `accelerator_view` objeto.

## <a name="getversion"></a>get_version

Retorna a versão do accelerator_view.

### <a name="syntax"></a>Sintaxe

```
unsigned int get_version() const;
```

### <a name="return-value"></a>Valor de retorno

A versão do `accelerator_view`.

## <a name="isautoselection"></a>is_auto_selection

Obtém um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando accelerator_view for passado para um [parallel_for_each](concurrency-namespace-functions-amp.md#parallel_for_each).

### <a name="syntax"></a>Sintaxe

```
__declspec(property(get= get_is_auto_selection)) bool is_auto_selection;
```

## <a name="isdebug"></a>is_debug

Obtém um valor booliano que indica se o objeto accelerator_view tem a camada DEBUG ativada para o relatório de erro extensos.

### <a name="syntax"></a>Sintaxe

```
__declspec(property(get= get_is_debug)) bool is_debug;
```

## <a name="operator_neq"></a> operador! =

Compara este objeto accelerator_view com outro e retorna **falsos** se eles forem iguais; caso contrário, retornará **verdadeiro**.

### <a name="syntax"></a>Sintaxe

```
bool operator!= ( const accelerator_view & other ) const;
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
O `accelerator_view` objeto a ser comparado com este.

### <a name="return-value"></a>Valor de retorno

**False** se os dois objetos forem iguais; caso contrário, **verdadeiro**.

## <a name="operator_eq"></a> operator=

Copia o conteúdo do objeto accelerator_view especificado para esse outro.

### <a name="syntax"></a>Sintaxe

```
accelerator_view & operator= ( const accelerator_view & other );
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
O `accelerator_view` objeto do qual copiar.

### <a name="return-value"></a>Valor de retorno

Uma referência ao modificado `accelerator_view` objeto.

## <a name="operator_eq_eq"></a> operator==

Compara este objeto accelerator_view com outro e retorna **verdadeira** se eles forem iguais; caso contrário, retornará **falso**.

### <a name="syntax"></a>Sintaxe

```
bool operator== ( const accelerator_view & other ) const;
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
O `accelerator_view` objeto a ser comparado com este.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se os dois objetos forem iguais; caso contrário, **falso**.

## <a name="queuingmode"></a>queuing_mode

Obtém o modo de fila para o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```
__declspec(property(get= get_queuing_mode)) Concurrency::queuing_mode queuing_mode;
```

## <a name="version"></a>version

Obtém a versão do accelerator_view.

### <a name="syntax"></a>Sintaxe

```
__declspec(property(get= get_version)) unsigned int version;
```

## <a name="wait"></a>Aguarde

Aguarda até que todos os comandos enviados para o objeto accelerator_view concluir.

### <a name="syntax"></a>Sintaxe

```
void wait();
```

### <a name="return-value"></a>Valor de retorno

Retorna `void`.

### <a name="remarks"></a>Comentários

Se o [queuing_mode](concurrency-namespace-enums-amp.md#queuing_mode) é `immediate`, esse método retornará imediatamente sem bloqueio.

##  <a name="dtor"></a> ~accelerator_view

Destrói o objeto accelerator_view.

### <a name="syntax"></a>Sintaxe

```
~accelerator_view();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
