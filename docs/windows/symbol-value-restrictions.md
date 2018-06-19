---
title: Restrições de valor do símbolo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.symbol.restrictions.value
dev_langs:
- C++
helpviewer_keywords:
- symbols, value restrictions
- restrictions, symbol values
ms.assetid: 32467ec3-690b-4cd0-a4d0-7d189a3296cb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3432ca82d9557fbcb47da65be148bedb0f47f8b8
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889532"
---
# <a name="symbol-value-restrictions"></a>Restrições de valor do símbolo
Um valor de símbolo pode ser qualquer inteiro expressado da maneira normal para #define as diretivas de pré-processamento. Aqui estão alguns exemplos de valores de símbolo:  
  
```  
18  
4001  
0x0012  
-3456  
```  
  
 Valores de símbolo de recursos (aceleradores, bitmaps, cursores, caixas de diálogo, ícones, menus, tabelas de cadeia de caracteres e informações de versão) devem ser números decimais no intervalo entre 0 e 32.767 (mas não podem ser hexadecimais). Valores de símbolo para partes de recursos, como controles de caixa de diálogo ou cadeias de caracteres individuais na tabela de cadeia de caracteres, podem ser de 0 a 65.534 ou de -32.768 a 32.767.  
  
 Símbolos de recurso são números de 16 bits. Você pode inseri-las como sinal ou, no entanto, eles são usados internamente como números inteiros sem sinal. Números negativos assim serão convertidos em seu valor positivo correspondente.  
  
 Aqui estão algumas limitações de valores de símbolo:  
  
-   O ambiente de desenvolvimento do Visual Studio e MFC usam alguns intervalos de números para fins especiais. Todos os números com o conjunto de bits mais significativo (-32.768 a -1 ou 32.768 para 65.534, dependendo da entrada) são reservados pelo MFC.  
  
-   Não é possível definir um valor de símbolo usando outras cadeias de caracteres de símbolo. Por exemplo, não há suporte para a definição de símbolo a seguir:  
  
    ```  
    #define IDC_MYEDIT  IDC_OTHEREDIT  //not supported  
    ```  
  
-   Você não pode usar macros de pré-processador com argumentos como definições de valores. Por exemplo:  
  
    ```  
    #define   IDD_ABOUT  ID(7) //not supported  
    ```  
  
     não é uma expressão válida, independentemente de qual `ID` é avaliada como em tempo de compilação.  
  
-   Seu aplicativo pode ter um arquivo existente que contém os símbolos definidos com expressões. Para obter mais informações sobre como incluir os símbolos como símbolos de somente leitura, consulte [usando compartilhados (somente leitura) ou símbolos calculados](../windows/including-shared-read-only-or-calculated-symbols.md).  
  
 Para obter mais informações sobre intervalos de número, consulte [TN023: recursos MFC padrão](../mfc/tn023-standard-mfc-resources.md).  
  

  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Alterando o valor numérico do símbolo](../windows/changing-a-symbol-s-numeric-value.md)   
 [Restrições de nome de símbolo](../windows/symbol-name-restrictions.md)   
 [IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)