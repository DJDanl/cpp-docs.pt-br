---
title: _malloca
ms.date: 11/04/2016
api_name:
- _malloca
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
- malloca
- _malloca
helpviewer_keywords:
- memory allocation, stack
- malloca function
- _malloca function
ms.assetid: 293992df-cfca-4bc9-b313-0a733a6bb936
ms.openlocfilehash: 0b12b4adde710f2fc46b3a3790519006fabbb1fc
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70952768"
---
# <a name="_malloca"></a>_malloca

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

A rotina **_malloca** retorna um ponteiro **void** para o espaço alocado, que tem a garantia de estar alinhada adequadamente para o armazenamento de qualquer tipo de objeto. Se *size* for 0, **_malloca** aloca um item de comprimento zero e retorna um ponteiro válido para esse item.

Se *size* for maior que **_ALLOCA_S_THRESHOLD**, **_malloca** tentará alocar no heap e retornará um ponteiro NULL se o espaço não puder ser alocado. Se *size* for menor ou igual a **_ALLOCA_S_THRESHOLD**, **_malloca** tentará alocar na pilha, e uma exceção de estouro de pilha será gerada se o espaço não puder ser alocado. A exceção de estouro de pilha C++ não é uma exceção; é uma exceção estruturada. Em vez de C++ usar a manipulação de exceções, você deve usar o SEH ( [manipulação de exceção estruturada](../../cpp/structured-exception-handling-c-cpp.md) ) para capturar essa exceção.

## <a name="remarks"></a>Comentários

**_malloca** aloca os bytes de *tamanho* da pilha de programa ou do heap se a solicitação exceder um determinado tamanho em bytes fornecidos por **_ALLOCA_S_THRESHOLD**. A diferença entre **_malloca** e **_alloca** é que **_alloca** sempre aloca na pilha, independentemente do tamanho. Ao contrário de **_alloca**, que não exige ou permite uma chamada **para livre para liberar a** memória, portanto alocada, **_malloca** requer o uso de [_freea](freea.md) para liberar memória. No modo de depuração, o **_malloca** sempre aloca memória a partir do heap.

Há restrições para chamar explicitamente **_malloca** em um eh (manipulador de exceção). As rotinas de EH executadas em processadores de classe x86 operam em seu próprio quadro de memória: Eles executam suas tarefas no espaço de memória que não se baseiam no local atual do ponteiro de pilha da função de circunscrição. As implementações mais comuns incluem SEH (Manipulação de Exceção Estruturada ) do Windows NT e expressões de cláusula catch de C++. Portanto, chamar explicitamente **_malloca** em qualquer um dos cenários a seguir resulta em falha do programa durante o retorno para a rotina de chamada eh:

- Expressão de filtro de exceção SEH do Windows NT`_malloca ()` : __except ()

- Manipulador de exceção final de SEH do Windows NT`_malloca ()` : __finally {}

- Expressão da cláusula catch do EH de C++

No entanto, o **_malloca** pode ser chamado diretamente de dentro de uma rotina de eh ou de um retorno de chamada fornecido pelo aplicativo que é invocado por um dos cenários de eh listados anteriormente.

> [!IMPORTANT]
> No Windows XP, se **_malloca** for chamado dentro de um bloco try/catch, você deverá chamar [_resetstkoflw](resetstkoflw.md) no bloco catch.

Além das restrições acima, ao usar a opção [/CLR (compilação em tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) , **_malloca** não pode ser usado em blocos **__except** . Para obter mais informações, consulte [/clr Restrições](../../build/reference/clr-restrictions.md).

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
