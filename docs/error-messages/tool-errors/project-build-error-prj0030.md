---
title: Erro de Build prj0030 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0030
dev_langs:
- C++
helpviewer_keywords:
- PRJ0030
ms.assetid: c48b3727-e166-46e7-bcd7-3e5b2ac5c1d4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b6fe537dd8e6705fd5e30929a2480eb1d9ef9119
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-error-prj0030"></a>Erro de Build PRJ0030 no Projeto
Erro de expansão de macro. Avalie recursão excedida 32 níveis para $(macro).  
  
 Esse erro é causado por recursão em suas macros. Por exemplo, se você definir o **diretório intermediário** propriedade (consulte [página de propriedade geral (projeto)](../../ide/general-property-page-project.md)) $ (IntDir), você terá de recursão.  
  
 Para resolver esse erro, não definem propriedades em termos de macros que são usados para definir ou macros.