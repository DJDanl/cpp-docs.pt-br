---
title: Aviso D9026 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9026
helpviewer_keywords:
- D9026
ms.assetid: 149fe5e3-5329-4be8-b871-49dfd423aaba
ms.openlocfilehash: 59dfcdc97fb9caf60a018cb20583ee6fca3dcb27
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196697"
---
# <a name="command-line-warning-d9026"></a>Aviso D9026 (linha de comando)

as opções se aplicam à linha de comando inteira

Uma opção foi especificada em um comando depois que um nome de arquivo foi especificado. A opção foi aplicada ao arquivo que o precede.

Por exemplo, no comando

```
CL verdi.c /G5 puccini.c
```

o arquivo VERDI. c será compilado usando a opção/G5, não o padrão/G4.

Esse comportamento é diferente do de algumas versões anteriores, que aplicaram apenas as opções especificadas antes do nome do arquivo, resultando em VERDI. c sendo compilado usando/G4 e PUCCINI. c sendo compilado usando/G5.
