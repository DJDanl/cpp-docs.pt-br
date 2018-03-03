---
title: Como BSCMAKE compila um. Arquivos BSC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- browse information files (.bsc), building
ms.assetid: 8512b33e-c856-44a2-87bd-01ab10b52a95
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cb8e03bed85a5e466a3c41f0cffc51d35c4b4561
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-bscmake-builds-a-bsc-file"></a>Como BSCMAKE compila um arquivo .Bsc
BSCMAKE cria ou recria um arquivo. bsc da maneira mais eficiente possível. Para evitar possíveis problemas, é importante compreender o processo de compilação.  
  
 Quando BSCMAKE compila um arquivo de informações de procura, ele trunca os arquivos. SBR para comprimento de zero. Durante uma compilação subsequente do mesmo arquivo, um arquivo. SBR de comprimento zero (ou vazio) informa BSCMAKE, o arquivo. SBR não tem nenhum novo contribuição para fazer. Ele permite que o BSCMAKE que não é necessária uma atualização essa parte do arquivo e uma compilação incremental será suficiente. Durante cada compilação (a menos que a opção /n for especificada), BSCMAKE primeiro tenta atualizar o arquivo de forma incremental usando somente os arquivos. SBR foram alterados.  
  
 BSCMAKE procura um arquivo. bsc que tem o nome especificado com a opção /o. Se /o não for especificado, o BSCMAKE procurará um arquivo que tem o nome base do arquivo. SBR primeiro e uma extensão. bsc. Se o arquivo existir, BSCMAKE executa uma compilação incremental do arquivo de informações de procura usando somente os arquivos. SBR contribuição. Se o arquivo não existir, BSCMAKE executa uma compilação completa usando todos os arquivos. SBR. As regras para compilações são da seguinte maneira:  
  
-   Para obter uma compilação completa seja bem-sucedida, todos especificados arquivos. SBR devem existir e não devem ser truncados. Se um arquivo. SBR estiver truncado, você deve recriá-lo (por recompilar ou montar) antes de executar BSCMAKE.  
  
-   Para uma compilação incremental seja bem-sucedida, o arquivo. bsc deve existir. Todos os arquivos. SBR contribuição, até mesmo arquivos vazios, deve existir e deve ser especificado na linha de comando BSCMAKE. Se você omitir um arquivo. SBR da linha de comando, BSCMAKE remove sua contribuição do arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Compilando um arquivo .Bsc](../../build/reference/building-a-dot-bsc-file.md)