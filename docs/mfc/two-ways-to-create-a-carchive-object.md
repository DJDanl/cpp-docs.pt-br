---
title: Duas maneiras de criar um objeto CArchive
ms.date: 11/04/2016
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
ms.openlocfilehash: 71592584d4ecdd3169ad894861a97fa668c04ee8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370953"
---
# <a name="two-ways-to-create-a-carchive-object"></a>Duas maneiras de criar um objeto CArchive

Há duas maneiras `CArchive` de criar um objeto:

- [Criação implícita de um objeto CArchive através da estrutura](#_core_implicit_creation_of_a_carchive_object_via_the_framework)

- [Criação explícita de um objeto CArchive](#_core_explicit_creation_of_a_carchive_object)

## <a name="implicit-creation-of-a-carchive-object-via-the-framework"></a><a name="_core_implicit_creation_of_a_carchive_object_via_the_framework"></a>Criação implícita de um objeto CArchive através da Estrutura

A maneira mais comum e fácil é deixar `CArchive` que a estrutura crie um objeto para o seu documento em nome dos comandos Salvar, Salvar Como e Abrir no menu Arquivo.

Aqui está o que a estrutura faz quando o usuário do seu aplicativo emite o comando Salvar como no menu Arquivo:

1. Apresenta a caixa de diálogo **Salvar como** e obtém o nome do arquivo do usuário.

1. Abre o arquivo nomeado pelo `CFile` usuário como um objeto.

1. Cria `CArchive` um objeto que `CFile` aponta para este objeto. Ao criar `CArchive` o objeto, a estrutura define o modo como "armazenar" (gravar, serializar), em vez de "carregar" (ler, desserializar).

1. Chama `Serialize` a função `CDocument`definida em sua classe derivada, `CArchive` passando-a uma referência ao objeto.

A função `Serialize` do documento então `CArchive` grava dados para o objeto, conforme explicado em breve. Ao retornar `Serialize` de sua função, `CArchive` a estrutura `CFile` destrói o objeto e, em seguida, o objeto.

Assim, se você deixar `CArchive` a estrutura criar o objeto para o seu `Serialize` documento, tudo o que você precisa fazer é implementar a função do documento que grava e lê de e para o arquivo. Você também tem `Serialize` que `CObject`implementar para quaisquer objetos `Serialize` derivados que a função do documento, por sua vez, serializa direta ou indiretamente.

## <a name="explicit-creation-of-a-carchive-object"></a><a name="_core_explicit_creation_of_a_carchive_object"></a>Criação explícita de um objeto CArchive

Além de serializar um documento através da estrutura, há `CArchive` outras ocasiões em que você pode precisar de um objeto. Por exemplo, você pode querer serializar dados de e `CSharedFile` para a Área de Transferência, representado por um objeto. Ou, você pode querer usar uma interface de usuário para salvar um arquivo que é diferente do oferecido pela estrutura. Neste caso, você pode criar `CArchive` explicitamente um objeto. Você faz isso da mesma maneira que a estrutura faz, usando o seguinte procedimento.

#### <a name="to-explicitly-create-a-carchive-object"></a>Para criar explicitamente um objeto CArchive

1. Construa `CFile` um objeto ou `CFile`um objeto derivado de .

1. Passe `CFile` o objeto para `CArchive`o construtor para , como mostrado no exemplo a seguir:

   [!code-cpp[NVC_MFCSerialization#5](../mfc/codesnippet/cpp/two-ways-to-create-a-carchive-object_1.cpp)]

   O segundo argumento `CArchive` para o construtor é um valor enumerado que especifica se o arquivo será usado para armazenar ou carregar dados para ou a partir do arquivo. A `Serialize` função de um objeto verifica `IsStoring` este estado chamando a função para o objeto de arquivamento.

Quando terminar de armazenar ou carregar dados `CArchive` para ou do objeto, feche-o. Embora `CArchive` os `CFile`objetos (e ) fechem automaticamente o arquivo (e o arquivo), é uma boa prática fazê-lo explicitamente, pois facilita a recuperação de erros. Para obter mais informações sobre o tratamento de erros, consulte o artigo [Exceções: Captura e Exclusão exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).

#### <a name="to-close-the-carchive-object"></a>Para fechar o objeto CArchive

1. O exemplo a seguir ilustra `CArchive` como fechar o objeto:

   [!code-cpp[NVC_MFCSerialization#6](../mfc/codesnippet/cpp/two-ways-to-create-a-carchive-object_2.cpp)]

## <a name="see-also"></a>Confira também

[Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)
