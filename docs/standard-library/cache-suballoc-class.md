---
title: cache_suballoc Class | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::cache_suballoc
- stdext::cache_suballoc
- cache_suballoc
- allocators/stdext::cache_suballoc::allocate
- allocators/stdext::cache_suballoc::deallocate
dev_langs:
- C++
helpviewer_keywords:
- cache_suballoc class
ms.assetid: 9ea9c5e9-1dcc-45d0-b3a7-a56a93d88898
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 537930868e47fd1e947a99ff808d870532c38c58
ms.lasthandoff: 02/25/2017

---
# <a name="cachesuballoc-class"></a>Classe cache_suballoc
Define um [alocador de blocos](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <std::size_t Sz, size_t Nelts = 20>  
class cache_suballoc
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Sz`|O número de elementos na matriz a serem alocados.|  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo cache_suballoc armazena blocos de memória desalocados em uma lista livre com comprimento ilimitado, usando `freelist<sizeof(Type), max_unbounded>` e subaloca blocos de memória de uma parte maior alocada com `operator new` quando a lista livre está vazia.  
  
 Cada parte contém `Sz * Nelts` bytes de memória utilizável e os dados que `operator new` e `operator delete` requerem. Partes alocadas nunca são liberadas.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[cache_suballoc](#cache_suballoc__cache_suballoc)|Constrói um objeto do tipo `cache_suballoc`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocate](#cache_suballoc__allocate)|Aloca um bloco de memória.|  
|[deallocate](#cache_suballoc__deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="cache_suballoc__allocate"></a>  cache_suballoc::allocate  
 Aloca um bloco de memória.  
  
```
void *allocate(std::size_t count);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`count`|O número de elementos na matriz a serem alocados.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto alocado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cache_suballoc__cache_suballoc"></a>  cache_suballoc::cache_suballoc  
 Constrói um objeto do tipo `cache_suballoc`.  
  
```
cache_suballoc();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cache_suballoc__deallocate"></a>  cache_suballoc::deallocate  
 Libera um número especificado de objetos do armazenamento começando em uma posição especificada.  
  
```
void deallocate(void* ptr, std::size_t count);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`ptr`|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|  
|`count`|O número de objetos a serem desalocados do armazenamento.|  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




