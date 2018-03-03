---
title: "Classes de coleção ATL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 24b0fbdc5ab68319704fb59746862384198f232b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="atl-collection-classes"></a>Classes de coleção ATL
ATL fornece muitas classes para armazenar e acessar dados. Classe que você decidir usar depende de vários fatores, incluindo:  
  
-   A quantidade de dados a serem armazenados  
  
-   Eficiência versus o desempenho de acesso os dados  
  
-   A capacidade de acessar os dados por índice ou chave  
  
-   Como os dados são ordenados  
  
-   Preferência pessoal  
  
## <a name="small-collection-classes"></a>Classes de coleção pequeno  
 ATL fornece as seguintes classes de matriz para lidar com um número pequeno de objetos. No entanto, essas classes são limitados e projetados para ser usado internamente pelo ATL. Não é recomendável usá-los em seus programas.  
  
|Classe|Tipo de armazenamento de dados|  
|-----------|--------------------------|  
|[CSimpleArray](../atl/reference/csimplearray-class.md)|Implementa uma classe de matriz para lidar com um número pequeno de objetos.|  
|[CSimpleMap](../atl/reference/csimplemap-class.md)|Implementa uma classe de mapeamento para lidar com um número pequeno de objetos.|  
  
## <a name="general-purpose-collection-classes"></a>Classes de coleção de uso geral  
 As classes de acompanhamento implementam matrizes, listas e mapas e são fornecidas como classes de coleção de uso geral:  
  
|Classe|Tipo de armazenamento de dados|  
|-----------|--------------------------|  
|[CAtlArray](../atl/reference/catlarray-class.md)|Implementa uma matriz.|  
|[CAtlList](../atl/reference/catllist-class.md)|Implementa uma lista.|  
|[CAtlMap](../atl/reference/catlmap-class.md)|Implementa uma estrutura de mapeamento, no qual os dados podem ser referenciados por chave ou valor.|  
|[CRBMap](../atl/reference/crbmap-class.md)|Implementa uma estrutura de mapeamento usando o algoritmo de vermelho-preto.|  
|[CRBMultiMap](../atl/reference/crbmultimap-class.md)|Implementa uma estrutura multimapping vermelho-preto.|  
  
 Essas classes interceptará muitos erros de programação quando usado em compilações de depuração, mas para fins de desempenho, essas verificações não serão executadas em compilações para venda.  
  
## <a name="specialized-collection-classes"></a>Classes de coleção especializadas  
 Classes de coleção mais especializadas também são fornecidos para gerenciamento de ponteiros de memória e ponteiros de interface:  
  
|Classe|Finalidade|  
|-----------|-------------|  
|[CAutoPtrArray](../atl/reference/cautoptrarray-class.md)|Fornece métodos úteis ao construir uma matriz de ponteiros inteligentes.|  
|[CAutoPtrList](../atl/reference/cautoptrlist-class.md)|Fornece métodos úteis ao construir uma lista de ponteiros inteligentes.|  
|[CComUnkArray](../atl/reference/ccomunkarray-class.md)|Repositórios `IUnknown` ponteiros e foi projetado para ser usado como um parâmetro para o [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md) classe de modelo.|  
|[CHeapPtrList](../atl/reference/cheapptrlist-class.md)|Fornece métodos úteis ao construir uma lista de ponteiros de pilha.|  
|[CInterfaceArray](../atl/reference/cinterfacearray-class.md)|Fornece métodos úteis ao construir uma matriz de ponteiros de interface COM.|  
|[CInterfaceList](../atl/reference/cinterfacelist-class.md)|Fornece métodos úteis ao construir uma lista de ponteiros de interface COM.|  
  
## <a name="choosing-a-collection-class"></a>Escolher uma classe de coleção  
 Cada uma das classes de coleção disponível oferece diferentes características de desempenho, conforme mostrado na tabela a seguir.  
  
-   Colunas 2 e 3 descrevem cada classe ordenação e características de acesso. Na tabela, o termo "ordenado" significa que a ordem na qual os itens são inseridos e excluídos determina a ordem na coleção; Isso não significa que os itens são classificados em seu conteúdo. O termo "indexed" significa que os itens na coleção podem ser recuperados por um índice de inteiro, como itens em uma matriz típica.  
  
-   Colunas 4 e 5 descrevem o desempenho de cada classe. Em aplicativos que exigem várias inserções na coleção, a velocidade de inserção pode ser especialmente importante; para outros aplicativos, a velocidade de pesquisa pode ser mais importante.  
  
-   Coluna 6 descreve se cada forma permite elementos duplicados.  
  
-   O desempenho de uma operação de classe determinada coleção é expressa em termos da relação entre o tempo necessário para concluir a operação e o número de elementos na coleção. Uma operação de colocar um período de tempo que aumenta linearmente conforme o número de elementos é descrito como um algoritmo de (n). Por outro lado, uma operação de colocar um período de tempo que aumenta a menos que o número de elementos é descrita como um algoritmo O (log n). Portanto, em termos de desempenho, os algoritmos O (log n) superam (n) algoritmos mais como o número de elementos.  
  
### <a name="collection-shape-features"></a>Recursos do conjunto de forma  
  
|Forma|Ordenada|Indexadas|Inserir um<br /><br /> Elemento|Procurar<br /><br /> elemento especificado|Duplicar<br /><br /> elementos|  
|-----------|--------------|--------------|---------------------------|--------------------------------------|-----------------------------|  
|Lista|Sim|Não|Fast (tempo constante)|Lento (n)|Sim|  
|Matriz|Sim|Por int (tempo constante)|Lenta (n), exceto se inserir no final, no qual caso tempo constante|Lento (n)|Sim|  
|Mapa|Não|Por chave (tempo constante)|Fast (tempo constante)|Fast (tempo constante)|Nenhum (chaves) Sim (valores)|  
|Mapa de vermelho-preto|Sim (por chave)|Por chave O (log n)|O Fast (log n)|O Fast (log n)|Não|  
|Vários mapeamentos de vermelho-preto|Sim (por chave)|Por chave O(log n) (vários valores por chave)|O Fast (log n)|O Fast (log n)|Sim (vários valores por chave)|  
  
## <a name="using-ctraits-objects"></a>Usando objetos CTraits  
 Como as classes de coleção ATL podem ser usadas para armazenar uma ampla variedade de tipos de dados definidos pelo usuário, pode ser útil poder substituir funções importantes como comparações. Isso é feito usando as classes CTraits.  
  
 Classes CTraits são semelhante, mas é mais flexível do que as funções de auxiliar de classe de coleção MFC; consulte [auxiliares da classe de coleção](../mfc/reference/collection-class-helpers.md) para obter mais informações.  
  
 Ao construir sua classe de coleção, você tem a opção de especificar uma classe CTraits. Essa classe contém o código que irá executar operações como comparações quando chamado por outros métodos que formam a classe de coleção. Por exemplo, se o objeto da lista contém suas próprias estruturas definidas pelo usuário, você talvez queira redefinir o teste de igualdade para comparar apenas determinadas variáveis de membro. Dessa forma, método de localização do objeto de lista operam de forma mais útil.  
  
## <a name="example"></a>Exemplo  
  
### <a name="code"></a>Código  
 [!code-cpp[NVC_ATL_Utilities#112](../atl/codesnippet/cpp/atl-collection-classes_1.cpp)]  
  
## <a name="comments"></a>Comentários  
 Para obter uma lista das classes CTraits, consulte [Classes de coleção](../atl/collection-classes.md).  
  
 O diagrama a seguir mostra a hierarquia de classe para as classes CTraits.  
  
 ![Hierarquia de características de classes de coleção](../atl/media/vctraitscollectionclasseshierarchy.gif "vctraitscollectionclasseshierarchy")  
  
## <a name="collection-classes-samples"></a>Exemplos de Classes de coleção  
 Os exemplos a seguir demonstram as classes de coleção:  
  
-   [Exemplo de MMXSwarm](../visual-cpp-samples.md)  
  
-   [Exemplo de DynamicConsumer](../visual-cpp-samples.md)  
  
-   [Exemplo de UpdatePV](../visual-cpp-samples.md)  
  
-   [Exemplo de marca de seleção](../visual-cpp-samples.md)  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)   
 [Classes de coleção](../atl/collection-classes.md)

