---
title: Erro de Build PRJ0002 no Projeto
ms.date: 08/27/2018
f1_keywords:
- PRJ0002
helpviewer_keywords:
- PRJ0002
ms.assetid: 1c820b1f-9a24-4681-80ed-4fcbfd7caa00
ms.openlocfilehash: d8e13bcc03a02fd9dbc739566a92025a7b97d598
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50516266"
---
# <a name="project-build-error-prj0002"></a>Erro de Build PRJ0002 no Projeto

> resultado do erro retornado de '*linha de comando*'.

Um comando, *linha de comando*, que foi formado de entrada do usuário na **páginas de propriedades** caixa de diálogo, retornada um código de erro, mas nenhuma informação será exibida no **saída** janela .

A resolução para esse erro depende da ferramenta que gerou o erro. Para MIDL, você terá uma ideia do que deu errado se /o (redirecionar a saída) for definido.

Um arquivo em lotes, como uma etapa de compilação personalizada ou evento de build, que não é informativo sobre condições de falha também pode ser o motivo para esse erro.