---
title: Linha de comando D9025 de aviso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: D9025
dev_langs: C++
helpviewer_keywords: D9025
ms.assetid: 6edff72c-1508-46c2-99f4-0e4b3c5e60c9
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d95c4c16b472f0e1b37a981df7f73ff573d06447
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="command-line-warning-d9025"></a>Aviso D9025 (linha de comando)
substituindo a opção ' 1' com 'option2'  
  
 O *opção 1* opção foi especificada, mas, em seguida, foi substituída pelo *option2*. O *option2* opção foi usada.  
  
 Se duas opções especificam diretivas contraditórias ou incompatíveis, a diretiva especificada ou implícita na opção mais à direita na linha de comando é usada.  
  
 Se você receber esse aviso durante a compilação do ambiente de desenvolvimento e não estiver certo de que as opções conflitantes são provenientes, considere o seguinte:  
  
-   Uma opção pode ser especificada no código ou nas configurações de projeto do projeto. Se você observar o compilador [páginas de propriedade de linha de comando](../../ide/command-line-property-pages.md) e se você ver as opções conflitantes no **todas as opções** , em seguida, as opções são definidas nas páginas de propriedades do projeto, caso contrário, as opções de campo são definidos no código-fonte.  
  
     Se as opções são definidas nas páginas de propriedades do projeto, procure na página de propriedade de pré-processador do compilador (com o nó do projeto selecionado no Gerenciador de soluções).  Se você não vir a opção definido lá, verifique as configurações de página de propriedade pré-processador para cada arquivo de código fonte (no Gerenciador de soluções) para verificar se ele não é adicionado existe.  
  
     Se as opções são definidas no código pode ser definida no código ou nos cabeçalhos do windows.  Você pode tentar criar um arquivo pré-processados ([/p](../../build/reference/p-preprocess-to-a-file.md)) e pesquisá-lo para o símbolo.