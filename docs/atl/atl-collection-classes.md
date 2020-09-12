---
title: Visão geral da classe da coleção ATL
ms.date: 11/19/2018
helpviewer_keywords:
- DestructElements function
- collection classes, choosing
- ConstructElements function
- SerializeElements function
- traits classes
- collection classes, about collection classes
- CTraits classes
- collection classes
ms.assetid: 4d619d46-5b4e-41dd-b9fd-e86b1fbc00b5
ms.openlocfilehash: 039af388a3713540c6ba7d39e8b639cf83d291ff
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040854"
---
# <a name="atl-collection-classes"></a>Classes de coleção ATL

A ATL fornece muitas classes para armazenar e acessar dados. A classe que você decide usar depende de vários fatores, incluindo:

- A quantidade de dados a serem armazenados

- Eficiência versus desempenho para acessar os dados

- A capacidade de acessar os dados por índice ou por chave

- Como os dados são ordenados

- Preferência pessoal

## <a name="small-collection-classes"></a>Classes de coleção pequenas

A ATL fornece as seguintes classes de matriz para lidar com pequenas quantidades de objetos. No entanto, essas classes são limitadas e projetadas para uso internamente pela ATL. Não é recomendável usá-los em seus programas.

|Classe|Tipo de armazenamento de dados|
|-----------|--------------------------|
|[CSimpleArray](../atl/reference/csimplearray-class.md)|Implementa uma classe de matriz para lidar com pequenas quantidades de objetos.|
|[CSimpleMap](../atl/reference/csimplemap-class.md)|Implementa uma classe de mapeamento para lidar com pequenas quantidades de objetos.|

## <a name="general-purpose-collection-classes"></a>Uso Geral classes de coleção

As classes a seguir implementam matrizes, listas e mapas e são fornecidas como classes de coleção de uso geral:

|Classe|Tipo de armazenamento de dados|
|-----------|--------------------------|
|[CAtlArray](../atl/reference/catlarray-class.md)|Implementa uma matriz.|
|[CAtlList](../atl/reference/catllist-class.md)|Implementa uma lista.|
|[CAtlMap](../atl/reference/catlmap-class.md)|Implementa uma estrutura de mapeamento, na qual os dados podem ser referenciados por chave ou valor.|
|[CRBMap](../atl/reference/crbmap-class.md)|Implementa uma estrutura de mapeamento usando o algoritmo vermelho-preto.|
|[CRBMultiMap](../atl/reference/crbmultimap-class.md)|Implementa uma estrutura de multimapeamento vermelho-preto.|

Essas classes interceptarão muitos erros de programação quando usadas em compilações de depuração, mas para fins de desempenho, essas verificações não serão executadas em compilações de varejo.

## <a name="specialized-collection-classes"></a>Classes de coleção especializadas

Classes de coleção mais especializadas também são fornecidas para gerenciar ponteiros de memória e ponteiros de interface:

|Classe|Finalidade|
|-----------|-------------|
|[CAutoPtrArray](../atl/reference/cautoptrarray-class.md)|Fornece métodos úteis ao construir uma matriz de ponteiros inteligentes.|
|[CAutoPtrList](../atl/reference/cautoptrlist-class.md)|Fornece métodos úteis ao construir uma lista de ponteiros inteligentes.|
|[CComUnkArray](../atl/reference/ccomunkarray-class.md)|Armazena `IUnknown` ponteiros e é projetado para ser usado como um parâmetro para a classe de modelo [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md) .|
|[CHeapPtrList](../atl/reference/cheapptrlist-class.md)|Fornece métodos úteis ao construir uma lista de ponteiros de heap.|
|[CInterfaceArray](../atl/reference/cinterfacearray-class.md)|Fornece métodos úteis ao construir uma matriz de ponteiros de interface COM.|
|[CInterfaceList](../atl/reference/cinterfacelist-class.md)|Fornece métodos úteis ao construir uma lista de ponteiros de interface COM.|

## <a name="choosing-a-collection-class"></a>Escolhendo uma classe de coleção

Cada uma das classes de coleção disponíveis oferece características de desempenho diferentes, conforme mostrado na tabela a seguir.

- As colunas 2 e 3 descrevem a ordenação e as características de acesso de cada classe. Na tabela, o termo "ordenado" significa que a ordem na qual os itens são inseridos e excluídos determina sua ordem na coleção; Isso não significa que os itens são classificados em seu conteúdo. O termo "indexado" significa que os itens na coleção podem ser recuperados por um índice de números inteiros, assim como os itens em uma matriz típica.

- As colunas 4 e 5 descrevem o desempenho de cada classe. Em aplicativos que exigem muitas inserções na coleção, a velocidade de inserção pode ser especialmente importante; para outros aplicativos, a velocidade de pesquisa pode ser mais importante.

- A coluna 6 descreve se cada forma permite elementos duplicados.

- O desempenho de uma determinada operação de classe de coleção é expresso em termos da relação entre o tempo necessário para concluir a operação e o número de elementos na coleção. Uma operação que leva uma quantidade de tempo que aumenta linearmente à medida que o número de elementos aumenta é descrita como um algoritmo O (n). Por outro lado, uma operação que leva um período de tempo que aumenta menos ou menos conforme o aumento do número de elementos é descrita como um algoritmo O (log n). Portanto, em termos de desempenho, O (log n) algoritmos supera O (n) algoritmos mais e mais conforme o número de elementos aumenta.

### <a name="collection-shape-features"></a>Recursos de forma de coleção

|Forma|Encomendado|Indexa|Inserir um<br /><br /> elemento|Procurar<br /><br /> elemento especificado|Duplicar<br /><br /> elementos|
|-----------|--------------|--------------|---------------------------|--------------------------------------|-----------------------------|
|Lista|Sim|Não|Rápido (tempo constante)|Lento O (n)|Sim|
|Array|Sim|Por int (tempo constante)|Lento O (n) exceto se inserir no final, nesse caso, tempo constante|Lento O (n)|Sim|
|Mapeamento|Não|Por chave (tempo constante)|Rápido (tempo constante)|Rápido (tempo constante)|Não (chaves) Sim (valores)|
|Mapa vermelho-preto|Sim (por chave)|Por chave O (log n)|Fast O (log n)|Fast O (log n)|Não|
|Vermelho-preto Multimap|Sim (por chave)|Por chave O (log n) (vários valores por chave)|Fast O (log n)|Fast O (log n)|Sim (vários valores por chave)|

## <a name="using-ctraits-objects"></a>Usando objetos CTraits

Como as classes de coleção do ATL podem ser usadas para armazenar uma ampla gama de tipos de dados definidos pelo usuário, pode ser útil substituir funções importantes, como comparações. Isso é obtido usando as classes CTraits.

As classes CTraits são semelhantes, mas mais flexíveis do que as funções auxiliares de classe de coleção MFC; consulte [auxiliares de classe de coleção](../mfc/reference/collection-class-helpers.md) para obter mais informações.

Ao construir sua classe de coleção, você tem a opção de especificar uma classe CTraits. Essa classe conterá o código que executará operações como comparações quando chamadas por outros métodos que compõem a classe de coleção. Por exemplo, se o seu objeto de lista contiver suas próprias estruturas definidas pelo usuário, talvez você queira redefinir o teste de igualdade para comparar apenas determinadas variáveis de membro. Dessa forma, o método Find do objeto de lista funcionará de maneira mais útil.

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

[!code-cpp[NVC_ATL_Utilities#112](../atl/codesnippet/cpp/atl-collection-classes_1.cpp)]

## <a name="comments"></a>Comentários

Para obter uma lista das classes CTraits, consulte [classes de coleção](../atl/collection-classes.md).

O diagrama a seguir mostra a hierarquia de classes para as classes CTraits.

![Hierarquia de características para classes de coleção](../atl/media/vctraitscollectionclasseshierarchy.gif "Hierarquia de características para classes de coleção")

## <a name="collection-classes-samples"></a>Exemplos de classes de coleção

Os exemplos a seguir demonstram as classes de coleção:

- [Exemplo de MMXSwarm](../overview/visual-cpp-samples.md)

- [Exemplo de DynamicConsumer](../overview/visual-cpp-samples.md)

- [Exemplo de UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV)

- [Exemplo de letreiro](../overview/visual-cpp-samples.md)

## <a name="see-also"></a>Confira também

[Conceitos](../atl/active-template-library-atl-concepts.md)<br/>
[Classes de coleção](../atl/collection-classes.md)
