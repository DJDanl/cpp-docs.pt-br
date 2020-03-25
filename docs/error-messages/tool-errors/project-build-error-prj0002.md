---
title: Erro de Build PRJ0002 no Projeto
ms.date: 08/27/2018
f1_keywords:
- PRJ0002
helpviewer_keywords:
- PRJ0002
ms.assetid: 1c820b1f-9a24-4681-80ed-4fcbfd7caa00
ms.openlocfilehash: 30680f5b26f3be5e7f9b48d18e82fca42ed65493
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192933"
---
# <a name="project-build-error-prj0002"></a>Erro de Build PRJ0002 no Projeto

> resultado do erro retornado da '*linha de comando*'.

Um comando, *linha de comando*, que foi formado por entrada do usuário na caixa de diálogo **páginas de propriedades** , retornou um código de erro, mas nenhuma informação será exibida na janela **saída** .

A resolução para esse erro depende de qual ferramenta gerou o erro. Para MIDL, você terá uma ideia do que deu errado se/o (saída de redirecionamento) for definida.

Um arquivo em lotes, como uma etapa de compilação personalizada ou um evento de Build, que não é informativo sobre as condições de falha também pode ser o motivo desse erro.
