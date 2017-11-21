---
title: "Mecânica básica de atributos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- attributes [C++], inserting in code
- attributes [C++], about attributes
ms.assetid: dc2069c3-b9f3-4a72-965c-4e5208ce8e34
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ebf81d5bfb20f151cc8f405fb8346b66451f77e2
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="basic-mechanics-of-attributes"></a>Mecânica básica de atributos
Há três maneiras para inserir atributos no seu projeto. Primeiro, você pode inseri-los manualmente no seu código-fonte. Em segundo lugar, você pode inseri-los usando a grade de propriedades de um objeto em seu projeto. Por fim, você pode inseri-los usando vários assistentes. Para obter mais informações sobre como usar a janela Propriedades e os vários assistentes, consulte [criando e gerenciando projetos do Visual C++](../ide/creating-and-managing-visual-cpp-projects.md).  
  
 Como antes, quando o projeto é compilado, o compilador analisa cada arquivo de origem C++, produzir um arquivo de objeto. No entanto, quando o compilador encontra um atributo, é analisado e sintaticamente verificado. O compilador chama dinamicamente um provedor de atributo para inserir código ou fazer outras modificações em tempo de compilação. A implementação do provedor difere dependendo do tipo de atributo. Por exemplo, os atributos de ATL são implementados por Atlprov.dll.  
  
 A figura a seguir demonstra a relação entre o compilador e o provedor de atributo.  
  
 ![Comunicação do atributo de componente](../windows/media/vccompattrcomm.gif "vcCompAttrComm")  
  
> [!NOTE]
>  Uso do atributo não altera o conteúdo do arquivo de origem. É o único momento em que o código gerado do atributo é visível durante as sessões de depuração. Além disso, para cada arquivo de origem no projeto, você pode gerar um arquivo de texto que exibe os resultados da substituição de atributo. Para obter mais informações sobre esse procedimento, consulte [/Fx (mesclar código injetado)](../build/reference/fx-merge-injected-code.md) e [depurar código injetado](/visualstudio/debugger/how-to-debug-injected-code).  
  
 Como a maioria das construções de C++, atributos têm um conjunto de características que define seu uso adequado. Isso é conhecido como o contexto do atributo e é abordado na tabela de contexto de atributo para cada tópico de referência de atributo. Por exemplo, o [coclass](../windows/coclass.md) atributo só pode ser aplicado a uma classe existente ou a estrutura, em vez do [cpp_quote](../windows/cpp-quote.md) atributo, que pode ser inserido em qualquer lugar em um arquivo de origem C++.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../windows/attributed-programming-concepts.md)