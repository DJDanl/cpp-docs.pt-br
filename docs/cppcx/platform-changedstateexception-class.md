---
title: Classe Platform::ChangedStateException
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::ChangedStateException
- VCCORLIB/Platform::ChangedStateException::ChangedStateException
helpviewer_keywords:
- Platform::ChangedStateException
ms.assetid: f894beac-9e80-4fac-ac25-89f1dbc0a6a4
ms.openlocfilehash: 749e242db37944f0c4dcbfb785028b01a0604f14
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50581673"
---
# <a name="platformchangedstateexception-class"></a>Classe Platform::ChangedStateException

Lançada quando o estado interno de um objeto é alterado, invalidando, assim, os resultados do método.

## <a name="syntax"></a>Sintaxe

```cpp
public ref class ChangedStateException : COMException,    IException,    IPrintable,    IEquatable
```

### <a name="remarks"></a>Comentários

Um exemplo de onde essa exceção é gerada é quando métodos de um iterador de coleção ou uma exibição de coleção são chamados após a alteração da coleção pai, invalidando os resultados do método.

Para obter mais informações, consulte a classe [COMException](../cppcx/platform-comexception-class.md) .

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Metadados:** platform.winmd

## <a name="see-also"></a>Consulte também

[Classe Platform::COMException](../cppcx/platform-comexception-class.md)