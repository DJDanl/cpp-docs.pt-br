---
title: Usando o CArchive &lt; &lt; e os &gt; &gt; operadores
ms.date: 11/04/2016
helpviewer_keywords:
- objects [MFC], loading from previously stored values
- CArchive class [MFC], storing and loading objects
- CArchive class [MFC], operators
ms.assetid: 56aef326-02dc-4992-8282-f0a4b78a064e
ms.openlocfilehash: 5029227078ac0af9ebdd0c74522a7b0ae8ea4d42
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228512"
---
# <a name="using-the-carchive-ltlt-and-gtgt-operators"></a>Usando o CArchive &lt; &lt; e os &gt; &gt; operadores

`CArchive`fornece <\< and >> operadores para gravar e ler tipos de dados simples, bem como `CObject` s para e de um arquivo.

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

A biblioteca define os **<\<** and **>>** operadores para `CArchive` como o primeiro operando e os tipos de dados e tipos de classe a seguir como o segundo operando:

||||
|-|-|-|
|`CObject*`|**Tamanho** e`CSize`|**`float`**|
|**TEXTOS**|`CString`|**Ponto** e`CPoint`|
|`DWORD`|**MINUCIOSA**|`RECT` e `CRect`|
|**Double**|**Longas**|`CTime` e `CTimeSpan`|
|`Int`|**COleCurrency**|`COleVariant`|
|`COleDateTime`|`COleDateTimeSpan`||

> [!NOTE]
> O armazenamento e `CObject` o carregamento de s por meio de um arquivo requer uma consideração extra. Para obter mais informações, consulte [armazenar e carregar CObjects por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md).

Os operadores de **<\<** and **> > CArchive** sempre retornam uma referência ao `CArchive` objeto, que é o primeiro operando. Isso permite encadear os operadores, conforme ilustrado abaixo:

[!code-cpp[NVC_MFCSerialization#11](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_5.cpp)]

## <a name="see-also"></a>Confira também

[Serialização: Serializando um objeto](../mfc/serialization-serializing-an-object.md)
