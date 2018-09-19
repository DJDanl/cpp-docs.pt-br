---
title: Aviso PRJ0029 de Build do projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0029
dev_langs:
- C++
helpviewer_keywords:
- PRJ0029
ms.assetid: f02c09c6-09f3-4d44-8cd4-9a25336be1ea
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 854120bf6021295348ff2e28b36f7b44007017b1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46025994"
---
# <a name="project-build-warning-prj0029"></a>Aviso PRJ0029 no Build do Projeto

A propriedade 'Outputs' para a etapa de compilação personalizada em nível de projeto não está definida. A etapa de compilação personalizada será ignorada.

Uma etapa de compilação personalizada não foi executada porque nenhuma saída foi especificada.

Para resolver esse erro, siga um procedimentos:

- Exclua a etapa de compilação personalizada do build.

- Adicione uma saída.

- Exclua o conteúdo do comando da etapa de compilação personalizada.