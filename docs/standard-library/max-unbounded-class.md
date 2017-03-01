---
title: Classe max_unbounded | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::max_unbounded
- stdext::max_unbounded
- stdext.max_unbounded
- max_unbounded
dev_langs:
- C++
helpviewer_keywords:
- max_unbounded class
ms.assetid: e34627a9-c231-4031-a483-cbb0514fff46
caps.latest.revision: 18
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
ms.openlocfilehash: 1cb47fd28c9eb099e9c78e4084b74fb6636f5b60
ms.lasthandoff: 02/25/2017

---
# <a name="maxunbounded-class"></a>Classe max_unbounded
Descreve um objeto da [classe max](../standard-library/allocators-header.md) que não limita o comprimento máximo de um objeto [freelist](../standard-library/freelist-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```
class max_unbounded
```  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocated](#max_unbounded__allocated)|Aumenta a contagem de blocos de memória alocada.|  
|[deallocated](#max_unbounded__deallocated)|Diminui a contagem de blocos de memória alocada.|  
|[full](#max_unbounded__full)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|  
|[released](#max_unbounded__released)|Diminui a contagem de blocos de memória na lista livre.|  
|[saved](#max_unbounded__saved)|Aumenta a contagem de blocos de memória na lista livre.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="a-namemaxunboundedallocateda--maxunboundedallocated"></a><a name="max_unbounded__allocated"></a>  max_unbounded::allocated  
 Aumenta a contagem de blocos de memória alocada.  
  
```
void allocated(std::size_t _Nx = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Nx`|O valor do incremento.|  
  
### <a name="remarks"></a>Comentários  
 Essa função membro não faz nada. Ela é chamada após cada chamada bem-sucedida por `cache_freelist::allocate` ao operador `new`. O argumento `_Nx` é o número de blocos de memória na parte alocada pelo operador `new`.  
  
##  <a name="a-namemaxunboundeddeallocateda--maxunboundeddeallocated"></a><a name="max_unbounded__deallocated"></a>  max_unbounded::deallocated  
 Diminui a contagem de blocos de memória alocada.  
  
```
void deallocated(std::size_t _Nx = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Nx`|O valor do incremento.|  
  
### <a name="remarks"></a>Comentários  
 A função membro não faz nada. Essa função membro é chamada após cada chamada por `cache_freelist::deallocate` ao operador `delete`. O argumento `_Nx` é o número de blocos de memória na parte desalocada pelo operador `delete`.  
  
##  <a name="a-namemaxunboundedfulla--maxunboundedfull"></a><a name="max_unbounded__full"></a>  max_unbounded::full  
 Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.  
  
```
bool full();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro sempre retorna `false`.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada retornar `true`, `deallocate` colocará o bloco de memória na lista livre, se ele retornar false, `deallocate` chamará o operador `delete` para desalocar o bloco.  
  
##  <a name="a-namemaxunboundedreleaseda--maxunboundedreleased"></a><a name="max_unbounded__released"></a>  max_unbounded::released  
 Diminui a contagem de blocos de memória na lista livre.  
  
```
void released();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro não faz nada. A função membro `released` da classe max é chamada por `cache_freelist::allocate` sempre que ele remove um bloco de memória da lista livre.  
  
##  <a name="a-namemaxunboundedsaveda--maxunboundedsaved"></a><a name="max_unbounded__saved"></a>  max_unbounded::saved  
 Aumenta a contagem de blocos de memória na lista livre.  
  
```
void saved();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro não faz nada. Ela é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




