---
title: "Acessando todos os membros de uma cole&#231;&#227;o | Microsoft Docs"
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
  - "MFC, coleções"
  - "enumerações [MFC]"
  - "enumerando coleções"
  - "coleções, acessando"
  - "classes de coleção, acessando membros"
  - "matrizes [C++], iteração"
  - "iteração, coleções"
  - "acesso de membro, coleções"
  - "iterações de coleções de lista"
  - "Classes de coleção MFC, acessando membros"
  - "loop por meio de coleções"
  - "estruturas de loop, o loop pelas coleções"
ms.assetid: 7bbae518-062e-4393-81f9-b22abd2e5f59
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acessando todos os membros de uma cole&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes de coleção MFC matriz — ambos baseado em modelo e não — usar índices para acessar seus elementos. As classes de coleção MFC lista e mapa — ambos baseado em modelo e não — use um indicador do tipo **posição** para descrever uma posição especificada dentro da coleção. Para acessar um ou mais membros dessas coleções, você primeiro inicializar o indicador de posição repetidamente passa nessa posição na coleção e pede para retornar o próximo elemento. A coleção não é responsável por manter informações de estado sobre o progresso da iteração. Essa informação é mantida no indicador de posição. Mas, dada uma posição específica, a coleção é responsável por retornar o próximo elemento.  
  
 Os procedimentos a seguir mostram como iterar sobre os três tipos principais de coleções fornecidos com o MFC:  
  
-   [Percorrer uma matriz](#_core_to_iterate_an_array)  
  
-   [Iteração de uma lista](#_core_to_iterate_a_list)  
  
-   [Iterando um mapa](#_core_to_iterate_a_map)  
  
### Para repetir uma matriz  
  
1.  Use números seqüenciais de índice com o `GetAt` função de membro:  
  
     [!code-cpp[NVC_MFCCollections#12](../mfc/codesnippet/CPP/accessing-all-members-of-a-collection_1.cpp)]  
  
     Este exemplo usa uma matriz de ponteiro tipado que contém ponteiros para `CPerson` objetos. A matriz é derivada da classe `CObArray`, um a nontemplate classes predefinidas.`GetAt` Retorna um ponteiro para um `CPerson` objeto. Para classes de coleção do tipo ponteiro — matrizes ou listas — o primeiro parâmetro especifica a classe base; o segundo parâmetro especifica o tipo de armazenamento.  
  
     O `CTypedPtrArray` também classe sobrecargas de **\[ \]** operador para que você possa usar a sintaxe de subscrito de matriz comum de acessar elementos de uma matriz.  Uma alternativa para a instrução no corpo do `for` loop acima é  
  
     [!code-cpp[NVC_MFCCollections#13](../mfc/codesnippet/CPP/accessing-all-members-of-a-collection_2.cpp)]  
  
     Este operador contiverem **const** e não\-**const** versões. O **const** versão, que é invocado para **const** matrizes, podem aparecer apenas no lado direito de uma instrução de atribuição.  
  
### Para repetir uma lista  
  
1.  Use as funções de membro `GetHeadPosition` e `GetNext` para examinar a lista:  
  
     [!code-cpp[NVC_MFCCollections#14](../mfc/codesnippet/CPP/accessing-all-members-of-a-collection_3.cpp)]  
  
     Este exemplo usa uma lista de ponteiro tipado para contêm ponteiros para `CPerson` objetos. A declaração de lista assemelha\-se à matriz no procedimento de [para iterar uma matriz](#_core_to_iterate_an_array) mas é derivada da classe `CObList`.`GetNext` Retorna um ponteiro para um `CPerson` objeto.  
  
### Para iterar um mapa  
  
1.  Use `GetStartPosition` para ir para o início do mapa e `GetNextAssoc` repetidamente obter a próxima chave e valor do mapa, conforme mostrado no exemplo a seguir:  
  
     [!code-cpp[NVC_MFCCollections#15](../mfc/codesnippet/CPP/accessing-all-members-of-a-collection_4.cpp)]  
  
     Este exemplo usa um modelo simples de mapa \(em vez de uma coleção do tipo ponteiro\) que usa `CString` chaves e armazena ponteiros para `CPerson` objetos. Quando você usa funções de acesso como `GetNextAssoc`, a classe fornece ponteiros para `CPerson` objetos. Se você usar uma das coleções de mapa fora do modelo em vez disso, você deve converter retornado `CObject` ponteiro para um ponteiro para um `CPerson`.  
  
    > [!NOTE]
    >  Para mapas de fora do modelo, o compilador exige uma referência para um `CObject` ponteiro no último parâmetro para `GetNextAssoc`. Na entrada, você deve converter os ponteiros para tipo, conforme mostrado no exemplo a seguir.  
  
     A solução de modelo é mais simples e ajuda a fornecer melhor segurança de tipos. O código fora do modelo é mais complicado, como você pode ver aqui:  
  
     [!code-cpp[NVC_MFCCollections#16](../mfc/codesnippet/CPP/accessing-all-members-of-a-collection_5.cpp)]  
  
 Para obter mais informações, consulte [Excluir todos os objetos em uma coleção CObject](../Topic/Deleting%20All%20Objects%20in%20a%20CObject%20Collection.md).  
  
## Consulte também  
 [Coleções](../mfc/collections.md)