---
title: 2.6.2 construto critical | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: c46ecd00-b4a2-4a5e-ba92-288c329e773a
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4c658b32536404dde1a693582e78bfbedc2823b8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="262-critical-construct"></a>2.6.2 Construto critical
O **crítico** diretiva identifica uma construção que restringe a execução do bloco estruturado associado a um único thread por vez. A sintaxe do **crítico** diretiva é da seguinte maneira:  
  
```  
#pragma omp critical [(name)]  new-linestructured-block  
```  
  
 Um recurso opcional *nome* pode ser usado para identificar a região crítica. Identificadores usados para identificar uma região crítica possuir vínculo externo e estão em um espaço para nome que é separado de espaços para nome usados por rótulos, marcas, membros e identificadores comuns.  
  
 Um thread aguarda o início de uma região crítica até que nenhum outro thread está em execução em uma região crítica (em qualquer lugar no programa) com o mesmo nome. Todos os sem nome **crítico** diretivas mapeiam para o mesmo nome não especificado.