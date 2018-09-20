---
title: Usando o CArchive &lt; &lt; e &gt; &gt; operadores | Microsoft Docs
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
- objects [MFC], loading from previously stored values
- CArchive class [MFC], storing and loading objects
- CArchive class [MFC], operators
ms.assetid: 56aef326-02dc-4992-8282-f0a4b78a064e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 49ea94258c163c241243934f41d55d896d0d1fa2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46372451"
---
# <a name="using-the-carchive-ltlt-and-gtgt-operators"></a>Usando o CArchive &lt; &lt; e &gt; &gt; operadores

`CArchive` Fornece <\< e >> operadores para gravar e ler os tipos de dados simples, bem como `CObject`s para e de um arquivo.

#### <a name="to-store-an-object-in-a-file-via-an-archive"></a>Para armazenar um objeto em um arquivo por meio de um arquivo morto

1. O exemplo a seguir mostra como armazenar um objeto em um arquivo por meio de um arquivo morto:

     [!code-cpp[NVC_MFCSerialization#7](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_1.cpp)]

#### <a name="to-load-an-object-from-a-value-previously-stored-in-a-file"></a>Carregar um objeto de um valor anteriormente armazenado em um arquivo

1. O exemplo a seguir mostra como carregar um objeto de um valor anteriormente armazenado em um arquivo:

     [!code-cpp[NVC_MFCSerialization#8](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_2.cpp)]

Normalmente, você pode armazenar e carregar dados para e de um arquivo por meio de um arquivo morto na `Serialize` funções de `CObject`-classes derivadas, que você deve ter declarado com a macro DECLARE_SERIALIZE. Uma referência a um `CArchive` objeto é passado para sua `Serialize` função. Você chama o `IsLoading` função do `CArchive` objeto para determinar se o `Serialize` a função foi chamada para carregar dados do arquivo ou armazenar dados no arquivo.

O `Serialize` função de um serializável `CObject`-classe derivada normalmente tem a seguinte forma:

[!code-cpp[NVC_MFCSerialization#9](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_3.cpp)]

O modelo de código acima é exatamente o mesmo que um AppWizard cria para o `Serialize` função do documento (uma classe derivada de `CDocument`). Esse modelo de código ajuda você a escrever código que é mais fácil de examinar, porque o código de armazenamento e o código de carregamento devem sempre ser paralelos, como no exemplo a seguir:

[!code-cpp[NVC_MFCSerialization#10](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_4.cpp)]

A biblioteca define **< \<** e **>>** operadores para `CArchive` como o primeiro operando e os seguintes tipos de dados e tipos de classe como o segundo operando :

||||
|-|-|-|
|`CObject*`|**TAMANHO** e `CSize`|**float**|
|**WORD**|`CString`|**PONTO** e `CPoint`|
|`DWORD`|**BYTE**|`RECT` e `CRect`|
|**Duplo**|**LONG**|`CTime` e `CTimeSpan`|
|`Int`|**COleCurrency**|`COleVariant`|
|`COleDateTime`|`COleDateTimeSpan`||

> [!NOTE]
>  Armazenando e carregando `CObject`s por meio de um arquivo morto exige uma consideração extra. Para obter mais informações, consulte [armazenando e carregando CObjects por meio de um arquivo morto](../mfc/storing-and-loading-cobjects-via-an-archive.md).

O **CArchive <\<**  e **>>** operadores sempre retornam uma referência para o `CArchive` objeto, que é o primeiro operando. Isso permite encadear os operadores, conforme ilustrado abaixo:

[!code-cpp[NVC_MFCSerialization#11](../mfc/codesnippet/cpp/using-the-carchive-output-and-input-operators_5.cpp)]

## <a name="see-also"></a>Consulte também

[Serialização: serializando um objeto](../mfc/serialization-serializing-an-object.md)

