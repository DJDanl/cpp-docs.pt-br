---
title: Erro PRJ0030 (compilação de projeto)
ms.date: 11/04/2016
f1_keywords:
- PRJ0030
helpviewer_keywords:
- PRJ0030
ms.assetid: c48b3727-e166-46e7-bcd7-3e5b2ac5c1d4
ms.openlocfilehash: aa1c8539247287f7644742857c3cb7de321a20a2
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57811470"
---
# <a name="project-build-error-prj0030"></a>Erro PRJ0030 (compilação de projeto)

Erro de expansão de macro. Avalie a recursão excedida 32 níveis para $(macro).

Esse erro é causado por recursão em suas macros. Por exemplo, se você definir a **diretório intermediário** propriedade (consulte [página de propriedades gerais (projeto)](../../build/reference/general-property-page-project.md)) para $(IntDir), você terá de recursão.

Para resolver esse erro, não defina macros ou propriedades em termos de macros, que elas são usadas para definir.