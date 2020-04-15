---
title: terminate (CRT)
ms.date: 4/2/2020
api_name:
- terminate
- _o_terminate
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- terminate
helpviewer_keywords:
- terminate function
- exception handling, termination
ms.assetid: 90e67402-08e9-4b2a-962c-66a8afd3ccb4
ms.openlocfilehash: 1aa95daeab424c933f10060fb4f87cb317aa188c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81362536"
---
# <a name="terminate-crt"></a>terminate (CRT)

Chamadas [abortam](abort.md) ou uma função especificada usando **set_terminate**.

## <a name="syntax"></a>Sintaxe

```C
void terminate( void );
```

## <a name="remarks"></a>Comentários

A função **de término** é usada com o tratamento de exceção C++ e é chamada nos seguintes casos:

- Não foi encontrado nenhum manipulador catch correspondente a uma exceção do C++ gerada.

- Uma exceção é gerada por uma função do destruidor durante o desenrolamento da pilha.

- A pilha é corrompida depois de gerar uma exceção.

**encerrar** chamadas [abortam](abort.md) por padrão. Você pode alterar esse padrão escrevendo sua própria função de rescisão e chamando **set_terminate** com o nome de sua função como seu argumento. **acabar** chama a última função dada como argumento para **set_terminate**. Para obter mais informações, consulte [Exceções do C++ sem tratamento](../../cpp/unhandled-cpp-exceptions.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Terminar**|\<eh.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// crt_terminate.cpp
// compile with: /EHsc
#include <eh.h>
#include <process.h>
#include <iostream>
using namespace std;

void term_func();

int main()
{
    int i = 10, j = 0, result;
    set_terminate( term_func );
    try
    {
        if( j == 0 )
            throw "Divide by zero!";
        else
            result = i/j;
    }
    catch( int )
    {
        cout << "Caught some integer exception.\n";
    }
    cout << "This should never print.\n";
}

void term_func()
{
    cout << "term_func() was called by terminate().\n";

    // ... cleanup tasks performed here

    // If this function does not exit, abort is called.

    exit(-1);
}
```

```Output
term_func() was called by terminate().
```

## <a name="see-also"></a>Confira também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)<br/>
[Abortar](abort.md)<br/>
[_set_se_translator](set-se-translator.md)<br/>
[set_terminate](set-terminate-crt.md)<br/>
[Set_unexpected](set-unexpected-crt.md)<br/>
[Inesperado](unexpected-crt.md)<br/>
