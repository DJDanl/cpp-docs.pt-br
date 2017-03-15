---
title: C2696 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2696
dev_langs:
- C++
helpviewer_keywords:
- C2696
ms.assetid: 6c6eb7df-1230-4346-9a73-abf14c20785d
caps.latest.revision: 12
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
translationtype: Machine Translation
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: 08b8a7990efbf981aec342b99bbb558fd9fab8d5
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2696"></a>C2696 de erro do compilador
Não é possível criar um objeto temporário de um tipo gerenciado 'type'  
  
As referências a `const` em um programa gerenciado com que o compilador chama o construtor e criar um objeto temporário na pilha. No entanto, uma classe gerenciada nunca pode ser criada na pilha.  
  
C2696 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  

