---
title: "Compilador aviso (nível 3) C4635 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4635
dev_langs:
- C++
helpviewer_keywords:
- C4635
ms.assetid: b2ba90de-c093-4a76-8076-b65878467574
caps.latest.revision: 8
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
ms.openlocfilehash: a1ebd34ab1eff78dc731eb963554afb07119cd58
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4635"></a>Compilador C4635 de aviso (nível 3)
Destino de comentário de documento XML: incorreta de XML: motivo  
  
 O compilador encontrar algum problema com as marcas XML.  Corrigir o problema e recompile  
  
 O exemplo a seguir gera C4635:  
  
```  
// C4635.cpp  
// compile with: /doc /clr /W3 /c  
/// <summary>     
/// The contents of the folder have changed.  
/// <summary/>   // C4635  
  
// try the following line instead  
// /// </summary>  
public ref class Test {};  
```  
  
 Observe que a saída deste exemplo diz: **marca final 'member' não coincide com a marca de início 'Resumo'.**  
  
 O problema com este exemplo é que a marca de fim \<resumo > está incorreta, e o compilador não reconhecê-lo como o \<resumo > marca de fim.  O \<membro > marca é inserida no arquivo .xdc pelo compilador em cada compilação /doc.  Portanto, o problema aqui é que a marca de fim \</member >, não coincide com a marca de início anterior, o compilador processado (\<resumo >.
