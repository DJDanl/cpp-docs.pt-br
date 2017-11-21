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
ms.openlocfilehash: ea22f9462ee674610ae3bbd2a55d86a048a63c83
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4819"></a>Compilador C4819 de aviso (nível 1)
O arquivo contém um caractere que não pode ser representado na página de código atual (número). Salve o arquivo no formato Unicode para evitar a perda de dados.  
  
 C4819 ocorre quando um arquivo de origem ANSI é compilado em um sistema com uma página de código que não pode representar todos os caracteres no arquivo.  
  
 Para resolver C4819, salve o arquivo no formato Unicode. No Visual Studio, escolha **arquivo**, **opções avançadas de salvar**. No **opções avançadas de salvar** caixa de diálogo, selecione uma codificação que podem representar todos os caracteres no arquivo — por exemplo, UTF-8 — e, em seguida, escolha **Okey**.