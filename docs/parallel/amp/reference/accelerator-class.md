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
ms.openlocfilehash: 99747899e9264404244d66f3f0d18bee5d2b0967
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87182701"
---
# <a name="accelerator-class"></a>Classe accelerator

Um acelerador é um recurso de hardware que é otimizado para computação em paralelo a dados. Um acelerador pode ser um dispositivo conectado a um barramento PCIe (como uma GPU) ou pode ser um conjunto de instruções estendidas na CPU principal.

## <a name="syntax"></a>Sintaxe

```cpp
class accelerator;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor de acelerador](#ctor)|Inicializa uma nova instância da classe `accelerator`.|
|[~ Destruidor de acelerador](#ctor)|Destrói o `accelerator` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[create_view](#create_view)|Cria e retorna um `accelerator_view` objeto neste acelerador.|
|[get_all](#get_all)|Retorna um vetor de `accelerator` objetos que representa todos os Aceleradores disponíveis.|
|[get_auto_selection_view](#get_auto_selection_view)|Retorna a seleção automática `accelerator_view` .|
|[get_dedicated_memory](#get_dedicated_memory)|Retorna a memória dedicada para o `accelerator` , em quilobytes.|
|[get_default_cpu_access_type](#get_default_cpu_access_type)|Retorna o [access_type](concurrency-namespace-enums-amp.md#access_type) padrão para buffers criados neste acelerador.|
|[get_default_view](#get_default_view)|Retorna o `accelerator_view` objeto padrão associado ao `accelerator` .|
|[get_description](#get_description)|Retorna uma breve descrição do `accelerator` dispositivo.|
|[get_device_path](#get_device_path)|Retorna o caminho do dispositivo.|
|[get_has_display](#get_has_display)|Determina se o `accelerator` está anexado a uma exibição.|
|[get_is_debug](#get_is_debug)|Determina se o `accelerator` tem a camada de depuração habilitada para relatórios de erros extensivos.|
|[get_is_emulated](#get_is_emulated)|Determina se o `accelerator` é emulado.|
|[get_supports_cpu_shared_memory](#get_supports_cpu_shared_memory)|Determina se o `accelerator` dá suporte à memória compartilhada|
|[get_supports_double_precision](#get_supports_double_precision)|Determina se o `accelerator` está anexado a uma exibição.|
|[get_supports_limited_double_precision](#get_supports_limited_double_precision)|Determina se o `accelerator` tem suporte limitado para matemática de precisão dupla.|
|[get_version](#get_version)|Retorna a versão do `accelerator` .|
|[set_default](#set_default)|Retorna o caminho do acelerador padrão.|
|[set_default_cpu_access_type](#set_default_cpu_access_type)|Define a [access_type](concurrency-namespace-enums-amp.md#access_type)de CPU padrão para matrizes e alocações de memória implícitas feitas neste `accelerator` .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador! =](#operator_neq)|Compara esse `accelerator` objeto com outro e retorna **`false`** se eles forem iguais; caso contrário, retorna **`true`** .|
|[operador =](#operator_eq)|Copia o conteúdo do objeto especificado `accelerator` para este.|
|[operador = =](#operator_eq_eq)|Compara esse `accelerator` objeto com outro e retorna **`true`** se eles forem iguais; caso contrário, retorna **`false`** .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[cpu_accelerator](#cpu_accelerator)|Obtém uma constante de cadeia de caracteres para a CPU `accelerator` .|
|[dedicated_memory](#dedicated_memory)|Obtém a memória dedicada para o `accelerator` , em quilobytes.|
|[default_accelerator](#default_accelerator)|Obtém uma constante de cadeia de caracteres para o padrão `accelerator` .|
|[default_cpu_access_type](#default_cpu_access_type)|Obtém ou define a [access_type](concurrency-namespace-enums-amp.md#access_type)de CPU padrão para matrizes e alocações de memória implícitas feitas neste `accelerator` .|
|[default_view](#default_view)|Obtém o `accelerator_view` objeto padrão associado ao `accelerator` .|
|[descrição](#description)|Obtém uma breve descrição do `accelerator` dispositivo.|
|[device_path](#device_path)|Obtém o caminho do dispositivo.|
|[direct3d_ref](#direct3d_ref)|Obtém uma constante de cadeia de caracteres para uma referência do Direct3D `accelerator` .|
|[direct3d_warp](#direct3d_warp)|Obtém a constante de cadeia de caracteres para um `accelerator` objeto que você pode usar para executar C++ amp código em CPUs com vários núcleos que usam SSE (Streaming SIMD Extensions).|
|[has_display](#has_display)|Obtém um valor booliano que indica se o `accelerator` está anexado a uma exibição.|
|[is_debug](#is_debug)|Indica se o `accelerator` tem a camada de depuração habilitada para relatórios de erro extensivos.|
|[is_emulated](#is_emulated)|Indica se o `accelerator` é emulado.|
|[supports_cpu_shared_memory](#supports_cpu_shared_memory)|Indica se o `accelerator` oferece suporte à memória compartilhada.|
|[supports_double_precision](#supports_double_precision)|Indica se o acelerador dá suporte a matemática de precisão dupla.|
|[supports_limited_double_precision](#supports_limited_double_precision)|Indica se o acelerador tem suporte limitado para matemática de precisão dupla.|
|[version](#version)|Obtém a versão de `accelerator`.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`accelerator`

## <a name="remarks"></a>Comentários

Um acelerador é um recurso de hardware que é otimizado para computação em paralelo a dados. Um acelerador é geralmente uma GPU discreta, mas também pode ser uma entidade do lado do host virtual, como um dispositivo de referência do DirectX, uma detorção (um dispositivo do lado da CPU que é acelerado por meio de instruções SSE) ou a própria CPU.

Você pode construir um `accelerator` objeto enumerando os dispositivos disponíveis ou obtendo o dispositivo padrão, o dispositivo de referência ou o dispositivo Warp.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** amprt. h

**Namespace:** Simultaneidade

## <a name="a-accelerator"></a><a name="dtor"></a></a>~ acelerador

Destrói o `accelerator` objeto.

```cpp
~accelerator();
```

### <a name="return-value"></a>Valor retornado

## <a name="accelerator"></a><a name="ctor"></a>Accelerator

Inicializa uma nova instância da [classe do acelerador](accelerator-class.md).

```cpp
accelerator();

explicit accelerator(const std::wstring& _Device_path);

accelerator(const accelerator& _Other);
```

### <a name="parameters"></a>parâmetros

*_Device_path*<br/>
O caminho do dispositivo físico.

*_Other*<br/>
O acelerador a ser copiado.

## <a name="cpu_accelerator"></a><a name="cpu_accelerator"></a>cpu_accelerator

Obtém uma constante de cadeia de caracteres para o acelerador de CPU.

```cpp
static const wchar_t cpu_accelerator[];
```

## <a name="create_view"></a><a name="create_view"></a>create_view

Cria e retorna um `accelerator_view` objeto neste acelerador, usando o modo de enfileiramento especificado. Quando o modo de enfileiramento não é especificado, o novo `accelerator_view` usa o modo de enfileiramento [queuing_mode:: Immediate](concurrency-namespace-enums-amp.md#queuing_mode) .

```cpp
accelerator_view create_view(queuing_mode qmode = queuing_mode_automatic);
```

### <a name="parameters"></a>parâmetros

*qmode*<br/>
O modo de enfileiramento.

### <a name="return-value"></a>Valor retornado

Um novo `accelerator_view` objeto neste acelerador, usando o modo de enfileiramento especificado.

## <a name="dedicated_memory"></a><a name="dedicated_memory"></a>dedicated_memory

Obtém a memória dedicada para o `accelerator` , em quilobytes.

```cpp
__declspec(property(get= get_dedicated_memory)) size_t dedicated_memory;
```

## <a name="default_accelerator"></a><a name="default_accelerator"></a>default_accelerator

Obtém uma constante de cadeia de caracteres para o padrão `accelerator` .

```cpp
static const wchar_t default_accelerator[];
```

## <a name="default_cpu_access_type"></a><a name="default_cpu_access_type"></a>default_cpu_access_type

A [access_type](concurrency-namespace-enums-amp.md#access_type)de CPU padrão para matrizes e alocações de memória implícitas feitas neste `accelerator` .

```cpp
__declspec(property(get= get_default_cpu_access_type)) access_type default_cpu_access_type;
```

## <a name="default_view"></a><a name="default_view"></a>default_view

Obtém o modo de exibição de acelerador padrão associado ao `accelerator` .

```cpp
__declspec(property(get= get_default_view)) accelerator_view default_view;
```

## <a name="description"></a><a name="description"></a>ndescrição

Obtém uma breve descrição do `accelerator` dispositivo.

```cpp
__declspec(property(get= get_description)) std::wstring description;
```

## <a name="device_path"></a><a name="device_path"></a>device_path

Obtém o caminho do acelerador. O caminho é exclusivo no sistema.

```cpp
__declspec(property(get= get_device_path)) std::wstring device_path;
```

## <a name="direct3d_ref"></a><a name="direct3d_ref"></a>direct3d_ref

Obtém uma constante de cadeia de caracteres para um acelerador de referência do Direct3D.

```cpp
static const wchar_t direct3d_ref[];
```

## <a name="direct3d_warp"></a><a name="direct3d_warp"></a>direct3d_warp

Obtém a constante de cadeia de caracteres para um `accelerator` objeto que você pode usar para executar seu código de C++ amp em CPUs com vários núcleos usando SSE (Streaming SIMD Extensions).

```cpp
static const wchar_t direct3d_warp[];
```

## <a name="get_all"></a><a name="get_all"></a>get_all

Retorna um vetor de `accelerator` objetos que representa todos os Aceleradores disponíveis.

```cpp
static inline std::vector<accelerator> get_all();
```

### <a name="return-value"></a>Valor retornado

O vetor de Aceleradores disponíveis

## <a name="get_auto_selection_view"></a><a name="get_auto_selection_view"></a>get_auto_selection_view

Retorna a seleção automática accelerator_view, que quando especificado como o destino de parallel_for_each resulta na accelerator_view de destino para executar o kernel de parallel_for_each a ser selecionado automaticamente pelo tempo de execução. Para todas as outras finalidades, o accelerator_view retornado por esse método é o mesmo que o accelerator_view padrão do acelerador padrão

```cpp
static accelerator_view __cdecl get_auto_selection_view();
```

### <a name="return-value"></a>Valor retornado

A seleção automática accelerator_view.

## <a name="get_dedicated_memory"></a><a name="get_dedicated_memory"></a>get_dedicated_memory

Retorna a memória dedicada para o `accelerator` , em quilobytes.

```cpp
size_t get_dedicated_memory() const;
```

### <a name="return-value"></a>Valor retornado

A memória dedicada para o `accelerator` , em quilobytes.

## <a name="get_default_cpu_access_type"></a><a name="get_default_cpu_access_type"></a>get_default_cpu_access_type

Obter a access_type de CPU padrão para buffers criados neste acelerador

```cpp
access_type get_default_cpu_access_type() const;
```

### <a name="return-value"></a>Valor retornado

A access_type de CPU padrão para buffers criados neste acelerador.

## <a name="get_default_view"></a><a name="get_default_view"></a>get_default_view

Retorna o `accelerator_view` objeto padrão associado ao `accelerator` .

```cpp
accelerator_view get_default_view() const;
```

### <a name="return-value"></a>Valor retornado

O `accelerator_view` objeto padrão associado ao `accelerator` .

## <a name="get_description"></a><a name="get_description"></a>get_description

Retorna uma breve descrição do `accelerator` dispositivo.

```cpp
std::wstring get_description() const;
```

### <a name="return-value"></a>Valor retornado

Uma breve descrição do `accelerator` dispositivo.

## <a name="get_device_path"></a><a name="get_device_path"></a>get_device_path

Retorna o caminho do acelerador. O caminho é exclusivo no sistema.

```cpp
std::wstring get_device_path() const;
```

### <a name="return-value"></a>Valor retornado

O caminho de instância de dispositivo exclusivo em todo o sistema.

## <a name="get_has_display"></a><a name="get_has_display"></a>get_has_display

Retorna um valor booliano que indica se a `accelerator` saída pode ser exibida para uma exibição.

```cpp
bool get_has_display() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o `accelerator` pode gerar uma saída para uma exibição; caso contrário, **`false`** .

## <a name="get_is_debug"></a><a name="get_is_debug"></a>get_is_debug

Determina se o `accelerator` tem a camada de depuração habilitada para relatórios de erros extensivos.

```cpp
bool get_is_debug() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o `accelerator` tiver a camada de depuração habilitada para relatórios de erro extensivos. Caso contrário, **`false`** .

## <a name="get_is_emulated"></a><a name="get_is_emulated"></a>get_is_emulated

Determina se o `accelerator` é emulado.

```cpp
bool get_is_emulated() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o `accelerator` for emulado. Caso contrário, **`false`** .

## <a name="get_supports_cpu_shared_memory"></a><a name="get_supports_cpu_shared_memory"></a>get_supports_cpu_shared_memory

Retorna um valor booliano que indica se o acelerador dá suporte à memória acessível pelo acelerador e pela CPU.

```cpp
bool get_supports_cpu_shared_memory() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o acelerador der suporte à memória compartilhada da CPU; caso contrário, **`false`** .

## <a name="get_supports_double_precision"></a><a name="get_supports_double_precision"></a>get_supports_double_precision

Retorna um valor booliano que indica se o acelerador dá suporte a matemática de precisão dupla, incluindo FMA (adição de multiplicação) com fusível, divisão, recíproca e conversão entre **`int`** e**`double`**

```cpp
bool get_supports_double_precision() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o acelerador der suporte a matemática de precisão dupla; caso contrário, **`false`** .

## <a name="get_supports_limited_double_precision"></a><a name="get_supports_limited_double_precision"></a>get_supports_limited_double_precision

Retorna um valor booliano que indica se o acelerador tem suporte limitado para matemática de precisão dupla. Se o acelerador tiver apenas suporte limitado, o FMA (adição de multiplicação) com fusível, divisão, recíproca e conversão entre **`int`** e **`double`** não terá suporte.

```cpp
bool get_supports_limited_double_precision() const;
```

### <a name="return-value"></a>Valor retornado

**`true`** Se o acelerador tiver suporte limitado para matemática de precisão dupla; caso contrário, **`false`** .

## <a name="get_version"></a><a name="get_version"></a>get_version

Retorna a versão do `accelerator` .

```cpp
unsigned int get_version() const;
```

### <a name="return-value"></a>Valor retornado

A versão do `accelerator` .

## <a name="has_display"></a><a name="has_display"></a>has_display

Obtém um valor booliano que indica se a `accelerator` saída pode ser exibida para uma exibição.

```cpp
__declspec(property(get= get_has_display)) bool has_display;
```

## <a name="is_debug"></a><a name="is_debug"></a>is_debug

Obtém um valor booliano que indica se o `accelerator` tem a camada de depuração habilitada para o relatório de erros extensivo.

```cpp
__declspec(property(get= get_is_debug)) bool is_debug;
```

## <a name="is_emulated"></a><a name="is_emulated"></a>is_emulated

Obtém um valor booliano que indica se o `accelerator` é emulado.

```cpp
__declspec(property(get= get_is_emulated)) bool is_emulated;
```

## <a name="operator"></a><a name="operator_neq"></a>operador! =

Compara esse `accelerator` objeto com outro e retorna **`false`** se eles forem iguais; caso contrário, retorna **`true`** .

```cpp
bool operator!= (const accelerator& _Other) const;
```

### <a name="parameters"></a>parâmetros

*_Other*<br/>
O `accelerator` objeto a ser comparado com este.

### <a name="return-value"></a>Valor retornado

**`false`** Se os dois `accelerator` objetos forem os mesmos; caso contrário, **`true`** .

## <a name="operator"></a><a name="operator_eq"></a>operador =

Copia o conteúdo do objeto especificado `accelerator` para este.

```cpp
accelerator& operator= (const accelerator& _Other);
```

### <a name="parameters"></a>parâmetros

*_Other*<br/>
O `accelerator` objeto do qual copiar.

### <a name="return-value"></a>Valor retornado

Uma referência a este `accelerator` objeto.

## <a name="operator"></a><a name="operator_eq_eq"></a>operador = =

Compara esse `accelerator` objeto com outro e retorna **`true`** se eles forem iguais; caso contrário, retorna **`false`** .

```cpp
bool operator== (const accelerator& _Other) const;
```

### <a name="parameters"></a>parâmetros

*_Other*<br/>
O `accelerator` objeto a ser comparado com este.

### <a name="return-value"></a>Valor retornado

**`true`** Se o outro `accelerator` objeto for o mesmo que esse `accelerator` objeto; caso contrário, **`false`** .

## <a name="set_default"></a><a name="set_default"></a>set_default

Define o acelerador padrão a ser usado para qualquer operação que usa implicitamente o acelerador padrão. Esse método só terá sucesso se o acelerador padrão selecionado pelo tempo de execução ainda não tiver sido usado em uma operação que usa implicitamente o acelerador padrão

```cpp
static inline bool set_default(std::wstring _Path);
```

### <a name="parameters"></a>parâmetros

*_Path*<br/>
O caminho para o acelerador.

### <a name="return-value"></a>Valor retornado

**`true`** se a chamada tiver sucesso na definição do acelerador padrão. Caso contrário, **`false`** .

## <a name="set_default_cpu_access_type"></a><a name="set_default_cpu_access_type"></a>set_default_cpu_access_type

Defina a access_type de CPU padrão para matrizes criadas neste acelerador ou para alocações de memória implícita como parte do array_views acessado neste acelerador. Esse método só terá sucesso se o default_cpu_access_type para o acelerador ainda não tiver sido substituído por uma chamada anterior para esse método e o tempo de execução selecionado default_cpu_access_type para esse acelerador ainda não tiver sido usado para alocar uma matriz ou para uma alocação de memória implícita fazendo backup de um array_view acessado nesse acelerador.

```cpp
bool set_default_cpu_access_type(access_type _Default_cpu_access_type);
```

### <a name="parameters"></a>parâmetros

*_Default_cpu_access_type*<br/>
A access_type de CPU padrão a ser usada para alocações de memória de array_view/matriz neste acelerador.

### <a name="return-value"></a>Valor retornado

Um valor booliano que indica se a access_type de CPU padrão para o acelerador foi definida com êxito.

## <a name="supports_cpu_shared_memory"></a><a name="supports_cpu_shared_memory"></a>supports_cpu_shared_memory

Obtém um valor booliano que indica se o `accelerator` oferece suporte à memória compartilhada.

```cpp
__declspec(property(get= get_supports_cpu_shared_memory)) bool supports_cpu_shared_memory;
```

## <a name="supports_double_precision"></a><a name="supports_double_precision"></a>supports_double_precision

Obtém um valor booliano que indica se o acelerador dá suporte a matemática de precisão dupla.

```cpp
__declspec(property(get= get_supports_double_precision)) bool supports_double_precision;
```

## <a name="supports_limited_double_precision"></a><a name="supports_limited_double_precision"></a>supports_limited_double_precision

Obtém um valor booliano que indica se o acelerador tem suporte limitado para matemática de precisão dupla. Se o acelerador tiver apenas suporte limitado, o FMA (adição de multiplicação) com fusível, divisão, recíproca e conversão entre **`int`** e **`double`** não terá suporte.

```cpp
__declspec(property(get= get_supports_limited_double_precision)) bool supports_limited_double_precision;
```

## <a name="version"></a>Versão do <a name="version"></a>

Obtém a versão de `accelerator`.

```cpp
__declspec(property(get= get_version)) unsigned int version;
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)
