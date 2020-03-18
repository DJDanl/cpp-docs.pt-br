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
ms.openlocfilehash: 38642906b0973730149ed0de5381519f06d69fe5
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79442031"
---
# <a name="two-ways-to-create-a-carchive-object"></a>Duas maneiras de criar um objeto CArchive

Há duas maneiras de criar um objeto de `CArchive`:

- [Criação implícita de um objeto CArchive por meio da estrutura](#_core_implicit_creation_of_a_carchive_object_via_the_framework)

- [Criação explícita de um objeto CArchive](#_core_explicit_creation_of_a_carchive_object)

##  <a name="_core_implicit_creation_of_a_carchive_object_via_the_framework"></a>Criação implícita de um objeto CArchive por meio da estrutura

A maneira mais comum e fácil é permitir que a estrutura crie um objeto `CArchive` para o seu documento em nome dos comandos salvar, salvar como e abrir no menu arquivo.

Aqui está o que a estrutura faz quando o usuário do seu aplicativo emite o comando Salvar como no menu arquivo:

1. Apresenta a caixa de diálogo **salvar como** e Obtém o nome de arquivo do usuário.

1. Abre o arquivo nomeado pelo usuário como um objeto `CFile`.

1. Cria um objeto `CArchive` que aponta para esse objeto `CFile`. Ao criar o objeto `CArchive`, a estrutura define o modo como "Store" (Write, Serialize), em oposição a "Load" (Read, desserializate).

1. Chama a função `Serialize` definida em sua classe derivada de `CDocument`, passando uma referência para o objeto `CArchive`.

A função de `Serialize` do seu documento grava dados no objeto `CArchive`, conforme explicado em breve. Após o retorno de sua função `Serialize`, a estrutura destrói o objeto `CArchive` e, em seguida, o objeto `CFile`.

Portanto, se você permitir que a estrutura crie o objeto `CArchive` para seu documento, tudo o que você precisa fazer é implementar a função `Serialize` do documento que grava e lê de e para o arquivo morto. Você também precisa implementar `Serialize` para qualquer objeto derivado de `CObject`que a função de `Serialize` do documento, por sua vez, serializa direta ou indiretamente.

##  <a name="_core_explicit_creation_of_a_carchive_object"></a>Criação explícita de um objeto CArchive

Além de serializar um documento por meio da estrutura, há outras ocasiões em que você pode precisar de um objeto `CArchive`. Por exemplo, você pode desejar serializar dados de e para a área de transferência, representados por um objeto `CSharedFile`. Ou, talvez você queira usar uma interface do usuário para salvar um arquivo diferente daquele oferecido pela estrutura. Nesse caso, você pode criar explicitamente um objeto `CArchive`. Você faz isso da mesma forma que a estrutura, usando o procedimento a seguir.

#### <a name="to-explicitly-create-a-carchive-object"></a>Para criar explicitamente um objeto CArchive

1. Construa um objeto `CFile` ou um objeto derivado de `CFile`.

1. Passe o objeto `CFile` para o construtor para `CArchive`, conforme mostrado no exemplo a seguir:

   [!code-cpp[NVC_MFCSerialization#5](../mfc/codesnippet/cpp/two-ways-to-create-a-carchive-object_1.cpp)]

   O segundo argumento para o construtor de `CArchive` é um valor enumerado que especifica se o arquivo será usado para armazenar ou carregar dados de ou para o arquivo. A função `Serialize` de um objeto verifica esse estado chamando a função `IsStoring` para o objeto de arquivo morto.

Quando terminar de armazenar ou carregar dados de ou para o objeto `CArchive`, feche-o. Embora os objetos `CArchive` (e `CFile`) fechem automaticamente o arquivo (e o arquivo), é recomendável fazer isso explicitamente, pois torna a recuperação de erros mais fácil. Para obter mais informações sobre o tratamento de erros, consulte o artigo [exceções: capturando e excluindo exceções](../mfc/exceptions-catching-and-deleting-exceptions.md).

#### <a name="to-close-the-carchive-object"></a>Para fechar o objeto CArchive

1. O exemplo a seguir ilustra como fechar o objeto `CArchive`:

   [!code-cpp[NVC_MFCSerialization#6](../mfc/codesnippet/cpp/two-ways-to-create-a-carchive-object_2.cpp)]

## <a name="see-also"></a>Consulte também

[Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)
