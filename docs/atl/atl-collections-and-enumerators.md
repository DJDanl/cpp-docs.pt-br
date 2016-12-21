---
title: "Cole&#231;&#245;es e enumeradores ATL | Microsoft Docs"
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
  - "interfaces de coleção"
  - "coleções, classes da ATL"
  - "interfaces de enumerador"
  - "enumeradores, classes da ATL"
ms.assetid: b2d37119-3ab2-4e0a-b65b-f377f07e4098
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cole&#231;&#245;es e enumeradores ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`collection` é um objeto COM que fornece uma interface que permite o acesso a um grupo de itens de dados \(dados brutos ou outros objetos.\)  Uma interface que segue o padrão para fornecer acesso a um grupo de objetos é conhecida como *uma interface de coleção*.  
  
 Por o menos, as interfaces de coleção devem fornecer uma propriedade de **Contagem** que retorna o número de itens na coleção, em uma propriedade de **Item** que retorna um item da coleção baseada em um índice, e uma propriedade de `_NewEnum` que retorna um enumerador para a coleção.  Opcionalmente, as interfaces de coleção podem fornecer **Adicionar** e métodos de **Remover** para permitir que os itens são inseridos em ou excluídos da coleção, e um método de **Limpar** para remover todos os itens.  
  
 `enumerator` é um objeto COM que fornece uma interface para percorrer os itens em uma coleção.  As interfaces de enumerador serial fornecem acesso aos elementos de uma coleção via quatro métodos necessários: `Next`, **Ignorar**, **Redefinir**, e `Clone`.  
  
 Você pode aprender mais sobre interfaces de enumerador ler sobre a interface arquétipa \(mas totalmente imaginária\) [IEnumXXXX](https://msdn.microsoft.com/en-us/library/ms680089.aspx).  
  
## Nesta seção  
 [Classes de coleção e o enumerador de ATL](../atl/atl-collection-and-enumerator-classes.md)  
 Descreve resumidamente e fornece links para classes de ATL que ajudarão ao implementar coleções e enumeradores.  
  
 [Noções básicas de criação de interfaces de coleção e enumerator](../atl/design-principles-for-collection-and-enumerator-interfaces.md)  
 Descreve os conceitos básicos de design diferentes de apoio cada tipo de interface.  
  
 [Implementando uma coleção com base STL\-](../atl/implementing-an-stl-based-collection.md)  
 Um exemplo estendido que irá conduzi\-lo pela implementação de uma coleção com base em \(STL\) de biblioteca de modelo de padrão.  
  
## Seções relacionadas  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando a biblioteca ativa do modelo.  
  
 [exemplo de ATLCollections](../top/visual-cpp-samples.md)  
 Um exemplo que demonstra o uso de `ICollectionOnSTLImpl` e de `CComEnumOnSTL`, e a implementação da diretiva personalizado de impressão classe.  
  
## Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)