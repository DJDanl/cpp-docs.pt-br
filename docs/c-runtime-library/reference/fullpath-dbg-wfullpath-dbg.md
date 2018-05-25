---
title: _fullpath_dbg, _wfullpath_dbg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _wfullpath_dbg
- _fullpath_dbg
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
- wfullpath_dbg
- _wfullpath_dbg
- _fullpath_dbg
- fullpath_dbg
dev_langs:
- C++
helpviewer_keywords:
- _fullpath_dbg function
- relative file paths
- absolute paths
- fullpath_dbg function
- _wfullpath_dbg function
- wfullpath_dbg function
ms.assetid: 81f72f85-07da-4f5c-866a-598e0fb03f6b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d04f3d7b53eca27d38a38b0bce284c17b15cae02
ms.sourcegitcommit: 6e3cf8df676d59119ce88bf5321d063cf479108c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/22/2018
---
# <a name="fullpathdbg-wfullpathdbg"></a>_fullpath_dbg, _wfullpath_dbg

Versões do [FullPath, wfullpath](fullpath-wfullpath.md) que usam a versão de depuração **malloc** ao alocar memória.

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

### <a name="parameters"></a>Parâmetros

*absPath*<br/>
Ponteiro para um buffer que contém o nome de caminho absoluto ou completo, ou **nulo**.

*relPath*<br/>
Nome de caminho relativo.

*maxLength*<br/>
Comprimento máximo do buffer de nome de caminho absoluto (*absPath*). Esse comprimento é em bytes para **FullPath** , mas em caracteres largos (**wchar_t**) para **wfullpath**.

*blockType*<br/>
Tipo de bloco de memória solicitado: **client_block** ou **normal_block**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que a operação de alocação solicitada ou **nulo**.

*linenumber*<br/>
Número no arquivo de origem em que a operação de alocação foi solicitada da linha ou **nulo**.

## <a name="return-value"></a>Valor de retorno

Cada função retorna um ponteiro para um buffer que contém o nome de caminho absoluto (*absPath*). Se houver um erro (por exemplo, se o valor passado na *relPath* inclui uma letra de unidade que não é válido ou não pode ser encontrada, ou se o comprimento do nome do caminho absoluto criado (*absPath*) é maior que *maxLength*) retorna a função **nulo**.

## <a name="remarks"></a>Comentários

O **fullpath_dbg** e **wfullpath_dbg** funções são idênticas aos **FullPath** e **wfullpath** exceto que, quando **Debug** é definida, essas funções usam a versão de depuração **malloc**, **malloc_dbg**para alocar memória se **nulo** é passado como o primeiro parâmetro. Para obter informações sobre os recursos de depuração **malloc_dbg**, consulte [malloc_dbg](malloc-dbg.md).

Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir o **crtdbg_map_alloc** sinalizador. Quando **crtdbg_map_alloc** é definida, chamadas para **FullPath** e **wfullpath** são remapeados para **fullpath_dbg** e **wfullpath_dbg**, respectivamente, com o *blockType* definida como **normal_block**. Assim, você não precisa chamar essas funções explicitamente, a menos que você deseja marcar os blocos de heap como **client_block**. Para obter mais informações, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).

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

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_fullpath, _wfullpath](fullpath-wfullpath.md)<br/>
[Versões de depuração de funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)<br/>
