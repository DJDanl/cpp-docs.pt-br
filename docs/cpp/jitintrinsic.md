---
title: jitintrinsic | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
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
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 6712a62aaff0ff903117da87364cae5bc88580fd
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
