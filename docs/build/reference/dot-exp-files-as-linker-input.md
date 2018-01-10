---
title: . Arquivos EXP como entrada de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- exporting functions
- import libraries, linker files
- linking [C++], exports
- exporting functions, information about exported functions
- exporting data, export (.exp) files
- functions [C++], exporting
- .exp files [C++]
- EXP files
ms.assetid: 399f5636-0a4d-462e-b500-5f5b9ae5ad22
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5cd6351623b230e3be1e432bd6ee0fb760da5abd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exp-files-as-linker-input"></a>Arquivos .Exp como entrada de vinculador
Arquivos de exportação (. Exp) contêm informações sobre itens de funções e os dados exportados. Quando o LIB cria uma biblioteca de importação, ele também cria um arquivo. Exp. Você usa o arquivo. EXP quando você vincular um programa que exporta para e importa de outro programa, direta ou indiretamente. Se você vincular com um arquivo. EXP, LINK não produz uma biblioteca de importação, porque ele pressupõe que LIB já criado um. Para obter detalhes sobre os arquivos. EXP e bibliotecas de importação, consulte [trabalhando com bibliotecas importar e exportar arquivos](../../build/reference/working-with-import-libraries-and-export-files.md).  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de entrada de LINK](../../build/reference/link-input-files.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)