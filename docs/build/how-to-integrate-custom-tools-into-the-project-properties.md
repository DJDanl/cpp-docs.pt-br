---
title: "Como integrar ferramentas personalizar a propriedades de projeto | Microsoft Docs"
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
  - "msbuild.cpp.howto.integratecustomtools"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "msbuild (c++), como integrar ferramentas personalizadas"
ms.assetid: f32d91a4-44e9-4de3-aa9a-1c7f709ad2ee
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Como integrar ferramentas personalizar a propriedades de projeto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode adicionar opções personalizadas de ferramenta para a janela do Visual Studio **Páginas de Propriedades** criando um arquivo XML subjacente do esquema.  
  
 A seção de **Propriedades de Configuração** da janela de **Páginas de Propriedades** exibe os grupos de configurações que são conhecidos como *regras*.  Cada regra contém as configurações para uma ferramenta ou um grupo de recursos.  Por exemplo, a regra de **Vinculador** contém as definições da ferramenta do vinculador.  As configurações em uma regra podem ser subdivididas em *categorias*.  
  
 Este documento explica como criar um arquivo em um diretório de conjunto que contém as propriedades da ferramenta personalizado de forma que elas sejam carregadas quando o Visual Studio é iniciado.  Para obter informações sobre como alterar o arquivo, consulte [Parte da plataforma de 2 Extensibilty](http://go.microsoft.com/fwlink/?LinkID=191489) o blog da equipe do projeto do Visual Studio.  
  
### Para adicionar ou alterar as propriedades do projeto  
  
1.  No editor de XML, crie um arquivo XML.  
  
2.  Salve o arquivo na pasta de %ProgramFiles%\\MSBuild\\Microsoft.Cpp\\v4.0\\ .  Cada regra na janela de **Páginas de Propriedades** é representada por um arquivo XML nessa pasta.  Certifique\-se de que o arquivo é denominado exclusivamente na pasta.  
  
3.  Copie o conteúdo de %ProgramFiles%\\MSBuild\\Microsoft.Cpp\\v4.0\\cl.xml, próximo ele sem salvar as alterações, e colar o conteúdo no novo arquivo XML.  Você pode usar qualquer arquivo de esquema XML – este é apenas um que pode ser usado assim que você começa com um modelo.  
  
4.  No novo arquivo XML, modifique o conteúdo de acordo com seus requisitos.  Não se esqueça de alterar **Nome da regra** e **Rule.DisplayName** no topo do arquivo.  
  
5.  Salvar as alterações e feche o arquivo.  
  
6.  Os arquivos XML em %ProgramFiles%\\MSBuild\\Microsoft.Cpp\\v4.0\\ são carregados quando o é iniciado do Visual Studio.  Em virtude disso, para testar o novo arquivo, reinicie o Visual Studio.  
  
7.  Em **Gerenciador de Soluções**, clique com o botão direito do mouse no projeto e clique em **Propriedades**.  Na janela de **Páginas de Propriedades** , no painel esquerdo, verifique se existe um novo nó com o nome da regra.  
  
## Consulte também  
 [MSBuild \(Visual C\+\+\)](../Topic/MSBuild%20\(Visual%20C++\).md)