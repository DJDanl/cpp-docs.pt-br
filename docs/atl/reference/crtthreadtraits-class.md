---
title: Classe CRTThreadTraits | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRTThreadTraits
- ATLBASE/ATL::CRTThreadTraits
- ATLBASE/ATL::CRTThreadTraits::CreateThread
dev_langs:
- C++
helpviewer_keywords:
- CRTThreadTraits class
- threading [ATL], creation functions
- threading [ATL], CRT threads
ms.assetid: eb6e20b0-c2aa-4170-8e34-aaeeacc86343
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d6fbe71ff23db8dba431b9d46d71fc6c924fbc5e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crtthreadtraits-class"></a>Classe CRTThreadTraits
Essa classe fornece a função de criação de um thread do CRT. Use essa classe se o thread de usar funções de CRT.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
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
 Características de thread são classes que fornecem uma função de criação de um tipo específico de thread. A função de criação tem a mesma assinatura e a semântica de como o Windows [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) função.  
  
 Características de segmento são usadas por classes a seguir:  
  
- [CThreadPool](../../atl/reference/cthreadpool-class.md)  
  
- [CWorkerThread](../../atl/reference/cworkerthread-class.md)  
  
 Se o thread não usando funções de CRT, use [Win32ThreadTraits](../../atl/reference/win32threadtraits-class.md) em vez disso.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  
  
##  <a name="createthread"></a>CRTThreadTraits::CreateThread  
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
  
 Esta função chama [beginthreadex](../../c-runtime-library/reference/beginthread-beginthreadex.md) para criar o thread.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
