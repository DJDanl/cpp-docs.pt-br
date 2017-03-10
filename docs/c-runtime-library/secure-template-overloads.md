---
title: Sobrecargas de modelo seguras | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
- _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
- _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
dev_langs:
- C++
helpviewer_keywords:
- _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
- _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
- _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
- secure template overloads
ms.assetid: 562741d0-39c0-485e-8529-73d740f29f8f
caps.latest.revision: 13
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
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 1519fde9f60f9cb9b45db4a4921f2bec5185e549
ms.lasthandoff: 02/25/2017

---
# <a name="secure-template-overloads"></a>Sobrecargas de modelo seguras
Muitas funções de CRT foram substituídas por versões mais recentes, com segurança aprimorada (por exemplo, `strcpy_s` é o substituto mais seguro de `strcpy`). A CRT fornece sobrecargas de modelo para ajudar a facilitar a transição para as variantes mais seguras.  
  
 Por exemplo, este código gera um aviso porque `strcpy` é preterida:  
  
 `char szBuf[10];`  
  
 `strcpy(szBuf, "test"); // warning: deprecated`  
  
 Você pode ignorar o aviso. Defina o símbolo `_CRT_SECURE_NO_WARNINGS` para suprimir o aviso ou atualize o código para usar `strcpy_s`:  
  
 `char szBuf[10];`  
  
 `strcpy_s(szBuf, 10, "test"); // security-enhanced _s function`  
  
 As sobrecargas de modelo oferecem opções adicionais. Definir `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` como 1 habilita as sobrecargas de modelo das funções de CRT padrão que chamam as variantes mais seguras automaticamente. Se `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` for 1, nenhuma alteração no código é necessária. Nos bastidores, a chamada para `strcpy` será alterada para uma chamada para `strcpy_s` com o argumento de tamanho fornecido automaticamente.  
  
 `#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1`  
  
 `...`  
  
 `char szBuf[10];`  
  
 `strcpy(szBuf, "test"); // ==> strcpy_s(szBuf, 10, "test")`  
  
 `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` não afeta as funções que usam contagem, como `strncpy`. Para habilitar as sobrecargas de modelo para funções de contagem, defina `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT` como 1. Antes de fazer isso, no entanto, certifique-se de que seu código passa a contagem de caracteres, não o tamanho do buffer (um erro comum). Além disso, um código que grave explicitamente um terminador nulo ao final do buffer após a chamada de função não é necessário se a variante segura for chamada. Se você precisar de comportamento de truncamento, consulte [_TRUNCATE](../c-runtime-library/truncate.md).  
  
> [!NOTE]
>  A macro `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT` requer que `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` também seja definida como 1. Se `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT` for definida como 1 e `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` for definida como 0, o aplicativo não executará sobrecargas de modelo.  
  
 Definir `_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES` como 1 habilita sobrecargas de modelo das variantes seguras (cujos nomes terminam em “_s”). Nesse caso, se `_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES` for 1, uma pequena alteração deverá ser feita no código original:  
  
 `#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1`  
  
 `...`  
  
 `char szBuf[10];`  
  
 `strcpy_s(szBuf, "test"); // ==> strcpy_s(szBuf, 10, "test")`  
  
 Somente o nome da função precisa ser alterado (adicionando “_s”); a sobrecarga de modelo se encarregará de fornecer o argumento de tamanho.  
  
 Por padrão, `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES` e `_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT` são definidas como 0 (desabilitada) e `_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES` é definida como 1 (ativada).  
  
 Observe que essas sobrecargas de modelo só funcionam para matrizes estáticas. Buffers alocados dinamicamente exigem alterações de código de origem adicionais. Revisitando os exemplos anteriores:  
  
 `#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1`  
  
 `...`  
  
 `char *szBuf = (char*)malloc(10);`  
  
 `strcpy(szBuf, "test"); // still deprecated; have to change to`  
  
 `// strcpy_s(szBuf, 10, "test");`  
  
 E este:  
  
 `#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1`  
  
 `...`  
  
 `char *szBuf = (char*)malloc(10);`  
  
 `strcpy_s(szBuf, "test"); // doesn't compile; have to change to`  
  
 `// strcpy_s(szBuf, 10, "test");`  
  
## <a name="see-also"></a>Consulte também  
 [Recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md)   
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
