---
title: Classe CComAutoCriticalSection | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComAutoCriticalSection
- ATLCORE/ATL::CComAutoCriticalSection
- ATLCORE/ATL::CComAutoCriticalSection::CComAutoCriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CComAutoCriticalSection class
ms.assetid: 491a9d90-3398-4f90-88f5-fd2172a46b30
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ae0c3cd1d00ce83a4e952d60a978663bfa76f814
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32357223"
---
# <a name="ccomautocriticalsection-class"></a>Classe CComAutoCriticalSection
`CComAutoCriticalSection` fornece métodos para a obtenção e liberar a propriedade de um objeto de seção crítica.  
  
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
 `CComAutoCriticalSection` é semelhante à classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md), exceto `CComAutoCriticalSection` automaticamente inicializa o objeto de seção crítica no construtor.  
  
 Normalmente, você usa `CComAutoCriticalSection` por meio de `typedef` nome [AutoCriticalSection](ccommultithreadmodel-class.md#autocriticalsection). Faz referência a esse nome `CComAutoCriticalSection` quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.  

  
 O `Init` e `Term` métodos de [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) não estão disponíveis ao usar essa classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)  
  
 `CComAutoCriticalSection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="ccomautocriticalsection"></a>  CComAutoCriticalSection::CComAutoCriticalSection  
 O construtor.  
  
```
CComAutoCriticalSection();
```  
  
### <a name="remarks"></a>Comentários  
 Chama a função Win32 [InitializeCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms683472), que inicializa o objeto de seção crítica.  
  
##  <a name="dtor"></a>  CComAutoCriticalSection:: ~ CComAutoCriticalSection  
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
