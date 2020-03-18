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
ms.openlocfilehash: 1a7386e527b5327d928bfdcb3281c88666f1b106
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417120"
---
# <a name="reader_writer_lock-class"></a>Classe reader_writer_lock

Um gravador-bloqueio de leitor baseado em fila de preferência de gravação com rotação somente local. O bloqueio concede o acesso PEPS (primeiro a entrar, primeiro a sair) a gravadores e priva os leitores em uma carga contínua de gravadores.

## <a name="syntax"></a>Sintaxe

```cpp
class reader_writer_lock;
```

## <a name="members"></a>Membros

### <a name="public-classes"></a>Classes Públicas

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Classe reader_writer_lock:: scoped_lock](#scoped_lock_class)|Um wrapper RAII de exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um gravador.|
|[Classe reader_writer_lock:: scoped_lock_read](#scoped_lock_read_class)|Um wrapper RAII de exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um leitor.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[reader_writer_lock](#ctor)|Constrói um novo objeto `reader_writer_lock`.|
|[~ reader_writer_lock destruidor](#dtor)|Destrói o objeto `reader_writer_lock`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[lock](#lock)|Adquire o bloqueio do gravador de leitor como um gravador.|
|[lock_read](#lock_read)|Adquire o bloqueio do gravador de leitor como um leitor. Se houver gravadores, os leitores ativos deverão aguardar até que sejam concluídos. O leitor simplesmente registra um interesse no bloqueio e aguarda que os gravadores o liberem.|
|[try_lock](#try_lock)|Tenta adquirir o bloqueio do gravador de leitor como um gravador sem bloqueio.|
|[try_lock_read](#try_lock_read)|Tenta adquirir o bloqueio do gravador de leitor como um leitor sem bloqueio.|
|[unlock](#unlock)|Desbloqueia o bloqueio de leitor-gravador com base em quem o bloqueou, leitor ou gravador.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Synchronization data structures](../../../parallel/concrt/synchronization-data-structures.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`reader_writer_lock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="lock"></a>proprietário

Adquire o bloqueio do gravador de leitor como um gravador.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Geralmente, é mais seguro utilizar a construção [scoped_lock](#scoped_lock_class) para adquirir e liberar um objeto `reader_writer_lock` como um gravador de uma forma segura de exceção.

Depois que um gravador tenta adquirir o bloqueio, os leitores futuros serão bloqueados até que os gravadores tenham adquirido e liberado o bloqueio com êxito. Esse bloqueio é polarizado em relação a gravadores e pode privar os leitores sob uma carga contínua de gravadores.

Os gravadores são encadeados para que um gravador que sai do bloqueio libere o próximo gravador em linha.

Se o bloqueio já estiver sendo mantido pelo contexto de chamada, uma exceção de [improper_lock](improper-lock-class.md) será lançada.

## <a name="lock_read"></a>lock_read

Adquire o bloqueio do gravador de leitor como um leitor. Se houver gravadores, os leitores ativos deverão aguardar até que sejam concluídos. O leitor simplesmente registra um interesse no bloqueio e aguarda que os gravadores o liberem.

```cpp
void lock_read();
```

### <a name="remarks"></a>Comentários

Geralmente, é mais seguro utilizar a construção [scoped_lock_read](#scoped_lock_read_class) para adquirir e liberar um objeto `reader_writer_lock` como um leitor de uma forma segura de exceção.

Se houver gravadores aguardando o bloqueio, o leitor aguardará até que todos os gravadores na linha tenham adquirido e liberado o bloqueio. Esse bloqueio é polarizado em relação a gravadores e pode privar os leitores sob uma carga contínua de gravadores.

## <a name="ctor"></a>reader_writer_lock

Constrói um novo objeto `reader_writer_lock`.

```cpp
reader_writer_lock();
```

## <a name="dtor"></a>~ reader_writer_lock

Destrói o objeto `reader_writer_lock`.

```cpp
~reader_writer_lock();
```

### <a name="remarks"></a>Comentários

Espera-se que o bloqueio não seja mais mantido quando o destruidor for executado. Permitir que o bloqueio do gravador de leitor seja destruido com o bloqueio ainda resulta em um comportamento indefinido.

## <a name="scoped_lock_class"></a>Classe reader_writer_lock:: scoped_lock

Um wrapper RAII de exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um gravador.

```cpp
class scoped_lock;
```

## <a name="scoped_lock_ctor"></a>scoped_lock:: scoped_lock

Constrói um objeto `scoped_lock` e adquire o objeto `reader_writer_lock` passado no parâmetro `_Reader_writer_lock` como um gravador. Se o bloqueio for mantido por outro thread, essa chamada será bloqueada.

```cpp
explicit _CRTIMP scoped_lock(reader_writer_lock& _Reader_writer_lock);
```

### <a name="parameters"></a>parâmetros

*_Reader_writer_lock*<br/>
O objeto `reader_writer_lock` a ser adquirido como um gravador.

## <a name="scoped_lock_dtor"></a>scoped_lock:: ~ scoped_lock

Destrói um objeto `reader_writer_lock` e libera o bloqueio fornecido em seu construtor.

```cpp
~scoped_lock();
```

## <a name="scoped_lock_read_class"></a>Classe reader_writer_lock:: scoped_lock_read

Um wrapper RAII de exceção seguro que pode ser usado para adquirir `reader_writer_lock` bloquear objetos como um leitor.

```cpp
class scoped_lock_read;
```

## <a name="scoped_lock_read_ctor"></a>scoped_lock_read:: scoped_lock_read

Constrói um objeto `scoped_lock_read` e adquire o objeto `reader_writer_lock` passado no parâmetro `_Reader_writer_lock` como um leitor. Se o bloqueio for mantido por outro thread como um gravador ou se houver gravadores pendentes, essa chamada será bloqueada.

```cpp
explicit _CRTIMP scoped_lock_read(reader_writer_lock& _Reader_writer_lock);
```

### <a name="parameters"></a>parâmetros

*_Reader_writer_lock*<br/>
O objeto `reader_writer_lock` a ser adquirido como um leitor.

## <a name="a-namescoped_lock_read_dtor--reader_writer_lockscoped_lock_readscoped_lock_read-destructor"></a><a name="scoped_lock_read_dtor"> reader_writer_lock:: scoped_lock_read:: ~ scoped_lock_read destruidor

Destrói um objeto `scoped_lock_read` e libera o bloqueio fornecido em seu construtor.

```cpp
~scoped_lock_read();
```

## <a name="try_lock"></a>try_lock

Tenta adquirir o bloqueio do gravador de leitor como um gravador sem bloqueio.

### <a name="syntax"></a>Sintaxe

```cpp
bool try_lock();
```

### <a name="return-value"></a>Valor retornado

Se o bloqueio foi adquirido, o valor **true**; caso contrário, o valor **false**.

## <a name="try_lock_read"></a>try_lock_read

Tenta adquirir o bloqueio do gravador de leitor como um leitor sem bloqueio.

```cpp
bool try_lock_read();
```

### <a name="return-value"></a>Valor retornado

Se o bloqueio foi adquirido, o valor **true**; caso contrário, o valor **false**.

## <a name="unlock"></a>automático

Desbloqueia o bloqueio de leitor-gravador com base em quem o bloqueou, leitor ou gravador.

```cpp
void unlock();
```

### <a name="remarks"></a>Comentários

Se houver gravadores aguardando o bloqueio, o lançamento do bloqueio sempre vai para o próximo gravador na ordem FIFO. Esse bloqueio é polarizado em relação a gravadores e pode privar os leitores sob uma carga contínua de gravadores.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe critical_section](critical-section-class.md)
