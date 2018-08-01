---
title: char, wchar_t, char16_t, char32_t | Microsoft Docs
ms.custom: ''
ms.date: 02/14/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- char_cpp
- char16_t_cpp
- wchar_t_cpp
- char32_t_cpp
dev_langs:
- C++
ms.assetid: 6b33e9f5-455b-4e49-8f12-a150cbfe2e5b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2d0c89df02c624d96c613f6241c9beefd466827e
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402608"
---
# <a name="char-wchart-char16t-char32t"></a>char, wchar_t, char16_t, char32_t
Os tipos **char**, **wchar_t**, **char16_t** e **char32_t** são tipos internos que representam caracteres alfanuméricos, bem como glifos não alfanuméricos e caracteres não imprimíveis.

## <a name="syntax"></a>Sintaxe

```cpp  
char     ch1{ 'a' };  // or { u8'a' }   
wchar_t  ch2{ L'a' };    
char16_t ch3{ u'a' };    
char32_t ch4{ U'a' };  
```  
  
## <a name="remarks"></a>Comentários

O **char** tipo era o tipo de caracteres original em C e C++. O tipo **unsigned char** geralmente é usado para representar uma *bytes*, que não é um tipo interno em C++. O **char** tipo pode ser usado para armazenar os caracteres do conjunto de caracteres ASCII ou qualquer um dos conjuntos de caracteres ISO-8859 e bytes individuais de caracteres de vários bytes, como Shift-JIS ou a codificação UTF-8 de conjunto de caracteres Unicode. Cadeias de caracteres de **char** tipo são denominados *restringir* cadeias de caracteres, mesmo quando usado para codificar caracteres multibyte. No compilador da Microsoft, **char** é um tipo de 8 bits.

O **wchar_t** tipo é um tipo de caractere largo definido pela implementação. O compilador da Microsoft, ele representa um caractere largo de 16 bits usado para armazenar Unicode codificado como UTF-16LE, o tipo de caracteres nativos em sistemas de operacionais do Windows. As versões de caractere largo do uso de funções da biblioteca de tempo de execução do C Universal (UCRT) **wchar_t** e seu ponteiro e uma matriz de tipos como parâmetros e valores de retorno, assim como as versões de caractere largo da API nativa do Windows.

O **char16_t** e **char32_t** tipos representam caracteres largos de 16 bits e 32 bits, respectivamente. Unicode codificada como UTF-16 pode ser armazenado na **char16_t** tipo e Unicode codificada como UTF-32 pode ser armazenados na **char32_t** tipo. Cadeias de caracteres de um desses tipos e **wchar_t** são todos os referidos como *ampla* cadeias de caracteres, embora o termo geralmente refere-se especificamente a cadeias de caracteres de **wchar_t** tipo.

Na biblioteca C++ padrão, o `basic_string` tipo é especializado em cadeias de caracteres estreitas e largos. Use `std::string` quando os caracteres são do tipo **char**, `std::u16string` quando os caracteres são do tipo **char16_t**, `std::u32string` quando os caracteres são do tipo **char32_t** , e `std::wstring` quando os caracteres são do tipo **wchar_t**. Outros tipos que representam o texto, incluindo `std::stringstream` e `std::cout` tem especializações para cadeias de caracteres estreitas e largos.  