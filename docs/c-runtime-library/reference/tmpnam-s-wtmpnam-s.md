---
title: tmpnam_s, _wtmpnam_s
ms.date: 4/2/2020
api_name:
- tmpnam_s
- _wtmpnam_s
- _o__wtmpnam_s
- _o_tmpnam_s
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
- tmpnam_s
- _wtmpnam_s
- L_tmpnam_s
helpviewer_keywords:
- tmpnam_s function
- file names [C++], creating temporary
- _wtmpnam_s function
- L_tmpnam_s constant
- temporary files, creating
- file names [C++], temporary
- wtmpnam_s function
ms.assetid: e70d76dc-49f5-4aee-bfa2-f1baa2bcd29f
ms.openlocfilehash: 4839cb6baae8f163ac5e5efd8fecfab43f599d19
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82917481"
---
# <a name="tmpnam_s-_wtmpnam_s"></a>tmpnam_s, _wtmpnam_s

Gere nomes que podem ser usados para criar arquivos temporários. Estas são versões de [tmpnam e _wtmpnam](tempnam-wtempnam-tmpnam-wtmpnam.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t tmpnam_s(
   char * str,
   size_t sizeInChars
);
errno_t _wtmpnam_s(
   wchar_t *str,
   size_t sizeInChars
);
template <size_t size>
errno_t tmpnam_s(
   char (&str)[size]
); // C++ only
template <size_t size>
errno_t _wtmpnam_s(
   wchar_t (&str)[size]
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
Ponteiro que conterá o nome gerado.

*sizeInChars*<br/>
O tamanho do buffer em caracteres.

## <a name="return-value"></a>Valor retornado

Ambas as funções retornarão 0 se tiverem êxito ou um número de erro em caso de falha.

### <a name="error-conditions"></a>Condições de erro

|||||
|-|-|-|-|
|*Str*|*sizeInChars*|**Valor retornado**|**Conteúdo de**  *Str*|
|**NULO**|any|**EINVAL**|não modificado|
|Not **NULL** (aponta para memória válida)|muito curto|**ERANGE**|não modificado|

Se *Str* for **NULL**, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** como **EINVAL** e retornarão **EINVAL**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções retorna o nome de um arquivo que não existe no momento. **tmpnam_s** retorna um nome exclusivo no diretório temporário do Windows designado retornado por [GetTempPathW](/windows/win32/api/fileapi/nf-fileapi-gettemppathw). Observe que quando um nome de arquivo é precedido por uma barra invertida e nenhuma informação de caminho, como \fname21, isso indica que o nome é válido para o diretório de trabalho atual.

Por **tmpnam_s**, você pode armazenar esse nome de arquivo gerado em *Str*. O comprimento máximo de uma cadeia de caracteres retornada pelo **tmpnam_s** é **L_tmpnam_s**, definido em STDIO. T. Se *Str* for **NULL**, **tmpnam_s** deixará o resultado em um buffer estático interno. Portanto, todas as chamadas posteriores destroem esse valor. O nome gerado por **tmpnam_s** consiste em um nome de arquivo gerado por programa e, após a primeira chamada para **tmpnam_s**, uma extensão de arquivo de números sequenciais na base 32 (. 1-. 1vvvvvu, quando **TMP_MAX_S** em STDIO. H é **INT_MAX**).

**tmpnam_s** manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código OEM obtida do sistema operacional. **_wtmpnam_s** é uma versão de caractere largo do **tmpnam_s**; o argumento e o valor de retorno de **_wtmpnam_s** são cadeias de caracteres largos. **_wtmpnam_s** e **tmpnam_s** se comportam de forma idêntica, exceto que **_wtmpnam_s** não lida com cadeias de caracteres multibyte.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_ttmpnam_s**|**tmpnam_s**|**tmpnam_s**|**_wtmpnam_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**tmpnam_s**|\<stdio.h>|
|**_wtmpnam_s**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_tmpnam_s.c
// This program uses tmpnam_s to create a unique filename in the
// current working directory.
//

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   char name1[L_tmpnam_s];
   errno_t err;
   int i;

   for (i = 0; i < 15; i++)
   {
      err = tmpnam_s( name1, L_tmpnam_s );
      if (err)
      {
         printf("Error occurred creating unique filename.\n");
         exit(1);
      }
      else
      {
         printf( "%s is safe to use as a temporary file.\n", name1 );
      }
   }
}
```

```Output
C:\Users\LocalUser\AppData\Local\Temp\u19q8.0 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.1 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.2 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.3 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.4 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.5 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.6 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.7 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.8 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.9 is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.a is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.b is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.c is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.d is safe to use as a temporary file.
C:\Users\LocalUser\AppData\Local\Temp\u19q8.e is safe to use as a temporary file.
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[malloc](malloc.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[tmpfile_s](tmpfile-s.md)<br/>
