---
title: _malloca
ms.date: 11/04/2016
apiname:
- _malloca
apilocation:
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
apitype: DLLExport
f1_keywords:
- malloca
- _malloca
helpviewer_keywords:
- memory allocation, stack
- malloca function
- _malloca function
ms.assetid: 293992df-cfca-4bc9-b313-0a733a6bb936
ms.openlocfilehash: 8c8ce8bdf8ab40cae45ecec9c4b182bdf3d6bc82
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50563976"
---
# <a name="malloca"></a>_malloca

Aloca memória na pilha. Esta é uma versão de [_alloca](alloca.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
void *_malloca(
   size_t size
);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Bytes a serem alocados da pilha.

## <a name="return-value"></a>Valor de retorno

O **malloca** rotina retorna um **void** ponteiro para o espaço alocado, que é garantido para ser sutilmente alinhado para armazenamento de qualquer tipo de objeto. Se *tamanho* é 0, o **malloca** alocará um item de comprimento zero e retornará um ponteiro válido para esse item.

Uma exceção de excedente de pilha será gerada se não for possível alocar o espaço. A exceção de excedente de pilha não é uma exceção de C++; ela é uma exceção estruturada. Em vez de usar o tratamento de exceções de C++, você deve usar a [SEH](../../cpp/structured-exception-handling-c-cpp.md) (Manipulação de Exceção Estruturada).

## <a name="remarks"></a>Comentários

**malloca** aloca *tamanho* bytes de pilha de programa ou o heap se a solicitação excede um determinado tamanho em bytes fornecidos pelo **_ALLOCA_S_THRESHOLD**. A diferença entre **malloca** e **alloca** é que **alloca** sempre aloca na pilha, independentemente do tamanho. Diferentemente **alloca**, que não exige ou permite que uma chamada para **livre** liberar a memória alocada, **malloca** requer o uso de [freea](freea.md)para liberar memória. No modo de depuração **malloca** sempre aloca memória do heap.

Há restrições para chamar explicitamente **malloca** em um manipulador de exceção (EH). As rotinas do EH que são executadas em processadores da classe x86 operam em seu próprio quadro de memória: elas realizam suas tarefas no espaço de memória que não é baseado no local atual do ponteiro de pilha da função delimitadora. As implementações mais comuns incluem SEH (Manipulação de Exceção Estruturada ) do Windows NT e expressões de cláusula catch de C++. Portanto, chamar explicitamente **malloca** em qualquer um dos seguintes cenários resulta em falha do programa durante o retorno ao chamar a rotina EH:

- Expressão de filtro de exceção do Windows NT SEH: **EXCEPT** (`_malloca ()` )

- Manipulador de exceção final do Windows NT SEH: **Finally** {`_malloca ()` }

- Expressão da cláusula catch do EH de C++

No entanto, **malloca** podem ser chamados diretamente de dentro de uma rotina do EH ou de um retorno de chamada fornecida pelo aplicativo que é invocado por um dos cenários do EH listados anteriormente.

> [!IMPORTANT]
> No Windows XP, se **malloca** é chamado dentro de um bloco try/catch, você deve chamar [resetstkoflw](resetstkoflw.md) em um bloco catch.

Além das restrições acima, ao usar o [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) opção **malloca** não pode ser usado na **EXCEPT** blocos. Para obter mais informações, consulte [/clr Restrições](../../build/reference/clr-restrictions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_malloca**|\<malloc.h>|

## <a name="example"></a>Exemplo

```C
// crt_malloca_simple.c
#include <stdio.h>
#include <malloc.h>

void Fn()
{
   char * buf = (char *)_malloca( 100 );
   // do something with buf
   _freea( buf );
}

int main()
{
   Fn();
}
```

## <a name="example"></a>Exemplo

```C
// crt_malloca_exception.c
// This program demonstrates the use of
// _malloca and trapping any exceptions
// that may occur.

#include <windows.h>
#include <stdio.h>
#include <malloc.h>

int main()
{
    int     size;
    int     numberRead = 0;
    int     errcode = 0;
    void    *p = NULL;
    void    *pMarker = NULL;

    while (numberRead == 0)
    {
        printf_s("Enter the number of bytes to allocate "
                 "using _malloca: ");
        numberRead = scanf_s("%d", &size);
    }

    // Do not use try/catch for _malloca,
    // use __try/__except, since _malloca throws
    // Structured Exceptions, not C++ exceptions.

    __try
    {
        if (size > 0)
        {
            p =  _malloca( size );
        }
        else
        {
            printf_s("Size must be a positive number.");
        }
        _freea( p );
    }

    // Catch any exceptions that may occur.
    __except( GetExceptionCode() == STATUS_STACK_OVERFLOW )
    {
        printf_s("_malloca failed!\n");

        // If the stack overflows, use this function to restore.
        errcode = _resetstkoflw();
        if (errcode)
        {
            printf("Could not reset the stack!");
            _exit(1);
        }
    };
}
```

### <a name="input"></a>Entrada

```Input
1000
```

### <a name="sample-output"></a>Saída de Exemplo

```Output
Enter the number of bytes to allocate using _malloca: 1000
```

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[malloc](malloc.md)<br/>
[realloc](realloc.md)<br/>
[_resetstkoflw](resetstkoflw.md)<br/>
