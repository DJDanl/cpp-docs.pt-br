---
title: Usando o &lt; &lt; CArchive e &gt; &gt; operadores
ms.date: 11/04/2016
helpviewer_keywords:
- objects [MFC], loading from previously stored values
- CArchive class [MFC], storing and loading objects
- CArchive class [MFC], operators
ms.assetid: 56aef326-02dc-4992-8282-f0a4b78a064e
ms.openlocfilehash: 91ea565867cc0cb3b27ad9d5597037b637cb6544
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368968"
---
# <a name="using-the-carchive-ltlt-and-gtgt-operators"></a>Usando o &lt; &lt; CArchive e &gt; &gt; operadores

`CArchive`fornece \< <e >> operadores para escrever e `CObject`ler tipos de dados simples, bem como s para e a partir de um arquivo.

#### <a name="to-store-an-object-in-a-file-via-an-archive"></a>Para armazenar um objeto em um arquivo através de um arquivo

1. O exemplo a seguir mostra como armazenar um objeto em um arquivo através de um arquivo:

   [!code-cpp[NVC_MFCSerialization#7](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_1.cpp)]

#### <a name="to-load-an-object-from-a-value-previously-stored-in-a-file"></a>Para carregar um objeto de um valor armazenado anteriormente em um arquivo

1. O exemplo a seguir mostra como carregar um objeto de um valor armazenado anteriormente em um arquivo:

   [!code-cpp[NVC_MFCSerialization#8](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_2.cpp)]

Normalmente, você armazena e carrega dados de e `Serialize` para `CObject`um arquivo através de um arquivo nas funções de classes derivadas, que você deve ter declarado com a DECLARE_SERIALIZE macro. Uma referência `CArchive` a um objeto `Serialize` é passada para sua função. Você chama `IsLoading` a `CArchive` função do objeto `Serialize` para determinar se a função foi chamada para carregar dados do arquivo ou armazenar dados para o arquivo.

A `Serialize` função de `CObject`uma classe serializável derivada normalmente tem a seguinte forma:

[!code-cpp[NVC_MFCSerialization#9](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_3.cpp)]

O modelo de código acima é exatamente o `Serialize` mesmo que o AppWizard cria `CDocument`para a função do documento (uma classe derivada ). Este modelo de código ajuda você a escrever códigos mais fáceis de revisar, porque o código de armazenamento e o código de carregamento devem ser sempre paralelos, como no exemplo a seguir:

[!code-cpp[NVC_MFCSerialization#10](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_4.cpp)]

A biblioteca ** < ** define **>>** e `CArchive` os operadores para como o primeiro operato e os seguintes tipos de dados e tipos de classe como o segundo operand:

||||
|-|-|-|
|`CObject*`|**TAMANHO** e`CSize`|**float**|
|**Palavra**|`CString`|**PONTO** e`CPoint`|
|`DWORD`|**Byte**|`RECT` e `CRect`|
|**Double**|**Longas**|`CTime` e `CTimeSpan`|
|`Int`|**Colecurrency**|`COleVariant`|
|`COleDateTime`|`COleDateTimeSpan`||

> [!NOTE]
> Armazenar e carregar `CObject`s através de um arquivo requer uma consideração extra. Para obter mais informações, consulte [Armazenar e carregar CObjects através de um Arquivo](../mfc/storing-and-loading-cobjects-via-an-archive.md).

O **CArchive \< ** **>>** <e os operadores `CArchive` sempre retornam uma referência ao objeto, que é o primeiro orperand. Isso permite que você acorrente os operadores, conforme ilustrado abaixo:

[!code-cpp[NVC_MFCSerialization#11](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_5.cpp)]

## <a name="see-also"></a>Confira também

[Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)
