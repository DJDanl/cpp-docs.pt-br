---
title: Definindo opções de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- files [C++], LINK
- input files [C++], linker
- linker [C++], ways to set options
- linker [C++], switches
- input files [C++]
- object/library modules
ms.assetid: e08fb487-0f2e-4f24-87db-232dbc8bd2e2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 18728994be3f44152a263fb8a6009728e33a42a0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="setting-linker-options"></a>Definindo opções de vinculador
Opções do vinculador podem ser definidas dentro ou fora do ambiente de desenvolvimento. O tópico de cada opção de vinculador discute como ele pode ser definido no ambiente de desenvolvimento. Consulte [opções do vinculador](../../build/reference/linker-options.md) para obter uma lista completa.  
  
 Quando você executa o vínculo fora do ambiente de desenvolvimento, você pode especificar a entrada de uma ou mais formas:  
  
-   Sobre o [linha de comando](../../build/reference/linker-command-line-syntax.md)  
  
-   Usando [arquivos de comando](../../build/reference/link-command-files.md)  
  
-   Em [variáveis de ambiente](../../build/reference/link-environment-variables.md)  
  
 Opções de processos primeiro LINK especificado na variável de ambiente LINK, seguido pelas opções na ordem em que elas são especificadas na linha de comando e nos arquivos de comando. Se uma opção é repetida com argumentos diferentes, o último deles processados terá precedência.  
  
 Opções se aplicam à compilação de inteiro; Não há opções podem ser aplicadas aos arquivos de entrada específicos.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de build do C/C++](../../build/reference/c-cpp-building-reference.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)