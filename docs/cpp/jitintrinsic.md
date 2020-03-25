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
ms.openlocfilehash: 4626ba82d1d24582951bbffd8e6be687007d390f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178166"
---
# <a name="jitintrinsic"></a>jitintrinsic

Marca a função como significante para o Common Language Runtime de 64 bits. Isso é usado em determinadas funções em bibliotecas fornecidas pela Microsoft.

## <a name="syntax"></a>Sintaxe

```
__declspec(jitintrinsic)
```

## <a name="remarks"></a>Comentários

**jitintrinsic** adiciona um MODOPT (<xref:System.Runtime.CompilerServices.IsJitIntrinsic>) a uma assinatura de função.

Os usuários são desencorajados de usar esse modificador de **__declspec** , pois podem ocorrer resultados inesperados.

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
