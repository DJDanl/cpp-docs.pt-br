---
title: _open_osfhandle
ms.date: 05/21/2019
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
helpviewer_keywords:
- open_osfhandle function
- file handles [C++], associating
- _open_osfhandle function
ms.assetid: 30d94df4-7868-4667-a401-9eb67ecb7855
ms.openlocfilehash: 8527dade37f20b7341d5a26f5752ece668ab7fc9
ms.sourcegitcommit: bde3279f70432f819018df74923a8bb895636f81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/23/2019
ms.locfileid: "66174796"
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

Se for bem-sucedido, **_open_osfhandle** retornará um descritor de arquivo de tempo de execução C. Caso contrário, retornará -1.

## <a name="remarks"></a>Comentários

A função **_open_osfhandle** aloca um descritor de arquivo de tempo de execução C e o associa ao identificador de arquivo do sistema operacional especificado por *osfhandle*. Para evitar um aviso do compilador, converta o argumento *osfhandle* de **HANDLE** para **intptr_t**. O argumento *flags* é uma expressão inteira formada por uma ou mais constantes de manifesto definidas em \<fcntl.h>. Quando duas ou mais constantes de manifesto são usadas para formar o argumento *flags*, as constantes são combinadas com o operador OR bit a bit (**&#124;**).

As constantes de manifesto são definidas em \<fcntl.h>:

|||
|-|-|
| **\_O\_APPEND** | Posiciona um ponteiro de arquivo no final do arquivo, antes de cada operação de gravação. |
| **\_O\_RDONLY** | Abre o arquivo para somente leitura. |
| **\_O\_TEXT** | Abre o arquivo no modo de texto (convertido). |
| **\_O\_WTEXT** | Abre o arquivo no modo Unicode (convertido em UTF-16). |

A chamada **_open_osfhandle** transfere a propriedade do identificador de arquivo do Win32 para o descritor de arquivo. Para fechar um arquivo aberto usando **_open_osfhandle**, chame [\_close](close.md). O identificador de arquivo do sistema operacional subjacente também é fechado por uma chamada para **_close**. Não chame a função **CloseHandle** do Win32 no identificador original. Se o descritor de arquivo pertencer a um fluxo **FILE &#42;**, uma chamada para [fclose](fclose-fcloseall.md) no fluxo **FILE &#42;** fechará o descritor de arquivo e o identificador subjacente. Nesse caso, não chame **_close** no descritor de arquivo ou **CloseHandle** no identificador original.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_open_osfhandle**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
