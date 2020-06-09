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
ms.openlocfilehash: 0d8b5491ee5321171ef358308f3c1548e43953d3
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616491"
---
# <a name="accessing-all-members-of-a-collection"></a>Acessando todos os membros de uma coleção

As classes de coleção de matriz do MFC (baseadas em modelo e não) usam índices para acessar seus elementos. A lista do MFC e as classes de coleção do mapa — baseadas em modelo e não — usam um indicador da **posição** do tipo para descrever uma determinada posição dentro da coleção. Para acessar um ou mais membros dessas coleções, primeiro você inicializa o indicador de posição e, em seguida, passa repetidamente essa posição para a coleção e solicita que ele retorne o próximo elemento. A coleção não é responsável por manter informações de estado sobre o progresso da iteração. Essas informações são mantidas no indicador de posição. Mas, considerando uma determinada posição, a coleção é responsável por retornar o próximo elemento.

Os procedimentos a seguir mostram como iterar nos três tipos principais de coleções fornecidas com o MFC:

- [Iterando uma matriz](#_core_to_iterate_an_array)

- [Iterando uma lista](#_core_to_iterate_a_list)

- [Iterando um mapa](#_core_to_iterate_a_map)

### <a name="to-iterate-an-array"></a><a name="_core_to_iterate_an_array"></a>Para iterar uma matriz

1. Use números de índice sequenciais com a `GetAt` função de membro:

   [!code-cpp[NVC_MFCCollections#12](codesnippet/cpp/accessing-all-members-of-a-collection_1.cpp)]

   Este exemplo usa uma matriz de ponteiro tipado que contém ponteiros para `CPerson` objetos. A matriz é derivada da classe `CObArray` , uma das classes predefinidas não modelo. `GetAt`Retorna um ponteiro para um `CPerson` objeto. Para classes de coleção de ponteiro tipado — matrizes ou listas — o primeiro parâmetro especifica a classe base; o segundo parâmetro especifica o tipo a ser armazenado.

   A `CTypedPtrArray` classe também sobrecarrega o operador **[]** para que você possa usar a sintaxe matriz-subscript personalizada para acessar os elementos de uma matriz. Uma alternativa à instrução no corpo do loop **for** acima é

   [!code-cpp[NVC_MFCCollections#13](codesnippet/cpp/accessing-all-members-of-a-collection_2.cpp)]

   Esse operador existe em versões **const** e não**const** . A versão **const** , que é invocada para matrizes **const** , pode aparecer somente no lado direito de uma instrução de atribuição.

### <a name="to-iterate-a-list"></a><a name="_core_to_iterate_a_list"></a>Para iterar uma lista

1. Use as funções de membro `GetHeadPosition` e `GetNext` para trabalhar na lista:

   [!code-cpp[NVC_MFCCollections#14](codesnippet/cpp/accessing-all-members-of-a-collection_3.cpp)]

   Este exemplo usa uma lista de ponteiros tipados para conter ponteiros para `CPerson` objetos. A declaração de lista é semelhante a uma para a matriz no procedimento [para iterar uma matriz](#_core_to_iterate_an_array) , mas é derivada da classe `CObList` . `GetNext`Retorna um ponteiro para um `CPerson` objeto.

### <a name="to-iterate-a-map"></a><a name="_core_to_iterate_a_map"></a>Para iterar um mapa

1. Use `GetStartPosition` para chegar ao início do mapa e `GetNextAssoc` para obter repetidamente a próxima chave e o valor do mapa, conforme mostrado no exemplo a seguir:

   [!code-cpp[NVC_MFCCollections#15](codesnippet/cpp/accessing-all-members-of-a-collection_4.cpp)]

   Este exemplo usa um modelo de mapa simples (em vez de uma coleção de ponteiros tipados) que usa `CString` chaves e armazena ponteiros para `CPerson` objetos. Quando você usa funções de acesso como `GetNextAssoc` , a classe fornece ponteiros para `CPerson` objetos. Se você usar uma das coleções de mapa não modelo, deverá converter o `CObject` ponteiro retornado em um ponteiro para um `CPerson` .

    > [!NOTE]
    >  Para mapas não modelo, o compilador requer uma referência a um `CObject` ponteiro no último parâmetro para `GetNextAssoc` . Na entrada, você deve converter seus ponteiros para esse tipo, conforme mostrado no exemplo a seguir.

   A solução de modelo é mais simples e ajuda a fornecer uma melhor segurança de tipo. O código não modelo é mais complicado, como você pode ver aqui:

   [!code-cpp[NVC_MFCCollections#16](codesnippet/cpp/accessing-all-members-of-a-collection_5.cpp)]

Para obter mais informações, consulte [excluindo todos os objetos em uma coleção CObject](deleting-all-objects-in-a-cobject-collection.md).

## <a name="see-also"></a>Consulte também

[Coleções](collections.md)
