---
title: fwrite
ms.date: 11/04/2016
apiname:
- fwrite
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- fwrite
helpviewer_keywords:
- streams, writing data to
- fwrite function
ms.assetid: 7afacf3a-72d7-4a50-ba2e-bea1ab9f4124
ms.openlocfilehash: b4d6b9ce4fb66ee545f52946e28e4984d9e4f924
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50506736"
---
# <a name="fwrite"></a>fwrite

Grava dados em um fluxo.

## <a name="syntax"></a>Sintaxe

```C
size_t fwrite(
   const void *buffer,
   size_t size,
   size_t count,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*buffer*<br/>
Ponteiro para os dados a serem gravados.

*size*<br/>
Tamanho do item, em bytes.

*count*<br/>
Máximo de itens a serem gravados.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

**fwrite** retorna o número de completo itens são gravados, que pode ser menor que *contagem* se ocorrer um erro. Além disso, em caso de erro, não será possível determinar o indicador de posição do arquivo. Se qualquer um dos *stream* ou *buffer* for um ponteiro nulo ou se um número ímpar de bytes a serem gravados for especificado no modo Unicode, a função invocará o manipulador de parâmetro inválido, conforme descrito em [ Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá **errno** à **EINVAL** e retornará 0.

## <a name="remarks"></a>Comentários

O **fwrite** função grava até *contagem* itens, de *tamanho* comprimento cada um, de *buffer* para a saída *fluxo*. O ponteiro de arquivo associado *stream* (se houver) é incrementado pelo número de bytes gravados. Se *stream* é aberto no modo de texto, cada avanço de linha é substituído por um retorno de carro - alimentação de linha par. A substituição não interfere no valor retornado.

Quando *stream* é aberto no modo de conversão de Unicode – por exemplo, se *fluxo* é aberta chamando **fopen** e usando um parâmetro de modo que inclui **ccs = UNICODE**, **ccs = UTF-16LE**, ou **ccs = UTF-8**, ou se o modo for alterado para um modo de translação Unicode usando **setmode** e um modo parâmetro que inclui **o_wtext**, **_O_U16TEXT**, ou **_O_U8TEXT**—*buffer* é interpretado como um ponteiro para um matriz de **wchar_t** que contém dados UTF-16. Tentar gravar uma quantidade ímpar de bytes nesse modo gera um erro de validação de parâmetro.

Como essa função bloqueia o thread da chamada, ela é thread-safe. Para obter uma versão sem bloqueio, consulte **fwrite_nolock**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fwrite**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [thread](fread.md).

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_setmode](setmode.md)<br/>
[fread](fread.md)<br/>
[_fwrite_nolock](fwrite-nolock.md)<br/>
[_write](write.md)<br/>
