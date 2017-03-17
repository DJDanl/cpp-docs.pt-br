---
title: Classe CComQIPtr | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComQIPtr
- ATLCOMCLI/ATL::CComQIPtr
- ATLCOMCLI/ATL::CComQIPtr::CComQIPtr
dev_langs:
- C++
helpviewer_keywords:
- CComQIPtr class
ms.assetid: 969cacb5-05b6-4af4-b683-24911d70242d
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: e2060a0be3f9780191c316c2df41115e66033d4d
ms.lasthandoff: 02/25/2017

---
# <a name="ccomqiptr-class"></a>Classe CComQIPtr
Uma classe de ponteiro inteligente para gerenciar os ponteiros de interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T, const IID* piid= &__uuidof(T)>  
class CComQIPtr: public CComPtr<T>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma interface COM especificando o tipo de ponteiro a ser armazenado.  
  
 `piid`  
 Um ponteiro para o IID da `T`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComQIPtr::CComQIPtr](#ccomqiptr)|Construtor.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComQIPtr::operator =](#operator_eq)|Atribui um ponteiro para o ponteiro de membro.|  
  
## <a name="remarks"></a>Comentários  
 ATL usa `CComQIPtr` e [CComPtr](../../atl/reference/ccomptr-class.md) para gerenciar os ponteiros de interface, que derivam de [CComPtrBase](../../atl/reference/ccomptrbase-class.md). Ambas as classes executam por meio de chamadas de contagem de referência automática `AddRef` e **versão**. Operadores sobrecarregados lidar com operações de ponteiro.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CComPtrBase](../../atl/reference/ccomptrbase-class.md)  
  
 [CComPtr](../../atl/reference/ccomptr-class.md)  
  
 `CComQIPtr`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcomcli. h  
  
##  <a name="ccomqiptr"></a>CComQIPtr::CComQIPtr  
 O construtor.  
  
```
CComQIPtr() throw();
CComQIPtr(T* lp) throw();
CComQIPtr(IUnknown* lp) throw();
CComQIPtr(const CComQIPtr<T, piid>& lp) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lp`  
 Usado para inicializar o ponteiro de interface.  
  
 `T`  
 Uma interface COM.  
  
 `piid`  
 Um ponteiro para o IID da `T`.  
  
##  <a name="operator_eq"></a>CComQIPtr::operator =  
 O operador de atribuição.  
  
```
T* operator= (T* lp) throw();
T* operator= (const CComQIPtr<T, piid>& lp) throw();
T* operator= (IUnknown* lp) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lp`  
 Usado para inicializar o ponteiro de interface.  
  
 `T`  
 Uma interface COM.  
  
 `piid`  
 Um ponteiro para o IID da `T`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a atualização `CComQIPtr` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [CComPtr::CComPtr](../../atl/reference/ccomptr-class.md#ccomptr)   
 [CComQIPtr::CComQIPtr](#ccomqiptr)   
 [Classe CComPtrBase](../../atl/reference/ccomptrbase-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CComQIPtrElementTraits](../../atl/reference/ccomqiptrelementtraits-class.md)

