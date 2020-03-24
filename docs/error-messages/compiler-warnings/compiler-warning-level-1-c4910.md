---
title: Aviso do compilador (nível 1) C4910
ms.date: 11/04/2016
f1_keywords:
- C4910
helpviewer_keywords:
- C4910
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
ms.openlocfilehash: dc5feb3613e45134a08e493b397eb738fffee8a9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174772"
---
# <a name="compiler-warning-level-1-c4910"></a>Aviso do compilador (nível 1) C4910

'\<Identifier > ': ' __declspec (dllexport) ' e ' extern ' são incompatíveis em uma instanciação explícita

A instanciação de modelo explícita nomeada *\<identificador >* é modificada pelas palavras-chave `__declspec(dllexport)` e `extern`. No entanto, essas palavras-chave são mutuamente exclusivas. A palavra-chave `__declspec(dllexport)` significa instanciar a classe de modelo, enquanto a palavra-chave `extern` significa não instanciar automaticamente a classe de modelo.

## <a name="see-also"></a>Confira também

[Instanciação explícita](../../cpp/explicit-instantiation.md)<br/>
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)<br/>
[Regras e limitações gerais](../../cpp/general-rules-and-limitations.md)
