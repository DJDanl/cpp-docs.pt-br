---
title: "Funções globais de registro de servidor | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: c2f0a35d-857c-4538-a44d-c4ea0db63b06
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 4ace3bb50d824827071260e3f43cec3cda32742f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="server-registration-global-functions"></a>Funções globais de registro de servidor
Essas funções fornecem suporte para registrar e cancelar o registro de objetos de servidor no mapa de objetos.  
  
> [!IMPORTANT]
>  As funções listadas na tabela a seguir não podem ser usadas em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
|||  
|-|-|  
|[AtlComModuleRegisterServer](#atlcommoduleregisterserver)|Essa função é chamada para registrar cada objeto no mapa de objetos.|  
|[AtlComModuleUnregisterServer](#atlcommoduleunregisterserver)|Essa função é chamada para cancelar o registro de cada objeto no mapa de objetos.|  
|[AtlComModuleRegisterClassObjects](#atlcommoduleregisterclassobjects)|Essa função é chamada para registrar objetos da classe.|  
|[AtlComModuleRevokeClassObjects](#atlcommodulerevokeclassobjects)|Essa função é chamada para revogar os objetos de classe de um módulo de COM.|  
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
  
### <a name="parameters"></a>Parâmetros  
 `pComModule`  
 Ponteiro para o módulo de COM.  
  
 `bRegTypeLib`  
 TRUE se a biblioteca de tipos a ser registrado.  
  
 `pCLSID`  
 Aponta para o CLSID do objeto a ser registrado. Se for NULL, todos os objetos no mapa do objeto serão registrados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `AtlComModuleRegisterServer`orienta o mapa de objeto ATL gerada automaticamente e registra cada objeto no mapa. Se `pCLSID` não é nulo, então apenas o objeto referenciado por `pCLSID` é registrado; caso contrário, todos os objetos são registrados.  
  
 Essa função é chamada pelo [CAtlComModule::RegisterServer](catlcommodule-class.md#registerserver).  
  
##  <a name="atlcommoduleunregisterserver"></a>AtlComModuleUnregisterServer  
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
 Aponta para o CLSID do objeto a ser cancelado. Se for NULL, todos os objetos no mapa de objetos será cancelados.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 `AtlComModuleUnregisterServer`orienta o mapa de objeto ATL e cancela o registro de cada objeto no mapa. Se `pCLSID` não é nulo, então apenas o objeto referenciado por `pCLSID` esteja registrado; caso contrário, todos os objetos não são registrados.  
  
 Essa função é chamada pelo [CAtlComModule::UnregisterServer](catlcommodule-class.md#unregisterserver).  
  
##  <a name="atlcommoduleregisterclassobjects"></a>AtlComModuleRegisterClassObjects  
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
 Especifica o contexto no qual o objeto de classe deve ser executado. Os valores possíveis são CLSCTX_INPROC_SERVER, CLSCTX_INPROC_HANDLER ou CLSCTX_LOCAL_SERVER. Consulte [CLSCTX](http://msdn.microsoft.com/library/windows/desktop/ms693716) para obter mais detalhes.  
  
 `dwFlags`  
 Determina os tipos de conexão para o objeto de classe. Os valores possíveis são REGCLS_SINGLEUSE, REGCLS_MULTIPLEUSE ou REGCLS_MULTI_SEPARATE. Consulte [REGCLS](http://msdn.microsoft.com/library/windows/desktop/ms679697) para obter mais detalhes.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar é utilizada por [CComModule::RegisterClassObjects](ccommodule-class.md#registerclassobjects) (obsoleto na ATL 7.0) e [CAtlExeModuleT::RegisterClassObjects](catlexemodulet-class.md#registerclassobjects).  
  
##  <a name="atlcommodulerevokeclassobjects"></a>AtlComModuleRevokeClassObjects  
 Essa função é chamada para remover a fábrica/as fábricas da classe da Tabela de Objetos em Execução.  
  
```
ATLINLINE ATLAPI AtlComModuleRevokeClassObjects(_ATL_COM_MODULE* pComModule);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pComModule`  
 Ponteiro para o módulo de COM.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar é utilizada por [CComModule::RevokeClassObjects](ccommodule-class.md#revokeclassobjects) (obsoleto na ATL 7.0) e [CAtlExeModuleT::RevokeClassObjects](catlexemodulet-class.md#revokeclassobjects).  
  
##  <a name="atlcommodulegetclassobject"></a>AtlComModuleGetClassObject  
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
 Um ponteiro para o ponteiro de interface identificado pelo `riid`. Se o objeto não oferece suporte a essa interface, `ppv` é definido como NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função auxiliar é utilizada por [CComModule::GetClassObject](ccommodule-class.md#getclassobject) (obsoleto na ATL 7.0) e [CAtlDllModuleT::GetClassObject](catldllmodulet-class.md#getclassobject).  
  
## <a name="see-also"></a>Consulte também  
 [Funções](../../atl/reference/atl-functions.md)

