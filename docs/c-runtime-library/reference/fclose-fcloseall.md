---
title: fclose, _fcloseall
ms.date: 4/2/2020
api_name:
- fclose
- _fcloseall
- _o__fcloseall
- _o_fclose
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- fclose
- _fcloseall
helpviewer_keywords:
- fclose function
- streams, closing
- _fcloseall function
ms.assetid: c3c6ea72-92c6-450a-a33e-3e568d2784a4
ms.openlocfilehash: b2ee14c5fc8bb47cc2652443c0263bd14147c90d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81347487"
---
# <a name="fclose-_fcloseall"></a>fclose, _fcloseall

Fecha um córrego **(fclose)** ou fecha todos os fluxos abertos **(_fcloseall).**

## <a name="syntax"></a>Sintaxe

```C
int fclose(
   FILE *stream
);
int _fcloseall( void );
```

### <a name="parameters"></a>Parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

**fclose** retorna 0 se o fluxo for fechado com sucesso. **_fcloseall** retorna o número total de córregos fechados. Ambas as funções retornam **EOF** para indicar um erro.

## <a name="remarks"></a>Comentários

A função **de fechamento** fecha *o fluxo*. Se *o fluxo* for **NULO,** o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **feche** sets **errno** para **EINVAL** e devolva **EOF**. Recomenda-se que o ponteiro do *fluxo* seja sempre verificado antes de chamar esta função.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

A função **_fcloseall** fecha todos os fluxos abertos, exceto **stdin,** **stdout,** **stderr** (e, em MS-DOS, **_stdaux** e **_stdprn**). Ele também fecha e exclui quaisquer arquivos temporários criados por **tmpfile**. Em ambas as funções, todos os buffers associados com o fluxo são liberados antes do fechamento. Buffers alocados pelo sistema são liberados quando o fluxo está fechado. Buffers atribuídos pelo usuário com **setbuf** e **setvbuf** não são liberados automaticamente.

**Observação:** quando essas funções são usadas para fechar um fluxo, o descritor de arquivo subjacente e o identificador de arquivo do sistema operacional (ou soquete) são fechados, bem como o fluxo. Assim, se o arquivo foi originalmente aberto como um descritor de arquivo ou arquivo e for fechado com **fclose,** também não chame **_close** para fechar o descritor do arquivo; não chame a função Win32 **CloseHandle** para fechar a alça do arquivo.

**fechar** e **_fcloseall** incluir código para proteger contra interferências de outros segmentos. Para a versão sem travamento de um **fclose,** consulte **_fclose_nolock**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fclose**|\<stdio.h>|
|**_fcloseall**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [fopen](fopen-wfopen.md).

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_close](close.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[fflush](fflush.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[freopen, _wfreopen](freopen-wfreopen.md)<br/>
