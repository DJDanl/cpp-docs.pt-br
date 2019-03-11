---
title: Implementação de uma cadeia de caracteres Gerenciador de personalizada (método avançado)
ms.date: 11/04/2016
helpviewer_keywords:
- IAtlStringMgr class, using
ms.assetid: 64ab7da9-47c1-4c4a-9cd7-4cc37e7f3f57
ms.openlocfilehash: 3854ffe205aa8e6cb9cfb800b9aa1473094fffaf
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57743393"
---
# <a name="implementation-of-a-custom-string-manager-advanced-method"></a>Implementação de uma cadeia de caracteres Gerenciador de personalizada (método avançado)

Em situações especializadas, você talvez queira implementar um Gerenciador de cadeia de caracteres personalizada que mais do que apenas alterar quais heap é usado para alocar memória. Nessa situação, você deve implementar manualmente a [IAtlStringMgr](../atl-mfc-shared/reference/iatlstringmgr-class.md) interface como Gerenciador de cadeia de caracteres personalizada.

Para fazer isso, é importante compreender primeiro como [CStringT](../atl-mfc-shared/reference/cstringt-class.md) usa aquela interface para gerenciar seus dados de cadeia de caracteres. Todas as instâncias de `CStringT` tem um ponteiro para uma [CStringData](../atl-mfc-shared/reference/cstringdata-class.md) estrutura. Essa estrutura de comprimento variável contém informações importantes sobre a cadeia de caracteres (por exemplo, comprimento), bem como os dados de caractere real para a cadeia de caracteres. Cada Gerenciador de cadeia de caracteres personalizada é responsável por alocar e liberar essas estruturas mediante solicitação do `CStringT`.

O `CStringData` estrutura consiste em quatro campos:

- [pStringMgr](../atl-mfc-shared/reference/cstringdata-class.md#pstringmgr) esse campo aponta para o `IAtlStringMgr` interface usada para gerenciar esses dados de cadeia de caracteres. Quando `CStringT` precisa realocar ou liberar o buffer de cadeia de caracteres que ele chama o realocar ou livres métodos dessa interface, passando o `CStringData` estrutura como um parâmetro. Ao alocar um `CStringData` estrutura em seu gerente de cadeia de caracteres, você deve definir esse campo para apontar para seu gerente de cadeia de caracteres personalizada.

- [nDataLength](../atl-mfc-shared/reference/cstringdata-class.md#ndatalength) esse campo contém o tamanho lógico atual da cadeia de caracteres armazenado no buffer excluindo a terminação nula. `CStringT` Atualiza este campo quando o comprimento da cadeia de caracteres for alterado. Ao alocar um `CStringData` estrutura, seu gerente de cadeia de caracteres deve definir este campo como zero. Ao realocar um `CStringData` estrutura, seu gerente de cadeia de caracteres personalizada deve deixar esse campo inalterado.

- [nAllocLength](../atl-mfc-shared/reference/cstringdata-class.md#nalloclength) esse campo contém o número máximo de caracteres (exceto o nulo de terminação) que pode ser armazenado nesse buffer de cadeia de caracteres sem realocando-lo. Sempre que `CStringT` precisa aumentar o tamanho lógico da cadeia de caracteres, ele primeiro verifica esse campo para verificar se há espaço suficiente no buffer. Se a verificação falhar, `CStringT` chamadas seu gerente de cadeia de caracteres personalizada para realocar o buffer. Ao alocar ou realocar um `CStringData` estrutura, você deve definir esse campo para o número de caracteres solicitada em pelo menos o *nChars* parâmetro para [IAtlStringMgr::Allocate](../atl-mfc-shared/reference/iatlstringmgr-class.md#allocate) ou [IAtlStringMgr::Reallocate](../atl-mfc-shared/reference/iatlstringmgr-class.md#reallocate). Se houver mais espaço no buffer que solicitado, você pode definir esse valor para refletir a quantidade real de espaço disponível. Isso permite que `CStringT` aumentar a cadeia de caracteres para preencher todo o espaço alocado antes que ele tenha retornar a chamada para o Gerenciador de cadeia de caracteres para realocar o buffer.

- [nRefs](../atl-mfc-shared/reference/cstringdata-class.md#nrefs) esse campo contém a contagem de referência atual do buffer de cadeia de caracteres. Se o valor for um, em seguida, uma única instância de `CStringT` é usando o buffer. Além disso, a instância tem permissão para ler e modificar o conteúdo do buffer. Se o valor for maior do que um, várias instâncias do `CStringT` pode usar o buffer. Como o buffer de caracteres é compartilhado, `CStringT` instâncias só podem ler o conteúdo do buffer. Para modificar o conteúdo, `CStringT` pela primeira vez, faz uma cópia do buffer. Se o valor for negativo, apenas uma instância de `CStringT` é usando o buffer. Nesse caso, o buffer é considerado bloqueado. Quando um `CStringT` instância não está usando um buffer bloqueado nenhuma outra instância de `CStringT` podem compartilhar o buffer. Em vez disso, essas instâncias de criar uma cópia do buffer antes de manipular o conteúdo. Além disso, o `CStringT` instância usando o buffer bloqueado não tentará compartilhar o buffer de qualquer outro `CStringT` instância atribuída a ele. Nesse caso, o `CStringT` instância copia outra cadeia de caracteres para o buffer bloqueado.

   Ao alocar um `CStringData` estrutura, você deve definir esse campo para refletir o tipo de compartilhamento é permitido para o buffer. Para a maioria das implementações, defina esse valor para um. Isso permite que o comportamento de compartilhamento de cópia na gravação comum. No entanto, se seu gerente de cadeia de caracteres não dá suporte ao compartilhamento de buffer de cadeia de caracteres, defina esse campo para um estado bloqueado. Isso força `CStringT` para usar somente esse buffer para a instância do `CStringT` que o alocado.

## <a name="see-also"></a>Consulte também

[Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)
