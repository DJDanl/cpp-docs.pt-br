---
title: Aviso prj0042 no Build do projeto | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0042
dev_langs:
- C++
helpviewer_keywords:
- PRJ0042
ms.assetid: 682c9999-6f85-409f-b102-00c93243f74f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 260da8ac336c640ea875610b2c62e6c42c7d335e
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43211344"
---
# <a name="project-build-warning-prj0042"></a>Aviso PRJ0042 no Build do Projeto

> O 'property dos saídas para a etapa de compilação personalizada para o arquivo'*arquivo*' não está definida. A etapa de compilação personalizada será ignorada.

Uma etapa de compilação personalizada não foi executada porque nenhuma saída foi especificada.

Para resolver esse erro, siga um procedimentos:

- Exclua a etapa de compilação personalizada do build.

- Adicione uma saída.

- Exclua o conteúdo do comando da etapa de compilação personalizada.