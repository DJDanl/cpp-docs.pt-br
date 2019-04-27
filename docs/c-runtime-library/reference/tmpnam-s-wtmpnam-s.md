---
title: tmpnam_s, _wtmpnam_s
ms.date: 11/04/2016
apiname:
- tmpnam_s
- _wtmpnam_s
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
ms.openlocfilehash: 9bf994d16362ef461d8d25d72466721ba9a5890f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62155531"
---
# <a name="tmpnams-wtmpnams"></a>tmpnam_s, _wtmpnam_s

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

*str*<br/>
Ponteiro que conterá o nome gerado.

*sizeInChars*<br/>
O tamanho do buffer em caracteres.

## <a name="return-value"></a>Valor de retorno

Ambas as funções retornarão 0 se tiverem êxito ou um número de erro em caso de falha.

### <a name="error-conditions"></a>Condições de Erro

|||||
|-|-|-|-|
|*str*|*sizeInChars*|**Valor retornado**|**Contents of**  *str*|
|**NULL**|qualquer|**EINVAL**|não modificado|
|Não **nulo** (aponta para a memória válida)|muito curto|**ERANGE**|não modificado|

Se *str* é **nulo**, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornar **EINVAL**.

## <a name="remarks"></a>Comentários

Cada uma dessas funções retorna o nome de um arquivo que não existe no momento. **tmpnam_s** retorna um nome exclusivo no diretório temporário designado do Windows retornado por [GetTempPathW](/windows/desktop/api/fileapi/nf-fileapi-gettemppathw). Observe que quando um nome de arquivo é precedido por uma barra invertida e nenhuma informação de caminho, como \fname21, isso indica que o nome é válido para o diretório de trabalho atual.

Para **tmpnam_s**, você pode armazenar esse nome de arquivo gerado no *str*. O comprimento máximo de uma cadeia de caracteres retornada por **tmpnam_s** é **L_tmpnam_s**, definidas em STDIO. H. Se *str* é **nulo**, em seguida, **tmpnam_s** deixará o resultado em um buffer estático interno. Portanto, todas as chamadas posteriores destroem esse valor. O nome gerado por **tmpnam_s** consiste em um nome de arquivo gerado pelo programa e, após a primeira chamada para **tmpnam_s**, uma extensão de arquivo de números sequenciais em base 32 (. 1-.1vvvvvu quando **TMP _MAX_S** em STDIO. H seja **INT_MAX**).

**tmpnam_s** automaticamente argumentos de cadeia de caracteres multibyte alças conforme apropriado, reconhecendo as sequências de caracteres multibyte de acordo com a página de código OEM obtida do sistema operacional. **wtmpnam_s** é uma versão de caractere largo de **tmpnam_s**; o argumento e o valor retornado de **wtmpnam_s** são cadeias de caracteres largos. **wtmpnam_s** e **tmpnam_s** se comportam de forma idêntica exceto que **wtmpnam_s** não manipula cadeias de caracteres multibyte.

No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_ttmpnam_s**|**tmpnam_s**|**tmpnam_s**|**_wtmpnam_s**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**tmpnam_s**|\<stdio.h>|
|**_wtmpnam_s**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[malloc](malloc.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[tmpfile_s](tmpfile-s.md)<br/>
