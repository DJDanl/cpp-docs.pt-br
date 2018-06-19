---
title: Compilador (nível 4) de aviso C4513 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4513
dev_langs:
- C++
helpviewer_keywords:
- C4513
ms.assetid: 6877334a-f30a-4184-9483-dac3348737a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 92c3e89204ec30f9c96a5ea03ede5093dd013d0c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33292890"
---
# <a name="compiler-warning-level-4-c4513"></a>Compilador C4513 de aviso (nível 4)
'class': não foi possível gerar um destruidor  
  
 O compilador não pode gerar um destruidor de padrão de uma determinada classe; Nenhum destruidor foi criado. O destruidor é em uma classe base que não está acessível na classe derivada. Se a classe base tiver um destruidor privado, torne-o público ou protegido.