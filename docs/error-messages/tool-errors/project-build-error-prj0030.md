---
title: "PRJ0030 de erro de compilação de projeto | Documentos do Microsoft"
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
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 156c7e0d7ce4ad252ef94a92776bd9430ca9f42a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0030"></a>Erro de Build PRJ0030 no Projeto
Erro de expansão de macro. Avalie recursão excedida 32 níveis para $(macro).  
  
 Esse erro é causado por recursão em suas macros. Por exemplo, se você definir o **diretório intermediário** propriedade (consulte [página de propriedade geral (projeto)](../../ide/general-property-page-project.md)) para $(IntDir), você terá de recursão.  
  
 Para resolver esse erro, não definem propriedades em termos de macros que são usados para definir ou macros.
