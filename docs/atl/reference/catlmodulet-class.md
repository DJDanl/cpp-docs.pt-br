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
ms.openlocfilehash: 2cd207038a92b944bf95575f0e0c820b8f09d615
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62260143"
---
# <a name="catlmodulet-class"></a>Classe CAtlModuleT

Essa classe implementa um módulo do ATL.

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
|[CAtlModuleT::InitLibId](#initlibid)|Inicializa o membro de dados que contém o GUID do módulo atual.|
|[CAtlModuleT::RegisterAppId](#registerappid)|Adiciona o arquivo EXE ao registro.|
|[CAtlModuleT::RegisterServer](#registerserver)|Adiciona o serviço no registro.|
|[CAtlModuleT::UnregisterAppId](#unregisterappid)|Remove o arquivo EXE do registro.|
|[CAtlModuleT::UnregisterServer](#unregisterserver)|Remove o serviço do registro.|
|[CAtlModuleT::UpdateRegistryAppId](#updateregistryappid)|Atualiza as informações de EXE no registro.|

## <a name="remarks"></a>Comentários

`CAtlModuleT`, derivada de [CAtlModule](../../atl/reference/catlmodule-class.md), implementa um executável (EXE) ou um módulo de serviço (EXE) ATL. Um módulo executável é um servidor local, out-of-process, enquanto um módulo de serviço é um aplicativo do Windows que é executado em segundo plano quando o Windows é iniciado.

`CAtlModuleT` fornece suporte para inicializar, registrar e cancelar o registro do módulo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_MODULE](atl-typedefs.md#_atl_module)

[CAtlModule](../../atl/reference/catlmodule-class.md)

`CAtlModuleT`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="catlmodulet"></a>  CAtlModuleT::CAtlModuleT

O construtor.

```
CAtlModuleT() throw();
```

### <a name="remarks"></a>Comentários

Chamadas [CAtlModuleT::InitLibId](#initlibid).

##  <a name="initlibid"></a>  CAtlModuleT::InitLibId

Inicializa o membro de dados que contém o GUID do módulo atual.

```
static void InitLibId() throw();
```

### <a name="remarks"></a>Comentários

Chamado pelo construtor [CAtlModuleT::CAtlModuleT](#catlmodulet).

##  <a name="registerappid"></a>  CAtlModuleT::RegisterAppId

Adiciona o arquivo EXE ao registro.

```
HRESULT RegisterAppId() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="registerserver"></a>  CAtlModuleT::RegisterServer

Adiciona o serviço no registro.

```
HRESULT RegisterServer(
    BOOL bRegTypeLib = FALSE,
    const CLSID* pCLSID = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*bRegTypeLib*<br/>
TRUE se a biblioteca de tipos deve ser registrado. O valor padrão é FALSE.

*pCLSID*<br/>
Aponta para o CLSID do objeto a ser registrado. Se NULL (o valor padrão), todos os objetos no mapa de objetos será registrado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="unregisterappid"></a>  CAtlModuleT::UnregisterAppId

Remove o arquivo EXE do registro.

```
HRESULT UnregisterAppId() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="unregisterserver"></a>  CAtlModuleT::UnregisterServer

Remove o serviço do registro.

```
HRESULT UnregisterServer(
    BOOL bUnRegTypeLib,
    const CLSID* pCLSID = NULL) throw();
```

### <a name="parameters"></a>Parâmetros

*bUnRegTypeLib*<br/>
TRUE se a biblioteca de tipos também é possível cancelar o registro.

*pCLSID*<br/>
Aponta para o CLSID do objeto a ser cancelado. Se NULL (o valor padrão), todos os objetos no mapa de objetos será cancelado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

##  <a name="updateregistryappid"></a>  CAtlModuleT::UpdateRegistryAppId

Atualiza as informações de EXE no registro.

```
static HRESULT WINAPI UpdateRegistryAppId(BOOL /* bRegister*/) throw();
```

### <a name="parameters"></a>Parâmetros

*bRegister*<br/>
Reservado.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

## <a name="see-also"></a>Consulte também

[Classe CAtlModule](../../atl/reference/catlmodule-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classes de módulo](../../atl/atl-module-classes.md)
