---
title: _tempnam, _wtempnam, tmpnam, _wtmpnam | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _wtempnam
- _wtmpnam
- tmpnam
- _tempnam
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
- wtempnam
- _wtmpnam
- wtmpnam
- tmpnam
- _wtempnam
- _tempnam
dev_langs:
- C++
helpviewer_keywords:
- wtempnam function
- file names [C++], creating temporary
- _tempnam function
- ttmpnam function
- tmpnam function
- tempnam function
- wtmpnam function
- temporary files, creating
- file names [C++], temporary
- _ttmpnam function
- _wtmpnam function
- _wtempnam function
ms.assetid: 3ce75f0f-5e30-42a6-9791-8d7cbfe70fca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 55ff069d72d68493eee524ea2f9c012d2fc7f534
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32417007"
---
# <a name="tempnam-wtempnam-tmpnam-wtmpnam"></a>_tempnam, _wtempnam, tmpnam, _wtmpnam

Gere nomes que podem ser usados para criar arquivos temporários. Versões mais seguras de algumas dessas funções estão disponíveis; consulte [tmpnam_s, _wtmpnam_s](tmpnam-s-wtmpnam-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *_tempnam(
   const char *dir,
   const char *prefix
);
wchar_t *_wtempnam(
   const wchar_t *dir,
   const wchar_t *prefix
);
char *tmpnam(
   char *str
);
wchar_t *_wtmpnam(
   wchar_t *str
);
```

### <a name="parameters"></a>Parâmetros

*prefix*<br/>
A cadeia de caracteres que será anexado aos nomes retornado por **tempnam**.

*dir*<br/>
O caminho usado no nome de arquivo, se não houver variável de ambiente TMP ou se TMP não for um diretório válido.

*str*<br/>
Ponteiro que conterá o nome gerado e será idêntico ao nome retornado pela função. Essa é uma maneira conveniente de salvar o nome gerado.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para o nome gerado ou **nulo** se houver uma falha. Falha pode ocorrer se você tentar mais de **TMP_MAX** (consulte STDIO. H) chamadas com **tmpnam** ou se você usar **tempnam** e há um nome de diretório inválido especificado na variável de ambiente TMP e no *dir* parâmetro.

> [!NOTE]
> Os ponteiros retornados por **tmpnam** e **wtmpnam** aponte para buffers estáticos internos. [free](free.md) não deve ser chamado para desalocar esses ponteiros. **livre** precisa ser chamado para ponteiros alocados por **tempnam** e **wtempnam**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções retorna o nome de um arquivo que não existe no momento. **tmpnam** retorna um nome exclusivo no diretório de trabalho atual e **tempnam** permite gerar um nome exclusivo em um diretório diferente do atual. Observe que quando um nome de arquivo é precedido por uma barra invertida e nenhuma informação de caminho, como \fname21, isso indica que o nome é válido para o diretório de trabalho atual.

Para **tmpnam**, você pode armazenar esse nome de arquivo gerado no *str*. Se *str* é **nulo**, em seguida, **tmpnam** deixa o resultado em um buffer interno de estático. Portanto, todas as chamadas posteriores destroem esse valor. O nome gerado pelo **tmpnam** consiste em um nome de arquivo gerado pelo programa e, após a primeira chamada para **tmpnam**, uma extensão de arquivo dos números sequenciais na base 32 (quando.1-.vvu **TMP_MAX**  em STDIO. H é 32.767).

**tempnam** irá gerar um nome de arquivo exclusivo para um diretório escolhido pelas seguintes regras:

- Se a variável de ambiente TMP for definida com um nome de diretório válido, nomes de arquivo exclusivos serão gerados para o diretório especificado por TMP.

- Se a variável de ambiente TMP não está definida ou se ele for definido como o nome de um diretório que não existe, **tempnam** usará o *dir* parâmetro como o caminho para o qual ele irá gerar nomes exclusivos.

- Se a variável de ambiente TMP não está definida ou se ele for definido como o nome de um diretório que não existe e se *dir* é **nulo** ou definido como o nome de um diretório que não existe, **_ tempnam** usará o diretório de trabalho atual para gerar nomes exclusivos. No momento, se ambos os TMP e *dir* especificar nomes de diretórios não existirem, o **tempnam** haverá falha na chamada de função.

O nome retornado pela **tempnam** será uma concatenação de *prefixo* e um número sequencial, que serão combinados para criar um nome de arquivo exclusivo para o diretório especificado. **tempnam** gera nomes de arquivo com nenhuma extensão. **tempnam** usa [malloc](malloc.md) para alocar espaço para nome de arquivo; o programa é responsável pela liberação esse espaço quando ele não for mais necessário.

**tempnam** e **tmpnam** obtidas automaticamente de argumentos da cadeia de caracteres multibyte identificador conforme apropriado, reconhecer sequências de caracteres multibyte de acordo com a página de código OEM do sistema operacional. **wtempnam** é uma versão de caractere largo de **tempnam**; o valor de retorno e argumentos **wtempnam** são cadeias de caracteres do caractere largo. **wtempnam** e **tempnam** tenham comportamento idêntico, exceto que **wtempnam** não trata cadeias de caracteres multibyte. **wtmpnam** é uma versão de caractere largo de **tmpnam**; o valor de retorno e de argumento de **wtmpnam** são cadeias de caracteres do caractere largo. **wtmpnam** e **tmpnam** tenham comportamento idêntico, exceto que **wtmpnam** não trata cadeias de caracteres multibyte.

Se **Debug** e **crtdbg_map_alloc** são definidos, **tempnam** e **wtempnam** são substituídos por chamadas para [tempnam _dbg e wtempnam_dbg](tempnam-dbg-wtempnam-dbg.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**ttmpnam**|**tmpnam**|**tmpnam**|**_wtmpnam**|
|**_ttempnam**|**_tempnam**|**_tempnam**|**_wtempnam**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_tempnam**|\<stdio.h>|
|**wtempnam**, **wtmpnam**|\<stdio.h> ou \<wchar.h>|
|**tmpnam**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_tempnam.c
// compile with: /W3
// This program uses tmpnam to create a unique filename in the
// current working directory, then uses _tempnam to create
// a unique filename with a prefix of stq.

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   char* name1 = NULL;
   char* name2 = NULL;

   // Create a temporary filename for the current working directory:
   if( ( name1 = tmpnam( NULL ) ) != NULL ) // C4996
   // Note: tmpnam is deprecated; consider using tmpnam_s instead
      printf( "%s is safe to use as a temporary file.\n", name1 );
   else
      printf( "Cannot create a unique filename\n" );

   // Create a temporary filename in temporary directory with the
   // prefix "stq". The actual destination directory may vary
   // depending on the state of the TMP environment variable and
   // the global variable P_tmpdir.

   if( ( name2 = _tempnam( "c:\\tmp", "stq" ) ) != NULL )
      printf( "%s is safe to use as a temporary file.\n", name2 );
   else
      printf( "Cannot create a unique filename\n" );

   // When name2 is no longer needed :
   if(name2)
     free(name2);

}
```

```Output
\s1gk. is safe to use as a temporary file.
C:\DOCUME~1\user\LOCALS~1\Temp\2\stq2 is safe to use as a temporary file.
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[malloc](malloc.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[tmpfile](tmpfile.md)<br/>
[tmpfile_s](tmpfile-s.md)<br/>
