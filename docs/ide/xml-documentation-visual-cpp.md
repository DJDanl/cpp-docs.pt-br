---
title: "Documentação XML (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- XML documentation
- XML, documentation comments in source code
- comments, C++ source code files
- /// delimiter for C++ documentation
ms.assetid: a1aec1c5-b2d1-4c74-83ae-1dbbbb76b506
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 17853a43d3a94be779b659b0da825467fa66f61c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="xml-documentation-visual-c"></a>Documentação XML (Visual C++)
No Visual C++, você pode adicionar comentários no código-fonte que será processado para um arquivo. XML. Esse arquivo pode ser a entrada para um processo que cria documentação para as classes no seu código.  
  
 Em um arquivo de código do Visual C++, comentários de documentação XML devem estar localizados antes de uma definição de método ou tipo. Os comentários podem ser usados para popular a dica de dados do Intellisense QuickInfo nos seguintes cenários:  
  
1.  Quando o código é compilado como um componente de tempo de execução do Windows com um arquivo. winmd relacionado  
  
2.  Quando o código-fonte está incluído no projeto atual  
  
3.  em uma biblioteca cujo declarações de tipo e implementações está localizada no mesmo arquivo de cabeçalho  
  
> [!NOTE]
>  Na versão atual, os comentários de código não são processados em modelos ou qualquer coisa que contém um tipo de modelo (por exemplo, uma função levando a um parâmetro como um modelo). Adicionar esses comentários resultará em um comportamento indefinido.  
  
 Para obter detalhes sobre como criar um arquivo. XML com comentários de documentação, consulte os tópicos a seguir.  
  
|Para obter informações sobre|Consulte|  
|---------------------------|---------|  
|As opções do compilador para usar|[/doc](../build/reference/doc-process-documentation-comments-c-cpp.md)|  
|Você pode usar para fornecer mais as marcas usadas funcionalidade na documentação|[Marcas recomendadas para comentários de documentação](../ide/recommended-tags-for-documentation-comments-visual-cpp.md)|  
|As cadeias de caracteres de ID que o compilador gera para identificar as construções em seu código|[Processando o arquivo. XML](../ide/dot-xml-file-processing.md)|  
|Como delimitar marcações de documentação|[Delimitadores de marcas de documentação para o Visual C++](../ide/delimiters-for-visual-cpp-documentation-tags.md)|  
|Gerando um arquivo. XML de um ou mais arquivos. XDC.|[Referência XDCMake](../ide/xdcmake-reference.md)|  
|Links para informações sobre XML como ele se relaciona com áreas de recursos do Visual Studio|[XML no Visual Studio](/visualstudio/xml-tools/xml-tools-in-visual-studio)|  
  
 Se você precisa colocar os caracteres especiais de XML no texto de um comentário de documentação, você deve usar entidades XML ou uma seção CDATA.  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)