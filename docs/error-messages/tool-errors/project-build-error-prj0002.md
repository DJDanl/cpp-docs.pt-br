---
title: Erro de Build PRJ0002 no Projeto
ms.date: 08/27/2018
f1_keywords:
- PRJ0002
helpviewer_keywords:
- PRJ0002
ms.assetid: 1c820b1f-9a24-4681-80ed-4fcbfd7caa00
ms.openlocfilehash: d8e13bcc03a02fd9dbc739566a92025a7b97d598
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62359703"
---
# <a name="project-build-error-prj0002"></a>Erro de Build PRJ0002 no Projeto

> resultado do erro retornado de '*linha de comando*'.

Um comando, *linha de comando*, que foi formado de entrada do usuário na **páginas de propriedades** caixa de diálogo, retornada um código de erro, mas nenhuma informação será exibida no **saída** janela .

A resolução para esse erro depende da ferramenta que gerou o erro. Para MIDL, você terá uma ideia do que deu errado se /o (redirecionar a saída) for definido.

Um arquivo em lotes, como uma etapa de compilação personalizada ou evento de build, que não é informativo sobre condições de falha também pode ser o motivo para esse erro.