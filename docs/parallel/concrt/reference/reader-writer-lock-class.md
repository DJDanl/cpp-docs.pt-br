---
title: Classe reader_writer_lock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 75bea63c6e2f73ebd58434874758c4f20444958a
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="readerwriterlock-class"></a>Classe reader_writer_lock
Um bloqueio de leitor-gravador baseadas em fila do gravador de preferência com local apenas girando. O bloqueio concede primeiro - primeiro acesso (PEPS) para gravadores e impede leitores sob uma carga contínua de gravadores.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class reader_writer_lock;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-classes"></a>Classes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe de reader_writer_lock](#scoped_lock_class)|Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um gravador.|  
|[Classe de reader_writer_lock](#scoped_lock_read_class)|Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um leitor.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[reader_writer_lock](#ctor)|Constrói um novo objeto `reader_writer_lock`.|  
|[~ reader_writer_lock destruidor](#dtor)|Destrói a `reader_writer_lock` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[lock](#lock)|Adquire o bloqueio de leitor-gravador como um gravador.|  
|[lock_read](#lock_read)|Adquire o bloqueio de leitor-gravador como um leitor. Se houver gravadores, leitores active necessário esperar até que eles são feitos. O leitor simplesmente registra um interesse no bloqueio e aguarda gravadores para liberá-lo.|  
|[try_lock](#try_lock)|Tenta adquirir o bloqueio de leitor-gravador como um gravador sem bloqueio.|  
|[try_lock_read](#try_lock_read)|Tenta adquirir o bloqueio de leitor-gravador como um leitor sem bloqueio.|  
|[unlock](#unlock)|Libera o bloqueio de leitor-gravador com base em quem bloqueou a ele, leitor ou gravador.|  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [estruturas de dados de sincronização](../../../parallel/concrt/synchronization-data-structures.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `reader_writer_lock`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrt.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="lock"></a> bloqueio 

 Adquire o bloqueio de leitor-gravador como um gravador.  
  
```
void lock();
```  
  
### <a name="remarks"></a>Comentários  
 Geralmente é mais seguro utilizar o [scoped_lock](#scoped_lock_class) construção para adquirir e liberar uma `reader_writer_lock` objeto como um gravador de uma exceção modo seguro.  
  
 Depois que um gravador tenta adquirir o bloqueio, qualquer leitores futuras serão bloqueado até que os gravadores tiveram adquirido e liberado o bloqueio com êxito. Esse bloqueio é restrito pela gravadores e pode enfraquecer leitores sob uma carga contínua de gravadores.  
  
 Os gravadores são encadeados para que um gravador sair do bloqueio libera o gravador Avançar na linha.  
  
 Se o bloqueio já é mantido pelo contexto de chamada, um [improper_lock](improper-lock-class.md) exceção será lançada.  
  
##  <a name="lock_read"></a> lock_read 

 Adquire o bloqueio de leitor-gravador como um leitor. Se houver gravadores, leitores active necessário esperar até que eles são feitos. O leitor simplesmente registra um interesse no bloqueio e aguarda gravadores para liberá-lo.  
  
```
void lock_read();
```  
  
### <a name="remarks"></a>Comentários  
 Geralmente é mais seguro utilizar o [scoped_lock_read](#scoped_lock_read_class) construção para adquirir e liberar uma `reader_writer_lock` objeto como um leitor em uma exceção modo seguro.  
  
 Se houver gravadores aguardando o bloqueio, o leitor aguardará até que todos os gravadores de linha têm adquiridos e liberados o bloqueio. Esse bloqueio é restrito pela gravadores e pode enfraquecer leitores sob uma carga contínua de gravadores.  
  
##  <a name="ctor"></a> reader_writer_lock 

 Constrói um novo objeto `reader_writer_lock`.  
  
```
reader_writer_lock();
```  
  
##  <a name="dtor"></a> ~ reader_writer_lock 

 Destrói a `reader_writer_lock` objeto.  
  
```
~reader_writer_lock();
```  
  
### <a name="remarks"></a>Comentários  
 É esperado que o bloqueio não é mantido quando o destruidor é executado. Ainda que permite o bloqueio de gravador do leitor para destruct com o bloqueio mantido resultados em um comportamento indefinido.  
  
##  <a name="scoped_lock_class">Classe de reader_writer_lock</a>  
 Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um gravador.  
  
```
class scoped_lock;
``` 
## <a name="scoped_lock_ctor"></a> scoped_lock::scoped_lock 

Constrói um `scoped_lock` de objeto e adquire o `reader_writer_lock` objeto passado a `_Reader_writer_lock` parâmetro como um gravador. Se o bloqueio é mantido por outro thread, essa chamada será bloqueado.  
  
  
```
explicit _CRTIMP scoped_lock(reader_writer_lock& _Reader_writer_lock);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Reader_writer_lock`  
 O `reader_writer_lock` objeto adquirir como um gravador.  
  
## <a name="scoped_lock_dtor"></a> scoped_lock:: ~ scoped_lock 

Destrói um `reader_writer_lock` de objeto e libera o bloqueio fornecido no construtor.   

```
~scoped_lock();
```  
  
##  <a name="scoped_lock_read_class">Classe de reader_writer_lock</a>  
 Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um leitor.  
  
```
class scoped_lock_read;
```  
  
##  <a name="try_lock"></a> try_lock 

 Tenta adquirir o bloqueio de leitor-gravador como um gravador sem bloqueio.  

## <a name="scoped_lock_read_ctor"></a> scoped_lock_read::scoped_lock_read 

Constrói um `scoped_lock_read` de objeto e adquire o `reader_writer_lock` objeto passado a `_Reader_writer_lock` parâmetro como um leitor. Se o bloqueio é mantido por outro thread, como autor ou pendentes gravadores, essa chamada será bloqueado.  
  
```
explicit _CRTIMP scoped_lock_read(reader_writer_lock& _Reader_writer_lock);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Reader_writer_lock`  
 O `reader_writer_lock` objeto adquirir como um leitor.  
  
## <a name="a-namescopedlockreaddtor--readerwriterlockscopedlockreadscopedlockread-destructor"></a><a name="scoped_lock_read_dtor">  reader_writer_lock:: ~ scoped_lock_read destruidor
Destrói um `scoped_lock_read` de objeto e libera o bloqueio fornecido no construtor.  

```
~scoped_lock_read();
```  
  
## <a name="try_lock"></a> try_lock 

```
bool try_lock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio foi adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="try_lock_read"></a> try_lock_read 

 Tenta adquirir o bloqueio de leitor-gravador como um leitor sem bloqueio.  
  
```
bool try_lock_read();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o bloqueio foi adquirido, o valor `true`; caso contrário, o valor `false`.  
  
##  <a name="unlock"></a> desbloquear 

 Libera o bloqueio de leitor-gravador com base em quem bloqueou a ele, leitor ou gravador.  
  
```
void unlock();
```  
  
### <a name="remarks"></a>Comentários  
 Se houver gravadores aguardando o bloqueio, a liberação do bloqueio sempre vai para o próximo gravador na ordem FIFO. Esse bloqueio é restrito pela gravadores e pode enfraquecer leitores sob uma carga contínua de gravadores.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Classe critical_section](critical-section-class.md)
