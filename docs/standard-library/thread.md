---
title: '&lt;thread&gt;'
ms.date: 11/04/2016
f1_keywords:
- <thread>
ms.assetid: 0c858405-4efb-449d-bf76-70d3693c9234
ms.openlocfilehash: 43fb79ceda6de7409e6f93797ce2f4ff213c43ee
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50487510"
---
# <a name="ltthreadgt"></a>&lt;thread&gt;

Inclua o cabeçalho padrão \<thread > para definir a classe **thread** e várias funções de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <thread>
```

## <a name="remarks"></a>Comentários

> [!NOTE]
> No código que é compilado usando **/clr**, esse cabeçalho é bloqueado.

O `__STDCPP_THREADS__` macro é definida como um valor diferente de zero para indicar que os threads têm suporte por esse cabeçalho.

## <a name="members"></a>Membros

### <a name="public-classes"></a>Classes públicas

|Nome|Descrição|
|----------|-----------------|
|[Classe thread](../standard-library/thread-class.md)|Define um objeto que é usado para observar e gerenciar um thread de execução em um aplicativo.|

### <a name="public-structures"></a>Estruturas públicas

|Nome|Descrição|
|----------|-----------------|
|[Estrutura hash (Biblioteca Padrão C++)](../standard-library/hash-structure-stl.md)|Define uma função de membro que retorna um valor que é determinado exclusivamente por um `thread::id`. A função de membro define uma [hash](../standard-library/hash-class.md) função que é adequada para mapear valores do tipo `thread::id` para uma distribuição de valores de índice.|

### <a name="public-functions"></a>Funções públicas

|Nome|Descrição|
|----------|-----------------|
|[get_id](../standard-library/thread-functions.md#get_id)|Identifica exclusivamente o thread atual de execução.|
|[sleep_for](../standard-library/thread-functions.md#sleep_for)|Bloqueia o thread de chamada.|
|[sleep_until](../standard-library/thread-functions.md#sleep_until)|Bloqueia o thread de chamada, pelo menos, até o tempo especificado.|
|[swap](../standard-library/thread-functions.md#swap)|Troca os estados de dois **thread** objetos.|
|[yield](../standard-library/thread-functions.md#yield)|Sinaliza ao sistema operacional para executar outros threads, mesmo se o thread atual continuar normalmente em execução.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador > = operador](../standard-library/thread-operators.md#op_gt_eq)|Determina se um objeto `thread::id` é maior ou igual a outro.|
|[operador > operador](../standard-library/thread-operators.md#op_gt)|Determina se um objeto `thread::id` é maior que outro.|
|[operador < Operator =](../standard-library/thread-operators.md#op_lt_eq)|Determina se um objeto `thread::id` é menor ou igual a outro.|
|[operador < operador](../standard-library/thread-operators.md#op_lt)|Determina se um objeto `thread::id` é menor que outro.|
|[operador! = operador](../standard-library/thread-operators.md#op_neq)|Compara dois objetos `thread::id` quanto à desigualdade.|
|[operador Operator = =](../standard-library/thread-operators.md#op_eq_eq)|Compara dois objetos `thread::id` quanto à igualdade.|
|[operador << operador](../standard-library/thread-operators.md#op_lt_lt)|Insere uma representação de texto de um objeto `thread::id` em um fluxo.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
