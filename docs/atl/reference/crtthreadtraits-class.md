---
title: Classe de CRTThreadTraits | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CRTThreadTraits
- ATL.CRTThreadTraits
- CRTThreadTraits
dev_langs:
- C++
helpviewer_keywords:
- CRTThreadTraits class
- threading [ATL], creation functions
- threading [ATL], CRT threads
ms.assetid: eb6e20b0-c2aa-4170-8e34-aaeeacc86343
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 24cee5c74819d9a880bedbcebcce4dabfabae960
ms.lasthandoff: 02/25/2017

---
# <a name="crtthreadtraits-class"></a>Classe de CRTThreadTraits
Essa classe fornece a função de criação de um thread de CRT. Use esta classe se o thread possa utilizar as funções de CRT.  
  
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
 Características de thread são classes que fornecem uma função de criação de um tipo específico de thread. A função de criação tem a mesma assinatura e semântica de como o Windows [CreateThread](http://msdn.microsoft.com/library/windows/desktop/ms682453) função.  
  
 Características de thread são usadas por classes a seguir:  
  
- [CThreadPool](../../atl/reference/cthreadpool-class.md)  
  
- [CWorkerThread](../../atl/reference/cworkerthread-class.md)  
  
 Se o thread não usar funções de CRT, [Win32ThreadTraits](../../atl/reference/win32threadtraits-class.md) em vez disso.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase. h  
  
##  <a name="a-namecreatethreada--crtthreadtraitscreatethread"></a><a name="createthread"></a>CRTThreadTraits::CreateThread  
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
  
 Essa função chama [beginthreadex](../../c-runtime-library/reference/beginthread-beginthreadex.md) criar o thread.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

