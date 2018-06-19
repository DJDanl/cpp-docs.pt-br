---
title: wcstombs_s, _wcstombs_s_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _wcstombs_s_l
- wcstombs_s
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- wcstombs_s
- _wcstombs_s_l
dev_langs:
- C++
helpviewer_keywords:
- wcstombs_s function
- string conversion, wide characters
- wide characters, converting
- _wcstombs_s_l function
- wcstombs_s_l function
- characters, converting
- string conversion, multibyte character strings
ms.assetid: 105f2d33-221a-4f6d-864c-23c1865c42af
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f23c4836d178c64590536a809ac5fe6cbbdf8380
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32416495"
---
# <a name="wcstombss-wcstombssl"></a>wcstombs_s, _wcstombs_s_l

Converte uma sequência de caracteres largos em uma sequência de caracteres multibyte correspondente. Uma versão de [wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t wcstombs_s(
   size_t *pReturnValue,
   char *mbstr,
   size_t sizeInBytes,
   const wchar_t *wcstr,
   size_t count
);

errno_t _wcstombs_s_l(
   size_t *pReturnValue,
   char *mbstr,
   size_t sizeInBytes,
   const wchar_t *wcstr,
   size_t count,
   _locale_t locale
);

template <size_t size>
errno_t wcstombs_s(
   size_t *pReturnValue,
   char (&mbstr)[size],
   const wchar_t *wcstr,
   size_t count
); // C++ only

template <size_t size>
errno_t _wcstombs_s_l(
   size_t *pReturnValue,
   char (&mbstr)[size],
   const wchar_t *wcstr,
   size_t count,
   _locale_t locale
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*pReturnValue*<br/>
O número de caracteres convertidos.

*mbstr*<br/>
O endereço de um buffer da cadeia de caracteres multibyte convertida resultante.

*sizeInBytes*<br/>
O tamanho em bytes do *mbstr* buffer.

*wcstr*<br/>
Aponta para a cadeia de caracteres largos a ser convertida.

*count*<br/>
O número máximo de bytes para armazenar no *mbstr* buffer, não incluindo o caractere null de terminação ou [TRUNCATE](../../c-runtime-library/truncate.md).

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*mbstr* é **nulo** e *sizeInBytes* > 0|**EINVAL**|
|*wcstr* é **nulo**|**EINVAL**|
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que *contagem* é **TRUNCATE**; consulte comentários abaixo)|**ERANGE**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, a função retornará um código de erro e define **errno** conforme indicado na tabela.

## <a name="remarks"></a>Comentários

O **wcstombs_s** função converte uma cadeia de caracteres largos apontada pelo *wcstr* em caracteres multibyte armazenados no buffer apontado pelo *mbstr*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere largo nulo é encontrado

- Um caractere largo que não pode ser convertido é encontrado

- O número de bytes armazenados no *mbstr* buffer é igual a *contagem*.

A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).

Se *contagem* é o valor especial [TRUNCATE](../../c-runtime-library/truncate.md), em seguida, **wcstombs_s** converte máximo da cadeia de caracteres como será se ajustar no buffer de destino, enquanto ainda deixa espaço para um valor nulo terminador. Se a cadeia de caracteres é truncada, o valor de retorno é **STRUNCATE**, e a conversão é considerada bem-sucedido.

Se **wcstombs_s** com êxito converte a cadeia de caracteres de origem, ele coloca o tamanho em bytes da cadeia de caracteres convertida, incluindo o terminador nulo, em  *&#42;pReturnValue* (fornecido  *pReturnValue* não é **nulo**). Isso ocorre mesmo se o *mbstr* argumento é **nulo** e fornece uma maneira de determinar o tamanho do buffer necessário. Observe que, se *mbstr* é **nulo**, *contagem* será ignorado.

Se **wcstombs_s** encontra um caractere largo não é possível converter um caractere multibyte, ele coloca 0  *&#42;pReturnValue*, define o buffer de destino como uma cadeia de caracteres vazia, define **errno**  para **EILSEQ**e retorna **EILSEQ**.

Se as sequências apontada pelo *wcstr* e *mbstr* se sobrepõem, o comportamento de **wcstombs_s** é indefinido.

> [!IMPORTANT]
> Certifique-se de que *wcstr* e *mbstr* não se sobrepõem e que *contagem* corretamente reflete o número de caracteres largos para converter.

**wcstombs_s** usa a localidade atual para qualquer comportamento dependente de localidade; **wcstombs_s_l** é idêntico ao **wcstombs** exceto que ele usa a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wcstombs_s**|\<stdlib.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este programa ilustra o comportamento do **wcstombs_s** função.

```C
// crt_wcstombs_s.c
// This example converts a wide character
// string to a multibyte character string.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER_SIZE 100

int main( void )
{
    size_t   i;
    char      *pMBBuffer = (char *)malloc( BUFFER_SIZE );
    wchar_t*pWCBuffer = L"Hello, world.";

    printf( "Convert wide-character string:\n" );

    // Conversion
    wcstombs_s(&i, pMBBuffer, (size_t)BUFFER_SIZE,
               pWCBuffer, (size_t)BUFFER_SIZE );

    // Output
    printf("   Characters converted: %u\n", i);
    printf("    Multibyte character: %s\n\n",
     pMBBuffer );

    // Free multibyte character buffer
    if (pMBBuffer)
    {
    free(pMBBuffer);
    }
}
```

```Output
Convert wide-character string:
   Characters converted: 14
    Multibyte character: Hello, world.
```

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[wctomb_s, _wctomb_s_l](wctomb-s-wctomb-s-l.md)<br/>
[WideCharToMultiByte](http://msdn.microsoft.com/library/windows/desktop/dd374130)<br/>
