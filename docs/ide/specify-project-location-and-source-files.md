---
title: "Especificar local do projeto e arquivos de origem, Assistente para Criar Novo Projeto de Arquivos de C&#243;digo Existentes | Microsoft Docs"
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
  - "vc.appwiz.importwiz.location"
dev_langs: 
  - "C++"
ms.assetid: 29ddffb9-5918-4d72-8c7a-a365f9de96dd
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificar local do projeto e arquivos de origem, Assistente para Criar Novo Projeto de Arquivos de C&#243;digo Existentes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use esta página do Assistente para criar novo projeto de arquivos de código existentes para especificar:  
  
-   O caminho do diretório do novo projeto  
  
-   Os diretórios para procurar por arquivos de origem existentes  
  
-   Os tipos de arquivos, que o assistente importará no novo projeto  
  
## Lista de Tarefas  
 [Como criar um projeto do C\+\+ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)  
  
## Lista UIElement  
 **Localização do arquivo de projeto**  
 Especifica o caminho do diretório do novo projeto.  Esse local é onde o assistente irá depositar todos os arquivos \(e subdiretórios\) do novo projeto.  
  
 **Procurar**  
 Exibe o  **local do arquivo de projeto** caixa de diálogo, o que ajuda você a especificar o diretório que conterá o novo projeto.  Este controle permite que você navegue para a pasta desejada.  
  
 **Nome do projeto**  
 Especifica o nome do novo projeto.  Arquivos de projeto, que tem as extensões de arquivo como, por exemplo, .vcxproj venham a adotar esse nome.  Arquivos de código existentes manterá seu nome original.  
  
 **Adicionar arquivos ao projeto dessas pastas**  
 Quando marcado, define o Assistente para copiar arquivos de código existentes de seus diretórios originais \(que são especificados na caixa de listagem abaixo deste controle\) no novo projeto.  
  
 **Adicionar subpastas**  
 Especifica copiar os arquivos de código de todos os subdiretórios do diretório listados  **pasta** coluna no novo projeto.  
  
 **Folder**  
 Indica o caminho para o diretório que contém os arquivos de código existentes para copiar para o novo projeto.  Essa coluna lista todos os diretórios que o assistente irá procurar por arquivos de código existentes.  
  
 **Add**  
 Exibe o  **Adicionar arquivos ao projeto desta pasta** caixa de diálogo que ajuda você a especificar diretórios que o assistente irá procurar por arquivos de código existentes.  
  
 **Remove**  
 Exclui o caminho do diretório selecionado à esquerda da caixa de lista deste controle.  
  
 **Tipos de arquivo para adicionar ao projeto**  
 Especifica os tipos de arquivos que o assistente adicionará o novo projeto com base nas extensões de arquivo determinado.  Extensões de arquivo são precedidas com o caractere curinga asterisco e na lista de extensões de arquivo, por um ponto e vírgula.  
  
 **Mostrar todos os arquivos no Solution Explorer**  
 Especifica que todos os arquivos no novo projeto seja visível e exibido na janela Solution Explorer.  Essa opção é ativada por padrão.