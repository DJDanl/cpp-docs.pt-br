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
ms.openlocfilehash: 9e726413f0bbfbd9d6affa348777c995c51283a5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62245501"
---
# <a name="jitintrinsic"></a>jitintrinsic

Marca a função como significante para o Common Language Runtime de 64 bits. Isso é usado em determinadas funções em bibliotecas fornecidas pela Microsoft.

## <a name="syntax"></a>Sintaxe

```
__declspec(jitintrinsic)
```

## <a name="remarks"></a>Comentários

**jitintrinsic** adiciona um MODOPT (<xref:System.Runtime.CompilerServices.IsJitIntrinsic>) para uma assinatura de função.

Os usuários não devem usar isso **declspec** modificador, como resultados inesperados pode ocorrer.

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)