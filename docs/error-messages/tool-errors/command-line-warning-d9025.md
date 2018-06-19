---
title: Linha de comando D9025 de aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D9025
dev_langs:
- C++
helpviewer_keywords:
- D9025
ms.assetid: 6edff72c-1508-46c2-99f4-0e4b3c5e60c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3875a2cbd065fd5ad887267bcc80748fa9845d0d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33298844"
---
# <a name="command-line-warning-d9025"></a>Aviso D9025 (linha de comando)
substituindo a opção ' 1' com 'option2'  
  
 O *opção 1* opção foi especificada, mas, em seguida, foi substituída pelo *option2*. O *option2* opção foi usada.  
  
 Se duas opções especificam diretivas contraditórias ou incompatíveis, a diretiva especificada ou implícita na opção mais à direita na linha de comando é usada.  
  
 Se você receber esse aviso durante a compilação do ambiente de desenvolvimento e não estiver certo de que as opções conflitantes são provenientes, considere o seguinte:  
  
-   Uma opção pode ser especificada no código ou nas configurações de projeto do projeto. Se você observar o compilador [páginas de propriedade de linha de comando](../../ide/command-line-property-pages.md) e se você ver as opções conflitantes no **todas as opções** , em seguida, as opções são definidas nas páginas de propriedades do projeto, caso contrário, as opções de campo são definidos no código-fonte.  
  
     Se as opções são definidas nas páginas de propriedades do projeto, procure na página de propriedade de pré-processador do compilador (com o nó do projeto selecionado no Gerenciador de soluções).  Se você não vir a opção definido lá, verifique as configurações de página de propriedade pré-processador para cada arquivo de código fonte (no Gerenciador de soluções) para verificar se ele não é adicionado existe.  
  
     Se as opções são definidas no código pode ser definida no código ou nos cabeçalhos do windows.  Você pode tentar criar um arquivo pré-processados ([/p](../../build/reference/p-preprocess-to-a-file.md)) e pesquisá-lo para o símbolo.