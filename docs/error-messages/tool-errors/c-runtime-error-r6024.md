---
title: R6024 de erro de tempo de execução C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- R6024
dev_langs:
- C++
helpviewer_keywords:
- R6024
ms.assetid: 0fb11c0f-9b81-4cab-81bd-4785742946a5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bcdfee9da378415afe0b88fe6eed18ec8f570d4a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302705"
---
# <a name="c-runtime-error-r6024"></a>R6024 de erro de tempo de execução do C
Não há espaço suficiente para a tabela OnExit/atexit  
  
> [!NOTE]
>  Se você receber essa mensagem de erro durante a execução de um aplicativo, o aplicativo foi desligado porque ele tem um problema de memória interna. Esse erro geralmente é causado por uma condição de memória muito baixa, ou raramente, por um bug no programa ou por danos das bibliotecas do Visual C++ que ele usa.  
>   
>  Você pode tentar corrigir esse erro com estas etapas:  
>   
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.  
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar todas as cópias do Microsoft Visual C++ redistribuível.  
> -   Verificar **Windows Update** no **painel de controle** para atualizações de software.  
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.  
  
 **Informações para os programadores**  
  
 Esse erro ocorre porque não havia nenhuma memória disponível para o `_onexit` ou `atexit` função. Este erro é causado por uma condição de memória insuficiente. Você pode considerar pré-alocação de buffers na inicialização do aplicativo para ajudar a salvar os dados de usuário e executar um aplicativo normal de saída em condições de pouca memória.