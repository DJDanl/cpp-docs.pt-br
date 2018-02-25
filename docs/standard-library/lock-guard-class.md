---
title: lock_guard Class | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- mutex/std::lock_guard
- mutex/std::lock_guard::lock_guard
dev_langs:
- C++
ms.assetid: 57121f0d-9c50-481c-b971-54e64df864e0
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 60643375742ef02ef1ba8ea08e614d12c504c573
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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
|[lock_guard](#lock_guard)|Constrói um objeto `lock_guard`.|  
|[Destruidor lock_guard::~lock_guard](#dtorlock_guard_destructor)|Desbloqueia o `mutex` que foi passado ao construtor.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<mutex >  
  
 **Namespace:** std  
  
##  <a name="lock_guard"></a>  Construtor lock_guard::lock_guard  
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
  
##  <a name="dtorlock_guard_destructor"></a>  Destruidor lock_guard::~lock_guard  
 Desbloqueia o `mutex` que foi passado ao construtor.  
  
```
~lock_guard() noexcept;
```  
  
### <a name="remarks"></a>Comentários  
 Se o `mutex` não existir quando o destruidor for executado, o comportamento será indefinido.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex>](../standard-library/mutex.md)



