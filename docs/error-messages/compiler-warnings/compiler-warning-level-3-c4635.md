---
title: Aviso do compilador (nível 3) C4635
ms.date: 11/04/2016
f1_keywords:
- C4635
helpviewer_keywords:
- C4635
ms.assetid: b2ba90de-c093-4a76-8076-b65878467574
ms.openlocfilehash: b6fd45dc6c28c0d12eb2b2991f8a087b1841d1a9
ms.sourcegitcommit: 217fac22604639ebd62d366a69e6071ad5b724ac
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/19/2019
ms.locfileid: "74189141"
---
# <a name="compiler-warning-level-3-c4635"></a>Aviso do compilador (nível 3) C4635

Destino de comentário de documento XML: XML com formato incorreto: motivo

O compilador encontrou algum problema com as marcas XML.  Corrigir o problema e recompilar

O exemplo a seguir gera C4635:

```cpp
// C4635.cpp
// compile with: /doc /clr /W3 /c
/// <summary>
/// The contents of the folder have changed.
/// <summary/>   // C4635

// try the following line instead
// /// </summary>
public ref class Test {};
```

Observe que a saída para este exemplo diz: **a marca de fim ' member ' não corresponde à marca de início ' summary '.**

O problema com esse exemplo é que a marca de fim para \<Resumo > é mal formada, e o compilador não o reconhece como a \<Resumo > marca de fim.  A marca de > de membro \<é inserida no arquivo. xdc pelo compilador em cada compilação/doc.  Portanto, o problema aqui é que a marca final \</member >, não corresponde à marca de início anterior que o compilador processou (\<Resumo >.