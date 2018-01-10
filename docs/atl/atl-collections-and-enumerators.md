---
title: "ATL coleções e enumeradores | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- enumerator interfaces
- collections, ATL classes
- enumerators, ATL classes
- collection interfaces
ms.assetid: b2d37119-3ab2-4e0a-b65b-f377f07e4098
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 52b74f51733947ca46c0ddb1039f92ce7f69e670
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="atl-collections-and-enumerators"></a>Coleções e enumeradores ATL
Um `collection` é um objeto COM que fornece uma interface que permite o acesso a um grupo de itens de dados (dados brutos ou outros objetos). Uma interface que segue os padrões para fornecer acesso a um grupo de objetos é conhecido como um *interface de coleção*.  
  
 No mínimo, interfaces de coleção devem fornecer um **contagem** propriedade que retorna o número de itens na coleção, um **Item** propriedade que retorna um item da coleção com base em um índice e um `_NewEnum` propriedade que retorna um enumerador para a coleção. Opcionalmente, as interfaces de coleção podem fornecer **adicionar** e **remover** métodos para permitir que os itens a serem inseridos ou removidos da coleção e um **limpar** método para remover todos os itens.  
  
 Um `enumerator` é um objeto COM que fornece uma interface para iteração por meio de itens em uma coleção. Interfaces de enumerador fornecem acesso de série para os elementos de uma coleção por meio de quatro métodos necessários: `Next`, **ignorar**, **redefinir**, e `Clone`.  
  
 Você pode aprender mais sobre as interfaces de enumerador, leia sobre o típico (mas inteiramente imaginário) [IEnumXXXX](https://msdn.microsoft.com/library/ms680089.aspx) interface.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Classes de coleção e enumerador da ATL](../atl/atl-collection-and-enumerator-classes.md)  
 Brevemente descreve e fornece links para as classes ATL que ajudarão você a implementam coleções e enumeradores.  
  
 [Princípios de design para interfaces de coleção e enumerador](../atl/design-principles-for-collection-and-enumerator-interfaces.md)  
 Descreve os princípios de design diferentes em cada tipo de interface.  
  
 [Implementando uma coleção baseada na biblioteca padrão C++](../atl/implementing-an-stl-based-collection.md)  
 Um exemplo estendido que orienta a implementação de um conjunto de biblioteca padrão C++.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.  
  
 [Exemplo de ATLCollections](../visual-cpp-samples.md)  
 Um exemplo que demonstra o uso de `ICollectionOnSTLImpl` e `CComEnumOnSTL`e a implementação de classes de política personalizada de cópia.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)

