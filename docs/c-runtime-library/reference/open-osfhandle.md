---
title: _open_osfhandle
ms.date: 4/2/2020
api_name:
- _open_osfhandle
- _o__open_osfhandle
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _open_osfhandle
- open_osfhandle
helpviewer_keywords:
- open_osfhandle function
- file handles [C++], associating
- _open_osfhandle function
ms.assetid: 30d94df4-7868-4667-a401-9eb67ecb7855
ms.openlocfilehash: d0f86c2588eed506bc9b8408e01bccdb6d1aad9d
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88844061"
---
# <a name="_open_osfhandle"></a>_open_osfhandle

Associa um descritor de arquivo em tempo de execução C a um identificador de arquivo do sistema operacional existente.

## <a name="syntax"></a>Sintaxe

```cpp
int _open_osfhandle (
   intptr_t osfhandle,
   int flags
);
```

### <a name="parameters"></a>parâmetros

*osfhandle*<br/>
Identificador de arquivo do sistema operacional.

*sinalizadores*<br/>
Tipos de operações permitidas.

## <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, **_open_osfhandle** retornará um descritor de arquivo de tempo de execução C. Caso contrário, ele retornará -1.

## <a name="remarks"></a>Comentários

A função **_open_osfhandle** aloca um descritor de arquivo em tempo de execução C. Ele associa este descritor de arquivo ao identificador de arquivo do sistema operacional especificado por *osfhandle*. Para evitar um aviso do compilador, converta o argumento *osfhandle* de **HANDLE** para **intptr_t**. O argumento *flags* é uma expressão de número inteiro formada por uma ou mais das constantes de manifesto definidas em \<fcntl.h> . Você pode usar o operador-OR-bit-a-OR ( **&#124;** ) para combinar duas ou mais constantes de manifesto para formar o argumento *flags* .

Essas constantes de manifesto são definidas em \<fcntl.h> :

| Constante | DESCRIÇÃO |
|--|--|
| **\_O \_ Append** | Posiciona um ponteiro de arquivo no final do arquivo, antes de cada operação de gravação. |
| **\_O \_ RDONLY** | Abre o arquivo para somente leitura. |
| **\_O \_ texto** | Abre o arquivo no modo de texto (convertido). |
| **\_O \_ WTEXT** | Abre o arquivo no modo Unicode (convertido em UTF-16). |

A chamada **_open_osfhandle** transfere a propriedade do identificador de arquivo do Win32 para o descritor de arquivo. Para fechar um arquivo aberto usando **_open_osfhandle**, chame [\_close](close.md). O identificador de arquivo do sistema operacional subjacente também é fechado por uma chamada para **_close**. Não chame a função **CloseHandle** do Win32 no identificador original. Se o descritor de arquivo pertencer a um **arquivo &#42;** Stream, uma chamada para [fclose](fclose-fcloseall.md) fechará o descritor de arquivo e o identificador subjacente. Nesse caso, não chame **_close** no descritor de arquivo ou **CloseHandle** no identificador original.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_open_osfhandle**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Manipulação de arquivos](../../c-runtime-library/file-handling.md)<br/>
[\_get_osfhandle](get-osfhandle.md)
