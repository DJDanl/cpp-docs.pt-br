---
title: Classe CInterfaceArray | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CInterfaceArray
- ATLCOLL/ATL::CInterfaceArray
- ATLCOLL/ATL::CInterfaceArray::CInterfaceArray
dev_langs:
- C++
helpviewer_keywords:
- CInterfaceArray class
ms.assetid: 1f29cf66-a086-4a7b-b6a8-64f73da39f79
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c33e0783acfba1b460894ac8f5dde80e61780762
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37882701"
---
# <a name="cinterfacearray-class"></a>Classe CInterfaceArray
Essa classe fornece métodos úteis ao construir uma matriz de ponteiros de interface COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class I, const IID* piid=& __uuidof(I)>  
class CInterfaceArray : 
   public CAtlArray<ATL::CComQIPtr<I, piid>,
                    CComQIPtrElementTraits<I, piid>>
```  
  
#### <a name="parameters"></a>Parâmetros  
 *I*  
 Uma interface COM especificando o tipo de ponteiro a ser armazenado.  
  
 *piid*  
 Um ponteiro para o IID da *eu*.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInterfaceArray::CInterfaceArray](#cinterfacearray)|O construtor para a matriz de interface.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe fornece um construtor e métodos derivados para criar uma matriz de ponteiros de interface COM. Use [CInterfaceList](../../atl/reference/cinterfacelist-class.md) quando uma lista é necessária.  
  
 Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CAtlArray`  
  
 `CInterfaceArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcoll.h  
  
##  <a name="cinterfacearray"></a>  CInterfaceArray::CInterfaceArray  
 O construtor.  
  
```
CInterfaceArray() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa a matriz de ponteiro inteligente.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CAtlArray](../../atl/reference/catlarray-class.md)   
 [Classe CComQIPtr](../../atl/reference/ccomqiptr-class.md)   
 [Classe CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
