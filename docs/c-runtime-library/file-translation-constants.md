---
title: "Constantes de translação de arquivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.constants.file
dev_langs:
- C++
helpviewer_keywords:
- translation constants
- file translation [C++], constants
- translation, file translation constants
- translation, constants
- constants [C++], file translation mode
- file translation [C++]
ms.assetid: 49b13bf3-442e-4d19-878b-bd1029fa666a
caps.latest.revision: 6
author: corob-msft
ms.author: corob
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: c4a695e18c138a0a526c00bb42a92af7b88cb227
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="file-translation-constants"></a>Constantes de translação de arquivo
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <stdio.h>  
```  
  
## <a name="remarks"></a>Comentários  
 Essas constantes especificam o modo de translação (**"b"** ou **"t"**). O modo é incluído na cadeia de caracteres que especifica o tipo de acesso (**"r"**, **"w"**, **"a"**, **"r +"**, **"w +"**, **"+"**).  
  
 Os modos de translação são os seguintes:  
  
 **t**  
 Abre no modo de texto (convertido). Neste modo, combinações de CR-LF (retorno de carro/avanço de linha) são convertidas em LFs (avanços de linha) simples na entrada e caracteres de LF são convertidos em combinações de CR-LF na saída. Além disso, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura ou leitura/gravação, `fopen` verifica se há um CTRL+Z no fim do arquivo e o remove, se possível. Isso é feito porque usar as funções `fseek` e `ftell` para movimentação dentro de um arquivo que termina com CTRL+Z poderá fazer o `fseek` se comportar incorretamente perto do fim do arquivo.  
  
> [!NOTE]
>  A opção **t** não faz parte do padrão ANSI para `fopen` e `freopen`. Trata-se de uma extensão da Microsoft e não deve ser usada quando se desejar portabilidade ANSI.  
  
 **b**  
 Abre no modo binário (não convertido). As translações acima são suprimidas.  
  
 Se **t** ou **b** não for informado em *mode*, o modo de translação será definido pela variável de modo padrão [_fmode](../c-runtime-library/fmode.md). Para obter mais informações sobre o uso dos modos de texto e binário, consulte [E/S de arquivo em modo de texto e binário](../c-runtime-library/text-and-binary-mode-file-i-o.md).  
  
## <a name="see-also"></a>Consulte também  
 [_fdopen, _wfdopen](../c-runtime-library/reference/fdopen-wfdopen.md)   
 [fopen, _wfopen](../c-runtime-library/reference/fopen-wfopen.md)   
 [freopen, _wfreopen](../c-runtime-library/reference/freopen-wfreopen.md)   
 [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)
