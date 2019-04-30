---
title: Compilador aviso (nível 3) C4635
ms.date: 11/04/2016
f1_keywords:
- C4635
helpviewer_keywords:
- C4635
ms.assetid: b2ba90de-c093-4a76-8076-b65878467574
ms.openlocfilehash: 21873a883b19924ce3ef41511d65f8ae640875f4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401716"
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

Observe que a saída deste exemplo diz: **End marca 'member' não coincide com a marca de início 'Resumo'.**

O problema com este exemplo é que a marca de fim \<summary > está mal formado, e o compilador não reconhecê-lo como o \<resumo > marca de fim.  O \<membro > marca será inserida no arquivo. XDC pelo compilador em cada compilação /doc.  Portanto, o problema aqui é que a marca de fim \</member >, não coincide com a marca de início anterior que o compilador processado (\<resumo >.