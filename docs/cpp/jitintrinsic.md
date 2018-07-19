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
ms.openlocfilehash: f8b1c932f53651b8ad116139724348714b183506
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939384"
---
# <a name="jitintrinsic"></a>jitintrinsic
Marca a função como significante para o Common Language Runtime de 64 bits. Isso é usado em determinadas funções em bibliotecas fornecidas pela Microsoft.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__declspec(jitintrinsic)  
```  
  
## <a name="remarks"></a>Comentários  
 `jitintrinsic` adiciona um MODOPT (<xref:System.Runtime.CompilerServices.IsJitIntrinsic>) a uma assinatura de função.  
  
 Os usuários não devem usar isso **declspec** modificador, como resultados inesperados pode ocorrer.  
  
## <a name="see-also"></a>Consulte também  
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)