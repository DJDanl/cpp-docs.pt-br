---
title: Compilador aviso (nível 1) C4910 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- C4910
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5e6db959e467ea449a66feb3ee07c202f4dee002
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46018945"
---
# <a name="compiler-warning-level-1-c4910"></a>Compilador aviso (nível 1) C4910

'\<identificador >': 'dllexport' e 'extern' são incompatíveis em uma instanciação explícita

A instanciação de modelo explícitos denominada  *\<identificador >* for modificado por ambos os `__declspec(dllexport)` e `extern` palavras-chave. No entanto, essas palavras-chave é mutuamente exclusivos. O `__declspec(dllexport)` palavra-chave significa criar uma instância da classe de modelo, enquanto o `extern` significa que a palavra-chave não é instanciado automaticamente a classe de modelo.

## <a name="see-also"></a>Consulte também

[Instanciação explícita](../../cpp/explicit-instantiation.md)<br/>
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)<br/>
[Regras e limitações gerais](../../cpp/general-rules-and-limitations.md)