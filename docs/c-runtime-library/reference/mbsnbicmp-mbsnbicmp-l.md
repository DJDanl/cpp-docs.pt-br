---
title: _mbsnbicmp, _mbsnbicmp_l
ms.date: 4/2/2020
api_name:
- _mbsnbicmp_l
- _mbsnbicmp
- _o__mbsnbicmp
- _o__mbsnbicmp_l
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _mbsnbicmp
- mbsnbicmp
- mbsnbicmp_l
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
ms.openlocfilehash: 80d2708396cdaeb86c25932c3d13129fb318719a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81340572"
---
# <a name="_mbsnbicmp-_mbsnbicmp_l"></a>_mbsnbicmp, _mbsnbicmp_l

Compara **n** bytes de duas strings de caracteres multibytes, e ignora o caso.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _mbsnbicmp(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count
);
```

### <a name="parameters"></a>Parâmetros

*string1,* *string2*<br/>
Cadeias de caracteres com terminação nula.

*contagem*<br/>
Número de bytes a serem comparados.

## <a name="return-value"></a>Valor retornado

O valor retornado indica a relação entre as subcadeias de caracteres.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|*string1* substring menos do que *string2* substring.|
|0|*string1* substring idêntico ao substring *string2.*|
|> 0|*string1* substring maior do que *string2* substring.|

Em um erro, **_mbsnbicmp** retorna **_NLSCMPERROR**, que é definido em String.h e Mbstring.h.

## <a name="remarks"></a>Comentários

A função **_mbsnbicmp** realiza uma comparação ordinal de, no máximo, os bytes de primeira *contagem* de *string1* e *string2*. A comparação é realizada convertendo cada caractere em minúsculas; [_mbsnbcmp](mbsnbcmp-mbsnbcmp-l.md) é uma versão sensível ao caso de **_mbsnbicmp.** A comparação termina se um caractere nulo terminando for alcançado em qualquer seqüência antes *de contar* caracteres. Se as strings forem iguais quando um caractere nulo terminante for alcançado em qualquer seqüência antes de os caracteres *de contagem* forem comparados, a seqüência mais curta será menor.

**_mbsnbicmp** é semelhante ao [_mbsnbcmp,](mbsnbcmp-mbsnbcmp-l.md)exceto que ele compara strings até *contar* bytes em vez de por caracteres.

Duas cadeias de caracteres que contêm caracteres localizados entre 'Z' e 'a' na tabela ASCII ('[', '\\', ']', '^', '_' e '\`') são comparadas de modo diferente, dependendo das maiúsculas e minúsculas delas. Por exemplo, as duas cordas "ABCDE" e "ABCD^" comparam-se de uma maneira se a comparação for minúscula ("abcde" > "abcd^") e a outra ("ABCDE" < "ABCD^") se for maiúscula.

**_mbsnbicmp** reconhece sequências de caracteres multibytes de acordo com a [página de código multibyte](../../c-runtime-library/code-pages.md) atualmente em uso. Ela não é afetada pela configuração da localidade atual.

Se a *string1* ou *a string2* forem um ponteiro nulo, **_mbsnbicmp** invocará o manipulador de parâmetros inválidos conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna **_NLSCMPERROR** e define **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_mbsnbcat, _mbsnbcat_l](mbsnbcat-mbsnbcat-l.md)<br/>
[_mbsnbcmp, _mbsnbcmp_l](mbsnbcmp-mbsnbcmp-l.md)<br/>
[_stricmp, _wcsicmp, _mbsicmp, _stricmp_l, _wcsicmp_l, _mbsicmp_l](stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l-mbsicmp-l.md)<br/>
