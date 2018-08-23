---
title: _endthread, _endthreadex | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 898281e0652345f22c63076cf4b0a73294faaf04
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42572806"
---
# <a name="endthread-endthreadex"></a>_endthread, _endthreadex

Termina um thread; **endthread** termina um thread criado pela **beginthread** e **endthreadex** termina um thread criado pelo **beginthreadex**.

## <a name="syntax"></a>Sintaxe

```C
void _endthread( void );
void _endthreadex(
   unsigned retval
);
```

### <a name="parameters"></a>Parâmetros

*retval* código de saída de Thread.

## <a name="remarks"></a>Comentários

Você pode chamar **endthread** ou **endthreadex** explicitamente para terminar um thread; no entanto, **endthread** ou **endthreadex** é chamado automaticamente quando o thread volta da rotina passado como um parâmetro para **beginthread** ou **beginthreadex**. Encerrar um thread com uma chamada para **endthread** ou **endthreadex** ajuda a garantir que a recuperação apropriada dos recursos alocados para o thread.

> [!NOTE]
> No caso de arquivos executáveis vinculados a Libcmt.lib, não chame a API [ExitThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) do Win32. Isso impede que o sistema do tempo de execução recupere os recursos alocados. **endthread** e **endthreadex** recuperar os recursos alocados ao thread e, em seguida, chame **ExitThread**.

**endthread** fecha automaticamente o identificador de thread. (Esse comportamento difere do Win32 **ExitThread** API.) Portanto, quando você usa **beginthread** e **endthread**, não feche explicitamente o identificador de thread chamando Win32 [CloseHandle](http://msdn.microsoft.com/library/windows/desktop/ms724211.aspx) API.

Como o Win32 **ExitThread** API, **endthreadex** não fecha o identificador de thread. Portanto, quando você usa **beginthreadex** e **endthreadex**, você deve fechar o identificador de thread chamando Win32 **CloseHandle** API.

> [!NOTE]
> **endthread** e **endthreadex** fazer com que os destruidores C++ pendentes no thread não deve ser chamada.

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
