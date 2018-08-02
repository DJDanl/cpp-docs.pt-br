---
title: Mecânica básica dos atributos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++], inserting in code
- attributes [C++], about attributes
ms.assetid: dc2069c3-b9f3-4a72-965c-4e5208ce8e34
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3bb7ff68f9c17f7b90261c2c96630911454842a5
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39462486"
---
# <a name="basic-mechanics-of-attributes"></a>Mecânica básica de atributos
Há três maneiras para inserir atributos no seu projeto. Primeiro, você pode inseri-los manualmente no seu código-fonte. Em segundo lugar, você pode inseri-los usando a grade de propriedade de um objeto em seu projeto. Por fim, você pode inseri-los usando vários assistentes. Para obter mais informações sobre como usar o **propriedades** janela e vários assistentes, consulte [criando e gerenciando projetos do Visual C++](../ide/creating-and-managing-visual-cpp-projects.md).  
  
 Como antes, quando o projeto é compilado, o compilador analisa cada arquivo de origem C++, produzir um arquivo de objeto. No entanto, quando o compilador encontra um atributo, ele é analisado e sintaticamente verificado. O compilador chama dinamicamente um provedor de atributo para inserir código ou fazer outras modificações em tempo de compilação. A implementação do provedor é diferente dependendo do tipo de atributo. Por exemplo, os atributos relacionados à ATL são implementados por Atlprov.dll.  
  
 A figura a seguir demonstra a relação entre o compilador e o provedor de atributo.  
  
 ![Comunicação de atributos do componente](../windows/media/vccompattrcomm.gif "vcCompAttrComm")  
  
> [!NOTE]
>  Uso do atributo não altera o conteúdo do arquivo de origem. É a única vez em que o código gerado do atributo é visível durante as sessões de depuração. Além disso, para cada arquivo de origem no projeto, você pode gerar um arquivo de texto que exibe os resultados da substituição de atributo. Para obter mais informações sobre esse procedimento, consulte [/Fx (mesclar código injetado)](../build/reference/fx-merge-injected-code.md) e [depurando código injetado](/visualstudio/debugger/how-to-debug-injected-code).  
  
 Como a maioria das construções de C++, os atributos têm um conjunto de características que define seu uso adequado. Isso é conhecido como o contexto do atributo e é abordado na tabela de contexto de atributo para cada tópico de referência de atributo. Por exemplo, o [coclass](../windows/coclass.md) atributo só pode ser aplicado a uma classe existente ou estrutura, em vez de [cpp_quote](../windows/cpp-quote.md) atributo, que pode ser inserido em qualquer lugar dentro de um arquivo de origem do C++.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../windows/attributed-programming-concepts.md)