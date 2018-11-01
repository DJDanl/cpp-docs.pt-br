---
title: Compilador aviso (nível 1) C4910
ms.date: 11/04/2016
helpviewer_keywords:
- C4910
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
ms.openlocfilehash: f0d1df0a383b6646d52fc2babc53ca656d49ace6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50428191"
---
# <a name="compiler-warning-level-1-c4910"></a>Compilador aviso (nível 1) C4910

'\<identificador >': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita

A instanciação de modelo explícitos denominada  *\<identificador >* for modificado por ambos os `__declspec(dllexport)` e `extern` palavras-chave. No entanto, essas palavras-chave é mutuamente exclusivos. O `__declspec(dllexport)` palavra-chave significa criar uma instância da classe de modelo, enquanto o `extern` significa que a palavra-chave não é instanciado automaticamente a classe de modelo.

## <a name="see-also"></a>Consulte também

[Instanciação explícita](../../cpp/explicit-instantiation.md)<br/>
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)<br/>
[Regras e limitações gerais](../../cpp/general-rules-and-limitations.md)