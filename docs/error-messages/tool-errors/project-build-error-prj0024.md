---
title: Erro de Build prj0024 no projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 59bf76aba80093bf9e8e653bdfb9fad49687a501
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33318341"
---
# <a name="project-build-error-prj0024"></a>Erro de Build PRJ0024 no Projeto
O caminho Unicode 'path' não pôde ser convertido na página de código ANSI do usuário.  
  
 ***caminho*** é a versão original do Unicode da cadeia de caracteres de caminho. Esse erro pode ocorrer em casos em que há um caminho de Unicode que não pode ser convertido diretamente para ANSI para a página de código atual do sistema.  
  
 Esse erro pode ocorrer se você estiver trabalhando com um projeto que foi desenvolvido em um sistema usando uma página de código que não está no seu computador.  
  
 A resolução para esse erro é atualizar o caminho para usar texto ANSI ou para instalar a página de código em seu computador e defina-o como o padrão do sistema.