---
title: mbsrtowcs
ms.date: 11/04/2016
apiname:
- mbsrtowcs
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
- mbsrtowcs
helpviewer_keywords:
- mbsrtowcs function
ms.assetid: f3a29de8-e36e-425b-a7fa-a258e6d7909d
ms.openlocfilehash: 2bc0c8c9e2d871b6d1748c42dc02c627244dbf69
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50597139"
---
# <a name="mbsrtowcs"></a>mbsrtowcs

Converte um caractere multibyte na localidade atual em uma cadeia de caracteres largos correspondente, com a capacidade de reiniciar no meio de um caractere multibyte. Uma versão mais segura dessa função está disponível, consulte [mbsrtowcs_s](mbsrtowcs-s.md).

## <a name="syntax"></a>Sintaxe

```C
size_t mbsrtowcs(
   wchar_t *wcstr,
   const char **mbstr,
   sizeof count,
   mbstate_t *mbstate
);
template <size_t size>
size_t mbsrtowcs(
   wchar_t (&wcstr)[size],
   const char **mbstr,
   sizeof count,
   mbstate_t *mbstate
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*wcstr*<br/>
Endereço para armazenar a cadeia de caracteres largos convertida resultante.

*mbstr*<br/>
O ponteiro indireto para o local da cadeia de caracteres multibyte a ser convertida.

*count*<br/>
O número máximo de caracteres (não em bytes) para converter e armazenar em *wcstr*.

*mbstate*<br/>
Um ponteiro para um **mbstate_t** objeto de estado de conversão. Se esse valor for um ponteiro nulo, um objeto de estado de conversão interno estático será usado. Porque o internal **mbstate_t** objeto não é thread-safe, é recomendável que você sempre passe seu próprio *mbstate* parâmetro.

## <a name="return-value"></a>Valor de retorno

Retorna o número de caracteres convertidos com êxito, sem incluir o caractere nulo de terminação, se houver. Retorna (size_t)(-1) se ocorreu um erro e define **errno** como EILSEQ.

## <a name="remarks"></a>Comentários

O **mbsrtowcs** função converte uma cadeia de caracteres multibyte apontada indiretamente por *mbstr*, em caracteres largos armazenados no buffer apontado por *wcstr*, por usando o estado de conversão contido em *mbstate*. A conversão continuará para cada caractere até que ambos um caractere nulo de terminação multibyte é encontrado, uma sequência multibyte que não corresponde a um caractere válido na localidade atual for encontrada, ou até *contagem* caracteres foram convertidos. Se **mbsrtowcs** encontra o caractere nulo multibyte ('\0') antes ou quando *contagem* ocorre, ele converte em um caractere nulo de terminação 16 bits e é interrompido.

Dessa forma, a cadeia de caracteres largos em *wcstr* é terminada em nulo somente se **mbsrtowcs** encontrar um caractere nulo multibyte durante a conversão. Se as sequências apontadas por *mbstr* e *wcstr* se sobrepõem, o comportamento do **mbsrtowcs** é indefinido. **mbsrtowcs** é afetado pela categoria LC_TYPE da localidade atual.

O **mbsrtowcs** função difere [mbstowcs, mbstowcs_l](mbstowcs-mbstowcs-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas posteriores às mesmas funções ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo deve usar **mbsrlen** em vez de **mbslen**, se uma chamada subsequente para **mbsrtowcs** é usado em vez de **mbstowcs**.

Se *wcstr* não é um ponteiro nulo, o objeto de ponteiro apontado por *mbstr* é atribuído um ponteiro nulo se a conversão foi interrompida porque um caractere nulo de terminação foi atingido. Caso contrário, será atribuído o endereço logo depois do último caractere multibyte convertido, se houver. Isso permite que uma chamada de função subsequente reinicie a conversão em que essa chamada é interrompida.

Se o *wcstr* argumento for um ponteiro nulo, o *contagem* argumento será ignorado e **mbsrtowcs** retornará o tamanho necessário em caracteres largos da cadeia de caracteres de destino. Se *mbstate* for um ponteiro nulo, a função usa um estático não thread-safe interno **mbstate_t** objeto de estado de conversão. Se a sequência de caracteres *mbstr* multibyte correspondente não tem representação de caractere, -1 será retornado e o **errno** está definido como **EILSEQ**.

Se *mbstr* um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retornará -1.

Em C++, essa função tem uma sobrecarga de modelo que invoca o equivalente mais recente e seguro dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="exceptions"></a>Exceções

O **mbsrtowcs** função será multithread-safe contanto que nenhuma função no thread atual chame **setlocale** desde que essa função está em execução e o *mbstate* argumento não é um ponteiro nulo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbsrtowcs**|\<wchar.h>|

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbrtowc](mbrtowc.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
