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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 70ed4adb7ceada53205fd69f111c8976fe95c711
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234010"
---
# <a name="set_terminate-crt"></a>set_terminate (CRT)

Instala sua própria rotina de encerramento a ser chamada pelo **encerramento**.

## <a name="syntax"></a>Sintaxe

```cpp
terminate_function set_terminate( terminate_function termFunction );
```

### <a name="parameters"></a>parâmetros

*termFunction*<br/>
Ponteiro para uma função de encerramento que você escreve.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para a função anterior registrada por **set_terminate** para que a função anterior possa ser restaurada mais tarde. Se nenhuma função anterior tiver sido definida, o valor de retorno poderá ser usado para restaurar o comportamento padrão; Esse valor pode ser **nulo**.

## <a name="remarks"></a>Comentários

A função **set_terminate** instala *termFunction* como a função chamada por **Terminate**. **set_terminate** é usado com a manipulação de exceção do C++ e pode ser chamado em qualquer ponto do programa antes que a exceção seja lançada. **encerrar** chamadas [abortar](abort.md) por padrão. Você pode alterar esse padrão escrevendo sua própria função de encerramento e chamando **set_terminate** com o nome da sua função como seu argumento. **Terminate** chama a última função fornecida como um argumento para **set_terminate**. Depois de executar as tarefas de limpeza desejadas, o *termFunction* deve sair do programa. Se ele não sair (se retornar ao chamador), [Abort](abort.md) será chamado.

Em um ambiente multithreaded, funções de encerramento são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função de encerramento. Portanto, cada thread é responsável por sua própria manipulação de encerramento.

O tipo de **terminate_function** é definido em eh. H como um ponteiro para uma função de encerramento definida pelo usuário, *termFunction* que retorna **`void`** . Sua função personalizada *termFunction* pode não usar argumentos e não deve retornar ao chamador. Se tiver, [Abort](abort.md) será chamado. Uma exceção não pode ser lançada de dentro de *termFunction*.

```cpp
typedef void ( *terminate_function )( );
```

> [!NOTE]
> A função **set_terminate** só funciona fora do depurador.

Há um único manipulador de **set_terminate** para todas as DLLs ou EXEs vinculados dinamicamente; mesmo que você chame **set_terminate** seu manipulador pode ser substituído por outro, ou você pode estar substituindo um conjunto definido por outro dll ou exe.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**set_terminate**|\<eh.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [terminate](terminate-crt.md).

## <a name="see-also"></a>Confira também

[Rotinas de manipulação de exceção](../../c-runtime-library/exception-handling-routines.md)<br/>
[abort](abort.md)<br/>
[_get_terminate](get-terminate.md)<br/>
[set_unexpected](set-unexpected-crt.md)<br/>
[encerrar](terminate-crt.md)<br/>
[previsto](unexpected-crt.md)<br/>
