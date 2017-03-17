---
title: Classe CAutoPtrArray | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAutoPtrArray
- ATLCOLL/ATL::CAutoPtrArray
- ATLCOLL/ATL::CAutoPtrArray::CAutoPtrArray
dev_langs:
- C++
helpviewer_keywords:
- CAutoPtrArray class
ms.assetid: 880a70da-8c81-4427-8ac6-49aa8d424244
caps.latest.revision: 21
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 58ee329c7a3925fe3a29cf9738670cfa71df6777
ms.lasthandoff: 02/25/2017

---
# <a name="cautoptrarray-class"></a>Classe CAutoPtrArray
Essa classe fornece métodos úteis ao construir uma matriz de ponteiros inteligentes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <typename E>
class CAutoPtrArray : public CAtlArray<
                        ATL::CAutoPtr<E>,
                        CAutoPtrElementTraits<E>>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `E`  
 O tipo de ponteiro.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAutoPtrArray::CAutoPtrArray](#cautoptrarray)|O construtor.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece um construtor e deriva de métodos de [CAtlArray](../../atl/reference/catlarray-class.md) e [CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md) para ajudar na criação de um objeto de classe de coleção armazenar ponteiros inteligentes.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CAtlArray`  
  
 `CAutoPtrArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="cautoptrarray"></a>CAutoPtrArray::CAutoPtrArray  
 O construtor.  
  
```
CAutoPtrArray() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa a matriz de ponteiro inteligente.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlArray](../../atl/reference/catlarray-class.md)   
 [Classe CAutoPtrElementTraits](../../atl/reference/cautoptrelementtraits-class.md)   
 [Classe CAutoPtrList](../../atl/reference/cautoptrlist-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

