---
title: "Arquivos de solução e projeto | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.files.projectandsolution
dev_langs: C++
helpviewer_keywords:
- project files [C++]
- file types [C++], makefiles
- .sdf, browsing database file
- Makefile projects
- browsing database file, .sdf
- file types [C++], project files
ms.assetid: 5823b954-36cf-42d3-8fd5-25bab3ef63d9
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 498f4404f0b3f6b291eca0e78315d2a010cbf846
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="project-and-solution-files"></a>Arquivos de projeto e solução
Os seguintes arquivos são criados quando você cria um projeto no Visual Studio. Eles são usados para gerenciar arquivos de projeto na solução.  
  
|Filename|Local do diretório|Local do Gerenciador de solução|Descrição|  
|--------------|------------------------|--------------------------------|-----------------|  
|*Solname*. sln|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *solução* arquivo. Organiza todos os elementos de um projeto ou vários projetos em uma solução.|  
|*NomeDoProjeto*. suo|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *opções solução* arquivo. Ele armazena as personalizações para a solução para que sempre que você abrir um arquivo ou projeto na solução, ele tem a aparência e o comportamento desejado.|  
|*NomeDoProjeto*. vcxproj|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *projeto* arquivo. Ele armazena informações específicas para cada projeto. (Nas versões anteriores, este arquivo foi nomeado *NomeDoProjeto*. vcproj ou *NomeDoProjeto*. DSP.) Para obter um exemplo de um arquivo de projeto do Visual C++, consulte [arquivos de projeto](../ide/project-files.md).|  
|*NomeDoProjeto*.vcxitems|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *itens compartilhados projeto* arquivo. Este projeto não está compilado.  Em vez disso, o projeto pode ser referenciado por outro projeto de C++ e seus arquivos se tornará parte do processo de compilação do projeto de referência. Isso pode ser usado para compartilhar código comum com projetos do C++ de plataforma cruzada.|
|*NomeDoProjeto*. sdf|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *pesquisa no banco de dados* arquivo. Ele oferece suporte a recursos de pesquisa e navegação como **ir para definição**, **localizar todas as referências**, e **exibição de classe**. Analisando os arquivos de cabeçalho é gerado.|  
|*NomeDoProjeto.* vcxproj.filters|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *filtros* arquivo. Especifica onde colocar um arquivo que é adicionado à solução. Por exemplo, um arquivo. h é colocado **arquivos de cabeçalho** nó.|  
|*NomeDoProjeto.* vcxproj.user|*NomeDoProjeto*|Não é exibido no Gerenciador de soluções|O *usuário migração* arquivo. Depois que um projeto é migrado do Visual Studio 2008, esse arquivo contém informações que foi convertidas a partir de qualquer arquivo. vsprops.|  
|*NomeDoProjeto*. idl|*NomeDoProjeto*|Origem|(Específicos do projeto) Contém o código de origem de linguagem de descrição de Interface (IDL) para uma biblioteca de tipos de controle. Esse arquivo é usado pelo Visual C++ para gerar uma biblioteca de tipos. A biblioteca gerada expõe a interface do controle para outros clientes de automação. Para obter mais informações, consulte [arquivo IDL (Interface Definition)](http://msdn.microsoft.com/library/windows/desktop/aa378712) no SDK do Windows.|  
|Leiame. txt|*NomeDoProjeto*|Projeto|O *Leia-me* arquivo. Ele é gerado pelo Assistente de aplicativo e descreve os arquivos em um projeto.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)