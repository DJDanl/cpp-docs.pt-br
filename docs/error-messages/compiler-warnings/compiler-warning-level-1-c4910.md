---
title: Aviso do compilador (nível 1) C4910
ms.date: 11/04/2016
f1_keywords:
- C4910
helpviewer_keywords:
- C4910
ms.assetid: 67963560-fbca-4ca7-93db-06beaf7055f0
ms.openlocfilehash: a3f29cb895da8c06ed43dd5c9956426f3f6014f1
ms.sourcegitcommit: 8762a3f9b5476b4dee03f0ee8064ea606550986e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/04/2019
ms.locfileid: "74810723"
---
# <a name="compiler-warning-level-1-c4910"></a>Aviso do compilador (nível 1) C4910

'\<Identifier > ': ' __declspec (dllexport) ' e ' extern ' são incompatíveis em uma instanciação explícita

A instanciação de modelo explícita nomeada *\<identificador >* é modificada pelas palavras-chave `__declspec(dllexport)` e `extern`. No entanto, essas palavras-chave são mutuamente exclusivas. A palavra-chave `__declspec(dllexport)` significa instanciar a classe de modelo, enquanto a palavra-chave `extern` significa não instanciar automaticamente a classe de modelo.

## <a name="see-also"></a>Consulte também

[Instanciação explícita](../../cpp/explicit-instantiation.md)<br/>
[dllexport, dllimport](../../cpp/dllexport-dllimport.md)<br/>
[Regras e limitações gerais](../../cpp/general-rules-and-limitations.md)