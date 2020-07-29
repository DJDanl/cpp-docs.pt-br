---
title: jitintrinsic
ms.date: 11/04/2016
f1_keywords:
- jitintrinsic
- jitintrinsic_cpp
helpviewer_keywords:
- __declspec keyword [C++], jitintrinsic
- jitintrinsic __declspec modifier
ms.assetid: 23dbe416-7ef6-442b-b16d-9a81aab04fa6
ms.openlocfilehash: cecadcad15ee65a44ad5a8245efdb69903c89459
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233698"
---
# <a name="jitintrinsic"></a>jitintrinsic

Marca a função como significante para o Common Language Runtime de 64 bits. Isso é usado em determinadas funções em bibliotecas fornecidas pela Microsoft.

## <a name="syntax"></a>Sintaxe

```
__declspec(jitintrinsic)
```

## <a name="remarks"></a>Comentários

**`jitintrinsic`** Adiciona um MODOPT ( <xref:System.Runtime.CompilerServices.IsJitIntrinsic> ) a uma assinatura de função.

Os usuários são desencorajados de usar esse **`__declspec`** modificador, pois podem ocorrer resultados inesperados.

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
