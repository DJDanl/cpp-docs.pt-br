---
title: mbsrtowcs_s
ms.date: 4/2/2020
api_name:
- mbsrtowcs_s
- _o_mbsrtowcs_s
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
- mbsrtowcs_s
helpviewer_keywords:
- mbsrtowcs_s function
ms.assetid: 4ee084ec-b15d-4e5a-921d-6584ec3b5a60
ms.openlocfilehash: 62ae534e8080b74ada49cca005811a049055cb65
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338896"
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

*Preturnvalue*<br/>
O número de caracteres convertidos.

*Wcstr*<br/>
Endereço do buffer para armazenar a cadeia de caracteres largos convertida resultante.

*sizeInWords*<br/>
O tamanho do *wcstr* em palavras (caracteres largos).

*Mbstr*<br/>
O ponteiro indireto para o local da cadeia de caracteres multibyte a ser convertida.

*contagem*<br/>
O número máximo de caracteres largos para armazenar no buffer *wcstr,* sem incluir o nulo final, ou [_TRUNCATE](../../c-runtime-library/truncate.md).

*Mbstate*<br/>
Um ponteiro para um objeto de estado de conversão **mbstate_t.** Se esse valor for um ponteiro nulo, um objeto de estado de conversão interno estático será usado. Como o objeto **interno mbstate_t** não é seguro para rosca, recomendamos que você sempre passe seu próprio parâmetro *de mbstate.*

## <a name="return-value"></a>Valor retornado

Zero se a conversão for bem-sucedida ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*wcstr* é um ponteiro nulo e *tamanhoInWords* > 0|**Einval**|
|*mbstr* é um ponteiro nulo|**Einval**|
|A seqüência indiretamente apontada por *mbstr* contém uma seqüência de vários bytes que não é válida para o local atual.|**EILSEQ**|
|O buffer de destino é muito pequeno para conter a seqüência convertida (a menos que a *contagem* seja **_TRUNCATE;** para obter mais informações, consulte Observações)|**ERANGE**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna um código de erro e define **errno** como indicado na tabela.

## <a name="remarks"></a>Comentários

A função **mbsrtowcs_s** converte uma seqüência de caracteres multibytes indiretamente apontados por *mbstr* em caracteres largos armazenados no buffer apontado por *wcstr,* usando o estado de conversão contido em *mbstate*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere nulo multibyte é encontrado

- Um caractere multibyte inválido é encontrado

- O número de caracteres largos armazenados no buffer *wcstr* é igual *a contagem*.

O *wcstr* de seqüência de destino é sempre nulo, mesmo no caso de um erro, a menos que *wcstr* seja um ponteiro nulo.

Se *a contagem* for o valor especial [_TRUNCATE,](../../c-runtime-library/truncate.md) **mbsrtowcs_s** converte tanto da string quanto caberá no buffer de destino, enquanto ainda deixa espaço para um exterminador nulo.

Se **mbsrtowcs_s** converte com sucesso a seqüência de caracteres de origem, ele coloca o tamanho em caracteres largos da seqüência de caracteres convertidos e o exterminador nulo em *&#42;pReturnValue,* desde que *pReturnValue* não seja um ponteiro nulo. Isso ocorre mesmo que o *argumento wcstr* seja um ponteiro nulo e permite determinar o tamanho de buffer necessário. Observe que se *wcstr* é um ponteiro nulo, *a contagem* é ignorada.

Se *o wcstr* não for um ponteiro nulo, o objeto de ponteiro apontado por *mbstr* é atribuído a um ponteiro nulo se a conversão foi interrompida porque um caractere nulo final foi alcançado. Caso contrário, será atribuído o endereço logo depois do último caractere multibyte convertido, se houver. Isso permite que uma chamada de função subsequente reinicie a conversão em que essa chamada é interrompida.

Se *mbstate* for um ponteiro nulo, o objeto estático do estado de conversão interna **mbstate_t** da biblioteca será usado. Como este objeto estático interno não é seguro para rosca, recomendamos que você passe seu próprio valor *de mbstate.*

Se **mbsrtowcs_s** encontrar um caractere multibyte que não é válido na localidade atual, ele coloca -1 em *&#42;pReturnValue*, define o buffer de destino *wcstr* como uma seqüência vazia, define **errno** para **EILSEQ**e retorna **EILSEQ**.

Se as seqüências apontadas por *mbstr* e *wcstr* se sobrepõem, o comportamento de **mbsrtowcs_s** é indefinido. **mbsrtowcs_s** é afetada pela categoria LC_TYPE da localidade atual.

> [!IMPORTANT]
> Certifique-se de que *wcstr* e *mbstr* não se sobrepõem, e essa *contagem* reflete corretamente o número de caracteres multibytes a serem convertidos.

A função **mbsrtowcs_s** difere [de mbstowcs_s, _mbstowcs_s_l](mbstowcs-s-mbstowcs-s-l.md) pela sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subseqüentes para as mesmas ou outras funções reinicializáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo deve usar **mbsrlen** em vez de **mbslen**, se uma chamada subseqüente para **mbsrtowcs_s** for usada em vez de **mbstowcs_s**.

Em C++, o uso dessa função é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando o requisito de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras usando suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="exceptions"></a>Exceções

A função **mbsrtowcs_s** é segura em vários segmentos se nenhuma função no **setlocal** de chamadas de thread atual enquanto esta função estiver sendo executada e o argumento *mbstate* não for um ponteiro nulo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbsrtowcs_s**|\<wchar.h>|

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbrtowc](mbrtowc.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[mbstowcs_s, _mbstowcs_s_l](mbstowcs-s-mbstowcs-s-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
