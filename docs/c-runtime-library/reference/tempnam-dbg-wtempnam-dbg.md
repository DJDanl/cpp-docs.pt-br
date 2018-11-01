---
title: _tempnam_dbg, _wtempnam_dbg
ms.date: 11/04/2016
apiname:
- _wtempnam_dbg
- _tempnam_dbg
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
- wtempnam_dbg
- tempnam_dbg
- _tempnam_dbg
- _wtempnam_dbg
helpviewer_keywords:
- file names [C++], creating temporary
- tempnam_dbg function
- temporary files, creating
- file names [C++], temporary
- wtempnam_dbg function
- _tempnam_dbg function
- _wtempnam_dbg function
ms.assetid: e3760bb4-bb01-4808-b689-2c45af56a170
ms.openlocfilehash: 804c8ad1f17c6ee1df563cafc69ee7aef494d1cb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50596450"
---
# <a name="tempnamdbg-wtempnamdbg"></a>_tempnam_dbg, _wtempnam_dbg

Versões de função de [tempnam, wtempnam, tmpnam, wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md) que usam a versão de depuração **malloc**, **malloc_dbg**.

## <a name="syntax"></a>Sintaxe

```C
char *_tempnam_dbg(
   const char *dir,
   const char *prefix,
   int blockType,
   const char *filename,
   int linenumber
);
wchar_t *_wtempnam_dbg(
   const wchar_t *dir,
   const wchar_t *prefix,
   int blockType,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*dir*<br/>
O caminho usado no nome de arquivo, se não houver variável de ambiente TMP ou se TMP não for um diretório válido.

*prefix*<br/>
A cadeia de caracteres que será pré-anexada a nomes retornados pelo **tempnam**.

*blockType*<br/>
Tipo de bloco de memória solicitado: **client_block** ou **normal_block**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nulo**.

## <a name="return-value"></a>Valor de retorno

Cada função retorna um ponteiro para o nome gerado ou **nulo** se houver uma falha. Falha pode ocorrer se houver um nome de diretório inválido especificado na variável de ambiente TMP e nos *dir* parâmetro.

> [!NOTE]
> **livre** (ou **free_dbg**) precisa ser chamado para ponteiros alocados por **tempnam_dbg** e **wtempnam_dbg**.

## <a name="remarks"></a>Comentários

O **tempnam_dbg** e **wtempnam_dbg** funções são idênticas às **tempnam** e **wtempnam** , exceto que, quando **Debug** é definido, essas funções usam a versão de depuração **malloc** e **malloc_dbg**para alocar memória se **nulo** é passado como o primeiro parâmetro. Para obter mais informações, consulte [_malloc_dbg](malloc-dbg.md).

Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir o sinalizador **crtdbg_map_alloc**. Quando **crtdbg_map_alloc** for definido, chamadas para **tempnam** e **wtempnam** são remapeadas para **tempnam_dbg** e **_ wtempnam_dbg**, respectivamente, com o *blockType* definido como **normal_block**. Portanto, você não precisa chamar essas funções explicitamente, a menos que você deseja marcar os blocos de heap como **client_block**. Para obter mais informações, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_ttempnam_dbg**|**_tempnam_dbg**|**_tempnam_dbg**|**_wtempnam_dbg**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**tempnam_dbg**, **wtempnam_dbg**|\<crtdbg.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[_tempnam, _wtempnam, tmpnam, _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)<br/>
[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Versões de depuração de funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)<br/>
