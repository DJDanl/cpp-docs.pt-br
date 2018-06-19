---
title: . Arquivos EXP como entrada de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f9b5c118e81372bd57810a9472526909ed21f765
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32371093"
---
# <a name="exp-files-as-linker-input"></a>Arquivos .Exp como entrada de vinculador
Arquivos de exportação (. Exp) contêm informações sobre itens de funções e os dados exportados. Quando o LIB cria uma biblioteca de importação, ele também cria um arquivo. Exp. Você usa o arquivo. EXP quando você vincular um programa que exporta para e importa de outro programa, direta ou indiretamente. Se você vincular com um arquivo. EXP, LINK não produz uma biblioteca de importação, porque ele pressupõe que LIB já criado um. Para obter detalhes sobre os arquivos. EXP e bibliotecas de importação, consulte [trabalhando com bibliotecas importar e exportar arquivos](../../build/reference/working-with-import-libraries-and-export-files.md).  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos de entrada de LINK](../../build/reference/link-input-files.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)