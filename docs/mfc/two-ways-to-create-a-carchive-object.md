---
title: Duas maneiras de criar um objeto CArchive | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CArchive
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cba1596e1dd114dcd46610b824405740a783c21e
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36954787"
---
# <a name="two-ways-to-create-a-carchive-object"></a>Duas maneiras de criar um objeto CArchive
Há duas maneiras de criar um `CArchive` objeto:  
  
-   [Criação implícita de um objeto CArchive por meio da estrutura](#_core_implicit_creation_of_a_carchive_object_via_the_framework)  
  
-   [Criação explícita de um objeto CArchive](#_core_explicit_creation_of_a_carchive_object)  
  
##  <a name="_core_implicit_creation_of_a_carchive_object_via_the_framework"></a> Criação implícita de um objeto CArchive por meio da estrutura  
 É a maneira mais comum e mais fácil permitir que a estrutura de criar um `CArchive` objeto para o documento em nome de salvar, salvar como e abrir comandos no menu arquivo.  
  
 Aqui está o que faz o framework quando o usuário do seu aplicativo emite o comando Salvar como no menu Arquivo:  
  
1.  Apresenta o **Salvar como** caixa de diálogo e obtém o nome do arquivo do usuário.  
  
2.  Abre o arquivo chamado pelo usuário como um `CFile` objeto.  
  
3.  Cria um `CArchive` que aponta para esse objeto `CFile` objeto. Criar o `CArchive` do objeto, a estrutura define o modo como "armazenar" (gravação, serializar), em vez de "carga" (leitura, desserializar).  
  
4.  Chamadas de `Serialize` função definida no seu `CDocument`-derivado da classe, passando uma referência para o `CArchive` objeto.  
  
 O documento `Serialize` função, em seguida, grava os dados para o `CArchive` do objeto, conforme explicado em breve. Após o retorno de seu `Serialize` função, o framework destrói o `CArchive` objeto e, em seguida, o `CFile` objeto.  
  
 Portanto, se você permitir que a estrutura de criar o `CArchive` do objeto para o documento, você precisa fazer é implementar o documento `Serialize` função gravações e leituras de e para o arquivo morto. Você também precisa implementar `Serialize` para qualquer `CObject`-objetos derivados que o documento `Serialize` função sucessivamente serializa direta ou indiretamente.  
  
##  <a name="_core_explicit_creation_of_a_carchive_object"></a> Criação explícita de um objeto CArchive  
 Além de serialização de um documento por meio da estrutura, há outras ocasiões, é necessário um `CArchive` objeto. Por exemplo, você talvez queira serializar dados para e da área de transferência, representado por um `CSharedFile` objeto. Ou, você talvez queira usar uma interface do usuário para salvar um arquivo que é diferente da oferecida pela estrutura. Nesse caso, você pode criar explicitamente uma `CArchive` objeto. Você fazer isso da mesma maneira que faz a estrutura, usando o procedimento a seguir.  
  
#### <a name="to-explicitly-create-a-carchive-object"></a>Para criar explicitamente um objeto CArchive  
  
1.  Construir um `CFile` objeto ou um objeto derivado de `CFile`.  
  
2.  Passar o `CFile` objeto para o construtor para `CArchive`, conforme mostrado no exemplo a seguir:  
  
     [!code-cpp[NVC_MFCSerialization#5](../mfc/codesnippet/cpp/two-ways-to-create-a-carchive-object_1.cpp)]  
  
     O segundo argumento para o `CArchive` construtor é um valor enumerado que especifica se o arquivo será usado para armazenar ou carregar dados para ou do arquivo. O `Serialize` verificações de função de um objeto nesse estado chamando o `IsStoring` função para o objeto de arquivo morto.  
  
 Quando tiver terminado de armazenamento ou carregamento de dados de ou para o `CArchive` de objeto, feche-o. Embora o `CArchive` (e `CFile`) objetos automaticamente fechará o arquivo morto (e o arquivo), é uma boa prática fazer isso explicitamente desde que facilita a recuperação de erros. Para obter mais informações sobre tratamento de erros, consulte o artigo [exceções: exceções de detectar e excluindo](../mfc/exceptions-catching-and-deleting-exceptions.md).  
  
#### <a name="to-close-the-carchive-object"></a>Para fechar o objeto CArchive  
  
1.  O exemplo a seguir ilustra como fechar o `CArchive` objeto:  
  
     [!code-cpp[NVC_MFCSerialization#6](../mfc/codesnippet/cpp/two-ways-to-create-a-carchive-object_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)

