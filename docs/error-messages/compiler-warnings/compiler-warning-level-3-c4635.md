---
title: Compilador aviso (nível 3) C4635 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4635
dev_langs:
- C++
helpviewer_keywords:
- C4635
ms.assetid: b2ba90de-c093-4a76-8076-b65878467574
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7651012d4c48d420734a9c6ec2ff051718f82007
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46038107"
---
# <a name="compiler-warning-level-3-c4635"></a>Compilador aviso (nível 3) C4635

Destino de comentário de documento XML:-XML malformado: motivo

O compilador encontrar algum problema com as marcas XML.  Corrigir o problema e recompile

O exemplo a seguir gera C4635:

```
// C4635.cpp
// compile with: /doc /clr /W3 /c
/// <summary>
/// The contents of the folder have changed.
/// <summary/>   // C4635

// try the following line instead
// /// </summary>
public ref class Test {};
```

Observe que a saída deste exemplo diz: **marca final 'member' não coincide com a marca de início 'Resumo'.**

O problema com este exemplo é que a marca de fim \<summary > está mal formado, e o compilador não reconhecê-lo como o \<resumo > marca de fim.  O \<membro > marca será inserida no arquivo. XDC pelo compilador em cada compilação /doc.  Portanto, o problema aqui é que a marca de fim \</member >, não coincide com a marca de início anterior que o compilador processado (\<resumo >.