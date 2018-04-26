---
title: set_unexpected (CRT) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- set_unexpected function
- unexpected function
- exception handling, termination
ms.assetid: ebcef032-4771-48e5-88aa-2a1ab8750aa6
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c740f74dc13ea22819d0f792bfc1e3dbcc9f425e
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="setunexpected-crt"></a>set_unexpected (CRT)

Instala sua próprio função de terminação a ser chamada por **unexpected**.

## <a name="syntax"></a>Sintaxe

```cpp
unexpected_function set_unexpected( unexpected_function unexpFunction );
```

### <a name="parameters"></a>Parâmetros

*unexpFunction*<br/>
Ponteiro para uma função que você grava para substituir o **inesperado** função.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a função de encerramento anterior registrado por **_set_unexpected** para que a função anterior pode ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor retornado poderá ser usado para restaurar o comportamento padrão; esse valor pode ser NULL.

## <a name="remarks"></a>Comentários

O **set_unexpected** função instala *unexpFunction* como a função chamada **inesperado**. **inesperado** não é usado na implementação atual de manipulação de exceção de C++. O **unexpected_function** tipo está definido em EH. H como um ponteiro para uma função inesperado definida pelo usuário, *unexpFunction* que retorna **void**. Personalizados *unexpFunction* função não deve retornar ao chamador.

```cpp
typedef void ( *unexpected_function )( );
```

Por padrão, **inesperado** chamadas **encerrar**. Você pode alterar esse comportamento padrão ao escrever sua própria função de encerramento e chamar **set_unexpected** com o nome da sua função como seu argumento. **inesperado** chama a função último fornecida como um argumento para **set_unexpected**.

Diferentemente da função de encerramento personalizado instalada por uma chamada para **set_terminate**, uma exceção pode ser gerada no *unexpFunction*.

Em um ambiente multithreaded, funções inesperadas são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função inesperada. Portanto, cada thread é responsável por sua própria manipulação de evento inesperado.

Na implementação atual do Microsoft C++ de tratamento de exceções, **inesperado** chamadas **encerrar** por padrão e nunca é chamado pela biblioteca de tempo de execução de tratamento de exceção. Não há nenhuma vantagem específica para chamar **inesperado** em vez de **encerrar**.

Há um único **set_unexpected** manipulador para todos os vinculadas dinamicamente DLLs ou EXEs; mesmo se você chamar **set_unexpected** o manipulador pode ser substituído por outro ou que você está substituindo um manipulador definido por outro DLL ou EXE.

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
