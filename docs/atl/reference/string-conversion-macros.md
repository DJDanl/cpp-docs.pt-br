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
ms.openlocfilehash: 6a84424de81eba2e6ab1e1baf60f567ebf2739ee
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68915500"
---
# <a name="string-conversion-macros"></a>Macros de conversão de cadeia de caracteres

Essas macros fornecem recursos de conversão de cadeia de caracteres.

##  <a name="atl_and_mfc_string_conversion_macros"></a>Macros de conversão de cadeia de caracteres ATL e MFC

As macros de conversão de cadeia de caracteres discutidas neste documento são válidas para ATL e MFC. Para obter mais informações sobre conversão de cadeia de [caracteres MFC, consulte TN059: Usando macros](../../mfc/tn059-using-mfc-mbcs-unicode-conversion-macros.md) de conversão do MFC MBCS/Unicode e [macros MFC e globais](../../mfc/reference/mfc-macros-and-globals.md).

##  <a name="devmode_and_textmetric_string_conversion_macros"></a>Macros de conversão DEVMODE e TEXTMETRIC String

Essas macros criam uma cópia de uma estrutura [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) ou [TEXTMETRIC](/windows/desktop/api/wingdi/ns-wingdi-tagtextmetrica) e convertem as cadeias de caracteres dentro da nova estrutura para um novo tipo de cadeia. As macros alocam memória na pilha para a nova estrutura e retornam um ponteiro para a nova estrutura.

```cpp
MACRONAME( address_of_structure )
```

### <a name="remarks"></a>Comentários

Por exemplo:

[!code-cpp[NVC_ATL_Utilities#128](../../atl/codesnippet/cpp/string-conversion-macros_1.cpp)]

e:

[!code-cpp[NVC_ATL_Utilities#129](../../atl/codesnippet/cpp/string-conversion-macros_2.cpp)]

Nos nomes de macro, o tipo de cadeia de caracteres na estrutura de origem está à esquerda (por exemplo, **a**) e o tipo de cadeia de caracteres na estrutura de destino está à direita (por exemplo, **W**). **Um** significa que se refere a LPStr, **OLE** significa LPOLESTR, **T** significa LPTSTR e **W** significa LPWSTR.

Assim, DEVMODEA2W copia uma `DEVMODE` estrutura com cadeias de LPSTR `DEVMODE` em uma estrutura com cadeias de caracteres `TEXTMETRIC` LPWStr, TEXTMETRICOLE2T copia uma estrutura `TEXTMETRIC` com cadeias de caracteres LPOLESTR em uma estrutura com cadeias de caracteres de LPTSTR e assim por diante.

As duas cadeias de caracteres `DEVMODE` convertidas na estrutura são`dmDeviceName`o nome do dispositivo ()`dmFormName`e o nome do formulário (). As `DEVMODE` macros de conversão de cadeia de caracteres também`dmSize`atualizam o tamanho da estrutura ().

As quatro cadeias de caracteres `TEXTMETRIC` convertidas na estrutura são`tmFirstChar`o primeiro caractere (),`tmLastChar`o último caractere (),`tmDefaultChar`o caractere padrão () e o`tmBreakChar`caractere de quebra ().

O comportamento das `DEVMODE` macros `TEXTMETRIC` e de conversão de cadeia de caracteres depende da diretiva do compilador em vigor, se houver. Se os tipos de origem e de destino forem o mesmo, a conversão não ocorre. As diretivas do compilador alteram **T** e **OLE** da seguinte maneira:

|Diretriz do compilador em vigor|T torna-se|OLE torna-se|
|----------------------------------|---------------|-----------------|
|nenhum|**A**|**W**|
|**\_UNICODE**|**W**|**W**|
|**OLE2ANSI**|**A**|**A**|
|Unicode e **OLE2ANSI**  **\_**|**W**|**A**|

A tabela a seguir lista `DEVMODE` as `TEXTMETRIC` macros de conversão de cadeia de caracteres e.

|||
|-|-|
|DEVMODEA2W|TEXTMETRICA2W|
|DEVMODEOLE2T|TEXTMETRICOLE2T|
|DEVMODET2OLE|TEXTMETRICT2OLE|
|DEVMODEW2A|TEXTMETRICW2A|

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
