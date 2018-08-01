---
title: Instruções compostas (blocos) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c85de0f147d0cfed873a091d17c46e56bf5758a9
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39408791"
---
# <a name="compound-statements-blocks"></a>Instruções compostas (blocos)
Uma instrução composta consiste em zero ou mais instruções entre chaves (**{}**). Uma instrução composta pode ser usada em qualquer lugar em que uma instrução é esperada. As instruções compostas são comumente chamadas de "blocos".  
  
## <a name="syntax"></a>Sintaxe  
  
```  
{ [ statement-list ] }  
```  
  
## <a name="remarks"></a>Comentários  
 O exemplo a seguir usa uma instrução composta, como o *instrução* fazem parte do **se** instrução (consulte [if instrução](../cpp/if-else-statement-cpp.md) para obter detalhes sobre a sintaxe):  
  
```cpp 
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
>  Como uma declaração de uma instrução, uma declaração pode ser uma das instruções na *lista de instruções*. Portanto, os nomes declarados em uma instrução composta, mas não declarados explicitamente como estáticos, têm escopo e vida útil locais (para objetos). Ver [escopo](../cpp/scope-visual-cpp.md) para obter detalhes sobre o tratamento de nomes com escopo local.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral das instruções C++](../cpp/overview-of-cpp-statements.md)