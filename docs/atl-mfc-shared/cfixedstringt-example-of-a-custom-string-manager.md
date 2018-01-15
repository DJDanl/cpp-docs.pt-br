---
title: 'CFixedStringT: Exemplo de um Gerenciador de cadeia de caracteres personalizada | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
helpviewer_keywords: CFixedStringT class, using a custom string manager
ms.assetid: 1cf11fd7-51b8-4b94-87af-02bc25f47dd6
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7164d2313f5610d1d7e56f5449c81ea9e2282981
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cfixedstringt-example-of-a-custom-string-manager"></a>CFixedStringT: Exemplo de um Gerenciador de cadeia de caracteres personalizada
A biblioteca do ATL para implementar um exemplo de um Gerenciador de cadeia de caracteres personalizada usado pela classe [CFixedStringT](../atl-mfc-shared/reference/cfixedstringt-class.md), chamado **CFixedStringMgr**. `CFixedStringT`é derivado de [CStringT](../atl-mfc-shared/reference/cstringt-class.md) e implementa uma cadeia de caracteres que aloca seus dados de caractere como parte do `CFixedStringT` objeto em si, desde que a cadeia de caracteres é menor que o comprimento especificado pelo **t_nChars** parâmetro do modelo de `CFixedStringT`. Com essa abordagem, a cadeia de caracteres não precisa de heap, a menos que o comprimento da cadeia de caracteres ultrapassar o tamanho do buffer fixo. Porque `CFixedStringT` não sempre use um heap para alocar a seus dados de cadeia de caracteres, não é possível usar **CAtlStringMgr** como seu gerente de cadeia de caracteres. Ele usa um Gerenciador de cadeia de caracteres personalizada (**CFixedStringMgr**), a implementação de [IAtlStringMgr](../atl-mfc-shared/reference/iatlstringmgr-class.md) interface. Essa interface é discutida em [implementação um Gerenciador de personalizado cadeia de caracteres (método avançado)](../atl-mfc-shared/implementation-of-a-custom-string-manager-advanced-method.md).  
  
 O construtor para **CFixedStringMgr** usa três parâmetros:  
  
-   **pData:** um ponteiro para o fixa `CStringData` estrutura a ser usado.  
  
-   **nChars:** o número máximo de caracteres a `CStringData` estrutura pode conter.  
  
-   **pMgr:** um ponteiro para o `IAtlStringMgr` interface de um "Gerenciador de backup de cadeia de caracteres".  
  
 O construtor armazena os valores de `pData` e **pMgr** em suas variáveis de membro do respectivos (`m_pData` e **m_pMgr**). Em seguida, define o comprimento do buffer para zero, o comprimento disponível igual ao tamanho máximo do buffer fixo e a contagem de referência como -1. O valor de contagem de referência indica que o buffer está bloqueado e usar essa instância de **CFixedStringMgr** como o Gerenciador de cadeia de caracteres.  
  
 Marcar o buffer bloqueado impede que outros `CStringT` instâncias mantendo uma referência de compartilhado para o buffer. Se outras `CStringT` instâncias foram autorizadas a compartilhar o buffer seria possível para o buffer contido pelo `CFixedStringT` a ser excluído enquanto outras cadeias de caracteres ainda estavam usando o buffer.  
  
 **CFixedStringMgr** é uma implementação completa do `IAtlStringMgr` interface. A implementação de cada método é discutida separadamente.  
  
## <a name="implementation-of-cfixedstringmgrallocate"></a>Implementação de CFixedStringMgr::Allocate  
 A implementação de **CFixedStringMgr::Allocate** primeiro verifica se o tamanho solicitado da cadeia de caracteres é menor ou igual ao tamanho do buffer fixo (armazenados no `m_pData` membro). Se o buffer fixo é grande o suficiente, **CFixedStringMgr** bloqueia o buffer fixo com um comprimento de zero. Como o comprimento da cadeia de caracteres não ultrapassem o tamanho do buffer fixo, `CStringT` não terá que realocar o buffer.  
  
 Se o tamanho solicitado da cadeia de caracteres for maior que o buffer fixo **CFixedStringMgr** encaminha a solicitação para o Gerenciador de backup de cadeia de caracteres. É provável que o Gerenciador de backup de cadeia de caracteres para alocar o buffer da pilha. No entanto, antes de retornar esse buffer **CFixedStringMgr** bloqueia o buffer e substitui o ponteiro de Gerenciador de cadeia de caracteres do buffer com um ponteiro para o **CFixedStringMgr** objeto. Isso garante que qualquer tentativa realocar ou liberar o buffer por `CStringT` chamará **CFixedStringMgr**.  
  
## <a name="implementation-of-cfixedstringmgrreallocate"></a>Implementação de CFixedStringMgr::ReAllocate  
 A implementação de **CFixedStringMgr::ReAllocate** é muito semelhante à sua implementação de **alocar**.  
  
 Se o buffer que está sendo realocado for o buffer fixado e o tamanho do buffer solicitado é menor do que o buffer fixo, nenhuma alocação é feita. No entanto, se o buffer que está sendo realocado não for o buffer fixado, ele deve ser um buffer alocado com o Gerenciador de backup. Nesse caso, o Gerenciador de backup é usado para realocar o buffer.  
  
 Se o buffer que está sendo realocado for o buffer fixo e o novo tamanho do buffer é muito grande para caber no buffer fixo, **CFixedStringMgr** aloca um novo buffer usando o Gerenciador de backup. O conteúdo do buffer fixado, em seguida, é copiado para o novo buffer.  
  
## <a name="implementation-of-cfixedstringmgrfree"></a>Implementação de CFixedStringMgr::Free  
 A implementação de **CFixedStringMgr::Free** segue o mesmo padrão **alocar** e `ReAllocate`. Se o buffer que está sendo liberado é o buffer fixo, o método define para um buffer de comprimento zero bloqueado. Se o buffer que está sendo liberado foi alocado com o Gerenciador de backup, **CFixedStringMgr** usa o Gerenciador de backup para liberá-la.  
  
## <a name="implementation-of-cfixedstringmgrclone"></a>Implementação de CFixedStringMgr::Clone  
 A implementação de **CFixedStringMgr::Clone** sempre retorna um ponteiro para o Gerenciador de backup em vez de **CFixedStringMgr** em si. Isso ocorre porque todas as instâncias de **CFixedStringMgr** só pode ser associado uma única instância de `CStringT`. Quaisquer outras instâncias do `CStringT` para clonar o Gerenciador o deve obter o Gerenciador de backup em vez disso. Isso ocorre porque o Gerenciador de backup oferece suporte a ser compartilhado.  
  
## <a name="implementation-of-cfixedstringmgrgetnilstring"></a>Implementação de CFixedStringMgr::GetNilString  
 A implementação de **CFixedStringMgr::GetNilString** retorna o buffer fixo. Devido a correspondência individuais de **CFixedStringMgr** e `CStringT`, uma determinada instância do `CStringT` nunca usa mais de um buffer por vez. Portanto, uma cadeia de caracteres nula e um buffer de cadeia de caracteres real nunca são necessárias ao mesmo tempo.  
  
 Sempre que o buffer fixo não está em uso, **CFixedStringMgr** garante que ele é inicializado com um comprimento zero. Isso permite que ele seja usado como a cadeia de caracteres nula. Como bônus, os `nAllocLength` membro do buffer fixo é sempre definido como o tamanho máximo do buffer fixo. Isso significa que `CStringT` pode aumentar a cadeia de caracteres sem chamar [IAtlStringMgr::Reallocate](../atl-mfc-shared/reference/iatlstringmgr-class.md#reallocate), mesmo para a cadeia de caracteres nula.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** cstringt.h  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)

