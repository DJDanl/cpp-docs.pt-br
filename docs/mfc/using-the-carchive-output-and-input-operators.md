---
title: Usando os operadores CArchive &lt;&lt; e &gt;&gt;
ms.date: 11/04/2016
helpviewer_keywords:
- objects [MFC], loading from previously stored values
- CArchive class [MFC], storing and loading objects
- CArchive class [MFC], operators
ms.assetid: 56aef326-02dc-4992-8282-f0a4b78a064e
ms.openlocfilehash: 8e175f35f2218341c69571c818711596180df4a6
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79442179"
---
# <a name="using-the-carchive-ltlt-and-gtgt-operators"></a>Usando os operadores CArchive &lt;&lt; e &gt;&gt;

o `CArchive` fornece <\< e > operadores de > para gravar e ler tipos de dados simples, bem como `CObject`s de e para um arquivo.

#### <a name="to-store-an-object-in-a-file-via-an-archive"></a>Para armazenar um objeto em um arquivo por meio de um arquivamento

1. O exemplo a seguir mostra como armazenar um objeto em um arquivo usando um arquivo morto:

   [!code-cpp[NVC_MFCSerialization#7](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_1.cpp)]

#### <a name="to-load-an-object-from-a-value-previously-stored-in-a-file"></a>Para carregar um objeto de um valor armazenado anteriormente em um arquivo

1. O exemplo a seguir mostra como carregar um objeto de um valor armazenado anteriormente em um arquivo:

   [!code-cpp[NVC_MFCSerialization#8](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_2.cpp)]

Normalmente, você armazena e carrega dados de e para um arquivo por meio de um arquivamento nas funções `Serialize` de classes derivadas de `CObject`, que você deve ter declarado com a macro DECLARE_SERIALIZE. Uma referência a um objeto `CArchive` é passada para sua função `Serialize`. Você chama a função `IsLoading` do objeto `CArchive` para determinar se a função `Serialize` foi chamada para carregar dados do arquivo ou armazenar dados no arquivo.

A função `Serialize` de uma classe derivada de `CObject`serializável normalmente tem o seguinte formato:

[!code-cpp[NVC_MFCSerialization#9](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_3.cpp)]

O modelo de código acima é exatamente o mesmo que o AppWizard cria para a função `Serialize` do documento (uma classe derivada de `CDocument`). Esse modelo de código ajuda a escrever código que é mais fácil de examinar, pois o código de armazenamento e o código de carregamento devem ser sempre paralelos, como no exemplo a seguir:

[!code-cpp[NVC_MFCSerialization#10](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_4.cpp)]

A biblioteca define **<\<** e **>>** operadores para `CArchive` como o primeiro operando e os tipos de dados e tipos de classe a seguir como o segundo operando:

||||
|-|-|-|
|`CObject*`|**Tamanho** e `CSize`|**float**|
|**WORD**|`CString`|**Apontar** e `CPoint`|
|`DWORD`|**BYTE**|`RECT` e `CRect`|
|**Duplo**|**LONG**|`CTime` e `CTimeSpan`|
|`Int`|**COleCurrency**|`COleVariant`|
|`COleDateTime`|`COleDateTimeSpan`||

> [!NOTE]
>  O armazenamento e o carregamento `CObject`s por meio de um arquivo requer uma consideração extra. Para obter mais informações, consulte [armazenar e carregar CObjects por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md).

O **CArchive <\<** e os operadores de **>>** sempre retornam uma referência ao objeto `CArchive`, que é o primeiro operando. Isso permite encadear os operadores, conforme ilustrado abaixo:

[!code-cpp[NVC_MFCSerialization#11](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_5.cpp)]

## <a name="see-also"></a>Consulte também

[Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)
