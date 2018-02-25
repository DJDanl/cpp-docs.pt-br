---
title: "Funções &lt;future&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- future/std::async
- future/std::future_category
- future/std::make_error_code
- future/std::make_error_condition
- future/std::swap
ms.assetid: 1e3acc1e-736a-42dc-ade2-b2fe69aa96bc
caps.latest.revision: 
manager: ghogen
helpviewer_keywords:
- std::async [C++]
- std::future_category [C++]
- std::make_error_code [C++]
- std::make_error_condition [C++]
- std::swap [C++]
ms.openlocfilehash: d136f972786938e453d5a9116ea198ac2a5d8f46
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ltfuturegt-functions"></a>Funções &lt;future&gt;
||||  
|-|-|-|  
|[async](#async)|[future_category](#future_category)|[make_error_code](#make_error_code)|  
|[make_error_condition](#make_error_condition)|[swap](#swap)|  
  
##  <a name="async"></a>  async  
 Representa um *provedor assíncrono*.  
  
```
template <class Fn, class... ArgTypes>
future<typename result_of<Fn(ArgTypes...)>::type>
    async(Fn&& fn, ArgTypes&&... args);

template <class Fn, class... ArgTypes>
future<typename result_of<Fn(ArgTypes...)>::type>
    async(launch policy, Fn&& fn, ArgTypes&&... args);
```  
  
### <a name="parameters"></a>Parâmetros  
 `policy`  
 Um valor [launch](../standard-library/future-enums.md#launch).  
  
### <a name="remarks"></a>Comentários  
 Definições das abreviações:  
  
|||  
|-|-|  
|*dfn*|O resultado da chamada para `decay_copy(forward<Fn>(fn))`.|  
|*dargs*|Os resultados das chamadas para `decay_copy(forward<ArgsTypes>(args...))`.|  
|*Ty*|O tipo `result_of<Fn(ArgTypes...)>::type`.|  
  
 A primeira função de modelo retorna `async(launch::any, fn, args...)`.  
  
 A segunda função retorna um objeto `future<Ty>` cujo *estado assíncrono associado* contém um resultado em conjunto com os valores de *dfn* e *dargs*, bem como um objeto de thread para gerenciar um thread de execução separado.  
  
 A menos que `decay<Fn>::type` não seja do tipo launch, a segunda função não participará da resolução da sobrecarga.  
  
 Se `policy` for `launch::any`, a função poderá escolher `launch::async` ou `launch::deferred`. Nesta implementação, a função usa `launch::async`.  
  
 Se `policy` for `launch::async`, a função criará um thread que avalia `INVOKE(dfn, dargs..., Ty)`. A função será retornada após criar o thread sem esperar resultados. Se o sistema não puder iniciar um novo thread, a função lançará um [system_error](../standard-library/system-error-class.md) com o código de erro `resource_unavailable_try_again`.  
  
 Se `policy` for `launch::deferred`, a função marcará seu estado assíncrono associado como contendo uma *adiada função* e será retornada. A primeira chamada para qualquer função não temporizada que aguarda que o estado assíncrono associado fique pronto chama a função adiada avaliando `INVOKE(dfn, dargs..., Ty)`.  
  
 Em todos caso, o estado assíncrono associado do objeto `future` não é definido como *ready* até que a avaliação de `INVOKE(dfn, dargs..., Ty)` seja concluída, seja lançando uma exceção ou retornando normalmente. O resultado do estado assíncrono associado é uma exceção se uma tiver sido gerada ou qualquer valor que for retornado pela avaliação.  
  
> [!NOTE]
>  Para um `future`— ou o último [shared_future](../standard-library/shared-future-class.md) — anexado a uma tarefa iniciada com `std::async`, os destruidor é bloqueado se a tarefa não tiver sido concluída, ou seja, ele é bloqueado se esse thread ainda não tiver chamado `.get()` ou `.wait()` e a tarefa ainda estiver em execução. Se um `future` obtido de `std::async` for movido para fora do escopo local, outro código que o utiliza deve estar ciente de que seu destruidor pode ser bloqueado para que o estado compartilhado fique pronto.  
  
 A pseudo função `INVOKE` é definida em [\<functional>](../standard-library/functional.md).  
  
##  <a name="future_category"></a>  future_category  
 Retorna uma referência ao objeto [error_category](../standard-library/error-category-class.md) que caracteriza erros associados a objetos `future`.  
  
```
const error_category& future_category() noexcept;
```  
  
##  <a name="make_error_code"></a>  make_error_code  
 Cria um [error_code](../standard-library/error-code-class.md) com o objeto [error_category](../standard-library/error-category-class.md) que caracteriza erros de [future](../standard-library/future-class.md).  
  
```
inline error_code make_error_code(future_errc Errno) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Errno`  
 Um valor de [future_errc](../standard-library/future-enums.md#future_errc) que identifica o erro relatado.  
  
### <a name="return-value"></a>Valor de retorno  
 `error_code(static_cast<int>(Errno), future_category());`  
  
##  <a name="make_error_condition"></a>  make_error_condition  
 Cria um [error_condition](../standard-library/error-condition-class.md) com o objeto [error_category](../standard-library/error-category-class.md) que caracteriza erros de [future](../standard-library/future-class.md).  
  
```
inline error_condition make_error_condition(future_errc Errno) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Errno`  
 Um valor de [future_errc](../standard-library/future-enums.md#future_errc) que identifica o erro relatado.  
  
### <a name="return-value"></a>Valor de retorno  
 `error_condition(static_cast<int>(Errno), future_category());`  
  
##  <a name="swap"></a>  swap  
 Troca o *estado assíncrono associado* de um objeto `promise` pelo de outro objeto.  
  
```
template <class Ty>
void swap(promise<Ty>& Left, promise<Ty>& Right) noexcept;

template <class Ty, class... ArgTypes>
void swap(packaged_task<Ty(ArgTypes...)>& Left, packaged_task<Ty(ArgTypes...)>& Right) noexcept;
```  
  
### <a name="parameters"></a>Parâmetros  
 `Left`  
 O objeto `promise` à esquerda.  
  
 `Right`  
 O objeto `promise` à direita.  
  
## <a name="see-also"></a>Consulte também  
 [\<future>](../standard-library/future.md)



