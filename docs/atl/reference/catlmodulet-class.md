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
ms.openlocfilehash: bf64c073249b7426fafb430a708573d9d06d11fd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321421"
---
# <a name="catlmodulet-class"></a>Classe CAtlModuleT

Esta classe implementa um módulo ATL.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class ATL_NO_VTABLE CAtlModuleT : public CAtlModule
```

#### <a name="parameters"></a>Parâmetros

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
|[CAtlModuleT::InitLibId](#initlibid)|Inicializa o membro de dados contendo o GUID do módulo atual.|
|[CAtlModuleT::RegisterAppId](#registerappid)|Adiciona o EXE ao registro.|
|[CAtlModuleT::RegisterServer](#registerserver)|Adiciona o serviço ao registro.|
|[CAtlModuleT::UnregisterAppId](#unregisterappid)|Remove o EXE do registro.|
|[CAtlModuleT::UnregisterServer](#unregisterserver)|Remove o serviço do registro.|
|[CAtlModuleT::AtualizaçãoRegistryAppId](#updateregistryappid)|Atualiza as informações exe no registro.|

## <a name="remarks"></a>Comentários

`CAtlModuleT`, derivado do [CAtlModule,](../../atl/reference/catlmodule-class.md)implementa um módulo ATL executável (EXE) ou um Serviço (EXE). Um módulo executável é um servidor local, fora de processo, enquanto um módulo de serviço é um aplicativo do Windows que é executado em segundo plano quando o Windows é iniciado.

`CAtlModuleT`fornece suporte para inicialização, registro e não registro do módulo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[Catlmodule](../../atl/reference/catlmodule-class.md)

`CAtlModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="catlmoduletcatlmodulet"></a><a name="catlmodulet"></a>CAtlModuleT::CAtlModuleT

O construtor.

```
CAtlModuleT() throw();
```

### <a name="remarks"></a>Comentários

Chama [CAtlModuleT::InitLibId](#initlibid).

## <a name="catlmoduletinitlibid"></a><a name="initlibid"></a>CAtlModuleT::InitLibId

Inicializa o membro de dados contendo o GUID do módulo atual.

```
static void InitLibId() throw();
```

### <a name="remarks"></a>Comentários

Chamado pelo construtor [CAtlModuleT::CAtlModuleT](#catlmodulet).

## <a name="catlmoduletregisterappid"></a><a name="registerappid"></a>CAtlModuleT::RegisterAppId

Adiciona o EXE ao registro.

```
HRESULT RegisterAppId() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catlmoduletregisterserver"></a><a name="registerserver"></a>CAtlModuleT::RegisterServer

Adiciona o serviço ao registro.

```
HRESULT RegisterServer(
    BOOL bRegTypeLib = FALSE,
    const CLSID* pCLSID = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*bRegtypelib*<br/>
TRUE se a biblioteca do tipo for registrada. O valor padrão é FALSE.

*Pclsid*<br/>
Aponta para o CLSID do objeto a ser registrado. Se NULL (o valor padrão), todos os objetos no mapa do objeto serão registrados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catlmoduletunregisterappid"></a><a name="unregisterappid"></a>CAtlModuleT::UnregisterAppId

Remove o EXE do registro.

```
HRESULT UnregisterAppId() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catlmoduletunregisterserver"></a><a name="unregisterserver"></a>CAtlModuleT::UnregisterServer

Remove o serviço do registro.

```
HRESULT UnregisterServer(
    BOOL bUnRegTypeLib,
    const CLSID* pCLSID = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*bunRegtypelib*<br/>
TRUE se a biblioteca do tipo também não for registrada.

*Pclsid*<br/>
Aponta para o CLSID do objeto não registrado. Se NULL (o valor padrão), todos os objetos no mapa do objeto não serão registrados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="catlmoduletupdateregistryappid"></a><a name="updateregistryappid"></a>CAtlModuleT::AtualizaçãoRegistryAppId

Atualiza as informações exe no registro.

```
static HRESULT WINAPI UpdateRegistryAppId(BOOL /* bRegister*/) throw();
```

### <a name="parameters"></a>Parâmetros

*Bregister*<br/>
Reservado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="see-also"></a>Confira também

[Classe CAtlModule](../../atl/reference/catlmodule-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Aulas de módulo](../../atl/atl-module-classes.md)
