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
ms.openlocfilehash: ce4272ecfee4b3d02d8bf79f7816200a392c9735
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39404818"
---
# <a name="exit-function"></a>Função exit
O **saia** função, declarada no arquivo de inclusão padrão \<stdlib. h >, encerra um programa C++.  
  
 O valor fornecido como um argumento para **sair** é retornado para o sistema operacional como código retorno de código ou sair do programa. Por convenção, um código de retorno de zero indica que o programa foi encerrado com êxito.  
  
> [!NOTE]
>  Você pode usar as constantes EXIT_FAILURE e EXIT_SUCCESS, definido em \<stdlib. h >, para indicar êxito ou falha do programa.  
  
 Emitir uma **retornar** instrução from a `main` função é equivalente a chamar o **sair** função com o valor de retorno como seu argumento.  
  
 Para obter mais informações, consulte [saia](../c-runtime-library/reference/exit-exit-exit.md) na *referência de biblioteca de tempo de execução*.  
  
## <a name="see-also"></a>Consulte também  
 [Término do programa](../cpp/program-termination.md)