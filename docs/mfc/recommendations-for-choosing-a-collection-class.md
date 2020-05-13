---
title: Recomendações para escolher uma classe de coleção
ms.date: 11/04/2016
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
ms.openlocfilehash: 53a4eb3e30048d9dc82722d912a026d63a87586d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371740"
---
# <a name="recommendations-for-choosing-a-collection-class"></a>Recomendações para escolher uma classe de coleção

Este artigo contém informações detalhadas projetadas para ajudá-lo a escolher uma classe de coleta para suas necessidades específicas de aplicativos.

Sua escolha de uma classe de coleta depende de uma série de fatores, incluindo:

- As características da forma da classe: ordem, indexação e desempenho, como mostrado na tabela [Recursos de forma de coleção](#_core_collection_shape_features) mais tarde neste tópico

- Se a classe usa modelos C++

- Se os elementos armazenados na coleção podem ser serializados

- Se os elementos armazenados na coleção podem ser despejados para diagnóstico

- Se a coleção é segura para o tipo

A tabela a seguir, [Collection Shape Features,](#_core_collection_shape_features)resume as características das formas de coleção disponíveis.

- As colunas 2 e 3 descrevem as características de ordem e acesso de cada forma. Na tabela, o termo "ordenado" significa que a ordem em que os itens são inseridos e excluídos determina sua ordem na coleta; isso não significa que os itens estão classificados em seu conteúdo. O termo "indexado" significa que os itens da coleção podem ser recuperados por um índice inteiro, assim como itens em uma matriz típica.

- As colunas 4 e 5 descrevem o desempenho de cada forma. Em aplicações que requerem muitas inserções na coleção, a velocidade de inserção pode ser especialmente importante; para outras aplicações, a velocidade de pesquisa pode ser mais importante.

- A coluna 6 descreve se cada forma permite elementos duplicados.

### <a name="collection-shape-features"></a><a name="_core_collection_shape_features"></a>Características da forma da coleção

|Forma|Encomendado|Indexado|Insira um elemento|Procurar por elemento especificado|Elementos duplicados|
|-----------|--------------|--------------|-----------------------|----------------------------------|-------------------------|
|Lista|Sim|Não|Rápido|Lenta|Sim|
|Array|Sim|Por int|Lenta|Lenta|Sim|
|Mapeamento|Não|Por chave|Rápido|Rápido|Não (chaves) Sim (valores)|

A tabela a seguir, [Características das Classes de Coleção mfc,](#_core_characteristics_of_mfc_collection_classes)resume outras características importantes das classes específicas de coleta de MFC como guia de seleção. Sua escolha pode depender se a classe é baseada em modelos C++, se seus elementos podem ser serializados através do mecanismo [de serialização](../mfc/serialization-in-mfc.md) de documentos da MFC, se seus elementos podem ser despejados através do mecanismo de dumping de diagnóstico da MFC ou se a classe é segura para o tipo — ou seja, se você pode garantir o tipo de elementos armazenados e recuperados de uma coleção com base na classe.

### <a name="characteristics-of-mfc-collection-classes"></a><a name="_core_characteristics_of_mfc_collection_classes"></a>Características das Classes de Coleção mfc

|Classe|Usa C++<br /><br /> modelos|Pode ser<br /><br /> Serializado|Pode ser<br /><br /> Despejado|Is<br /><br /> tipo seguro|
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
|`CTypedPtrArray`|Sim|Depende 2|Sim|Sim|
|`CTypedPtrList`|Sim|Depende 2|Sim|Sim|
|`CTypedPtrMap`|Sim|Depende 2|Sim|Sim|
|`CUIntArray`|Não|Não|Sim|Sim 3|
|`CWordArray`|Não|Sim|Sim|Sim 3|

1. Para serializar, você deve chamar explicitamente `Serialize` a função do objeto de coleta; para despejar, você deve `Dump` explicitamente chamar sua função. Você não pode `ar << collObj` usar o formulário `dmp` `<< collObj` para serializar ou o formulário para despejar.

2. A serlizabilidade depende do tipo de coleta subjacente. Por exemplo, se uma matriz de `CObArray`ponteiro digitada for baseada em , ela é serializável; se baseado `CPtrArray`em, não é serializável. Em geral, as classes "Ptr" não podem ser serializadas.

3. Se marcado Sim nesta coluna, uma classe de coleção sem modelo é segura para o tipo, desde que você a use como pretendido. Por exemplo, se você armazenar `CByteArray`bytes em um , a matriz é segura para o tipo. Mas se você usá-lo para armazenar caracteres, sua segurança do tipo é menos certa.

## <a name="see-also"></a>Confira também

[Coleções](../mfc/collections.md)<br/>
[Classes baseadas em modelos](../mfc/template-based-classes.md)<br/>
[Como fazer uma coleção fortemente tipada](../mfc/how-to-make-a-type-safe-collection.md)<br/>
[Acessando todos os membros de uma coleção](../mfc/accessing-all-members-of-a-collection.md)
