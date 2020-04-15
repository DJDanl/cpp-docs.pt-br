---
title: tmpfile_s
ms.date: 4/2/2020
api_name:
- tmpfile_s
- _o_tmpfile_s
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
- tmpfile_s
helpviewer_keywords:
- temporary files
- tmpfile_s function
- temporary files, creating
ms.assetid: 50879c69-215e-425a-a2a3-8b5467121eae
ms.openlocfilehash: 8f9dd58abdf1d3225341e40661c14ae3a5013257
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81362470"
---
# <a name="tmpfile_s"></a>tmpfile_s

Cria um arquivo temporário. Trata-se de uma versão de [tmpfile](tmpfile.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t tmpfile_s(
   FILE** pFilePtr
);
```

### <a name="parameters"></a>Parâmetros

*Pfileptr*<br/>
O endereço de um ponteiro para armazenar o endereço do ponteiro gerado em um fluxo.

## <a name="return-value"></a>Valor retornado

Retornará 0 se for bem-sucedido; um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de erro

|*Pfileptr*|**Valor retornado**|**Conteúdo de**  *pFilePtr*|
|----------------|----------------------|---------------------------------|
|**NULO**|**Einval**|não alterado|

Se ocorrer o erro de validação de parâmetro acima, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e o valor de retorno será **EINVAL**.

## <a name="remarks"></a>Comentários

A função **tmpfile_s** cria um arquivo temporário e coloca um ponteiro para esse fluxo no argumento *pFilePtr.* O arquivo temporário é criado no diretório raiz. Para criar um arquivo temporário em um diretório que não seja a raiz, use [tmpnam_s](tmpnam-s-wtmpnam-s.md) ou [tempnam](tempnam-wtempnam-tmpnam-wtmpnam.md) em conjunto com [fopen](fopen-wfopen.md).

Se o arquivo não puder ser aberto, **tmpfile_s** **gravaNULL** no parâmetro *pFilePtr.* Este arquivo temporário é automaticamente excluído quando o arquivo é fechado, quando o programa termina normalmente, ou quando **_rmtmp** é chamado, assumindo que o diretório de trabalho atual não muda. O arquivo temporário é aberto no modo **w+b** (binário read/write).

A falha pode ocorrer se você tentar mais de **TMP_MAX_S** (ver STDIO. H) chamadas com **tmpfile_s**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**tmpfile_s**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

> [!NOTE]
> Este exemplo pode exigir privilégios administrativos para ser executado no Windows.

```C
// crt_tmpfile_s.c
// This program uses tmpfile_s to create a
// temporary file, then deletes this file with _rmtmp.
//

#include <stdio.h>

int main( void )
{
   FILE *stream;
   char tempstring[] = "String to be written";
   int  i;
   errno_t err;

   // Create temporary files.
   for( i = 1; i <= 3; i++ )
   {
      err = tmpfile_s(&stream);
      if( err )
         perror( "Could not open new temporary file\n" );
      else
         printf( "Temporary file %d was created\n", i );
   }

   // Remove temporary files.
   printf( "%d temporary files deleted\n", _rmtmp() );
}
```

```Output
Temporary file 1 was created
Temporary file 2 was created
Temporary file 3 was created
3 temporary files deleted
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_rmtmp](rmtmp.md)<br/>
[_tempnam, _wtempnam, tmpnam, _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)<br/>
