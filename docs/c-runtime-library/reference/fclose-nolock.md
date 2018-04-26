---
title: _fclose_nolock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _fclose_nolock
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
- fclose_nolock
- _fclose_nolock
dev_langs:
- C++
helpviewer_keywords:
- streams, closing
- fclose_nolock function
- _fclose_nolock function
ms.assetid: b4af4392-5fc8-49bb-9fe2-ca7293d3ce04
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 42a01b7174fd644af0fbb60f09795f7e93f9d46b
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="fclosenolock"></a>_fclose_nolock

Fecha um fluxo sem bloquear o thread.

## <a name="syntax"></a>Sintaxe

```C
int _fclose_nolock(
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*Fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

**fclose** retorna 0 se o fluxo está fechado com êxito. Retorna **EOF** para indicar um erro.

## <a name="remarks"></a>Comentários

Essas funções é uma versão de não bloqueio de **fclose**. Ela é idêntica, exceto pelo fato de não ser protegida contra interferência de outros threads. Ela pode ser mais rápida, porque não incorre na sobrecarga de bloquear outros threads. Use esta função apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_fclose_nolock**|\<stdio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[_close](close.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[fflush](fflush.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[freopen, _wfreopen](freopen-wfreopen.md)<br/>
