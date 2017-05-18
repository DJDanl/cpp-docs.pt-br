---
title: _set_new_handler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 17
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
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: c8a3b6e7df9f46ebf299f2fe5472461f1944b055
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="setnewhandler"></a>_set_new_handler
Transfere o controle ao mecanismo de gerenciamento de erros se o operador `new` não conseguir alocar memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_PNH _set_new_handler(  
   _PNH pNewHandler   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pNewHandler`  
 Ponteiro para a função de manipulação de memória fornecida pelo aplicativo. Um argumento de 0 faz com que o novo manipulador seja removido.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a função de manipulação de exceção anterior registrada por `_set_new_handler`, de modo que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor retornado poderá ser usado para restaurar o comportamento padrão; esse valor pode ser `NULL`.  
  
## <a name="remarks"></a>Comentários  
 A função `_set_new_handler` C++ é usada para especificar uma função de manipulação de exceção que assumirá o controle se o operador `new` falhar ao alocar memória. Se `new` falhar, o sistema de tempo de execução chamará automaticamente a função de manipulação de exceção que foi passada como um argumento para `_set_new_handler`. `_PNH`, definido em New.h, é um ponteiro para uma função que retorna o tipo `int` e leva um argumento do tipo `size_t`. Use `size_t` para especificar a quantidade de espaço a ser alocado.  
  
 Não há nenhum manipulador padrão.  
  
 `_set_new_handler` é essencialmente um esquema de coleta de lixo. O sistema de tempo de execução repete a alocação cada vez que a função retorna um valor diferente de zero e falha se a função retorna 0.  
  
 Uma ocorrência da função `_set_new_handler` em um programa registra a função de manipulação de exceção especificada na lista de argumentos com o sistema de tempo de execução:  
  
```  
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
  
 Você pode salvar o último endereço de função a ser passado para a função `_set_new_handler` e restabelecê-lo mais tarde:  
  
```  
_PNH old_handler = _set_new_handler( my_handler );  
   // Code that requires my_handler  
   _set_new_handler( old_handler )  
   // Code that requires old_handler  
```  
  
 A função de C++ [set_new_mode](../../c-runtime-library/reference/set-new-mode.md) define o novo modo do manipulador para [malloc](../../c-runtime-library/reference/malloc.md). O novo modo do manipulador indica se, em caso de falha, `malloc` deverá chamar a nova rotina do manipulador, conforme definido por `_set_new_handler`. Por padrão, `malloc` não chama a nova rotina do manipulador em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando `malloc` falhar ao alocar memória, `malloc` chame a nova rotina do manipulador da mesma forma que o operador `new` fará quando ele falhar pelo mesmo motivo. Para substituir o padrão, chame:  
  
```  
_set_new_mode(1)  
```  
  
 no início de seu programa ou vincule com Newmode.obj.  
  
 Se um usuário definido `operator new` for fornecido, as novas funções de manipulador não forem chamadas automaticamente em caso de falha.  
  
 Para obter mais informações, consulte [new](../../cpp/new-operator-cpp.md) e [delete](../../cpp/delete-operator-cpp.md) na *Referência da linguagem C++*.  
  
 Há um único manipulador `_set_new_handler` para todas as DLLs ou executáveis vinculados dinamicamente; mesmo que você chame `_set_new_handler`, o manipulador poderá ser substituído por outro caso você esteja substituindo um manipulador definido por outra DLL ou executável.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_set_new_handler`|\<new.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, quando a alocação falhar, o controle será transferido para MyNewHandler. O argumento passado para MyNewHandler é o número de bytes solicitado. O valor retornado de MyNewHandler é um sinalizador que indica se a tentativa de alocação deve ser repetida: um valor diferente de zero indica que a tentativa de alocação deve ser repetida, enquanto um valor zero indica que a alocação falhou.  
  
```  
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
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [calloc](../../c-runtime-library/reference/calloc.md)   
 [free](../../c-runtime-library/reference/free.md)   
 [realloc](../../c-runtime-library/reference/realloc.md)
