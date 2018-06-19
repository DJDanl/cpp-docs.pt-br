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
ms.openlocfilehash: ae7070fcc590307e71b0c34259bcbe1c12200550
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33689591"
---
# <a name="262-critical-construct"></a>2.6.2 Construto critical
O **crítico** diretiva identifica uma construção que restringe a execução do bloco estruturado associado a um único thread por vez. A sintaxe do **crítico** diretiva é da seguinte maneira:  
  
```  
#pragma omp critical [(name)]  new-linestructured-block  
```  
  
 Um recurso opcional *nome* pode ser usado para identificar a região crítica. Identificadores usados para identificar uma região crítica possuir vínculo externo e estão em um espaço para nome que é separado de espaços para nome usados por rótulos, marcas, membros e identificadores comuns.  
  
 Um thread aguarda o início de uma região crítica até que nenhum outro thread está em execução em uma região crítica (em qualquer lugar no programa) com o mesmo nome. Todos os sem nome **crítico** diretivas mapeiam para o mesmo nome não especificado.