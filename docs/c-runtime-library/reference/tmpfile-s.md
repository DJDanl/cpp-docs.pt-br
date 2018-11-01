---
title: tmpfile_s
ms.date: 11/04/2016
apiname:
- tmpfile_s
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
- tmpfile_s
helpviewer_keywords:
- temporary files
- tmpfile_s function
- temporary files, creating
ms.assetid: 50879c69-215e-425a-a2a3-8b5467121eae
ms.openlocfilehash: 341e1c8ed6dd20ec7e6a3d71999fb365e45e614a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50488108"
---
# <a name="tmpfiles"></a>tmpfile_s

Cria um arquivo temporário. Trata-se de uma versão de [tmpfile](tmpfile.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t tmpfile_s(
   FILE** pFilePtr
);
```

### <a name="parameters"></a>Parâmetros

*pFilePtr*<br/>
O endereço de um ponteiro para armazenar o endereço do ponteiro gerado em um fluxo.

## <a name="return-value"></a>Valor de retorno

Retornará 0 se for bem-sucedido; um código de erro em caso de falha.

### <a name="error-conditions"></a>Condições de Erro

|*pFilePtr*|**Valor retornado**|**Conteúdo do***pFilePtr* |
|----------------|----------------------|---------------------------------|
|**NULL**|**EINVAL**|não alterado|

Se ocorrer o erro de validação de parâmetro acima, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e o valor retornado será **EINVAL**.

## <a name="remarks"></a>Comentários

O **tmpfile_s** função cria um arquivo temporário e coloca um ponteiro nesse fluxo na *pFilePtr* argumento. O arquivo temporário é criado no diretório raiz. Para criar um arquivo temporário em um diretório que não seja a raiz, use [tmpnam_s](tmpnam-s-wtmpnam-s.md) ou [tempnam](tempnam-wtempnam-tmpnam-wtmpnam.md) em conjunto com [fopen](fopen-wfopen.md).

Se o arquivo não pode ser aberto, **tmpfile_s** grava **nulo** para o *pFilePtr* parâmetro. Esse arquivo temporário é excluído automaticamente quando o arquivo é fechado quando o programa for encerrado normalmente ou quando **rmtmp** é chamado, supondo que o diretório de trabalho atual não é alterado. O arquivo temporário é aberto no **w + b** modo (leitura/gravação binária).

Falha pode ocorrer se você tentar mais de **TMP_MAX_S** (consulte STDIO. H) chamadas de com **tmpfile_s**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**tmpfile_s**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_rmtmp](rmtmp.md)<br/>
[_tempnam, _wtempnam, tmpnam, _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md)<br/>
