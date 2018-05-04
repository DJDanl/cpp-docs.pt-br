---
title: naked (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- naked_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], naked
- naked __declspec keyword
ms.assetid: 69723241-05e1-439b-868e-20a83a16ab6d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 84e172c24bbb87f9243a4c0de25a98c90e043acc
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="naked-c"></a>naked (C++)
**Seção específica da Microsoft**  
  
 Para as funções declaradas com o atributo `naked`, o compilador gera um código sem código de prólogo e de epílogo. Você pode usar esse recurso para escrever suas próprias sequências de código de prólogo/epílogo usando o código de assembler embutido. As funções naked são particularmente úteis para escrever drivers para dispositivo virtuais.  Observe que o atributo `naked` só é válido em x86 e ARM, e não está disponível em [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__declspec(naked) declarator  
```  
  
## <a name="remarks"></a>Comentários  
 Porque o `naked` atributo só é relevante para a definição de uma função e não é um modificador de tipo, funções naked devem usar a sintaxe de atributo estendido e a [declspec](../cpp/declspec.md) palavra-chave.  
  

 O compilador não pode gerar uma função embutida para uma função marcada com o atributo naked, mesmo se a função também está marcada com o [forceinline](inline-functions-cpp.md) palavra-chave.  

  
 O compilador emitirá um erro se o atributo `naked` for aplicado a qualquer elemento que não seja a definição de um método de não membro.  
  
## <a name="examples"></a>Exemplos  
 Este código define uma função com o atributo `naked`:  
  
```  
__declspec( naked ) int func( formal_parameters ) {}  
```  
  
 Ou, alternativamente:  
  
```  
#define Naked __declspec( naked )  
Naked int func( formal_parameters ) {}  
```  
  
 O atributo `naked` afeta somente a natureza de geração de código do compilador para as sequências de prólogo e epílogo da função. Não afeta o código que é gerado pela chamada dessas funções. Assim, o atributo `naked` não é considerado parte do tipo de função, e os ponteiros da função não podem ter o atributo `naked`. Além disso, o atributo `naked` não pode ser aplicado a uma definição de dados. Por exemplo, esta amostra de código gera um erro:  
  
```  
__declspec( naked ) int i;       // Error--naked attribute not  
                                 // permitted on data declarations.  
```  
  
 O atributo `naked` é relevante apenas à definição da função e não pode ser especificado no protótipo da função. Por exemplo, esta declaração gera um erro de compilador:  
  
```  
__declspec( naked ) int func();  // Error--naked attribute not   
                                 // permitted on function declarations  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Chamadas de função naked](../cpp/naked-function-calls.md)