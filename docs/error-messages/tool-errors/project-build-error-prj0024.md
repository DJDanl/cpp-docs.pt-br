---
title: Erro de Build PRJ0024 no Projeto
ms.date: 08/27/2018
f1_keywords:
- PRJ0024
helpviewer_keywords:
- PRJ0024
ms.assetid: 8bde6368-6c1b-4e04-bc5e-3c6d0b8fa1d7
ms.openlocfilehash: bcfdcce54618acca0e22daa54e95083cf3ee9d50
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80192608"
---
# <a name="project-build-error-prj0024"></a>Erro de Build PRJ0024 no Projeto

> Não foi possível converter o caminho Unicode '*path*' na página de código ANSI do usuário.

*path* é a versão Unicode original da cadeia de caracteres do caminho. Esse erro pode ocorrer em casos em que há um caminho Unicode que não pode ser convertido diretamente em ANSI para a página de código do sistema atual.

Esse erro pode ocorrer se você estiver trabalhando com um projeto que foi desenvolvido em um sistema usando uma página de código que não está em seu computador.

A resolução para esse erro é atualizar o caminho para usar o texto ANSI ou instalar a página de código em seu computador e defini-la como o padrão do sistema.
