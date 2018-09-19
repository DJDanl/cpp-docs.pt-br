---
title: Compilador aviso (nível 1) C4819 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4819
dev_langs:
- C++
helpviewer_keywords:
- C4819
ms.assetid: c0316e85-249c-414d-9df0-622d077c6bc2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ac468bc605c261b66f47fdf40efd1a01a5383d58
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46074273"
---
# <a name="compiler-warning-level-1-c4819"></a>Compilador aviso (nível 1) C4819

O arquivo contém um caractere que não pode ser representado na página de código atual (número). Salve o arquivo no formato Unicode para evitar a perda de dados.

C4819 ocorre quando um arquivo de origem ANSI é compilado em um sistema com uma página de código que não pode representar todos os caracteres no arquivo.

Para resolver C4819, salve o arquivo no formato Unicode. No Visual Studio, escolha **arquivo**, **opções avançadas de salvamento**. No **opções avançadas de salvamento** caixa de diálogo, selecione uma codificação que pode representar todos os caracteres no arquivo — por exemplo, UTF-8 — e, em seguida, escolha **Okey**.