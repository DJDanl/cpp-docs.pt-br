---
title: Ferramentas de vinculador LNK1179 erro | Documentos do Microsoft
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
caps.latest.revision: 8
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ab8c6fcff738a30ea62d3f853560dfa164436e2b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1179"></a>Erro das Ferramentas de Vinculador LNK1179
arquivo inválido ou corrompido: duplicar COMDAT 'filename'  
  
 Um objeto de módulo contém duas ou mais COMDATs com o mesmo nome.  
  
 Esse erro pode ser causado por meio [/H](../../build/reference/h-restrict-length-of-external-names.md), que limita o comprimento dos nomes externos, e [/Gy](../../build/reference/gy-enable-function-level-linking.md), que empacota funções em COMDATs.  
  
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
