---
title: "Função strerror | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- strerror function
ms.assetid: 9fb9366e-d9a8-47d4-ad51-d98774a0617f
caps.latest.revision: 6
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 1a0fcfd69e453c1b39fce0ad6ac59b660315d4bb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="strerror-function"></a>Função strerror
**ANSI 4.11.6.2** O conteúdo das cadeias de caracteres da mensagem de erro retornada pela `strerror` função  
  
 A função `strerror` gera essas mensagens:  
  
```  
0   Error 0  
1    
2   No such file or directory  
3    
4    
5    
6    
7   Arg list too long  
8   Exec format error  
9   Bad file number  
10    
11    
12  Not enough core  
13  Permission denied  
14    
15    
16    
17  File exists  
18  Cross-device link  
19    
20    
21    
22  Invalid argument  
23    
24  Too many open files  
25    
26    
27    
28  No space left on device  
29    
30    
31    
32    
33  Math argument  
34  Result too large  
35    
36  Resource deadlock would occur  
```  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)
