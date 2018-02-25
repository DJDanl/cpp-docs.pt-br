---
title: hdrstop | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- hdrstop_CPP
- vc-pragma.hdrstop
dev_langs:
- C++
helpviewer_keywords:
- hdrstop pragma
- pragmas, hdrstop
ms.assetid: 5ea8370a-10d1-4538-ade6-4c841185da0e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 18216663524c48e4ec4ee327ff096c8b3dbd391c
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="hdrstop"></a>hdrstop
Fornece controle adicional sobre nomes de arquivo de pré-compilação e sobre o local em que o estado da compilação é salvo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma hdrstop [( "filename" )]    
```  
  
## <a name="remarks"></a>Comentários  
 O *filename* é o nome do arquivo de cabeçalho pré-compilado para usar ou criar (dependendo se [/Yu](../build/reference/yu-use-precompiled-header-file.md) ou [/Yc](../build/reference/yc-create-precompiled-header-file.md) for especificado). Se *filename* não contém uma especificação de caminho, o arquivo de cabeçalho pré-compilado devem para estar no mesmo diretório que o arquivo de origem.  
  
 Se um arquivo C ou C++ contém uma **hdrstop** pragma quando compilado com /Yc, o compilador salva o estado da compilação até o local do pragma. O estado compilado de todo o código que se segue ao pragma não é salvo.  
  
 Use *filename* para nomear o arquivo de cabeçalho pré-compilado no qual o estado compilado é salvo. Um espaço entre **hdrstop** e *filename* é opcional. O nome de arquivo especificado no **hdrstop** pragma é uma cadeia de caracteres e, portanto, está sujeito às restrições de qualquer cadeia de caracteres C ou C++. Em particular, você deve colocá-lo entre aspas e usar o caractere de escape (barra invertida) para especificar nomes de diretório. Por exemplo:  
  
```  
#pragma hdrstop( "c:\\projects\\include\\myinc.pch" )  
```  
  
 O nome do arquivo de cabeçalho pré-compilado é determinado de acordo com as regras a seguir, em ordem de precedência:  
  
1.  O argumento da opção de compilador /Fp  
  
2.  O *filename* argumento #**pragma hdrstop**  
  
3.  O nome base do arquivo de origem com a extensão .PCH  
  
 Para as opções de /Yc e /Yu, se nenhuma das opções de dois compilação nem o **hdrstop** pragma Especifica um nome de arquivo, o nome base do arquivo de origem é usado como o nome base do arquivo de cabeçalho pré-compilado.  
  
 Você também pode usar comandos de pré-processamento para executar a substituição de macros, da seguinte maneira:  
  
```  
#define INCLUDE_PATH "c:\\progra~`1\\devstsu~1\\vc\\include\\"  
#define PCH_FNAME "PROG.PCH"  
.  
.  
.  
#pragma hdrstop( INCLUDE_PATH PCH_FNAME )  
```  
  
 As regras a seguir determinam onde o **hdrstop** pragma pode ser colocado:  
  
-   Deve aparecer fora de qualquer declaração ou definição de dados ou de função.  
  
-   Deve ser especificado no arquivo de origem, e não em um arquivo de cabeçalho.  
  
## <a name="example"></a>Exemplo  
  
```  
#include <windows.h>                 // Include several files  
#include "myhdr.h"  
  
__inline Disp( char *szToDisplay )   // Define an inline function  
{  
    ...                              // Some code to display string  
}  
#pragma hdrstop  
```  
  
 Neste exemplo, o **hdrstop** pragma aparece depois de dois arquivos foram incluídos e uma função embutida foi definida. Inicialmente, isso pode parecer um posicionamento estranho para o pragma. No entanto, considere que o uso de opções de pré-compilação manuais, /Yc e /Yu, com o **hdrstop** pragma possibilita pré-compilar os arquivos de origem inteiro — mesmo código embutido. Com o compilador da Microsoft, você não está limitado a pré-compilar somente declarações de dados.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)