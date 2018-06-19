---
title: Classe CAtlWinModule | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 14b918747d9b7bee1b661eebd61fbb35325861e7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32358046"
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
  
### <a name="public-constructors"></a>Construtores Públicos  
  
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
  
##  <a name="addcreatewnddata"></a>  CAtlWinModule::AddCreateWndData  
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
  
##  <a name="catlwinmodule"></a>  CAtlWinModule::CAtlWinModule  
 O construtor.  
  
```
CAtlWinModule();
```  
  
### <a name="remarks"></a>Comentários  
 Se a inicialização falhar, um **EXCEPTION_NONCONTINUABLE** exceção será gerada.  
  
##  <a name="dtor"></a>  CAtlWinModule:: ~ CAtlWinModule  
 O destruidor.  
  
```
~CAtlWinModule();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="extractcreatewnddata"></a>  CAtlWinModule::ExtractCreateWndData  
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
