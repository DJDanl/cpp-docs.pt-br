---
title: Classe CDefaultHashTraits | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDefaultHashTraits
- ATLCOLL/ATL::CDefaultHashTraits
- ATLCOLL/ATL::CDefaultHashTraits::Hash
dev_langs:
- C++
helpviewer_keywords:
- CDefaultHashTraits class
ms.assetid: d8ec4b37-6d58-447b-a0c1-8580c5b1ab85
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 5191327e5e60935829750c7d1e04ba89fcddc771
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cdefaulthashtraits-class"></a>Classe CDefaultHashTraits
Essa classe fornece uma função estática para calcular valores de hash.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>  
class CDefaultHashTraits
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDefaultHashTraits::Hash](#hash)|(Estático) Chame essa função para calcular um valor de hash para um determinado elemento.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe contém uma única função estática que retorna um valor de hash para um determinado elemento. Essa classe é utilizada pelo [CDefaultElementTraits classe](../../atl/reference/cdefaultelementtraits-class.md).  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="hash"></a>CDefaultHashTraits::Hash  
 Chame essa função para calcular um valor de hash para um determinado elemento.  
  
```
static ULONG Hash(const T& element) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `element`  
 O elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de hash.  
  
### <a name="remarks"></a>Comentários  
 O algoritmo de hash padrão é muito simple: o valor de retorno é o número do elemento. Substitua essa função se um algoritmo mais complicado é necessário.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

