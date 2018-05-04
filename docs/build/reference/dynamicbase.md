---
title: -DYNAMICBASE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /dynamicbase
dev_langs:
- C++
helpviewer_keywords:
- -DYNAMICBASE editbin option
- DYNAMICBASE editbin option
- /DYNAMICBASE editbin option
ms.assetid: edb3df90-7b07-42fb-a94a-f5a4c1d325d6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d7a4cf7aa35d7ad6b41fc6d61f3f27662ae2c8d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="dynamicbase"></a>/DYNAMICBASE
Especifica se uma imagem executável pode ser baseada aleatoriamente de novo no tempo de carregamento usando aleatória de layout de espaço de endereço (ASLR).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
/DYNAMICBASE[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, o vinculador define o **/DYNAMICBASE** opção.  
  
 Esta opção modifica o cabeçalho de uma imagem executável para indicar se o carregador pode rebase aleatoriamente a imagem no tempo de carregamento.  
  
 ASLR é suportado no Windows Vista, Windows Server 2008, Windows 7, Windows 8 e Windows Server 2012.  
  
## <a name="see-also"></a>Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)   
 [Defesas de segurança do Windows Software ISV](http://msdn.microsoft.com/library/bb430720.aspx)