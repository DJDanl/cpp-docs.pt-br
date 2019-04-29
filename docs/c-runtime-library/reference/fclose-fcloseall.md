---
title: fclose, _fcloseall
ms.date: 11/04/2016
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
helpviewer_keywords:
- fclose function
- streams, closing
- _fcloseall function
ms.assetid: c3c6ea72-92c6-450a-a33e-3e568d2784a4
ms.openlocfilehash: 4713ffb7ecdf8da73e5f949bbef7be124dfaf28a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62334873"
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

*stream*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

**fclose** retorna 0 se o fluxo está fechado com êxito. **fcloseall** retorna o número total de fluxos fechados. Ambas as funções retornam **EOF** para indicar um erro.

## <a name="remarks"></a>Comentários

O **fclose** função fecha *fluxo*. Se *stream* é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **fclose** define **errno** para **EINVAL** e retorna **EOF**. É recomendável que o *stream* ponteiro sempre seja verificado antes de chamar essa função.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

O **fcloseall** função fecha todos os fluxos abertos exceto **stdin**, **stdout**, **stderr** (e, no MS-DOS, **_stdaux**  e **_stdprn**). Ela também fecha e exclui todos os arquivos temporários criados pelo **tmpfile**. Em ambas as funções, todos os buffers associados com o fluxo são liberados antes do fechamento. Buffers alocados pelo sistema são liberados quando o fluxo está fechado. Buffers atribuídos pelo usuário com **setbuf** e **setvbuf** não são liberados automaticamente.

**Observação:** Quando essas funções são usadas para fechar um fluxo, o subjacente descritor de arquivo e sistema operacional identificador de arquivo (ou soquete) é fechado, bem como o fluxo. Assim, se o arquivo foi aberto originalmente como um arquivo de manipular ou descritor de arquivo e é fechada com **fclose**, não chame **Close** para fechar o descritor de arquivo; não chame a função Win32  **CloseHandle** para fechar o identificador de arquivo.

**fclose** e **fcloseall** incluir código para proteger contra interferência de outros threads. Para a versão sem bloqueio de um **fclose**, consulte **fclose_nolock**.

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
