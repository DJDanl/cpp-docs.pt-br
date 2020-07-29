---
title: _fullpath_dbg, _wfullpath_dbg
ms.date: 11/04/2016
api_name:
- _wfullpath_dbg
- _fullpath_dbg
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
- wfullpath_dbg
- _wfullpath_dbg
- _fullpath_dbg
- fullpath_dbg
helpviewer_keywords:
- _fullpath_dbg function
- relative file paths
- absolute paths
- fullpath_dbg function
- _wfullpath_dbg function
- wfullpath_dbg function
ms.assetid: 81f72f85-07da-4f5c-866a-598e0fb03f6b
ms.openlocfilehash: b728090c201c9c5d07cc2f1bec4f53b1682e0e92
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220672"
---
# <a name="_fullpath_dbg-_wfullpath_dbg"></a>_fullpath_dbg, _wfullpath_dbg

Versões do [_fullpath, _wfullpath](fullpath-wfullpath.md) que usam a versão de depuração de **malloc** para alocar memória.

## <a name="syntax"></a>Sintaxe

```C
char *_fullpath_dbg(
   char *absPath,
   const char *relPath,
   size_t maxLength,
   int blockType,
   const char *filename,
   int linenumber
);
wchar_t *_wfullpath_dbg(
   wchar_t *absPath,
   const wchar_t *relPath,
   size_t maxLength,
   int blockType,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>parâmetros

*absPath*<br/>
Ponteiro para um buffer que contém o nome do caminho absoluto ou completo, ou **NULL**.

*relPath*<br/>
Nome de caminho relativo.

*Determinado*<br/>
Comprimento máximo do buffer de nome de caminho absoluto (*absPath*). Esse comprimento é em bytes para **_fullpath** , mas em caracteres largos ( **`wchar_t`** ) para **_wfullpath**.

*blockType*<br/>
Tipo de bloco de memória solicitado: **_CLIENT_BLOCK** ou **_NORMAL_BLOCK**.

*nome do arquivo*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*LineNumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nula**.

## <a name="return-value"></a>Valor retornado

Cada função retorna um ponteiro para um buffer que contém o nome do caminho absoluto (*absPath*). Se houver um erro (por exemplo, se o valor passado em *RelPath* incluir uma letra de unidade que não seja válida ou não puder ser encontrada, ou se o comprimento do nome do caminho absoluto criado (*absPath*) for maior que *MaxLength*) a função retornará **NULL**.

## <a name="remarks"></a>Comentários

As funções **_fullpath_dbg** e **_wfullpath_dbg** são idênticas a **_fullpath** e **_wfullpath** , exceto que, quando **_DEBUG** é definido, essas funções usam a versão de depuração de **malloc**, **_malloc_dbg**, para alocar memória se **NULL** for passado como o primeiro parâmetro. Para obter informações sobre os recursos de depuração do **_malloc_dbg**, consulte [_malloc_dbg](malloc-dbg.md).

Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir o sinalizador de **_CRTDBG_MAP_ALLOC** . Quando **_CRTDBG_MAP_ALLOC** é definido, as chamadas para **_fullpath** e **_wfullpath** são remapeadas para **_fullpath_dbg** e **_wfullpath_dbg**, respectivamente, com o *blockType* definido como **_NORMAL_BLOCK**. Portanto, você não precisa chamar essas funções explicitamente, a menos que queira marcar os blocos de heap como **_CLIENT_BLOCK**. Para obter mais informações, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tfullpath_dbg**|**_fullpath_dbg**|**_fullpath_dbg**|**_wfullpath_dbg**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_fullpath_dbg**|\<crtdbg.h>|
|**_wfullpath_dbg**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Manipulação de arquivos](../../c-runtime-library/file-handling.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[Versões de depuração das funções de alocação da pilha](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)<br/>
