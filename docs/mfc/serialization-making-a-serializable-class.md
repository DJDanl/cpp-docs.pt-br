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
ms.openlocfilehash: 5b8e52750f6f4589f90048e248305b2f0f5b4855
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36953068"
---
# <a name="serialization-making-a-serializable-class"></a>Serialização: criando uma classe serializável
Cinco etapas principais são necessárias para tornar uma classe serializável. Eles são listados abaixo e explicados nas seções a seguir:  
  
1.  [Derivando de sua classe de CObject](#_core_deriving_your_class_from_cobject) (ou de qualquer classe derivada de `CObject`).  
  
2.  [Substituindo a função de membro Serialize](#_core_overriding_the_serialize_member_function).  
  
3.  [Usando a macro DECLARE_SERIAL](#_core_using_the_declare_serial_macro) na declaração da classe.  
  
4.  [Definir um construtor que não aceita argumentos](#_core_defining_a_constructor_with_no_arguments).  
  
5.  [Usando a macro IMPLEMENT_SERIAL no arquivo de implementação](#_core_using_the_implement_serial_macro_in_the_implementation_file) para sua classe.  
  
 Se você chamar `Serialize` diretamente em vez de por meio de >> e << operadores de [CArchive](../mfc/reference/carchive-class.md), as três últimas etapas não são necessárias para a serialização.  
  
##  <a name="_core_deriving_your_class_from_cobject"></a> Derivando de sua classe de CObject  
 O protocolo de serialização básica e a funcionalidade são definidos no `CObject` classe. Derivando de sua classe de `CObject` (ou de uma classe derivada de `CObject`), conforme mostrado na seguinte declaração da classe `CPerson`, você ganha acesso para o protocolo de serialização e a funcionalidade de `CObject`.  
  
##  <a name="_core_overriding_the_serialize_member_function"></a> Substituindo a serializar a função de membro  
 O `Serialize` a função de membro, que é definida no `CObject` da classe, que é responsável pela serialização, na verdade, os dados necessários para capturar o estado atual do objeto. O `Serialize` função tem um `CArchive` argumento que ele usa para ler e gravar os dados do objeto. O [CArchive](../mfc/reference/carchive-class.md) objeto tem uma função de membro, `IsStoring`, que indica se `Serialize` é armazenar (gravar dados) ou carregar (leitura de dados). Usando os resultados de `IsStoring` como guia, você o inserir dados do objeto no `CArchive` objeto com o operador de inserção (**<\<**) ou extrair os dados com o operador de extração ( **>>**).  
  
 Considere uma classe que é derivada de `CObject` e tem duas novas variáveis membro, dos tipos de `CString` e **WORD**. O fragmento de declaração de classe a seguir mostra o novo membro variáveis e a declaração substituído `Serialize` função de membro:  
  
 [!code-cpp[NVC_MFCSerialization#1](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_1.h)]  
  
#### <a name="to-override-the-serialize-member-function"></a>Para substituir a função de membro de serialização  
  
1.  Chamar a versão da classe base do `Serialize` para certificar-se de que a parte herdada do objeto é serializada.  
  
2.  Inserir ou extrair as variáveis de membro específicas para sua classe.  
  
     Os operadores de inserção e extração interagem com a classe de arquivamento para ler e gravar os dados. O exemplo a seguir mostra como implementar `Serialize` para o `CPerson` classe declarada acima:  
  
     [!code-cpp[NVC_MFCSerialization#2](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_2.cpp)]  
  
 Você também pode usar o [CArchive::Read](../mfc/reference/carchive-class.md#read) e [CArchive::Write](../mfc/reference/carchive-class.md#write) funções de membro para ler e gravar grandes quantidades de dados não digitados.  
  
##  <a name="_core_using_the_declare_serial_macro"></a> Usando a Macro DECLARE_SERIAL  
 A macro DECLARE_SERIAL é necessária na declaração de classes que oferecem suporte a serialização, conforme mostrado aqui:  
  
 [!code-cpp[NVC_MFCSerialization#3](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_3.h)]  
  
##  <a name="_core_defining_a_constructor_with_no_arguments"></a> Definir um construtor sem argumentos  
 MFC requer um construtor padrão ao recriar os objetos como desserializado (carregado do disco). O processo de desserialização preencherá todas as variáveis de membro com os valores necessários para recriar o objeto.  
  
 Este construtor pode ser declarado pública, protegida ou privada. Se você fizer protegida ou privada, você certificar-se de que ele só será usado pelas funções de serialização. O construtor deve colocar o objeto em um estado que permita a ser excluído se necessário.  
  
> [!NOTE]
>  Se você se esquecer de definir um construtor sem argumentos em uma classe que usa as macros DECLARE_SERIAL e IMPLEMENT_SERIAL, você receberá um aviso do compilador "nenhum construtor padrão disponível" na linha em que a macro IMPLEMENT_SERIAL é usada.  
  
##  <a name="_core_using_the_implement_serial_macro_in_the_implementation_file"></a> Usando a Macro IMPLEMENT_SERIAL no arquivo de implementação  
 A macro IMPLEMENT_SERIAL é usada para definir as várias funções necessárias quando você derivar uma classe serializável de `CObject`. Use esta macro no arquivo de implementação (. CPP) para a sua classe. Os dois primeiros argumentos para a macro serão o nome da classe e o nome de sua classe base imediata.  
  
 O terceiro argumento para essa macro é um número de esquema. O número de esquema é essencialmente um número de versão para objetos da classe. Use um número inteiro maior ou igual a 0 para o número de esquema. (Não confunda esse número de esquema com a terminologia de banco de dados).  
  
 O código de serialização do MFC verifica o número de esquema durante a leitura de objetos na memória. Se o número de esquema do objeto no disco não coincide com o número de esquema de classe na memória, a biblioteca lançará um `CArchiveException`, impedindo que o programa leiam uma versão incorreta do objeto.  
  
 Se você quiser que seu `Serialize` a função de membro para ser capaz de ler várias versões — ou seja, os arquivos criados com versões diferentes do aplicativo — você pode usar o valor *VERSIONABLE_SCHEMA* como um argumento para o IMPLEMENT_SERIAL macro. Para obter informações de uso e um exemplo, consulte o `GetObjectSchema` função de membro de classe `CArchive`.  
  
 O exemplo a seguir mostra como usar IMPLEMENT_SERIAL para uma classe, `CPerson`, que é derivado de `CObject`:  
  
 [!code-cpp[NVC_MFCSerialization#4](../mfc/codesnippet/cpp/serialization-making-a-serializable-class_4.cpp)]  
  
 Uma vez que uma classe serializável, você pode serializar objetos da classe, conforme descrito no artigo [serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md).  
  
## <a name="see-also"></a>Consulte também  
 [Serialização](../mfc/serialization-in-mfc.md)

