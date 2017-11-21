---
title: cache_suballoc Class | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::cache_suballoc
- allocators/stdext::cache_suballoc::allocate
- allocators/stdext::cache_suballoc::deallocate
dev_langs: C++
helpviewer_keywords:
- stdext::cache_suballoc
- stdext::cache_suballoc [C++], allocate
- stdext::cache_suballoc [C++], deallocate
ms.assetid: 9ea9c5e9-1dcc-45d0-b3a7-a56a93d88898
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f835efbe84b05359a9a835f3afbdccf5839fc31c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
|[cache_suballoc](#cache_suballoc)|Constrói um objeto do tipo `cache_suballoc`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocate](#allocate)|Aloca um bloco de memória.|  
|[deallocate](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="allocate"></a>  cache_suballoc::allocate  
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
  
##  <a name="cache_suballoc"></a>  cache_suballoc::cache_suballoc  
 Constrói um objeto do tipo `cache_suballoc`.  
  
```
cache_suballoc();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="deallocate"></a>  cache_suballoc::deallocate  
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



