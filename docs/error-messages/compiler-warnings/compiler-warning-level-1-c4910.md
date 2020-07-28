---
title: Aviso do compilador (nível 1) C4910
ms.date: 11/04/2016
f1_keywords:
- C4910
helpviewer_keywords:
- C4910
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
ms.openlocfilehash: b17df9d7a9997e5d8ef37a4721de8693968cbbdf
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214445"
---
# <a name="compiler-warning-level-1-c4910"></a>Aviso do compilador (nível 1) C4910

' \<identifier> ': ' __declspec (dllexport) ' e ' extern ' são incompatíveis em uma instanciação explícita

A instanciação de modelo explícita denominada *\<identifier>* é modificada `__declspec(dllexport)` pelas **`extern`** palavras-chave e. No entanto, essas palavras-chave são mutuamente exclusivas. A `__declspec(dllexport)` palavra-chave significa instanciar a classe de modelo, enquanto a **`extern`** palavra-chave significa não instanciar automaticamente a classe de modelo.

## <a name="see-also"></a>Confira também

[Instanciação explícita](../../cpp/explicit-instantiation.md)<br/>
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)<br/>
[Regras e limitações gerais](../../cpp/general-rules-and-limitations.md)
