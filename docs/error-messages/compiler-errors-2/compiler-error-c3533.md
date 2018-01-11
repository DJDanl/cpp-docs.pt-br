---
title: C3533 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3533
dev_langs: C++
helpviewer_keywords: C3533
ms.assetid: a68b1ba5-466e-4190-a1a4-505ccfe548b7
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e7bcd9c710ac5cdd50b966a72291918459d984be
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3533"></a>C3533 de erro do compilador
'type': um parâmetro não pode ter um tipo que contém 'auto'  
  
 Um parâmetro de método ou o modelo não pode ser declarado com a `auto` palavra-chave se o padrão [/ZC: auto](../../build/reference/zc-auto-deduce-variable-type.md) opção de compilador está em vigor.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Remover o `auto` palavra-chave da declaração de parâmetro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3535 porque ele declara um parâmetro de função com o `auto` palavra-chave e ele é compilado com **/ZC: auto**.  
  
```  
// C3533a.cpp  
// Compile with /Zc:auto  
void f(auto j){} // C3533  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3535 porque ele declara um parâmetro de modelo com o `auto` palavra-chave e ele é compilado com **/ZC: auto**.  
  
```  
// C3533b.cpp  
// Compile with /Zc:auto  
template<auto T> class C{}; // C3533  
```  
  
## <a name="see-also"></a>Consulte também  
 [palavra-chave auto](../../cpp/auto-keyword.md)   
 [/ZC: auto (deduzir tipo variável)](../../build/reference/zc-auto-deduce-variable-type.md)