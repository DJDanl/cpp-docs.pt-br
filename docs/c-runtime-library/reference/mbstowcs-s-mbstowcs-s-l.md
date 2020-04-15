---
title: mbstowcs_s, _mbstowcs_s_l
ms.date: 4/2/2020
api_name:
- _mbstowcs_s_l
- mbstowcs_s
- _o__mbstowcs_s_l
- _o_mbstowcs_s
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 07d694a7430f23e2f9600a5d2b147bcee2ef0e09
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338807"
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

*Preturnvalue*<br/>
O número de caracteres convertidos.

*Wcstr*<br/>
Endereço do buffer para a cadeia de caracteres largos convertida resultante.

*sizeInWords*<br/>
O tamanho do *tampão wcstr* em palavras.

*Mbstr*<br/>
O endereço de uma sequência de caracteres multibyte terminadas por nulo.

*contagem*<br/>
O número máximo de caracteres largos para armazenar no buffer *wcstr,* sem incluir o nulo final, ou [_TRUNCATE](../../c-runtime-library/truncate.md).

*Localidade*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*wcstr* é **NULL** e *tamanhoInWords* > 0|**Einval**|
|*mbstr* é **NULO**|**Einval**|
|O buffer de destino é muito pequeno para conter a seqüência convertida (a menos que a *contagem* seja **_TRUNCATE;** veja Observações abaixo)|**ERANGE**|
|*wcstr* não é **NULO** e *tamanhoInWords* == 0|**Einval**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna um código de erro e define **errno** como indicado na tabela.

## <a name="remarks"></a>Comentários

A função **mbstowcs_s** converte uma seqüência de caracteres multibytes apontados por *mbstr* em caracteres largos armazenados no buffer apontado por *wcstr*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere nulo multibyte é encontrado

- Um caractere multibyte inválido é encontrado

- O número de caracteres largos armazenados no buffer *wcstr* é igual *a contagem*.

A cadeia de caracteres de destino sempre é terminada em nulo (mesmo em caso de erro).

Se *a contagem* for o valor especial [_TRUNCATE,](../../c-runtime-library/truncate.md)então **mbstowcs_s** converte tanto da string quanto caberá no buffer de destino, enquanto ainda deixa espaço para um exterminador nulo.

Se **mbstowcs_s** converter com sucesso a seqüência de caracteres de origem, ele coloca o tamanho em caracteres amplos da seqüência de caracteres convertidos, incluindo o exterminador nulo, em *&#42;pReturnValue* (desde *que pReturnValue* não seja **NULL**). Isso ocorre mesmo que o *argumento wcstr* seja **NULO** e forneça uma maneira de determinar o tamanho de buffer necessário. Observe que se *wcstr* for **NULL**, *a contagem* é ignorada e *o tamanhoInWords* deve ser 0.

Se **mbstowcs_s** encontrar um caractere multibyte inválido, ele coloca 0 em *&#42;pReturnValue,* define o buffer de destino como uma seqüência vazia, define **errno** para **EILSEQ**e retorna **EILSEQ**.

Se as seqüências apontadas por *mbstr* e *wcstr* se sobrepõem, o comportamento de **mbstowcs_s** é indefinido.

> [!IMPORTANT]
> Certifique-se de que *wcstr* e *mbstr* não se sobrepõem, e essa *contagem* reflete corretamente o número de caracteres multibytes a serem convertidos.

**mbstowcs_s** usa o local atual para qualquer comportamento dependente de localidades; **_mbstowcs_s_l** é idêntica, exceto que usa o local passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbstowcs_s**|\<stdlib.h>|
|**_mbstowcs_s_l**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
