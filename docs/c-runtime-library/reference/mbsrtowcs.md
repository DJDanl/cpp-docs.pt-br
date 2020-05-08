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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- mbsrtowcs
helpviewer_keywords:
- mbsrtowcs function
ms.assetid: f3a29de8-e36e-425b-a7fa-a258e6d7909d
ms.openlocfilehash: fc9310a95165944b7f516c1f8c48d8d4d1e56117
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82915488"
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

*contagem*<br/>
O número máximo de caracteres (não bytes) a serem convertidos e armazenados em *wcstr*.

*mbstate*<br/>
Um ponteiro para um objeto de estado de conversão de **mbstate_t** . Se esse valor for um ponteiro nulo, um objeto de estado de conversão interno estático será usado. Como o objeto de **mbstate_t** interno não é thread-safe, é recomendável que você sempre passe seu próprio parâmetro *mbstate* .

## <a name="return-value"></a>Valor retornado

Retorna o número de caracteres convertidos com êxito, sem incluir o caractere nulo de terminação, se houver. Retorna (size_t) (-1) se ocorreu um erro e define **errno** como EILSEQ.

## <a name="remarks"></a>Comentários

A função **mbsrtowcs** converte uma cadeia de caracteres de vários bytes indiretamente apontados por *mbstr*, em caracteres largos armazenados no buffer apontados pelo *wcstr*, usando o estado de conversão contido em *mbstate*. A conversão continua para cada caractere até que um caractere de multibyte nulo de terminação seja encontrado, uma sequência multibyte que não corresponde a um caractere válido na localidade atual é encontrada ou até que os caracteres de *contagem* tenham sido convertidos. Se **mbsrtowcs** encontrar o caractere nulo multibyte (' \ 0 ') antes ou quando ocorrer a *contagem* , ele o converterá em um caractere nulo de terminação de 16 bits e será interrompido.

Assim, a cadeia de caracteres larga em *wcstr* será encerrada em nulo somente se **mbsrtowcs** encontrar um caractere nulo multibyte durante a conversão. Se as sequências apontadas por *mbstr* e *wcstr* se sobrepõem, o comportamento de **mbsrtowcs** é indefinido. **mbsrtowcs** é afetado pela categoria de LC_TYPE da localidade atual.

A função **mbsrtowcs** difere de [mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md) por sua reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para as mesmas ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo deve usar **mbsrlen** em vez de **mbslen**, se uma chamada subsequente para **mbsrtowcs** for usada em vez de **mbstowcs**.

Se *wcstr* não for um ponteiro NULL, o objeto pointer apontado por *mbstr* receberá um ponteiro NULL se a conversão for interrompida porque um caractere nulo de terminação foi atingido. Caso contrário, será atribuído o endereço logo depois do último caractere multibyte convertido, se houver. Isso permite que uma chamada de função subsequente reinicie a conversão em que essa chamada é interrompida.

Se o argumento *wcstr* for um ponteiro NULL, o argumento *Count* será ignorado e **mbsrtowcs** retornará o tamanho necessário em caracteres largos para a cadeia de caracteres de destino. Se *mbstate* for um ponteiro nulo, a função usará um objeto de estado de conversão de **mbstate_t** interno estático sem thread. Se a sequência de caracteres *mbstr* não tiver uma representação de caractere multibyte correspondente, um-1 será retornado e o **errno** será definido como **EILSEQ**.

Se *mbstr* ponteiro NULL do ISA, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** como **EINVAL** e retornará-1.

Em C++, essa função tem uma sobrecarga de modelo que invoca o equivalente mais recente e seguro dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="exceptions"></a>Exceções

A função **mbsrtowcs** é multithread segura, desde que nenhuma função no thread atual chame **setlocal** , contanto que essa função esteja em execução e o argumento *mbstate* não seja um ponteiro nulo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbsrtowcs**|\<wchar.h>|

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Locale](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbrtowc](mbrtowc.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
