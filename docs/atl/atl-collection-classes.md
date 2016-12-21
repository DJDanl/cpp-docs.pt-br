---
title: "Classes de cole&#231;&#227;o ATL | Microsoft Docs"
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
  - "classes de coleção"
  - "classes de coleção, sobre classes de coleção"
  - "classes de coleção, escolha"
  - "Função ConstructElements"
  - "Classes CTraits"
  - "Função DestructElements"
  - "Função SerializeElements"
  - "classes de características"
ms.assetid: 4d619d46-5b4e-41dd-b9fd-e86b1fbc00b5
caps.latest.revision: 14
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de cole&#231;&#227;o ATL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

ATL fornece muitas classes para armazenar e acessar dados.  Classe que você decidir usar depende de vários fatores, incluindo:  
  
-   A quantidade de dados a serem armazenados  
  
-   Eficiência contra o desempenho sobre acessar os dados  
  
-   A capacidade de acessar os dados pelo índice ou por chave  
  
-   Como os dados são ordenados  
  
-   Preferência pessoal  
  
## Classes de coleções pequenas  
 ATL fornece as seguintes classes de matriz para manipular um pequeno número de objetos.  Em o entanto, essas classes são limitadas e criadas para uso internamente por ATL.  Não é recomendável que você usa nos seus programas.  
  
|Classe|Tipo de armazenamento de dados|  
|------------|------------------------------------|  
|[CSimpleArray](../atl/reference/csimplearray-class.md)|Implementa uma classe de matriz para manipular um pequeno número de objetos.|  
|[CSimpleMap](../atl/reference/csimplemap-class.md)|Implementa uma classe de mapeamento para manipular um pequeno número de objetos.|  
  
## Classes de coleção comumente usadas  
 As classes a seguir implementam, listas, matrizes e mapeia e são fornecidas como a coleção comumente usadas classe:  
  
|Classe|Tipo de armazenamento de dados|  
|------------|------------------------------------|  
|[CAtlArray](../atl/reference/catlarray-class.md)|Implementa uma matriz.|  
|[CAtlList](../Topic/CAtlList%20Class.md)|Implementa uma lista.|  
|[CAtlMap](../atl/reference/catlmap-class.md)|Implementa uma estrutura de mapeamento, pelo qual os dados podem ser referenciados por chave ou por valor.|  
|[CRBMap](../atl/reference/crbmap-class.md)|Implementa uma estrutura de mapeamento usando o algoritmo Vermelho\- Preto.|  
|[CRBMultiMap](../atl/reference/crbmultimap-class.md)|Implementa uma estrutura multimapping Vermelho\-Preta.|  
  
 Essas classes interceptarão muitos erros de programação quando usadas em compilações de depuração, mas para a causa de desempenho, essas verificações não serão executadas em construções varejistas.  
  
## Classes de coleção especializadas  
 As classes mais especializadas de coleção são fornecidas também gerenciando ponteiros de memória e ponteiros a interface:  
  
|Classe|Objetivo|  
|------------|--------------|  
|[CAutoPtrArray](../atl/reference/cautoptrarray-class.md)|Fornece métodos úteis quando construir uma matriz de ponteiros inteligentes.|  
|[CAutoPtrList](../atl/reference/cautoptrlist-class.md)|Fornece métodos úteis quando construir uma lista de ponteiros inteligentes.|  
|[CComUnkArray](../atl/reference/ccomunkarray-class.md)|Armazena ponteiros de `IUnknown` e é projetado para ser usado como um parâmetro para a classe de modelo de [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md) .|  
|[CHeapPtrList](../atl/reference/cheapptrlist-class.md)|Fornece métodos úteis quando construir uma lista de ponteiros da heap.|  
|[CInterfaceArray](../atl/reference/cinterfacearray-class.md)|Fornece métodos úteis quando construir uma matriz de ponteiros da interface COM.|  
|[CInterfaceList](../Topic/CInterfaceList%20Class.md)|Fornece métodos úteis quando construir uma lista de ponteiros da interface COM.|  
  
## Escolhendo uma classe de coleção  
 Cada uma das classes disponíveis de coleção oferece características de desempenho diferentes, como mostrado na tabela abaixo.  
  
-   As colunas 2 e 3 descrevem cada classe de ordenação e acessam características.  Em a tabela, o termo “pediu” significa que a ordem em que os itens excluídos são inseridos e determina a ordem na coleção; não significa que os itens são classificadas em seu conteúdo.  O termo “indexado” significa que os itens na coleção podem ser recuperados por um índice inteiro, bem como itens em uma matriz típica.  
  
-   As colunas 4 e 5 descrevem o desempenho de cada classe.  Em aplicativos que requerem várias inserções na coleção, a velocidade de inserção pode ser especialmente importante; para outros aplicativos, a velocidade de pesquisa pode ser mais importante.  
  
-   Descreve a coluna 6 se cada formulário permite elementos duplicados.  
  
-   O desempenho de uma operação determinada de classe de coleção é expresso em termos de relação entre o tempo necessário para concluir a operação e o número de elementos na coleção.  Uma operação que leva uma quantidade de tempo que aumenta linear como o número de gera de elementos é descrito como um algoritmo \(O\)n.  Por outro lado, uma operação que recebe um período de tempo que disparam sempre menor que o número de gera de elementos é descrito como um algoritmo de O \(log\) em.  Portanto, em termos de desempenho, algoritmos de O \(log\) em O outperform \(em\) algoritmos sempre mais como o número de elementos aumenta.  
  
### Recursos de forma de coleção  
  
|Forma|Ordenada?|Indexado?|Insira<br /><br /> elemento|Procure por<br /><br /> elemento especificado|Duplicate<br /><br /> elementos?|  
|-----------|---------------|---------------|-------------------------|-------------------------------------------|------------------------------|  
|List|Sim|Não|Rápido \(tempo constantes\)|O lento \(em\)|Sim|  
|Matriz|Sim|Int \(tempo por constantes\)|Desacelerar O \(em\) exceto se inserção no final, em esse caso constante cronometra|O lento \(em\)|Sim|  
|Mapa|Não|Por chave \(tempo constantes\)|Rápido \(tempo constantes\)|Rápido \(tempo constantes\)|Não \(chaves\) Sim \(valores\)|  
|Mapa Vermelho\-Preto|Sim \(por chave\)|Por chave em O \(log\)|Rápido no \(log\)|Rápido no \(log\)|Não|  
|Multimap Vermelho\-Preto|Sim \(por chave\)|Por chave em O \(log\) \(vários valores por chave\)|Rápido no \(log\)|Rápido no \(log\)|Sim \(vários valores por chave\)|  
  
## Usando objetos de CTraits  
 Como as classes de coleção de ATL podem ser usadas para armazenar uma ampla variedade de tipos de dados definidos pelo usuário, pode ser útil poder substituir funções importantes como comparações.  Isso é conseguido usando as classes de CTraits.  
  
 As classes de CTraits são semelhantes a, mas mais flexíveis do que, as funções auxiliares de classe de coleção MFC; consulte [Auxiliares da classe de coleção](../mfc/reference/collection-class-helpers.md) para mais informações.  
  
 Quando construir sua classe de coleção, você tem a opção de especificar uma classe de CTraits.  Essa classe conterá o código que irá executar operações como comparações quando chamado pelos outros métodos que compõem a classe de coleção.  Por exemplo, se seu objeto de lista contém suas próprias estruturas definidos pelo usuário, você pode querer redefinir o teste de igualdade para comparar somente certos variáveis de membro.  Assim, o método de localização do objeto de lista operar\-se\-á de uma maneira mais útil.  
  
## Exemplo  
  
### Código  
 [!CODE [NVC_ATL_Utilities#112](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#112)]  
  
## Comentários  
 Para obter uma lista de classes de CTraits, consulte [Classes de coleção](../Topic/Collection%20Classes.md).  
  
 O diagrama a seguir mostra a hierarquia de classe para as classes de CTraits.  
  
 ![Hierarquia de características de Classes de coleção](../atl/media/vctraitscollectionclasseshierarchy.png "vcTraitsCollectionClassesHierarchy")  
  
## A coleção de classes de exemplos  
 Os seguintes exemplos mostram as classes de coleção:  
  
-   [Exemplo de MMXSwarm](../top/visual-cpp-samples.md)  
  
-   [Exemplo de DynamicConsumer](../top/visual-cpp-samples.md)  
  
-   [Exemplo de UpdatePV](../top/visual-cpp-samples.md)  
  
-   [Exemplo de famoso](../top/visual-cpp-samples.md)  
  
## Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)   
 [Classes de coleção](../Topic/Collection%20Classes.md)