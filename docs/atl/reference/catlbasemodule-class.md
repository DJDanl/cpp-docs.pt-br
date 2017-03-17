---
title: Classe CAtlBaseModule | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlBaseModule
- ATLCORE/ATL::CAtlBaseModule
- ATLCORE/ATL::CAtlBaseModule::CAtlBaseModule
- ATLCORE/ATL::CAtlBaseModule::AddResourceInstance
- ATLCORE/ATL::CAtlBaseModule::GetHInstanceAt
- ATLCORE/ATL::CAtlBaseModule::GetModuleInstance
- ATLCORE/ATL::CAtlBaseModule::GetResourceInstance
- ATLCORE/ATL::CAtlBaseModule::RemoveResourceInstance
- ATLCORE/ATL::CAtlBaseModule::SetResourceInstance
- ATLCORE/ATL::CAtlBaseModule::m_bInitFailed
dev_langs:
- C++
helpviewer_keywords:
- CAtlBaseModule class
ms.assetid: 55ade80c-9b0c-4c51-933e-2158436c1096
caps.latest.revision: 18
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 4897f6cf7e12a18401720ad663c90491bb0e599d
ms.lasthandoff: 02/25/2017

---
# <a name="catlbasemodule-class"></a>Classe CAtlBaseModule
Essa classe é instanciada em cada projeto ATL.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAtlBaseModule : public _ATL_BASE_MODULE
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlBaseModule::CAtlBaseModule](#catlbasemodule)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlBaseModule::AddResourceInstance](#addresourceinstance)|Adiciona uma instância do recurso à lista de identificadores armazenados.|  
|[CAtlBaseModule::GetHInstanceAt](#gethinstanceat)|Retorna um identificador para uma instância do recurso especificado.|  
|[CAtlBaseModule::GetModuleInstance](#getmoduleinstance)|Retorna a instância de módulo de um `CAtlBaseModule` objeto.|  
|[CAtlBaseModule::GetResourceInstance](#getresourceinstance)|Retorna a instância do recurso de uma `CAtlBaseModule` objeto.|  
|[CAtlBaseModule::RemoveResourceInstance](#removeresourceinstance)|Remove uma instância do recurso da lista de identificadores armazenados.|  
|[CAtlBaseModule::SetResourceInstance](#setresourceinstance)|Define a instância do recurso de uma `CAtlBaseModule` objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlBaseModule::m_bInitFailed](#m_binitfailed)|Uma variável que indica se a inicialização do módulo falhou.|  
  
## <a name="remarks"></a>Comentários  
 Uma instância de `CAtlBaseModule` _AtlBaseModule nomeado está presente em cada projeto ATL, que contém um identificador para a instância de módulo, um identificador para o módulo que contém os recursos (que, por padrão, são o mesmo) e uma matriz de identificadores para módulos que fornecem recursos principais. `CAtlBaseModule`pode ser acessado com segurança de vários threads.  
  
 Esta classe substitui o obsoleto [CComModule](../../atl/reference/ccommodule-class.md) classe usada em versões anteriores do ATL.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_BASE_MODULE](atl-typedefs.md#_atl_base_module)  
  
 `CAtlBaseModule`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="addresourceinstance"></a>CAtlBaseModule::AddResourceInstance  
 Adiciona uma instância do recurso à lista de identificadores armazenados.  
  
```
bool AddResourceInstance(HINSTANCE hInst) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInst`  
 A instância do recurso para adicionar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o recurso tiver sido adicionado, FALSO caso contrário.  
  
##  <a name="catlbasemodule"></a>CAtlBaseModule::CAtlBaseModule  
 O construtor.  
  
```
CAtlBaseModule() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Cria o `CAtlBaseModule`.  
  
##  <a name="gethinstanceat"></a>CAtlBaseModule::GetHInstanceAt  
 Retorna um identificador para uma instância do recurso especificado.  
  
```
HINSTANCE GetHInstanceAt(int i) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *i*  
 O número da instância do recurso.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador de instância do recurso, ou nulo se não existe nenhuma instância de recurso correspondente.  
  
##  <a name="getmoduleinstance"></a>CAtlBaseModule::GetModuleInstance  
 Retorna a instância de módulo de um `CAtlBaseModule` objeto.  
  
```
HINSTANCE GetModuleInstance() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a instância de módulo.  
  
##  <a name="getresourceinstance"></a>CAtlBaseModule::GetResourceInstance  
 Retorna a instância do recurso.  
  
```
HINSTANCE GetResourceInstance() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a instância do recurso.  
  
##  <a name="m_binitfailed"></a>CAtlBaseModule::m_bInitFailed  
 Uma variável que indica se a inicialização do módulo falhou.  
  
```
static bool m_bInitFailed;
```  
  
### <a name="remarks"></a>Comentários  
 True se o módulo inicializado, FALSO se ele não conseguiu inicializar.  
  
##  <a name="removeresourceinstance"></a>CAtlBaseModule::RemoveResourceInstance  
 Remove uma instância do recurso da lista de identificadores armazenados.  
  
```
bool RemoveResourceInstance(HINSTANCE hInst) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInst`  
 A instância do recurso para remover.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se o recurso foi removido com êxito, FALSO caso contrário.  
  
##  <a name="setresourceinstance"></a>CAtlBaseModule::SetResourceInstance  
 Define a instância do recurso de uma `CAtlBaseModule` objeto.  
  
```
HINSTANCE SetResourceInstance(HINSTANCE hInst) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInst`  
 A nova instância do recurso.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a instância do recurso atualizado.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)

