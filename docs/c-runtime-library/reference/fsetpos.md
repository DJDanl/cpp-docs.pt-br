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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 8fa6ec1f37703ce51e0c9c565d766c56cf164322
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82910174"
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

*pos*<br/>
Armazenamento do indicador de posição.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, **fsetpos** retornará 0. Em caso de falha, a função retorna um valor diferente de zero e define **errno** como uma das constantes de manifesto a seguir (definidas em errno. H): **EBADF**, que significa que o arquivo não está acessível ou o objeto ao qual o *fluxo* aponta não é uma estrutura de arquivo válida; ou **EINVAL**, o que significa que um valor inválido para *Stream* ou *pos* foi passado. Se um parâmetro inválido for passado, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

A função **fsetpos** define o indicador de posição de arquivo para *fluxo* para o valor de *pos*, que é obtido em uma chamada anterior para **fgetpos** em relação ao *fluxo*. A função limpa o indicador de fim de arquivo e desfaz os efeitos de [ungetc](ungetc-ungetwc.md) no *fluxo*. Depois de chamar **fsetpos**, a próxima operação no *fluxo* pode ser entrada ou saída.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fsetpos**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [fgetpos](fgetpos.md).

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fgetpos](fgetpos.md)<br/>
