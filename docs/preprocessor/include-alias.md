---
title: "include_alias | Microsoft Docs"
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
  - "vc-pragma.include_alias"
  - "include_alias_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "include_alias (pragma)"
  - "pragmas, include_alias"
ms.assetid: 3256d589-12b3-4af0-a586-199e96eabacc
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# include_alias
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica que *short\_filename* deve ser usado como alias para *long\_filename*.  
  
## Sintaxe  
  
```  
  
      #pragma include_alias( "  
      long_filename  
      ", "  
      short_filename  
      " )  
#pragma include_alias( <long_filename>, <short_filename> )  
```  
  
## Comentários  
 Alguns sistemas de arquivos permitem nomes de arquivo de cabeçalho mais longos do que o limite do sistema de arquivos FAT 8.3.  O compilador não pode simplesmente truncar nomes mais longos para 8.3, pois os primeiros oito caracteres dos nomes de arquivos de cabeçalho mais longos podem não ser exclusivos.  Sempre que o compilador encontra a cadeia de caracteres *long\_filename*, ele substitui *short\_filename* e procura o *short\_filename* do arquivo de cabeçalho.  Esse pragma deve aparecer antes das políticas `#include` correspondentes.  Por exemplo:  
  
```  
// First eight characters of these two files not unique.  
#pragma include_alias( "AppleSystemHeaderQuickdraw.h", "quickdra.h" )  
#pragma include_alias( "AppleSystemHeaderFruit.h", "fruit.h" )  
  
#pragma include_alias( "GraphicsMenu.h", "gramenu.h" )  
  
#include "AppleSystemHeaderQuickdraw.h"  
#include "AppleSystemHeaderFruit.h"  
#include "GraphicsMenu.h"  
```  
  
 O alias que está sendo pesquisado deve corresponder exatamente a especificação, na ortografia e no uso de aspas duplas ou colchetes angulares.  O pragma **include\_alias** faz a correspondência simples de cadeia de caracteres nos nomes de arquivos; nenhuma outra validação do nome de arquivo é executada.  Por exemplo, dadas as seguintes políticas,  
  
```  
#pragma include_alias("mymath.h", "math.h")  
#include "./mymath.h"  
#include "sys/mymath.h"  
```  
  
 nenhuma criação de alias \(substituição\) é executada, pois as cadeias de caracteres do arquivo de cabeçalho não correspondem exatamente.  Além disso, os nomes de arquivos de cabeçalho usados como argumentos para as opções do compilador \/Yu e \/Yc, ou o pragma **hdrstop**, não são substituídos.  Por exemplo, se o arquivo de origem contiver a seguinte política,  
  
```  
#include <AppleSystemHeaderStop.h>  
```  
  
 a opção do compilador correspondente deve ser  
  
```  
/YcAppleSystemHeaderStop.h  
```  
  
 Você pode usar o pragma **include\_alias** para mapear qualquer nome de arquivo de cabeçalho para outro.  Por exemplo:  
  
```  
#pragma include_alias( "api.h", "c:\version1.0\api.h" )  
#pragma include_alias( <stdio.h>, <newstdio.h> )  
#include "api.h"  
#include <stdio.h>  
```  
  
 Não misture nomes de arquivos incluídos entre aspas duplas com nomes de arquivos entre colchetes angulares.  Por exemplo, nas duas políticas **\#pragma include\_alias** acima, o compilador não executa nenhuma substituição nas políticas `#include` a seguir:  
  
```  
#include <api.h>  
#include "stdio.h"  
```  
  
 Além disso, a política a seguir gera um erro:  
  
```  
#pragma include_alias(<header.h>, "header.h")  // Error  
```  
  
 Observe que o nome de arquivo relatado nas mensagens de erro, ou como o valor da macro **\_\_FILE\_\_** predefinida, é o nome do arquivo após a substituição ser executada.  Por exemplo, após as seguintes políticas,  
  
```  
#pragma include_alias( "VeryLongFileName.H", "myfile.h" )  
#include "VeryLongFileName.H"  
```  
  
 um erro em VERYLONGFILENAME.H gera a seguinte mensagem de erro:  
  
```  
myfile.h(15) : error C2059 : syntax error  
```  
  
 Observe também que a transitividade não tem suporte.  Dadas as seguintes políticas,  
  
```  
#pragma include_alias( "one.h", "two.h" )  
#pragma include_alias( "two.h", "three.h" )  
#include "one.h"  
```  
  
 o compilador procura pelo arquivo TWO.H em vez de THREE.H.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)