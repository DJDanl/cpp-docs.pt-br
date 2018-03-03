---
title: "Variáveis de ambiente LINK | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- link
dev_langs:
- C++
helpviewer_keywords:
- variables, environment
- LINK tool [C++], environment variables
- LIB environment variable
- environment variables [C++], LINK
ms.assetid: 9a3d3291-0cc4-4a7d-9d50-80e351b90708
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 67b36afce92140c4f205f8e5a4a46dfc7ac2d300
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="link-environment-variables"></a>Variáveis de ambiente LINK

A ferramenta LINK usa as seguintes variáveis de ambiente:  
  
-   LINK e \_LINK\_, se definido. A ferramenta LINK precede as opções e argumentos definidos na variável de ambiente LINK e acrescenta as opções e argumentos definidos no \_LINK\_ variável de ambiente para os argumentos de linha de comando antes do processamento.  
  
-   LIB, se definido. As ferramentas LINK usa o caminho de biblioteca ao procurar um objeto, a biblioteca ou a outro arquivo especificado na linha de comando ou pelo [/BASE](../../build/reference/base-base-address.md) opção. Ele também usa o caminho de biblioteca para localizar um arquivo. PDB chamado em um objeto. A variável LIB pode conter uma ou mais especificações de caminho, separadas por ponto e vírgula. Um caminho deve apontar para o subdiretório \lib da instalação do Visual C++.  
  
-   CAMINHO, se a ferramenta precisa executar CVTRES e não é possível localizar o arquivo no mesmo diretório que o próprio LINK. (LINK requer CVTRES vincular um arquivo. res). PATH deve apontar para o subdiretório \bin da instalação do Visual C++.  
  
-   TMP, para especificar um diretório ao vincular arquivos OMF ou. res.  
  
## <a name="see-also"></a>Consulte também  

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
[Opções do vinculador](../../build/reference/linker-options.md)   
[Compilar código C/C++ na linha de comando](../../build/building-on-the-command-line.md)  
[Definir o caminho e variáveis de ambiente para builds de linha de comando](../../build/setting-the-path-and-environment-variables-for-command-line-builds.md)
