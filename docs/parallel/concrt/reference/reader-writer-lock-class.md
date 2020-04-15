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
ms.openlocfilehash: 13b44387f3e9489090ec31345fe4347ff5f205ca
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376248"
---
# <a name="reader_writer_lock-class"></a>Classe reader_writer_lock

Um bloqueio de leitor-escritor baseado em fila de preferência de escritor com apenas giro local. O bloqueio concede primeiro acesso - primeiro out (FIFO) a escritores e morre de fome aos leitores sob uma carga contínua de escritores.

## <a name="syntax"></a>Sintaxe

```cpp
class reader_writer_lock;
```

## <a name="members"></a>Membros

### <a name="public-classes"></a>Classes públicas

|Nome|Descrição|
|----------|-----------------|
|[Classe reader_writer_lock::scoped_lock](#scoped_lock_class)|Um invólucro RAII seguro de `reader_writer_lock` exceção que pode ser usado para adquirir objetos de bloqueio como um escritor.|
|[Classe reader_writer_lock::scoped_lock_read](#scoped_lock_read_class)|Um invólucro RAII seguro de `reader_writer_lock` exceção que pode ser usado para adquirir objetos de bloqueio como um leitor.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[reader_writer_lock](#ctor)|Constrói um novo objeto `reader_writer_lock`.|
|[~reader_writer_lock Destruidor](#dtor)|Destrói o `reader_writer_lock` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Bloqueio](#lock)|Adquire o bloqueio leitor-escritor como escritor.|
|[lock_read](#lock_read)|Adquire o bloqueio leitor-escritor como leitor. Se há escritores, os leitores ativos têm que esperar até que eles sejam feitos. O leitor simplesmente registra um interesse na fechadura e espera que os escritores a liberem.|
|[try_lock](#try_lock)|Tenta adquirir o bloqueio leitor-escritor como um escritor sem bloquear.|
|[try_lock_read](#try_lock_read)|Tenta adquirir o bloqueio leitor-escritor como leitor sem bloquear.|
|[Desbloquear](#unlock)|Desbloqueia o bloqueio leitor-escritor com base em quem o trancou, leitor ou escritor.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Estruturas de dados de sincronização](../../../parallel/concrt/synchronization-data-structures.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`reader_writer_lock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt.h

**Namespace:** concurrency

## <a name="lock"></a><a name="lock"></a>Bloqueio

Adquire o bloqueio leitor-escritor como escritor.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Muitas vezes é mais [scoped_lock](#scoped_lock_class) seguro utilizar o `reader_writer_lock` scoped_lock construir para adquirir e liberar um objeto como escritor de forma segura.

Depois que um escritor tentar adquirir a fechadura, qualquer futuro leitor bloqueará até que os escritores tenham adquirido e liberado a fechadura com sucesso. Este bloqueio é tendencioso para escritores e pode matar de fome leitores sob uma carga contínua de escritores.

Escritores são acorrentados para que um escritor que sai da fechadura libere o próximo escritor na linha.

Se o bloqueio já estiver mantido pelo contexto de chamada, uma [exceção improper_lock](improper-lock-class.md) será lançada.

## <a name="lock_read"></a><a name="lock_read"></a>lock_read

Adquire o bloqueio leitor-escritor como leitor. Se há escritores, os leitores ativos têm que esperar até que eles sejam feitos. O leitor simplesmente registra um interesse na fechadura e espera que os escritores a liberem.

```cpp
void lock_read();
```

### <a name="remarks"></a>Comentários

Muitas vezes é mais [scoped_lock_read](#scoped_lock_read_class) seguro utilizar o `reader_writer_lock` scoped_lock_read construir para adquirir e liberar um objeto como leitor de forma segura.

Se houver escritores esperando na fechadura, o leitor esperará até que todos os escritores da fila tenham adquirido e liberado a fechadura. Este bloqueio é tendencioso para escritores e pode matar de fome leitores sob uma carga contínua de escritores.

## <a name="reader_writer_lock"></a><a name="ctor"></a>Reader_writer_lock

Constrói um novo objeto `reader_writer_lock`.

```cpp
reader_writer_lock();
```

## <a name="reader_writer_lock"></a><a name="dtor"></a>~READER_WRITER_LOCK

Destrói o `reader_writer_lock` objeto.

```cpp
~reader_writer_lock();
```

### <a name="remarks"></a>Comentários

Espera-se que a trava não seja mais mantida quando o destruidor funciona. Permitir que o bloqueio do leitor se destrua com o bloqueio ainda mantido resulta em comportamento indefinido.

## <a name="reader_writer_lockscoped_lock-class"></a><a name="scoped_lock_class"></a>reader_writer_lock::Scoped_lock

Um invólucro RAII seguro de `reader_writer_lock` exceção que pode ser usado para adquirir objetos de bloqueio como um escritor.

```cpp
class scoped_lock;
```

## <a name="scoped_lockscoped_lock"></a><a name="scoped_lock_ctor"></a>scoped_lock:scoped_lock

Constrói um `scoped_lock` objeto e `reader_writer_lock` adquire o `_Reader_writer_lock` objeto passado no parâmetro como escritor. Se a trava for mantida por outro fio, esta chamada será bloqueada.

```cpp
explicit _CRTIMP scoped_lock(reader_writer_lock& _Reader_writer_lock);
```

### <a name="parameters"></a>Parâmetros

*_Reader_writer_lock*<br/>
O `reader_writer_lock` objeto a adquirir como escritor.

## <a name="scoped_lockscoped_lock"></a><a name="scoped_lock_dtor"></a>scoped_lock::~scoped_lock

Destrói um `reader_writer_lock` objeto e libera a fechadura fornecida em sua construtora.

```cpp
~scoped_lock();
```

## <a name="reader_writer_lockscoped_lock_read-class"></a><a name="scoped_lock_read_class"></a>reader_writer_lock:scoped_lock_read

Um invólucro RAII seguro de `reader_writer_lock` exceção que pode ser usado para adquirir objetos de bloqueio como um leitor.

```cpp
class scoped_lock_read;
```

## <a name="scoped_lock_readscoped_lock_read"></a><a name="scoped_lock_read_ctor"></a>scoped_lock_read:scoped_lock_read

Constrói um `scoped_lock_read` objeto e `reader_writer_lock` adquire o `_Reader_writer_lock` objeto passado no parâmetro como leitor. Se o bloqueio for mantido por outro segmento como um escritor ou houver escritores pendentes, esta chamada será bloqueada.

```cpp
explicit _CRTIMP scoped_lock_read(reader_writer_lock& _Reader_writer_lock);
```

### <a name="parameters"></a>Parâmetros

*_Reader_writer_lock*<br/>
O `reader_writer_lock` objeto a adquirir como leitor.

## <a name="a-namescoped_lock_read_dtor--reader_writer_lockscoped_lock_readscoped_lock_read-destructor"></a><a name="scoped_lock_read_dtor">reader_writer_lock:scoped_lock_read::~Scoped_lock_read Destruidor

Destrói um `scoped_lock_read` objeto e libera a fechadura fornecida em sua construtora.

```cpp
~scoped_lock_read();
```

## <a name="try_lock"></a><a name="try_lock"></a>try_lock

Tenta adquirir o bloqueio leitor-escritor como um escritor sem bloquear.

### <a name="syntax"></a>Sintaxe

```cpp
bool try_lock();
```

### <a name="return-value"></a>Valor retornado

Se o bloqueio foi adquirido, o valor **verdadeiro;** caso contrário, o valor **falso**.

## <a name="try_lock_read"></a><a name="try_lock_read"></a>try_lock_read

Tenta adquirir o bloqueio leitor-escritor como leitor sem bloquear.

```cpp
bool try_lock_read();
```

### <a name="return-value"></a>Valor retornado

Se o bloqueio foi adquirido, o valor **verdadeiro;** caso contrário, o valor **falso**.

## <a name="unlock"></a><a name="unlock"></a>Desbloquear

Desbloqueia o bloqueio leitor-escritor com base em quem o trancou, leitor ou escritor.

```cpp
void unlock();
```

### <a name="remarks"></a>Comentários

Se houver escritores esperando na fechadura, a liberação da fechadura sempre irá para o próximo escritor em ordem FIFO. Este bloqueio é tendencioso para escritores e pode matar de fome leitores sob uma carga contínua de escritores.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[Classe critical_section](critical-section-class.md)
