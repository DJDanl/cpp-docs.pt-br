---
title: _open_osfhandle | Microsoft Docs
ms.custom: ''
ms.date: 12/12/2017
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _open_osfhandle
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _open_osfhandle
- open_osfhandle
dev_langs:
- C++
helpviewer_keywords:
- open_osfhandle function
- file handles [C++], associating
- _open_osfhandle function
ms.assetid: 30d94df4-7868-4667-a401-9eb67ecb7855
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: beb8c074beeb47274fbae21ea293d0ea55f28d36
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="openosfhandle"></a>_open_osfhandle

Associa um descritor de arquivo de tempo de execução C a um identificador de arquivo do sistema operacional existente.

## <a name="syntax"></a>Sintaxe

```cpp
int _open_osfhandle (
   intptr_t osfhandle,
   int flags
);
```

### <a name="parameters"></a>Parâmetros

*osfhandle*<br/>
Identificador de arquivo do sistema operacional.

*flags*<br/>
Tipos de operações permitidas.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **open_osfhandle** retorna um descritor de arquivo de tempo de execução C. Caso contrário, retornará -1.

## <a name="remarks"></a>Comentários

O **open_osfhandle** função aloca um descritor de arquivo de tempo de execução do C e a associa o identificador de arquivo do sistema operacional especificado pelo *osfhandle*. O *sinalizadores* argumento é uma expressão de inteiro formada de um ou mais das constantes de manifesto definidas em Fcntl.h. Quando duas ou mais constantes de manifesto são usados para formar o *sinalizadores* argumento, as constantes são combinadas com o operador OR bit a bit ( **&#124;** ).

Fcntl.h define as seguintes constantes de manifesto:

**\_O\_APPEND** posiciona um ponteiro de arquivo para o final do arquivo antes de cada operação de gravação.

**\_O\_RDONLY** abre o arquivo para acesso somente leitura.

**\_O\_texto** abre o arquivo no modo de texto (convertido).

**\_O\_WTEXT** abre o arquivo no modo Unicode (UTF-16 traduzido).

Para fechar um arquivo aberto com **open_osfhandle**, chame [ \_fechar](close.md). O identificador de arquivo do sistema operacional subjacente também é fechado por uma chamada para **echar**, portanto, não é necessário chamar a função Win32 **CloseHandle** no identificador do original. Se o descritor de arquivo pertence a um **arquivo &#42;**  fluxo, em seguida, chamar [fclose](fclose-fcloseall.md) naquele **arquivo &#42;**  fluxo também fecha ambos o descritor de arquivo e o Identificador subjacente. Nesse caso, não chame **echar** no descritor de arquivo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_open_osfhandle**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
