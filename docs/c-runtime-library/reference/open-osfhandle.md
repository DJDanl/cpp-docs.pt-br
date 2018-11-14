---
title: _open_osfhandle
ms.date: 05/29/2018
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
ms.openlocfilehash: f45ca46cae459c8606f88a98d03b64c40e5d5f01
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51327857"
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

Se for bem-sucedido, **open_osfhandle** retorna um descritor de arquivo de tempo de execução C. Caso contrário, ele retornará -1.

## <a name="remarks"></a>Comentários

O **open_osfhandle** função aloca um descritor de arquivo de tempo de execução do C e a associa com o identificador de arquivo do sistema operacional especificado por *osfhandle*. Para evitar um aviso do compilador, converta a *osfhandle* argumento de **MANIPULAR** para **intptr_t**. O *sinalizadores* argumento é uma expressão inteira formada por uma ou mais das constantes de manifesto definidas em \<fcntl. h >. Quando duas ou mais constantes manifestas são usadas para formar o *sinalizadores* argumento, as constantes são combinadas com o operador OR bit a bit ( **&#124;** ).

Essas constantes de manifesto são definidas em \<fcntl. h >:

|||
|-|-|
| **\_O\_APPEND** | Posiciona um ponteiro de arquivo no final do arquivo, antes de cada operação de gravação. |
| **\_O\_RDONLY** | Abre o arquivo para somente leitura. |
| **\_O\_TEXT** | Abre o arquivo no modo de texto (convertido). |
| **\_O\_WTEXT** | Abre o arquivo no modo Unicode (convertido em UTF-16). |

O **open_osfhandle** chamada transfere a propriedade do identificador de arquivo do Win32 para o descritor de arquivo. Para fechar um arquivo aberto com **open_osfhandle**, chame [ \_fechar](close.md). O identificador de arquivo do sistema operacional subjacente também é fechado por uma chamada para **Close**, portanto, não é necessário chamar a função Win32 **CloseHandle** no identificador original. Se o descritor de arquivo pertence a um **arquivo &#42;**  fluxo, em seguida, chamar [fclose](fclose-fcloseall.md) em que **arquivo &#42;**  fluxo também fecha o descritor do arquivo e o Identificador subjacente. Nesse caso, não chame **Close** no descritor de arquivo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_open_osfhandle**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
