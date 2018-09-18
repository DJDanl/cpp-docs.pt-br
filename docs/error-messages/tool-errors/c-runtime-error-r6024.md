---
title: C R6024 de erro de tempo de execução | Microsoft Docs
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
ms.openlocfilehash: 10b258b12bb1ad7e47a7b126b8fd503814186645
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46041591"
---
# <a name="c-runtime-error-r6024"></a>C R6024 de erro de tempo de execução

Não há espaço suficiente para a tabela de OnExit

> [!NOTE]
>  Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Esse erro geralmente é causado por uma condição de memória extremamente baixa, ou raramente, por um bug no programa ou por danos das bibliotecas do Visual C++ que ele usa.
>
>  Você pode tentar corrigir esse erro com estas etapas:
>
>  -   Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> -   Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> -   Use o **aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar todas as cópias do Microsoft Visual C++ redistribuível.
> -   Verifique **Windows Update** na **painel de controle** para atualizações de software.
> -   Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Esse erro ocorre porque não havia nenhuma memória disponível para o `_onexit` ou `atexit` função. Esse erro é causado por uma condição de pouca memória. Você pode considerar a pré-alocação de buffers na inicialização do aplicativo para ajudar a salvar os dados de usuário e executar um aplicativo limpo sair em condições de pouca memória.