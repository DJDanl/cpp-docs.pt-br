---
title: _endthread, _endthreadex | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _endthread
- _endthreadex
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _endthread
- endthreadex
- _endthreadex
- endthread
dev_langs:
- C++
helpviewer_keywords:
- _endthread function
- endthread function
- terminating threads
- endthreadex function
- _endthreadex function
- threading [C++], terminating threads
ms.assetid: 18a91f2f-659e-40b4-b266-ec12dcf2abf5
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ea85337ad22675a9cd7726fa5880d4d565ed9f14
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="endthread-endthreadex"></a>_endthread, _endthreadex

Encerra um thread; **endthread** encerra um thread que é criado por **beginthread** e **endthreadex** encerra um thread que é criado pela **beginthreadex**.

## <a name="syntax"></a>Sintaxe

```C
void _endthread( void );
void _endthreadex(
   unsigned retval
);
```

### <a name="parameters"></a>Parâmetros

*retval* código de saída do Thread.

## <a name="remarks"></a>Comentários

Você pode chamar **endthread** ou **endthreadex** explicitamente para encerrar um thread; no entanto, **endthread** ou **endthreadex** é chamado automaticamente quando o thread retorna da rotina passado como um parâmetro para **beginthread** ou **beginthreadex**. Encerrando um thread com uma chamada para **endthread** ou **endthreadex** ajuda a garantir a recuperação adequada de recursos alocados para o thread.

> [!NOTE]
> No caso de arquivos executáveis vinculados a Libcmt.lib, não chame a API [ExitThread](http://msdn.microsoft.com/library/windows/desktop/ms682659.aspx) do Win32. Isso impede que o sistema do tempo de execução recupere os recursos alocados. **endthread** e **endthreadex** recuperar os recursos de thread alocado e, em seguida, chamar **ExitThread**.

**endthread** fecha automaticamente o identificador de thread. (Esse comportamento difere do Win32 **ExitThread** API.) Portanto, quando você usa **beginthread** e **endthread**, não feche explicitamente o identificador de thread chamando o Win32 [CloseHandle](http://msdn.microsoft.com/library/windows/desktop/ms724211.aspx) API.

O Win32, como **ExitThread** API, **endthreadex** não fechar o identificador de thread. Portanto, quando você usa **beginthreadex** e **endthreadex**, você deve fechar o identificador de thread chamando o Win32 **CloseHandle** API.

> [!NOTE]
> **endthread** e **endthreadex** causar destruidores C++ pendentes no thread não deve ser chamada.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_endthread**|\<process.h>|
|**_endthreadex**|\<process.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões multi-threaded da [biblioteca em tempo de execução do C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_beginthread](beginthread-beginthreadex.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[_beginthread, _beginthreadex](beginthread-beginthreadex.md)<br/>
