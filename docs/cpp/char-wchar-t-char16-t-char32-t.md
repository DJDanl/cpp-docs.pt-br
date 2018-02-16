---
title: char, wchar_t, char16_t, char32_t | Microsoft Docs
ms.custom: 
ms.date: 02/14/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- char_cpp
- char16_t_cpp
- wchar_t_cpp
- char32_t_cpp
dev_langs:
- C++
ms.assetid: 6b33e9f5-455b-4e49-8f12-a150cbfe2e5b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a87eff9801b2754909159ef4d5e2c24c079ee8f1
ms.sourcegitcommit: 23a0ddd271bbcc31631283542981ff5f1693d27f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/15/2018
---
# <a name="char-wchart-char16t-char32t"></a>char, wchar_t, char16_t, char32_t
Os tipos de **char**, **wchar_t**, **char16_t** e **char32_t** são tipos internos que representam os caracteres alfanuméricos, bem como glifos não-alfanuméricos e caracteres não imprimíveis.

## <a name="syntax"></a>Sintaxe

```cpp  
char     ch1{ 'a' };  // or { u8'a' }   
wchar_t  ch2{ L'a' };    
char16_t ch3{ u'a' };    
char32_t ch4{ U'a' };  
```  
  
## <a name="remarks"></a>Comentários

O **char** tipo era o tipo de caracteres original em C e C++. O tipo **unsigned char** geralmente é usada para representar um *bytes*, que não é um tipo interno em C++. O **char** tipo pode ser usado para armazenar caracteres do conjunto de caracteres ASCII ou qualquer um dos conjuntos de caracteres ISO 8859 e individuais bytes de caracteres de vários bytes, como Shift JIS ou a codificação UTF-8 do conjunto de caracteres Unicode. Cadeias de caracteres de **char** tipo são denominados *restringir* cadeias de caracteres, mesmo quando usado para codificar caracteres multibyte. Em que o compilador da Microsoft, **char** é um tipo de 8 bits.

O **wchar_t** é um tipo de caractere largo definido pela implementação. O compilador da Microsoft, ele representa um caractere largo de 16 bits usado para armazenar Unicode codificado como UTF-16LE, o tipo de caractere nativo em sistemas operacionais Windows. As versões de caractere largo de que o uso de funções de biblioteca de tempo de execução de C Universal (UCRT) **wchar_t** e seu ponteiro e matriz de tipos como parâmetros e valores de retorno, como as versões de caractere largo da API do Windows nativo.

O **char16_t** e **char32_t** tipos representam caracteres largos de 16 bits e 32 bits, respectivamente. Codificada como UTF-16 pode ser armazenado em Unicode de **char16_t** tipo e a codificação como UTF-32 pode ser armazenado em Unicode a **char32_t** tipo. Cadeias de caracteres desses tipos e **wchar_t** são todos os chamados de *ampla* cadeias de caracteres, embora o termo geralmente refere-se especificamente a cadeias de caracteres de **wchar_t** tipo.

Na biblioteca C++ padrão, o `basic_string` tipo é especializado para cadeias de caracteres estreitas e largura. Use `std::string` quando os caracteres são do tipo **char**, `std::u16string` quando os caracteres são do tipo **char16_t**, `std::u32string` quando os caracteres são do tipo **char32_t** , e `std::wstring` quando os caracteres são do tipo **wchar_t**. Outros tipos que representam o texto, incluindo `std::stringstream` e `std::cout` têm especializações para cadeias de caracteres largas e estreitas.  
  
