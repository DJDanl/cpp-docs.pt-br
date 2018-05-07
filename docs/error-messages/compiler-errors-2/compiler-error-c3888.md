---
title: C3888 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3888
dev_langs:
- C++
helpviewer_keywords:
- C3888
ms.assetid: 40820812-79c5-4dcd-a19d-b4164d25fc8a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c11c897f35a6c395c4bc6ee6a64be51fa810911b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3888"></a>C3888 de erro do compilador
'name': a expressão const associada a este membro de dados literal não é suportado pelo C + + CLI  
  
 O *nome* membro de dados que é declarado com o [literal](../../windows/literal-cpp-component-extensions.md) palavra-chave é inicializada com um valor que o compilador não oferece suporte. O compilador suporta apenas constante integral, enum ou tipos de cadeia de caracteres. A causa mais provável para o **C3888** erro é que o membro de dados é inicializado com uma matriz de bytes.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Verifique se o membro de dados literal declarado é um tipo com suporte.  
  
## <a name="see-also"></a>Consulte também  
 [Literal](../../windows/literal-cpp-component-extensions.md)