---
title: Recomendações para escolher uma classe de coleção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- type safety of collection classes [MFC]
- collection classes [MFC], serialization
- collection classes [MFC], speed
- collection classes [MFC], type safety
- collection classes [MFC], choosing
- collection classes [MFC], functionality
- shapes, collection
- collection classes [MFC], template-based
- MFC collection classes [MFC], characteristics
- collection classes [MFC], about collection classes [MFC]
- serialization [MFC], collection classes
- collection classes [MFC], duplicates allowed
- collection classes [MFC], shapes
ms.assetid: a82188cd-443f-40d8-a244-edf292a53db4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 28527f9668b9ca6a9ef00cf399a04ce9bad65716
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33353126"
---
# <a name="recommendations-for-choosing-a-collection-class"></a>Recomendações para escolher uma classe de coleção
Este artigo contém informações detalhadas, projetadas para ajudá-lo a escolher uma classe de coleção para suas necessidades de aplicativo específico.  
  
 Sua escolha de uma classe de coleção depende de vários fatores, incluindo:  
  
-   Os recursos da forma classe: ordem, indexação e desempenho, conforme mostrado no [recursos do conjunto de forma](#_core_collection_shape_features) tabela mais adiante neste tópico  
  
-   Se a classe usar modelos do C++  
  
-   Se os elementos armazenados na coleção podem ser serializados  
  
-   Se os elementos armazenados na coleção podem ser despejados para diagnóstico  
  
-   Se a coleção é fortemente tipado  
  
 A tabela a seguir, [recursos do conjunto de forma](#_core_collection_shape_features), resume as características das formas de coleção disponíveis.  
  
-   Colunas 2 e 3 descrevem cada forma ordenação e características de acesso. Na tabela, o termo "ordenado" significa que a ordem na qual os itens são inseridos e excluídos determina a ordem na coleção; Isso não significa que os itens são classificados em seu conteúdo. O termo "indexed" significa que os itens na coleção podem ser recuperados por um índice de inteiro, como itens em uma matriz típica.  
  
-   Colunas 4 e 5 descrevem o desempenho de cada forma. Em aplicativos que exigem várias inserções na coleção, a velocidade de inserção pode ser especialmente importante; para outros aplicativos, a velocidade de pesquisa pode ser mais importante.  
  
-   Coluna 6 descreve se cada forma permite elementos duplicados.  
  
### <a name="_core_collection_shape_features"></a>  Recursos do conjunto de forma  
  
|Forma|Ordenada|Indexadas|Inserir um elemento|Procure o elemento especificado|Elementos duplicados|  
|-----------|--------------|--------------|-----------------------|----------------------------------|-------------------------|  
|Lista|Sim|Não|Rápido|Reduzir|Sim|  
|Matriz|Sim|Por int|Reduzir|Reduzir|Sim|  
|Mapa|Não|Por chave|Rápido|Rápido|Nenhum (chaves) Sim (valores)|  
  
 A tabela a seguir, [características de Classes de coleção MFC](#_core_characteristics_of_mfc_collection_classes), resume outras características importantes de classes de coleção MFC específicos como um guia para seleção. Sua escolha dependerá se a classe é baseada em modelos do C++, se seus elementos podem ser serializados por meio de documento do MFC [serialização](../mfc/serialization-in-mfc.md) mecanismo, se seus elementos podem ser despejados via MFC do diagnóstico de despejo mecanismo, ou Se a classe é fortemente tipado — ou seja, se você pode garantir que o tipo dos elementos armazenados no e recuperados de uma coleção com base na classe.  
  
### <a name="_core_characteristics_of_mfc_collection_classes"></a>  Características de Classes de coleção MFC  
  
|Classe|Usa C++<br /><br /> modelos|Pode ser<br /><br /> serializado|Pode ser<br /><br /> despejadas|É<br /><br /> segurança de tipo|  
|-----------|------------------------------|---------------------------|-----------------------|-----------------------|  
|`CArray`|Sim|Sim 1|Sim 1|Não|  
|`CByteArray`|Não|Sim|Sim|Sim 3|  
|`CDWordArray`|Não|Sim|Sim|Sim 3|  
|`CList`|Sim|Sim 1|Sim 1|Não|  
|`CMap`|Sim|Sim 1|Sim 1|Não|  
|`CMapPtrToPtr`|Não|Não|Sim|Não|  
|`CMapPtrToWord`|Não|Não|Sim|Não|  
|`CMapStringToOb`|Não|Sim|Sim|Não|  
|`CMapStringToPtr`|Não|Não|Sim|Não|  
|`CMapStringToString`|Não|Sim|Sim|Sim 3|  
|`CMapWordToOb`|Não|Sim|Sim|Não|  
|`CMapWordToPtr`|Não|Não|Sim|Não|  
|`CObArray`|Não|Sim|Sim|Não|  
|`CObList`|Não|Sim|Sim|Não|  
|`CPtrArray`|Não|Não|Sim|Não|  
|`CPtrList`|Não|Não|Sim|Não|  
|`CStringArray`|Não|Sim|Sim|Sim 3|  
|`CStringList`|Não|Sim|Sim|Sim 3|  
|`CTypedPtrArray`|Sim|Depende de 2|Sim|Sim|  
|`CTypedPtrList`|Sim|Depende de 2|Sim|Sim|  
|`CTypedPtrMap`|Sim|Depende de 2|Sim|Sim|  
|`CUIntArray`|Não|Não|Sim|Sim 3|  
|`CWordArray`|Não|Sim|Sim|Sim 3|  
  
 1. Para serializar, você deve chamar explicitamente o objeto de coleção `Serialize` função; para despejar, você deve chamar explicitamente o `Dump` função. Você não pode usar o formulário `ar << collObj` para serializar o formulário ou `dmp` `<< collObj` para despejar.  
  
 2. Serialização depende do tipo de coleção subjacente. Por exemplo, se uma matriz de tipo de ponteiro é baseada em `CObArray`, é serializável; se baseado em `CPtrArray`, não é serializável. Em geral, as classes de "Ptr" não podem ser serializadas.  
  
 3. Se marcado como Sim nessa coluna, uma classe de coleção de nontemplate é fortemente tipado, desde que você use conforme pretendido. Por exemplo, se você armazenar bytes em um `CByteArray`, a matriz é fortemente tipado. Mas se você usá-lo para armazenar caracteres, segurança de tipos é menos certo.  
  
## <a name="see-also"></a>Consulte também  
 [Coleções](../mfc/collections.md)   
 [Classes com base no modelo](../mfc/template-based-classes.md)   
 [Como: fazer uma coleção fortemente tipada](../mfc/how-to-make-a-type-safe-collection.md)   
 [Acessando todos os membros de uma coleção](../mfc/accessing-all-members-of-a-collection.md)

