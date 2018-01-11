---
title: detect_mismatch | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc-pragma.detect_mismatch
- detect_mismatch_CPP
dev_langs: C++
helpviewer_keywords:
- pragmas, detect_mismatch
- detect_mismatch pragma
ms.assetid: ddb13ac9-0e2f-40ce-be69-7e44c04f5a12
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 90f4013606ba94c6ea18aa4369bb2e3298034081
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="detectmismatch"></a>detect_mismatch
Coloca um registro em um objeto. O vinculador verifica possíveis incompatibilidades nesses registros.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma detect_mismatch( "name", "value"))  
```  
  
## <a name="remarks"></a>Comentários  
 Ao vincular o projeto, o vinculador lança um erro `LNK2038` se o projeto contiver dois objetos que tenham o mesmo `name` mas dois `value`diferentes. Use este pragma para impedir que os arquivos de objeto inconsistentes sejam vinculados.  
  
 O nome e o valor são literais de cadeia de caracteres e obedecem às regras de literais de cadeia de caracteres em relação aos caracteres de escape e a concatenação. Eles têm diferenciação de maiúsculas e minúsculas e não podem conter vírgulas, sinais de igual, aspas ou o caractere `null`.  
  
## <a name="example"></a>Exemplo  
 Este exemplo cria dois arquivos que têm números de versão diferentes para o mesmo rótulo da versão.  
  
```  
// pragma_directive_detect_mismatch_a.cpp  
#pragma detect_mismatch("myLib_version", "9")  
int main ()  
{  
   return 0;  
}  
  
// pragma_directive_detect_mismatch_b.cpp  
#pragma detect_mismatch("myLib_version", "1")  
```  
  
 Se você criar ambos os arquivos usando a linha de comando `cl pragma_directive_detect_mismatch_a.cpp pragma_directive_detect_mismatch_b.cpp`, receberá o erro `LNK2038`.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)