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
ms.openlocfilehash: f9c3697259e1cee2b1107ded785ca583d730b55e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78863146"
---
# <a name="server-registration-global-functions"></a>Funções globais de registro de servidor

Essas funções fornecem suporte para registrar e cancelar o registro de objetos de servidor no mapa de objetos.

> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados no Windows Runtime.

|||
|-|-|
|[AtlComModuleRegisterServer](#atlcommoduleregisterserver)|Essa função é chamada para registrar cada objeto no mapa de objetos.|
|[AtlComModuleUnregisterServer](#atlcommoduleunregisterserver)|Essa função é chamada para cancelar o registro de cada objeto no mapa de objetos.|
|[AtlComModuleRegisterClassObjects](#atlcommoduleregisterclassobjects)|Essa função é chamada para registrar objetos da classe.|
|[AtlComModuleRevokeClassObjects](#atlcommodulerevokeclassobjects)|Essa função é chamada para revogar objetos de classe de um módulo COM.|
|[AtlComModuleGetClassObject](#atlcommodulegetclassobject)|Essa função é chamada para obter o objeto de classe.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="atlcommoduleregisterserver"></a>AtlComModuleRegisterServer

Essa função é chamada para registrar cada objeto no mapa de objetos.

```
ATLINLINE ATLAPI AtlComModuleRegisterServer(
    _ATL_COM_MODULE* pComModule,
    BOOL bRegTypeLib,
    const CLSID* pCLSID);
```

### <a name="parameters"></a>parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

*bRegTypeLib*<br/>
TRUE se a biblioteca de tipos for registrada.

*pCLSID*<br/>
Aponta para o CLSID do objeto a ser registrado. Se for NULL, todos os objetos no mapa de objetos serão registrados.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

`AtlComModuleRegisterServer` percorre o mapa de objetos do ATL gerado automaticamente e registra cada objeto no mapa. Se *pCLSID* não for nulo, somente o objeto referido por *pCLSID* será registrado; caso contrário, todos os objetos serão registrados.

Essa função é chamada por [CAtlComModule:: RegisterServer](catlcommodule-class.md#registerserver).

##  <a name="atlcommoduleunregisterserver"></a>AtlComModuleUnregisterServer

Essa função é chamada para cancelar o registro de cada objeto no mapa de objetos.

```
ATLINLINE ATLAPI AtlComModuleUnregisterServer(
    _ATL_COM_MODULE* pComModule,
    BOOL bUnRegTypeLib,
    const CLSID* pCLSID);
```

### <a name="parameters"></a>parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

*bUnRegTypeLib*<br/>
TRUE se a biblioteca de tipos for registrada.

*pCLSID*<br/>
Aponta para o CLSID do objeto a ser cancelado. Se NULL, todos os objetos no mapa de objetos terão o registro cancelado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

`AtlComModuleUnregisterServer` percorre o mapa do objeto ATL e cancela o registro de cada objeto no mapa. Se *pCLSID* não for nulo, somente o objeto referido por *pCLSID* será cancelado. caso contrário, todos os objetos têm o registro cancelado.

Essa função é chamada por [CAtlComModule:: UnregisterServer](catlcommodule-class.md#unregisterserver).

##  <a name="atlcommoduleregisterclassobjects"></a>AtlComModuleRegisterClassObjects

Essa função é chamada para registrar objetos da classe.

```
ATLINLINE ATLAPI AtlComModuleRegisterClassObjects(
    _ATL_COM_MODULE* pComModule,
    DWORD dwClsContext,
    DWORD dwFlags);
```

### <a name="parameters"></a>parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

*dwClsContext*<br/>
Especifica o contexto no qual o objeto de classe deve ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER. Consulte [CLSCTX](/windows/win32/api/wtypesbase/ne-wtypesbase-clsctx) para obter mais detalhes.

*dwFlags*<br/>
Determina os tipos de conexão para o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE. Consulte [REGCLS](/windows/win32/api/combaseapi/ne-combaseapi-regcls) para obter mais detalhes.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Essa função auxiliar é utilizada por [CComModule:: RegisterClassObjects](ccommodule-class.md#registerclassobjects) (obsoleto no ATL 7,0) e [CAtlExeModuleT:: RegisterClassObjects](catlexemodulet-class.md#registerclassobjects).

##  <a name="atlcommodulerevokeclassobjects"></a>AtlComModuleRevokeClassObjects

Essa função é chamada para remover a fábrica/as fábricas da classe da Tabela de Objetos em Execução.

```
ATLINLINE ATLAPI AtlComModuleRevokeClassObjects(_ATL_COM_MODULE* pComModule);
```

### <a name="parameters"></a>parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Essa função auxiliar é utilizada por [CComModule:: RevokeClassObjects](ccommodule-class.md#revokeclassobjects) (obsoleto no ATL 7,0) e [CAtlExeModuleT:: RevokeClassObjects](catlexemodulet-class.md#revokeclassobjects).

##  <a name="atlcommodulegetclassobject"></a>AtlComModuleGetClassObject

Essa função é chamada para retornar a fábrica da classe.

```
ATLINLINE ATLAPI AtlComModuleGetClassObject(
    _ATL_COM_MODULE* pComModule,
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv);
```

### <a name="parameters"></a>parâmetros

*pComModule*<br/>
Ponteiro para o módulo COM.

*rclsid*<br/>
O CLSID do objeto a ser criado.

*riid*<br/>
O IID da interface solicitada.

*ppv*<br/>
Um ponteiro para o ponteiro de interface identificado por *riid*. Se o objeto não oferecer suporte a essa interface, *PPV* será definido como NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Essa função auxiliar é utilizada por [CComModule:: GetClassObject](ccommodule-class.md#getclassobject) (obsoleto em ATL 7,0) e [CAtlDllModuleT:: GetClassObject](catldllmodulet-class.md#getclassobject).

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
