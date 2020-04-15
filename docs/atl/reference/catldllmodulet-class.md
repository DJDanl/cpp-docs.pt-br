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
ms.openlocfilehash: 7a5f8e7e489c8e0d573569ac7c4a8fb63f652732
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319010"
---
# <a name="catldllmodulet-class"></a>Classe CAtlDllModuleT

Esta classe representa o módulo de um DLL.

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

|Nome|Descrição|
|----------|-----------------|
|[CAtlDllModuleT::CAtlDllModuleT](#catldllmodulet)|O construtor.|
|[CAtlDllModuleT::~CAtlDllModuleT](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlDllModuleT::DllCanUnloadNow](#dllcanunloadnow)|Teste se o DLL pode ser descarregado.|
|[CAtlDllModuleT::DllGetClassObject](#dllgetclassobject)|Devolve uma fábrica de classe.|
|[CAtlDllModuleT::DllMain](#dllmain)|O ponto de entrada opcional em uma biblioteca de link dinâmico (DLL).|
|[CAtlDllModuleT::DllRegisterServer](#dllregisterserver)|Adiciona entradas ao registro do sistema para objetos na DLL.|
|[CAtlDllModuleT::DllUnregisterServer](#dllunregisterserver)|Remove entradas no registro do sistema para objetos na DLL.|
|[CAtlDllModuleT::GetClassObject](#getclassobject)|Devolve uma fábrica de classe. Invocado por [DllGetClassObject](#dllgetclassobject).|

## <a name="remarks"></a>Comentários

`CAtlDllModuleT`representa o módulo para uma biblioteca de link dinâmico (DLL) e fornece funções usadas por todos os projetos DeLl. Esta especialização da classe [CAtlModuleT](../../atl/reference/catlmodulet-class.md) inclui suporte para registro.

Para obter mais informações sobre módulos em ATL, consulte [ATL Module Classes](../../atl/atl-module-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[Catlmodule](../../atl/reference/catlmodule-class.md)

[Catlmodulet](../../atl/reference/catlmodulet-class.md)

`CAtlDllModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="catldllmoduletcatldllmodulet"></a><a name="catldllmodulet"></a>CAtlDllModuleT::CAtlDllModuleT

O construtor.

```
CAtlDllModuleT() throw();
```

## <a name="catldllmoduletcatldllmodulet"></a><a name="dtor"></a>CAtlDllModuleT::~CAtlDllModuleT

O destruidor.

```
~CAtlDllModuleT() throw();
```

## <a name="catldllmoduletdllcanunloadnow"></a><a name="dllcanunloadnow"></a>CAtlDllModuleT::DllCanUnloadNow

Teste se o DLL pode ser descarregado.

```
HRESULT DllCanUnloadNow() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK se o DLL puder ser descarregado ou S_FALSE se não puder.

## <a name="catldllmoduletdllgetclassobject"></a><a name="dllgetclassobject"></a>CAtlDllModuleT::DllGetClassObject

Devolve a fábrica de classe.

```
HRESULT DllGetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) throw();
```

### <a name="parameters"></a>Parâmetros

*Rclsid*<br/>
O CLSID do objeto a ser criado.

*riid*<br/>
O IID da interface solicitada.

*Ppv*<br/>
Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não suportar essa interface, *o ppv* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catldllmoduletdllmain"></a><a name="dllmain"></a>CAtlDllModuleT::DllMain

O ponto de entrada opcional em uma biblioteca de link dinâmico (DLL).

```
BOOL WINAPI DllMain(DWORD dwReason, LPVOID /* lpReserved*/) throw();
```

### <a name="parameters"></a>Parâmetros

*Dwreason*<br/>
Se definido como DLL_PROCESS_ATTACH, as chamadas de notificação de DLL_THREAD_ATTACH e DLL_THREAD_DETACH serão desativadas.

*lpReservado*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Desativar as chamadas de notificação DLL_THREAD_ATTACH e DLL_THREAD_DETACH pode ser uma otimização útil para aplicativos multithreaded que possuem muitos DLLs, que frequentemente criam e excluem threads, e cujos DLLs não precisam dessas notificações em nível de segmento de anexo/desprendimento.

## <a name="catldllmoduletdllregisterserver"></a><a name="dllregisterserver"></a>CAtlDllModuleT::DllRegisterServer

Adiciona entradas ao registro do sistema para objetos na DLL.

```
HRESULT DllRegisterServer(BOOL bRegTypeLib = TRUE) throw();
```

### <a name="parameters"></a>Parâmetros

*bRegtypelib*<br/>
TRUE se a biblioteca do tipo for registrada. O valor padrão é TRUE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catldllmoduletdllunregisterserver"></a><a name="dllunregisterserver"></a>CAtlDllModuleT::DllUnregisterServer

Remove entradas no registro do sistema para objetos na DLL.

```
HRESULT DllUnregisterServer(BOOL bUnRegTypeLib = TRUE) throw();
```

### <a name="parameters"></a>Parâmetros

*bunRegtypelib*<br/>
TRUE se a biblioteca do tipo for removida do registro. O valor padrão é TRUE.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catldllmoduletgetclassobject"></a><a name="getclassobject"></a>CAtlDllModuleT::GetClassObject

Cria um objeto do CLSID especificado.

```
HRESULT GetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) throw();
```

### <a name="parameters"></a>Parâmetros

*Rclsid*<br/>
O CLSID do objeto a ser criado.

*riid*<br/>
O IID da interface solicitada.

*Ppv*<br/>
Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não suportar essa interface, *o ppv* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Este método é chamado por [CAtlDllModuleT::DllGetClassObject](#dllgetclassobject) e está incluído para compatibilidade retrógrada.

## <a name="see-also"></a>Confira também

[Classe CAtlModuleT](../../atl/reference/catlmodulet-class.md)<br/>
[Classe CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Aulas de módulo](../../atl/atl-module-classes.md)
