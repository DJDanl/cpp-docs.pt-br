---
title: Classe CComSafeDeleteCriticalSection | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComSafeDeleteCriticalSection
- ATL::CComSafeDeleteCriticalSection
- ATL.CComSafeDeleteCriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CComSafeDeleteCriticalSection class
ms.assetid: 4d2932c4-ba8f-48ec-8664-1db8bed01314
caps.latest.revision: 18
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
ms.openlocfilehash: 511627de9d4f6411c508dd78a237cf546e2493de
ms.lasthandoff: 02/25/2017

---
# <a name="ccomsafedeletecriticalsection-class"></a>Classe CComSafeDeleteCriticalSection
Essa classe fornece métodos para a obtenção e liberar a propriedade de um objeto da seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComSafeDeleteCriticalSection : public CComCriticalSection
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComSafeDeleteCriticalSection::CComSafeDeleteCriticalSection](#ccomsafedeletecriticalsection)|O construtor.|  
|[CComSafeDeleteCriticalSection:: ~ CComSafeDeleteCriticalSection](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComSafeDeleteCriticalSection::Init](#init)|Cria e inicializa um objeto da seção crítica.|  
|[CComSafeDeleteCriticalSection::Lock](#lock)|Obtém a propriedade do objeto da seção crítica.|  
|[CComSafeDeleteCriticalSection::Term](#term)|Libera recursos do sistema usados pelo objeto de seção crítica.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_bInitialized](#m_binitialized)|Sinalizadores se interno **CRITICAL_SECTION** objeto foi inicializado.|  
  
## <a name="remarks"></a>Comentários  
 `CComSafeDeleteCriticalSection`deriva da classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md). No entanto, `CComSafeDeleteCriticalSection` fornece mecanismos de segurança adicionais sobre [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md).  
  
 Quando uma instância de `CComSafeDeleteCriticalSection` sai do escopo ou é explicitamente excluído da memória, o objeto subjacente da seção crítica será automaticamente limpo se ele ainda é válido. Além disso, o [CComSafeDeleteCriticalSection::Term](#term) método sairá normalmente se o objeto subjacente da seção crítica ainda não foi alocado ou já foi liberado da memória.  
  
 Consulte [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) para obter mais informações sobre classes auxiliares de seção crítica.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)  
  
 `CComSafeDeleteCriticalSection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcore.h  
  
##  <a name="a-nameccomsafedeletecriticalsectiona--ccomsafedeletecriticalsectionccomsafedeletecriticalsection"></a><a name="ccomsafedeletecriticalsection"></a>CComSafeDeleteCriticalSection::CComSafeDeleteCriticalSection  
 O construtor.  
  
```
CComSafeDeleteCriticalSection();
```  
  
### <a name="remarks"></a>Comentários  
 Conjuntos de [m_bInitialized](#m_binitialized) membro de dados para **false**.  
  
##  <a name="a-namedtora--ccomsafedeletecriticalsectionccomsafedeletecriticalsection"></a><a name="dtor"></a>CComSafeDeleteCriticalSection:: ~ CComSafeDeleteCriticalSection  
 O destruidor.  
  
```
~CComSafeDeleteCriticalSection() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Libera o interno **CRITICAL_SECTION** do objeto da memória se o [m_bInitialized](#m_binitialized) membro de dados está definido como **true**.  
  
##  <a name="a-nameinita--ccomsafedeletecriticalsectioninit"></a><a name="init"></a>CComSafeDeleteCriticalSection::Init  
 Chama a implementação da classe base [Init](/visualstudio/debugger/init) e define [m_bInitialized](#m_binitialized) para **true** se for bem-sucedido.  
  
```
HRESULT Init() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o resultado de [CComCriticalSection::Init](../../atl/reference/ccomcriticalsection-class.md#init).  
  
##  <a name="a-namelocka--ccomsafedeletecriticalsectionlock"></a><a name="lock"></a>CComSafeDeleteCriticalSection::Lock  
Chama a implementação da classe base [bloqueio](ccomcriticalsection-class.md#lock).  

  
```
HRESULT Lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o resultado de [CComCriticalSection::Lock](../../atl/reference/ccomcriticalsection-class.md#lock).  
  
### <a name="remarks"></a>Comentários  
 Este método assume o [m_bInitialized](#m_binitialized) membro de dados está definido como **true** na entrada. Uma declaração é gerada em compilações de depuração se este condidtion não for atendida.  
  
 Para obter mais informações sobre o comportamento da função, consulte [CComCriticalSection::Lock](../../atl/reference/ccomcriticalsection-class.md#lock).  
  
##  <a name="a-namembinitializeda--ccomsafedeletecriticalsectionmbinitialized"></a><a name="m_binitialized"></a>CComSafeDeleteCriticalSection::m_bInitialized  
 Sinalizadores se interno **CRITICAL_SECTION** objeto foi inicializado.  
  
```
bool m_bInitialized;
```  
  
### <a name="remarks"></a>Comentários  
 O **m_bInitialized** membro de dados é usado para controlar a validade de subjacente **CRITICAL_SECTION** objeto associado a [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md) classe. Subjacente **CRITICAL_SECTION** objeto não será tentado a liberação da memória se este sinalizador não estiver definido como **true**.  
  
##  <a name="a-nameterma--ccomsafedeletecriticalsectionterm"></a><a name="term"></a>CComSafeDeleteCriticalSection::Term  
 Chama a implementação da classe base [CComCriticalSection::Term](../../atl/reference/ccomcriticalsection-class.md#term) se interno **CRITICAL_SECTION** objeto é válido.  
  
```
HRESULT Term() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o resultado de [CComCriticalSection::Term](../../atl/reference/ccomcriticalsection-class.md#term), ou **S_OK** se [m_bInitialized](#m_binitialized) foi definido como **false** na entrada.  
  
### <a name="remarks"></a>Comentários  
 É seguro chamar este se até mesmo método interno **CRITICAL_SECTION** objeto não é válido. O destruidor da classe chama esse método se o [m_bInitialized](#m_binitialized) membro de dados está definido como **true**.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

