---
title: cache_chunklist Class | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::cache_chunklist
- allocators/stdext::cache_chunklist::allocate
- allocators/stdext::cache_chunklist::deallocate
dev_langs:
- C++
helpviewer_keywords:
- stdext::cache_chunklist
- stdext::cache_chunklist [C++], allocate
- stdext::cache_chunklist [C++], deallocate
ms.assetid: af19eccc-4ae7-4a34-bbb2-81e397424cb9
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: 3d8047844a96cf80e64ab7aae5d1e7d9f4a85474
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="cachechunklist-class"></a>Classe cache_chunklist
Define um [alocador de blocos](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <std::size_t Sz, std::size_t Nelts = 20>  
class cache_chunklist
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Sz`|O número de elementos na matriz a serem alocados.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de modelo usa `operator new` para alocar partes de memória bruta, subalocando blocos para alocar armazenamento para um bloco de memória quando necessário; ela armazena os blocos de memória desalocados em uma lista livre separada para cada parte e usar `operator delete` para desalocar uma parte quando nenhum dos seus blocos de memória está em uso.  
  
 Cada bloco de memória contém `Sz` bytes de memória utilizável e um ponteiro para a parte à qual pertence. Cada parte contém `Nelts` blocos de memória, três ponteiros, int e os dados que `operator new` e `operator delete` exigem.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[cache_chunklist](#cache_chunklist)|Constrói um objeto do tipo `cache_chunklist`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocate](#allocate)|Aloca um bloco de memória.|  
|[deallocate](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="allocate"></a>  cache_chunklist::allocate  
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
  
##  <a name="cache_chunklist"></a>  cache_chunklist::cache_chunklist  
 Constrói um objeto do tipo `cache_chunklist`.  
  
```
cache_chunklist();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="deallocate"></a>  cache_chunklist::deallocate  
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




