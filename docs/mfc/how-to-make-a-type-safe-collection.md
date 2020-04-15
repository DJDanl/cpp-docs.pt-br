---
title: Como fazer uma coleção fortemente tipada
ms.date: 11/04/2016
helpviewer_keywords:
- type-safe collections [MFC]
- serializing collection-class elements [MFC]
- collection classes [MFC], type safety
- SerializeElements function [MFC]
- collection classes [MFC], template-based
- serialization [MFC], collection classes
- collection classes [MFC], deriving from nontemplate
ms.assetid: 7230b2db-4283-4083-b098-eb231bf5b89e
ms.openlocfilehash: 1901100996a776244b57efe0951795ceec3c630a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377258"
---
# <a name="how-to-make-a-type-safe-collection"></a>Como fazer uma coleção fortemente tipada

Este artigo explica como fazer coletas seguras de tipo para seus próprios tipos de dados. Os tópicos incluem:

- [Usando classes baseadas em modelos para segurança de tipo](#_core_using_template.2d.based_classes_for_type_safety)

- [Implementando funções auxiliares](#_core_implementing_helper_functions)

- [Usando classes de coleta sem modelo](#_core_using_nontemplate_collection_classes)

A Biblioteca de Classes da Microsoft Foundation fornece coleções predefinidas baseadas em modelos C++. Por serem modelos, essas aulas ajudam a fornecer segurança do tipo e facilidade de uso sem o casting de tipos e outros trabalhos extras envolvidos no uso de uma classe não-modelo para este fim. O MFC sample [COLLECT](../overview/visual-cpp-samples.md) demonstra o uso de classes de coleta baseadas em modelos em um aplicativo MFC. Em geral, use essas classes sempre que escrever novos códigos de coleções.

## <a name="using-template-based-classes-for-type-safety"></a><a name="_core_using_template.2d.based_classes_for_type_safety"></a>Usando classes baseadas em modelos para segurança de tipo

#### <a name="to-use-template-based-classes"></a>Para usar classes baseadas em modelos

1. Declare uma variável do tipo de classe de coleta. Por exemplo:

   [!code-cpp[NVC_MFCCollections#7](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_1.cpp)]

1. Chame as funções de membro do objeto de coleta. Por exemplo:

   [!code-cpp[NVC_MFCCollections#8](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_2.cpp)]

1. Se necessário, implemente as [funções do ajudante](../mfc/reference/collection-class-helpers.md) e [SerializeElements](../mfc/reference/collection-class-helpers.md#serializeelements). Para obter informações sobre a implementação dessas funções, consulte [Implementando funções auxiliares](#_core_implementing_helper_functions).

Este exemplo mostra a declaração de uma lista de inteiros. O primeiro parâmetro na etapa 1 é o tipo de dados armazenados como elementos da lista. O segundo parâmetro especifica como os dados devem ser passados e devolvidos das `Add` funções membros da classe de coleta, tais como e `GetAt`.

## <a name="implementing-helper-functions"></a><a name="_core_implementing_helper_functions"></a>Implementando funções auxiliares

As classes de `CArray`coleção `CList`baseadas em modelos e `CMap` usam cinco funções de ajudante global que você pode personalizar conforme necessário para a sua classe de coleção derivada. Para obter informações sobre essas funções auxiliares, consulte [Os Ajudantes de Classe de Coleta](../mfc/reference/collection-class-helpers.md) na referência *MFC*. A implementação da função de serialização é necessária para a maioria dos usos das classes de coleção baseadas em modelos.

### <a name="serializing-elements"></a><a name="_core_serializing_elements"></a>Elementos serializadores

As `CArray` `CList`aulas `CMap` e `SerializeElements` as classes chamam para armazenar elementos de coleção ou lê-los a partir de um arquivo.

A implementação `SerializeElements` padrão da função helper faz uma gravação bitwise dos objetos para o arquivo, ou uma leitura bitwise do arquivo para os objetos, dependendo se os objetos estão sendo armazenados ou recuperados do arquivo. Anular `SerializeElements` se essa ação não for apropriada.

Se sua coleção armazena `CObject` objetos derivados e você usa a `IMPLEMENT_SERIAL` macro na implementação da classe de `CArchive` `CObject`elementos de coleta, você pode aproveitar a funcionalidade de serialização incorporada e:

[!code-cpp[NVC_MFCCollections#9](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_3.cpp)]

Os operadores de `CArchive` inserção sobrecarregados para chamada `CObject::Serialize` (ou uma substituição dessa função) para cada `CPerson` objeto.

## <a name="using-nontemplate-collection-classes"></a><a name="_core_using_nontemplate_collection_classes"></a>Usando classes de coleta não-modelo

O MFC também suporta as classes de coleta introduzidas com a versão 1.0 do MFC. Essas classes não são baseadas em modelos. Eles podem ser usados para conter `CObject*` `UINT`dados `DWORD`dos `CString`tipos suportados, e . Você pode usar essas coleções predefinidas (como `CObList`) para guardar `CObject`coleções de quaisquer objetos derivados de . O MFC também fornece outras coleções predefinidas para manter tipos primitivos, como `UINT` e ponteiros vazios (*).`void` Em geral, no entanto, muitas vezes é útil definir suas próprias coleções de tipo seguros para guardar objetos de uma classe mais específica e seus derivados. Observe que fazer isso com as classes de coleta não baseadas em modelos é mais trabalhoso do que usar as classes baseadas em modelos.

Existem duas maneiras de criar coleções seguras de tipo com as coleções não-modelo:

1. Use as coleções não-modelo, com fundição de tipo, se necessário. Esta é a abordagem mais fácil.

1. Derivar e estender uma coleção não-modelo de segurança de tipo.

#### <a name="to-use-the-nontemplate-collections-with-type-casting"></a>Para usar as coleções não-modelo com fundição de tipo

1. Use uma das classes não-modelo, tais como `CWordArray`, diretamente.

   Por exemplo, você `CWordArray` pode criar um e adicionar quaisquer valores de 32 bits a ele, em seguida, recuperá-los. Não há mais nada para fazer. Basta usar a funcionalidade predefinida.

   Você também pode usar uma coleção `CObList`predefinida, como, `CObject`para segurar quaisquer objetos derivados de . Uma `CObList` coleção é definida para `CObject`segurar ponteiros para . Quando você recupera um objeto da lista, você pode ter que `CObList` lançar o resultado `CObject`para o tipo adequado, uma vez que as funções retornam ponteiros para . Por exemplo, se `CPerson` você `CObList` armazenar objetos em uma coleção, você tem `CPerson` que lançar um elemento recuperado para ser um ponteiro para um objeto. O exemplo a `CObList` seguir `CPerson` usa uma coleção para guardar objetos:

   [!code-cpp[NVC_MFCCollections#10](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_4.cpp)]

   Esta técnica de usar um tipo de coleta predefinido e fundição conforme necessário pode ser adequada para muitas de suas necessidades de coleta. Se você precisar de mais funcionalidade ou mais segurança de tipo, use uma classe baseada em modelo ou siga o próximo procedimento.

#### <a name="to-derive-and-extend-a-nontemplate-type-safe-collection"></a>Para derivar e estender uma coleção não-modelo segura de tipo

1. Obtenha sua própria classe de coleção de uma das classes não-modelo predefinidas.

   Quando você deriva sua classe, você pode adicionar funções de invólucro de tipo para fornecer uma interface de tipo segura às funções existentes.

   Por exemplo, se você derivado `CObList` de `CPerson` uma lista de para segurar `AddHeadPerson` `GetHeadPerson`objetos, você pode adicionar as funções de invólucro e , como mostrado abaixo.

   [!code-cpp[NVC_MFCCollections#11](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_5.h)]

   Essas funções de invólucro fornecem uma `CPerson` maneira segura de adicionar e recuperar objetos da lista derivada. Você pode ver `GetHeadPerson` que para a função, você está simplesmente encapsulando o tipo de fundição.

   Você também pode adicionar novas funcionalidades definindo novas funções que ampliam os recursos da coleção em vez de apenas envolver a funcionalidade existente em embalagens seguras de tipo. Por exemplo, o artigo [Excluindo todos os objetos em uma Coleção CObject](../mfc/deleting-all-objects-in-a-cobject-collection.md) descreve uma função para excluir todos os objetos contidos em uma lista. Esta função pode ser adicionada à classe derivada como uma função membro.

## <a name="see-also"></a>Confira também

[Coleções](../mfc/collections.md)
