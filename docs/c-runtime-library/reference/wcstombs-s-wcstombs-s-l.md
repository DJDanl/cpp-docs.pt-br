---
title: wcstombs_s, _wcstombs_s_l
ms.date: 11/04/2016
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
helpviewer_keywords:
- wcstombs_s function
- string conversion, wide characters
- wide characters, converting
- _wcstombs_s_l function
- wcstombs_s_l function
- characters, converting
- string conversion, multibyte character strings
ms.assetid: 105f2d33-221a-4f6d-864c-23c1865c42af
ms.openlocfilehash: 3f30ef1f94803005a1afd99a6f82c46296f5c4f7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498996"
---
# <a name="wcstombs_s-_wcstombs_s_l"></a>wcstombs_s, _wcstombs_s_l

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
O tamanho em bytes da cadeia de caracteres convertida, incluindo o terminador nulo.

*mbstr*<br/>
O endereço de um buffer da cadeia de caracteres multibyte convertida resultante.

*sizeInBytes*<br/>
O tamanho em bytes do buffer *mbstr* .

*wcstr*<br/>
Aponta para a cadeia de caracteres largos a ser convertida.

*count*<br/>
O número máximo de bytes a serem armazenados no buffer *mbstr* , não incluindo o caractere nulo de terminação ou [_TRUNCATE](../../c-runtime-library/truncate.md).

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*mbstr* é **nulo** e *sizeInBytes* > 0|**EINVAL**|
|*wcstr* é **nulo**|**EINVAL**|
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que a *contagem* seja **_TRUNCATE**; consulte os comentários abaixo)|**ERANGE**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará um código de erro e definirá **errno** como indicado na tabela.

## <a name="remarks"></a>Comentários

A função **wcstombs_s** converte uma cadeia de caracteres largos apontados por *wcstr* em caracteres multibyte armazenados no buffer apontado pelo *mbstr*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere largo nulo é encontrado

- Um caractere largo que não pode ser convertido é encontrado

- O número de bytes armazenados na *contagem*de Equals do buffer *mbstr* .

A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).

Se *Count* for o valor especial [_TRUNCATE](../../c-runtime-library/truncate.md), **wcstombs_s** converterá a maior parte da cadeia de caracteres que se ajustará ao buffer de destino, enquanto ainda deixará espaço para um terminador nulo. Se a cadeia de caracteres estiver truncada, o valor de retorno será **STRUNCATE**e a conversão será considerada com êxito.

Se **wcstombs_s** converter com êxito a cadeia de caracteres de origem, ela colocará o tamanho em bytes da cadeia de caracteres convertida,  *&#42;* incluindo o terminador nulo, em pretransformvalue (a preactivavalue fornecida não é **nula**). Isso ocorre mesmo que o argumento *mbstr* seja **nulo** e forneça uma maneira de determinar o tamanho do buffer necessário. Observe que, se *mbstr* for **NULL**, *Count* será ignorado.

Se **wcstombs_s** encontrar um caractere largo, ele não poderá converter para um caractere multibyte, ele colocará 0 em  *&#42;* preligávalue, definirá o buffer de destino como uma cadeia de caracteres vazia, definirá **errno** como **EILSEQ**e retornará **EILSEQ**.

Se as sequências apontadas por *wcstr* e *mbstr* se sobrepõem, o comportamento de **wcstombs_s** é indefinido.

> [!IMPORTANT]
> Verifique se *wcstr* e *mbstr* não se sobrepõem e se *Count* reflete corretamente o número de caracteres largos a serem convertidos.

**wcstombs_s** usa a localidade atual para qualquer comportamento dependente de localidade; **_wcstombs_s_l** é idêntico ao **wcstombs** , exceto pelo fato de que ele usa a localidade transmitida em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wcstombs_s**|\<stdlib.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este programa ilustra o comportamento da função **wcstombs_s** .

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
[WideCharToMultiByte](/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte)<br/>
