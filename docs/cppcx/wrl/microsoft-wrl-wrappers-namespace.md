---
title: Namespace Microsoft::WRL::Wrappers
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers
helpviewer_keywords:
- Wrappers namespace
ms.assetid: 36ac38c7-1fc3-42da-a879-5c68661dc9e1
ms.openlocfilehash: ece26b3f9928d44a593de830cf8a25c57e4c2d89
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213740"
---
# <a name="microsoftwrlwrappers-namespace"></a>Namespace Microsoft::WRL::Wrappers

Define a aquisição de recursos como tipos de wrapper de inicialização (RAII) que simplificam o gerenciamento do tempo de vida de objetos, cadeias de caracteres e identificadores.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Microsoft::WRL::Wrappers;
```

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`FileHandle`|`HandleT<HandleTraits::FileHandleTraits>`|

### <a name="classes"></a>Classes

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[Classe CriticalSection](criticalsection-class.md)|Representa um objeto de seção crítica.|
|[Classe de evento (WRL)](event-class-wrl.md)|Representa um evento.|
|[Classe HandleT](handlet-class.md)|Representa um identificador para um objeto.|
|[Classe HString](hstring-class.md)|Fornece suporte para manipular identificadores HSTRING.|
|[Classe HStringReference](hstringreference-class.md)|Representa um HSTRING que é criado a partir de uma cadeia de caracteres existente.|
|[Classe Mutex](mutex-class.md)|Representa um objeto de sincronização que controla exclusivamente um recurso compartilhado.|
|[Classe RoInitializeWrapper](roinitializewrapper-class.md)|Inicializa o Windows Runtime.|
|[Classe Semaphore](semaphore-class.md)|Representa um objeto de sincronização que controla um recurso compartilhado que pode dar suporte a um número limitado de usuários.|
|[Classe SRWLock](srwlock-class.md)|Representa um bloqueio de leitor/gravador reduzido.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft:: WRL:: wrappers

## <a name="see-also"></a>Confira também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)
