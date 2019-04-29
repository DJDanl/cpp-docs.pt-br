---
title: set_terminate (CRT)
ms.date: 11/04/2016
apiname:
- set_terminate
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
- set_terminate
helpviewer_keywords:
- set_terminate function
- terminate function
- exception handling, termination
ms.assetid: 3ff1456a-7898-44bc-9266-a328a80b6006
ms.openlocfilehash: 7be81dec7fba80a273d635cbd30b96b09928bc66
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62356440"
---
# <a name="setterminate-crt"></a>set_terminate (CRT)

Instala sua própria rotina de terminação a ser chamado pelo **encerrar**.

## <a name="syntax"></a>Sintaxe

```cpp
terminate_function set_terminate( terminate_function termFunction );
```

### <a name="parameters"></a>Parâmetros

*termFunction*<br/>
Ponteiro para uma função de encerramento que você escreve.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a função anterior registrada por **set_terminate** para que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor retornado pode ser usado para restaurar o comportamento padrão; Esse valor pode ser **nulo**.

## <a name="remarks"></a>Comentários

O **set_terminate** função instala *termFunction* como a função chamada por **encerrar**. **set_terminate** é usado com C++ tratamento de exceção e pode ser chamado a qualquer momento em seu programa antes que a exceção seja lançada. **encerrar** chamadas [anular](abort.md) por padrão. Você pode alterar esse padrão escrevendo sua própria função de encerramento e chamar **set_terminate** com o nome da sua função como seu argumento. **encerrar** chama a função last especificada como um argumento para **set_terminate**. Depois de executar quaisquer tarefas de limpeza, desejadas *termFunction* deve sair do programa. Se ele não é encerrado (se ele retorna para seu chamador), [anular](abort.md) é chamado.

Em um ambiente multithreaded, funções de encerramento são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função de encerramento. Portanto, cada thread é responsável por sua própria manipulação de encerramento.

O **terminate_function** tipo é definido em EH. H como um ponteiro para uma função de encerramento definida pelo usuário, *termFunction* que retorna **void**. A função personalizada *termFunction* não pode levar argumentos e não deve retornar a seu chamador. Se isso acontecer, [anular](abort.md) é chamado. Uma exceção não pode ser lançada de dentro *termFunction*.

```cpp
typedef void ( *terminate_function )( );
```

> [!NOTE]
> O **set_terminate** função só funciona fora do depurador.

Há um único **set_terminate** manipulador para dinamicamente todas as DLLs ou EXEs vinculados; mesmo se você chamar **set_terminate** o manipulador poderá ser substituído por outro, ou que você esteja substituindo um manipulador definido por outro DLL ou EXE.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**set_terminate**|\<eh.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [terminate](terminate-crt.md).

## <a name="see-also"></a>Consulte também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)<br/>
[abort](abort.md)<br/>
[_get_terminate](get-terminate.md)<br/>
[set_unexpected](set-unexpected-crt.md)<br/>
[terminate](terminate-crt.md)<br/>
[unexpected](unexpected-crt.md)<br/>
