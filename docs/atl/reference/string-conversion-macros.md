---
title: Macros de conversão de strings
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
ms.openlocfilehash: 8df496b78334d26e7d3664642b2e9d93d6149843
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325846"
---
# <a name="string-conversion-macros"></a>Macros de conversão de strings

Essas macros fornecem recursos de conversão de strings.

## <a name="atl-and-mfc-string-conversion-macros"></a><a name="atl_and_mfc_string_conversion_macros"></a>Macros de conversão de strings ATL e MFC

As macros de conversão de cadeia de caracteres discutidas neste documento são válidas para ATL e MFC. Para obter mais informações sobre a conversão de strings MFC, consulte [TN059: Usando macros de conversão MFC MBCS/Unicode](../../mfc/tn059-using-mfc-mbcs-unicode-conversion-macros.md) e [Macros e Globais MFC](../../mfc/reference/mfc-macros-and-globals.md).

## <a name="devmode-and-textmetric-string-conversion-macros"></a><a name="devmode_and_textmetric_string_conversion_macros"></a>DeVMODE e Macros de conversão de strings textmétricas

Essas macros criam uma cópia de uma estrutura [DEVMODE](/windows/win32/api/wingdi/ns-wingdi-devmodea) ou [TEXTMETRIC](/windows/win32/api/wingdi/ns-wingdi-textmetricw) e convertem as strings dentro da nova estrutura para um novo tipo de string. As macros alocam memória na pilha para a nova estrutura e retornam um ponteiro para a nova estrutura.

```cpp
MACRONAME( address_of_structure )
```

### <a name="remarks"></a>Comentários

Por exemplo:

[!code-cpp[NVC_ATL_Utilities#128](../../atl/codesnippet/cpp/string-conversion-macros_1.cpp)]

e:

[!code-cpp[NVC_ATL_Utilities#129](../../atl/codesnippet/cpp/string-conversion-macros_2.cpp)]

Nos nomes de macro, o tipo de string na estrutura de origem está à esquerda (por exemplo, **A**) e o tipo de string na estrutura de destino está à direita (por exemplo, **W**). **A** significa LPSTR, **OLE** significa LPOLESTR, **T** significa LPTSTR, e **W** significa LPWSTR.

Assim, `DEVMODE` O DEVMODEA2W copia uma estrutura `DEVMODE` com cordas LPSTR em uma estrutura com strings LPWSTR, TEXTMETRICOLE2T copia uma `TEXTMETRIC` estrutura com cordas LPOLESTR em uma `TEXTMETRIC` estrutura com strings LPTSTR, e assim por diante.

As duas cordas convertidas `DEVMODE` na estrutura são`dmDeviceName`o nome do`dmFormName`dispositivo ( ) e o nome do formulário ( ). As `DEVMODE` macros de conversão de`dmSize`strings também atualizam o tamanho da estrutura ( ).

As quatro cordas convertidas `TEXTMETRIC` na estrutura são`tmFirstChar`o primeiro`tmLastChar`caractere ( ),`tmDefaultChar`o último caractere`tmBreakChar`( ), o caractere padrão ( ), e o caractere de ruptura ( ).

O comportamento `DEVMODE` das `TEXTMETRIC` macros de conversão de cordas e depende da diretiva do compilador em vigor, se houver. Se os tipos de origem e de destino forem o mesmo, a conversão não ocorre. As diretivas do compilador alteram **T** e **OLE** da seguinte forma:

|Diretriz do compilador em vigor|T torna-se|OLE torna-se|
|----------------------------------|---------------|-----------------|
|none|**A**|**W**|
|**\_Unicode**|**W**|**W**|
|**OLE2ANSI**|**A**|**A**|
|UNICODE e **OLE2ANSI** ** \_**|**W**|**A**|

A tabela a `DEVMODE` `TEXTMETRIC` seguir lista as macros e conversão de strings.

|||
|-|-|
|DEVMODEA2W|TEXTMETRICA2W|
|DEVMODEOLE2T|TEXTMETRICOLE2T|
|DEVMODET2OLE|TEXTMETRICT2OLE|
|DEVMODEW2A|TEXTMETRICW2A|

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
