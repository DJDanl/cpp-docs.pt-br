---
title: char, wchar_t, char16_t, char32_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- char_cpp
- char16_t_cpp
- wchar_t_cpp
- char32_t_cpp
dev_langs: C++
ms.assetid: 6b33e9f5-455b-4e49-8f12-a150cbfe2e5b
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4eaccef4253d2b677f01801b680bb94d8a4d3516
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="char-wchart-char16t-char32t"></a>char, wchar_t, char16_t, char32_t
O caractere de tipos wchar_t, char16_t e char32_t são criados em tipos que representam os caracteres alfanuméricos, bem como glifos não-alfanuméricos e caracteres não imprimíveis. Char é de oito bits de tamanho, wchar_t e char16_t são 16 bits de tamanho e char32_t é de 32 bits.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
char     ch1{ 'a' };    
wchar_t  ch2{ 'a' }; // or {L'a'}    
char16_t ch3{ L'a' };// or {L'a'}    
char32_t ch4{ L'a' };// or {L'a'}  
```  
  
## <a name="remarks"></a>Comentários  
 O `char` tipo era o tipo de caracteres original em C e C++. Ele pode ser usado para armazenar caracteres do conjunto de caracteres ASCII ou qualquer um dos conjuntos de caracteres ISO 8859 ou conjunto de caracteres UTF-8. O tipo `unsigned char` geralmente é usada para representar um *bytes* que não é um tipo interno em C++. O tipo de caractere não é adequado para texto em vários idiomas. Em geral, os programas modernos devem usar um dos tipos de caractere largo para representar o texto. Unicode é a  
  
 Na biblioteca C++ padrão, o tipo basic_string é especializado para cadeias de caracteres estreitas e largura. Use std::string quando os caracteres são do tipo char e std:: wstring quando os caracteres são do tipo wchar_t. Outros tipos que representam o texto, incluindo std::stringstream e std::cout têm especializações para cadeias de caracteres largas e estreitas.  
  
