---
title: Classe CAutoPtrList | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAutoPtrList
- ATLCOLL/ATL::CAutoPtrList
- ATLCOLL/ATL::CAutoPtrList::CAutoPtrList
dev_langs: C++
helpviewer_keywords: CAutoPtrList class
ms.assetid: 11de4aca-28b0-4ff2-a74a-cb602312ffbd
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 79ca570b8f4534287ae4ec40167de3bc3d947139
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cautoptrlist-class"></a>Classe CAutoPtrList
Essa classe fornece métodos úteis ao construir uma lista de ponteiros inteligentes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename E>  
class CAutoPtrList : 
   public CAtlList<ATL::CAutoPtr<E>, CAutoPtrElementTraits<E>>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `E`  
 O tipo de ponteiro.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoPtrList::CAutoPtrList](#cautoptrlist)|O construtor.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece um construtor e deriva de métodos de [CAtlList](../../atl/reference/catllist-class.md) e [CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md) para facilitar a criação de um objeto de lista armazenar ponteiros inteligentes. A classe [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) fornece uma função semelhante para um objeto de matriz.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CAtlList](../../atl/reference/catllist-class.md)  
  
 `CAutoPtrList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="cautoptrlist"></a>CAutoPtrList::CAutoPtrList  
 O construtor.  
  
```
CAutoPtrList(UINT nBlockSize = 10) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBlockSize`  
 O tamanho do bloco, com um padrão de 10.  
  
### <a name="remarks"></a>Comentários  
 O tamanho do bloco é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de bloco maiores reduzem as chamadas para rotinas de alocação de memória, mas usam mais recursos.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlList](../../atl/reference/catllist-class.md)   
 [Classe CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
