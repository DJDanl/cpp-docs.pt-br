---
title: Classe CAtlComModule | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CAtlComModule
- CAtlComModule
- ATL::CAtlComModule
dev_langs:
- C++
helpviewer_keywords:
- CAtlComModule class
ms.assetid: af5dd71a-a0d1-4a2e-9a24-154a03381c75
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
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 6b933b5388fccc2dc0e31d035aa7eb56de3b1866
ms.lasthandoff: 02/25/2017

---
# <a name="catlcommodule-class"></a>Classe CAtlComModule
Essa classe implementa um módulo de servidor COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```
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
 `CAtlComModule`implementa um módulo de servidor COM, permitindo que um cliente acessar componentes do módulo.  
  
 Esta classe substitui o obsoleto [CComModule](../../atl/reference/ccommodule-class.md) classe usada em versões anteriores do ATL. Consulte [Classes de módulo ATL](../../atl/atl-module-classes.md) para obter mais detalhes.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module)  
  
 `CAtlComModule`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="a-namecatlcommodulea--catlcommodulecatlcommodule"></a><a name="catlcommodule"></a>CAtlComModule::CAtlComModule  
 O construtor.  
  
```
CAtlComModule() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa o módulo.  
  
##  <a name="a-namedtora--catlcommodulecatlcommodule"></a><a name="dtor"></a>CAtlComModule:: ~ CAtlComModule  
 O destruidor.  
  
```
~CAtlComModule();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todas as fábricas de classe.  
  
##  <a name="a-nameregisterservera--catlcommoduleregisterserver"></a><a name="registerserver"></a>CAtlComModule::RegisterServer  
 Chame esse método para atualizar o registro do sistema para cada objeto no mapa de objetos.  
  
```
HRESULT RegisterServer(BOOL bRegTypeLib = FALSE, const CLSID* pCLSID = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegTypeLib`  
 TRUE se a biblioteca de tipos a ser registrado. O valor padrão é FALSE.  
  
 `pCLSID`  
 Aponta para o CLSID do objeto a ser registrado. Se NULL (o valor padrão), todos os objetos no mapa de objetos será registrado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chama a função global [AtlComModuleRegisterServer](http://msdn.microsoft.com/library/d11a0c91-0c56-4b1b-a5f5-1287970f798b).  
  
##  <a name="a-nameregistertypeliba--catlcommoduleregistertypelib"></a><a name="registertypelib"></a>CAtlComModule::RegisterTypeLib  
 Chame esse método para registrar uma biblioteca de tipos.  
  
```
HRESULT RegisterTypeLib(LPCTSTR lpszIndex);
HRESULT RegisterTypeLib();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszIndex`  
 Cadeia de caracteres no formato "\\\N", onde N é o índice de recurso TYPELIB inteiro.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Adiciona informações sobre uma biblioteca de tipos para o registro do sistema. Se a instância do módulo contém várias bibliotecas de tipo, use a primeira versão desse método para especificar qual biblioteca de tipo deve ser usada.  
  
##  <a name="a-nameunregisterservera--catlcommoduleunregisterserver"></a><a name="unregisterserver"></a>CAtlComModule::UnregisterServer  
 Chame esse método para cancelar o registro de cada objeto no mapa de objetos.  
  
```
HRESULT UnregisterServer(
  BOOL bRegTypeLib = FALSE,  
  const CLSID* pCLSID = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRegTypeLib`  
 TRUE se a biblioteca de tipos deve ser cancelado. O valor padrão é FALSE.  
  
 `pCLSID`  
 Aponta para o CLSID do objeto a ser cancelado. Se NULL (o valor padrão), todos os objetos no mapa de objetos será cancelado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Chama a função global [AtlComModuleUnregisterServer](http://msdn.microsoft.com/library/c4ef3da4-def7-4aaf-b005-573a02e389d5).  
  
##  <a name="a-nameunregistertypeliba--catlcommoduleunregistertypelib"></a><a name="unregistertypelib"></a>CAtlComModule::UnRegisterTypeLib  
 Chame esse método para cancelar o registro de uma biblioteca de tipos.  
  
```
HRESULT UnRegisterTypeLib(LPCTSTR lpszIndex);
HRESULT UnRegisterTypeLib();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszIndex`  
 Cadeia de caracteres no formato "\\\N", onde N é o índice de recurso TYPELIB inteiro.  
  
### <a name="remarks"></a>Comentários  
 Remove informações sobre uma biblioteca de tipos de registro do sistema. Se a instância do módulo contém várias bibliotecas de tipo, use a primeira versão desse método para especificar qual biblioteca de tipo deve ser usada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK com êxito, ou um erro HRESULT em caso de falha.  
  
## <a name="see-also"></a>Consulte também  
 [_ATL_COM_MODULE](atl-typedefs.md#_atl_com_module)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

