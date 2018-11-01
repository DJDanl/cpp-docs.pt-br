---
title: set_unexpected (CRT)
ms.date: 11/04/2016
apiname:
- set_unexpected
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
- set_unexpected
helpviewer_keywords:
- set_unexpected function
- unexpected function
- exception handling, termination
ms.assetid: ebcef032-4771-48e5-88aa-2a1ab8750aa6
ms.openlocfilehash: 6c38421e447ca7b3f263148f51f0ade5c59e2804
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50484221"
---
# <a name="setunexpected-crt"></a>set_unexpected (CRT)

Instala sua próprio função de terminação a ser chamada por **unexpected**.

## <a name="syntax"></a>Sintaxe

```cpp
unexpected_function set_unexpected( unexpected_function unexpFunction );
```

### <a name="parameters"></a>Parâmetros

*unexpFunction*<br/>
Ponteiro para uma função que você escreve para substituir a **inesperado** função.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a função de terminação anterior registrado por **_set_unexpected** para que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor retornado pode ser usado para restaurar o comportamento padrão; Esse valor pode ser **nulo**.

## <a name="remarks"></a>Comentários

O **set_unexpected** função instala *unexpFunction* como a função chamada por **inesperado**. **inesperado** não é usado na implementação atual de manipulação de exceção do C++. O **unexpected_function** tipo é definido em EH. H como um ponteiro para uma função inesperada definida pelo usuário, *unexpFunction* que retorna **void**. O personalizado *unexpFunction* função não deve retornar a seu chamador.

```cpp
typedef void ( *unexpected_function )( );
```

Por padrão, **inesperado** chamadas **encerrar**. Você pode alterar esse comportamento padrão escrevendo sua própria função de encerramento e chamar **set_unexpected** com o nome da sua função como seu argumento. **inesperado** chama a função last especificada como um argumento para **set_unexpected**.

Diferentemente da função de encerramento personalizada instalada por uma chamada para **set_terminate**, uma exceção pode ser gerada do interior *unexpFunction*.

Em um ambiente multithreaded, funções inesperadas são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função inesperada. Portanto, cada thread é responsável por sua própria manipulação de evento inesperado.

Na implementação da Microsoft de tratamento de exceções do C++ **inesperado** chamadas **encerrar** por padrão e nunca é chamado pela biblioteca em tempo de execução de manipulação de exceção. Não há nenhuma vantagem em particular a chamar **inesperado** vez **encerrar**.

Há um único **set_unexpected** manipulador para dinamicamente todas as DLLs ou EXEs vinculados; mesmo se você chamar **set_unexpected** o manipulador poderá ser substituído por outro ou que você está substituindo um manipulador definido por outra DLL ou EXE.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**set_unexpected**|\<eh.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Rotinas de tratamento de exceções](../../c-runtime-library/exception-handling-routines.md)<br/>
[abort](abort.md)<br/>
[_get_unexpected](get-unexpected.md)<br/>
[set_terminate](set-terminate-crt.md)<br/>
[terminate](terminate-crt.md)<br/>
[unexpected](unexpected-crt.md)<br/>
