---
title: mbsrtowcs
ms.date: 4/2/2020
api_name:
- mbsrtowcs
- _o_mbsrtowcs
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
- api-ms-win-crt-convert-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- mbsrtowcs
helpviewer_keywords:
- mbsrtowcs function
ms.assetid: f3a29de8-e36e-425b-a7fa-a258e6d7909d
ms.openlocfilehash: 509046e1c55d89cd78b09076838983691423a1ee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338893"
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

*Wcstr*<br/>
Endereço para armazenar a cadeia de caracteres largos convertida resultante.

*Mbstr*<br/>
O ponteiro indireto para o local da cadeia de caracteres multibyte a ser convertida.

*contagem*<br/>
O número máximo de caracteres (não bytes) para converter e armazenar em *wcstr*.

*Mbstate*<br/>
Um ponteiro para um objeto de estado de conversão **mbstate_t.** Se esse valor for um ponteiro nulo, um objeto de estado de conversão interno estático será usado. Como o objeto **interno mbstate_t** não é seguro para rosca, recomendamos que você sempre passe seu próprio parâmetro *de mbstate.*

## <a name="return-value"></a>Valor retornado

Retorna o número de caracteres convertidos com êxito, sem incluir o caractere nulo de terminação, se houver. Retorna (size_t)(-1) se ocorreu um erro e define **errno** para EILSEQ.

## <a name="remarks"></a>Comentários

A função **mbsrtowcs** converte uma seqüência de caracteres multibytes indiretamente apontados por *mbstr,* em caracteres largos armazenados no buffer apontado por *wcstr,* usando o estado de conversão contido em *mbstate*. A conversão continua para cada personagem até que um caractere nulo final seja encontrado, uma seqüência multibyte que não corresponde a um caractere válido no local atual é encontrado, ou até que os caracteres *de contagem* tenham sido convertidos. Se **mbsrtowcs** encontrar o caractere nulo multibyte ('\0') antes ou quando a *contagem* ocorrer, ele o converte em um caractere nulo de 16 bits e pára.

Assim, a seqüência de caracteres ampla no *wcstr* é anulada apenas se **mbsrtowcs** encontrar um caractere nulo multibyte durante a conversão. Se as seqüências apontadas por *mbstr* e *wcstr* se sobrepõem, o comportamento dos **mbsrtowcs** é indefinido. **mbsrtowcs** é afetado pela categoria LC_TYPE da localidade atual.

A função **mbsrtowcs** difere de [mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subseqüentes para as mesmas ou outras funções reinicializáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo deve usar **mbsrlen** em vez de **mbslen,** se uma chamada subseqüente para **mbsrtowcs** for usada em vez de **mbstowcs**.

Se *o wcstr* não for um ponteiro nulo, o objeto de ponteiro apontado por *mbstr* é atribuído a um ponteiro nulo se a conversão foi interrompida porque um caractere nulo final foi alcançado. Caso contrário, será atribuído o endereço logo depois do último caractere multibyte convertido, se houver. Isso permite que uma chamada de função subsequente reinicie a conversão em que essa chamada é interrompida.

Se o argumento *wcstr* for um ponteiro nulo, o argumento *de contagem* será ignorado e **mbsrtowcs** retorna o tamanho necessário em caracteres largos para a seqüência de destinos. Se *o mbstate* for um ponteiro nulo, a função usará um objeto de estado de **conversão** mbstate_t estático não seguro de rosca. Se o *mbstr* de seqüência de caracteres não tiver uma representação de caractere multibyte correspondente, a -1 é devolvida e o **errno** é definido **como EILSEQ**.

Se o ponteiro nulo *mbstr* isa, o manipulador de parâmetros inválidos é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, esta função define **errno** para **EINVAL** e retorna -1.

Em C++, essa função tem uma sobrecarga de modelo que invoca o equivalente mais recente e seguro dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="exceptions"></a>Exceções

A função **mbsrtowcs** é segura em vários segmentos, desde que nenhuma função no **setlocale** de chamadas de thread atual, enquanto esta função estiver sendo executada e o argumento *mbstate* não seja um ponteiro nulo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbsrtowcs**|\<wchar.h>|

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbrtowc](mbrtowc.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
