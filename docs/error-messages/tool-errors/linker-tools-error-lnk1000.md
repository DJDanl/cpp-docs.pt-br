---
title: Erro das Ferramentas de Vinculador LNK1000
ms.date: 06/18/2018
f1_keywords:
- LNK1000
helpviewer_keywords:
- LNK1000
ms.assetid: 86421b9a-460a-4285-8dce-9b8257d78122
ms.openlocfilehash: 48b976f6e996d0e076849dc9b20b4cedd47dfbcd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195416"
---
# <a name="linker-tools-error-lnk1000"></a>Erro das Ferramentas de Vinculador LNK1000

> erro desconhecido; consulte a documentação para obter opções de suporte técnico

Observe as circunstâncias do erro e tente isolar o problema e criar um caso de teste reproduzível. Para obter informações sobre como investigar e relatar esses erros, consulte [como relatar um problema com o conjunto de C++ ferramentas ou a documentação do Visual](../../overview/how-to-report-a-problem-with-the-visual-cpp-toolset.md).

Você poderá receber esse erro se misturar arquivos de cabeçalho padrão (por exemplo, Windows. h) e seus próprios arquivos. Inclua um cabeçalho pré-compilado, se houver, primeiro, os cabeçalhos padrão, seguidos por seus próprios arquivos de cabeçalho.
