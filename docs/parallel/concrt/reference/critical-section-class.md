---
title: Classe CRITICAL_SECTION | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs: C++
helpviewer_keywords: critical_section class
ms.assetid: fa3c89d6-be5d-4d1b-bddb-8232814e6cf6
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5421cf47214d4ceeb7f8388835cb7a1cc57110ef
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[Classe de CRITICAL_SECTION](#critical_section__scoped_lock_class)|Um wrapper RAII seguro de exceção para um `critical_section` objeto.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRITICAL_SECTION](#ctor)|Constrói uma nova seção crítica.|  
|[~ critical_section destruidor](#dtor)|Destrói uma seção crítica.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[lock](#lock)|Adquire nesta seção crítica.|  
|[native_handle](#native_handle)|Retorna um identificador nativo específico de plataforma, se houver.|  
|[try_lock](#try_lock)|Tenta adquirir o bloqueio sem bloqueio.|  
|[try_lock_for](#try_lock_for)|Tenta adquirir o bloqueio sem bloqueio para um número específico de milissegundos.|  
|[unlock](#unlock)|Desbloqueia a seção crítica.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [estruturas de dados de sincronização](../../../parallel/concrt/synchronization-data-structures.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `critical_section`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>CRITICAL_SECTION 

 Constrói uma nova seção crítica.  
  
```
critical_section();
```  
  
##  <a name="dtor"></a>~ critical_section 

 Destrói uma seção crítica.  
  
```
~critical_section();
```  
  
### <a name="remarks"></a>Comentários  
 É esperado que o bloqueio não é mantido quando o destruidor é executado. Ainda que permite a seção crítica para destruct com o bloqueio mantido resultados em um comportamento indefinido.  
  
##  <a name="lock"></a>bloqueio 

 Adquire nesta seção crítica.  
  
```
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Geralmente é mais seguro utilizar o [scoped_lock](#critical_section__scoped_lock_class) construção para adquirir e liberar um `critical_section` objeto em uma exceção de modo seguro.  
  
 Se o bloqueio já é mantido pelo contexto de chamada, um [improper_lock](improper-lock-class.md) exceção será lançada.  
  
##  <a name="native_handle"></a>native_handle 

 Retorna um identificador nativo específico de plataforma, se houver.  
  
```
native_handle_type native_handle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência para a seção crítica.  
  
### <a name="remarks"></a>Comentários  
 Um `critical_section` objeto não está associado um identificador nativo específico de plataforma para o sistema operacional Windows. O método simplesmente retorna uma referência ao objeto em si.  
  
##  <a name="critical_section__scoped_lock_class"></a>Classe de CRITICAL_SECTION  
 Um wrapper RAII seguro de exceção para um `critical_section` objeto.  
  
```
class scoped_lock;
```  
  
##  <a name="critical_section__scoped_lock_ctor"></a>scoped_lock::scoped_lock 

 Constrói um `scoped_lock` de objeto e adquire o `critical_section` objeto passado a `_Critical_section` parâmetro. Se a seção crítica é mantida por outro thread, essa chamada será bloqueado.  
  
```
explicit _CRTIMP scoped_lock(critical_section& _Critical_section);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Critical_section`  
 Seção crítica para bloquear.  
  
##  <a name="critical_section__scoped_lock_dtor"></a>scoped_lock:: ~ scoped_lock 

 Destrói um `scoped_lock` de objeto e libera a seção crítica fornecida no construtor.  
  
```
~scoped_lock();
```  
  
##  <a name="try_lock"></a>try_lock 

 Tenta adquirir o bloqueio sem bloqueio.  
  
```
bool try_lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio foi adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="try_lock_for"></a>try_lock_for 

 Tenta adquirir o bloqueio sem bloqueio para um número específico de milissegundos.  
  
```
bool try_lock_for(unsigned int _Timeout);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Timeout`  
 O número de milissegundos de espera antes do tempo limite.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio foi adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="unlock"></a>desbloquear 

 Desbloqueia a seção crítica.  
  
```
void unlock();
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe reader_writer_lock](reader-writer-lock-class.md)
