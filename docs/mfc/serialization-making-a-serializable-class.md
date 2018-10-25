---
title: 'Serialização: Criando uma classe serializável | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2f3824e87a2016a848b3723aaa293f235f6f9b09
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50054859"
---
# <a name="serialization-making-a-serializable-class"></a>Serialização: criando uma classe serializável

Cinco etapas principais são necessárias para tornar uma classe serializável. Eles são listados abaixo e explicados nas seções a seguir:

1. [Derivando de sua classe de CObject](#_core_deriving_your_class_from_cobject) (ou de alguma classe derivada de `CObject`).

1. [Substituindo a função de membro Serialize](#_core_overriding_the_serialize_member_function).

1. [Usando a macro DECLARE_SERIAL](#_core_using_the_declare_serial_macro) na declaração da classe.

1. [Definindo um construtor que não usa argumentos](#_core_defining_a_constructor_with_no_arguments).

1. [Usando a macro IMPLEMENT_SERIAL no arquivo de implementação](#_core_using_the_implement_serial_macro_in_the_implementation_file) para sua classe.

Se você chamar `Serialize` diretamente em vez de por meio de >> e << operadores de [CArchive](../mfc/reference/carchive-class.md), as três últimas etapas não são necessárias para a serialização.

##  <a name="_core_deriving_your_class_from_cobject"></a> Derivando de sua classe de CObject

O protocolo de serialização básica e a funcionalidade são definidos na `CObject` classe. Derivando sua classe de `CObject` (ou de uma classe derivada de `CObject`), conforme mostrado na seguinte declaração de classe `CPerson`, você ganha acesso para o protocolo de serialização e a funcionalidade de `CObject`.

##  <a name="_core_overriding_the_serialize_member_function"></a> Substituindo a serializar a função de membro

O `Serialize` função de membro, que é definida no `CObject` de classe, é responsável pela serialização, na verdade, os dados necessários para capturar o estado atual de um objeto. O `Serialize` função tem um `CArchive` argumento que ele usa para ler e gravar os dados do objeto. O [CArchive](../mfc/reference/carchive-class.md) objeto tem uma função de membro `IsStoring`, que indica se `Serialize` é armazenar (gravação de dados) ou carregar (leitura de dados). Usando os resultados de `IsStoring` como guia, você o inserir seus dados de objeto na `CArchive` objeto com o operador de inserção (**<\<**) ou extrair os dados com o operador de extração ( **>>**).

Considere uma classe que deriva `CObject` e tem duas novas variáveis membro, dos tipos `CString` e **WORD**. O fragmento de declaração de classe a seguir mostra o novo membro variáveis e a declaração para substituído `Serialize` função de membro:

[!code-cpp[NVC_MFCSerialization#1](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_1.h)]

#### <a name="to-override-the-serialize-member-function"></a>Para substituir a função de membro Serialize

1. Chamar a sua versão da classe base do `Serialize` para certificar-se de que a parte herdada do objeto é serializada.

1. Inserir ou extrair as variáveis de membro específicas à sua classe.

   Os operadores de inserção e extração de interagem com a classe de arquivo morto para ler e gravar os dados. O exemplo a seguir mostra como implementar `Serialize` para o `CPerson` classe declarada acima:

   [!code-cpp[NVC_MFCSerialization#2](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_2.cpp)]

Você também pode usar o [CArchive::Read](../mfc/reference/carchive-class.md#read) e [CArchive::Write](../mfc/reference/carchive-class.md#write) funções de membro para ler e gravar grandes quantidades de dados não tipados.

##  <a name="_core_using_the_declare_serial_macro"></a> Usando a Macro DECLARE_SERIAL

A macro DECLARE_SERIAL é necessária na declaração de classes que oferecem suporte a serialização, conforme mostrado aqui:

[!code-cpp[NVC_MFCSerialization#3](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_3.h)]

##  <a name="_core_defining_a_constructor_with_no_arguments"></a> Definindo um construtor sem argumentos

MFC exige um construtor padrão, quando ela recria seus objetos conforme eles são desserializados (carregado do disco). O processo de desserialização preencherá todas as variáveis de membro com os valores necessários para recriar o objeto.

Esse construtor pode ser declarado pública, protegida ou privada. Se você fizer protegido ou particular, você ajuda Certifique-se de que ele só será usado pelas funções de serialização. O construtor deve colocar o objeto em um estado que permite que ele seja eliminado, se necessário.

> [!NOTE]
>  Se você esquecer de definir um construtor sem argumentos em uma classe que usa as macros DECLARE_SERIAL e IMPLEMENT_SERIAL, você receberá um aviso do compilador "nenhum construtor padrão disponíveis" na linha em que a macro IMPLEMENT_SERIAL é usada.

##  <a name="_core_using_the_implement_serial_macro_in_the_implementation_file"></a> Usando a Macro IMPLEMENT_SERIAL no arquivo de implementação

A macro IMPLEMENT_SERIAL é usada para definir as várias funções necessárias quando você derivar uma classe serializável de `CObject`. Usar essa macro no arquivo de implementação (. CPP) para a sua classe. Os dois primeiros argumentos para a macro serão o nome da classe e o nome da sua classe base imediata.

O terceiro argumento para essa macro é um número de esquema. O número de esquema é essencialmente um número de versão para objetos da classe. Use um número inteiro maior que ou igual a 0 para o número de esquema. (Não confunda esse número de esquema com a terminologia de banco de dados).

O código de serialização do MFC verifica o número de esquema durante a leitura de objetos na memória. Se o número de esquema do objeto no disco não corresponder ao número de esquema da classe na memória, a biblioteca lançará um `CArchiveException`, impedindo que o seu programa de leitura de uma versão incorreta do objeto.

Se você quiser que seu `Serialize` função de membro para ser capaz de ler várias versões — ou seja, os arquivos gravados com diferentes versões do aplicativo — você pode usar o valor *VERSIONABLE_SCHEMA* como um argumento para o IMPLEMENT_SERIAL macro. Para obter informações de uso e um exemplo, consulte o `GetObjectSchema` função de membro da classe `CArchive`.

O exemplo a seguir mostra como usar IMPLEMENT_SERIAL para uma classe `CPerson`, que é derivado de `CObject`:

[!code-cpp[NVC_MFCSerialization#4](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_4.cpp)]

Quando você tiver uma classe serializável, você pode serializar objetos da classe, conforme discutido no artigo [serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md).

## <a name="see-also"></a>Consulte também

[Serialização](../mfc/serialization-in-mfc.md)

