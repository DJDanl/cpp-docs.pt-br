---
title: Classe CComAutoThreadModule | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CComAutoThreadModule class
- apartment model modules
ms.assetid: 13063ea5-a57e-4aac-97d3-227137262811
caps.latest.revision: 21
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 07aaf6dc7029452fa6822c5f5f1ae09b724ddc8b
ms.lasthandoff: 02/25/2017

---
# <a name="ccomautothreadmodule-class"></a>Classe CComAutoThreadModule
A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class ThreadAllocator = CComSimpleThreadAllocator>  
class CComAutoThreadModule : public CComModule
```  
  
#### <a name="parameters"></a>Parâmetros  
 `ThreadAllocator`  
 [in] A classe de gerenciamento de seleção de thread. O valor padrão é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CreateInstance](#createinstance)|Seleciona um thread e, em seguida, cria um objeto no apartment associado.|  
|[GetDefaultThreads](#getdefaultthreads)|(Estático) Calcula dinamicamente o número de threads para o módulo com base no número de processadores.|  
|[Init](#init)|Cria threads do módulo.|  
|[Bloqueio](#lock)|Incrementa a contagem de bloqueio no módulo e no thread atual.|  
|[Desbloquear](#unlock)|Decrementa o bloqueio de contagem no módulo e no thread atual.|  
  
### <a name="data-members"></a>Membros de Dados  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[dwThreadID](#dwthreadid)|Contém o identificador do thread atual.|  
|[m_Allocator](#m_allocator)|Gerencia a seleção de thread.|  
|[m_nThreads](#m_nthreads)|Contém o número de threads no módulo.|  
|[m_pApartments](#m_papartments)|Gerencia apartments do módulo.|  
  
## <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Essa classe é obsoleto, tendo sido substituído pela [CAtlAutoThreadModule](../../atl/reference/catlautothreadmodule-class.md) e [CAtlModule](../../atl/reference/catlmodule-class.md) classes derivadas. As informações a seguir são para uso com versões mais antigas da ATL.  
  
 `CComAutoThreadModule`deriva de [CComModule](../../atl/reference/ccommodule-class.md) para implementar um servidor de pool de thread, o modelo de apartment COM para serviços EXEs e do Windows. `CComAutoThreadModule`usa [CComApartment](../../atl/reference/ccomapartment-class.md) para gerenciar um apartamento para cada thread no módulo.  
  
 Derivar o módulo de `CComAutoThreadModule` quando você deseja criar objetos em vários apartments. Você também deve incluir o [DECLARE_CLASSFACTORY_AUTO_THREAD](http://msdn.microsoft.com/library/19d7105e-03e8-4412-9f5e-5384c8a5e18f) macro na definição de classe do objeto para especificar [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) como a fábrica de classes.  
  
 Por padrão, o AppWizard de COM ATL (ATL Project Wizard no Visual Studio .NET) obterão o módulo de `CComModule`. Para usar `CComAutoThreadModule`, modifique a definição de classe. Por exemplo:  
  
 [!code-cpp[NVC_ATL_AxHost n º&2;](../../atl/codesnippet/cpp/ccomautothreadmodule-class_1.cpp)]  
  
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
  
##  <a name="createinstance"></a>CComAutoThreadModule::CreateInstance  
 A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HRESULT CreateInstance(
    void* pfnCreateInstance,
    REFIID riid,
    void** ppvObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pfnCreateInstance*  
 [in] Um ponteiro para uma função do criador.  
  
 `riid`  
 [in] O IID da interface solicitada.  
  
 `ppvObj`  
 [out] Um ponteiro para o ponteiro de interface identificado pelo `riid`. Se o objeto não oferece suporte a essa interface, `ppvObj` é definido como NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 Seleciona um thread e, em seguida, cria um objeto no apartment associado.  
  
##  <a name="dwthreadid"></a>CComAutoThreadModule::dwThreadID  
 A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
DWORD dwThreadID;
```  
  
### <a name="remarks"></a>Comentários  
 Contém o identificador do thread atual.  
  
##  <a name="getdefaultthreads"></a>CComAutoThreadModule::GetDefaultThreads  
 A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
static int GetDefaultThreads();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de threads a ser criado no módulo EXE.  
  
### <a name="remarks"></a>Comentários  
 A função estática calcula dinamicamente o número máximo de threads para o módulo EXE, com base no número de processadores. Por padrão, esse valor de retorno é passado para o [Init](#init) método para criar os threads.  
  
##  <a name="init"></a>CComAutoThreadModule::Init  
 A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
HRESULT Init(
    _ATL_OBJMAP_ENTRY* p,
    HINSTANCE h,
    const GUID* plibid = NULL,
    int nThreads = GetDefaultThreads());
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 [in] Um ponteiro para uma matriz de entradas de mapa do objeto.  
  
 `h`  
 [in] O `HINSTANCE` passado para **DLLMain** ou `WinMain`.  
  
 `plibid`  
 [in] Um ponteiro para a ID da biblioteca da biblioteca de tipos associada ao projeto.  
  
 `nThreads`  
 [in] O número de threads a ser criado. Por padrão, `nThreads` é o valor retornado por [GetDefaultThreads](#getdefaultthreads).  
  
### <a name="remarks"></a>Comentários  
 Inicializa membros de dados e cria o número de threads especificado por `nThreads`.  
  
##  <a name="lock"></a>CComAutoThreadModule::Lock  
 A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
LONG Lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para o diagnóstico ou teste.  
  
### <a name="remarks"></a>Comentários  
 Executa um incremento atômico na contagem de bloqueio para o módulo de e para o thread atual. `CComAutoThreadModule`usa a contagem de bloqueio de módulo para determinar se todos os clientes acessam o módulo. A contagem de bloqueio no thread atual é usada para fins estatísticos.  
  
##  <a name="m_allocator"></a>CComAutoThreadModule::m_Allocator  
 A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
ThreadAllocator  m_Allocator;
```     
  
### <a name="remarks"></a>Comentários  
 O objeto de gerenciamento de seleção de thread. Por padrão, o `ThreadAllocator` parâmetro do modelo de classe é [CComSimpleThreadAllocator](../../atl/reference/ccomsimplethreadallocator-class.md).  
  
##  <a name="m_nthreads"></a>CComAutoThreadModule::m_nThreads  
 A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
int m_nThreads;
```  
  
### <a name="remarks"></a>Comentários  
 Contém o número de threads no módulo EXE. Quando [Init](#init) é chamado, `m_nThreads` é definido como o `nThreads` o valor do parâmetro. Apartment associado de cada thread é gerenciado por um [CComApartment](../../atl/reference/ccomapartment-class.md) objeto.  
  
##  <a name="m_papartments"></a>CComAutoThreadModule::m_pApartments  
 A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
CComApartment* m_pApartments;
```  
  
### <a name="remarks"></a>Comentários  
 Aponta para uma matriz de [CComApartment](../../atl/reference/ccomapartment-class.md) objetos, cada um deles gerencia um apartamento no módulo. O número de elementos na matriz se baseia o [m_nThreads](#m_nthreads) membro.  
  
##  <a name="unlock"></a>CComAutoThreadModule::Unlock  
 A partir do ATL 7.0, `CComAutoThreadModule` é obsoleto: consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
```
LONG Unlock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para o diagnóstico ou teste.  
  
### <a name="remarks"></a>Comentários  
 Executa um decréscimo atômico na contagem de bloqueio para o módulo de e para o thread atual. `CComAutoThreadModule`usa a contagem de bloqueio de módulo para determinar se todos os clientes acessam o módulo. A contagem de bloqueio no thread atual é usada para fins estatísticos.  
  
 Quando a contagem de bloqueios do módulo chega a zero, o módulo pode ser descarregado.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)

