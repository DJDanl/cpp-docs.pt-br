---
title: '&lt;thread&gt; | Documentos do Microsoft'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- <thread>
dev_langs:
- C++
ms.assetid: 0c858405-4efb-449d-bf76-70d3693c9234
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
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: 9b32de86d2ec84017157cccf1a05b9e9b6802e47
ms.lasthandoff: 02/25/2017

---
# <a name="ltthreadgt"></a>&lt;thread&gt;
Inclua o cabeçalho padrão \<thread > para definir a classe `thread` e várias funções de suporte.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
#include <thread>  
```  
  
## <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  No código que é compilado usando **/clr**, esse cabeçalho é bloqueado.  
  
 O `__STDCPP_THREADS__` macro é definida como um valor diferente de zero para indicar que os threads são suportados por esse cabeçalho.  
  
## <a name="members"></a>Membros  
  
### <a name="public-classes"></a>Classes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe thread](../standard-library/thread-class.md)|Define um objeto que é usado para observar e gerenciar um thread de execução em um aplicativo.|  
  
### <a name="public-structures"></a>Estruturas de públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Estrutura hash (Biblioteca Padrão C++)](../standard-library/hash-structure-stl.md)|Define uma função de membro que retorna um valor que é determinado de forma exclusiva por um `thread::id`. A função de membro define uma [hash](../standard-library/hash-class.md) função adequada para valores de mapeamento de tipo `thread::id` para uma distribuição de valores de índice.|  
  
### <a name="public-functions"></a>Funções públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Função get_id](../standard-library/thread-functions.md#get_id_function)|Identifica exclusivamente o thread atual de execução.|  
|[Função sleep_for](../standard-library/thread-functions.md#sleep_for_function)|Bloqueia o thread de chamada.|  
|[Função sleep_until](../standard-library/thread-functions.md#sleep_until_function)|Bloqueia o thread de chamada, pelo menos, até o tempo especificado.|  
|[Função swap](../standard-library/thread-functions.md#swap_function)|Troca os estados de dois `thread` objetos.|  
|[Função yield](../standard-library/thread-functions.md#yield_function)|Sinaliza ao sistema operacional para executar outros threads, mesmo se o thread atual continuar normalmente em execução.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[operador > operador =](../standard-library/thread-operators.md#operator_gt__eq)|Determina se um objeto `thread::id` é maior ou igual a outro.|  
|[operador > operador](../standard-library/thread-operators.md#operator_gt_)|Determina se um objeto `thread::id` é maior que outro.|  
|[operador<=></=>](../standard-library/thread-operators.md#operator_lt__eq)|Determina se um objeto `thread::id` é menor ou igual a outro.|  
|[operador<>](../standard-library/thread-operators.md#operator_lt_)|Determina se um objeto `thread::id` é menor que outro.|  
|[operador! = operador](../standard-library/thread-operators.md#operator_neq)|Compara dois objetos `thread::id` quanto à desigualdade.|  
|[operador Operator = =](../standard-library/thread-operators.md#operator_eq_eq)|Compara dois objetos `thread::id` quanto à igualdade.|  
|[operador<>](../standard-library/thread-operators.md#operator_lt__lt_)|Insere uma representação de texto de um objeto `thread::id` em um fluxo.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


