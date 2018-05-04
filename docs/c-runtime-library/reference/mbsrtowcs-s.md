---
title: mbsrtowcs_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- mbsrtowcs_s
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
- mbsrtowcs_s
dev_langs:
- C++
helpviewer_keywords:
- mbsrtowcs_s function
ms.assetid: 4ee084ec-b15d-4e5a-921d-6584ec3b5a60
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a8885d11c7fca10c63077464020a8bbab2b6f3ae
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="mbsrtowcss"></a>mbsrtowcs_s

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
O tamanho de *wcstr* palavras (caracteres largos).

*mbstr*<br/>
O ponteiro indireto para o local da cadeia de caracteres multibyte a ser convertida.

*count*<br/>
O número máximo de caracteres largos para armazenar no *wcstr* buffer, não incluindo o terminação null, ou [TRUNCATE](../../c-runtime-library/truncate.md).

*mbstate*<br/>
Um ponteiro para um **mbstate_t** objeto de estado de conversão. Se esse valor for um ponteiro nulo, um objeto de estado de conversão interno estático será usado. Porque o interno **mbstate_t** objeto não é thread-safe, recomendamos que você sempre passa seu próprio *mbstate* parâmetro.

## <a name="return-value"></a>Valor de retorno

Zero se a conversão for bem-sucedida ou um código de erro em caso de falha.

|Condição de erro|Valor de retorno e **errno**|
|---------------------|------------------------------|
|*wcstr* é um ponteiro nulo e *sizeInWords* > 0|**EINVAL**|
|*mbstr* é um ponteiro nulo|**EINVAL**|
|A cadeia de caracteres apontada indiretamente por *mbstr* contém uma sequência de multibyte não é válida para a localidade atual.|**EILSEQ**|
|O buffer de destino é muito pequeno para conter a cadeia de caracteres convertida (a menos que *contagem* é **TRUNCATE**; para obter mais informações, consulte comentários)|**ERANGE**|

Se qualquer uma dessas condições ocorrer, a exceção de parâmetro inválido será invocada, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, a função retornará um código de erro e define **errno** conforme indicado na tabela.

## <a name="remarks"></a>Comentários

O **mbsrtowcs_s** função converte uma cadeia de caracteres multibyte indiretamente apontada pelo *mbstr* em caracteres largos armazenados no buffer apontado pelo *wcstr*, por usando o estado de conversão contido em *mbstate*. A conversão continuará para cada caractere até que uma das seguintes condições seja atendida:

- Um caractere nulo multibyte é encontrado

- Um caractere multibyte inválido é encontrado

- O número de caracteres largos armazenados no *wcstr* buffer é igual a *contagem*.

A cadeia de caracteres de destino *wcstr* sempre é terminada em nulo, mesmo no caso de um erro, a menos que *wcstr* é um ponteiro nulo.

Se *contagem* é o valor especial [TRUNCATE](../../c-runtime-library/truncate.md), **mbsrtowcs_s** converte máximo da cadeia de caracteres como será se ajustar no buffer de destino, enquanto ainda deixa espaço para um valor nulo terminador.

Se **mbsrtowcs_s** com êxito converte a cadeia de caracteres de origem, ele coloca o tamanho em caracteres largos de cadeia de caracteres convertida e o terminador nulo em  *&#42;pReturnValue*, fornecido  *pReturnValue* não é um ponteiro nulo. Isso ocorre mesmo se o *wcstr* argumento é um ponteiro nulo e permite que você determine o tamanho do buffer necessário. Observe que, se *wcstr* é um ponteiro nulo, *contagem* será ignorado.

Se *wcstr* não é um ponteiro nulo, o objeto de ponteiro apontada pelo *mbstr* é atribuído um ponteiro nulo se a conversão foi interrompida porque foi atingido um caractere null de terminação. Caso contrário, será atribuído o endereço logo depois do último caractere multibyte convertido, se houver. Isso permite que uma chamada de função subsequente reinicie a conversão em que essa chamada é interrompida.

Se *mbstate* é um ponteiro nulo, a biblioteca interna **mbstate_t** objeto estático do estado de conversão é usado. Como esse objeto estático interno não é thread-safe, recomendamos que você passa sua própria *mbstate* valor.

Se **mbsrtowcs_s** encontrar um caractere de multibyte não é válido na localidade atual, ele coloca -1  *&#42;pReturnValue*, define o buffer de destino *wcstr* uma cadeia de caracteres vazia, define **errno** para **EILSEQ**e retorna **EILSEQ**.

Se as sequências apontada pelo *mbstr* e *wcstr* se sobrepõem, o comportamento de **mbsrtowcs_s** é indefinido. **mbsrtowcs_s** é afetado pela categoria do LC_TYPE da localidade atual.

> [!IMPORTANT]
> Certifique-se de que *wcstr* e *mbstr* não se sobrepõem e que *contagem* corretamente reflete o número de caracteres multibyte para converter.

O **mbsrtowcs_s** função difere da [mbstowcs_s, mbstowcs_s_l](mbstowcs-s-mbstowcs-s-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para o mesmo ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo deve usar **mbsrlen** em vez de **mbslen**, se uma chamada subsequente para **mbsrtowcs_s** é usado em vez de **mbstowcs_s**.

Em C++, o uso dessa função é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando o requisito de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras usando suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="exceptions"></a>Exceções

O **mbsrtowcs_s** função é safe multithread se nenhuma função nas chamadas thread atual **setlocale** desde que essa função está em execução e o *mbstate* argumento não é um ponteiro nulo.

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
