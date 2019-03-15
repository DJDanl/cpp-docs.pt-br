---
title: Arquivos criados para projetos CLR
ms.date: 11/04/2016
helpviewer_keywords:
- Visual C++ projects, CLR programming
- .NET applications, C++
ms.assetid: 59ae9020-5f26-4ad0-bbdd-97c2e2023a20
ms.openlocfilehash: 8c3e4b4187e507f7e52f8764b546f85258902879
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824595"
---
# <a name="files-created-for-clr-projects"></a>Arquivos criados para projetos CLR

Quando você usa modelos do Visual C++ para criar seus projetos, vários arquivos são criados, dependendo do modelo utilizado. A tabela a seguir lista todos os arquivos criados pelos modelos de projeto para projetos do .NET Framework.

|Nome do arquivo|Descrição do arquivo|
|---------------|----------------------|
|AssemblyInfo.cpp|O arquivo que contém informações (ou seja, atributos, arquivos, recursos, tipos, informações de controle de versão, informações de autenticação e assim por diante) para modificar os metadados do assembly do projeto. Para obter mais informações, confira [Conceitos de assembly](/dotnet/framework/app-domains/assembly-contents).|
|*nome_do_projeto*.asmx|Um arquivo de texto que referencia as classes gerenciadas que encapsulam a funcionalidade do serviço Web XML.|
|*nome_do_projeto*.cpp|O arquivo de origem principal e o ponto de entrada para o aplicativo que o Visual Studio criou para você. Identifica o arquivo .dll e o namespace do projeto. Forneça seu próprio código nesse arquivo.|
|*nome_do_projeto*.vsdisco|Um arquivo de implantação XML que contém links para outros recursos que descrevem o serviço Web XML.|
|*nome_do_projeto*.h|O arquivo de inclusão principal do projeto, que contém todas as declarações, símbolos globais e diretivas `#include` para outros arquivos de cabeçalho.|
|*nome_do_projeto*.sln|O arquivo de solução usado no ambiente de desenvolvimento para organizar todos os elementos do projeto em uma única solução.|
|*nome_do_projeto*.suo|O arquivo de opções de solução usado no ambiente de desenvolvimento.|
|*nome_do_projeto*.vcxproj|O arquivo de projeto usado no ambiente de desenvolvimento que armazena as informações específicas a esse projeto.|
|ReadMe.txt|Um arquivo que descreve cada arquivo no projeto que usa os nomes de arquivo reais criados pelo modelo.|