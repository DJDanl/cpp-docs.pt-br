---
title: _alloca
ms.date: 11/04/2016
api_name:
- _alloca
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _alloca
- alloca
helpviewer_keywords:
- memory allocation, stack
- alloca function
- _alloca function
ms.assetid: 74488eb1-b71f-4515-88e1-cdd03b6f8225
ms.openlocfilehash: 2212f9e40c78932b63eebfc221ad2f07fa3d3f9d
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70943705"
---
# <a name="_alloca"></a>_alloca

Aloca memória na pilha. Esta função foi preterida porque uma versão mais segura está disponível; consulte [_malloca](malloca.md).

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

A rotina **_alloca** retorna um ponteiro **void** para o espaço alocado, que tem a garantia de estar alinhada adequadamente para o armazenamento de qualquer tipo de objeto. Se *size* for 0, **_alloca** aloca um item de comprimento zero e retorna um ponteiro válido para esse item.

Uma exceção de excedente de pilha será gerada se não for possível alocar o espaço. A exceção de excedente de pilha não é uma exceção de C++; ela é uma exceção estruturada. Em vez de usar o tratamento de exceções de C++, você deve usar a [SEH](../../cpp/structured-exception-handling-c-cpp.md) (Manipulação de Exceção Estruturada).

## <a name="remarks"></a>Comentários

**_alloca** aloca os bytes de *tamanho* da pilha de programa. O espaço alocado é liberado automaticamente quando a função de chamada é encerrada (não quando a alocação simplesmente passa para fora do escopo). Portanto, não passe o valor do ponteiro retornado por **_alloca** como um argumento para [gratuito](free.md).

Há restrições para chamar explicitamente **_alloca** em um eh (manipulador de exceção). As rotinas de EH executadas em processadores de classe x86 operam em seu próprio quadro de memória: Eles executam suas tarefas no espaço de memória que não se baseiam no local atual do ponteiro de pilha da função de circunscrição. As implementações mais comuns incluem SEH (Manipulação de Exceção Estruturada ) do Windows NT e expressões de cláusula catch de C++. Portanto, chamar explicitamente **_alloca** em qualquer um dos cenários a seguir resulta em falha do programa durante o retorno para a rotina de chamada eh:

- Expressão de filtro de exceção SEH do Windows NT:`__except ( _alloca() )`

- Manipulador de exceção final de SEH do Windows NT:`__finally { _alloca() }`

- Expressão da cláusula catch do EH de C++

No entanto, o **_alloca** pode ser chamado diretamente de dentro de uma rotina de eh ou de um retorno de chamada fornecido pelo aplicativo que é invocado por um dos cenários de eh listados anteriormente.

> [!IMPORTANT]
> No Windows XP, se **_alloca** for chamado dentro de um bloco try/catch, você deverá chamar [_resetstkoflw](resetstkoflw.md) no bloco catch.

Além das restrições acima, ao usar a opção[/CLR (compilação em tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) , **_alloca** não pode ser usado em blocos **__except** . Para obter mais informações, consulte [/clr Restrições](../../build/reference/clr-restrictions.md).

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
