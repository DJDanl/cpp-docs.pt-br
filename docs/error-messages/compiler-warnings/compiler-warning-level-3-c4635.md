---
title: "Compilador aviso (nível 3) C4635 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4635
dev_langs:
- C++
helpviewer_keywords:
- C4635
ms.assetid: b2ba90de-c093-4a76-8076-b65878467574
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 16b6a19618afeed952cfa594961a0e4ccb777d26
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4635"></a>Compilador C4635 de aviso (nível 3)
Destino de comentário de documento XML: incorreta de XML: motivo  
  
 O compilador encontrar algum problema com as marcas XML.  Corrija o problema e recompile  
  
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
  
 Observe que a saída para este exemplo diz: **marca final 'member' não coincide com a marca de início 'Resumo'.**  
  
 O problema com este exemplo é que a marca de fim \<resumo > está incorreta, e o compilador não reconhecê-lo como o \<resumo > marca de fim.  O \<membro > marca é inserida no arquivo. XDC pelo compilador em cada compilação /doc.  Portanto, o problema aqui é que a marca de fim \</member >, não coincide com a marca de início anterior, o compilador processado (\<resumo >.