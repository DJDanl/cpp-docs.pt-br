---
title: set_terminate (CRT) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- set_terminate function
- terminate function
- exception handling, termination
ms.assetid: 3ff1456a-7898-44bc-9266-a328a80b6006
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 017ea9d96cef9065ff82e7f3428e725b816c9319
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="setterminate-crt"></a>set_terminate (CRT)

Instala a sua própria rotina de término deve ser chamado por **encerrar**.

## <a name="syntax"></a>Sintaxe

```cpp
terminate_function set_terminate( terminate_function termFunction );
```

### <a name="parameters"></a>Parâmetros

*termFunction*<br/>
Ponteiro para uma função de encerramento que você escreve.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a função anterior registrada por **set_terminate** para que a função anterior pode ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor retornado poderá ser usado para restaurar o comportamento padrão; esse valor pode ser NULL.

## <a name="remarks"></a>Comentários

O **set_terminate** função instala *termFunction* como a função chamada **encerrar**. **set_terminate** é usado com o tratamento de exceções C++ e pode ser chamado a qualquer momento em seu programa antes que a exceção é gerada. **encerrar** chamadas [anular](abort.md) por padrão. Você pode alterar esse padrão escrevendo sua própria função de encerramento e chamar **set_terminate** com o nome da sua função como seu argumento. **encerrar** chama a função último fornecida como um argumento para **set_terminate**. Depois de executar qualquer desejado tarefas de limpeza, *termFunction* deve sair do programa. Se ele não existir (se ele retorna ao chamador), [anular](abort.md) é chamado.

Em um ambiente multithreaded, funções de encerramento são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função de encerramento. Portanto, cada thread é responsável por sua própria manipulação de encerramento.

O **terminate_function** tipo está definido em EH. H como um ponteiro para uma função definida pelo usuário encerramento, *termFunction* que retorna **void**. A função personalizada *termFunction* pode não usam argumentos e não deve retornar ao chamador. Em caso afirmativo, [anular](abort.md) é chamado. Não pode ser acionada uma exceção no *termFunction*.

```cpp
typedef void ( *terminate_function )( );
```

> [!NOTE]
> O **set_terminate** função só funciona fora do depurador.

Há um único **set_terminate** manipulador para todos os vinculadas dinamicamente DLLs ou EXEs; mesmo se você chamar **set_terminate** o manipulador pode ser substituído por outro, ou você pode substituir um manipulador definido por outro DLL ou EXE.

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
