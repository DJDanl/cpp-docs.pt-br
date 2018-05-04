---
title: mbsrtowcs | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- mbsrtowcs function
ms.assetid: f3a29de8-e36e-425b-a7fa-a258e6d7909d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ccb5bda16238888905678ffb3b6de01b93555ad0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
Um ponteiro para um **mbstate_t** objeto de estado de conversão. Se esse valor for um ponteiro nulo, um objeto de estado de conversão interno estático será usado. Porque o interno **mbstate_t** objeto não é thread-safe, recomendamos que você sempre passa seu próprio *mbstate* parâmetro.

## <a name="return-value"></a>Valor de retorno

Retorna o número de caracteres convertidos com êxito, sem incluir o caractere nulo de terminação, se houver. Retorna (size_t)(-1) se ocorreu um erro e define **errno** para EILSEQ.

## <a name="remarks"></a>Comentários

O **mbsrtowcs** função converte uma cadeia de caracteres multibyte indiretamente apontada pelo *mbstr*, em caracteres largos armazenados no buffer apontado pelo *wcstr*, por usando o estado de conversão contido em *mbstate*. A conversão continua para cada caractere até que um terminação nulo multibyte caractere for encontrado, uma sequência de multibyte não corresponde a um caractere válido na localidade atual for encontrada, ou até *contagem* caracteres foram convertidos. Se **mbsrtowcs** encontra o caractere null de multibyte ('\0') antes ou quando *contagem* ocorrer, ele converte em um caractere null de terminação 16 bits e para.

Assim, a cadeia de caracteres longa em *wcstr* é terminada em nulo apenas se **mbsrtowcs** encontra um caractere nulo multibyte durante a conversão. Se as sequências apontada pelo *mbstr* e *wcstr* se sobrepõem, o comportamento de **mbsrtowcs** é indefinido. **mbsrtowcs** é afetado pela categoria do LC_TYPE da localidade atual.

O **mbsrtowcs** função difere da [mbstowcs, mbstowcs_l](mbstowcs-mbstowcs-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para o mesmo ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo deve usar **mbsrlen** em vez de **mbslen**, se uma chamada subsequente para **mbsrtowcs** é usado em vez de **mbstowcs**.

Se *wcstr* não é um ponteiro nulo, o objeto de ponteiro apontada pelo *mbstr* é atribuído um ponteiro nulo se a conversão foi interrompida porque foi atingido um caractere null de terminação. Caso contrário, será atribuído o endereço logo depois do último caractere multibyte convertido, se houver. Isso permite que uma chamada de função subsequente reinicie a conversão em que essa chamada é interrompida.

Se o *wcstr* argumento é um ponteiro nulo, o *contagem* argumento será ignorado e **mbsrtowcs** retorna o tamanho necessário em caracteres largos para a cadeia de caracteres de destino. Se *mbstate* é um ponteiro nulo, a função usa non-thread-safe estático interno **mbstate_t** objeto de estado de conversão. Se a sequência de caracteres *mbstr* não tem um multibyte correspondente representação de caractere, -1 será retornado e a **errno** é definido como **EILSEQ**.

Se *mbstr* ponteiro nulo isa, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retorna -1.

Em C++, essa função tem uma sobrecarga de modelo que invoca o equivalente mais recente e seguro dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="exceptions"></a>Exceções

O **mbsrtowcs** função é safe multithread desde que nenhuma função no thread atual chama **setlocale** desde que essa função está em execução e o *mbstate* argumento não é um ponteiro nulo.

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
