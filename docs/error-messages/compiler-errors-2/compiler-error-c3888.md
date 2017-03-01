---
title: C3888 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3888
dev_langs:
- C++
helpviewer_keywords:
- C3888
ms.assetid: 40820812-79c5-4dcd-a19d-b4164d25fc8a
caps.latest.revision: 3
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
ms.openlocfilehash: 4c35d218b42d7a618d05014cd90032e62bf2a227
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3888"></a>C3888 de erro do compilador
'name': não há suporte para a expressão constante associada a este membro de dados literais pelo C + + / CLI  
  
 O *nome* membro de dados que é declarado com o [literal](../../windows/literal-cpp-component-extensions.md) palavra-chave é inicializada com um valor que o compilador não oferece suporte. O compilador suporta apenas constante integral, enum ou tipos de cadeia de caracteres. A causa provável para o **C3888** erro é que o membro de dados é inicializado com uma matriz de bytes.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Verifique se o membro de dados literais declarada é um tipo com suporte.  
  
## <a name="see-also"></a>Consulte também  
 [literal](../../windows/literal-cpp-component-extensions.md)
