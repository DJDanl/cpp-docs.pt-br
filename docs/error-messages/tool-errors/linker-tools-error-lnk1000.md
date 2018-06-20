---
title: Ferramentas de vinculador LNK1000 erro | Microsoft Docs
ms.custom: ''
ms.date: 06/18/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1000
dev_langs:
- C++
helpviewer_keywords:
- LNK1000
ms.assetid: 86421b9a-460a-4285-8dce-9b8257d78122
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7a01db36200995813ec4b6862e9ddd04c6f069ba
ms.sourcegitcommit: d06966efce25c0e66286c8047726ffe743ea6be0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/19/2018
ms.locfileid: "36238676"
---
# <a name="linker-tools-error-lnk1000"></a>Erro das Ferramentas de Vinculador LNK1000

> Erro desconhecido; Consulte a documentação para opções de suporte técnico

Observe as circunstâncias do erro, em seguida, tente isolar o problema e criar um caso de teste pode ser reproduzido. Para obter informações sobre como investigar e relatar esses erros, consulte [como relatar um problema com o conjunto de ferramentas do Visual C++ ou documentação](../../how-to-report-a-problem-with-the-visual-cpp-toolset.md).

Você pode obter esse erro se você mesclar arquivos de cabeçalho padrão (por exemplo, Windows. h) e seus próprios arquivos. Inclua um cabeçalho pré-compilado, se qualquer um, e, depois, os cabeçalhos padrão, seguido por seus próprios arquivos de cabeçalho.