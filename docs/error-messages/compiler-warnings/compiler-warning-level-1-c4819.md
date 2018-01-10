---
title: "Compilador (nível 1) de aviso C4819 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4819
dev_langs: C++
helpviewer_keywords: C4819
ms.assetid: c0316e85-249c-414d-9df0-622d077c6bc2
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b515a3f5e840bbc93f37420866023ee778b404ee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4819"></a>Compilador C4819 de aviso (nível 1)
O arquivo contém um caractere que não pode ser representado na página de código atual (número). Salve o arquivo no formato Unicode para evitar a perda de dados.  
  
 C4819 ocorre quando um arquivo de origem ANSI é compilado em um sistema com uma página de código que não pode representar todos os caracteres no arquivo.  
  
 Para resolver C4819, salve o arquivo no formato Unicode. No Visual Studio, escolha **arquivo**, **opções avançadas de salvar**. No **opções avançadas de salvar** caixa de diálogo, selecione uma codificação que podem representar todos os caracteres no arquivo — por exemplo, UTF-8 — e, em seguida, escolha **Okey**.