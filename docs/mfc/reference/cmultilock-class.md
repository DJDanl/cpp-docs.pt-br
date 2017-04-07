---
title: Classe CMultiLock | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMultiLock
- AFXMT/CMultiLock
- AFXMT/CMultiLock::CMultiLock
- AFXMT/CMultiLock::IsLocked
- AFXMT/CMultiLock::Lock
- AFXMT/CMultiLock::Unlock
dev_langs:
- C++
helpviewer_keywords:
- CMultiLock class
- synchronization objects, access control
ms.assetid: c5b7c78b-1f81-4387-b7dd-2c813c5b6b61
caps.latest.revision: 20
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: a58d59d8e4d7a1c542dee80295dd8eef6c8be338
ms.lasthandoff: 02/25/2017

---
# <a name="cmultilock-class"></a>Classe CMultiLock
Representa o mecanismo de controle de acesso usado para controlar o acesso a recursos em um programa multi-threaded.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMultiLock  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMultiLock::CMultiLock](#cmultilock)|Constrói um objeto `CMultiLock`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMultiLock::IsLocked](#islocked)|Determina se um objeto de sincronização específico na matriz está bloqueado.|  
|[CMultiLock::Lock](#lock)|Aguarda a matriz de objetos de sincronização.|  
|[CMultiLock::Unlock](#unlock)|Libera todos os objetos possuídos de sincronização.|  
  
## <a name="remarks"></a>Comentários  
 `CMultiLock`não tem uma classe base.  
  
 Para usar as classes de sincronização [CSemaphore](../../mfc/reference/csemaphore-class.md), [CMutex](../../mfc/reference/cmutex-class.md), e [CEvent](../../mfc/reference/cevent-class.md), você pode criar um **CMultiLock** ou [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto aguardar e liberar o objeto de sincronização. Use **CMultiLock** quando há vários objetos que você pode usar em um momento específico. Use `CSingleLock` quando você só precisa esperar em um objeto por vez.  
  
 Para usar um **CMultiLock** de objeto, primeiro crie uma matriz de objetos de sincronização que deseja esperar. Em seguida, chame o **CMultiLock** construtor do objeto dentro de uma função de membro na classe do recurso controlado. Em seguida, chame o [bloqueio](#lock) função de membro para determinar se um recurso está disponível (sinalizado). Caso haja, continue com o restante da função de membro. Se o recurso não estiver disponível, aguarde um determinado período de tempo para um recurso para ser liberado ou retornar falha. Após a conclusão do uso de um recurso, chamar o [Unlock](#unlock) funcionará se o **CMultiLock** objeto deve ser usado novamente ou permitir que o **CMultiLock** o objeto a ser destruído.  
  
 **CMultiLock** objetos são mais úteis quando um thread tem um grande número de `CEvent` objetos que ele pode responder. Criar uma matriz que contém todos os `CEvent` ponteiros e chamada `Lock`. Isso fará com que o thread a esperar até que um dos eventos é sinalizado.  
  
 Para obter mais informações sobre como usar **CMultiLock** objetos, consulte o artigo [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CMultiLock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmt.h  
  
##  <a name="cmultilock"></a>CMultiLock::CMultiLock  
 Constrói uma **CMultiLock** objeto.  
  
```  
CMultiLock(
    CSyncObject* ppObjects [ ],  
    DWORD dwCount,  
    BOOL bInitialLock = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppObjects`  
 Matriz de ponteiros para os objetos de sincronização a ser aguardado. Não pode ser **nulo**.  
  
 `dwCount`  
 Número de objetos em `ppObjects`. Deve ser maior que 0.  
  
 `bInitialLock`  
 Especifica se a inicialmente tentar acessar qualquer um dos objetos fornecidos.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada depois de criar a matriz de objetos de sincronização a ser aguardado. Ele geralmente é chamado do thread deve aguardar até que um dos objetos de sincronização se torne disponível.  
  
##  <a name="islocked"></a>CMultiLock::IsLocked  
 Determina se o objeto especificado for sinalizado (não disponível).  
  
```  
BOOL IsLocked(DWORD dwItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwItem*  
 O índice na matriz de objetos correspondente ao objeto cujo estado está sendo consultado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto especificado está bloqueado; Caso contrário, 0.  
  
##  <a name="lock"></a>CMultiLock::Lock  
 Chame essa função para obter acesso a um ou mais dos recursos controlados pelos objetos de sincronização fornecidos para o **CMultiLock** construtor.  
  
```  
DWORD Lock(
    DWORD dwTimeOut = INFINITE,  
    BOOL bWaitForAll = TRUE,  
    DWORD dwWakeMask = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwTimeOut*  
 Especifica a quantidade de tempo de espera para o objeto de sincronização esteja disponível (sinalizado). Se **infinito**, `Lock` aguardará até que o objeto é sinalizado antes de retornar.  
  
 `bWaitForAll`  
 Especifica se todos os objetos aguardados devem ficar sinalizados ao mesmo tempo antes de retornar. Se **FALSE**, `Lock` retornará quando qualquer um dos objetos aguardado é sinalizado.  
  
 `dwWakeMask`  
 Especifica a outras condições que podem interromper a espera. Para obter uma lista completa das opções disponíveis para esse parâmetro, consulte [MsgWaitForMultipleObjects](http://msdn.microsoft.com/library/windows/desktop/ms684242) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Se `Lock` falhar, ela retorna – 1. Se for bem-sucedido, ele retorna um dos seguintes valores:  
  
-   Entre **WAIT_OBJECT_0** e **WAIT_OBJECT_0** + (número de objetos – 1)  
  
     Se `bWaitForAll` é **TRUE**, todos os objetos são sinalizados (disponível). Se `bWaitForAll` é **FALSE**, o valor de retorno **WAIT_OBJECT_0** é o índice da matriz de objetos do objeto que é sinalizado (disponível).  
  
- **WAIT_OBJECT_0** + (número de objetos)  
  
     Um evento especificado em `dwWakeMask` está disponível na fila de entrada do thread.  
  
-   Entre **WAIT_ABANDONED_0** e **WAIT_ABANDONED_0** + (número de objetos – 1)  
  
     Se `bWaitForAll` é **TRUE**, todos os objetos são sinalizados e pelo menos um dos objetos é um objeto mutex abandonado. Se `bWaitForAll` é **FALSE**, o valor de retorno **WAIT_ABANDONED_0** é o índice na matriz de objetos do objeto mutex abandonado que atendeu à espera.  
  
- **WAIT_TIMEOUT**  
  
     O intervalo de tempo limite especificado em *dwTimeOut* expirado sem sucesso de espera.  
  
### <a name="remarks"></a>Comentários  
 Se `bWaitForAll` é **TRUE**, `Lock` retornará com êxito, assim como todos os objetos de sincronização tornou-se sinalizado simultaneamente. Se `bWaitForAll` é **FALSE**, `Lock` retornará, assim como um ou mais dos objetos de sincronização se torna sinalizado.  
  
 Se `Lock` não é capaz de retornar imediatamente, ele aguardará para não mais do que o número de milissegundos especificado no *dwTimeOut* parâmetro antes de retornar. Se *dwTimeOut* é **infinito**, `Lock` não retornará até que o acesso a um objeto é obtido ou uma condição especificada no `dwWakeMask` foi atendida. Caso contrário, se `Lock` foi capaz de adquirir um objeto de sincronização, ele retornará com êxito; se não, ela retornará falha.  
  
##  <a name="unlock"></a>CMultiLock::Unlock  
 Libera o objeto de sincronização de propriedade `CMultiLock`.  
  
```  
BOOL Unlock();

 
BOOL Unlock(
    LONG lCount,  
    LPLONG lPrevCount = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lCount`  
 Número de referência de conta para lançamento. Deve ser maior que 0. Se a quantidade especificada faria com que a contagem do objeto exceder seu máximo, a contagem não é alterada e a função retorna **FALSE**.  
  
 `lPrevCount`  
 Aponta para uma variável para receber a contagem anterior para o objeto de sincronização. Se **nulo**, a conta anterior não é retornada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada pelo `CMultiLock`do destruidor.  
  
 O primeiro formulário de `Unlock` tenta desbloquear o objeto de sincronização gerenciado pelo `CMultiLock`. A segunda forma de `Unlock` tenta desbloquear o `CSemaphore` objetos possuídos por `CMultiLock`. Se `CMultiLock` não possui qualquer bloqueado `CSemaphore` do objeto, a função retorna **FALSE**; caso contrário, ele retorna **TRUE**. `lCount`e `lpPrevCount` são exatamente os mesmos que os parâmetros de [CSingleLock::Unlock](../../mfc/reference/csinglelock-class.md#unlock). A segunda forma de `Unlock` é raramente aplicável a situações multilock.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




