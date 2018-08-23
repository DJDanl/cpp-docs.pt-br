---
title: Mutex Class1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Mutex
dev_langs:
- C++
helpviewer_keywords:
- Mutex class
ms.assetid: 682a0963-721c-46a2-8871-000e9997505b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b20c270f7848a346d717357f474d89e37ea117a4
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42600022"
---
# <a name="mutex-class1"></a>mutex Class1

Representa um objeto de sincronização que controla exclusivamente um recurso compartilhado.

## <a name="syntax"></a>Sintaxe

```cpp
class Mutex : public HandleT<HandleTraits::MutexTraits>
```

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`SyncLock`|Um sinônimo para uma classe que dá suporte a bloqueios síncronos.|

### <a name="public-constructor"></a>Construtor público

|Nome|Descrição|
|----------|-----------------|
|[Construtor Mutex::Mutex](../windows/mutex-mutex-constructor.md)|Inicializa uma nova instância dos **Mutex** classe.|

### <a name="public-members"></a>Membros públicos

|Nome|Descrição|
|----------|-----------------|
|[Método Mutex::Lock](../windows/mutex-lock-method.md)|Aguarda até que o objeto atual, ou o **Mutex** objeto associado ao identificador especificado, versões mutex ou o intervalo de tempo limite especificado tiver decorrido.|

### <a name="public-operator"></a>Operador público

|Nome|Descrição|
|----------|-----------------|
|[Operador Mutex::operator=](../windows/mutex-operator-assign-operator.md)|Atribui (se move) especificado **Mutex** objeto atual **Mutex** objeto.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Mutex`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)