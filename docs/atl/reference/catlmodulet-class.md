---
title: Classe CAtlModuleT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CAtlModuleT class
ms.assetid: 9b74d02f-9117-47b1-a05e-c5945f83dd2b
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
ms.openlocfilehash: 9c0c6a2302932df06db7166d83fe9a561dfe38ac
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="catlmodulet-class"></a>Classe CAtlModuleT
Essa classe implementa um módulo ATL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE CAtlModuleT : public CAtlModule
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
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
|[CAtlModuleT::RegisterAppId](#registerappid)|Adiciona o arquivo EXE no registro.|  
|[CAtlModuleT::RegisterServer](#registerserver)|Adiciona o serviço no registro.|  
|[CAtlModuleT::UnregisterAppId](#unregisterappid)|Remove o arquivo EXE do registro.|  
|[CAtlModuleT::UnregisterServer](#unregisterserver)|Remove o serviço de registro.|  
|[CAtlModuleT::UpdateRegistryAppId](#updateregistryappid)|Atualiza as informações de EXE no registro.|  
  
## <a name="remarks"></a>Comentários  
 `CAtlModuleT`, derivada de [CAtlModule](../../atl/reference/catlmodule-class.md), implementa um executável (EXE) ou um módulo ATL do serviço (EXE). Um módulo executável é um servidor local e fora de processo, enquanto um módulo de serviço é um aplicativo do Windows que é executado em segundo plano quando o Windows inicia.  
  
 `CAtlModuleT`fornece suporte para inicializar, registrar e cancelar o registro do módulo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_MODULE](atl-typedefs.md#_atl_module)  

  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 `CAtlModuleT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="catlmodulet"></a>CAtlModuleT::CAtlModuleT  
 O construtor.  
  
```
CAtlModuleT() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chamadas [CAtlModuleT::InitLibId](#initlibid).  
  
##  <a name="initlibid"></a>CAtlModuleT::InitLibId  
 Inicializa o membro de dados que contém o GUID do módulo atual.  
  
```
static void InitLibId() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Chamado pelo construtor [CAtlModuleT::CAtlModuleT](#catlmodulet).  
  
##  <a name="registerappid"></a>CAtlModuleT::RegisterAppId  
 Adiciona o arquivo EXE no registro.  
  
```
HRESULT RegisterAppId() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="registerserver"></a>CAtlModuleT::RegisterServer  
 Adiciona o serviço no registro.  
  
```
HRESULT RegisterServer(
    BOOL bRegTypeLib = FALSE,
    const CLSID* pCLSID = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegTypeLib`  
 TRUE se a biblioteca de tipos a ser registrado. O valor padrão é FALSE.  
  
 `pCLSID`  
 Aponta para o CLSID do objeto a ser registrado. Se NULL (o valor padrão), todos os objetos no mapa de objetos será registrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="unregisterappid"></a>CAtlModuleT::UnregisterAppId  
 Remove o arquivo EXE do registro.  
  
```
HRESULT UnregisterAppId() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="unregisterserver"></a>CAtlModuleT::UnregisterServer  
 Remove o serviço de registro.  
  
```
HRESULT UnregisterServer(
    BOOL bUnRegTypeLib,
    const CLSID* pCLSID = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bUnRegTypeLib`  
 TRUE se a biblioteca de tipos também é possível cancelar o registro.  
  
 `pCLSID`  
 Aponta para o CLSID do objeto a ser cancelado. Se NULL (o valor padrão), todos os objetos no mapa de objetos será cancelado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
##  <a name="updateregistryappid"></a>CAtlModuleT::UpdateRegistryAppId  
 Atualiza as informações de EXE no registro.  
  
```
static HRESULT WINAPI UpdateRegistryAppId(BOOL /* bRegister*/) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegister`  
 Reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlModule](../../atl/reference/catlmodule-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)

