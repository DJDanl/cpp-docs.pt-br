---
title: Erro do compilador C2030 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2030
dev_langs:
- C++
helpviewer_keywords:
- C2030
ms.assetid: 5806cead-64df-4eff-92de-52c9a3f5ee62
caps.latest.revision: 7
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 128bd124c2536d86c8b673b54abc4b5505526b41
ms.openlocfilehash: c76a4fc5de139c2cc9f6802fc66526f291b862a2
ms.contentlocale: pt-br
ms.lasthandoff: 05/10/2017

---
# <a name="compiler-error-c2030"></a>Erro do Compilador C2030
um destruidor com acessibilidade 'privada protegida' não pode ser membro de uma classe declarada 'lacrada'  
  
 Uma classe de tempo de execução do Windows é declarado como `sealed` não pode ter um destruidor privado e protegido. Somente públicas destruidores não virtual privados e virtuais são permitidas em tipos lacrados. Para obter mais informações, consulte [classes e estruturas Ref](../../cppcx/ref-classes-and-structs-c-cx.md).  
  
 Para corrigir esse erro, altere a acessibilidade do destruidor.
