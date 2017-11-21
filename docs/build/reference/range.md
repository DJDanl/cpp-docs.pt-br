---
title: -O INTERVALO | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /RANGE
dev_langs: C++
helpviewer_keywords:
- /RANGE dumpbin option
- -RANGE dumpbin option
ms.assetid: 7eeba266-32be-49cc-a350-96bdf541f98a
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2558beae1a7bd689beba001f4637b1109b70faa5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="range"></a>/RANGE
Modifica a saída de dumpbin quando usada com outras opções de dumpbin, como /RAWDATA ou /DISASM.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/RANGE:vaMin[,vaMax]  
```  
  
## <a name="flags"></a>Sinalizadores  
 **vaMin**  
 O endereço virtual no qual você deseja que a operação de dumpbin para começar.  
  
 **vaMax** (opcional)  
 O endereço virtual no qual você deseja que a operação de dumpbin para terminar. Se não for especificado, dumpbin irá para o final do arquivo.  
  
## <a name="remarks"></a>Comentários  
 Para ver os endereços virtuais para uma imagem, use o arquivo de mapa da imagem (RVA + Base), o **/DISASM** ou **/HEADERS** opção de dumpbin ou a janela de desmontagem no depurador do Visual Studio.  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, **/faixa** é usado para modificar a exibição do **/disasm** opção. Neste exemplo, o valor inicial é expresso como um número decimal e o valor final é especificado como um número hexadecimal.  
  
```  
dumpbin /disasm /range:4219334,0x004061CD t.exe  
```  
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)