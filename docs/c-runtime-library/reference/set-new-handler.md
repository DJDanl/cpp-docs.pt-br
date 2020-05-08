---
title: _set_new_handler
ms.date: 4/2/2020
api_name:
- _set_new_handler
- _o__set_new_handler
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
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _set_new_handler
- set_new_handler
helpviewer_keywords:
- _set_new_handler function
- set_new_handler function
- error handling
- transferring control to error handler
ms.assetid: 1d1781b6-5cf8-486a-b430-f365e0bb023f
ms.openlocfilehash: 06da25fb38d18691f78973f4e63a8b7b48d98ce1
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82913968"
---
# <a name="_set_new_handler"></a>_set_new_handler

Transfere o controle ao mecanismo de gerenciamento de erros caso o operador **new** não consiga alocar memória.

## <a name="syntax"></a>Sintaxe

```cpp
_PNH _set_new_handler( _PNH pNewHandler );
```

### <a name="parameters"></a>Parâmetros

*pNewHandler*<br/>
Ponteiro para a função de manipulação de memória fornecida pelo aplicativo. Um argumento de 0 faz com que o novo manipulador seja removido.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a função de manipulação de exceção anterior registrada por **_set_new_handler**, para que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor de retorno poderá ser usado para restaurar o comportamento padrão; Esse valor pode ser **nulo**.

## <a name="remarks"></a>Comentários

A função **_set_new_handler** do C++ especifica uma função de tratamento de exceção que obtém controle se o **novo** operador falhar ao alocar memória. Se o **novo** falhar, o sistema de tempo de execução chamará automaticamente a função de tratamento de exceção que foi passada como um argumento para **_set_new_handler**. **_PNH**, definido em New. h, é um ponteiro para uma função que retorna o tipo **int** e usa um argumento do tipo **size_t**. Use **size_t** para especificar a quantidade de espaço a ser alocada.

Não há nenhum manipulador padrão.

**_set_new_handler** é essencialmente um esquema de coleta de lixo. O sistema de tempo de execução repete a alocação cada vez que a função retorna um valor diferente de zero e falha se a função retorna 0.

Uma ocorrência da função **_set_new_handler** em um programa registra a função de tratamento de exceção especificada na lista de argumentos com o sistema de tempo de execução:

```cpp
// set_new_handler1.cpp
By default, this function's global state is scoped to the application. To change this, see [Global state in the CRT](../global-state.md).

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

Você pode salvar o endereço da função que foi passado pela última vez para a função **_set_new_handler** e restabelecê-lo mais tarde:

```cpp
   _PNH old_handler = _set_new_handler( my_handler );
   // Code that requires my_handler
   // . . .
   _set_new_handler( old_handler )
   // Code that requires old_handler
   // . . .
```

A função de C++ [set_new_mode](set-new-mode.md) define o novo modo do manipulador para [malloc](malloc.md). O novo modo de manipulador indica se, em caso de falha, **malloc** é chamar a nova rotina do manipulador, conforme definido por **_set_new_handler**. Por padrão, o **malloc** não chama a nova rotina do manipulador em caso de falha para alocar memória. Você pode substituir esse comportamento padrão para que, quando **malloc** não alocar memória, **malloc** chame a nova rotina do manipulador da mesma maneira que o **novo** operador faz quando ele falha pelo mesmo motivo. Para substituir o padrão, chame:

```cpp
_set_new_mode(1);
```

no início de seu programa ou vincule com Newmode.obj.

Se um definido pelo `operator new` usuário for fornecido, as novas funções do manipulador não serão automaticamente chamadas em caso de falha.

Para obter mais informações, consulte [new](../../cpp/new-operator-cpp.md) e [delete](../../cpp/delete-operator-cpp.md) na *Referência da linguagem C++*.

Há um único manipulador de **_set_new_handler** para todos os executáveis ou DLLs vinculados dinamicamente; mesmo que você chame **_set_new_handler** seu manipulador pode ser substituído por outro ou que você esteja substituindo um conjunto definido por outra DLL ou executável.

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

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[informações](free.md)<br/>
[realloc](realloc.md)<br/>
