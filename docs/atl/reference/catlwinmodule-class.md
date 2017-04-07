---
title: Classe CAtlWinModule | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAtlWinModule
- ATLBASE/ATL::CAtlWinModule
- ATLBASE/ATL::CAtlWinModule::CAtlWinModule
- ATLBASE/ATL::CAtlWinModule::AddCreateWndData
- ATLBASE/ATL::CAtlWinModule::ExtractCreateWndData
dev_langs:
- C++
helpviewer_keywords:
- CAtlWinModule class
ms.assetid: 7ec844af-0f68-4a34-b0c8-9de50a025df0
caps.latest.revision: 20
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
ms.sourcegitcommit: d2d39abf526a58b8442107b5ee816f316ae841f5
ms.openlocfilehash: f2d5e28f39159b097c4e00e11518295b2872a84b
ms.lasthandoff: 03/31/2017

---
# <a name="catlwinmodule-class"></a>Classe CAtlWinModule
Essa classe fornece suporte para componentes de janelas ATL.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CAtlWinModule : public _ATL_WIN_MODULE
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlWinModule::CAtlWinModule](#catlwinmodule)|O construtor.|  
|[CAtlWinModule:: ~ CAtlWinModule](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAtlWinModule::AddCreateWndData](#addcreatewnddata)|Adiciona um objeto de dados.|  
|[CAtlWinModule::ExtractCreateWndData](#extractcreatewnddata)|Retorna um ponteiro para o objeto de dados do módulo de janela.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece suporte para todas as classes ATL que exigem recursos de janelas.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)  
  
 `CAtlWinModule`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="addcreatewnddata"></a>CAtlWinModule::AddCreateWndData  
 Esse método inicializa e adiciona um `_AtlCreateWndData` estrutura.  
  
```
void AddCreateWndData(_AtlCreateWndData* pData, void* pObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pData`  
 Ponteiro para o `_AtlCreateWndData` estrutura a ser inicializado e adicionados ao módulo atual.  
  
 `pObject`  
 Ponteiro para um objeto **isso** ponteiro.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [AtlWinModuleAddCreateWndData](winmodule-global-functions.md#atlwinmoduleaddcreatewnddata) que inicializa um [_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md) estrutura. Essa estrutura armazenará o **isso** ponteiro, usado para obter a instância da classe nos procedimentos de janela.  
  
##  <a name="catlwinmodule"></a>CAtlWinModule::CAtlWinModule  
 O construtor.  
  
```
CAtlWinModule();
```  
  
### <a name="remarks"></a>Comentários  
 Se a inicialização falhar, um **EXCEPTION_NONCONTINUABLE** exceção será gerada.  
  
##  <a name="dtor"></a>CAtlWinModule:: ~ CAtlWinModule  
 O destruidor.  
  
```
~CAtlWinModule();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="extractcreatewnddata"></a>CAtlWinModule::ExtractCreateWndData  
 Esse método retorna um ponteiro para um `_AtlCreateWndData` estrutura.  
  
```
void* ExtractCreateWndData();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o `_AtlCreateWndData` estrutura adicionada anteriormente com [CAtlWinModule::AddCreateWndData](#addcreatewnddata), ou nulo se nenhum objeto está disponível.  
  
## <a name="see-also"></a>Consulte também  
 [_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)

