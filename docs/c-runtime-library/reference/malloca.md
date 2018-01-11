---
title: _malloca | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _malloca
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
dev_langs: C++
helpviewer_keywords:
- memory allocation, stack
- malloca function
- _malloca function
ms.assetid: 293992df-cfca-4bc9-b313-0a733a6bb936
caps.latest.revision: "27"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: fcdeab9e61eda17164be06498e9ce42695faf8ea
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="malloca"></a>_malloca
Aloca memória na pilha. Esta é uma versão de [_alloca](../../c-runtime-library/reference/alloca.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_malloca(   
   size_t size   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `size`  
 Bytes a serem alocados da pilha.  
  
## <a name="return-value"></a>Valor de retorno  
 A rotina `_malloca` retorna um ponteiro `void` para o espaço alocado, que deve ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto. Se `size` for 0, o `_malloca` alocará um item de comprimento zero e retornará um ponteiro válido para esse item.  
  
 Uma exceção de excedente de pilha será gerada se não for possível alocar o espaço. A exceção de excedente de pilha não é uma exceção de C++; ela é uma exceção estruturada. Em vez de usar o tratamento de exceções de C++, você deve usar a [SEH](../../cpp/structured-exception-handling-c-cpp.md) (Manipulação de Exceção Estruturada).  
  
## <a name="remarks"></a>Comentários  
 O `_malloca` alocará `size` bytes da pilha ou do heap do programa se a solicitação exceder um determinado tamanho em bytes fornecidos pelo `_ALLOCA_S_THRESHOLD`. A diferença entre `_malloca` e `_alloca` é que o `_alloca` sempre aloca na pilha, independentemente do tamanho. Ao contrário de `_alloca`, que não exige ou permite que uma chamada para `free` libere a memória alocada, `_malloca` exige o uso de [_freea](../../c-runtime-library/reference/freea.md) para liberar memória. No modo de depuração, o `_malloca` sempre aloca memória do heap.  
  
 Há restrições para chamar `_malloca` explicitamente em um EH (manipulador de exceção). As rotinas do EH que são executadas em processadores da classe x86 operam em seu próprio quadro de memória: elas realizam suas tarefas no espaço de memória que não é baseado no local atual do ponteiro de pilha da função delimitadora. As implementações mais comuns incluem SEH (Manipulação de Exceção Estruturada ) do Windows NT e expressões de cláusula catch de C++. Portanto, chamar `_malloca` explicitamente em qualquer um dos seguintes cenários resulta em falha do programa durante o retorno ao chamar a rotina EH:  
  
-   Expressão de filtro de exceção SEH do Windows NT: `__except` (`_malloca ()` )  
  
-   Manipulador de exceção final do Windows NT SEH: `__finally` {`_malloca ()` }  
  
-   Expressão da cláusula catch do EH de C++  
  
 No entanto, `_malloca` pode ser chamado diretamente de dentro de uma rotina do EH ou de um retorno de chamada fornecido pelo aplicativo, que é invocado por um dos cenários do EH listados anteriormente.  
  
> [!IMPORTANT]
>  No Windows XP, se `_malloca` for chamado dentro de um bloco try/catch, você deverá chamar [resetstkoflw](../../c-runtime-library/reference/resetstkoflw.md) no bloco catch.  
  
 Além das restrições acima, ao usar a opção [/clr (Compilação Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md), o `_malloca` não poderá ser usado nos blocos `__except`. Para obter mais informações, consulte [/clr Restrições](../../build/reference/clr-restrictions.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_malloca`|\<malloc.h>|  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
```  
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
  
## <a name="input"></a>Entrada  
  
```  
1000  
```  
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
Enter the number of bytes to allocate using _malloca: 1000  
```  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [_resetstkoflw](../../c-runtime-library/reference/resetstkoflw.md)