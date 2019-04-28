---
title: _mbsnbcat, _mbsnbcat_l
ms.date: 11/04/2016
apiname:
- _mbsnbcat_l
- _mbsnbcat
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
- api-ms-win-crt-multibyte-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- mbsnbcat
- mbsnbcat_l
- _mbsnbcat
- _mbsnbcat_l
helpviewer_keywords:
- tcsncat_l function
- _tcsncat function
- mbsnbcat_l function
- mbsnbcat function
- _mbsnbcat_l function
- _tcsncat_l function
- _mbsnbcat function
- tcsncat function
ms.assetid: aa0f1d30-0ddd-48d1-88eb-c6884b20fd91
ms.openlocfilehash: c1da330ee0faba922f1e5b193fa095b97d3f4745
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62285539"
---
# <a name="mbsnbcat-mbsnbcatl"></a>_mbsnbcat, _mbsnbcat_l

Acrescenta, no máximo, os primeiros **n** bytes de uma cadeia de caracteres multibyte a outra. Estão disponíveis versões mais seguras dessas funções, consulte [_mbsnbcat_s, _mbsnbcat_s_l](mbsnbcat-s-mbsnbcat-s-l.md).

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
unsigned char *_mbsnbcat(
   unsigned char *dest,
   const unsigned char *src,
   size_t count
);
unsigned char *_mbsnbcat_l(
   unsigned char *dest,
   const unsigned char *src,
   size_t count,
   _locale_t locale
);
template <size_t size>
unsigned char *_mbsnbcat(
   unsigned char (&dest)[size],
   const unsigned char *src,
   size_t count
); // C++ only
template <size_t size>
unsigned char *_mbsnbcat_l(
   unsigned char (&dest)[size],
   const unsigned char *src,
   size_t count,
   _locale_t locale
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*dest*<br/>
Cadeia de caracteres de destino de caractere multibyte terminada em nulo.

*src*<br/>
Cadeia de caracteres de origem de caractere multibyte terminada em nulo.

*count*<br/>
Número de bytes do *src* para acrescentar ao *dest*.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

**mbsnbcat** retorna um ponteiro para a cadeia de caracteres de destino. Nenhum valor retornado é reservado para indicar um erro.

## <a name="remarks"></a>Comentários

O **mbsnbcat** função acrescenta, no máximo, os primeiros *contagem* bytes de *src* para *dest*. Se o byte imediatamente antes do caractere nulo em *dest* for um byte o byte inicial de *src* substituirá esse byte inicial. Caso contrário, o byte inicial de *src* substitui o caractere nulo de terminação de *dest*. Se aparecer um byte nulo no *src* antes de *contagem* bytes serem acrescentados, **mbsnbcat** acrescentará todos os bytes de *src*, até o caractere nulo. Se *contagem* é maior que o comprimento de *src*, o comprimento da *src* é usado no lugar de *contagem*. A cadeia de caracteres resultante é terminada com um caractere nulo. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.

O valor de saída é afetado pela configuração da categoria **LC_CTYPE** da localidade. Consulte [setlocale](setlocale-wsetlocale.md) para obter mais informações. O **mbsnbcat** versão da função usa a localidade atual desse comportamento dependente da localidade; as **mbsnbcat_l** versão é idêntico, exceto que eles usam o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

**Observação de Segurança** Use uma cadeia de caracteres terminada em nulo. A cadeia de caracteres terminada em nulo não deve exceder o tamanho do buffer de destino. Para obter mais informações, consulte [Avoiding Buffer Overruns](/windows/desktop/SecBP/avoiding-buffer-overruns) (Evitando estouros de buffer).

Se *dest* ou *src* está **nulo**, a função gerará um erro de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro for tratado, a função retornará **EINVAL** e define **errno** para **EINVAL**.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcsncat**|[strncat](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|**_mbsnbcat**|[wcsncat](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)|
|**_tcsncat_l**|**_strncat_l**|**_mbsnbcat_l**|**_wcsncat_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsnbcat**|\<mbstring.h>|
|**_mbsnbcat_l**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_mbsnbcmp, _mbsnbcmp_l](mbsnbcmp-mbsnbcmp-l.md)<br/>
[_strncnt, _wcsncnt, _mbsnbcnt, _mbsnbcnt_l, _mbsnccnt, _mbsnccnt_l](strncnt-wcsncnt-mbsnbcnt-mbsnbcnt-l-mbsnccnt-mbsnccnt-l.md)<br/>
[_mbsnbcpy, _mbsnbcpy_l](mbsnbcpy-mbsnbcpy-l.md)<br/>
[_mbsnbicmp, _mbsnbicmp_l](mbsnbicmp-mbsnbicmp-l.md)<br/>
[_mbsnbset, _mbsnbset_l](mbsnbset-mbsnbset-l.md)<br/>
[strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)<br/>
[_mbsnbcat_s, _mbsnbcat_s_l](mbsnbcat-s-mbsnbcat-s-l.md)<br/>
