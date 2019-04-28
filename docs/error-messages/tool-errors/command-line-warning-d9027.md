---
title: Aviso D9027 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9027
helpviewer_keywords:
- D9027
ms.assetid: 2a29edc5-5649-48f2-9058-2057c747284c
ms.openlocfilehash: f89e7416efe7a0069ee2dae8df921933bbe76bcf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62214095"
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