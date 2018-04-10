---
title: Classe CAtlModuleT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
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
ms.workload:
- cplusplus
ms.openlocfilehash: a4f1ba8d59e85a480af38e5b9778fee0c714a0db
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 A classe derivada de `CAtlModuleT`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlModuleT::CAtlModuleT](#catlmodulet)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlModuleT::InitLibId](#initlibid)|Inicializa o membro de dados que contém o GUID do módulo atual.|  
|[CAtlModuleT::RegisterAppId](#registerappid)|Adiciona o arquivo EXE no registro.|  
|[CAtlModuleT::RegisterServer](#registerserver)|Adiciona o serviço de registro.|  
|[CAtlModuleT::UnregisterAppId](#unregisterappid)|Remove o arquivo EXE do registro.|  
|[CAtlModuleT::UnregisterServer](#unregisterserver)|Remove o serviço de registro.|  
|[CAtlModuleT::UpdateRegistryAppId](#updateregistryappid)|Atualiza as informações de EXE no registro.|  
  
## <a name="remarks"></a>Comentários  
 `CAtlModuleT`, derivado do [CAtlModule](../../atl/reference/catlmodule-class.md), implementa um executável (EXE) ou um módulo ATL do serviço (EXE). Um módulo executável é um servidor local, fora do processo, enquanto um módulo de serviço é um aplicativo do Windows que é executado em segundo plano quando o Windows iniciar.  
  
 `CAtlModuleT`fornece suporte para inicializar, registrar e cancelar o registro do módulo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_MODULE](atl-typedefs.md#_atl_module)  

  
 [CAtlModule](../../atl/reference/catlmodule-class.md)  
  
 `CAtlModuleT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
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
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
##  <a name="registerserver"></a>CAtlModuleT::RegisterServer  
 Adiciona o serviço de registro.  
  
```
HRESULT RegisterServer(
    BOOL bRegTypeLib = FALSE,
    const CLSID* pCLSID = NULL) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegTypeLib`  
 TRUE se a biblioteca de tipos a ser registrado. O valor padrão é FALSE.  
  
 `pCLSID`  
 Aponta para o CLSID do objeto a ser registrado. Se NULL (o valor padrão), todos os objetos no mapa de objeto será registrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
##  <a name="unregisterappid"></a>CAtlModuleT::UnregisterAppId  
 Remove o arquivo EXE do registro.  
  
```
HRESULT UnregisterAppId() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
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
 Aponta para o CLSID do objeto a ser cancelado. Se NULL (o valor padrão), todos os objetos no mapa de objeto será cancelado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
##  <a name="updateregistryappid"></a>CAtlModuleT::UpdateRegistryAppId  
 Atualiza as informações de EXE no registro.  
  
```
static HRESULT WINAPI UpdateRegistryAppId(BOOL /* bRegister*/) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegister`  
 Reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlModule](../../atl/reference/catlmodule-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)
