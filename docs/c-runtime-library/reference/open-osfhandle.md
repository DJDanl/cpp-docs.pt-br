---
title: _open_osfhandle | Microsoft Docs
ms.custom: 
ms.date: 12/12/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _open_osfhandle
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
dev_langs: C++
helpviewer_keywords:
- open_osfhandle function
- file handles [C++], associating
- _open_osfhandle function
ms.assetid: 30d94df4-7868-4667-a401-9eb67ecb7855
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ff05c99180ff8933316e1db9366da3b985c10305
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

*osfhandle*  
Identificador de arquivo do sistema operacional.

*flags*  
Tipos de operações permitidas.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, `_open_osfhandle` retornará um descritor de arquivo de tempo de execução C. Caso contrário, retornará -1.

## <a name="remarks"></a>Comentários

O `_open_osfhandle` função aloca um descritor de arquivo de tempo de execução do C e a associa o identificador de arquivo do sistema operacional especificado pelo *osfhandle*. O *sinalizadores* argumento é uma expressão de inteiro formada de um ou mais das constantes de manifesto definidas em Fcntl.h. Quando duas ou mais constantes de manifesto são usados para formar o *sinalizadores* argumento, as constantes são combinadas com o operador OR bit a bit ( **&#124;** ).

Fcntl.h define as seguintes constantes de manifesto:

**\_O\_APPEND**  
Posiciona um ponteiro de arquivo no final do arquivo, antes de cada operação de gravação.

**\_O\_RDONLY**  
Abre o arquivo para somente leitura.

**\_O\_TEXTO**  
Abre o arquivo no modo de texto (convertido).

**\_O\_WTEXT**  
Abre o arquivo no modo Unicode (convertido em UTF-16).

Para fechar um arquivo aberto com `_open_osfhandle`, chame [ \_fechar](../../c-runtime-library/reference/close.md). O identificador de arquivo do sistema operacional subjacente também é fechado por uma chamada para `_close`, portanto, não é necessário chamar a função Win32 `CloseHandle` no identificador do original. Se o descritor de arquivo pertence a um `FILE *` fluxo, em seguida, chamar [fclose](../../c-runtime-library/reference/fclose-fcloseall.md) naquele `FILE *` fluxo também fecha o descritor de arquivo e o identificador subjacente. Nesse caso, não chame `_close` no descritor de arquivo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_open_osfhandle`|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)  
