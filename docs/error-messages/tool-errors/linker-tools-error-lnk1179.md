---
title: Ferramentas de vinculador LNK1179 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1179
dev_langs:
- C++
helpviewer_keywords:
- LNK1179
ms.assetid: 4b1536d7-0d3d-4f29-a9c1-6fa5cf6cb665
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 72a531397c3c101fbff937f293f772c5f6778523
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33300209"
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