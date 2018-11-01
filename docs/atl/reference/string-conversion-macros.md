---
title: Macros de conversão de cadeia de caracteres
ms.date: 11/04/2016
f1_keywords:
- atlconv/ATL::DEVMODEA2W
- atlconv/ATL::TEXTMETRICA2W
- atlconv/ATL::DEVMODEOLE2T
- atlconv/ATL::TEXTMETRICOLE2T
- atlconv/ATL::DEVMODET2OLE
- atlconv/ATL::TEXTMETRICT2OLE
- atlconv/ATL::DEVMODEW2A
- atlconv/ATL::TEXTMETRICW2A
ms.assetid: 2ff7c0b6-2bde-45fe-897f-6128e18e0c27
ms.openlocfilehash: 1cad89fe065c0827169a22cc9699b677323d8594
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50544515"
---
# <a name="string-conversion-macros"></a>Macros de conversão de cadeia de caracteres

Essas macros fornecem recursos de conversão de cadeia de caracteres.

##  <a name="atl_and_mfc_string_conversion_macros"></a>  ATL e Macros de conversão de cadeia de caracteres MFC

As macros de conversão de cadeia de caracteres discutidas neste documento são válidas para ATL e MFC. Para obter mais informações sobre conversão de cadeia de caracteres MFC, consulte [TN059: usando Macros de conversão de MBCS/Unicode MFC](../../mfc/tn059-using-mfc-mbcs-unicode-conversion-macros.md) e [Macros e globais MFC](../../mfc/reference/mfc-macros-and-globals.md).

##  <a name="devmode_and_textmetric_string_conversion_macros"></a>  Macros de conversão de cadeia de caracteres TEXTMETRIC e DEVMODE

Essas macros de criar uma cópia de um [DEVMODE](/windows/desktop/api/wingdi/ns-wingdi-_devicemodea) ou [TEXTMETRIC](/windows/desktop/api/wingdi/ns-wingdi-tagtextmetrica) estruturar e converter as cadeias de caracteres dentro da nova estrutura para um novo tipo de cadeia de caracteres. As macros de alocar memória na pilha para a nova estrutura e retornam um ponteiro para a nova estrutura.

```cpp
MACRONAME( address_of_structure )
```

### <a name="remarks"></a>Comentários

Por exemplo:

[!code-cpp[NVC_ATL_Utilities#128](../../atl/codesnippet/cpp/string-conversion-macros_1.cpp)]

e:

[!code-cpp[NVC_ATL_Utilities#129](../../atl/codesnippet/cpp/string-conversion-macros_2.cpp)]

Os nomes de macro, o tipo de cadeia de caracteres na estrutura de origem está à esquerda (por exemplo, **um**) e o tipo de cadeia de caracteres na estrutura de destino está à direita (por exemplo, **W**). **Um** LPSTR, significa **OLE** LPOLESTR, significa **T** significa LPTSTR, e **W** significa LPWSTR.

Assim, DEVMODEA2W copia uma `DEVMODE` estrutura com LPSTR cadeias de caracteres em um `DEVMODE` estrutura com cadeias de caracteres LPWSTR, cópias TEXTMETRICOLE2T uma `TEXTMETRIC` estrutura com LPOLESTR cadeias de caracteres em um `TEXTMETRIC` estrutura com cadeias de caracteres LPTSTR e assim por diante.

As duas cadeias de caracteres convertidas na `DEVMODE` estrutura são o nome do dispositivo (`dmDeviceName`) e o nome do formulário (`dmFormName`). O `DEVMODE` macros de conversão de cadeia de caracteres também atualizar o tamanho da estrutura (`dmSize`).

As quatro cadeias de caracteres convertidas na `TEXTMETRIC` estrutura são o primeiro caractere (`tmFirstChar`), o último caractere (`tmLastChar`), o caractere padrão (`tmDefaultChar`) e o caractere de quebra (`tmBreakChar`).

O comportamento do `DEVMODE` e `TEXTMETRIC` macros de conversão de cadeia de caracteres depende da diretiva de compilador em vigor, se houver. Se os tipos de origem e de destino forem o mesmo, a conversão não ocorre. Alteram as diretivas de compilador **T** e **OLE** da seguinte maneira:

|Diretriz do compilador em vigor|T torna-se|OLE torna-se|
|----------------------------------|---------------|-----------------|
|nenhum|**A**|**W**|
|**\_UNICODE**|**W**|**W**|
|**OLE2ANSI**|**A**|**A**|
|**\_UNICODE** e **OLE2ANSI**|**W**|**A**|

A seguinte tabela lista os `DEVMODE` e `TEXTMETRIC` macros de conversão de cadeia de caracteres.

|||
|-|-|
|DEVMODEA2W|TEXTMETRICA2W|
|DEVMODEOLE2T|TEXTMETRICOLE2T|
|DEVMODET2OLE|TEXTMETRICT2OLE|
|DEVMODEW2A|TEXTMETRICW2A|

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
