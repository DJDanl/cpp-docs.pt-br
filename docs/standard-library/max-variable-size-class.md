---
title: Classe max_variable_size | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- stdext::max_variable_size
- allocators/stdext::max_variable_size
- max_variable_size
- allocators/stdext::max_variable_size::allocated
- allocators/stdext::max_variable_size::deallocated
- allocators/stdext::max_variable_size::full
- allocators/stdext::max_variable_size::released
- allocators/stdext::max_variable_size::saved
dev_langs:
- C++
helpviewer_keywords:
- max_variable_size class
ms.assetid: 9f2e9df0-4148-4b37-bc30-f8eca0ef86ae
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
ms.openlocfilehash: ae85871df47edee3f3504653229a12d0867d2fee
ms.lasthandoff: 02/25/2017

---
# <a name="maxvariablesize-class"></a>Classe max_variable_size
Descreve um objeto da [classe max](../standard-library/allocators-header.md) que limita um objeto [freelist](../standard-library/freelist-class.md) a um comprimento máximo aproximadamente proporcional ao número de blocos de memória alocados.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class max_variable_size
```  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[max_variable_size](#max_variable_size__max_variable_size)|Constrói um objeto do tipo `max_variable_size`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocated](#max_variable_size__allocated)|Aumenta a contagem de blocos de memória alocada.|  
|[deallocated](#max_variable_size__deallocated)|Diminui a contagem de blocos de memória alocada.|  
|[full](#max_variable_size__full)|Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.|  
|[released](#max_variable_size__released)|Diminui a contagem de blocos de memória na lista livre.|  
|[saved](#max_variable_size__saved)|Aumenta a contagem de blocos de memória na lista livre.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="max_variable_size__allocated"></a>  max_variable_size::allocated  
 Aumenta a contagem de blocos de memória alocada.  
  
```
void allocated(std::size_t _Nx = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Nx`|O valor do incremento.|  
  
### <a name="remarks"></a>Comentários  
 Essa função membro adiciona `_Nx` ao valor armazenado `_Nallocs`. Essa função membro é chamada após cada chamada bem-sucedida por `cache_freelist::allocate` ao operador `new`. O argumento `_Nx` é o número de blocos de memória na parte alocada pelo operador `new`.  
  
##  <a name="max_variable_size__deallocated"></a>  max_variable_size::deallocated  
 Diminui a contagem de blocos de memória alocada.  
  
```
void deallocated(std::size_t _Nx = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Nx`|O valor do incremento.|  
  
### <a name="remarks"></a>Comentários  
 A função membro subtrai `_Nx` do valor armazenado `_Nallocs`. Essa função membro é chamada após cada chamada por `cache_freelist::deallocate` ao operador `delete`. O argumento `_Nx` é o número de blocos de memória na parte desalocada pelo operador `delete`.  
  
##  <a name="max_variable_size__full"></a>  max_variable_size::full  
 Retorna um valor que especifica se mais blocos de memória devem ser adicionados à lista livre.  
  
```
bool full();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se `_Nallocs / 16 + 16 <= _Nblocks`.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro é chamada por `cache_freelist::deallocate`. Se a chamada retornar `true`, `deallocate` colocará o bloco de memória na lista livre, se ele retornar false, `deallocate` chamará o operador `delete` para desalocar o bloco.  
  
##  <a name="max_variable_size__max_variable_size"></a>  max_variable_size::max_variable_size  
 Constrói um objeto do tipo `max_variable_size`.  
  
```
max_variable_size();
```  
  
### <a name="remarks"></a>Comentários  
 O construtor inicializa os valores armazenados `_Nblocks` e `_Nallocs` como zero.  
  
##  <a name="max_variable_size__released"></a>  max_variable_size::released  
 Diminui a contagem de blocos de memória na lista livre.  
  
```
void released();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro diminui a o valor armazenado `_Nblocks`. A função membro `released` da classe max é chamada por `cache_freelist::allocate` sempre que ele remove um bloco de memória da lista livre.  
  
##  <a name="max_variable_size__saved"></a>  max_variable_size::saved  
 Aumenta a contagem de blocos de memória na lista livre.  
  
```
void saved();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro aumenta a o valor armazenado `_Nblocks`. Essa função membro é chamada pelo `cache_freelist::deallocate` sempre que ele coloca um bloco de memória na lista livre.  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




