---
title: Erro PRJ0025 (compilação de projeto)
ms.date: 08/27/2018
f1_keywords:
- PRJ0025
helpviewer_keywords:
- PRJ0025
ms.assetid: 57725c78-bc63-44f3-9667-2969b2d7c41d
ms.openlocfilehash: 30445a3abc2a6ad05c983448f57ed5b93df6e61f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192348"
---
# <a name="project-build-error-prj0025"></a>Erro PRJ0025 (compilação de projeto)

> O arquivo em lotes '*File*' contém o conteúdo Unicode que não pôde ser convertido na página de código ANSI do usuário.
>
> *Conteúdo UNICODE do arquivo*

O sistema de projeto encontrou o conteúdo Unicode em uma regra de compilação personalizada ou um evento de compilação que não pode ser convertido corretamente na página de código ANSI atual do usuário.

A resolução para esse erro é atualizar o conteúdo da regra de compilação ou do evento de compilação para usar o ANSI ou instalar a página de código no computador e defini-la como o padrão do sistema.

Para obter mais informações sobre etapas de compilação personalizadas e eventos de compilação, consulte [noções básicas sobre etapas de compilação personalizadas e eventos de compilação](../../build/understanding-custom-build-steps-and-build-events.md).
