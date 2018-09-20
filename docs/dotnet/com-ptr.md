---
title: 'com:: PTR | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- ptr
dev_langs:
- C++
helpviewer_keywords:
- com::ptr
ms.assetid: ee302e3c-8fed-4875-a372-2e55003718d3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f5e6a3f7936e21d22282fe37a29b5d91f2e50caa
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46434486"
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