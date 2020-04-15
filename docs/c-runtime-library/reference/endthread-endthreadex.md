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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: c76f479255080400e07678ef5dbde572b7a9dffc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81348031"
---
# <a name="_endthread-_endthreadex"></a>_endthread, _endthreadex

Termina um segmento; **_endthread** termina um segmento criado por **_beginthread** e **_endthreadex** termina um segmento criado por **_beginthreadex**.

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

Você pode ligar **para _endthread** ou **_endthreadex** explicitamente para terminar um segmento; no entanto, **_endthread** ou **_endthreadex** é chamado automaticamente quando o segmento retorna da rotina passado como parâmetro para **_beginthread** ou **_beginthreadex**. Terminar um segmento com uma chamada para **endthread** ou **_endthreadex** ajuda a garantir a recuperação adequada dos recursos alocados para o segmento.

> [!NOTE]
> No caso de arquivos executáveis vinculados a Libcmt.lib, não chame a API [ExitThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread) do Win32. Isso impede que o sistema do tempo de execução recupere os recursos alocados. **_endthread** e **_endthreadex** recuperar recursos de thread alocados e, em seguida, chamar **ExitThread**.

**_endthread** fecha automaticamente a pega de rosca. (Esse comportamento difere da API Do Win32 **ExitThread.)** Portanto, quando você usar **_beginthread** e **_endthread,** não feche explicitamente a alça de rosca chamando a API Win32 [CloseHandle.](/windows/win32/api/handleapi/nf-handleapi-closehandle)

Assim como a API Win32 **ExitThread,** **_endthreadex** não fecha a alça de rosca. Portanto, quando você usa **_beginthreadex** e **_endthreadex,** você deve fechar a alça de rosca chamando a API Win32 **CloseHandle.**

> [!NOTE]
> **_endthread** e **_endthreadex** fazem com que os destrutores C++ pendentes no segmento não sejam chamados.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[_beginthread, _beginthreadex](beginthread-beginthreadex.md)<br/>
