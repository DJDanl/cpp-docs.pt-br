---
title: _alloca
ms.date: 11/04/2016
apiname:
- _alloca
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
- _alloca
- alloca
helpviewer_keywords:
- memory allocation, stack
- alloca function
- _alloca function
ms.assetid: 74488eb1-b71f-4515-88e1-cdd03b6f8225
ms.openlocfilehash: 7c083e791301d3224709a5fc6c711ceaa6397d38
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62341594"
---
# <a name="alloca"></a>_alloca

Aloca memória na pilha. Essa função é preterida porque uma versão mais segura está disponível. ver [malloca](malloca.md).

## <a name="syntax"></a>Sintaxe

```C
void *_alloca(
   size_t size
);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Bytes a serem alocados da pilha.

## <a name="return-value"></a>Valor de retorno

O **alloca** rotina retorna um **void** ponteiro para o espaço alocado, que é garantido para ser sutilmente alinhado para armazenamento de qualquer tipo de objeto. Se *tamanho* é 0, o **alloca** alocará um item de comprimento zero e retornará um ponteiro válido para esse item.

Uma exceção de excedente de pilha será gerada se não for possível alocar o espaço. A exceção de excedente de pilha não é uma exceção de C++; ela é uma exceção estruturada. Em vez de usar o tratamento de exceções de C++, você deve usar a [SEH](../../cpp/structured-exception-handling-c-cpp.md) (Manipulação de Exceção Estruturada).

## <a name="remarks"></a>Comentários

**alloca** aloca *tamanho* bytes da pilha de programa. O espaço alocado é liberado automaticamente quando a função de chamada é encerrado (não quando a alocação simplesmente passa fora do escopo). Portanto, não passe o valor do ponteiro retornado por **alloca** como um argumento para [livre](free.md).

Há restrições para chamar explicitamente **alloca** em um manipulador de exceção (EH). As rotinas do EH que são executados em processadores da classe x86 operam em seu próprio quadro de memória: Elas realizam suas tarefas no espaço de memória que não se baseia o local atual do ponteiro de pilha da função. As implementações mais comuns incluem SEH (Manipulação de Exceção Estruturada ) do Windows NT e expressões de cláusula catch de C++. Portanto, chamar explicitamente **alloca** em qualquer um dos seguintes cenários resulta em falha do programa durante o retorno ao chamar a rotina EH:

- Expressão de filtro de exceção SEH do Windows NT: `__except ( _alloca() )`

- Manipulador de exceção final do Windows NT SEH: `__finally { _alloca() }`

- Expressão da cláusula catch do EH de C++

No entanto, **alloca** podem ser chamados diretamente de dentro de uma rotina do EH ou de um retorno de chamada fornecida pelo aplicativo que é invocado por um dos cenários do EH listados anteriormente.

> [!IMPORTANT]
> No Windows XP, se **alloca** é chamado dentro de um bloco try/catch, você deve chamar [resetstkoflw](resetstkoflw.md) em um bloco catch.

Além das restrições acima, ao usar o[/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) opção **alloca** não pode ser usado na **EXCEPT** blocos. Para obter mais informações, consulte [/clr Restrições](../../build/reference/clr-restrictions.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_alloca**|\<malloc.h>|

## <a name="example"></a>Exemplo

```C
// crt_alloca.c
// This program demonstrates the use of
// _alloca and trapping any exceptions
// that may occur.

#include <windows.h>
#include <stdio.h>
#include <malloc.h>

int main()
{
    int     size = 1000;
    int     errcode = 0;
    void    *pData = NULL;

    // Note: Do not use try/catch for _alloca,
    // use __try/__except, since _alloca throws
    // Structured Exceptions, not C++ exceptions.

    __try {
        // An unbounded _alloca can easily result in a
        // stack overflow.
        // Checking for a size < 1024 bytes is recommended.
        if (size > 0 && size < 1024)
        {
            pData = _alloca( size );
            printf_s( "Allocated %d bytes of stack at 0x%p",
                      size, pData);
        }
        else
        {
            printf_s("Tried to allocate too many bytes.\n");
        }
    }

    // If an exception occured with the _alloca function
    __except( GetExceptionCode() == STATUS_STACK_OVERFLOW )
    {
        printf_s("_alloca failed!\n");

        // If the stack overflows, use this function to restore.
        errcode = _resetstkoflw();
        if (errcode)
        {
            printf_s("Could not reset the stack!\n");
            _exit(1);
        }
    };
}
```

```Output
Allocated 1000 bytes of stack at 0x0012FB50
```

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[malloc](malloc.md)<br/>
[realloc](realloc.md)<br/>
[_resetstkoflw](resetstkoflw.md)<br/>
[_malloca](malloca.md)<br/>
