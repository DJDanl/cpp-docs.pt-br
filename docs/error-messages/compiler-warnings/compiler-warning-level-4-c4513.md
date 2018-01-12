---
title: "Compilador (nível 4) de aviso C4513 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4513
dev_langs: C++
helpviewer_keywords: C4513
ms.assetid: 6877334a-f30a-4184-9483-dac3348737a4
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c07828569b789c6035b5ea28d47d7fd026341026
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4513"></a>Compilador C4513 de aviso (nível 4)
'class': não foi possível gerar um destruidor  
  
 O compilador não pode gerar um destruidor de padrão de uma determinada classe; Nenhum destruidor foi criado. O destruidor é em uma classe base que não está acessível na classe derivada. Se a classe base tiver um destruidor privado, torne-o público ou protegido.