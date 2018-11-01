---
title: Acessando todos os membros de uma coleção
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, collections
- enumerations [MFC]
- enumerating collections [MFC]
- collections [MFC], accessing
- collection classes [MFC]
- ', '
- ', '
- ', '
- ', '
- ', '
- ', '
- ', '
ms.assetid: 7bbae518-062e-4393-81f9-b22abd2e5f59
ms.openlocfilehash: b6c79164bc1049f39ce0af4e00341df8f234b34a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50628807"
---
# <a name="accessing-all-members-of-a-collection"></a>Acessando todos os membros de uma coleção

As classes de coleção MFC matriz — ambos baseada em modelo e não — usar índices para acessar seus elementos. As classes de coleção de lista e mapa MFC — ambos baseada em modelo e não — use um indicador do tipo **posição** para descrever uma determinada posição dentro da coleção. Para acessar um ou mais membros dessas coleções, você primeiro inicializar o indicador de posição e, em seguida, repetidamente passa nessa posição na coleção e solicita que ele retorne o próximo elemento. A coleção não é responsável por manter informações de estado sobre o progresso da iteração. Essa informação é mantida no indicador de posição. Mas, considerando uma posição específica, a coleção é responsável por retornar o próximo elemento.

Os procedimentos a seguir mostram como iterar sobre os três principais tipos de coleções fornecidos com o MFC:

- [Percorrer uma matriz](#_core_to_iterate_an_array)

- [Iteração de uma lista](#_core_to_iterate_a_list)

- [Iteração de um mapa](#_core_to_iterate_a_map)

### <a name="_core_to_iterate_an_array"></a> Para iterar uma matriz

1. Usar números de índice sequenciais com o `GetAt` função de membro:

   [!code-cpp[NVC_MFCCollections#12](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_1.cpp)]

   Este exemplo usa uma matriz de ponteiro tipado que contém ponteiros para `CPerson` objetos. A matriz é derivada da classe `CObArray`, uma da nontemplate classes predefinidas. `GetAt` Retorna um ponteiro para um `CPerson` objeto. Para classes de coleção do tipo ponteiro — matrizes ou listas — o primeiro parâmetro especifica a classe base; o segundo parâmetro especifica o tipo para armazenar.

   O `CTypedPtrArray` classe também sobrecargas a **[]** operador para que você possa usar a sintaxe de subscrito de matriz comum para acessar os elementos de uma matriz. Uma alternativa para a instrução do corpo do **para** loop acima é

   [!code-cpp[NVC_MFCCollections#13](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_2.cpp)]

   Esse operador existe em ambos **const** e não-**const** versões. O **const** versão, que é invocado para **const** matrizes, pode aparecer somente no lado direito de uma instrução de atribuição.

### <a name="_core_to_iterate_a_list"></a> Para obter uma lista de iterar

1. Use as funções de membro `GetHeadPosition` e `GetNext` para examinar a lista:

   [!code-cpp[NVC_MFCCollections#14](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_3.cpp)]

   Este exemplo usa uma lista de ponteiro tipado para contêm ponteiros para `CPerson` objetos. A declaração de lista é semelhante o um para a matriz no procedimento [para iterar uma matriz](#_core_to_iterate_an_array) , mas é derivada da classe `CObList`. `GetNext` Retorna um ponteiro para um `CPerson` objeto.

### <a name="_core_to_iterate_a_map"></a> Para iterar um mapa

1. Use `GetStartPosition` para obter até o início do mapa e `GetNextAssoc` repetidamente obter a próxima chave e valor do mapa, conforme mostrado no exemplo a seguir:

   [!code-cpp[NVC_MFCCollections#15](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_4.cpp)]

   Este exemplo usa um modelo simples de mapa (em vez de uma coleção com tipo de ponteiro) que utiliza `CString` as chaves e armazena ponteiros para `CPerson` objetos. Quando você usa funções de acesso, como `GetNextAssoc`, a classe fornece ponteiros para `CPerson` objetos. Se você usar uma das coleções de mapa fora do modelo em vez disso, você deve converter retornado `CObject` ponteiro para um ponteiro para um `CPerson`.

    > [!NOTE]
    >  Para mapas de fora do modelo, o compilador requer uma referência a um `CObject` ponteiro no último parâmetro para `GetNextAssoc`. Na entrada, você deve converter os ponteiros para tipo, conforme mostrado no exemplo a seguir.

   A solução de modelo é mais simples e ajuda a fornecer a melhor segurança de tipos. O código fora do modelo é mais complicado, como você pode ver aqui:

   [!code-cpp[NVC_MFCCollections#16](../mfc/codesnippet/cpp/accessing-all-members-of-a-collection_5.cpp)]

Para obter mais informações, consulte [excluindo todos os objetos em uma coleção CObject](../mfc/deleting-all-objects-in-a-cobject-collection.md).

## <a name="see-also"></a>Consulte também

[Coleções](../mfc/collections.md)

