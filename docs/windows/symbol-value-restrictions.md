---
title: Restrições de valor de símbolo | Microsoft Docs
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
ms.openlocfilehash: 1e6b594ad7fe1d805511d5e2cd1b67bd0d791e8e
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40013395"
---
# <a name="symbol-value-restrictions"></a>Restrições de valor do símbolo
Um valor de símbolo pode ser qualquer inteiro expressado da maneira normal para #define as diretivas de pré-processamento. Aqui estão alguns exemplos de valores de símbolo:  
  
```  
18  
4001  
0x0012  
-3456  
```  
  
 Valores de símbolo para os recursos (aceleradores, bitmaps, cursores, caixas de diálogo, ícones, menus, tabelas de cadeia de caracteres e informações de versão) devem ser números decimais no intervalo entre 0 e 32.767 (mas não podem ser hexadecimais). Valores de símbolo para partes de recursos, como controles de caixa de diálogo ou cadeias de caracteres individuais na tabela de cadeia de caracteres, podem ser de 0 a 65.534 ou de -32.768 a 32.767.  
  
 Símbolos de recurso são números de 16 bits. Você pode inseri-las como com ou sem sinal, no entanto, eles são usados internamente como números inteiros sem sinal. Números negativos então serão convertidos em seu valor positivo correspondente.  
  
 Aqui estão algumas limitações de valores de símbolo:  
  
-   O ambiente de desenvolvimento do Visual Studio e o MFC usam alguns intervalos de número para fins especiais. Todos os números com o conjunto de bits mais significativo (-32.768 a -1 ou 32.768 para 65.534, dependendo do sinal) são reservados pelo MFC.  
  
-   Você não pode definir um valor de símbolo usando outras cadeias de caracteres de símbolo. Por exemplo, não há suporte para a definição de símbolo a seguir:  
  
    ```cpp  
    #define IDC_MYEDIT  IDC_OTHEREDIT  //not supported  
    ```  
  
-   Você não pode usar macros de pré-processador com argumentos como definições de valor. Por exemplo:  
  
    ```cpp  
    #define   IDD_ABOUT  ID(7) //not supported  
    ```  
  
     não é uma expressão válida, independentemente de qual `ID` é avaliada como em tempo de compilação.  
  
-   Seu aplicativo pode ter um arquivo existente que contém símbolos definidos com expressões. Para obter mais informações sobre como incluir os símbolos como símbolos somente leitura, consulte [usando compartilhados (somente leitura) ou símbolos calculados](../windows/including-shared-read-only-or-calculated-symbols.md).  
  
 Para obter mais informações sobre intervalos de número, consulte [TN023: recursos padrão do MFC](../mfc/tn023-standard-mfc-resources.md).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Alterando o valor numérico de um símbolo](../windows/changing-a-symbol-s-numeric-value.md)   
 [Restrições de nome de símbolo](../windows/symbol-name-restrictions.md)   
 [IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)