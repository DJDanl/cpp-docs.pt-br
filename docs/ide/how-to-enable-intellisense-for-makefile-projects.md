---
title: "Como habilitar o IntelliSense para projetos de makefile | Microsoft Docs"
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
  - "VC.Project.VCNMakeTool.IntelliSense"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "IntelliSense, projetos Makefile"
  - "projetos Makefile, IntelliSense"
ms.assetid: 9443f453-f18f-4f12-a9a1-ef9dbf8b188f
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como habilitar o IntelliSense para projetos de makefile
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Falha de IntelliSense para operar no IDE para projetos do Visual C\+\+ makefile quando determinadas configurações ou opções do compilador do projeto é configurada incorretamente.  Use este procedimento para configurar projetos makefile do Visual C\+\+, para que o IntelliSense funciona quando os projetos makefile estão abertos no ambiente de desenvolvimento Visual Studio.  
  
### Para habilitar o IntelliSense para projetos makefile no IDE  
  
1.  Abrir o  **Páginas de propriedades** caixa de diálogo.  Para obter detalhes, consulte:[Como abrir páginas de propriedade do projeto](../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o  **Propriedades de configuração** nó.  
  
3.  Selecione o  **NMake** propriedade da página e, em seguida, modificar propriedades em  **IntelliSense** conforme apropriado.  
  
    -   Definir o  **Definições do pré\-processador** propriedade para definir quaisquer símbolos pré\-processador do projeto makefile.  Consulte [\/D \(definições de pré\-processador\)](../build/reference/d-preprocessor-definitions.md), para obter mais informações.  
  
    -   Definir o  **Caminho de pesquisa incluem** propriedade para especificar a lista de pastas que o compilador pesquisará para resolver referências de arquivo que são passadas para as diretivas de pré\-processamento do projeto makefile.  Consulte [\/I \(diretórios de inclusão adicionais\)](../build/reference/i-additional-include-directories.md), para obter mais informações.  
  
         Para projetos criados com CL.EXE a partir de uma janela de comando, defina a  **INCLUDE** a variável de ambiente para especificar os diretórios que o compilador pesquisará para resolver referências de arquivo que são passadas para as diretivas de pré\-processamento do projeto makefile.  
  
    -   Definir o  **Forçada inclui** propriedade para especificar qual cabeçalho arquivos ao processo ao construir seu projeto makefile.  Consulte [\/FI \(Arquivo de inclusão forçado do nome\)](../Topic/-FI%20\(Name%20Forced%20Include%20File\).md), para obter mais informações.  
  
    -   Definir o  **Caminho de pesquisa de Assembly** propriedade para especificar a lista de pastas que o compilador pesquisará para resolver referências a.NET assemblies em seu projeto.  Consulte [\/AI \(especificar diretórios de metadados\)](../build/reference/ai-specify-metadata-directories.md), para obter mais informações.  
  
    -   Definir o  **Forçada usando Assemblies** propriedade para especificar quais.NET usados para processar ao construir seu projeto makefile.  Consulte [\/FU \(nome forçado \#usando arquivo\)](../build/reference/fu-name-forced-hash-using-file.md), para obter mais informações.  
  
    -   Definir o  **Opções adicionais de** propriedade para especificar opções adicionais do compilador a ser usado pelo Intellisense ao analisar arquivos C\+\+.  
  
4.  Clique **OK** para fechar as páginas de propriedades.  
  
5.  Use o  **Salvar tudo** comando para salvar as configurações do projeto modificado.  
  
 Na próxima vez que você abra o projeto makefile no ambiente de desenvolvimento Visual Studio, execute o  **Limpar solução** comando e, em seguida o  **Build Solution** no seu projeto makefile.  IntelliSense deve funcionar corretamente no IDE.  
  
## Consulte também  
 [Usando IntelliSense](../Topic/Using%20IntelliSense.md)   
 [Referência de NMAKE](../build/nmake-reference.md)   
 [Como criar um projeto do C\+\+ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)