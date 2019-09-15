---
title: mbstowcs_s, _mbstowcs_s_l
ms.date: 11/04/2016
api_name:
- _mbstowcs_s_l
- mbstowcs_s
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-convert-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _mbstowcs_s_l
- mbstowcs_s
helpviewer_keywords:
- _mbstowcs_s_l function
- mbstowcs_s function
- mbstowcs_s_l function
ms.assetid: 2fbda953-6918-498f-b440-3e7b21ed65a4
ms.openlocfilehash: 0812c3f667f28c5c43d7932d4746052dbaff3a60
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70952012"
---
# <a name="mbstowcs_s-_mbstowcs_s_l"></a>mbstowcs_s, _mbstowcs_s_l

Converte uma sequência de caracteres multibyte em uma sequência de caracteres largos correspondente. As versões de [mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t mbstowcs_s(
   size_t *pReturnValue,
   wchar_t *wcstr,
   size_t sizeInWords,
   const char *mbstr,
   size_t count
);
errno_t _mbstowcs_s_l(
   size_t *pReturnValue,
   wchar_t *wcstr,
   size_t sizeInWords,
   const char *mbstr,
   size_t count,
   _locale_t locale
);
template <size_t size>
errno_t mbstowcs_s(
   size_t *pReturnValue,
   wchar_t (&wcstr)[size],
   const char *mbstr,
   size_t count
); // C++ only
template <size_t size>
errno_t _mbstowcs_s_l(
   size_t *pReturnValue,
   wchar_t (&wcstr)[size],
   const char *mbstr,
   size_t count,
   _locale_t locale
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*pReturnValue*<br/>
O número de caracteres convertidos.

*wcstr*<br/>
Endereço do buffer para a cadeia de caracteres largos convertida resultante.

*sizeInWords*<br/>
O tamanho do buffer *wcstr* em palavras.

*mbstr*<br/>
O endereço de uma sequência de caracteres multibyte terminadas por nulo.

*count*<br/>
O número máximo de caracteres largos para armazenar no buffer *wcstr* , sem incluir o nulo de terminação ou [_TRUNCATE](../../c-runtime-library/truncate.md).

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*wcstr* é **nulo** e *sizeInWords* > 0|**EINVAL**|
|*mbstr* é **nulo**|**EINVAL**|
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que a *contagem* seja **_TRUNCATE**; consulte os comentários abaixo)|**ERANGE**|
|*wcstr* não é **nulo** e *sizeInWords* = = 0|**EINVAL**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará um código de erro e definirá **errno** como indicado na tabela.

## <a name="remarks"></a>Comentários

A função **mbstowcs_s** converte uma cadeia de caracteres de vários bytes apontados por *mbstr* em caracteres largos armazenados no buffer apontados pelo *wcstr*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere nulo multibyte é encontrado

- Um caractere multibyte inválido é encontrado

- O número de caracteres largos armazenados na *contagem*de Equals do buffer *wcstr* .

A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).

Se *Count* for o valor especial [_TRUNCATE](../../c-runtime-library/truncate.md), **mbstowcs_s** converterá a maior parte da cadeia de caracteres que se ajustará ao buffer de destino, enquanto ainda deixará espaço para um terminador nulo.

Se **mbstowcs_s** converter com êxito a cadeia de caracteres de origem, ela colocará o tamanho em caracteres largos da cadeia de caracteres convertida, incluindo o terminador nulo, em  *&#42;preligávalue* (a *preactivavalue* fornecida não é **nula**). Isso ocorre mesmo que o argumento *wcstr* seja **nulo** e forneça uma maneira de determinar o tamanho do buffer necessário. Observe que, se *wcstr* for **NULL**, *Count* será ignorado e *sizeInWords* deverá ser 0.

Se **mbstowcs_s** encontrar um caractere multibyte inválido, ele colocará 0 em  *&#42;preligávalue*, definirá o buffer de destino como uma cadeia de caracteres vazia, definirá **errno** como **EILSEQ**e retornará **EILSEQ**.

Se as sequências apontadas por *mbstr* e *wcstr* se sobrepõem, o comportamento de **mbstowcs_s** é indefinido.

> [!IMPORTANT]
> Verifique se *wcstr* e *mbstr* não se sobrepõem e se *Count* reflete corretamente o número de caracteres multibyte a serem convertidos.

**mbstowcs_s** usa a localidade atual para qualquer comportamento dependente de localidade; **_mbstowcs_s_l** é idêntico, exceto pelo fato de que ele usa a localidade transmitida em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbstowcs_s**|\<stdlib.h>|
|**_mbstowcs_s_l**|\<stdlib.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
