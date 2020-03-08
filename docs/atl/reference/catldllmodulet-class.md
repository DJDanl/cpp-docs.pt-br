---
title: Classe CAtlDllModuleT
ms.date: 11/04/2016
f1_keywords:
- CAtlDllModuleT
- ATLBASE/ATL::CAtlDllModuleT
- ATLBASE/ATL::CAtlDllModuleT::CAtlDllModuleT
- ATLBASE/ATL::CAtlDllModuleT::DllCanUnloadNow
- ATLBASE/ATL::CAtlDllModuleT::DllGetClassObject
- ATLBASE/ATL::CAtlDllModuleT::DllMain
- ATLBASE/ATL::CAtlDllModuleT::DllRegisterServer
- ATLBASE/ATL::CAtlDllModuleT::DllUnregisterServer
- ATLBASE/ATL::CAtlDllModuleT::GetClassObject
helpviewer_keywords:
- CAtlDllModuleT class
ms.assetid: 351d5767-8257-4878-94be-45a85e31a72d
ms.openlocfilehash: be42915c6c2e941bc5fc1de78c5c7ac26ccca6e2
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78863142"
---
# <a name="catldllmodulet-class"></a>Classe CAtlDllModuleT

Essa classe representa o módulo para uma DLL.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE CAtlDllModuleT : public CAtlModuleT<T>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe derivada de `CAtlDllModuleT`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CAtlDllModuleT::CAtlDllModuleT](#catldllmodulet)|O construtor.|
|[CAtlDllModuleT:: ~ CAtlDllModuleT](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CAtlDllModuleT::D llCanUnloadNow](#dllcanunloadnow)|Testa se a DLL pode ser descarregada.|
|[CAtlDllModuleT::D llGetClassObject](#dllgetclassobject)|Retorna uma fábrica de classes.|
|[CAtlDllModuleT::D llMain](#dllmain)|O ponto de entrada opcional em uma DLL (biblioteca de vínculo dinâmico).|
|[CAtlDllModuleT::D llRegisterServer](#dllregisterserver)|Adiciona entradas ao registro do sistema para objetos na DLL.|
|[CAtlDllModuleT::D llUnregisterServer](#dllunregisterserver)|Remove entradas no registro do sistema para objetos na DLL.|
|[CAtlDllModuleT:: GetClassObject](#getclassobject)|Retorna uma fábrica de classes. Invocado por [DllGetClassObject](#dllgetclassobject).|

## <a name="remarks"></a>Comentários

`CAtlDllModuleT` representa o módulo para uma DLL (biblioteca de vínculo dinâmico) e fornece funções usadas por todos os projetos de DLL. Essa especialização da classe [CAtlModuleT](../../atl/reference/catlmodulet-class.md) inclui suporte para registro.

Para obter mais informações sobre módulos na ATL, consulte [classes de módulo do ATL](../../atl/atl-module-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[CAtlModule](../../atl/reference/catlmodule-class.md)

[CAtlModuleT](../../atl/reference/catlmodulet-class.md)

`CAtlDllModuleT`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlbase. h

##  <a name="catldllmodulet"></a>CAtlDllModuleT::CAtlDllModuleT

O construtor.

```
CAtlDllModuleT() throw();
```

##  <a name="dtor"></a>CAtlDllModuleT:: ~ CAtlDllModuleT

O destruidor.

```
~CAtlDllModuleT() throw();
```

##  <a name="dllcanunloadnow"></a>CAtlDllModuleT::D llCanUnloadNow

Testa se a DLL pode ser descarregada.

```
HRESULT DllCanUnloadNow() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK se a DLL puder ser descarregada ou S_FALSE se não puder.

##  <a name="dllgetclassobject"></a>CAtlDllModuleT::D llGetClassObject

Retorna a fábrica de classes.

```
HRESULT DllGetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) throw();
```

### <a name="parameters"></a>Parâmetros

*rclsid*<br/>
O CLSID do objeto a ser criado.

*riid*<br/>
O IID da interface solicitada.

*ppv*<br/>
Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não oferecer suporte a essa interface, *PPV* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="dllmain"></a>CAtlDllModuleT::D llMain

O ponto de entrada opcional em uma DLL (biblioteca de vínculo dinâmico).

```
BOOL WINAPI DllMain(DWORD dwReason, LPVOID /* lpReserved*/) throw();
```

### <a name="parameters"></a>Parâmetros

*dwReason*<br/>
Se definido como DLL_PROCESS_ATTACH, as chamadas de notificação de DLL_THREAD_ATTACH e DLL_THREAD_DETACH estão desabilitadas.

*lpReserved*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Desabilitar as chamadas de notificação de DLL_THREAD_ATTACH e DLL_THREAD_DETACH pode ser uma otimização útil para aplicativos multissegmentados que têm muitas DLLs, que frequentemente criam e excluem threads e cujas DLLs não precisam dessas notificações no nível de thread de anexo/desanexação.

##  <a name="dllregisterserver"></a>CAtlDllModuleT::D llRegisterServer

Adiciona entradas ao registro do sistema para objetos na DLL.

```
HRESULT DllRegisterServer(BOOL bRegTypeLib = TRUE) throw();
```

### <a name="parameters"></a>Parâmetros

*bRegTypeLib*<br/>
TRUE se a biblioteca de tipos for registrada. O valor padrão é TRUE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="dllunregisterserver"></a>CAtlDllModuleT::D llUnregisterServer

Remove entradas no registro do sistema para objetos na DLL.

```
HRESULT DllUnregisterServer(BOOL bUnRegTypeLib = TRUE) throw();
```

### <a name="parameters"></a>Parâmetros

*bUnRegTypeLib*<br/>
TRUE se a biblioteca de tipos for removida do registro. O valor padrão é TRUE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

##  <a name="getclassobject"></a>CAtlDllModuleT:: GetClassObject

Cria um objeto do CLSID especificado.

```
HRESULT GetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) throw();
```

### <a name="parameters"></a>Parâmetros

*rclsid*<br/>
O CLSID do objeto a ser criado.

*riid*<br/>
O IID da interface solicitada.

*ppv*<br/>
Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não oferecer suporte a essa interface, *PPV* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método é chamado por [CAtlDllModuleT::D llgetclassobject](#dllgetclassobject) e está incluído para compatibilidade com versões anteriores.

## <a name="see-also"></a>Consulte também

[Classe CAtlModuleT](../../atl/reference/catlmodulet-class.md)<br/>
[Classe CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
