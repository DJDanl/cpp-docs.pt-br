---
title: lock_guard Class | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- mutex/std::lock_guard
dev_langs:
- C++
ms.assetid: 57121f0d-9c50-481c-b971-54e64df864e0
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: a280edb8c2b2cadccd6767046904723888ee67fa
ms.lasthandoff: 02/25/2017

---
# <a name="lockguard-class"></a>Classe lock_guard
Representa um modelo que pode ser instanciado para criar um objeto cujo destruidor desbloqueia um `mutex`.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Mutex>
class lock_guard;
```  
  
## <a name="remarks"></a>Comentários  
 O argumento de modelo `Mutex` deve nomear um *tipo mutex*.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`lock_guard::mutex_type`|Sinônimo para o argumento de modelo `Mutex`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor lock_guard::lock_guard](#lock_guard__lock_guard_constructor)|Constrói um objeto `lock_guard`.|  
|[Destruidor lock_guard::~lock_guard](#lock_guard___dtorlock_guard_destructor)|Desbloqueia o `mutex` que foi passado ao construtor.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** mutex  
  
 **Namespace:** std  
  
##  <a name="a-namelockguardlockguardconstructora--lockguardlockguard-constructor"></a><a name="lock_guard__lock_guard_constructor"></a>  Construtor lock_guard::lock_guard  
 Constrói um objeto `lock_guard`.  
  
```cpp  
explicit lock_guard(mutex_type& Mtx);

lock_guard(mutex_type& Mtx, adopt_lock_t);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Mtx`  
 Um objeto do *tipo mutex*.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor constrói um objeto do tipo `lock_guard` e bloqueia `Mtx`. Se `Mtx` não for um mutex recursivo, deve ser desbloqueado quando esse construtor for chamado.  
  
 O segundo construtor não bloqueia `Mtx`. `Mtx` deve ser bloqueado quando esse construtor for chamado. O construtor não lança exceções.  
  
##  <a name="a-namelockguarddtorlockguarddestructora--lockguardlockguard-destructor"></a><a name="lock_guard___dtorlock_guard_destructor"></a>  Destruidor lock_guard::~lock_guard  
 Desbloqueia o `mutex` que foi passado ao construtor.  
  
```
~lock_guard() noexcept;
```  
  
### <a name="remarks"></a>Comentários  
 Se o `mutex` não existir quando o destruidor for executado, o comportamento será indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex>](../standard-library/mutex.md)




