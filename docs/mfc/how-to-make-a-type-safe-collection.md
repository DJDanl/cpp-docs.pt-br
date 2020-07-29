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
ms.openlocfilehash: 7e6b0a4181607feaf6e92f5d92d95cb055761aa4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228616"
---
# <a name="how-to-make-a-type-safe-collection"></a>Como fazer uma coleção fortemente tipada

Este artigo explica como criar coleções com segurança de tipos para seus próprios tipos de dados. Os tópicos incluem:

- [Usando classes baseadas em modelo para segurança de tipo](#_core_using_template.2d.based_classes_for_type_safety)

- [Implementando funções auxiliares](#_core_implementing_helper_functions)

- [Usando classes de coleção não modelo](#_core_using_nontemplate_collection_classes)

O biblioteca MFC fornece coleções predefinidas com segurança de tipos com base em modelos C++. Como são modelos, essas classes ajudam a fornecer segurança de tipo e facilidade de uso sem a conversão de tipos e outros trabalhos extras envolvidos no uso de uma classe que não seja de modelo para essa finalidade. O [coletor](../overview/visual-cpp-samples.md) de exemplo do MFC demonstra o uso de classes de coleção baseadas em modelo em um aplicativo MFC. Em geral, use essas classes sempre que você escrever um novo código de coleções.

## <a name="using-template-based-classes-for-type-safety"></a><a name="_core_using_template.2d.based_classes_for_type_safety"></a>Usando classes baseadas em modelo para segurança de tipo

#### <a name="to-use-template-based-classes"></a>Para usar classes baseadas em modelo

1. Declare uma variável do tipo de classe de coleção. Por exemplo:

   [!code-cpp[NVC_MFCCollections#7](codesnippet/cpp/how-to-make-a-type-safe-collection_1.cpp)]

1. Chame as funções de membro do objeto de coleção. Por exemplo:

   [!code-cpp[NVC_MFCCollections#8](codesnippet/cpp/how-to-make-a-type-safe-collection_2.cpp)]

1. Se necessário, implemente as [funções auxiliares](reference/collection-class-helpers.md) e [SerializeElements](reference/collection-class-helpers.md#serializeelements). Para obter informações sobre como implementar essas funções, consulte [implementando funções auxiliares](#_core_implementing_helper_functions).

Este exemplo mostra a declaração de uma lista de inteiros. O primeiro parâmetro na etapa 1 é o tipo de dados armazenados como elementos da lista. O segundo parâmetro especifica como os dados serão passados e retornados das funções de membro da classe de coleção, como `Add` e `GetAt` .

## <a name="implementing-helper-functions"></a><a name="_core_implementing_helper_functions"></a>Implementando funções auxiliares

As classes de coleção baseadas em modelo `CArray` , `CList` e `CMap` usam cinco funções auxiliares globais que você pode personalizar conforme necessário para sua classe de coleção derivada. Para obter informações sobre essas funções auxiliares, consulte [auxiliares de classe de coleção](reference/collection-class-helpers.md) na *referência do MFC*. A implementação da função de serialização é necessária para a maioria dos usos das classes de coleção baseadas em modelo.

### <a name="serializing-elements"></a><a name="_core_serializing_elements"></a>Serializando elementos

As `CArray` `CList` classes, e `CMap` chamam `SerializeElements` para armazenar elementos de coleção ou lê-los de um arquivo morto.

A implementação padrão da `SerializeElements` função auxiliar faz uma gravação bit a bit dos objetos para o arquivo morto ou uma leitura de bits do arquivo morto para os objetos, dependendo se os objetos estão sendo armazenados ou recuperados do arquivo morto. Substituir `SerializeElements` se essa ação não for apropriada.

Se sua coleção armazena objetos derivados de `CObject` e você usa a `IMPLEMENT_SERIAL` macro na implementação da classe de elemento de coleção, você pode aproveitar a funcionalidade de serialização interna do `CArchive` e do `CObject` :

[!code-cpp[NVC_MFCCollections#9](codesnippet/cpp/how-to-make-a-type-safe-collection_3.cpp)]

Os operadores de inserção sobrecarregados para `CArchive` chamada `CObject::Serialize` (ou uma substituição dessa função) para cada `CPerson` objeto.

## <a name="using-nontemplate-collection-classes"></a><a name="_core_using_nontemplate_collection_classes"></a>Usando classes de coleção não modelo

O MFC também dá suporte às classes de coleção introduzidas com a versão 1,0 do MFC. Essas classes não são baseadas em modelos. Eles podem ser usados para conter dados dos tipos com suporte `CObject*` , `UINT` , `DWORD` e `CString` . Você pode usar essas coleções predefinidas (como `CObList` ) para manter coleções de quaisquer objetos derivados de `CObject` . O MFC também fornece outras coleções predefinidas para manter tipos primitivos como, `UINT` e ponteiros void ( **`void*`** ). Em geral, no entanto, geralmente é útil definir suas próprias coleções de tipo seguro para manter objetos de uma classe mais específica e seus derivativos. Observe que fazer isso com as classes de coleção não baseadas em modelos é mais trabalho do que usar as classes baseadas em modelo.

Há duas maneiras de criar coleções com segurança de tipo com as coleções de não modelo:

1. Use as coleções de não modelo, com conversão de tipo, se necessário. Essa é a abordagem mais fácil.

1. Derivar de e estender uma coleção de tipo seguro sem modelo.

#### <a name="to-use-the-nontemplate-collections-with-type-casting"></a>Para usar as coleções de não modelo com conversão de tipo

1. Use uma das classes não modelo, como `CWordArray` , diretamente.

   Por exemplo, você pode criar um `CWordArray` e adicionar quaisquer valores de 32 bits a ele e, em seguida, recuperá-los. Não há nada mais a fazer. Você simplesmente usa a funcionalidade predefinida.

   Você também pode usar uma coleção predefinida, como `CObList` , para manter todos os objetos derivados de `CObject` . Uma `CObList` coleção é definida para conter ponteiros para `CObject` . Quando você recupera um objeto da lista, pode ser necessário converter o resultado para o tipo adequado, uma vez que as `CObList` funções retornam ponteiros para `CObject` . Por exemplo, se você armazenar `CPerson` objetos em uma `CObList` coleção, precisará converter um elemento recuperado para ser um ponteiro para um `CPerson` objeto. O exemplo a seguir usa uma `CObList` coleção para conter `CPerson` objetos:

   [!code-cpp[NVC_MFCCollections#10](codesnippet/cpp/how-to-make-a-type-safe-collection_4.cpp)]

   Essa técnica de usar um tipo de coleção predefinido e a conversão conforme necessário pode ser adequada para muitas das suas necessidades de coleção. Se você precisar de mais funcionalidade ou mais segurança de tipo, use uma classe baseada em modelo ou siga o procedimento a seguir.

#### <a name="to-derive-and-extend-a-nontemplate-type-safe-collection"></a>Para derivar e estender um tipo sem modelo – coleção segura

1. Derive sua própria classe de coleção de uma das classes de não modelo predefinidas.

   Ao derivar sua classe, você pode adicionar funções de wrapper de tipo seguro para fornecer uma interface de tipo seguro a funções existentes.

   Por exemplo, se você tiver derivado uma lista de `CObList` para conter `CPerson` objetos, poderá adicionar as funções de wrapper `AddHeadPerson` e `GetHeadPerson` , conforme mostrado abaixo.

   [!code-cpp[NVC_MFCCollections#11](codesnippet/cpp/how-to-make-a-type-safe-collection_5.h)]

   Essas funções de wrapper fornecem uma maneira de tipo seguro para adicionar e recuperar `CPerson` objetos da lista derivada. Você pode ver que, para a `GetHeadPerson` função, você está simplesmente encapsulando a conversão de tipo.

   Você também pode adicionar novas funcionalidades definindo novas funções que estendem os recursos da coleção em vez de simplesmente encapsular a funcionalidade existente em wrappers de tipo seguro. Por exemplo, o artigo [excluindo todos os objetos em uma coleção CObject](deleting-all-objects-in-a-cobject-collection.md) descreve uma função para excluir todos os objetos contidos em uma lista. Essa função pode ser adicionada à classe derivada como uma função de membro.

## <a name="see-also"></a>Confira também

[Coleções](collections.md)
