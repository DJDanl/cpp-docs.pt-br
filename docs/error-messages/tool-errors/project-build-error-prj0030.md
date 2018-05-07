---
title: Erro de Build prj0030 no projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0030
dev_langs:
- C++
helpviewer_keywords:
- PRJ0030
ms.assetid: c48b3727-e166-46e7-bcd7-3e5b2ac5c1d4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1bf1c9137f8c4ed0d80955eef38b07ea86204a5c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="project-build-error-prj0030"></a>Erro de Build PRJ0030 no Projeto
Erro de expansão de macro. Avalie recursão excedida 32 níveis para $(macro).  
  
 Esse erro é causado por recursão em suas macros. Por exemplo, se você definir o **diretório intermediário** propriedade (consulte [página de propriedade geral (projeto)](../../ide/general-property-page-project.md)) $ (IntDir), você terá de recursão.  
  
 Para resolver esse erro, não definem propriedades em termos de macros que são usados para definir ou macros.