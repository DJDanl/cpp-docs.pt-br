---
title: Classe accelerator
ms.date: 11/04/2016
f1_keywords:
- AMPRT/accelerator
- AMPRT/Concurrency::accelerator::accelerator
- AMPRT/Concurrency::accelerator::create_view
- AMPRT/Concurrency::accelerator::get_all
- AMPRT/Concurrency::accelerator::get_auto_selection_view
- AMPRT/Concurrency::accelerator::get_dedicated_memory
- AMPRT/Concurrency::accelerator::get_default_cpu_access_type
- AMPRT/Concurrency::accelerator::get_default_view
- AMPRT/Concurrency::accelerator::get_description
- AMPRT/Concurrency::accelerator::get_device_path
- AMPRT/Concurrency::accelerator::get_has_display
- AMPRT/Concurrency::accelerator::get_is_debug
- AMPRT/Concurrency::accelerator::get_is_emulated
- AMPRT/Concurrency::accelerator::get_supports_cpu_shared_memory
- AMPRT/Concurrency::accelerator::get_supports_double_precision
- AMPRT/Concurrency::accelerator::get_supports_limited_double_precision
- AMPRT/Concurrency::accelerator::get_version
- AMPRT/Concurrency::accelerator::set_default
- AMPRT/Concurrency::accelerator::set_default_cpu_access_type
- AMPRT/Concurrency::accelerator::cpu_accelerator
- AMPRT/Concurrency::accelerator::dedicated_memory
- AMPRT/Concurrency::accelerator::default_accelerator
- AMPRT/Concurrency::accelerator::default_cpu_access_type
- AMPRT/Concurrency::accelerator::default_view
- AMPRT/Concurrency::accelerator::description
- AMPRT/Concurrency::accelerator::device_path
- AMPRT/Concurrency::accelerator::direct3d_ref
- AMPRT/Concurrency::accelerator::direct3d_warp
- AMPRT/Concurrency::accelerator::has_display
- AMPRT/Concurrency::accelerator::is_debug
- AMPRT/Concurrency::accelerator::is_emulated
- AMPRT/Concurrency::accelerator::supports_cpu_shared_memory
- AMPRT/Concurrency::accelerator::supports_double_precision
- AMPRT/Concurrency::accelerator::supports_limited_double_precision
- AMPRT/Concurrency::accelerator::version
helpviewer_keywords:
- accelerator class
ms.assetid: 37eed593-cf87-4611-9cdc-e98df6c2377a
ms.openlocfilehash: 31008b398d17ac0c226f9359745067c4fefc08a9
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326604"
---
# <a name="accelerator-class"></a>Classe accelerator

Um acelerador é um recurso de hardware que é otimizado para computação paralela de dados. Um acelerador pode ser um dispositivo conectado a um barramento PCIe (como um GPU), ou pode ser uma instrução estendida definida no CPU principal.

## <a name="syntax"></a>Sintaxe

```
class accelerator;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Acelerador de construtor](#ctor)|Inicializa uma nova instância da classe `accelerator`.|
|[~ accelerator destruidor](#ctor)|Destrói o `accelerator` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[create_view](#create_view)|Cria e retorna um `accelerator_view` objeto neste acelerador.|
|[get_all](#get_all)|Retorna um vetor de `accelerator` objetos que representam todos os Aceleradores disponíveis.|
|[get_auto_selection_view](#get_auto_selection_view)|Retorna a seleção automática `accelerator_view`.|
|[get_dedicated_memory](#get_dedicated_memory)|Retorna a memória dedicada para o `accelerator`, em quilobytes.|
|[get_default_cpu_access_type](#get_default_cpu_access_type)|Retorna o padrão [access_type](concurrency-namespace-enums-amp.md#access_type) para os buffers criados neste acelerador.|
|[get_default_view](#get_default_view)|Retorna o padrão `accelerator_view` objeto que está associado com o `accelerator`.|
|[get_description](#get_description)|Retorna uma descrição breve do `accelerator` dispositivo.|
|[get_device_path](#get_device_path)|Retorna o caminho do dispositivo.|
|[get_has_display](#get_has_display)|Determina se o `accelerator` é anexado a uma exibição.|
|[get_is_debug](#get_is_debug)|Determina se o `accelerator` tem a camada DEBUG ativada para o relatório de erro extensos.|
|[get_is_emulated](#get_is_emulated)|Determina se o `accelerator` é emulada.|
|[get_supports_cpu_shared_memory](#get_supports_cpu_shared_memory)|Determina se o `accelerator` dá suporte a memória compartilhada|
|[get_supports_double_precision](#get_supports_double_precision)|Determina se o `accelerator` é anexado a uma exibição.|
|[get_supports_limited_double_precision](#get_supports_limited_double_precision)|Determina se o `accelerator` tem suporte limitado para matemática de precisão dupla.|
|[get_version](#get_version)|Retorna a versão do `accelerator`.|
|[set_default](#set_default)|Retorna o caminho do acelerador padrão.|
|[set_default_cpu_access_type](#set_default_cpu_access_type)|Define a padrão CPU [access_type](concurrency-namespace-enums-amp.md#access_type)de matrizes e alocações de memória implícitas feitas nesse `accelerator`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)|Compara essa `accelerator` objeto com outro e retorna **falsos** se eles forem iguais; caso contrário, retornará **true**.|
|[operator=](#operator_eq)|Copia o conteúdo especificado `accelerator` objeto para esse outro.|
|[operator==](#operator_eq_eq)|Compara essa `accelerator` objeto com outro e retorna **verdadeira** se eles forem iguais; caso contrário, retornará **false**.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[cpu_accelerator](#cpu_accelerator)|Obtém uma cadeia de caracteres constante da CPU `accelerator`.|
|[dedicated_memory](#dedicated_memory)|Obtém a memória dedicada para o `accelerator`, em quilobytes.|
|[default_accelerator](#default_accelerator)|Obtém uma cadeia de caracteres constante para o padrão `accelerator`.|
|[default_cpu_access_type](#default_cpu_access_type)|Obtém ou define a padrão CPU [access_type](concurrency-namespace-enums-amp.md#access_type)de matrizes e alocações de memória implícitas feitas nesse `accelerator`.|
|[default_view](#default_view)|Obtém o padrão `accelerator_view` objeto que está associado com o `accelerator`.|
|[description](#description)|Obtém uma descrição breve do `accelerator` dispositivo.|
|[device_path](#device_path)|Obtém o caminho do dispositivo.|
|[direct3d_ref](#direct3d_ref)|Obtém uma cadeia de caracteres constante para obter uma referência de Direct3D `accelerator`.|
|[direct3d_warp](#direct3d_warp)|Obtém a cadeia de caracteres constante para um `accelerator` objeto que você pode usar para executar o código C++ AMP em CPUs de vários núcleos que usam extensões de SIMD de Streaming (SSE).|
|[has_display](#has_display)|Obtém um valor booliano que indica se o `accelerator` é anexado a uma exibição.|
|[is_debug](#is_debug)|Indica se o `accelerator` tem a camada DEBUG ativada para o relatório de erro extensos.|
|[is_emulated](#is_emulated)|Indica se o `accelerator` é emulada.|
|[supports_cpu_shared_memory](#supports_cpu_shared_memory)|Indica se o `accelerator` dá suporte a memória compartilhada.|
|[supports_double_precision](#supports_double_precision)|Indica se o acelerador dá suporte a matemática de precisão dupla.|
|[supports_limited_double_precision](#supports_limited_double_precision)|Indica se o acelerador limitou suporte para matemática de precisão dupla.|
|[version](#version)|Obtém a versão do `accelerator`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`accelerator`

## <a name="remarks"></a>Comentários

Um acelerador é um recurso de hardware que é otimizado para computação paralela de dados. Um acelerador é geralmente um GPU discreto, mas ele também pode ser uma entidade do lado do host virtual como um dispositivo de referência de DirectX, uma WARP (um dispositivo do lado do CPU é acelerado por meio das instruções SSE) ou o próprio CPU.

Você pode construir um `accelerator` objeto, enumerando os dispositivos disponíveis, ou obtendo o dispositivo padrão, o dispositivo de referência ou o dispositivo WARP.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Concorrência

##  <a name="dtor"></a> </a> ~ accelerator

Destrói o `accelerator` objeto.

```
~accelerator();
```

### <a name="return-value"></a>Valor de retorno

##  <a name="ctor"></a> Acelerador

Inicializa uma nova instância dos [classe accelerator](accelerator-class.md).

```
accelerator();

explicit accelerator(const std::wstring& _Device_path);

accelerator(const accelerator& _Other);
```

### <a name="parameters"></a>Parâmetros

*_Device_path*<br/>
O caminho do dispositivo físico.

*_Other*<br/>
O Acelerador a ser copiado.

##  <a name="cpu_accelerator"></a> cpu_accelerator

Obtém uma cadeia de caracteres constante para o Acelerador de CPU.

```
static const wchar_t cpu_accelerator[];
```

##  <a name="create_view"></a> create_view

Cria e retorna um `accelerator_view` objeto neste acelerador, usando o modo de enfileiramento de mensagens especificado. Quando o modo de fila não for especificado, o novo `accelerator_view` usa o [queuing_mode::immediate](concurrency-namespace-enums-amp.md#queuing_mode) modo de fila.

```
accelerator_view create_view(queuing_mode qmode = queuing_mode_automatic);
```

### <a name="parameters"></a>Parâmetros

*qmode*<br/>
O modo de fila.

### <a name="return-value"></a>Valor de retorno

Um novo `accelerator_view` objeto neste acelerador, usando o modo de enfileiramento de mensagens especificado.

##  <a name="dedicated_memory"></a> dedicated_memory

Obtém a memória dedicada para o `accelerator`, em quilobytes.

```
__declspec(property(get= get_dedicated_memory)) size_t dedicated_memory;
```

##  <a name="default_accelerator"></a> default_accelerator

Obtém uma cadeia de caracteres constante para o padrão `accelerator`.

```
static const wchar_t default_accelerator[];
```

##  <a name="default_cpu_access_type"></a> default_cpu_access_type

O padrão cpu [access_type](concurrency-namespace-enums-amp.md#access_type)de matrizes e alocações de memória implícitas feitas nesse `accelerator`.

```
__declspec(property(get= get_default_cpu_access_type)) access_type default_cpu_access_type;
```

##  <a name="default_view"></a> default_view

Obtém a exibição do acelerador padrão que está associada com o `accelerator`.

```
__declspec(property(get= get_default_view)) accelerator_view default_view;
```

##  <a name="description"></a> Descrição

Obtém uma descrição breve do `accelerator` dispositivo.

```
__declspec(property(get= get_description)) std::wstring description;
```

##  <a name="device_path"></a> device_path

Obtém o caminho do acelerador. O caminho é exclusivo no sistema.

```
__declspec(property(get= get_device_path)) std::wstring device_path;
```

##  <a name="direct3d_ref"></a> direct3d_ref

Obtém uma cadeia de caracteres constante para um acelerador de referência de Direct3D.

```
static const wchar_t direct3d_ref[];
```

##  <a name="direct3d_warp"></a> direct3d_warp

Obtém a cadeia de caracteres constante para um `accelerator` objeto que você pode usar para executar seu código C++ AMP em CPUs de vários núcleos usando Streaming SIMD Extensions (SSE).

```
static const wchar_t direct3d_warp[];
```

##  <a name="get_all"></a> get_all

Retorna um vetor de `accelerator` objetos que representam todos os Aceleradores disponíveis.

```
static inline std::vector<accelerator> get_all();
```

### <a name="return-value"></a>Valor de retorno

O vetor de Aceleradores disponíveis

##  <a name="get_auto_selection_view"></a> get_auto_selection_view

Retorna o accelerator_view de seleção automática, que, quando especificado como o destino parallel_for_each resulta no accelerator_view de destino para a execução do kernel parallel_for_each seja selecionada automaticamente pelo tempo de execução. Para outras finalidades, o accelerator_view retornado por esse método é igual ao accelerator_view padrão do acelerador padrão

```
static accelerator_view __cdecl get_auto_selection_view();
```

### <a name="return-value"></a>Valor de retorno

O accelerator_view de seleção automática.

##  <a name="get_dedicated_memory"></a> get_dedicated_memory

Retorna a memória dedicada para o `accelerator`, em quilobytes.

```
size_t get_dedicated_memory() const;
```

### <a name="return-value"></a>Valor de retorno

A memória dedicada para o `accelerator`, em quilobytes.

##  <a name="get_default_cpu_access_type"></a> get_default_cpu_access_type

Obtém o access_type da cpu padrão para os buffers criados neste acelerador

```
access_type get_default_cpu_access_type() const;
```

### <a name="return-value"></a>Valor de retorno

O access_type da cpu padrão para os buffers criados neste acelerador.

##  <a name="get_default_view"></a> get_default_view

Retorna o padrão `accelerator_view` objeto que está associado com o `accelerator`.

```
accelerator_view get_default_view() const;
```

### <a name="return-value"></a>Valor de retorno

O padrão `accelerator_view` objeto que está associado com o `accelerator`.

##  <a name="get_description"></a> get_description

Retorna uma descrição breve do `accelerator` dispositivo.

```
std::wstring get_description() const;
```

### <a name="return-value"></a>Valor de retorno

Uma breve descrição do `accelerator` dispositivo.

##  <a name="get_device_path"></a> get_device_path

Retorna o caminho do acelerador. O caminho é exclusivo no sistema.

```
std::wstring get_device_path() const;
```

### <a name="return-value"></a>Valor de retorno

O caminho de instância de dispositivo exclusivo de todo o sistema.

##  <a name="get_has_display"></a> get_has_display

Retorna um valor booliano que indica se o `accelerator` pode gerar uma exibição.

```
bool get_has_display() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o `accelerator` pode gerar uma exibição; caso contrário, **falso**.

##  <a name="get_is_debug"></a> get_is_debug

Determina se o `accelerator` tem a camada DEBUG ativada para o relatório de erro extensos.

```
bool get_is_debug() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o `accelerator` tem a camada DEBUG ativada para o relatório de erro extensos. Caso contrário, **falsos**.

##  <a name="get_is_emulated"></a> get_is_emulated

Determina se o `accelerator` é emulada.

```
bool get_is_emulated() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o `accelerator` é emulada. Caso contrário, **falsos**.

##  <a name="get_supports_cpu_shared_memory"></a> get_supports_cpu_shared_memory

Retorna um valor booliano que indica se o acelerador dá suporte a memória acessível tanto pelo Acelerador e a CPU.

```
bool get_supports_cpu_shared_memory() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o oferece suporte ao acelerador CPU compartilhado memória; caso contrário, **falso**.

##  <a name="get_supports_double_precision"></a> get_supports_double_precision

Retorna um valor booliano que indica se o Acelerador oferece suporte a matemática de precisão dupla, incluindo múltipla adição fundida multiplicar adicionar (FMA), divisão, recíproco e a conversão entre **int** e **duplo**

```
bool get_supports_double_precision() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o Acelerador oferece suporte a matemática de precisão dupla; caso contrário, **falso**.

##  <a name="get_supports_limited_double_precision"></a> get_supports_limited_double_precision

Retorna um valor booliano que indica se o acelerador limitou suporte para matemática de precisão dupla. Se o acelerador tem somente suporte limitado, em seguida, fundido multiply adicionar (FMA), divisão, recíproco e a conversão entre **int** e **duplo** não têm suporte.

```
bool get_supports_limited_double_precision() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o acelerador limitou suporte para matemática de precisão dupla; caso contrário, **falso**.

##  <a name="get_version"></a> get_version

Retorna a versão do `accelerator`.

```
unsigned int get_version() const;
```

### <a name="return-value"></a>Valor de retorno

A versão do `accelerator`.

##  <a name="has_display"></a> has_display

Obtém um valor booliano que indica se o `accelerator` pode gerar uma exibição.

```
__declspec(property(get= get_has_display)) bool has_display;
```

##  <a name="is_debug"></a> is_debug

Obtém um valor booliano que indica se o `accelerator` tem a camada DEBUG ativada para o relatório de erro extensos.

```
__declspec(property(get= get_is_debug)) bool is_debug;
```

##  <a name="is_emulated"></a> is_emulated

Obtém um valor booliano que indica se o `accelerator` é emulada.

```
__declspec(property(get= get_is_emulated)) bool is_emulated;
```

##  <a name="operator_neq"></a> operador! =

Compara essa `accelerator` objeto com outro e retorna **falsos** se eles forem iguais; caso contrário, retornará **true**.

```
bool operator!= (const accelerator& _Other) const;
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `accelerator` objeto a ser comparado com este.

### <a name="return-value"></a>Valor de retorno

**False** se os dois `accelerator` objetos forem iguais; caso contrário, **verdadeiro**.

##  <a name="operator_eq"></a> operator=

Copia o conteúdo especificado `accelerator` objeto para esse outro.

```
accelerator& operator= (const accelerator& _Other);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `accelerator` objeto do qual copiar.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `accelerator` objeto.

##  <a name="operator_eq_eq"></a> operator==

Compara essa `accelerator` objeto com outro e retorna **verdadeira** se eles forem iguais; caso contrário, retornará **false**.

```
bool operator== (const accelerator& _Other) const;
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `accelerator` objeto a ser comparado com este.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a outra `accelerator` objeto é o mesmo que isso `accelerator` do objeto; caso contrário, **false**.

##  <a name="set_default"></a> set_default

Define o acelerador padrão a ser usado para qualquer operação que usa implicitamente o acelerador padrão. Esse método é bem-sucedido somente se o acelerador padrão selecionado em tempo de execução já não tiver sido usado em uma operação que usa implicitamente o acelerador padrão

```
static inline bool set_default(std::wstring _Path);
```

### <a name="parameters"></a>Parâmetros

*_Path*<br/>
O caminho para o acelerador.

### <a name="return-value"></a>Valor de retorno

**True** se a chamada tiver êxito na configuração do acelerador padrão. Caso contrário, **falsos**.

##  <a name="set_default_cpu_access_type"></a> set_default_cpu_access_type

Defina o access_type do cpu padrão para matrizes criadas neste acelerador ou para alocações de memória implícitas como parte de array_views acessados neste acelerador. Esse método é bem-sucedido somente se o default_cpu_access_type do acelerador ainda não tiver sido substituída por uma chamada anterior a esse método e o default_cpu_access_type selecionado em tempo de execução para este acelerador ainda não foi usado para alocar uma matriz ou para uma alocação de memória implícitas um array_view acessado nesse acelerador.

```
bool set_default_cpu_access_type(access_type _Default_cpu_access_type);
```

### <a name="parameters"></a>Parâmetros

*_Default_cpu_access_type*<br/>
O access_type da cpu padrão a ser usada para alocações de memória de matriz/array_view neste acelerador.

### <a name="return-value"></a>Valor de retorno

Um valor booliano que indica se o access_type da cpu padrão para o acelerador foi definido com êxito.

##  <a name="supports_cpu_shared_memory"></a> supports_cpu_shared_memory

Obtém um valor booliano que indica se o `accelerator` dá suporte a memória compartilhada.

```
__declspec(property(get= get_supports_cpu_shared_memory)) bool supports_cpu_shared_memory;
```

##  <a name="supports_double_precision"></a> supports_double_precision

Obtém um valor booliano que indica se o Acelerador oferece suporte a matemática de precisão dupla.

```
__declspec(property(get= get_supports_double_precision)) bool supports_double_precision;
```

##  <a name="supports_limited_double_precision"></a> supports_limited_double_precision

Obtém um valor booliano que indica se o acelerador limitou suporte para matemática de precisão dupla. Se o acelerador tem somente suporte limitado, em seguida, fundido multiply adicionar (FMA), divisão, recíproco e a conversão entre `int` e `double` não têm suporte.

```
__declspec(property(get= get_supports_limited_double_precision)) bool supports_limited_double_precision;
```

##  <a name="version"></a> Versão

Obtém a versão do `accelerator`.

```
__declspec(property(get= get_version)) unsigned int version;
```

##  <a name="dtor"></a> </a> ~accelerator_view

Destrói a [accelerator_view](accelerator-view-class.md) objeto.

```
~accelerator_view();
```

### <a name="return-value"></a>Valor de retorno

##  <a name="accelerator"></a> Acelerador

Obtém o `accelerator` do objeto para o [accelerator_view](accelerator-view-class.md) objeto.

```
__declspec(property(get= get_accelerator)) Concurrency::accelerator accelerator;
```

##  <a name="ctor"></a> accelerator_view

Inicializa uma nova instância dos [accelerator_view](accelerator-view-class.md) classe copiando uma existente `accelerator_view` objeto.

```
accelerator_view(const accelerator_view& _Other);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `accelerator_view` objeto a ser copiado.

##  <a name="create_marker"></a> create_marker

Retorna um futuro para controlar a conclusão de todos os comandos enviados até agora a este `accelerator_view` objeto.

```
concurrency::completion_future create_marker();
```

### <a name="return-value"></a>Valor de retorno

Um futuro para controlar a conclusão de todos os comandos enviados até agora a este `accelerator_view` objeto.

##  <a name="flush"></a> liberar

Envia todos os comandos pendentes na fila para o [accelerator_view](accelerator-view-class.md) objeto para o acelerador para execução.

```
void flush();
```

### <a name="return-value"></a>Valor de retorno

Retorna `void`.

##  <a name="get_accelerator"></a> get_accelerator

Retorna o `accelerator` do objeto para o [accelerator_view](accelerator-view-class.md) objeto.

```
accelerator get_accelerator() const;
```

### <a name="return-value"></a>Valor de retorno

O `accelerator` do objeto para o `accelerator_view` objeto.

##  <a name="get_is_auto_selection"></a> get_is_auto_selection

Retorna um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando accelerator_view for passado para um [parallel_for_each](../../../parallel/concrt/reference/concurrency-namespace-functions.md#parallel_for_each).

```
bool get_is_auto_selection() const;
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o tempo de execução selecionará automaticamente um acelerador apropriado; caso contrário, **falso**.

##  <a name="get_is_debug"></a> get_is_debug

Retorna um valor booliano que indica se o [accelerator_view](accelerator-view-class.md) objeto tem a camada DEBUG ativada para o relatório de erro extensos.

```
bool get_is_debug() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor booliano que indica se o `accelerator_view` objeto tem a camada DEBUG ativada para o relatório de erro extensos.

##  <a name="get_queuing_mode"></a> get_queuing_mode

Retorna o modo de fila para o [accelerator_view](accelerator-view-class.md) objeto.

```
queuing_mode get_queuing_mode() const;
```

### <a name="return-value"></a>Valor de retorno

O modo de fila para o `accelerator_view` objeto.

##  <a name="get_version"></a> get_version

Retorna a versão dos [accelerator_view](accelerator-view-class.md).

```
unsigned int get_version() const;
```

### <a name="return-value"></a>Valor de retorno

A versão do `accelerator_view`.

##  <a name="is_auto_selection"></a> is_auto_selection

Obtém um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando accelerator_view for passado para um [parallel_for_each](../../../parallel/concrt/reference/concurrency-namespace-functions.md#parallel_for_each).

```
__declspec(property(get= get_is_auto_selection)) bool is_auto_selection;
```

##  <a name="is_debug"></a> is_debug

Obtém um valor booliano que indica se o [accelerator_view](accelerator-view-class.md) objeto tem a camada DEBUG ativada para o relatório de erro extensos.

```
__declspec(property(get= get_is_debug)) bool is_debug;
```

##  <a name="operator_neq"></a> operador! =

Compara essa [accelerator_view](accelerator-view-class.md) objeto com outro e retorna `false` se eles forem iguais; caso contrário, retornará `true`.

```
bool operator!= (const accelerator_view& _Other) const;
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `accelerator_view` objeto a ser comparado com este.

### <a name="return-value"></a>Valor de retorno

**False** se os dois objetos forem iguais; caso contrário, **verdadeiro**.

##  <a name="operator_eq"></a> operator=

Copia o conteúdo do especificado [accelerator_view](accelerator-view-class.md) esse objeto.

```
accelerator_view& operator= (const accelerator_view& _Other);
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `accelerator_view` objeto do qual copiar.

### <a name="return-value"></a>Valor de retorno

Uma referência ao modificado `accelerator_view` objeto.

##  <a name="operator_eq_eq"></a> operator==

Compara essa [accelerator_view](accelerator-view-class.md) objeto com outro e retorna **verdadeiro** se eles forem iguais; caso contrário, retornará **false**.

```
bool operator== (const accelerator_view& _Other) const;
```

### <a name="parameters"></a>Parâmetros

*_Other*<br/>
O `accelerator_view` objeto a ser comparado com este.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se os dois objetos forem iguais; caso contrário, **falso**.

##  <a name="queuing_mode"></a> queuing_mode

Obtém o modo de fila para o [accelerator_view](accelerator-view-class.md) objeto.

```
__declspec(property(get= get_queuing_mode)) Concurrency::queuing_mode queuing_mode;
```

##  <a name="version"></a> Versão

Obtém a versão dos [accelerator_view](accelerator-view-class.md).

```
__declspec(property(get= get_version)) unsigned int version;
```

##  <a name="wait"></a> Aguarde

Aguarda todos os comandos enviados para o [accelerator_view](accelerator-view-class.md) objeto ao fim.

```
void wait();
```

### <a name="return-value"></a>Valor de retorno

Retorna `void`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
