---
title: fsetpos
ms.date: 11/04/2016
apiname:
- fsetpos
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
- fsetpos
helpviewer_keywords:
- streams, setting position indicators
- fsetpos function
ms.assetid: 6d19ff48-1a2b-47b3-9f23-ed0a47b5a46e
ms.openlocfilehash: 9854c71e381da6ec9a75d440b9588e2476bada7c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50528226"
---
# <a name="fsetpos"></a>fsetpos

Define o indicador de posição do fluxo.

## <a name="syntax"></a>Sintaxe

```C
int fsetpos(
   FILE *stream,
   const fpos_t *pos
);
```

### <a name="parameters"></a>Parâmetros

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*POS*<br/>
Armazenamento do indicador de posição.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **fsetpos** retornará 0. Em caso de falha, a função retorna um valor diferente de zero e define **errno** para uma das seguintes constantes (definidas em ERRNO de manifesto. H): **EBADF**, que significa que o arquivo não está acessível ou o objeto que *fluxo* aponta não é uma estrutura de arquivo válido; ou **EINVAL**, que significa que um valor inválido para *stream* ou *pos* foi passado. Se um parâmetro inválido for passado, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

O **fsetpos** função define o indicador de posição do arquivo para *fluxo* para o valor de *pos*, que é obtido em uma chamada anterior ao **fgetpos**contra *fluxo*. A função limpa o indicador de final de arquivo e desfaz os efeitos de [ungetc](ungetc-ungetwc.md) nos *fluxo*. Depois de chamar **fsetpos**, a próxima operação na *fluxo* pode ser de entrada ou saída.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fsetpos**|\<stdio.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [fgetpos](fgetpos.md).

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fgetpos](fgetpos.md)<br/>
