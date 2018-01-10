---
title: Criar um. Arquivos SBR | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- SBR files
- BSCMAKE, input files
- .sbr files
- source browser files
- local symbols in browse information
- symbols
ms.assetid: bdb4b93c-a88a-441a-84fd-01087d03be25
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d87b71daaf5d7b37e67c2c0e56e844bd5251a490
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-an-sbr-file"></a>Criando um arquivo .Sbr
Os arquivos de entrada para BSCMAKE são arquivos. SBR. O compilador cria um arquivo. SBR para cada arquivo de objeto (. obj) ele compila. Quando você criar ou atualizar o arquivo de informações de procura, todos os arquivos. SBR para seu projeto devem estar disponíveis no disco.  
  
 Para criar um arquivo. SBR com todas as informações possíveis, especifique [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md).  
  
 Para criar um arquivo. SBR que não contenha símbolos locais, especifique [/Fr](../../build/reference/fr-fr-create-dot-sbr-file.md). Se os arquivos. SBR contém símbolos locais, você pode ainda omiti-los do arquivo. bsc por meio do BSCMAKE [opção /El](../../build/reference/bscmake-options.md)`.`  
  
 Você pode criar um arquivo. SBR sem executar uma compilação completa. Por exemplo, você pode especificar a opção /Zs ao compilador para executar uma verificação de sintaxe e ainda se você especificar /FR ou /Fr., gerar um arquivo. SBR  
  
 O processo de compilação pode ser mais eficiente se os arquivos. SBR primeiro são compactados para remover as definições não referenciadas. O compilador automaticamente pacotes de arquivos. SBR.  
  
## <a name="see-also"></a>Consulte também  
 [Compilando um arquivo .Bsc](../../build/reference/building-a-dot-bsc-file.md)