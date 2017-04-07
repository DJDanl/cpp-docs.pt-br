---
title: Classe reader_writer_lock | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- reader_writer_lock
- CONCRT/concurrency::reader_writer_lock
- CONCRT/concurrency::reader_writer_lock::scoped_lock
- CONCRT/concurrency::reader_writer_lock::scoped_lock_read
- CONCRT/concurrency::reader_writer_lock::reader_writer_lock
- CONCRT/concurrency::reader_writer_lock::lock
- CONCRT/concurrency::reader_writer_lock::lock_read
- CONCRT/concurrency::reader_writer_lock::try_lock
- CONCRT/concurrency::reader_writer_lock::try_lock_read
- CONCRT/concurrency::reader_writer_lock::unlock
dev_langs:
- C++
helpviewer_keywords:
- reader_writer_lock class
ms.assetid: 91a59cd2-ca05-4b74-8398-d826d9f86736
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: b5107923baa7d22e6a98c6617a22a883c4d84125
ms.lasthandoff: 03/17/2017

---
# <a name="readerwriterlock-class"></a>Classe reader_writer_lock
Um bloqueio de leitor-gravador baseado em fila preferência gravador com local apenas girando. O bloqueio concede primeiro em - primeiro acesso (FIFO) para escritores e impede os leitores sob uma carga contínua de gravadores.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class reader_writer_lock;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-classes"></a>Classes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe reader_writer_lock](#scoped_lock_class)|Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um gravador.|  
|[Classe reader_writer_lock](#scoped_lock_read_class)|Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um leitor.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[reader_writer_lock](#ctor)|Constrói um novo `reader_writer_lock` objeto.|  
|[~ reader_writer_lock destruidor](#dtor)|Destrói o `reader_writer_lock` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[lock](#lock)|Adquire o bloqueio de leitor-gravador como um gravador.|  
|[lock_read](#lock_read)|Adquire o bloqueio de leitor-gravador como um leitor. Se houver gravadores, leitores active necessário esperar até que eles são feitos. O leitor simplesmente registra um interesse no bloqueio e aguarda gravadores para liberá-lo.|  
|[try_lock](#try_lock)|Tenta adquirir o bloqueio de leitor-gravador redator sem bloqueio.|  
|[try_lock_read](#try_lock_read)|Tenta adquirir o bloqueio de leitor-gravador como um leitor sem bloqueio.|  
|[unlock](#unlock)|Desbloqueia o bloqueio de leitor-gravador com base em quem bloqueou, leitor ou gravador.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [estruturas de dados](../../../parallel/concrt/synchronization-data-structures.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `reader_writer_lock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="lock"></a>bloqueio 

 Adquire o bloqueio de leitor-gravador como um gravador.  
  
```
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Geralmente é mais seguro utilizar o [scoped_lock](#scoped_lock_class) construção para adquirir e liberar uma `reader_writer_lock` objeto como um gravador em uma exceção modo seguro.  
  
 Após um gravador tenta adquirir o bloqueio, qualquer leitores futuros serão bloqueado até que os gravadores tiveram adquirido e libere o bloqueio com êxito. Esse bloqueio é mais adequado para gravadores e pode enfraquecer leitores sob uma carga contínua de gravadores.  
  
 Gravadores são encadeados para que um gravador sair do bloqueio libera o gravador Avançar na linha.  
  
 Se o bloqueio já é mantido pelo contexto de chamada, um [improper_lock](improper-lock-class.md) exceção será lançada.  
  
##  <a name="lock_read"></a>lock_read 

 Adquire o bloqueio de leitor-gravador como um leitor. Se houver gravadores, leitores active necessário esperar até que eles são feitos. O leitor simplesmente registra um interesse no bloqueio e aguarda gravadores para liberá-lo.  
  
```
void lock_read();
```  
  
### <a name="remarks"></a>Comentários  
 Geralmente é mais seguro utilizar o [scoped_lock_read](#scoped_lock_read_class) construção para adquirir e liberar uma `reader_writer_lock` objeto como um leitor em uma exceção modo seguro.  
  
 Se houver gravadores aguardando o bloqueio, o leitor aguardará até que todos os gravadores na linha tem adquirido e libere o bloqueio. Esse bloqueio é mais adequado para gravadores e pode enfraquecer leitores sob uma carga contínua de gravadores.  
  
##  <a name="ctor"></a>reader_writer_lock 

 Constrói um novo `reader_writer_lock` objeto.  
  
```
reader_writer_lock();
```  
  
##  <a name="dtor"></a>~ reader_writer_lock 

 Destrói o `reader_writer_lock` objeto.  
  
```
~reader_writer_lock();
```  
  
### <a name="remarks"></a>Comentários  
 Espera-se que o bloqueio não é mantido quando o destruidor é executado. Ainda permitindo que o bloqueio de gravador de leitor para destruct com o bloqueio mantido resultados em um comportamento indefinido.  
  
##  <a name="scoped_lock_class"></a>Classe reader_writer_lock  
 Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um gravador.  
  
```
class scoped_lock;
``` 
## <a name="scoped_lock_ctor"></a>scoped_lock::scoped_lock 

Constrói uma `scoped_lock` de objeto e adquire o `reader_writer_lock` objeto passado a `_Reader_writer_lock` parâmetro como um gravador. Se o bloqueio é mantido por outro thread, essa chamada será bloqueado.  
  
  
```
explicit _CRTIMP scoped_lock(reader_writer_lock& _Reader_writer_lock);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Reader_writer_lock`  
 O `reader_writer_lock` objeto adquirir como um gravador.  
  
## <a name="scoped_lock_dtor"></a>scoped_lock:: ~ scoped_lock 

Destrói um `reader_writer_lock` do objeto e libera o bloqueio fornecido no construtor.   

```
~scoped_lock();
```  
  
##  <a name="scoped_lock_read_class"></a>Classe reader_writer_lock  
 Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um leitor.  
  
```
class scoped_lock_read;
```  
  
##  <a name="try_lock"></a>try_lock 

 Tenta adquirir o bloqueio de leitor-gravador redator sem bloqueio.  

## <a name="scoped_lock_read_ctor"></a>scoped_lock_read::scoped_lock_read 

Constrói uma `scoped_lock_read` de objeto e adquire o `reader_writer_lock` objeto passado a `_Reader_writer_lock` parâmetro como um leitor. Se o bloqueio é mantido por outro thread como um gravador ou pendentes gravadores, essa chamada será bloqueado.  
  
```
explicit _CRTIMP scoped_lock_read(reader_writer_lock& _Reader_writer_lock);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Reader_writer_lock`  
 O `reader_writer_lock` objeto adquirir como um leitor.  
  
## <a name="a-namescopedlockreaddtor--readerwriterlockscopedlockreadscopedlockread-destructor"></a><a name="scoped_lock_read_dtor">reader_writer_lock:: ~ scoped_lock_read destruidor
Destrói um `scoped_lock_read` do objeto e libera o bloqueio fornecido no construtor.  

```
~scoped_lock_read();
```  
  
## <a name="try_lock"></a>try_lock 

```
bool try_lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio tiver sido adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="try_lock_read"></a>try_lock_read 

 Tenta adquirir o bloqueio de leitor-gravador como um leitor sem bloqueio.  
  
```
bool try_lock_read();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio tiver sido adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="unlock"></a>desbloquear 

 Desbloqueia o bloqueio de leitor-gravador com base em quem bloqueou, leitor ou gravador.  
  
```
void unlock();
```  
  
### <a name="remarks"></a>Comentários  
 Se houver gravadores aguardando o bloqueio, a liberação do bloqueio sempre vai para o próximo gravador na ordem FIFO. Esse bloqueio é mais adequado para gravadores e pode enfraquecer leitores sob uma carga contínua de gravadores.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe critical_section](critical-section-class.md)

