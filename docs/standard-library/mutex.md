---
title: '&lt;mutex&gt;'
ms.date: 11/04/2016
f1_keywords:
- <mutex>
ms.assetid: efb60c89-687a-4e38-8fe4-694e11c4e8a3
ms.openlocfilehash: 515318cda2155db81406a5c23cb64e46e79c4e19
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68448422"
---
# <a name="ltmutexgt"></a>&lt;mutex&gt;

Inclua o cabeçalho padrão \<mutex> para definir as classes `mutex`, `recursive_mutex`, `timed_mutex` e `recursive_timed_mutex`; os modelos `lock_guard` e `unique_lock`; e o os tipos e as funções de suporte que definem as regiões de código de exclusão mútua.

> [!WARNING]
> A partir do Visual Studio 2015, C++ os tipos de sincronização de biblioteca padrão são baseados em primitivos de sincronização do Windows e não usam mais ConcRT (exceto quando a plataforma de destino é o Windows XP). Os tipos definidos em \<mutex> não devem ser usados com as funções ou tipos ConcRT.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> mutex

**Namespace:** std

## <a name="remarks"></a>Comentários

> [!NOTE]
> No código que é compilado usando **/CLR**, esse cabeçalho é bloqueado.

As classes `mutex` e `recursive_mutex` são *tipos mutex*. Um tipo mutex tem um construtor padrão e um destruidor que não lançam exceções. Esses objetos têm métodos que propiciam exclusão mútua quando vários threads tentam bloquear o mesmo objeto. Especificamente, um tipo mutex contém os métodos `lock`, `try_lock` e `unlock`:

- O método `lock` bloqueia o thread de chamada até que ele tenha obtido a propriedade do mutex. Seu valor retornado é ignorado.

- O método `try_lock` tenta obter a propriedade do mutex sem bloquear. Seu tipo de retorno será convertido em **bool** e será **true** se o método obtiver a propriedade, mas, caso contrário, será **false**.

- O método `unlock` libera a propriedade do mutex do thread de chamada.

Você pode usar tipos mutex como argumentos de tipo para instanciar os modelos `lock_guard` e `unique_lock`. Você pode usar objetos desses tipos, como o argumento `Lock` para as funções membro de espera no modelo [condition_variable_any](../standard-library/condition-variable-any-class.md).

Um *tipo mutex programado* satisfaz os requisitos para um tipo mutex. Além disso, ele tem os `try_lock_for` métodos `try_lock_until` e que devem ser chamados usando um argumento e devem retornar um tipo que possa ser convertido em **bool**. Um tipo de mutex programado pode definir essas funções usando argumentos adicionais, desde que esses argumentos adicionais tenham valores padrão.

- O método `try_lock_for` deve ser chamado usando um argumento, `Rel_time`, cujo tipo é uma instanciação de [chrono::duration](../standard-library/duration-class.md). O método tenta obter a propriedade do mutex, mas retorna no tempo designado pelo `Rel_time`, independentemente do êxito. O valor de retorno será convertido em **true** se o método obtiver a propriedade; caso contrário, o valor de retorno será convertido em **false**.

- O método `try_lock_until` deve ser chamado usando um argumento, `Abs_time`, cujo tipo é uma instanciação de [chrono::time_point](../standard-library/time-point-class.md). O método tenta obter a propriedade do mutex, mas retorna no tempo designado pelo `Abs_time`, independentemente do êxito. O valor de retorno será convertido em **true** se o método obtiver a propriedade; caso contrário, o valor de retorno será convertido em **false**.

Um tipo mutex é também conhecido como um *tipo bloqueável*. Se ele não fornece a função membro `try_lock`, ele é um *tipo bloqueável básico*. Um tipo mutex programado é também conhecido como um *tipo bloqueável programado*.

## <a name="members"></a>Membros

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe lock_guard](../standard-library/lock-guard-class.md)|Representa um modelo que pode ser instanciado para criar um objeto cujo destruidor desbloqueia um `mutex`.|
|[Classe mutex (biblioteca padrão C++)](../standard-library/mutex-class-stl.md)|Representa um tipo mutex. Use objetos desse tipo para impor a exclusão mútua dentro de um programa.|
|[Classe recursive_mutex](../standard-library/recursive-mutex-class.md)|Representa um tipo mutex. Em contraste com a classe `mutex`, o comportamento de chamadas para métodos de bloqueio para objetos que já estão bloqueados é bem definido.|
|[Classe recursive_timed_mutex](../standard-library/recursive-timed-mutex-class.md)|Representa um tipo mutex programado. Use objetos desse tipo para impor a exclusão mútua usando o bloqueio de tempo limite dentro de um programa. Ao contrário de objetos do tipo `timed_mutex`, o efeito de chamar métodos de bloqueio para objetos `recursive_timed_mutex` é bem definido.|
|[Classe scoped_lock](../standard-library/scoped-lock-class.md)||
|[Classe timed_mutex](../standard-library/timed-mutex-class.md)|Representa um tipo mutex programado. Use objetos desse tipo para impor a exclusão mútua usando o bloqueio de tempo limite dentro de um programa.|
|[Classe unique_lock](../standard-library/unique-lock-class.md)|Representa um modelo que pode ser instanciado para criar objetos que gerenciam o bloqueio e o desbloqueio de um `mutex`.|

### <a name="functions"></a>Funções

|||
|-|-|
|[call_once](../standard-library/mutex-functions.md#call_once)|Fornece um mecanismo para chamar um objeto especificado que pode ser chamado apenas uma vez durante a execução.|
|[lock](../standard-library/mutex-functions.md#lock)|Tenta bloquear todos os argumentos sem deadlock.|
|[swap](../standard-library/mutex-functions.md#swap)||
|[try_lock](../standard-library/mutex-functions.md#try_lock)||

### <a name="structs"></a>Structs

|||
|-|-|
|[Estrutura adopt_lock_t](../standard-library/adopt-lock-t-structure.md)|Representa um tipo que é usado para definir um `adopt_lock`.|
|[Estrutura defer_lock_t](../standard-library/defer-lock-t-structure.md)|Representa um tipo que define um objeto `defer_lock` que é usado para selecionar um dos construtores sobrecarregados de `unique_lock`.|
|[Estrutura once_flag](../standard-library/once-flag-structure.md)|Representa uma **struct** que é usada com a função `call_once` de modelo para garantir que o código de inicialização seja chamado apenas uma vez, mesmo na presença de vários threads de execução.|
|[Estrutura try_to_lock_t](../standard-library/try-to-lock-t-structure.md)|Representa uma **struct** que define um `try_to_lock` objeto e é usada para selecionar um dos construtores sobrecarregados de. `unique_lock`|

### <a name="variables"></a>Variáveis

|||
|-|-|
|[adopt_lock](../standard-library/mutex-functions.md#adopt_lock)|Representa um objeto que pode ser passado para construtores para `lock_guard` e `unique_lock` para indicar que o objeto mutex que também está sendo passado para o construtor está bloqueado.|
|[defer_lock](../standard-library/mutex-functions.md#defer_lock)|Representa um objeto que pode ser passado para construtores para `unique_lock` para indicar que o construtor não deve bloquear o objeto mutex que também está sendo passado para ele.|
|[try_to_lock](../standard-library/mutex-functions.md#try_to_lock)|Representa um objeto que pode ser passado para construtores para `unique_lock` para indicar que o construtor deve tentar desbloquear o `mutex` que também está sendo passado para ele sem bloqueio.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
