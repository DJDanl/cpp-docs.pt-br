---
title: Erro de Build prj0002 do projeto | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0002
dev_langs:
- C++
helpviewer_keywords:
- PRJ0002
ms.assetid: 1c820b1f-9a24-4681-80ed-4fcbfd7caa00
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bc0e48130c17e04c2671395161452c9e66000047
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43195709"
---
# <a name="project-build-error-prj0002"></a>Erro de Build PRJ0002 no Projeto

> resultado do erro retornado de '*linha de comando*'.

Um comando, *linha de comando*, que foi formado de entrada do usuário na **páginas de propriedades** caixa de diálogo, retornada um código de erro, mas nenhuma informação será exibida no **saída** janela .

A resolução para esse erro depende da ferramenta que gerou o erro. Para MIDL, você terá uma ideia do que deu errado se /o (redirecionar a saída) for definido.

Um arquivo em lotes, como uma etapa de compilação personalizada ou evento de build, que não é informativo sobre condições de falha também pode ser o motivo para esse erro.