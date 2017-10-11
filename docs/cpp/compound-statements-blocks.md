---
title: "Instruções compostas (blocos) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- '}'
- '{'
dev_langs:
- C++
helpviewer_keywords:
- blocks, about blocks
- compound statements
ms.assetid: 23855939-7430-498e-8936-0c70055ea701
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 9dc28fde0ab2cf5b21771347554d0c664b7f462d
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="compound-statements-blocks"></a>Instruções compostas (blocos)
Uma instrução composta consiste em zero ou mais instruções entre chaves (**{}**). Uma instrução composta pode ser usada em qualquer lugar em que uma instrução é esperada. As instruções compostas são comumente chamadas de "blocos".  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
{ [ statement-list ] }  
```  
  
## <a name="remarks"></a>Comentários  
 O exemplo a seguir usa uma instrução composta como o *instrução* parte do **se** instrução (consulte [if instrução](../cpp/if-else-statement-cpp.md) para obter detalhes sobre a sintaxe):  
  
```  
if( Amount > 100 )  
{  
    cout << "Amount was too large to handle\n";  
    Alert();  
}  
else  
{
    Balance -= Amount;  
}
```  
  
> [!NOTE]
>  Como uma declaração de uma instrução, uma declaração pode ser uma das instruções no *lista de instruções*. Portanto, os nomes declarados em uma instrução composta, mas não declarados explicitamente como estáticos, têm escopo e vida útil locais (para objetos). Consulte [escopo](../cpp/scope-visual-cpp.md) para obter detalhes sobre o tratamento de nomes com escopo local.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)
