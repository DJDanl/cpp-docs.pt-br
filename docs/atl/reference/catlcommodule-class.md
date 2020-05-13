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
ms.openlocfilehash: 4b8c98630b27c35ed6a7e32318c6ebad8a82a5c5
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168807"
---
# <a name="catlcommodule-class"></a>Classe CAtlComModule

Essa classe implementa um módulo de servidor COM.

## <a name="syntax"></a>Sintaxe

```cpp
class CAtlComModule : public _ATL_COM_MODULE
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlComModule::CAtlComModule](#catlcommodule)|O construtor.|
|[CAtlComModule:: ~ CAtlComModule](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlComModule::RegisterServer](#registerserver)|Chame esse método para atualizar o registro do sistema para cada objeto no mapa de objetos.|
|[CAtlComModule::RegisterTypeLib](#registertypelib)|Chame esse método para registrar uma biblioteca de tipos.|
|[CAtlComModule::UnregisterServer](#unregisterserver)|Chame esse método para cancelar o registro de cada objeto no mapa de objetos.|
|[CAtlComModule::UnRegisterTypeLib](#unregistertypelib)|Chame esse método para cancelar o registro de uma biblioteca de tipos.|

## <a name="remarks"></a>Comentários

`CAtlComModule`implementa um módulo de servidor COM, permitindo que um cliente acesse os componentes do módulo.

Essa classe substitui a classe [CComModule](../../atl/reference/ccommodule-class.md) obsoleta usada em versões anteriores do ATL. Consulte [classes de módulo do ATL](../../atl/atl-module-classes.md) para obter mais detalhes.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module)

`CAtlComModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="catlcommodulecatlcommodule"></a><a name="catlcommodule"></a>CAtlComModule::CAtlComModule

O construtor.

```cpp
CAtlComModule() throw();
```

### <a name="remarks"></a>Comentários

Inicializa o módulo.

## <a name="catlcommodulecatlcommodule"></a><a name="dtor"></a>CAtlComModule:: ~ CAtlComModule

O destruidor.

```cpp
~CAtlComModule();
```

### <a name="remarks"></a>Comentários

Libera Todas as fábricas de classe.

## <a name="catlcommoduleregisterserver"></a><a name="registerserver"></a>CAtlComModule::RegisterServer

Chame esse método para atualizar o registro do sistema para cada objeto no mapa de objetos.

```cpp
HRESULT RegisterServer(BOOL bRegTypeLib = FALSE, const CLSID* pCLSID = NULL);
```

### <a name="parameters"></a>Parâmetros

*bRegTypeLib*<br/>
TRUE se a biblioteca de tipos for registrada. O valor padrão é FALSE.

*pCLSID*<br/>
Aponta para o CLSID do objeto a ser registrado. Se for NULL (o valor padrão), todos os objetos no mapa de objetos serão registrados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama a função global [AtlComModuleRegisterServer](server-registration-global-functions.md#atlcommoduleregisterserver).

## <a name="catlcommoduleregistertypelib"></a><a name="registertypelib"></a>CAtlComModule::RegisterTypeLib

Chame esse método para registrar uma biblioteca de tipos.

```cpp
HRESULT RegisterTypeLib(LPCTSTR lpszIndex);
HRESULT RegisterTypeLib();
```

### <a name="parameters"></a>Parâmetros

*lpszIndex*<br/>
Cadeia de caracteres no formato\\"\n", em que N é o índice de inteiro do recurso TypeLib.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Adiciona informações sobre uma biblioteca de tipos ao registro do sistema. Se a instância do módulo contiver várias bibliotecas de tipos, use a primeira versão desse método para especificar qual biblioteca de tipos deve ser usada.

## <a name="catlcommoduleunregisterserver"></a><a name="unregisterserver"></a>CAtlComModule::UnregisterServer

Chame esse método para cancelar o registro de cada objeto no mapa de objetos.

```cpp
HRESULT UnregisterServer(
    BOOL bRegTypeLib = FALSE,
    const CLSID* pCLSID = NULL);
```

### <a name="parameters"></a>Parâmetros

*bRegTypeLib*<br/>
TRUE se a biblioteca de tipos tiver que ter o registro cancelado. O valor padrão é FALSE.

*pCLSID*<br/>
Aponta para o CLSID do objeto a ser cancelado. Se NULL (o valor padrão), todos os objetos no mapa de objeto terão o registro cancelado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Chama a função global [AtlComModuleUnregisterServer](server-registration-global-functions.md#atlcommoduleunregisterserver).

## <a name="catlcommoduleunregistertypelib"></a><a name="unregistertypelib"></a>CAtlComModule::UnRegisterTypeLib

Chame esse método para cancelar o registro de uma biblioteca de tipos.

```cpp
HRESULT UnRegisterTypeLib(LPCTSTR lpszIndex);
HRESULT UnRegisterTypeLib();
```

### <a name="parameters"></a>Parâmetros

*lpszIndex*<br/>
Cadeia de caracteres no formato\\"\n", em que N é o índice de inteiro do recurso TypeLib.

### <a name="remarks"></a>Comentários

Remove informações sobre uma biblioteca de tipos do registro do sistema. Se a instância do módulo contiver várias bibliotecas de tipos, use a primeira versão desse método para especificar qual biblioteca de tipos deve ser usada.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="see-also"></a>Confira também

[_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
