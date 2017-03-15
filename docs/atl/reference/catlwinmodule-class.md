---
title: Classe CAtlWinModule | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CAtlWinModule
- ATL.CAtlWinModule
- CAtlWinModule
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 6db3ae9e610605524683e984f2aba602b1daf0d4
ms.lasthandoff: 02/25/2017

---
# <a name="catlwinmodule-class"></a>Classe CAtlWinModule
Esta classe oferece suporte para componentes de janela ATL.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
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
 Esta classe oferece suporte para todas as classes ATL que exigem recursos de janelas.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)  
  
 `CAtlWinModule`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="a-nameaddcreatewnddataa--catlwinmoduleaddcreatewnddata"></a><a name="addcreatewnddata"></a>CAtlWinModule::AddCreateWndData  
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
 Esse método chama [AtlWinModuleAddCreateWndData](http://msdn.microsoft.com/library/8463a6ed-07ea-4aad-92ec-ded681601b32) que inicializa um [_AtlCreateWndData](../../atl/reference/atlcreatewnddata-structure.md) estrutura. Essa estrutura armazenará o **isso** ponteiro, usado para obter a instância da classe nos procedimentos de janela.  
  
##  <a name="a-namecatlwinmodulea--catlwinmodulecatlwinmodule"></a><a name="catlwinmodule"></a>CAtlWinModule::CAtlWinModule  
 O construtor.  
  
```
CAtlWinModule();
```  
  
### <a name="remarks"></a>Comentários  
 Se a inicialização falhar, uma **EXCEPTION_NONCONTINUABLE** exceção é gerada.  
  
##  <a name="a-namedtora--catlwinmodulecatlwinmodule"></a><a name="dtor"></a>CAtlWinModule:: ~ CAtlWinModule  
 O destruidor.  
  
```
~CAtlWinModule();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="a-nameextractcreatewnddataa--catlwinmoduleextractcreatewnddata"></a><a name="extractcreatewnddata"></a>CAtlWinModule::ExtractCreateWndData  
 Esse método retorna um ponteiro para um `_AtlCreateWndData` estrutura.  
  
```
void* ExtractCreateWndData();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o `_AtlCreateWndData` estrutura adicionada anteriormente com [CAtlWinModule::AddCreateWndData](#addcreatewnddata), ou nulo se o objeto não está disponível.  
  
## <a name="see-also"></a>Consulte também  
 [_ATL_WIN_MODULE](atl-typedefs.md#_atl_win_module)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classes de módulo](../../atl/atl-module-classes.md)

