---
title: Aviso D9026 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9026
helpviewer_keywords:
- D9026
ms.assetid: 149fe5e3-5329-4be8-b871-49dfd423aaba
ms.openlocfilehash: 3fd8d442dfabaf2f03d8b564c9fdfb1537f6ff28
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50599427"
---
# <a name="command-line-warning-d9026"></a>Aviso D9026 (linha de comando)

opções se aplicam a toda linha de comando

Uma opção foi especificada em um comando depois que um nome de arquivo foi especificado. A opção foi aplicada ao arquivo que a antecedem.

Por exemplo, no comando

```
CL verdi.c /G5 puccini.c
```

o arquivo VERDI.c será compilado usando a opção G5, não o padrão de /G4.

Esse comportamento é diferente de algumas versões anteriores, que são aplicados apenas as opções especificadas antes do nome do arquivo, resultando em VERDI.c que está sendo compilado usando/G4 e PUCCINI.c que está sendo compilado usando G5.