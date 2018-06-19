---
title: Funções globais do registro de servidor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlComModuleRegisterServer
- atlbase/ATL::AtlComModuleUnregisterServer
- atlbase/ATL::AtlComModuleRegisterClassObjects
- atlbase/ATL::AtlComModuleRevokeClassObjects
- atlbase/ATL::AtlComModuleGetClassObject
dev_langs:
- C++
ms.assetid: c2f0a35d-857c-4538-a44d-c4ea0db63b06
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 08a4141ab5ff27e44f663a4d5f267c2b7d754283
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32364699"
---
# <a name="server-registration-global-functions"></a>Funções globais do registro de servidor
Essas funções fornecem suporte para registrar e cancelar o registro de objetos de servidor no mapa do objeto.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados o tempo de execução do Windows.  
  
|||  
|-|-|  
|[AtlComModuleRegisterServer](#atlcommoduleregisterserver)|Essa função é chamada para registrar cada objeto no mapa de objetos.|  
|[AtlComModuleUnregisterServer](#atlcommoduleunregisterserver)|Essa função é chamada para cancelar o registro de cada objeto no mapa de objetos.|  
|[AtlComModuleRegisterClassObjects](#atlcommoduleregisterclassobjects)|Essa função é chamada para registrar objetos da classe.|  
|[AtlComModuleRevokeClassObjects](#atlcommodulerevokeclassobjects)|Essa função é chamada para revogar os objetos da classe de um módulo de COM.|  
|[AtlComModuleGetClassObject](#atlcommodulegetclassobject)|Essa função é chamada para obter o objeto de classe.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
   
##  <a name="atlcommoduleregisterserver"></a>  AtlComModuleRegisterServer  
 Essa função é chamada para registrar cada objeto no mapa de objetos.  
  
```
ATLINLINE ATLAPI AtlComModuleRegisterServer(
    _ATL_COM_MODULE* pComModule,
    BOOL bRegTypeLib,
    const CLSID* pCLSID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pComModule`  
 Ponteiro para o módulo de COM.  
  
 `bRegTypeLib`  
 TRUE se a biblioteca de tipos a ser registrado.  
  
 `pCLSID`  
 Aponta para o CLSID do objeto a ser registrado. Se for NULL, todos os objetos no mapa de objeto serão registrados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `AtlComModuleRegisterServer` orienta o mapa de objeto ATL gerado automaticamente e registra cada objeto no mapa. Se `pCLSID` não for NULL, apenas o objeto referenciado por `pCLSID` está registrado; caso contrário, todos os objetos são registrados.  
  
 Essa função é chamada [CAtlComModule::RegisterServer](catlcommodule-class.md#registerserver).  
  
##  <a name="atlcommoduleunregisterserver"></a>  AtlComModuleUnregisterServer  
 Essa função é chamada para cancelar o registro de cada objeto no mapa de objetos.  
  
```
ATLINLINE ATLAPI AtlComModuleUnregisterServer(
    _ATL_COM_MODULE* pComModule,
    BOOL bUnRegTypeLib,
    const CLSID* pCLSID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pComModule`  
 Ponteiro para o módulo de COM.  
  
 `bUnRegTypeLib`  
 TRUE se a biblioteca de tipos a ser registrado.  
  
 `pCLSID`  
 Aponta para o CLSID do objeto a ser cancelado. Se for NULL, todos os objetos no mapa de objeto será cancelados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `AtlComModuleUnregisterServer` orienta o mapa de objeto ATL e cancela o registro de cada objeto no mapa. Se `pCLSID` não for NULL, apenas o objeto referenciado por `pCLSID` esteja registrado; caso contrário, todos os objetos não são registrados.  
  
 Essa função é chamada [CAtlComModule::UnregisterServer](catlcommodule-class.md#unregisterserver).  
  
##  <a name="atlcommoduleregisterclassobjects"></a>  AtlComModuleRegisterClassObjects  
 Essa função é chamada para registrar objetos da classe.  
  
```
ATLINLINE ATLAPI AtlComModuleRegisterClassObjects(
    _ATL_COM_MODULE* pComModule,
    DWORD dwClsContext,
    DWORD dwFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pComModule`  
 Ponteiro para o módulo de COM.  
  
 `dwClsContext`  
 Especifica o contexto no qual o objeto de classe é para ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER. Consulte [CLSCTX](http://msdn.microsoft.com/library/windows/desktop/ms693716) para obter mais detalhes.  
  
 `dwFlags`  
 Determina os tipos de conexão para o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE. Consulte [REGCLS](http://msdn.microsoft.com/library/windows/desktop/ms679697) para obter mais detalhes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar utilizada por [CComModule::RegisterClassObjects](ccommodule-class.md#registerclassobjects) (obsoleto no ATL 7.0) e [CAtlExeModuleT::RegisterClassObjects](catlexemodulet-class.md#registerclassobjects).  
  
##  <a name="atlcommodulerevokeclassobjects"></a>  AtlComModuleRevokeClassObjects  
 Essa função é chamada para remover a fábrica/as fábricas da classe da Tabela de Objetos em Execução.  
  
```
ATLINLINE ATLAPI AtlComModuleRevokeClassObjects(_ATL_COM_MODULE* pComModule);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pComModule`  
 Ponteiro para o módulo de COM.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar utilizada por [CComModule::RevokeClassObjects](ccommodule-class.md#revokeclassobjects) (obsoleto no ATL 7.0) e [CAtlExeModuleT::RevokeClassObjects](catlexemodulet-class.md#revokeclassobjects).  
  
##  <a name="atlcommodulegetclassobject"></a>  AtlComModuleGetClassObject  
 Essa função é chamada para retornar a fábrica da classe.  
  
```
ATLINLINE ATLAPI AtlComModuleGetClassObject(
    _ATL_COM_MODULE* pComModule,
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pComModule`  
 Ponteiro para o módulo de COM.  
  
 `rclsid`  
 O CLSID do objeto a ser criado.  
  
 `riid`  
 O IID da interface solicitada.  
  
 `ppv`  
 Um ponteiro para o ponteiro de interface identificado por `riid`. Se o objeto não oferece suporte a essa interface `ppv` é definido como NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar utilizada por [CComModule::GetClassObject](ccommodule-class.md#getclassobject) (obsoleto no ATL 7.0) e [CAtlDllModuleT::GetClassObject](catldllmodulet-class.md#getclassobject).  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)
