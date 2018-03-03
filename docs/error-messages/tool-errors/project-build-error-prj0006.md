---
title: Erro de Build prj0006 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0006
dev_langs:
- C++
helpviewer_keywords:
- PRJ0006
ms.assetid: ce092be4-1652-414f-8cb5-b97ef5841f89
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 817450fb6b72f985d7ff49f7e65f9dfa0933b4d6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="project-build-error-prj0006"></a>Erro de Build PRJ0006 no Projeto
Não foi possível abrir o arquivo temporário 'file'. Verifique se o arquivo existe e se o diretório não está protegido contra gravação.  
  
 Visual C++ não foi possível criar um arquivo temporário durante o processo de compilação. Motivos para isso:  
  
-   Nenhum diretório temp.  
  
-   Diretório temp de somente leitura.  
  
-   Sem espaço em disco.  
  
-   A pasta $ (IntDir) é somente leitura ou que contém os arquivos temporários que são somente leitura.  
  
 Esse erro também ocorrerá após erro prj0007 no: não foi possível criar o diretório' diretório de saída'. Erro prj0007 no significa que não foi possível criar o diretório $ (IntDir), indicando a criação de arquivos temporariamente também falharão.  
  
 Arquivos temporários são criados sempre que você especificar:  
  
-   Um arquivo de resposta.  
  
-   Uma etapa de compilação personalizada.  
  
-   Um evento de compilação.