---
title: Classe CInterfaceList | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CInterfaceList
- ATLCOLL/ATL::CInterfaceList
- ATLCOLL/ATL::CInterfaceList::CInterfaceList
dev_langs: C++
helpviewer_keywords: CInterfaceList class
ms.assetid: 2077764d-25e5-4b3d-96c8-08a287bbcd25
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 86e92f86896ac7c5a06b73a68e2d6889d10ea87b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cinterfacelist-class"></a>Classe CInterfaceList
Essa classe fornece métodos úteis ao construir uma lista de ponteiros de interface COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class I, const IID* piid =& __uuidof(I)>  
class CInterfaceList 
   : public CAtlList<ATL::CComQIPtr<I, piid>,
                     CComQIPtrElementTraits<I, piid>>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `I`  
 Uma interface COM especificando o tipo de ponteiro para ser armazenado.  
  
 `piid`  
 Um ponteiro para o IID da `I`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInterfaceList::CInterfaceList](#cinterfacelist)|O construtor para a lista de interfaces.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece um construtor e métodos derivados para criar uma lista de ponteiros de interface COM. Use [CInterfaceArray](../../atl/reference/cinterfacearray-class.md) quando uma matriz é necessária.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CAtlList](../../atl/reference/catllist-class.md)  
  
 `CInterfaceList`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="cinterfacelist"></a>CInterfaceList::CInterfaceList  
 O construtor para a lista de interfaces.  
  
```
CInterfaceList(UINT nBlockSize = 10) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBlockSize`  
 O tamanho do bloco, com um padrão de 10.  
  
### <a name="remarks"></a>Comentários  
 O tamanho do bloco é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de bloco maiores reduzem as chamadas para rotinas de alocação de memória, mas usam mais recursos.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlList](../../atl/reference/catllist-class.md)   
 [Classe CComQIPtr](../../atl/reference/ccomqiptr-class.md)   
 [Classe CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
