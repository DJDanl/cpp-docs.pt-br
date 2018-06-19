---
title: Assembler embutido (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- __asm keyword [C]
- inline assembler [C]
ms.assetid: 821acc77-60b1-434c-ba54-2ba930a25ab4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5bf99606601b86c6a328e9547515b3518cef4ffe
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32384314"
---
# <a name="inline-assembler-c"></a>Assembler embutido (C)
**Seção específica da Microsoft**  
  
 O assembler integrado permite inserir instruções da linguagem de assembly diretamente aos seus programas de código-fonte C sem etapas adicionais de assembly e vinculação. O assembler integrado é incorporado ao compilador e, portanto, não é necessário um assembler separado, como o MASM (Microsoft Macro Assembler).  
  
 Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado. O código do assembly integrado pode usar qualquer nome de variável ou de função C que esteja no escopo. Portanto, ele é de fácil integração com código C do programa. E como o código do assembly pode ser combinado com as instruções de C, ele poderá realizar as tarefas que são incômodas ou impossíveis apenas em C.  
  
 A palavra-chave `__asm` invoca o assembler integrado e pode aparecer sempre que uma declaração C é válida. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo "bloco `__asm`" refere-se aqui a qualquer instrução ou grupo de instruções, estando ou não entre chaves.  
  
 O código abaixo é um bloco simples de `__asm` entre chaves. (O código é uma sequência personalizada de prólogos da função.)  
  
```  
__asm  
{  
   push ebp  
   mov  ebp, esp  
   sub  esp, __LOCAL_SIZE  
}  
```  
  
 Como alternativa, você pode colocar `__asm` na frente de cada instrução de assemblies:  
  
```  
__asm push ebp  
__asm mov  ebp, esp  
__asm sub  esp, __LOCAL_SIZE  
```  
  
 Como a palavra-chave `__asm` é um separador de instruções, você também pode colocar instruções de assembly na mesma linha:  
  
```  
__asm push ebp   __asm mov  ebp, esp   __asm sub  esp, __LOCAL_SIZE   
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de função](../c-language/function-attributes.md)