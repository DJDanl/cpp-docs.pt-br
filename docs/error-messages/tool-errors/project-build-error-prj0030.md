---
title: Erro de Build prj0030 do projeto | Microsoft Docs
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
ms.openlocfilehash: 964fedd40f577a8b337c4ad0c20ba80d33ed2a23
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099872"
---
# <a name="project-build-error-prj0030"></a>Erro de Build PRJ0030 no Projeto

Erro de expansão de macro. Avalie a recursão excedida 32 níveis para $(macro).

Esse erro é causado por recursão em suas macros. Por exemplo, se você definir a **diretório intermediário** propriedade (consulte [página de propriedades gerais (projeto)](../../ide/general-property-page-project.md)) para $(IntDir), você terá de recursão.

Para resolver esse erro, não defina macros ou propriedades em termos de macros, que elas são usadas para definir.