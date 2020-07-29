---
title: _resetstkoflw
ms.date: 4/2/2020
api_name:
- _resetstkoflw
- _o__resetstkoflw
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- resetstkoflw
- _resetstkoflw
helpviewer_keywords:
- resetstkoflw function
- stack overflow
- stack, recovering
- _resetstkoflw function
ms.assetid: 319529cd-4306-4d22-810b-2063f3ad9e14
ms.openlocfilehash: 6f4d5d930ebdc487c3c2bcc2f93494a25528c438
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216772"
---
# <a name="_resetstkoflw"></a>_resetstkoflw

Recupera o excedente de pilha.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _resetstkoflw( void );
```

## <a name="return-value"></a>Valor retornado

Será diferente de zero se a função obtiver êxito, zero se ela falhar.

## <a name="remarks"></a>Comentários

A função **_resetstkoflw** recupera de uma condição de estouro de pilha, permitindo que um programa continue em vez de falhar com um erro de exceção fatal. Se a função **_resetstkoflw** não for chamada, não haverá nenhuma página de proteção após a exceção anterior. Na próxima vez que houver um excedente de pilha, não haverá qualquer exceção e o processo terminará sem aviso.

Se um thread em um aplicativo causa uma exceção **EXCEPTION_STACK_OVERFLOW**, o thread deixou sua pilha em um estado danificado. Isso é diferente de outras exceções como **EXCEPTION_ACCESS_VIOLATION** ou **EXCEPTION_INT_DIVIDE_BY_ZERO**, nas quais a pilha não está danificada. A pilha é definida para um valor arbitrariamente pequeno quando o programa é carregado pela primeira vez. Em seguida, a pilha aumenta conforme a demanda para atender às necessidades do thread. Isso é implementado colocando uma página com acesso PAGE_GUARD no final da pilha atual. Para obter mais informações, consulte [Criando páginas de proteção](/windows/win32/Memory/creating-guard-pages).

Quando o código faz com que o ponteiro de pilha aponte para um endereço nessa página, ocorre uma exceção e o sistema executa as três ações a seguir:

- Remove a proteção de PAGE_GUARD na página de proteção para que o thread possa ler e gravar dados na memória.

- Aloca uma nova página de proteção que é localizada uma página abaixo da última.

- Executa novamente a instrução que gerou a exceção.

Dessa forma, o sistema pode aumentar o tamanho da pilha do thread automaticamente. Cada thread em um processo tem um tamanho máximo de pilha. O tamanho da pilha é definido no tempo de compilação pelo [/STACK (alocações da pilha)](../../build/reference/stack-stack-allocations.md) ou pela instrução [STACKSIZE](../../build/reference/stacksize.md) no arquivo .def para o projeto.

Quando esse tamanho de pilha máximo for excedido, o sistema executa as três ações a seguir:

- Remove a proteção de PAGE_GUARD na página de proteção, conforme descrito anteriormente.

- Tenta alocar uma nova página de proteção abaixo da última. No entanto, isso falhará porque o tamanho da pilha máximo foi excedido.

- Gera uma exceção para que o thread possa manipulá-lo no bloco de exceção.

Observe que, nesse ponto, a pilha não tem uma página de proteção. Na próxima vez que o programa aumentar totalmente a pilha até o fim, onde deveria haver uma página de proteção, o programa grava além do fim da pilha e causa uma violação de acesso.

Chame **_resetstkoflw** para restaurar a página de proteção sempre que a recuperação for feita após uma exceção de estouro de pilha. Essa função pode ser chamada de dentro do corpo principal de um **`__except`** bloco ou fora de um **`__except`** bloco. No entanto, há algumas restrições sobre quando isso deve ser usado. **_resetstkoflw** nunca deve ser chamado de:

- Uma expressão de filtro.

- Uma função de filtro.

- Uma função chamada de uma função de filtro.

- Um **`catch`** bloco.

- Um **`__finally`** bloco.

Nesses pontos, a pilha ainda não está suficientemente organizada.

Exceções de estouro de pilha são geradas como exceções estruturadas, não exceções C++, portanto **_resetstkoflw** não é útil em um **`catch`** bloco comum porque ela não capturará uma exceção de estouro de pilha. No entanto, se [_set_se_translator](set-se-translator.md) for usado para implementar um conversor de exceção estruturada que gera exceções C++ (como no segundo exemplo), uma exceção de excedente de pilha resulta em uma exceção C++ que pode ser manipulada por um bloco catch de C++.

Não é seguro chamar **_resetstkoflw** em um bloco catch de C++ que é alcançado de uma exceção gerada pela função do conversor de exceção estruturada. Nesse caso, o espaço de pilha não é liberado e o ponteiro de pilha não é redefinido até estar fora do bloco catch, embora os destruidores tenham sido chamados para todos os objetos destrutíveis antes do bloco catch. Essa função não deve ser chamada até o espaço de pilha ser liberado e o ponteiro de pilha ser redefinido. Portanto, ele deve ser chamado somente depois de sair do bloco catch. Como o menor espaço na pilha possível deve ser usado no bloco catch devido ao excedente de pilha que ocorre no bloco catch que está tentando se recuperar de um excedente de pilha anterior não é recuperável e pode fazer com que o programa pare de responder enquanto o excedente no bloco catch dispara uma exceção que é em si manipulada pelo mesmo bloco catch.

Há situações em que **_resetstkoflw** pode falhar mesmo se usadas em um local correto, como em um **`__except`** bloco. Se, mesmo depois do desenrolamento da pilha, ainda não houver espaço de pilha suficiente para executar **_resetstkoflw** sem gravar na última página da pilha, **_resetstkoflw** não conseguirá redefinir a última página da pilha como a página de proteção e retornará 0, indicando falha. Portanto, o uso seguro desta função deve incluir a verificação do valor retornado em vez de supor que é seguro usar a pilha.

A manipulação de exceção estruturada não capturará uma exceção **STATUS_STACK_OVERFLOW** quando o aplicativo for compilado com **/CLR** (consulte [/CLR (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_resetstkoflw**|\<malloc.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

**Bibliotecas:** todas as versões dos [Recursos da Biblioteca CRT](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

O exemplo a seguir mostra o uso recomendado da função **_resetstkoflw** .

```C
// crt_resetstkoflw.c
// Launch program with and without arguments to observe
// the difference made by calling _resetstkoflw.

#include <malloc.h>
#include <stdio.h>
#include <windows.h>

void recursive(int recurse)
{
   _alloca(2000);
   if (recurse)
      recursive(recurse);
}

// Filter for the stack overflow exception.
// This function traps the stack overflow exception, but passes
// all other exceptions through.
int stack_overflow_exception_filter(int exception_code)
{
   if (exception_code == EXCEPTION_STACK_OVERFLOW)
   {
       // Do not call _resetstkoflw here, because
       // at this point, the stack is not yet unwound.
       // Instead, signal that the handler (the __except block)
       // is to be executed.
       return EXCEPTION_EXECUTE_HANDLER;
   }
   else
       return EXCEPTION_CONTINUE_SEARCH;
}

int main(int ac)
{
   int i = 0;
   int recurse = 1, result = 0;

   for (i = 0 ; i < 10 ; i++)
   {
      printf("loop #%d\n", i + 1);
      __try
      {
         recursive(recurse);

      }

      __except(stack_overflow_exception_filter(GetExceptionCode()))
      {
         // Here, it is safe to reset the stack.

         if (ac >= 2)
         {
            puts("resetting stack overflow");
            result = _resetstkoflw();
         }
      }

      // Terminate if _resetstkoflw failed (returned 0)
      if (!result)
         return 3;
   }

   return 0;
}
```

Exemplo de saída sem argumentos de programa:

```Output
loop #1
```

O programa para de responder sem executar nenhuma outra iteração.

Com argumentos do programa:

```Output
loop #1
resetting stack overflow
loop #2
resetting stack overflow
loop #3
resetting stack overflow
loop #4
resetting stack overflow
loop #5
resetting stack overflow
loop #6
resetting stack overflow
loop #7
resetting stack overflow
loop #8
resetting stack overflow
loop #9
resetting stack overflow
loop #10
resetting stack overflow
```

### <a name="description"></a>Descrição

O exemplo a seguir mostra o uso recomendado de **_resetstkoflw** em um programa em que as exceções estruturadas são convertidas em exceções do C++.

### <a name="code"></a>Código

```cpp
// crt_resetstkoflw2.cpp
// compile with: /EHa
// _set_se_translator requires the use of /EHa
#include <malloc.h>
#include <stdio.h>
#include <windows.h>
#include <eh.h>

class Exception { };

class StackOverflowException : Exception { };

// Because the overflow is deliberate, disable the warning that
// this function will cause a stack overflow.
#pragma warning (disable: 4717)
void CauseStackOverflow (int i)
{
    // Overflow the stack by allocating a large stack-based array
    // in a recursive function.
    int a[10000];
    printf("%d ", i);
    CauseStackOverflow (i + 1);
}

void __cdecl SEHTranslator (unsigned int code, _EXCEPTION_POINTERS*)
{
    // For stack overflow exceptions, throw our own C++
    // exception object.
    // For all other exceptions, throw a generic exception object.
    // Use minimal stack space in this function.
    // Do not call _resetstkoflw in this function.

    if (code == EXCEPTION_STACK_OVERFLOW)
        throw StackOverflowException ( );
    else
        throw Exception( );
}

int main ( )
{
    bool stack_reset = false;
    bool result = false;

    // Set up a function to handle all structured exceptions,
    // including stack overflow exceptions.
    _set_se_translator (SEHTranslator);

    try
    {
        CauseStackOverflow (0);
    }
    catch (StackOverflowException except)
    {
        // Use minimal stack space here.
        // Do not call _resetstkoflw here.
        printf("\nStack overflow!\n");
        stack_reset = true;
    }
    catch (Exception except)
    {
        // Do not call _resetstkoflw here.
        printf("\nUnknown Exception!\n");
    }
    if (stack_reset)
    {
        result = _resetstkoflw();
        // If stack reset failed, terminate the application.
        if (result == 0)
            exit(1);
    }

    void* pv = _alloca(100000);
    printf("Recovered from stack overflow and allocated 100,000 bytes"
           " using _alloca.");

    return 0;
}
```

```Output
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
Stack overflow!
Recovered from stack overflow and allocated 100,000 bytes using _alloca.
```

## <a name="see-also"></a>Confira também

[_alloca](alloca.md)<br/>
