---
title: _CrtIsMemoryBlock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _CrtIsMemoryBlock
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
- CrtlsMemoryBlock
- _CrtIsMemoryBlock
dev_langs:
- C++
helpviewer_keywords:
- _CrtIsMemoryBlock function
- CrtIsMemoryBlock function
ms.assetid: f7cbbc60-3690-4da0-a07b-68fd7f250273
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a556ef0ade8e336efaca64b79c86c41cc9643c9a
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="crtismemoryblock"></a>_CrtIsMemoryBlock

Verifica se um bloco de memória especificado está no heap local e se ele tem um identificador de tipo de bloco de heap de depuração válido (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
int _CrtIsMemoryBlock(
   const void *userData,
   unsigned int size,
   long *requestNumber,
   char **filename,
   int *linenumber
);
```

### <a name="parameters"></a>Parâmetros

*Dados do usuário*<br/>
Ponteiro para o início do bloco de memória a ser verificado.

*size*<br/>
Tamanho do bloco especificado (em bytes).

*requestNumber*<br/>
Ponteiro para o número de alocação do bloco ou **nulo**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou o bloco ou **nulo**.

*linenumber*<br/>
Ponteiro para o número da linha no arquivo de origem ou **nulo**.

## <a name="return-value"></a>Valor de retorno

**Crtismemoryblock** retorna **TRUE** se o bloco de memória especificado está localizado dentro de heap local e tem um identificador de tipo de bloco de heap de depuração válido; caso contrário, a função retornará **FALSE**.

## <a name="remarks"></a>Comentários

O **crtismemoryblock** função verifica se um bloco de memória especificado está localizado na pilha de local do aplicativo e se ele tem um identificador de tipo de bloco válido. Essa função também pode ser usada para obter o número de ordem de alocação do objeto e o nome do arquivo de origem/número de linha em que a alocação de bloco de memória foi originalmente solicitada. Passando valores não nulos para a *requestNumber*, *filename*, ou *linenumber* causas parâmetros **crtismemoryblock** para definir Esses parâmetros para os valores no bloco de memória de depuração cabeçalho, se ele encontrar o bloco na pilha de local. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtismemoryblock** são removidos durante o pré-processamento.

Se **crtismemoryblock** falhar, ele retorna **FALSE** e os parâmetros de saída são inicializados para valores padrão: *requestNumber* e **lineNumber**  são definidos como 0 e *filename* é definido como **nulo**.

Como essa função retorna **TRUE** ou **FALSE**, ela pode ser passada para uma das macros [_ASSERT](assert-asserte-assert-expr-macros.md) para criar um mecanismo simples de tratamento de erro de depuração. O seguinte exemplo causa uma falha de asserção se o endereço especificado não está localizado no heap local:

```C
_ASSERTE( _CrtIsMemoryBlock( userData, size, &requestNumber,
          &filename, &linenumber ) );
```

Para obter mais informações sobre como **crtismemoryblock** pode ser usado com outras funções de depuração e macros, consulte [Macros para relatórios](/visualstudio/debugger/macros-for-reporting). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtIsMemoryBlock**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Consulte o exemplo do tópico [_CrtIsValidHeapPointer](crtisvalidheappointer.md).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
