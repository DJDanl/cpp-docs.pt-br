---
title: "Operador stringizing (#) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "#"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Operador de pré-processador #"
  - "argumentos [C++], convertendo em cadeias de caracteres"
  - "macros [C++], convertendo parâmetros em cadeias de caracteres"
  - "pré-processador"
  - "pré-processador, operadores"
  - "literais String, convertendo parâmetros de macro em"
  - "Operador stringizing"
ms.assetid: 1175dd19-4538-43b3-ad97-a008ab80e7b1
caps.latest.revision: 16
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Operador stringizing (#)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O operador de sinal de número ou “stringizing” \(**\#**\) converte parâmetros de macro em literais de cadeia de caracteres sem expanda a definição do parâmetro.  É usado apenas com macros que aceitam argumentos.  Se ele preceder um parâmetro formal na definição da macro, o argumento real passado por invocação de macro é colocado entre em aspas e tratado como literal de cadeia de caracteres.  O literal da cadeia de caracteres substitui cada ocorrência de uma combinação do operador stringizing e do parâmetro formal na definição da macro.  
  
> [!NOTE]
>  A extensão do Microsoft C \(versões 6.0 e anteriores\) para o padrão ANSI C, que anteriormente expandia os argumentos formais de macro que apareciam em literais de cadeias de caracteres e constantes de caracteres, não tem mais suporte.  O código que usava esta extensão tinha de ser recriado usando o operador stringizing \(**\#**\).  
  
 O espaço em branco que precede o primeiro token do argumento real e depois do último token do argumento real é ignorado.  Todo o espaço em branco entre os tokens no argumento real é reduzido a um único espaço em branco no literal de cadeia de caracteres resultante.  Assim, se um comentário ocorrer entre dois tokens no argumento real, ele será reduzido a um único espaço em branco.  O literal de cadeia de caracteres resultante é concatenada automaticamente com os literais de cadeia de caracteres adjacentes dos quais ele esteja separado apenas por espaço em branco.  
  
 Além disso, se um caractere contido no argumento exigir normalmente uma sequência de escape quando usado em um literal de cadeia de caracteres \(por exemplo, aspas \(**"**\) ou um caractere de barra invertida \(**\\**\), a barra invertida de escape necessária é automaticamente inserida antes do caractere.  
  
 O operador stringizing do Visual C\+\+ pode não se comportar como esperado em todas as situações; consulte [16.3.2 O operador \#](../misc/16-3-2-the-hash-operator.md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir mostra uma definição macro que inclui o operador stringizing e uma função main que invoca a macro:  
  
 Essas invocações seriam expandidas durante o pré\-processamento, gerando o seguinte código:  
  
```  
int main() {  
   printf_s( "In quotes in the printf function call\n" "\n" );  
   printf_s( "\"In quotes when printed to the screen\"\n" "\n" );  
   printf_s( "\"This: \\\" prints an escaped double quote\"" "\n" );  
}  
```  
  
```  
// stringizer.cpp  
#include <stdio.h>  
#define stringer( x ) printf_s( #x "\n" )  
int main() {  
   stringer( In quotes in the printf function call );   
   stringer( "In quotes when printed to the screen" );     
   stringer( "This: \"  prints an escaped double quote" );  
}  
```  
  
  **Entre aspas na chamada de função printf**  
**“Entre aspas quando impresso na tela”**  
**"Isto: \\" imprime aspas duplas de escape"**   
## Exemplo  
 O exemplo a seguir mostra como você pode expandir um parâmetro de macro:  
  
```  
// stringizer_2.cpp  
// compile with: /E  
#define F abc  
#define B def  
#define FB(arg) #arg  
#define FB1(arg) FB(arg)  
FB(F B)  
FB1(F B)  
```  
  
## Consulte também  
 [Operadores de pré\-processador](../preprocessor/preprocessor-operators.md)