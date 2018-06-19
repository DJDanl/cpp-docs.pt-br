---
title: Classe CComCriticalSection | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComCriticalSection
- ATLCORE/ATL::CComCriticalSection
- ATLCORE/ATL::CComCriticalSection::CComCriticalSection
- ATLCORE/ATL::CComCriticalSection::Init
- ATLCORE/ATL::CComCriticalSection::Lock
- ATLCORE/ATL::CComCriticalSection::Term
- ATLCORE/ATL::CComCriticalSection::Unlock
- ATLCORE/ATL::CComCriticalSection::m_sec
dev_langs:
- C++
helpviewer_keywords:
- CComCriticalSection class
ms.assetid: 44e1edd2-90be-4bfe-9739-58e8b419e7d1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 25376aba3cfbade202d1cf95c2218e88713ac22a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32359899"
---
# <a name="ccomcriticalsection-class"></a>Classe CComCriticalSection
Essa classe fornece métodos para a obtenção e liberar a propriedade de um objeto de seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComCriticalSection
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCriticalSection::CComCriticalSection](#ccomcriticalsection)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCriticalSection::Init](#init)|Cria e inicializa um objeto de seção crítica.|  
|[CComCriticalSection::Lock](#lock)|Obtém a propriedade do objeto de seção crítica.|  
|[CComCriticalSection::Term](#term)|Libera os recursos do sistema usados pelo objeto de seção crítica.|  
|[CComCriticalSection::Unlock](#unlock)|Libera a propriedade do objeto de seção crítica.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCriticalSection::m_sec](#m_sec)|Um **CRITICAL_SECTION** objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CComCriticalSection` é semelhante à classe [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md), exceto que você deve inicializar explicitamente e liberará a seção crítica.  
  
 Normalmente, você usa `CComCriticalSection` por meio de `typedef` nome [CriticalSection](ccommultithreadmodel-class.md#criticalsection). Faz referência a esse nome `CComCriticalSection` quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.  

  
 Consulte [CComCritSecLock classe](../../atl/reference/ccomcritseclock-class.md) de uma maneira mais segura usar essa classe que chamar `Lock` e `Unlock` diretamente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="ccomcriticalsection"></a>  CComCriticalSection::CComCriticalSection  
 O construtor.  
  
```
CComCriticalSection() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Conjuntos de [m_sec](#m_sec) membro de dados como NULL **.**  
  
##  <a name="init"></a>  CComCriticalSection::Init  
 Chama a função Win32 [InitializeCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms683472), que inicializa o objeto de seção crítica dentro de [m_sec](#m_sec) membro de dados.  
  
```
HRESULT Init() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` em caso de sucesso, **E_OUTOFMEMORY** ou **E_FAIL** em caso de falha.  
  
##  <a name="lock"></a>  CComCriticalSection::Lock  
 Chama a função Win32 [EnterCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms682608), que aguarda até que o thread pode assumir a propriedade do objeto de seção crítica contido no [m_sec](#m_sec) membro de dados.  
  
```
HRESULT Lock() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` em caso de sucesso, **E_OUTOFMEMORY** ou **E_FAIL** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O objeto de seção crítica primeiro deve ser inicializado com uma chamada para o [Init](#init) método. Quando o código protegido concluiu a execução, o thread deve chamar [Unlock](#unlock) Libere a propriedade da seção crítica.  
  
##  <a name="m_sec"></a>  CComCriticalSection::m_sec  
 Contém um objeto de seção crítica que é usado por todos os `CComCriticalSection` métodos.  
  
```
CRITICAL_SECTION m_sec;
```  
  
##  <a name="term"></a>  CComCriticalSection::Term  
 Chama a função Win32 [DeleteCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms682552), que libera todos os recursos usados pelo objeto de seção crítica dentro de [m_sec](#m_sec) membro de dados.  
  
```
HRESULT Term() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Uma vez `Term` foi chamado, críticos seção não pode ser usada para sincronização.  
  
##  <a name="unlock"></a>  CComCriticalSection::Unlock  
 Chama a função Win32 [LeaveCriticalSection](http://msdn.microsoft.com/library/windows/desktop/ms684169), que libera a propriedade do objeto de seção crítica dentro de [m_sec](#m_sec) membro de dados.  
  
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
