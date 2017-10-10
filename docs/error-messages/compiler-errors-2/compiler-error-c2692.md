---
title: C2692 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2692
dev_langs:
- C++
helpviewer_keywords:
- C2692
ms.assetid: 02ade3b4-b757-448b-b065-d7d71bc3f441
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6e65c0310dfd82f86b49193fb173bb483fbd4333
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2692"></a>C2692 de erro do compilador
'function_name': funções totalmente prototipadas são necessárias no compilador C com o ' / clr' opção  
  
 Quando estiver compilando para .NET de código gerenciado, o compilador C requer declarações de função de ANSI. Além disso, se uma função não usa nenhum parâmetro, ele deve declarar explicitamente `void` como o tipo de parâmetro.
