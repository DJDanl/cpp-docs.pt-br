---
title: jitintrinsic | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- jitintrinsic
- jitintrinsic_cpp
dev_langs: C++
helpviewer_keywords:
- __declspec keyword [C++], jitintrinsic
- jitintrinsic __declspec modifier
ms.assetid: 23dbe416-7ef6-442b-b16d-9a81aab04fa6
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 451f9e534284a2daa69ddc11495f6ecc8af1ee13
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="jitintrinsic"></a>jitintrinsic
Marca a função como significante para o Common Language Runtime de 64 bits. Isso é usado em determinadas funções em bibliotecas fornecidas pela Microsoft.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__declspec(jitintrinsic)  
```  
  
## <a name="remarks"></a>Comentários  
 `jitintrinsic` adiciona um MODOPT (<xref:System.Runtime.CompilerServices.IsJitIntrinsic>) a uma assinatura de função.  
  
 Não é aconselhável que os usuários usem esse modificador `__declspec`, porque resultados inesperados podem ocorrer.  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)