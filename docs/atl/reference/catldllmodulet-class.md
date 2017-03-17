---
title: Classe CAtlDllModuleT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CAtlDllModuleT class
ms.assetid: 351d5767-8257-4878-94be-45a85e31a72d
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 13cd0adb860660e06c92e8f02c07721ede391fb7
ms.lasthandoff: 02/25/2017

---
# <a name="catldllmodulet-class"></a>Classe CAtlDllModuleT
Essa classe representa o módulo para uma DLL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE CAtlDllModuleT : public CAtlModuleT<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `CAtlDllModuleT`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlDllModuleT::CAtlDllModuleT](#catldllmodulet)|O construtor.|  
|[CAtlDllModuleT:: ~ CAtlDllModuleT](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlDllModuleT::DllCanUnloadNow](#dllcanunloadnow)|Testa se a DLL pode ser descarregada.|  
|[CAtlDllModuleT::DllGetClassObject](#dllgetclassobject)|Retorna uma fábrica de classes.|  
|[CAtlDllModuleT::DllMain](#dllmain)|O ponto de entrada opcional em uma biblioteca de vínculo dinâmico (DLL).|  
|[CAtlDllModuleT::DllRegisterServer](#dllregisterserver)|Adiciona entradas ao registro do sistema para objetos na DLL.|  
|[CAtlDllModuleT::DllUnregisterServer](#dllunregisterserver)|Remove as entradas no registro do sistema para objetos na DLL.|  
|[CAtlDllModuleT::GetClassObject](#getclassobject)|Retorna uma fábrica de classes. Chamado por [DllGetClassObject](#dllgetclassobject).|  
  
## <a name="remarks"></a>Comentários  
 `CAtlDllModuleT`representa o módulo para uma biblioteca de vínculo dinâmico (DLL) e fornece funções usadas por todos os projetos DLL. Essa especialização de [CAtlModuleT](../../atl/reference/catlmodulet-class.md) classe inclui suporte para registro.  
  
 Para obter mais informações sobre módulos em ATL, consulte [Classes de módulo ATL](../../atl/atl-module-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_MODULE](atl-typedefs.md#_atl_module)  
  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 [CAtlModuleT](../../atl/reference/catlmodulet-class.md)  
  
 `CAtlDllModuleT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="catldllmodulet"></a>CAtlDllModuleT::CAtlDllModuleT  
 O construtor.  
  
```
CAtlDllModuleT() throw();
```  
  
##  <a name="dtor"></a>CAtlDllModuleT:: ~ CAtlDllModuleT  
 O destruidor.  
  
```
~CAtlDllModuleT() throw();
```  
  
##  <a name="dllcanunloadnow"></a>CAtlDllModuleT::DllCanUnloadNow  
 Testa se a DLL pode ser descarregada.  
  
```
HRESULT DllCanUnloadNow() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK se a DLL pode ser descarregada ou S_FALSE se não for.  
  
##  <a name="dllgetclassobject"></a>CAtlDllModuleT::DllGetClassObject  
 Retorna a fábrica de classes.  
  
```
HRESULT DllGetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rclsid`  
 O CLSID do objeto a ser criado.  
  
 `riid`  
 O IID da interface solicitada.  
  
 `ppv`  
 Um ponteiro para o ponteiro de interface identificado pelo `riid`. Se o objeto não oferece suporte a essa interface, `ppv` é definido como NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="dllmain"></a>CAtlDllModuleT::DllMain  
 O ponto de entrada opcional em uma biblioteca de vínculo dinâmico (DLL).  
  
```
BOOL WINAPI DllMain(DWORD dwReason, LPVOID /* lpReserved*/) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwReason`  
 Se definido como chamadas de notificação DLL_PROCESS_ATTACH DLL_THREAD_ATTACH e DLL_THREAD_DETACH está desabilitado.  
  
 *lpReserved*  
 Reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna TRUE.  
  
### <a name="remarks"></a>Comentários  
 Desabilitando o DLL_THREAD_ATTACH e DLL_THREAD_DETACH chamadas de notificação podem ser uma otimização útil para aplicativos multithread que têm várias DLLs, que frequentemente criar e excluir threads e cujas DLLs não precisam essas notificações de nível de thread de anexo/desconexão.  
  
##  <a name="dllregisterserver"></a>CAtlDllModuleT::DllRegisterServer  
 Adiciona entradas ao registro do sistema para objetos na DLL.  
  
```
HRESULT DllRegisterServer(BOOL bRegTypeLib = TRUE) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegTypeLib`  
 TRUE se a biblioteca de tipos a ser registrado. O valor padrão é TRUE.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="dllunregisterserver"></a>CAtlDllModuleT::DllUnregisterServer  
 Remove as entradas no registro do sistema para objetos na DLL.  
  
```
HRESULT DllUnregisterServer(BOOL bUnRegTypeLib = TRUE) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bUnRegTypeLib`  
 TRUE se a biblioteca de tipos a ser removido do registro. O valor padrão é TRUE.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="getclassobject"></a>CAtlDllModuleT::GetClassObject  
 Cria um objeto do CLSID especificado.  
  
```
HRESULT GetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    LPVOID* ppv) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `rclsid`  
 O CLSID do objeto a ser criado.  
  
 `riid`  
 O IID da interface solicitada.  
  
 `ppv`  
 Um ponteiro para o ponteiro de interface identificado pelo `riid`. Se o objeto não oferece suporte a essa interface, `ppv` é definido como NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pelo [CAtlDllModuleT::DllGetClassObject](#dllgetclassobject) e é incluído para compatibilidade com versões anteriores.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlModuleT](../../atl/reference/catlmodulet-class.md)   
 [Classe CAtlExeModuleT](../../atl/reference/catlexemodulet-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)

