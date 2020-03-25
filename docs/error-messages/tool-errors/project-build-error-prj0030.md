---
title: Erro PRJ0030 (compilação de projeto)
ms.date: 11/04/2016
f1_keywords:
- PRJ0030
helpviewer_keywords:
- PRJ0030
ms.assetid: c48b3727-e166-46e7-bcd7-3e5b2ac5c1d4
ms.openlocfilehash: 3675c3796ae37df848e458aa2db665d8c4aa7766
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192504"
---
# <a name="project-build-error-prj0030"></a>Erro PRJ0030 (compilação de projeto)

Erro de expansão de macro. A recursão de avaliação excedeu 32 níveis para $ (macro).

Esse erro é causado por recursão em suas macros. Por exemplo, se você definir a propriedade do **diretório intermediário** (consulte a [página de propriedades geral (projeto)](../../build/reference/general-property-page-project.md)como $ (IntDir), terá recursão.

Para resolver esse erro, não defina macros ou propriedades em termos de macros que são usadas para definir.
