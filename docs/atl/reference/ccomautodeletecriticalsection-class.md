---
title: Classe CComAutoDeleteCriticalSection | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComAutoDeleteCriticalSection
- atlcore/ATL::CComAutoDeleteCriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CComAutoDeleteCriticalSection class
ms.assetid: 2396dbea-1c60-4841-b50e-c4e18af311a3
caps.latest.revision: 17
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
ms.sourcegitcommit: 050e7483670bd32f633660ba44491c8bb3fc462d
ms.openlocfilehash: eb53a0966d29759bbe7513f6042f72a280801707
ms.lasthandoff: 02/25/2017

---
# <a name="ccomautodeletecriticalsection-class"></a>Classe CComAutoDeleteCriticalSection
Essa classe fornece métodos para a obtenção e liberar a propriedade de um objeto da seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComAutoDeleteCriticalSection : public CComSafeDeleteCriticalSection
```  
  
## <a name="remarks"></a>Comentários  
 `CComAutoDeleteCriticalSection`deriva da classe [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md). No entanto, `CComAutoDeleteCriticalSection` substitui o [termo](ccomsafedeletecriticalsection-class.md#term) método `private` acesso, o que força a limpeza de memória interna para ocorrer somente quando as instâncias dessa classe saem do escopo ou explicitamente são excluídas da memória.  

  
 Essa classe não apresenta nenhuma métodos adicionais em sua classe base. Consulte [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md) e [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) para obter mais informações sobre classes auxiliares de seção crítica.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)  
  
 [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md)  
  
 `CComAutoDeleteCriticalSection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md)   
 [Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

