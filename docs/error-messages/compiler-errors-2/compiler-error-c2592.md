---
title: C2592 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2592
dev_langs: C++
helpviewer_keywords: C2592
ms.assetid: 833a4d7b-66ef-4d4c-ae83-a533c2b0eb07
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3528354797987b47379d0ec56e103223ac87892f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2592"></a>C2592 de erro do compilador
'class': 'base_class_2' é herdado de 'base_class_1' e não pode ser especificado novamente  
  
 Você só pode especificar classes base que não herdar de outras classes base. Nesse caso, somente `base_class_1` é necessária na especificação de `class` porque `base_class_1` já herda `base_class_2`.