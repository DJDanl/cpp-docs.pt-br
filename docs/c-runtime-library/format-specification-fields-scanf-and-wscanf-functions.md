---
title: "Campos de especificação de formato: funções scanf e wscanf | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apilocation:
- msvcr80.dll
- msvcr110.dll
- msvcr90.dll
- msvcr100.dll
- msvcr110_clr0400.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- wscanf
- scanf
dev_langs:
- C++
helpviewer_keywords:
- width, specifications in scanf function
- scanf format specifications
- scanf width specifications
- scanf type field characters
- type fields, scanf function
- format specification fields for scanf function
- type fields
ms.assetid: 7e95de1b-0b71-4de3-9f81-c9560c78e039
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 77ef83eccc158cb9fff1a9161b5694a4caf62777
ms.lasthandoff: 04/01/2017

---
# <a name="format-specification-fields-scanf-and-wscanf-functions"></a>Campos de especificação de formato: funções scanf e wscanf
As informações aqui se aplicam a toda a família de funções `scanf`, incluindo as versões seguras e descreve os símbolos usados para informar as funções `scanf` como analisar o fluxo de entrada, como o fluxo de entrada `stdin` para `scanf`, em valores inseridos em variáveis de programa.  
  
 Uma especificação de formato tem a seguinte forma:  
  
 `%`[`*`] [[width](../c-runtime-library/scanf-width-specification.md)] [{[h &#124; l &#124; ll &#124; I64 &#124; L](../c-runtime-library/scanf-width-specification.md)}][type](../c-runtime-library/scanf-type-field-characters.md)  
  
 O argumento `format` especifica a interpretação da entrada e pode conter um ou mais dos seguintes:  
  
-   Caracteres de espaço em branco: em branco (' '); tabulação ('\t') ou nova linha ('\n'). Um caractere de espaço em branco faz com que `scanf` leia, mas não armazene todos os caracteres de espaço em branco consecutivos na entrada, até o próximo caractere que não seja de espaço em branco. Um caractere de espaço em branco no formato corresponde a qualquer número (incluindo 0) e combinação de caracteres de espaço em branco na entrada.  
  
-   Caracteres que não são de espaço em branco, exceto pelo sinal de porcentagem (`%`). Um caractere que não é de espaço em branco faz com que `scanf` leia, mas não armazene um caractere que não seja de espaço em branco correspondente. Se o próximo caractere no fluxo de entrada não for correspondente, `scanf` será encerrado.  
  
-   Especificações de formato, introduzidas pelo sinal de porcentagem (`%`). Uma especificação de formato faz com que `scanf` leia e converta caracteres na entrada em valores de um tipo especificado. O valor é atribuído a um argumento na lista de argumentos.  
  
 O formato é lido da esquerda para a direita. Caracteres fora das especificações de formato devem corresponder à sequência de caracteres no fluxo de entrada; os caracteres correspondentes no fluxo de entrada são verificados, mas não armazenados. Se um caractere no fluxo de entrada estiver em conflito com a especificação de formato, `scanf` será encerrado e o caractere será deixado no fluxo de entrada como se não tivesse sido lido.  
  
 Quando a primeira especificação de formato é encontrada, o valor do primeiro campo de entrada é convertido de acordo com essa especificação e é armazenado no local especificado pelo primeiro `argument`. A segunda especificação de formato faz com que o segundo campo de entrada seja convertido e armazenado no segundo `argument` e assim por diante, até o final da cadeia de caracteres de formato.  
  
 Um campo de entrada é definido como todos os caracteres até o primeiro caractere de espaço em branco (espaço, tabulação ou nova linha), até o primeiro caractere que não possa ser convertido de acordo com a especificação de formato ou até que a largura do campo (se especificada) seja atingida. Se houver muitos argumentos para as especificações fornecidas, os argumentos extra serão avaliados, mas ignorados. Os resultados serão imprevisíveis se não houver argumentos suficientes para a especificação de formato.  
  
 Cada campo da especificação de formato é um caractere único ou um número indicando uma opção de formato específico. O caractere `type`, que aparece após o último campo de formato opcional, determina se o campo de entrada é interpretado como um caractere, uma cadeia de caracteres ou um número.  
  
 A especificação de formato mais simples contém apenas o sinal de porcentagem e um caractere `type` (por exemplo, `%s`). Se um sinal de porcentagem (`%`) for seguido por um caractere sem nenhum significado, como um caractere de controle de formato, esse caractere e os caracteres seguintes (até o sinal de porcentagem seguinte) serão tratados como uma simples sequência de caracteres, ou seja, uma sequência de caracteres que deve corresponder à entrada. Por exemplo, para especificar que um caractere de sinal de porcentagem deve ser inserido, use `%%`.  
  
 Um asterisco (`*`) após o sinal de porcentagem suprime a atribuição do próximo campo de entrada, o que é interpretado como um campo do tipo especificado. O campo é verificado, mas não armazenado.  
  
 As versões seguras (aquelas com o sufixo `_s`) da família de funções `scanf` exigem que um parâmetro de tamanho do buffer seja passado imediatamente após cada parâmetro do tipo `c`, `C`, `s`, `S` ou `[`. Para obter mais informações sobre as versões seguras da família de funções `scanf`, consulte [scanf_s, scanf_s_l, wscanf_s, wscanf_s_l](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md).  
  
## <a name="see-also"></a>Consulte também  
 [Especificação de largura scanf](../c-runtime-library/scanf-width-specification.md)   
 [Caracteres de campo de tipo scanf](../c-runtime-library/scanf-type-field-characters.md)   
 [scanf, _scanf_l, wscanf, _wscanf_l](../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l](../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md)
