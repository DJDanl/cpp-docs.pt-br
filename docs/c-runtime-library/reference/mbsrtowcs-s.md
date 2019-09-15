---
title: mbsrtowcs_s
ms.date: 11/04/2016
api_name:
- mbsrtowcs_s
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- mbsrtowcs_s
helpviewer_keywords:
- mbsrtowcs_s function
ms.assetid: 4ee084ec-b15d-4e5a-921d-6584ec3b5a60
ms.openlocfilehash: d79cceaf923c1da126a1d133a8d2eb8752883457
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70952094"
---
# <a name="mbsrtowcs_s"></a>mbsrtowcs_s

Converte uma cadeia de caracteres multibyte na localidade atual para sua representação de cadeia de caracteres largos. Uma versão de [mbsrtowcs](mbsrtowcs.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t mbsrtowcs_s(
   size_t * pReturnValue,
   wchar_t * wcstr,
   size_t sizeInWords,
   const char ** mbstr,
   size_t count,
   mbstate_t * mbstate
);
template <size_t size>
errno_t mbsrtowcs_s(
   size_t * pReturnValue,
   wchar_t (&wcstr)[size],
   const char ** mbstr,
   size_t count,
   mbstate_t * mbstate
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*pReturnValue*<br/>
O número de caracteres convertidos.

*wcstr*<br/>
Endereço do buffer para armazenar a cadeia de caracteres largos convertida resultante.

*sizeInWords*<br/>
O tamanho de *wcstr* em palavras (caracteres largos).

*mbstr*<br/>
O ponteiro indireto para o local da cadeia de caracteres multibyte a ser convertida.

*count*<br/>
O número máximo de caracteres largos para armazenar no buffer *wcstr* , sem incluir o nulo de terminação ou [_TRUNCATE](../../c-runtime-library/truncate.md).

*mbstate*<br/>
Um ponteiro para um objeto de estado de conversão **mbstate_t** . Se esse valor for um ponteiro nulo, um objeto de estado de conversão interno estático será usado. Como o objeto **mbstate_t** interno não é thread-safe, é recomendável que você sempre passe seu próprio parâmetro *mbstate* .

## <a name="return-value"></a>Valor de retorno

Zero se a conversão for bem-sucedida ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*wcstr* é um ponteiro nulo e *sizeInWords* > 0|**EINVAL**|
|*mbstr* é um ponteiro nulo|**EINVAL**|
|A cadeia de caracteres apontada indiretamente por *mbstr* contém uma sequência multibyte que não é válida para a localidade atual.|**EILSEQ**|
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que a *contagem* seja **_TRUNCATE**; para obter mais informações, consulte comentários)|**ERANGE**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará um código de erro e definirá **errno** como indicado na tabela.

## <a name="remarks"></a>Comentários

A função **mbsrtowcs_s** converte uma cadeia de caracteres multibyte indiretamente apontada por *mbstr* em caracteres largos armazenados no buffer apontados pelo *wcstr*, usando o estado de conversão contido em *mbstate*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere nulo multibyte é encontrado

- Um caractere multibyte inválido é encontrado

- O número de caracteres largos armazenados na *contagem*de Equals do buffer *wcstr* .

A cadeia de caracteres de destino *wcstr* é sempre terminada em nulo, mesmo no caso de um erro, a menos que *wcstr* seja um ponteiro nulo.

Se *Count* for o valor especial [_TRUNCATE](../../c-runtime-library/truncate.md), **mbsrtowcs_s** converterá a maior parte da cadeia de caracteres que se ajustará ao buffer de destino e, ao mesmo tempo, deixará espaço para um terminador nulo.

Se o **mbsrtowcs_s** converter com êxito a cadeia de caracteres de origem, ele colocará o tamanho em caracteres largos da cadeia de caracteres convertida e o terminador nulo em  *&#42;preligávalue*, desde que o *preativarvalue* não seja um ponteiro nulo. Isso ocorre mesmo se o argumento *wcstr* é um ponteiro nulo e permite que você determine o tamanho do buffer necessário. Observe que, se *wcstr* for um ponteiro NULL, *Count* será ignorado.

Se *wcstr* não for um ponteiro NULL, o objeto pointer apontado por *mbstr* receberá um ponteiro NULL se a conversão for interrompida porque um caractere nulo de terminação foi atingido. Caso contrário, será atribuído o endereço logo depois do último caractere multibyte convertido, se houver. Isso permite que uma chamada de função subsequente reinicie a conversão em que essa chamada é interrompida.

Se *mbstate* for um ponteiro NULL, o objeto estático do estado de conversão **mbstate_t** interno da biblioteca será usado. Como esse objeto estático interno não é thread-safe, recomendamos que você passe seu próprio valor de *mbstate* .

Se **mbsrtowcs_s** encontrar um caractere multibyte que não seja válido na localidade atual, ele colocará-1 em  *&#42;preligávalue*, definirá o buffer de destino *wcstr* como uma cadeia de caracteres vazia, definirá **errno** como **EILSEQ**e retornará **EILSEQ**.

Se as sequências apontadas por *mbstr* e *wcstr* se sobrepõem, o comportamento de **mbsrtowcs_s** é indefinido. **mbsrtowcs_s** é afetado pela categoria LC_TYPE da localidade atual.

> [!IMPORTANT]
> Verifique se *wcstr* e *mbstr* não se sobrepõem e se *Count* reflete corretamente o número de caracteres multibyte a serem convertidos.

A função **mbsrtowcs_s** difere de [mbstowcs_s, _mbstowcs_s_l](mbstowcs-s-mbstowcs-s-l.md) por sua reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para as mesmas ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo deve usar **mbsrlen** em vez de **mbslen**, se uma chamada subsequente para **mbsrtowcs_s** for usada em vez de **mbstowcs_s**.

Em C++, o uso dessa função é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando o requisito de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras usando suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="exceptions"></a>Exceções

A função **mbsrtowcs_s** será multithread segura se nenhuma função no thread atual chamar **setlocaling** , desde que essa função esteja em execução e o argumento *mbstate* não seja um ponteiro nulo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbsrtowcs_s**|\<wchar.h>|

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbrtowc](mbrtowc.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[mbstowcs_s, _mbstowcs_s_l](mbstowcs-s-mbstowcs-s-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
