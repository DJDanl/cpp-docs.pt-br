---
title: "hdrstop | Microsoft Docs"
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
  - "hdrstop_CPP"
  - "vc-pragma.hdrstop"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragma hdrstop"
  - "pragmas, hdrstop"
ms.assetid: 5ea8370a-10d1-4538-ade6-4c841185da0e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# hdrstop
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fornece controle adicional sobre nomes de arquivo de pré\-compilação e sobre o local em que o estado da compilação é salvo.  
  
## Sintaxe  
  
```  
  
#pragma hdrstop [( "filename" )]    
```  
  
## Comentários  
 O argumento *filename* é o nome do arquivo de cabeçalho pré\-compilado a ser usado ou criado \(dependendo se [\/Yu](../build/reference/yu-use-precompiled-header-file.md) ou [\/Yc](../build/reference/yc-create-precompiled-header-file.md) é especificado\).  Se *filename* não contém uma especificação de caminho, pressupõe\-se que o arquivo de cabeçalho pré\-compilado esteja no mesmo diretório do arquivo de origem.  
  
 Se um arquivo de C ou C\+\+ contém um pragma **hdrstop** quando compilado com \/Yc, o compilador salva o estado da compilação até o local do pragma.  O estado compilado de todo o código que se segue ao pragma não é salvo.  
  
 Use *filename* para nomear o arquivo de cabeçalho pré\-compilado no qual o estado compilado é salvo.  Um espaço entre **hdrstop** e *filename* é opcional.  O nome de arquivo especificado no pragma **hdrstop** é uma cadeia de caracteres e, portanto, está sujeito às restrições de qualquer cadeia de caracteres de C ou C\+\+.  Em particular, você deve colocá\-lo entre aspas e usar o caractere de escape \(barra invertida\) para especificar nomes de diretório.  Por exemplo:  
  
```  
#pragma hdrstop( "c:\\projects\\include\\myinc.pch" )  
```  
  
 O nome do arquivo de cabeçalho pré\-compilado é determinado de acordo com as regras a seguir, em ordem de precedência:  
  
1.  O argumento da opção de compilador \/Fp  
  
2.  O argumento *filename* de \#**pragma hdrstop**  
  
3.  O nome base do arquivo de origem com a extensão .PCH  
  
 Para as opções \/Yc e \/Yu, se nenhuma das duas opções de compilação nem o pragma **hdrstop** especificar um nome de arquivo, o nome base do arquivo de origem será usado como o nome base do arquivo de cabeçalho pré\-compilado.  
  
 Você também pode usar comandos de pré\-processamento para executar a substituição de macros, da seguinte maneira:  
  
```  
#define INCLUDE_PATH "c:\\progra~`1\\devstsu~1\\vc\\include\\"  
#define PCH_FNAME "PROG.PCH"  
.  
.  
.  
#pragma hdrstop( INCLUDE_PATH PCH_FNAME )  
```  
  
 As seguintes regras orientam onde o pragma **hdrstop** pode ser colocado:  
  
-   Deve aparecer fora de qualquer declaração ou definição de dados ou de função.  
  
-   Deve ser especificado no arquivo de origem, e não em um arquivo de cabeçalho.  
  
## Exemplo  
  
```  
#include <windows.h>                 // Include several files  
#include "myhdr.h"  
  
__inline Disp( char *szToDisplay )   // Define an inline function  
{  
    ...                              // Some code to display string  
}  
#pragma hdrstop  
```  
  
 Nesse exemplo, o pragma **hdrstop** aparece depois que dois arquivos foram incluídos e uma função embutida foi definida.  Inicialmente, isso pode parecer um posicionamento estranho para o pragma.  Porém, considere que, usando as opções de pré\-compilação manual, \/Yc e \/Yu, com o pragma **hdrstop**, você pode pré\-compilar arquivos de origem inteiros — incluindo até o código embutido.  Com o compilador da Microsoft, você não está limitado a pré\-compilar somente declarações de dados.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)