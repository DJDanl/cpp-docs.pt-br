---
title: Linha de comando D9027 de aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D9027
dev_langs:
- C++
helpviewer_keywords:
- D9027
ms.assetid: 2a29edc5-5649-48f2-9058-2057c747284c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 105ebbf62027ac3d9377c513c4f7c59e261b983d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46112519"
---
# <a name="command-line-warning-d9027"></a>Aviso D9027 (linha de comando)

arquivo de origem '\<filename >' ignorado

CL.exe ignorado o arquivo de fonte de entrada.

Esse aviso pode ser causado por um espaço entre a opção /Fo e um nome de arquivo de saída em uma linha de comando com a opção /c. Por exemplo:

```
cl /c /Fo output.obj input.c
```

Porque há um espaço entre /Fo e `output.obj`, usa CL.exe `output.obj` como o nome do arquivo de entrada. Para corrigir o problema, remova o espaço:

```
cl /c /Fooutput.obj input.c
```