---
title: _CrtIsMemoryBlock
ms.date: 11/04/2016
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
helpviewer_keywords:
- _CrtIsMemoryBlock function
- CrtIsMemoryBlock function
ms.assetid: f7cbbc60-3690-4da0-a07b-68fd7f250273
ms.openlocfilehash: c4a85ebeb45552c6f5355853de2a45766d6bc984
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62339891"
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

*userData*<br/>
Ponteiro para o início do bloco de memória a ser verificado.

*size*<br/>
Tamanho do bloco especificado (em bytes).

*requestNumber*<br/>
Ponteiro para o número de alocação do bloco ou **nulo**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou o bloco ou **nulo**.

*linenumber*<br/>
Ponteiro para o número de linha no arquivo de origem ou **nulo**.

## <a name="return-value"></a>Valor de retorno

**Crtismemoryblock** retorna **verdadeira** se o bloco de memória especificado está localizado no heap local e tem um identificador de tipo de bloco de heap de depuração válido; caso contrário, a função retornará **FALSE**.

## <a name="remarks"></a>Comentários

O **crtismemoryblock** função verifica se um bloco de memória especificado está localizado no heap local do aplicativo e se ele tem um identificador de tipo de bloco válido. Essa função também pode ser usada para obter o número de ordem de alocação do objeto e o nome do arquivo de origem/número de linha em que a alocação de bloco de memória foi originalmente solicitada. Passagem de não -**nulo** os valores para o *requestNumber*, *filename*, ou *linenumber* causas parâmetros **_ CrtIsMemoryBlock** para definir esses parâmetros para os valores no cabeçalho de depuração do bloco de memória, se ele encontrar o bloco no heap local. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtismemoryblock** são removidas durante o pré-processamento.

Se **crtismemoryblock** falhar, retornará **falso** e os parâmetros de saída são inicializados para valores padrão: *requestNumber* e **lineNumber**  são definidos como 0 e *filename* é definido como **nulo**.

Como essa função retorna **TRUE** ou **FALSE**, ela pode ser passada para uma das macros [_ASSERT](assert-asserte-assert-expr-macros.md) para criar um mecanismo simples de tratamento de erro de depuração. O seguinte exemplo causa uma falha de asserção se o endereço especificado não está localizado no heap local:

```C
_ASSERTE( _CrtIsMemoryBlock( userData, size, &requestNumber,
          &filename, &linenumber ) );
```

Para obter mais informações sobre como **crtismemoryblock** pode ser usado com outras macros e funções de depuração, consulte [Macros para relatórios](/visualstudio/debugger/macros-for-reporting). Para obter informações sobre como os blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes do heap de depuração CRT](/visualstudio/debugger/crt-debug-heap-details).

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
