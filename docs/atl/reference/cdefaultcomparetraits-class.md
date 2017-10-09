---
title: Classe CDefaultCompareTraits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDefaultCompareTraits
- ATLCOLL/ATL::CDefaultCompareTraits
- ATLCOLL/ATL::CDefaultCompareTraits::CompareElements
- ATLCOLL/ATL::CDefaultCompareTraits::CompareElementsOrdered
dev_langs:
- C++
helpviewer_keywords:
- CDefaultCompareTraits class
ms.assetid: a17e2740-e7b4-48f2-aeb7-c80ce84b63f7
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: c55726a1728185f699afbac4ba68a6dc0f70c2bf
ms.openlocfilehash: 410d34d59da33b6d929abbe2af0798a6cf46238b
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="cdefaultcomparetraits-class"></a>Classe CDefaultCompareTraits
Essa classe fornece funções de comparação de elemento de padrão.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T>  
class CDefaultCompareTraits
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDefaultCompareTraits::CompareElements](#compareelements)|(Estático) Chame essa função para comparar dois elementos de igualdade.|  
|[CDefaultCompareTraits::CompareElementsOrdered](#compareelementsordered)|(Estático) Chame essa função para determinar o elemento superior e inferior.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe contém duas funções estáticas para comparar armazenados em um objeto de classe de coleção de elementos. Essa classe é utilizada pelo [CDefaultElementTraits classe](../../atl/reference/cdefaultelementtraits-class.md).  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="compareelements"></a>CDefaultCompareTraits::CompareElements  
 Chame essa função para comparar dois elementos de igualdade.  
  
```
static bool CompareElements(const T& element1, const T& element2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `element1`  
 O primeiro elemento.  
  
 `element2`  
 O segundo elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se os elementos forem iguais; caso contrário, false.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função é a igualdade ( `==`) operador. Para objetos diferentes tipos de dados simples, essa função pode precisar ser substituído.  
  
##  <a name="compareelementsordered"></a>CDefaultCompareTraits::CompareElementsOrdered  
 Chame essa função para determinar o elemento superior e inferior.  
  
```
static int CompareElementsOrdered(const T& element1, const T& element2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `element1`  
 O primeiro elemento.  
  
 `element2`  
 O segundo elemento.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um inteiro com base na tabela a seguir:  
  
|Condição|Valor retornado|  
|---------------|------------------|  
|`element1` < `element2`|<0|  
|`element1` == `element2`|0|  
|`element1` > `element2`|>0|  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função usa o `==`,  **\<** , e  **>**  operadores. Para objetos diferentes tipos de dados simples, essa função pode precisar ser substituído.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

