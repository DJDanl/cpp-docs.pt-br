---
title: Arquivos criados para projetos CLR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Visual C++ projects, CLR programming
- .NET applications, C++
ms.assetid: 59ae9020-5f26-4ad0-bbdd-97c2e2023a20
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b9d66c3f55164a743bc395dc5e9b48f8bcd57654
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="files-created-for-clr-projects"></a>Arquivos criados para projetos CLR
Quando você usar os modelos do Visual C++ para criar seus projetos, vários arquivos são criados, dependendo do modelo que você usa. A tabela a seguir lista todos os arquivos que são criados pelos modelos de projeto para projetos do .NET Framework.  
  
|Nome do arquivo|Descrição do arquivo|  
|---------------|----------------------|  
|AssemblyInfo|O arquivo que contém informações (ou seja, atributos, arquivos, recursos, tipos, informações de controle de versão, as informações de assinatura e assim por diante) para modificar metadados de assembly do projeto. Para obter mais informações, consulte [conceitos de Assembly](/dotnet/framework/app-domains/assembly-contents).|  
|*NomeDoProjeto*. asmx|Um arquivo de texto que referências gerenciadas classes que encapsulam a funcionalidade do serviço Web XML.|  
|*NomeDoProjeto*. cpp|O arquivo de origem principal e ponto de entrada para o aplicativo que o Visual Studio criado para você. Identifica o arquivo. dll de projeto e o namespace do projeto. Fornece seu próprio código nesse arquivo.|  
|*NomeDoProjeto*.vsdisco|Um arquivo de implantação de XML que contém links para outros recursos que descrevem o serviço Web XML.|  
|*NomeDoProjeto*. h|O arquivo de inclusão principal para o projeto que contém todas as declarações, símbolos globais, e `#include` diretivas para outros arquivos de cabeçalho.|  
|*NomeDoProjeto*. sln|O arquivo de solução usado no ambiente de desenvolvimento para organizar todos os elementos de seu projeto em uma única solução.|  
|*NomeDoProjeto*. suo|O arquivo de opções de solução usado dentro do ambiente de desenvolvimento.|  
|*NomeDoProjeto*. vcxproj|O arquivo de projeto usado dentro do ambiente de desenvolvimento que armazena as informações específicas para este projeto.|  
|Leiame. txt|Um arquivo que descreve cada arquivo em seu projeto usando os nomes de arquivo real criados pelo modelo.|