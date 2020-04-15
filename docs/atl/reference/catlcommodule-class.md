---
title: Classe CAtlComModule
ms.date: 11/04/2016
f1_keywords:
- CAtlComModule
- ATLBASE/ATL::CAtlComModule
- ATLBASE/ATL::CAtlComModule::CAtlComModule
- ATLBASE/ATL::CAtlComModule::RegisterServer
- ATLBASE/ATL::CAtlComModule::RegisterTypeLib
- ATLBASE/ATL::CAtlComModule::UnregisterServer
- ATLBASE/ATL::CAtlComModule::UnRegisterTypeLib
helpviewer_keywords:
- CAtlComModule class
ms.assetid: af5dd71a-a0d1-4a2e-9a24-154a03381c75
ms.openlocfilehash: 68fdb48edc9304d9d74df6f36bd208cfd35ff307
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321480"
---
# <a name="catlcommodule-class"></a>Classe CAtlComModule

Esta classe implementa um módulo de servidor COM.

## <a name="syntax"></a>Sintaxe

```
class CAtlComModule : public _ATL_COM_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlComModule::CAtlComModule](#catlcommodule)|O construtor.|
|[CAtlComModule::~CAtlComModule](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlComModule::RegisterServer](#registerserver)|Chame este método para atualizar o registro do sistema para cada objeto no mapa do objeto.|
|[CAtlComModule::RegisterTypeLib](#registertypelib)|Chame este método para registrar uma biblioteca de tipos.|
|[CAtlComModule::UnregisterServer](#unregisterserver)|Chame este método para desregistrar cada objeto no mapa do objeto.|
|[CAtlComModule::UnRegisterTypeLib](#unregistertypelib)|Chame este método para cancelar o registro de uma biblioteca de tipos.|

## <a name="remarks"></a>Comentários

`CAtlComModule`implementa um módulo de servidor COM, permitindo que um cliente acesse os componentes do módulo.

Esta classe substitui a obsoleta classe [CComModule](../../atl/reference/ccommodule-class.md) usada em versões anteriores do ATL. Consulte [atl module classes](../../atl/atl-module-classes.md) para obter mais detalhes.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module)

`CAtlComModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="catlcommodulecatlcommodule"></a><a name="catlcommodule"></a>CAtlComModule::CAtlComModule

O construtor.

```
CAtlComModule() throw();
```

### <a name="remarks"></a>Comentários

Inicializa o módulo.

## <a name="catlcommodulecatlcommodule"></a><a name="dtor"></a>CAtlComModule::~CAtlComModule

O destruidor.

```
~CAtlComModule();
```

### <a name="remarks"></a>Comentários

Liberta todas as fábricas de classe.

## <a name="catlcommoduleregisterserver"></a><a name="registerserver"></a>CAtlComModule::RegisterServer

Chame este método para atualizar o registro do sistema para cada objeto no mapa do objeto.

```
HRESULT RegisterServer(BOOL bRegTypeLib = FALSE, const CLSID* pCLSID = NULL);
```

### <a name="parameters"></a>Parâmetros

*bRegtypelib*<br/>
TRUE se a biblioteca do tipo for registrada. O valor padrão é FALSE.

*Pclsid*<br/>
Aponta para o CLSID do objeto a ser registrado. Se NULL (o valor padrão), todos os objetos no mapa do objeto serão registrados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chama a função global [AtlComModuleRegisterServer](server-registration-global-functions.md#atlcommoduleregisterserver).

## <a name="catlcommoduleregistertypelib"></a><a name="registertypelib"></a>CAtlComModule::RegisterTypeLib

Chame este método para registrar uma biblioteca de tipos.

```
HRESULT RegisterTypeLib(LPCTSTR lpszIndex);
HRESULT RegisterTypeLib();
```

### <a name="parameters"></a>Parâmetros

*lpszIndex*<br/>
String no formato\\"\N", onde N é o índice inteiro do recurso TYPELIB.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Adiciona informações sobre uma biblioteca de tipo ao registro do sistema. Se a instância do módulo contiver várias bibliotecas de tipo, use a primeira versão deste método para especificar qual biblioteca de tipo deve ser usada.

## <a name="catlcommoduleunregisterserver"></a><a name="unregisterserver"></a>CAtlComModule::UnregisterServer

Chame este método para desregistrar cada objeto no mapa do objeto.

```
HRESULT UnregisterServer(
    BOOL bRegTypeLib = FALSE,
    const CLSID* pCLSID = NULL);
```

### <a name="parameters"></a>Parâmetros

*bRegtypelib*<br/>
TRUE se a biblioteca do tipo não for registrada. O valor padrão é FALSE.

*Pclsid*<br/>
Aponta para o CLSID do objeto não registrado. Se NULL (o valor padrão), todos os objetos no mapa do objeto não serão registrados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Chama a função global [AtlComModuleUnregisterServer](server-registration-global-functions.md#atlcommoduleunregisterserver).

## <a name="catlcommoduleunregistertypelib"></a><a name="unregistertypelib"></a>CAtlComModule::UnRegisterTypeLib

Chame este método para cancelar o registro de uma biblioteca de tipos.

```
HRESULT UnRegisterTypeLib(LPCTSTR lpszIndex);
HRESULT UnRegisterTypeLib();
```

### <a name="parameters"></a>Parâmetros

*lpszIndex*<br/>
String no formato\\"\N", onde N é o índice inteiro do recurso TYPELIB.

### <a name="remarks"></a>Comentários

Remove informações sobre uma biblioteca de tipo do registro do sistema. Se a instância do módulo contiver várias bibliotecas de tipo, use a primeira versão deste método para especificar qual biblioteca de tipo deve ser usada.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="see-also"></a>Confira também

[_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
