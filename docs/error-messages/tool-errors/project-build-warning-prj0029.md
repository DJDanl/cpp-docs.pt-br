---
title: Aviso PRJ0029 (compilação de projeto)
ms.date: 11/04/2016
f1_keywords:
- PRJ0029
helpviewer_keywords:
- PRJ0029
ms.assetid: f02c09c6-09f3-4d44-8cd4-9a25336be1ea
ms.openlocfilehash: 1daac3435bc8f1b4bd4ed8462caf3b8eaa397e22
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62298029"
---
# <a name="project-build-warning-prj0029"></a>Aviso PRJ0029 (compilação de projeto)

A propriedade 'Outputs' para a etapa de compilação personalizada em nível de projeto não está definida. A etapa de compilação personalizada será ignorada.

Uma etapa de compilação personalizada não foi executada porque nenhuma saída foi especificada.

Para resolver esse erro, siga um procedimentos:

- Exclua a etapa de compilação personalizada do build.

- Adicione uma saída.

- Exclua o conteúdo do comando da etapa de compilação personalizada.