---
title: Classe CComAutoCriticalSection | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComAutoCriticalSection
- ATLCORE/ATL::CComAutoCriticalSection
- ATLCORE/ATL::CComAutoCriticalSection::CComAutoCriticalSection
dev_langs: C++
helpviewer_keywords: CComAutoCriticalSection class
ms.assetid: 491a9d90-3398-4f90-88f5-fd2172a46b30
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d12abfceeebeb1cac89b510c14d7a9211173406e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccomautocriticalsection-class"></a>Classe CComAutoCriticalSection
`CComAutoCriticalSection`fornece métodos para a obtenção e liberar a propriedade de um objeto de seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComAutoCriticalSection : public CComCriticalSection
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComAutoCriticalSection::CComAutoCriticalSection](#ccomautocriticalsection)|O construtor.|  
|[CComAutoCriticalSection:: ~ CComAutoCriticalSection](#dtor)|O destruidor.|  
  
## <a name="remarks"></a>Comentários  
 `CComAutoCriticalSection`é semelhante à classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md), exceto `CComAutoCriticalSection` automaticamente inicializa o objeto de seção crítica no construtor.  
  
 Normalmente, você usa `CComAutoCriticalSection` por meio de `typedef` nome [AutoCriticalSection](ccommultithreadmodel-class.md#autocriticalsection). Faz referência a esse nome `CComAutoCriticalSection` quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.  

  
 O `Init` e `Term` métodos de [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) não estão disponíveis ao usar essa classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)  
  
 `CComAutoCriticalSection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="ccomautocriticalsection"></a>CComAutoCriticalSection::CComAutoCriticalSection  
 O construtor.  
  
```
CComAutoCriticalSection();
```  
  
### <a name="remarks"></a>Comentários  
 Chama a função Win32 [InitializeCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms683472), que inicializa o objeto de seção crítica.  
  
##  <a name="dtor"></a>CComAutoCriticalSection:: ~ CComAutoCriticalSection  
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
