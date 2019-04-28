---
title: Compilador aviso (nível 1) C4910
ms.date: 11/04/2016
helpviewer_keywords:
- C4910
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
ms.openlocfilehash: 49cbbf3369fc4765d93e67e2dca84a4d975560d7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62242877"
---
# <a name="compiler-warning-level-1-c4910"></a>Compilador aviso (nível 1) C4910

'\<identificador >': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita

A instanciação de modelo explícitos denominada  *\<identificador >* for modificado por ambos os `__declspec(dllexport)` e `extern` palavras-chave. No entanto, essas palavras-chave é mutuamente exclusivos. O `__declspec(dllexport)` palavra-chave significa criar uma instância da classe de modelo, enquanto o `extern` significa que a palavra-chave não é instanciado automaticamente a classe de modelo.

## <a name="see-also"></a>Consulte também

[Instanciação explícita](../../cpp/explicit-instantiation.md)<br/>
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)<br/>
[Regras e limitações gerais](../../cpp/general-rules-and-limitations.md)