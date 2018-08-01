---
title: jitintrinsic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- jitintrinsic
- jitintrinsic_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], jitintrinsic
- jitintrinsic __declspec modifier
ms.assetid: 23dbe416-7ef6-442b-b16d-9a81aab04fa6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f0b114089567de06a71f15b69c556e08d1e4e9c6
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39404074"
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
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)