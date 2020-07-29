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
ms.openlocfilehash: f7df639a879bad7af1b4de401460ff298e466c78
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215810"
---
# <a name="critical_section-class"></a>Classe critical_section

Um mutex não reentrante que reconhece explicitamente o Tempo de Execução de Simultaneidade.

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
|[Classe critical_section::scoped_lock](#critical_section__scoped_lock_class)|Um wrapper RAII de exceção seguro para um `critical_section` objeto.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[critical_section](#ctor)|Constrói uma nova seção crítica.|
|[~ critical_section destruidor](#dtor)|Destrói uma seção crítica.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[proprietário](#lock)|Adquire essa seção crítica.|
|[native_handle](#native_handle)|Retorna um identificador nativo específico da plataforma, se houver.|
|[try_lock](#try_lock)|Tenta adquirir o bloqueio sem bloqueio.|
|[try_lock_for](#try_lock_for)|Tenta adquirir o bloqueio sem bloqueio para um número específico de milissegundos.|
|[automático](#unlock)|Desbloqueia a seção crítica.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [Synchronization data structures](../../../parallel/concrt/synchronization-data-structures.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`critical_section`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ConcRT. h

**Namespace:** simultaneidade

## <a name="critical_section"></a><a name="ctor"></a>critical_section

Constrói uma nova seção crítica.

```cpp
critical_section();
```

## <a name="critical_section"></a><a name="dtor"></a>~ critical_section

Destrói uma seção crítica.

```cpp
~critical_section();
```

### <a name="remarks"></a>Comentários

Espera-se que o bloqueio não seja mais mantido quando o destruidor for executado. Permitir que a seção crítica seja destruida com o bloqueio ainda resulta em um comportamento indefinido.

## <a name="lock"></a><a name="lock"></a>proprietário

Adquire essa seção crítica.

```cpp
void lock();
```

### <a name="remarks"></a>Comentários

Geralmente, é mais seguro utilizar a construção [scoped_lock](#critical_section__scoped_lock_class) para adquirir e liberar um `critical_section` objeto de uma forma segura de exceção.

Se o bloqueio já estiver sendo mantido pelo contexto de chamada, uma exceção de [improper_lock](improper-lock-class.md) será lançada.

## <a name="native_handle"></a><a name="native_handle"></a>native_handle

Retorna um identificador nativo específico da plataforma, se houver.

```cpp
native_handle_type native_handle();
```

### <a name="return-value"></a>Valor retornado

Uma referência à seção crítica.

### <a name="remarks"></a>Comentários

Um `critical_section` objeto não está associado a um identificador nativo específico da plataforma para o sistema operacional Windows. O método simplesmente retorna uma referência ao próprio objeto.

## <a name="critical_sectionscoped_lock-class"></a><a name="critical_section__scoped_lock_class"></a>Classe critical_section:: scoped_lock

Um wrapper RAII de exceção seguro para um `critical_section` objeto.

```cpp
class scoped_lock;
```

## <a name="scoped_lockscoped_lock"></a><a name="critical_section__scoped_lock_ctor"></a>scoped_lock:: scoped_lock

Constrói um `scoped_lock` objeto e adquire o `critical_section` objeto passado no `_Critical_section` parâmetro. Se a seção crítica for mantida por outro thread, essa chamada será bloqueada.

```cpp
explicit _CRTIMP scoped_lock(critical_section& _Critical_section);
```

### <a name="parameters"></a>parâmetros

*_Critical_section*<br/>
A seção crítica a ser bloqueada.

## <a name="scoped_lockscoped_lock"></a><a name="critical_section__scoped_lock_dtor"></a>scoped_lock:: ~ scoped_lock

Destrói um `scoped_lock` objeto e libera a seção crítica fornecida em seu construtor.

```cpp
~scoped_lock();
```

## <a name="try_lock"></a><a name="try_lock"></a>try_lock

Tenta adquirir o bloqueio sem bloqueio.

```cpp
bool try_lock();
```

### <a name="return-value"></a>Valor retornado

Se o bloqueio foi adquirido, o valor **`true`** ; caso contrário, o valor **`false`** .

## <a name="try_lock_for"></a><a name="try_lock_for"></a>try_lock_for

Tenta adquirir o bloqueio sem bloqueio para um número específico de milissegundos.

```cpp
bool try_lock_for(unsigned int _Timeout);
```

### <a name="parameters"></a>parâmetros

*_Timeout*<br/>
O número de milissegundos a aguardar antes de atingir o tempo limite.

### <a name="return-value"></a>Valor retornado

Se o bloqueio foi adquirido, o valor **`true`** ; caso contrário, o valor **`false`** .

## <a name="unlock"></a><a name="unlock"></a>automático

Desbloqueia a seção crítica.

```cpp
void unlock();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe reader_writer_lock](reader-writer-lock-class.md)
