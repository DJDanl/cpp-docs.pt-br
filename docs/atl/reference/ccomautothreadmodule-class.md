---
title: Classe CComAutoThreadModule
ms.date: 11/04/2016
f1_keywords:
- CComAutoThreadModule
- ATLBASE/ATL::CComAutoThreadModule
- ATLBASE/ATL::CreateInstance
- ATLBASE/ATL::GetDefaultThreads
- ATLBASE/ATL::Init
- ATLBASE/ATL::Lock
- ATLBASE/ATL::Unlock
- ATLBASE/ATL::dwThreadID
- ATLBASE/ATL::m_Allocator
- ATLBASE/ATL::m_nThreads
- ATLBASE/ATL::m_pApartments
helpviewer_keywords:
- CComAutoThreadModule class
- apartment model modules
ms.assetid: 13063ea5-a57e-4aac-97d3-227137262811
ms.openlocfilehash: 9b0fa685bf9a7de94b158bd62b00161c1b58562d
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866167"
---
# <a name="ccomautothreadmodule-class"></a>Classe CComAutoThreadModule

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class ThreadAllocator = CComSimpleThreadAllocator>
class CComAutoThreadModule : public CComModule
```

#### <a name="parameters"></a>parâmetros

*ThreadAllocator*<br/>
no A classe que gerencia a seleção de thread. O valor padrão é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CreateInstance](#createinstance)|Seleciona um thread e, em seguida, cria um objeto no apartamento associado.|
|[GetDefaultThreads](#getdefaultthreads)|Auto-estática Calcula dinamicamente o número de threads para o módulo com base no número de processadores.|
|[Init](#init)|Cria os threads do módulo.|
|[Proprietário](#lock)|Incrementa a contagem de bloqueios no módulo e no thread atual.|
|[Automático](#unlock)|Decrementa a contagem de bloqueios no módulo e no thread atual.|

### <a name="data-members"></a>Membros de dados

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[dwThreadID](#dwthreadid)|Contém o identificador do thread atual.|
|[m_Allocator](#m_allocator)|Gerencia a seleção de threads.|
|[m_nThreads](#m_nthreads)|Contém o número de threads no módulo.|
|[m_pApartments](#m_papartments)|Gerencia o Apartments do módulo.|

## <a name="remarks"></a>Comentários

> [!NOTE]
>  Esta classe está obsoleta, tendo sido substituída pelas classes derivadas [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) e [CAtlModule](../../atl/reference/catlmodule-class.md) . As informações a seguir são para uso com versões mais antigas do ATL.

`CComAutoThreadModule` deriva de [CComModule](../../atl/reference/ccommodule-class.md) para implementar um servidor com de modelo de apartamento em pool de threads para EXEs e serviços do Windows. `CComAutoThreadModule` usa [CComApartment](../../atl/reference/ccomapartment-class.md) para gerenciar um apartamento para cada thread no módulo.

Derive seu módulo de `CComAutoThreadModule` quando desejar criar objetos em vários Apartments. Você também deve incluir a macro [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) na definição de classe do seu objeto para especificar [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como a fábrica de classes.

Por padrão, o ATL COM AppWizard (o assistente de projeto do ATL no Visual Studio .NET) irá derivar seu módulo do `CComModule`. Para usar `CComAutoThreadModule`, modifique a definição de classe. Por exemplo:

[!code-cpp[NVC_ATL_AxHost#2](../../atl/codesnippet/cpp/ccomautothreadmodule-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[CAtlModule](../../atl/reference/catlmodule-class.md)

`IAtlAutoThreadModule`

[CAtlModuleT](../../atl/reference/catlmodulet-class.md)

[CAtlAutoThreadModuleT](../../atl/reference/catlautothreadmodulet-class.md)

[CComModule](../../atl/reference/ccommodule-class.md)

`CComAutoThreadModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="createinstance"></a>CComAutoThreadModule:: CreateInstance

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT CreateInstance(
    void* pfnCreateInstance,
    REFIID riid,
    void** ppvObj);
```

### <a name="parameters"></a>parâmetros

*pfnCreateInstance*<br/>
no Um ponteiro para uma função de criador.

*riid*<br/>
no O IID da interface solicitada.

*ppvObj*<br/>
fora Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não oferecer suporte a essa interface, *ppvObj* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Seleciona um thread e, em seguida, cria um objeto no apartamento associado.

##  <a name="dwthreadid"></a>CComAutoThreadModule::d wThreadID

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
DWORD dwThreadID;
```

### <a name="remarks"></a>Comentários

Contém o identificador do thread atual.

##  <a name="getdefaultthreads"></a>CComAutoThreadModule::GetDefaultThreads

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
static int GetDefaultThreads();
```

### <a name="return-value"></a>Valor retornado

O número de threads a serem criados no módulo EXE.

### <a name="remarks"></a>Comentários

Essa função estática calcula dinamicamente o número máximo de threads para o módulo EXE, com base no número de processadores. Por padrão, esse valor de retorno é passado para o método [init](#init) para criar os threads.

##  <a name="init"></a>CComAutoThreadModule:: init

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT Init(
    _ATL_OBJMAP_ENTRY* p,
    HINSTANCE h,
    const GUID* plibid = NULL,
    int nThreads = GetDefaultThreads());
```

### <a name="parameters"></a>parâmetros

*p*<br/>
no Um ponteiro para uma matriz de entradas de mapa de objeto.

*h*<br/>
no O HINSTANCE passado para `DLLMain` ou `WinMain`.

*plibid*<br/>
no Um ponteiro para o LIBID da biblioteca de tipos associada ao projeto.

*nThreads*<br/>
no O número de threads a serem criados. Por padrão, *nThreads* é o valor retornado por [GetDefaultThreads](#getdefaultthreads).

### <a name="remarks"></a>Comentários

Inicializa membros de dados e cria o número de threads especificados por *nThreads*.

##  <a name="lock"></a>CComAutoThreadModule:: Lock

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
LONG Lock();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnóstico ou teste.

### <a name="remarks"></a>Comentários

Executa um incremento atômico na contagem de bloqueios para o módulo e para o thread atual. `CComAutoThreadModule` usa a contagem de bloqueios de módulo para determinar se algum cliente está acessando o módulo. A contagem de bloqueios no thread atual é usada para fins estatísticos.

##  <a name="m_allocator"></a>CComAutoThreadModule:: m_Allocator

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
ThreadAllocator  m_Allocator;
```

### <a name="remarks"></a>Comentários

O objeto que gerencia a seleção de thread. Por padrão, o parâmetro de modelo de classe `ThreadAllocator` é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).

##  <a name="m_nthreads"></a>CComAutoThreadModule:: m_nThreads

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
int m_nThreads;
```

### <a name="remarks"></a>Comentários

Contém o número de threads no módulo EXE. Quando [init](#init) é chamado, `m_nThreads` é definido como o valor do parâmetro *nThreads* . O Apartment associado de cada thread é gerenciado por um objeto [CComApartment](../../atl/reference/ccomapartment-class.md) .

##  <a name="m_papartments"></a>CComAutoThreadModule:: m_pApartments

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
CComApartment* m_pApartments;
```

### <a name="remarks"></a>Comentários

Aponta para uma matriz de objetos [CComApartment](../../atl/reference/ccomapartment-class.md) , cada um dos quais gerencia um apartamento no módulo. O número de elementos na matriz é baseado no membro [m_nThreads](#m_nthreads) .

##  <a name="unlock"></a>CComAutoThreadModule:: desbloquear

A partir do ATL 7,0, o `CComAutoThreadModule` é obsoleto: consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

```
LONG Unlock();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnóstico ou teste.

### <a name="remarks"></a>Comentários

Executa um decréscimo atômico na contagem de bloqueios para o módulo e para o thread atual. `CComAutoThreadModule` usa a contagem de bloqueios de módulo para determinar se algum cliente está acessando o módulo. A contagem de bloqueios no thread atual é usada para fins estatísticos.

Quando a contagem de bloqueios de módulo chega a zero, o módulo pode ser descarregado.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
