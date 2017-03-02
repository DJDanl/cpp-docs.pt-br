---
title: Classe CRITICAL_SECTION | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- concrt/concurrency::critical_section
dev_langs:
- C++
helpviewer_keywords:
- critical_section class
ms.assetid: fa3c89d6-be5d-4d1b-bddb-8232814e6cf6
caps.latest.revision: 23
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
ms.sourcegitcommit: fc190feb08d9b221cd1cc21a9c91ad567c86c848
ms.openlocfilehash: 20a150c1aedbd9d78c84187bf29e6284a248fbc7
ms.lasthandoff: 02/25/2017

---
# <a name="criticalsection-class"></a>Classe critical_section
Um mutex não reentrante que reconhece explicitamente o tempo de execução de simultaneidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class critical_section;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`native_handle_type`|Uma referência a um objeto `critical_section`.|  
  
### <a name="public-classes"></a>Classes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe CRITICAL_SECTION](#critical_section__scoped_lock_class)|Um wrapper RAII de segurança de exceção para um `critical_section` objeto.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor CRITICAL_SECTION](#ctor)|Constrói uma nova seção crítica.|  
|[~ critical_section destruidor](#dtor)|Destrói uma seção crítica.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método de bloqueio](#lock)|Adquire essa seção crítica.|  
|[Método native_handle](#native_handle)|Retorna um identificador nativo específico de plataforma, se houver.|  
|[Método try_lock](#try_lock)|Tenta adquirir o bloqueio sem bloqueio.|  
|[Método try_lock_for](#try_lock_for)|Tenta adquirir o bloqueio sem bloqueio por um número específico de milissegundos.|  
|[Método Unlock](#unlock)|Desbloqueia a seção crítica.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [estruturas de dados](../../../parallel/concrt/synchronization-data-structures.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `critical_section`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora-criticalsection"></a><a name="ctor"></a>CRITICAL_SECTION 

 Constrói uma nova seção crítica.  
  
```
critical_section();
```  
  
##  <a name="a-namedtora-criticalsection"></a><a name="dtor"></a>~ critical_section 

 Destrói uma seção crítica.  
  
```
~critical_section();
```  
  
### <a name="remarks"></a>Comentários  
 Espera-se que o bloqueio não é mantido quando o destruidor é executado. Ainda permitindo que a seção crítica para destruct com o bloqueio mantido resultados em um comportamento indefinido.  
  
##  <a name="a-namelocka-lock"></a><a name="lock"></a>bloqueio 

 Adquire essa seção crítica.  
  
```
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Geralmente é mais seguro utilizar o [scoped_lock](#critical_section__scoped_lock_class) construção para adquirir e liberar um `critical_section` objeto em uma exceção modo seguro.  
  
 Se o bloqueio já é mantido pelo contexto de chamada, um [improper_lock](improper-lock-class.md) exceção será lançada.  
  
##  <a name="a-namenativehandlea-nativehandle"></a><a name="native_handle"></a>native_handle 

 Retorna um identificador nativo específico de plataforma, se houver.  
  
```
native_handle_type native_handle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a seção crítica.  
  
### <a name="remarks"></a>Comentários  
 Um `critical_section` objeto não está associado um identificador nativo específico de plataforma para o sistema operacional Windows. O método simplesmente retorna uma referência ao próprio objeto.  
  
##  <a name="a-namecriticalsectionscopedlockclassa--criticalsectionscopedlock-class"></a><a name="critical_section__scoped_lock_class"></a>Classe CRITICAL_SECTION  
 Um wrapper RAII de segurança de exceção para um `critical_section` objeto.  
  
```
class scoped_lock;
```  
  
##  <a name="a-namecriticalsectionscopedlockctora-scopedlockscopedlock"></a><a name="critical_section__scoped_lock_ctor"></a>scoped_lock::scoped_lock 

 Constrói uma `scoped_lock` de objeto e adquire o `critical_section` objeto passado a `_Critical_section` parâmetro. Se a seção crítica é mantida por outro thread, essa chamada será bloqueado.  
  
```
explicit _CRTIMP scoped_lock(critical_section& _Critical_section);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Critical_section`  
 A seção crítica para bloquear.  
  
##  <a name="a-namecriticalsectionscopedlockdtora-scopedlockscopedlock"></a><a name="critical_section__scoped_lock_dtor"></a>scoped_lock:: ~ scoped_lock 

 Destrói um `scoped_lock` object e libera a seção crítica, fornecida no construtor.  
  
```
~scoped_lock();
```  
  
##  <a name="a-nametrylocka-trylock"></a><a name="try_lock"></a>try_lock 

 Tenta adquirir o bloqueio sem bloqueio.  
  
```
bool try_lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio tiver sido adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="a-nametrylockfora-trylockfor"></a><a name="try_lock_for"></a>try_lock_for 

 Tenta adquirir o bloqueio sem bloqueio por um número específico de milissegundos.  
  
```
bool try_lock_for(unsigned int _Timeout);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Timeout`  
 O número de milissegundos de espera antes do tempo limite.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio tiver sido adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="a-nameunlocka-unlock"></a><a name="unlock"></a>desbloquear 

 Desbloqueia a seção crítica.  
  
```
void unlock();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe reader_writer_lock](reader-writer-lock-class.md)

