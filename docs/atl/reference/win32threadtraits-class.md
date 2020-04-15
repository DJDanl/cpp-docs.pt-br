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
ms.openlocfilehash: 64f02293508894a70f36c29d5032c9ba8f250c38
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325793"
---
# <a name="win32threadtraits-class"></a>Classe Win32ThreadTraits

Esta classe fornece a função de criação de um segmento do Windows. Use esta classe se o segmento não usar funções CRT.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class Win32ThreadTraits
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Win32ThreadTraits::CreateThread](#createthread)|(Estática) Chame esta função para criar um segmento que não deve usar funções CRT.|

## <a name="remarks"></a>Comentários

Os traços do segmento são classes que fornecem uma função de criação para um determinado tipo de segmento. A função de criação tem a mesma assinatura e semântica que a função Windows [CreateThread.](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread)

Os traços de rosca são usados pelas seguintes classes:

- [Cthreadpool](../../atl/reference/cthreadpool-class.md)

- [Cworkerthread](../../atl/reference/cworkerthread-class.md)

Se o segmento estiver usando funções CRT, use [CRTThreadTraits](../../atl/reference/crtthreadtraits-class.md) em vez disso.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="win32threadtraitscreatethread"></a><a name="createthread"></a>Win32ThreadTraits::CreateThread

Chame esta função para criar um segmento que não deve usar funções CRT.

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

*LPSA*<br/>
Os atributos de segurança para o novo segmento.

*dwStackSize*<br/>
O tamanho da pilha para o novo fio.

*pfnThreadProc*<br/>
O procedimento de rosca do novo fio.

*Pvparam*<br/>
O parâmetro a ser passado para o procedimento de rosca.

*Dwcreationflags*<br/>
Bandeiras de criação (0 ou CREATE_SUSPENDED).

*pdwThreadId*<br/>
[fora] Endereço da variável DWORD que, com sucesso, recebe o ID de thread do segmento recém-criado.

### <a name="return-value"></a>Valor retornado

Retorna a alça para o segmento recém-criado ou NULL na falha. Ligue para [getLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) para obter informações de erro estendidas.

### <a name="remarks"></a>Comentários

Consulte [CreateThread](/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) para obter mais informações sobre os parâmetros desta função.

Esta função `CreateThread` chama para criar o segmento.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
