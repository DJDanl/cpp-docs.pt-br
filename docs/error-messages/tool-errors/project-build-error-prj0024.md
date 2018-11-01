---
title: Erro de Build PRJ0024 no Projeto
ms.date: 08/27/2018
f1_keywords:
- PRJ0024
helpviewer_keywords:
- PRJ0024
ms.assetid: 8bde6368-6c1b-4e04-bc5e-3c6d0b8fa1d7
ms.openlocfilehash: 645b898bdffcc6d7b397c25eb3c41cea25cb361f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50589638"
---
# <a name="project-build-error-prj0024"></a>Erro de Build PRJ0024 no Projeto

> O caminho Unicode '*caminho*' não pôde ser convertido na página de código ANSI do usuário.

*caminho* é a versão original do Unicode da cadeia de caracteres de caminho. Esse erro pode ocorrer em casos em que há um caminho de Unicode que não pode ser convertido diretamente para ANSI para a página de código atual do sistema.

Esse erro pode ocorrer se você estiver trabalhando com um projeto que foi desenvolvido em um sistema usando uma página de código que não está em seu computador.

A resolução para esse erro é atualizar o caminho para usar texto ANSI ou para instalar a página de código em seu computador e defini-lo como o padrão do sistema.