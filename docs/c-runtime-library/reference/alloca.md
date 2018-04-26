---
title: _alloca | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- memory allocation, stack
- alloca function
- _alloca function
ms.assetid: 74488eb1-b71f-4515-88e1-cdd03b6f8225
caps.latest.revision: 23
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 27ee6e3c63a086ad2371350baddd038a93f36794
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="alloca"></a>_alloca

Aloca memória na pilha. Essa função é preterida porque uma versão mais segura está disponível. consulte [malloca](malloca.md).

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

O **alloca** rotina retorna um **void** ponteiro para o espaço alocado, é garantido para ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto. Se *tamanho* é 0, **alloca** aloca um item de comprimento zero e retorna um ponteiro válido para esse item.

Uma exceção de excedente de pilha será gerada se não for possível alocar o espaço. A exceção de excedente de pilha não é uma exceção de C++; ela é uma exceção estruturada. Em vez de usar o tratamento de exceções de C++, você deve usar a [SEH](../../cpp/structured-exception-handling-c-cpp.md) (Manipulação de Exceção Estruturada).

## <a name="remarks"></a>Comentários

**alloca** aloca *tamanho* bytes da pilha de programa. O espaço alocado é liberado automaticamente quando a função de chamada for encerrada (não quando a alocação simplesmente passa fora do escopo). Portanto, não passe o valor do ponteiro retornado por **alloca** como um argumento para [livre](free.md).

Há restrições ao chamar explicitamente **alloca** em um manipulador de exceção (EH). As rotinas do EH que são executadas em processadores da classe x86 operam em seu próprio quadro de memória: elas realizam suas tarefas no espaço de memória que não é baseado no local atual do ponteiro de pilha da função delimitadora. As implementações mais comuns incluem SEH (Manipulação de Exceção Estruturada ) do Windows NT e expressões de cláusula catch de C++. Portanto, chamar explicitamente **alloca** em qualquer um dos seguintes resultados de cenários de falha de programa durante o retorno para chamar a rotina EH:

- Expressão de filtro de exceção SEH Windows NT: `__except ( _alloca() )`

- Manipulador de exceção final SEH Windows NT: `__finally { _alloca() }`

- Expressão da cláusula catch do EH de C++

No entanto, **alloca** pode ser chamado diretamente de dentro de uma rotina EH ou de um retorno de chamada fornecida pelo aplicativo que é invocado por um dos cenários de EH listados anteriormente.

> [!IMPORTANT]
> No Windows XP, se **alloca** é chamado dentro de um bloco try/catch, você deve chamar [resetstkoflw](resetstkoflw.md) em um bloco catch.

Além das restrições anteriores, ao usar o[/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) opção **alloca** não pode ser usado em **EXCEPT** blocos. Para obter mais informações, consulte [/clr Restrições](../../build/reference/clr-restrictions.md).

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
