---
title: "Compilador aviso (nível 1) C4678 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4678
dev_langs:
- C++
helpviewer_keywords:
- C4678
ms.assetid: 0c588f34-595d-4e5c-9470-8723fca2cc06
caps.latest.revision: 10
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: d35e60d60d194bc0ca68a116dc45b6d9864d9fe2
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4678"></a>Compilador C4678 de aviso (nível 1)
classe base 'base_type' é menos acessível que 'derived_type'  
  
Um tipo público deriva de um tipo particular. Se o tipo de público é instanciado em um assembly referenciado, os membros do tipo base particular não estarão acessíveis.  
  
C4678 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**. É um erro ao usar **/clr**, para ter uma classe base que é menos acessível que a classe derivada.  

