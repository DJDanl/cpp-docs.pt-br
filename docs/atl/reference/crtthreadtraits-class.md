---
title: Classe CRTThreadTraits
ms.date: 11/04/2016
f1_keywords:
- CRTThreadTraits
- ATLBASE/ATL::CRTThreadTraits
- ATLBASE/ATL::CRTThreadTraits::CreateThread
helpviewer_keywords:
- CRTThreadTraits class
- threading [ATL], creation functions
- threading [ATL], CRT threads
ms.assetid: eb6e20b0-c2aa-4170-8e34-aaeeacc86343
ms.openlocfilehash: e5e13bad907e76968c4d4343e6617903e309e40f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57282598"
---
# <a name="crtthreadtraits-class"></a>Classe CRTThreadTraits

Essa classe fornece a função de criação de um thread de CRT. Use essa classe se o thread usará as funções de CRT.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CRTThreadTraits
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRTThreadTraits::CreateThread](#createthread)|(Estático) Chame essa função para criar um thread que pode usar funções de CRT.|

## <a name="remarks"></a>Comentários

Características de thread são classes que fornecem uma função de criação de um tipo específico de thread. A função de criação tem a mesma assinatura e a semântica de como o Windows [CreateThread](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) função.

Características de thread são usadas pelas classes:

- [CThreadPool](../../atl/reference/cthreadpool-class.md)

- [CWorkerThread](../../atl/reference/cworkerthread-class.md)

Se o thread não usando funções de CRT, use [Win32ThreadTraits](../../atl/reference/win32threadtraits-class.md) em vez disso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="createthread"></a>  CRTThreadTraits::CreateThread

Chame essa função para criar um thread que pode usar funções de CRT.

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

Essa função chama [beginthreadex](../../c-runtime-library/reference/beginthread-beginthreadex.md) para criar o thread.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
