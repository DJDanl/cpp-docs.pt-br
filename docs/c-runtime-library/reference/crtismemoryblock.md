---
title: _CrtIsMemoryBlock
ms.date: 11/04/2016
api_name:
- _CrtIsMemoryBlock
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
- CrtlsMemoryBlock
- _CrtIsMemoryBlock
helpviewer_keywords:
- _CrtIsMemoryBlock function
- CrtIsMemoryBlock function
ms.assetid: f7cbbc60-3690-4da0-a07b-68fd7f250273
ms.openlocfilehash: f29745acd06f6f5b3fa96367444e800bdc3e8e3a
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70938733"
---
# <a name="_crtismemoryblock"></a>_CrtIsMemoryBlock

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

*userData*<br/>
Ponteiro para o início do bloco de memória a ser verificado.

*size*<br/>
Tamanho do bloco especificado (em bytes).

*requestNumber*<br/>
Ponteiro para o número de alocação do bloco ou **NULL**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou o bloco ou **nulo**.

*linenumber*<br/>
Ponteiro para o número de linha no arquivo de origem ou **nulo**.

## <a name="return-value"></a>Valor de retorno

**_CrtIsMemoryBlock** retornará **true** se o bloco de memória especificado estiver localizado no heap local e tiver um identificador de tipo de bloco de heap de depuração válido; caso contrário, a função retornará **false**.

## <a name="remarks"></a>Comentários

A função **_CrtIsMemoryBlock** verifica se um bloco de memória especificado está localizado no heap local do aplicativo e se ele tem um identificador de tipo de bloco válido. Essa função também pode ser usada para obter o número de ordem de alocação do objeto e o nome do arquivo de origem/número de linha em que a alocação de bloco de memória foi originalmente solicitada. A passagem de valores não**nulos** para os parâmetros *requestNumber*, *filename*ou *LineNumber* faz com que **_CrtIsMemoryBlock** defina esses parâmetros para os valores no cabeçalho de depuração do bloco de memória, caso encontre o bloco no heap local. Quando [_DEBUG](../../c-runtime-library/debug.md) não é definido, as chamadas para **_CrtIsMemoryBlock** são removidas durante o pré-processamento.

Se **_CrtIsMemoryBlock** falhar, ele retornará **false** e os parâmetros de saída serão inicializados para valores padrão: *requestNumber* e **LineNumber** serão definidos como 0 e *filename* será definido como **NULL**.

Como essa função retorna **TRUE** ou **FALSE**, ela pode ser passada para uma das macros [_ASSERT](assert-asserte-assert-expr-macros.md) para criar um mecanismo simples de tratamento de erro de depuração. O seguinte exemplo causa uma falha de asserção se o endereço especificado não está localizado no heap local:

```C
_ASSERTE( _CrtIsMemoryBlock( userData, size, &requestNumber,
          &filename, &linenumber ) );
```

Para obter mais informações sobre como o **_CrtIsMemoryBlock** pode ser usado com outras funções e macros de depuração, consulte [macros para relatórios](/visualstudio/debugger/macros-for-reporting). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).

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
