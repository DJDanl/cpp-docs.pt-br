---
title: "Especificadores de classe de armazenamento com declarações de função | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- function specifiers, storage class
- declaring functions, specifiers
- external declarations
- specifiers, function
- external linkage, function declarations
- external linkage, storage-class specifiers
ms.assetid: 801d7df2-efa9-4924-a725-274a5654cfd4
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f7d8b6ba1c0287492195ee891b1a573bf74de6cf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="storage-class-specifiers-with-function-declarations"></a>Especificadores de classe de armazenamento com declarações de função
Você pode usar ou o especificador **static** ou de classe de armazenamento `extern` em declarações de função. As funções sempre têm tempos de vida globais.  
  
 **Seção específica da Microsoft**  
  
 As declarações de função no nível interno têm o mesmo significado que as declarações de função no nível externo. Isso significa que uma função é visível do ponto de declaração durante o restante da unidade de conversão mesmo que seja declarada no escopo local.  
  
 **Fim da seção específica da Microsoft**  
  
 As regras de visibilidade para funções variam ligeiramente das regras para as variáveis, como segue:  
  
-   Uma função declarada como **static** só é visível no arquivo de origem em que é definida. As funções no mesmo arquivo de origem podem chamar a função **static**, mas as funções em outros arquivos de origem não podem acessá-la diretamente pelo nome. Você pode declarar outra função **static** com o mesmo nome em outro arquivo de origem sem conflito.  
  
-   As funções declaradas como `extern` são visíveis nos arquivos de origem do programa (a menos que você redeclare posteriormente tal função como **static**). Qualquer função pode chamar uma função `extern`.  
  
-   As declarações de função que omitem o especificador de classe de armazenamento são `extern` por padrão.  
  
 **Seção específica da Microsoft**  
  
 A Microsoft permite a redefinição de um identificador `extern` como **static**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classes de armazenamento C](../c-language/c-storage-classes.md)