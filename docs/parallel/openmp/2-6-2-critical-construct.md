---
title: 2.6.2 construto critical | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c46ecd00-b4a2-4a5e-ba92-288c329e773a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e51bd425999081c7a06a7d5692dbea16c887fa0b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46417846"
---
# <a name="262-critical-construct"></a>2.6.2 Construto critical

O **críticos** diretiva identifica uma construção que restringe a execução do bloco estruturado associado a um único thread por vez. A sintaxe do **críticos** diretiva é da seguinte maneira:

```
#pragma omp critical [(name)]  new-linestructured-block
```

Um recurso opcional *nome* pode ser usado para identificar a região crítica. Usado para identificar uma região crítica de identificadores têm vinculação externa e estão em um espaço para nome que é separado dos name spaces usados por rótulos, marcas, membros e identificadores comuns.

Um thread aguarda no início de uma região crítica, até que nenhum outro thread está em execução em uma região crítica (em qualquer lugar no programa) com o mesmo nome. Tudo sem nome **críticos** diretivas mapeiam para o mesmo nome não especificado.