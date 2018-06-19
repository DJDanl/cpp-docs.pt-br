---
title: Função exit | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- Exit
dev_langs:
- C++
helpviewer_keywords:
- exit function
ms.assetid: 26ce439f-81e2-431c-9ff8-a09a96f32127
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5767f6b08b4adcd3d1a8d367c6286a746eeecec3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32412524"
---
# <a name="exit-function"></a>Função exit
O **sair** função, declarada no arquivo de inclusão padrão \<stdlib.h >, encerra um programa C++.  
  
 O valor fornecido como um argumento para **sair** é retornado para o sistema operacional como o código de saída ou de código de retorno do programa. Por convenção, um código de retorno de zero indica que o programa foi encerrado com êxito.  
  
> [!NOTE]
>  Você pode usar as constantes `EXIT_FAILURE` e `EXIT_SUCCESS`, definido em \<stdlib.h >, para indicar êxito ou falha do programa.  
  
 Emitir um `return` instrução from a **principal** função é equivalente a chamar o **sair** função com valor de retorno como seu argumento.  
  
 Para obter mais informações, consulte [sair](../c-runtime-library/reference/exit-exit-exit.md) no *referência da biblioteca de tempo de execução*.  
  
## <a name="see-also"></a>Consulte também  
 [Término do programa](../cpp/program-termination.md)