---
title: Classe Accelerator | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs:
- C++
helpviewer_keywords:
- accelerator class
ms.assetid: 37eed593-cf87-4611-9cdc-e98df6c2377a
caps.latest.revision: 29
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: d1e68b3533452ec1e47053086c59654337c995fa
ms.lasthandoff: 03/17/2017

---
# <a name="accelerator-class"></a>Classe accelerator
Um acelerador é um recurso de hardware que é otimizado para computação paralela de dados. Um acelerador pode ser um dispositivo conectado a um barramento de PCIe, (como uma GPU) ou pode ser um conjunto de instruções estendido na CPU principal.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class accelerator;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor Accelerator](#ctor)|Inicializa uma nova instância da classe `accelerator`.|  
|[~ accelerator destruidor](#ctor)|Destrói o `accelerator` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[create_view](#create_view)|Cria e retorna um `accelerator_view` objeto esse acelerador.|  
|[get_all](#get_all)|Retorna um vetor de `accelerator` objetos que representam todos os Aceleradores disponíveis.|  
|[get_auto_selection_view](#get_auto_selection_view)|Retorna a seleção automática `accelerator_view`.|  
|[get_dedicated_memory](#get_dedicated_memory)|Retorna a memória dedicada para o `accelerator`, em quilobytes.|  
|[get_default_cpu_access_type](#get_default_cpu_access_type)|Retorna o padrão [access_type](concurrency-namespace-enums-amp.md#access_type) para buffers criados nesse acelerador.|  
|[get_default_view](#get_default_view)|Retorna o padrão `accelerator_view` objeto que está associado com o `accelerator`.|  
|[get_description](#get_description)|Retorna uma descrição resumida do `accelerator` dispositivo.|  
|[get_device_path](#get_device_path)|Retorna o caminho do dispositivo.|  
|[get_has_display](#get_has_display)|Determina se o `accelerator` está anexado a uma exibição.|  
|[get_is_debug](#get_is_debug)|Determina se o `accelerator` tem a camada de depuração habilitada para o relatório de erros abrangente.|  
|[get_is_emulated](#get_is_emulated)|Determina se o `accelerator` é emulada.|  
|[get_supports_cpu_shared_memory](#get_supports_cpu_shared_memory)|Determina se o `accelerator` oferece suporte a memória compartilhada|  
|[get_supports_double_precision](#get_supports_double_precision)|Determina se o `accelerator` está anexado a uma exibição.|  
|[get_supports_limited_double_precision](#get_supports_limited_double_precision)|Determina se o `accelerator` tem suporte limitado para matemática de precisão dupla.|  
|[get_version](#get_version)|Retorna a versão do `accelerator`.|  
|[set_default](#set_default)|Retorna o caminho do acelerador padrão.|  
|[set_default_cpu_access_type](#set_default_cpu_access_type)|Define a CPU padrão [access_type](concurrency-namespace-enums-amp.md#access_type)para matrizes e alocações de memória implícita feitas neste `accelerator`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operator!=](#operator_neq)|Compara isso `accelerator` objeto com outra e retorna `false` se eles forem iguais; caso contrário, retornará `true`.|  
|[operator=](#operator_eq)|Copia o conteúdo especificado `accelerator` objeto a este.|  
|[operator==](#operator_eq_eq)|Compara isso `accelerator` objeto com outra e retorna `true` se eles forem iguais; caso contrário, retornará `false`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[cpu_accelerator](#cpu_accelerator)|Obtém uma cadeia de caracteres constante da CPU `accelerator`.|  
|[dedicated_memory](#dedicated_memory)|Obtém a memória dedicada para o `accelerator`, em quilobytes.|  
|[default_accelerator](#default_accelerator)|Obtém uma cadeia de caracteres constante para o padrão `accelerator`.|  
|[default_cpu_access_type](#default_cpu_access_type)|Obtém ou define a CPU padrão [access_type](concurrency-namespace-enums-amp.md#access_type)para matrizes e alocações de memória implícita feitas neste `accelerator`.|  
|[default_view](#default_view)|Obtém o padrão `accelerator_view` objeto que está associado com o `accelerator`.|  
|[Descrição](#description)|Obtém uma descrição resumida do `accelerator` dispositivo.|  
|[device_path](#device_path)|Obtém o caminho do dispositivo.|  
|[direct3d_ref](#direct3d_ref)|Obtém uma cadeia de caracteres constante para obter uma referência do Direct3D `accelerator`.|  
|[direct3d_warp](#direct3d_warp)|Obtém a cadeia de caracteres constante para um `accelerator` que você pode usar para executar o código C++ AMP em CPUs de vários núcleos que usam o Streaming SIMD Extensions (SSE) do objeto.|  
|[has_display](#has_display)|Obtém um valor booliano que indica se o `accelerator` está anexado a uma exibição.|  
|[is_debug](#is_debug)|Indica se o `accelerator` tem a camada de depuração habilitada para o relatório de erros abrangente.|  
|[is_emulated](#is_emulated)|Indica se o `accelerator` é emulada.|  
|[supports_cpu_shared_memory](#supports_cpu_shared_memory)|Indica se o `accelerator` oferece suporte a memória compartilhada.|  
|[supports_double_precision](#supports_double_precision)|Indica se o Acelerador oferece suporte a matemática de precisão dupla.|  
|[supports_limited_double_precision](#supports_limited_double_precision)|Indica se o acelerador tem suporte limitado para matemática de precisão dupla.|  
|[version](#version)|Obtém a versão dos `accelerator`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `accelerator`  
  
## <a name="remarks"></a>Comentários  
 Um acelerador é um recurso de hardware que é otimizado para computação paralela de dados. Um acelerador costuma ser uma GPU discreta, mas também pode ser uma entidade do host virtual como um dispositivo DirectX REF, uma distorção (um dispositivo de lado da CPU é acelerado por meio de instruções SSE), ou a própria CPU.  
  
 Você pode construir um `accelerator` objeto Enumerando os dispositivos disponíveis ou fazendo com que o dispositivo padrão, o dispositivo de referência ou o dispositivo de distorção.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  
  
##  <a name="dtor"></a></a> ~ accelerator 

 Destrói o `accelerator` objeto.  
  
```  
~accelerator();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="ctor"></a>Acelerador 

 Inicializa uma nova instância de [classe accelerator](accelerator-class.md).  
  
```  
accelerator();

 
explicit accelerator(const std::wstring& _Device_path);

 
accelerator(const accelerator& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Device_path`  
 O caminho do dispositivo físico.  
  
 `_Other`  
 Copie o acelerador.  
  
##  <a name="cpu_accelerator"></a>cpu_accelerator 

 Obtém uma cadeia de caracteres constante para o Acelerador de CPU.  
  
```  
static const wchar_t cpu_accelerator[];  
```  
  
##  <a name="create_view"></a>create_view 

 Cria e retorna um `accelerator_view` objeto esse acelerador, usando o modo de enfileiramento de mensagens especificado. Quando o modo de enfileiramento de mensagens não for especificado, o novo `accelerator_view` usa o [queuing_mode::immediate](concurrency-namespace-enums-amp.md#queuing_mode) modo de enfileiramento de mensagens.  
  
```  
accelerator_view create_view(queuing_mode qmode = queuing_mode_automatic);
```  
  
### <a name="parameters"></a>Parâmetros  
 `qmode`  
 O modo de enfileiramento de mensagens.  
  
### <a name="return-value"></a>Valor de retorno  
 Um novo `accelerator_view` objeto esse acelerador, usando o modo de enfileiramento de mensagens especificado.  
  
##  <a name="dedicated_memory"></a>dedicated_memory 

 Obtém a memória dedicada para o `accelerator`, em quilobytes.  
  
```  
__declspec(property(get= get_dedicated_memory)) size_t dedicated_memory;  
```  
  
##  <a name="default_accelerator"></a>default_accelerator 

 Obtém uma cadeia de caracteres constante para o padrão `accelerator`.  
  
```  
static const wchar_t default_accelerator[];  
```  
  
##  <a name="default_cpu_access_type"></a>default_cpu_access_type 

 O padrão cpu [access_type](concurrency-namespace-enums-amp.md#access_type)para matrizes e alocações de memória implícita feitas sobre essa isso `accelerator`.  
  
```  
__declspec(property(get= get_default_cpu_access_type)) access_type default_cpu_access_type;  
```  
  
##  <a name="default_view"></a>default_view 

 Obtém o modo de acelerador padrão que está associado a `accelerator`.  
  
```  
__declspec(property(get= get_default_view)) accelerator_view default_view;  
```  
  
##  <a name="description"></a>Descrição 

 Obtém uma descrição resumida do `accelerator` dispositivo.  
  
```  
__declspec(property(get= get_description)) std::wstring description;  
```  
  
##  <a name="device_path"></a>device_path 

 Obtém o caminho do accelerator. O caminho é exclusivo no sistema.  
  
```  
__declspec(property(get= get_device_path)) std::wstring device_path;  
```  
  
##  <a name="direct3d_ref"></a>direct3d_ref 

 Obtém uma cadeia de caracteres constante para um acelerador de referência do Direct3D.  
  
```  
static const wchar_t direct3d_ref[];  
```  
  
##  <a name="direct3d_warp"></a>direct3d_warp 

 Obtém a cadeia de caracteres constante para um `accelerator` que você pode usar para executar seu código C++ AMP em CPUs de vários núcleos usando Streaming SIMD Extensions (SSE) do objeto.  
  
```  
static const wchar_t direct3d_warp[];  
```  
  
##  <a name="get_all"></a>get_all 

 Retorna um vetor de `accelerator` objetos que representam todos os Aceleradores disponíveis.  
  
```  
static inline std::vector<accelerator> get_all();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O vetor de Aceleradores disponíveis  
  
##  <a name="get_auto_selection_view"></a>get_auto_selection_view 

 Retorna o accelerator_view de seleção automática, que, quando especificado como os resultados de destino parallel_for_each em accelerator_view de destino para executar o kernel parallel_for_each seja selecionado automaticamente pelo tempo de execução. Para outras finalidades, o accelerator_view retornado por esse método é o mesmo que o accelerator_view padrão do acelerador padrão  
  
```  
static accelerator_view __cdecl get_auto_selection_view();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Accelerator_view a seleção automática.  
  
##  <a name="get_dedicated_memory"></a>get_dedicated_memory 

 Retorna a memória dedicada para o `accelerator`, em quilobytes.  
  
```  
size_t get_dedicated_memory() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 A memória dedicada para o `accelerator`, em quilobytes.  
  
##  <a name="get_default_cpu_access_type"></a>get_default_cpu_access_type 

 Obtém o access_type de cpu padrão para buffers criados nesse acelerador  
  
```  
access_type get_default_cpu_access_type() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O access_type de cpu padrão para buffers criado nesse acelerador.  
  
##  <a name="get_default_view"></a>get_default_view 

 Retorna o padrão `accelerator_view` objeto que está associado com o `accelerator`.  
  
```  
accelerator_view get_default_view() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O padrão `accelerator_view` objeto que está associado com o `accelerator`.  
  
##  <a name="get_description"></a>get_description 

 Retorna uma descrição resumida do `accelerator` dispositivo.  
  
```  
std::wstring get_description() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma descrição resumida do `accelerator` dispositivo.  
  
##  <a name="get_device_path"></a>get_device_path 

 Retorna o caminho do accelerator. O caminho é exclusivo no sistema.  
  
```  
std::wstring get_device_path() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O caminho de instância de dispositivo exclusivo de todo o sistema.  
  
##  <a name="get_has_display"></a>get_has_display 

 Retorna um valor booliano que indica se o `accelerator` pode dar saída a uma exibição.  
  
```  
bool get_has_display() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o `accelerator` pode dar saída a uma exibição; caso contrário, `false`.  
  
##  <a name="get_is_debug"></a>get_is_debug 

 Determina se o `accelerator` tem a camada de depuração habilitada para o relatório de erros abrangente.  
  
```  
bool get_is_debug() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o `accelerator` tem a camada de depuração habilitada para o relatório de erros abrangente. Caso contrário, `false`.  
  
##  <a name="get_is_emulated"></a>get_is_emulated 

 Determina se o `accelerator` é emulada.  
  
```  
bool get_is_emulated() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o `accelerator` é emulada. Caso contrário, `false`.  
  
##  <a name="get_supports_cpu_shared_memory"></a>get_supports_cpu_shared_memory 

 Retorna um valor booliano que indica se o Acelerador oferece suporte a memória acessível pelo Acelerador e CPU.  
  
```  
bool get_supports_cpu_shared_memory() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o Acelerador oferece suporte a memória de CPU compartilhada; Caso contrário, `false`.  
  
##  <a name="get_supports_double_precision"></a>get_supports_double_precision 

 Retorna um valor booliano que indica se o Acelerador oferece suporte a matemática de precisão dupla, incluindo fusível multiplicar adicionar (FMA), divisão e recíproco conversão entre `int` e `double`.  
  
```  
bool get_supports_double_precision() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o accelerator suporta double math de precisão; Caso contrário, `false`.  
  
##  <a name="get_supports_limited_double_precision"></a>get_supports_limited_double_precision 

 Retorna um valor booliano que indica se o acelerador tem suporte limitado para matemática de precisão dupla. Se o acelerador tem somente suporte limitado a, com fusível multiply adicionar (FMA), divisão e recíproco conversão entre `int` e `double` não têm suporte.  
  
```  
bool get_supports_limited_double_precision() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o acelerador tem suporte limitado para double math de precisão; Caso contrário, `false`.  
  
##  <a name="get_version"></a>get_version 

 Retorna a versão do `accelerator`.  
  
```  
unsigned int get_version() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 A versão do `accelerator`.  
  
##  <a name="has_display"></a>has_display 

 Obtém um valor booliano que indica se o `accelerator` pode dar saída a uma exibição.  
  
```  
__declspec(property(get= get_has_display)) bool has_display;  
```  
  
##  <a name="is_debug"></a>is_debug 

 Obtém um valor booliano que indica se o `accelerator` tem a camada de depuração habilitada para o relatório de erros abrangente.  
  
```  
__declspec(property(get= get_is_debug)) bool is_debug;  
```  
  
##  <a name="is_emulated"></a>is_emulated 

 Obtém um valor booliano que indica se o `accelerator` é emulada.  
  
```  
__declspec(property(get= get_is_emulated)) bool is_emulated;  
```  
  
##  <a name="operator_neq"></a>operador! = 

 Compara isso `accelerator` objeto com outra e retorna `false` se eles forem iguais; caso contrário, retornará `true`.  
  
```  
bool operator!= (const accelerator& _Other) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `false`Se os dois `accelerator` objetos forem iguais; caso contrário, `true`.  
  
##  <a name="operator_eq"></a>operador = 

 Copia o conteúdo especificado `accelerator` objeto a este.  
  
```  
accelerator& operator= (const accelerator& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `accelerator` objeto.  
  
##  <a name="operator_eq_eq"></a>operador = = 

 Compara isso `accelerator` objeto com outra e retorna `true` se eles forem iguais; caso contrário, retornará `false`.  
  
```  
bool operator== (const accelerator& _Other) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o outro `accelerator` objeto é o mesmo que isso `accelerator` objeto; caso contrário, `false`.  
  
##  <a name="set_default"></a>set_default 

 Define o acelerador padrão a ser usado para qualquer operação que usa implicitamente o acelerador padrão. Esse método só terá êxito se o Acelerador de tempo de execução padrão selecionado já não tiver sido usado em uma operação que utiliza implicitamente o acelerador padrão  
  
```  
static inline bool set_default(std::wstring _Path);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Path`  
 O caminho para o acelerador.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a chamada tiver êxito na configuração do acelerador padrão. Caso contrário, `false`.  
  
##  <a name="set_default_cpu_access_type"></a>set_default_cpu_access_type 

 Defina o access_type de cpu padrão para matrizes criados nesse acelerador ou para alocações de memória implícita como parte da array_views acessados nesse acelerador. Esse método só terá êxito se o default_cpu_access_type Accelerator ainda não tiver sido substituído por uma chamada anterior a esse método e default_cpu_access_type o tempo de execução selecionado para este acelerador não ainda foi usado para alocar uma matriz ou uma alocação de memória implícita fazendo uma array_view acessados nesse acelerador.  
  
```  
bool set_default_cpu_access_type(access_type _Default_cpu_access_type);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Default_cpu_access_type`  
 O access_type de cpu padrão a ser usado para as alocações de memória matriz/array_view esse acelerador.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que indica se o access_type de cpu padrão Accelerator foi definido com êxito.  
  
##  <a name="supports_cpu_shared_memory"></a>supports_cpu_shared_memory 

 Obtém um valor booliano que indica se o `accelerator` oferece suporte a memória compartilhada.  
  
```  
__declspec(property(get= get_supports_cpu_shared_memory)) bool supports_cpu_shared_memory;  
```  
  
##  <a name="supports_double_precision"></a>supports_double_precision 

 Obtém um valor booliano que indica se o Acelerador oferece suporte a matemática de precisão dupla.  
  
```  
__declspec(property(get= get_supports_double_precision)) bool supports_double_precision;  
```  
  
##  <a name="supports_limited_double_precision"></a>supports_limited_double_precision 

 Obtém um valor booliano que indica se o acelerador tem suporte limitado para matemática de precisão dupla. Se o acelerador tem somente suporte limitado a, com fusível multiply adicionar (FMA), divisão e recíproco conversão entre `int` e `double` não têm suporte.  
  
```  
__declspec(property(get= get_supports_limited_double_precision)) bool supports_limited_double_precision;  
```  
  
##  <a name="version"></a>Versão 

 Obtém a versão dos `accelerator`.  
  
```  
__declspec(property(get= get_version)) unsigned int version;  
```  
  
##  <a name="dtor"></a></a> ~ accelerator_view 

 Destrói o [accelerator_view](accelerator-view-class.md) objeto.  
  
```  
~accelerator_view();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="accelerator"></a>Acelerador 

 Obtém o `accelerator` de objeto para o [accelerator_view](accelerator-view-class.md) objeto.  
  
```  
__declspec(property(get= get_accelerator)) Concurrency::accelerator accelerator;  
```  
  
##  <a name="ctor"></a>accelerator_view 

 Inicializa uma nova instância do [accelerator_view](accelerator-view-class.md) classe copiando existente `accelerator_view` objeto.  
  
```  
accelerator_view(const accelerator_view& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto a ser copiado.  
  
##  <a name="create_marker"></a>create_marker 

 Retorna um futuro para controlar a conclusão de todos os comandos enviados até o momento a este `accelerator_view` objeto.  
  
```  
concurrency::completion_future create_marker();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um futuro para controlar a conclusão de todos os comandos enviados até o momento a este `accelerator_view` objeto.  
  
##  <a name="flush"></a>liberar 

 Envia todos os comandos pendentes na fila para o [accelerator_view](accelerator-view-class.md) objeto para o Acelerador de execução.  
  
```  
void flush();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `void`.  
  
##  <a name="get_accelerator"></a>get_accelerator 

 Retorna o `accelerator` de objeto para o [accelerator_view](accelerator-view-class.md) objeto.  
  
```  
accelerator get_accelerator() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `accelerator` de objeto para o `accelerator_view` objeto.  
  
##  <a name="get_is_auto_selection"></a>get_is_auto_selection 

 Retorna um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o accelerator_view é passado para um [parallel_for_each](../../../parallel/concrt/reference/concurrency-namespace-functions.md#parallel_for_each).  
  
```  
bool get_is_auto_selection() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o tempo de execução automaticamente selecionará um acelerador apropriado; Caso contrário, `false`.  
  
##  <a name="get_is_debug"></a>get_is_debug 

 Retorna um valor booliano que indica se o [accelerator_view](accelerator-view-class.md) objeto tem a camada de depuração habilitada para o relatório de erros abrangente.  
  
```  
bool get_is_debug() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que indica se o `accelerator_view` objeto tem a camada de depuração habilitada para o relatório de erros abrangente.  
  
##  <a name="get_queuing_mode"></a>get_queuing_mode 

 Retorna o modo de enfileiramento de mensagens para o [accelerator_view](accelerator-view-class.md) objeto.  
  
```  
queuing_mode get_queuing_mode() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de enfileiramento de mensagens para o `accelerator_view` objeto.  
  
##  <a name="get_version"></a>get_version 

 Retorna a versão do [accelerator_view](accelerator-view-class.md).  
  
```  
unsigned int get_version() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 A versão do `accelerator_view`.  
  
##  <a name="is_auto_selection"></a>is_auto_selection 

 Obtém um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o accelerator_view é passado para um [parallel_for_each](../../../parallel/concrt/reference/concurrency-namespace-functions.md#parallel_for_each).  
  
```  
__declspec(property(get= get_is_auto_selection)) bool is_auto_selection;  
```  
  
##  <a name="is_debug"></a>is_debug 

 Obtém um valor booliano que indica se o [accelerator_view](accelerator-view-class.md) objeto tem a camada de depuração habilitada para o relatório de erros abrangente.  
  
```  
__declspec(property(get= get_is_debug)) bool is_debug;  
```  
  
##  <a name="operator_neq"></a>operador! = 

 Compara isso [accelerator_view](accelerator-view-class.md) objeto com outra e retorna `false` se eles forem iguais; caso contrário, retornará `true`.  
  
```  
bool operator!= (const accelerator_view& _Other) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `false` se os dois objetos forem iguais; caso contrário, `true`.  
  
##  <a name="operator_eq"></a>operador = 

 Copia o conteúdo especificado [accelerator_view](accelerator-view-class.md) deste objeto.  
  
```  
accelerator_view& operator= (const accelerator_view& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a modificação `accelerator_view` objeto.  
  
##  <a name="operator_eq_eq"></a>operador = = 

 Compara isso [accelerator_view](accelerator-view-class.md) objeto com outra e retorna `true` se eles forem iguais; caso contrário, retornará `false`.  
  
```  
bool operator== (const accelerator_view& _Other) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se os dois objetos forem iguais; caso contrário, `false`.  
  
##  <a name="queuing_mode"></a>queuing_mode 

 Obtém o modo de enfileiramento de mensagens para o [accelerator_view](accelerator-view-class.md) objeto.  
  
```  
__declspec(property(get= get_queuing_mode)) Concurrency::queuing_mode queuing_mode;  
```  
  
##  <a name="version"></a>Versão 

 Obtém a versão dos [accelerator_view](accelerator-view-class.md).  
  
```  
__declspec(property(get= get_version)) unsigned int version;  
```  
  
##  <a name="wait"></a>Aguarde 

 Aguarda todos os comandos enviados para o [accelerator_view](accelerator-view-class.md) objeto para concluir.  
  
```  
void wait();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `void`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

