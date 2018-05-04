---
title: Classe CComSimpleThreadAllocator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: da050dbf2b4052aeadd9fe8380857a0ba15b264f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
 `CComSimpleThreadAllocator` gerencia a seleção de thread para [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md). `CComSimpleThreadAllocator::GetThread` simplesmente percorre cada thread e retorna o outro na sequência.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="getthread"></a>  CComSimpleThreadAllocator::GetThread  
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
 Um número inteiro entre zero e ( `nThreads` - 1). Identifica um dos segmentos no módulo EXE.  
  
### <a name="remarks"></a>Comentários  
 Você pode substituir `GetThread` para fornecer um método diferente da seleção ou fazer uso do `pApt` parâmetro.  
  
 `GetThread` é chamado pelo [CComAutoThreadModule::CreateInstance](../../atl/reference/ccomautothreadmodule-class.md#createinstance).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComApartment](../../atl/reference/ccomapartment-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
