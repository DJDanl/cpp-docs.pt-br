---
title: 'Como: fazer uma coleção fortemente tipada | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- type-safe collections [MFC]
- serializing collection-class elements [MFC]
- collection classes [MFC], type safety
- SerializeElements function [MFC]
- collection classes [MFC], template-based
- serialization [MFC], collection classes
- collection classes [MFC], deriving from nontemplate
ms.assetid: 7230b2db-4283-4083-b098-eb231bf5b89e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 58d0d250e17ddd8beaef2a9f5cff4d4e1046fdcb
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46380432"
---
# <a name="how-to-make-a-type-safe-collection"></a>Como fazer uma coleção fortemente tipada

Este artigo explica como criar coleções fortemente tipadas para seus próprios tipos de dados. Os tópicos incluem:

- [Usando classes com base no modelo de segurança de tipo](#_core_using_template.2d.based_classes_for_type_safety)

- [Implementando funções auxiliares](#_core_implementing_helper_functions)

- [Usando classes de coleção de fora do modelo](#_core_using_nontemplate_collection_classes)

A biblioteca Microsoft Foundation Class fornece predefinidas coleções fortemente tipadas com base em modelos de C++. Porque eles são modelos, essas classes ajudam a fornecer o tipo de segurança e facilidade de uso sem a conversão de tipo e outro trabalho extra envolvidas no uso de uma classe de fora do modelo para essa finalidade. O exemplo MFC [COLETAR](../visual-cpp-samples.md) demonstra o uso de classes de coleção com base em modelo em um aplicativo MFC. Em geral, use essas classes sempre que você escrever novo código de coleções.

##  <a name="_core_using_template.2d.based_classes_for_type_safety"></a> Usando Classes com base no modelo de segurança de tipo

#### <a name="to-use-template-based-classes"></a>Para usar as classes com base no modelo

1. Declare uma variável do tipo de classe de coleção. Por exemplo:

     [!code-cpp[NVC_MFCCollections#7](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_1.cpp)]

1. Chame o membro de funções do objeto da coleção. Por exemplo:

     [!code-cpp[NVC_MFCCollections#8](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_2.cpp)]

1. Se necessário, implemente a [funções auxiliares](../mfc/reference/collection-class-helpers.md) e [SerializeElements](../mfc/reference/collection-class-helpers.md#serializeelements). Para obter informações sobre como implementar essas funções, consulte [implementar funções de auxiliar](#_core_implementing_helper_functions).

Este exemplo mostra a declaração de uma lista de inteiros. O primeiro parâmetro na etapa 1 é o tipo de dados armazenados como elementos da lista. O segundo parâmetro especifica como os dados deve ser passados e retornados de funções de membro de classe de coleção, como `Add` e `GetAt`.

##  <a name="_core_implementing_helper_functions"></a> Implementando funções auxiliares

As classes de coleção com base no modelo `CArray`, `CList`, e `CMap` usar cinco funções de auxiliar global que você pode personalizar conforme necessário para sua classe derivada de coleção. Para obter informações sobre essas funções auxiliares, consulte [auxiliares da classe de coleção](../mfc/reference/collection-class-helpers.md) na *referência da MFC*. Implementação da função de serialização é necessária para a maioria dos usos das classes de coleção com base no modelo.

###  <a name="_core_serializing_elements"></a> Serializando elementos

O `CArray`, `CList`, e `CMap` classes chamada `SerializeElements` para armazenar elementos de coleção para ou de leitura-los de um arquivo.

A implementação padrão da `SerializeElements` função auxiliar faz uma gravação de bit a bit de objetos para o arquivo morto ou de leitura do arquivo morto para os objetos, dependendo se os objetos estão sendo armazenados em um bit a bit ou recuperado do arquivo morto. Substituir `SerializeElements` se esta ação não é apropriada.

Se sua coleção armazena objetos derivados de `CObject` e você usar o `IMPLEMENT_SERIAL` macro na implementação de classe de elemento da coleção, você pode aproveitar a funcionalidade de serialização incorporada `CArchive` e `CObject`:

[!code-cpp[NVC_MFCCollections#9](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_3.cpp)]

Os operadores de inserção sobrecarregado para `CArchive` chamar `CObject::Serialize` (ou uma substituição dessa função) para cada `CPerson` objeto.

##  <a name="_core_using_nontemplate_collection_classes"></a> Usando Classes de coleção de fora do modelo

MFC também oferece suporte as classes de coleção introduzidas com o MFC versão 1.0. Essas classes não são baseadas em modelos. Eles podem ser usados para conter dados dos tipos suportados `CObject*`, `UINT`, `DWORD`, e `CString`. Você pode usar essas coleções predefinidas (como `CObList`) para armazenar coleções de qualquer objeto derivado de `CObject`. O MFC também fornece outras coleções predefinidas para conter tipos primitivos, como `UINT` e anular ponteiros (`void`*). Em geral, no entanto, muitas vezes é útil definir suas próprias coleções fortemente tipadas para manter objetos de uma classe mais específica e seus derivados. Observe que não fazer isso com as classes de coleção com base em modelos é mais trabalho do que usando as classes com base no modelo.

Há duas maneiras de criar coleções fortemente tipadas com as coleções de fora do modelo:

1. Use as coleções de fora do modelo, com o tipo de conversão se necessário. Essa é a abordagem mais fácil.

1. Derivam e estender uma coleção fortemente tipada de fora do modelo.

#### <a name="to-use-the-nontemplate-collections-with-type-casting"></a>Para usar as coleções de fora do modelo com a conversão de tipo

1. Use uma das classes nontemplate, tais como `CWordArray`, diretamente.

     Por exemplo, você pode criar um `CWordArray` adicionar quaisquer valores de 32 bits a ele e recuperá-los. Não há nada mais o que fazer. Você simplesmente usar a funcionalidade predefinida.

     Você também pode usar uma coleção predefinida, como `CObList`, para manter qualquer objeto derivado de `CObject`. Um `CObList` coleta está definida para conter os ponteiros para `CObject`. Quando você recupera um objeto da lista, talvez você precise converter o resultado para o tipo apropriado, desde o `CObList` funções retornam ponteiros para `CObject`. Por exemplo, se você armazenar `CPerson` objetos em um `CObList` coleção, você tem que converter um elemento recuperado para ser um ponteiro para um `CPerson` objeto. O exemplo a seguir usa uma `CObList` coleção para conter `CPerson` objetos:

     [!code-cpp[NVC_MFCCollections#10](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_4.cpp)]

     Essa técnica de usar um tipo de coleção predefinido e conforme a necessidade de conversão pode ser adequada para muitas das suas necessidades de coleção. Se você precisar de funcionalidade adicional ou mais segurança de tipo, use uma classe de modelo ou siga o procedimento a seguir.

#### <a name="to-derive-and-extend-a-nontemplate-type-safe-collection"></a>Derivar e estender uma coleção fortemente tipada de fora do modelo

1. Derive sua própria classe de coleção de uma das classes predefinidas fora do modelo.

     Ao derivar de sua classe, você pode adicionar funções de wrapper fortemente tipado para fornecer uma interface de tipo seguro para as funções existentes.

     Por exemplo, se você derivado de uma lista de `CObList` para manter `CPerson` objetos, você pode adicionar as funções de invólucro `AddHeadPerson` e `GetHeadPerson`, conforme mostrado abaixo.

     [!code-cpp[NVC_MFCCollections#11](../mfc/codesnippet/cpp/how-to-make-a-type-safe-collection_5.h)]

     Essas funções de wrapper fornecem uma maneira fortemente tipada para adicionar e recuperar `CPerson` objetos da lista derivada. Você pode ver que para o `GetHeadPerson` função, basta encapsular a conversão de tipo.

     Você também pode adicionar novas funcionalidades definindo novas funções que estendem os recursos da coleção em vez de apenas envolvendo a funcionalidade existente nos wrappers de tipo seguro. Por exemplo, o artigo [excluindo todos os objetos em uma coleção CObject](../mfc/deleting-all-objects-in-a-cobject-collection.md) descreve uma função para excluir todos os objetos contidos em uma lista. Essa função pode ser adicionada à classe derivada como uma função de membro.

## <a name="see-also"></a>Consulte também

[Coleções](../mfc/collections.md)

