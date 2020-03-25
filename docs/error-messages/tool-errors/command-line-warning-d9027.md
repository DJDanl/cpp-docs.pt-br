---
title: Aviso D9027 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9027
helpviewer_keywords:
- D9027
ms.assetid: 2a29edc5-5649-48f2-9058-2057c747284c
ms.openlocfilehash: 46ed5750bd1f315f20658ace9b83fac532fbbabb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196671"
---
# <a name="command-line-warning-d9027"></a>Aviso D9027 (linha de comando)

arquivo de origem '\<filename > ' ignorado

O CL. exe ignorou o arquivo de origem de entrada.

Esse aviso pode ser causado por um espaço entre a opção/FO e um nome de arquivo de saída em uma linha de comando com a opção/c. Por exemplo:

```
cl /c /Fo output.obj input.c
```

Como há um espaço entre/fo e `output.obj`, o CL. exe usa `output.obj` como o nome do arquivo de entrada. Para corrigir o problema, remova o espaço:

```
cl /c /Fooutput.obj input.c
```
