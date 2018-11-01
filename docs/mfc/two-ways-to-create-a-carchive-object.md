---
title: Duas maneiras de criar um objeto CArchive
ms.date: 11/04/2016
f1_keywords:
- CArchive
helpviewer_keywords:
- CArchive class [MFC], closing CArchive objects
- CArchive objects [MFC], closing
- I/O [MFC], creating CArchive objects
- serialization [MFC], CArchive class
- CArchive objects [MFC]
- storage [MFC], CArchive class [MFC]
- data storage [MFC], CArchive class
- CArchive class [MFC], constructor
ms.assetid: aefa28ce-b55c-40dc-9e42-5f038030985d
ms.openlocfilehash: a97223602e9994647a8af16cc68de5394494c1ca
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50659916"
---
# <a name="two-ways-to-create-a-carchive-object"></a>Duas maneiras de criar um objeto CArchive

Há duas maneiras de criar um `CArchive` objeto:

- [Criação implícita de um objeto CArchive por meio da estrutura](#_core_implicit_creation_of_a_carchive_object_via_the_framework)

- [Criação explícita de um objeto CArchive](#_core_explicit_creation_of_a_carchive_object)

##  <a name="_core_implicit_creation_of_a_carchive_object_via_the_framework"></a> Criação implícita de um objeto CArchive por meio da estrutura

A maneira mais comum e mais fácil, é permitir que a estrutura de criar um `CArchive` objeto do documento em nome de salvar, salvar como e Open comandos no menu arquivo.

Aqui está a estrutura que funciona quando o usuário do seu aplicativo emite o comando Salvar como no menu Arquivo:

1. Apresenta o **Salvar como** caixa de diálogo e obtém o nome do arquivo do usuário.

1. Abre o arquivo chamado pelo usuário como um `CFile` objeto.

1. Cria uma `CArchive` que aponta para esse objeto `CFile` objeto. Na criação de `CArchive` do objeto, a estrutura define o modo de "store" (gravar, serializar), em vez de "carga" (leitura, desserializar).

1. Chamadas a `Serialize` função definida em seu `CDocument`-derivado da classe, passando a ele uma referência para o `CArchive` objeto.

O documento `Serialize` função, em seguida, grava os dados para o `CArchive` objeto, conforme explicado em breve. Após o retorno de seu `Serialize` função, o framework destrói o `CArchive` objeto e, em seguida, o `CFile` objeto.

Portanto, se você permitir que a estrutura de criar o `CArchive` do objeto para o documento, tudo o que você precisa fazer é implementar o documento `Serialize` função que gravações e leituras de e para o arquivo morto. Você também precisará implementar `Serialize` para qualquer `CObject`-objetos derivados que o documento `Serialize` função serializa por sua vez direta ou indiretamente.

##  <a name="_core_explicit_creation_of_a_carchive_object"></a> Criação explícita de um objeto CArchive

Além de serializar um documento por meio da estrutura, existem outras ocasiões quando talvez seja necessário um `CArchive` objeto. Por exemplo, você talvez queira serializar os dados de e para a área de transferência, representado por um `CSharedFile` objeto. Ou, você talvez queira usar uma interface do usuário para salvar um arquivo que é diferente do oferecido pela estrutura. Nesse caso, você pode criar explicitamente um `CArchive` objeto. Você faz isso da mesma maneira que a estrutura faz, usando o procedimento a seguir.

#### <a name="to-explicitly-create-a-carchive-object"></a>Para criar explicitamente um objeto CArchive

1. Construir uma `CFile` objeto ou um objeto derivado de `CFile`.

1. Passe o `CFile` objeto para o construtor para `CArchive`, conforme mostrado no exemplo a seguir:

   [!code-cpp[NVC_MFCSerialization#5](../mfc/codesnippet/cpp/two-ways-to-create-a-carchive-object_1.cpp)]

   O segundo argumento para o `CArchive` construtor é um valor enumerado que especifica se o arquivo será usado para armazenar ou carregamento de dados para ou do arquivo. O `Serialize` função de um objeto verifica esse estado chamando o `IsStoring` função para o objeto de arquivo morto.

Quando tiver terminado de armazenar ou carregamento de dados de ou para o `CArchive` de objeto, fechá-lo. Embora o `CArchive` (e `CFile`) objetos fechará automaticamente o arquivo morto (e o arquivo), ele é uma boa prática fazer isso explicitamente, pois ele facilita a recuperação de erros. Para obter mais informações sobre o tratamento de erro, consulte o artigo [exceções: exceções de detectar e exclua](../mfc/exceptions-catching-and-deleting-exceptions.md).

#### <a name="to-close-the-carchive-object"></a>Para fechar o objeto CArchive

1. O exemplo a seguir ilustra como fechar o `CArchive` objeto:

   [!code-cpp[NVC_MFCSerialization#6](../mfc/codesnippet/cpp/two-ways-to-create-a-carchive-object_2.cpp)]

## <a name="see-also"></a>Consulte também

[Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)

