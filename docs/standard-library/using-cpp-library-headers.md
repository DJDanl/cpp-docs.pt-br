---
title: "Usando cabe&#231;alhos da Biblioteca C++ | Microsoft Docs"
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
  - "cabeçalhos"
  - "cabeçalhos, nomeando em diretiva include do C++"
  - "cabeçalhos, Biblioteca Padrão C++"
  - "diretiva INCLUDE"
  - "cabeçalhos de biblioteca"
  - "Biblioteca Padrão C++, cabeçalhos"
  - "cabeçalho padrão em C++"
ms.assetid: a36e889e-1af2-4cd9-a211-bfc7a3fd8e85
caps.latest.revision: 10
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando cabe&#231;alhos da Biblioteca C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você inclui o conteúdo de um cabeçalho padrão nomeando o em uma política incluir.  
  
```  
#include <iostream>   // include I/O facilities  
```  
  
 Você pode incluir os cabeçalhos padrão em qualquer ordem, um cabeçalho padrão mais de uma vez, ou dois ou mais cabeçalhos padrão que definem o mesmo macro ou o mesmo tipo.  Não inclua um cabeçalho padrão em uma declaração.  Não defina macros que têm os mesmos nomes que as palavras\-chave antes que você inclui um cabeçalho padrão.  
  
 O cabeçalho da biblioteca c criando inclui todos os outros cabeçalhos da biblioteca C\+\+ necessário definir tipos necessários. \(Sempre incluir explicitamente todos os cabeçalhos da biblioteca C\+\+ necessários em uma unidade de tradução, no entanto, a fim de que você não suponha errado sobre suas dependências reais.\) Um cabeçalho padrão C nunca inclui outro cabeçalho padrão.  Um cabeçalho padrão declara ou define apenas as entidades descritas para ele neste documento.  
  
 Cada função na biblioteca é declarada em um cabeçalho padrão.  Diferentemente de C padrão 2.0, o cabeçalho padrão nunca fornece uma macro mascarando com o mesmo nome que a função que mascara a declaração de função e obtém o mesmo efeito.  Para obter mais informações sobre como mascarar macros, consulte [Convenções da Biblioteca C\+\+](../standard-library/cpp-library-conventions.md).  
  
 Todos os nomes diferentes de `operator delete` e de `operator new` nos cabeçalhos da biblioteca C\+\+ são definidos no namespace de `std` , ou em um namespace aninhada dentro do namespace de `std` .  Você se referir ao nome `cin`, por exemplo, como `std::cin`.  A observe, entretanto, que os nomes de macro não estão sujeitos a qualificação do namespace, assim que você gravação sempre `__STD_COMPLEX` sem um qualificador de namespace.  
  
 Em alguns ambientes de tradução, incluir o cabeçalho da biblioteca c criando pode içar os nomes externos declarados no namespace de `std` no namespace global além disso, com instruções individuais de `using` para cada um dos nomes.  Caso contrário, o cabeçalho *não* apresenta nomes de biblioteca no namespace atual.  
  
 O padrão do C\+\+ requer que os cabeçalhos padrão C declaram todos os nomes externos no namespace `std`, então iça\-os no namespace global com instruções individuais de `using` para cada um dos nomes.  Mas em alguns ambientes de tradução os cabeçalhos padrão C não inclui nenhuma declaração de namespace, declarando todos os nomes diretamente no namespace global.  Assim, a maneira mais portáteis de tratar os namespaces é e duas regras:  
  
-   Para declarar realmente no namespace `std` um nome externo que é declarada tradicional \<em stdlib.h, por exemplo\>, o inclui o cstdlib de cabeçalho \<.\>  Lembre\-se de que o nome também pode ser declarado no namespace global.  
  
-   Para declarar realmente no namespace global um nome externo declarado \<em stdlib.h, inclua\>o cabeçalho stdlib.h \<diretamente\> .  Lembre\-se de que o nome também pode ser declarado no namespace `std`.  
  
 Assim, se você deseja chamar `std::abort` para fazer com que o encerramento anormal, você deve incluir \<o cstdlib\>.  Se você deseja chamar `abort`, você deve incluir \<stdlib.h.\>  
  
 Como alternativa, você pode gravar a instrução:  
  
```  
using namespace std;  
```  
  
 que coloca todos os nomes de biblioteca no namespace atual.  Se você escrever essa instrução imediatamente após inclui políticas, você içam os nomes no namespace global.  Você pode ignorar subsequentemente considerações de namespace no restante da unidade de conversão.  Você também impede a maioria das diferenças em ambientes diferentes de tradução para o.  
  
 A menos que indicado especificamente de outra forma, você não pode definir os nomes no namespace de `std` , ou em um namespace aninhada dentro do namespace de `std` , dentro de seu programa.  
  
## Consulte também  
 [Visão geral da STL](../standard-library/cpp-standard-library-overview.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)