---
title: Classe CElementTraits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CElementTraits
- atlcoll/ATL::CElementTraits
dev_langs: C++
helpviewer_keywords: CElementTraits class
ms.assetid: 496528e5-7f80-4b45-be0c-6f646feb43c5
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cda18f6148f9a1cbc39a6e7003cce6324e36eeeb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="celementtraits-class"></a>Classe CElementTraits
Essa classe é usada pelas classes de coleção para fornecer funções e métodos para mover, copiar, comparação e operações de hash.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>  
class CElementTraits : public CDefaultElementTraits<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece métodos e funções estáticas padrão para mover, copiar, comparando e armazenados em um objeto de classe de coleção de elementos de hash. `CElementTraits`é especificado como o provedor padrão dessas operações pelas classes de coleção [CAtlArray](../../atl/reference/catlarray-class.md), [CAtlList](../../atl/reference/catllist-class.md), [CRBMap](../../atl/reference/crbmap-class.md), [CRBMultiMap](../../atl/reference/crbmultimap-class.md), e [CRBTree](../../atl/reference/crbtree-class.md).  
  
 As implementações padrão serão suficiente para tipos de dados simples, mas se as classes de coleção são usadas para armazenar objetos mais complexos, as funções e os métodos devem ser substituídos por implementações fornecido pelo usuário.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
