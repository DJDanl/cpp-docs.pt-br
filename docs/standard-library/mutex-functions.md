---
title: "Funções e variáveis &lt;mutex&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 78ab3c8b-c7db-4226-ac93-e2e78ff8b964
caps.latest.revision: 11
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: a3bb29348b6bf7da235e608a915bcd10391dcac6
ms.lasthandoff: 02/25/2017

---
# <a name="ltmutexgt-functions-and-variables"></a>Funções e variáveis &lt;mutex&gt;
||||  
|-|-|-|  
|[Variável adopt_lock](#adopt_lock_variable)|[Função call_once](#call_once_function)|[Variável defer_lock](#defer_lock_variable)|  
|[Função lock](#lock_function)|[Variável try_to_lock](#try_to_lock_variable)|  
  
##  <a name="a-nameadoptlockvariablea--adoptlock-variable"></a><a name="adopt_lock_variable"></a>  Variável adopt_lock  
 Representa um objeto que pode ser passado para construtores para [lock_guard](../standard-library/lock-guard-class.md) e [unique_lock](../standard-library/unique-lock-class.md) para indicar que o objeto mutex que também está sendo passado para o construtor está bloqueado.  
  
```cpp  
const adopt_lock_t adopt_lock;
```  
  
##  <a name="a-namecalloncefunctiona--callonce"></a><a name="call_once_function"></a>  call_once  
 Fornece um mecanismo para chamar um objeto especificado que pode ser chamado apenas uma vez durante a execução.  
  
```
template <class Callable, class... Args>
void call_once(once_flag& Flag,
    Callable F&&, Args&&... A);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Flag`  
 Um objeto [once_flag](../standard-library/once-flag-structure.md) que garante que o objeto que pode ser chamado seja chamado apenas uma vez.  
  
 `F`  
 Um objeto que pode ser chamado.  
  
 `A`  
 Uma lista de argumentos.  
  
### <a name="remarks"></a>Comentários  
 Se `Flag` não for válido, a função lançará um [system_error](../standard-library/system-error-class.md) com o código de erro `invalid_argument`. Caso contrário, a função de modelo usará seu argumento `Flag` para garantir que chame `F(A...)` com êxito exatamente uma vez, independentemente de quantas vezes o modelo de função for chamado. Se `F(A...)` sai ao lançar uma exceção, a chamada não foi bem-sucedida.  
  
##  <a name="a-namedeferlockvariablea--deferlock-variable"></a><a name="defer_lock_variable"></a>  Variável defer_lock  
 Representa um objeto que pode ser passado para o construtor para [unique_lock](../standard-library/unique-lock-class.md). Isso indica que o construtor não deve bloquear o objeto mutex que também está sendo passado para ele.  
  
```cpp  
const defer_lock_t defer_lock;
```  
  
##  <a name="a-namelockfunctiona--lock"></a><a name="lock_function"></a>  lock  
 Tenta bloquear todos os argumentos sem deadlock.  
  
```cpp  
template <class L1, class L2, class... L3>
void lock(L1&, L2&, L3&...);
```  
  
### <a name="remarks"></a>Comentários  
 Os argumentos para a função de modelo devem ser *tipos mutex*, exceto as chamadas para `try_lock` que podem lançar exceções.  
  
 A função bloqueia todos os argumentos sem deadlock por chamadas para `lock`, `try_lock` e `unlock`. Se uma chamada para `lock` ou `try_lock` lançar uma exceção, a função chamará `unlock` em qualquer objeto mutex que foi bloqueado com êxito antes do relançamento da exceção.  
  
##  <a name="a-nametrytolockvariablea--trytolock-variable"></a><a name="try_to_lock_variable"></a>  Variável try_to_lock  
 Representa um objeto que pode ser passado para construtores para [unique_lock](../standard-library/unique-lock-class.md) para indicar que o construtor deve tentar desbloquear o `mutex` que também está sendo passado para ele sem bloqueio.  
  
```cpp  
const try_to_lock_t try_to_lock;
```  
  
## <a name="see-also"></a>Consulte também  
 [\<mutex>](../standard-library/mutex.md)




