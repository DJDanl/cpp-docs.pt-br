---
title: "Arquivos criados para projetos CLR | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "Aplicativos .NET, C++"
  - "Projetos Visual C++, Programação de CLR"
ms.assetid: 59ae9020-5f26-4ad0-bbdd-97c2e2023a20
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos criados para projetos CLR
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você usa modelos Visual C\+\+ para criar seus projetos, vários arquivos são criados, dependendo do modelo você usar.  A tabela a seguir lista todos os arquivos que são criados por modelos de projeto para projetos do .NET Framework.  
  
|File name|Descrição do arquivo|  
|---------------|--------------------------|  
|AssemblyInfo.cpp|O arquivo que contém informações \(isto é, atributos, arquivos, recursos, tipos, informações de controle de versão, assinando informações, e assim por diante\) para alterar os metadados do assembly de projeto.  Para obter mais informações consulte [Conceitos de assembly](../Topic/Assembly%20Contents.md).|  
|*projname.asmx*|Um arquivo de texto que faz referência às classes gerenciadas que encapsulam funcionalidades de serviço Web XML.|  
|*projname.cpp*|O principal ponto do arquivo de origem e de entrada no aplicativo que o Visual Studio criou para você.  Identifica o arquivo .dll de projeto e o namespace do projeto.  Fornecer seu próprio código no arquivo.|  
|*projname.vsdisco*|Um arquivo de implantação XML que contém links para outros recursos que descrevem o serviço Web XML.|  
|*projname.h*|O main inclui o arquivo para o projeto, que contém todas as declarações, símbolos globais, e políticas de `#include` para outros arquivos de cabeçalho.|  
|*projname.sln*|O arquivo de solução usado dentro do ambiente de desenvolvimento para organizar todos os elementos do projeto em uma única solução.|  
|*projname.suo*|O arquivo das opções de solução usado dentro do ambiente de desenvolvimento.|  
|*projname.vcxproj*|O arquivo de projeto usado dentro do ambiente de desenvolvimento o que armazena informações específicas ao projeto.|  
|ReadMe.txt|Um arquivo que descreve cada arquivo no seu projeto usando os verdadeiros nomes de arquivo criados pelo modelo.|