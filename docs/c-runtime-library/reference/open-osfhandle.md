---
title: _open_osfhandle | Microsoft Docs
ms.custom: ''
ms.date: 05/29/2018
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
ms.openlocfilehash: af3783420389dc008e39c818c39406f0b2af8af5
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34569830"
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

O **open_osfhandle** função aloca um descritor de arquivo de tempo de execução do C e a associa o identificador de arquivo do sistema operacional especificado pelo *osfhandle*. Para evitar um aviso do compilador, converter o *osfhandle* argumento de **tratar** para **intptr_t**. O *sinalizadores* argumento é uma expressão de inteiro formada de um ou mais das constantes de manifesto definidos no \<fcntl.h >. Quando duas ou mais constantes de manifesto são usados para formar o *sinalizadores* argumento, as constantes são combinadas com o operador OR bit a bit ( **&#124;** ).

Constantes de manifesto são definidos no \<fcntl.h >:

|||
|-|-|
**\_O\_APPEND**|Posiciona um ponteiro de arquivo no final do arquivo, antes de cada operação de gravação.
**\_O\_RDONLY**|Abre o arquivo para somente leitura.
**\_O\_TEXT**|Abre o arquivo no modo de texto (convertido).
**\_O\_WTEXT**|Abre o arquivo no modo Unicode (convertido em UTF-16).

O **open_osfhandle** chamada transfere a propriedade do identificador de arquivo do Win32 para o descritor de arquivo. Para fechar um arquivo aberto com **open_osfhandle**, chame [ \_fechar](close.md). O identificador de arquivo do sistema operacional subjacente também é fechado por uma chamada para **echar**, portanto, não é necessário chamar a função Win32 **CloseHandle** no identificador do original. Se o descritor de arquivo pertence a um **arquivo &#42;**  fluxo, em seguida, chamar [fclose](fclose-fcloseall.md) naquele **arquivo &#42;**  fluxo também fecha ambos o descritor de arquivo e o Identificador subjacente. Nesse caso, não chame **echar** no descritor de arquivo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_open_osfhandle**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
