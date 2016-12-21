---
title: "CFixedStringT: Exemplo de um gerente personalizado de cadeia de caracteres | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFixedStringT, usando um gerente personalizado de cadeia de caracteres"
ms.assetid: 1cf11fd7-51b8-4b94-87af-02bc25f47dd6
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CFixedStringT: Exemplo de um gerente personalizado de cadeia de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de ATL implementa um exemplo de um gerente personalizado de cadeia de caracteres usada pela classe [CFixedStringT](../atl-mfc-shared/reference/cfixedstringt-class.md), **CFixedStringMgr**chamado.  `CFixedStringT` é derivado de [CStringT](../atl-mfc-shared/reference/cstringt-class.md) e implementa uma cadeia de caracteres que atribui seus dados de caractere como parte do objeto de `CFixedStringT` próprios como a cadeia de caracteres é menor que o comprimento especificado pelo parâmetro do modelo de **t\_nChars** de `CFixedStringT`.  Com essa abordagem, a cadeia de caracteres não precisa o heap de todo, a menos que o comprimento da cadeia de caracteres crescer além do tamanho do buffer fixo.  Porque `CFixedStringT` nem sempre usar um heap para atribuir os dados da cadeia de caracteres, não pode usar **CAtlStringMgr** como o gerenciador de cadeia de caracteres.  Usa um gerente personalizado de cadeia de caracteres \(**CFixedStringMgr**\), implementando a interface de [IAtlStringMgr](../Topic/IAtlStringMgr%20Class.md) .  Essa interface é discutida em [Implementação de um gerente personalizado de cadeia de caracteres \(método poderoso\)](../Topic/Implementation%20of%20a%20Custom%20String%20Manager%20\(Advanced%20Method\).md).  
  
 O construtor para **CFixedStringMgr** recebe três parâmetros:  
  
-   Ponteiro de**pData:** A estrutura fixa de `CStringData` a ser usada.  
  
-   **nChars:** o número máximo de caracteres que a estrutura de `CStringData` pode conter.  
  
-   Ponteiro de**pMgr:** A a interface de `IAtlStringMgr` “de um gerente alternativo de cadeia de caracteres”.  
  
 O construtor armazenar os valores de `pData` e de **pMgr** em seus respectivos variáveis de membro \(`m_pData` e **m\_pMgr**\).  Defina o tamanho do buffer como zero, o comprimento disponível igual ao tamanho máximo do buffer fixa, e a contagem de referência – a 1.  O valor de contagem de referência indica que o buffer está bloqueado e usar essa instância de **CFixedStringMgr** como o gerenciador de cadeia de caracteres.  
  
 Marcar o buffer como bloqueado impede que outras instâncias de `CStringT` guardarem uma referência compartilhada no buffer.  Se foram permitidas para outras instâncias de `CStringT` compartilhar o buffer seria possível para o buffer contido por `CFixedStringT` a ser excluído enquanto outras cadeias de caracteres ainda usavam o buffer.  
  
 **CFixedStringMgr** é uma implementação completa de interface de `IAtlStringMgr` .  A implementação de cada método é abordada separadamente.  
  
## Implementação de CFixedStringMgr::Allocate  
 A implementação de **CFixedStringMgr::Allocate** primeiro verifica para ver se o aplicativo tamanho da cadeia de caracteres é menor ou igual ao tamanho do buffer fixo \(armazenado no membro de `m_pData` \).  Se o tamanho fixo é grande o suficiente, **CFixedStringMgr** bloqueia o buffer de comprimento fixo com um zero.  Como o comprimento da cadeia de caracteres não aumenta além do tamanho do buffer fixo, `CStringT` não terá que realocar o buffer.  
  
 Se o aplicativo tamanho da cadeia de caracteres é maior do que o tamanho fixo **CFixedStringMgr** encaminha a solicitação alternativa para o gerenciador cadeia de caracteres.  O gerenciador alternativo de cadeia de caracteres é presumido atribuir o buffer de heap.  Entretanto, antes de retornar o buffer **CFixedStringMgr** bloqueia o buffer e substitui o ponteiro do gerenciador de cadeia de caracteres de buffer com um ponteiro para o objeto de **CFixedStringMgr** .  Isso garante que tentativas de realocar ou liberar o buffer por `CStringT` chamem em **CFixedStringMgr**.  
  
## Implementação de CFixedStringMgr::ReAllocate  
 A implementação de **CFixedStringMgr::ReAllocate** é muito semelhante à sua implementação de **Allocate**.  
  
 Se o buffer que está sendo realocado é o buffer fixo e o tamanho do buffer aplicativo for menor do que o tamanho fixo, nenhuma alocação é feita.  Em o entanto, se o buffer que está sendo realocado não é o buffer fixo, deve ser um buffer atribuído com o gerenciador alternativo.  O gerenciador alternativo é usado em esse caso o buffer. para realocar  
  
 Se o buffer que está sendo realocado é o buffer fixo e o novo tamanho do buffer é muito grande caber no tamanho fixo, **CFixedStringMgr** atribui um novo buffer usando o gerenciador alternativo.  O conteúdo do buffer fixo são copiados no novo buffer.  
  
## Implementação de CFixedStringMgr::Free  
 a implementação de **CFixedStringMgr::Free** segue o mesmo padrão que **Allocate** e `ReAllocate`.  Se o buffer que está sendo é liberado o buffer fixo o método, defina como um buffer bloqueado de comprimento zero.  Se o buffer que está sendo liberado foi atribuído com o gerenciador alternativa, **CFixedStringMgr** usa o gerenciador alternativo para o libera.  
  
## Implementação de CFixedStringMgr::Clone  
 A implementação de **CFixedStringMgr::Clone** sempre retorna um ponteiro para o gerenciador alternativo em vez de **CFixedStringMgr** própria.  Isso acontece porque cada instância de **CFixedStringMgr** só pode ser associado com uma única instância de `CStringT`.  Todas as outras instâncias de `CStringT` tentando clonar o gerenciador devem obter o gerenciador alternativo em vez de isso.  Isso ocorre porque o oferece suporte alternativas do que está sendo compartilhada.  
  
## Implementação de CFixedStringMgr::GetNilString  
 A implementação de **CFixedStringMgr::GetNilString** retorna o tamanho fixo.  Devido a correspondência cara\-a\-cara de **CFixedStringMgr** e de `CStringT`, uma determinada instância de `CStringT` nunca usa mais de um buffer de cada vez.  Portanto, uma cadeia de caracteres de nada e um buffer real da cadeia de caracteres são necessários nunca ao mesmo tempo.  
  
 Sempre que o buffer fixo não está em uso, **CFixedStringMgr** garante que é inicializado com um comprimento zero.  Isso permite que é usado como a cadeia de caracteres de nada.  Como um bônus adicionado, o membro de `nAllocLength` o tamanho fixo é sempre definir o tamanho do buffer máximo fixo.  Isso significa que `CStringT` pode crescer a cadeia de caracteres sem chamar [IAtlStringMgr::Reallocate](../Topic/IAtlStringMgr::Reallocate.md), mesmo para a cadeia de caracteres de nada.  
  
## Requisitos  
 **Cabeçalho:** cstringt.h  
  
## Consulte também  
 [Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)