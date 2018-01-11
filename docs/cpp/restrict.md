---
title: restringir | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: restrict_cpp
dev_langs: C++
helpviewer_keywords:
- __declspec keyword [C++], restrict
- restrict __declspec keyword
ms.assetid: f39cf632-68d8-4362-a497-2d4c15693689
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 24fa0dae15fb0d4dfab8d481c6626c7611295572
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="restrict"></a>restrict
**Seção específica da Microsoft**  
  
 Aplicado a uma declaração ou a uma definição de função que retorna um tipo de ponteiro e diz ao compilador que a função retorna um objeto sem alias com nenhum outro ponteiro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__declspec(restrict) return_type f();  
```  
  
## <a name="remarks"></a>Comentários  
 O compilador propagará `__declspec(restrict)`. Por exemplo, a função de CRT `malloc` é decorada com `__declspec(restrict)` e, como consequência, os ponteiros inicializados para locais de memória com `malloc` também são pressupostos como sem alias.  
  
 O compilador não verifica se o ponteiro realmente não possui alias. É responsabilidade do desenvolvedor assegurar que o programa não coloque alias em um ponteiro com o modificador `restrict __declspec`.  
  
 Para uma semântica semelhante em variáveis, consulte [Restrict](../cpp/extension-restrict.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [noalias](../cpp/noalias.md) para um exemplo usando `restrict`.  
  
 Para obter informações sobre a palavra-chave restrict que faz parte do C++ AMP, consulte [restrict (C++ AMP)](../cpp/restrict-cpp-amp.md).  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)