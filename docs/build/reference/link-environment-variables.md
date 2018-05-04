---
title: Variáveis de ambiente LINK | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 076e427e50520651f30cde20c764ff1124a6f953
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
