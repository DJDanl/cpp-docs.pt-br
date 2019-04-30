---
title: Compilador aviso (nível 1) C4819
ms.date: 04/08/2019
f1_keywords:
- C4819
helpviewer_keywords:
- C4819
ms.assetid: c0316e85-249c-414d-9df0-622d077c6bc2
ms.openlocfilehash: d43b49d473e7113d8cdfb89aaa6e93045e13d0f7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406308"
---
# <a name="compiler-warning-level-1-c4819"></a>Compilador aviso (nível 1) C4819

> O arquivo contém um caractere que não pode ser representado na página de código atual (*número*). Salve o arquivo no formato Unicode para evitar a perda de dados.

C4819 ocorre quando você compila um arquivo de origem ANSI em um sistema usando uma página de código que não pode representar todos os caracteres no arquivo.

Há várias maneiras de resolver C4819. É uma maneira simples remover o caractere incorreto, se você não precisar dele, por exemplo, se ele estiver em um comentário. Você pode definir a página de código do sistema no painel de controle para um que suporte o conjunto de caracteres usado pelo seu código-fonte. Você pode usar o Unicode [sequências de escape](/cpp/c-language/escape-sequences) para criar caracteres ou cadeias de caracteres que usam apenas o básico ANSI do conjunto de caracteres no seu código-fonte. Por fim, você pode salvar o arquivo em um formato Unicode com uma assinatura, também conhecido como uma marca de ordem de byte (BOM).

Para salvar um arquivo em formato Unicode, no Visual Studio, escolha **arquivo** > **Salvar como**. No **salvar arquivo como** caixa de diálogo, selecione na lista suspensa na **salve** botão e escolha **salvar com codificação**. Se você salvar o mesmo nome de arquivo, você precisará confirmar que você deseja substituir o arquivo. No **opções avançadas de salvamento** caixa de diálogo, escolha uma codificação que pode representar todos os caracteres no arquivo — por exemplo, **Unicode (UTF-8 com assinatura) - página de código 65001**— e, em seguida, escolha  **Okey**.