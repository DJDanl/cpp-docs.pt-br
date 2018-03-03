---
title: "Criar arquivos de informações de procura: Visão geral | Microsoft Docs"
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
- .bsc files, about .bsc files
- bsc files, about bsc files
- browse information files (.bsc)
- browse information files (.bsc), creating
ms.assetid: b5c12832-51f6-4953-8044-4264dd0fb242
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f5b369d5a708e0ee56df635234c68ee88a31af48
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="building-browse-information-files-overview"></a>Compilando arquivos de informações de navegação: visão geral
Para criar informações de navegação de símbolo de procura, o compilador cria um arquivo. SBR para cada arquivo de origem em seu projeto, em seguida, BSCMAKE. EXE concatena os arquivos. SBR em um arquivo. bsc.  
  
 Gerando arquivos. SBR e. bsc leva tempo, para que o Visual C++ desativa essas funções por padrão. Se você desejar procurar informações atuais, você deve ativar as opções de pesquisa e compilar o projeto novamente.  
  
 Use [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) ou [/Fr](../../build/reference/fr-fr-create-dot-sbr-file.md) para informar ao compilador para criar arquivos. SBR. Para criar arquivos. bsc, você pode chamar [BSCMAKE](../../build/reference/bscmake-command-line.md) da linha de comando. Usar BSCMAKE da linha de comando fornece controle mais preciso sobre a manipulação de arquivos de informações de procura. Consulte [referência de BSCMAKE](../../build/reference/bscmake-reference.md) para obter mais informações.  
  
> [!TIP]
>  Você pode ativar a geração de arquivo. SBR mas deixar a geração do arquivo. bsc desativada. Isso fornece fast cria, mas também permite que você crie um arquivo. bsc nova rapidamente ativar a geração de arquivo. bsc e compilar o projeto.  
  
 Você pode reduzir o tempo, memória e espaço em disco necessário para criar um arquivo. bsc, reduzindo o tamanho do arquivo. bsc.  
  
 Consulte [página de propriedade geral (projeto)](../../ide/general-property-page-project.md) para obter informações sobre como criar um arquivo de navegador no ambiente de desenvolvimento.  
  
### <a name="to-create-a-smaller-bsc-file"></a>Para criar um arquivo. bsc menor  
  
1.  Use [opções de linha de comando BSCMAKE](../../build/reference/bscmake-options.md) para excluir informações do arquivo de informações de procura.  
  
2.  Omita símbolos locais em um ou mais arquivos. SBR ao compilar ou montar.  
  
3.  Se um arquivo de objeto não contém informações necessárias para o estágio atual de depuração, omita o seu arquivo. SBR do comando BSCMAKE quando você recria o arquivo de informações de procura.  
  
### <a name="to-combine-the-browse-information-from-several-projects-into-one-browser-file-bsc"></a>Para combinar as informações de procura de vários projetos em arquivos de um navegador (. bsc)  
  
1.  Não criar o arquivo. bsc no nível do projeto ou use a opção /n para impedir que os arquivos. SBR sendo truncado.  
  
2.  Depois que todos os projetos são criados, execute BSCMAKE com todos os arquivos. SBR como entrada. Caracteres curinga é aceitos. Por exemplo, se você tiver pastas de projeto C:\X, C:\Y e C:\Z com arquivos. SBR neles e você quisesse combiná-las em um arquivo. bsc, em seguida, usar BSCMAKE C:\X\\*.sbr C:\Y\\\*. SBR C:\Z\\\*. SBR /o c:\whatever_directory\combined.bsc para criar o arquivo. bsc combinado.  
  
## <a name="see-also"></a>Consulte também  
 [Ferramentas de compilação do C/C++](../../build/reference/c-cpp-build-tools.md)   
 [Referência de BSCMAKE](../../build/reference/bscmake-reference.md)