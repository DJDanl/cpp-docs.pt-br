---
title: _endthread, _endthreadex
ms.date: 4/2/2020
api_name:
- _endthread
- _endthreadex
- _o__endthread
- _o__endthreadex
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
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _endthread
- endthreadex
- _endthreadex
- endthread
helpviewer_keywords:
- _endthread function
- endthread function
- terminating threads
- endthreadex function
- _endthreadex function
- threading [C++], terminating threads
ms.assetid: 18a91f2f-659e-40b4-b266-ec12dcf2abf5
ms.openlocfilehash: a3889adcc90bd62e766102b72aae68577915e55b
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82915080"
---
# <a name="_endthread-_endthreadex"></a>_endthread, _endthreadex

Finaliza um thread; **_endthread** encerra um thread que é criado por **_beginthread** e **_endthreadex** encerra um thread que é criado pelo **_beginthreadex**.

## <a name="syntax"></a>Sintaxe

```C
void _endthread( void );
void _endthreadex(
   unsigned retval
);
```

### <a name="parameters"></a>Parâmetros

*retval*<br/>
Código de saída do thread.

## <a name="remarks"></a>Comentários

Você pode chamar **_endthread** ou **_endthreadex** explicitamente para encerrar um thread; no entanto, **_endthread** ou **_endthreadex** é chamado automaticamente quando o thread retorna da rotina passada como um parâmetro para **_beginthread** ou **_beginthreadex**. Encerrar um thread com uma chamada para **endthread** ou **_endthreadex** ajuda a garantir uma recuperação adequada dos recursos alocados para o thread.

> [!NOTE]
> No caso de arquivos executáveis vinculados a Libcmt.lib, não chame a API [ExitThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread) do Win32. Isso impede que o sistema do tempo de execução recupere os recursos alocados. **_endthread** e **_endthreadex** recuperar recursos de thread alocados e, em seguida, chamar **ExitThread**.

**_endthread** fecha automaticamente o identificador de thread. (Esse comportamento difere da API **ExitThread** do Win32.) Portanto, quando você usa **_beginthread** e **_endthread**, não feche explicitamente o identificador de thread chamando a API [CloseHandle](/windows/win32/api/handleapi/nf-handleapi-closehandle) do Win32.

Assim como a API **ExitThread** do Win32, **_endthreadex** não fecha o identificador de thread. Portanto, ao usar **_beginthreadex** e **_endthreadex**, você deve fechar o identificador de thread chamando a API **CloseHandle** do Win32.

> [!NOTE]
> **_endthread** e **_endthreadex** fazem com que os destruidores de C++ pendentes no thread não sejam chamados.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_endthread**|\<process.h>|
|**_endthreadex**|\<process.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Somente versões multi-threaded da [biblioteca em tempo de execução do C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Veja o exemplo de [_beginthread](beginthread-beginthreadex.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[_beginthread, _beginthreadex](beginthread-beginthreadex.md)<br/>
