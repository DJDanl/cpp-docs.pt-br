---
title: "Implementação do Manager uma cadeia de caracteres personalizada (Avançado método) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- IAtlStringMgr class, using
ms.assetid: 64ab7da9-47c1-4c4a-9cd7-4cc37e7f3f57
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7e76edc65e5f30fee90f346d5434ecbee320a37a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="implementation-of-a-custom-string-manager-advanced-method"></a>Implementação um Gerenciador de personalizado cadeia de caracteres (método avançado)
Em situações especiais, você talvez queira implementar um Gerenciador de cadeia de caracteres personalizada que mais do que apenas alterar quais heap é usada para alocar memória. Nessa situação, você deve implementar manualmente a [IAtlStringMgr](../atl-mfc-shared/reference/iatlstringmgr-class.md) interface como Gerenciador de cadeia de caracteres personalizada.  
  
 Para fazer isso, é importante compreender primeiro como [CStringT](../atl-mfc-shared/reference/cstringt-class.md) usa essa interface para gerenciar seus dados de cadeia de caracteres. Todas as instâncias de `CStringT` tem um ponteiro para um [CStringData](../atl-mfc-shared/reference/cstringdata-class.md) estrutura. Essa estrutura de comprimento variável contém informações importantes sobre a cadeia de caracteres (como comprimento), bem como os dados de caractere para a cadeia de caracteres. Cada Gerenciador de cadeia de caracteres personalizada é responsável por alocar e liberar essas estruturas por solicitação do `CStringT`.  
  
 O `CStringData` estrutura consiste em quatro campos:  
  
-   [pStringMgr](../atl-mfc-shared/reference/cstringdata-class.md#pstringmgr) esse campo aponta para o `IAtlStringMgr` interface usada para gerenciar esses dados de cadeia de caracteres. Quando `CStringT` precisa ser realocados ou liberar o buffer de cadeia de caracteres, ele chama a realocação ou métodos livres desta interface, passando o `CStringData` estrutura como um parâmetro. Ao alocar um `CStringData` estrutura seu gerente de cadeia de caracteres, você deve definir esse campo para apontar para o gerente de cadeia de caracteres personalizada.  
  
-   [nDataLength](../atl-mfc-shared/reference/cstringdata-class.md#ndatalength) esse campo contém o comprimento lógico atual da cadeia de caracteres armazenado no buffer, exceto o nulo de terminação. `CStringT`atualiza esse campo quando o comprimento da cadeia de caracteres é alterado. Ao alocar um `CStringData` estrutura, o gerente de cadeia de caracteres deve definir este campo como zero. Ao realocar um `CStringData` estrutura, o gerente de cadeia de caracteres personalizada deve deixar esse campo inalterado.  
  
-   [nAllocLength](../atl-mfc-shared/reference/cstringdata-class.md#nalloclength) este campo contém o número máximo de caracteres (exceto a terminação nula) que podem ser armazenados nesse buffer de cadeia de caracteres sem realocando-lo. Sempre que `CStringT` precisa aumentar o tamanho lógico de cadeia de caracteres, ele primeiro verifica esse campo para verificar se há espaço suficiente no buffer. Se a verificação falhar, `CStringT` chama o Gerenciador de cadeia de caracteres personalizada para realocar o buffer. Ao alocar ou realocar um `CStringData` estrutura, você deve definir esse campo para o número de caracteres solicitada em pelo menos o **nChars** parâmetro para [IAtlStringMgr::Allocate](../atl-mfc-shared/reference/iatlstringmgr-class.md#allocate) ou [IAtlStringMgr::Reallocate](../atl-mfc-shared/reference/iatlstringmgr-class.md#reallocate). Se houver mais espaço no buffer do solicitado, você pode definir esse valor para refletir a quantidade de espaço disponível real. Isso permite que `CStringT` aumentar a cadeia de caracteres para preencher todo o espaço alocado antes de chamar novamente no Gerenciador de cadeia de caracteres para realocar o buffer.  
  
-   [nRefs](../atl-mfc-shared/reference/cstringdata-class.md#nrefs) esse campo contém a contagem de referência atual do buffer de cadeia de caracteres. Se o valor for um, uma única instância de `CStringT` está usando o buffer. Além disso, a instância tem permissão para ler e modificar o conteúdo do buffer. Se o valor for maior do que um, várias instâncias do `CStringT` pode usar o buffer. Como o buffer de caractere é compartilhado, `CStringT` instâncias somente podem ler o conteúdo do buffer. Para modificar o conteúdo, `CStringT` pela primeira vez, faz uma cópia do buffer. Se o valor for negativo, apenas uma instância de `CStringT` está usando o buffer. Nesse caso, o buffer é considerado bloqueado. Quando um `CStringT` instância não está usando um buffer bloqueado nenhuma outra instância de `CStringT` podem compartilhar o buffer. Em vez disso, essas instâncias de criar uma cópia do buffer antes de manipular o conteúdo. Além disso, o `CStringT` instância usando o buffer bloqueado não tentará compartilhar o buffer de qualquer outro `CStringT` instância atribuída a ele. Nesse caso, o `CStringT` instância copia outra cadeia de caracteres no buffer de bloqueado.  
  
     Ao alocar um `CStringData` estrutura, você deve definir esse campo para refletir o tipo de compartilhamento que é permitido para o buffer. Para a maioria das implementações, defina esse valor como um. Isso permite que o comportamento comum de compartilhamento de cópia na gravação. No entanto, se o Gerenciador de cadeia de caracteres não oferece suporte a compartilhamento o buffer de cadeia de caracteres, defina este campo para um estado bloqueado. Isso força `CStringT` Use somente esse buffer para a instância do `CStringT` que alocou.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)

