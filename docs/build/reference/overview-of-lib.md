---
title: "Vis&#227;o geral de LIB | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "Lib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LIB [C++], modos"
ms.assetid: e997d423-f574-434f-8b56-25585d137ee0
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vis&#227;o geral de LIB
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O LIB cria bibliotecas padrão, bibliotecas de importação, e arquivos de exportação que você pode usar com [LINK](../../build/reference/linker-options.md) ao criar um programa.  O LIB executar o em um prompt de comando.  
  
 Você pode usar o LIB nos seguintes modos:  
  
-   [Criando ou alterando uma biblioteca de COFF](../../build/reference/managing-a-library.md)  
  
-   [Extraindo um objeto do membro em um arquivo](../../build/reference/extracting-a-library-member.md)  
  
-   [Criando um arquivo de exportação e importação de uma biblioteca](../../build/reference/working-with-import-libraries-and-export-files.md)  
  
 Esses modos são mutuamente exclusivos; você pode usar o LIB em apenas um modo de cada vez.  
  
## Opções de biblioteca  
 A tabela a seguir lista as opções para lib.exe, com um link para mais informações.  
  
 **\/DEF**  
 Crie uma biblioteca de importação e um arquivo de exportação.  
  
 Para obter mais informações, consulte [Compilando uma biblioteca de importação e um arquivo de exportação](../../build/reference/building-an-import-library-and-export-file.md).  
  
 **\/ERRORREPORT**  
 Enviar informações à Microsoft sobre erros internos com lib.exe.  
  
 Para obter mais informações, consulte [Executando LIB](../../build/reference/running-lib.md).  
  
 **\/EXPORT**  
 Exporta uma função do programa.  
  
 Para obter mais informações, consulte [Compilando uma biblioteca de importação e um arquivo de exportação](../../build/reference/building-an-import-library-and-export-file.md).  
  
 **\/EXTRACT**  
 Crie um arquivo do objeto \(.obj\) que contém uma cópia de um membro existente de uma biblioteca.  
  
 Para obter mais informações, consulte [Extraindo um membro da biblioteca](../../build/reference/extracting-a-library-member.md).  
  
 **\/INCLUDE**  
 Adiciona um símbolo à tabela de símbolo.  
  
 Para obter mais informações, consulte [Compilando uma biblioteca de importação e um arquivo de exportação](../../build/reference/building-an-import-library-and-export-file.md).  
  
 **\/LIBPATH**  
 Substitui o caminho da biblioteca de ambiente.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **\/LIST**  
 Exibe informações sobre a biblioteca de saída para a saída padrão.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **\/LTCG**  
 Faz com que a biblioteca a ser criada usando a geração de código de link\- Horas.  
  
 Para obter mais informações, consulte [Executando LIB](../../build/reference/running-lib.md).  
  
 **\/MACHINE**  
 Especifica a plataforma de destino para o programa.  
  
 Para obter mais informações, consulte [Executando LIB](../../build/reference/running-lib.md).  
  
 **\/NAME**  
 Ao criar uma biblioteca de importação, especifique o nome da DLL da biblioteca de importação está sendo criada.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **\/NODEFAULTLIB**  
 Remove uma ou várias bibliotecas padrão da lista de bibliotecas que pesquisa ao resolver referências externas.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **\/NOLOGO**  
 Suprime a exibição da mensagem e o número de versão de direitos autorais de LIB e evita o eco de arquivos de comando.  
  
 Para obter mais informações, consulte [Executando LIB](../../build/reference/running-lib.md).  
  
 **\/OUT**  
 Substitui o nome do arquivo de saída padrão.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **\/REMOVE**  
 Omitir um objeto da biblioteca de saída.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **\/SUBSYSTEM**  
 Informa ao sistema operacional como executar um programa criado vinculando à biblioteca de saída.  
  
 Para obter mais informações, consulte [Gerenciando uma biblioteca](../../build/reference/managing-a-library.md).  
  
 **\/VERBOSE**  
 Detalhes das exibe informações sobre o progresso da sessão, incluindo nomes dos arquivos de .obj que está sendo adicionado.  
  
 Para obter mais informações, consulte [Executando LIB](../../build/reference/running-lib.md).  
  
 **\/WX**  
 Avisos de serem tratados como erros.  
  
 Para obter mais informações, consulte [Executando LIB](../../build/reference/running-lib.md).  
  
## Consulte também  
 [Referência LIB](../../build/reference/lib-reference.md)   
 [Arquivos de entrada LIB](../../build/reference/lib-input-files.md)   
 [Arquivos de saída LIB](../../build/reference/lib-output-files.md)   
 [Outra saída LIB](../../build/reference/other-lib-output.md)   
 [Estrutura de uma biblioteca](../../build/reference/structure-of-a-library.md)