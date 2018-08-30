---
title: Erro de Build prj0024 do projeto | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0024
dev_langs:
- C++
helpviewer_keywords:
- PRJ0024
ms.assetid: 8bde6368-6c1b-4e04-bc5e-3c6d0b8fa1d7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eb539a5f1ee5f1aa5f9d828d93fa6d0dc8690c22
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43215592"
---
# <a name="project-build-error-prj0024"></a>Erro de Build PRJ0024 no Projeto

> O caminho Unicode '*caminho*' não pôde ser convertido na página de código ANSI do usuário.

*caminho* é a versão original do Unicode da cadeia de caracteres de caminho. Esse erro pode ocorrer em casos em que há um caminho de Unicode que não pode ser convertido diretamente para ANSI para a página de código atual do sistema.

Esse erro pode ocorrer se você estiver trabalhando com um projeto que foi desenvolvido em um sistema usando uma página de código que não está em seu computador.

A resolução para esse erro é atualizar o caminho para usar texto ANSI ou para instalar a página de código em seu computador e defini-lo como o padrão do sistema.