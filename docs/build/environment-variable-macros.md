---
title: "Macros de variável de ambiente | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, environment variable macros
- environment variables, macros in NMAKE
- macros, environment-variable
ms.assetid: f8e96635-0906-47b0-9f56-12a6fdf5e347
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 69fae15b7a12d990d2fb2c8e457bfdc0407f7702
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="environment-variable-macros"></a>Macros de variável de ambiente
NMAKE herda as definições de macro para variáveis de ambiente que existem antes do início da sessão. Se uma variável foi definida no ambiente de sistema operacional, ele está disponível como uma macro NMAKE. Os nomes herdados são convertidos em maiusculas. Herança ocorre antes de pré-processamento. Use a opção /E para fazer com que as macros herdadas de variáveis de ambiente para substituir todas as macros com o mesmo nome no makefile.  
  
 Macros de variável de ambiente podem ser redefinidas na sessão, e isso altera a variável de ambiente correspondente. Você também pode alterar as variáveis de ambiente com o comando SET. Usando o comando SET para alterar uma variável de ambiente em uma sessão não altera a macro correspondente, no entanto.  
  
 Por exemplo:  
  
```  
PATH=$(PATH);\nonesuch  
  
all:  
    echo %PATH%  
```  
  
 Neste exemplo, a alteração `PATH` altera a variável de ambiente correspondente `PATH`; ele anexa `\nonesuch` ao seu caminho.  
  
 Se uma variável de ambiente é definida como uma cadeia de caracteres que seria sintaticamente incorreta em um makefile, nenhuma macro é criada e nenhum aviso é gerado. Se o valor da variável contém um sinal de cifrão ($), NMAKE interpretará como o início de uma invocação de macro. Usando a macro pode causar um comportamento inesperado.  
  
## <a name="see-also"></a>Consulte também  
 [Macros NMAKE especiais](../build/special-nmake-macros.md)