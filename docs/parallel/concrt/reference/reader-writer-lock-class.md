---
title: Classe reader_writer_lock
ms.date: 11/04/2016
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
helpviewer_keywords:
- reader_writer_lock class
ms.assetid: 91a59cd2-ca05-4b74-8398-d826d9f86736
ms.openlocfilehash: 111d48b9c4a575078f2342bfaa944871bbd628f5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394332"
---
# <a name="readerwriterlock-class"></a>Classe reader_writer_lock

Um bloqueio de leitor-gravador baseado em fila do gravador preferência com local apenas em rotação. O bloqueio concede a primeiro – primeiro acesso (FIFO) para gravadores e consome os leitores sob uma carga contínua de gravadores.

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
|[~ reader_writer_lock destruidor](#dtor)|Destrói o `reader_writer_lock` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[lock](#lock)|Adquire o bloqueio de leitor-gravador como um gravador.|
|[lock_read](#lock_read)|Adquire o bloqueio de leitor-gravador como um leitor. Se houver gravadores, leitores de Active Directory precisa aguardar até que eles são feitos. O leitor simplesmente registra um interesse em que o bloqueio e aguarda para gravadores de liberá-la.|
|[try_lock](#try_lock)|Tenta adquirir o bloqueio de leitor-gravador como redator sem bloqueio.|
|[try_lock_read](#try_lock_read)|Tenta adquirir o bloqueio de leitor-gravador como um leitor sem bloqueio.|
|[unlock](#unlock)|Desbloqueia o bloqueio de leitor-gravador com base em quem bloqueou a ele, leitor ou gravador.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [estruturas de dados de sincronização](../../../parallel/concrt/synchronization-data-structures.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`reader_writer_lock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt. h

**Namespace:** simultaneidade

##  <a name="lock"></a> Bloqueio

Adquire o bloqueio de leitor-gravador como um gravador.

```
void lock();
```

### <a name="remarks"></a>Comentários

Geralmente é mais seguro utilizar o [scoped_lock](#scoped_lock_class) constructo para adquirir e liberar um `reader_writer_lock` objeto como um gravador em uma exceção modo seguro.

Depois de um gravador de tentativas adquirir o bloqueio, leitores futuras serão bloqueada até que os gravadores com êxito tem adquirido e liberado o bloqueio. Esse bloqueio é mais adequado para os gravadores e pode enfraquecer os leitores sob uma carga contínua de gravadores.

Os gravadores são encadeados para que um gravador de sair do bloqueio libera o gravador Avançar na linha.

Se o bloqueio já é mantido pelo contexto de chamada, um [improper_lock](improper-lock-class.md) exceção será lançada.

##  <a name="lock_read"></a> lock_read

Adquire o bloqueio de leitor-gravador como um leitor. Se houver gravadores, leitores de Active Directory precisa aguardar até que eles são feitos. O leitor simplesmente registra um interesse em que o bloqueio e aguarda para gravadores de liberá-la.

```
void lock_read();
```

### <a name="remarks"></a>Comentários

Geralmente é mais seguro utilizar o [scoped_lock_read](#scoped_lock_read_class) constructo para adquirir e liberar um `reader_writer_lock` objeto como um leitor em uma exceção modo seguro.

Se houver gravadores aguardando o bloqueio, o leitor aguardará até que todos os gravadores na linha tem adquirido e liberado o bloqueio. Esse bloqueio é mais adequado para os gravadores e pode enfraquecer os leitores sob uma carga contínua de gravadores.

##  <a name="ctor"></a> reader_writer_lock

Constrói um novo objeto `reader_writer_lock`.

```
reader_writer_lock();
```

##  <a name="dtor"></a> ~reader_writer_lock

Destrói o `reader_writer_lock` objeto.

```
~reader_writer_lock();
```

### <a name="remarks"></a>Comentários

É esperado que o bloqueio não é mais mantido quando o destruidor for executado. Ainda que permite o bloqueio de gravador de leitor destruidor com o bloqueio mantido resultados em um comportamento indefinido.

##  <a name="scoped_lock_class"></a>  Classe de reader_writer_lock

Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um gravador.

```
class scoped_lock;
```

## <a name="scoped_lock_ctor"></a> scoped_lock::scoped_lock

Constrói uma `scoped_lock` do objeto e adquire o `reader_writer_lock` objeto passado a `_Reader_writer_lock` parâmetro como um gravador. Se o bloqueio for mantido por outro thread, essa chamada bloqueará.

```
explicit _CRTIMP scoped_lock(reader_writer_lock& _Reader_writer_lock);
```

#### <a name="parameters"></a>Parâmetros

*_Reader_writer_lock*<br/>
O `reader_writer_lock` objeto adquirir como um gravador.

## <a name="scoped_lock_dtor"></a> scoped_lock:: ~ scoped_lock

Destrói um `reader_writer_lock` do objeto e libera o bloqueio fornecido no construtor.

```
~scoped_lock();
```

##  <a name="scoped_lock_read_class"></a>  Classe de reader_writer_lock

Um wrapper RAII exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um leitor.

```
class scoped_lock_read;
```

##  <a name="try_lock"></a> try_lock

Tenta adquirir o bloqueio de leitor-gravador como redator sem bloqueio.

## <a name="scoped_lock_read_ctor"></a> scoped_lock_read::scoped_lock_read

Constrói uma `scoped_lock_read` do objeto e adquire o `reader_writer_lock` objeto passado a `_Reader_writer_lock` parâmetro como um leitor. Se o bloqueio for mantido por outro thread como um gravador ou há pendentes gravadores, essa chamada bloqueará.

```
explicit _CRTIMP scoped_lock_read(reader_writer_lock& _Reader_writer_lock);
```

#### <a name="parameters"></a>Parâmetros

*_Reader_writer_lock*<br/>
O `reader_writer_lock` objeto adquirir como um leitor.

## <a name="a-namescopedlockreaddtor--readerwriterlockscopedlockreadscopedlockread-destructor"></a><a name="scoped_lock_read_dtor">  reader_writer_lock:: ~ scoped_lock_read destruidor

Destrói um `scoped_lock_read` do objeto e libera o bloqueio fornecido no construtor.

```
~scoped_lock_read();
```

## <a name="try_lock"></a> try_lock

```
bool try_lock();
```

### <a name="return-value"></a>Valor de retorno

Se o bloqueio foi adquirido, o valor **verdadeira**; caso contrário, o valor **falso**.

##  <a name="try_lock_read"></a> try_lock_read

Tenta adquirir o bloqueio de leitor-gravador como um leitor sem bloqueio.

```
bool try_lock_read();
```

### <a name="return-value"></a>Valor de retorno

Se o bloqueio foi adquirido, o valor **verdadeira**; caso contrário, o valor **falso**.

##  <a name="unlock"></a> desbloquear

Desbloqueia o bloqueio de leitor-gravador com base em quem bloqueou a ele, leitor ou gravador.

```
void unlock();
```

### <a name="remarks"></a>Comentários

Se houver gravadores aguardando o bloqueio, a versão do bloqueio sempre vai para o gravador de Avançar na ordem FIFO. Esse bloqueio é mais adequado para os gravadores e pode enfraquecer os leitores sob uma carga contínua de gravadores.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe critical_section](critical-section-class.md)
