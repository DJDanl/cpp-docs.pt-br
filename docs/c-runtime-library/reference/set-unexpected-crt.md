---
title: set_unexpected (CRT)
ms.date: 11/04/2016
api_name:
- set_unexpected
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- set_unexpected
helpviewer_keywords:
- set_unexpected function
- unexpected function
- exception handling, termination
ms.assetid: ebcef032-4771-48e5-88aa-2a1ab8750aa6
ms.openlocfilehash: 77c8f0ae8c64423a656a2ebbe1fe3ef6dbe1b794
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70948298"
---
# <a name="set_unexpected-crt"></a>set_unexpected (CRT)

Instala sua próprio função de terminação a ser chamada por **unexpected**.

## <a name="syntax"></a>Sintaxe

```cpp
unexpected_function set_unexpected( unexpected_function unexpFunction );
```

### <a name="parameters"></a>Parâmetros

*unexpFunction*<br/>
Ponteiro para uma função que você escreve para substituir a função **inesperada** .

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a função de encerramento anterior registrada por **_set_unexpected** para que a função anterior possa ser restaurada posteriormente. Se nenhuma função anterior tiver sido definida, o valor de retorno poderá ser usado para restaurar o comportamento padrão; Esse valor pode ser **nulo**.

## <a name="remarks"></a>Comentários

A função **set_unexpected** instala *unexpFunction* como a função chamada por **inesperado**. **inesperado** não é usado na C++ implementação atual do tratamento de exceções. O tipo **unexpected_function** é definido em eh. H como um ponteiro para uma função inesperada definida pelo usuário, *unexpFunction* que retorna **void**. Sua função *unexpFunction* personalizada não deve retornar ao chamador.

```cpp
typedef void ( *unexpected_function )( );
```

Por padrão, as chamadas **inesperadas** **terminam**. Você pode alterar esse comportamento padrão escrevendo sua própria função de encerramento e chamando **set_unexpected** com o nome da sua função como seu argumento. chamadas **inesperadas** a última função fornecida como um argumento para **set_unexpected**.

Ao contrário da função de encerramento personalizada instalada por uma chamada para **set_terminate**, uma exceção pode ser lançada de dentro de *unexpFunction*.

Em um ambiente multithreaded, funções inesperadas são mantidas separadamente para cada thread. Cada novo thread precisa instalar sua própria função inesperada. Portanto, cada thread é responsável por sua própria manipulação de evento inesperado.

Na implementação atual da Microsoft do C++ tratamento de exceções, chamadas **inesperadas** **terminam** por padrão e nunca são chamadas pela biblioteca de tempo de execução de tratamento de exceções. Não há nenhuma vantagem específica para chamar **inesperado** em vez de **terminar**.

Há um único manipulador **set_unexpected** para todas as DLLs ou EXEs vinculados dinamicamente; mesmo que você chame **set_unexpected** , seu manipulador poderá ser substituído por outro ou que você esteja substituindo um conjunto definido por outro dll ou exe.

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
