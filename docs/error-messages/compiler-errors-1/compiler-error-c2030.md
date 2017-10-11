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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: a2efd868160e3ec7e5bf356603cc821a0b07f149
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2030"></a>Erro do Compilador C2030
um destruidor com acessibilidade 'privada protegida' não pode ser um membro de uma classe declarada 'lacrada'  
  
 Uma classe de tempo de execução do Windows é declarado como `sealed` não pode ter um destruidor privado e protegido. Somente públicas destruidores não virtual privados e virtuais são permitidas em tipos lacrados. Para obter mais informações, consulte [classes e estruturas Ref](../../cppcx/ref-classes-and-structs-c-cx.md).  
  
 Para corrigir esse erro, altere a acessibilidade do destruidor.
