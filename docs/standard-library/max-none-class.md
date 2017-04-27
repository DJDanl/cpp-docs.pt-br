---
title: Classe max_none | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- max_none
- stdext::max_none
- allocators/stdext::max_none
- allocators/stdext::max_none::allocated
- allocators/stdext::max_none::deallocated
- allocators/stdext::max_none::full
- allocators/stdext::max_none::released
- allocators/stdext::max_none::saved
dev_langs:
- C++
helpviewer_keywords:
- max_none class
ms.assetid: 12ab5376-412e-479c-86dc-2c3d6a3559b6
caps.latest.revision: 19
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
ms.openlocfilehash: 522e950aa9f7a33ee6210d3b40effd2a1760daf3
ms.lasthandoff: 02/25/2017

---
# <a name="maxnone-class"></a>Classe max_none
Descreve um objeto da [classe max](../standard-library/allocators-header.md) que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo igual a zero.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <std::size_t Max>  
class max_none
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Max`|A classe max que determina o número máximo de elementos para armazenar no `freelist`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocated](#max_none__allocated)|Aumenta a contagem de blocos de memória alocada.|  
|[deallocated](#max_none__deallocated)|Diminui a contagem de blocos de memória alocada.|  
|[full](#max_none__full)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|  
|[released](#max_none__released)|Diminui a contagem de blocos de memória na lista livre.|  
|[saved](#max_none__saved)|Aumenta a contagem de blocos de memória na lista livre.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="max_none__allocated"></a>  max_none::allocated  
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
  
##  <a name="max_none__deallocated"></a>  max_none::deallocated  
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
  
##  <a name="max_none__full"></a>  max_none::full  
 Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.  
  
```
bool full();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Essa função membro sempre retorna `true`.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada retornar `true`, `deallocate` colocará o bloco de memória na lista livre, se ele retornar false, `deallocate` chamará o operador `delete` para desalocar o bloco.  
  
##  <a name="max_none__released"></a>  max_none::released  
 Diminui a contagem de blocos de memória na lista livre.  
  
```
void released();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro não faz nada. A função membro `released` da classe max é chamada por `cache_freelist::allocate` sempre que ele remove um bloco de memória da lista livre.  
  
##  <a name="max_none__saved"></a>  max_none::saved  
 Aumenta a contagem de blocos de memória na lista livre.  
  
```
void saved();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro não faz nada. Ela é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




