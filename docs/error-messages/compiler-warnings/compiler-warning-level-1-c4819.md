---
title: Compilador aviso (nível 1) C4819
ms.date: 11/04/2016
f1_keywords:
- C4819
helpviewer_keywords:
- C4819
ms.assetid: c0316e85-249c-414d-9df0-622d077c6bc2
ms.openlocfilehash: c0ca29a304fbd05cb0c6b7d1b06414304c70fb2a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50596606"
---
# <a name="compiler-warning-level-1-c4819"></a>Compilador aviso (nível 1) C4819

O arquivo contém um caractere que não pode ser representado na página de código atual (número). Salve o arquivo no formato Unicode para evitar a perda de dados.

C4819 ocorre quando um arquivo de origem ANSI é compilado em um sistema com uma página de código que não pode representar todos os caracteres no arquivo.

Para resolver C4819, salve o arquivo no formato Unicode. No Visual Studio, escolha **arquivo**, **opções avançadas de salvamento**. No **opções avançadas de salvamento** caixa de diálogo, selecione uma codificação que pode representar todos os caracteres no arquivo — por exemplo, UTF-8 — e, em seguida, escolha **Okey**.