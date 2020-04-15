---
title: fsetpos
ms.date: 4/2/2020
api_name:
- fsetpos
- _o_fsetpos
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
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- fsetpos
helpviewer_keywords:
- streams, setting position indicators
- fsetpos function
ms.assetid: 6d19ff48-1a2b-47b3-9f23-ed0a47b5a46e
ms.openlocfilehash: 22b8cebd0154c0dbfc3d21843380ebc9a139059a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345726"
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

*Pos*<br/>
Armazenamento do indicador de posição.

## <a name="return-value"></a>Valor retornado

Se for bem sucedido, **fsetpos** retorna 0. Na falha, a função retorna um valor não zero e define **errno** a uma das seguintes constantes de manifesto (definidas em ERRNO. H): **EBADF**, o que significa que o arquivo não está acessível ou o objeto que o *fluxo* aponta não é uma estrutura de arquivo válida; ou **EINVAL,** o que significa que um valor inválido para *fluxo* ou *pos* foi passado. Se um parâmetro inválido for passado, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Veja [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses, e outros, códigos de devolução.

## <a name="remarks"></a>Comentários

A função **fsetpos** define o indicador de posição de arquivo para *fluxo* para o valor de *pos*, que é obtido em uma chamada anterior para **fgetpos** contra *fluxo*. A função limpa o indicador de fim de arquivo e desfaz quaisquer efeitos de [ungetc](ungetc-ungetwc.md) no *fluxo*. Depois de chamar **fsetpos,** a próxima operação no *fluxo* pode ser entrada ou saída.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fsetpos**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [fgetpos](fgetpos.md).

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fgetpos](fgetpos.md)<br/>
