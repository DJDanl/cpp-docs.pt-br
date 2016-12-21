---
title: "Compilando arquivos de informa&#231;&#245;es de navega&#231;&#227;o: vis&#227;o geral | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .bsc, sobre arquivos .bsc"
  - "arquivos de informações de pesquisa (.bsc)"
  - "arquivos de informações de pesquisa (.bsc), criando"
  - "arquivos bsc, sobre arquivos bsc"
ms.assetid: b5c12832-51f6-4953-8044-4264dd0fb242
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilando arquivos de informa&#231;&#245;es de navega&#231;&#227;o: vis&#227;o geral
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para criar procurar informações para o símbolo que procura, o compilador cria um arquivo de .sbr para cada arquivo de origem em seu projeto, então BSCMAKE.EXE concatena os arquivos de .sbr em um arquivo de .bsc.  
  
 Gerar .sbr e .bsc arquivos retira tempo, portanto voltas do Visual C\+\+ essas funções por padrão.  Se você quiser procurar as informações atuais, você deve ativar ou desativar as opções para procurar no e criar seu projeto novamente.  
  
 Use [\/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) ou [\/Fr](../../build/reference/fr-fr-create-dot-sbr-file.md) para informar o compilador para criar arquivos de .sbr.  Para criar arquivos de .bsc, você pode chamar [BSCMAKE](../../build/reference/bscmake-command-line.md) de linha de comando.  Usar BSCMAKE de linha de comando dá\-o que um controle mais preciso sobre a manipulação de procura arquivos de informações.  Consulte [Referência de BSCMAKE](../../build/reference/bscmake-reference.md) para obter mais informações.  
  
> [!TIP]
>  Você pode ativar a geração de arquivo de .sbr mas deixar a geração de arquivo de .bsc desativada.  Isso fornece construções rápidas mas também permite criar rapidamente um arquivo atualizado de .bsc ativando a geração de arquivo de .bsc e criando o projeto.  
  
 Você pode reduzir o tempo, a memória, e o espaço em disco necessário criar um arquivo de .bsc reduzindo o tamanho do arquivo de .bsc.  
  
 Consulte [Página de propriedades geral projeto \(\)](../Topic/General%20Property%20Page%20\(Project\).md) para obter informações sobre como criar um arquivo do navegador no ambiente de desenvolvimento.  
  
### Para criar um arquivo menor de .bsc  
  
1.  Use [Opções de linha de comando de BSCMAKE](../Topic/BSCMAKE%20Options.md) para excluir as informações do arquivo de informações de navegação.  
  
2.  Omitir símbolos locais em um ou mais arquivos de .sbr ao criar ou ao montar.  
  
3.  Se um arquivo de objeto não contém as informações necessárias para sua fase atual de depuração, omita o arquivo de .sbr de comando de BSCMAKE quando você recria o arquivo de informações de navegação.  
  
### Para combinar informações de procura de vários projetos em um navegador arquivo \(.bsc\)  
  
1.  Não crie o arquivo de .bsc no nível de projeto ou não use a opção \/n para impedir que os arquivos de .sbr sejam truncados.  
  
2.  Os projetos são criados depois, a execução BSCMAKE com todos os arquivos de .sbr como entrada.  Os curingas são aceitas.  Por exemplo, se você tivesse diretórios C:\\X, C:\\Y, de projeto e C:\\Z com arquivos de .sbr nelas e você quiser combinar todos os em um arquivo de .bsc, use BSCMAKE C:\\X\\\*.sbr C:\\Y\\\*.sbr C:\\Z\\\*.sbr \/o c:\\whatever\_directory\\combined.bsc para criar o arquivo de combinação de .bsc.  
  
## Consulte também  
 [Ferramentas de compilação do C\/C\+\+](../Topic/C-C++%20Build%20Tools.md)   
 [Referência de BSCMAKE](../../build/reference/bscmake-reference.md)