---
title: _set_new_handler | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _set_new_handler
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _set_new_handler
- set_new_handler
dev_langs:
- C++
helpviewer_keywords:
- _set_new_handler function
- set_new_handler function
- error handling
- transferring control to error handler
ms.assetid: 1d1781b6-5cf8-486a-b430-f365e0bb023f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 30cd0c2a991ec046b0b1f55100c58641833cb992
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="setnewhandler"></a>_set_new_handler

Transfere o controle ao mecanismo de gerenciamento de erros caso o operador **new** não consiga alocar memória.

## <a name="syntax"></a>Sintaxe

```cpp
_PNH _set_new_handler( _PNH pNewHandler );
```

### <a name="parameters"></a>Parâmetros

*pNewHandler*<br/>
Ponteiro para a função de manipulação de memória fornecida pelo aplicativo. Um argumento de 0 faz com que o novo manipulador seja removido.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a função registrada por tratamento de exceção anterior **set_new_handler**, de modo que a função anterior pode ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor de retorno pode ser usado para restaurar o comportamento padrão; Esse valor pode ser **nulo**.

## <a name="remarks"></a>Comentários

O C++ **set_new_handler** função especifica uma função de manipulação de exceção que obtiver controle se o **novo** operador falha ao alocar memória. Se **novo** falhar, o sistema de tempo de execução automaticamente chama a função de tratamento de exceção que foi passada como um argumento para **set_new_handler**. **Pnh**, definido em New.h, é um ponteiro para uma função que retorna tipo **int** e usa um argumento de tipo **size_t**. Use **size_t** para especificar a quantidade de espaço a ser alocado.

Não há nenhum manipulador padrão.

**set_new_handler** é essencialmente um esquema de coleta de lixo. O sistema de tempo de execução repete a alocação cada vez que a função retorna um valor diferente de zero e falha se a função retorna 0.

Uma ocorrência da **set_new_handler** função em um programa registra a função de manipulação de exceção especificada na lista de argumentos com o sistema de tempo de execução:

```cpp
// set_new_handler1.cpp
#include <new.h>

int handle_program_memory_depletion( size_t )
{
   // Your code
}

int main( void )
{
   _set_new_handler( handle_program_memory_depletion );
   int *pi = new int[BIG_NUMBER];
}
```

Você pode salvar o endereço da função última passado para o **set_new_handler** de função e reabilitá-la mais tarde:

```cpp
   _PNH old_handler = _set_new_handler( my_handler );
   // Code that requires my_handler
   // . . .
   _set_new_handler( old_handler )
   // Code that requires old_handler
   // . . .
```

A função de C++ [set_new_mode](set-new-mode.md) define o novo modo do manipulador para [malloc](malloc.md). O novo modo de manipulador indica se, em caso de falha **malloc** é chamar a rotina do manipulador de novo conforme definido pela **set_new_handler**. Por padrão, **malloc** não chamar a rotina do manipulador de novo em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando **malloc** Falha ao alocar memória, **malloc** chama a rotina do manipulador de novo na mesma forma que o **novo** does de operador Quando falhar pela mesma razão. Para substituir o padrão, chame:

```cpp
_set_new_mode(1);
```

no início de seu programa ou vincule com Newmode.obj.

Se um usuário definido `operator new` for fornecido, as novas funções de manipulador não forem chamadas automaticamente em caso de falha.

Para obter mais informações, consulte [new](../../cpp/new-operator-cpp.md) e [delete](../../cpp/delete-operator-cpp.md) na *Referência da linguagem C++*.

Há um único **set_new_handler** manipulador para todos os vinculadas dinamicamente DLLs ou executáveis; mesmo se você chamar **set_new_handler** o manipulador pode ser substituído por outro ou que você está substituindo um manipulador definido por outro DLL ou executável.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_new_handler**|\<new.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Neste exemplo, quando a alocação falhar, o controle será transferido para MyNewHandler. O argumento passado para MyNewHandler é o número de bytes solicitado. O valor retornado de MyNewHandler é um sinalizador que indica se a tentativa de alocação deve ser repetida: um valor diferente de zero indica que a tentativa de alocação deve ser repetida, enquanto um valor zero indica que a alocação falhou.

```cpp
// crt_set_new_handler.cpp
// compile with: /c
#include <stdio.h>
#include <new.h>
#define BIG_NUMBER 0x1fffffff

int coalesced = 0;

int CoalesceHeap()
{
   coalesced = 1;  // Flag RecurseAlloc to stop
   // do some work to free memory
   return 0;
}
// Define a function to be called if new fails to allocate memory.
int MyNewHandler( size_t size )
{
   printf("Allocation failed. Coalescing heap.\n");

   // Call a function to recover some heap space.
   return CoalesceHeap();
}

int RecurseAlloc() {
   int *pi = new int[BIG_NUMBER];
   if (!coalesced)
      RecurseAlloc();
   return 0;
}

int main()
{
   // Set the failure handler for new to be MyNewHandler.
   _set_new_handler( MyNewHandler );
   RecurseAlloc();
}
```

```Output
Allocation failed. Coalescing heap.

This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.
```

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[free](free.md)<br/>
[realloc](realloc.md)<br/>
