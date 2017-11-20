---
title: Classe CHeapPtr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHeapPtr
- ATLCORE/ATL::CHeapPtr
- ATLCORE/ATL::CHeapPtr::CHeapPtr
- ATLCORE/ATL::CHeapPtr::Allocate
- ATLCORE/ATL::CHeapPtr::Reallocate
dev_langs: C++
helpviewer_keywords: CHeapPtr class
ms.assetid: e5c5bfd4-9bf1-4164-8a83-8155fe253454
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 506dac565ef30c44c553301c6669e416a7dd5f8a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cheapptr-class"></a>Classe CHeapPtr
Uma classe de ponteiro inteligente para o gerenciamento de ponteiros de pilha.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<typename T, class Allocator=CCRTAllocator>  
class CHeapPtr : public CHeapPtrBase<T, Allocator>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo de objeto a ser armazenado no heap.  
  
 `Allocator`  
 A classe de alocação de memória a ser usado.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtr::CHeapPtr](#cheapptr)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtr::Allocate](#allocate)|Chame esse método para alocar memória no heap para armazenar objetos.|  
|[CHeapPtr::Reallocate](#reallocate)|Chame este método para realocar a memória no heap.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeapPtr::operator =](#operator_eq)|O operador de atribuição.|  
  
## <a name="remarks"></a>Comentários  
 `CHeapPtr`é derivado de [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md) e por padrão, usa as rotinas de CRT (em [CCRTAllocator](../../atl/reference/ccrtallocator-class.md)) para alocar e liberar memória. A classe [CHeapPtrList](../../atl/reference/cheapptrlist-class.md) pode ser usado para construir uma lista dos ponteiros de pilha. Consulte também [CComHeapPtr](../../atl/reference/ccomheapptr-class.md), que usa as rotinas de alocação de memória COM.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)  
  
 `CHeapPtr`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="allocate"></a>CHeapPtr::Allocate  
 Chame esse método para alocar memória no heap para armazenar objetos.  
  
```
bool Allocate(size_t nElements = 1) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nElements`  
 O número de elementos usados para calcular a quantidade de memória para alocar. O valor padrão é 1.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a memória foi iniciado com êxito alocados false em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 As rotinas de alocador são usadas para reservar memória suficiente no heap para armazenar *nElement* objetos de um tipo definido no construtor.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#77](../../atl/codesnippet/cpp/cheapptr-class_1.cpp)]  
  
##  <a name="cheapptr"></a>CHeapPtr::CHeapPtr  
 O construtor.  
  
```
CHeapPtr() throw();
explicit CHeapPtr(T* p) throw();
CHeapPtr(CHeapPtr<T, Allocator>& p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Um ponteiro de pilha existente ou `CHeapPtr`.  
  
### <a name="remarks"></a>Comentários  
 O ponteiro de pilha, opcionalmente, pode ser criado usando um ponteiro existente, ou um `CHeapPtr` objeto. Nesse caso, o novo `CHeapPtr` objeto assume a responsabilidade de gerenciar os recursos e o ponteiro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#78](../../atl/codesnippet/cpp/cheapptr-class_2.cpp)]  
  
##  <a name="operator_eq"></a>CHeapPtr::operator =  
 Operador de atribuição.  
  
```
CHeapPtr<T, Allocator>& operator=(
    CHeapPtr<T, Allocator>& p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Um objeto `CHeapPtr` existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para a atualização `CHeapPtr`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#80](../../atl/codesnippet/cpp/cheapptr-class_3.cpp)]  
  
##  <a name="reallocate"></a>CHeapPtr::Reallocate  
 Chame este método para realocar a memória no heap.  
  
```
bool Reallocate(size_t nElements) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nElements`  
 O novo número de elementos usados para calcular a quantidade de memória para alocar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a memória foi iniciado com êxito alocados false em caso de falha.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#79](../../atl/codesnippet/cpp/cheapptr-class_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)   
 [Classe CCRTAllocator](../../atl/reference/ccrtallocator-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
