---
title: "Arquivos de recurso (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "tipos de arquivo [C++], arquivos de recurso"
  - "arquivos de recurso"
  - "recursos [C++]"
ms.assetid: 338a4a0f-0c62-4ef1-a34f-5d86262d93a4
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos de recurso (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os recursos são elementos de interface que fornecem informações ao usuário.  Bitmaps, ícones, cursores e barras de ferramentas são todos os recursos.  Alguns recursos podem ser manipulados para executar uma ação, como selecionar um menu ou inserir dados na caixa de diálogo.  
  
 Consulte  [Trabalhando com recursos](../mfc/working-with-resource-files.md) para obter mais informações.  
  
|File name|Local do diretório|Localização do Solution Explorer|Descrição|  
|---------------|------------------------|--------------------------------------|---------------|  
|*Nomedoprojeto*. rc|*Nomedoprojeto*|Arquivos de origem|O arquivo de script de recurso para o projeto.  O arquivo de script de recurso contém o seguinte, dependendo do tipo de projeto e o suporte selecionado para o projeto \(por exemplo, barras de ferramentas, caixas de diálogo ou HTML\):<br /><br /> -   Definição de menu padrão.<br />-   Tabelas de acelerador e a seqüência de caracteres.<br />-   Padrão  **sobre** caixa de diálogo.<br />-   Outras caixas de diálogo.<br />-   Arquivo de ícone \(res\\*nomedoprojeto*. ico\).<br />-   Informações de versão.<br />-   Bitmaps.<br />-   Barra de ferramentas.<br />-   Arquivos HTML.<br /><br /> O arquivo de recursos inclui o arquivo Afxres.rc para os recursos padrão do Microsoft Foundation Class.|  
|Resource.h|*Nomedoprojeto*|Arquivos de cabeçalho|O arquivo de cabeçalho de recursos que inclui definições para os recursos usados pelo projeto.|  
|*Nomedoprojeto*.rc2|*Nomedoprojeto*\\res|Arquivos de origem|O arquivo de script que contém recursos adicionais usados pelo projeto.  Você pode incluir o arquivo .rc2 na parte superior do arquivo. RC do projeto.<br /><br /> Um arquivo de .rc2 é útil para incluir os recursos usados por vários projetos diferentes.  Em vez de criar os mesmos recursos várias vezes para diferentes projetos, você pode colocá\-los em um arquivo de .rc2 e inclua o arquivo de .rc2 no arquivo. rc principal.|  
|*Nomedoprojeto*. def|*Nomedoprojeto*|Arquivos de origem|O arquivo de definição de módulo para um projeto DLL.  Para um controle, ele fornece o nome e a descrição do controle, bem como o tamanho da pilha tempo de execução.|  
|*Nomedoprojeto*. ico|*Nomedoprojeto*\\res|Arquivos de recursos|O arquivo de ícone do projeto ou controle.  Este ícone é exibido quando o aplicativo é minimizado.  Ele também é usado no aplicativo de  **sobre** caixa.  Por padrão, MFC fornece o ícone do MFC e ATL fornece o ícone de ATL.|  
|*Nomedoprojeto*Doc.ico|*Nomedoprojeto*\\res|Arquivos de recursos|O arquivo de ícone para um projeto MFC que inclui suporte para a arquitetura de exibição do documento.|  
|Toolbar.bmp|*Nomedoprojeto*\\res|Arquivos de recursos|O arquivo de bitmap que representa o aplicativo ou controle em uma barra de ferramentas ou uma paleta.  Esse bitmap está incluído no arquivo de recurso do projeto.  A barra de ferramentas inicial e a barra de status são construídos da  **CMainFrame** classe.|  
|Ribbon.mfcribbon\-ms.|*Nomedoprojeto*\\res|Arquivos de recursos|O arquivo de recurso que contém o código XML que define os atributos, controles e botões na faixa de opções.  Para obter mais informações, consulte [Designer da faixa de opções \(MFC\)](../mfc/ribbon-designer-mfc.md).|  
  
## Consulte também  
 [Tipos de arquivo criados para projetos do Visual C\+\+](../ide/file-types-created-for-visual-cpp-projects.md)