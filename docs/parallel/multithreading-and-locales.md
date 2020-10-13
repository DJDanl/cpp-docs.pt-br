---
title: Multithread e localidades
ms.date: 11/04/2016
helpviewer_keywords:
- locales [C++], multithreading
- multithreading [C++], locales
- threading [C++], locales
- per-thread locale
ms.assetid: d6fb159a-eaca-4130-a51a-f95d62f71485
ms.openlocfilehash: 82b410c592e5b68737514dda5a864c7bd15f6dc3
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008589"
---
# <a name="multithreading-and-locales"></a>Multithread e localidades

A biblioteca de tempo de execução C e a biblioteca C++ standard oferecem suporte para alterar a localidade do programa. Este tópico aborda os problemas que surgem ao usar a funcionalidade de localidade de ambas as bibliotecas em um aplicativo multithread.

## <a name="remarks"></a>Comentários

Com a biblioteca de tempo de execução C, você pode criar aplicativos multissegmentados usando `_beginthread` as `_beginthreadex` funções e. Este tópico aborda apenas os aplicativos multithread criados usando essas funções. Para obter mais informações, consulte [_beginthread, _beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md).

Para alterar a localidade usando a biblioteca de tempo de execução C, use a função [setlocale](../preprocessor/setlocale.md) . Nas versões anteriores do Visual C++, essa função sempre modificaria a localidade em todo o aplicativo. Agora há suporte para definir a localidade por thread. Isso é feito usando a função [_configthreadlocale](../c-runtime-library/reference/configthreadlocale.md) . Para especificar que [setlocaling](../preprocessor/setlocale.md) só deve alterar a localidade no thread atual, chame `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)` nesse thread. Por outro lado, chamar fará com `_configthreadlocale(_DISABLE_PER_THREAD_LOCALE)` que esse thread use a localidade global, e qualquer chamada para [setlocaling](../preprocessor/setlocale.md) nesse thread alterará a localidade em todos os threads que não habilitaram explicitamente a localidade por thread.

Para alterar a localidade usando a biblioteca de tempo de execução C++, use a [classe Locale](../standard-library/locale-class.md). Chamando o método [locale:: global](../standard-library/locale-class.md#global) , você altera a localidade em todos os threads que não ativou explicitamente a localidade por thread. Para alterar a localidade em um único thread ou parte de um aplicativo, basta criar uma instância de um `locale` objeto nesse thread ou parte do código.

> [!NOTE]
> Chamando [localidade:: global](../standard-library/locale-class.md#global) altera a localidade para a biblioteca padrão C++ e a biblioteca de tempo de execução C. No entanto, chamar [setlocaling](../preprocessor/setlocale.md) apenas altera a localidade para a biblioteca de tempo de execução C; a biblioteca padrão C++ não é afetada.

Os exemplos a seguir mostram como usar a função [setlocale](../preprocessor/setlocale.md) , a [classe Locale](../standard-library/locale-class.md)e a função [_configthreadlocale](../c-runtime-library/reference/configthreadlocale.md) para alterar a localidade de um aplicativo em vários cenários diferentes.

## <a name="example-change-locale-with-per-thread-locale-enabled"></a>Exemplo: alterar a localidade com a localidade por thread habilitada

Neste exemplo, o thread principal gera dois threads filho. O primeiro thread, thread A, habilita a localidade por thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)` . O segundo thread, thread B, bem como o thread principal, não habilita a localidade por thread. Em seguida, o thread A prossegue para alterar a localidade usando a função [setlocalize](../preprocessor/setlocale.md) da biblioteca de tempo de execução C.

Como o thread A tem a localidade por thread habilitada, somente as funções da biblioteca de tempo de execução C no thread A começam a usar a localidade "francês". As funções da biblioteca de tempo de execução C no thread B e no thread principal continuam a usar a localidade "C". Além disso, como [setlocale](../preprocessor/setlocale.md) não afeta a localidade da biblioteca padrão do c++, todos os objetos de biblioteca padrão do c++ continuam a usar a localidade "C".

```cpp
// multithread_locale_1.cpp
// compile with: /EHsc /MD
#include <clocale>
#include <cstdio>
#include <locale>
#include <process.h>
#include <windows.h>

#define NUM_THREADS 2
using namespace std;

unsigned __stdcall RunThreadA(void *params);
unsigned __stdcall RunThreadB(void *params);

BOOL localeSet = FALSE;
HANDLE printMutex = CreateMutex(NULL, FALSE, NULL);

int main()
{
    HANDLE threads[NUM_THREADS];

    unsigned aID;
    threads[0] = (HANDLE)_beginthreadex(
        NULL, 0, RunThreadA, NULL, 0, &aID);

    unsigned bID;
    threads[1] = (HANDLE)_beginthreadex(
        NULL, 0, RunThreadB, NULL, 0, &bID);

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    printf_s("[Thread main] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread main] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread main] locale::global is set to \"%s\"\n",
        locale().name().c_str());

    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    CloseHandle(printMutex);

    return 0;
}

unsigned __stdcall RunThreadA(void *params)
{
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
    setlocale(LC_ALL, "french");
    localeSet = TRUE;

    WaitForSingleObject(printMutex, INFINITE);
    printf_s("[Thread A] Per-thread locale is enabled.\n");
    printf_s("[Thread A] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread A] locale::global is set to \"%s\"\n\n",
        locale().name().c_str());
    ReleaseMutex(printMutex);

    return 1;
}

unsigned __stdcall RunThreadB(void *params)
{
    while (!localeSet)
        Sleep(100);

    WaitForSingleObject(printMutex, INFINITE);
    printf_s("[Thread B] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread B] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread B] locale::global is set to \"%s\"\n\n",
        locale().name().c_str());
    ReleaseMutex(printMutex);

    return 1;
}
```

```Output
[Thread A] Per-thread locale is enabled.
[Thread A] CRT locale is set to "French_France.1252"
[Thread A] locale::global is set to "C"

[Thread B] Per-thread locale is NOT enabled.
[Thread B] CRT locale is set to "C"
[Thread B] locale::global is set to "C"

[Thread main] Per-thread locale is NOT enabled.
[Thread main] CRT locale is set to "C"
[Thread main] locale::global is set to "C"
```

## <a name="example-change-global-locale-with-per-thread-locale-enabled"></a>Exemplo: alterar a localidade global com a localidade por thread habilitada

Neste exemplo, o thread principal gera dois threads filho. O primeiro thread, thread A, habilita a localidade por thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)` . O segundo thread, thread B, bem como o thread principal, não habilita a localidade por thread. Em seguida, o thread A continua a alterar a localidade usando o método [locale:: global](../standard-library/locale-class.md#global) da biblioteca padrão C++.

Como o thread A tem a localidade por thread habilitada, somente as funções da biblioteca de tempo de execução C no thread A começam a usar a localidade "francês". As funções da biblioteca de tempo de execução C no thread B e no thread principal continuam a usar a localidade "C". No entanto, como o método [locale:: global](../standard-library/locale-class.md#global) altera a localidade "globalmente", todos os objetos de biblioteca padrão do C++ em todos os threads começam a usar a localidade "francês".

```cpp
// multithread_locale_2.cpp
// compile with: /EHsc /MD
#include <clocale>
#include <cstdio>
#include <locale>
#include <process.h>
#include <windows.h>

#define NUM_THREADS 2
using namespace std;

unsigned __stdcall RunThreadA(void *params);
unsigned __stdcall RunThreadB(void *params);

BOOL localeSet = FALSE;
HANDLE printMutex = CreateMutex(NULL, FALSE, NULL);

int main()
{
    HANDLE threads[NUM_THREADS];

    unsigned aID;
    threads[0] = (HANDLE)_beginthreadex(
        NULL, 0, RunThreadA, NULL, 0, &aID);

    unsigned bID;
    threads[1] = (HANDLE)_beginthreadex(
        NULL, 0, RunThreadB, NULL, 0, &bID);

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    printf_s("[Thread main] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread main] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread main] locale::global is set to \"%s\"\n",
        locale().name().c_str());

    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    CloseHandle(printMutex);

    return 0;
}

unsigned __stdcall RunThreadA(void *params)
{
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
    locale::global(locale("french"));
    localeSet = TRUE;

    WaitForSingleObject(printMutex, INFINITE);
    printf_s("[Thread A] Per-thread locale is enabled.\n");
    printf_s("[Thread A] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread A] locale::global is set to \"%s\"\n\n",
        locale().name().c_str());
    ReleaseMutex(printMutex);

    return 1;
}

unsigned __stdcall RunThreadB(void *params)
{
    while (!localeSet)
        Sleep(100);

    WaitForSingleObject(printMutex, INFINITE);
    printf_s("[Thread B] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread B] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread B] locale::global is set to \"%s\"\n\n",
        locale().name().c_str());
    ReleaseMutex(printMutex);

    return 1;
}
```

```Output
[Thread A] Per-thread locale is enabled.
[Thread A] CRT locale is set to "French_France.1252"
[Thread A] locale::global is set to "French_France.1252"

[Thread B] Per-thread locale is NOT enabled.
[Thread B] CRT locale is set to "C"
[Thread B] locale::global is set to "French_France.1252"

[Thread main] Per-thread locale is NOT enabled.
[Thread main] CRT locale is set to "C"
[Thread main] locale::global is set to "French_France.1252"
```

## <a name="example-change-locale-without-per-thread-locale-enabled"></a>Exemplo: alterar a localidade sem a localidade por thread habilitada

Neste exemplo, o thread principal gera dois threads filho. O primeiro thread, thread A, habilita a localidade por thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)` . O segundo thread, thread B, bem como o thread principal, não habilita a localidade por thread. O thread B continua a alterar a localidade usando a função [setlocalize](../preprocessor/setlocale.md) da biblioteca de tempo de execução C.

Como o thread B não tem a localidade por thread habilitada, as funções da biblioteca de tempo de execução C no thread B e no thread principal começam a usar a localidade "francês". As funções da biblioteca de tempo de execução C no thread A continuam a usar a localidade "C" porque o thread A tem A localidade por thread habilitada. Além disso, como [setlocale](../preprocessor/setlocale.md) não afeta a localidade da biblioteca padrão do c++, todos os objetos de biblioteca padrão do c++ continuam a usar a localidade "C".

```cpp
// multithread_locale_3.cpp
// compile with: /EHsc /MD
#include <clocale>
#include <cstdio>
#include <locale>
#include <process.h>
#include <windows.h>

#define NUM_THREADS 2
using namespace std;

unsigned __stdcall RunThreadA(void *params);
unsigned __stdcall RunThreadB(void *params);

BOOL localeSet = FALSE;
BOOL configThreadLocaleCalled = FALSE;
HANDLE printMutex = CreateMutex(NULL, FALSE, NULL);

int main()
{
    HANDLE threads[NUM_THREADS];

    unsigned aID;
    threads[0] = (HANDLE)_beginthreadex(
        NULL, 0, RunThreadA, NULL, 0, &aID);

    unsigned bID;
    threads[1] = (HANDLE)_beginthreadex(
        NULL, 0, RunThreadB, NULL, 0, &bID);

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    printf_s("[Thread main] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread main] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread main] locale::global is set to \"%s\"\n",
        locale().name().c_str());

    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    CloseHandle(printMutex);

    return 0;
}

unsigned __stdcall RunThreadA(void *params)
{
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
    configThreadLocaleCalled = TRUE;
    while (!localeSet)
        Sleep(100);

    WaitForSingleObject(printMutex, INFINITE);
    printf_s("[Thread A] Per-thread locale is enabled.\n");
    printf_s("[Thread A] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread A] locale::global is set to \"%s\"\n\n",
        locale().name().c_str());
    ReleaseMutex(printMutex);

    return 1;
}

unsigned __stdcall RunThreadB(void *params)
{
    while (!configThreadLocaleCalled)
        Sleep(100);
    setlocale(LC_ALL, "french");
    localeSet = TRUE;

    WaitForSingleObject(printMutex, INFINITE);
    printf_s("[Thread B] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread B] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread B] locale::global is set to \"%s\"\n\n",
        locale().name().c_str());
    ReleaseMutex(printMutex);

    return 1;
}
```

```Output
[Thread B] Per-thread locale is NOT enabled.
[Thread B] CRT locale is set to "French_France.1252"
[Thread B] locale::global is set to "C"

[Thread A] Per-thread locale is enabled.
[Thread A] CRT locale is set to "C"
[Thread A] locale::global is set to "C"

[Thread main] Per-thread locale is NOT enabled.
[Thread main] CRT locale is set to "French_France.1252"
[Thread main] locale::global is set to "C"
```

## <a name="example-change-global-locale-without-per-thread-locale-enabled"></a>Exemplo: alterar a localidade global sem a localidade por thread habilitada

Neste exemplo, o thread principal gera dois threads filho. O primeiro thread, thread A, habilita a localidade por thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)` . O segundo thread, thread B, bem como o thread principal, não habilita a localidade por thread. O thread B continua a alterar a localidade usando o método [locale:: global](../standard-library/locale-class.md#global) da biblioteca padrão C++.

Como o thread B não tem a localidade por thread habilitada, as funções da biblioteca de tempo de execução C no thread B e no thread principal começam a usar a localidade "francês". As funções da biblioteca de tempo de execução C no thread A continuam a usar a localidade "C" porque o thread A tem A localidade por thread habilitada. No entanto, como o método [locale:: global](../standard-library/locale-class.md#global) altera a localidade "globalmente", todos os objetos de biblioteca padrão do C++ em todos os threads começam a usar a localidade "francês".

```cpp
// multithread_locale_4.cpp
// compile with: /EHsc /MD
#include <clocale>
#include <cstdio>
#include <locale>
#include <process.h>
#include <windows.h>

#define NUM_THREADS 2
using namespace std;

unsigned __stdcall RunThreadA(void *params);
unsigned __stdcall RunThreadB(void *params);

BOOL localeSet = FALSE;
BOOL configThreadLocaleCalled = FALSE;
HANDLE printMutex = CreateMutex(NULL, FALSE, NULL);

int main()
{
    HANDLE threads[NUM_THREADS];

    unsigned aID;
    threads[0] = (HANDLE)_beginthreadex(
        NULL, 0, RunThreadA, NULL, 0, &aID);

    unsigned bID;
    threads[1] = (HANDLE)_beginthreadex(
        NULL, 0, RunThreadB, NULL, 0, &bID);

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    printf_s("[Thread main] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread main] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread main] locale::global is set to \"%s\"\n",
        locale().name().c_str());

    CloseHandle(threads[0]);
    CloseHandle(threads[1]);
    CloseHandle(printMutex);

    return 0;
}

unsigned __stdcall RunThreadA(void *params)
{
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
    configThreadLocaleCalled = TRUE;
    while (!localeSet)
        Sleep(100);

    WaitForSingleObject(printMutex, INFINITE);
    printf_s("[Thread A] Per-thread locale is enabled.\n");
    printf_s("[Thread A] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread A] locale::global is set to \"%s\"\n\n",
        locale().name().c_str());
    ReleaseMutex(printMutex);

    return 1;
}

unsigned __stdcall RunThreadB(void *params)
{
    while (!configThreadLocaleCalled)
        Sleep(100);
    locale::global(locale("french"));
    localeSet = TRUE;

    WaitForSingleObject(printMutex, INFINITE);
    printf_s("[Thread B] Per-thread locale is NOT enabled.\n");
    printf_s("[Thread B] CRT locale is set to \"%s\"\n",
        setlocale(LC_ALL, NULL));
    printf_s("[Thread B] locale::global is set to \"%s\"\n\n",
        locale().name().c_str());
    ReleaseMutex(printMutex);

    return 1;
}
```

```Output
[Thread B] Per-thread locale is NOT enabled.
[Thread B] CRT locale is set to "French_France.1252"
[Thread B] locale::global is set to "French_France.1252"

[Thread A] Per-thread locale is enabled.
[Thread A] CRT locale is set to "C"
[Thread A] locale::global is set to "French_France.1252"

[Thread main] Per-thread locale is NOT enabled.
[Thread main] CRT locale is set to "French_France.1252"
[Thread main] locale::global is set to "French_France.1252"
```

## <a name="see-also"></a>Veja também

[Suporte multithread para código anterior (Visual C++)](multithreading-support-for-older-code-visual-cpp.md)<br/>
[_beginthread, _beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md)<br/>
[_configthreadlocale](../c-runtime-library/reference/configthreadlocale.md)<br/>
[setlocale](../preprocessor/setlocale.md)<br/>
[Internacionalização](../c-runtime-library/internationalization.md)<br/>
[Localidade](../c-runtime-library/locale.md)<br/>
[\<clocale>](../standard-library/clocale.md)<br/>
[\<locale>](../standard-library/locale.md)<br/>
[Classe de localidade](../standard-library/locale-class.md)
