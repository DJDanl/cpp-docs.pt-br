---
title: "Classe accelerator | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "amprt/Concurrency::accelerator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe accelerator"
ms.assetid: 37eed593-cf87-4611-9cdc-e98df6c2377a
caps.latest.revision: 29
caps.handback.revision: 29
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe accelerator
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um acelerador é um recurso de hardware que é otimizado para computação paralela de dados. Um acelerador pode ser um dispositivo conectado a um barramento PCIe (como uma GPU) ou pode ser um conjunto de instruções estendido na CPU principal.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class accelerator;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Accelerator:: Accelerator construtor](#accelerator__accelerator_constructor)|Inicializa uma nova instância da classe `accelerator`.|  
|[Accelerator:: ~ accelerator destruidor](#accelerator___dtoraccelerator_destructor)|Destrói o `accelerator` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Accelerator:: create_view](#accelerator__create_view_method)|Cria e retorna um `accelerator_view` objeto esse acelerador.|  
|[Método Accelerator:: get_all](#accelerator__get_all_method)|Retorna um vetor de `accelerator` objetos que representam todos os Aceleradores disponíveis.|  
|[Método Accelerator:: get_auto_selection_view](#accelerator__get_auto_selection_view_method)|Retorna a seleção automática `accelerator_view`.|  
|[Método Accelerator:: get_dedicated_memory](#accelerator__get_dedicated_memory_method)|Retorna a memória dedicada para o `accelerator`, em quilobytes.|  
|[Método Accelerator:: get_default_cpu_access_type](#accelerator__get_default_cpu_access_type_method)|Retorna o padrão [access_type](../Topic/concurrency%20namespace%20enums.md#access_type) para buffers criados nesse acelerador.|  
|[Método Accelerator:: get_default_view](#accelerator__get_default_view_method)|Retorna o padrão `accelerator_view` objeto que está associado com o `accelerator`.|  
|[Método Accelerator:: get_description](#accelerator__get_description_method)|Retorna uma descrição resumida do `accelerator` dispositivo.|  
|[Método Accelerator:: get_device_path](#accelerator__get_device_path_method)|Retorna o caminho do dispositivo.|  
|[Método Accelerator:: get_has_display](#accelerator__get_has_display_method)|Determina se o `accelerator` está anexado a uma exibição.|  
|[Método Accelerator:: get_is_debug](#accelerator__get_is_debug_method)|Determina se o `accelerator` tem a camada de DEPURAÇÃO habilitada para o relatório de erros abrangente.|  
|[Método Accelerator:: get_is_emulated](#accelerator__get_is_emulated_method)|Determina se o `accelerator` é emulada.|  
|[Método Accelerator:: get_supports_cpu_shared_memory](#accelerator__get_supports_cpu_shared_memory_method)|Determina se o `accelerator` oferece suporte a memória compartilhada|  
|[Método Accelerator:: get_supports_double_precision](#accelerator__get_supports_double_precision_method)|Determina se o `accelerator` está anexado a uma exibição.|  
|[Método Accelerator:: get_supports_limited_double_precision](#accelerator__get_supports_limited_double_precision_method)|Determina se o `accelerator` tem suporte limitado para matemática de precisão dupla.|  
|[Método Accelerator:: get_version](#accelerator__get_version_method)|Retorna a versão do `accelerator`.|  
|[Método Accelerator:: set_default](#accelerator__set_default_method)|Retorna o caminho do acelerador padrão.|  
|[Método Accelerator:: set_default_cpu_access_type](#accelerator__set_default_cpu_access_type_method)|Define a CPU padrão [access_type](../Topic/concurrency%20namespace%20enums.md#access_type) para matrizes e alocações de memória implícita feitas neste `accelerator`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Accelerator:: Operator! = operador](#accelerator__operator_neq_operator)|Compara isso `accelerator` objeto com outra e retorna `false` se eles forem iguais; caso contrário, retornará `true`.|  
|[Accelerator:: Operator operador =](#accelerator__operator_eq_operator)|Copia o conteúdo especificado `accelerator` objeto a este.|  
|[Accelerator:: Operator = = operador](#accelerator__operator_eq_eq_operator)|Compara isso `accelerator` objeto com outra e retorna `true` se eles forem iguais; caso contrário, retornará `false`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Accelerator:: cpu_accelerator membro de dados](#accelerator__cpu_accelerator_data_member)|Obtém uma cadeia de caracteres constante da CPU `accelerator`.|  
|[Accelerator:: dedicated_memory membro de dados](#accelerator__dedicated_memory_data_member)|Obtém a memória dedicada para o `accelerator`, em quilobytes.|  
|[Accelerator:: default_accelerator membro de dados](#accelerator__default_accelerator_data_member)|Obtém uma cadeia de caracteres constante para o padrão `accelerator`.|  
|[Accelerator:: default_cpu_access_type membro de dados](#accelerator__default_cpu_access_type_data_member)|Obtém ou define a CPU padrão [access_type](../Topic/concurrency%20namespace%20enums.md#access_type) para matrizes e alocações de memória implícita feitas neste `accelerator`.|  
|[Accelerator:: default_view membro de dados](#accelerator__default_view_data_member)|Obtém o padrão `accelerator_view` objeto que está associado com o `accelerator`.|  
|[Accelerator:: Description membro de dados](#accelerator__description_data_member)|Obtém uma descrição resumida do `accelerator` dispositivo.|  
|[Accelerator:: device_path membro de dados](#accelerator__device_path_data_member)|Obtém o caminho do dispositivo.|  
|[Membro de dados Accelerator:: direct3d_ref](#accelerator__direct3d_ref_data_member)|Obtém uma cadeia de caracteres constante para obter uma referência do Direct3D `accelerator`.|  
|[Membro de dados Accelerator:: direct3d_warp](#accelerator__direct3d_warp_data_member)|Obtém a cadeia de caracteres constante para um [accelerator](../../../parallel/amp/reference/accelerator-class.md) do objeto que você pode usar para executar o código C++ AMP em CPUs de vários núcleos que usam o Streaming SIMD Extensions (SSE).|  
|[Accelerator:: has_display membro de dados](#accelerator__has_display_data_member)|Obtém um valor booliano que indica se o `accelerator` está anexado a uma exibição.|  
|[Accelerator:: is_debug membro de dados](#accelerator__is_debug_data_member)|Indica se o `accelerator` tem a camada de DEPURAÇÃO habilitada para o relatório de erros abrangente.|  
|[Accelerator:: is_emulated membro de dados](#accelerator__is_emulated_data_member)|Indica se o `accelerator` é emulada.|  
|[Accelerator:: supports_cpu_shared_memory membro de dados](#accelerator__supports_cpu_shared_memory_data_member)|Indica se o `accelerator` oferece suporte a memória compartilhada.|  
|[Accelerator:: supports_double_precision membro de dados](#accelerator__supports_double_precision_data_member)|Indica se o Acelerador oferece suporte a matemática de precisão dupla.|  
|[Accelerator:: supports_limited_double_precision membro de dados](#accelerator__supports_limited_double_precision_data_member)|Indica se o acelerador tem suporte limitado para matemática de precisão dupla.|  
|[Accelerator:: Version membro de dados](#accelerator__version_data_member)|Obtém a versão dos `accelerator`.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `accelerator`  
  
## <a name="remarks"></a>Comentários  
 Um acelerador é um recurso de hardware que é otimizado para computação paralela de dados. Um acelerador costuma ser uma GPU discreta, mas também pode ser uma entidade do host virtual como um dispositivo DirectX REF, uma DISTORÇÃO (um dispositivo do lado da CPU é acelerado por meio de instruções SSE), ou a própria CPU.  
  
 Você pode construir um `accelerator` objeto Enumerando os dispositivos disponíveis ou fazendo com que o dispositivo padrão, o dispositivo de referência ou o dispositivo de DISTORÇÃO.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-nameacceleratordtoracceleratordestructora-acceleratoraccelerator-destructor"></a><a name="accelerator___dtoraccelerator_destructor"></a>  Accelerator:: ~ accelerator destruidor  
 Destrói o [accelerator](../../../parallel/amp/reference/accelerator-class.md) objeto.  
  
```  
~accelerator();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="a-nameacceleratoracceleratorconstructora-acceleratoraccelerator-constructor"></a><a name="accelerator__accelerator_constructor"></a>  Accelerator:: Accelerator construtor  
 Inicializa uma nova instância de [classe accelerator](../../../parallel/amp/reference/accelerator-class.md).  
  
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
  
##  <a name="a-nameacceleratorcpuacceleratordatamembera-acceleratorcpuaccelerator-data-member"></a><a name="accelerator__cpu_accelerator_data_member"></a>  Accelerator:: cpu_accelerator membro de dados  
 Obtém uma cadeia de caracteres constante para o Acelerador de CPU.  
  
```  
static const wchar_t cpu_accelerator[];  
```  
  
##  <a name="a-nameacceleratorcreateviewmethoda-acceleratorcreateview-method"></a><a name="accelerator__create_view_method"></a>  Método Accelerator:: create_view  
 Cria e retorna um `accelerator_view` objeto esse acelerador, usando o modo de enfileiramento de mensagens especificado. Quando o modo de enfileiramento de mensagens não for especificado, o novo `accelerator_view` usa o [queuing_mode::immediate](../Topic/concurrency%20namespace%20enums.md#queuing_mode) modo de enfileiramento de mensagens.  
  
```  
accelerator_view create_view(queuing_mode qmode = queuing_mode_automatic);
```  
  
### <a name="parameters"></a>Parâmetros  
 `qmode`  
 O modo de enfileiramento de mensagens.  
  
### <a name="return-value"></a>Valor de retorno  
 Um novo `accelerator_view` objeto esse acelerador, usando o modo de enfileiramento de mensagens especificado.  
  
##  <a name="a-nameacceleratordedicatedmemorydatamembera-acceleratordedicatedmemory-data-member"></a><a name="accelerator__dedicated_memory_data_member"></a>  Accelerator:: dedicated_memory membro de dados  
 Obtém a memória dedicada para o [accelerator](../../../parallel/amp/reference/accelerator-class.md), em quilobytes.  
  
```  
__declspec(property(get= get_dedicated_memory)) size_t dedicated_memory;  
```  
  
##  <a name="a-nameacceleratordefaultacceleratordatamembera-acceleratordefaultaccelerator-data-member"></a><a name="accelerator__default_accelerator_data_member"></a>  Accelerator:: default_accelerator membro de dados  
 Obtém uma cadeia de caracteres constante para o padrão [accelerator](../../../parallel/amp/reference/accelerator-class.md).  
  
```  
static const wchar_t default_accelerator[];  
```  
  
##  <a name="a-nameacceleratordefaultcpuaccesstypedatamembera-acceleratordefaultcpuaccesstype-data-member"></a><a name="accelerator__default_cpu_access_type_data_member"></a>  Accelerator:: default_cpu_access_type membro de dados  
 O padrão cpu [access_type](../Topic/concurrency%20namespace%20enums.md#access_type) para matrizes e alocações de memória implícita feitas sobre essa isso `accelerator`.  
  
```  
__declspec(property(get= get_default_cpu_access_type)) access_type default_cpu_access_type;  
```  
  
##  <a name="a-nameacceleratordefaultviewdatamembera-acceleratordefaultview-data-member"></a><a name="accelerator__default_view_data_member"></a>  Accelerator:: default_view membro de dados  
 Obtém o modo de acelerador padrão que está associado com o [accelerator](../../../parallel/amp/reference/accelerator-class.md).  
  
```  
__declspec(property(get= get_default_view)) accelerator_view default_view;  
```  
  
##  <a name="a-nameacceleratordescriptiondatamembera-acceleratordescription-data-member"></a><a name="accelerator__description_data_member"></a>  Accelerator:: Description membro de dados  
 Obtém uma descrição resumida do [accelerator](../../../parallel/amp/reference/accelerator-class.md) dispositivo.  
  
```  
__declspec(property(get= get_description)) std::wstring description;  
```  
  
##  <a name="a-nameacceleratordevicepathdatamembera-acceleratordevicepath-data-member"></a><a name="accelerator__device_path_data_member"></a>  Accelerator:: device_path membro de dados  
 Obtém o caminho do accelerator. O caminho é exclusivo no sistema.  
  
```  
__declspec(property(get= get_device_path)) std::wstring device_path;  
```  
  
##  <a name="a-nameacceleratordirect3drefdatamembera-acceleratordirect3dref-data-member"></a><a name="accelerator__direct3d_ref_data_member"></a>  Membro de dados Accelerator:: direct3d_ref  
 Obtém uma cadeia de caracteres constante para um acelerador de referência do Direct3D.  
  
```  
static const wchar_t direct3d_ref[];  
```  
  
##  <a name="a-nameacceleratordirect3dwarpdatamembera-acceleratordirect3dwarp-data-member"></a><a name="accelerator__direct3d_warp_data_member"></a>  Membro de dados Accelerator:: direct3d_warp  
 Obtém a cadeia de caracteres constante para um [accelerator](../../../parallel/amp/reference/accelerator-class.md) do objeto que você pode usar para executar seu código C++ AMP em CPUs de vários núcleos usando Streaming SIMD Extensions (SSE).  
  
```  
static const wchar_t direct3d_warp[];  
```  
  
##  <a name="a-nameacceleratorgetallmethoda-acceleratorgetall-method"></a><a name="accelerator__get_all_method"></a>  Método Accelerator:: get_all  
 Retorna um vetor de `accelerator` objetos que representam todos os Aceleradores disponíveis.  
  
```  
static inline std::vector<accelerator> get_all();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O vetor de Aceleradores disponíveis  
  
##  <a name="a-nameacceleratorgetautoselectionviewmethoda-acceleratorgetautoselectionview-method"></a><a name="accelerator__get_auto_selection_view_method"></a>  Método Accelerator:: get_auto_selection_view  
 Retorna o accelerator_view de seleção automática, que, quando especificado como os resultados de destino parallel_for_each em accelerator_view de destino para executar o kernel parallel_for_each seja selecionado automaticamente pelo tempo de execução. Para outras finalidades, o accelerator_view retornado por esse método é o mesmo que o accelerator_view padrão do acelerador padrão  
  
```  
static accelerator_view __cdecl get_auto_selection_view();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Accelerator_view a seleção automática.  
  
##  <a name="a-nameacceleratorgetdedicatedmemorymethoda-acceleratorgetdedicatedmemory-method"></a><a name="accelerator__get_dedicated_memory_method"></a>  Método Accelerator:: get_dedicated_memory  
 Retorna a memória dedicada para o [accelerator](../../../parallel/amp/reference/accelerator-class.md), em quilobytes.  
  
```  
size_t get_dedicated_memory() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 A memória dedicada para o `accelerator`, em quilobytes.  
  
##  <a name="a-nameacceleratorgetdefaultcpuaccesstypemethoda-acceleratorgetdefaultcpuaccesstype-method"></a><a name="accelerator__get_default_cpu_access_type_method"></a>  Método Accelerator:: get_default_cpu_access_type  
 Obtém o access_type de cpu padrão para buffers criados nesse acelerador  
  
```  
access_type get_default_cpu_access_type() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O access_type de cpu padrão para buffers criado nesse acelerador.  
  
##  <a name="a-nameacceleratorgetdefaultviewmethoda-acceleratorgetdefaultview-method"></a><a name="accelerator__get_default_view_method"></a>  Método Accelerator:: get_default_view  
 Retorna o padrão `accelerator_view` objeto que está associado com o [accelerator](../../../parallel/amp/reference/accelerator-class.md).  
  
```  
accelerator_view get_default_view() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O padrão `accelerator_view` objeto que está associado com o `accelerator`.  
  
##  <a name="a-nameacceleratorgetdescriptionmethoda-acceleratorgetdescription-method"></a><a name="accelerator__get_description_method"></a>  Método Accelerator:: get_description  
 Retorna uma descrição resumida do [accelerator](../../../parallel/amp/reference/accelerator-class.md) dispositivo.  
  
```  
std::wstring get_description() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma descrição resumida do `accelerator` dispositivo.  
  
##  <a name="a-nameacceleratorgetdevicepathmethoda-acceleratorgetdevicepath-method"></a><a name="accelerator__get_device_path_method"></a>  Método Accelerator:: get_device_path  
 Retorna o caminho do accelerator. O caminho é exclusivo no sistema.  
  
```  
std::wstring get_device_path() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O caminho de instância de dispositivo exclusivo de todo o sistema.  
  
##  <a name="a-nameacceleratorgethasdisplaymethoda-acceleratorgethasdisplay-method"></a><a name="accelerator__get_has_display_method"></a>  Método Accelerator:: get_has_display  
 Retorna um valor booliano que indica se o [accelerator](../../../parallel/amp/reference/accelerator-class.md) pode dar saída a uma exibição.  
  
```  
bool get_has_display() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o `accelerator` pode dar saída a uma exibição; caso contrário, `false`.  
  
##  <a name="a-nameacceleratorgetisdebugmethoda-acceleratorgetisdebug-method"></a><a name="accelerator__get_is_debug_method"></a>  Método Accelerator:: get_is_debug  
 Determina se o [accelerator](../../../parallel/amp/reference/accelerator-class.md) tem a camada de DEPURAÇÃO habilitada para o relatório de erros abrangente.  
  
```  
bool get_is_debug() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o `accelerator` tem a camada de DEPURAÇÃO habilitada para o relatório de erros abrangente. Caso contrário, `false`.  
  
##  <a name="a-nameacceleratorgetisemulatedmethoda-acceleratorgetisemulated-method"></a><a name="accelerator__get_is_emulated_method"></a>  Método Accelerator:: get_is_emulated  
 Determina se o [accelerator](../../../parallel/amp/reference/accelerator-class.md) é emulada.  
  
```  
bool get_is_emulated() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o `accelerator` é emulada. Caso contrário, `false`.  
  
##  <a name="a-nameacceleratorgetsupportscpusharedmemorymethoda-acceleratorgetsupportscpusharedmemory-method"></a><a name="accelerator__get_supports_cpu_shared_memory_method"></a>  Método Accelerator:: get_supports_cpu_shared_memory  
 Retorna um valor booliano que indica se o Acelerador oferece suporte a memória acessível pelo Acelerador e CPU.  
  
```  
bool get_supports_cpu_shared_memory() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o Acelerador oferece suporte a memória de CPU compartilhada; Caso contrário, `false`.  
  
##  <a name="a-nameacceleratorgetsupportsdoubleprecisionmethoda-acceleratorgetsupportsdoubleprecision-method"></a><a name="accelerator__get_supports_double_precision_method"></a>  Método Accelerator:: get_supports_double_precision  
 Retorna um valor booliano que indica se o Acelerador oferece suporte a matemática de precisão dupla, incluindo fusível multiplicar adicionar (FMA), divisão e recíproco conversão entre `int` e `double`.  
  
```  
bool get_supports_double_precision() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o accelerator suporta double math de precisão; Caso contrário, `false`.  
  
##  <a name="a-nameacceleratorgetsupportslimiteddoubleprecisionmethoda-acceleratorgetsupportslimiteddoubleprecision-method"></a><a name="accelerator__get_supports_limited_double_precision_method"></a>  Método Accelerator:: get_supports_limited_double_precision  
 Retorna um valor booliano que indica se o acelerador tem suporte limitado para matemática de precisão dupla. Se o acelerador tem somente suporte limitado a, com fusível multiply adicionar (FMA), divisão e recíproco conversão entre `int` e `double` não têm suporte.  
  
```  
bool get_supports_limited_double_precision() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o acelerador tem suporte limitado para double math de precisão; Caso contrário, `false`.  
  
##  <a name="a-nameacceleratorgetversionmethoda-acceleratorgetversion-method"></a><a name="accelerator__get_version_method"></a>  Método Accelerator:: get_version  
 Retorna a versão do [accelerator](../../../parallel/amp/reference/accelerator-class.md).  
  
```  
unsigned int get_version() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 A versão do `accelerator`.  
  
##  <a name="a-nameacceleratorhasdisplaydatamembera-acceleratorhasdisplay-data-member"></a><a name="accelerator__has_display_data_member"></a>  Accelerator:: has_display membro de dados  
 Obtém um valor booliano que indica se o [accelerator](../../../parallel/amp/reference/accelerator-class.md) pode dar saída a uma exibição.  
  
```  
__declspec(property(get= get_has_display)) bool has_display;  
```  
  
##  <a name="a-nameacceleratorisdebugdatamembera-acceleratorisdebug-data-member"></a><a name="accelerator__is_debug_data_member"></a>  Accelerator:: is_debug membro de dados  
 Obtém um valor booliano que indica se o [accelerator](../../../parallel/amp/reference/accelerator-class.md) tem a camada de DEPURAÇÃO habilitada para o relatório de erros abrangente.  
  
```  
__declspec(property(get= get_is_debug)) bool is_debug;  
```  
  
##  <a name="a-nameacceleratorisemulateddatamembera-acceleratorisemulated-data-member"></a><a name="accelerator__is_emulated_data_member"></a>  Accelerator:: is_emulated membro de dados  
 Obtém um valor booliano que indica se o [accelerator](../../../parallel/amp/reference/accelerator-class.md) é emulada.  
  
```  
__declspec(property(get= get_is_emulated)) bool is_emulated;  
```  
  
##  <a name="a-nameacceleratoroperatorneqoperatora-acceleratoroperator-operator"></a><a name="accelerator__operator_neq_operator"></a>  Accelerator:: Operator! = operador  
 Compara isso `accelerator` objeto com outra e retorna `false` se eles forem iguais; caso contrário, retornará `true`.  
  
```  
bool operator!= (const accelerator& _Other) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `false` Se os dois `accelerator` objetos forem iguais; caso contrário, `true`.  
  
##  <a name="a-nameacceleratoroperatoreqoperatora-acceleratoroperator-operator"></a><a name="accelerator__operator_eq_operator"></a>  Accelerator:: Operator operador =  
 Copia o conteúdo especificado [accelerator](../../../parallel/amp/reference/accelerator-class.md) objeto a este.  
  
```  
accelerator& operator= (const accelerator& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a esta `accelerator` objeto.  
  
##  <a name="a-nameacceleratoroperatoreqeqoperatora-acceleratoroperator-operator"></a><a name="accelerator__operator_eq_eq_operator"></a>  Accelerator:: Operator = = operador  
 Compara isso [accelerator](../../../parallel/amp/reference/accelerator-class.md) objeto com outra e retorna `true` se eles forem iguais; caso contrário, retornará `false`.  
  
```  
bool operator== (const accelerator& _Other) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o outro `accelerator` objeto é o mesmo que isso `accelerator` objeto; caso contrário, `false`.  
  
##  <a name="a-nameacceleratorsetdefaultmethoda-acceleratorsetdefault-method"></a><a name="accelerator__set_default_method"></a>  Método Accelerator:: set_default  
 Define o acelerador padrão a ser usado para qualquer operação que usa implicitamente o acelerador padrão. Esse método só terá êxito se o Acelerador de tempo de execução padrão selecionado já não tiver sido usado em uma operação que utiliza implicitamente o acelerador padrão  
  
```  
static inline bool set_default(std::wstring _Path);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Path`  
 O caminho para o acelerador.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se a chamada tiver êxito na configuração do acelerador padrão. Caso contrário, `false`.  
  
##  <a name="a-nameacceleratorsetdefaultcpuaccesstypemethoda-acceleratorsetdefaultcpuaccesstype-method"></a><a name="accelerator__set_default_cpu_access_type_method"></a>  Método Accelerator:: set_default_cpu_access_type  
 Defina o access_type de cpu padrão para matrizes criados nesse acelerador ou para alocações de memória implícita como parte da array_views acessados nesse acelerador. Esse método só terá êxito se o default_cpu_access_type Accelerator ainda não tiver sido substituído por uma chamada anterior a esse método e default_cpu_access_type o tempo de execução selecionado para este acelerador não ainda foi usado para alocar uma matriz ou uma alocação de memória implícita fazendo uma array_view acessados nesse acelerador.  
  
```  
bool set_default_cpu_access_type(access_type _Default_cpu_access_type);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Default_cpu_access_type`  
 O access_type de cpu padrão a ser usado para as alocações de memória matriz/array_view esse acelerador.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que indica se o access_type de cpu padrão Accelerator foi definido com êxito.  
  
##  <a name="a-nameacceleratorsupportscpusharedmemorydatamembera-acceleratorsupportscpusharedmemory-data-member"></a><a name="accelerator__supports_cpu_shared_memory_data_member"></a>  Accelerator:: supports_cpu_shared_memory membro de dados  
 Obtém um valor booliano que indica se o `accelerator` oferece suporte a memória compartilhada.  
  
```  
__declspec(property(get= get_supports_cpu_shared_memory)) bool supports_cpu_shared_memory;  
```  
  
##  <a name="a-nameacceleratorsupportsdoubleprecisiondatamembera-acceleratorsupportsdoubleprecision-data-member"></a><a name="accelerator__supports_double_precision_data_member"></a>  Accelerator:: supports_double_precision membro de dados  
 Obtém um valor booliano que indica se o Acelerador oferece suporte a matemática de precisão dupla.  
  
```  
__declspec(property(get= get_supports_double_precision)) bool supports_double_precision;  
```  
  
##  <a name="a-nameacceleratorsupportslimiteddoubleprecisiondatamembera-acceleratorsupportslimiteddoubleprecision-data-member"></a><a name="accelerator__supports_limited_double_precision_data_member"></a>  Accelerator:: supports_limited_double_precision membro de dados  
 Obtém um valor booliano que indica se o acelerador tem suporte limitado para matemática de precisão dupla. Se o acelerador tem somente suporte limitado a, com fusível multiply adicionar (FMA), divisão e recíproco conversão entre `int` e `double` não têm suporte.  
  
```  
__declspec(property(get= get_supports_limited_double_precision)) bool supports_limited_double_precision;  
```  
  
##  <a name="a-nameacceleratorversiondatamembera-acceleratorversion-data-member"></a><a name="accelerator__version_data_member"></a>  Accelerator:: Version membro de dados  
 Obtém a versão dos [accelerator](../../../parallel/amp/reference/accelerator-class.md).  
  
```  
__declspec(property(get= get_version)) unsigned int version;  
```  
  
##  <a name="a-nameacceleratorviewdtoracceleratorviewdestructora-acceleratorviewacceleratorview-destructor"></a><a name="accelerator_view___dtoraccelerator_view_destructor"></a>  accelerator_view:: ~ accelerator_view destruidor  
 Destrói o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto.  
  
```  
~accelerator_view();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="a-nameacceleratorviewacceleratordatamembera-acceleratorviewaccelerator-data-member"></a><a name="accelerator_view__accelerator_data_member"></a>  accelerator_view:: Accelerator membro de dados  
 Obtém o [accelerator](../../../parallel/amp/reference/accelerator-class.md) do objeto para o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto.  
  
```  
__declspec(property(get= get_accelerator)) Concurrency::accelerator accelerator;  
```  
  
##  <a name="a-nameacceleratorviewacceleratorviewconstructora-acceleratorviewacceleratorview-constructor"></a><a name="accelerator_view__accelerator_view_constructor"></a>  accelerator_view:: accelerator_view construtor  
 Inicializa uma nova instância do [accelerator_view](../Topic/accelerator_view%20Class.md) classe copiando existente `accelerator_view` objeto.  
  
```  
accelerator_view(const accelerator_view& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto a ser copiado.  
  
##  <a name="a-nameacceleratorviewcreatemarkermethoda-acceleratorviewcreatemarker-method"></a><a name="accelerator_view__create_marker_method"></a>  Método accelerator_view:: create_marker  
 Retorna um futuro para controlar a conclusão de todos os comandos enviados até o momento a este `accelerator_view` objeto.  
  
```  
concurrency::completion_future create_marker();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um futuro para controlar a conclusão de todos os comandos enviados até o momento a este `accelerator_view` objeto.  
  
##  <a name="a-nameacceleratorviewflushmethoda-acceleratorviewflush-method"></a><a name="accelerator_view__flush_method"></a>  Método accelerator_view:: Flush  
 Envia todos os comandos pendentes na fila para o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto para o Acelerador de execução.  
  
```  
void flush();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `void`.  
  
##  <a name="a-nameacceleratorviewgetacceleratormethoda-acceleratorviewgetaccelerator-method"></a><a name="accelerator_view__get_accelerator_method"></a>  Método accelerator_view:: get_accelerator  
 Retorna o [accelerator](../../../parallel/amp/reference/accelerator-class.md) do objeto para o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto.  
  
```  
accelerator get_accelerator() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `accelerator` do objeto para o `accelerator_view` objeto.  
  
##  <a name="a-nameacceleratorviewgetisautoselectionmethoda-acceleratorviewgetisautoselection-method"></a><a name="accelerator_view__get_is_auto_selection_method"></a>  Método accelerator_view:: get_is_auto_selection  
 Retorna um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o accelerator_view é passado para um [parallel_for_each](../Topic/concurrency%20namespace%20functions.md#parallel_for_each).  
  
```  
bool get_is_auto_selection() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se o tempo de execução automaticamente selecionará um acelerador apropriado; Caso contrário, `false`.  
  
##  <a name="a-nameacceleratorviewgetisdebugmethoda-acceleratorviewgetisdebug-method"></a><a name="accelerator_view__get_is_debug_method"></a>  Método accelerator_view:: get_is_debug  
 Retorna um valor booliano que indica se o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto tem a camada de DEPURAÇÃO habilitada para o relatório de erros abrangente.  
  
```  
bool get_is_debug() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que indica se o `accelerator_view` objeto tem a camada de DEPURAÇÃO habilitada para o relatório de erros abrangente.  
  
##  <a name="a-nameacceleratorviewgetqueuingmodemethoda-acceleratorviewgetqueuingmode-method"></a><a name="accelerator_view__get_queuing_mode_method"></a>  Método accelerator_view:: get_queuing_mode  
 Retorna o modo de enfileiramento de mensagens para o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto.  
  
```  
queuing_mode get_queuing_mode() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de enfileiramento de mensagens para o `accelerator_view` objeto.  
  
##  <a name="a-nameacceleratorviewgetversionmethoda-acceleratorviewgetversion-method"></a><a name="accelerator_view__get_version_method"></a>  Método accelerator_view:: get_version  
 Retorna a versão do [accelerator_view](../Topic/accelerator_view%20Class.md).  
  
```  
unsigned int get_version() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 A versão do `accelerator_view`.  
  
##  <a name="a-nameacceleratorviewisautoselectiondatamembera-acceleratorviewisautoselection-data-member"></a><a name="accelerator_view__is_auto_selection_data_member"></a>  accelerator_view:: is_auto_selection membro de dados  
 Obtém um valor booliano que indica se o tempo de execução selecionará automaticamente um acelerador apropriado quando o accelerator_view é passado para um [parallel_for_each](concurrency%20namespace%20functions.md#parallel_for_each).  
  
```  
__declspec(property(get= get_is_auto_selection)) bool is_auto_selection;  
```  
  
##  <a name="a-nameacceleratorviewisdebugdatamembera-acceleratorviewisdebug-data-member"></a><a name="accelerator_view__is_debug_data_member"></a>  accelerator_view:: is_debug membro de dados  
 Obtém um valor booliano que indica se o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto tem a camada de DEPURAÇÃO habilitada para o relatório de erros abrangente.  
  
```  
__declspec(property(get= get_is_debug)) bool is_debug;  
```  
  
##  <a name="a-nameacceleratorviewoperatorneqoperatora-acceleratorviewoperator-operator"></a><a name="accelerator_view__operator_neq_operator"></a>  accelerator_view:: Operator! = operador  
 Compara isso [accelerator_view](../Topic/accelerator_view%20Class.md) objeto com outra e retorna `false` se eles forem iguais; caso contrário, retornará `true`.  
  
```  
bool operator!= (const accelerator_view& _Other) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `false` se os dois objetos forem iguais; caso contrário, `true`.  
  
##  <a name="a-nameacceleratorviewoperatoreqoperatora-acceleratorviewoperator-operator"></a><a name="accelerator_view__operator_eq_operator"></a>  accelerator_view:: Operator operador =  
 Copia o conteúdo especificado [accelerator_view](../Topic/accelerator_view%20Class.md) deste objeto.  
  
```  
accelerator_view& operator= (const accelerator_view& _Other);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto copiar de.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a modificação `accelerator_view` objeto.  
  
##  <a name="a-nameacceleratorviewoperatoreqeqoperatora-acceleratorviewoperator-operator"></a><a name="accelerator_view__operator_eq_eq_operator"></a>  accelerator_view:: Operator = = operador  
 Compara isso [accelerator_view](../Topic/accelerator_view%20Class.md) objeto com outra e retorna `true` se eles forem iguais; caso contrário, retornará `false`.  
  
```  
bool operator== (const accelerator_view& _Other) const;

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Other`  
 O `accelerator_view` objeto a ser comparado com este.  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se os dois objetos forem iguais; caso contrário, `false`.  
  
##  <a name="a-nameacceleratorviewqueuingmodedatamembera-acceleratorviewqueuingmode-data-member"></a><a name="accelerator_view__queuing_mode_data_member"></a>  accelerator_view:: queuing_mode membro de dados  
 Obtém o modo de enfileiramento de mensagens para o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto.  
  
```  
__declspec(property(get= get_queuing_mode)) Concurrency::queuing_mode queuing_mode;  
```  
  
##  <a name="a-nameacceleratorviewversiondatamembera-acceleratorviewversion-data-member"></a><a name="accelerator_view__version_data_member"></a>  accelerator_view:: Version membro de dados  
 Obtém a versão dos [accelerator_view](../Topic/accelerator_view%20Class.md).  
  
```  
__declspec(property(get= get_version)) unsigned int version;  
```  
  
##  <a name="a-nameacceleratorviewwaitmethoda-acceleratorviewwait-method"></a><a name="accelerator_view__wait_method"></a>  Método accelerator_view:: wait  
 Aguarda todos os comandos enviados para o [accelerator_view](../Topic/accelerator_view%20Class.md) objeto para concluir.  
  
```  
void wait();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `void`.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Concurrency (C++ AMP)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)
