---
title: Ferramentas de vinculador LNK1179 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1179
dev_langs:
- C++
helpviewer_keywords:
- LNK1179
ms.assetid: 4b1536d7-0d3d-4f29-a9c1-6fa5cf6cb665
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 93b042e928331e369d64a45aa27f5f613ce9fc31
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1179"></a>Erro das Ferramentas de Vinculador LNK1179
arquivo inválido ou corrompido: duplicate COMDAT 'filename'  
  
 Um objeto de módulo contém duas ou mais COMDATs com o mesmo nome.  
  
 Esse erro pode ser causado por meio [/H](../../build/reference/h-restrict-length-of-external-names.md), que limita o comprimento de nomes externos, e [/Gy](../../build/reference/gy-enable-function-level-linking.md), quais funções em COMDATs de pacotes.  
  
## <a name="example"></a>Exemplo  
 No código a seguir, `function1` e `function2` são idênticos nos oito primeiros caracteres. Compilando com **/Gy** e **/H8** produz um erro de link.  
  
```  
void function1(void);  
void function2(void);  
  
int main() {  
    function1();  
    function2();  
}  
  
void function1(void) {}  
void function2(void) {}  
```