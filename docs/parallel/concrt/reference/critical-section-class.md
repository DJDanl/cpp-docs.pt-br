---
title: Classe CRITICAL_SECTION | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- critical_section
- CONCRT/concurrency::critical_section
- CONCRT/concurrency::critical_section::critical_section::scoped_lock Class
- CONCRT/concurrency::critical_section::critical_section
- CONCRT/concurrency::critical_section::lock
- CONCRT/concurrency::critical_section::native_handle
- CONCRT/concurrency::critical_section::try_lock
- CONCRT/concurrency::critical_section::try_lock_for
- CONCRT/concurrency::critical_section::unlock
dev_langs:
- C++
helpviewer_keywords:
- critical_section class
ms.assetid: fa3c89d6-be5d-4d1b-bddb-8232814e6cf6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cbffd14bdde45c3d6124eb5f982b90c92f64f47c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46136198"
---
# <a name="criticalsection-class"></a>Classe critical_section
Um mutex não reentrante que esteja explicitamente ciente do tempo de execução de simultaneidade.  
  
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
|[Classe de CRITICAL_SECTION](#critical_section__scoped_lock_class)|Um wrapper RAII seguro de exceção para um `critical_section` objeto.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[critical_section](#ctor)|Constrói uma nova seção crítica.|  
|[~ critical_section destruidor](#dtor)|Destrói uma seção crítica.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[lock](#lock)|Adquire essa seção crítica.|  
|[native_handle](#native_handle)|Retorna um identificador nativo específico de plataforma, se houver um.|  
|[try_lock](#try_lock)|Tenta adquirir o bloqueio sem bloqueio.|  
|[try_lock_for](#try_lock_for)|Tenta adquirir o bloqueio sem bloqueio para um determinado número de milissegundos.|  
|[unlock](#unlock)|Desbloqueia a seção crítica.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [estruturas de dados de sincronização](../../../parallel/concrt/synchronization-data-structures.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `critical_section`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a> CRITICAL_SECTION 

 Constrói uma nova seção crítica.  
  
```
critical_section();
```  
  
##  <a name="dtor"></a> ~ critical_section 

 Destrói uma seção crítica.  
  
```
~critical_section();
```  
  
### <a name="remarks"></a>Comentários  
 É esperado que o bloqueio não é mais mantido quando o destruidor for executado. Ainda permitindo que a seção crítica destruidor com o bloqueio mantido resultados em um comportamento indefinido.  
  
##  <a name="lock"></a> Bloqueio 

 Adquire essa seção crítica.  
  
```
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Geralmente é mais seguro utilizar o [scoped_lock](#critical_section__scoped_lock_class) constructo para adquirir e liberar um `critical_section` objeto em uma exceção modo seguro.  
  
 Se o bloqueio já é mantido pelo contexto de chamada, um [improper_lock](improper-lock-class.md) exceção será lançada.  
  
##  <a name="native_handle"></a> native_handle 

 Retorna um identificador nativo específico de plataforma, se houver um.  
  
```
native_handle_type native_handle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a seção crítica.  
  
### <a name="remarks"></a>Comentários  
 Um `critical_section` objeto não está associado um identificador nativo de plataforma específica para o sistema operacional Windows. O método simplesmente retorna uma referência ao próprio objeto.  
  
##  <a name="critical_section__scoped_lock_class"></a>  Classe de CRITICAL_SECTION  
 Um wrapper RAII seguro de exceção para um `critical_section` objeto.  
  
```
class scoped_lock;
```  
  
##  <a name="critical_section__scoped_lock_ctor"></a> scoped_lock::scoped_lock 

 Constrói uma `scoped_lock` do objeto e adquire o `critical_section` objeto passado a `_Critical_section` parâmetro. Se a seção crítica for mantida por outro thread, essa chamada bloqueará.  
  
```
explicit _CRTIMP scoped_lock(critical_section& _Critical_section);
```  
  
### <a name="parameters"></a>Parâmetros  
*_Critical_section*<br/>
A seção crítica para bloquear.  
  
##  <a name="critical_section__scoped_lock_dtor"></a> scoped_lock:: ~ scoped_lock 

 Destrói um `scoped_lock` de objeto e libera a seção crítica fornecida no construtor.  
  
```
~scoped_lock();
```  
  
##  <a name="try_lock"></a> try_lock 

 Tenta adquirir o bloqueio sem bloqueio.  
  
```
bool try_lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio foi adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="try_lock_for"></a> try_lock_for 

 Tenta adquirir o bloqueio sem bloqueio para um determinado número de milissegundos.  
  
```
bool try_lock_for(unsigned int _Timeout);
```  
  
### <a name="parameters"></a>Parâmetros  
*Tempo limite*<br/>
O número de milissegundos de espera antes do tempo limite.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio foi adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="unlock"></a> desbloquear 

 Desbloqueia a seção crítica.  
  
```
void unlock();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe reader_writer_lock](reader-writer-lock-class.md)
