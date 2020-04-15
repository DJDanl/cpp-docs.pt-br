---
title: set_terminate (CRT)
ms.date: 4/2/2020
api_name:
- set_terminate
- _o_set_terminate
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- set_terminate
helpviewer_keywords:
- set_terminate function
- terminate function
- exception handling, termination
ms.assetid: 3ff1456a-7898-44bc-9266-a328a80b6006
ms.openlocfilehash: 08ea5bb8c446fadac6a7bcf7ca172c5d14546776
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332096"
---
# <a name="set_terminate-crt"></a>set_terminate (CRT)

Instala sua própria rotina de término para ser chamada por **terminar**.

## <a name="syntax"></a>Sintaxe

```cpp
terminate_function set_terminate( terminate_function termFunction );
```

### <a name="parameters"></a>Parâmetros

*Termfunction*<br/>
Ponteiro para uma função de encerramento que você escreve.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a função anterior registrada por **set_terminate** para que a função anterior possa ser restaurada mais tarde. Se nenhuma função anterior tiver sido definida, o valor de retorno poderá ser usado para restaurar o comportamento padrão; este valor pode ser **NULO**.

## <a name="remarks"></a>Comentários

A função **set_terminate** instala *o termoFunção* como a função chamada por **terminar**. **set_terminate** é usado com o tratamento de exceção C++ e pode ser chamado a qualquer momento do seu programa antes que a exceção seja lançada. **encerrar** chamadas [abortam](abort.md) por padrão. Você pode alterar esse padrão escrevendo sua própria função de rescisão e chamando **set_terminate** com o nome de sua função como seu argumento. **acabar** chama a última função dada como argumento para **set_terminate**. Depois de executar quaisquer tarefas de limpeza desejadas, *termFunction* deve sair do programa. Se ele não sair (se ele retornar ao seu chamador), [abortar](abort.md) é chamado.

Em um ambiente multithreaded, funções de encerramento são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função de encerramento. Portanto, cada thread é responsável por sua própria manipulação de encerramento.

O **tipo terminate_function** é definido em EH. H como ponteiro para uma função de terminação definida pelo usuário, *termoFunção* que retorna **vazio**. Seu termo função *personalizadaFunction* não pode ter argumentos e não deve retornar ao seu chamador. Se isso acontecer, [abortar](abort.md) é chamado. Uma exceção não pode ser lançada dentro do *prazoFunção*.

```cpp
typedef void ( *terminate_function )( );
```

> [!NOTE]
> A função **set_terminate** só funciona fora do depurador.

Existe um único manipulador **de set_terminate** para todos os DLLs ou EXEs dinamicamente ligados; mesmo se você ligar **para set_terminate** seu manipulador pode ser substituído por outro, ou você pode estar substituindo um manipulador definido por outro DLL ou EXE.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**set_terminate**|\<eh.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [terminate](terminate-crt.md).

## <a name="see-also"></a>Confira também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)<br/>
[Abortar](abort.md)<br/>
[_get_terminate](get-terminate.md)<br/>
[Set_unexpected](set-unexpected-crt.md)<br/>
[Terminar](terminate-crt.md)<br/>
[Inesperado](unexpected-crt.md)<br/>
