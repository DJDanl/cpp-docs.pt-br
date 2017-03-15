---
title: "Basic Mechanics of Attributes | Microsoft Docs"
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
  - "attributes [C++], inserting in code"
  - "attributes [C++], about attributes"
ms.assetid: dc2069c3-b9f3-4a72-965c-4e5208ce8e34
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Basic Mechanics of Attributes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Existem três maneiras de inserir os atributos em seu projeto.  Primeiro, você pode inseri\-los manualmente no seu código\-fonte.  Em segundo lugar, você pode inseri\-los usando a grade de propriedades de um objeto em seu projeto.  Finalmente, você pode inseri\-los usando a vários assistentes.  Para obter mais informações sobre como usar a janela de propriedades e os vários assistentes, consulte  [Criando e gerenciando projetos do Visual C\+\+](../ide/creating-and-managing-visual-cpp-projects.md).  
  
 Iniciando com o Visual C\+\+.NET, o compilador reconhece a presença de atributos em um arquivo de origem e é capaz de analisar e verificá\-los durante a compilação dinamicamente.  
  
 Como antes, quando o projeto é construído, o compilador analisa cada arquivo de origem do C\+\+, produzindo um arquivo de objeto.  No entanto, quando o compilador encontra um atributo, ele é analisado e sintaticamente verificado.  O compilador chama dinamicamente um provedor de atributo para inserir o código ou fazer outras modificações em tempo de compilação.  A implementação do provedor difere dependendo do tipo do atributo.  Por exemplo, os atributos relacionados ao ATL são implementados por Atlprov.dll.  
  
 A figura a seguir demonstra a relação entre o compilador e o provedor de atributo.  
  
 ![Gráfico de comunicação do atributo de componente](../windows/media/vccompattrcomm.png "vcCompAttrComm")  
  
> [!NOTE]
>  Uso do atributo não altera o conteúdo do arquivo de origem.  O único momento em que o código gerado do atributo fica visível é durante sessões de depuração.  Além disso, para cada arquivo de origem no projeto, você pode gerar um arquivo de texto que exibe os resultados da substituição de atributo.  Para obter mais informações sobre este procedimento, consulte  [\/Fx \(mesclar código injetado\)](../build/reference/fx-merge-injected-code.md) e  [Depuração código injetado](../Topic/How%20to:%20Debug%20Injected%20Code.md).  
  
 Como a maioria das construções de C\+\+, os atributos têm um conjunto de características que define seu uso correto.  Isso é conhecido como o contexto do atributo e é abordado a tabela de atributos de contexto para cada tópico de referência de atributo.  Por exemplo, o  [coclass](../windows/coclass.md) atributo só pode ser aplicado a uma classe existente ou estrutura, em oposição a  [cpp\_quote](../Topic/cpp_quote.md) atributo, que pode ser inserido em qualquer lugar em um arquivo de origem do C\+\+.  
  
## Consulte também  
 [Concepts](../windows/attributed-programming-concepts.md)