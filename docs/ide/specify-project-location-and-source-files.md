---
title: Novo projeto de código existente - arquivos de origem (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.appwiz.importwiz.location
dev_langs:
- C++
ms.assetid: 29ddffb9-5918-4d72-8c7a-a365f9de96dd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d85a7b85996ed307596865a31d55cf4b119e5bd5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="specify-project-location-and-source-files-create-new-project-from-existing-code-files-wizard"></a>Especificar local do projeto e arquivos de origem, Assistente para Criar Novo Projeto de Arquivos de Código Existentes
Use esta página do Assistente para criar novo projeto de arquivos de código existentes para especificar:  
  
-   O caminho do diretório do novo projeto  
  
-   Os diretórios para procurar por arquivos de origem existente  
  
-   Os tipos de arquivos que o assistente serão importados para o novo projeto  
  
## <a name="task-list"></a>Lista de Tarefas  
 [Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Local do arquivo de projeto**  
 Especifica o caminho do diretório do novo projeto. Esse local é onde o assistente irá colocar todos os arquivos (e subdiretórios) do novo projeto.  
  
 **Procurar**  
 Exibe o **local do arquivo de projeto** caixa de diálogo, o que ajuda você a especificar o diretório que conterá o novo projeto. Esse controle permite que você navegue até a pasta desejada.  
  
 **Nome do projeto**  
 Especifica o nome do novo projeto. Arquivos de projeto que têm extensões de arquivo como. vcxproj adotarão esse nome. Arquivos de código existentes manterá seu nome original.  
  
 **Adicionar arquivos ao projeto dessas pastas**  
 Quando marcada, define o Assistente para copiar arquivos de código existentes de seus diretórios originais (que são especificados na caixa de listagem abaixo deste controle) para o novo projeto.  
  
 **Adicionar subpastas**  
 Especifica copiar arquivos de código de todos os subdiretórios do diretório listados **pasta** coluna para o novo projeto.  
  
 **Pasta**  
 Indica o caminho para o diretório que contém arquivos de código existente para copiar para o novo projeto. Esta coluna lista todos os diretórios que o assistente irá procurar por arquivos de código existentes.  
  
 **Adicionar**  
 Exibe o **adicionar arquivos ao projeto desta pasta** caixa de diálogo que ajuda você os especificar diretórios que o assistente irá procurar por arquivos de código existentes.  
  
 **Removerr**  
 Exclui o caminho do diretório que está selecionado na parte esquerda da caixa de lista deste controle.  
  
 **Tipos de arquivo para adicionar ao projeto**  
 Especifica os tipos de arquivos que o assistente adicionará ao novo projeto com base nas extensões de arquivo fornecido. Extensões de arquivo são precedidas com o caractere curinga asterisco e são delimitadas por ponto e vírgula na lista de extensões de arquivo.  
  
 **Mostrar todos os arquivos no Gerenciador de soluções**  
 Especifica que todos os arquivos no novo projeto a ser exibido e visíveis na janela do Gerenciador de soluções. Essa opção é habilitada por padrão.