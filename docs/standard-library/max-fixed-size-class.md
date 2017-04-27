---
title: Classe max_fixed_size | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::max_fixed_size
- max_fixed_size
- stdext::max_fixed_size
- allocators/stdext::max_fixed_size::allocated
- allocators/stdext::max_fixed_size::deallocated
- allocators/stdext::max_fixed_size::full
- allocators/stdext::max_fixed_size::released
- allocators/stdext::max_fixed_size::saved
dev_langs:
- C++
helpviewer_keywords:
- max_fixed_size class
ms.assetid: 8c8f4588-37e9-4579-8168-ba3553800914
caps.latest.revision: 18
author: corob-msft
ms.author: corob
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c1d83d147fc163a8747a68baff16b1fa1401902b
ms.lasthandoff: 02/25/2017

---
# <a name="maxfixedsize-class"></a>Classe max_fixed_size
Descreve um objeto da [classe max](../standard-library/allocators-header.md) que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo fixo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <std::size_t Max>  
class max_fixed_size
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Max`|A classe max que determina o número máximo de elementos para armazenar no `freelist`.|  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[max_fixed_size](#max_fixed_size__max_fixed_size)|Constrói um objeto do tipo `max_fixed_size`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocated](#max_fixed_size__allocated)|Aumenta a contagem de blocos de memória alocada.|  
|[deallocated](#max_fixed_size__deallocated)|Diminui a contagem de blocos de memória alocada.|  
|[full](#max_fixed_size__full)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|  
|[released](#max_fixed_size__released)|Diminui a contagem de blocos de memória na lista livre.|  
|[saved](#max_fixed_size__saved)|Aumenta a contagem de blocos de memória na lista livre.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="max_fixed_size__allocated"></a>  max_fixed_size::allocated  
 Aumenta a contagem de blocos de memória alocada.  
  
```
void allocated(std::size_t _Nx = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Nx`|O valor do incremento.|  
  
### <a name="remarks"></a>Comentários  
 A função membro não faz nada. Essa função membro é chamada após cada chamada bem-sucedida por `cache_freelist::allocate` ao operador `new`. O argumento `_Nx` é o número de blocos de memória na parte alocada pelo operador `new`.  
  
##  <a name="max_fixed_size__deallocated"></a>  max_fixed_size::deallocated  
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
  
##  <a name="max_fixed_size__full"></a>  max_fixed_size::full  
 Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.  
  
```
bool full();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se `Max <= _Nblocks`, caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada retornar `true`, `deallocate` colocará o bloco de memória na lista livre, se ele retornar false, `deallocate` chamará o operador `delete` para desalocar o bloco.  
  
##  <a name="max_fixed_size__max_fixed_size"></a>  max_fixed_size::max_fixed_size  
 Constrói um objeto do tipo `max_fixed_size`.  
  
```
max_fixed_size();
```  
  
### <a name="remarks"></a>Comentários  
 Este construtor inicializa o valor armazenado `_Nblocks` como zero.  
  
##  <a name="max_fixed_size__released"></a>  max_fixed_size::released  
 Diminui a contagem de blocos de memória na lista livre.  
  
```
void released();
```  
  
### <a name="remarks"></a>Comentários  
 Diminui o valor armazenado `_Nblocks`. A função membro `released` da [classe max](../standard-library/allocators-header.md) é chamada por `cache_freelist::allocate` sempre que ele remove um bloco de memória da lista livre.  
  
##  <a name="max_fixed_size__saved"></a>  max_fixed_size::saved  
 Aumenta a contagem de blocos de memória na lista livre.  
  
```
void saved();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro aumenta a o valor armazenado `_Nblocks`. Essa função membro é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




