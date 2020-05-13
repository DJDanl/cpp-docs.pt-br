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
ms.openlocfilehash: 391354c5672cf15c0286491619a13c6005493cfa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321061"
---
# <a name="ccomautothreadmodule-class"></a>Classe CComAutoThreadModule

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class ThreadAllocator = CComSimpleThreadAllocator>
class CComAutoThreadModule : public CComModule
```

#### <a name="parameters"></a>Parâmetros

*Alocador de thread*<br/>
[em] A classe gerenciando a seleção de segmentos. O valor padrão é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Createinstance](#createinstance)|Seleciona um segmento e, em seguida, cria um objeto no apartamento associado.|
|[GetDefaultThreads](#getdefaultthreads)|(Estática) Calcula dinamicamente o número de threads para o módulo com base no número de processadores.|
|[Init](#init)|Cria os segmentos do módulo.|
|[Bloqueio](#lock)|Incrementa a contagem de bloqueio no módulo e no segmento atual.|
|[Desbloquear](#unlock)|Decréscretes a contagem de bloqueios no módulo e no fio atual.|

### <a name="data-members"></a>Membros de dados

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[Dwthreadid](#dwthreadid)|Contém o identificador do segmento atual.|
|[m_Allocator](#m_allocator)|Gerencia a seleção de segmentos.|
|[m_nThreads](#m_nthreads)|Contém o número de threads no módulo.|
|[m_pApartments](#m_papartments)|Gerencia os apartamentos do módulo.|

## <a name="remarks"></a>Comentários

> [!NOTE]
> Esta classe é obsoleta, tendo sido substituída pelas classes derivadas [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) e [CAtlModule.](../../atl/reference/catlmodule-class.md) As informações a seguir são para uso com versões mais antigas do ATL.

`CComAutoThreadModule`deriva do [CComModule](../../atl/reference/ccommodule-class.md) para implementar um servidor COM com modelo de apartamento com thread para EXEs e serviços windows. `CComAutoThreadModule`usa [CComApartment](../../atl/reference/ccomapartment-class.md) para gerenciar um apartamento para cada segmento no módulo.

Obtenha seu `CComAutoThreadModule` módulo de quando você deseja criar objetos em vários apartamentos. Você também deve incluir a [DECLARE_CLASSFACTORY_AUTO_THREAD](aggregation-and-class-factory-macros.md#declare_classfactory_auto_thread) macro na definição de classe do seu objeto para especificar [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como a fábrica de classes.

Por padrão, o ATL COM AppWizard (o Assistente de Projeto ATL `CComModule`no Visual Studio .NET) derivará seu módulo de . Para `CComAutoThreadModule`usar, modifique a definição de classe. Por exemplo:

[!code-cpp[NVC_ATL_AxHost#2](../../atl/codesnippet/cpp/ccomautothreadmodule-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[Catlmodule](../../atl/reference/catlmodule-class.md)

`IAtlAutoThreadModule`

[Catlmodulet](../../atl/reference/catlmodulet-class.md)

[Catlautothreadmodulet](../../atl/reference/catlautothreadmodulet-class.md)

[Ccommodule](../../atl/reference/ccommodule-class.md)

`CComAutoThreadModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomautothreadmodulecreateinstance"></a><a name="createinstance"></a>CComAutoThreadModule::CreateInstance

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT CreateInstance(
    void* pfnCreateInstance,
    REFIID riid,
    void** ppvObj);
```

### <a name="parameters"></a>Parâmetros

*pfnCreateInstance*<br/>
[em] Um ponteiro para uma função de criador.

*riid*<br/>
[em] O IID da interface solicitada.

*Ppvobj*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não suportar essa interface, *ppvObj* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Seleciona um segmento e, em seguida, cria um objeto no apartamento associado.

## <a name="ccomautothreadmoduledwthreadid"></a><a name="dwthreadid"></a>CComAutoThreadMódulo::dwThreadID

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
DWORD dwThreadID;
```

### <a name="remarks"></a>Comentários

Contém o identificador do segmento atual.

## <a name="ccomautothreadmodulegetdefaultthreads"></a><a name="getdefaultthreads"></a>CComAutoThreadMódulo::GetDefaultThreads

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
static int GetDefaultThreads();
```

### <a name="return-value"></a>Valor retornado

O número de threads a serem criados no módulo EXE.

### <a name="remarks"></a>Comentários

Esta função estática calcula dinamicamente o número máximo de threads para o módulo EXE, com base no número de processadores. Por padrão, esse valor de retorno é passado para o método [Init](#init) para criar os segmentos.

## <a name="ccomautothreadmoduleinit"></a><a name="init"></a>CComAutoThreadModule::Init

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
HRESULT Init(
    _ATL_OBJMAP_ENTRY* p,
    HINSTANCE h,
    const GUID* plibid = NULL,
    int nThreads = GetDefaultThreads());
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
[em] Um ponteiro para uma matriz de entradas de mapa de objetos.

*H*<br/>
[em] O HINSTANCE `DLLMain` passou `WinMain`para ou .

*plibid*<br/>
[em] Um ponteiro para o LIBID da biblioteca do tipo associado ao projeto.

*Nthreads*<br/>
[em] O número de threads a serem criados. Por padrão, *nThreads* é o valor retornado pelo [GetDefaultThreads](#getdefaultthreads).

### <a name="remarks"></a>Comentários

Inicializa os membros de dados e cria o número de threads especificados por *nThreads*.

## <a name="ccomautothreadmodulelock"></a><a name="lock"></a>CComAutoThreadModule::Lock

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
LONG Lock();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos ou testes.

### <a name="remarks"></a>Comentários

Executa um incremento atômico na contagem de bloqueio satisfaz o módulo e para o segmento atual. `CComAutoThreadModule`usa a contagem de bloqueio do módulo para determinar se algum cliente está acessando o módulo. A contagem de bloqueio sustais no segmento atual é usada para fins estatísticos.

## <a name="ccomautothreadmodulem_allocator"></a><a name="m_allocator"></a>CComAutoThreadModule::m_Allocator

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
ThreadAllocator  m_Allocator;
```

### <a name="remarks"></a>Comentários

O objeto que gerencia a seleção de segmentos. Por padrão, `ThreadAllocator` o parâmetro de modelo de classe é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).

## <a name="ccomautothreadmodulem_nthreads"></a><a name="m_nthreads"></a>CComAutoThreadMódulo::m_nThreads

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
int m_nThreads;
```

### <a name="remarks"></a>Comentários

Contém o número de threads no módulo EXE. Quando [o Init](#init) é chamado, `m_nThreads` é definido como o valor do parâmetro *nThreads.* O apartamento associado de cada segmento é gerenciado por um objeto [CComApartment.](../../atl/reference/ccomapartment-class.md)

## <a name="ccomautothreadmodulem_papartments"></a><a name="m_papartments"></a>CComAutoThreadModule::m_pApartments

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
CComApartment* m_pApartments;
```

### <a name="remarks"></a>Comentários

Aponta para uma matriz de objetos [CComApartment,](../../atl/reference/ccomapartment-class.md) cada um dos quais gerencia um apartamento no módulo. O número de elementos na matriz é baseado no [membro m_nThreads.](#m_nthreads)

## <a name="ccomautothreadmoduleunlock"></a><a name="unlock"></a>CComAutoThreadModule::Unlock

A partir do ATL `CComAutoThreadModule` 7.0, é obsoleto: consulte [ATL Module Classes](../../atl/atl-module-classes.md) para obter mais detalhes.

```
LONG Unlock();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos ou testes.

### <a name="remarks"></a>Comentários

Realiza um decrésio atômico na contagem de bloqueio sustais para o módulo e para o fio atual. `CComAutoThreadModule`usa a contagem de bloqueio do módulo para determinar se algum cliente está acessando o módulo. A contagem de bloqueio sustais no segmento atual é usada para fins estatísticos.

Quando a contagem de bloqueio do módulo atinge zero, o módulo pode ser descarregado.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Aulas de módulo](../../atl/atl-module-classes.md)
