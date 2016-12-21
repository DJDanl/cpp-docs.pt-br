---
title: "Documenta&#231;&#227;o XML (Visual C++) | Microsoft Docs"
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
  - "/// delimitador para documentação C++"
  - "comentários, Arquivos de código fonte C++"
  - "documentação XML"
  - "XML, comentários da documentação no código fonte"
ms.assetid: a1aec1c5-b2d1-4c74-83ae-1dbbbb76b506
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Documenta&#231;&#227;o XML (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em Visual C\+\+, você pode adicionar comentários ao código\-fonte que será processado para um arquivo .xml.  Este arquivo pode ser entrada a um processo que criar documentação para as classes em seu código.  
  
 Em um arquivo de código Visual C\+\+, comentários de documentação XML devem ser localizadas diretamente antes de um método ou uma definição de tipo.  Comentários podem ser usados para preencher a dica de dados do Intellisense QuickInfo nas seguintes situações:  
  
1.  quando o código é compilado como um componente de Tempo de Execução do Windows com um arquivo de rastreamento de .winmd  
  
2.  quando o código\-fonte está incluído no projeto atual  
  
3.  em uma biblioteca cujas declarações e as implementações de tipo são posicionadas no mesmo arquivo de cabeçalho  
  
> [!NOTE]
>  Na versão atual, os comentários de código não são processados nos modelos ou em qualquer coisa que contêm um tipo de modelo \(por exemplo, uma função que aceita um parâmetro como um modelo\).  Como adicionar comentários resultará em comportamento indefinido.  
  
 Para obter detalhes sobre como criar um arquivo .xml com comentários de documentação, consulte os seguintes tópicos.  
  
|Para obter informações sobre LINQ|Consulte|  
|---------------------------------------|--------------|  
|As opções de compilador usar|[\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md)|  
|Marcas que você pode usar para fornecer funcionalidades comumente usadas na documentação|[Marcas recomendadas para comentários de documentação](../Topic/Recommended%20Tags%20for%20Documentation%20Comments%20\(Visual%20C++\).md)|  
|As cadeias de caracteres de identificação que o compilador gera para identificar as compilações no seu código|[Processando o arquivo.xml](../ide/dot-xml-file-processing.md)|  
|Como limitar marcas de documentação|[Delimitadores para marcas de documentação do Visual C\+\+](../ide/delimiters-for-visual-cpp-documentation-tags.md)|  
|Gerando um arquivo .xml de um ou mais arquivos de .xdc.|[Referência de XDCMake](../ide/xdcmake-reference.md)|  
|Links para informações sobre XML como ele se relaciona as áreas de recurso do Visual Studio|[XML no Visual Studio](../Topic/XML%20Tools%20in%20Visual%20Studio.md)|  
  
 Se você precisa colocar XML caracteres especiais no texto de um comentário de documentação, você deve usar entidades XML ou uma seção CDATA.  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)