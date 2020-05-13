---
title: Classe critical_section
ms.date: 11/04/2016
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
helpviewer_keywords:
- critical_section class
ms.assetid: fa3c89d6-be5d-4d1b-bddb-8232814e6cf6
ms.openlocfilehash: 24f96282a7728c6db6e0b05d36406f15383913f3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372688"
---
# <a name="critical_section-class"></a>Classe critical_section

Um mutex não reentrante que está explicitamente ciente do Tempo de Execução de Concorrência.

## <a name="syntax"></a>Sintaxe

```cpp
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
|[Classe critical_section::scoped_lock](#critical_section__scoped_lock_class)|Um invólucro RAII `critical_section` seguro de exceção para um objeto.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[critical_section](#ctor)|Constrói uma nova seção crítica.|
|[~critical_section Destruidor](#dtor)|Destrói uma seção crítica.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Bloqueio](#lock)|Adquire esta seção crítica.|
|[native_handle](#native_handle)|Retorna uma alça nativa específica da plataforma, se existir.|
|[try_lock](#try_lock)|Tenta adquirir a fechadura sem bloquear.|
|[try_lock_for](#try_lock_for)|Tenta adquirir a fechadura sem bloquear por um número específico de milissegundos.|
|[Desbloquear](#unlock)|Desbloqueia a seção crítica.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Estruturas de dados de sincronização](../../../parallel/concrt/synchronization-data-structures.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`critical_section`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrt.h

**Namespace:** concurrency

## <a name="critical_section"></a><a name="ctor"></a>Critical_section

Constrói uma nova seção crítica.

```cpp
critical_section();
```

## <a name="critical_section"></a><a name="dtor"></a>~critical_section

Destrói uma seção crítica.

```cpp
~critical_section();
```

### <a name="remarks"></a>Comentários

Espera-se que a trava não seja mais mantida quando o destruidor funciona. Permitir que a seção crítica se destrua com o bloqueio ainda mantido resulta em comportamento indefinido.

## <a name="lock"></a><a name="lock"></a>Bloqueio

Adquire esta seção crítica.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Muitas vezes é mais [scoped_lock](#critical_section__scoped_lock_class) seguro utilizar o `critical_section` scoped_lock construir para adquirir e liberar um objeto de forma segura.

Se o bloqueio já estiver mantido pelo contexto de chamada, uma [exceção improper_lock](improper-lock-class.md) será lançada.

## <a name="native_handle"></a><a name="native_handle"></a>native_handle

Retorna uma alça nativa específica da plataforma, se existir.

```cpp
native_handle_type native_handle();
```

### <a name="return-value"></a>Valor retornado

Uma referência à seção crítica.

### <a name="remarks"></a>Comentários

Um `critical_section` objeto não está associado a uma alça nativa específica da plataforma para o sistema operacional Windows. O método simplesmente retorna uma referência ao objeto em si.

## <a name="critical_sectionscoped_lock-class"></a><a name="critical_section__scoped_lock_class"></a>critical_section::Classe scoped_lock

Um invólucro RAII `critical_section` seguro de exceção para um objeto.

```cpp
class scoped_lock;
```

## <a name="scoped_lockscoped_lock"></a><a name="critical_section__scoped_lock_ctor"></a>scoped_lock:scoped_lock

Constrói um `scoped_lock` objeto e `critical_section` adquire o `_Critical_section` objeto passado no parâmetro. Se a seção crítica for mantida por outro segmento, esta chamada será bloqueada.

```cpp
explicit _CRTIMP scoped_lock(critical_section& _Critical_section);
```

### <a name="parameters"></a>Parâmetros

*_Critical_section*<br/>
A seção crítica para travar.

## <a name="scoped_lockscoped_lock"></a><a name="critical_section__scoped_lock_dtor"></a>scoped_lock::~scoped_lock

Destrói um `scoped_lock` objeto e libera a seção crítica fornecida em seu construtor.

```cpp
~scoped_lock();
```

## <a name="try_lock"></a><a name="try_lock"></a>try_lock

Tenta adquirir a fechadura sem bloquear.

```cpp
bool try_lock();
```

### <a name="return-value"></a>Valor retornado

Se o bloqueio foi adquirido, o valor **verdadeiro;** caso contrário, o valor **falso**.

## <a name="try_lock_for"></a><a name="try_lock_for"></a>try_lock_for

Tenta adquirir a fechadura sem bloquear por um número específico de milissegundos.

```cpp
bool try_lock_for(unsigned int _Timeout);
```

### <a name="parameters"></a>Parâmetros

*_Timeout*<br/>
O número de milissegundos para esperar antes de cronometrar.

### <a name="return-value"></a>Valor retornado

Se o bloqueio foi adquirido, o valor **verdadeiro;** caso contrário, o valor **falso**.

## <a name="unlock"></a><a name="unlock"></a>Desbloquear

Desbloqueia a seção crítica.

```cpp
void unlock();
```

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[classe reader_writer_lock](reader-writer-lock-class.md)
