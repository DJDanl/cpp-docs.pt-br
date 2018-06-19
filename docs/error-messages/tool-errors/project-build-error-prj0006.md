---
title: Erro de Build prj0006 no projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0006
dev_langs:
- C++
helpviewer_keywords:
- PRJ0006
ms.assetid: ce092be4-1652-414f-8cb5-b97ef5841f89
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 151c22bf13c13de21e89a5c96185cf1c4c1ca349
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33317473"
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