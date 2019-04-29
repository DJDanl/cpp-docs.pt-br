---
title: Classe Win32ThreadTraits
ms.date: 11/04/2016
f1_keywords:
- Win32ThreadTraits
- ATLBASE/ATL::Win32ThreadTraits
- ATLBASE/ATL::Win32ThreadTraits::CreateThread
helpviewer_keywords:
- threading [ATL], Windows threads
- threading [ATL], creation functions
- Win32ThreadTraits class
ms.assetid: 50279c38-eae1-4301-9ea6-97ccea580f3e
ms.openlocfilehash: da4b8b3d5a41ab16dc2027fd632c56158afd3b97
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62275932"
---
# <a name="win32threadtraits-class"></a>Classe Win32ThreadTraits

Essa classe fornece a função de criação de um thread do Windows. Use essa classe se o thread não usará as funções de CRT.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class Win32ThreadTraits
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[Win32ThreadTraits::CreateThread](#createthread)|(Estático) Chame essa função para criar um thread que não deve usar funções de CRT.|

## <a name="remarks"></a>Comentários

Características de thread são classes que fornecem uma função de criação de um tipo específico de thread. A função de criação tem a mesma assinatura e a semântica de como o Windows [CreateThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) função.

Características de thread são usadas pelas classes:

- [CThreadPool](../../atl/reference/cthreadpool-class.md)

- [CWorkerThread](../../atl/reference/cworkerthread-class.md)

Se o thread estiver usando funções de CRT, use [CRTThreadTraits](../../atl/reference/crtthreadtraits-class.md) em vez disso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="createthread"></a>  Win32ThreadTraits::CreateThread

Chame essa função para criar um thread que não deve usar funções de CRT.

```
static HANDLE CreateThread(
    LPSECURITY_ATTRIBUTES lpsa,
    DWORD dwStackSize,
    LPTHREAD_START_ROUTINE pfnThreadProc,
    void* pvParam,
    DWORD dwCreationFlags,
    DWORD* pdwThreadId) throw();
```

### <a name="parameters"></a>Parâmetros

*lpsa*<br/>
Os atributos de segurança para o novo thread.

*dwStackSize*<br/>
O tamanho da pilha para o novo thread.

*pfnThreadProc*<br/>
O procedimento de thread do novo thread.

*pvParam*<br/>
O parâmetro a serem passados ao procedimento de thread.

*dwCreationFlags*<br/>
A criação de sinalizadores (0 ou CREATE_SUSPENDED).

*pdwThreadId*<br/>
[out] Endereço da variável DWORD que, em caso de sucesso, recebe a ID do thread do thread recém-criado.

### <a name="return-value"></a>Valor de retorno

Retorna o identificador para o thread recém-criado ou nulo, em caso de falha. Chame [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) para obter mais informações sobre o erro.

### <a name="remarks"></a>Comentários

Ver [CreateThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) para obter mais informações sobre os parâmetros para essa função.

Essa função chama `CreateThread` para criar o thread.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
