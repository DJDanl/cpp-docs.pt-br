---
title: Classe CComSimpleThreadAllocator | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComSimpleThreadAllocator
- ATLBASE/ATL::CComSimpleThreadAllocator
- ATLBASE/ATL::CComSimpleThreadAllocator::GetThread
dev_langs:
- C++
helpviewer_keywords:
- threading [ATL], selecting threads
- ATL threads
- CComSimpleThreadAllocator class
- ATL threads, allocating
ms.assetid: 66b2166a-8c50-49fd-b8e4-7f293470327d
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
ms.openlocfilehash: 377e7f2fa6d8377d46e98b52e9c8f075b10956a8
ms.lasthandoff: 02/25/2017

---
# <a name="ccomsimplethreadallocator-class"></a>Classe CComSimpleThreadAllocator
Essa classe gerencia a seleção de thread para a classe `CComAutoThreadModule`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComSimpleThreadAllocator
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComSimpleThreadAllocator::GetThread](#getthread)|Seleciona um thread.|  
  
## <a name="remarks"></a>Comentários  
 `CComSimpleThreadAllocator`gerencia a seleção de thread para [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md). `CComSimpleThreadAllocator::GetThread`simplesmente percorre cada thread e retornará o próximo na sequência.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="getthread"></a>CComSimpleThreadAllocator::GetThread  
 Seleciona um thread, especificando o próximo segmento na sequência.  
  
```
int GetThread(CComApartment* /* pApt */, int nThreads);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pApt`  
 Não usado na implementação do padrão da ATL.  
  
 `nThreads`  
 O número máximo de threads no módulo EXE.  
  
### <a name="return-value"></a>Valor de retorno  
 Um número inteiro entre zero e ( `nThreads` – 1). Identifica um dos threads no módulo EXE.  
  
### <a name="remarks"></a>Comentários  
 Você pode substituir `GetThread` para fornecer um método diferente de seleção ou fazer uso do `pApt` parâmetro.  
  
 `GetThread`chamado por [CComAutoThreadModule::CreateInstance](../../atl/reference/ccomautothreadmodule-class.md#createinstance).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComApartment](../../atl/reference/ccomapartment-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

