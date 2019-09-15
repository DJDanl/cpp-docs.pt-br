---
title: terminate (CRT)
ms.date: 11/04/2016
api_name:
- terminate
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
ms.openlocfilehash: b76ce42817fa1a6b79ef32965fcfa550a508e88d
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70946194"
---
# <a name="terminate-crt"></a>terminate (CRT)

Chama [Abort](abort.md) ou uma função que você especifica usando **set_terminate**.

## <a name="syntax"></a>Sintaxe

```C
void terminate( void );
```

## <a name="remarks"></a>Comentários

A função **Terminate** é usada com C++ manipulação de exceção e é chamada nos seguintes casos:

- Não foi encontrado nenhum manipulador catch correspondente a uma exceção do C++ gerada.

- Uma exceção é gerada por uma função do destruidor durante o desenrolamento da pilha.

- A pilha é corrompida depois de gerar uma exceção.

**encerrar** chamadas [abortar](abort.md) por padrão. Você pode alterar esse padrão escrevendo sua própria função de encerramento e chamando **set_terminate** com o nome da sua função como seu argumento. **Terminate** chama a última função fornecida como um argumento para **set_terminate**. Para obter mais informações, consulte [Exceções do C++ sem tratamento](../../cpp/unhandled-cpp-exceptions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**terminate**|\<eh.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)<br/>
[abort](abort.md)<br/>
[_set_se_translator](set-se-translator.md)<br/>
[set_terminate](set-terminate-crt.md)<br/>
[set_unexpected](set-unexpected-crt.md)<br/>
[unexpected](unexpected-crt.md)<br/>
