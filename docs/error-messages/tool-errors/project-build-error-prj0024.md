---
title: Erro de Build prj0024 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0024
dev_langs:
- C++
helpviewer_keywords:
- PRJ0024
ms.assetid: 8bde6368-6c1b-4e04-bc5e-3c6d0b8fa1d7
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2cf9ad974856f132599932a32b954e50453adf56
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-error-prj0024"></a>Erro de Build PRJ0024 no Projeto
O caminho Unicode 'path' não pôde ser convertido na página de código ANSI do usuário.  
  
 ***caminho*** é a versão original do Unicode da cadeia de caracteres de caminho. Esse erro pode ocorrer em casos em que há um caminho de Unicode que não pode ser convertido diretamente para ANSI para a página de código atual do sistema.  
  
 Esse erro pode ocorrer se você estiver trabalhando com um projeto que foi desenvolvido em um sistema usando uma página de código que não está no seu computador.  
  
 A resolução para esse erro é atualizar o caminho para usar texto ANSI ou para instalar a página de código em seu computador e defina-o como o padrão do sistema.