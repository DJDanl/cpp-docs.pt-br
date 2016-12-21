---
title: "Exemplo de confinamento do documento ativo: Office Binder | Microsoft Docs"
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
  - "contêineres de documentos ativos [C++], exemplos"
  - "documentos ativos [C++], contêineres"
  - "contêineres [C++], documento ativo"
  - "exemplos [C++], contenção de documentos ativos"
  - "COM MFC [C++], contenção de documentos ativos"
  - "Office Binder"
ms.assetid: 70dd8568-e8bc-44ac-bf5e-678767efe8e3
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exemplo de confinamento do documento ativo: Office Binder
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A pasta do Microsoft Office é um exemplo de um contêiner ativa do documento.  Uma pasta do Office inclui dois painéis principais, como os contêineres geralmente fazem.  O painel esquerdo contém os ícones que correspondem aos documentos ativas na pasta.  Cada documento é chamado *uma seção* na pasta.  Por exemplo, uma pasta pode conter documentos do word, o Powerpoint arquivos, planilhas do Excel, e assim por diante.  
  
 Clique em um ícone no painel esquerdo ativa o documento ativo correspondente.  O painel direito da pasta exibe o conteúdo do documento ativo atualmente selecionado.  
  
 Se você abrir e ativa um documento do word em uma pasta, a barra de menus e barras de ferramentas do word aparecem na parte superior do quadro na exibição, e você pode editar o conteúdo do documento com qualquer comando ou ferramenta do word.  No entanto, a barra de menus é uma combinação das barras de menus da pasta e do word.  Como a pasta e as palavras têm menus de **Ajuda** , o conteúdo de menus respectivos são mesclados.  Os contêineres ativas do documento como a pasta do Office fornecem automaticamente a mesclagem do menu de **Ajuda** ; para obter mais informações, consulte [A mesclagem do menu ajuda](../Topic/Help%20Menu%20Merging.md).  
  
 Quando você seleciona um documento ativo de outro tipo de aplicativo, a interface da pasta muda para acomodar a do tipo de aplicativo ativa do documento.  Por exemplo, se uma pasta contém uma planilha do Excel, você observará que os menus na pasta se alteram quando você seleciona a seção da planilha do Excel.  
  
 Há, naturalmente, outros tipos possíveis de contêineres ao lado das pastas.  Pesquisador de Arquivos usa a interface comum de dual e o painel no qual o painel esquerdo usa um controle de árvore para exibir uma lista hierárquica de diretórios em uma unidade ou em uma rede, quando o painel direito para exibir os arquivos contidos no diretório selecionado.  Um navegador de Internet tipo de contêiner \(como o Microsoft Internet Explorer\), em vez de usar uma interface de dual e o painel, geralmente tem um único quadro e fornece navegação usando hiperlinks.  
  
## Consulte também  
 [Contenção de documento ativa](../mfc/active-document-containment.md)