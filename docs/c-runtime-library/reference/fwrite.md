---
title: fwrite | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- streams, writing data to
- fwrite function
ms.assetid: 7afacf3a-72d7-4a50-ba2e-bea1ab9f4124
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f1320bcc61830833f2b1a4a225dff30652df2d3a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32400574"
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

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

**fwrite** retorna o número de completo itens realmente escritos, que pode ser menor que *contagem* se ocorrer um erro. Além disso, em caso de erro, não será possível determinar o indicador de posição do arquivo. Se qualquer um dos *fluxo* ou *buffer* é um ponteiro nulo, ou se for especificado um número ímpar de bytes a serem gravados no modo Unicode, a função invoca o manipulador de parâmetro inválido, conforme descrito em [ Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, esta função define **errno** para **EINVAL** e retornará 0.

## <a name="remarks"></a>Comentários

O **fwrite** função grava até *contagem* itens, de *tamanho* comprimento cada, de *buffer* para a saída *fluxo*. O ponteiro de arquivo associado ao *fluxo* (se houver) é incrementado pelo número de bytes gravados. Se *fluxo* é aberto no modo de texto, cada avanço de linha é substituído por um retorno de carro - alimentação de linha par. A substituição não interfere no valor retornado.

Quando *fluxo* é aberto no modo de conversão de Unicode — por exemplo, se *fluxo* é aberta, chamando **fopen** e usando um parâmetro de modo que inclui **ccs = UNICODE**, **ccs = UTF-16LE**, ou **ccs = UTF-8**, ou se o modo for alterado para um modo de conversão Unicode usando **setmode** e um modo parâmetro que inclui **_O_WTEXT**, **_O_U16TEXT**, ou **_O_U8TEXT**—*buffer* é interpretado como um ponteiro para um matriz de **wchar_t** que contém dados UTF-16. Tentar gravar uma quantidade ímpar de bytes nesse modo gera um erro de validação de parâmetro.

Como essa função bloqueia o thread da chamada, ela é thread-safe. Para obter uma versão de não bloqueio, consulte **fwrite_nolock**.

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
