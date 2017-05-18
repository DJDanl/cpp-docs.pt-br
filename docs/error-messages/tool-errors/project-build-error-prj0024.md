---
title: "PRJ0024 de erro de compilação de projeto | Documentos do Microsoft"
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
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 593d49cfcfa1849ae8d9715764f783d8486236e6
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="project-build-error-prj0024"></a>Erro de Build PRJ0024 no Projeto
O caminho Unicode 'path' não pôde ser convertido na página de código ANSI do usuário.  
  
 ***caminho*** é a versão Unicode original da cadeia do caminho. Esse erro pode ocorrer em casos onde há um caminho de Unicode que não pode ser diretamente convertido em ANSI para a página de código atual do sistema.  
  
 Esse erro pode ocorrer se você estiver trabalhando com um projeto que foi desenvolvido em um sistema usando uma página de código que não está em seu computador.  
  
 A resolução para esse erro é atualizar o caminho para usar texto ANSI ou para instalar a página de código em seu computador e defini-lo como o padrão do sistema.
