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
ms.openlocfilehash: 60cccebf4e1db8369ea5a88f04a37b96838ff49f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835149"
---
# <a name="string-conversion-macros"></a>Macros de conversão de cadeia de caracteres

Essas macros fornecem recursos de conversão de cadeia de caracteres.

## <a name="atl-and-mfc-string-conversion-macros"></a><a name="atl_and_mfc_string_conversion_macros"></a> Macros de conversão de cadeia de caracteres ATL e MFC

As macros de conversão de cadeia de caracteres discutidas neste documento são válidas para ATL e MFC. Para obter mais informações sobre conversão de cadeia de caracteres do MFC, consulte [TN059: usando macros de conversão do MFC MBCS/Unicode](../../mfc/tn059-using-mfc-mbcs-unicode-conversion-macros.md) e [macros do MFC e globais](../../mfc/reference/mfc-macros-and-globals.md).

## <a name="devmode-and-textmetric-string-conversion-macros"></a><a name="devmode_and_textmetric_string_conversion_macros"></a> Macros de conversão DEVMODE e TEXTMETRIC String

Essas macros criam uma cópia de uma estrutura [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) ou [TEXTMETRIC](/windows/win32/api/wingdi/ns-wingdi-textmetricw) e convertem as cadeias de caracteres dentro da nova estrutura para um novo tipo de cadeia. As macros alocam memória na pilha para a nova estrutura e retornam um ponteiro para a nova estrutura.

```cpp
MACRONAME( address_of_structure )
```

### <a name="remarks"></a>Comentários

Por exemplo:

[!code-cpp[NVC_ATL_Utilities#128](../../atl/codesnippet/cpp/string-conversion-macros_1.cpp)]

e:

[!code-cpp[NVC_ATL_Utilities#129](../../atl/codesnippet/cpp/string-conversion-macros_2.cpp)]

Nos nomes de macro, o tipo de cadeia de caracteres na estrutura de origem está à esquerda (por exemplo, **a**) e o tipo de cadeia de caracteres na estrutura de destino está à direita (por exemplo, **W**). **Um** significa que se refere a LPStr, **OLE** significa LPOLESTR, **T** significa LPTSTR e **W** significa LPWSTR.

Assim, DEVMODEA2W copia uma `DEVMODE` estrutura com cadeias de LPSTR em uma `DEVMODE` estrutura com cadeias de caracteres LPWSTR, TEXTMETRICOLE2T copia uma `TEXTMETRIC` estrutura com cadeias de caracteres LPOLESTR em uma `TEXTMETRIC` estrutura com cadeias de caracteres de LPTSTR e assim por diante.

As duas cadeias de caracteres convertidas na `DEVMODE` estrutura são o nome do dispositivo ( `dmDeviceName` ) e o nome do formulário ( `dmFormName` ). As `DEVMODE` macros de conversão de cadeia de caracteres também atualizam o tamanho da estrutura ( `dmSize` ).

As quatro cadeias de caracteres convertidas na `TEXTMETRIC` estrutura são o primeiro caractere ( `tmFirstChar` ), o último caractere ( `tmLastChar` ), o caractere padrão ( `tmDefaultChar` ) e o caractere de quebra ( `tmBreakChar` ).

O comportamento das `DEVMODE` `TEXTMETRIC` macros e de conversão de cadeia de caracteres depende da diretiva do compilador em vigor, se houver. Se os tipos de origem e de destino forem o mesmo, a conversão não ocorre. As diretivas do compilador alteram **T** e **OLE** da seguinte maneira:

|Diretriz do compilador em vigor|T torna-se|OLE torna-se|
|----------------------------------|---------------|-----------------|
|nenhum|**A**|**W**|
|**\_UNICODE**|**W**|**W**|
|**OLE2ANSI**|**A**|**A**|
|** \_ Unicode** e **OLE2ANSI**|**W**|**A**|

A tabela a seguir lista `DEVMODE` as `TEXTMETRIC` macros de conversão de cadeia de caracteres e.

|`DEVMODE` Ela|`TEXTMETRIC` Ela|
|-|-|
|DEVMODEA2W|TEXTMETRICA2W|
|DEVMODEOLE2T|TEXTMETRICOLE2T|
|DEVMODET2OLE|TEXTMETRICT2OLE|
|DEVMODEW2A|TEXTMETRICW2A|

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
