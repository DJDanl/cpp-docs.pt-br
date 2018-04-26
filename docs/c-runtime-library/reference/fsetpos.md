---
title: fsetpos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- streams, setting position indicators
- fsetpos function
ms.assetid: 6d19ff48-1a2b-47b3-9f23-ed0a47b5a46e
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0ceacacbe029488995c47e305682b56751347591
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

*POS*<br/>
Armazenamento do indicador de posição.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **fsetpos** retorna 0. Em caso de falha, a função retorna um valor diferente de zero e define **errno** para uma das seguintes constantes (definidas na ERRNO de manifesto. H): **EBADF**, que significa que o arquivo não está acessível ou o objeto que *fluxo* pontos não é uma estrutura de arquivo válido; ou **EINVAL**, que significa que um valor inválido para *fluxo* ou *pos* foi passado. Se um parâmetro inválido for passado, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

O **fsetpos** função define o indicador de posição do arquivo de *fluxo* para o valor de *pos*, que é obtido em uma chamada anterior para **fgetpos**contra *fluxo*. A função limpa o indicador de fim de arquivo e desfazer os efeitos da [ungetc](ungetc-ungetwc.md) na *fluxo*. Depois de chamar **fsetpos**, a próxima operação na *fluxo* pode ser de entrada ou saída.

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
