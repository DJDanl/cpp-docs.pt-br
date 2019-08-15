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
ms.openlocfilehash: 9e12e64041e38b8fa014815870132a75885014bf
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496561"
---
# <a name="crtthreadtraits-class"></a>Classe CRTThreadTraits

Essa classe fornece a função de criação para um thread CRT. Use essa classe se o thread usar funções CRT.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CRTThreadTraits
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRTThreadTraits::CreateThread](#createthread)|Auto-estática Chame essa função para criar um thread que possa usar funções CRT.|

## <a name="remarks"></a>Comentários

As características de thread são classes que fornecem uma função de criação para um determinado tipo de thread. A função de criação tem a mesma assinatura e semântica que a função [CreateThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) do Windows.

As características de thread são usadas pelas seguintes classes:

- [CThreadPool](../../atl/reference/cthreadpool-class.md)

- [CWorkerThread](../../atl/reference/cworkerthread-class.md)

Se o thread não estiver usando funções CRT, use [Win32ThreadTraits](../../atl/reference/win32threadtraits-class.md) em vez disso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="createthread"></a>  CRTThreadTraits::CreateThread

Chame essa função para criar um thread que possa usar funções CRT.

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
O parâmetro a ser passado para o procedimento de thread.

*dwCreationFlags*<br/>
Os sinalizadores de criação (0 ou CREATE_SUSPENDED).

*pdwThreadId*<br/>
fora Endereço da variável DWORD que, em êxito, recebe a ID de thread do thread recém-criado.

### <a name="return-value"></a>Valor de retorno

Retorna o identificador para o thread recém-criado ou nulo em caso de falha. Chame [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) para obter informações de erro estendidas.

### <a name="remarks"></a>Comentários

Consulte [CreateThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) para obter mais informações sobre os parâmetros para essa função.

Essa função chama [_beginthreadex](../../c-runtime-library/reference/beginthread-beginthreadex.md) para criar o thread.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
