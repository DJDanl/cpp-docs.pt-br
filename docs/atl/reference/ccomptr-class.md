---
title: Classe CComPtr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComPtr
- ATLBASE/ATL::CComPtr
- ATLBASE/ATL::CComPtr::CComPtr
dev_langs:
- C++
helpviewer_keywords:
- CComPtr class
ms.assetid: 22d9ea8d-ed66-4c34-940f-141db11e83bd
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4ef8c49b04a769fd6202aa58324f20216948cf3a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccomptr-class"></a>Classe CComPtr
Uma classe de ponteiro inteligente para o gerenciamento de ponteiros de interface COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class CComPtr
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma interface COM especificando o tipo de ponteiro para ser armazenado.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtr::CComPtr](#ccomptr)|O construtor.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPtr::operator =](#operator_eq)|Atribui um ponteiro para o ponteiro de membro.|  
  
## <a name="remarks"></a>Comentários  
 ATL usa `CComPtr` e [CComQIPtr](../../atl/reference/ccomqiptr-class.md) para gerenciar os ponteiros de interface COM. Ambos são derivadas de [CComPtrBase](../../atl/reference/ccomptrbase-class.md), e ambos executam a contagem de referência automática.  
  
 O **CComPtr** e [CComQIPtr](../../atl/reference/ccomqiptr-class.md) classes podem ajudar a eliminar vazamentos de memória, executando a contagem de referência automática.  As seguintes funções de executam as mesmas operações lógicas; No entanto, observe como a segunda versão pode ser menos propensas a erros usando o **CComPtr** classe:  
  
 [!code-cpp[NVC_ATL_Utilities#130](../../atl/codesnippet/cpp/ccomptr-class_1.cpp)]  
  
 [!code-cpp[NVC_ATL_Utilities#131](../../atl/codesnippet/cpp/ccomptr-class_2.cpp)]  
  
 Em compilações de depuração, vincule atlsd.lib para rastreamento de código.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CComPtrBase](../../atl/reference/ccomptrbase-class.md)  
  
 `CComPtr`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="ccomptr"></a>CComPtr::CComPtr  
 O construtor.  
  
```
CComPtr() throw ();
CComPtr(T* lp) throw ();
CComPtr (const CComPtr<T>& lp) throw ();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lp`  
 Usado para inicializar o ponteiro de interface.  
  
 `T`  
 Uma interface COM.  
  
##  <a name="operator_eq"></a>CComPtr::operator =  
 Operador de atribuição.  
  
```
T* operator= (T* lp) throw ();
T* operator= (const CComPtr<T>& lp) throw ();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a atualização `CComPtr` objeto  
  
### <a name="remarks"></a>Comentários  
 Esta operação AddRefs o novo objeto e versões existe o objeto existente, se houver um.  
  
## <a name="see-also"></a>Consulte também  
 [CComPtr::CComPtr](#ccomptr)   
 [CComQIPtr::CComQIPtr](../../atl/reference/ccomqiptr-class.md#ccomqiptr)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
