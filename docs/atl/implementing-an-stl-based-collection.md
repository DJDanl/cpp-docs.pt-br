---
title: Implementando uma coleção baseada em biblioteca padrão C++
ms.date: 11/04/2016
helpviewer_keywords:
- ICollectionOnSTLImpl interface
ms.assetid: 6d49f819-1957-4813-b074-3f12c494d8ca
ms.openlocfilehash: e80ce5e7bbc6b9c6be1615dad1ea43c18e03eb55
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319433"
---
# <a name="implementing-a-c-standard-library-based-collection"></a>Implementando uma coleção baseada em biblioteca padrão C++

A ATL `ICollectionOnSTLImpl` fornece a interface para permitir que você implemente rapidamente interfaces de coleção baseadas em BibliotecaS C++ em seus objetos. Para entender como essa classe funciona, você trabalhará através de um exemplo simples (abaixo) que usa essa classe para implementar uma coleção somente de leitura voltada para clientes de Automação.

O código amostral é da [amostra ATLCollections](../overview/visual-cpp-samples.md).

Para completar este procedimento, você irá:

- [Gerar um novo objeto simples](#vccongenerating_an_object).

- [Edite o arquivo IDL](#vcconedit_the_idl) para a interface gerada.

- [Crie cinco typedefs](#vcconstorage_and_exposure_typedefs) descrevendo como os itens de coleção são armazenados e como eles serão expostos aos clientes através de interfaces COM.

- [Crie dois typedefs para classes de diretiva de cópia](#vcconcopy_classes).

- [Criar typedefs para as implementações de enumerador e coleção](#vcconenumeration_and_collection).

- [Edite o código C++ gerado pelo assistente para usar o typedef de coleção](#vcconedit_the_generated_code).

- [Adicionar código para preencher a coleção](#vcconpopulate_the_collection).

## <a name="generating-a-new-simple-object"></a><a name="vccongenerating_an_object"></a>Gerando um novo objeto simples

Crie um novo projeto, garantindo que a caixa Atributos em Configurações de aplicativo seja limpa. Use a caixa de diálogo ATL Add Class e `Words`adicione o Assistente de Objeto Simples para gerar um objeto simples chamado . Certifique-se de que `IWords` uma interface dupla chamada seja gerada. Objetos da classe gerada serão usados para representar uma coleção de palavras (isto é, strings).

## <a name="editing-the-idl-file"></a><a name="vcconedit_the_idl"></a>Edição do arquivo IDL

Agora, abra o arquivo IDL e adicione `IWords` as três propriedades necessárias para se transformar em uma interface de coleta somente leitura, como mostrado abaixo:

[!code-cpp[NVC_ATL_COM#24](../atl/codesnippet/cpp/implementing-an-stl-based-collection_1.idl)]

Este é o formulário padrão para uma interface de coleção somente leitura projetada com clientes de Automação em mente. Os comentários numerados nesta definição de interface correspondem aos comentários abaixo:

1. As interfaces de cobrança geralmente são `_NewEnum` duplas `IDispatch::Invoke`porque os clientes de Automação acessam o imóvel via . No entanto, os clientes de Automação podem acessar os métodos restantes através da vtable, de modo que interfaces duplas são preferíveis a dispinterfaces.

1. Se uma interface dupla ou dispinterface não for estendida no tempo de execução (ou seja, você não fornecerá métodos ou propriedades extras via), `IDispatch::Invoke`você deve aplicar o atributo não **extensível** à sua definição. Esse atributo permite que os clientes de automação realizem a verificação completa do código no momento da compilação. Neste caso, a interface não deve ser estendida.

1. O DISPID correto é importante se você quiser que os clientes de Automação possam usar esta propriedade. (Note que há apenas um sublinhado em DISPID_NEWENUM.)

1. Você pode fornecer qualquer valor como o `Item` DISPID da propriedade. No `Item` entanto, normalmente usa DISPID_VALUE para torná-lo a propriedade padrão da coleção. Isso permite que os clientes da Automação se refiram ao imóvel sem nomeá-lo explicitamente.

1. O tipo de dados utilizado `Item` para o valor de devolução do imóvel é o tipo de item armazenado na coleção no que diz respeito aos clientes COM. A interface retorna as strings, então você deve usar o tipo de string COM padrão, BSTR. Você pode armazenar os dados em um formato diferente internamente, como você verá em breve.

1. O valor utilizado para o DISPID da `Count` propriedade é completamente arbitrário. Não há DISPID padrão para esta propriedade.

## <a name="creating-typedefs-for-storage-and-exposure"></a><a name="vcconstorage_and_exposure_typedefs"></a>Criando typedefs para armazenamento e exposição

Uma vez definida a interface de coleta, você precisa decidir como os dados serão armazenados e como os dados serão expostos através do enumerador.

As respostas a essas perguntas podem ser fornecidas na forma de uma série de typedefs, que você pode adicionar perto da parte superior do arquivo de cabeçalho para sua classe recém-criada:

[!code-cpp[NVC_ATL_COM#25](../atl/codesnippet/cpp/implementing-an-stl-based-collection_2.h)]

Neste caso, você armazenará os dados como um **std::vetor** de **std::string**s. **std::vector** é uma classe de contêiner C++ Standard Library que se comporta como uma matriz gerenciada. **std::string** é a classe de strings da C++ Standard Library. Essas aulas facilitam o trabalho com uma coleção de cordas.

Como o suporte visual básico é vital para o sucesso desta `_NewEnum` interface, o `IEnumVARIANT` enumerador devolvido pela propriedade deve suportar a interface. Esta é a única interface enumeradora entendida pelo Visual Basic.

## <a name="creating-typedefs-for-copy-policy-classes"></a><a name="vcconcopy_classes"></a>Criando typedefs para classes de diretiva de cópia

Os typedefs criados até agora fornecem todas as informações necessárias para criar mais tipodefs para as classes de cópia que serão usadas pelo enumerador e coleção:

[!code-cpp[NVC_ATL_COM#26](../atl/codesnippet/cpp/implementing-an-stl-based-collection_3.h)]

Neste exemplo, você pode `GenericCopy` usar a classe personalizada definida em VCUE_Copy.h e VCUE_CopyString.h da amostra [ATLCollections.](../overview/visual-cpp-samples.md) Você pode usar esta classe em outro código, mas talvez `GenericCopy` seja necessário definir mais especializações para suportar tipos de dados usados em suas próprias coleções. Para obter mais informações, consulte [ATL Copy Policy Classes](../atl/atl-copy-policy-classes.md).

## <a name="creating-typedefs-for-enumeration-and-collection"></a><a name="vcconenumeration_and_collection"></a>Criação de Typedefs para Enumeração e Coleção

Agora, todos os parâmetros `CComEnumOnSTL` `ICollectionOnSTLImpl` de modelo necessários para especializar a situação foram fornecidos sob a forma de typedefs. Para simplificar o uso das especializações, crie mais dois typedefs, conforme mostrado abaixo:

[!code-cpp[NVC_ATL_COM#27](../atl/codesnippet/cpp/implementing-an-stl-based-collection_4.h)]

Agora `CollectionType` é um sinônimo para `ICollectionOnSTLImpl` uma especialização que implementa a `IWords` interface definida `IEnumVARIANT`anteriormente e fornece um enumerador que suporta .

## <a name="editing-the-wizard-generated-code"></a><a name="vcconedit_the_generated_code"></a>Edição do código gerado pelo assistente

Agora você `CWords` deve derivar da `CollectionType` implementação da `IWords`interface representada pelo typedef em vez de , como mostrado abaixo:

[!code-cpp[NVC_ATL_COM#28](../atl/codesnippet/cpp/implementing-an-stl-based-collection_5.h)]

## <a name="adding-code-to-populate-the-collection"></a><a name="vcconpopulate_the_collection"></a>Adicionando código para preencher a coleção

A única coisa que resta é preencher o vetor com dados. Neste simples exemplo, você pode adicionar algumas palavras à coleção na construtora para a classe:

[!code-cpp[NVC_ATL_COM#29](../atl/codesnippet/cpp/implementing-an-stl-based-collection_6.h)]

Agora, você pode testar o código com o cliente de sua escolha.

## <a name="see-also"></a>Confira também

[Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)<br/>
[Amostra atlcollections](../overview/visual-cpp-samples.md)<br/>
[Classes de política de cópia atl](../atl/atl-copy-policy-classes.md)
