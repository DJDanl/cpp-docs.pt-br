---
title: 'Serialização: criando uma classe serializável'
ms.date: 11/04/2016
helpviewer_keywords:
- serializable class [MFC]
- DECLARE_SERIAL macro [MFC]
- default constructor [MFC]
- VERSIONABLE_SCHEMA macro [MFC]
- classes [MFC], derived
- IMPLEMENT_SERIAL macro [MFC]
- no-arguments constructor [MFC]
- Serialize method, overriding
- defaults [MFC], constructor
- CObject class [MFC], deriving serializable classes
- constructors [MFC], defining with no arguments
- serialization [MFC], serializable classes
- no default constructor
ms.assetid: 59a14d32-1cc8-4275-9829-99639beee27c
ms.openlocfilehash: 9648bd4f516a5f174534336b1ca3b42bb51ca0c4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372712"
---
# <a name="serialization-making-a-serializable-class"></a>Serialização: criando uma classe serializável

Cinco passos principais são necessários para tornar uma classe serializável. Eles estão listados abaixo e explicados nas seguintes seções:

1. [Derivando sua classe de CObject](#_core_deriving_your_class_from_cobject) (ou `CObject`de alguma classe derivada de ).

1. [Substituindo a função membro Serialize](#_core_overriding_the_serialize_member_function).

1. [Usando a DECLARE_SERIAL macro](#_core_using_the_declare_serial_macro) na declaração de classe.

1. [Definindo um construtor que não aceita argumentos.](#_core_defining_a_constructor_with_no_arguments)

1. [Usando a macro IMPLEMENT_SERIAL no arquivo de implementação](#_core_using_the_implement_serial_macro_in_the_implementation_file) da sua classe.

Se você `Serialize` ligar diretamente e não através dos operadores de >> e << do [CArchive,](../mfc/reference/carchive-class.md)as últimas três etapas não são necessárias para serialização.

## <a name="deriving-your-class-from-cobject"></a><a name="_core_deriving_your_class_from_cobject"></a>Derivando sua classe do CObject

O protocolo básico de serialização e `CObject` funcionalidade são definidos na classe. Ao derivar sua `CObject` classe de (ou `CObject`de uma classe derivada), `CPerson`como mostrado na seguinte declaração de `CObject`classe, você ganha acesso ao protocolo de serialização e funcionalidade de .

## <a name="overriding-the-serialize-member-function"></a><a name="_core_overriding_the_serialize_member_function"></a>Substituindo a função serialize membro

A `Serialize` função membro, definida `CObject` na classe, é responsável por realmente serializar os dados necessários para capturar o estado atual de um objeto. A `Serialize` função `CArchive` tem um argumento que usa para ler e gravar os dados do objeto. O objeto [CArchive](../mfc/reference/carchive-class.md) tem `IsStoring`uma função `Serialize` de membro, que indica se está armazenando (gravação de dados) ou carregando (dados de leitura). Usando os `IsStoring` resultados como guia, você insere os `CArchive` dados do seu**<** objeto no objeto com**>>** o operador de inserção ( ) ou extrai dados com o operador de extração ( ).

Considere uma classe derivada `CObject` e que tenha duas novas `CString` variáveis de membros, de tipos e **WORD**. O fragmento da declaração de classe a seguir mostra `Serialize` as novas variáveis de membros e a declaração para a função de membro substituído:

[!code-cpp[NVC_MFCSerialization#1](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_1.h)]

#### <a name="to-override-the-serialize-member-function"></a>Para substituir a função membro Serialize

1. Ligue para a `Serialize` versão da classe base para garantir que a parte herdada do objeto seja serializada.

1. Insira ou extraia as variáveis de membro específicas da sua classe.

   Os operadores de inserção e extração interagem com a classe de arquivamento para ler e escrever os dados. O exemplo a seguir `Serialize` mostra `CPerson` como implementar para a classe declarada acima:

   [!code-cpp[NVC_MFCSerialization#2](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_2.cpp)]

Você também pode usar o [CArchive::Read](../mfc/reference/carchive-class.md#read) e [CArchive::Write](../mfc/reference/carchive-class.md#write) funções de membro para ler e gravar grandes quantidades de dados não digitados.

## <a name="using-the-declare_serial-macro"></a><a name="_core_using_the_declare_serial_macro"></a>Usando a DECLARE_SERIAL Macro

A DECLARE_SERIAL macro é exigida na declaração de classes que suportarão a serialização, conforme mostrado aqui:

[!code-cpp[NVC_MFCSerialization#3](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_3.h)]

## <a name="defining-a-constructor-with-no-arguments"></a><a name="_core_defining_a_constructor_with_no_arguments"></a>Definindo um Construtor sem argumentos

O MFC requer um construtor padrão quando recria seus objetos à medida que eles são desserializados (carregados do disco). O processo de desserialização preencherá todas as variáveis de membros com os valores necessários para recriar o objeto.

Este construtor pode ser declarado público, protegido ou privado. Se você torná-lo protegido ou privado, você ajuda a garantir que ele só será usado pelas funções de serialização. O construtor deve colocar o objeto em um estado que permita que ele seja excluído, se necessário.

> [!NOTE]
> Se você esquecer de definir um construtor sem argumentos em uma classe que usa as macros DECLARE_SERIAL e IMPLEMENT_SERIAL, você receberá um aviso de compilador "sem construtor padrão disponível" na linha onde a macro IMPLEMENT_SERIAL é usada.

## <a name="using-the-implement_serial-macro-in-the-implementation-file"></a><a name="_core_using_the_implement_serial_macro_in_the_implementation_file"></a>Usando o IMPLEMENT_SERIAL Macro no Arquivo de Implementação

A IMPLEMENT_SERIAL macro é usada para definir as várias funções necessárias quando você deriva uma classe serializável de `CObject`. Você usa esta macro no arquivo de implementação (. CPP) para sua classe. Os dois primeiros argumentos para a macro são o nome da classe e o nome de sua classe de base imediata.

O terceiro argumento para esta macro é um número de esquema. O número do esquema é essencialmente um número de versão para objetos da classe. Use um inteiro maior ou igual a 0 para o número do esquema. (Não confunda esse número de esquema com a terminologia do banco de dados.)

O código de serialização do MFC verifica o número do esquema ao ler objetos na memória. Se o número do esquema do objeto no disco não corresponder ao número de esquema `CArchiveException`da classe na memória, a biblioteca lançará um , impedindo que seu programa leia uma versão incorreta do objeto.

Se você `Serialize` quiser que sua função de membro seja capaz de ler várias versões — ou seja, arquivos gravados com diferentes versões do aplicativo — você pode usar o valor *VERSIONABLE_SCHEMA* como um argumento para a macro IMPLEMENT_SERIAL. Para obter informações de uso `GetObjectSchema` e um `CArchive`exemplo, consulte a função membro da classe .

O exemplo a seguir mostra como `CPerson`usar IMPLEMENT_SERIAL para `CObject`uma classe, que é derivado de :

[!code-cpp[NVC_MFCSerialization#4](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_4.cpp)]

Uma vez que você tenha uma classe serializável, você pode serializar objetos da classe, conforme discutido no artigo [Serialização: Serializing a Object](../mfc/serialization-serializing-an-object.md).

## <a name="see-also"></a>Confira também

[Serialização](../mfc/serialization-in-mfc.md)
