---
title: "char, wchar_t, char16_t, char32_t | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "char_cpp"
  - "char16_t_cpp"
  - "whchar_t_cpp"
  - "char32_t_cpp"
dev_langs: 
  - "C++"
ms.assetid: 6b33e9f5-455b-4e49-8f12-a150cbfe2e5b
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# char, wchar_t, char16_t, char32_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os tipos char wchar\_t, char16\_t e char32\_t baseiam\-se em tipos que representam os caracteres alfanuméricos, bem como não\-alfanuméricos glifos e caracteres não imprimíveis.  Char é de oito bits de tamanho, wchar\_t e char16\_t têm 16 bits de tamanho e char32\_t é de 32 bits.  
  
## Sintaxe  
  
```vb  
char     ch1{ 'a' };  
wchar_t  ch2{ 'a' }; // or {L'a'}  
char16_t ch3{ L'a' };// or {L'a'}  
char32_t ch4{ L'a' };// or {L'a'}  
```  
  
## Comentários  
 O `char` tipo era o tipo de caracteres original em C e C\+\+.  Ele pode ser usado para armazenar caracteres do conjunto de caracteres ASCII ou qualquer um dos conjuntos de caracteres ISO\-8859 ou conjunto de caracteres UTF\-8.  O tipo `unsigned char` é frequentemente usado para representar um *bytes* que não é um tipo interno em C\+\+.  O tipo char não é adequado para texto em vários idiomas.  Em geral, os programas modernos devem usar um dos tipos de caractere largo para representar o texto.  O Unicode é o  
  
 Na biblioteca C\+\+ padrão, o tipo basic\_string é especializado para cadeias de caracteres estreitas e largura.  Use std:: string quando os caracteres são do tipo char e std:: wstring quando os caracteres são do tipo wchar\_t.  Outros tipos que representam o texto, incluindo std::stringstream e std::cout têm especializações para cadeias de caracteres estreitas e largura.  
  
## Requisitos