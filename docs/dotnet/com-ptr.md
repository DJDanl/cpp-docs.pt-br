---
title: com::ptr
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- ptr
helpviewer_keywords:
- com::ptr
ms.assetid: ee302e3c-8fed-4875-a372-2e55003718d3
ms.openlocfilehash: 9bcfe00bd41d57542116f786f28df19d12c68b65
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50664575"
---
# <a name="comptr"></a>com::ptr

Um wrapper para um objeto COM que pode ser usado como um membro de uma classe CLR. O wrapper também automatiza o gerenciamento de tempo de vida do objeto COM, liberando referências de propriedade no objeto quando seu destruidor é chamado. Análogo à [classe CComPtr](../atl/reference/ccomptr-class.md).

## <a name="syntax"></a>Sintaxe

```
#include <msclr\com\ptr.h>
```

## <a name="remarks"></a>Comentários

[com:: PTR classe](../dotnet/com-ptr-class.md) é definido no \<msclr\com\ptr.h > arquivo.

## <a name="see-also"></a>Consulte também

[Biblioteca de suporte do C++](../dotnet/cpp-support-library.md)