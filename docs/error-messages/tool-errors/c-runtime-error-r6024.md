---
title: Erro em tempo de execução de C R6024
ms.date: 11/04/2016
f1_keywords:
- R6024
helpviewer_keywords:
- R6024
ms.assetid: 0fb11c0f-9b81-4cab-81bd-4785742946a5
ms.openlocfilehash: 89b99a93512603eaf2273a6ff3f434f1ad3b3bb8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62214101"
---
# <a name="c-runtime-error-r6024"></a>Erro em tempo de execução de C R6024

Não há espaço suficiente para a tabela de OnExit

> [!NOTE]
> Se você encontrar esta mensagem de erro durante a execução de um aplicativo, o aplicativo foi encerrado porque ele tem um problema de memória interna. Esse erro geralmente é causado por uma condição de memória extremamente baixa, ou raramente, por um bug no programa ou por danos das bibliotecas do Visual C++ que ele usa.
>
> Você pode tentar corrigir esse erro com estas etapas:
>
> - Feche outros aplicativos em execução ou reinicie o computador para liberar memória.
> - Use o **aplicativos e recursos** ou **programas e recursos** página o **painel de controle** para reparar ou reinstalar o programa.
> - Use o **aplicativos e recursos** ou **programas e recursos** página de **painel de controle** para reparar ou reinstalar todas as cópias do Microsoft Visual C++ redistribuível.
> - Verifique **Windows Update** na **painel de controle** para atualizações de software.
> - Verifique se há uma versão atualizada do aplicativo. Se o problema persistir, entre em contato com o fornecedor do aplicativo.

**Informações para programadores**

Esse erro ocorre porque não havia nenhuma memória disponível para o `_onexit` ou `atexit` função. Esse erro é causado por uma condição de pouca memória. Você pode considerar a pré-alocação de buffers na inicialização do aplicativo para ajudar a salvar os dados de usuário e executar um aplicativo limpo sair em condições de pouca memória.