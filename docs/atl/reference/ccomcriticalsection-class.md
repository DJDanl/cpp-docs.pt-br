---
title: Classe CComCriticalSection | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CComCriticalSection
- CComCriticalSection
- ATL::CComCriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CComCriticalSection class
ms.assetid: 44e1edd2-90be-4bfe-9739-58e8b419e7d1
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
ms.sourcegitcommit: 050e7483670bd32f633660ba44491c8bb3fc462d
ms.openlocfilehash: a7c4fbc87ff06bb09766eb3e4ad0d7c5275eed65
ms.lasthandoff: 02/25/2017

---
# <a name="ccomcriticalsection-class"></a>Classe CComCriticalSection
Essa classe fornece métodos para a obtenção e liberar a propriedade de um objeto da seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComCriticalSection
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCriticalSection::CComCriticalSection](#ccomcriticalsection)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCriticalSection::Init](#init)|Cria e inicializa um objeto da seção crítica.|  
|[CComCriticalSection::Lock](#lock)|Obtém a propriedade do objeto da seção crítica.|  
|[CComCriticalSection::Term](#term)|Libera recursos do sistema usados pelo objeto de seção crítica.|  
|[CComCriticalSection::Unlock](#unlock)|Libera a propriedade do objeto de seção crítica.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCriticalSection::m_sec](#m_sec)|A **CRITICAL_SECTION** objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CComCriticalSection`é semelhante à classe [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md), exceto que você deve inicializar explicitamente e liberará a seção crítica.  
  
 Normalmente, você usa `CComCriticalSection` por meio de `typedef` nome [CriticalSection](ccommultithreadmodel-class.md#criticalsection). Esse nome faz referência `CComCriticalSection` quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.  

  
 Consulte [CComCritSecLock classe](../../atl/reference/ccomcritseclock-class.md) de uma maneira mais segura usar essa classe de chamada `Lock` e `Unlock` diretamente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="a-nameccomcriticalsectiona--ccomcriticalsectionccomcriticalsection"></a><a name="ccomcriticalsection"></a>CComCriticalSection::CComCriticalSection  
 O construtor.  
  
```
CComCriticalSection() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Conjuntos de [m_sec](#m_sec) membro de dados como NULL **.**  
  
##  <a name="a-nameinita--ccomcriticalsectioninit"></a><a name="init"></a>CComCriticalSection::Init  
 Chama a função Win32 [InitializeCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms683472), que inicializa o objeto da seção crítica contido a [m_sec](#m_sec) membro de dados.  
  
```
HRESULT Init() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` com êxito, **E_OUTOFMEMORY** ou **E_FAIL** em caso de falha.  
  
##  <a name="a-namelocka--ccomcriticalsectionlock"></a><a name="lock"></a>CComCriticalSection::Lock  
 Chama a função Win32 [EnterCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms682608), que aguarda até que o thread pode assumir a propriedade do objeto de seção crítica contida a [m_sec](#m_sec) membro de dados.  
  
```
HRESULT Lock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` com êxito, **E_OUTOFMEMORY** ou **E_FAIL** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O objeto da seção crítica primeiro deve ser inicializado com uma chamada para o [Init](#init) método. Quando o código protegido terminou de executar, o thread deve chamar [Unlock](#unlock) Libere a propriedade da seção crítica.  
  
##  <a name="a-namemseca--ccomcriticalsectionmsec"></a><a name="m_sec"></a>CComCriticalSection::m_sec  
 Contém um objeto de seção crítica que é usado por todos os `CComCriticalSection` métodos.  
  
```
CRITICAL_SECTION m_sec;
```  
  
##  <a name="a-nameterma--ccomcriticalsectionterm"></a><a name="term"></a>CComCriticalSection::Term  
 Chama a função Win32 [DeleteCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms682552), que libera todos os recursos usados pelo objeto de seção crítica contido a [m_sec](#m_sec) membro de dados.  
  
```
HRESULT Term() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Uma vez `Term` foi chamado, o importante seção não pode ser usada para sincronização.  
  
##  <a name="a-nameunlocka--ccomcriticalsectionunlock"></a><a name="unlock"></a>CComCriticalSection::Unlock  
 Chama a função Win32 [LeaveCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms684169), que libera a propriedade do objeto de seção crítica contida a [m_sec](#m_sec) membro de dados.  
  
```
HRESULT Unlock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Para obter a propriedade pela primeira vez, o thread deve chamar o [bloqueio](#lock) método. Cada chamada para `Lock` requer uma chamada correspondente para `Unlock` Libere a propriedade da seção crítica.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CComCritSecLock](../../atl/reference/ccomcritseclock-class.md)

