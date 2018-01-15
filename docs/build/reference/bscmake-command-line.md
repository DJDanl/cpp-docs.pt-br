---
title: Linha de comando BSCMAKE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: BSCMAKE, command line
ms.assetid: 8006e8cf-8bfe-4c23-868a-b0a25e6bbf0f
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c00a3842db37cc5027809f717ac47bd471dd073f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="bscmake-command-line"></a>Linha de comando BSCMAKE
Para executar BSCMAKE, use a seguinte sintaxe de linha de comando:  
  
```  
BSCMAKE [options] sbrfiles  
```  
  
 Opções podem aparecer somente no `options` campo na linha de comando.  
  
 O *sbrfiles* campo especifica um ou mais arquivos. SBR criados por um compilador ou assembler. Separe os nomes dos arquivos. SBR com tabulações ou espaços. Você deve especificar a extensão. Não há nenhum padrão. Você pode especificar um caminho com o nome de arquivo e você pode usar o sistema operacional curingas (* e?).  
  
 Durante uma compilação incremental, você pode especificar novos arquivos. SBR que não fazem parte da compilação original. Se desejar que todas as colaborações permaneça no arquivo de informações de procura, você deve especificar todos os arquivos. SBR (incluindo arquivos truncados) que foram usados originalmente para criar o arquivo. bsc. Se você omitir um arquivo. SBR, contribuição desse arquivo para o arquivo de informações de procura é removida.  
  
 Não especifique um arquivo. SBR truncados para uma compilação completa. Uma compilação completa exige contribuições de todos os arquivos. SBR especificado. Antes de executar uma compilação completa, recompile o projeto e criar um novo arquivo. SBR para cada arquivo vazio.  
  
 O comando a seguir executa BSCMAKE para criar um arquivo chamado MAIN.bsc de três arquivos. SBR:  
  
```  
BSCMAKE main.sbr file1.sbr file2.sbr  
```  
  
 Para obter informações relacionadas, consulte [arquivo de comando BSCMAKE](../../build/reference/bscmake-command-file-response-file.md) e [opções BSCMAKE](../../build/reference/bscmake-options.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de BSCMAKE](../../build/reference/bscmake-reference.md)