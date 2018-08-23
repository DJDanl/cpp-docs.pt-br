---
title: Classe SRWLock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::SRWLock
dev_langs:
- C++
helpviewer_keywords:
- SRWLock class
ms.assetid: 4fa250e3-5f29-4b06-ac24-61b6c04ade93
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fb97a29796c287cfaadddc305f25807de5dcba2e
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42604230"
---
# <a name="srwlock-class"></a>Classe SRWLock

Representa um bloqueio de leitor/gravador reduzido.

## <a name="syntax"></a>Sintaxe

```cpp
class SRWLock;
```

## <a name="remarks"></a>Comentários

Um bloqueio de leitor/gravador reduzido é usado para sincronizar o acesso entre threads para um objeto ou recurso. Para obter mais informações, consulte [funções de sincronização](/windows/desktop/Sync/synchronization-functions).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|||
|-|-|
|`SyncLockExclusive`|Sinônimo de um **SRWLock** objeto que é adquirido em modo exclusivo.|
|`SyncLockShared`|Sinônimo de um **SRWLock** objeto que é adquirido no modo compartilhado.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor SRWLock::SRWLock](../windows/srwlock-srwlock-constructor.md)|Inicializa uma nova instância dos **SRWLock** classe.|
|[Destruidor SRWLock::~SRWLock](../windows/srwlock-tilde-srwlock-destructor.md)|Realiza o desligamento de uma instância das **SRWLock** classe.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método SRWLock::LockExclusive](../windows/srwlock-lockexclusive-method.md)|Adquire uma **SRWLock** objeto no modo exclusivo.|
|[Método SRWLock::LockShared](../windows/srwlock-lockshared-method.md)|Adquire uma **SRWLock** objeto no modo compartilhado.|
|[Método SRWLock::TryLockExclusive](../windows/srwlock-trylockexclusive-method.md)|Tenta adquirir um **SRWLock** objeto no modo exclusivo para o atual ou especificada **SRWLock** objeto.|
|[Método SRWLock::TryLockShared](../windows/srwlock-trylockshared-method.md)|Tenta adquirir um **SRWLock** objeto no modo compartilhado para o atual ou especificada **SRWLock** objeto.|

### <a name="protected-data-member"></a>Membro de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[Membro de dados SRWLock::SRWLock_](../windows/srwlock-srwlock-data-member.md)|Contém a variável subjacente de bloqueio atual **SRWLock** objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`SRWLock`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)