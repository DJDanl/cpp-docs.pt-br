---
title: Linha de comando D9026 de aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D9026
dev_langs:
- C++
helpviewer_keywords:
- D9026
ms.assetid: 149fe5e3-5329-4be8-b871-49dfd423aaba
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 07be633e56dad6c8f0b304a3c88c1b9919221d4a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46079148"
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