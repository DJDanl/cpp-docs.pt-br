---
title: _mbsnbicmp, _mbsnbicmp_l
ms.date: 11/04/2016
api_name:
- _mbsnbicmp_l
- _mbsnbicmp
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _strnicmp
- _wcsnicmp_l
- _mbsnbicmp
- mbsnbicmp
- mbsnbicmp_l
- _tcsnicmp
- _strnicmp_l
- _tcsnicmp_l
- _wcsnicmp
- _mbsnbicmp_l
helpviewer_keywords:
- _tcsnicmp_l function
- _strnicmp function
- mbsnbicmp_l function
- _wcsnicmp_l function
- _mbsnbicmp function
- _mbsnbicmp_l function
- _tcsnicmp function
- _strnicmp_l function
- mbsnbicmp function
- _wcsnicmp function
ms.assetid: ddb44974-8b0c-42f0-90d0-56c9350bae0c
ms.openlocfilehash: 19ffa4c47f0144ba136607fe5cef09e9bd65374f
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70952183"
---
# <a name="_mbsnbicmp-_mbsnbicmp_l"></a>_mbsnbicmp, _mbsnbicmp_l

Compara **n** bytes de duas cadeias de caracteres multibyte e ignora maiúsculas e minúsculas.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _mbsnbicmp(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count
);
```

### <a name="parameters"></a>Parâmetros

*string1*, *string2*<br/>
Cadeias de caracteres com terminação nula.

*count*<br/>
Número de bytes a serem comparados.

## <a name="return-value"></a>Valor de retorno

O valor retornado indica a relação entre as subcadeias de caracteres.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|Subcadeia de caracteres *Cadeia1* menor que a subcadeia de *seqüência2* .|
|0|Subcadeia de caracteres *seqüência1* idêntica à subcadeia de *seqüência2* .|
|> 0|Subcadeia de caracteres *seqüência1* maior que a subcadeia de *seqüência2* .|

Em um erro, **_mbsnbicmp** retorna **_NLSCMPERROR**, que é definido em String. h e Mbstring. h.

## <a name="remarks"></a>Comentários

A função **_mbsnbicmp** executa uma comparação ordinal de, no máximo, os bytes da primeira *contagem* de *seqüência1* e *seqüência2*. A comparação é executada convertendo cada caractere em minúsculas; [_mbsnbcmp](mbsnbcmp-mbsnbcmp-l.md) é uma versão com diferenciação de maiúsculas e minúsculas do **_mbsnbicmp**. A comparação terminará se um caractere nulo de terminação for atingido em qualquer cadeia de caracteres antes de a *contagem* deles ser comparada. Se as cadeias de caracteres forem iguais quando um caractere nulo de terminação for atingido em uma cadeia de caracteres antes de a *contagem* de caracteres serem comparados, a cadeia de caracteres menor será menor.

**_mbsnbicmp** é semelhante a [_mbsnbcmp](mbsnbcmp-mbsnbcmp-l.md), exceto pelo fato de que ele compara Cadeias de caracteres com até *contagem* de bytes, em vez de personagens.

Duas cadeias de caracteres que contêm caracteres localizados entre 'Z' e 'a' na tabela ASCII ('[', '\\', ']', '^', '_' e '\`') são comparadas de modo diferente, dependendo das maiúsculas e minúsculas delas. Por exemplo, as duas cadeias de caracteres "ABCDE" e "ABCD ^" comparam uma maneira se a comparação for minúscula ("ABCDE" > "abcd ^") e a outra maneira ("ABCDE" < "ABCD ^") se for maiúscula.

o **_mbsnbicmp** reconhece sequências de caracteres multibyte de acordo com a [página de código multibyte](../../c-runtime-library/code-pages.md) em uso no momento. Ela não é afetada pela configuração da localidade atual.

Se *seqüência1* ou *seqüência2* for um ponteiro nulo, **_mbsnbicmp** invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará **_NLSCMPERROR** e definirá **errno** como **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tcsnicmp**|**_strnicmp**|**_mbsnbicmp**|**_wcsnicmp**|
|**_tcsnicmp_l**|**_strnicmp_l**|**_mbsnbicmp_l**|**_wcsnicmp_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_mbsnbicmp**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_mbsnbcmp, _mbsnbcmp_l](mbsnbcmp-mbsnbcmp-l.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_mbsnbcat, _mbsnbcat_l](mbsnbcat-mbsnbcat-l.md)<br/>
[_mbsnbcmp, _mbsnbcmp_l](mbsnbcmp-mbsnbcmp-l.md)<br/>
[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)<br/>
