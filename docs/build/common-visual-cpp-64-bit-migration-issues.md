---
title: "Problemas de migra&#231;&#227;o de 64 bits do Visual C++comuns | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "movimentação de código de 32 bits [C++]"
  - "Aplicativos 64-bit [C++]"
  - "compilador de 64 bits [C++], migração"
  - "compilador de 64 bits [C++], movimentando código de 32 bits"
  - "Programação 64-bit [C++], migração"
  - "migração [C++], problemas de código de 64 bits"
  - "movimentando código de 32 bits para código de 64 bits"
  - "atualizando aplicativos Visual C++, código de 32 bits"
  - "Win64 [C++]"
ms.assetid: d17fb838-7513-4e2d-8b27-a1666f17ad76
caps.latest.revision: 19
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Problemas de migra&#231;&#227;o de 64 bits do Visual C++comuns
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você usa o Visual C\+\+ para criar aplicativos para serem executados em um sistema de operacional do Windows de 64 bits, você deve estar ciente dos seguintes problemas:  
  
-   Um `int` e um `long` são valores de 32 bits em sistemas operacionais 64 bits.  Para programas que você pretende compilar para plataformas de 64 bits, você deve ser cuidado para não atribuir ponteiros para variáveis de 32 bits.  Os ponteiros são 64 bits em plataformas de 64 bits e você irá truncar o valor do ponteiro se você atribuir uma variável de 32 bits.  
  
-   `size_t`, `time_t`, e `ptrdiff_t` são valores de 64 bits em sistemas operacionais 64 bits.  
  
-   `time_t` é um valor de 32 bits em sistemas de operacional Windows de 32 bits em versões do Visual C\+\+ antes do Visual C\+\+ 2005.  `time_t` Agora é um inteiro de 64 bits por padrão.  Para obter mais informações, consulte [gerenciamento de tempo](../c-runtime-library/time-management.md).  
  
     Você deve estar ciente de onde seu código usa um `int` valor e o processa como um `size_t` ou `time_t` valor.  É possível que o número pode aumentar para ser maior do que um número de 32 bits e os dados serão truncados quando ele é passado de volta para o `int` armazenamento.  
  
 O %x \(hexadecimal `int` formato\) `printf` modificador não funcionará conforme o esperado em um sistema de operacional do Windows de 64 bits.  Ele só funciona nos primeiros 32 bits do valor que é passado para ele.  
  
-   Use % I32x para exibir um tipo integral de 32 bits em formato hexadecimal.  
  
-   Use % I64x para exibir um tipo integral de 64 bits em formato hexadecimal.  
  
-   O %p \(formato hexadecimal de um ponteiro\) funcionará conforme o esperado em um sistema de operacional do Windows de 64 bits.  
  
 Para obter mais informações, consulte:  
  
-   [Opções do Compilador](../build/reference/compiler-options.md)  
  
-   [\<caps:sentence id\="tgt18" sentenceid\="8228b16e9fef41dbba1af1d78bf0cc87" class\="tgtSentence"\>Dicas de migração\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/aa384214)  
  
## Consulte também  
 [Configurando programas para 64 bits](../build/configuring-programs-for-64-bit-visual-cpp.md)   
 [portar seu programa](http://msdn.microsoft.com/pt-br/c36c44b3-5a9b-4bb4-9b7a-469aa770ed00)