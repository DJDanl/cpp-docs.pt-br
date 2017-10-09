---
title: Classe Win32ThreadTraits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- Win32ThreadTraits
- ATLBASE/ATL::Win32ThreadTraits
- ATLBASE/ATL::Win32ThreadTraits::CreateThread
dev_langs:
- C++
helpviewer_keywords:
- threading [ATL], Windows threads
- threading [ATL], creation functions
- Win32ThreadTraits class
ms.assetid: 50279c38-eae1-4301-9ea6-97ccea580f3e
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: c55726a1728185f699afbac4ba68a6dc0f70c2bf
ms.openlocfilehash: a777b3c1ae6056fe4ae414371cbed4eee1accd86
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="win32threadtraits-class"></a>Classe Win32ThreadTraits
Essa classe fornece a função de criação de um thread do Windows. Use essa classe se o thread não usará as funções de CRT.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
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
 Características de thread são classes que fornecem uma função de criação de um tipo específico de thread. A função de criação tem a mesma assinatura e a semântica de como o Windows [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) função.  
  
 Características de segmento são usadas por classes a seguir:  
  
- [CThreadPool](../../atl/reference/cthreadpool-class.md)  
  
- [CWorkerThread](../../atl/reference/cworkerthread-class.md)  
  
 Se o thread estiver usando funções de CRT, use [CRTThreadTraits](../../atl/reference/crtthreadtraits-class.md) em vez disso.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="createthread"></a>Win32ThreadTraits::CreateThread  
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
 `lpsa`  
 Os atributos de segurança para o novo thread.  
  
 `dwStackSize`  
 O tamanho da pilha para o novo thread.  
  
 `pfnThreadProc`  
 O procedimento de thread do novo thread.  
  
 `pvParam`  
 O parâmetro a ser passado para o procedimento de thread.  
  
 `dwCreationFlags`  
 A criação de sinalizadores (0 ou CREATE_SUSPENDED).  
  
 `pdwThreadId`  
 [out] Endereço da variável DWORD que, em caso de sucesso, recebe a ID do thread do thread recém-criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador para o thread recém-criado ou NULL em caso de falha. Chamar [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) para obter mais informações sobre o erro.  
  
### <a name="remarks"></a>Comentários  
 Consulte [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) para obter mais informações sobre os parâmetros para essa função.  
  
 Esta função chama `CreateThread` ao criar o thread.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

