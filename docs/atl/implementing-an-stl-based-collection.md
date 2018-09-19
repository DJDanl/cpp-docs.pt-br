---
title: Implementando uma coleção de baseada na biblioteca padrão C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ICollectionOnSTLImpl interface
ms.assetid: 6d49f819-1957-4813-b074-3f12c494d8ca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d414df9d5e5f7d930497d42b5ec73d92a65ac3cc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46116694"
---
# <a name="implementing-a-c-standard-library-based-collection"></a>Implementando uma coleção de baseada na biblioteca padrão C++

ATL fornece o `ICollectionOnSTLImpl` interface para que você possa implementar rapidamente as interfaces de coleção baseada na biblioteca padrão C++ em seus objetos. Para entender como funciona essa classe, você irá trabalhar por meio de um exemplo simples (abaixo) que usa essa classe para implementar uma coleção somente leitura que visa clientes de automação.

O código de exemplo é do [ATLCollections exemplo](../visual-cpp-samples.md).

Para concluir este procedimento, você irá:

- [Gerar um novo objeto simples](#vccongenerating_an_object).

- [Edite o arquivo IDL](#vcconedit_the_idl) para a interface gerada.

- [Criar definições de cinco tipo](#vcconstorage_and_exposure_typedefs) que descrevem como os itens de coleta são armazenados e como eles serão expostos a clientes por meio de interfaces COM.

- [Crie duas definições de tipo para cópia de classes de política](#vcconcopy_classes).

- [Criar definições de tipo para as implementações de coleção e enumerador](#vcconenumeration_and_collection).

- [Editar o código de C++ gerado pelo Assistente para usar a definição de tipo de coleção](#vcconedit_the_generated_code).

- [Adicione código para preencher a coleção](#vcconpopulate_the_collection).

##  <a name="vccongenerating_an_object"></a> Gerar um novo objeto Simple

Crie um novo projeto, garantindo que a caixa de atributos em configurações de aplicativo está desmarcada. Use a caixa de diálogo Adicionar classe de ATL e adicionar Simple Object Wizard para gerar um objeto simples chamado `Words`. Certifique-se de que uma interface dupla chamado `IWords` é gerado. Objetos da classe gerada serão ser usados para representar um conjunto de palavras (isto é, cadeias de caracteres).

##  <a name="vcconedit_the_idl"></a> Editando o arquivo IDL

Agora, abra o arquivo IDL e adicione as três propriedades necessárias para ativar `IWords` em uma interface de coleção somente leitura, conforme mostrado abaixo:

[!code-cpp[NVC_ATL_COM#24](../atl/codesnippet/cpp/implementing-an-stl-based-collection_1.idl)]

Este é o formulário padrão para uma interface de coleção somente leitura projetado com clientes de automação em mente. Os comentários numerados nesta definição de interface correspondem aos comentários abaixo:

1. Interfaces de coleção são geralmente duplos porque os clientes de automação acessa o `_NewEnum` propriedade via `IDispatch::Invoke`. No entanto, os clientes de automação podem acessar os métodos restantes via vtable, para que as interfaces duplas são preferíveis para dispinterfaces.

2. Se uma interface dupla ou dispinterface não será estendido em tempo de execução (ou seja, você não fornecer métodos extras ou propriedades por meio `IDispatch::Invoke`), você deve aplicar a **nonextensible** à sua definição de atributo. Este atributo permite que os clientes de automação realizar a verificação de código completo no tempo de compilação. Nesse caso, a interface não deve ser estendida.

3. O DISPID correto é importante se você deseja que os clientes de automação para ser capaz de usar essa propriedade. (Observe que há apenas um sublinhado no DISPID_NEWENUM.)

4. Você pode fornecer qualquer valor como o DISPID do `Item` propriedade. No entanto, `Item` normalmente usa DISPID_VALUE para torná-lo a propriedade padrão da coleção. Isso permite que os clientes de automação para se referir à propriedade sem nomeá-lo explicitamente.

5. O tipo de dados usado para o valor de retorno de `Item` propriedade é o tipo do item armazenado na coleção, como os clientes COM estão preocupados. A interface retorna cadeias de caracteres, portanto, você deve usar o tipo de cadeia de caracteres COM padrão, BSTR. Você pode armazenar os dados em um formato diferente internamente como você verá em breve.

6. O valor usado para o DISPID do `Count` propriedade é completamente arbitrária. Não há nenhum DISPID padrão para essa propriedade.

##  <a name="vcconstorage_and_exposure_typedefs"></a> Criando definições de tipo para o armazenamento e a exposição

Depois que a interface de coleção é definida, você precisa decidir como os dados serão armazenados e como os dados serão expostos através do enumerador.

As respostas a essas perguntas podem ser fornecidas na forma de um número de definições de tipo, que pode ser adicionado na parte superior do arquivo de cabeçalho para a sua classe recém-criado:

[!code-cpp[NVC_ATL_COM#25](../atl/codesnippet/cpp/implementing-an-stl-based-collection_2.h)]

Nesse caso, você armazenará os dados como uma **std:: Vector** dos **std:: string**s. **std:: Vector** é uma classe de contêiner de biblioteca padrão C++ que se comporta como uma matriz gerenciada. **std:: string** é a classe de cadeia de caracteres da biblioteca padrão C++. Essas classes tornam fácil trabalhar com uma coleção de cadeias de caracteres.

Como o suporte ao Visual Basic é essencial para o sucesso dessa interface, o enumerador retornado pelo `_NewEnum` propriedade deve oferecer suporte a `IEnumVARIANT` interface. Essa é a interface de enumerador somente compreendida pelo Visual Basic.

##  <a name="vcconcopy_classes"></a> Criando definições de tipo para Classes de política de cópia

As definições de tipo que você criou até agora fornecem todas as informações que você precisa criar mais definições de tipo para as classes de cópia que serão usadas pelo enumerador e a coleção:

[!code-cpp[NVC_ATL_COM#26](../atl/codesnippet/cpp/implementing-an-stl-based-collection_3.h)]

Neste exemplo, você pode usar o custom `GenericCopy` classe definida em VCUE_Copy.h e VCUE_CopyString.h do [ATLCollections](../visual-cpp-samples.md) exemplo. Você pode usar essa classe em outro código, mas talvez você precise definir ainda mais especializações de `GenericCopy` para dar suporte a tipos de dados usados em suas próprias coleções. Para obter mais informações, consulte [Classes de política de cópia de ATL](../atl/atl-copy-policy-classes.md).

##  <a name="vcconenumeration_and_collection"></a> Criando definições de tipo de enumeração e coleção

Agora todos os parâmetros de modelo necessários especializar o `CComEnumOnSTL` e `ICollectionOnSTLImpl` classes para essa situação foram fornecidas na forma de definições de tipo. Para simplificar o uso de especializações, crie duas mais definições de tipo conforme mostrado abaixo:

[!code-cpp[NVC_ATL_COM#27](../atl/codesnippet/cpp/implementing-an-stl-based-collection_4.h)]

Agora `CollectionType` é um sinônimo para uma especialização da `ICollectionOnSTLImpl` que implementa o `IWords` interface definida anteriormente e fornece um enumerador que ofereça suporte a `IEnumVARIANT`.

##  <a name="vcconedit_the_generated_code"></a> O código gerado pelo Assistente de edição

Agora você deve derivar `CWords` da implementação da interface representada pelo `CollectionType` typedef vez `IWords`, conforme mostrado abaixo:

[!code-cpp[NVC_ATL_COM#28](../atl/codesnippet/cpp/implementing-an-stl-based-collection_5.h)]

##  <a name="vcconpopulate_the_collection"></a> Adicionar código para preencher a coleção

A única coisa que resta é preencher o vetor com dados. Neste exemplo simples, você pode adicionar algumas palavras à coleção no construtor da classe:

[!code-cpp[NVC_ATL_COM#29](../atl/codesnippet/cpp/implementing-an-stl-based-collection_6.h)]

Agora, você pode testar o código com o cliente de sua escolha.

## <a name="see-also"></a>Consulte também

[Coleções e enumeradores](../atl/atl-collections-and-enumerators.md)<br/>
[Exemplo de ATLCollections](../visual-cpp-samples.md)<br/>
[Classes de política de cópia da ATL](../atl/atl-copy-policy-classes.md)

