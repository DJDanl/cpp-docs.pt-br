---
title: Funções globais de registro de servidor
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlComModuleRegisterServer
- atlbase/ATL::AtlComModuleUnregisterServer
- atlbase/ATL::AtlComModuleRegisterClassObjects
- atlbase/ATL::AtlComModuleRevokeClassObjects
- atlbase/ATL::AtlComModuleGetClassObject
ms.assetid: c2f0a35d-857c-4538-a44d-c4ea0db63b06
ms.openlocfilehash: fb6353b52f487d0511c54223fe9e31dab88704b2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325926"
---
# <a name="server-registration-global-functions"></a>Funções globais de registro de servidor

Essas funções fornecem suporte para registrar e cancelar o registro de objetos do servidor no mapa do objeto.

> [!IMPORTANT]
> As funções listadas na tabela a seguir não podem ser usadas em aplicativos executados no Tempo de execução do Windows.

|||
|-|-|
|[AtlComModuleRegisterServer](#atlcommoduleregisterserver)|Essa função é chamada para registrar cada objeto no mapa de objetos.|
|[AtlComModuleUnregisterServer](#atlcommoduleunregisterserver)|Essa função é chamada para cancelar o registro de cada objeto no mapa de objetos.|
|[AtlComModuleRegisterClassObjects](#atlcommoduleregisterclassobjects)|Essa função é chamada para registrar objetos da classe.|
|[AtlComModuleRevokeClassObjects](#atlcommodulerevokeclassobjects)|Esta função é chamada para revogar objetos de classe de um módulo COM.|
|[AtlComModuleGetClassObject](#atlcommodulegetclassobject)|Esta função é chamada para obter o objeto de classe.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="atlcommoduleregisterserver"></a><a name="atlcommoduleregisterserver"></a>AtlComModuleRegisterServer

Essa função é chamada para registrar cada objeto no mapa de objetos.

```
ATLINLINE ATLAPI AtlComModuleRegisterServer(
    _ATL_COM_MODULE* pComModule,
    BOOL bRegTypeLib,
    const CLSID* pCLSID);
```

### <a name="parameters"></a>Parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

*bRegtypelib*<br/>
TRUE se a biblioteca do tipo for registrada.

*Pclsid*<br/>
Aponta para o CLSID do objeto a ser registrado. Se NULA, todos os objetos no mapa do objeto serão registrados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

`AtlComModuleRegisterServer`caminha pelo mapa de objetos gerado sél e registra cada objeto no mapa. Se *o pCLSID* não for NULO, então apenas o objeto referido pelo *pCLSID* será registrado; caso contrário, todos os objetos estão registrados.

Esta função é chamada por [CAtlComModule::RegisterServer](catlcommodule-class.md#registerserver).

## <a name="atlcommoduleunregisterserver"></a><a name="atlcommoduleunregisterserver"></a>Atlcommoduleunregisterserver

Essa função é chamada para cancelar o registro de cada objeto no mapa de objetos.

```
ATLINLINE ATLAPI AtlComModuleUnregisterServer(
    _ATL_COM_MODULE* pComModule,
    BOOL bUnRegTypeLib,
    const CLSID* pCLSID);
```

### <a name="parameters"></a>Parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

*bunRegtypelib*<br/>
TRUE se a biblioteca do tipo for registrada.

*Pclsid*<br/>
Aponta para o CLSID do objeto não registrado. Se NULL todos os objetos no mapa do objeto não serão registrados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

`AtlComModuleUnregisterServer`caminha pelo mapa do objeto ATL e desregistra cada objeto no mapa. Se *o pCLSID* não for NULO, então apenas o objeto referido pelo *pCLSID* não será registrado; caso contrário, todos os objetos não estão registrados.

Esta função é chamada por [CAtlComModule::UnregisterServer](catlcommodule-class.md#unregisterserver).

## <a name="atlcommoduleregisterclassobjects"></a><a name="atlcommoduleregisterclassobjects"></a>AtlComModuleRegisterClassObjects

Essa função é chamada para registrar objetos da classe.

```
ATLINLINE ATLAPI AtlComModuleRegisterClassObjects(
    _ATL_COM_MODULE* pComModule,
    DWORD dwClsContext,
    DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

*Dwclscontext*<br/>
Especifica o contexto em que o objeto de classe deve ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER. Consulte [CLSCTX](/windows/win32/api/wtypesbase/ne-wtypesbase-clsctx) para obter mais detalhes.

*dwFlags*<br/>
Determina os tipos de conexão com o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE. Consulte [REGCLS](/windows/win32/api/combaseapi/ne-combaseapi-regcls) para obter mais detalhes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Esta função auxiliar é utilizada pelo [CComModule::RegisterClassObjects](ccommodule-class.md#registerclassobjects) (obsoleto no ATL 7.0) e [cAtlExeModuleT::RegisterClassObjects](catlexemodulet-class.md#registerclassobjects).

## <a name="atlcommodulerevokeclassobjects"></a><a name="atlcommodulerevokeclassobjects"></a>AtlComModuleRevokeClassObjects

Essa função é chamada para remover a fábrica/as fábricas da classe da Tabela de Objetos em Execução.

```
ATLINLINE ATLAPI AtlComModuleRevokeClassObjects(_ATL_COM_MODULE* pComModule);
```

### <a name="parameters"></a>Parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Esta função de ajudante é utilizada por [CComModule::RevokeClassObjects](ccommodule-class.md#revokeclassobjects) (obsoleto no ATL 7.0) e [CAtlExeModuleT::RevokeClassObjects](catlexemodulet-class.md#revokeclassobjects).

## <a name="atlcommodulegetclassobject"></a><a name="atlcommodulegetclassobject"></a>AtlComModuleGetClassObject

Essa função é chamada para retornar a fábrica da classe.

```
ATLINLINE ATLAPI AtlComModuleGetClassObject(
    _ATL_COM_MODULE* pComModule,
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv);
```

### <a name="parameters"></a>Parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

*Rclsid*<br/>
O CLSID do objeto a ser criado.

*riid*<br/>
O IID da interface solicitada.

*Ppv*<br/>
Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não suportar essa interface, *o ppv* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Esta função auxiliar é utilizada por [CComModule::GetClassObject](ccommodule-class.md#getclassobject) (obsoleto no ATL 7.0) e [CAtlDllModuleT::GetClassObject](catldllmodulet-class.md#getclassobject).

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
