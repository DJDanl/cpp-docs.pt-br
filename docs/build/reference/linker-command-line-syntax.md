---
title: "Sintaxe da linha de comando do vinculador | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "ferramenta LINK [C++], sintaxe de linha de comando"
  - "vinculador [C++], sintaxe"
  - "linha de comando de vinculador [C++]"
ms.assetid: e2a31e17-77bd-4e74-9305-75b105b26539
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Sintaxe da linha de comando do vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para executar LINK.EXE, use a seguinte sintaxe de comando:  
  
```  
LINK arguments  
```  
  
 `arguments` inclui opções e nomes de arquivo e pode ser especificado em qualquer ordem.  As opções são processadas primeiro, depois arquivos.  Use um ou mais espaços ou guias para separar argumentos.  
  
> [!NOTE]
>  É possível iniciar esta ferramenta somente usando o prompt de comando [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)].  Não é possível iniciá\-lo a partir de um prompt de comando do sistema ou do gerenciador de arquivos.  
  
 Na linha de comando, uma opção consiste em um especificador da opção, um traço \(–\) ou uma barra \(\/\), seguida pelo nome da opção.  Os nomes de opção não podem ser abreviados.  Algumas opções possuem um argumento especificado, depois de dois\-pontos \(:\).  Nenhum espaço ou a guia são permitidos em uma especificação da opção, exceto em uma cadeia de caracteres entre aspas na opção do \/COMMENT.  Especificar argumentos numéricos em notação decimal do ou do C \- idioma.  Os nomes da opção e seus argumentos da palavra\-chave ou o nome do arquivo não está com diferenciação de maiúsculas e minúsculas, mas identificadores como os argumentos diferenciam maiúsculas de minúsculas.  
  
 Para transmitir um arquivo ao vinculador, especifique o nome de arquivo na linha de comando depois que o comando de LINK.  Você pode especificar um caminho relativo ou absoluto um com o nome do arquivo, e você pode usar curingas o nome do arquivo.  Se você omitir a extensão do ponto \(.\) e nome de arquivo, o LINK assume .obj com a finalidade de localizar o arquivo.  O LINK não usa extensões de nome de arquivo ou a falta delass para fazer suposições sobre o conteúdo dos arquivos; determina o tipo de arquivo por meio do exame do, e o processa de acordo.  
  
 link.exe retorna zero para o êxito \(nenhum erro\).  Caso contrário, o vinculador retorna o número do erro que interrompeu o link.  Por exemplo, se o vinculador gerenciar LNK1104, o vinculador retorna 1104.  Consequentemente, o número mais baixo de erro retornado em um erro pelo vinculador é 1000.  Um valor de retorno 128 representa um problema de configuração com o sistema operacional ou um arquivo de .config; o carregador não foi carregado link.exe ou c2.dll.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)