---
title: Classe CComAutoCriticalSection | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CComAutoCriticalSection
- ATL::CComAutoCriticalSection
- CComAutoCriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CComAutoCriticalSection class
ms.assetid: 491a9d90-3398-4f90-88f5-fd2172a46b30
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
ms.sourcegitcommit: 050e7483670bd32f633660ba44491c8bb3fc462d
ms.openlocfilehash: 9f58a4cfd02af09a05b625a7e02b574b672adade
ms.lasthandoff: 02/25/2017

---
# <a name="ccomautocriticalsection-class"></a>Classe CComAutoCriticalSection
`CComAutoCriticalSection`fornece métodos para a obtenção e liberar a propriedade de um objeto da seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComAutoCriticalSection : public CComCriticalSection
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComAutoCriticalSection::CComAutoCriticalSection](#ccomautocriticalsection)|O construtor.|  
|[CComAutoCriticalSection:: ~ CComAutoCriticalSection](#dtor)|O destruidor.|  
  
## <a name="remarks"></a>Comentários  
 `CComAutoCriticalSection`é semelhante à classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md), exceto `CComAutoCriticalSection` automaticamente inicializa o objeto da seção crítica no construtor.  
  
 Normalmente, você usa `CComAutoCriticalSection` por meio de `typedef` nome [AutoCriticalSection](ccommultithreadmodel-class.md#autocriticalsection). Esse nome faz referência `CComAutoCriticalSection` quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.  

  
 O `Init` e `Term` métodos de [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) não estão disponíveis ao usar essa classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)  
  
 `CComAutoCriticalSection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="a-nameccomautocriticalsectiona--ccomautocriticalsectionccomautocriticalsection"></a><a name="ccomautocriticalsection"></a>CComAutoCriticalSection::CComAutoCriticalSection  
 O construtor.  
  
```
CComAutoCriticalSection();
```  
  
### <a name="remarks"></a>Comentários  
 Chama a função Win32 [InitializeCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms683472), que inicializa o objeto da seção crítica.  
  
##  <a name="a-namedtora--ccomautocriticalsectionccomautocriticalsection"></a><a name="dtor"></a>CComAutoCriticalSection:: ~ CComAutoCriticalSection  
 O destruidor.  
  
```
~CComAutoCriticalSection() throw();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de destruidor [DeleteCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms682552), que libera todos os recursos do sistema usados pelo objeto de seção crítica.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)

