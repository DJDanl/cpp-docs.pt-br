---
title: Erro de Build PRJ0030 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0030
helpviewer_keywords:
- PRJ0030
ms.assetid: c48b3727-e166-46e7-bcd7-3e5b2ac5c1d4
ms.openlocfilehash: 2a6cde4ca48acb9aadfe3109084483dbb554e1e4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50488069"
---
# <a name="project-build-error-prj0030"></a>Erro de Build PRJ0030 no Projeto

Erro de expansão de macro. Avalie a recursão excedida 32 níveis para $(macro).

Esse erro é causado por recursão em suas macros. Por exemplo, se você definir a **diretório intermediário** propriedade (consulte [página de propriedades gerais (projeto)](../../ide/general-property-page-project.md)) para $(IntDir), você terá de recursão.

Para resolver esse erro, não defina macros ou propriedades em termos de macros, que elas são usadas para definir.