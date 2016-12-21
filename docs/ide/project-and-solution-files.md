---
title: "Arquivos de projeto e solu&#231;&#227;o | Microsoft Docs"
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
  - "vc.files.projectandsolution"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".sdf, navegando pelo arquivo do banco de dados"
  - "navegando pelo arquivo do banco de dados, .sdf"
  - "tipos de arquivo [C++], makefiles"
  - "tipos de arquivo [C++], arquivos de projeto"
  - "projetos Makefile"
  - "arquivos de projeto [C++]"
ms.assetid: 5823b954-36cf-42d3-8fd5-25bab3ef63d9
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos de projeto e solu&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os seguintes arquivos são criados quando você cria um projeto no Visual Studio.  Eles são usados para gerenciar arquivos de projeto na solução.  
  
|Nome do arquivo|Local do diretório|Local do Solution Explorer|Descrição|  
|---------------------|------------------------|--------------------------------|---------------|  
|*Solname*. sln|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *solução* arquivo.  Organiza todos os elementos de um projeto ou vários projetos em uma solução.|  
|*NomeDoProjeto*. suo|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *Opções de solução* arquivo.  Ele armazena suas personalizações para a solução para que sempre que você abrir um arquivo ou projeto na solução, ele tem a aparência e o comportamento desejado.|  
|*NomeDoProjeto*vcxproj|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *projeto* arquivo.  Ele armazena informações específicas para cada projeto.  \(Em versões anteriores, esse arquivo foi nomeado *NomeDoProjeto*. vcproj ou *NomeDoProjeto*.dsp.\) Para obter um exemplo de um arquivo de projeto do Visual C\+\+, consulte [Arquivos de projeto](../ide/project-files.md).|  
|*NomeDoProjeto*. sdf|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *banco de dados de navegação* arquivo.  Ele oferece suporte a recursos de pesquisa e navegação como **Ir para definição**, **Localizar todas as referências**, e **Class View**.  Ele é gerado ao analisar os arquivos de cabeçalho.|  
|*NomeDoProjeto.*vcxproj.Filters|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *filtros* arquivo.  Especifica onde colocar um arquivo que é adicionado à solução.  Por exemplo, um arquivo. h é colocado **arquivos de cabeçalho** nó.|  
|*NomeDoProjeto.*vcxproj|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *usuário migração* arquivo.  Depois que um projeto é migrado do Visual Studio 2008, esse arquivo contém informações que foi convertidas de qualquer arquivo. vsprops.|  
|*NomeDoProjeto*. idl|*NomeDoProjeto*|Origem|\(Específico do projeto\) Contém o código\-fonte linguagem de descrição de Interface \(IDL\) para uma biblioteca de tipos de controle.  Esse arquivo é usado pelo Visual C\+\+ para gerar uma biblioteca de tipos.  A biblioteca gerada expõe a interface do controle para outros clientes de automação.  Para obter mais informações, consulte [arquivo de definição de Interface \(IDL\)](http://msdn.microsoft.com/library/windows/desktop/aa378712) no [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)].|  
|Readme. txt|*NomeDoProjeto*|Projeto|O *Leia\-me* arquivo.  Ele é gerado pelo Assistente de aplicativo e descreve os arquivos em um projeto.|  
  
## Consulte também  
 [Tipos de arquivo criados para projetos do Visual C\+\+](../ide/file-types-created-for-visual-cpp-projects.md)