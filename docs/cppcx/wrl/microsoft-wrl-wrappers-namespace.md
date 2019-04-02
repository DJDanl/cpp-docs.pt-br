---
title: Namespace Microsoft::WRL::Wrappers
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers
helpviewer_keywords:
- Wrappers namespace
ms.assetid: 36ac38c7-1fc3-42da-a879-5c68661dc9e1
ms.openlocfilehash: 953318e09c4c0d00748f2b6189615dbd66677a96
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783802"
---
# <a name="microsoftwrlwrappers-namespace"></a>Namespace Microsoft::WRL::Wrappers

Define os tipos de wrapper de recurso aquisição é a inicialização (RAII) que simplificam o gerenciamento de tempo de vida de objetos, cadeias de caracteres e identificadores.

## <a name="syntax"></a>Sintaxe

```cpp
namespace Microsoft::WRL::Wrappers;
```

## <a name="members"></a>Membros

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|----------|-----------------|
|`FileHandle`|`HandleT<HandleTraits::FileHandleTraits>`|

### <a name="classes"></a>Classes

|Nome|Descrição|
|----------|-----------------|
|[Classe CriticalSection](criticalsection-class.md)|Representa um objeto de seção crítica.|
|[Classe de evento (WRL)](event-class-wrl.md)|Representa um evento.|
|[Classe HandleT](handlet-class.md)|Representa um identificador para um objeto.|
|[Classe HString](hstring-class.md)|Fornece suporte para manipular identificadores de HSTRING.|
|[Classe HStringReference](hstringreference-class.md)|Representa um HSTRING que é criado a partir de uma cadeia de caracteres existente.|
|[Classe Mutex](mutex-class.md)|Representa um objeto de sincronização que controla exclusivamente um recurso compartilhado.|
|[Classe RoInitializeWrapper](roinitializewrapper-class.md)|Inicializa o tempo de execução do Windows.|
|[Classe Semaphore](semaphore-class.md)|Representa um objeto de sincronização que controla um recurso compartilhado que pode dar suporte a um número limitado de usuários.|
|[Classe SRWLock](srwlock-class.md)|Representa um bloqueio de leitor/gravador reduzido.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)