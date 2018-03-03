---
title: Erro de Build PRJ0008 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0008
dev_langs:
- C++
helpviewer_keywords:
- PRJ0008
ms.assetid: 6bf7f17a-d2a8-4826-99c7-d600d846952f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1740b0cf1edfc90258de4fe26478298ddf2875c6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-error-prj0008"></a>Erro de Build PRJ0008 no Projeto
Não foi possível excluir o arquivo 'file'.  
  
 **Certifique-se de que o arquivo não está aberto por outro processo e não está protegido contra gravação.**  
  
 Durante uma reconstrução ou a limpeza, Visual C++ exclui todos os arquivos de saída e intermediários conhecidos para a compilação, bem como todos os arquivos que atende às especificações de curinga no **extensões para excluir na limpeza** propriedade o [geral Página de propriedades de configurações de configuração](../../ide/general-property-page-project.md).  
  
 Você verá esse erro se o Visual C++ não é possível excluir um arquivo. Para resolver o erro, verifique o arquivo e o diretório gravável para o usuário que faz a compilação.