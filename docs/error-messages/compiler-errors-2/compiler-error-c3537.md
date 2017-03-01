---
title: C3537 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3537
dev_langs:
- C++
helpviewer_keywords:
- C3537
ms.assetid: f537ebd1-4fb0-4e09-a453-4f38db2c6881
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8dcc58d8a5f6702740eda805c7e48e60a7512b3c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3537"></a>C3537 de erro do compilador
'type': não pode ser convertido em um tipo que contém 'auto'  
  
 Você não pode converter uma variável para o tipo indicado porque o tipo contém o `auto` palavra-chave e o padrão [/ZC: auto](../../build/reference/zc-auto-deduce-variable-type.md) opção de compilador está em vigor.  
  
## <a name="example"></a>Exemplo  
 O código a seguir produz C3537 porque as variáveis são convertidas em um tipo que contém o `auto` palavra-chave.  
  
```  
// C3537.cpp  
// Compile with /Zc:auto  
int main()  
{  
   int value = 123;  
   auto(value);                        // C3537  
   (auto)value;                        // C3537  
   auto x1 = auto(value);              // C3537  
   auto x2 = (auto)value;              // C3537  
   auto x3 = static_cast<auto>(value); // C3537  
   return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [palavra-chave auto](../../cpp/auto-keyword.md)
