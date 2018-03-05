---
title: "-Zc: auto (deduzir tipo variável) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /Zc:auto
dev_langs:
- C++
helpviewer_keywords:
- -Zc compiler options (C++)
- Deduce variable type (C++)
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 5f5bc102-44c3-4688-bbe1-080594dcee5c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dd2f0ff353e1243685c94da0c28f29e810b2a9ef
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zcauto-deduce-variable-type"></a>/Zc:auto (deduzir tipo variável)
O **/ZC: auto [-]** opção de compilador informa ao compilador como usar o [palavra-chave auto](../../cpp/auto-keyword.md) para declarar variáveis. Se você especificar a opção padrão, **/ZC: auto**, o compilador deduz o tipo da variável declarada de sua expressão de inicialização. Se você especificar **/Zc:auto-**, o compilador aloca a variável para a classe de armazenamento automático.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zc:auto[-]  
```  
  
## <a name="remarks"></a>Comentários  
 O padrão C++ define um significado original e um significado revisado para a palavra-chave `auto`. Antes de [!INCLUDE[cpp_dev10_long](../../build/includes/cpp_dev10_long_md.md)], a palavra-chave declara uma variável na classe de armazenamento automático; ou seja, uma variável que tem um tempo de vida de local. Começando com [!INCLUDE[cpp_dev10_long](../../build/includes/cpp_dev10_long_md.md)], a palavra-chave deduz o tipo de uma variável da expressão de inicialização da declaração. Use o **/ZC: auto [-]** opção de compilador para informar ao compilador para usar o significado original ou revisado o `auto` palavra-chave.  
  
 O compilador emite uma mensagem de diagnóstico pertinente se o uso da palavra-chave `auto` for contrário à opção atual do compilador. Para obter mais informações, consulte [palavra-chave auto](../../cpp/auto-keyword.md). Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).  
  
### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **propriedades de configuração** nó.  
  
3.  Clique o **C/C++** nó.  
  
4.  Clique o **linha de comando** nó.  
  
5.  Adicionar **/ZC: auto** ou **/Zc:auto-** para o **opções adicionais:** painel.  
  
## <a name="see-also"></a>Consulte também  
 [/ZC (conformidade)](../../build/reference/zc-conformance.md)   
 [Palavra-chave auto](../../cpp/auto-keyword.md)