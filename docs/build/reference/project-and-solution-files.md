---
title: Arquivos de projeto e solução
ms.date: 05/06/2019
helpviewer_keywords:
- project files [C++]
- file types [C++], makefiles
- .sdf, browsing database file
- Makefile projects
- browsing database file, .sdf
- file types [C++], project files
ms.assetid: 5823b954-36cf-42d3-8fd5-25bab3ef63d9
ms.openlocfilehash: 37bfd1a6db2087e97ab76d3d06ed6f56e59b96e3
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65707410"
---
# <a name="project-and-solution-files"></a>Arquivos de projeto e solução

Os arquivos a seguir são criados quando você cria um projeto no Visual Studio. Eles são usados para gerenciar arquivos de projeto na solução.

|Filename|Local do diretório|Local do Gerenciador de Soluções|Descrição|
|--------------|------------------------|--------------------------------|-----------------|
|*Solname*.sln|*Nome_do_projeto*|Não exibido no Gerenciador de Soluções|O arquivo de *solução*. Organiza todos os elementos de um projeto ou de vários projetos em uma só solução.|
|*Nome_do_projeto*.suo|*Nome_do_projeto*|Não exibido no Gerenciador de Soluções|O arquivo de *opções da solução*. Armazena as personalizações da solução, de modo que ele tenha a aparência e o comportamento desejado, sempre que você abrir um projeto ou um arquivo na solução.|
|*Nome_do_projeto*.vcxproj|*Nome_do_projeto*|Não exibido no Gerenciador de Soluções|O arquivo de *projeto*. Armazena informações específicas a cada projeto. (Nas versões anteriores, esse arquivo era nomeado *Nome_do_projeto*.vcproj ou *Nome_do_projeto*.dsp.) Para obter um exemplo de um arquivo de projeto do C++ (.vcxproj), confira [Arquivos de Projeto](project-files.md).|
|*Nome_do_projeto*.vcxitems|*Nome_do_projeto*|Não exibido no Gerenciador de Soluções|O arquivo de *projeto Itens Compartilhados*. O projeto não é compilado.  Em vez disso, ele pode ser referenciado por outro projeto do C++ e seus arquivos se tornarão parte do processo de build do projeto de referência. Isso pode ser usado para compartilhar um código comum com projetos do C++ multiplataforma.|
|*Nome_do_projeto*.sdf|*Nome_do_projeto*|Não exibido no Gerenciador de Soluções|O arquivo de *navegação no banco de dados*. Dá suporte às funcionalidades de procura e de navegação como **Ir para definição**, **Localizar Todas as Referências** e **Modo de Exibição de Classe**. É gerado pela análise dos arquivos de cabeçalho.|
|*Projname*.vcxproj.filters|*Nome_do_projeto*|Não exibido no Gerenciador de Soluções|O arquivo de *filtros*. Especifica o local em que colocar um arquivo adicionado à solução. Por exemplo, um arquivo .h é colocado no nó **Arquivos de Cabeçalho**.|
|*Projname*.vcxproj.user|*Nome_do_projeto*|Não exibido no Gerenciador de Soluções|O arquivo de *usuário de migração*. Depois que um projeto é migrado do Visual Studio 2008, esse arquivo contém informações que foram convertidas de qualquer arquivo .vsprops.|
|*Nome_do_projeto*.idl|*Nome_do_projeto*|Origem|(Específico ao projeto) Contém o código-fonte da linguagem IDL para uma biblioteca de tipos de controle. Esse arquivo é usado pelo Visual C++ para gerar uma biblioteca de tipos. A biblioteca gerada expõe a interface do controle para outros clientes de Automação. Para obter mais informações, confira [Arquivo IDL](/windows/desktop/Rpc/the-interface-definition-language-idl-file) no SDK do Windows.|
|Readme.txt|*Nome_do_projeto*|Projeto|O arquivo *Leiame*. É gerado pelo assistente de aplicativo e descreve os arquivos em um projeto.|

## <a name="see-also"></a>Consulte também

[Tipos de arquivo criados para projetos do Visual Studio C++](file-types-created-for-visual-cpp-projects.md)
