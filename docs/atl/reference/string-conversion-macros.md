---
title: "Macros de conversão de cadeia de caracteres | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: 2ff7c0b6-2bde-45fe-897f-6128e18e0c27
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: bb94e24657d16b2a3eda3a770c2b6ae734c6006f
ms.openlocfilehash: e322c3af297c288ec6c9ccdb1c04e58d0a5759ff
ms.lasthandoff: 04/12/2017

---
# <a name="string-conversion-macros"></a>Macros de conversão de cadeia de caracteres
Essas macros fornecem recursos de conversão de cadeia de caracteres.  
  
 
##  <a name="atl_and_mfc_string_conversion_macros"></a>ATL e MFC Macros de conversão de cadeia de caracteres  
 As macros de conversão de cadeia de caracteres discutidas neste documento são válidas para ATL e MFC. Para obter mais informações sobre conversão de cadeia de caracteres do MFC, consulte [TN059: usando Macros de conversão de MBCS/Unicode MFC](../../mfc/tn059-using-mfc-mbcs-unicode-conversion-macros.md) e [Macros e globais MFC](../../mfc/reference/mfc-macros-and-globals.md).  
  
##  <a name="devmode_and_textmetric_string_conversion_macros"></a>DEVMODE e TEXTMETRIC Macros de conversão de cadeia de caracteres  
 Essas macros criar uma cópia de um [DEVMODE](http://msdn.microsoft.com/library/windows/desktop/dd183565) ou [TEXTMETRIC](http://msdn.microsoft.com/library/windows/desktop/dd145132) estrutura e converter as cadeias de caracteres dentro da estrutura de novo para um novo tipo de cadeia de caracteres. As macros alocar memória na pilha para a nova estrutura e retornam um ponteiro para a nova estrutura.  
  
```
MACRONAME( address_of_structure )
```  
  
### <a name="remarks"></a>Comentários  
 Por exemplo:  
  
 [!code-cpp[NVC_ATL_Utilities #128](../../atl/codesnippet/cpp/string-conversion-macros_1.cpp)]  
  
 e:  
  
 [!code-cpp[NVC_ATL_Utilities #129](../../atl/codesnippet/cpp/string-conversion-macros_2.cpp)]  
  
 Os nomes de macro, o tipo de cadeia de caracteres na estrutura de origem é à esquerda (por exemplo, **um**) e o tipo de cadeia de caracteres na estrutura de destino é à direita (por exemplo, **W**). **A** stands for **LPSTR**, **OLE** stands for `LPOLESTR`, **T** stands for `LPTSTR`, and **W** stands for `LPWSTR`.  
  
 Portanto, `DEVMODEA2W` cópias um `DEVMODE` estrutura com **LPSTR** cadeias de caracteres em um `DEVMODE` estrutura com `LPWSTR` cadeias de caracteres, `TEXTMETRICOLE2T` cópias um `TEXTMETRIC` estrutura com `LPOLESTR` cadeias de caracteres em uma `TEXTMETRIC` estrutura com `LPTSTR` cadeias de caracteres e assim por diante.  
  
 As duas cadeias de caracteres convertidas a `DEVMODE` estrutura são o nome do dispositivo ( **dmDeviceName**) e o nome do formulário ( **dmFormName**). O `DEVMODE` macros de conversão de cadeia de caracteres também atualizar o tamanho da estrutura ( **dmSize**).  
  
 As quatro cadeias de caracteres convertidas no `TEXTMETRIC` estrutura são o primeiro caractere ( **tmFirstChar**), o último caractere ( **tmLastChar**), o caractere padrão ( **tmDefaultChar**) e o caractere de quebra ( **tmBreakChar**).  
  
 O comportamento do `DEVMODE` e `TEXTMETRIC` macros de conversão de cadeia de caracteres depende da diretiva de compilador em vigor, se houver. Se os tipos de origem e de destino forem o mesmo, a conversão não ocorre. Diretivas de compilador alterar **T** e **OLE** da seguinte maneira:  
  
|Diretriz do compilador em vigor|T torna-se|OLE torna-se|  
|----------------------------------|---------------|-----------------|  
|nenhum|**A**|**W**|  
|**UNICODE**|**W**|**W**|  
|**OLE2ANSI**|**A**|**A**|  
|**Unicode** e **OLE2ANSI**|**W**|**A**|  
  
 A seguinte tabela lista o `DEVMODE` e `TEXTMETRIC` macros de conversão de cadeia de caracteres.  
  
|||  
|-|-|  
|`DEVMODEA2W`|`TEXTMETRICA2W`|  
|`DEVMODEOLE2T`|`TEXTMETRICOLE2T`|  
|`DEVMODET2OLE`|`TEXTMETRICT2OLE`|  
|`DEVMODEW2A`|`TEXTMETRICW2A`|  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)


