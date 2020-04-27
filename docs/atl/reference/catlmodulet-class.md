---
title: Classe CAtlModuleT
ms.date: 11/04/2016
f1_keywords:
- CAtlModuleT
- ATLBASE/ATL::CAtlModuleT
- ATLBASE/ATL::CAtlModuleT::CAtlModuleT
- ATLBASE/ATL::CAtlModuleT::InitLibId
- ATLBASE/ATL::CAtlModuleT::RegisterAppId
- ATLBASE/ATL::CAtlModuleT::RegisterServer
- ATLBASE/ATL::CAtlModuleT::UnregisterAppId
- ATLBASE/ATL::CAtlModuleT::UnregisterServer
- ATLBASE/ATL::CAtlModuleT::UpdateRegistryAppId
helpviewer_keywords:
- CAtlModuleT class
ms.assetid: 9b74d02f-9117-47b1-a05e-c5945f83dd2b
ms.openlocfilehash: b07e60265570e66337a2d13007e9ad57c6f369e4
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82167853"
---
# <a name="catlmodulet-class"></a>Classe CAtlModuleT

Essa classe implementa um módulo ATL.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class ATL_NO_VTABLE CAtlModuleT : public CAtlModule
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe derivada de `CAtlModuleT`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlModuleT::CAtlModuleT](#catlmodulet)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlModuleT::InitLibId](#initlibid)|Inicializa o membro de dados que contém o GUID do módulo atual.|
|[CAtlModuleT::RegisterAppId](#registerappid)|Adiciona o EXE ao registro.|
|[CAtlModuleT::RegisterServer](#registerserver)|Adiciona o serviço ao registro.|
|[CAtlModuleT::UnregisterAppId](#unregisterappid)|Remove o EXE do registro.|
|[CAtlModuleT::UnregisterServer](#unregisterserver)|Remove o serviço do registro.|
|[CAtlModuleT::UpdateRegistryAppId](#updateregistryappid)|Atualiza as informações de EXE no registro.|

## <a name="remarks"></a>Comentários

`CAtlModuleT`, derivado de [CAtlModule](../../atl/reference/catlmodule-class.md), implementa um módulo ATL executável (exe) ou um serviço (exe). Um módulo executável é um servidor local e fora do processo, enquanto um módulo de serviço é um aplicativo do Windows que é executado em segundo plano quando o Windows é iniciado.

`CAtlModuleT`fornece suporte para inicializar, registrar e cancelar o registro do módulo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[CAtlModule](../../atl/reference/catlmodule-class.md)

`CAtlModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="catlmoduletcatlmodulet"></a><a name="catlmodulet"></a>CAtlModuleT::CAtlModuleT

O construtor.

```cpp
CAtlModuleT() throw();
```

### <a name="remarks"></a>Comentários

Chama [CAtlModuleT:: InitLibId](#initlibid).

## <a name="catlmoduletinitlibid"></a><a name="initlibid"></a>CAtlModuleT::InitLibId

Inicializa o membro de dados que contém o GUID do módulo atual.

```cpp
static void InitLibId() throw();
```

### <a name="remarks"></a>Comentários

Chamado pelo construtor [CAtlModuleT:: CAtlModuleT](#catlmodulet).

## <a name="catlmoduletregisterappid"></a><a name="registerappid"></a>CAtlModuleT::RegisterAppId

Adiciona o EXE ao registro.

```cpp
HRESULT RegisterAppId() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="catlmoduletregisterserver"></a><a name="registerserver"></a>CAtlModuleT::RegisterServer

Adiciona o serviço ao registro.

```cpp
HRESULT RegisterServer(
    BOOL bRegTypeLib = FALSE,
    const CLSID* pCLSID = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*bRegTypeLib*<br/>
TRUE se a biblioteca de tipos for registrada. O valor padrão é FALSE.

*pCLSID*<br/>
Aponta para o CLSID do objeto a ser registrado. Se for NULL (o valor padrão), todos os objetos no mapa de objetos serão registrados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="catlmoduletunregisterappid"></a><a name="unregisterappid"></a>CAtlModuleT::UnregisterAppId

Remove o EXE do registro.

```cpp
HRESULT UnregisterAppId() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="catlmoduletunregisterserver"></a><a name="unregisterserver"></a>CAtlModuleT::UnregisterServer

Remove o serviço do registro.

```cpp
HRESULT UnregisterServer(
    BOOL bUnRegTypeLib,
    const CLSID* pCLSID = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*bUnRegTypeLib*<br/>
TRUE se a biblioteca de tipos também tiver seu registro cancelado.

*pCLSID*<br/>
Aponta para o CLSID do objeto a ser cancelado. Se NULL (o valor padrão), todos os objetos no mapa de objeto terão o registro cancelado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="catlmoduletupdateregistryappid"></a><a name="updateregistryappid"></a>CAtlModuleT::UpdateRegistryAppId

Atualiza as informações de EXE no registro.

```cpp
static HRESULT WINAPI UpdateRegistryAppId(BOOL /* bRegister*/) throw();
```

### <a name="parameters"></a>Parâmetros

*bRegister*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="see-also"></a>Confira também

[Classe CAtlModule](../../atl/reference/catlmodule-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
