---
title: Novo Projeto com base em um Código Existente – Arquivos de Origem (Visual C++) | Microsoft Docs
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
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33338689"
---
# <a name="specify-project-location-and-source-files-create-new-project-from-existing-code-files-wizard"></a>Especificar local do projeto e arquivos de origem, Assistente para Criar Novo Projeto de Arquivos de Código Existentes
Use esta página do Assistente para Criar Novo Projeto com base em Arquivos de Código Existentes para especificar:  
  
-   O caminho do diretório do novo projeto  
  
-   Os diretórios a serem pesquisados por arquivos de origem existentes  
  
-   Os tipos de arquivos que o assistente importará para o novo projeto  
  
## <a name="task-list"></a>Lista de Tarefas  
 [Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Local do arquivo de projeto**  
 Especifica o caminho do diretório do novo projeto. Esse é o local em que o assistente colocará todos os arquivos (e subdiretórios) do novo projeto.  
  
 **Procurar**  
 Exibe a caixa de diálogo **Local do arquivo de projeto**, que ajuda você a especificar o diretório que conterá o novo projeto. Esse controle permite que você navegue para a pasta desejada.  
  
 **Nome do projeto**  
 Especifica o nome do novo projeto. Os arquivos de projeto, que têm extensões de arquivo como .vcxproj, adotarão esse nome. Os arquivos de código existentes manterão seus nomes originais.  
  
 **Adicionar arquivos ao projeto destas pastas**  
 Quando essa opção é marcada, define o assistente para copiar os arquivos de código existentes de seus diretórios originais (que são especificados na caixa de listagem abaixo desse controle) para o novo projeto.  
  
 **Adicionar Subpastas**  
 Especifica que os arquivos de código serão copiados de todos os subdiretórios do diretório listado na coluna **Pasta** para o novo projeto.  
  
 **Pasta**  
 Indica o caminho para o diretório que contém os arquivos de código existentes a serem copiados para o novo projeto. Essa coluna lista todos os diretórios que o assistente pesquisará por arquivos de código existentes.  
  
 **Adicionar**  
 Exibe a caixa de diálogo **Adicionar Arquivos ao projeto desta pasta**, que ajuda você a especificar os diretórios que o assistente pesquisará por arquivos de código existentes.  
  
 **Removerr**  
 Exclui o caminho do diretório selecionado à esquerda da caixa de listagem desse controle.  
  
 **Tipos de arquivos a serem adicionados ao projeto**  
 Especifica os tipos de arquivos que o assistente adicionará ao novo projeto com base nas extensões de arquivo fornecidas. As extensões de arquivos são precedidas com o caractere curinga asterisco e delimitadas por ponto e vírgula na lista de extensões de arquivo.  
  
 **Mostrar todos os arquivos no Gerenciador de Soluções**  
 Especifica que todos os arquivos do novo projeto estarão visíveis e serão exibidos na janela Gerenciador de Soluções. Essa opção é habilitada por padrão.