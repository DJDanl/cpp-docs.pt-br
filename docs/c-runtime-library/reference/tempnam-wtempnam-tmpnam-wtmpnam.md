---
title: _tempnam, _wtempnam, tmpnam, _wtmpnam
ms.date: 11/04/2016
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
ms.openlocfilehash: 0e8e11182948e9bccf1c55685cc7c3d55ff697c8
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500760"
---
# <a name="_tempnam-_wtempnam-tmpnam-_wtmpnam"></a>_tempnam, _wtempnam, tmpnam, _wtmpnam

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
A cadeia de caracteres que será pré-instalada para nomes retornados por **_tempnam**.

*dir*<br/>
O caminho usado no nome de arquivo, se não houver variável de ambiente TMP ou se TMP não for um diretório válido.

*str*<br/>
Ponteiro que conterá o nome gerado e será idêntico ao nome retornado pela função. Essa é uma maneira conveniente de salvar o nome gerado.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para o nome gerado ou **nulo** se houver uma falha. A falha poderá ocorrer se você tentar mais de **TMP_MAX** (consulte STDIO. H) chamadas com **tmpnam** ou se você usar **_tempnam** e houver um nome de diretório inválido especificado na variável de ambiente TMP e no parâmetro *dir* .

> [!NOTE]
> Os ponteiros retornados por **tmpnam** e **_wtmpnam** apontam para buffers estáticos internos. [free](free.md) não deve ser chamado para desalocar esses ponteiros. **gratuito** precisa ser chamado para ponteiros alocados por **_tempnam** e **_wtempnam**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções retorna o nome de um arquivo que não existe no momento. **tmpnam** retorna um nome que é exclusivo no diretório temporário do Windows designado retornado por [GetTempPathW](/windows/win32/api/fileapi/nf-fileapi-gettemppathw). tempnam gera um nome exclusivo em um diretório diferente do designado.  **\_** Observe que quando um nome de arquivo é precedido por uma barra invertida e nenhuma informação de caminho, como \fname21, isso indica que o nome é válido para o diretório de trabalho atual.

Para **tmpnam**, você pode armazenar esse nome de arquivo gerado em *Str*. Se *Str* for **NULL**, **tmpnam** deixará o resultado em um buffer estático interno. Portanto, todas as chamadas posteriores destroem esse valor. O nome gerado por **tmpnam** consiste em um nome de arquivo gerado por programa e, após a primeira chamada para **tmpnam**, uma extensão de arquivo de números sequenciais na base 32 (. 1 –. vvu, quando **TMP_MAX** em STDIO. H é 32.767).

**_tempnam** irá gerar um nome de arquivo exclusivo para um diretório escolhido pelas seguintes regras:

- Se a variável de ambiente TMP for definida com um nome de diretório válido, nomes de arquivo exclusivos serão gerados para o diretório especificado por TMP.

- Se a variável de ambiente TMP não for definida ou se estiver definida como o nome de um diretório que não existe, o **_tempnam** usará o parâmetro *dir* como o caminho para o qual irá gerar nomes exclusivos.

- Se a variável de ambiente TMP não for definida ou se estiver definida como o nome de um diretório que não existe, e se *dir* for **nulo** ou definido como o nome de um diretório que não existe, o **_tempnam** usará o diretório de trabalho atual para Gene Classifique nomes exclusivos. Atualmente, se TMP e *dir* especificarem nomes de diretórios que não existem, a chamada de função **_tempnam** falhará.

O nome retornado por **_tempnam** será uma concatenação do *prefixo* e um número sequencial, que será combinado para criar um nome de arquivo exclusivo para o diretório especificado. **_tempnam** gera nomes de arquivo que não têm extensão. **_tempnam** usa [malloc](malloc.md) para alocar espaço para o nome de arquivo; o programa é responsável por liberar esse espaço quando ele não for mais necessário.

**_tempnam** e **tmpnam** manipulam automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código OEM obtida do sistema operacional. **_wtempnam** é uma versão de caractere largo do **_tempnam**; os argumentos e o valor de retorno de **_wtempnam** são cadeias de caracteres largos. **_wtempnam** e **_tempnam** se comportam de forma idêntica, exceto pelo fato de que o **_wtempnam** não lida com cadeias de caracteres multibyte. **_wtmpnam** é uma versão de caractere largo do **tmpnam**; o argumento e o valor de retorno de **_wtmpnam** são cadeias de caracteres largos. **_wtmpnam** e **tmpnam** se comportam de forma idêntica, exceto pelo fato de que o **_wtmpnam** não lida com cadeias de caracteres multibyte.

Se **_DEBUG** e **_CRTDBG_MAP_ALLOC** forem definidos, **_tempnam** e **_wtempnam** serão substituídos por chamadas para [_tempnam_dbg e _wtempnam_dbg](tempnam-dbg-wtempnam-dbg.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_ttmpnam**|**tmpnam**|**tmpnam**|**_wtmpnam**|
|**_ttempnam**|**_tempnam**|**_tempnam**|**_wtempnam**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_tempnam**|\<stdio.h>|
|**_wtempnam**, **_wtmpnam**|\<stdio.h> ou \<wchar.h>|
|**tmpnam**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_tempnam.c
// compile with: /W3
// This program uses tmpnam to create a unique filename in the
// temporary directory, and _tempname to create a unique filename
// in C:\\tmp.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   char * name1 = NULL;
   char * name2 = NULL;
   char * name3 = NULL;

   // Create a temporary filename for the current working directory:
   if ((name1 = tmpnam(NULL)) != NULL) { // C4996
   // Note: tmpnam is deprecated; consider using tmpnam_s instead
      printf("%s is safe to use as a temporary file.\n", name1);
   } else {
      printf("Cannot create a unique filename\n");
   }

   // Create a temporary filename in temporary directory with the
   // prefix "stq". The actual destination directory may vary
   // depending on the state of the TMP environment variable and
   // the global variable P_tmpdir.

   if ((name2 = _tempnam("c:\\tmp", "stq")) != NULL) {
      printf("%s is safe to use as a temporary file.\n", name2);
   } else {
      printf("Cannot create a unique filename\n");
   }

   // When name2 is no longer needed:
   if (name2) {
      free(name2);
   }

   // Unset TMP environment variable, then create a temporary filename in C:\tmp.
   if (_putenv("TMP=") != 0) {
      printf("Could not remove TMP environment variable.\n");
   }

   // With TMP unset, we will use C:\tmp as the temporary directory.
   // Create a temporary filename in C:\tmp with prefix "stq".
   if ((name3 = _tempnam("c:\\tmp", "stq")) != NULL) {
      printf("%s is safe to use as a temporary file.\n", name3);
   }
   else {
      printf("Cannot create a unique filename\n");
   }

   // When name3 is no longer needed:
   if (name3) {
      free(name3);
   }

   return 0;
}
```

```Output
C:\Users\LocalUser\AppData\Local\Temp\sriw.0 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\stq2 is safe to use as a temporary file.
c:\tmp\stq3 is safe to use as a temporary file.
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[malloc](malloc.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[tmpfile](tmpfile.md)<br/>
[tmpfile_s](tmpfile-s.md)<br/>
