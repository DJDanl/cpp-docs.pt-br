---
title: Usando o CArchive &lt; &lt; e os &gt; &gt; operadores
ms.date: 11/04/2016
helpviewer_keywords:
- objects [MFC], loading from previously stored values
- CArchive class [MFC], storing and loading objects
- CArchive class [MFC], operators
ms.assetid: 56aef326-02dc-4992-8282-f0a4b78a064e
ms.openlocfilehash: 0351cd0fad1d0fc838c75d3cdbd809a04b0fb393
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832289"
---
# <a name="using-the-carchive-ltlt-and-gtgt-operators"></a>Usando o CArchive &lt; &lt; e os &gt; &gt; operadores

`CArchive` fornece <\< and >> operadores para gravar e ler tipos de dados simples, bem como `CObject` s para e de um arquivo.

#### <a name="to-store-an-object-in-a-file-via-an-archive"></a>Para armazenar um objeto em um arquivo por meio de um arquivamento

1. O exemplo a seguir mostra como armazenar um objeto em um arquivo usando um arquivo morto:

   [!code-cpp[NVC_MFCSerialization#7](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_1.cpp)]

#### <a name="to-load-an-object-from-a-value-previously-stored-in-a-file"></a>Para carregar um objeto de um valor armazenado anteriormente em um arquivo

1. O exemplo a seguir mostra como carregar um objeto de um valor armazenado anteriormente em um arquivo:

   [!code-cpp[NVC_MFCSerialization#8](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_2.cpp)]

Normalmente, você armazena e carrega dados de e para um arquivo por meio de um arquivamento nas `Serialize` funções de `CObject` classes derivadas, que você deve ter declarado com a macro DECLARE_SERIALIZE. Uma referência a um `CArchive` objeto é passada para sua `Serialize` função. Você chama a `IsLoading` função do `CArchive` objeto para determinar se a `Serialize` função foi chamada para carregar dados do arquivo ou armazenar dados no arquivo.

A `Serialize` função de uma `CObject` classe derivada de Serializable normalmente tem o seguinte formato:

[!code-cpp[NVC_MFCSerialization#9](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_3.cpp)]

O modelo de código acima é exatamente o mesmo que o AppWizard cria para a `Serialize` função do documento (uma classe derivada de `CDocument` ). Esse modelo de código ajuda a escrever código que é mais fácil de examinar, pois o código de armazenamento e o código de carregamento devem ser sempre paralelos, como no exemplo a seguir:

[!code-cpp[NVC_MFCSerialization#10](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_4.cpp)]

A biblioteca define **`<<`** os **`>>`** operadores e para `CArchive` como o primeiro operando e os tipos de dados e tipos de classe a seguir como o segundo operando:

:::row:::
   :::column span="":::
      `BYTE`\
      `CObject*`\
      `COleCurrency`\
      `COleDateTime`\
      `COleDateTimeSpan`
   :::column-end:::
   :::column span="":::
      `COleVariant`\
      `CString`\
      `CTime` e `CTimeSpan`\
      `Double`
   :::column-end:::
   :::column span="":::
      `DWORD`\
      `Float`\
      `Int`\
      `LONG`
   :::column-end:::
   :::column span="":::
      `POINT` e `CPoint`\
      `RECT` e `CRect`\
      `SIZE` e `CSize`\
      `WORD`
   :::column-end:::
:::row-end:::

> [!NOTE]
> O armazenamento e `CObject` o carregamento de s por meio de um arquivo requer uma consideração extra. Para obter mais informações, consulte [armazenar e carregar CObjects por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md).

Os `CArchive` **`<<`** **`>>`** operadores e sempre retornam uma referência ao `CArchive` objeto, que é o primeiro operando. Isso permite encadear os operadores, conforme ilustrado abaixo:

[!code-cpp[NVC_MFCSerialization#11](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_5.cpp)]

## <a name="see-also"></a>Confira também

[Serialização: Serializando um objeto](../mfc/serialization-serializing-an-object.md)
