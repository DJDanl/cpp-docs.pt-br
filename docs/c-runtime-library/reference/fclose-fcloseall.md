---
title: fclose, _fcloseall
ms.date: 11/04/2016
api_name:
- fclose
- _fcloseall
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
ms.openlocfilehash: 215925fb16f5d51e481ae92cbb45b0270bd5ebd4
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70941497"
---
# <a name="fclose-_fcloseall"></a>fclose, _fcloseall

Fecha um fluxo (**fclose**) ou fecha todos os fluxos abertos ( **_fcloseall**).

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

**fclose** retornará 0 se o fluxo for fechado com êxito. **_fcloseall** retorna o número total de fluxos fechados. Ambas as funções retornam **EOF** para indicar um erro.

## <a name="remarks"></a>Comentários

A função **fclose** fecha o *fluxo*. Se o *fluxo* for **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, **fclose** definirá **errno** como **EINVAL** e retornará **EOF**. É recomendável que o ponteiro de *fluxo* sempre seja verificado antes de chamar essa função.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

A função **_fcloseall** fecha todos os fluxos abertos, exceto **stdin**, **stdout**, **stderr** (e, em MS-dos, **_stdaux** e **_stdprn**). Ele também fecha e exclui todos os arquivos temporários criados pelo **tmpfile**. Em ambas as funções, todos os buffers associados com o fluxo são liberados antes do fechamento. Buffers alocados pelo sistema são liberados quando o fluxo está fechado. Os buffers atribuídos pelo usuário com **setbuf** e **setvbuf** não são liberados automaticamente.

**Observação:** Quando essas funções são usadas para fechar um fluxo, o descritor de arquivo subjacente e o identificador de arquivo do sistema operacional (ou soquete) são fechados, bem como o fluxo. Portanto, se o arquivo foi aberto originalmente como um identificador de arquivo ou descritor de arquivo e é fechado com **fclose**, não chame também **_close** para fechar o descritor de arquivo; Não chame a função **CloseHandle** do Win32 para fechar o identificador de arquivo.

**fclose** e **_fcloseall** incluem código para proteger contra interferência de outros threads. Para uma versão sem bloqueio de um **fclose**, consulte **_fclose_nolock**.

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
