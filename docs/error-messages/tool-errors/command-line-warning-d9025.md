---
title: Linha de comando aviso D9025 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- D9025
dev_langs:
- C++
helpviewer_keywords:
- D9025
ms.assetid: 6edff72c-1508-46c2-99f4-0e4b3c5e60c9
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0087a2721f1aaeb1424a69d1c4333648b0eac43d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="command-line-warning-d9025"></a>Aviso D9025 (linha de comando)
substituindo a opção '&1;' com a opção '2'  
  
 O *opção&1;* opção foi especificada, mas, em seguida, foi substituída pelo *opção&2;*. O *opção&2;* opção foi usada.  
  
 Se duas opções especificam diretivas incompatíveis ou contraditórias, será usada a diretiva especificada ou implícita na opção mais à direita na linha de comando.  
  
 Se você receber esse aviso durante a compilação do ambiente de desenvolvimento e não tiver certeza de onde as opções conflitantes são provenientes de, considere o seguinte:  
  
-   Uma opção pode ser especificada no código ou nas configurações de projeto do projeto. Se você examinar o compilador [páginas de propriedade de linha de comando](../../ide/command-line-property-pages.md) e se você vir as opções conflitantes a **todas as opções de** campo e as opções são definidas nas páginas de propriedades do projeto, caso contrário, as opções são definidas no código-fonte.  
  
     Se as opções são definidas nas páginas de propriedades do projeto, procure na página de propriedade do pré-processador do compilador (com o nó do projeto selecionado no Gerenciador de soluções).  Se você não vir a opção ali definido, verifique as configurações de página de propriedade de pré-processador para cada arquivo de código fonte (no Gerenciador de soluções) para verificar se ele não é adicionado lá.  
  
     Se as opções são definidas no código pode ser configurado no código ou nos cabeçalhos do windows.  Você pode tentar criar um arquivo pré-processado ([/p](../../build/reference/p-preprocess-to-a-file.md)) e pesquisá-lo para o símbolo.
