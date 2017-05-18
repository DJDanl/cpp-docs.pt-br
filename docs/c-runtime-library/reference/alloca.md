---
title: alloca | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 5875a26dc5758674665fba2fde5b51c2ff53420e
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="alloca"></a>_alloca
Aloca memória na pilha. Essa função é preterida porque uma versão mais segura está disponível. consulte [malloca](../../c-runtime-library/reference/malloca.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_alloca(   
   size_t size   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `size`  
 Bytes a serem alocados da pilha.  
  
## <a name="return-value"></a>Valor de retorno  
 A rotina `_alloca` retorna um ponteiro `void` para o espaço alocado, que deve ser alinhado adequadamente para o armazenamento de qualquer tipo de objeto. Se `size` for 0, o `_alloca` alocará um item de comprimento zero e retornará um ponteiro válido para esse item.  
  
 Uma exceção de excedente de pilha será gerada se não for possível alocar o espaço. A exceção de excedente de pilha não é uma exceção de C++; ela é uma exceção estruturada. Em vez de usar o tratamento de exceções de C++, você deve usar a [SEH](../../cpp/structured-exception-handling-c-cpp.md) (Manipulação de Exceção Estruturada).  
  
## <a name="remarks"></a>Comentários  
 `_alloca`aloca `size` bytes da pilha de programa. O espaço alocado é liberado automaticamente quando a função de chamada for encerrada (não quando a alocação simplesmente passa fora do escopo). Portanto, não passe o valor do ponteiro retornado por `_alloca` como um argumento para [livre](../../c-runtime-library/reference/free.md).  
  
 Há restrições para chamar `_alloca` explicitamente em um EH (manipulador de exceção). As rotinas do EH que são executadas em processadores da classe x86 operam em seu próprio quadro de memória: elas realizam suas tarefas no espaço de memória que não é baseado no local atual do ponteiro de pilha da função delimitadora. As implementações mais comuns incluem SEH (Manipulação de Exceção Estruturada ) do Windows NT e expressões de cláusula catch de C++. Portanto, chamar `_alloca` explicitamente em qualquer um dos seguintes cenários resulta em falha do programa durante o retorno ao chamar a rotina EH:  
  
-   Expressão de filtro de exceção SEH do Windows NT: `__except` (`_alloca ()` )  
  
-   Manipulador de exceção final do Windows NT SEH: `__finally` {`_alloca ()` }  
  
-   Expressão da cláusula catch do EH de C++  
  
 No entanto, `_alloca` pode ser chamado diretamente de dentro de uma rotina do EH ou de um retorno de chamada fornecido pelo aplicativo, que é invocado por um dos cenários do EH listados anteriormente.  
  
> [!IMPORTANT]
>  No Windows XP, se `_alloca` for chamado dentro de um bloco try/catch, você deverá chamar [resetstkoflw](../../c-runtime-library/reference/resetstkoflw.md) no bloco catch.  
  
 Além das restrições anteriores, ao usar o[/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) opção `_alloca` não pode ser usado em `__except` blocos. Para obter mais informações, consulte [/clr Restrições](../../build/reference/clr-restrictions.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_alloca`|\<malloc.h>|  
  
## <a name="example"></a>Exemplo  
  
```  
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
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [malloc](../../c-runtime-library/reference/malloc.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)   
 [resetstkoflw](../../c-runtime-library/reference/resetstkoflw.md)   
 [_malloca](../../c-runtime-library/reference/malloca.md)
