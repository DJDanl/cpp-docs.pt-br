---
title: fclose, _fcloseall | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- fclose
- _fcloseall
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
- fclose
- _fcloseall
dev_langs:
- C++
helpviewer_keywords:
- fclose function
- streams, closing
- _fcloseall function
ms.assetid: c3c6ea72-92c6-450a-a33e-3e568d2784a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 71b98a239cd1a6504611bf436533e7b5fbe1302c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32400233"
---
# <a name="fclose-fcloseall"></a>fclose, _fcloseall

Fecha um fluxo (**fclose**) ou fecha todos os fluxos abertos (**fcloseall**).

## <a name="syntax"></a>Sintaxe

```C
int fclose(
   FILE *stream
);
int _fcloseall( void );
```

### <a name="parameters"></a>Parâmetros

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

**fclose** retorna 0 se o fluxo está fechado com êxito. **fcloseall** retorna o número total de fluxos fechado. As duas funções retornam **EOF** para indicar um erro.

## <a name="remarks"></a>Comentários

O **fclose** função fecha *fluxo*. Se *fluxo* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **fclose** define **errno** para **EINVAL** e retorna **EOF**. É recomendável que o *fluxo* ponteiro sempre ser verificada antes de chamar essa função.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

O **fcloseall** função fecha todos os fluxos exceto **stdin**, **stdout**, **stderr** (e, em MS-DOS, **_stdaux**  e **_stdprn**). Ele também fecha e exclui todos os arquivos temporários criados pelo **tmpfile**. Em ambas as funções, todos os buffers associados com o fluxo são liberados antes do fechamento. Buffers alocados pelo sistema são liberados quando o fluxo está fechado. Buffers atribuídos pelo usuário com **setbuf** e **setvbuf** não são liberados automaticamente.

**Observação:** quando essas funções são usadas para fechar um fluxo, o descritor de arquivo subjacente e o identificador de arquivo do sistema operacional (ou soquete) são fechados, bem como o fluxo. Assim, se o arquivo foi aberto originalmente como um arquivo de manipular ou descritor de arquivo e é fechado com **fclose**, não também fazer chamada **echar** para fechar o descritor de arquivo, não chamar a função Win32  **CloseHandle** para fechar o identificador de arquivo.

**fclose** e **fcloseall** incluir código para proteger contra interferência de outros threads. Para a versão de não bloqueio de um **fclose**, consulte **fclose_nolock**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fclose**|\<stdio.h>|
|**_fcloseall**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [fopen](fopen-wfopen.md).

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_close](close.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[fflush](fflush.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[freopen, _wfreopen](freopen-wfreopen.md)<br/>
