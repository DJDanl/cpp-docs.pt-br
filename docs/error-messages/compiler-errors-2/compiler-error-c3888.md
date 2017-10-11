---
title: C3888 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 26e55c8a675ada3fd2e88976bc9d9a51cfa8b751
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3888"></a>C3888 de erro do compilador
'name': a expressão const associada a este membro de dados literal não é suportado pelo C + + CLI  
  
 O *nome* membro de dados que é declarado com o [literal](../../windows/literal-cpp-component-extensions.md) palavra-chave é inicializada com um valor que o compilador não oferece suporte. O compilador suporta apenas constante integral, enum ou tipos de cadeia de caracteres. A causa mais provável para o **C3888** erro é que o membro de dados é inicializado com uma matriz de bytes.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Verifique se o membro de dados literal declarado é um tipo com suporte.  
  
## <a name="see-also"></a>Consulte também  
 [literal](../../windows/literal-cpp-component-extensions.md)
