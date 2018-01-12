---
title: C3888 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3888
dev_langs: C++
helpviewer_keywords: C3888
ms.assetid: 40820812-79c5-4dcd-a19d-b4164d25fc8a
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e6f0310324afcbde112623959c4dc3b11155fed1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3888"></a>C3888 de erro do compilador
'name': a expressão const associada a este membro de dados literal não é suportado pelo C + + CLI  
  
 O *nome* membro de dados que é declarado com o [literal](../../windows/literal-cpp-component-extensions.md) palavra-chave é inicializada com um valor que o compilador não oferece suporte. O compilador suporta apenas constante integral, enum ou tipos de cadeia de caracteres. A causa mais provável para o **C3888** erro é que o membro de dados é inicializado com uma matriz de bytes.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Verifique se o membro de dados literal declarado é um tipo com suporte.  
  
## <a name="see-also"></a>Consulte também  
 [literal](../../windows/literal-cpp-component-extensions.md)